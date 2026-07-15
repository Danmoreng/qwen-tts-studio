package com.qwen.tts.studio.embedding

import kotlin.math.sqrt
import kotlin.test.Test
import kotlin.test.assertContentEquals
import kotlin.test.assertEquals
import kotlin.test.assertFailsWith

class EmbeddingArithmeticTest {
    @Test
    fun weightedMeanInterpolatesSources() {
        val result = EmbeddingArithmetic.weightedMean(
            vectors = listOf(
                EmbeddingArithmetic.WeightedVector(3f, floatArrayOf(0f, 2f)),
                EmbeddingArithmetic.WeightedVector(1f, floatArrayOf(4f, 2f))
            ),
            preserveAverageNorm = false
        )

        assertContentEquals(floatArrayOf(1f, 2f), result)
    }

    @Test
    fun weightedMeanPreservesAverageSourceNorm() {
        val result = EmbeddingArithmetic.weightedMean(
            vectors = listOf(
                EmbeddingArithmetic.WeightedVector(1f, floatArrayOf(1f, 0f)),
                EmbeddingArithmetic.WeightedVector(1f, floatArrayOf(0f, 1f))
            ),
            preserveAverageNorm = true
        )

        assertEquals(1.0, EmbeddingArithmetic.l2Norm(result), absoluteTolerance = 1e-6)
        assertEquals(1.0 / sqrt(2.0), result[0].toDouble(), absoluteTolerance = 1e-6)
        assertEquals(result[0], result[1])
    }

    @Test
    fun zeroWeightEndpointCanCopyOneSelectedSource() {
        val result = EmbeddingArithmetic.weightedMean(
            vectors = listOf(
                EmbeddingArithmetic.WeightedVector(1f, floatArrayOf(2f, -3f))
            ),
            preserveAverageNorm = true
        )

        assertContentEquals(floatArrayOf(2f, -3f), result)
    }

    @Test
    fun directionShiftReachesTowardVectorWhenBaseEqualsFrom() {
        val from = floatArrayOf(1f, 2f, 3f)
        val toward = floatArrayOf(4f, 6f, 8f)

        val result = EmbeddingArithmetic.shiftAlongDirection(
            base = from,
            from = from,
            toward = toward,
            strength = 1f,
            preserveBaseNorm = false
        )

        assertContentEquals(toward, result)
    }

    @Test
    fun zeroDirectionStrengthLeavesBaseUnchanged() {
        val base = floatArrayOf(3f, 4f)

        val result = EmbeddingArithmetic.shiftAlongDirection(
            base = base,
            from = floatArrayOf(10f, 20f),
            toward = floatArrayOf(-5f, -10f),
            strength = 0f,
            preserveBaseNorm = true
        )

        assertContentEquals(base, result)
    }

    @Test
    fun directionShiftCanPreserveBaseNorm() {
        val base = floatArrayOf(3f, 4f)

        val result = EmbeddingArithmetic.shiftAlongDirection(
            base = base,
            from = floatArrayOf(0f, 0f),
            toward = floatArrayOf(10f, 0f),
            strength = 0.5f,
            preserveBaseNorm = true
        )

        assertEquals(5.0, EmbeddingArithmetic.l2Norm(result), absoluteTolerance = 1e-6)
    }

    @Test
    fun preservingZeroBaseNormProducesZeroVector() {
        val result = EmbeddingArithmetic.shiftAlongDirection(
            base = floatArrayOf(0f, 0f),
            from = floatArrayOf(0f, 0f),
            toward = floatArrayOf(3f, 4f),
            strength = 1f,
            preserveBaseNorm = true
        )

        assertContentEquals(floatArrayOf(0f, 0f), result)
    }

    @Test
    fun operationsRejectMismatchedDimensions() {
        assertFailsWith<IllegalArgumentException> {
            EmbeddingArithmetic.shiftAlongDirection(
                base = floatArrayOf(1f, 2f),
                from = floatArrayOf(1f),
                toward = floatArrayOf(2f, 3f),
                strength = 0.25f,
                preserveBaseNorm = false
            )
        }
    }

    @Test
    fun weightedMeanRejectsNonPositiveWeights() {
        assertFailsWith<IllegalArgumentException> {
            EmbeddingArithmetic.weightedMean(
                vectors = listOf(
                    EmbeddingArithmetic.WeightedVector(0f, floatArrayOf(1f, 2f))
                ),
                preserveAverageNorm = false
            )
        }
    }
}
