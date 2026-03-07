package com.qwen.tts.studio.screens

import androidx.compose.foundation.layout.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowDropDown
import androidx.compose.material.icons.filled.FolderOpen
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import com.qwen.tts.studio.viewmodel.ModelVariant
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import io.github.vinceglb.filekit.compose.rememberDirectoryPickerLauncher

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun SetupScreen(viewModel: SettingsViewModel) {
    val modelDir by viewModel.modelDir.collectAsState()
    val modelVariant by viewModel.modelVariant.collectAsState()
    
    val launcher = rememberDirectoryPickerLauncher(title = "Select Qwen3 Model Directory") { directory ->
        directory?.path?.let { viewModel.setModelDir(it) }
    }

    Column(
        modifier = Modifier.fillMaxSize().padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Card(
            modifier = Modifier.widthIn(max = 600.dp).fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = androidx.compose.foundation.BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Column(modifier = Modifier.padding(32.dp), verticalArrangement = Arrangement.spacedBy(24.dp)) {
                Text("Local Model Configuration", style = MaterialTheme.typography.titleLarge, fontWeight = FontWeight.Bold)
                
                Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                    Text("Qwen3 Model Directory", style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
                    Text(
                        "Select the folder containing tokenizer/vocoder files and your target qwen3-tts model file.",
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
                    Text("Model Variant", style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
                    Text(
                        "Switch between 0.6B (custom voice cloning) and 1.7B (instruction + named speakers).",
                        style = MaterialTheme.typography.labelSmall,
                        color = MaterialTheme.colorScheme.onSurfaceVariant.copy(alpha = 0.7f)
                    )
                    var variantExpanded by remember { mutableStateOf(false) }
                    Box {
                        OutlinedCard(
                            onClick = { variantExpanded = true },
                            modifier = Modifier.fillMaxWidth()
                        ) {
                            Row(
                                modifier = Modifier.padding(horizontal = 12.dp, vertical = 12.dp),
                                verticalAlignment = Alignment.CenterVertically
                            ) {
                                Text(modelVariant.label, style = MaterialTheme.typography.bodyLarge)
                                Spacer(Modifier.weight(1f))
                                Icon(Icons.Default.ArrowDropDown, contentDescription = null)
                            }
                        }
                        DropdownMenu(
                            expanded = variantExpanded,
                            onDismissRequest = { variantExpanded = false }
                        ) {
                            ModelVariant.entries.forEach { variant ->
                                DropdownMenuItem(
                                    text = { Text("${variant.label} (${variant.modelFile})") },
                                    onClick = {
                                        viewModel.setModelVariant(variant)
                                        variantExpanded = false
                                    }
                                )
                            }
                        }
                    }
                }

                HorizontalDivider(thickness = 1.dp, color = MaterialTheme.colorScheme.outlineVariant)
                
                Spacer(Modifier.height(16.dp))
                
                Button(
                    onClick = { /* Save Settings */ },
                    modifier = Modifier.fillMaxWidth(),
                    shape = MaterialTheme.shapes.medium
                ) {
                    Text("Save & Apply Configuration")
                }
            }
        }
    }
}
