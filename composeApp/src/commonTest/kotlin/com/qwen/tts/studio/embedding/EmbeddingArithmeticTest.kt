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
