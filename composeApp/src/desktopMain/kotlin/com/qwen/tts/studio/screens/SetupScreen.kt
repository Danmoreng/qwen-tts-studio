package com.qwen.tts.studio.screens

import androidx.compose.foundation.BorderStroke
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
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.automirrored.filled.OpenInNew
import androidx.compose.material.icons.filled.ArrowDropDown
import androidx.compose.material.icons.filled.CloudDownload
import androidx.compose.material.icons.filled.Delete
import androidx.compose.material.icons.filled.FolderOpen
import androidx.compose.material.icons.filled.SkipNext
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.Checkbox
import androidx.compose.material3.DropdownMenu
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material3.HorizontalDivider
import androidx.compose.material3.Icon
import androidx.compose.material3.LinearProgressIndicator
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedButton
import androidx.compose.material3.OutlinedCard
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.material3.TextButton
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
import com.qwen.tts.studio.viewmodel.ModelDownloadOption
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import io.github.vinceglb.filekit.compose.rememberDirectoryPickerLauncher
import java.awt.Desktop
import java.net.URI

@Composable
fun WelcomeSetupScreen(
    viewModel: SettingsViewModel,
    onContinue: () -> Unit
) {
    val modelDir by viewModel.modelDir.collectAsState()
    val availableModelNames by viewModel.availableModelNames.collectAsState()

    LaunchedEffect(modelDir) {
        viewModel.refreshModelNames()
    }

    Surface(modifier = Modifier.fillMaxSize(), color = MaterialTheme.colorScheme.background) {
        Column(
            modifier = Modifier
                .fillMaxSize()
                .verticalScroll(rememberScrollState())
                .padding(32.dp),
            horizontalAlignment = Alignment.CenterHorizontally,
            verticalArrangement = Arrangement.Center
        ) {
            Column(
                modifier = Modifier.widthIn(max = 860.dp).fillMaxWidth(),
                verticalArrangement = Arrangement.spacedBy(24.dp)
            ) {
                Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                    Text("Qwen-TTS Studio", style = MaterialTheme.typography.headlineLarge, fontWeight = FontWeight.Bold)
                    Text(
                        "Choose where your GGUF models live, or download a starter set from Hugging Face.",
                        style = MaterialTheme.typography.bodyLarge,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )
                }

                ModelDirectorySection(viewModel)
                ModelDownloadSection(viewModel)

                Row(
                    modifier = Modifier.fillMaxWidth(),
                    horizontalArrangement = Arrangement.SpaceBetween,
                    verticalAlignment = Alignment.CenterVertically
                ) {
                    Text(
                        if (availableModelNames.isEmpty()) "You can skip and configure models later in Setup." else "${availableModelNames.size} model file(s) detected.",
                        style = MaterialTheme.typography.bodyMedium,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )
                    Row(horizontalArrangement = Arrangement.spacedBy(12.dp)) {
                        OutlinedButton(onClick = onContinue) {
                            Icon(Icons.Default.SkipNext, contentDescription = null)
                            Spacer(Modifier.width(8.dp))
                            Text("Skip")
                        }
                        Button(onClick = onContinue, enabled = availableModelNames.isNotEmpty()) {
                            Text("Continue")
                        }
                    }
                }
            }
        }
    }
}

/**
 * Screen for configuring the application settings, such as model directory and file.
 */
@Composable
fun SetupScreen(viewModel: SettingsViewModel) {
    val modelDir by viewModel.modelDir.collectAsState()
    val modelName by viewModel.modelName.collectAsState()
    val availableModelNames by viewModel.availableModelNames.collectAsState()

    LaunchedEffect(modelDir) {
        viewModel.refreshModelNames()
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .verticalScroll(rememberScrollState())
            .padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Column(
            modifier = Modifier.widthIn(max = 820.dp).fillMaxWidth(),
            verticalArrangement = Arrangement.spacedBy(20.dp)
        ) {
            Card(
                colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
                border = BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
            ) {
                Column(modifier = Modifier.padding(28.dp), verticalArrangement = Arrangement.spacedBy(22.dp)) {
                    Text("Local Model Configuration", style = MaterialTheme.typography.titleLarge, fontWeight = FontWeight.Bold)

                    ModelDirectorySection(viewModel)

                    Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                        Text("Model File Name", style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
                        Text(
                            "Pick a Serveurperso qwen-talker GGUF model file.",
                            style = MaterialTheme.typography.labelSmall,
                            color = MaterialTheme.colorScheme.onSurfaceVariant.copy(alpha = 0.7f)
                        )
                        OutlinedTextField(
                            value = modelName,
                            onValueChange = { viewModel.setModelName(it) },
                            modifier = Modifier.fillMaxWidth(),
                            singleLine = true,
                            placeholder = { Text("qwen-talker-0.6b-base-Q8_0.gguf") },
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

                    Text(
                        "Features such as instructions, named speakers, and cloning are detected from the loaded model.",
                        style = MaterialTheme.typography.bodySmall,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )
                }
            }

            ModelDownloadSection(viewModel)
        }
    }
}

@Composable
private fun ModelDirectorySection(viewModel: SettingsViewModel) {
    val modelDir by viewModel.modelDir.collectAsState()
    val launcher = rememberDirectoryPickerLauncher(title = "Select Qwen3 Model Directory") { directory ->
        directory?.path?.let { viewModel.setModelDir(it) }
    }

    Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
        Text("Model Directory", style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
        Text(
            "This folder should contain one tokenizer GGUF and one or more talker model GGUF files.",
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
}

@Composable
private fun ModelDownloadSection(viewModel: SettingsViewModel) {
    val downloadState by viewModel.downloadState.collectAsState()
    val installedIds by viewModel.installedDownloadOptionIds.collectAsState()
    var selectedIds by remember { mutableStateOf(setOf(SettingsViewModel.downloadOptions.first().id)) }

    Card(
        colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
        border = BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
    ) {
        Column(modifier = Modifier.padding(24.dp), verticalArrangement = Arrangement.spacedBy(16.dp)) {
            Row(verticalAlignment = Alignment.CenterVertically, horizontalArrangement = Arrangement.spacedBy(12.dp)) {
                Icon(Icons.Default.CloudDownload, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                Column(modifier = Modifier.weight(1f)) {
                    Text("Download GGUF Models", style = MaterialTheme.typography.titleMedium, fontWeight = FontWeight.SemiBold)
                    Text(
                        "Source: Serveurperso/Qwen3-TTS-GGUF on Hugging Face.",
                        style = MaterialTheme.typography.bodySmall,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )
                }
                OutlinedButton(
                    onClick = { openExternalUrl(SettingsViewModel.HUGGING_FACE_REPO_URL) }
                ) {
                    Icon(Icons.AutoMirrored.Filled.OpenInNew, contentDescription = null)
                    Spacer(Modifier.width(8.dp))
                    Text("View Source")
                }
            }

            Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                SettingsViewModel.downloadOptions.forEach { option ->
                    DownloadOptionRow(
                        option = option,
                        checked = option.id in selectedIds,
                        installed = option.id in installedIds,
                        enabled = !downloadState.isDownloading,
                        onUninstall = { viewModel.uninstallModel(option.id) },
                        onCheckedChange = { checked ->
                            selectedIds = if (checked) selectedIds + option.id else selectedIds - option.id
                        }
                    )
                }
            }

            if (downloadState.isDownloading || downloadState.status.isNotBlank()) {
                Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                    LinearProgressIndicator(
                        progress = { downloadState.progress.coerceIn(0f, 1f) },
                        modifier = Modifier.fillMaxWidth()
                    )
                    Text(
                        listOf(
                            downloadState.status,
                            formatByteProgress(downloadState.bytesDownloaded, downloadState.bytesTotal),
                            downloadState.currentFile
                        ).filter { it.isNotBlank() }.joinToString(" - "),
                        style = MaterialTheme.typography.bodySmall,
                        color = MaterialTheme.colorScheme.onSurfaceVariant,
                        maxLines = 1,
                        overflow = TextOverflow.Ellipsis
                    )
                }
            }

            downloadState.error?.let { error ->
                Text(error, style = MaterialTheme.typography.bodySmall, color = MaterialTheme.colorScheme.error)
            }

            Row(horizontalArrangement = Arrangement.spacedBy(12.dp), verticalAlignment = Alignment.CenterVertically) {
                Button(
                    onClick = { viewModel.downloadModels(selectedIds) },
                    enabled = selectedIds.isNotEmpty() && !downloadState.isDownloading
                ) {
                    Icon(Icons.Default.CloudDownload, contentDescription = null)
                    Spacer(Modifier.width(8.dp))
                    Text(if (downloadState.isDownloading) "Downloading..." else "Download Selected")
                }
                TextButton(
                    onClick = { selectedIds = SettingsViewModel.downloadOptions.map { it.id }.toSet() },
                    enabled = !downloadState.isDownloading
                ) {
                    Text("Select all")
                }
            }
        }
    }
}

@Composable
private fun DownloadOptionRow(
    option: ModelDownloadOption,
    checked: Boolean,
    installed: Boolean,
    enabled: Boolean,
    onUninstall: () -> Unit,
    onCheckedChange: (Boolean) -> Unit
) {
    OutlinedCard(
        onClick = { if (enabled) onCheckedChange(!checked) },
        modifier = Modifier.fillMaxWidth()
    ) {
        Row(
            modifier = Modifier.padding(horizontal = 12.dp, vertical = 10.dp),
            verticalAlignment = Alignment.CenterVertically,
            horizontalArrangement = Arrangement.spacedBy(12.dp)
        ) {
            Checkbox(checked = checked, onCheckedChange = onCheckedChange, enabled = enabled)
            Column(modifier = Modifier.weight(1f), verticalArrangement = Arrangement.spacedBy(2.dp)) {
                Text(option.title, style = MaterialTheme.typography.bodyMedium, fontWeight = FontWeight.Medium)
                Text(option.description, style = MaterialTheme.typography.bodySmall, color = MaterialTheme.colorScheme.onSurfaceVariant)
            }
            Column(horizontalAlignment = Alignment.End, verticalArrangement = Arrangement.spacedBy(4.dp)) {
                Text(formatBytes(option.totalSizeBytes), style = MaterialTheme.typography.labelMedium, color = MaterialTheme.colorScheme.onSurface)
                Text("${option.files.size} files", style = MaterialTheme.typography.labelSmall, color = MaterialTheme.colorScheme.onSurfaceVariant)
                Text(
                    if (installed) "Installed" else "Not installed",
                    style = MaterialTheme.typography.labelSmall,
                    color = if (installed) MaterialTheme.colorScheme.primary else MaterialTheme.colorScheme.onSurfaceVariant
                )
                if (installed) {
                    TextButton(onClick = onUninstall, enabled = enabled) {
                        Icon(Icons.Default.Delete, contentDescription = null)
                        Spacer(Modifier.width(6.dp))
                        Text("Delete")
                    }
                }
            }
        }
    }
}

private fun formatByteProgress(downloaded: Long, total: Long): String {
    if (total <= 0L) return ""
    return "${formatBytes(downloaded.coerceIn(0L, total))} / ${formatBytes(total)}"
}

private fun formatBytes(bytes: Long): String {
    if (bytes <= 0L) return "Unknown size"
    val gib = bytes.toDouble() / (1024.0 * 1024.0 * 1024.0)
    if (gib >= 1.0) return String.format("%.2f GB", gib)
    val mib = bytes.toDouble() / (1024.0 * 1024.0)
    return String.format("%.0f MB", mib)
}

private fun openExternalUrl(url: String) {
    runCatching {
        if (Desktop.isDesktopSupported()) {
            Desktop.getDesktop().browse(URI(url))
        }
    }
}
