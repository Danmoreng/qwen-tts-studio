package com.qwen.tts.studio.util

import java.awt.FileDialog
import java.awt.Frame
import java.io.File
import javax.swing.JFileChooser

object FilePicker {
    fun pickFile(
        title: String,
        allowedExtensions: List<String> = listOf(".gguf", ".bin"),
        onFilePicked: (String) -> Unit
    ) {
        val dialog = FileDialog(null as Frame?, title, FileDialog.LOAD)
        dialog.file = allowedExtensions.joinToString(";") { "*$it" }
        dialog.isVisible = true
        
        if (dialog.directory != null && dialog.file != null) {
            val file = File(dialog.directory, dialog.file)
            onFilePicked(file.absolutePath)
        }
    }

    fun pickDirectory(
        title: String,
        onDirectoryPicked: (String) -> Unit
    ) {
        val chooser = JFileChooser()
        chooser.fileSelectionMode = JFileChooser.DIRECTORIES_ONLY
        chooser.dialogTitle = title
        
        val result = chooser.showOpenDialog(null)
        if (result == JFileChooser.APPROVE_OPTION) {
            onDirectoryPicked(chooser.selectedFile.absolutePath)
        }
    }
}
