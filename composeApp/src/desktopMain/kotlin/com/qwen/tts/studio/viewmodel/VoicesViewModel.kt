package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.qwen.tts.studio.engine.NativeBackendPreference
import com.qwen.tts.studio.engine.QwenEngine
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.asCoroutineDispatcher
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.isActive
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.io.ByteArrayInputStream
import java.io.ByteArrayOutputStream
import java.io.File
import java.nio.ByteBuffer
import java.nio.ByteOrder
import java.nio.charset.StandardCharsets
import java.util.Base64
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit
import kotlin.math.sqrt
import javax.sound.sampled.AudioFileFormat
import javax.sound.sampled.AudioFormat
import javax.sound.sampled.AudioInputStream
import javax.sound.sampled.AudioSystem
import javax.sound.sampled.DataLine
import javax.sound.sampled.TargetDataLine

/**
 * Represents a voice profile that can be used for synthesis.
 *
 * @property id Unique identifier for the voice preset.
 * @property name Display name of the voice.
 * @property referenceWav Optional path to a reference WAV file for cloning.
 * @property referenceText Optional transcript for full ICL voice prompt extraction.
 * @property speakerEmbeddings Extracted speaker embeddings keyed by embedding dimension.
 * @property iclPrompts Extracted full ICL prompts keyed by embedding dimension.
 */
data class VoicePreset(
    val id: String,
    val name: String,
    val referenceWav: String?,
    val referenceText: String? = null,
    val speakerEmbeddings: Map<Int, String> = emptyMap(),
    val iclPrompts: Map<Int, String> = emptyMap()
) {
    /** Whether this is a built-in system voice (not a custom preset). */
    val isSystem: Boolean = referenceWav == null && speakerEmbeddings.isEmpty() && iclPrompts.isEmpty()
}

data class VoiceRecordingState(
    val isRecording: Boolean = false,
    val elapsedSeconds: Int = 0,
    val lastRecordingPath: String? = null
)

data class EmbeddingBlendSource(
    val voiceId: String,
    val weight: Float
)

/**
 * ViewModel for managing custom voice presets and speaker embedding extraction.
 */
class VoicesViewModel : ViewModel() {
    private val defaultVoice = VoicePreset(
        id = "default",
        name = "Default Voice (Model)",
        referenceWav = null
    )

    private val storageFile = File(
        File(System.getProperty("user.home"), ".qwen-tts-studio"),
        "voice-presets.tsv"
    )
    private val recordingsDir = File(
        File(System.getProperty("user.home"), ".qwen-tts-studio"),
        "recordings"
    )

    private val _voices = MutableStateFlow(loadVoices())
    /** List of all available voice presets, including the default system voice. */
    val voices: StateFlow<List<VoicePreset>> = _voices.asStateFlow()

    private val _isCreating = MutableStateFlow(false)
    /** Whether a voice preset is currently being created (embedding extraction). */
    val isCreating: StateFlow<Boolean> = _isCreating.asStateFlow()

    private val _error = MutableStateFlow<String?>(null)
    /** Current error message related to voice preset operations. */
    val error: StateFlow<String?> = _error.asStateFlow()

    private val _supportsCloning = MutableStateFlow(true)
    /** Whether the currently loaded model supports voice cloning. */
    val supportsCloning: StateFlow<Boolean> = _supportsCloning.asStateFlow()

    private val _currentEmbeddingDim = MutableStateFlow(0)
    /** The speaker embedding dimension required by the currently loaded model. */
    val currentEmbeddingDim: StateFlow<Int> = _currentEmbeddingDim.asStateFlow()

    private val _recordingState = MutableStateFlow(VoiceRecordingState())
    val recordingState: StateFlow<VoiceRecordingState> = _recordingState.asStateFlow()

    private val qwenEngine = QwenEngine()
    private val nativeDispatcher = Executors.newSingleThreadExecutor { runnable ->
        Thread(null, runnable, "QwenVoicePresetThread", 8L * 1024 * 1024).apply {
            isDaemon = true
        }
    }.asCoroutineDispatcher()
    private var recordingJob: Job? = null
    private var recordingTimerJob: Job? = null
    @Volatile
    private var recordingLine: TargetDataLine? = null
    @Volatile
    private var recordingProcess: Process? = null

    private companion object {
        private const val RECORDING_BUFFER_MILLIS = 100
        private const val MIN_RECORDING_SECONDS = 0.25
        private const val SILENCE_PEAK_THRESHOLD = 128
        private const val SILENCE_RMS_THRESHOLD = 8.0
        private const val PIPEWIRE_SOURCE_RECORDING_VOLUME = 0.05f
        private const val CLIPPING_SAMPLE_THRESHOLD = 0.01
        private const val RECORDING_POST_PROCESS_FILTER = "highpass=f=90,lowpass=f=9000,loudnorm=I=-18:TP=-3:LRA=11,aresample=48000"
    }

    /**
     * Refreshes model capabilities to update cloning support and embedding dimensions.
     *
     * @param modelDir Directory containing the models.
     * @param modelName Optional specific model name.
     */
    fun refreshModelCapabilities(
        modelDir: String,
        modelName: String?,
        backendPreference: NativeBackendPreference
    ) {
        if (modelDir.isBlank()) return
        viewModelScope.launch(Dispatchers.IO) {
            val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
            val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, resolvedModelName, backendPreference) }
            if (!loaded) return@launch
            val caps = withContext(nativeDispatcher) { qwenEngine.getModelCapabilities() }
            _supportsCloning.value = caps?.supportsCloning ?: true
            _currentEmbeddingDim.value = caps?.speakerEmbeddingDim ?: 0
        }
    }

    /**
     * Creates a new voice preset by extracting a speaker embedding from a reference WAV file.
     *
     * @param name The name for the new preset.
     * @param referenceWav Path to the reference audio file.
     * @param modelDir Directory containing the models (needed for extraction).
     * @param modelName Optional specific model name.
     */
    fun createVoicePreset(
        name: String,
        referenceWav: String,
        referenceText: String?,
        modelDir: String,
        modelName: String?,
        backendPreference: NativeBackendPreference
    ) {
        val wavFile = File(referenceWav)
        if (!wavFile.exists() || !wavFile.isFile) {
            _error.value = "Reference audio file does not exist."
            return
        }
        if (modelDir.isBlank()) {
            _error.value = "Please select the Model Directory in Setup."
            return
        }

        val trimmedName = name.trim()
        if (trimmedName.isBlank()) {
            _error.value = "Preset name is required."
            return
        }

        _isCreating.value = true
        _error.value = null

        val uniqueName = makeUniqueName(trimmedName)
        val voiceId = "voice-${System.currentTimeMillis()}"
        val trimmedReferenceText = referenceText?.trim().orEmpty()
        viewModelScope.launch {
            try {
                val targetModels = withContext(Dispatchers.IO) { findEmbeddingTargetModels(modelDir, modelName) }
                if (targetModels.isEmpty()) {
                    _error.value = "No qwen-talker GGUF model found for speaker embedding extraction."
                    return@launch
                }

                val embeddingsDir = withContext(Dispatchers.IO) { embeddingsDirectory().apply { mkdirs() } }
                val iclPromptsDir = withContext(Dispatchers.IO) { iclPromptsDirectory().apply { mkdirs() } }
                val extractedEmbeddings = sortedMapOf<Int, String>()
                val extractedIclPrompts = sortedMapOf<Int, String>()
                var lastSupportsCloning = false
                var lastEmbeddingDim = 0
                var iclPromptWarning: String? = null
                val extractionErrors = mutableListOf<String>()

                for (targetModel in targetModels) {
                    val inferredTargetDim = inferEmbeddingDimFromModelName(targetModel)
                    if (
                        inferredTargetDim > 0 &&
                        extractedEmbeddings.containsKey(inferredTargetDim) &&
                        (trimmedReferenceText.isBlank() || extractedIclPrompts.containsKey(inferredTargetDim))
                    ) {
                        continue
                    }

                    val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, targetModel, backendPreference) }
                    if (!loaded) {
                        extractionErrors += "Failed to load $targetModel for speaker embedding extraction."
                        continue
                    }

                    val caps = withContext(nativeDispatcher) { qwenEngine.getModelCapabilities() }
                    val supportsCloning = caps?.supportsCloning ?: true
                    val embeddingDim = caps?.speakerEmbeddingDim ?: inferredTargetDim
                    lastSupportsCloning = supportsCloning
                    lastEmbeddingDim = embeddingDim
                    _supportsCloning.value = supportsCloning
                    _currentEmbeddingDim.value = embeddingDim

                    if (!supportsCloning || embeddingDim <= 0) {
                        continue
                    }

                    if (!extractedEmbeddings.containsKey(embeddingDim)) {
                        val embeddingFile = File(embeddingsDir, "$voiceId-d$embeddingDim.json")
                        val extraction = withContext(nativeDispatcher) {
                            qwenEngine.extractSpeakerEmbeddingDetailed(wavFile.absolutePath, embeddingFile.absolutePath)
                        }
                        if (!extraction.success) {
                            deleteEmbeddingFiles(listOf(embeddingFile.absolutePath))
                            extractionErrors += "Failed to extract D$embeddingDim speaker embedding with $targetModel: ${extraction.errorMsg ?: "Unknown native error"}"
                            continue
                        }
                        extractedEmbeddings[embeddingDim] = embeddingFile.absolutePath
                    }

                    if (trimmedReferenceText.isNotBlank() && !extractedIclPrompts.containsKey(embeddingDim)) {
                        val iclPromptFile = File(iclPromptsDir, "$voiceId-d$embeddingDim.json")
                        val iclLoaded = withContext(nativeDispatcher) {
                            qwenEngine.loadIclPromptEncoder(modelDir, targetModel, backendPreference)
                        }
                        if (!iclLoaded) {
                            deleteIclPromptFiles(extractedIclPrompts.values + iclPromptFile.absolutePath)
                            iclPromptWarning = "Speaker preset created, but ICL prompt extraction is unavailable. Rebuild the native backend, then generate the ICL prompt from this preset."
                            continue
                        }
                        val iclExtraction = withContext(nativeDispatcher) {
                            qwenEngine.extractIclPromptDetailed(wavFile.absolutePath, trimmedReferenceText, iclPromptFile.absolutePath)
                        }
                        if (!iclExtraction.success) {
                            deleteIclPromptFiles(extractedIclPrompts.values + iclPromptFile.absolutePath)
                            iclPromptWarning = "Speaker preset created, but D$embeddingDim ICL prompt extraction failed with $targetModel: ${iclExtraction.errorMsg ?: "Unknown native error"}"
                            continue
                        }
                        extractedIclPrompts[embeddingDim] = iclPromptFile.absolutePath
                    }
                }

                if (extractedEmbeddings.isEmpty() && extractedIclPrompts.isEmpty()) {
                    _supportsCloning.value = lastSupportsCloning
                    _currentEmbeddingDim.value = lastEmbeddingDim
                    _error.value = extractionErrors.firstOrNull()
                        ?: "No installed model supports custom voice clone extraction."
                    return@launch
                }

                val preset = VoicePreset(
                    id = voiceId,
                    name = uniqueName,
                    referenceWav = wavFile.absolutePath,
                    referenceText = trimmedReferenceText.ifBlank { null },
                    speakerEmbeddings = extractedEmbeddings,
                    iclPrompts = extractedIclPrompts
                )
                _voices.value = _voices.value + preset
                saveVoices()
                _error.value = iclPromptWarning ?: extractionErrors.firstOrNull()?.let {
                    "Speaker preset created, but $it"
                }
            } finally {
                _isCreating.value = false
            }
        }
    }

    fun createMissingSpeakerEmbedding(
        name: String,
        targetDim: Int,
        modelDir: String,
        backendPreference: NativeBackendPreference
    ) {
        if (_isCreating.value) return
        if (targetDim <= 0) {
            _error.value = "Unknown speaker embedding dimension."
            return
        }
        if (modelDir.isBlank()) {
            _error.value = "Please select the Model Directory in Setup."
            return
        }

        val preset = _voices.value.firstOrNull { it.name == name || it.id == name }
        if (preset == null || preset.isSystem) {
            _error.value = "Select a custom speaker preset first."
            return
        }
        if (preset.speakerEmbeddings.containsKey(targetDim)) {
            _error.value = null
            return
        }

        val referenceWav = preset.referenceWav
        if (referenceWav.isNullOrBlank() || !File(referenceWav).isFile) {
            _error.value = "This speaker preset has no reference WAV for generating D$targetDim."
            return
        }

        _isCreating.value = true
        _error.value = null

        viewModelScope.launch {
            try {
                val targetModels = withContext(Dispatchers.IO) {
                    findEmbeddingTargetModels(modelDir, null)
                        .filter { inferEmbeddingDimFromModelName(it) == targetDim }
                }
                if (targetModels.isEmpty()) {
                    _error.value = "No installed D$targetDim qwen-talker model found."
                    return@launch
                }

                val embeddingFile = withContext(Dispatchers.IO) {
                    embeddingsDirectory().apply { mkdirs() }
                    File(embeddingsDirectory(), "${preset.id}-d$targetDim.json")
                }
                var extracted = false
                var lastError: String? = null
                for (targetModel in targetModels) {
                    val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, targetModel, backendPreference) }
                    if (!loaded) {
                        lastError = "Failed to load $targetModel."
                        continue
                    }

                    val caps = withContext(nativeDispatcher) { qwenEngine.getModelCapabilities() }
                    val supportsCloning = caps?.supportsCloning ?: true
                    val embeddingDim = caps?.speakerEmbeddingDim ?: inferEmbeddingDimFromModelName(targetModel)
                    _supportsCloning.value = supportsCloning
                    _currentEmbeddingDim.value = embeddingDim

                    if (!supportsCloning || embeddingDim != targetDim) {
                        lastError = "$targetModel does not expose D$targetDim speaker embeddings."
                        continue
                    }

                    val extraction = withContext(nativeDispatcher) {
                        qwenEngine.extractSpeakerEmbeddingDetailed(referenceWav, embeddingFile.absolutePath)
                    }
                    extracted = extraction.success
                    if (extracted) break
                    lastError = "Failed to extract D$targetDim with $targetModel: ${extraction.errorMsg ?: "Unknown native error"}"
                }

                if (!extracted) {
                    runCatching { embeddingFile.delete() }
                    _error.value = lastError ?: "Failed to extract D$targetDim speaker embedding."
                    return@launch
                }

                _voices.value = _voices.value.map {
                    if (it.id == preset.id) {
                        it.copy(speakerEmbeddings = (it.speakerEmbeddings + (targetDim to embeddingFile.absolutePath)).toSortedMap())
                    } else {
                        it
                    }
                }
                saveVoices()
            } finally {
                _isCreating.value = false
            }
        }
    }

    fun createMissingIclPrompt(
        name: String,
        targetDim: Int,
        modelDir: String,
        backendPreference: NativeBackendPreference
    ) {
        if (_isCreating.value) return
        if (targetDim <= 0) {
            _error.value = "Unknown ICL prompt dimension."
            return
        }
        if (modelDir.isBlank()) {
            _error.value = "Please select the Model Directory in Setup."
            return
        }

        val preset = _voices.value.firstOrNull { it.name == name || it.id == name }
        if (preset == null || preset.isSystem) {
            _error.value = "Select a custom speaker preset first."
            return
        }
        if (preset.iclPrompts.containsKey(targetDim)) {
            _error.value = null
            return
        }

        val referenceWav = preset.referenceWav
        if (referenceWav.isNullOrBlank() || !File(referenceWav).isFile) {
            _error.value = "This speaker preset has no reference WAV for generating a D$targetDim ICL prompt."
            return
        }

        val referenceText = preset.referenceText?.trim().orEmpty()
        if (referenceText.isBlank()) {
            _error.value = "This speaker preset has no reference transcript for ICL prompt extraction."
            return
        }

        _isCreating.value = true
        _error.value = null

        viewModelScope.launch {
            try {
                val targetModels = withContext(Dispatchers.IO) {
                    findEmbeddingTargetModels(modelDir, null)
                        .filter { inferEmbeddingDimFromModelName(it) == targetDim }
                }
                if (targetModels.isEmpty()) {
                    _error.value = "No installed D$targetDim qwen-talker model found."
                    return@launch
                }

                val iclPromptFile = withContext(Dispatchers.IO) {
                    iclPromptsDirectory().apply { mkdirs() }
                    File(iclPromptsDirectory(), "${preset.id}-d$targetDim.json")
                }
                var extracted = false
                var lastError: String? = null
                for (targetModel in targetModels) {
                    val loaded = withContext(nativeDispatcher) {
                        qwenEngine.loadIclPromptEncoder(modelDir, targetModel, backendPreference)
                    }
                    if (!loaded) {
                        lastError = "Failed to load $targetModel for ICL prompt extraction."
                        continue
                    }

                    val embeddingDim = inferEmbeddingDimFromModelName(targetModel)
                    _currentEmbeddingDim.value = embeddingDim
                    if (embeddingDim != targetDim) {
                        lastError = "$targetModel does not expose D$targetDim ICL prompts."
                        continue
                    }

                    val extraction = withContext(nativeDispatcher) {
                        qwenEngine.extractIclPromptDetailed(referenceWav, referenceText, iclPromptFile.absolutePath)
                    }
                    extracted = extraction.success
                    if (extracted) break
                    lastError = "Failed to extract D$targetDim ICL prompt with $targetModel: ${extraction.errorMsg ?: "Unknown native error"}"
                }

                if (!extracted) {
                    runCatching { iclPromptFile.delete() }
                    _error.value = lastError ?: "Failed to extract D$targetDim ICL prompt."
                    return@launch
                }

                _voices.value = _voices.value.map {
                    if (it.id == preset.id) {
                        it.copy(iclPrompts = (it.iclPrompts + (targetDim to iclPromptFile.absolutePath)).toSortedMap())
                    } else {
                        it
                    }
                }
                saveVoices()
            } finally {
                _isCreating.value = false
            }
        }
    }

    fun startRecording() {
        if (_isCreating.value || _recordingState.value.isRecording) return

        _error.value = null
        recordingsDir.mkdirs()
        val outputFile = File(recordingsDir, "recording-${System.currentTimeMillis()}.wav")

        if (startPipeWireRecording(outputFile)) {
            return
        }

        try {
            val line = openRecordingLine()
            recordingLine = line
            line.start()
            _recordingState.value = VoiceRecordingState(isRecording = true)

            startRecordingTimer()

            recordingJob = viewModelScope.launch(Dispatchers.IO) {
                val format = line.format
                val buffer = ByteArray(recordingBufferBytes(format))
                val captured = ByteArrayOutputStream()
                var peak = 0
                var squareSum = 0.0
                var sampleCount = 0L
                var clippedSamples = 0L
                try {
                    while (isActive && _recordingState.value.isRecording && line.isOpen) {
                        val read = line.read(buffer, 0, buffer.size)
                        if (read <= 0) continue

                        captured.write(buffer, 0, read)
                        val stats = accumulatePcm16Stats(buffer, read)
                        peak = maxOf(peak, stats.peak)
                        squareSum += stats.squareSum
                        sampleCount += stats.sampleCount
                        clippedSamples += stats.clippedSamples
                    }

                    val audioBytes = captured.toByteArray()
                    val minBytes = (format.frameRate * format.frameSize * MIN_RECORDING_SECONDS)
                        .toInt()
                        .coerceAtLeast(format.frameSize)
                    val rms = if (sampleCount > 0L) kotlin.math.sqrt(squareSum / sampleCount) else 0.0
                    val clippingRatio = if (sampleCount > 0L) clippedSamples.toDouble() / sampleCount else 0.0

                    if (
                        audioBytes.size >= minBytes &&
                        clippingRatio <= CLIPPING_SAMPLE_THRESHOLD &&
                        !(peak < SILENCE_PEAK_THRESHOLD && rms < SILENCE_RMS_THRESHOLD)
                    ) {
                        ByteArrayInputStream(audioBytes).use { input ->
                            AudioInputStream(input, format, (audioBytes.size / format.frameSize).toLong()).use { stream ->
                                AudioSystem.write(stream, AudioFileFormat.Type.WAVE, outputFile)
                            }
                        }
                        postProcessRecording(outputFile)
                        _recordingState.value = _recordingState.value.copy(
                            isRecording = false,
                            lastRecordingPath = outputFile.absolutePath
                        )
                    } else {
                        outputFile.delete()
                        _recordingState.value = VoiceRecordingState()
                        _error.value = if (audioBytes.size < minBytes) {
                            "Recording was too short."
                        } else if (clippingRatio > CLIPPING_SAMPLE_THRESHOLD) {
                            "Recording is clipping. Lower the system microphone input volume and try again."
                        } else {
                            "Recording was silent. Check the selected system microphone input and capture level."
                        }
                    }
                } catch (e: Exception) {
                    outputFile.delete()
                    if (_recordingState.value.isRecording) {
                        _error.value = "Recording failed: ${e.message}"
                    }
                    _recordingState.value = VoiceRecordingState()
                } finally {
                    recordingTimerJob?.cancel()
                    recordingTimerJob = null
                    recordingLine = null
                    runCatching { line.stop() }
                    runCatching { line.close() }
                }
            }
        } catch (e: Exception) {
            _recordingState.value = VoiceRecordingState()
            _error.value = "Could not start microphone recording: ${e.message}"
        }
    }

    fun stopRecording() {
        val process = recordingProcess
        if (process != null) {
            _recordingState.value = _recordingState.value.copy(isRecording = false)
            interruptProcess(process)
            viewModelScope.launch(Dispatchers.IO) {
                if (!process.waitFor(2, TimeUnit.SECONDS)) {
                    process.destroy()
                }
                if (!process.waitFor(1, TimeUnit.SECONDS)) {
                    process.destroyForcibly()
                }
            }
            return
        }

        val line = recordingLine ?: return
        _recordingState.value = _recordingState.value.copy(isRecording = false)
        runCatching { line.stop() }
    }

    /**
     * Deletes a custom voice preset.
     *
     * @param id The unique identifier of the preset to delete.
     */
    fun deleteVoicePreset(id: String) {
        val target = _voices.value.firstOrNull { it.id == id } ?: return
        if (target.isSystem) return

        deleteEmbeddingFiles(target.speakerEmbeddings.values)
        deleteIclPromptFiles(target.iclPrompts.values)
        _voices.value = _voices.value.filterNot { it.id == id }
        saveVoices()
    }

    /**
     * Returns the reference WAV path for a voice preset name.
     *
     * @param name The name of the voice preset.
     * @return The path to the reference WAV file, or null if not found.
     */
    fun referenceForVoice(name: String): String? {
        return _voices.value.firstOrNull { it.name == name }?.referenceWav
    }

    /**
     * Returns the speaker embedding path for a voice preset name, matching the expected dimension.
     *
     * @param name The name of the voice preset.
     * @param expectedDim The required embedding dimension.
     * @return The path to the embedding file, or null if not found or dimension mismatch.
     */
    fun speakerEmbeddingForVoice(name: String, expectedDim: Int): String? {
        val preset = _voices.value.firstOrNull { it.name == name } ?: return null
        if (expectedDim <= 0) return preset.speakerEmbeddings.values.firstOrNull()
        return preset.speakerEmbeddings[expectedDim]
    }

    fun iclPromptForVoice(name: String, expectedDim: Int): String? {
        val preset = _voices.value.firstOrNull { it.name == name } ?: return null
        if (expectedDim <= 0) return preset.iclPrompts.values.firstOrNull()
        return preset.iclPrompts[expectedDim]
    }

    fun hasSpeakerEmbeddingForVoice(name: String, expectedDim: Int): Boolean {
        val preset = _voices.value.firstOrNull { it.name == name } ?: return false
        if (preset.isSystem) return true
        return speakerEmbeddingForVoice(name, expectedDim) != null
    }

    fun hasIclPromptForVoice(name: String, expectedDim: Int): Boolean {
        val preset = _voices.value.firstOrNull { it.name == name } ?: return false
        if (preset.isSystem) return false
        return iclPromptForVoice(name, expectedDim) != null
    }

    fun createMixedVoicePreset(
        name: String,
        sources: List<EmbeddingBlendSource>,
        normalize: Boolean
    ) {
        if (_isCreating.value) return

        val trimmedName = name.trim()
        if (trimmedName.isBlank()) {
            _error.value = "Preset name is required."
            return
        }

        val activeSources = sources.filter { it.weight > 0f }
        if (activeSources.map { it.voiceId }.distinct().size < 2) {
            _error.value = "Select at least two voices."
            return
        }

        _isCreating.value = true
        _error.value = null

        viewModelScope.launch(Dispatchers.IO) {
            try {
                val presetsById = _voices.value.associateBy { it.id }
                val selectedPresets = mutableListOf<Pair<Float, VoicePreset>>()

                for (source in activeSources) {
                    val preset = presetsById[source.voiceId]
                    if (preset == null || preset.isSystem) {
                        _error.value = "Only custom speaker presets can be mixed."
                        return@launch
                    }

                    selectedPresets += source.weight to preset
                }

                val commonDims = selectedPresets
                    .map { (_, preset) -> preset.speakerEmbeddings.keys }
                    .reduce { acc, dims -> acc.intersect(dims) }
                    .filter { it == 1024 || it == 2048 }
                    .sorted()

                if (commonDims.isEmpty()) {
                    _error.value = "Selected voices do not share a speaker embedding dimension."
                    return@launch
                }

                val voiceId = "voice-${System.currentTimeMillis()}"
                val embeddingsDir = embeddingsDirectory().apply { mkdirs() }
                val mixedEmbeddings = sortedMapOf<Int, String>()

                for (dim in commonDims) {
                    val vectors = mutableListOf<Pair<Float, FloatArray>>()
                    for ((weight, preset) in selectedPresets) {
                        val path = preset.speakerEmbeddings[dim]
                            ?: throw IllegalArgumentException("${preset.name} has no D$dim embedding.")
                        val vector = loadSpeakerEmbedding(path)
                        if (vector.size != dim) {
                            throw IllegalArgumentException(
                                "${preset.name} has a ${vector.size}-value embedding, expected D$dim."
                            )
                        }
                        vectors += weight to vector
                    }

                    val mixed = mixSpeakerEmbeddings(vectors, normalize)
                    val embeddingFile = File(embeddingsDir, "$voiceId-d$dim.json")
                    saveSpeakerEmbeddingJson(embeddingFile, mixed)
                    mixedEmbeddings[dim] = embeddingFile.absolutePath
                }

                val preset = VoicePreset(
                    id = voiceId,
                    name = makeUniqueName(trimmedName),
                    referenceWav = null,
                    speakerEmbeddings = mixedEmbeddings
                )

                _voices.value = _voices.value + preset
                saveVoices()
                _error.value = null
            } catch (e: Exception) {
                _error.value = "Failed to create mixed voice: ${e.message}"
            } finally {
                _isCreating.value = false
            }
        }
    }

    private fun makeUniqueName(baseName: String): String {
        if (_voices.value.none { it.name.equals(baseName, ignoreCase = true) }) {
            return baseName
        }

        var index = 2
        while (true) {
            val candidate = "$baseName ($index)"
            if (_voices.value.none { it.name.equals(candidate, ignoreCase = true) }) {
                return candidate
            }
            index++
        }
    }

    private fun loadVoices(): List<VoicePreset> {
        val clones = if (storageFile.exists()) {
            storageFile.readLines()
                .mapNotNull { line ->
                    val parts = line.split('\t')
                    if (parts.size < 3) return@mapNotNull null

                    val id = parts[0]
                    val name = parts[1]
                    if (id.isBlank() || name.isBlank()) return@mapNotNull null
                    if (parts.size >= 5) {
                        val embedding = parts[2].ifBlank { null }
                        val wav = parts[3].ifBlank { null }
                        val dim = parts.getOrNull(4)?.toIntOrNull() ?: embedding?.let(::inferSpeakerEmbeddingDim)
                        val embeddings = decodeSpeakerEmbeddings(parts.getOrNull(5))
                            .ifEmpty {
                                if (embedding != null && dim != null) mapOf(dim to embedding) else emptyMap()
                            }
                        val referenceText = decodeStorageText(parts.getOrNull(6))
                        val iclPrompts = decodeIclPrompts(parts.getOrNull(7))
                        VoicePreset(
                            id = id,
                            name = name,
                            referenceWav = wav,
                            referenceText = referenceText,
                            speakerEmbeddings = embeddings,
                            iclPrompts = iclPrompts
                        )
                    } else {
                        val wav = parts.getOrNull(2).orEmpty()
                        if (wav.isBlank()) return@mapNotNull null
                        VoicePreset(id = id, name = name, referenceWav = wav)
                    }
                }
        } else {
            emptyList()
        }
        return listOf(defaultVoice) + clones
    }

    private fun saveVoices() {
        storageFile.parentFile?.mkdirs()
        val lines = _voices.value
            .filterNot { it.isSystem }
            .map {
                val primary = it.speakerEmbeddings.entries.firstOrNull()
                listOf(
                    it.id,
                    it.name,
                    primary?.value.orEmpty(),
                    it.referenceWav.orEmpty(),
                    primary?.key?.toString().orEmpty(),
                    encodeSpeakerEmbeddings(it.speakerEmbeddings),
                    encodeStorageText(it.referenceText),
                    encodeIclPrompts(it.iclPrompts)
                ).joinToString("\t")
            }
        storageFile.writeText(lines.joinToString(System.lineSeparator()))
    }

    private fun findEmbeddingTargetModels(modelDir: String, preferredModelName: String?): List<String> {
        val dir = File(modelDir)
        val localModels = dir.listFiles()
            ?.asSequence()
            ?.filter { it.isFile }
            ?.map { it.name }
            ?.filter(::isTalkerModelFile)
            ?.toMutableSet()
            ?: mutableSetOf()

        preferredModelName
            ?.trim()
            ?.takeIf { it.isNotBlank() }
            ?.let { localModels += it }

        return localModels
            .sortedWith(
                compareBy<String>(
                    { embeddingDimSortRank(inferEmbeddingDimFromModelName(it)) },
                    { modelExtractionRank(it) },
                    { it.lowercase() }
                )
            )
    }

    private fun isTalkerModelFile(fileName: String): Boolean {
        return fileName.endsWith(".gguf", ignoreCase = true) &&
            fileName.startsWith("qwen-talker-", ignoreCase = true) &&
            !fileName.contains("tokenizer", ignoreCase = true) &&
            !fileName.contains("speech", ignoreCase = true)
    }

    private fun inferEmbeddingDimFromModelName(modelName: String): Int {
        val normalized = modelName.lowercase()
        return when {
            normalized.contains("1.7b") -> 2048
            normalized.contains("0.6b") -> 1024
            else -> 0
        }
    }

    private fun embeddingDimSortRank(dim: Int): Int {
        return when (dim) {
            1024 -> 0
            2048 -> 1
            else -> 2
        }
    }

    private fun modelExtractionRank(modelName: String): Int {
        val normalized = modelName.lowercase()
        return when {
            normalized.contains("base") -> 0
            normalized.contains("customvoice") -> 1
            normalized.contains("voicedesign") || normalized.contains("voice-design") -> 2
            else -> 3
        }
    }

    private fun embeddingsDirectory(): File {
        return File(
            File(System.getProperty("user.home"), ".qwen-tts-studio"),
            "embeddings"
        )
    }

    private fun iclPromptsDirectory(): File {
        return File(
            File(System.getProperty("user.home"), ".qwen-tts-studio"),
            "icl-prompts"
        )
    }

    private fun deleteEmbeddingFiles(paths: Collection<String>) {
        val embeddingsDir = runCatching { embeddingsDirectory().canonicalFile }.getOrNull() ?: return
        deleteManagedFiles(paths, embeddingsDir)
    }

    private fun deleteIclPromptFiles(paths: Collection<String>) {
        val iclPromptsDir = runCatching { iclPromptsDirectory().canonicalFile }.getOrNull() ?: return
        deleteManagedFiles(paths, iclPromptsDir)
    }

    private fun deleteManagedFiles(paths: Collection<String>, managedDir: File) {
        paths.forEach { path ->
            runCatching {
                val file = File(path).canonicalFile
                if (file.parentFile == managedDir && file.isFile) {
                    file.delete()
                }
            }
        }
    }

    private fun encodeSpeakerEmbeddings(embeddings: Map<Int, String>): String {
        return encodePathMap(embeddings)
    }

    private fun decodeSpeakerEmbeddings(value: String?): Map<Int, String> {
        return decodePathMap(value)
    }

    private fun encodeIclPrompts(prompts: Map<Int, String>): String {
        return encodePathMap(prompts)
    }

    private fun decodeIclPrompts(value: String?): Map<Int, String> {
        return decodePathMap(value)
    }

    private fun encodePathMap(paths: Map<Int, String>): String {
        val encoder = Base64.getUrlEncoder().withoutPadding()
        return paths.entries
            .sortedBy { it.key }
            .joinToString(";") { (dim, path) ->
                val encodedPath = encoder.encodeToString(path.toByteArray(StandardCharsets.UTF_8))
                "$dim:$encodedPath"
            }
    }

    private fun decodePathMap(value: String?): Map<Int, String> {
        if (value.isNullOrBlank()) return emptyMap()
        val decoder = Base64.getUrlDecoder()
        return value.split(';')
            .mapNotNull { entry ->
                val separator = entry.indexOf(':')
                if (separator <= 0 || separator == entry.lastIndex) return@mapNotNull null
                val dim = entry.substring(0, separator).toIntOrNull() ?: return@mapNotNull null
                val path = runCatching {
                    String(decoder.decode(entry.substring(separator + 1)), StandardCharsets.UTF_8)
                }.getOrNull() ?: return@mapNotNull null
                dim to path
            }
            .toMap()
    }

    private fun encodeStorageText(value: String?): String {
        if (value.isNullOrBlank()) return ""
        return Base64.getUrlEncoder()
            .withoutPadding()
            .encodeToString(value.toByteArray(StandardCharsets.UTF_8))
    }

    private fun decodeStorageText(value: String?): String? {
        if (value.isNullOrBlank()) return null
        return runCatching {
            String(Base64.getUrlDecoder().decode(value), StandardCharsets.UTF_8)
        }.getOrNull()?.takeIf { it.isNotBlank() }
    }

    private fun inferSpeakerEmbeddingDim(path: String): Int? {
        val file = File(path)
        if (!file.exists() || !file.isFile) return null

        return try {
            if (file.extension.equals("json", ignoreCase = true)) {
                val text = file.readText()
                Regex("""[-+]?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?""")
                    .findAll(text)
                    .count()
                    .takeIf { it > 0 }
            } else {
                val bytes = file.length()
                if (bytes > 0L && bytes % 4L == 0L) (bytes / 4L).toInt() else null
            }
        } catch (_: Exception) {
            null
        }
    }

    private fun loadSpeakerEmbedding(path: String): FloatArray {
        val file = File(path)
        if (!file.isFile) throw IllegalArgumentException("Embedding file does not exist.")
        val bytes = file.readBytes()
        if (bytes.isEmpty()) throw IllegalArgumentException("Embedding file is empty.")

        val textLike = file.extension.equals("json", ignoreCase = true) ||
            bytes.any { it == '['.code.toByte() }

        return if (textLike) {
            Regex("""[-+]?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?""")
                .findAll(String(bytes, StandardCharsets.UTF_8))
                .map { it.value.toFloat() }
                .toList()
                .toFloatArray()
        } else {
            if (bytes.size % 4 != 0) {
                throw IllegalArgumentException("Binary embedding size is not divisible by 4.")
            }
            val buffer = ByteBuffer.wrap(bytes).order(ByteOrder.LITTLE_ENDIAN)
            FloatArray(bytes.size / 4) { buffer.float }
        }
    }

    private fun mixSpeakerEmbeddings(
        weightedVectors: List<Pair<Float, FloatArray>>,
        normalize: Boolean
    ): FloatArray {
        val dim = weightedVectors.first().second.size
        val sum = DoubleArray(dim)
        var weightSum = 0.0
        var normSum = 0.0

        weightedVectors.forEach { (weightFloat, vector) ->
            if (vector.size != dim) throw IllegalArgumentException("Embedding dimensions do not match.")
            val weight = weightFloat.toDouble()
            weightSum += weight
            normSum += l2Norm(vector) * weight
            for (i in 0 until dim) {
                sum[i] += vector[i].toDouble() * weight
            }
        }

        if (weightSum <= 0.0) throw IllegalArgumentException("Weights must be positive.")
        val mixed = FloatArray(dim) { i -> (sum[i] / weightSum).toFloat() }

        if (normalize) {
            val targetNorm = normSum / weightSum
            val mixedNorm = l2Norm(mixed)
            if (targetNorm > 0.0 && mixedNorm > 0.0) {
                val scale = targetNorm / mixedNorm
                for (i in mixed.indices) {
                    mixed[i] = (mixed[i] * scale).toFloat()
                }
            }
        }

        if (mixed.any { !it.isFinite() }) {
            throw IllegalArgumentException("Mixed embedding contains invalid values.")
        }
        return mixed
    }

    private fun l2Norm(vector: FloatArray): Double {
        var sum = 0.0
        for (value in vector) {
            sum += value.toDouble() * value.toDouble()
        }
        return sqrt(sum)
    }

    private fun saveSpeakerEmbeddingJson(file: File, embedding: FloatArray) {
        file.writeText(
            embedding.joinToString(
                separator = ",\n",
                prefix = "[\n  ",
                postfix = "\n]"
            ) { it.toString() },
            StandardCharsets.UTF_8
        )
    }

    private fun openRecordingLine(): TargetDataLine {
        val formats = listOf(
            AudioFormat(44_100f, 16, 1, true, false),
            AudioFormat(48_000f, 16, 1, true, false),
            AudioFormat(24_000f, 16, 1, true, false),
            AudioFormat(16_000f, 16, 1, true, false)
        )

        val mixers = AudioSystem.getMixerInfo()
            .sortedByDescending(::recordingMixerRank)

        for (format in formats) {
            val info = DataLine.Info(TargetDataLine::class.java, format)
            for (mixerInfo in mixers) {
                runCatching {
                    val mixer = AudioSystem.getMixer(mixerInfo)
                    if (!mixer.isLineSupported(info)) return@runCatching
                    val line = mixer.getLine(info) as TargetDataLine
                    line.open(format, recordingBufferBytes(format))
                    println("[VoicesViewModel] Recording from mixer: ${mixerInfo.name} (${mixerInfo.description}), format=$format")
                    return line
                }
            }

            runCatching {
                val line = AudioSystem.getLine(info) as TargetDataLine
                line.open(format, recordingBufferBytes(format))
                println("[VoicesViewModel] Recording from default input, format=$format")
                return line
            }
        }

        throw IllegalStateException("No supported microphone input line was found.")
    }

    private fun startPipeWireRecording(outputFile: File): Boolean {
        if (!isLinux() || !isExecutableOnPath("pw-record")) return false

        val command = listOf(
            "pw-record",
            "--rate", "48000",
            "--channels", "1",
            "--format", "s16",
            "--container", "wav",
            outputFile.absolutePath
        )

        return runCatching {
            val previousSourceVolume = lowerDefaultSourceVolumeForRecording()
            val process = try {
                ProcessBuilder(command)
                    .redirectOutput(ProcessBuilder.Redirect.DISCARD)
                    .redirectError(ProcessBuilder.Redirect.DISCARD)
                    .start()
            } catch (e: Exception) {
                restoreDefaultSourceVolume(previousSourceVolume)
                throw e
            }

            Thread.sleep(150)
            if (!process.isAlive) {
                outputFile.delete()
                restoreDefaultSourceVolume(previousSourceVolume)
                return@runCatching false
            }

            println("[VoicesViewModel] Recording through PipeWire: ${command.joinToString(" ")}")
            recordingProcess = process
            _recordingState.value = VoiceRecordingState(isRecording = true)
            startRecordingTimer()

            recordingJob = viewModelScope.launch(Dispatchers.IO) {
                try {
                    val exitCode = process.waitFor()
                    val validationError = validateRecordedWav(outputFile)

                    if (validationError == null) {
                        postProcessRecording(outputFile)
                        _recordingState.value = VoiceRecordingState(
                            isRecording = false,
                            lastRecordingPath = outputFile.absolutePath
                        )
                    } else {
                        outputFile.delete()
                        _recordingState.value = VoiceRecordingState()
                        _error.value = if (exitCode == 0 || validationError != "Recording did not produce usable audio.") {
                            if (exitCode == 0) validationError else "$validationError (pw-record exit code $exitCode)"
                        } else {
                            "PipeWire recording failed with exit code $exitCode."
                        }
                    }
                } catch (e: Exception) {
                    outputFile.delete()
                    if (_recordingState.value.isRecording) {
                        _error.value = "PipeWire recording failed: ${e.message}"
                    }
                    _recordingState.value = VoiceRecordingState()
                } finally {
                    recordingTimerJob?.cancel()
                    recordingTimerJob = null
                    recordingProcess = null
                    restoreDefaultSourceVolume(previousSourceVolume)
                }
            }

            true
        }.getOrDefault(false)
    }

    private fun startRecordingTimer() {
        recordingTimerJob?.cancel()
        recordingTimerJob = viewModelScope.launch {
            while (_recordingState.value.isRecording) {
                delay(1000)
                val state = _recordingState.value
                if (state.isRecording) {
                    _recordingState.value = state.copy(elapsedSeconds = state.elapsedSeconds + 1)
                }
            }
        }
    }

    private fun validateRecordedWav(file: File): String? {
        if (!file.isFile || file.length() <= 44L) {
            return "Recording did not produce usable audio."
        }

        return try {
            AudioSystem.getAudioInputStream(file).use { input ->
                val format = input.format
                if (format.sampleSizeInBits != 16 || format.channels <= 0) {
                    return null
                }

                val buffer = ByteArray(recordingBufferBytes(format))
                var peak = 0
                var squareSum = 0.0
                var sampleCount = 0L
                var clippedSamples = 0L
                var bytesRead = 0L

                while (true) {
                    val read = input.read(buffer)
                    if (read <= 0) break
                    bytesRead += read
                    val stats = accumulatePcm16Stats(buffer, read)
                    peak = maxOf(peak, stats.peak)
                    squareSum += stats.squareSum
                    sampleCount += stats.sampleCount
                    clippedSamples += stats.clippedSamples
                }

                val minBytes = (format.frameRate * format.frameSize * MIN_RECORDING_SECONDS)
                    .toInt()
                    .coerceAtLeast(format.frameSize)
                val rms = if (sampleCount > 0L) kotlin.math.sqrt(squareSum / sampleCount) else 0.0

                when {
                    bytesRead < minBytes -> "Recording was too short."
                    sampleCount > 0L && clippedSamples.toDouble() / sampleCount > CLIPPING_SAMPLE_THRESHOLD ->
                        "Recording is clipping. Lower the system microphone input volume and try again."
                    peak < SILENCE_PEAK_THRESHOLD && rms < SILENCE_RMS_THRESHOLD ->
                        "Recording was silent. Check the selected system microphone input and capture level."
                    else -> null
                }
            }
        } catch (_: Exception) {
            null
        }
    }

    private fun postProcessRecording(file: File) {
        if (!isLinux() || !isExecutableOnPath("ffmpeg") || !file.isFile) return

        val processed = File(file.parentFile, "${file.nameWithoutExtension}.processed.wav")
        val success = runCatching {
            val process = ProcessBuilder(
                "ffmpeg",
                "-y",
                "-hide_banner",
                "-loglevel",
                "error",
                "-i",
                file.absolutePath,
                "-af",
                RECORDING_POST_PROCESS_FILTER,
                "-ar",
                "48000",
                "-ac",
                "1",
                "-c:a",
                "pcm_s16le",
                processed.absolutePath
            )
                .redirectOutput(ProcessBuilder.Redirect.DISCARD)
                .redirectError(ProcessBuilder.Redirect.DISCARD)
                .start()

            process.waitFor(20, TimeUnit.SECONDS) && process.exitValue() == 0 && processed.length() > 44L
        }.getOrDefault(false)

        if (success) {
            if (!processed.renameTo(file)) {
                runCatching {
                    processed.copyTo(file, overwrite = true)
                    processed.delete()
                }
            }
        } else {
            processed.delete()
        }
    }

    private fun lowerDefaultSourceVolumeForRecording(): Float? {
        if (!isLinux() || !isExecutableOnPath("wpctl")) return null

        val previous = readDefaultSourceVolume() ?: return null
        val target = minOf(previous, PIPEWIRE_SOURCE_RECORDING_VOLUME)
        if (target < previous) {
            setDefaultSourceVolume(target)
            println("[VoicesViewModel] Lowered PipeWire source volume from $previous to $target for recording.")
        }
        return previous
    }

    private fun restoreDefaultSourceVolume(previous: Float?) {
        if (previous == null || !isLinux() || !isExecutableOnPath("wpctl")) return
        setDefaultSourceVolume(previous)
    }

    private fun readDefaultSourceVolume(): Float? {
        return runCatching {
            val process = ProcessBuilder("wpctl", "get-volume", "@DEFAULT_AUDIO_SOURCE@")
                .redirectError(ProcessBuilder.Redirect.DISCARD)
                .start()
            val output = process.inputStream.bufferedReader().use { it.readText() }
            if (!process.waitFor(1, TimeUnit.SECONDS) || process.exitValue() != 0) return@runCatching null
            Regex("""Volume:\s*([0-9]+(?:\.[0-9]+)?)""")
                .find(output)
                ?.groupValues
                ?.getOrNull(1)
                ?.toFloatOrNull()
        }.getOrNull()
    }

    private fun setDefaultSourceVolume(volume: Float) {
        runCatching {
            ProcessBuilder("wpctl", "set-volume", "@DEFAULT_AUDIO_SOURCE@", volume.coerceIn(0f, 1f).toString())
                .redirectOutput(ProcessBuilder.Redirect.DISCARD)
                .redirectError(ProcessBuilder.Redirect.DISCARD)
                .start()
                .waitFor(1, TimeUnit.SECONDS)
        }
    }

    private fun isLinux(): Boolean {
        return System.getProperty("os.name").lowercase().contains("linux")
    }

    private fun isExecutableOnPath(name: String): Boolean {
        return System.getenv("PATH")
            ?.split(File.pathSeparator)
            ?.any { File(it, name).canExecute() }
            ?: false
    }

    private fun interruptProcess(process: Process) {
        if (!isLinux()) {
            process.destroy()
            return
        }

        val interrupted = runCatching {
            ProcessBuilder("kill", "-INT", process.pid().toString())
                .redirectOutput(ProcessBuilder.Redirect.DISCARD)
                .redirectError(ProcessBuilder.Redirect.DISCARD)
                .start()
                .waitFor(500, TimeUnit.MILLISECONDS)
        }.getOrDefault(false)

        if (!interrupted) {
            process.destroy()
        }
    }

    private fun recordingMixerRank(info: javax.sound.sampled.Mixer.Info): Int {
        val text = "${info.name} ${info.description}".lowercase()
        var score = 0
        if (text.contains("generic") || text.contains("analog")) score += 100
        if (text.contains("mic") || text.contains("capture") || text.contains("input")) score += 50
        if (text.contains("default") || text.contains("pulse") || text.contains("pipewire")) score += 40
        if (text.contains("monitor") || text.contains("loopback")) score -= 100
        if (text.contains("hdmi") || text.contains("nvidia")) score -= 50
        if (text.contains("port ")) score -= 25
        return score
    }

    private fun recordingBufferBytes(format: AudioFormat): Int {
        val frameSize = format.frameSize.coerceAtLeast(1)
        val frames = (format.frameRate * RECORDING_BUFFER_MILLIS / 1000)
            .toInt()
            .coerceAtLeast(1024)
        return frames * frameSize
    }

    private data class PcmStats(
        val peak: Int,
        val squareSum: Double,
        val sampleCount: Long,
        val clippedSamples: Long
    )

    private fun accumulatePcm16Stats(bytes: ByteArray, byteCount: Int): PcmStats {
        var peak = 0
        var squareSum = 0.0
        var sampleCount = 0L
        var clippedSamples = 0L
        var i = 0
        while (i + 1 < byteCount) {
            val sample = ((bytes[i + 1].toInt() shl 8) or (bytes[i].toInt() and 0xFF)).toShort().toInt()
            val abs = kotlin.math.abs(sample)
            peak = maxOf(peak, abs)
            squareSum += sample.toDouble() * sample.toDouble()
            if (abs >= 32760) {
                clippedSamples++
            }
            sampleCount++
            i += 2
        }
        return PcmStats(peak, squareSum, sampleCount, clippedSamples)
    }

    fun releaseEngine() {
        viewModelScope.launch(nativeDispatcher) {
            qwenEngine.release()
        }
    }

    override fun onCleared() {
        super.onCleared()
        stopRecording()
        recordingJob?.cancel()
        recordingTimerJob?.cancel()
        qwenEngine.release()
        nativeDispatcher.close()
    }
}
