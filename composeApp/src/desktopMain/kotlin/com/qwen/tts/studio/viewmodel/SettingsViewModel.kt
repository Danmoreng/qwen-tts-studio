package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow

class SettingsViewModel : ViewModel() {
    private val _modelDir = MutableStateFlow("C:\\Development\\Qwen3TTSDev\\qwen3-tts.cpp\\models")
    val modelDir = _modelDir.asStateFlow()

    fun setModelDir(path: String) {
        _modelDir.value = path
    }
}
