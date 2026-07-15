package com.qwen.tts.studio.embedding

import kotlin.math.sqrt
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class EmbeddingVisualizationTest {
    @Test
    fun rawMorphStaysOnSourceTargetChord() {
        val analysis = EmbeddingVisualization.analyzeMorph(
            source = floatArrayOf(1f, 2f, 3f),
            target = floatArrayOf(5f, 4f, 1f),
            amount = 0.25f,
            preserveAverageNorm = false
        )

        assertEquals(0.25, analysis.chordPosition!!, absoluteTolerance = 1e-6)
        assertEquals(0.0, analysis.mixed.y, absoluteTolerance = 1e-6)
        assertEquals(0.0, analysis.relativeOrthogonalDeviation!!, absoluteTolerance = 1e-6)
        assertTrue(analysis.actualPathSegments.flatten().all { kotlin.math.abs(it.y) < 1e-6 })
    }

    @Test
    fun normRescalingProducesTheReportedMixedNorm() {
        val source = floatArrayOf(4f, 0f)
        val target = floatArrayOf(0f, 2f)
        val analysis = EmbeddingVisualization.analyzeMorph(
            source = source,
            target = target,
            amount = 0.5f,
            preserveAverageNorm = true
        )

        assertEquals(3.0, analysis.mixedNorm, absoluteTolerance = 1e-6)
        assertTrue(analysis.relativeOrthogonalDeviation!! > 0.0)
        assertEquals(sqrt(20.0), analysis.target.x, absoluteTolerance = 1e-6)
        assertEquals(0.0, analysis.target.y, absoluteTolerance = 1e-6)
        assertEquals(8.0 / sqrt(5.0) - 1.8, analysis.mixed.x, absoluteTolerance = 1e-6)
        assertEquals(2.4 - 4.0 / sqrt(5.0), analysis.mixed.y, absoluteTolerance = 1e-6)
        val sampledMidpoint = analysis.actualPathSegments.flatten()[16]
        assertEquals(analysis.mixed.x, sampledMidpoint.x, absoluteTolerance = 1e-6)
        assertEquals(analysis.mixed.y, sampledMidpoint.y, absoluteTolerance = 1e-6)
    }

    @Test
    fun unrelatedNormalizationSingularitySplitsPathInsteadOfHidingCurrentMix() {
        val analysis = EmbeddingVisualization.analyzeMorph(
            source = floatArrayOf(1f, 0f),
            target = floatArrayOf(-1f, 0f),
            amount = 0.25f,
            preserveAverageNorm = true
        )

        assertEquals(2, analysis.actualPathSegments.size)
        assertTrue(analysis.actualPathSegments.all { it.isNotEmpty() })
        assertEquals(0.0, analysis.mixed.x, absoluteTolerance = 1e-6)
        assertEquals(0.0, analysis.mixed.y, absoluteTolerance = 1e-6)
    }

    @Test
    fun endpointsRemainExactWithNormRescaling() {
        val source = floatArrayOf(3f, 4f)
        val target = floatArrayOf(8f, 0f)

        val atSource = EmbeddingVisualization.analyzeMorph(source, target, 0f, true)
        val atTarget = EmbeddingVisualization.analyzeMorph(source, target, 1f, true)

        assertEquals(0.0, atSource.mixed.x, absoluteTolerance = 1e-6)
        assertEquals(0.0, atSource.mixed.y, absoluteTolerance = 1e-6)
        assertEquals(atTarget.target.x, atTarget.mixed.x, absoluteTolerance = 1e-6)
        assertEquals(atTarget.target.y, atTarget.mixed.y, absoluteTolerance = 1e-6)
    }

    @Test
    fun differenceBinsCoverAllDimensions() {
        val analysis = EmbeddingVisualization.analyzeMorph(
            source = floatArrayOf(0f, 0f, 0f, 0f, 0f),
            target = floatArrayOf(1f, 2f, 3f, 4f, 5f),
            amount = 0.5f,
            preserveAverageNorm = false,
            differenceBinCount = 2
        )

        assertEquals(2, analysis.differenceBins.size)
        assertEquals(sqrt(2.5), analysis.differenceBins[0].sourceToTargetRms, absoluteTolerance = 1e-6)
        assertEquals(sqrt(50.0 / 3.0), analysis.differenceBins[1].sourceToTargetRms, absoluteTolerance = 1e-6)
        assertEquals(sqrt(0.625), analysis.differenceBins[0].sourceToMixRms, absoluteTolerance = 1e-6)
        assertEquals(sqrt(25.0 / 6.0), analysis.differenceBins[1].sourceToMixRms, absoluteTolerance = 1e-6)
    }

    @Test
    fun differenceBinCountIsCappedAtEmbeddingDimension() {
        val analysis = EmbeddingVisualization.analyzeMorph(
            source = floatArrayOf(0f, 0f, 0f),
            target = floatArrayOf(2f, 4f, 6f),
            amount = 0.5f,
            preserveAverageNorm = false,
            differenceBinCount = 10
        )

        assertEquals(3, analysis.differenceBins.size)
        assertEquals(2.0, analysis.differenceBins[0].sourceToTargetRms, absoluteTolerance = 1e-6)
        assertEquals(4.0, analysis.differenceBins[1].sourceToTargetRms, absoluteTolerance = 1e-6)
        assertEquals(6.0, analysis.differenceBins[2].sourceToTargetRms, absoluteTolerance = 1e-6)
    }
}
