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
import javax.sound.sampled.*

data class StudioUiState(
    val text: String = "Another test bites the dust.",
    val selectedVoice: String = "Default Voice (Model)",
    val availableSpeakers: List<String> = emptyList(),
    val selectedSpeaker: String = "",
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
        // Native model loading can require a deeper stack than coroutine scheduler worker threads.
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

    private fun supportsModel17Features(modelName: String?): Boolean {
        return modelName?.contains("1.7b", ignoreCase = true) == true
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
                    val useModel17Features = supportsModel17Features(resolvedModelName)
                    val loaded = withContext(nativeDispatcher) {
                        qwenEngine.load(modelDir, resolvedModelName)
                    }
                    if (!loaded) {
                        throw Exception("Failed to load Qwen3 models from directory.")
                    }

                    if (useModel17Features) {
                        val speakers = withContext(nativeDispatcher) {
                            qwenEngine.getAvailableSpeakers()
                        }
                        _uiState.update { state ->
                            val normalized = speakers.distinct()
                            val nextSpeaker = state.selectedSpeaker.takeIf { it.isNotBlank() && normalized.contains(it) }.orEmpty()
                            state.copy(availableSpeakers = normalized, selectedSpeaker = nextSpeaker)
                        }
                    } else {
                        _uiState.update { state ->
                            state.copy(availableSpeakers = emptyList(), selectedSpeaker = "", selectedInstruction = "")
                        }
                    }

                    // Re-read state in case it changed during load
                    val latestState = _uiState.value
                    val langId = QwenEngine.mapLanguageToId(latestState.selectedLanguage)
                    val selectedSpeaker = latestState.selectedSpeaker.takeIf { it.isNotBlank() }
                    val effectiveSpeaker = if (!useModel17Features || !speakerEmbeddingPath.isNullOrBlank() || !referenceWav.isNullOrBlank()) {
                        null
                    } else {
                        selectedSpeaker
                    }

                    val audio = withContext(nativeDispatcher) {
                        qwenEngine.generate(
                            text = latestState.text,
                            referenceWav = referenceWav,
                            speakerEmbeddingPath = speakerEmbeddingPath,
                            languageId = langId,
                            instruction = if (useModel17Features) {
                                latestState.selectedInstruction.takeIf { it.isNotBlank() }
                            } else {
                                null
                            },
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

    fun refreshAvailableSpeakers(modelDir: String, modelName: String?) {
        if (modelDir.isBlank() || _uiState.value.isGenerating) return
        viewModelScope.launch(Dispatchers.IO) {
            val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
            val useModel17Features = supportsModel17Features(resolvedModelName)
            if (!useModel17Features) {
                _uiState.update { state ->
                    state.copy(availableSpeakers = emptyList(), selectedSpeaker = "", selectedInstruction = "")
                }
                return@launch
            }
            val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, resolvedModelName) }
            if (!loaded) return@launch
            val speakers = withContext(nativeDispatcher) { qwenEngine.getAvailableSpeakers() }.distinct()
            _uiState.update { state ->
                val nextSpeaker = state.selectedSpeaker.takeIf { it.isNotBlank() && speakers.contains(it) }.orEmpty()
                state.copy(availableSpeakers = speakers, selectedSpeaker = nextSpeaker)
            }
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

    private fun playAudio(samples: FloatArray) {
        viewModelScope.launch(Dispatchers.IO) {
            try {
                _uiState.update { it.copy(isPlaying = true) }
                
                val format = AudioFormat(24000f, 16, 1, true, false)
                val info = DataLine.Info(SourceDataLine::class.java, format)
                val line = AudioSystem.getLine(info) as SourceDataLine
                
                line.open(format)
                line.start()
                
                val buffer = ByteArray(samples.size * 2)
                for (i in samples.indices) {
                    val sample = (samples[i] * 32767).toInt().coerceIn(-32768, 32767)
                    buffer[i * 2] = (sample and 0xFF).toByte()
                    buffer[i * 2 + 1] = ((sample shr 8) and 0xFF).toByte()
                }
                
                line.write(buffer, 0, buffer.size)
                line.drain()
                line.close()
            } catch (e: Exception) {
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
