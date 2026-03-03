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
import androidx.compose.material3.CircularProgressIndicator
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
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import com.qwen.tts.studio.viewmodel.VoicePreset
import com.qwen.tts.studio.viewmodel.VoicesViewModel
import io.github.vinceglb.filekit.compose.rememberFilePickerLauncher
import io.github.vinceglb.filekit.core.PickerType
import java.io.File

@Composable
fun VoicesScreen(viewModel: VoicesViewModel, settingsViewModel: SettingsViewModel) {
    val voices by viewModel.voices.collectAsState()
    val isCreating by viewModel.isCreating.collectAsState()
    val error by viewModel.error.collectAsState()
    val modelDir by settingsViewModel.modelDir.collectAsState()
    var presetName by remember { mutableStateOf("") }
    var referencePath by remember { mutableStateOf("") }
    
    val launcher = rememberFilePickerLauncher(
        type = PickerType.File(extensions = listOf("wav")),
        title = "Select Reference Audio"
    ) { file ->
        file?.path?.let { referencePath = it }
    }

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
                        onClick = { launcher.launch() }
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
                        viewModel.createVoicePreset(nameToUse, referencePath, modelDir)
                        presetName = ""
                        referencePath = ""
                    },
                    enabled = referencePath.isNotBlank() && !isCreating
                ) {
                    if (isCreating) {
                        CircularProgressIndicator(modifier = Modifier.size(18.dp), strokeWidth = 2.dp)
                        Spacer(Modifier.width(8.dp))
                        Text("Extracting Embedding...")
                    } else {
                        Icon(Icons.Default.Add, contentDescription = null)
                        Spacer(Modifier.width(8.dp))
                        Text("Create Preset")
                    }
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
                    if (preset.isSystem) "Built-in model voice" else "Embedding: ${preset.speakerEmbeddingPath}",
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
