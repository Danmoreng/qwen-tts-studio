package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow

class SettingsViewModel : ViewModel() {
    private val _modelDir = MutableStateFlow("C:\\Development\\Qwen3TTSDev\\qwen3-tts.cpp\\models")
    val modelDir = _modelDir.asStateFlow()

    private val _acceleration = MutableStateFlow("CPU (AVX2)")
    val acceleration = _acceleration.asStateFlow()

    fun setModelDir(path: String) {
        _modelDir.value = path
    }

    fun setAcceleration(mode: String) {
        _acceleration.value = mode
    }
}
