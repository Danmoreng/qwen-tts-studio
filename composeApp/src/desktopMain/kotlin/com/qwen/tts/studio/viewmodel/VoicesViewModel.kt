package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.qwen.tts.studio.engine.QwenEngine
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.asCoroutineDispatcher
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.io.File
import java.util.concurrent.Executors
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
 * @property speakerEmbeddingPath Optional path to an extracted speaker embedding file.
 * @property embeddingDim The dimension of the speaker embedding, if known.
 */
data class VoicePreset(
    val id: String,
    val name: String,
    val referenceWav: String?,
    val speakerEmbeddingPath: String?,
    val embeddingDim: Int? = null
) {
    /** Whether this is a built-in system voice (not a custom preset). */
    val isSystem: Boolean = referenceWav == null && speakerEmbeddingPath == null
}

data class VoiceRecordingState(
    val isRecording: Boolean = false,
    val elapsedSeconds: Int = 0,
    val lastRecordingPath: String? = null
)

/**
 * ViewModel for managing custom voice presets and speaker embedding extraction.
 */
class VoicesViewModel : ViewModel() {
    private val defaultVoice = VoicePreset(
        id = "default",
        name = "Default Voice (Model)",
        referenceWav = null,
        speakerEmbeddingPath = null
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

    /**
     * Refreshes model capabilities to update cloning support and embedding dimensions.
     *
     * @param modelDir Directory containing the models.
     * @param modelName Optional specific model name.
     */
    fun refreshModelCapabilities(modelDir: String, modelName: String?) {
        if (modelDir.isBlank()) return
        viewModelScope.launch(Dispatchers.IO) {
            val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
            val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, resolvedModelName) }
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
    fun createVoicePreset(name: String, referenceWav: String, modelDir: String, modelName: String?) {
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
        viewModelScope.launch {
            try {
                val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
                val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, resolvedModelName) }
                if (!loaded) {
                    _error.value = "Failed to load Qwen3 models for speaker embedding extraction."
                    return@launch
                }

                val caps = withContext(nativeDispatcher) { qwenEngine.getModelCapabilities() }
                val supportsCloning = caps?.supportsCloning ?: true
                val embeddingDim = caps?.speakerEmbeddingDim ?: 0
                _supportsCloning.value = supportsCloning
                _currentEmbeddingDim.value = embeddingDim
                if (!supportsCloning) {
                    _error.value = "Current model does not support custom voice cloning."
                    return@launch
                }

                val embeddingFile = withContext(Dispatchers.IO) {
                    val embeddingsDir = File(
                        File(System.getProperty("user.home"), ".qwen-tts-studio"),
                        "embeddings"
                    )
                    embeddingsDir.mkdirs()
                    val dimSuffix = if (embeddingDim > 0) "-d$embeddingDim" else ""
                    File(embeddingsDir, "$voiceId$dimSuffix.json")
                }

                val extracted = withContext(nativeDispatcher) {
                    qwenEngine.extractSpeakerEmbedding(wavFile.absolutePath, embeddingFile.absolutePath)
                }
                if (!extracted) {
                    _error.value = "Failed to extract speaker embedding from reference audio."
                    return@launch
                }

                val preset = VoicePreset(
                    id = voiceId,
                    name = uniqueName,
                    referenceWav = wavFile.absolutePath,
                    speakerEmbeddingPath = embeddingFile.absolutePath,
                    embeddingDim = embeddingDim.takeIf { it > 0 }
                )
                _voices.value = _voices.value + preset
                saveVoices()
                _error.value = null
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

        try {
            val line = openRecordingLine()
            recordingLine = line
            line.start()
            _recordingState.value = VoiceRecordingState(isRecording = true)

            recordingTimerJob = viewModelScope.launch {
                while (_recordingState.value.isRecording) {
                    delay(1000)
                    val state = _recordingState.value
                    if (state.isRecording) {
                        _recordingState.value = state.copy(elapsedSeconds = state.elapsedSeconds + 1)
                    }
                }
            }

            recordingJob = viewModelScope.launch(Dispatchers.IO) {
                try {
                    AudioInputStream(line).use { stream ->
                        AudioSystem.write(stream, AudioFileFormat.Type.WAVE, outputFile)
                    }

                    if (outputFile.isFile && outputFile.length() > 44L) {
                        _recordingState.value = _recordingState.value.copy(
                            isRecording = false,
                            lastRecordingPath = outputFile.absolutePath
                        )
                    } else {
                        outputFile.delete()
                        _recordingState.value = VoiceRecordingState()
                        _error.value = "Recording did not produce usable audio."
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
                    runCatching { line.close() }
                }
            }
        } catch (e: Exception) {
            _recordingState.value = VoiceRecordingState()
            _error.value = "Could not start microphone recording: ${e.message}"
        }
    }

    fun stopRecording() {
        val line = recordingLine ?: return
        _recordingState.value = _recordingState.value.copy(isRecording = false)
        runCatching { line.stop() }
        runCatching { line.close() }
    }

    /**
     * Deletes a custom voice preset.
     *
     * @param id The unique identifier of the preset to delete.
     */
    fun deleteVoicePreset(id: String) {
        val target = _voices.value.firstOrNull { it.id == id } ?: return
        if (target.isSystem) return

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
        val embedding = preset.speakerEmbeddingPath ?: return null
        if (expectedDim <= 0) return embedding
        val dim = preset.embeddingDim ?: inferSpeakerEmbeddingDim(embedding) ?: return null
        return if (dim == expectedDim) embedding else null
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
                    if (parts.size >= 4) {
                        val embedding = parts[2].ifBlank { null }
                        val wav = parts[3].ifBlank { null }
                        val dim = parts.getOrNull(4)?.toIntOrNull() ?: embedding?.let(::inferSpeakerEmbeddingDim)
                        VoicePreset(id = id, name = name, referenceWav = wav, speakerEmbeddingPath = embedding, embeddingDim = dim)
                    } else {
                        val wav = parts.getOrNull(2).orEmpty()
                        if (wav.isBlank()) return@mapNotNull null
                        VoicePreset(id = id, name = name, referenceWav = wav, speakerEmbeddingPath = null)
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
                "${it.id}\t${it.name}\t${it.speakerEmbeddingPath.orEmpty()}\t${it.referenceWav.orEmpty()}\t${it.embeddingDim?.toString().orEmpty()}"
            }
        storageFile.writeText(lines.joinToString(System.lineSeparator()))
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

    private fun openRecordingLine(): TargetDataLine {
        val formats = listOf(
            AudioFormat(16_000f, 16, 1, true, false),
            AudioFormat(24_000f, 16, 1, true, false),
            AudioFormat(44_100f, 16, 1, true, false),
            AudioFormat(48_000f, 16, 1, true, false)
        )

        for (format in formats) {
            val info = DataLine.Info(TargetDataLine::class.java, format)
            runCatching {
                val line = AudioSystem.getLine(info) as TargetDataLine
                line.open(format)
                return line
            }

            for (mixerInfo in AudioSystem.getMixerInfo()) {
                runCatching {
                    val mixer = AudioSystem.getMixer(mixerInfo)
                    if (!mixer.isLineSupported(info)) return@runCatching
                    val line = mixer.getLine(info) as TargetDataLine
                    line.open(format)
                    return line
                }
            }
        }

        throw IllegalStateException("No supported microphone input line was found.")
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
