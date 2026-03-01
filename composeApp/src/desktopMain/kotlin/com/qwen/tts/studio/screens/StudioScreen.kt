package com.qwen.tts.studio.screens

import androidx.compose.animation.AnimatedVisibility
import androidx.compose.animation.expandVertically
import androidx.compose.animation.fadeIn
import androidx.compose.animation.fadeOut
import androidx.compose.animation.shrinkVertically
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import com.qwen.tts.studio.viewmodel.StudioViewModel
import com.qwen.tts.studio.viewmodel.VoicesViewModel

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun StudioScreen(
    viewModel: StudioViewModel,
    settingsViewModel: SettingsViewModel,
    voicesViewModel: VoicesViewModel
) {
    val uiState by viewModel.uiState.collectAsState()
    val modelDir by settingsViewModel.modelDir.collectAsState()
    val voices by voicesViewModel.voices.collectAsState()

    LaunchedEffect(uiState.selectedVoice, voices) {
        if (voices.none { it.name == uiState.selectedVoice } && voices.isNotEmpty()) {
            viewModel.onVoiceChange(voices.first().name)
        }
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(24.dp)
            .verticalScroll(rememberScrollState()),
        verticalArrangement = Arrangement.spacedBy(24.dp)
    ) {
        // Error Display
        AnimatedVisibility(
            visible = uiState.error != null,
            enter = expandVertically() + fadeIn(),
            exit = shrinkVertically() + fadeOut()
        ) {
            uiState.error?.let {
                Surface(
                    color = MaterialTheme.colorScheme.errorContainer,
                    shape = MaterialTheme.shapes.medium,
                    modifier = Modifier.fillMaxWidth()
                ) {
                    Row(
                        modifier = Modifier.padding(16.dp),
                        verticalAlignment = Alignment.CenterVertically,
                        horizontalArrangement = Arrangement.spacedBy(12.dp)
                    ) {
                        Icon(Icons.Default.Error, contentDescription = null, tint = MaterialTheme.colorScheme.error)
                        Text(it, style = MaterialTheme.typography.bodyMedium, color = MaterialTheme.colorScheme.onErrorContainer)
                    }
                }
            }
        }

        // Controls Row
        Card(
            modifier = Modifier.fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Row(
                modifier = Modifier.padding(16.dp),
                verticalAlignment = Alignment.CenterVertically,
                horizontalArrangement = Arrangement.spacedBy(16.dp)
            ) {
                // Voice Selection
                var expanded by remember { mutableStateOf(false) }
                Box {
                    OutlinedCard(
                        onClick = { expanded = true },
                        modifier = Modifier.width(240.dp)
                    ) {
                        Row(
                            modifier = Modifier.padding(horizontal = 16.dp, vertical = 12.dp),
                            verticalAlignment = Alignment.CenterVertically,
                            horizontalArrangement = Arrangement.spacedBy(12.dp)
                        ) {
                            Icon(Icons.Default.Person, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                            Text(uiState.selectedVoice, fontWeight = FontWeight.Medium)
                            Spacer(Modifier.weight(1f))
                            Icon(Icons.Default.ArrowDropDown, contentDescription = null)
                        }
                    }
                    DropdownMenu(expanded = expanded, onDismissRequest = { expanded = false }) {
                        voices.forEach { voice ->
                            DropdownMenuItem(
                                text = { Text(voice.name) },
                                onClick = {
                                    viewModel.onVoiceChange(voice.name)
                                    expanded = false
                                }
                            )
                        }
                    }
                }
            }
        }

        // Text Input
        Card(
            modifier = Modifier.fillMaxWidth().weight(1f, fill = false).heightIn(min = 300.dp),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Column(modifier = Modifier.fillMaxSize()) {
                TextField(
                    value = uiState.text,
                    onValueChange = { viewModel.onTextChange(it) },
                    placeholder = { Text("Enter the text you want to be spoken here...") },
                    modifier = Modifier.fillMaxWidth().weight(1f),
                    colors = TextFieldDefaults.colors(
                        focusedContainerColor = Color.Transparent,
                        unfocusedContainerColor = Color.Transparent,
                        disabledContainerColor = Color.Transparent,
                        focusedIndicatorColor = Color.Transparent,
                        unfocusedIndicatorColor = Color.Transparent,
                    ),
                    textStyle = MaterialTheme.typography.bodyLarge.copy(fontSize = 18.sp, lineHeight = 28.sp)
                )
                
                HorizontalDivider(modifier = Modifier.fillMaxWidth(), thickness = 1.dp, color = MaterialTheme.colorScheme.outlineVariant)
                
                Row(
                    modifier = Modifier.fillMaxWidth().padding(16.dp),
                    horizontalArrangement = Arrangement.SpaceBetween,
                    verticalAlignment = Alignment.CenterVertically
                ) {
                    Text(
                        "${uiState.text.length} / 5000 characters",
                        style = MaterialTheme.typography.labelMedium,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )

                    val referenceWav = voicesViewModel.referenceForVoice(uiState.selectedVoice)
                    Button(
                        onClick = { viewModel.generateAudio(modelDir, referenceWav) },
                        enabled = uiState.text.isNotBlank() && !uiState.isGenerating,
                        contentPadding = PaddingValues(horizontal = 24.dp, vertical = 12.dp)
                    ) {
                        if (uiState.isGenerating) {
                            CircularProgressIndicator(modifier = Modifier.size(18.dp), strokeWidth = 2.dp, color = MaterialTheme.colorScheme.onPrimary)
                            Spacer(Modifier.width(12.dp))
                            Text("Processing...")
                        } else {
                            Icon(Icons.Default.PlayArrow, contentDescription = null)
                            Spacer(Modifier.width(8.dp))
                            Text("Read Aloud")
                        }
                    }
                }
            }
        }

        // Playback controls
        Card(
            modifier = Modifier.fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Row(
                modifier = Modifier.fillMaxWidth().padding(horizontal = 24.dp, vertical = 16.dp),
                verticalAlignment = Alignment.CenterVertically,
                horizontalArrangement = Arrangement.SpaceBetween
            ) {
                Text(
                    text = if (uiState.isPlaying) "Playing generated audio..." else "Ready",
                    style = MaterialTheme.typography.bodyMedium
                )
                OutlinedButton(
                    onClick = { viewModel.replayLastAudio() },
                    enabled = !uiState.isPlaying
                ) {
                    Icon(Icons.Default.PlayArrow, contentDescription = null)
                    Spacer(Modifier.width(8.dp))
                    Text("Replay Last Audio")
                }
            }
        }
    }
}
