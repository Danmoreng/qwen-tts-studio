package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.qwen.tts.studio.engine.QwenEngine
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.asCoroutineDispatcher
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
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
    val progress: Float = 0f,
    val error: String? = null
)

class StudioViewModel : ViewModel() {
    private val _uiState = MutableStateFlow(StudioUiState())
    val uiState: StateFlow<StudioUiState> = _uiState.asStateFlow()

    private val qwenEngine = QwenEngine()
    private var lastGeneratedAudio: FloatArray? = null
    private val nativeDispatcher = Executors.newSingleThreadExecutor { runnable ->
        Thread(null, runnable, "QwenNativeThread", 8L * 1024 * 1024).apply {
            isDaemon = true
        }
    }.asCoroutineDispatcher()

    fun onTextChange(newText: String) {
        if (newText.length <= 5000) {
            _uiState.update { it.copy(text = newText, error = null) }
        }
    }

    fun onVoiceChange(newVoice: String) {
        _uiState.update { it.copy(selectedVoice = newVoice) }
    }

    fun onSpeakerChange(newSpeaker: String) {
        _uiState.update { it.copy(selectedSpeaker = newSpeaker) }
    }

    fun onLanguageChange(newLanguage: String) {
        _uiState.update { it.copy(selectedLanguage = newLanguage) }
    }

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

    fun generateAudio(
        modelDir: String,
        modelName: String?,
        speakerEmbeddingPath: String?,
        referenceWav: String?
    ) {
        val currentState = _uiState.value
        if (currentState.text.isBlank() || currentState.isGenerating) return
        if (modelDir.isBlank()) {
            _uiState.update { it.copy(error = "Please select the Model Directory in Setup.") }
            return
        }

        viewModelScope.launch {
            _uiState.update { it.copy(isGenerating = true, error = null, hasAudio = false) }

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
                    val effectiveSpeaker = if (
                        latestState.supportsNamedSpeakers &&
                        speakerEmbeddingPath.isNullOrBlank() &&
                        referenceWav.isNullOrBlank()
                    ) {
                        selectedSpeaker ?: latestState.availableSpeakers.firstOrNull()
                    } else {
                        null
                    }
                    val effectiveEmbedding = if (latestState.supportsCloning) speakerEmbeddingPath else null
                    val effectiveReference = if (latestState.supportsCloning) referenceWav else null
                    val effectiveInstruction = if (latestState.supportsInstruction) {
                        latestState.selectedInstruction.takeIf { it.isNotBlank() }
                    } else {
                        null
                    }

                    val audio = withContext(nativeDispatcher) {
                        qwenEngine.generate(
                            text = latestState.text,
                            referenceWav = effectiveReference,
                            speakerEmbeddingPath = effectiveEmbedding,
                            languageId = langId,
                            instruction = effectiveInstruction,
                            speaker = effectiveSpeaker
                        )
                    }
                    if (audio != null) {
                        lastGeneratedAudio = audio
                        _uiState.update { it.copy(hasAudio = true) }
                        playAudio(audio)
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

    fun replayLastAudio() {
        val audio = lastGeneratedAudio ?: return
        if (_uiState.value.isPlaying) return
        playAudio(audio)
    }

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

    private fun playAudio(samples: FloatArray) {
        viewModelScope.launch(Dispatchers.IO) {
            try {
                _uiState.update { it.copy(isPlaying = true) }

                val format = AudioFormat(24000f, 16, 1, true, false)
                val info = DataLine.Info(SourceDataLine::class.java, format)
                
                val mixer = findWorkingMixer(format)
                val line = if (mixer != null) {
                    mixer.getLine(info) as SourceDataLine
                } else {
                    AudioSystem.getLine(info) as SourceDataLine
                }

                println("[StudioViewModel] Opening audio line...")
                line.open(format)
                line.start()
                println("[StudioViewModel] Audio line started.")

                val buffer = ByteArray(samples.size * 2)
                for (i in samples.indices) {
                    val sample = (samples[i] * 32767).toInt().coerceIn(-32768, 32767)
                    buffer[i * 2] = (sample and 0xFF).toByte()
                    buffer[i * 2 + 1] = ((sample shr 8) and 0xFF).toByte()
                }

                println("[StudioViewModel] Writing to audio line (${buffer.size} bytes)...")
                line.write(buffer, 0, buffer.size)
                line.drain()
                line.close()
                println("[StudioViewModel] Playback finished.")
            } catch (e: Exception) {
                System.err.println("[StudioViewModel] Playback failed: ${e.message}")
                e.printStackTrace()
            } finally {
                _uiState.update { it.copy(isPlaying = false) }
            }
        }
    }

    override fun onCleared() {
        super.onCleared()
        qwenEngine.release()
        nativeDispatcher.close()
    }
}
