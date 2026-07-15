package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.qwen.tts.studio.embedding.EmbeddingArithmetic
import com.qwen.tts.studio.engine.NativeBackendPreference
import com.qwen.tts.studio.engine.QwenEngine
import kotlinx.coroutines.CancellationException
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
import java.nio.file.AtomicMoveNotSupportedException
import java.nio.file.Files
import java.nio.file.StandardCopyOption
import java.util.Base64
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit
import java.util.concurrent.atomic.AtomicLong
import javax.sound.sampled.AudioFileFormat
import javax.sound.sampled.AudioFormat
import javax.sound.sampled.AudioInputStream
import javax.sound.sampled.AudioSystem
import javax.sound.sampled.DataLine
import javax.sound.sampled.SourceDataLine
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

sealed interface VoiceLabRecipe {
    val normalize: Boolean

    data class WeightedMean(
        val sources: List<EmbeddingBlendSource>,
        override val normalize: Boolean
    ) : VoiceLabRecipe
}

data class LoadedVoiceEmbedding(
    val voiceId: String,
    val name: String,
    val dimension: Int,
    val values: FloatArray
)

data class VoiceLabPreviewState(
    val isGenerating: Boolean = false,
    val isPlaying: Boolean = false,
    val hasAudio: Boolean = false,
    val durationSeconds: Float = 0f,
    val waveform: List<Float> = emptyList(),
    val error: String? = null
)

private enum class VoiceEngineSessionKind {
    Talker,
    IclPromptEncoder
}

private data class VoiceEngineSessionKey(
    val modelDirectory: String,
    val modelName: String?,
    val backendPreference: NativeBackendPreference,
    val kind: VoiceEngineSessionKind
)

/**
 * ViewModel for managing custom voice presets and speaker embedding extraction.
 */
class VoicesViewModel(initialAppDir: String = defaultAppDirectory().absolutePath) : ViewModel() {
    private val defaultVoice = VoicePreset(
        id = "default",
        name = "Default Voice (Model)",
        referenceWav = null
    )

    private var appDirectory = resolveAppDirectory(initialAppDir)

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

    private val _voiceLabPreviewState = MutableStateFlow(VoiceLabPreviewState())
    val voiceLabPreviewState: StateFlow<VoiceLabPreviewState> = _voiceLabPreviewState.asStateFlow()

    private val qwenEngine = QwenEngine()
    private val nativeExecutor = Executors.newSingleThreadExecutor { runnable ->
        Thread(null, runnable, "QwenVoicePresetThread", 8L * 1024 * 1024).apply {
            isDaemon = true
        }
    }
    private val nativeDispatcher = nativeExecutor.asCoroutineDispatcher()
    private var loadedEngineSession: VoiceEngineSessionKey? = null
    private var recordingJob: Job? = null
    private var recordingTimerJob: Job? = null
    private var previewGenerationJob: Job? = null
    private var previewPlaybackJob: Job? = null
    private val previewRequestVersion = AtomicLong(0L)
    private val previewPlaybackVersion = AtomicLong(0L)
    private var previewAudio: FloatArray? = null
    @Volatile
    private var recordingLine: TargetDataLine? = null
    @Volatile
    private var recordingProcess: Process? = null
    @Volatile
    private var previewPlaybackLine: SourceDataLine? = null

    private companion object {
        private const val RECORDING_BUFFER_MILLIS = 100
        private const val MIN_RECORDING_SECONDS = 0.25
        private const val SILENCE_PEAK_THRESHOLD = 128
        private const val SILENCE_RMS_THRESHOLD = 8.0
        private const val PIPEWIRE_SOURCE_RECORDING_VOLUME = 0.05f
        private const val CLIPPING_SAMPLE_THRESHOLD = 0.01
        private const val RECORDING_POST_PROCESS_FILTER = "highpass=f=90,lowpass=f=9000,loudnorm=I=-18:TP=-3:LRA=11,aresample=48000"
        private const val PREVIEW_SAMPLE_RATE = 24_000
        private const val PREVIEW_PLAYBACK_CHUNK_SAMPLES = 1_024
        private const val PREVIEW_WAVEFORM_BUCKETS = 96

        private fun defaultAppDirectory(): File =
            File(System.getProperty("user.home"), ".qwen-tts-studio")

        private fun resolveAppDirectory(path: String): File =
            File(path.trim().ifBlank { defaultAppDirectory().absolutePath }).absoluteFile
    }

    fun setAppDir(path: String) {
        val next = resolveAppDirectory(path)
        if (next == appDirectory) return
        invalidateVoiceLabPreview()
        appDirectory = next
        _voices.value = loadVoices()
        _error.value = null
    }

    private fun loadTalkerEngine(
        modelDir: String,
        modelName: String?,
        backendPreference: NativeBackendPreference
    ): Boolean = loadEngineSession(
        modelDir = modelDir,
        modelName = modelName,
        backendPreference = backendPreference,
        kind = VoiceEngineSessionKind.Talker
    )

    private fun loadIclPromptEngine(
        modelDir: String,
        modelName: String?,
        backendPreference: NativeBackendPreference
    ): Boolean = loadEngineSession(
        modelDir = modelDir,
        modelName = modelName,
        backendPreference = backendPreference,
        kind = VoiceEngineSessionKind.IclPromptEncoder
    )

    private fun loadEngineSession(
        modelDir: String,
        modelName: String?,
        backendPreference: NativeBackendPreference,
        kind: VoiceEngineSessionKind
    ): Boolean {
        val normalizedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
        val requestedSession = VoiceEngineSessionKey(
            modelDirectory = File(modelDir).absolutePath,
            modelName = normalizedModelName,
            backendPreference = backendPreference,
            kind = kind
        )
        if (loadedEngineSession == requestedSession) return true

        loadedEngineSession = null
        val loaded = when (kind) {
            VoiceEngineSessionKind.Talker ->
                qwenEngine.load(modelDir, normalizedModelName, backendPreference)
            VoiceEngineSessionKind.IclPromptEncoder ->
                qwenEngine.loadIclPromptEncoder(modelDir, normalizedModelName, backendPreference)
        }
        if (loaded) loadedEngineSession = requestedSession
        return loaded
    }

    private fun releaseLoadedEngine() {
        loadedEngineSession = null
        qwenEngine.release()
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
            val loaded = withContext(nativeDispatcher) {
                loadTalkerEngine(modelDir, resolvedModelName, backendPreference)
            }
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

                    val loaded = withContext(nativeDispatcher) {
                        loadTalkerEngine(modelDir, targetModel, backendPreference)
                    }
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
                            loadIclPromptEngine(modelDir, targetModel, backendPreference)
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
                    val loaded = withContext(nativeDispatcher) {
                        loadTalkerEngine(modelDir, targetModel, backendPreference)
                    }
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
                        loadIclPromptEngine(modelDir, targetModel, backendPreference)
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
        val recordingsDir = recordingsDirectory().apply { mkdirs() }
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

    suspend fun loadVoiceLabEmbeddings(
        voiceIds: List<String>,
        dimension: Int
    ): Result<List<LoadedVoiceEmbedding>> = withContext(Dispatchers.IO) {
        runCatching {
            require(dimension == 1024 || dimension == 2048) { "Unsupported embedding dimension D$dimension." }
            val presetsById = _voices.value.associateBy { it.id }
            voiceIds.map { voiceId ->
                val preset = presetsById[voiceId]
                    ?: throw IllegalArgumentException("Selected voice no longer exists.")
                require(!preset.isSystem) { "System voices do not expose speaker embeddings." }
                val path = preset.speakerEmbeddings[dimension]
                    ?: throw IllegalArgumentException("${preset.name} has no D$dimension embedding.")
                val values = loadSpeakerEmbedding(path)
                require(values.size == dimension) {
                    "${preset.name} has a ${values.size}-value embedding, expected D$dimension."
                }
                LoadedVoiceEmbedding(
                    voiceId = preset.id,
                    name = preset.name,
                    dimension = dimension,
                    values = values
                )
            }
        }
    }

    fun generateVoiceLabPreview(
        recipe: VoiceLabRecipe,
        text: String,
        language: String,
        modelDir: String,
        modelName: String?,
        backendPreference: NativeBackendPreference
    ) {
        val previewText = text.trim()
        if (previewText.isBlank()) {
            _voiceLabPreviewState.value = VoiceLabPreviewState(error = "Preview text is required.")
            return
        }
        if (modelDir.isBlank()) {
            _voiceLabPreviewState.value = VoiceLabPreviewState(error = "Select a model directory in Setup first.")
            return
        }
        if (_isCreating.value || _voiceLabPreviewState.value.isGenerating) return

        invalidateVoiceLabPreview()
        val requestId = previewRequestVersion.incrementAndGet()
        _voiceLabPreviewState.value = VoiceLabPreviewState(isGenerating = true)

        previewGenerationJob = viewModelScope.launch(Dispatchers.IO) {
            var temporaryEmbedding: File? = null
            try {
                val audio = withContext(nativeDispatcher) {
                    val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
                    val loaded = loadTalkerEngine(modelDir, resolvedModelName, backendPreference)
                    if (!loaded) {
                        throw IllegalStateException("Failed to load Qwen3 models from the selected directory.")
                    }

                    val capabilities = qwenEngine.getModelCapabilities()
                        ?: throw IllegalStateException("Could not read model capabilities.")
                    _supportsCloning.value = capabilities.supportsCloning
                    _currentEmbeddingDim.value = capabilities.speakerEmbeddingDim

                    if (!capabilities.supportsCloning) {
                        throw IllegalArgumentException("Voice Lab preview requires a Qwen3-TTS Base model with cloning support.")
                    }
                    val dimension = capabilities.speakerEmbeddingDim
                    if (dimension != 1024 && dimension != 2048) {
                        throw IllegalArgumentException(
                            "The selected model reports an unsupported speaker dimension: D$dimension."
                        )
                    }

                    val embedding = buildVoiceLabEmbedding(recipe, dimension)
                    val previewDirectory = File(appDirectory, "preview").apply { mkdirs() }
                    val temporaryFile = File.createTempFile("voice-lab-", ".json", previewDirectory)
                    temporaryEmbedding = temporaryFile
                    saveSpeakerEmbeddingJson(temporaryFile, embedding)

                    qwenEngine.generate(
                        text = previewText,
                        referenceWav = null,
                        speakerEmbeddingPath = temporaryFile.absolutePath,
                        iclPromptPath = null,
                        languageId = QwenEngine.mapLanguageToId(language),
                        instruction = null,
                        speaker = null
                    )
                }?.takeIf { it.isNotEmpty() }
                    ?: throw IllegalStateException("Preview synthesis failed.")

                if (requestId != previewRequestVersion.get()) return@launch
                previewAudio = audio
                _voiceLabPreviewState.value = VoiceLabPreviewState(
                    isGenerating = false,
                    hasAudio = true,
                    durationSeconds = audio.size.toFloat() / PREVIEW_SAMPLE_RATE,
                    waveform = downsampleWaveform(audio, PREVIEW_WAVEFORM_BUCKETS)
                )
                startVoiceLabPreviewPlayback(audio, requiredPreviewRequestId = requestId)
            } catch (e: CancellationException) {
                throw e
            } catch (e: Exception) {
                if (requestId == previewRequestVersion.get()) {
                    _voiceLabPreviewState.value = VoiceLabPreviewState(
                        error = e.message ?: "Voice preview failed."
                    )
                }
            } finally {
                temporaryEmbedding?.let { file -> runCatching { file.delete() } }
                if (requestId == previewRequestVersion.get()) {
                    _voiceLabPreviewState.value = _voiceLabPreviewState.value.copy(isGenerating = false)
                }
            }
        }
    }

    fun replayVoiceLabPreview() {
        val audio = previewAudio ?: return
        if (audio.isNotEmpty()) startVoiceLabPreviewPlayback(audio)
    }

    fun stopVoiceLabPreview() {
        previewPlaybackVersion.incrementAndGet()
        previewPlaybackJob?.cancel()
        previewPlaybackJob = null
        runCatching { previewPlaybackLine?.stop() }
        runCatching { previewPlaybackLine?.flush() }
        runCatching { previewPlaybackLine?.close() }
        previewPlaybackLine = null
        _voiceLabPreviewState.value = _voiceLabPreviewState.value.copy(isPlaying = false)
    }

    fun invalidateVoiceLabPreview() {
        previewRequestVersion.incrementAndGet()
        previewGenerationJob?.cancel()
        previewGenerationJob = null
        stopVoiceLabPreview()
        previewAudio = null
        _voiceLabPreviewState.value = VoiceLabPreviewState()
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

        if (sources.any { !it.weight.isFinite() || it.weight < 0f }) {
            _error.value = "Voice weights must be finite and non-negative."
            return
        }

        if (sources.map { it.voiceId }.filter { it.isNotBlank() }.distinct().size < 2) {
            _error.value = "Select at least two voices."
            return
        }
        val activeSources = sources.filter { it.weight > 0f }
        if (activeSources.isEmpty()) {
            _error.value = "At least one voice needs a positive weight."
            return
        }

        _isCreating.value = true
        _error.value = null

        viewModelScope.launch(Dispatchers.IO) {
            val createdFiles = mutableListOf<File>()
            var addedVoiceId: String? = null
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
                    val mixed = buildVoiceLabEmbedding(
                        recipe = VoiceLabRecipe.WeightedMean(sources, normalize),
                        dimension = dim
                    )
                    val embeddingFile = File(embeddingsDir, "$voiceId-d$dim.json")
                    createdFiles += embeddingFile
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
                addedVoiceId = voiceId
                saveVoices()
                _error.value = null
            } catch (e: Exception) {
                addedVoiceId?.let { id ->
                    _voices.value = _voices.value.filterNot { it.id == id }
                }
                createdFiles.forEach { file -> runCatching { file.delete() } }
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
        val storageFile = storageFile()
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
        val storageFile = storageFile()
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
        val contents = lines.joinToString(System.lineSeparator())
        val tempFile = File(storageFile.parentFile, "${storageFile.name}.tmp-${System.nanoTime()}")
        try {
            tempFile.writeText(contents)
            try {
                Files.move(
                    tempFile.toPath(),
                    storageFile.toPath(),
                    StandardCopyOption.ATOMIC_MOVE,
                    StandardCopyOption.REPLACE_EXISTING
                )
            } catch (_: AtomicMoveNotSupportedException) {
                Files.move(
                    tempFile.toPath(),
                    storageFile.toPath(),
                    StandardCopyOption.REPLACE_EXISTING
                )
            }
        } finally {
            if (tempFile.exists()) tempFile.delete()
        }
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
        return File(appDirectory, "embeddings")
    }

    private fun iclPromptsDirectory(): File {
        return File(appDirectory, "icl-prompts")
    }

    private fun recordingsDirectory(): File {
        return File(appDirectory, "recordings")
    }

    private fun storageFile(): File {
        return File(appDirectory, "voice-presets.tsv")
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

    private fun buildVoiceLabEmbedding(recipe: VoiceLabRecipe, dimension: Int): FloatArray {
        require(dimension == 1024 || dimension == 2048) { "Unsupported embedding dimension D$dimension." }
        val presetsById = _voices.value.associateBy { it.id }

        fun loadForVoice(voiceId: String): FloatArray {
            val preset = presetsById[voiceId]
                ?: throw IllegalArgumentException("Selected voice no longer exists.")
            require(!preset.isSystem) { "Only custom speaker presets can be used in the Voice Lab." }
            val path = preset.speakerEmbeddings[dimension]
                ?: throw IllegalArgumentException("${preset.name} has no D$dimension embedding.")
            return loadSpeakerEmbedding(path).also { vector ->
                require(vector.size == dimension) {
                    "${preset.name} has a ${vector.size}-value embedding, expected D$dimension."
                }
            }
        }

        return when (recipe) {
            is VoiceLabRecipe.WeightedMean -> {
                require(recipe.sources.map { it.voiceId }.filter { it.isNotBlank() }.distinct().size >= 2) {
                    "Select at least two different voices."
                }
                require(recipe.sources.all { it.weight.isFinite() && it.weight >= 0f }) {
                    "Voice weights must be finite and non-negative."
                }
                val activeSources = recipe.sources.filter { it.weight > 0f }
                require(activeSources.isNotEmpty()) { "At least one voice needs a positive weight." }
                EmbeddingArithmetic.weightedMean(
                    vectors = activeSources.map { source ->
                        EmbeddingArithmetic.WeightedVector(source.weight, loadForVoice(source.voiceId))
                    },
                    preserveAverageNorm = recipe.normalize
                )
            }

        }
    }

    private fun startVoiceLabPreviewPlayback(
        samples: FloatArray,
        requiredPreviewRequestId: Long? = null
    ) {
        if (samples.isEmpty()) return
        if (requiredPreviewRequestId != null && requiredPreviewRequestId != previewRequestVersion.get()) return
        stopVoiceLabPreview()
        val playbackId = previewPlaybackVersion.incrementAndGet()

        previewPlaybackJob = viewModelScope.launch(Dispatchers.IO) {
            var line: SourceDataLine? = null
            try {
                if (requiredPreviewRequestId != null && requiredPreviewRequestId != previewRequestVersion.get()) {
                    return@launch
                }
                val format = AudioFormat(PREVIEW_SAMPLE_RATE.toFloat(), 16, 1, true, false)
                val lineInfo = DataLine.Info(SourceDataLine::class.java, format)
                val mixer = findPreviewPlaybackMixer(format)
                line = if (mixer != null) {
                    mixer.getLine(lineInfo) as SourceDataLine
                } else {
                    AudioSystem.getLine(lineInfo) as SourceDataLine
                }
                previewPlaybackLine = line
                val bufferBytes = maxOf(4_096, PREVIEW_SAMPLE_RATE * format.frameSize / 4)
                line.open(format, bufferBytes)
                line.start()
                if (playbackId == previewPlaybackVersion.get()) {
                    _voiceLabPreviewState.value = _voiceLabPreviewState.value.copy(isPlaying = true, error = null)
                }

                val pcmBuffer = ByteArray(PREVIEW_PLAYBACK_CHUNK_SAMPLES * 2)
                var position = 0
                while (
                    isActive &&
                    playbackId == previewPlaybackVersion.get() &&
                    (requiredPreviewRequestId == null || requiredPreviewRequestId == previewRequestVersion.get()) &&
                    position < samples.size
                ) {
                    val sampleCount = minOf(PREVIEW_PLAYBACK_CHUNK_SAMPLES, samples.size - position)
                    fillPreviewPcm16(samples, position, sampleCount, pcmBuffer)
                    line.write(pcmBuffer, 0, sampleCount * 2)
                    position += sampleCount
                }
                if (isActive) line.drain()
            } catch (e: CancellationException) {
                throw e
            } catch (e: Exception) {
                if (playbackId == previewPlaybackVersion.get()) {
                    _voiceLabPreviewState.value = _voiceLabPreviewState.value.copy(
                        isPlaying = false,
                        error = "Preview was generated, but playback failed: ${e.message}"
                    )
                }
            } finally {
                runCatching { line?.stop() }
                runCatching { line?.flush() }
                runCatching { line?.close() }
                if (previewPlaybackLine == line) previewPlaybackLine = null
                if (playbackId == previewPlaybackVersion.get()) {
                    previewPlaybackJob = null
                    _voiceLabPreviewState.value = _voiceLabPreviewState.value.copy(isPlaying = false)
                }
            }
        }
    }

    private fun findPreviewPlaybackMixer(format: AudioFormat): javax.sound.sampled.Mixer? {
        return AudioSystem.getMixerInfo()
            .sortedByDescending { info ->
                val name = info.name.lowercase()
                when {
                    name.contains("pulse") || name.contains("pipewire") || name.contains("default") -> 100
                    name.contains("groove") -> 90
                    name.contains("analog") || name.contains("generic") -> 50
                    else -> 0
                }
            }
            .firstNotNullOfOrNull { info ->
                runCatching {
                    val mixer = AudioSystem.getMixer(info)
                    val lineInfo = DataLine.Info(SourceDataLine::class.java, format)
                    mixer.takeIf { it.isLineSupported(lineInfo) }
                }.getOrNull()
            }
    }

    private fun fillPreviewPcm16(
        samples: FloatArray,
        start: Int,
        sampleCount: Int,
        destination: ByteArray
    ) {
        for (offset in 0 until sampleCount) {
            val pcm = (samples[start + offset].coerceIn(-1f, 1f) * 32767f).toInt()
            destination[offset * 2] = (pcm and 0xFF).toByte()
            destination[offset * 2 + 1] = ((pcm ushr 8) and 0xFF).toByte()
        }
    }

    private fun downsampleWaveform(samples: FloatArray, requestedBuckets: Int): List<Float> {
        if (samples.isEmpty() || requestedBuckets <= 0) return emptyList()
        val bucketCount = minOf(requestedBuckets, samples.size)
        return List(bucketCount) { bucketIndex ->
            val start = bucketIndex * samples.size / bucketCount
            val end = maxOf(start + 1, (bucketIndex + 1) * samples.size / bucketCount)
            var peak = 0f
            for (index in start until end) {
                peak = maxOf(peak, kotlin.math.abs(samples[index]))
            }
            peak.coerceIn(0f, 1f)
        }
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
        invalidateVoiceLabPreview()
        viewModelScope.launch(nativeDispatcher) {
            releaseLoadedEngine()
        }
    }

    override fun onCleared() {
        super.onCleared()
        stopRecording()
        recordingJob?.cancel()
        recordingTimerJob?.cancel()
        invalidateVoiceLabPreview()
        nativeExecutor.execute { runCatching { releaseLoadedEngine() } }
        nativeExecutor.shutdown()
    }
}
