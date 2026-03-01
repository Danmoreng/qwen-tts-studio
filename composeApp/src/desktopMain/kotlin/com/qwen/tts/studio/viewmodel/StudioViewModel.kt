package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.qwen.tts.studio.engine.QwenEngine
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.asCoroutineDispatcher
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.util.concurrent.Executors
import javax.sound.sampled.AudioFormat
import javax.sound.sampled.AudioSystem
import javax.sound.sampled.DataLine
import javax.sound.sampled.SourceDataLine

data class StudioUiState(
    val text: String = "Another test bites the dust.",
    val selectedVoice: String = "Default Voice (Model)",
    val isGenerating: Boolean = false,
    val isPlaying: Boolean = false,
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
            _uiState.value = _uiState.value.copy(text = newText, error = null)
        }
    }

    fun onVoiceChange(newVoice: String) {
        _uiState.value = _uiState.value.copy(selectedVoice = newVoice)
    }

    fun generateAudio(modelDir: String, referenceWav: String?) {
        val currentState = _uiState.value
        if (currentState.text.isBlank() || currentState.isGenerating) return
        if (modelDir.isBlank()) {
            _uiState.value = _uiState.value.copy(error = "Please select the Model Directory in Setup.")
            return
        }

        viewModelScope.launch {
            _uiState.value = _uiState.value.copy(isGenerating = true, error = null)
            
            try {
                withContext(Dispatchers.IO) {
                    val loaded = withContext(nativeDispatcher) {
                        qwenEngine.load(modelDir)
                    }
                    if (!loaded) {
                        throw Exception("Failed to load Qwen3 models from directory.")
                    }

                    val audio = withContext(nativeDispatcher) {
                        qwenEngine.generate(currentState.text, referenceWav)
                    }
                    if (audio != null) {
                        lastGeneratedAudio = audio
                        playAudio(audio)
                    } else {
                        throw Exception("Generation failed.")
                    }
                }
            } catch (e: Exception) {
                _uiState.value = _uiState.value.copy(error = e.message)
            } finally {
                _uiState.value = _uiState.value.copy(isGenerating = false)
            }
        }
    }

    fun replayLastAudio() {
        val audio = lastGeneratedAudio ?: return
        if (_uiState.value.isPlaying) return
        playAudio(audio)
    }

    private fun playAudio(samples: FloatArray) {
        viewModelScope.launch(Dispatchers.IO) {
            try {
                _uiState.value = _uiState.value.copy(isPlaying = true)
                
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
                _uiState.value = _uiState.value.copy(isPlaying = false)
            }
        }
    }

    override fun onCleared() {
        super.onCleared()
        qwenEngine.release()
        nativeDispatcher.close()
    }
}
