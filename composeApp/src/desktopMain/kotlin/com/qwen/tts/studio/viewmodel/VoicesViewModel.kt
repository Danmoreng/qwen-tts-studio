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
import java.io.File
import java.util.concurrent.Executors

data class VoicePreset(
    val id: String,
    val name: String,
    val referenceWav: String?,
    val speakerEmbeddingPath: String?,
    val embeddingDim: Int? = null
) {
    val isSystem: Boolean = referenceWav == null && speakerEmbeddingPath == null
}

class VoicesViewModel : ViewModel() {
    private val defaultVoice = VoicePreset(
        id = "default",
        name = "Default Voice (Model)",
        referenceWav = null,
        speakerEmbeddingPath = null
    )

    private val storageFile = File(
        File(System.getProperty("user.home"), ".qwen-tts-studio"),
        "voice-presets.tsv"
    )

    private val _voices = MutableStateFlow(loadVoices())
    val voices: StateFlow<List<VoicePreset>> = _voices.asStateFlow()
    private val _isCreating = MutableStateFlow(false)
    val isCreating: StateFlow<Boolean> = _isCreating.asStateFlow()
    private val _error = MutableStateFlow<String?>(null)
    val error: StateFlow<String?> = _error.asStateFlow()
    private val _supportsCloning = MutableStateFlow(true)
    val supportsCloning: StateFlow<Boolean> = _supportsCloning.asStateFlow()
    private val _currentEmbeddingDim = MutableStateFlow(0)
    val currentEmbeddingDim: StateFlow<Int> = _currentEmbeddingDim.asStateFlow()

    private val qwenEngine = QwenEngine()
    private val nativeDispatcher = Executors.newSingleThreadExecutor { runnable ->
        Thread(null, runnable, "QwenVoicePresetThread", 8L * 1024 * 1024).apply {
            isDaemon = true
        }
    }.asCoroutineDispatcher()

    fun refreshModelCapabilities(modelDir: String, modelName: String?) {
        if (modelDir.isBlank()) return
        viewModelScope.launch(Dispatchers.IO) {
            val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
            val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, resolvedModelName) }
            if (!loaded) return@launch
            val caps = withContext(nativeDispatcher) { qwenEngine.getModelCapabilities() }
            _supportsCloning.value = caps?.supportsCloning ?: true
            _currentEmbeddingDim.value = caps?.speakerEmbeddingDim ?: 0
        }
    }

    fun createVoicePreset(name: String, referenceWav: String, modelDir: String, modelName: String?) {
        val wavFile = File(referenceWav)
        if (!wavFile.exists() || !wavFile.isFile) {
            _error.value = "Reference audio file does not exist."
            return
        }
        if (modelDir.isBlank()) {
            _error.value = "Please select the Model Directory in Setup."
            return
        }

        val trimmedName = name.trim()
        if (trimmedName.isBlank()) {
            _error.value = "Preset name is required."
            return
        }

        _isCreating.value = true
        _error.value = null

        val uniqueName = makeUniqueName(trimmedName)
        val voiceId = "voice-${System.currentTimeMillis()}"
        viewModelScope.launch {
            try {
                val resolvedModelName = modelName?.trim().takeUnless { it.isNullOrEmpty() }
                val loaded = withContext(nativeDispatcher) { qwenEngine.load(modelDir, resolvedModelName) }
                if (!loaded) {
                    _error.value = "Failed to load Qwen3 models for speaker embedding extraction."
                    return@launch
                }

                val caps = withContext(nativeDispatcher) { qwenEngine.getModelCapabilities() }
                val supportsCloning = caps?.supportsCloning ?: true
                val embeddingDim = caps?.speakerEmbeddingDim ?: 0
                _supportsCloning.value = supportsCloning
                _currentEmbeddingDim.value = embeddingDim
                if (!supportsCloning) {
                    _error.value = "Current model does not support custom voice cloning."
                    return@launch
                }

                val embeddingFile = withContext(Dispatchers.IO) {
                    val embeddingsDir = File(
                        File(System.getProperty("user.home"), ".qwen-tts-studio"),
                        "embeddings"
                    )
                    embeddingsDir.mkdirs()
                    val dimSuffix = if (embeddingDim > 0) "-d$embeddingDim" else ""
                    File(embeddingsDir, "$voiceId$dimSuffix.json")
                }

                val extracted = withContext(nativeDispatcher) {
                    qwenEngine.extractSpeakerEmbedding(wavFile.absolutePath, embeddingFile.absolutePath)
                }
                if (!extracted) {
                    _error.value = "Failed to extract speaker embedding from reference audio."
                    return@launch
                }

                val preset = VoicePreset(
                    id = voiceId,
                    name = uniqueName,
                    referenceWav = wavFile.absolutePath,
                    speakerEmbeddingPath = embeddingFile.absolutePath,
                    embeddingDim = embeddingDim.takeIf { it > 0 }
                )
                _voices.value = _voices.value + preset
                saveVoices()
                _error.value = null
            } finally {
                _isCreating.value = false
            }
        }
    }

    fun deleteVoicePreset(id: String) {
        val target = _voices.value.firstOrNull { it.id == id } ?: return
        if (target.isSystem) return

        _voices.value = _voices.value.filterNot { it.id == id }
        saveVoices()
    }

    fun referenceForVoice(name: String): String? {
        return _voices.value.firstOrNull { it.name == name }?.referenceWav
    }

    fun speakerEmbeddingForVoice(name: String, expectedDim: Int): String? {
        val preset = _voices.value.firstOrNull { it.name == name } ?: return null
        val embedding = preset.speakerEmbeddingPath ?: return null
        if (expectedDim <= 0) return embedding
        val dim = preset.embeddingDim
        if (dim == null) {
            return null
        }
        return if (dim == expectedDim) embedding else null
    }

    private fun makeUniqueName(baseName: String): String {
        if (_voices.value.none { it.name.equals(baseName, ignoreCase = true) }) {
            return baseName
        }

        var index = 2
        while (true) {
            val candidate = "$baseName ($index)"
            if (_voices.value.none { it.name.equals(candidate, ignoreCase = true) }) {
                return candidate
            }
            index++
        }
    }

    private fun loadVoices(): List<VoicePreset> {
        val clones = if (storageFile.exists()) {
            storageFile.readLines()
                .mapNotNull { line ->
                    val parts = line.split('\t')
                    if (parts.size < 3) return@mapNotNull null

                    val id = parts[0]
                    val name = parts[1]
                    if (id.isBlank() || name.isBlank()) return@mapNotNull null
                    if (parts.size >= 4) {
                        val embedding = parts[2].ifBlank { null }
                        val wav = parts[3].ifBlank { null }
                        val dim = parts.getOrNull(4)?.toIntOrNull()
                        VoicePreset(id = id, name = name, referenceWav = wav, speakerEmbeddingPath = embedding, embeddingDim = dim)
                    } else {
                        val wav = parts.getOrNull(2).orEmpty()
                        if (wav.isBlank()) return@mapNotNull null
                        VoicePreset(id = id, name = name, referenceWav = wav, speakerEmbeddingPath = null)
                    }
                }
        } else {
            emptyList()
        }
        return listOf(defaultVoice) + clones
    }

    private fun saveVoices() {
        storageFile.parentFile?.mkdirs()
        val lines = _voices.value
            .filterNot { it.isSystem }
            .map {
                "${it.id}\t${it.name}\t${it.speakerEmbeddingPath.orEmpty()}\t${it.referenceWav.orEmpty()}\t${it.embeddingDim?.toString().orEmpty()}"
            }
        storageFile.writeText(lines.joinToString(System.lineSeparator()))
    }

    override fun onCleared() {
        super.onCleared()
        qwenEngine.release()
        nativeDispatcher.close()
    }
}
