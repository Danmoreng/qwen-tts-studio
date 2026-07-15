package com.qwen.tts.studio.screens

import androidx.compose.foundation.BorderStroke
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.horizontalScroll
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowDropDown
import androidx.compose.material.icons.filled.Error
import androidx.compose.material.icons.filled.Science
import androidx.compose.material.icons.filled.Tune
import androidx.compose.material.icons.filled.WarningAmber
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
import androidx.compose.material3.Slider
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
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
import com.qwen.tts.studio.embedding.EmbeddingVisualization
import com.qwen.tts.studio.viewmodel.EmbeddingBlendSource
import com.qwen.tts.studio.viewmodel.LoadedVoiceEmbedding
import com.qwen.tts.studio.viewmodel.SettingsViewModel
import com.qwen.tts.studio.viewmodel.VoiceLabRecipe
import com.qwen.tts.studio.viewmodel.VoicePreset
import com.qwen.tts.studio.viewmodel.VoicesViewModel
import kotlin.math.roundToInt

internal enum class VoiceLabMode {
    Morph,
    Average
}

internal class VoiceLabSessionState {
    internal val modeState = mutableStateOf(VoiceLabMode.Morph)
    internal val presetNameState = mutableStateOf("")
    internal val mixLeftIdState = mutableStateOf("")
    internal val mixRightIdState = mutableStateOf("")
    internal val mixAmountState = mutableStateOf(0.5f)
    internal val averageSelectionState = mutableStateOf(setOf<String>())
    internal val normalizeState = mutableStateOf(true)
    internal val visualizationDimensionState = mutableStateOf(0)
    internal val previewTextState = mutableStateOf("This sentence previews the voice currently being mixed.")
    internal val previewLanguageState = mutableStateOf("English")
    internal val clearPresetNameOnSuccessState = mutableStateOf(false)
}

@Composable
internal fun rememberVoiceLabSessionState(): VoiceLabSessionState = remember {
    VoiceLabSessionState()
}

@Composable
internal fun VoiceLabScreen(
    viewModel: VoicesViewModel,
    settingsViewModel: SettingsViewModel,
    sessionState: VoiceLabSessionState
) {
    val voices by viewModel.voices.collectAsState()
    val isCreating by viewModel.isCreating.collectAsState()
    val error by viewModel.error.collectAsState()
    val previewState by viewModel.voiceLabPreviewState.collectAsState()
    val currentEmbeddingDimension by viewModel.currentEmbeddingDim.collectAsState()
    val modelDir by settingsViewModel.modelDir.collectAsState()
    val modelName by settingsViewModel.modelName.collectAsState()
    val backendPreference by settingsViewModel.backendPreference.collectAsState()
    val customVoices = voices.filter { !it.isSystem && it.speakerEmbeddings.isNotEmpty() }

    var mode by sessionState.modeState
    var presetName by sessionState.presetNameState
    var mixLeftId by sessionState.mixLeftIdState
    var mixRightId by sessionState.mixRightIdState
    var mixAmount by sessionState.mixAmountState
    var averageSelection by sessionState.averageSelectionState
    var normalize by sessionState.normalizeState
    var visualizationDimension by sessionState.visualizationDimensionState
    var previewText by sessionState.previewTextState
    var previewLanguage by sessionState.previewLanguageState
    var clearPresetNameOnSuccess by sessionState.clearPresetNameOnSuccessState
    var morphEmbeddings by remember { mutableStateOf<List<LoadedVoiceEmbedding>>(emptyList()) }
    var morphVisualizationError by remember { mutableStateOf<String?>(null) }
    var isMorphVisualizationLoading by remember { mutableStateOf(false) }

    LaunchedEffect(customVoices) {
        val ids = customVoices.map { it.id }
        if (mixLeftId !in ids) mixLeftId = ids.firstOrNull().orEmpty()
        if (mixRightId !in ids || mixRightId == mixLeftId) {
            mixRightId = ids.firstOrNull { it != mixLeftId }.orEmpty()
        }
        averageSelection = averageSelection.filterTo(mutableSetOf()) { it in ids }
    }

    val selectedIds = when (mode) {
        VoiceLabMode.Morph -> listOf(mixLeftId, mixRightId)
        VoiceLabMode.Average -> averageSelection.toList()
    }.filter { it.isNotBlank() }

    val outputDims = commonEmbeddingDims(customVoices, selectedIds)
    val selectionReady = when (mode) {
        VoiceLabMode.Morph ->
            mixLeftId.isNotBlank() && mixRightId.isNotBlank() && mixLeftId != mixRightId
        VoiceLabMode.Average -> averageSelection.size >= 2
    }
    val canCreate = outputDims.isNotEmpty() && selectionReady
    val requiredPreviewDimension = when {
        modelName.contains("1.7b", ignoreCase = true) -> 2048
        modelName.contains("0.6b", ignoreCase = true) -> 1024
        currentEmbeddingDimension == 1024 || currentEmbeddingDimension == 2048 -> currentEmbeddingDimension
        else -> 0
    }
    val selectedModelIsKnownNonBase = modelName.contains("customvoice", ignoreCase = true) ||
        modelName.contains("voicedesign", ignoreCase = true)
    val previewCompatibilityMessage = when {
        selectedModelIsKnownNonBase -> "Voice Lab preview requires a Qwen3-TTS Base model."
        selectionReady && requiredPreviewDimension > 0 && requiredPreviewDimension !in outputDims ->
            "The selected model needs D$requiredPreviewDimension, which these voices do not share."
        else -> null
    }
    val visualizationDimensions = if (requiredPreviewDimension in outputDims) {
        listOf(requiredPreviewDimension)
    } else {
        outputDims
    }

    val currentRecipe: VoiceLabRecipe = when (mode) {
        VoiceLabMode.Morph -> VoiceLabRecipe.WeightedMean(
            sources = listOf(
                EmbeddingBlendSource(mixLeftId, 1f - mixAmount),
                EmbeddingBlendSource(mixRightId, mixAmount)
            ),
            normalize = normalize
        )
        VoiceLabMode.Average -> VoiceLabRecipe.WeightedMean(
            sources = averageSelection.sorted().map { EmbeddingBlendSource(it, 1f) },
            normalize = normalize
        )
    }

    LaunchedEffect(outputDims, currentEmbeddingDimension, modelName) {
        if (outputDims.isEmpty()) {
            visualizationDimension = 0
        } else if (
            visualizationDimension !in outputDims ||
            (requiredPreviewDimension in outputDims && visualizationDimension != requiredPreviewDimension)
        ) {
            val inferredDimension = when {
                requiredPreviewDimension in outputDims -> requiredPreviewDimension
                currentEmbeddingDimension in outputDims -> currentEmbeddingDimension
                else -> outputDims.first()
            }
            visualizationDimension = inferredDimension
        }
    }

    LaunchedEffect(mode, mixLeftId, mixRightId, visualizationDimension, voices) {
        if (
            mode != VoiceLabMode.Morph ||
            mixLeftId.isBlank() ||
            mixRightId.isBlank() ||
            mixLeftId == mixRightId ||
            visualizationDimension !in outputDims
        ) {
            morphEmbeddings = emptyList()
            morphVisualizationError = null
            isMorphVisualizationLoading = false
            return@LaunchedEffect
        }

        isMorphVisualizationLoading = true
        morphVisualizationError = null
        viewModel.loadVoiceLabEmbeddings(
            voiceIds = listOf(mixLeftId, mixRightId),
            dimension = visualizationDimension
        ).fold(
            onSuccess = { morphEmbeddings = it },
            onFailure = {
                morphEmbeddings = emptyList()
                morphVisualizationError = it.message ?: "Could not load the selected embedding vectors."
            }
        )
        isMorphVisualizationLoading = false
    }

    val morphAnalysisResult = remember(
        mode,
        morphEmbeddings,
        mixAmount,
        normalize,
        visualizationDimension
    ) {
        runCatching {
            if (mode != VoiceLabMode.Morph || morphEmbeddings.size != 2) return@runCatching null
            EmbeddingVisualization.analyzeMorph(
                source = morphEmbeddings[0].values,
                target = morphEmbeddings[1].values,
                amount = mixAmount,
                preserveAverageNorm = normalize,
                pathSampleCount = 2
            )
        }
    }
    val morphAnalysis = morphAnalysisResult.getOrNull()
    val displayedMorphError = morphVisualizationError
        ?: morphAnalysisResult.exceptionOrNull()?.message

    LaunchedEffect(currentRecipe, previewText, previewLanguage, modelDir, modelName, backendPreference) {
        viewModel.invalidateVoiceLabPreview()
    }

    DisposableEffect(viewModel) {
        onDispose { viewModel.invalidateVoiceLabPreview() }
    }

    LaunchedEffect(isCreating, error, clearPresetNameOnSuccess) {
        if (clearPresetNameOnSuccess && !isCreating) {
            if (error == null) presetName = ""
            clearPresetNameOnSuccess = false
        }
    }

    val saveLabel = when (mode) {
        VoiceLabMode.Morph -> "Save voice"
        VoiceLabMode.Average -> "Save average"
    }
    val savePreset: () -> Unit = {
        val nameToUse = presetName.ifBlank {
            when (mode) {
                VoiceLabMode.Morph -> "Morphed Voice"
                VoiceLabMode.Average -> "Averaged Voice"
            }
        }

        when (mode) {
            VoiceLabMode.Morph -> viewModel.createMixedVoicePreset(
                name = nameToUse,
                sources = listOf(
                    EmbeddingBlendSource(mixLeftId, 1f - mixAmount),
                    EmbeddingBlendSource(mixRightId, mixAmount)
                ),
                normalize = normalize
            )
            VoiceLabMode.Average -> viewModel.createMixedVoicePreset(
                name = nameToUse,
                sources = averageSelection
                    .sorted()
                    .map { EmbeddingBlendSource(it, 1f) },
                normalize = normalize
            )
        }
        clearPresetNameOnSuccess = true
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .verticalScroll(rememberScrollState())
            .padding(24.dp),
        verticalArrangement = Arrangement.spacedBy(16.dp)
    ) {
        error?.let { ErrorBanner(it) }

        Card(
            modifier = Modifier.fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surface),
            border = BorderStroke(1.dp, MaterialTheme.colorScheme.outlineVariant)
        ) {
            Column(
                modifier = Modifier.padding(20.dp),
                verticalArrangement = Arrangement.spacedBy(16.dp)
            ) {
                Row(
                    verticalAlignment = Alignment.CenterVertically,
                    horizontalArrangement = Arrangement.spacedBy(12.dp)
                ) {
                    Icon(Icons.Default.Tune, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
                    Column(modifier = Modifier.weight(1f)) {
                        Text(
                            "Embedding Workbench",
                            style = MaterialTheme.typography.titleMedium,
                            fontWeight = FontWeight.SemiBold
                        )
                        Text(
                            "Create reusable voices with dimension-checked vector arithmetic.",
                            style = MaterialTheme.typography.bodySmall,
                            color = MaterialTheme.colorScheme.onSurfaceVariant
                        )
                    }
                    DimensionBadge(outputDims, selectionReady)
                }

                if (customVoices.size < 2) {
                    EmptyLabState(customVoices.size)
                }

                Row(
                    modifier = Modifier.fillMaxWidth().horizontalScroll(rememberScrollState()),
                    horizontalArrangement = Arrangement.spacedBy(8.dp),
                    verticalAlignment = Alignment.CenterVertically
                ) {
                    ModeButton("Morph", mode == VoiceLabMode.Morph) { mode = VoiceLabMode.Morph }
                    ModeButton("Average", mode == VoiceLabMode.Average) { mode = VoiceLabMode.Average }
                }

                if (mode != VoiceLabMode.Morph) MethodNotice(mode)

                when (mode) {
                    VoiceLabMode.Morph -> {
                        Row(
                            horizontalArrangement = Arrangement.spacedBy(12.dp),
                            verticalAlignment = Alignment.CenterVertically
                        ) {
                            LabeledVoiceDropdown(
                                label = "Voice A",
                                voices = customVoices,
                                selectedId = mixLeftId,
                                onSelected = { selected ->
                                    mixLeftId = selected
                                    if (mixRightId == selected) {
                                        mixRightId = customVoices.firstOrNull { it.id != selected }?.id.orEmpty()
                                    }
                                },
                                modifier = Modifier.weight(1f)
                            )
                            LabeledVoiceDropdown(
                                label = "Voice B",
                                voices = customVoices,
                                selectedId = mixRightId,
                                onSelected = { selected ->
                                    mixRightId = selected
                                    if (mixLeftId == selected) {
                                        mixLeftId = customVoices.firstOrNull { it.id != selected }?.id.orEmpty()
                                    }
                                },
                                modifier = Modifier.weight(1f)
                            )
                        }
                        Row(
                            verticalAlignment = Alignment.CenterVertically,
                            horizontalArrangement = Arrangement.spacedBy(12.dp)
                        ) {
                            Text(
                                "${((1f - mixAmount) * 100).roundToInt()}% A",
                                style = MaterialTheme.typography.labelMedium
                            )
                            Slider(
                                value = mixAmount,
                                onValueChange = { mixAmount = it },
                                modifier = Modifier.weight(1f),
                                enabled = customVoices.size >= 2,
                                steps = 19
                            )
                            Text(
                                "${(mixAmount * 100).roundToInt()}% B",
                                style = MaterialTheme.typography.labelMedium
                            )
                        }
                    }

                    VoiceLabMode.Average -> {
                        Text(
                            "Select two or more embeddings. Equal weights are used.",
                            style = MaterialTheme.typography.labelLarge
                        )
                        Column(verticalArrangement = Arrangement.spacedBy(8.dp)) {
                            customVoices.forEach { voice ->
                                VoiceCheckRow(
                                    voice = voice,
                                    checked = voice.id in averageSelection,
                                    onCheckedChange = { checked ->
                                        averageSelection = if (checked) {
                                            averageSelection + voice.id
                                        } else {
                                            averageSelection - voice.id
                                        }
                                    }
                                )
                            }
                        }
                    }

                }

                if (selectedIds.distinct().size >= 2 && outputDims.isEmpty()) {
                    WarningBanner(
                        "The selected presets do not share D1024 or D2048. Only embeddings from the same " +
                            "Base checkpoint should be combined."
                    )
                }

                if (mode != VoiceLabMode.Morph) {
                    Row(
                        modifier = Modifier.fillMaxWidth(),
                        verticalAlignment = Alignment.CenterVertically,
                        horizontalArrangement = Arrangement.spacedBy(8.dp)
                    ) {
                        Checkbox(checked = normalize, onCheckedChange = { normalize = it })
                        Column(modifier = Modifier.weight(1f)) {
                            Text(
                                "Match the weighted mean of source norms",
                                style = MaterialTheme.typography.bodyMedium
                            )
                            Text(
                                "Optional norm-stability heuristic; it does not guarantee a natural result.",
                                style = MaterialTheme.typography.bodySmall,
                                color = MaterialTheme.colorScheme.onSurfaceVariant
                            )
                        }
                    }
                }

                if (mode == VoiceLabMode.Morph && selectionReady && outputDims.isNotEmpty()) {
                    MorphEmbeddingVisualization(
                        sourceName = voiceName(customVoices, mixLeftId),
                        targetName = voiceName(customVoices, mixRightId),
                        availableDimensions = visualizationDimensions,
                        selectedDimension = visualizationDimension,
                        onDimensionSelected = { visualizationDimension = it },
                        preserveAverageNorm = normalize,
                        onPreserveAverageNormChange = { normalize = it },
                        analysis = morphAnalysis,
                        isLoading = isMorphVisualizationLoading,
                        error = displayedMorphError
                    )
                }

                VoiceLabPreviewPanel(
                    previewText = previewText,
                    onPreviewTextChange = { previewText = it.take(500) },
                    language = previewLanguage,
                    onLanguageChange = { previewLanguage = it },
                    presetName = presetName,
                    onPresetNameChange = { presetName = it },
                    state = previewState,
                    selectedModelName = modelName,
                    selectedEmbeddingDimension = requiredPreviewDimension.takeIf { it > 0 },
                    compatibilityMessage = previewCompatibilityMessage,
                    canGenerate = canCreate && previewCompatibilityMessage == null &&
                        previewText.isNotBlank() && modelDir.isNotBlank() && !isCreating,
                    canSave = canCreate && !isCreating && !previewState.isGenerating,
                    isSaving = isCreating,
                    saveLabel = saveLabel,
                    onGenerate = {
                        viewModel.generateVoiceLabPreview(
                            recipe = currentRecipe,
                            text = previewText,
                            language = previewLanguage,
                            modelDir = modelDir,
                            modelName = modelName,
                            backendPreference = backendPreference
                        )
                    },
                    onReplay = viewModel::replayVoiceLabPreview,
                    onStop = viewModel::stopVoiceLabPreview,
                    onCancel = viewModel::invalidateVoiceLabPreview,
                    onSave = savePreset
                )
            }
        }
    }
}

@Composable
private fun ModeButton(label: String, selected: Boolean, onClick: () -> Unit) {
    val contentPadding = PaddingValues(horizontal = 14.dp, vertical = 8.dp)
    if (selected) {
        Button(onClick = onClick, contentPadding = contentPadding) {
            Text(label)
        }
    } else {
        OutlinedButton(onClick = onClick, contentPadding = contentPadding) {
            Text(label)
        }
    }
}

@Composable
private fun MethodNotice(mode: VoiceLabMode) {
    val (icon, title, body) = when (mode) {
        VoiceLabMode.Morph -> Triple(
            Icons.Default.Tune,
            "Interpolation",
            "Move between two complete voice embeddings. The endpoints remain the original voices."
        )
        VoiceLabMode.Average -> Triple(
            Icons.Default.Tune,
            "Equal-weight mean",
            "Average multiple embeddings, with optional norm rescaling. Treat same-speaker averaging as experimental."
        )
    }

    Surface(
        color = MaterialTheme.colorScheme.primaryContainer.copy(alpha = 0.35f),
        shape = MaterialTheme.shapes.medium,
        modifier = Modifier.fillMaxWidth()
    ) {
        Row(
            modifier = Modifier.padding(14.dp),
            horizontalArrangement = Arrangement.spacedBy(10.dp),
            verticalAlignment = Alignment.Top
        ) {
            Icon(icon, contentDescription = null, tint = MaterialTheme.colorScheme.primary)
            Column(verticalArrangement = Arrangement.spacedBy(2.dp)) {
                Text(title, style = MaterialTheme.typography.labelLarge, fontWeight = FontWeight.SemiBold)
                Text(
                    body,
                    style = MaterialTheme.typography.bodySmall,
                    color = MaterialTheme.colorScheme.onSurfaceVariant
                )
            }
        }
    }
}

@Composable
private fun LabeledVoiceDropdown(
    label: String,
    voices: List<VoicePreset>,
    selectedId: String,
    onSelected: (String) -> Unit,
    modifier: Modifier = Modifier,
    helper: String? = null
) {
    Column(modifier = modifier, verticalArrangement = Arrangement.spacedBy(6.dp)) {
        Text(label, style = MaterialTheme.typography.labelLarge, fontWeight = FontWeight.Medium)
        helper?.let {
            Text(it, style = MaterialTheme.typography.bodySmall, color = MaterialTheme.colorScheme.onSurfaceVariant)
        }
        VoiceDropdown(
            voices = voices,
            selectedId = selectedId,
            onSelected = onSelected,
            modifier = Modifier.fillMaxWidth()
        )
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
            onClick = { if (voices.isNotEmpty()) expanded = true },
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
                    text = {
                        Column {
                            Text(voice.name)
                            Text(
                                voice.speakerEmbeddings.keys.sorted().joinToString(" + ") { "D$it" },
                                style = MaterialTheme.typography.labelSmall,
                                color = MaterialTheme.colorScheme.onSurfaceVariant
                            )
                        }
                    },
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
    OutlinedCard(modifier = Modifier.fillMaxWidth()) {
        Row(
            modifier = Modifier.fillMaxWidth().padding(horizontal = 8.dp, vertical = 4.dp),
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
}

@Composable
private fun DimensionBadge(dimensions: List<Int>, selectionReady: Boolean) {
    Surface(
        color = MaterialTheme.colorScheme.surfaceVariant,
        contentColor = MaterialTheme.colorScheme.onSurfaceVariant,
        shape = MaterialTheme.shapes.small
    ) {
        Text(
            when {
                !selectionReady -> "Selection incomplete"
                dimensions.isEmpty() -> "No shared dimension"
                else -> dimensions.joinToString(" + ") { "D$it" }
            },
            modifier = Modifier.padding(horizontal = 10.dp, vertical = 6.dp),
            style = MaterialTheme.typography.labelMedium
        )
    }
}

@Composable
private fun EmptyLabState(voiceCount: Int) {
    Surface(
        modifier = Modifier.fillMaxWidth(),
        color = MaterialTheme.colorScheme.surfaceVariant.copy(alpha = 0.45f),
        shape = MaterialTheme.shapes.medium
    ) {
        Row(
            modifier = Modifier.padding(16.dp),
            horizontalArrangement = Arrangement.spacedBy(12.dp),
            verticalAlignment = Alignment.CenterVertically
        ) {
            Icon(Icons.Default.Science, contentDescription = null, tint = MaterialTheme.colorScheme.onSurfaceVariant)
            Column {
                Text("At least two voice embeddings are needed", fontWeight = FontWeight.SemiBold)
                Text(
                    if (voiceCount == 0) "Create custom voices in the Voices tab first."
                    else "Create one more compatible custom voice in the Voices tab.",
                    style = MaterialTheme.typography.bodySmall,
                    color = MaterialTheme.colorScheme.onSurfaceVariant
                )
            }
        }
    }
}

@Composable
private fun ErrorBanner(message: String) {
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
            Text(message, style = MaterialTheme.typography.bodyMedium, color = MaterialTheme.colorScheme.onErrorContainer)
        }
    }
}

@Composable
private fun WarningBanner(message: String) {
    Surface(
        color = MaterialTheme.colorScheme.tertiaryContainer,
        contentColor = MaterialTheme.colorScheme.onTertiaryContainer,
        shape = MaterialTheme.shapes.medium,
        modifier = Modifier.fillMaxWidth()
    ) {
        Row(
            modifier = Modifier.padding(12.dp),
            verticalAlignment = Alignment.Top,
            horizontalArrangement = Arrangement.spacedBy(10.dp)
        ) {
            Icon(Icons.Default.WarningAmber, contentDescription = null)
            Text(message, style = MaterialTheme.typography.bodySmall)
        }
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

private fun voiceName(voices: List<VoicePreset>, id: String): String =
    voices.firstOrNull { it.id == id }?.name ?: "Select voice"
