package com.qwen.tts.studio.screens

import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.layout.widthIn
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowDropDown
import androidx.compose.material.icons.filled.FolderOpen
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.DropdownMenu
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material3.HorizontalDivider
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedCard
import androidx.compose.material3.OutlinedTextField
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
import androidx.compose.ui.unit.dp
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import io.github.vinceglb.filekit.compose.rememberDirectoryPickerLauncher

@Composable
fun SetupScreen(viewModel: SettingsViewModel) {
    val modelDir by viewModel.modelDir.collectAsState()
    val modelName by viewModel.modelName.collectAsState()
    val availableModelNames by viewModel.availableModelNames.collectAsState()

    val launcher = rememberDirectoryPickerLauncher(title = "Select Qwen3 Model Directory") { directory ->
        directory?.path?.let { viewModel.setModelDir(it) }
    }

    LaunchedEffect(modelDir) {
        viewModel.refreshModelNames()
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Card(
            modifier = Modifier.widthIn(max = 700.dp).fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Column(modifier = Modifier.padding(32.dp), verticalArrangement = Arrangement.spacedBy(24.dp)) {
                Text("Local Model Configuration", style = MaterialTheme.typography.titleLarge, fontWeight = FontWeight.Bold)

                Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                    Text("Qwen3 Model Directory", style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
                    Text(
                        "Select the folder containing tokenizer/vocoder files and one or more qwen3-tts model GGUF files.",
                        style = MaterialTheme.typography.labelSmall,
                        color = MaterialTheme.colorScheme.onSurfaceVariant.copy(alpha = 0.7f)
                    )
                    Row(horizontalArrangement = Arrangement.spacedBy(12.dp)) {
                        OutlinedTextField(
                            value = modelDir,
                            onValueChange = { viewModel.setModelDir(it) },
                            modifier = Modifier.weight(1f),
                            singleLine = true,
                            placeholder = { Text("Select folder...") },
                            shape = MaterialTheme.shapes.medium
                        )
                        Button(
                            onClick = { launcher.launch() },
                            shape = MaterialTheme.shapes.medium,
                            modifier = Modifier.height(56.dp)
                        ) {
                            Icon(Icons.Default.FolderOpen, contentDescription = null)
                            Spacer(Modifier.width(8.dp))
                            Text("Browse")
                        }
                    }
                }

                Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                    Text("Model File Name", style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
                    Text(
                        "Pick a model file (e.g. 0.6B Base, 1.7B Base, 1.7B CustomVoice). UI features adapt automatically after load.",
                        style = MaterialTheme.typography.labelSmall,
                        color = MaterialTheme.colorScheme.onSurfaceVariant.copy(alpha = 0.7f)
                    )
                    OutlinedTextField(
                        value = modelName,
                        onValueChange = { viewModel.setModelName(it) },
                        modifier = Modifier.fillMaxWidth(),
                        singleLine = true,
                        placeholder = { Text("qwen3-tts-0.6b-f16.gguf") },
                        shape = MaterialTheme.shapes.medium
                    )

                    if (availableModelNames.isNotEmpty()) {
                        var modelExpanded by remember { mutableStateOf(false) }
                        Box {
                            OutlinedCard(
                                onClick = { modelExpanded = true },
                                modifier = Modifier.fillMaxWidth()
                            ) {
                                Row(
                                    modifier = Modifier.padding(horizontal = 12.dp, vertical = 12.dp),
                                    verticalAlignment = Alignment.CenterVertically
                                ) {
                                    Text("Choose detected model file")
                                    Spacer(Modifier.weight(1f))
                                    Icon(Icons.Default.ArrowDropDown, contentDescription = null)
                                }
                            }
                            DropdownMenu(
                                expanded = modelExpanded,
                                onDismissRequest = { modelExpanded = false }
                            ) {
                                availableModelNames.forEach { fileName ->
                                    DropdownMenuItem(
                                        text = { Text(fileName) },
                                        onClick = {
                                            viewModel.setModelName(fileName)
                                            modelExpanded = false
                                        }
                                    )
                                }
                            }
                        }
                    }
                }

                HorizontalDivider(thickness = 1.dp, color = MaterialTheme.colorScheme.outlineVariant)

                Spacer(Modifier.height(8.dp))

                Text(
                    "Features (instruction, named speakers, custom cloning) are detected automatically from the loaded model.",
                    style = MaterialTheme.typography.bodySmall,
                    color = MaterialTheme.colorScheme.onSurfaceVariant
                )
            }
        }
    }
}
