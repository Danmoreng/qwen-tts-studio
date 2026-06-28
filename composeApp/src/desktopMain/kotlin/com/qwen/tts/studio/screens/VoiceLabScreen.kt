package com.qwen.tts.studio.screens

import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Add
import androidx.compose.material.icons.filled.ArrowDropDown
import androidx.compose.material.icons.filled.Error
import androidx.compose.material.icons.filled.Tune
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.Checkbox
import androidx.compose.material3.DropdownMenu
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedButton
import androidx.compose.material3.OutlinedCard
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Slider
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.unit.dp
import com.qwen.tts.studio.viewmodel.EmbeddingBlendSource
import com.qwen.tts.studio.viewmodel.VoicePreset
import com.qwen.tts.studio.viewmodel.VoicesViewModel

private enum class VoiceLabMode {
    Mix,
    Merge
}

@Composable
fun VoiceLabScreen(viewModel: VoicesViewModel) {
    val voices by viewModel.voices.collectAsState()
    val isCreating by viewModel.isCreating.collectAsState()
    val error by viewModel.error.collectAsState()
    val customVoices = voices.filter { !it.isSystem && it.speakerEmbeddings.isNotEmpty() }

    var mode by remember { mutableStateOf(VoiceLabMode.Mix) }
    var presetName by remember { mutableStateOf("") }
    var mixLeftId by remember { mutableStateOf("") }
    var mixRightId by remember { mutableStateOf("") }
    var mixAmount by remember { mutableStateOf(0.5f) }
    var mergeSelection by remember { mutableStateOf(setOf<String>()) }
    var normalize by remember { mutableStateOf(true) }

    LaunchedEffect(customVoices) {
        val ids = customVoices.map { it.id }
        if (mixLeftId !in ids) mixLeftId = ids.firstOrNull().orEmpty()
        if (mixRightId !in ids || mixRightId == mixLeftId) {
            mixRightId = ids.firstOrNull { it != mixLeftId }.orEmpty()
        }
        mergeSelection = mergeSelection.filterTo(mutableSetOf()) { it in ids }
    }

    val selectedIds = when (mode) {
        VoiceLabMode.Mix -> listOf(mixLeftId, mixRightId).filter { it.isNotBlank() }
        VoiceLabMode.Merge -> mergeSelection.toList()
    }
    val outputDims = commonEmbeddingDims(customVoices, selectedIds)
    val canCreate = outputDims.isNotEmpty() && when (mode) {
        VoiceLabMode.Mix -> mixLeftId.isNotBlank() && mixRightId.isNotBlank() && mixLeftId != mixRightId
        VoiceLabMode.Merge -> mergeSelection.size >= 2
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(24.dp)
            .verticalScroll(rememberScrollState()),
        verticalArrangement = Arrangement.spacedBy(16.dp)
    ) {
        if (error != null) {
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
                    Text(error!!, style = MaterialTheme.typography.bodyMedium, color = MaterialTheme.colorScheme.onErrorContainer)
                }
            }
        }

        Card(
            modifier = Modifier.fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Column(
                modifier = Modifier.padding(16.dp),
                verticalArrangement = Arrangement.spacedBy(14.dp)
            ) {
                Row(verticalAlignment = Alignment.CenterVertically, horizontalArrangement = Arrangement.spacedBy(12.dp)) {
                    Icon(Icons.Default.Tune, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                    Text("Mix & Merge", style = MaterialTheme.typography.titleMedium, fontWeight = FontWeight.SemiBold)
                    Spacer(Modifier.weight(1f))
                    Text(
                        if (outputDims.isEmpty()) "No shared output" else outputDims.joinToString(" + ") { "D$it" },
                        style = MaterialTheme.typography.labelMedium,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )
                }

                Row(horizontalArrangement = Arrangement.spacedBy(8.dp), verticalAlignment = Alignment.CenterVertically) {
                    ModeButton("Mix", mode == VoiceLabMode.Mix) { mode = VoiceLabMode.Mix }
                    ModeButton("Merge", mode == VoiceLabMode.Merge) { mode = VoiceLabMode.Merge }
                    Row(verticalAlignment = Alignment.CenterVertically) {
                        Checkbox(checked = normalize, onCheckedChange = { normalize = it })
                        Text("Normalize", style = MaterialTheme.typography.bodyMedium)
                    }
                }

                OutlinedTextField(
                    value = presetName,
                    onValueChange = { presetName = it },
                    modifier = Modifier.fillMaxWidth(),
                    label = { Text("New Preset Name") },
                    singleLine = true
                )

                if (mode == VoiceLabMode.Mix) {
                    Row(horizontalArrangement = Arrangement.spacedBy(12.dp), verticalAlignment = Alignment.CenterVertically) {
                        VoiceDropdown(
                            voices = customVoices,
                            selectedId = mixLeftId,
                            onSelected = { mixLeftId = it },
                            modifier = Modifier.weight(1f)
                        )
                        VoiceDropdown(
                            voices = customVoices,
                            selectedId = mixRightId,
                            onSelected = { mixRightId = it },
                            modifier = Modifier.weight(1f)
                        )
                    }
                    Row(verticalAlignment = Alignment.CenterVertically, horizontalArrangement = Arrangement.spacedBy(12.dp)) {
                        Text("${((1f - mixAmount) * 100).toInt()}%", style = MaterialTheme.typography.labelMedium)
                        Slider(
                            value = mixAmount,
                            onValueChange = { mixAmount = it },
                            modifier = Modifier.weight(1f),
                            enabled = customVoices.size >= 2
                        )
                        Text("${(mixAmount * 100).toInt()}%", style = MaterialTheme.typography.labelMedium)
                    }
                } else {
                    Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                        customVoices.forEach { voice ->
                            VoiceCheckRow(
                                voice = voice,
                                checked = voice.id in mergeSelection,
                                onCheckedChange = { checked ->
                                    mergeSelection = if (checked) mergeSelection + voice.id else mergeSelection - voice.id
                                }
                            )
                        }
                    }
                }

                Row(horizontalArrangement = Arrangement.End, modifier = Modifier.fillMaxWidth()) {
                    Button(
                        onClick = {
                            val nameToUse = presetName.ifBlank {
                                when (mode) {
                                    VoiceLabMode.Mix -> "Mixed Voice"
                                    VoiceLabMode.Merge -> "Merged Voice"
                                }
                            }
                            val sources = when (mode) {
                                VoiceLabMode.Mix -> listOf(
                                    EmbeddingBlendSource(mixLeftId, 1f - mixAmount),
                                    EmbeddingBlendSource(mixRightId, mixAmount)
                                )
                                VoiceLabMode.Merge -> mergeSelection
                                    .sorted()
                                    .map { EmbeddingBlendSource(it, 1f) }
                            }
                            viewModel.createMixedVoicePreset(nameToUse, sources, normalize)
                            presetName = ""
                        },
                        enabled = canCreate && !isCreating
                    ) {
                        Icon(Icons.Default.Add, contentDescription = null)
                        Spacer(Modifier.size(8.dp))
                        Text(
                            when {
                                isCreating -> "Creating..."
                                mode == VoiceLabMode.Mix -> "Create Mix"
                                else -> "Create Merge"
                            }
                        )
                    }
                }
            }
        }
    }
}

@Composable
private fun ModeButton(label: String, selected: Boolean, onClick: () -> Unit) {
    if (selected) {
        Button(onClick = onClick, contentPadding = androidx.compose.foundation.layout.PaddingValues(horizontal = 14.dp, vertical = 8.dp)) {
            Text(label)
        }
    } else {
        OutlinedButton(onClick = onClick, contentPadding = androidx.compose.foundation.layout.PaddingValues(horizontal = 14.dp, vertical = 8.dp)) {
            Text(label)
        }
    }
}

@Composable
private fun VoiceDropdown(
    voices: List<VoicePreset>,
    selectedId: String,
    onSelected: (String) -> Unit,
    modifier: Modifier = Modifier
) {
    var expanded by remember { mutableStateOf(false) }
    val selected = voices.firstOrNull { it.id == selectedId }

    Box(modifier = modifier) {
        OutlinedCard(
            onClick = { expanded = true },
            modifier = Modifier.fillMaxWidth()
        ) {
            Row(
                modifier = Modifier.padding(horizontal = 12.dp, vertical = 10.dp),
                verticalAlignment = Alignment.CenterVertically
            ) {
                Text(
                    selected?.name ?: "Select voice",
                    fontWeight = FontWeight.Medium,
                    maxLines = 1,
                    overflow = TextOverflow.Ellipsis,
                    modifier = Modifier.weight(1f)
                )
                Icon(Icons.Default.ArrowDropDown, contentDescription = null)
            }
        }
        DropdownMenu(expanded = expanded, onDismissRequest = { expanded = false }) {
            voices.forEach { voice ->
                DropdownMenuItem(
                    text = { Text(voice.name) },
                    onClick = {
                        onSelected(voice.id)
                        expanded = false
                    }
                )
            }
        }
    }
}

@Composable
private fun VoiceCheckRow(
    voice: VoicePreset,
    checked: Boolean,
    onCheckedChange: (Boolean) -> Unit
) {
    Row(
        modifier = Modifier.fillMaxWidth(),
        verticalAlignment = Alignment.CenterVertically,
        horizontalArrangement = Arrangement.spacedBy(8.dp)
    ) {
        Checkbox(checked = checked, onCheckedChange = onCheckedChange)
        Text(
            voice.name,
            style = MaterialTheme.typography.bodyMedium,
            maxLines = 1,
            overflow = TextOverflow.Ellipsis,
            modifier = Modifier.weight(1f)
        )
        Text(
            voice.speakerEmbeddings.keys.sorted().joinToString(" + ") { "D$it" },
            style = MaterialTheme.typography.labelMedium,
            color = MaterialTheme.colorScheme.onSurfaceVariant
        )
    }
}

private fun commonEmbeddingDims(voices: List<VoicePreset>, ids: List<String>): List<Int> {
    val selected = ids
        .distinct()
        .mapNotNull { id -> voices.firstOrNull { it.id == id } }
    if (selected.size < 2) return emptyList()

    return selected
        .map { it.speakerEmbeddings.keys }
        .reduce { acc, dims -> acc.intersect(dims) }
        .filter { it == 1024 || it == 2048 }
        .sorted()
}
