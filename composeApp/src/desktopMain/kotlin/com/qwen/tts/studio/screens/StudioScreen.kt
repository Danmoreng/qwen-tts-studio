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
import com.qwen.tts.studio.viewmodel.ModelVariant
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import com.qwen.tts.studio.viewmodel.StudioViewModel
import com.qwen.tts.studio.viewmodel.VoicesViewModel
import io.github.vinceglb.filekit.compose.rememberFileSaverLauncher

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun StudioScreen(
    viewModel: StudioViewModel,
    settingsViewModel: SettingsViewModel,
    voicesViewModel: VoicesViewModel
) {
    val uiState by viewModel.uiState.collectAsState()
    val modelDir by settingsViewModel.modelDir.collectAsState()
    val modelVariant by settingsViewModel.modelVariant.collectAsState()
    val voices by voicesViewModel.voices.collectAsState()
    val isModel17 = modelVariant == ModelVariant.MODEL_1_7B

    val saverLauncher = rememberFileSaverLauncher { file ->
        file?.path?.let { viewModel.saveAudioToFile(java.io.File(it)) }
    }

    LaunchedEffect(uiState.selectedVoice, voices) {
        if (voices.none { it.name == uiState.selectedVoice } && voices.isNotEmpty()) {
            viewModel.onVoiceChange(voices.first().name)
        }
    }

    LaunchedEffect(modelDir, modelVariant) {
        viewModel.refreshAvailableSpeakers(modelDir, modelVariant.modelFile)
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
                // Model Variant Selection
                var modelExpanded by remember { mutableStateOf(false) }
                Box {
                    OutlinedCard(
                        onClick = { modelExpanded = true },
                        modifier = Modifier.width(190.dp)
                    ) {
                        Row(
                            modifier = Modifier.padding(horizontal = 16.dp, vertical = 12.dp),
                            verticalAlignment = Alignment.CenterVertically,
                            horizontalArrangement = Arrangement.spacedBy(12.dp)
                        ) {
                            Icon(Icons.Default.Memory, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                            Text(modelVariant.label, fontWeight = FontWeight.Medium)
                            Spacer(Modifier.weight(1f))
                            Icon(Icons.Default.ArrowDropDown, contentDescription = null)
                        }
                    }
                    DropdownMenu(expanded = modelExpanded, onDismissRequest = { modelExpanded = false }) {
                        ModelVariant.entries.forEach { variant ->
                            DropdownMenuItem(
                                text = { Text("${variant.label} (${variant.modelFile})") },
                                onClick = {
                                    settingsViewModel.setModelVariant(variant)
                                    modelExpanded = false
                                }
                            )
                        }
                    }
                }

                if (!isModel17) {
                    // Voice Selection (0.6B only)
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

                // Language Selection
                var langExpanded by remember { mutableStateOf(false) }
                val languages = listOf("English", "German", "French", "Spanish", "Chinese", "Japanese", "Korean", "Russian", "Italian", "Portuguese")
                Box {
                    OutlinedCard(
                        onClick = { langExpanded = true },
                        modifier = Modifier.width(180.dp)
                    ) {
                        Row(
                            modifier = Modifier.padding(horizontal = 16.dp, vertical = 12.dp),
                            verticalAlignment = Alignment.CenterVertically,
                            horizontalArrangement = Arrangement.spacedBy(12.dp)
                        ) {
                            Icon(Icons.Default.Language, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                            Text(uiState.selectedLanguage, fontWeight = FontWeight.Medium)
                            Spacer(Modifier.weight(1f))
                            Icon(Icons.Default.ArrowDropDown, contentDescription = null)
                        }
                    }
                    DropdownMenu(expanded = langExpanded, onDismissRequest = { langExpanded = false }) {
                        languages.forEach { lang ->
                            DropdownMenuItem(
                                text = { Text(lang) },
                                onClick = {
                                    viewModel.onLanguageChange(lang)
                                    langExpanded = false
                                }
                            )
                        }
                    }
                }
            }
        }

        if (isModel17) {
            Card(
                modifier = Modifier.fillMaxWidth(),
                colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
                border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
            ) {
                Column(
                    modifier = Modifier.padding(12.dp),
                    verticalArrangement = Arrangement.spacedBy(10.dp)
                ) {
                    if (uiState.availableSpeakers.isNotEmpty()) {
                        var speakersExpanded by remember { mutableStateOf(false) }
                        val speakerLabel = if (uiState.selectedSpeaker.isBlank()) {
                            "Auto (model default)"
                        } else {
                            uiState.selectedSpeaker
                        }
                        Row(
                            verticalAlignment = Alignment.CenterVertically,
                            horizontalArrangement = Arrangement.spacedBy(12.dp)
                        ) {
                            Icon(Icons.Default.RecordVoiceOver, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                            Box {
                                OutlinedCard(
                                    onClick = { speakersExpanded = true },
                                    modifier = Modifier.width(320.dp)
                                ) {
                                    Row(
                                        modifier = Modifier.padding(horizontal = 12.dp, vertical = 10.dp),
                                        verticalAlignment = Alignment.CenterVertically
                                    ) {
                                        Text(speakerLabel, fontWeight = FontWeight.Medium)
                                        Spacer(Modifier.weight(1f))
                                        Icon(Icons.Default.ArrowDropDown, contentDescription = null)
                                    }
                                }
                                DropdownMenu(expanded = speakersExpanded, onDismissRequest = { speakersExpanded = false }) {
                                    DropdownMenuItem(
                                        text = { Text("Auto (model default)") },
                                        onClick = {
                                            viewModel.onSpeakerChange("")
                                            speakersExpanded = false
                                        }
                                    )
                                    uiState.availableSpeakers.forEach { speaker ->
                                        DropdownMenuItem(
                                            text = { Text(speaker) },
                                            onClick = {
                                                viewModel.onSpeakerChange(speaker)
                                                speakersExpanded = false
                                            }
                                        )
                                    }
                                }
                            }
                        }
                    }

                    Row(
                        modifier = Modifier.padding(start = 4.dp),
                        verticalAlignment = Alignment.CenterVertically,
                        horizontalArrangement = Arrangement.spacedBy(12.dp)
                    ) {
                        Icon(
                            Icons.Default.Tune,
                            contentDescription = null,
                            tint = MaterialTheme.colorScheme.primary
                        )
                        TextField(
                            value = uiState.selectedInstruction,
                            onValueChange = { viewModel.onInstructionChange(it) },
                            placeholder = { Text("Style instruction, e.g. Whispering, calm, close-mic.") },
                            modifier = Modifier.weight(1f),
                            colors = TextFieldDefaults.colors(
                                focusedContainerColor = Color.Transparent,
                                unfocusedContainerColor = Color.Transparent,
                                disabledContainerColor = Color.Transparent,
                                focusedIndicatorColor = Color.Transparent,
                                unfocusedIndicatorColor = Color.Transparent,
                                focusedTextColor = MaterialTheme.colorScheme.onSurface,
                                unfocusedTextColor = MaterialTheme.colorScheme.onSurface,
                            ),
                            singleLine = true
                        )
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
                        focusedTextColor = MaterialTheme.colorScheme.onSurface,
                        unfocusedTextColor = MaterialTheme.colorScheme.onSurface,
                        focusedPlaceholderColor = MaterialTheme.colorScheme.onSurfaceVariant,
                        unfocusedPlaceholderColor = MaterialTheme.colorScheme.onSurfaceVariant,
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

                    val speakerEmbeddingPath = if (isModel17) null else voicesViewModel.speakerEmbeddingForVoice(uiState.selectedVoice)
                    val referenceWav = if (isModel17) null else voicesViewModel.referenceForVoice(uiState.selectedVoice)
                    Button(
                        onClick = { viewModel.generateAudio(modelDir, modelVariant.modelFile, speakerEmbeddingPath, referenceWav) },
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
                    text = when {
                        uiState.isSaving -> "Saving to file..."
                        uiState.isPlaying -> "Playing generated audio..."
                        uiState.hasAudio -> "Audio ready"
                        else -> "Ready"
                    },
                    style = MaterialTheme.typography.bodyMedium
                )
                Row(horizontalArrangement = Arrangement.spacedBy(12.dp)) {
                    if (uiState.hasAudio) {
                        OutlinedButton(
                            onClick = {
                                saverLauncher.launch(
                                    baseName = "output",
                                    extension = "wav"
                                )
                            },
                            enabled = !uiState.isSaving
                        ) {
                            Icon(Icons.Default.Save, contentDescription = null)
                            Spacer(Modifier.width(8.dp))
                            Text("Save to File")
                        }
                    }
                    
                    OutlinedButton(
                        onClick = { viewModel.replayLastAudio() },
                        enabled = !uiState.isPlaying && uiState.hasAudio
                    ) {
                        Icon(Icons.Default.PlayArrow, contentDescription = null)
                        Spacer(Modifier.width(8.dp))
                        Text("Replay Last Audio")
                    }
                }
            }
        }
    }
}
