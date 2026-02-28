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
import org.jetbrains.compose.ui.tooling.preview.Preview

enum class Screen(val label: String, val icon: ImageVector) {
    Studio("Studio", Icons.Default.VolumeUp),
    Voices("Voices", Icons.Default.Mic),
    Setup("Setup", Icons.Default.Settings)
}

@Composable
@Preview
fun App() {
    var currentScreen by remember { mutableStateOf(Screen.Studio) }
    var isDarkMode by remember { mutableStateOf(true) }
    
    // Shared ViewModels
    val settingsViewModel: SettingsViewModel = viewModel { SettingsViewModel() }
    val studioViewModel: StudioViewModel = viewModel { StudioViewModel() }

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
                    IconButton(onClick = { isDarkMode = !isDarkMode }) {
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
                    Header(currentScreen, isDarkMode)

                    // Screen Content
                    Box(modifier = Modifier.fillMaxSize()) {
                        when (currentScreen) {
                            Screen.Studio -> StudioScreen(studioViewModel, settingsViewModel)
                            Screen.Voices -> VoicesScreen()
                            Screen.Setup -> SetupScreen(settingsViewModel)
                        }
                    }
                }
            }
        }
    }
}

@Composable
fun Header(screen: Screen, isDarkMode: Boolean) {
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

            Row(verticalAlignment = Alignment.CenterVertically) {
                // Hardware Monitor Mockup
                Surface(
                    color = MaterialTheme.colorScheme.background,
                    shape = MaterialTheme.shapes.small,
                    border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
                ) {
                    Row(
                        modifier = Modifier.padding(horizontal = 12.dp, vertical = 6.dp),
                        verticalAlignment = Alignment.CenterVertically,
                        horizontalArrangement = Arrangement.spacedBy(8.dp)
                    ) {
                        Icon(Icons.Default.Analytics, contentDescription = null, modifier = Modifier.size(14.dp), tint = MaterialTheme.colorScheme.primary)
                        Text("RAM: 2.4 GB", style = MaterialTheme.typography.labelSmall, fontFamily = androidx.compose.ui.text.font.FontFamily.Monospace)
                        VerticalDivider(modifier = Modifier.height(12.dp).width(1.dp))
                        Text("CPU: 2%", style = MaterialTheme.typography.labelSmall, fontFamily = androidx.compose.ui.text.font.FontFamily.Monospace)
                    }
                }

                Spacer(Modifier.width(16.dp))

                // Status Indicator
                val statusBgColor = if (isDarkMode) Color(0xFF1B3921) else Color(0xFFE8F5E9)
                val statusTextColor = if (isDarkMode) Color(0xFF81C784) else Color(0xFF2E7D32)
                val statusDotColor = Color(0xFF4CAF50)

                Surface(
                    color = statusBgColor,
                    shape = androidx.compose.foundation.shape.CircleShape,
                    border = androidx.compose.foundation.BorderStroke(1.dp, statusTextColor.copy(alpha = 0.2f))
                ) {
                    Row(
                        modifier = Modifier.padding(horizontal = 12.dp, vertical = 6.dp),
                        verticalAlignment = Alignment.CenterVertically,
                        horizontalArrangement = Arrangement.spacedBy(6.dp)
                    ) {
                        Box(modifier = Modifier.size(8.dp).background(statusDotColor, shape = androidx.compose.foundation.shape.CircleShape))
                        Text("Engine Ready", color = statusTextColor, style = MaterialTheme.typography.labelSmall, fontWeight = FontWeight.Medium)
                    }
                }
            }
        }
    }
}
