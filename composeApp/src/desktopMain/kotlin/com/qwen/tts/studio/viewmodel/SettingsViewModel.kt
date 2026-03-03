package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import java.io.File
import java.util.Properties

class SettingsViewModel : ViewModel() {
    private val appDir = File(System.getProperty("user.home"), ".qwen-tts-studio")
    private val settingsFile = File(appDir, "settings.properties")
    private val defaultModelDir = File(appDir, "models").absolutePath

    private val _modelDir = MutableStateFlow(loadModelDir())
    val modelDir = _modelDir.asStateFlow()

    init {
        if (!appDir.exists()) {
            appDir.mkdirs()
        }
    }

    private fun loadModelDir(): String {
        if (settingsFile.exists()) {
            try {
                val props = Properties()
                settingsFile.inputStream().use { props.load(it) }
                return props.getProperty("modelDir", defaultModelDir)
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
        return defaultModelDir
    }

    private fun saveModelDir(path: String) {
        try {
            if (!appDir.exists()) appDir.mkdirs()
            val props = Properties()
            if (settingsFile.exists()) {
                settingsFile.inputStream().use { props.load(it) }
            }
            props.setProperty("modelDir", path)
            settingsFile.outputStream().use { props.store(it, "Qwen-TTS Studio Settings") }
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    fun setModelDir(path: String) {
        _modelDir.value = path
        saveModelDir(path)
    }
}
