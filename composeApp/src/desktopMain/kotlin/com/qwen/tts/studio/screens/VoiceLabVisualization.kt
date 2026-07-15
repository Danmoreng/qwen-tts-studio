package com.qwen.tts.studio.screens

import androidx.compose.foundation.Canvas
import androidx.compose.foundation.horizontalScroll
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.FlowRow
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.rememberScrollState
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowDropDown
import androidx.compose.material.icons.filled.GraphicEq
import androidx.compose.material.icons.filled.PlayArrow
import androidx.compose.material.icons.filled.Replay
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
import androidx.compose.material3.Surface
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
import androidx.compose.ui.graphics.Path
import androidx.compose.ui.graphics.PathEffect
import androidx.compose.ui.graphics.drawscope.Stroke
import androidx.compose.ui.semantics.contentDescription
import androidx.compose.ui.semantics.semantics
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.dp
import com.qwen.tts.studio.embedding.EmbeddingPoint2D
import com.qwen.tts.studio.embedding.MorphDifferenceBin
import com.qwen.tts.studio.embedding.MorphEmbeddingAnalysis
import com.qwen.tts.studio.viewmodel.VoiceLabPreviewState
import java.util.Locale
import kotlin.math.max
import kotlin.math.min

@Composable
internal fun MorphEmbeddingVisualization(
    sourceName: String,
    targetName: String,
    availableDimensions: List<Int>,
    selectedDimension: Int,
    onDimensionSelected: (Int) -> Unit,
    analysis: MorphEmbeddingAnalysis?,
    isLoading: Boolean,
    error: String?
) {
    Card(
        modifier = Modifier.fillMaxWidth(),
        colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surfaceVariant.copy(alpha = 0.35f))
    ) {
        Column(
            modifier = Modifier.padding(16.dp),
            verticalArrangement = Arrangement.spacedBy(12.dp)
        ) {
            Row(
                modifier = Modifier.fillMaxWidth(),
                verticalAlignment = Alignment.CenterVertically,
                horizontalArrangement = Arrangement.spacedBy(12.dp)
            ) {
                Icon(Icons.Default.GraphicEq, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                Column(modifier = Modifier.weight(1f)) {
                    Text("Embedding geometry", style = MaterialTheme.typography.titleSmall, fontWeight = FontWeight.SemiBold)
                    Text(
                        "Exact local geometry of this morph — not a waveform or frequency plot.",
                        style = MaterialTheme.typography.bodySmall,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )
                }
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
                        modifier = Modifier.fillMaxWidth().padding(vertical = 32.dp),
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
                    EmbeddingPathPlot(
                        analysis = analysis,
                        sourceName = sourceName,
                        targetName = targetName
                    )
                    GeometryMetrics(analysis)
                    DifferenceBins(
                        bins = analysis.differenceBins,
                        sourceName = sourceName,
                        targetName = targetName
                    )
                }
            }
        }
    }
}

@Composable
private fun EmbeddingPathPlot(
    analysis: MorphEmbeddingAnalysis,
    sourceName: String,
    targetName: String
) {
    val sourceColor = MaterialTheme.colorScheme.primary
    val targetColor = MaterialTheme.colorScheme.tertiary
    val mixColor = MaterialTheme.colorScheme.secondary
    val gridColor = MaterialTheme.colorScheme.outlineVariant
    val rawPathColor = MaterialTheme.colorScheme.onSurfaceVariant
    val surfaceColor = MaterialTheme.colorScheme.surface

    Text(
        "Vertical axis: orthogonal deviation introduced by norm matching",
        style = MaterialTheme.typography.labelSmall,
        color = MaterialTheme.colorScheme.onSurfaceVariant
    )

    Canvas(
        modifier = Modifier
            .fillMaxWidth()
            .height(230.dp)
            .semantics {
                contentDescription =
                    "Local two-dimensional embedding plane with $sourceName, current mix, and $targetName. " +
                        "Axes use embedding units and are not acoustic frequencies."
            }
    ) {
        val plotPadding = 22.dp.toPx()
        val plotWidth = (size.width - 2f * plotPadding).coerceAtLeast(1f)
        val plotHeight = (size.height - 2f * plotPadding).coerceAtLeast(1f)
        val allPoints = analysis.actualPathSegments.flatten() + analysis.source + analysis.target + analysis.mixed
        val rawMinX = allPoints.minOf { it.x }
        val rawMaxX = allPoints.maxOf { it.x }
        val rawMinY = allPoints.minOf { it.y }
        val rawMaxY = allPoints.maxOf { it.y }
        val xCenter = (rawMinX + rawMaxX) / 2.0
        val yCenter = (rawMinY + rawMaxY) / 2.0
        val xSpan = max(rawMaxX - rawMinX, 1e-9)
        val ySpan = max(rawMaxY - rawMinY, xSpan * 0.22)
        val paddedXSpan = xSpan * 1.18
        val paddedYSpan = ySpan * 1.18
        val scale = min(plotWidth / paddedXSpan.toFloat(), plotHeight / paddedYSpan.toFloat())

        fun map(point: EmbeddingPoint2D): Offset = Offset(
            x = size.width / 2f + ((point.x - xCenter) * scale).toFloat(),
            y = size.height / 2f - ((point.y - yCenter) * scale).toFloat()
        )

        for (step in 0..4) {
            val fraction = step / 4f
            val x = plotPadding + plotWidth * fraction
            val y = plotPadding + plotHeight * fraction
            drawLine(gridColor, Offset(x, plotPadding), Offset(x, size.height - plotPadding), strokeWidth = 1f)
            drawLine(gridColor, Offset(plotPadding, y), Offset(size.width - plotPadding, y), strokeWidth = 1f)
        }

        drawLine(
            color = rawPathColor,
            start = map(analysis.source),
            end = map(analysis.target),
            strokeWidth = 2.dp.toPx(),
            pathEffect = PathEffect.dashPathEffect(floatArrayOf(8.dp.toPx(), 6.dp.toPx()))
        )

        analysis.actualPathSegments.forEach { segment ->
            val path = Path()
            segment.forEachIndexed { index, point ->
                val mapped = map(point)
                if (index == 0) path.moveTo(mapped.x, mapped.y) else path.lineTo(mapped.x, mapped.y)
            }
            drawPath(path, color = mixColor, style = Stroke(width = 3.dp.toPx()))
        }

        val sourceCenter = map(analysis.source)
        val targetCenter = map(analysis.target)
        val mixedCenter = map(analysis.mixed)
        val targetRadius = 7.dp.toPx()
        val mixedRadius = 9.dp.toPx()

        drawCircle(sourceColor, radius = 7.dp.toPx(), center = sourceCenter)
        drawRect(
            color = targetColor,
            topLeft = Offset(targetCenter.x - targetRadius, targetCenter.y - targetRadius),
            size = androidx.compose.ui.geometry.Size(targetRadius * 2f, targetRadius * 2f)
        )
        val mixedMarker = Path().apply {
            moveTo(mixedCenter.x, mixedCenter.y - mixedRadius)
            lineTo(mixedCenter.x + mixedRadius, mixedCenter.y)
            lineTo(mixedCenter.x, mixedCenter.y + mixedRadius)
            lineTo(mixedCenter.x - mixedRadius, mixedCenter.y)
            close()
        }
        drawPath(mixedMarker, color = mixColor)
        drawCircle(
            color = surfaceColor,
            radius = 4.dp.toPx(),
            center = mixedCenter
        )
    }

    Text(
        "Horizontal axis: A → B direction (embedding units)",
        modifier = Modifier.fillMaxWidth(),
        textAlign = TextAlign.Center,
        style = MaterialTheme.typography.labelSmall,
        color = MaterialTheme.colorScheme.onSurfaceVariant
    )

    Row(
        modifier = Modifier.fillMaxWidth().horizontalScroll(rememberScrollState()),
        horizontalArrangement = Arrangement.spacedBy(16.dp),
        verticalAlignment = Alignment.CenterVertically
    ) {
        PlotLegendItem(sourceColor, PlotMarker.Circle, sourceName)
        PlotLegendItem(mixColor, PlotMarker.Diamond, "Current mix")
        PlotLegendItem(targetColor, PlotMarker.Square, targetName)
        Text("Dashed: raw linear path", style = MaterialTheme.typography.labelSmall, color = MaterialTheme.colorScheme.onSurfaceVariant)
    }
    Text(
        "Both axes use the same scale. Norm matching can bend the solid path away from the raw A→B line.",
        style = MaterialTheme.typography.bodySmall,
        color = MaterialTheme.colorScheme.onSurfaceVariant
    )
}

private enum class PlotMarker {
    Circle,
    Diamond,
    Square
}

@Composable
private fun PlotLegendItem(color: Color, marker: PlotMarker, label: String) {
    Row(verticalAlignment = Alignment.CenterVertically, horizontalArrangement = Arrangement.spacedBy(6.dp)) {
        Canvas(Modifier.size(10.dp)) {
            when (marker) {
                PlotMarker.Circle -> drawCircle(color)
                PlotMarker.Square -> drawRect(color)
                PlotMarker.Diamond -> {
                    val markerPath = Path().apply {
                        moveTo(size.width / 2f, 0f)
                        lineTo(size.width, size.height / 2f)
                        lineTo(size.width / 2f, size.height)
                        lineTo(0f, size.height / 2f)
                        close()
                    }
                    drawPath(markerPath, color)
                }
            }
        }
        Text(label, style = MaterialTheme.typography.labelSmall, maxLines = 1, overflow = TextOverflow.Ellipsis)
    }
}

@Composable
private fun GeometryMetrics(analysis: MorphEmbeddingAnalysis) {
    Row(
        modifier = Modifier.fillMaxWidth().horizontalScroll(rememberScrollState()),
        horizontalArrangement = Arrangement.spacedBy(10.dp)
    ) {
        Metric("Cosine A↔B", analysis.cosineSimilarity?.let { formatNumber(it, 4) } ?: "n/a")
        Metric("Angle", analysis.angleDegrees?.let { "${formatNumber(it, 1)}°" } ?: "n/a")
        Metric("L2 distance", formatNumber(analysis.sourceDistance, 3))
        Metric(
            "Symmetric relative L2",
            analysis.symmetricRelativeSourceDistance?.let { formatNumber(it, 3) } ?: "n/a"
        )
        Metric("Norm A / Mix / B", "${formatNumber(analysis.sourceNorm, 2)} / ${formatNumber(analysis.mixedNorm, 2)} / ${formatNumber(analysis.targetNorm, 2)}")
    }
    Text(
        "Symmetric relative L2 = 2·‖A−B‖₂ / (‖A‖₂+‖B‖₂). These diagnostics are not perceptual scores.",
        style = MaterialTheme.typography.bodySmall,
        color = MaterialTheme.colorScheme.onSurfaceVariant
    )
}

@Composable
private fun Metric(label: String, value: String) {
    Surface(color = MaterialTheme.colorScheme.surface, shape = MaterialTheme.shapes.small) {
        Column(modifier = Modifier.padding(horizontal = 10.dp, vertical = 7.dp)) {
            Text(label, style = MaterialTheme.typography.labelSmall, color = MaterialTheme.colorScheme.onSurfaceVariant)
            Text(value, style = MaterialTheme.typography.labelLarge, fontWeight = FontWeight.SemiBold)
        }
    }
}

@Composable
private fun DifferenceBins(
    bins: List<MorphDifferenceBin>,
    sourceName: String,
    targetName: String
) {
    if (bins.isEmpty()) return
    val sourceTargetColor = MaterialTheme.colorScheme.onSurfaceVariant
    val sourceMixColor = MaterialTheme.colorScheme.primary
    val mixTargetColor = MaterialTheme.colorScheme.tertiary
    val maximum = bins.maxOf { bin ->
        max(bin.sourceToTargetRms, max(bin.sourceToMixRms, bin.mixToTargetRms))
    }.coerceAtLeast(1e-12)

    Column(verticalArrangement = Arrangement.spacedBy(6.dp)) {
        Text("Latent-coordinate differences", style = MaterialTheme.typography.labelLarge, fontWeight = FontWeight.SemiBold)
        DifferenceBinRow("$sourceName ↔ $targetName", bins.map { it.sourceToTargetRms }, maximum, sourceTargetColor)
        DifferenceBinRow("$sourceName ↔ Mix", bins.map { it.sourceToMixRms }, maximum, sourceMixColor)
        DifferenceBinRow("Mix ↔ $targetName", bins.map { it.mixToTargetRms }, maximum, mixTargetColor)
        Text(
            "Each bar is RMS difference within an arbitrary block of latent coordinates. The blocks are not Hz bands.",
            style = MaterialTheme.typography.bodySmall,
            color = MaterialTheme.colorScheme.onSurfaceVariant
        )
    }
}

@Composable
private fun DifferenceBinRow(
    label: String,
    values: List<Double>,
    maximum: Double,
    color: Color
) {
    Column(verticalArrangement = Arrangement.spacedBy(3.dp)) {
        Text(label, style = MaterialTheme.typography.labelSmall, maxLines = 1, overflow = TextOverflow.Ellipsis)
        Canvas(
            modifier = Modifier
                .fillMaxWidth()
                .height(34.dp)
                .semantics { contentDescription = "$label across ${values.size} latent-coordinate bins" }
        ) {
            val gap = 1.dp.toPx()
            val barWidth = (size.width / values.size - gap).coerceAtLeast(1f)
            values.forEachIndexed { index, value ->
                val height = (value / maximum).toFloat().coerceIn(0f, 1f) * size.height
                drawRect(
                    color = color,
                    topLeft = Offset(index * size.width / values.size, size.height - height),
                    size = androidx.compose.ui.geometry.Size(barWidth, height)
                )
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
    state: VoiceLabPreviewState,
    selectedModelName: String?,
    selectedEmbeddingDimension: Int?,
    compatibilityMessage: String?,
    canGenerate: Boolean,
    onGenerate: () -> Unit,
    onReplay: () -> Unit,
    onStop: () -> Unit,
    onCancel: () -> Unit
) {
    Card(
        modifier = Modifier.fillMaxWidth(),
        colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surfaceVariant.copy(alpha = 0.35f))
    ) {
        Column(
            modifier = Modifier.padding(16.dp),
            verticalArrangement = Arrangement.spacedBy(12.dp)
        ) {
            Column(verticalArrangement = Arrangement.spacedBy(2.dp)) {
                Text("Listen before saving", style = MaterialTheme.typography.titleSmall, fontWeight = FontWeight.SemiBold)
                Text(
                    "Preview creates a temporary embedding, synthesizes this sentence, then deletes the temporary file.",
                    style = MaterialTheme.typography.bodySmall,
                    color = MaterialTheme.colorScheme.onSurfaceVariant
                )
            }

            OutlinedTextField(
                value = previewText,
                onValueChange = onPreviewTextChange,
                modifier = Modifier.fillMaxWidth(),
                label = { Text("Preview sentence") },
                supportingText = { Text("${previewText.length} / 500") },
                minLines = 2,
                maxLines = 4
            )

            Text("Preview language", style = MaterialTheme.typography.labelMedium)
            FlowRow(
                modifier = Modifier.fillMaxWidth(),
                horizontalArrangement = Arrangement.spacedBy(10.dp),
                verticalArrangement = Arrangement.spacedBy(10.dp)
            ) {
                PreviewLanguageDropdown(
                    selected = language,
                    onSelected = onLanguageChange,
                    modifier = Modifier.width(180.dp)
                )
                Button(
                    onClick = onGenerate,
                    enabled = canGenerate && !state.isGenerating
                ) {
                    if (state.isGenerating) {
                        CircularProgressIndicator(
                            modifier = Modifier.size(17.dp),
                            strokeWidth = 2.dp,
                            color = MaterialTheme.colorScheme.onPrimary
                        )
                    } else {
                        Icon(Icons.Default.PlayArrow, contentDescription = null)
                    }
                    Spacer(Modifier.width(7.dp))
                    Text(if (state.isGenerating) "Generating…" else "Generate preview")
                }
                if (state.isGenerating) {
                    OutlinedButton(onClick = onCancel) {
                        Icon(Icons.Default.Stop, contentDescription = null)
                        Spacer(Modifier.width(6.dp))
                        Text("Cancel")
                    }
                } else if (state.isPlaying) {
                    OutlinedButton(onClick = onStop) {
                        Icon(Icons.Default.Stop, contentDescription = null)
                        Spacer(Modifier.width(6.dp))
                        Text("Stop")
                    }
                } else if (state.hasAudio) {
                    OutlinedButton(onClick = onReplay) {
                        Icon(Icons.Default.Replay, contentDescription = null)
                        Spacer(Modifier.width(6.dp))
                        Text("Replay")
                    }
                }
            }

            Text(
                buildString {
                    append("Model: ")
                    append(selectedModelName?.takeIf { it.isNotBlank() } ?: "not selected")
                    selectedEmbeddingDimension?.let { append(" · D$it") }
                },
                style = MaterialTheme.typography.bodySmall,
                color = MaterialTheme.colorScheme.onSurfaceVariant,
                maxLines = 1,
                overflow = TextOverflow.Ellipsis
            )

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
    Column(verticalArrangement = Arrangement.spacedBy(4.dp)) {
        Canvas(
            modifier = Modifier
                .fillMaxWidth()
                .height(58.dp)
                .semantics { contentDescription = "Amplitude envelope of the generated ${formatNumber(durationSeconds.toDouble(), 1)} second preview" }
        ) {
            val centerY = size.height / 2f
            drawLine(centerLineColor, Offset(0f, centerY), Offset(size.width, centerY))
            val step = size.width / waveform.size
            waveform.forEachIndexed { index, peak ->
                val halfHeight = peak.coerceIn(0f, 1f) * size.height * 0.46f
                val x = (index + 0.5f) * step
                drawLine(color, Offset(x, centerY - halfHeight), Offset(x, centerY + halfHeight), strokeWidth = max(1f, step * 0.55f))
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
