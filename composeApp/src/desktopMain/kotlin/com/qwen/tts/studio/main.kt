package com.qwen.tts.studio

import androidx.compose.ui.window.Window
import androidx.compose.ui.window.application

fun main() = application {
    Window(
        onCloseRequest = ::exitApplication,
        title = "Qwen-TTS Studio",
    ) {
        App()
    }
}
