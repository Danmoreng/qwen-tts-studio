package com.qwen.tts.studio.engine

import java.io.File
import javax.sound.sampled.AudioFormat
import javax.sound.sampled.AudioSystem

/**
 * High-level wrapper for the Qwen3 Engine using JNI.
 */
class QwenEngine {
    private var nativePtr: Long = 0
    private var loadedModelDir: String? = null
    private var loadedModelName: String? = null
    private var useCliFallback = false

    /**
     * Data class matching JNI constructor in qwen3_tts_jni.cpp
     */
    data class NativeResult(
        val audio: FloatArray?,
        val sampleRate: Int,
        val success: Boolean,
        val errorMsg: String?,
        val timeMs: Long
    )

    data class NativeParams(
        val languageId: Int = 2050, // Default to English
        val instruction: String? = null,
        val speaker: String? = null,
        val maxAudioTokens: Int = 4096,
        val temperature: Float = 0.9f,
        val topP: Float = 1.0f,
        val topK: Int = 50,
        val threads: Int = 4
    )

    companion object {
        private var isNativeLoaded = false
        private val loadLock = Any()

        fun mapLanguageToId(lang: String): Int {
            return when (lang.lowercase()) {
                "en", "english" -> 2050
                "ru", "russian" -> 2069
                "zh", "chinese" -> 2055
                "ja", "japanese" -> 2058
                "ko", "korean" -> 2064
                "de", "german" -> 2053
                "fr", "french" -> 2061
                "es", "spanish" -> 2054
                "it", "italian" -> 2070
                "pt", "portuguese" -> 2071
                else -> 2050
            }
        }

        fun mapIdToLanguageCode(id: Int): String {
            return when (id) {
                2050 -> "en"
                2069 -> "ru"
                2055 -> "zh"
                2058 -> "ja"
                2064 -> "ko"
                2053 -> "de"
                2061 -> "fr"
                2054 -> "es"
                2070 -> "it"
                2071 -> "pt"
                else -> "en"
            }
        }

        private fun resolveNativeRoot(): File {
            val userDir = File(System.getProperty("user.dir"))
            val candidates = mutableListOf<File>()
            candidates += userDir
            userDir.parentFile?.let { candidates += it }
            
            // Add build directory for development (root or subproject)
            candidates += File(userDir, "external/qwen3-tts-cpp/build")
            userDir.parentFile?.let { candidates += File(it, "external/qwen3-tts-cpp/build") }

            val jnaLibPath = System.getProperty("jna.library.path")
            if (!jnaLibPath.isNullOrBlank()) {
                jnaLibPath.split(File.pathSeparator)
                    .map { it.trim() }
                    .filter { it.isNotEmpty() }
                    .mapTo(candidates) { File(it) }
            }

            val isWindows = System.getProperty("os.name").lowercase().contains("win")
            val libName = if (isWindows) "qwen3_tts.dll" else "libqwen3_tts_jni.so"

            return candidates.firstOrNull { File(it, libName).exists() }
                ?: throw IllegalArgumentException(
                    "Missing native library $libName. Checked: ${
                        candidates.joinToString(", ") { it.absolutePath }
                    }"
                )
        }

        private fun ensureNativeLoaded() {
            synchronized(loadLock) {
                if (isNativeLoaded) return
                try {
                    val root = resolveNativeRoot()
                    println("[QwenEngine] Root found at: ${root.absolutePath}")

                    val isWindows = System.getProperty("os.name").lowercase().contains("win")
                    val ext = if (isWindows) ".dll" else ".so"
                    val prefix = if (isWindows) "" else "lib"

                    if (isWindows) {
                        // Best-effort preload for common runtime/system libraries.
                        val systemDeps = listOf("vcomp140", "Psapi")
                        for (depName in systemDeps) {
                            try {
                                System.loadLibrary(depName)
                                println("[QwenEngine] Loaded system library: $depName.dll")
                            } catch (_: Throwable) {
                                // Optional preload: these may already be present/loaded.
                            }
                        }
                    }

                    // Required base dependency
                    val ggmlBaseName = "${prefix}ggml-base$ext"
                    var ggmlBase = File(root, ggmlBaseName)
                    if (!ggmlBase.exists()) {
                        // Check ggml/src subdirectory for development builds
                        ggmlBase = File(root, "ggml/src/$ggmlBaseName")
                    }
                    
                    if (!ggmlBase.exists()) {
                        throw IllegalStateException("Missing required dependency: $ggmlBaseName. Checked ${root.absolutePath} and its ggml/src subdirectory.")
                    }
                    System.load(ggmlBase.absolutePath)
                    println("[QwenEngine] Loaded dependency from root: ${ggmlBase.name}")

                    // Optional backend dependencies (CPU / CUDA).
                    // Load before ggml because ggml can import backend DLLs.
                    val backendCandidates = listOf("${prefix}ggml-cpu$ext", "${prefix}ggml-cuda$ext")
                    var backendLoaded = false
                    for (depName in backendCandidates) {
                        var depFile = File(root, depName)
                        if (!depFile.exists()) {
                            depFile = File(root, "ggml/src/$depName")
                        }
                        
                        if (!depFile.exists()) continue
                        try {
                            System.load(depFile.absolutePath)
                            println("[QwenEngine] Loaded dependency from root: $depName")
                            backendLoaded = true
                        } catch (e: Throwable) {
                            throw IllegalStateException("Failed loading dependency: ${depFile.absolutePath}", e)
                        }
                    }
                    if (!backendLoaded) {
                        throw IllegalStateException(
                            "Missing backend dependency. Expected at least one of: ${prefix}ggml-cpu$ext, ${prefix}ggml-cuda$ext"
                        )
                    }

                    val ggmlName = "${prefix}ggml$ext"
                    var ggml = File(root, ggmlName)
                    if (!ggml.exists()) {
                        ggml = File(root, "ggml/src/$ggmlName")
                    }
                    
                    if (!ggml.exists()) {
                        throw IllegalStateException("Missing required dependency: $ggmlName. Checked ${root.absolutePath} and its ggml/src subdirectory.")
                    }
                    System.load(ggml.absolutePath)
                    println("[QwenEngine] Loaded dependency from root: ${ggml.name}")

                    val mainLibName = if (isWindows) "qwen3_tts.dll" else "libqwen3_tts_jni.so"
                    val dll = File(root, mainLibName)
                    System.load(dll.absolutePath)
                    isNativeLoaded = true
                    println("[QwenEngine] JNI loaded successfully: ${dll.absolutePath}")
                } catch (e: Throwable) {
                    System.err.println("[QwenEngine] Failed to load JNI: ${e.message}")
                    e.printStackTrace()
                }
            }
        }

        private fun resolveCliExe(root: File): File? {
            val isWindows = System.getProperty("os.name").lowercase().contains("win")
            val exeExt = if (isWindows) ".exe" else ""
            
            val candidates = listOf(
                File(root, "qwen3-tts-cli$exeExt"),
                File(root, "external/qwen3-tts-cpp/build/qwen3-tts-cli$exeExt"),
                File(root, "external/build/qwen3-tts-cpp/Release/qwen3-tts-cli$exeExt"),
                File(root, "external/build_fix/qwen3-tts-cpp/Release/qwen3-tts-cli$exeExt"),
                File(root.parentFile ?: root, "external/build/qwen3-tts-cpp/Release/qwen3-tts-cli$exeExt")
            )
            return candidates.firstOrNull { it.exists() && it.isFile }
        }
    }

    private external fun nativeInit(): Long
    private external fun nativeFree(ptr: Long)
    private external fun nativeLoadModels(ptr: Long, modelDir: String, modelName: String?): Boolean
    private external fun nativeSynthesize(
        ptr: Long,
        text: String,
        referenceWav: String?,
        speakerEmbeddingPath: String?,
        params: Any?
    ): NativeResult?
    private external fun nativeExtractSpeakerEmbedding(ptr: Long, referenceWav: String, outputPath: String): Boolean
    private external fun nativeGetAvailableSpeakers(ptr: Long): String?

    fun load(modelDir: String, modelName: String? = null): Boolean {
        if (!File(modelDir).exists() || !File(modelDir).isDirectory) return false

        release()
        loadedModelDir = modelDir
        loadedModelName = modelName
        useCliFallback = false

        ensureNativeLoaded()
        
        if (!isNativeLoaded) {
            val root = try { resolveNativeRoot() } catch (e: Exception) { File(".") }
            useCliFallback = resolveCliExe(root) != null
            return useCliFallback
        }

        return try {
            nativePtr = nativeInit()
            if (nativePtr != 0L) {
                val ok = nativeLoadModels(nativePtr, modelDir, modelName)
                if (ok) {
                    true
                } else {
                    release()
                    val root = resolveNativeRoot()
                    useCliFallback = resolveCliExe(root) != null
                    useCliFallback
                }
            } else {
                val root = resolveNativeRoot()
                useCliFallback = resolveCliExe(root) != null
                useCliFallback
            }
        } catch (e: Throwable) {
            e.printStackTrace()
            val root = resolveNativeRoot()
            useCliFallback = resolveCliExe(root) != null
            useCliFallback
        }
    }

    fun generate(
        text: String,
        referenceWav: String? = null,
        speakerEmbeddingPath: String? = null,
        languageId: Int = 2050,
        instruction: String? = null,
        speaker: String? = null
    ): FloatArray? {
        if (useCliFallback) {
            return generateViaCli(text, referenceWav, speakerEmbeddingPath, languageId, instruction, speaker)
        }

        if (nativePtr == 0L) return null

        return try {
            val params = NativeParams(languageId = languageId, instruction = instruction, speaker = speaker)
            val result = nativeSynthesize(nativePtr, text, referenceWav, speakerEmbeddingPath, params)
            if (result != null && result.success) {
                result.audio
            } else {
                if (result != null) {
                    System.err.println("[QwenEngine] Native synthesis failed: ${result.errorMsg}")
                }
                null
            }
        } catch (e: Throwable) {
            e.printStackTrace()
            null
        }
    }

    fun release() {
        if (nativePtr != 0L) {
            nativeFree(nativePtr)
            nativePtr = 0L
        }
    }

    fun getAvailableSpeakers(): List<String> {
        if (useCliFallback || nativePtr == 0L) return emptyList()
        return try {
            val raw = nativeGetAvailableSpeakers(nativePtr).orEmpty()
            if (raw.isBlank()) emptyList() else {
                raw.lineSequence()
                    .map { it.trim() }
                    .filter { it.isNotEmpty() }
                    .toList()
            }
        } catch (e: Throwable) {
            e.printStackTrace()
            emptyList()
        }
    }

    fun extractSpeakerEmbedding(referenceWav: String, outputPath: String): Boolean {
        if (referenceWav.isBlank() || outputPath.isBlank()) return false

        if (useCliFallback) {
            return extractSpeakerEmbeddingViaCli(referenceWav, outputPath)
        }

        if (nativePtr == 0L) return false

        return try {
            nativeExtractSpeakerEmbedding(nativePtr, referenceWav, outputPath)
        } catch (e: Throwable) {
            e.printStackTrace()
            false
        }
    }

    private fun generateViaCli(
        text: String,
        referenceWav: String?,
        speakerEmbeddingPath: String?,
        languageId: Int,
        instruction: String?,
        speaker: String?
    ): FloatArray? {
        val modelDir = loadedModelDir ?: return null
        val root = try { resolveNativeRoot() } catch (e: Exception) { File(".") }
        val cliExe = resolveCliExe(root) ?: return null

        val tempDir = File(root, ".tts-cli")
        if (!tempDir.exists()) tempDir.mkdirs()
        val outputFile = File(tempDir, "out-${System.nanoTime()}.wav")

        val command = mutableListOf(
            cliExe.absolutePath,
            "-m", modelDir,
            "-t", text,
            "-o", outputFile.absolutePath,
            "-l", mapIdToLanguageCode(languageId)
        )
        loadedModelName?.takeIf { it.isNotBlank() }?.let {
            command += listOf("--model-name", it)
        }
        if (!speakerEmbeddingPath.isNullOrBlank()) {
            command += listOf("--speaker-embedding", speakerEmbeddingPath)
        } else if (!referenceWav.isNullOrBlank()) {
            command += listOf("-r", referenceWav)
        } else if (!speaker.isNullOrBlank()) {
            command += listOf("--speaker", speaker)
        }
        if (!instruction.isNullOrBlank()) {
            command += listOf("--instruction", instruction)
        }

        val process = ProcessBuilder(command)
            .directory(root)
            .redirectErrorStream(true)
            .start()

        val processOutput = process.inputStream.bufferedReader().use { it.readText() }
        val exitCode = process.waitFor()
        if (exitCode != 0 || !outputFile.exists()) {
            System.err.println("[QwenEngine] CLI fallback failed (exit=$exitCode).")
            if (processOutput.isNotBlank()) {
                System.err.println(processOutput)
            }
            return null
        }

        return try {
            readWavToFloatArray(outputFile)
        } finally {
            outputFile.delete()
        }
    }

    private fun extractSpeakerEmbeddingViaCli(referenceWav: String, outputPath: String): Boolean {
        val modelDir = loadedModelDir ?: return false
        val root = try { resolveNativeRoot() } catch (e: Exception) { File(".") }
        val cliExe = resolveCliExe(root) ?: return false
        val tempDir = File(root, ".tts-cli")
        if (!tempDir.exists()) tempDir.mkdirs()

        val command = listOf(
            cliExe.absolutePath,
            "-m", modelDir,
            "-t", "embedding extraction",
            "-r", referenceWav,
            "--dump-speaker-embedding", outputPath,
            "-o", File(tempDir, "embedding-${System.nanoTime()}.wav").absolutePath
        ).toMutableList()

        loadedModelName?.takeIf { it.isNotBlank() }?.let {
            command += listOf("--model-name", it)
        }

        val process = ProcessBuilder(command)
            .directory(root)
            .redirectErrorStream(true)
            .start()
        val processOutput = process.inputStream.bufferedReader().use { it.readText() }
        val exitCode = process.waitFor()
        if (exitCode != 0) {
            System.err.println("[QwenEngine] CLI embedding extraction failed (exit=$exitCode).")
            if (processOutput.isNotBlank()) {
                System.err.println(processOutput)
            }
            return false
        }
        return File(outputPath).exists()
    }

    private fun readWavToFloatArray(file: File): FloatArray {
        AudioSystem.getAudioInputStream(file).use { input ->
            val targetFormat = AudioFormat(
                AudioFormat.Encoding.PCM_SIGNED,
                input.format.sampleRate,
                16,
                1,
                2,
                input.format.sampleRate,
                false
            )
            AudioSystem.getAudioInputStream(targetFormat, input).use { pcm ->
                val bytes = pcm.readBytes()
                val samples = FloatArray(bytes.size / 2)
                var j = 0
                var i = 0
                while (i + 1 < bytes.size) {
                    val lo = bytes[i].toInt() and 0xFF
                    val hi = bytes[i + 1].toInt()
                    val v = (hi shl 8) or lo
                    samples[j++] = (v.toShort() / 32768.0f)
                    i += 2
                }
                return if (j == samples.size) samples else samples.copyOf(j)
            }
        }
    }
}
