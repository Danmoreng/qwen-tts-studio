package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import java.io.File
import java.util.Properties

/**
 * ViewModel for managing application settings, specifically model paths and variants.
 * Handles persistence of settings using a properties file in the user's home directory.
 */
class SettingsViewModel : ViewModel() {
    private val appDir = File(System.getProperty("user.home"), ".qwen-tts-studio")
    private val settingsFile = File(appDir, "settings.properties")
    private val defaultModelDir = File(appDir, "models").absolutePath
    private val defaultModelName = "qwen3-tts-0.6b-f16.gguf"

    private val _modelDir = MutableStateFlow(loadModelDir())
    /** The directory where Qwen3 models are stored. */
    val modelDir = _modelDir.asStateFlow()

    private val _modelName = MutableStateFlow(loadModelName())
    /** The currently selected model filename. */
    val modelName = _modelName.asStateFlow()

    private val _availableModelNames = MutableStateFlow(scanModelNames(_modelDir.value))
    /** List of available model filenames found in the current model directory. */
    val availableModelNames = _availableModelNames.asStateFlow()

    init {
        if (!appDir.exists()) {
            appDir.mkdirs()
        }
        if (_modelName.value.isBlank()) {
            _modelName.value = _availableModelNames.value.firstOrNull() ?: defaultModelName
            saveAll()
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
                val direct = props.getProperty("modelName", "").trim()
                if (direct.isNotBlank()) return direct
                // Backward compatibility with older saved variant setting.
                val variant = props.getProperty("modelVariant", "").trim()
                if (variant == "1.7B") return "qwen3-tts-1.7b-f16.gguf"
                if (variant == "0.6B") return "qwen3-tts-0.6b-f16.gguf"
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
        return defaultModelName
    }

    private fun scanModelNames(dirPath: String): List<String> {
        val dir = File(dirPath)
        if (!dir.exists() || !dir.isDirectory) return emptyList()
        return dir.listFiles()
            ?.asSequence()
            ?.filter { it.isFile }
            ?.map { it.name }
            ?.filter {
                it.endsWith(".gguf", ignoreCase = true) &&
                    it.startsWith("qwen3-tts-", ignoreCase = true) &&
                    !it.contains("tokenizer", ignoreCase = true) &&
                    !it.contains("speech", ignoreCase = true)
            }
            ?.sortedBy { it.lowercase() }
            ?.toList()
            ?: emptyList()
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
            // Clean up old key so future reads don't depend on it.
            props.remove("modelVariant")
            settingsFile.outputStream().use { props.store(it, "Qwen-TTS Studio Settings") }
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    /**
     * Updates the model directory and rescans for available models.
     *
     * @param path The new model directory path.
     */
    fun setModelDir(path: String) {
        _modelDir.value = path
        _availableModelNames.value = scanModelNames(path)
        val current = _modelName.value.trim()
        if (current.isBlank()) {
            _modelName.value = _availableModelNames.value.firstOrNull() ?: defaultModelName
        }
        saveAll()
    }

    /**
     * Updates the selected model filename.
     *
     * @param name The new model filename.
     */
    fun setModelName(name: String) {
        _modelName.value = name.trim()
        saveAll()
    }

    /**
     * Rescans the current model directory for available models.
     */
    fun refreshModelNames() {
        _availableModelNames.value = scanModelNames(_modelDir.value)
        if (_modelName.value.isBlank()) {
            _modelName.value = _availableModelNames.value.firstOrNull() ?: defaultModelName
            saveAll()
        }
    }
}

