package com.qwen.tts.studio

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.viewmodel.compose.viewModel
import com.qwen.tts.studio.screens.SetupScreen
import com.qwen.tts.studio.screens.StudioScreen
import com.qwen.tts.studio.screens.VoicesScreen
import com.qwen.tts.studio.theme.AppTheme
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import com.qwen.tts.studio.viewmodel.StudioViewModel
import com.qwen.tts.studio.viewmodel.VoicesViewModel
import org.jetbrains.compose.ui.tooling.preview.Preview

enum class Screen(val label: String, val icon: ImageVector) {
    Studio("Studio", Icons.Default.VolumeUp),
    Voices("Voices", Icons.Default.Mic),
    Setup("Setup", Icons.Default.Settings)
}

@Composable
@Preview
fun App(
    isDarkMode: Boolean = true,
    onThemeToggle: () -> Unit = {}
) {
    var currentScreen by remember { mutableStateOf(Screen.Studio) }
    
    // Shared ViewModels
    val settingsViewModel: SettingsViewModel = viewModel { SettingsViewModel() }
    val studioViewModel: StudioViewModel = viewModel { StudioViewModel() }
    val voicesViewModel: VoicesViewModel = viewModel { VoicesViewModel() }

    AppTheme(darkTheme = isDarkMode) {
        Surface(
            modifier = Modifier.fillMaxSize(),
            color = MaterialTheme.colorScheme.background
        ) {
            Row(modifier = Modifier.fillMaxSize()) {
                // Navigation Rail
                NavigationRail(
                    modifier = Modifier.width(80.dp),
                    containerColor = MaterialTheme.colorScheme.surface,
                    header = {
                        Box(
                            modifier = Modifier
                                .padding(vertical = 16.dp)
                                .size(48.dp)
                                .background(MaterialTheme.colorScheme.primary, shape = MaterialTheme.shapes.medium),
                            contentAlignment = Alignment.Center
                        ) {
                            Text(
                                "Q3",
                                color = Color.White,
                                fontWeight = FontWeight.Bold,
                                fontSize = 18.sp
                            )
                        }
                    }
                ) {
                    Spacer(Modifier.height(8.dp))
                    Screen.entries.forEach { screen ->
                        NavigationRailItem(
                            selected = currentScreen == screen,
                            onClick = { currentScreen = screen },
                            icon = { Icon(screen.icon, contentDescription = screen.label) },
                            label = { Text(screen.label, fontSize = 10.sp) },
                            alwaysShowLabel = true
                        )
                    }
                    
                    Spacer(Modifier.weight(1f))
                    
                    // Theme Toggle
                    IconButton(onClick = onThemeToggle) {
                        Icon(
                            if (isDarkMode) Icons.Default.LightMode else Icons.Default.DarkMode,
                            contentDescription = "Toggle Theme"
                        )
                    }
                    Spacer(Modifier.height(16.dp))
                }

                // Main Content
                Column(modifier = Modifier.fillMaxSize()) {
                    // Header
                    Header(currentScreen)

                    // Screen Content
                    Box(modifier = Modifier.fillMaxSize()) {
                        when (currentScreen) {
                            Screen.Studio -> StudioScreen(studioViewModel, settingsViewModel, voicesViewModel)
                            Screen.Voices -> VoicesScreen(voicesViewModel, settingsViewModel)
                            Screen.Setup -> SetupScreen(settingsViewModel)
                        }
                    }
                }
            }
        }
    }
}

@Composable
fun Header(screen: Screen) {
    Surface(
        modifier = Modifier.fillMaxWidth().height(64.dp),
        color = MaterialTheme.colorScheme.surface,
        tonalElevation = 1.dp
    ) {
        Row(
            modifier = Modifier.fillMaxSize().padding(horizontal = 24.dp),
            verticalAlignment = Alignment.CenterVertically,
            horizontalArrangement = Arrangement.SpaceBetween
        ) {
            Text(
                text = when (screen) {
                    Screen.Studio -> "Speech Synthesis"
                    Screen.Voices -> "Voice Cloning"
                    Screen.Setup -> "Model Settings"
                },
                style = MaterialTheme.typography.titleLarge,
                fontWeight = FontWeight.SemiBold
            )
        }
    }
}
