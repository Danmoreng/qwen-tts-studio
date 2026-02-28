package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch

data class StudioUiState(
    val text: String = "",
    val selectedVoice: String = "Default Voice (EN)",
    val selectedEmotion: String = "Neutral",
    val isGenerating: Boolean = false,
    val progress: Float = 0f
)

class StudioViewModel : ViewModel() {
    private val _uiState = MutableStateFlow(StudioUiState())
    val uiState: StateFlow<StudioUiState> = _uiState.asStateFlow()

    fun onTextChange(newText: String) {
        if (newText.length <= 5000) {
            _uiState.value = _uiState.value.copy(text = newText)
        }
    }

    fun onVoiceChange(newVoice: String) {
        _uiState.value = _uiState.value.copy(selectedVoice = newVoice)
    }

    fun onEmotionChange(newEmotion: String) {
        _uiState.value = _uiState.value.copy(selectedEmotion = newEmotion)
    }

    fun generateAudio() {
        val currentState = _uiState.value
        if (currentState.text.isBlank() || currentState.isGenerating) return

        viewModelScope.launch {
            _uiState.value = _uiState.value.copy(isGenerating = true)
            
            // Simulation of C++ Backend call
            delay(2500)
            
            _uiState.value = _uiState.value.copy(isGenerating = false)
        }
    }
}
