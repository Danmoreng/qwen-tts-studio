package com.qwen.tts.studio.engine

import com.sun.jna.Library
import com.sun.jna.Native
import com.sun.jna.Pointer
import com.sun.jna.ptr.IntByReference
import java.io.File

/**
 * JNA Interface for the qwen3-tts.cpp engine.
 */
interface Qwen3Library : Library {
    fun qwen3_tts_backend_init()
    fun qwen3_tts_init(modelDir: String): Pointer?
    fun qwen3_tts_generate(
        engine: Pointer,
        text: String,
        referenceWavPath: String?,
        outSize: IntByReference
    ): Pointer?
    fun qwen3_tts_free_audio(engine: Pointer)
    fun qwen3_tts_destroy(engine: Pointer)
}

/**
 * High-level wrapper for the Qwen3 Engine.
 */
class QwenEngine {
    private var enginePointer: Pointer? = null

    companion object {
        private var isInitialized = false
        private var library: Qwen3Library? = null

        fun getLibrary(): Qwen3Library {
            if (library == null) {
                val root = System.getProperty("user.dir")
                
                // Create a local JNA temp dir to bypass Windows policy blocks on system %TEMP%
                val localJnaDir = File(root, ".jna")
                if (!localJnaDir.exists()) localJnaDir.mkdirs()
                
                System.setProperty("jna.tmpdir", localJnaDir.absolutePath)
                System.setProperty("jna.library.path", root)
                System.setProperty("jna.nosys", "true")
                
                // Manually load dependencies in order using System.load to bypass JNA extraction blocks
                val dlls = listOf(
                    "cudart64_12.dll", 
                    "ggml-base.dll", 
                    "ggml-cpu.dll", 
                    "ggml-cuda.dll", 
                    "ggml.dll", 
                    "qwen3_tts.dll"
                )
                
                dlls.forEach { name ->
                    val file = File(root, name)
                    if (file.exists()) {
                        try {
                            println("[QwenEngine] System.load: ${file.absolutePath}")
                            System.load(file.absolutePath)
                        } catch (e: UnsatisfiedLinkError) {
                            System.err.println("[QwenEngine] Failed to load $name: ${e.message}")
                        }
                    }
                }

                library = Native.load("qwen3_tts", Qwen3Library::class.java).also {
                    if (!isInitialized) {
                        try {
                            it.qwen3_tts_backend_init()
                            isInitialized = true
                        } catch (e: Throwable) {
                            e.printStackTrace()
                        }
                    }
                }
            }
            return library!!
        }
    }

    fun load(modelDir: String): Boolean {
        if (!File(modelDir).exists() || !File(modelDir).isDirectory) return false
        
        return try {
            release()
            enginePointer = getLibrary().qwen3_tts_init(modelDir)
            enginePointer != null
        } catch (e: Exception) {
            e.printStackTrace()
            false
        }
    }

    fun generate(text: String, referenceWav: String? = null): FloatArray? {
        val pointer = enginePointer ?: return null
        val outSizeRef = IntByReference()
        
        val audioPointer = getLibrary().qwen3_tts_generate(
            pointer, text, referenceWav, outSizeRef
        ) ?: return null

        val size = outSizeRef.value
        val result = audioPointer.getFloatArray(0, size)
        
        getLibrary().qwen3_tts_free_audio(pointer)
        return result
    }

    fun release() {
        enginePointer?.let {
            getLibrary().qwen3_tts_destroy(it)
            enginePointer = null
        }
    }
}
