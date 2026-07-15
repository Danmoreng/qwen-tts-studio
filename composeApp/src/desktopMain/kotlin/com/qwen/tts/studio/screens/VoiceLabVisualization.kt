package com.qwen.tts.studio.screens

import androidx.compose.foundation.Canvas
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.BoxWithConstraints
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowDropDown
import androidx.compose.material.icons.filled.GraphicEq
import androidx.compose.material.icons.filled.PlayArrow
import androidx.compose.material.icons.filled.Replay
import androidx.compose.material.icons.filled.Save
import androidx.compose.material.icons.filled.Stop
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.CircularProgressIndicator
import androidx.compose.material3.DropdownMenu
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material3.FilterChip
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedButton
import androidx.compose.material3.OutlinedCard
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.geometry.Offset
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.lerp
import androidx.compose.ui.semantics.contentDescription
import androidx.compose.ui.semantics.semantics
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.unit.dp
import com.qwen.tts.studio.embedding.LatentBlockSummary
import com.qwen.tts.studio.embedding.MorphEmbeddingAnalysis
import com.qwen.tts.studio.viewmodel.VoiceLabPreviewState
import java.util.Locale
import kotlin.math.max
import kotlin.math.roundToInt
import kotlin.math.sqrt

@Composable
internal fun MorphEmbeddingVisualization(
    sourceName: String,
    targetName: String,
    availableDimensions: List<Int>,
    selectedDimension: Int,
    onDimensionSelected: (Int) -> Unit,
    preserveAverageNorm: Boolean,
    onPreserveAverageNormChange: (Boolean) -> Unit,
    analysis: MorphEmbeddingAnalysis?,
    isLoading: Boolean,
    error: String?
) {
    Card(
        modifier = Modifier.fillMaxWidth(),
        colors = CardDefaults.cardColors(
            containerColor = MaterialTheme.colorScheme.surfaceVariant.copy(alpha = 0.35f)
        )
    ) {
        Column(
            modifier = Modifier.padding(16.dp),
            verticalArrangement = Arrangement.spacedBy(10.dp)
        ) {
            Row(
                modifier = Modifier.fillMaxWidth(),
                verticalAlignment = Alignment.CenterVertically,
                horizontalArrangement = Arrangement.spacedBy(10.dp)
            ) {
                Icon(Icons.Default.GraphicEq, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                Text(
                    "Latent fingerprint",
                    modifier = Modifier.weight(1f),
                    style = MaterialTheme.typography.titleSmall,
                    fontWeight = FontWeight.SemiBold
                )
                FilterChip(
                    selected = preserveAverageNorm,
                    onClick = { onPreserveAverageNormChange(!preserveAverageNorm) },
                    label = { Text("Norm match") }
                )
                availableDimensions.forEach { dimension ->
                    FilterChip(
                        selected = selectedDimension == dimension,
                        onClick = { onDimensionSelected(dimension) },
                        label = { Text("D$dimension") }
                    )
                }
            }

            when {
                isLoading -> {
                    Row(
                        modifier = Modifier.fillMaxWidth().padding(vertical = 18.dp),
                        horizontalArrangement = Arrangement.Center,
                        verticalAlignment = Alignment.CenterVertically
                    ) {
                        CircularProgressIndicator(modifier = Modifier.size(20.dp), strokeWidth = 2.dp)
                        Spacer(Modifier.width(10.dp))
                        Text("Loading embedding vectors…", style = MaterialTheme.typography.bodySmall)
                    }
                }

                error != null -> {
                    Text(error, color = MaterialTheme.colorScheme.error, style = MaterialTheme.typography.bodySmall)
                }

                analysis != null -> {
                    LatentFingerprint(
                        analysis = analysis,
                        sourceName = sourceName,
                        targetName = targetName
                    )
                }
            }
        }
    }
}

@Composable
private fun LatentFingerprint(
    analysis: MorphEmbeddingAnalysis,
    sourceName: String,
    targetName: String
) {
    val bins = analysis.fingerprintBins
    if (bins.isEmpty()) return

    val vectorScale = bins.maxOf { bin ->
        maxOf(bin.source.rms, bin.target.rms)
    }.coerceAtLeast(1e-12)
    val negativeColor = MaterialTheme.colorScheme.tertiary
    val positiveColor = MaterialTheme.colorScheme.primary
    val neutralColor = MaterialTheme.colorScheme.surface
    val neutralMagnitudeColor = MaterialTheme.colorScheme.onSurfaceVariant

    Column(verticalArrangement = Arrangement.spacedBy(5.dp)) {
        FingerprintRow(
            label = "A · $sourceName",
            values = bins.map { it.source },
            scale = vectorScale,
            negativeColor = negativeColor,
            positiveColor = positiveColor,
            neutralColor = neutralColor,
            neutralMagnitudeColor = neutralMagnitudeColor
        )
        FingerprintRow(
            label = "B · $targetName",
            values = bins.map { it.target },
            scale = vectorScale,
            negativeColor = negativeColor,
            positiveColor = positiveColor,
            neutralColor = neutralColor,
            neutralMagnitudeColor = neutralMagnitudeColor
        )
        FingerprintRow(
            label = "Output",
            values = bins.map { it.mixed },
            scale = vectorScale,
            negativeColor = negativeColor,
            positiveColor = positiveColor,
            neutralColor = neutralColor,
            neutralMagnitudeColor = neutralMagnitudeColor
        )
    }
}

@Composable
private fun FingerprintRow(
    label: String,
    values: List<LatentBlockSummary>,
    scale: Double,
    negativeColor: Color,
    positiveColor: Color,
    neutralColor: Color,
    neutralMagnitudeColor: Color
) {
    val positiveCount = values.count { it.polarity > 0.02 }
    val negativeCount = values.count { it.polarity < -0.02 }
    val neutralCount = values.size - positiveCount - negativeCount
    val strongestIndex = values.indices.maxByOrNull { values[it].rms }
    val strongestPercent = strongestIndex
        ?.let { (values[it].rms / scale * 100.0).roundToInt().coerceIn(0, 100) }
        ?: 0

    Row(
        modifier = Modifier.fillMaxWidth(),
        verticalAlignment = Alignment.CenterVertically,
        horizontalArrangement = Arrangement.spacedBy(10.dp)
    ) {
        Text(
            label,
            modifier = Modifier.width(112.dp),
            style = MaterialTheme.typography.labelSmall,
            maxLines = 1,
            overflow = TextOverflow.Ellipsis
        )
        Canvas(
            modifier = Modifier
                .weight(1f)
                .height(18.dp)
                .semantics {
                    contentDescription =
                        "$label latent fingerprint: ${values.size} blocks, $positiveCount positive, " +
                            "$negativeCount negative, $neutralCount neutral-polarity. " +
                            "Strongest block ${strongestIndex?.plus(1) ?: 0} at $strongestPercent percent of this scale."
                }
        ) {
            val cellWidth = size.width / values.size
            val gap = 1.dp.toPx().coerceAtMost(cellWidth * 0.35f)
            values.forEachIndexed { index, summary ->
                val intensity = (summary.rms / scale).toFloat().coerceIn(0f, 1f)
                val contrastIntensity = sqrt(intensity)
                val tint = when {
                    summary.polarity > 0.02 -> positiveColor
                    summary.polarity < -0.02 -> negativeColor
                    else -> neutralMagnitudeColor
                }
                val blockX = index * cellWidth
                val blockWidth = (cellWidth - gap).coerceAtLeast(1f)
                drawRect(
                    color = lerp(neutralColor, tint, contrastIntensity.coerceIn(0f, 1f)),
                    topLeft = Offset(blockX, 0f),
                    size = androidx.compose.ui.geometry.Size(
                        width = blockWidth,
                        height = size.height
                    )
                )
                if (intensity > 0.01f) {
                    val markerHeight = 1.25.dp.toPx().coerceAtMost(size.height / 4f)
                    val markerY = when {
                        summary.polarity > 0.02 -> 0f
                        summary.polarity < -0.02 -> size.height - markerHeight
                        else -> (size.height - markerHeight) / 2f
                    }
                    drawRect(
                        color = neutralMagnitudeColor.copy(alpha = 0.72f),
                        topLeft = Offset(blockX, markerY),
                        size = androidx.compose.ui.geometry.Size(blockWidth, markerHeight)
                    )
                }
            }
        }
    }
}

@Composable
internal fun VoiceLabPreviewPanel(
    previewText: String,
    onPreviewTextChange: (String) -> Unit,
    language: String,
    onLanguageChange: (String) -> Unit,
    presetName: String,
    onPresetNameChange: (String) -> Unit,
    state: VoiceLabPreviewState,
    selectedModelName: String?,
    selectedEmbeddingDimension: Int?,
    compatibilityMessage: String?,
    canGenerate: Boolean,
    canSave: Boolean,
    isSaving: Boolean,
    saveLabel: String,
    onGenerate: () -> Unit,
    onReplay: () -> Unit,
    onStop: () -> Unit,
    onCancel: () -> Unit,
    onSave: () -> Unit
) {
    Card(
        modifier = Modifier.fillMaxWidth(),
        colors = CardDefaults.cardColors(
            containerColor = MaterialTheme.colorScheme.surfaceVariant.copy(alpha = 0.35f)
        )
    ) {
        Column(
            modifier = Modifier.padding(16.dp),
            verticalArrangement = Arrangement.spacedBy(10.dp)
        ) {
            Row(
                modifier = Modifier.fillMaxWidth(),
                verticalAlignment = Alignment.CenterVertically,
                horizontalArrangement = Arrangement.spacedBy(8.dp)
            ) {
                Icon(Icons.Default.PlayArrow, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                Text(
                    "Preview & save",
                    modifier = Modifier.weight(1f),
                    style = MaterialTheme.typography.titleSmall,
                    fontWeight = FontWeight.SemiBold
                )
                Text(
                    buildString {
                        append(selectedModelName?.takeIf { it.isNotBlank() } ?: "No model selected")
                        selectedEmbeddingDimension?.let { append(" · D$it") }
                    },
                    style = MaterialTheme.typography.labelSmall,
                    color = MaterialTheme.colorScheme.onSurfaceVariant,
                    maxLines = 1,
                    overflow = TextOverflow.Ellipsis
                )
            }

            BoxWithConstraints(modifier = Modifier.fillMaxWidth()) {
                when {
                    maxWidth >= 1100.dp -> {
                        Row(
                            modifier = Modifier.fillMaxWidth(),
                            verticalAlignment = Alignment.CenterVertically,
                            horizontalArrangement = Arrangement.spacedBy(10.dp)
                        ) {
                            PreviewSentenceField(
                                value = previewText,
                                onValueChange = onPreviewTextChange,
                                modifier = Modifier.weight(1f)
                            )
                            PreviewLanguageDropdown(
                                selected = language,
                                onSelected = onLanguageChange,
                                modifier = Modifier.width(145.dp)
                            )
                            PreviewTransportButtons(
                                state = state,
                                canGenerate = canGenerate,
                                onGenerate = onGenerate,
                                onReplay = onReplay,
                                onStop = onStop,
                                onCancel = onCancel
                            )
                            PresetNameField(
                                value = presetName,
                                onValueChange = onPresetNameChange,
                                modifier = Modifier.width(220.dp)
                            )
                            SaveVoiceButton(
                                label = saveLabel,
                                isSaving = isSaving,
                                enabled = canSave,
                                onClick = onSave
                            )
                        }
                    }

                    maxWidth >= 700.dp -> {
                        Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                            Row(
                                modifier = Modifier.fillMaxWidth(),
                                verticalAlignment = Alignment.CenterVertically,
                                horizontalArrangement = Arrangement.spacedBy(10.dp)
                            ) {
                                PreviewSentenceField(
                                    value = previewText,
                                    onValueChange = onPreviewTextChange,
                                    modifier = Modifier.weight(1f)
                                )
                                PreviewLanguageDropdown(
                                    selected = language,
                                    onSelected = onLanguageChange,
                                    modifier = Modifier.width(145.dp)
                                )
                                PreviewTransportButtons(
                                    state = state,
                                    canGenerate = canGenerate,
                                    onGenerate = onGenerate,
                                    onReplay = onReplay,
                                    onStop = onStop,
                                    onCancel = onCancel
                                )
                            }
                            Row(
                                modifier = Modifier.fillMaxWidth(),
                                verticalAlignment = Alignment.CenterVertically,
                                horizontalArrangement = Arrangement.spacedBy(10.dp)
                            ) {
                                PresetNameField(
                                    value = presetName,
                                    onValueChange = onPresetNameChange,
                                    modifier = Modifier.weight(1f)
                                )
                                SaveVoiceButton(
                                    label = saveLabel,
                                    isSaving = isSaving,
                                    enabled = canSave,
                                    onClick = onSave
                                )
                            }
                        }
                    }

                    else -> {
                        Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                            PreviewSentenceField(
                                value = previewText,
                                onValueChange = onPreviewTextChange,
                                modifier = Modifier.fillMaxWidth()
                            )
                            PreviewLanguageDropdown(
                                selected = language,
                                onSelected = onLanguageChange,
                                modifier = Modifier.fillMaxWidth()
                            )
                            PreviewTransportButtons(
                                state = state,
                                canGenerate = canGenerate,
                                onGenerate = onGenerate,
                                onReplay = onReplay,
                                onStop = onStop,
                                onCancel = onCancel
                            )
                            PresetNameField(
                                value = presetName,
                                onValueChange = onPresetNameChange,
                                modifier = Modifier.fillMaxWidth()
                            )
                            SaveVoiceButton(
                                label = saveLabel,
                                isSaving = isSaving,
                                enabled = canSave,
                                onClick = onSave
                            )
                        }
                    }
                }
            }

            compatibilityMessage?.let {
                Text(it, color = MaterialTheme.colorScheme.error, style = MaterialTheme.typography.bodySmall)
            }
            state.error?.let {
                Text(it, color = MaterialTheme.colorScheme.error, style = MaterialTheme.typography.bodySmall)
            }
            if (state.hasAudio && state.waveform.isNotEmpty()) {
                PreviewWaveform(state.waveform, state.durationSeconds, state.isPlaying)
            }
        }
    }
}

@Composable
private fun PreviewSentenceField(
    value: String,
    onValueChange: (String) -> Unit,
    modifier: Modifier
) {
    OutlinedTextField(
        value = value,
        onValueChange = onValueChange,
        modifier = modifier,
        label = { Text("Preview sentence") },
        singleLine = true
    )
}

@Composable
private fun PresetNameField(
    value: String,
    onValueChange: (String) -> Unit,
    modifier: Modifier
) {
    OutlinedTextField(
        value = value,
        onValueChange = onValueChange,
        modifier = modifier,
        label = { Text("Preset name (optional)") },
        singleLine = true
    )
}

@Composable
private fun PreviewTransportButtons(
    state: VoiceLabPreviewState,
    canGenerate: Boolean,
    onGenerate: () -> Unit,
    onReplay: () -> Unit,
    onStop: () -> Unit,
    onCancel: () -> Unit
) {
    Row(horizontalArrangement = Arrangement.spacedBy(8.dp), verticalAlignment = Alignment.CenterVertically) {
        Button(onClick = onGenerate, enabled = canGenerate && !state.isGenerating) {
            if (state.isGenerating) {
                CircularProgressIndicator(
                    modifier = Modifier.size(17.dp),
                    strokeWidth = 2.dp,
                    color = MaterialTheme.colorScheme.onPrimary
                )
            } else {
                Icon(Icons.Default.PlayArrow, contentDescription = null)
            }
            Spacer(Modifier.width(6.dp))
            Text(if (state.isGenerating) "Generating…" else "Preview")
        }
        when {
            state.isGenerating -> {
                OutlinedButton(onClick = onCancel) {
                    Icon(Icons.Default.Stop, contentDescription = null)
                    Spacer(Modifier.width(5.dp))
                    Text("Cancel")
                }
            }
            state.isPlaying -> {
                OutlinedButton(onClick = onStop) {
                    Icon(Icons.Default.Stop, contentDescription = null)
                    Spacer(Modifier.width(5.dp))
                    Text("Stop")
                }
            }
            state.hasAudio -> {
                OutlinedButton(onClick = onReplay) {
                    Icon(Icons.Default.Replay, contentDescription = null)
                    Spacer(Modifier.width(5.dp))
                    Text("Replay")
                }
            }
        }
    }
}

@Composable
private fun SaveVoiceButton(
    label: String,
    isSaving: Boolean,
    enabled: Boolean,
    onClick: () -> Unit
) {
    Button(onClick = onClick, enabled = enabled && !isSaving) {
        if (isSaving) {
            CircularProgressIndicator(
                modifier = Modifier.size(17.dp),
                strokeWidth = 2.dp,
                color = MaterialTheme.colorScheme.onPrimary
            )
        } else {
            Icon(Icons.Default.Save, contentDescription = null)
        }
        Spacer(Modifier.width(6.dp))
        Text(if (isSaving) "Saving…" else label)
    }
}

@Composable
private fun PreviewLanguageDropdown(
    selected: String,
    onSelected: (String) -> Unit,
    modifier: Modifier = Modifier
) {
    val languages = remember {
        listOf("English", "German", "French", "Spanish", "Chinese", "Japanese", "Korean", "Russian", "Italian", "Portuguese")
    }
    var expanded by remember { mutableStateOf(false) }
    Box(modifier = modifier) {
        OutlinedCard(
            onClick = { expanded = true },
            modifier = Modifier.fillMaxWidth().semantics {
                contentDescription = "Preview language: $selected"
            }
        ) {
            Row(
                modifier = Modifier.padding(horizontal = 12.dp, vertical = 10.dp),
                verticalAlignment = Alignment.CenterVertically
            ) {
                Text(selected, modifier = Modifier.weight(1f), style = MaterialTheme.typography.bodyMedium)
                Icon(Icons.Default.ArrowDropDown, contentDescription = null)
            }
        }
        DropdownMenu(expanded = expanded, onDismissRequest = { expanded = false }) {
            languages.forEach { language ->
                DropdownMenuItem(
                    text = { Text(language) },
                    onClick = {
                        onSelected(language)
                        expanded = false
                    }
                )
            }
        }
    }
}

@Composable
private fun PreviewWaveform(waveform: List<Float>, durationSeconds: Float, isPlaying: Boolean) {
    val color = if (isPlaying) MaterialTheme.colorScheme.primary else MaterialTheme.colorScheme.onSurfaceVariant
    val centerLineColor = MaterialTheme.colorScheme.outlineVariant
    Column(verticalArrangement = Arrangement.spacedBy(3.dp)) {
        Canvas(
            modifier = Modifier
                .fillMaxWidth()
                .height(44.dp)
                .semantics {
                    contentDescription =
                        "Amplitude envelope of the generated ${formatNumber(durationSeconds.toDouble(), 1)} second preview"
                }
        ) {
            val centerY = size.height / 2f
            drawLine(centerLineColor, Offset(0f, centerY), Offset(size.width, centerY))
            val step = size.width / waveform.size
            waveform.forEachIndexed { index, peak ->
                val halfHeight = peak.coerceIn(0f, 1f) * size.height * 0.46f
                val x = (index + 0.5f) * step
                drawLine(
                    color,
                    Offset(x, centerY - halfHeight),
                    Offset(x, centerY + halfHeight),
                    strokeWidth = max(1f, step * 0.55f)
                )
            }
        }
        Text(
            "Generated audio · ${formatNumber(durationSeconds.toDouble(), 1)} s",
            style = MaterialTheme.typography.labelSmall,
            color = MaterialTheme.colorScheme.onSurfaceVariant
        )
    }
}

private fun formatNumber(value: Double, decimals: Int): String =
    String.format(Locale.ROOT, "%.${decimals}f", value)
