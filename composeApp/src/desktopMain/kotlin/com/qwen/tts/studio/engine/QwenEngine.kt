package com.qwen.tts.studio.engine

import com.sun.jna.Memory
import com.sun.jna.NativeLibrary
import com.sun.jna.Pointer
import com.sun.jna.Function
import com.sun.jna.ptr.IntByReference
import java.io.File
import java.nio.charset.StandardCharsets
import javax.sound.sampled.AudioFormat
import javax.sound.sampled.AudioSystem

private class Qwen3Native(private val lib: NativeLibrary) {
    private val backendInitFn = lib.getFunction("qwen3_tts_backend_init", Function.C_CONVENTION)
    private val initFn = lib.getFunction("qwen3_tts_init", Function.C_CONVENTION)
    private val generateFn = lib.getFunction("qwen3_tts_generate", Function.C_CONVENTION)
    private val freeAudioFn = lib.getFunction("qwen3_tts_free_audio", Function.C_CONVENTION)
    private val destroyFn = lib.getFunction("qwen3_tts_destroy", Function.C_CONVENTION)

    fun backendInit() {
        backendInitFn.invokeVoid(emptyArray())
    }

    fun init(modelDir: Pointer): Pointer? {
        return initFn.invokePointer(arrayOf(modelDir))
    }

    fun generate(
        engine: Pointer,
        text: Pointer,
        referenceWavPath: Pointer?,
        outSize: IntByReference
    ): Pointer? {
        return generateFn.invokePointer(arrayOf(engine, text, referenceWavPath, outSize))
    }

    fun freeAudio(engine: Pointer) {
        freeAudioFn.invokeVoid(arrayOf(engine))
    }

    fun destroy(engine: Pointer) {
        destroyFn.invokeVoid(arrayOf(engine))
    }
}

/**
 * High-level wrapper for the Qwen3 Engine.
 */
class QwenEngine {
    private var enginePointer: Pointer? = null
    private var loadedModelDir: String? = null
    private var useCliFallback = false

    companion object {
        private var isInitialized = false
        private var native: Qwen3Native? = null
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

        private fun getNative(): Qwen3Native {
            synchronized(loadLock) {
                if (native != null) return native!!

                val root = resolveNativeRoot()

                // Keep JNA extraction local and deterministic.
                val localJnaDir = File(root, ".jna")
                if (!localJnaDir.exists()) localJnaDir.mkdirs()
                System.setProperty("jna.tmpdir", localJnaDir.absolutePath)
                System.setProperty("jna.nosys", "true")
                System.setProperty("jna.library.path", root.absolutePath)

                val qwenDll = File(root, "qwen3_tts.dll")
                require(qwenDll.exists()) { "Missing native library: ${qwenDll.absolutePath}" }
                println("[QwenEngine] NativeLibrary(abs): ${qwenDll.absolutePath}")
                val library = NativeLibrary.getInstance(qwenDll.absolutePath)
                native = Qwen3Native(library)

                if (!isInitialized) {
                    native!!.backendInit()
                    isInitialized = true
                }
            }
            return native!!
        }

        private fun toNativeCString(value: String): Memory {
            val utf8 = value.toByteArray(StandardCharsets.UTF_8)
            return Memory((utf8.size + 1).toLong()).apply {
                write(0, utf8, 0, utf8.size)
                setByte(utf8.size.toLong(), 0)
            }
        }

        private fun toOptionalNativeCString(value: String?): Memory? {
            if (value.isNullOrEmpty()) return null
            return toNativeCString(value)
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

    fun load(modelDir: String): Boolean {
        if (!File(modelDir).exists() || !File(modelDir).isDirectory) return false

        release()
        loadedModelDir = modelDir
        useCliFallback = false

        return try {
            val native = getNative()
            val modelDirNative = toNativeCString(modelDir)
            enginePointer = native.init(modelDirNative)
            if (enginePointer != null) {
                true
            } else {
                val root = resolveNativeRoot()
                useCliFallback = resolveCliExe(root) != null
                if (useCliFallback) {
                    println("[QwenEngine] Native init returned null, using CLI fallback.")
                }
                useCliFallback
            }
        } catch (e: Throwable) {
            e.printStackTrace()
            val root = resolveNativeRoot()
            useCliFallback = resolveCliExe(root) != null
            if (useCliFallback) {
                println("[QwenEngine] Native init failed, using CLI fallback.")
            }
            useCliFallback
        }
    }

    fun generate(text: String, referenceWav: String? = null): FloatArray? {
        if (useCliFallback) {
            return generateViaCli(text, referenceWav)
        }

        val pointer = enginePointer ?: return null
        val outSizeRef = IntByReference()

        val native = getNative()
        val textNative = toNativeCString(text)
        val referenceNative = toOptionalNativeCString(referenceWav)

        val audioPointer = native.generate(
            pointer, textNative, referenceNative, outSizeRef
        ) ?: return null

        val size = outSizeRef.value
        val result = audioPointer.getFloatArray(0, size)
        
        native.freeAudio(pointer)
        return result
    }

    fun release() {
        enginePointer?.let {
            getNative().destroy(it)
            enginePointer = null
        }
    }

    private fun generateViaCli(text: String, referenceWav: String?): FloatArray? {
        val modelDir = loadedModelDir ?: return null
        val root = resolveNativeRoot()
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
