package com.qwen.tts.studio.theme

import androidx.compose.foundation.isSystemInDarkTheme
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.darkColorScheme
import androidx.compose.material3.lightColorScheme
import androidx.compose.runtime.Composable
import androidx.compose.ui.graphics.Color

private val DarkColorScheme = darkColorScheme(
    primary = Color(0xFF3B82F6),
    secondary = Color(0xFF161B22),
    background = Color(0xFF0E1117),
    surface = Color(0xFF161B22),
    onPrimary = Color.White,
    onBackground = Color(0xFFE6EDF3),
    onSurface = Color(0xFFE6EDF3)
)

private val LightColorScheme = lightColorScheme(
    primary = Color(0xFF2563EB),
    secondary = Color(0xFFF3F4F6),
    background = Color(0xFFFAFAFA),
    surface = Color.White,
    onPrimary = Color.White,
    onBackground = Color(0xFF1F2937),
    onSurface = Color(0xFF1F2937)
)

@Composable
fun AppTheme(
    darkTheme: Boolean = isSystemInDarkTheme(),
    content: @Composable () -> Unit
) {
    val colorScheme = if (darkTheme) DarkColorScheme else LightColorScheme

    MaterialTheme(
        colorScheme = colorScheme,
        content = content
    )
}
