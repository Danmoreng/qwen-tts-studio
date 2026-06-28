package com.qwen.tts.studio.screens

import androidx.compose.animation.AnimatedVisibility
import androidx.compose.animation.expandVertically
import androidx.compose.animation.fadeIn
import androidx.compose.animation.fadeOut
import androidx.compose.animation.shrinkVertically
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.heightIn
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.layout.widthIn
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowDropDown
import androidx.compose.material.icons.filled.Error
import androidx.compose.material.icons.filled.Language
import androidx.compose.material.icons.filled.Memory
import androidx.compose.material.icons.filled.Pause
import androidx.compose.material.icons.filled.Person
import androidx.compose.material.icons.filled.PlayArrow
import androidx.compose.material.icons.filled.RecordVoiceOver
import androidx.compose.material.icons.filled.Save
import androidx.compose.material.icons.filled.Tune
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.Checkbox
import androidx.compose.material3.CircularProgressIndicator
import androidx.compose.material3.DropdownMenu
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material3.HorizontalDivider
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedButton
import androidx.compose.material3.OutlinedCard
import androidx.compose.material3.Slider
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.material3.TextField
import androidx.compose.material3.TextFieldDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.AnnotatedString
import androidx.compose.ui.text.SpanStyle
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.input.OffsetMapping
import androidx.compose.ui.text.input.TransformedText
import androidx.compose.ui.text.input.VisualTransformation
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.qwen.tts.studio.engine.QwenEngine
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import com.qwen.tts.studio.viewmodel.StudioViewModel
import com.qwen.tts.studio.viewmodel.VoicesViewModel
import io.github.vinceglb.filekit.compose.rememberFileSaverLauncher

/**
 * The main screen for audio synthesis.
 * Provides controls for selecting models, languages, speakers, and entering text to be synthesized.
 *
 * @param viewModel The StudioViewModel managing the synthesis state and operations.
 * @param settingsViewModel The SettingsViewModel for model configuration.
 * @param voicesViewModel The VoicesViewModel for custom voice presets.
 */
@Composable
fun StudioScreen(
    viewModel: StudioViewModel,
    settingsViewModel: SettingsViewModel,
    voicesViewModel: VoicesViewModel
) {
    val uiState by viewModel.uiState.collectAsState()
    val modelDir by settingsViewModel.modelDir.collectAsState()
    val modelName by settingsViewModel.modelName.collectAsState()
    val backendPreference by settingsViewModel.backendPreference.collectAsState()
    val availableModelNames by settingsViewModel.availableModelNames.collectAsState()
    val voices by voicesViewModel.voices.collectAsState()
    val isCreatingVoice by voicesViewModel.isCreating.collectAsState()

    val saverLauncher = rememberFileSaverLauncher { file ->
        file?.path?.let { viewModel.saveAudioToFile(java.io.File(it)) }
    }

    LaunchedEffect(uiState.selectedVoice, voices, uiState.supportsCloning) {
        if (!uiState.supportsCloning) return@LaunchedEffect
        if (voices.none { it.name == uiState.selectedVoice } && voices.isNotEmpty()) {
            viewModel.onVoiceChange(voices.first().name)
        }
    }

    LaunchedEffect(modelDir, modelName, backendPreference) {
        viewModel.refreshModelCapabilities(modelDir, modelName, backendPreference)
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(24.dp)
            .verticalScroll(rememberScrollState()),
        verticalArrangement = Arrangement.spacedBy(24.dp)
    ) {
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
                var modelExpanded by remember { mutableStateOf(false) }
                Box(modifier = Modifier.widthIn(max = 430.dp)) {
                    OutlinedCard(
                        onClick = { modelExpanded = true },
                        modifier = Modifier.fillMaxWidth()
                    ) {
                        Row(
                            modifier = Modifier.padding(horizontal = 16.dp, vertical = 12.dp),
                            verticalAlignment = Alignment.CenterVertically,
                            horizontalArrangement = Arrangement.spacedBy(12.dp)
                        ) {
                            Icon(Icons.Default.Memory, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                            Text(
                                text = modelName.ifBlank { "Select model file" },
                                fontWeight = FontWeight.Medium,
                                maxLines = 1,
                                overflow = TextOverflow.Ellipsis,
                                modifier = Modifier.weight(1f)
                            )
                            Icon(Icons.Default.ArrowDropDown, contentDescription = null)
                        }
                    }
                    DropdownMenu(expanded = modelExpanded, onDismissRequest = { modelExpanded = false }) {
                        availableModelNames.forEach { fileName ->
                            DropdownMenuItem(
                                text = { Text(fileName) },
                                onClick = {
                                    settingsViewModel.setModelName(fileName)
                                    modelExpanded = false
                                }
                            )
                        }
                    }
                }

                var langExpanded by remember { mutableStateOf(false) }
                val languages = listOf("English", "German", "French", "Spanish", "Chinese", "Japanese", "Korean", "Russian", "Italian", "Portuguese")
                Box {
                    OutlinedCard(
                        onClick = { langExpanded = true },
                        modifier = Modifier.width(200.dp)
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

        if (uiState.supportsCloning || uiState.supportsNamedSpeakers) {
            Card(
                modifier = Modifier.fillMaxWidth(),
                colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
                border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
            ) {
                Row(
                    modifier = Modifier.padding(12.dp),
                    verticalAlignment = Alignment.CenterVertically,
                    horizontalArrangement = Arrangement.spacedBy(12.dp)
                ) {
                    if (uiState.supportsNamedSpeakers) {
                        val speakerLabel = uiState.selectedSpeaker.ifBlank { uiState.availableSpeakers.firstOrNull().orEmpty() }
                        var speakersExpanded by remember { mutableStateOf(false) }
                        Icon(Icons.Default.RecordVoiceOver, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                        Box {
                            OutlinedCard(
                                onClick = { speakersExpanded = true },
                                modifier = Modifier.width(360.dp)
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
                    } else if (uiState.supportsCloning) {
                        var expanded by remember { mutableStateOf(false) }
                        Icon(Icons.Default.Person, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                        Box {
                            OutlinedCard(
                                onClick = { expanded = true },
                                modifier = Modifier.width(360.dp)
                            ) {
                                Row(
                                    modifier = Modifier.padding(horizontal = 12.dp, vertical = 10.dp),
                                    verticalAlignment = Alignment.CenterVertically
                                ) {
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
            }
        }

        if (uiState.supportsInstruction) {
            val instructionPlaceholder = when (uiState.modelKind) {
                QwenEngine.MODEL_KIND_VOICE_DESIGN ->
                    "Voice design prompt, e.g. Warm baritone narrator with calm studio delivery."
                QwenEngine.MODEL_KIND_CUSTOM_VOICE ->
                    "Style instruction, e.g. Whispering, calm, close-mic."
                else ->
                    "Instruction, e.g. Calm and natural delivery."
            }
            Card(
                modifier = Modifier.fillMaxWidth(),
                colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
                border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
            ) {
                Row(
                    modifier = Modifier.padding(12.dp),
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
                        placeholder = { Text(instructionPlaceholder) },
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
                    visualTransformation = highlightedTextTransformation(
                        start = uiState.highlightedTextStart,
                        end = uiState.highlightedTextEnd,
                        color = MaterialTheme.colorScheme.primaryContainer
                    ),
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

                    Row(
                        verticalAlignment = Alignment.CenterVertically,
                        horizontalArrangement = Arrangement.spacedBy(4.dp)
                    ) {
                        Checkbox(
                            checked = uiState.useStreaming,
                            onCheckedChange = { viewModel.onStreamingChange(it) },
                            enabled = !uiState.isGenerating
                        )
                        Text(
                            "Streaming",
                            style = MaterialTheme.typography.labelMedium,
                            color = MaterialTheme.colorScheme.onSurfaceVariant
                        )
                    }

                    val useNamedSpeaker = uiState.supportsNamedSpeakers && uiState.selectedSpeaker.isNotBlank()
                    val speakerEmbeddingPath = if (uiState.supportsCloning && !useNamedSpeaker) {
                        voicesViewModel.speakerEmbeddingForVoice(uiState.selectedVoice, uiState.speakerEmbeddingDim)
                    } else {
                        null
                    }
                    val selectedVoicePreset = voices.firstOrNull { it.name == uiState.selectedVoice }
                    val missingSpeakerEmbedding = uiState.supportsCloning &&
                        !useNamedSpeaker &&
                        selectedVoicePreset?.isSystem == false &&
                        uiState.speakerEmbeddingDim > 0 &&
                        speakerEmbeddingPath == null

                    if (missingSpeakerEmbedding) {
                        Row(
                            modifier = Modifier.fillMaxWidth(),
                            horizontalArrangement = Arrangement.spacedBy(12.dp, Alignment.End),
                            verticalAlignment = Alignment.CenterVertically
                        ) {
                            Text(
                                "D${uiState.speakerEmbeddingDim} embedding is missing for ${uiState.selectedVoice}.",
                                modifier = Modifier.weight(1f),
                                style = MaterialTheme.typography.bodySmall,
                                color = MaterialTheme.colorScheme.onSurfaceVariant
                            )
                            OutlinedButton(
                                onClick = {
                                    voicesViewModel.createMissingSpeakerEmbedding(
                                        uiState.selectedVoice,
                                        uiState.speakerEmbeddingDim,
                                        modelDir,
                                        backendPreference
                                    )
                                },
                                enabled = !isCreatingVoice
                            ) {
                                if (isCreatingVoice) {
                                    CircularProgressIndicator(modifier = Modifier.size(16.dp), strokeWidth = 2.dp)
                                    Spacer(Modifier.width(8.dp))
                                    Text("Generating...")
                                } else {
                                    Text("Generate D${uiState.speakerEmbeddingDim}")
                                }
                            }
                        }
                    }

                    Button(
                        onClick = { viewModel.generateAudio(modelDir, modelName, speakerEmbeddingPath, backendPreference) },
                        enabled = uiState.text.isNotBlank() && !uiState.isGenerating && !missingSpeakerEmbedding,
                        contentPadding = PaddingValues(horizontal = 24.dp, vertical = 12.dp)
                    ) {
                        if (uiState.isGenerating) {
                            CircularProgressIndicator(modifier = Modifier.size(18.dp), strokeWidth = 2.dp, color = MaterialTheme.colorScheme.onPrimary)
                            Spacer(Modifier.width(12.dp))
                            Text(if (uiState.useStreaming) "Streaming..." else "Processing...")
                        } else {
                            Icon(Icons.Default.PlayArrow, contentDescription = null)
                            Spacer(Modifier.width(8.dp))
                            Text(if (uiState.useStreaming) "Stream Aloud" else "Read Aloud")
                        }
                    }
                }
            }
        }

        Card(
            modifier = Modifier.fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Column(
                modifier = Modifier.fillMaxWidth().padding(horizontal = 24.dp, vertical = 16.dp),
                verticalArrangement = Arrangement.spacedBy(12.dp)
            ) {
                val duration = uiState.playbackDurationSeconds
                val position = uiState.playbackPositionSeconds.coerceIn(0f, duration.coerceAtLeast(0f))
                Row(
                    modifier = Modifier.fillMaxWidth(),
                    verticalAlignment = Alignment.CenterVertically,
                    horizontalArrangement = Arrangement.spacedBy(16.dp)
                ) {
                    OutlinedButton(
                        onClick = { viewModel.togglePlayback() },
                        enabled = uiState.hasAudio
                    ) {
                        Icon(
                            if (uiState.isPlaying) Icons.Default.Pause else Icons.Default.PlayArrow,
                            contentDescription = null
                        )
                        Spacer(Modifier.width(8.dp))
                        Text(if (uiState.isPlaying) "Pause" else "Play")
                    }

                    Text(
                        formatPlaybackTime(position),
                        style = MaterialTheme.typography.labelMedium,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )

                    Slider(
                        value = position,
                        onValueChange = { viewModel.seekPlayback(it) },
                        valueRange = 0f..duration.coerceAtLeast(0.01f),
                        enabled = uiState.hasAudio,
                        modifier = Modifier.weight(1f)
                    )

                    Text(
                        formatPlaybackTime(duration),
                        style = MaterialTheme.typography.labelMedium,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )

                    OutlinedButton(
                        onClick = {
                            saverLauncher.launch(
                                baseName = "output",
                                extension = "wav"
                            )
                        },
                        enabled = uiState.hasAudio && !uiState.isSaving
                    ) {
                        Icon(Icons.Default.Save, contentDescription = null)
                        Spacer(Modifier.width(8.dp))
                        Text(if (uiState.isSaving) "Saving..." else "Save")
                    }
                }

                Text(
                    text = when {
                        uiState.isSaving -> "Saving to file..."
                        uiState.isGenerating && uiState.useStreaming -> "Streaming generated audio..."
                        uiState.isPlaying -> "Playing generated audio..."
                        uiState.hasAudio -> "Audio ready"
                        else -> "Ready"
                    },
                    style = MaterialTheme.typography.bodySmall,
                    color = MaterialTheme.colorScheme.onSurfaceVariant
                )
            }
        }
    }
}

private fun formatPlaybackTime(seconds: Float): String {
    val totalSeconds = seconds.toInt().coerceAtLeast(0)
    val minutes = totalSeconds / 60
    val secs = totalSeconds % 60
    return "%d:%02d".format(minutes, secs)
}

private fun highlightedTextTransformation(start: Int, end: Int, color: Color): VisualTransformation {
    if (start < 0 || end <= start) return VisualTransformation.None

    return VisualTransformation { text ->
        val safeStart = start.coerceIn(0, text.length)
        val safeEnd = end.coerceIn(safeStart, text.length)
        if (safeEnd <= safeStart) {
            TransformedText(text, OffsetMapping.Identity)
        } else {
            val builder = AnnotatedString.Builder()
            builder.append(text)
            builder.addStyle(
                SpanStyle(background = color),
                start = safeStart,
                end = safeEnd
            )
            TransformedText(builder.toAnnotatedString(), OffsetMapping.Identity)
        }
    }
}
