package com.qwen.tts.studio.screens

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Add
import androidx.compose.material.icons.filled.Delete
import androidx.compose.material.icons.filled.FolderOpen
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import com.qwen.tts.studio.util.FilePicker
import com.qwen.tts.studio.viewmodel.VoicePreset
import com.qwen.tts.studio.viewmodel.VoicesViewModel
import java.io.File

@Composable
fun VoicesScreen(viewModel: VoicesViewModel) {
    val voices by viewModel.voices.collectAsState()
    var presetName by remember { mutableStateOf("") }
    var referencePath by remember { mutableStateOf("") }
    var error by remember { mutableStateOf<String?>(null) }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(24.dp),
        verticalArrangement = Arrangement.spacedBy(16.dp)
    ) {
        Card(
            modifier = Modifier.fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Column(
                modifier = Modifier.padding(16.dp),
                verticalArrangement = Arrangement.spacedBy(12.dp)
            ) {
                Text("Create Speaker Preset", style = MaterialTheme.typography.titleMedium, fontWeight = FontWeight.SemiBold)
                OutlinedTextField(
                    value = presetName,
                    onValueChange = { presetName = it },
                    modifier = Modifier.fillMaxWidth(),
                    label = { Text("Preset Name") },
                    singleLine = true
                )
                Row(horizontalArrangement = Arrangement.spacedBy(12.dp), verticalAlignment = Alignment.CenterVertically) {
                    OutlinedTextField(
                        value = referencePath,
                        onValueChange = {},
                        readOnly = true,
                        modifier = Modifier.weight(1f),
                        label = { Text("Reference Audio (.wav)") },
                        singleLine = true
                    )
                    Button(
                        onClick = {
                            FilePicker.pickFile(
                                title = "Select Reference Audio",
                                allowedExtensions = listOf(".wav")
                            ) { referencePath = it }
                        }
                    ) {
                        Icon(Icons.Default.FolderOpen, contentDescription = null)
                        Spacer(Modifier.width(8.dp))
                        Text("Browse")
                    }
                }
                if (error != null) {
                    Text(error!!, color = MaterialTheme.colorScheme.error, style = MaterialTheme.typography.bodySmall)
                }
                Button(
                    onClick = {
                        val fallbackName = File(referencePath).nameWithoutExtension
                        val nameToUse = presetName.ifBlank { fallbackName }
                        error = viewModel.addVoicePreset(nameToUse, referencePath)
                        if (error == null) {
                            presetName = ""
                            referencePath = ""
                        }
                    },
                    enabled = referencePath.isNotBlank()
                ) {
                    Icon(Icons.Default.Add, contentDescription = null)
                    Spacer(Modifier.width(8.dp))
                    Text("Create Preset")
                }
            }
        }

        LazyColumn(
            modifier = Modifier.fillMaxSize(),
            verticalArrangement = Arrangement.spacedBy(12.dp)
        ) {
            items(voices, key = { it.id }) { preset ->
                VoicePresetCard(
                    preset = preset,
                    onDelete = { viewModel.deleteVoicePreset(preset.id) }
                )
            }
        }
    }
}

@Composable
private fun VoicePresetCard(
    preset: VoicePreset,
    onDelete: () -> Unit
) {
    Card(
        modifier = Modifier.fillMaxWidth(),
        colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
        border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
    ) {
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .padding(16.dp),
            horizontalArrangement = Arrangement.SpaceBetween,
            verticalAlignment = Alignment.CenterVertically
        ) {
            Column(modifier = Modifier.weight(1f), verticalArrangement = Arrangement.spacedBy(4.dp)) {
                Text(preset.name, style = MaterialTheme.typography.titleMedium, fontWeight = FontWeight.SemiBold)
                Text(
                    if (preset.isSystem) "Built-in model voice" else "Reference: ${preset.referenceWav}",
                    style = MaterialTheme.typography.bodySmall,
                    color = MaterialTheme.colorScheme.onSurfaceVariant
                )
            }
            if (!preset.isSystem) {
                IconButton(onClick = onDelete) {
                    Icon(Icons.Default.Delete, contentDescription = "Delete preset")
                }
            }
        }
    }
}
