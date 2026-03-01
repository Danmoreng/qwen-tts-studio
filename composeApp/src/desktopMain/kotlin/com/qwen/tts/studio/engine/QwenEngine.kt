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

    companion object {
        private var isNativeLoaded = false
        private val loadLock = Any()

        private fun resolveNativeRoot(): File {
            val userDir = File(System.getProperty("user.dir"))
            val candidates = mutableListOf<File>()
            candidates += userDir
            userDir.parentFile?.let { candidates += it }

            val jnaLibPath = System.getProperty("jna.library.path")
            if (!jnaLibPath.isNullOrBlank()) {
                jnaLibPath.split(File.pathSeparator)
                    .map { it.trim() }
                    .filter { it.isNotEmpty() }
                    .mapTo(candidates) { File(it) }
            }

            return candidates.firstOrNull { File(it, "qwen3_tts.dll").exists() }
                ?: throw IllegalArgumentException(
                    "Missing native library qwen3_tts.dll. Checked: ${
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

                    // Required native dependencies. Order matters:
                    // ggml.dll imports ggml-cpu.dll, so ggml-cpu must be loaded first.
                    val requiredDeps = listOf(
                        "ggml-base.dll",
                        "ggml-cpu.dll",
                        "ggml.dll"
                    )
                    for (depName in requiredDeps) {
                        val depFile = File(root, depName)
                        if (!depFile.exists()) {
                            throw IllegalStateException("Missing required dependency: ${depFile.absolutePath}")
                        }
                        try {
                            System.load(depFile.absolutePath)
                            println("[QwenEngine] Loaded dependency from root: $depName")
                        } catch (e: Throwable) {
                            throw IllegalStateException("Failed loading dependency: ${depFile.absolutePath}", e)
                        }
                    }

                    val dll = File(root, "qwen3_tts.dll")
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
            val candidates = listOf(
                File(root, "qwen3-tts-cli.exe"),
                File(root, "external/build/qwen3-tts-cpp/Release/qwen3-tts-cli.exe"),
                File(root, "external/build_fix/qwen3-tts-cpp/Release/qwen3-tts-cli.exe"),
                File(root.parentFile ?: root, "external/build/qwen3-tts-cpp/Release/qwen3-tts-cli.exe")
            )
            return candidates.firstOrNull { it.exists() && it.isFile }
        }
    }

    private external fun nativeInit(): Long
    private external fun nativeFree(ptr: Long)
    private external fun nativeLoadModels(ptr: Long, modelDir: String): Boolean
    private external fun nativeSynthesize(ptr: Long, text: String, referenceWav: String?, params: Any?): NativeResult?

    fun load(modelDir: String): Boolean {
        if (!File(modelDir).exists() || !File(modelDir).isDirectory) return false

        release()
        loadedModelDir = modelDir
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
                val ok = nativeLoadModels(nativePtr, modelDir)
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

    fun generate(text: String, referenceWav: String? = null): FloatArray? {
        if (useCliFallback) {
            return generateViaCli(text, referenceWav)
        }

        if (nativePtr == 0L) return null

        return try {
            val result = nativeSynthesize(nativePtr, text, referenceWav, null)
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

    private fun generateViaCli(text: String, referenceWav: String?): FloatArray? {
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
            "-o", outputFile.absolutePath
        )
        if (!referenceWav.isNullOrBlank()) {
            command += listOf("-r", referenceWav)
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
