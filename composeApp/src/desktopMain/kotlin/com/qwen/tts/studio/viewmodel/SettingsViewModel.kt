package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import java.io.File
import java.util.Properties

enum class ModelVariant(val label: String, val modelFile: String) {
    MODEL_0_6B("0.6B", "qwen3-tts-0.6b-f16.gguf"),
    MODEL_1_7B("1.7B", "qwen3-tts-1.7b-f16.gguf")
}

class SettingsViewModel : ViewModel() {
    private val appDir = File(System.getProperty("user.home"), ".qwen-tts-studio")
    private val settingsFile = File(appDir, "settings.properties")
    private val defaultModelDir = File(appDir, "models").absolutePath
    private val defaultModelName = ""

    private val _modelDir = MutableStateFlow(loadModelDir())
    val modelDir = _modelDir.asStateFlow()
    private val _modelName = MutableStateFlow(loadModelName())
    val modelName = _modelName.asStateFlow()
    private val _modelVariant = MutableStateFlow(loadModelVariant(_modelName.value))
    val modelVariant = _modelVariant.asStateFlow()

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

    private fun loadModelName(): String {
        if (settingsFile.exists()) {
            try {
                val props = Properties()
                settingsFile.inputStream().use { props.load(it) }
                return props.getProperty("modelName", defaultModelName)
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
        return defaultModelName
    }

    private fun inferVariant(modelName: String): ModelVariant {
        return if (modelName.contains("1.7b", ignoreCase = true)) {
            ModelVariant.MODEL_1_7B
        } else {
            ModelVariant.MODEL_0_6B
        }
    }

    private fun loadModelVariant(currentModelName: String): ModelVariant {
        if (settingsFile.exists()) {
            try {
                val props = Properties()
                settingsFile.inputStream().use { props.load(it) }
                val raw = props.getProperty("modelVariant", "").trim()
                if (raw == "1.7B") return ModelVariant.MODEL_1_7B
                if (raw == "0.6B") return ModelVariant.MODEL_0_6B
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
        return inferVariant(currentModelName)
    }

    private fun saveAll() {
        try {
            if (!appDir.exists()) appDir.mkdirs()
            val props = Properties()
            if (settingsFile.exists()) {
                settingsFile.inputStream().use { props.load(it) }
            }
            props.setProperty("modelDir", _modelDir.value)
            props.setProperty("modelName", _modelName.value)
            props.setProperty("modelVariant", _modelVariant.value.label)
            settingsFile.outputStream().use { props.store(it, "Qwen-TTS Studio Settings") }
        } catch (e: Exception) {
            e.printStackTrace()
        }
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

    fun setModelName(name: String) {
        _modelName.value = name
        _modelVariant.value = inferVariant(name)
        saveAll()
    }

    fun setModelVariant(variant: ModelVariant) {
        _modelVariant.value = variant
        _modelName.value = variant.modelFile
        saveAll()
    }
}
