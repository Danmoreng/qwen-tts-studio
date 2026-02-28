package com.qwen.tts.studio.screens

import androidx.compose.foundation.layout.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.FolderOpen
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun SetupScreen() {
    var modelPath by remember { mutableStateOf("/models/qwen3-tts-q4_k_m.gguf") }
    var selectedAcceleration by remember { mutableStateOf("CPU (AVX2)") }

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
                    Text("Qwen3 Model Path (.bin / .gguf)", style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
                    Row(horizontalArrangement = Arrangement.spacedBy(12.dp)) {
                        OutlinedTextField(
                            value = modelPath,
                            onValueChange = { modelPath = it },
                            modifier = Modifier.weight(1f),
                            singleLine = true,
                            readOnly = true,
                            shape = MaterialTheme.shapes.medium
                        )
                        Button(
                            onClick = { /* Browse */ },
                            shape = MaterialTheme.shapes.medium,
                            modifier = Modifier.height(56.dp)
                        ) {
                            Icon(Icons.Default.FolderOpen, contentDescription = null)
                            Spacer(Modifier.width(8.dp))
                            Text("Browse")
                        }
                    }
                }

                HorizontalDivider(thickness = 1.dp, color = MaterialTheme.colorScheme.outlineVariant)

                Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                    Text("Hardware Acceleration", style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
                    var expanded by remember { mutableStateOf(false) }
                    ExposedDropdownMenuBox(
                        expanded = expanded,
                        onExpandedChange = { expanded = !expanded }
                    ) {
                        OutlinedTextField(
                            value = selectedAcceleration,
                            onValueChange = {},
                            readOnly = true,
                            trailingIcon = { ExposedDropdownMenuDefaults.TrailingIcon(expanded = expanded) },
                            modifier = Modifier.fillMaxWidth().menuAnchor(),
                            shape = MaterialTheme.shapes.medium
                        )
                        ExposedDropdownMenu(
                            expanded = expanded,
                            onDismissRequest = { expanded = false }
                        ) {
                            listOf("CPU (AVX2)", "CUDA (NVIDIA GPU)", "Vulkan (AMD/Intel)").forEach { selectionOption ->
                                DropdownMenuItem(
                                    text = { Text(selectionOption) },
                                    onClick = {
                                        selectedAcceleration = selectionOption
                                        expanded = false
                                    }
                                )
                            }
                        }
                    }
                }
                
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
