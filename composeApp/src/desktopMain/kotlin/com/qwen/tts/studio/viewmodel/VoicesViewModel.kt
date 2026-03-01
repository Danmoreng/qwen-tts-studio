package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import java.io.File

data class VoicePreset(
    val id: String,
    val name: String,
    val referenceWav: String?
) {
    val isSystem: Boolean = referenceWav == null
}

class VoicesViewModel : ViewModel() {
    private val defaultVoice = VoicePreset(
        id = "default",
        name = "Default Voice (Model)",
        referenceWav = null
    )

    private val storageFile = File(
        File(System.getProperty("user.home"), ".qwen-tts-studio"),
        "voice-presets.tsv"
    )

    private val _voices = MutableStateFlow(loadVoices())
    val voices: StateFlow<List<VoicePreset>> = _voices.asStateFlow()

    fun addVoicePreset(name: String, referenceWav: String): String? {
        val wavFile = File(referenceWav)
        if (!wavFile.exists() || !wavFile.isFile) {
            return "Reference audio file does not exist."
        }

        val trimmedName = name.trim()
        if (trimmedName.isBlank()) {
            return "Preset name is required."
        }

        val uniqueName = makeUniqueName(trimmedName)
        val preset = VoicePreset(
            id = "voice-${System.currentTimeMillis()}",
            name = uniqueName,
            referenceWav = wavFile.absolutePath
        )

        _voices.value = _voices.value + preset
        saveVoices()
        return null
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
                    val wav = parts[2]
                    if (id.isBlank() || name.isBlank() || wav.isBlank()) return@mapNotNull null
                    VoicePreset(id = id, name = name, referenceWav = wav)
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
            .map { "${it.id}\t${it.name}\t${it.referenceWav}" }
        storageFile.writeText(lines.joinToString(System.lineSeparator()))
    }
}
