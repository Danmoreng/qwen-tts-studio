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
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.isActive
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.io.ByteArrayInputStream
import java.io.File
import java.util.concurrent.Executors
import javax.sound.sampled.AudioFileFormat
import javax.sound.sampled.AudioFormat
import javax.sound.sampled.AudioInputStream
import javax.sound.sampled.AudioSystem
import javax.sound.sampled.DataLine
import javax.sound.sampled.Mixer
import javax.sound.sampled.SourceDataLine

/**
 * UI state for the Studio screen.
 *
 * @property text The current text to be synthesized.
 * @property selectedVoice The currently selected voice profile or model name.
 * @property availableSpeakers List of speaker names available in the current model.
 * @property selectedSpeaker The currently selected speaker name.
 * @property supportsCloning Whether the current model supports voice cloning.
 * @property supportsNamedSpeakers Whether the current model supports selecting speakers by name.
 * @property supportsInstruction Whether the current model supports text instructions.
 * @property speakerEmbeddingDim The dimension of speaker embeddings for the current model.
 * @property modelKind The kind of model currently loaded.
 * @property selectedLanguage The currently selected language for synthesis.
 * @property selectedInstruction The current instruction text for the model.
 * @property isGenerating Whether an audio generation process is currently active.
 * @property isPlaying Whether audio is currently being played.
 * @property isSaving Whether the generated audio is currently being saved to a file.
 * @property hasAudio Whether there is generated audio available to play or save.
 * @property playbackPositionSeconds The current playback position in seconds.
 * @property playbackDurationSeconds The generated audio duration in seconds.
 * @property progress Generation progress (0.0 to 1.0).
 * @property error Current error message, if any.
 */
data class StudioUiState(
    val text: String = "Another test bites the dust.",
    val selectedVoice: String = "Default Voice (Model)",
    val availableSpeakers: List<String> = emptyList(),
    val selectedSpeaker: String = "",
    val supportsCloning: Boolean = true,
    val supportsNamedSpeakers: Boolean = false,
    val supportsInstruction: Boolean = false,
    val speakerEmbeddingDim: Int = 0,
    val modelKind: Int = QwenEngine.MODEL_KIND_UNKNOWN,
    val selectedLanguage: String = "English",
    val selectedInstruction: String = "",
    val isGenerating: Boolean = false,
    val isPlaying: Boolean = false,
    val isSaving: Boolean = false,
    val hasAudio: Boolean = false,
    val playbackPositionSeconds: Float = 0f,
    val playbackDurationSeconds: Float = 0f,
    val progress: Float = 0f,
    val error: String? = null
)

/**
 * ViewModel for the Studio screen, managing audio generation, playback, and state.
 */
class StudioViewModel : ViewModel() {
    private val _uiState = MutableStateFlow(StudioUiState())
    /** The current UI state as a StateFlow. */
    val uiState: StateFlow<StudioUiState> = _uiState.asStateFlow()

    private val qwenEngine = QwenEngine()
    private var lastGeneratedAudio: FloatArray? = null
    private var playbackJob: Job? = null
    @Volatile
    private var playbackRequestedPosition: Int? = null
    @Volatile
    private var playbackPositionSample: Int = 0
    @Volatile
    private var playbackPaused: Boolean = false
    @Volatile
    private var playbackLine: SourceDataLine? = null
    private val nativeDispatcher = Executors.newSingleThreadExecutor { runnable ->
        Thread(null, runnable, "QwenNativeThread", 8L * 1024 * 1024).apply {
            isDaemon = true
        }
    }.asCoroutineDispatcher()

    private companion object {
        private const val AUDIO_SAMPLE_RATE = 24_000
        private const val PLAYBACK_CHUNK_SAMPLES = 1_024
    }

    /**
     * Updates the text to be synthesized.
     *
     * @param newText The new text.
     */
    fun onTextChange(newText: String) {
        if (newText.length <= 5000) {
            _uiState.update { it.copy(text = newText, error = null) }
        }
    }

    /**
     * Updates the selected voice.
     *
     * @param newVoice The new voice name.
     */
    fun onVoiceChange(newVoice: String) {
        _uiState.update { it.copy(selectedVoice = newVoice) }
    }

    /**
     * Updates the selected speaker.
     *
     * @param newSpeaker The new speaker name.
     */
    fun onSpeakerChange(newSpeaker: String) {
        _uiState.update { it.copy(selectedSpeaker = newSpeaker) }
    }

    /**
     * Updates the selected language.
     *
     * @param newLanguage The new language name.
     */
    fun onLanguageChange(newLanguage: String) {
        _uiState.update { it.copy(selectedLanguage = newLanguage) }
    }

    /**
     * Updates the selected instruction.
     *
     * @param newInstruction The new instruction text.
     */
    fun onInstructionChange(newInstruction: String) {
        _uiState.update { it.copy(selectedInstruction = newInstruction) }
    }

    private fun applyCapabilitiesAndSpeakers(
        caps: QwenEngine.NativeCapabilities?,
        speakers: List<String>
    ) {
        _uiState.update { state ->
            val supportsCloning = caps?.supportsCloning ?: true
            val supportsNamedSpeakers = caps?.supportsNamedSpeakers ?: false
            val supportsInstruction = caps?.supportsInstruction ?: false
            val allowedSpeakers = if (supportsNamedSpeakers) speakers.distinct() else emptyList()
            val nextSpeaker = if (supportsNamedSpeakers && allowedSpeakers.isNotEmpty()) {
                state.selectedSpeaker.takeIf { it.isNotBlank() && allowedSpeakers.contains(it) } ?: allowedSpeakers.first()
            } else {
                ""
            }
            state.copy(
                supportsCloning = supportsCloning,
                supportsNamedSpeakers = supportsNamedSpeakers,
                supportsInstruction = supportsInstruction,
                speakerEmbeddingDim = caps?.speakerEmbeddingDim ?: 0,
                modelKind = caps?.modelKind ?: QwenEngine.MODEL_KIND_UNKNOWN,
                availableSpeakers = allowedSpeakers,
                selectedSpeaker = if (supportsNamedSpeakers) nextSpeaker else "",
                selectedInstruction = if (supportsInstruction) state.selectedInstruction else ""
            )
        }
    }

    /**
     * Generates audio using the current UI state and provided model/speaker information.
     *
     * @param modelDir Directory containing the models.
     * @param modelName Optional specific model name.
     * @param speakerEmbeddingPath Optional path to a speaker embedding file.
     */
    fun generateAudio(
        modelDir: String,
        modelName: String?,
        speakerEmbeddingPath: String?
    ) {
        val currentState = _uiState.value
        if (currentState.text.isBlank() || currentState.isGenerating) return
        if (modelDir.isBlank()) {
            _uiState.update { it.copy(error = "Please select the Model Directory in Setup.") }
            return
        }

        viewModelScope.launch {
            stopPlayback(resetPosition = true)
            _uiState.update {
                it.copy(
                    isGenerating = true,
                    error = null,
                    hasAudio = false,
                    playbackPositionSeconds = 0f,
                    playbackDurationSeconds = 0f
                )
            }

            try {
                withContext(Dispatchers.IO) {
                    val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
                    val loaded = withContext(nativeDispatcher) {
                        qwenEngine.load(modelDir, resolvedModelName)
                    }
                    if (!loaded) {
                        throw Exception("Failed to load Qwen3 models from directory.")
                    }

                    val caps = withContext(nativeDispatcher) { qwenEngine.getModelCapabilities() }
                    val speakers = if (caps?.supportsNamedSpeakers == true) {
                        withContext(nativeDispatcher) { qwenEngine.getAvailableSpeakers() }
                    } else {
                        emptyList()
                    }
                    applyCapabilitiesAndSpeakers(caps, speakers)

                    val latestState = _uiState.value
                    val langId = QwenEngine.mapLanguageToId(latestState.selectedLanguage)
                    val selectedSpeaker = latestState.selectedSpeaker.takeIf { it.isNotBlank() }
                    val useNamedSpeaker = latestState.supportsNamedSpeakers && selectedSpeaker != null
                    val effectiveSpeaker = if (useNamedSpeaker) {
                        selectedSpeaker
                    } else {
                        null
                    }
                    val effectiveEmbedding = if (latestState.supportsCloning && !useNamedSpeaker) speakerEmbeddingPath else null
                    val effectiveInstruction = if (latestState.supportsInstruction) {
                        latestState.selectedInstruction.takeIf { it.isNotBlank() }
                    } else {
                        null
                    }

                    val audio = withContext(nativeDispatcher) {
                        qwenEngine.generate(
                            text = latestState.text,
                            referenceWav = null,
                            speakerEmbeddingPath = effectiveEmbedding,
                            languageId = langId,
                            instruction = effectiveInstruction,
                            speaker = effectiveSpeaker
                        )
                    }
                    if (audio != null) {
                        lastGeneratedAudio = audio
                        playbackPositionSample = 0
                        _uiState.update {
                            it.copy(
                                hasAudio = true,
                                playbackPositionSeconds = 0f,
                                playbackDurationSeconds = audio.size.toFloat() / AUDIO_SAMPLE_RATE
                            )
                        }
                        startPlayback()
                    } else {
                        throw Exception("Generation failed.")
                    }
                }
            } catch (e: Throwable) {
                _uiState.update { it.copy(error = e.message ?: "Unknown error occurred") }
            } finally {
                _uiState.update { it.copy(isGenerating = false) }
            }
        }
    }

    /**
     * Refreshes the model capabilities from the current engine state.
     *
     * @param modelDir Directory containing the models.
     * @param modelName Optional specific model name.
     */
    fun refreshModelCapabilities(modelDir: String, modelName: String?) {
        if (modelDir.isBlank() || _uiState.value.isGenerating) return
        viewModelScope.launch(Dispatchers.IO) {
            val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
            val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, resolvedModelName) }
            if (!loaded) return@launch

            val caps = withContext(nativeDispatcher) { qwenEngine.getModelCapabilities() }
            val speakers = if (caps?.supportsNamedSpeakers == true) {
                withContext(nativeDispatcher) { qwenEngine.getAvailableSpeakers() }
            } else {
                emptyList()
            }
            applyCapabilitiesAndSpeakers(caps, speakers)
        }
    }

    /**
     * Replays the last generated audio.
     */
    fun replayLastAudio() {
        seekPlayback(0f)
        startPlayback()
    }

    fun togglePlayback() {
        if (_uiState.value.isPlaying) {
            pausePlayback()
        } else {
            startPlayback()
        }
    }

    fun pausePlayback() {
        playbackPaused = true
        playbackLine?.stop()
        _uiState.update { it.copy(isPlaying = false) }
    }

    fun seekPlayback(positionSeconds: Float) {
        val samples = lastGeneratedAudio ?: return
        val targetSample = (positionSeconds * AUDIO_SAMPLE_RATE)
            .toInt()
            .coerceIn(0, samples.size)
        playbackPositionSample = targetSample
        playbackRequestedPosition = targetSample
        playbackLine?.flush()
        _uiState.update {
            it.copy(
                playbackPositionSeconds = targetSample.toFloat() / AUDIO_SAMPLE_RATE,
                playbackDurationSeconds = samples.size.toFloat() / AUDIO_SAMPLE_RATE
            )
        }
    }

    /**
     * Saves the last generated audio to a WAV file.
     *
     * @param file The file to save to.
     */
    fun saveAudioToFile(file: File) {
        val samples = lastGeneratedAudio ?: return
        viewModelScope.launch(Dispatchers.IO) {
            _uiState.update { it.copy(isSaving = true) }
            try {
                val format = AudioFormat(24000f, 16, 1, true, false)
                val buffer = ByteArray(samples.size * 2)
                for (i in samples.indices) {
                    val sample = (samples[i] * 32767).toInt().coerceIn(-32768, 32767)
                    buffer[i * 2] = (sample and 0xFF).toByte()
                    buffer[i * 2 + 1] = ((sample shr 8) and 0xFF).toByte()
                }

                ByteArrayInputStream(buffer).use { bais ->
                    AudioInputStream(bais, format, samples.size.toLong()).use { ais ->
                        AudioSystem.write(ais, AudioFileFormat.Type.WAVE, file)
                    }
                }
            } catch (e: Exception) {
                _uiState.update { it.copy(error = "Failed to save audio: ${e.message}") }
            } finally {
                _uiState.update { it.copy(isSaving = false) }
            }
        }
    }

    private fun findWorkingMixer(format: AudioFormat): Mixer? {
        val mixers = AudioSystem.getMixerInfo()
        println("[StudioViewModel] Found ${mixers.size} mixers.")
        
        // Preference 1: PulseAudio/Pipewire if available (often named "PulseAudio" or "Default Audio Device")
        // Preference 2: "Groove" as found in user environment
        // Preference 3: Generic Analog
        val sortedMixers = mixers.sortedByDescending { info ->
            val name = info.name.lowercase()
            when {
                name.contains("pulse") || name.contains("pipewire") || name.contains("default") -> 100
                name.contains("groove") -> 90
                name.contains("analog") || name.contains("generic") -> 50
                else -> 0
            }
        }

        for (info in sortedMixers) {
            try {
                val mixer = AudioSystem.getMixer(info)
                val lineInfo = DataLine.Info(SourceDataLine::class.java, format)
                if (mixer.isLineSupported(lineInfo)) {
                    println("[StudioViewModel] Using mixer: ${info.name}")
                    return mixer
                }
            } catch (e: Exception) {
                println("[StudioViewModel] Failed to check mixer ${info.name}: ${e.message}")
            }
        }
        println("[StudioViewModel] No suitable mixer found, falling back to default.")
        return null
    }

    private fun startPlayback() {
        val samples = lastGeneratedAudio ?: return
        if (samples.isEmpty()) return
        if (playbackPositionSample >= samples.size) {
            playbackPositionSample = 0
        }

        playbackPaused = false
        playbackLine?.start()
        if (playbackJob?.isActive == true) {
            _uiState.update { it.copy(isPlaying = true) }
            return
        }

        playbackJob = viewModelScope.launch(Dispatchers.IO) {
            var line: SourceDataLine? = null
            try {
                _uiState.update { it.copy(isPlaying = true) }

                val format = AudioFormat(AUDIO_SAMPLE_RATE.toFloat(), 16, 1, true, false)
                val info = DataLine.Info(SourceDataLine::class.java, format)

                val mixer = findWorkingMixer(format)
                line = if (mixer != null) {
                    mixer.getLine(info) as SourceDataLine
                } else {
                    AudioSystem.getLine(info) as SourceDataLine
                }
                playbackLine = line

                println("[StudioViewModel] Opening audio line...")
                line.open(format)
                line.start()
                println("[StudioViewModel] Audio line started.")

                val chunkBuffer = ByteArray(PLAYBACK_CHUNK_SAMPLES * 2)
                while (isActive && playbackPositionSample < samples.size) {
                    playbackRequestedPosition?.let { requested ->
                        playbackRequestedPosition = null
                        playbackPositionSample = requested.coerceIn(0, samples.size)
                        line.flush()
                    }

                    if (playbackPaused) {
                        line.stop()
                        _uiState.update { it.copy(isPlaying = false) }
                        while (isActive && playbackPaused) {
                            delay(25)
                        }
                        if (!isActive) break
                        line.start()
                        _uiState.update { it.copy(isPlaying = true) }
                    }

                    val start = playbackPositionSample
                    val chunkSamples = minOf(PLAYBACK_CHUNK_SAMPLES, samples.size - start)
                    if (chunkSamples <= 0) break

                    for (offset in 0 until chunkSamples) {
                        val sample = (samples[start + offset] * 32767).toInt().coerceIn(-32768, 32767)
                        val byteIndex = offset * 2
                        chunkBuffer[byteIndex] = (sample and 0xFF).toByte()
                        chunkBuffer[byteIndex + 1] = ((sample shr 8) and 0xFF).toByte()
                    }

                    line.write(chunkBuffer, 0, chunkSamples * 2)
                    playbackPositionSample = start + chunkSamples
                    _uiState.update {
                        it.copy(
                            isPlaying = true,
                            playbackPositionSeconds = playbackPositionSample.toFloat() / AUDIO_SAMPLE_RATE,
                            playbackDurationSeconds = samples.size.toFloat() / AUDIO_SAMPLE_RATE
                        )
                    }
                }

                if (!playbackPaused && isActive) {
                    line.drain()
                }
                println("[StudioViewModel] Playback finished.")
            } catch (e: Exception) {
                System.err.println("[StudioViewModel] Playback failed: ${e.message}")
                e.printStackTrace()
            } finally {
                runCatching { line?.stop() }
                runCatching { line?.flush() }
                runCatching { line?.close() }
                if (playbackLine == line) {
                    playbackLine = null
                }
                val audioSize = lastGeneratedAudio?.size ?: 0
                val atEnd = playbackPositionSample >= audioSize
                if (atEnd) {
                    playbackPositionSample = audioSize
                    playbackRequestedPosition = null
                }
                _uiState.update {
                    it.copy(
                        isPlaying = false,
                        playbackPositionSeconds = playbackPositionSample.toFloat() / AUDIO_SAMPLE_RATE
                    )
                }
            }
        }
    }

    private fun stopPlayback(resetPosition: Boolean) {
        playbackPaused = false
        playbackRequestedPosition = null
        playbackJob?.cancel()
        playbackJob = null
        runCatching { playbackLine?.stop() }
        runCatching { playbackLine?.flush() }
        runCatching { playbackLine?.close() }
        playbackLine = null
        if (resetPosition) {
            playbackPositionSample = 0
        }
        _uiState.update {
            it.copy(
                isPlaying = false,
                playbackPositionSeconds = if (resetPosition) 0f else playbackPositionSample.toFloat() / AUDIO_SAMPLE_RATE
            )
        }
    }

    override fun onCleared() {
        super.onCleared()
        stopPlayback(resetPosition = false)
        qwenEngine.release()
        nativeDispatcher.close()
    }
}
