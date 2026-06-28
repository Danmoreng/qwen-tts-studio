package com.qwen.tts.studio.viewmodel

import androidx.lifecycle.ViewModel
import com.qwen.tts.studio.engine.NativeBackendPreference
import com.qwen.tts.studio.engine.QwenEngine
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.cancel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.io.File
import java.net.URI
import java.net.http.HttpClient
import java.net.http.HttpRequest
import java.net.http.HttpResponse
import java.nio.file.StandardCopyOption
import java.time.Duration
import java.util.Properties

data class ModelDownloadFile(
    val fileName: String,
    val url: String,
    val sizeBytes: Long
)

data class ModelDownloadOption(
    val id: String,
    val title: String,
    val description: String,
    val primaryModelName: String,
    val files: List<ModelDownloadFile>
) {
    val totalSizeBytes: Long = files.sumOf { it.sizeBytes }
}

data class ModelDownloadState(
    val isDownloading: Boolean = false,
    val currentFile: String = "",
    val progress: Float = 0f,
    val bytesDownloaded: Long = 0L,
    val bytesTotal: Long = 0L,
    val status: String = "",
    val error: String? = null
)

/**
 * ViewModel for managing application settings, specifically model paths and variants.
 * Handles persistence of settings using a properties file in the user's home directory.
 */
class SettingsViewModel : ViewModel() {
    companion object {
        private const val HUGGING_FACE_REPO = "Serveurperso/Qwen3-TTS-GGUF"
        private const val HF_BASE_URL = "https://huggingface.co/$HUGGING_FACE_REPO/resolve/main"
        const val HUGGING_FACE_REPO_URL = "https://huggingface.co/$HUGGING_FACE_REPO/tree/main"
        private const val TOKENIZER_Q8 = "qwen-tokenizer-12hz-Q8_0.gguf"

        private val fileSizes = mapOf(
            TOKENIZER_Q8 to 291_150_624L,
            "qwen-talker-0.6b-base-Q8_0.gguf" to 992_615_488L,
            "qwen-talker-1.7b-base-Q8_0.gguf" to 2_079_448_256L,
            "qwen-talker-1.7b-customvoice-Q8_0.gguf" to 2_042_834_304L,
            "qwen-talker-1.7b-voicedesign-Q8_0.gguf" to 2_042_833_824L
        )

        val downloadOptions = listOf(
            ModelDownloadOption(
                id = "0.6b-base-q8",
                title = "0.6B Base Q8_0",
                description = "Compact base model with voice cloning support.",
                primaryModelName = "qwen-talker-0.6b-base-Q8_0.gguf",
                files = listOf(
                    hfFile(TOKENIZER_Q8),
                    hfFile("qwen-talker-0.6b-base-Q8_0.gguf")
                )
            ),
            ModelDownloadOption(
                id = "1.7b-base-q8",
                title = "1.7B Base Q8_0",
                description = "Larger base model for higher quality voice cloning.",
                primaryModelName = "qwen-talker-1.7b-base-Q8_0.gguf",
                files = listOf(
                    hfFile(TOKENIZER_Q8),
                    hfFile("qwen-talker-1.7b-base-Q8_0.gguf")
                )
            ),
            ModelDownloadOption(
                id = "1.7b-customvoice-q8",
                title = "1.7B CustomVoice Q8_0",
                description = "Named speakers and style instructions.",
                primaryModelName = "qwen-talker-1.7b-customvoice-Q8_0.gguf",
                files = listOf(
                    hfFile(TOKENIZER_Q8),
                    hfFile("qwen-talker-1.7b-customvoice-Q8_0.gguf")
                )
            ),
            ModelDownloadOption(
                id = "1.7b-voicedesign-q8",
                title = "1.7B VoiceDesign Q8_0",
                description = "Instruction-driven voice design model.",
                primaryModelName = "qwen-talker-1.7b-voicedesign-Q8_0.gguf",
                files = listOf(
                    hfFile(TOKENIZER_Q8),
                    hfFile("qwen-talker-1.7b-voicedesign-Q8_0.gguf")
                )
            )
        )

        private fun hfFile(fileName: String): ModelDownloadFile =
            ModelDownloadFile(fileName, "$HF_BASE_URL/$fileName?download=true", fileSizes[fileName] ?: 0L)
    }

    private val appDir = File(System.getProperty("user.home"), ".qwen-tts-studio")
    private val settingsFile = File(appDir, "settings.properties")
    private val defaultModelDir = File(appDir, "models").absolutePath
    private val defaultModelName = "qwen-talker-0.6b-base-Q8_0.gguf"
    private val scope = CoroutineScope(SupervisorJob() + Dispatchers.Main)
    private val httpClient = HttpClient.newBuilder()
        .followRedirects(HttpClient.Redirect.NORMAL)
        .connectTimeout(Duration.ofSeconds(30))
        .build()

    private val _modelDir = MutableStateFlow(loadModelDir())
    /** The directory where Qwen3 models are stored. */
    val modelDir = _modelDir.asStateFlow()

    private val _modelName = MutableStateFlow(loadModelName())
    /** The currently selected model filename. */
    val modelName = _modelName.asStateFlow()

    private val _backendPreference = MutableStateFlow(loadBackendPreference())
    val backendPreference = _backendPreference.asStateFlow()

    private val _compiledBackendMask = MutableStateFlow(QwenEngine.BACKEND_CPU)
    val compiledBackendMask = _compiledBackendMask.asStateFlow()

    private val _availableModelNames = MutableStateFlow(scanModelNames(_modelDir.value))
    /** List of available model filenames found in the current model directory. */
    val availableModelNames = _availableModelNames.asStateFlow()

    private val _installedDownloadOptionIds = MutableStateFlow(scanInstalledDownloadOptionIds(_modelDir.value))
    val installedDownloadOptionIds = _installedDownloadOptionIds.asStateFlow()

    private val _downloadState = MutableStateFlow(ModelDownloadState())
    val downloadState = _downloadState.asStateFlow()

    private val _showWelcome = MutableStateFlow(!loadWelcomeDismissed() && _availableModelNames.value.isEmpty())
    val showWelcome = _showWelcome.asStateFlow()

    init {
        if (!appDir.exists()) {
            appDir.mkdirs()
        }
        if (_modelName.value.isBlank()) {
            _modelName.value = _availableModelNames.value.firstOrNull() ?: defaultModelName
            saveAll()
        }
        scope.launch(Dispatchers.IO) {
            _compiledBackendMask.value = runCatching { QwenEngine().compiledBackendMask() }
                .getOrDefault(QwenEngine.BACKEND_CPU)
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
                val variant = props.getProperty("modelVariant", "").trim()
                if (variant == "1.7B") return "qwen-talker-1.7b-base-Q8_0.gguf"
                if (variant == "0.6B") return "qwen-talker-0.6b-base-Q8_0.gguf"
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
        return defaultModelName
    }

    private fun loadWelcomeDismissed(): Boolean {
        if (settingsFile.exists()) {
            try {
                val props = Properties()
                settingsFile.inputStream().use { props.load(it) }
                return props.getProperty("welcomeDismissed", "false").toBoolean()
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
        return false
    }

    private fun loadBackendPreference(): NativeBackendPreference {
        System.getenv("QWEN_TTS_BACKEND")
            ?.trim()
            ?.takeIf { it.isNotBlank() }
            ?.let { return NativeBackendPreference.fromId(it) }

        if (settingsFile.exists()) {
            try {
                val props = Properties()
                settingsFile.inputStream().use { props.load(it) }
                return NativeBackendPreference.fromId(props.getProperty("backendPreference", "auto"))
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
        return NativeBackendPreference.Auto
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
                    it.startsWith("qwen-talker-", ignoreCase = true) &&
                    !it.contains("tokenizer", ignoreCase = true) &&
                    !it.contains("speech", ignoreCase = true)
            }
            ?.sortedBy { it.lowercase() }
            ?.toList()
            ?: emptyList()
    }

    private fun scanInstalledDownloadOptionIds(dirPath: String): Set<String> {
        val dir = File(dirPath)
        if (!dir.exists() || !dir.isDirectory) return emptySet()
        return downloadOptions
            .filter { option ->
                option.files.all { file ->
                    val localFile = File(dir, file.fileName)
                    localFile.isFile && localFile.length() > 0L
                }
            }
            .map { it.id }
            .toSet()
    }

    private fun refreshLocalModelState(selectFallbackIfMissing: Boolean = false) {
        _availableModelNames.value = scanModelNames(_modelDir.value)
        _installedDownloadOptionIds.value = scanInstalledDownloadOptionIds(_modelDir.value)

        val current = _modelName.value.trim()
        if (current.isBlank()) {
            _modelName.value = _availableModelNames.value.firstOrNull() ?: defaultModelName
        } else if (selectFallbackIfMissing && _availableModelNames.value.none { it.equals(current, ignoreCase = true) }) {
            _modelName.value = _availableModelNames.value.firstOrNull() ?: defaultModelName
        }
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
            props.setProperty("backendPreference", _backendPreference.value.id)
            props.setProperty("welcomeDismissed", (!_showWelcome.value).toString())
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
        refreshLocalModelState(selectFallbackIfMissing = true)
        val current = _modelName.value.trim()
        if (current.isBlank()) {
            _modelName.value = _availableModelNames.value.firstOrNull() ?: defaultModelName
        }
        if (_availableModelNames.value.isNotEmpty()) {
            _showWelcome.value = false
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

    fun setBackendPreference(preference: NativeBackendPreference) {
        _backendPreference.value = preference
        saveAll()
    }

    /**
     * Rescans the current model directory for available models.
     */
    fun refreshModelNames() {
        refreshLocalModelState()
        if (_availableModelNames.value.isNotEmpty() && _showWelcome.value) {
            _showWelcome.value = false
            saveAll()
        }
    }

    fun dismissWelcome() {
        _showWelcome.value = false
        saveAll()
    }

    fun downloadModels(optionIds: Set<String>) {
        if (_downloadState.value.isDownloading) return

        val selected = downloadOptions.filter { it.id in optionIds }
        if (selected.isEmpty()) {
            _downloadState.value = ModelDownloadState(error = "Select at least one model to download.")
            return
        }

        scope.launch {
            _downloadState.value = ModelDownloadState(isDownloading = true, status = "Preparing download...")
            try {
                val modelDirFile = File(_modelDir.value)
                withContext(Dispatchers.IO) {
                    modelDirFile.mkdirs()
                }

                val files = selected
                    .flatMap { it.files }
                    .distinctBy { it.fileName.lowercase() }
                val totalBytes = files.sumOf { it.sizeBytes }
                var completedBytes = 0L

                files.forEachIndexed { index, file ->
                    completedBytes = downloadFile(file, modelDirFile, index, files.size, completedBytes, totalBytes)
                }

                refreshLocalModelState()
                selected.firstOrNull()?.primaryModelName?.let { primary ->
                    if (_availableModelNames.value.any { it.equals(primary, ignoreCase = true) }) {
                        _modelName.value = primary
                    }
                }
                _showWelcome.value = false
                _downloadState.value = ModelDownloadState(
                    progress = 1f,
                    bytesDownloaded = totalBytes,
                    bytesTotal = totalBytes,
                    status = "Downloaded ${files.size} file${if (files.size == 1) "" else "s"}."
                )
                saveAll()
            } catch (e: Exception) {
                _downloadState.value = ModelDownloadState(error = e.message ?: "Download failed.")
            }
        }
    }

    fun uninstallModel(optionId: String) {
        if (_downloadState.value.isDownloading) return

        val option = downloadOptions.firstOrNull { it.id == optionId } ?: return
        scope.launch {
            try {
                val modelFile = File(_modelDir.value, option.primaryModelName)
                val deleted = withContext(Dispatchers.IO) {
                    modelFile.exists() && modelFile.delete()
                }

                refreshLocalModelState(selectFallbackIfMissing = true)
                _downloadState.value = ModelDownloadState(
                    status = if (deleted) {
                        "Removed ${option.title}."
                    } else {
                        "${option.title} was not installed."
                    }
                )
                saveAll()
            } catch (e: Exception) {
                _downloadState.value = ModelDownloadState(error = "Failed to remove ${option.title}: ${e.message}")
            }
        }
    }

    private suspend fun downloadFile(
        file: ModelDownloadFile,
        targetDir: File,
        index: Int,
        total: Int,
        completedBytesBefore: Long,
        totalBytes: Long
    ): Long {
        return withContext(Dispatchers.IO) {
            val target = File(targetDir, file.fileName)
            if (target.exists() && target.length() > 0L) {
                val completedBytes = completedBytesBefore + file.sizeBytes.coerceAtLeast(target.length())
                _downloadState.value = ModelDownloadState(
                    isDownloading = true,
                    currentFile = file.fileName,
                    progress = progressFor(completedBytes, totalBytes, index + 1, total),
                    bytesDownloaded = completedBytes,
                    bytesTotal = totalBytes,
                    status = "Already present: ${file.fileName}"
                )
                return@withContext completedBytes
            }

            val part = File(targetDir, "${file.fileName}.part")
            val request = HttpRequest.newBuilder(URI.create(file.url))
                .timeout(Duration.ofMinutes(30))
                .GET()
                .build()
            val response = httpClient.send(request, HttpResponse.BodyHandlers.ofInputStream())
            if (response.statusCode() !in 200..299) {
                throw IllegalStateException("Download failed for ${file.fileName}: HTTP ${response.statusCode()}")
            }

            val contentLength = response.headers().firstValueAsLong("content-length").orElse(file.sizeBytes)
            val effectiveFileSize = if (contentLength > 0L) contentLength else file.sizeBytes
            response.body().use { input ->
                part.outputStream().use { output ->
                    val buffer = ByteArray(DEFAULT_BUFFER_SIZE)
                    var read: Int
                    var downloaded = 0L
                    while (input.read(buffer).also { read = it } >= 0) {
                        output.write(buffer, 0, read)
                        downloaded += read
                        val bytesDownloaded = completedBytesBefore + downloaded
                        _downloadState.value = ModelDownloadState(
                            isDownloading = true,
                            currentFile = file.fileName,
                            progress = progressFor(bytesDownloaded, totalBytes, index, total),
                            bytesDownloaded = bytesDownloaded,
                            bytesTotal = totalBytes,
                            status = "Downloading ${index + 1}/$total"
                        )
                    }
                }
            }
            java.nio.file.Files.move(part.toPath(), target.toPath(), StandardCopyOption.REPLACE_EXISTING)
            val completedBytes = completedBytesBefore + effectiveFileSize.coerceAtLeast(target.length())
            _downloadState.value = ModelDownloadState(
                isDownloading = true,
                currentFile = file.fileName,
                progress = progressFor(completedBytes, totalBytes, index + 1, total),
                bytesDownloaded = completedBytes,
                bytesTotal = totalBytes,
                status = "Downloaded ${file.fileName}"
            )
            completedBytes
        }
    }

    private fun progressFor(bytesDownloaded: Long, bytesTotal: Long, completedFiles: Int, totalFiles: Int): Float {
        if (bytesTotal > 0L) {
            return (bytesDownloaded.toDouble() / bytesTotal.toDouble()).toFloat().coerceIn(0f, 1f)
        }
        return (completedFiles.toFloat() / totalFiles.toFloat()).coerceIn(0f, 1f)
    }

    override fun onCleared() {
        scope.cancel()
        super.onCleared()
    }
}
