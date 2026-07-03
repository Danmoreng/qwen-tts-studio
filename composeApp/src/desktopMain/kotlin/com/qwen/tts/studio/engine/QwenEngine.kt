package com.qwen.tts.studio.engine

import java.io.File
import javax.sound.sampled.AudioFormat
import javax.sound.sampled.AudioSystem

enum class NativeBackendPreference(val id: String, val label: String) {
    Auto("auto", "Auto"),
    Cpu("cpu", "CPU"),
    Cuda("cuda", "CUDA");

    companion object {
        fun fromId(id: String?): NativeBackendPreference =
            entries.firstOrNull { it.id.equals(id, ignoreCase = true) } ?: Auto
    }
}

/**
 * High-level wrapper for the Qwen3 Engine using JNI.
 * This class handles native library loading, model initialization, and audio synthesis.
 */
class QwenEngine {
    private var nativePtr: Long = 0
    private var loadedModelDir: String? = null
    private var loadedModelName: String? = null
    private var useCliFallback = false

    /**
     * Data class matching JNI constructor in qwen3_tts_jni.cpp.
     * Contains the result of a synthesis operation.
     *
     * @property audio The synthesized audio samples as a FloatArray (PCM).
     * @property sampleRate The sample rate of the generated audio.
     * @property success Whether the synthesis was successful.
     * @property errorMsg An error message if the synthesis failed.
     * @property timeMs The time taken for synthesis in milliseconds.
     */
    data class NativeResult(
        val audio: FloatArray?,
        val sampleRate: Int,
        val success: Boolean,
        val errorMsg: String?,
        val timeMs: Long
    )

    /**
     * Parameters for the synthesis operation.
     *
     * @property languageId The ID of the language to use for synthesis.
     * @property instruction Optional instruction or prompt for the model.
     * @property speaker Optional name of the speaker to use (for models with named speakers).
     * @property maxAudioTokens Maximum number of audio tokens to generate.
     * @property temperature Sampling temperature (higher is more random).
     * @property topP Top-P (nucleus) sampling threshold.
     * @property topK Top-K sampling threshold.
     * @property threads Number of threads to use for synthesis.
     */
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

    data class StreamingOptions(
        val chunkSeconds: Float = 0.75f,
        val leftContextSeconds: Float = 2.0f,
        val collectAudio: Boolean = true
    )

    data class NativeAudioChunk(
        val audio: FloatArray,
        val sampleRate: Int,
        val startSample: Long,
        val endSample: Long,
        val startFrame: Int,
        val endFrame: Int,
        val startTextByte: Int,
        val endTextByte: Int,
        val textAlignmentKind: Int,
        val confidence: Float
    )

    data class NativeOperationResult(
        val success: Boolean,
        val errorMsg: String? = null
    )

    interface StreamingAudioCallback {
        fun onAudioChunk(
            audio: FloatArray,
            sampleRate: Int,
            startSample: Long,
            endSample: Long,
            startFrame: Int,
            endFrame: Int,
            startTextByte: Int,
            endTextByte: Int,
            textAlignmentKind: Int,
            confidence: Float
        ): Boolean
    }

    /**
     * Capabilities of the currently loaded model.
     *
     * @property loaded Whether a model is currently loaded.
     * @property supportsCloning Whether the model supports voice cloning via reference audio.
     * @property supportsNamedSpeakers Whether the model supports selecting speakers by name.
     * @property supportsInstruction Whether the model supports text instructions.
     * @property speakerEmbeddingDim The dimension of the speaker embeddings.
     * @property modelKind The kind of model (Base, CustomVoice, etc.).
     * @property speakerCount The number of built-in speakers in the model.
     */
    data class NativeCapabilities(
        val loaded: Boolean,
        val supportsCloning: Boolean,
        val supportsNamedSpeakers: Boolean,
        val supportsInstruction: Boolean,
        val speakerEmbeddingDim: Int,
        val modelKind: Int,
        val speakerCount: Int
    )

    companion object {
        /** Unknown model kind. */
        const val MODEL_KIND_UNKNOWN = 0
        /** Base model kind, typically supports cloning. */
        const val MODEL_KIND_BASE = 1
        /** Custom voice model kind, typically supports named speakers. */
        const val MODEL_KIND_CUSTOM_VOICE = 2
        /** Voice design model kind. */
        const val MODEL_KIND_VOICE_DESIGN = 3

        const val BACKEND_AUTO = 0
        const val BACKEND_CPU = 1
        const val BACKEND_CUDA = 2

        private var isNativeLoaded = false
        private val loadLock = Any()

        /**
         * Maps a language code or name to its corresponding ID used by the engine.
         *
         * @param lang The language code (e.g., "en", "zh") or name.
         * @return The language ID.
         */
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

        /**
         * Maps a language ID back to its 2-letter ISO language code.
         *
         * @param id The language ID.
         * @return The 2-letter language code.
         */
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
            candidates += File(userDir, "external/build-linux")
            userDir.parentFile?.let { 
                candidates += File(it, "external/qwen3-tts-cpp/build") 
                candidates += File(it, "external/build-linux")
            }

            val jnaLibPath = System.getProperty("jna.library.path")
            if (!jnaLibPath.isNullOrBlank()) {
                jnaLibPath.split(File.pathSeparator)
                    .map { it.trim() }
                    .filter { it.isNotEmpty() }
                    .mapTo(candidates) { File(it) }
            }

            val isWindows = System.getProperty("os.name").lowercase().contains("win")
            val libName = if (isWindows) "qwen3_tts.dll" else "libqwen3_tts.so"

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

                    if (isWindows) {
                        preloadWindowsCudaRuntime(root)
                    }

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
                            if (depName.contains("cuda", ignoreCase = true) && backendLoaded) {
                                System.err.println("[QwenEngine] CUDA backend not available: ${e.message}")
                            } else {
                                throw IllegalStateException("Failed loading dependency: ${depFile.absolutePath}", e)
                            }
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

                    val mainLibName = if (isWindows) "qwen3_tts.dll" else "libqwen3_tts.so"
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

        private fun preloadWindowsCudaRuntime(root: File) {
            val cudaRuntimePatterns = listOf(
                "cudart64_*.dll",
                "cublas64_*.dll",
                "cublasLt64_*.dll"
            )

            val searchDirs = linkedSetOf<File>()
            searchDirs += root
            listOf("CUDA_PATH", "CUDAToolkit_ROOT")
                .mapNotNull { System.getenv(it) }
                .filter { it.isNotBlank() }
                .forEach { cudaRoot ->
                    searchDirs += File(cudaRoot, "bin")
                    searchDirs += File(cudaRoot, "bin/x64")
                }

            File("C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA")
                .listFiles { file -> file.isDirectory }
                ?.sortedByDescending { it.name }
                ?.forEach { cudaRoot ->
                    searchDirs += File(cudaRoot, "bin")
                    searchDirs += File(cudaRoot, "bin/x64")
                }

            for (pattern in cudaRuntimePatterns) {
                val runtimeDll = searchDirs
                    .asSequence()
                    .filter { it.exists() && it.isDirectory }
                    .mapNotNull { dir ->
                        dir.listFiles { file ->
                            file.isFile && wildcardMatches(pattern, file.name)
                        }?.maxByOrNull { it.lastModified() }
                    }
                    .firstOrNull()

                if (runtimeDll != null) {
                    try {
                        System.load(runtimeDll.absolutePath)
                        println("[QwenEngine] Loaded CUDA runtime: ${runtimeDll.absolutePath}")
                    } catch (e: Throwable) {
                        System.err.println("[QwenEngine] Failed to preload CUDA runtime ${runtimeDll.name}: ${e.message}")
                    }
                }
            }
        }

        private fun wildcardMatches(pattern: String, value: String): Boolean {
            val regex = pattern
                .replace(".", "\\.")
                .replace("*", ".*")
                .toRegex(RegexOption.IGNORE_CASE)
            return regex.matches(value)
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
    private external fun nativeLoadIclPromptEncoder(ptr: Long, modelDir: String, modelName: String?): Boolean
    private external fun nativeSetBackendPreference(preference: Int): Boolean
    private external fun nativeGetCompiledBackendMask(): Int
    private external fun nativeGetActiveBackendName(): String?
    private external fun nativeSynthesize(
        ptr: Long,
        text: String,
        referenceWav: String?,
        speakerEmbeddingPath: String?,
        params: Any?
    ): NativeResult?
    private external fun nativeSynthesizeWithIclPrompt(
        ptr: Long,
        text: String,
        iclPromptPath: String?,
        params: Any?
    ): NativeResult?
    private external fun nativeSynthesizeStreaming(
        ptr: Long,
        text: String,
        referenceWav: String?,
        speakerEmbeddingPath: String?,
        params: Any?,
        chunkSeconds: Float,
        leftContextSeconds: Float,
        collectAudio: Boolean,
        callback: StreamingAudioCallback
    ): NativeResult?
    private external fun nativeExtractSpeakerEmbedding(ptr: Long, referenceWav: String, outputPath: String): Boolean
    private external fun nativeExtractIclPrompt(
        ptr: Long,
        referenceWav: String,
        referenceText: String,
        outputPath: String
    ): Boolean
    private external fun nativeGetAvailableSpeakers(ptr: Long): String?
    private external fun nativeGetLastError(ptr: Long): String?
    private external fun nativeGetModelCapabilities(ptr: Long): NativeCapabilities?

    /**
     * Loads the engine and models from the specified directory.
     *
     * @param modelDir Path to the directory containing model files.
     * @param modelName Optional specific model name or prefix.
     * @return true if the engine was loaded successfully (either natively or via CLI fallback).
     */
    fun load(
        modelDir: String,
        modelName: String? = null,
        backendPreference: NativeBackendPreference = NativeBackendPreference.Auto
    ): Boolean {
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
            if (!nativeSetBackendPreference(backendPreference.nativeValue())) {
                throw IllegalStateException("Failed to select native backend: ${backendPreference.label}")
            }
            nativePtr = nativeInit()
            if (nativePtr != 0L) {
                val ok = nativeLoadModels(nativePtr, modelDir, modelName)
                if (ok) {
                    nativeGetActiveBackendName()?.takeIf { it.isNotBlank() }?.let {
                        println("[QwenEngine] Active backend: $it")
                    }
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

    fun loadIclPromptEncoder(
        modelDir: String,
        modelName: String? = null,
        backendPreference: NativeBackendPreference = NativeBackendPreference.Auto
    ): Boolean {
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
            if (!nativeSetBackendPreference(backendPreference.nativeValue())) {
                throw IllegalStateException("Failed to select native backend: ${backendPreference.label}")
            }
            nativePtr = nativeInit()
            if (nativePtr != 0L) {
                val ok = nativeLoadIclPromptEncoder(nativePtr, modelDir, modelName)
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
        } catch (e: UnsatisfiedLinkError) {
            System.err.println("[QwenEngine] ICL prompt encoder JNI is unavailable. Rebuild qwen3_tts.dll after updating qwen3-tts.cpp: ${e.message}")
            val root = resolveNativeRoot()
            useCliFallback = resolveCliExe(root) != null
            useCliFallback
        } catch (e: Throwable) {
            e.printStackTrace()
            val root = resolveNativeRoot()
            useCliFallback = resolveCliExe(root) != null
            useCliFallback
        }
    }

    /**
     * Generates audio from the given text.
     *
     * @param text The text to synthesize.
     * @param referenceWav Optional path to a reference WAV file for voice cloning.
     * @param speakerEmbeddingPath Optional path to a pre-extracted speaker embedding file.
     * @param languageId The language ID to use (default is English).
     * @param instruction Optional text instruction for the model.
     * @param speaker Optional speaker name.
     * @return A FloatArray containing the synthesized audio samples, or null if synthesis failed.
     */
    fun generate(
        text: String,
        referenceWav: String? = null,
        speakerEmbeddingPath: String? = null,
        iclPromptPath: String? = null,
        languageId: Int = 2050,
        instruction: String? = null,
        speaker: String? = null
    ): FloatArray? {
        if (useCliFallback) {
            return generateViaCli(text, referenceWav, speakerEmbeddingPath, iclPromptPath, languageId, instruction, speaker)
        }

        if (nativePtr == 0L) return null

        return try {
            val params = NativeParams(languageId = languageId, instruction = instruction, speaker = speaker)
            val result = try {
                if (!iclPromptPath.isNullOrBlank()) {
                    nativeSynthesizeWithIclPrompt(nativePtr, text, iclPromptPath, params)
                } else {
                    nativeSynthesize(nativePtr, text, referenceWav, speakerEmbeddingPath, params)
                }
            } catch (e: UnsatisfiedLinkError) {
                System.err.println("[QwenEngine] ICL prompt synthesis JNI is unavailable. Rebuild qwen3_tts.dll after updating qwen3-tts.cpp: ${e.message}")
                null
            }
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

    fun generateStreaming(
        text: String,
        referenceWav: String? = null,
        speakerEmbeddingPath: String? = null,
        iclPromptPath: String? = null,
        languageId: Int = 2050,
        instruction: String? = null,
        speaker: String? = null,
        options: StreamingOptions = StreamingOptions(),
        onAudioChunk: (NativeAudioChunk) -> Boolean
    ): NativeResult? {
        if (useCliFallback) {
            val audio = generateViaCli(text, referenceWav, speakerEmbeddingPath, iclPromptPath, languageId, instruction, speaker)
            return if (audio != null) {
                NativeResult(audio, 24_000, true, null, 0L)
            } else {
                NativeResult(null, 24_000, false, "Streaming is unavailable in CLI fallback mode.", 0L)
            }
        }

        if (nativePtr == 0L) return null
        if (!iclPromptPath.isNullOrBlank()) {
            val audio = generate(
                text = text,
                referenceWav = null,
                speakerEmbeddingPath = null,
                iclPromptPath = iclPromptPath,
                languageId = languageId,
                instruction = instruction,
                speaker = speaker
            )
            return if (audio != null) {
                NativeResult(audio, 24_000, true, null, 0L)
            } else {
                NativeResult(null, 24_000, false, "ICL prompt streaming is unavailable in this JNI build.", 0L)
            }
        }

        return try {
            val params = NativeParams(languageId = languageId, instruction = instruction, speaker = speaker)
            val callback = object : StreamingAudioCallback {
                override fun onAudioChunk(
                    audio: FloatArray,
                    sampleRate: Int,
                    startSample: Long,
                    endSample: Long,
                    startFrame: Int,
                    endFrame: Int,
                    startTextByte: Int,
                    endTextByte: Int,
                    textAlignmentKind: Int,
                    confidence: Float
                ): Boolean {
                    return onAudioChunk(
                        NativeAudioChunk(
                            audio = audio,
                            sampleRate = sampleRate,
                            startSample = startSample,
                            endSample = endSample,
                            startFrame = startFrame,
                            endFrame = endFrame,
                            startTextByte = startTextByte,
                            endTextByte = endTextByte,
                            textAlignmentKind = textAlignmentKind,
                            confidence = confidence
                        )
                    )
                }
            }
            val result = nativeSynthesizeStreaming(
                nativePtr,
                text,
                referenceWav,
                speakerEmbeddingPath,
                params,
                options.chunkSeconds,
                options.leftContextSeconds,
                options.collectAudio,
                callback
            )
            if (result != null && !result.success) {
                System.err.println("[QwenEngine] Native streaming synthesis failed: ${result.errorMsg}")
            }
            result
        } catch (e: Throwable) {
            e.printStackTrace()
            null
        }
    }

    /**
     * Releases native resources. Should be called when the engine is no longer needed.
     */
    fun release() {
        if (nativePtr != 0L) {
            nativeFree(nativePtr)
            nativePtr = 0L
        }
    }

    fun compiledBackendMask(): Int {
        ensureNativeLoaded()
        return if (isNativeLoaded) nativeGetCompiledBackendMask() else BACKEND_CPU
    }

    private fun NativeBackendPreference.nativeValue(): Int = when (this) {
        NativeBackendPreference.Auto -> BACKEND_AUTO
        NativeBackendPreference.Cpu -> BACKEND_CPU
        NativeBackendPreference.Cuda -> BACKEND_CUDA
    }

    /**
     * Returns a list of available built-in speakers for the currently loaded model.
     *
     * @return A list of speaker names.
     */
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

    /**
     * Gets the capabilities of the currently loaded model.
     *
     * @return A NativeCapabilities object, or null if no model is loaded.
     */
    fun getModelCapabilities(): NativeCapabilities? {
        if (useCliFallback) {
            return inferCapabilitiesFromModelName(loadedModelName)
        }
        if (nativePtr == 0L) return null
        return try {
            nativeGetModelCapabilities(nativePtr)
        } catch (e: Throwable) {
            e.printStackTrace()
            null
        }
    }

    /**
     * Extracts a speaker embedding from a reference WAV file.
     *
     * @param referenceWav Path to the reference WAV file.
     * @param outputPath Path where the extracted embedding should be saved.
     * @return true if the extraction was successful.
     */
    fun extractSpeakerEmbedding(referenceWav: String, outputPath: String): Boolean {
        return extractSpeakerEmbeddingDetailed(referenceWav, outputPath).success
    }

    fun extractSpeakerEmbeddingDetailed(referenceWav: String, outputPath: String): NativeOperationResult {
        if (referenceWav.isBlank() || outputPath.isBlank()) {
            return NativeOperationResult(false, "Reference WAV or output path is blank.")
        }

        if (useCliFallback) {
            val ok = extractSpeakerEmbeddingViaCli(referenceWav, outputPath)
            return NativeOperationResult(ok, if (ok) null else "CLI speaker embedding extraction failed. See terminal log for details.")
        }

        if (nativePtr == 0L) return NativeOperationResult(false, "Native engine is not loaded.")

        return try {
            val ok = nativeExtractSpeakerEmbedding(nativePtr, referenceWav, outputPath)
            if (ok) {
                NativeOperationResult(true)
            } else {
                NativeOperationResult(false, nativeGetLastError(nativePtr).takeUnless { it.isNullOrBlank() })
            }
        } catch (e: Throwable) {
            e.printStackTrace()
            NativeOperationResult(false, e.message ?: e::class.simpleName)
        }
    }

    fun extractIclPrompt(referenceWav: String, referenceText: String, outputPath: String): Boolean {
        return extractIclPromptDetailed(referenceWav, referenceText, outputPath).success
    }

    fun extractIclPromptDetailed(referenceWav: String, referenceText: String, outputPath: String): NativeOperationResult {
        if (referenceWav.isBlank() || referenceText.isBlank() || outputPath.isBlank()) {
            return NativeOperationResult(false, "Reference WAV, reference text, or output path is blank.")
        }

        if (useCliFallback) {
            val ok = extractIclPromptViaCli(referenceWav, referenceText, outputPath)
            return NativeOperationResult(ok, if (ok) null else "CLI ICL prompt extraction failed. See terminal log for details.")
        }

        if (nativePtr == 0L) return NativeOperationResult(false, "Native engine is not loaded.")

        return try {
            val ok = nativeExtractIclPrompt(nativePtr, referenceWav, referenceText, outputPath)
            if (ok) {
                NativeOperationResult(true)
            } else {
                NativeOperationResult(false, nativeGetLastError(nativePtr).takeUnless { it.isNullOrBlank() })
            }
        } catch (e: UnsatisfiedLinkError) {
            val message = "ICL prompt extraction is unavailable in the loaded native library. Rebuild qwen3_tts.dll after updating qwen3-tts.cpp."
            System.err.println("[QwenEngine] $message ${e.message}")
            NativeOperationResult(false, message)
        } catch (e: Throwable) {
            e.printStackTrace()
            NativeOperationResult(false, e.message ?: e::class.simpleName)
        }
    }

    private fun generateViaCli(
        text: String,
        referenceWav: String?,
        speakerEmbeddingPath: String?,
        iclPromptPath: String?,
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
        if (!iclPromptPath.isNullOrBlank()) {
            command += listOf("--icl-prompt", iclPromptPath)
        } else if (!speakerEmbeddingPath.isNullOrBlank()) {
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

    private fun extractIclPromptViaCli(referenceWav: String, referenceText: String, outputPath: String): Boolean {
        val modelDir = loadedModelDir ?: return false
        val root = try { resolveNativeRoot() } catch (e: Exception) { File(".") }
        val cliExe = resolveCliExe(root) ?: return false

        val command = mutableListOf(
            cliExe.absolutePath,
            "-m", modelDir,
            "-r", referenceWav,
            "--reference-text", referenceText,
            "--extract-icl-prompt", outputPath
        )

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
            System.err.println("[QwenEngine] CLI ICL prompt extraction failed (exit=$exitCode).")
            if (processOutput.isNotBlank()) {
                System.err.println(processOutput)
            }
            return false
        }
        return File(outputPath).exists()
    }

    private fun inferCapabilitiesFromModelName(modelName: String?): NativeCapabilities {
        val normalized = modelName.orEmpty().lowercase()
        val isCustomVoice = normalized.contains("customvoice")
        val isBase = normalized.contains("base")
        val isVoiceDesign = normalized.contains("voicedesign") || normalized.contains("voice-design")
        val is17 = normalized.contains("1.7b")
        val dim = if (is17) 2048 else 1024
        val modelKind = when {
            isCustomVoice -> MODEL_KIND_CUSTOM_VOICE
            isVoiceDesign -> MODEL_KIND_VOICE_DESIGN
            isBase -> MODEL_KIND_BASE
            else -> MODEL_KIND_UNKNOWN
        }
        return NativeCapabilities(
            loaded = true,
            supportsCloning = isBase || isCustomVoice || isVoiceDesign,
            supportsNamedSpeakers = isCustomVoice,
            supportsInstruction = (isCustomVoice && is17) || isVoiceDesign,
            speakerEmbeddingDim = dim,
            modelKind = modelKind,
            speakerCount = 0
        )
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
