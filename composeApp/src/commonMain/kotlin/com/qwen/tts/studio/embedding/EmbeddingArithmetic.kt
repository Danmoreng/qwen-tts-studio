package com.qwen.tts.studio.embedding

import kotlin.math.sqrt

/**
 * Pure vector operations used by the Voice Lab.
 *
 * Speaker-embedding dimensions are model-specific and do not have an intrinsic,
 * human-readable meaning. These operations therefore work on complete vectors
 * and deliberately avoid exposing individual dimensions as "voice controls".
 */
object EmbeddingArithmetic {
    data class WeightedVector(
        val weight: Float,
        val values: FloatArray
    )

    /**
     * Computes a positive weighted mean. When [preserveAverageNorm] is enabled,
     * the result is rescaled to the weighted average L2 norm of its sources.
     */
    fun weightedMean(
        vectors: List<WeightedVector>,
        preserveAverageNorm: Boolean
    ): FloatArray {
        require(vectors.isNotEmpty()) { "At least one embedding is required." }

        val dimension = vectors.first().values.size
        require(dimension > 0) { "Embedding must not be empty." }

        val sum = DoubleArray(dimension)
        var weightSum = 0.0
        var weightedNormSum = 0.0

        vectors.forEach { source ->
            require(source.values.size == dimension) { "Embedding dimensions do not match." }
            require(source.weight.isFinite() && source.weight > 0f) { "Weights must be finite and positive." }
            requireFinite(source.values)

            val weight = source.weight.toDouble()
            weightSum += weight
            weightedNormSum += l2Norm(source.values) * weight
            for (index in 0 until dimension) {
                sum[index] += source.values[index].toDouble() * weight
            }
        }

        val result = FloatArray(dimension) { index -> (sum[index] / weightSum).toFloat() }
        requireFinite(result)

        if (preserveAverageNorm) {
            rescaleToNorm(result, weightedNormSum / weightSum)
        }

        return result
    }

    /**
     * Transfers the direction represented by [toward] - [from] onto [base].
     *
     * This does not discover a semantic attribute. The caller is responsible for
     * choosing a meaningful, preferably paired reference recording for each end
     * of the direction.
     */
    fun shiftAlongDirection(
        base: FloatArray,
        from: FloatArray,
        toward: FloatArray,
        strength: Float,
        preserveBaseNorm: Boolean
    ): FloatArray {
        require(base.isNotEmpty()) { "Embedding must not be empty." }
        require(from.size == base.size && toward.size == base.size) { "Embedding dimensions do not match." }
        require(strength.isFinite()) { "Direction strength must be finite." }
        requireFinite(base)
        requireFinite(from)
        requireFinite(toward)

        val result = FloatArray(base.size) { index ->
            (base[index].toDouble() + strength.toDouble() *
                (toward[index].toDouble() - from[index].toDouble())).toFloat()
        }
        requireFinite(result)

        if (preserveBaseNorm) {
            rescaleToNorm(result, l2Norm(base))
        }

        return result
    }

    fun l2Norm(vector: FloatArray): Double {
        var squaredSum = 0.0
        for (value in vector) {
            squaredSum += value.toDouble() * value.toDouble()
        }
        return sqrt(squaredSum)
    }

    private fun rescaleToNorm(vector: FloatArray, targetNorm: Double) {
        if (targetNorm <= NORMALIZATION_EPSILON) {
            vector.fill(0f)
            return
        }

        val currentNorm = l2Norm(vector)
        require(currentNorm > NORMALIZATION_EPSILON) {
            "Embedding is too close to zero to preserve its norm. Try a different blend or strength."
        }

        val scale = targetNorm / currentNorm
        for (index in vector.indices) {
            vector[index] = (vector[index] * scale).toFloat()
        }
        requireFinite(vector)
    }

    private fun requireFinite(vector: FloatArray) {
        require(vector.all(Float::isFinite)) { "Embedding contains invalid values." }
    }

    private const val NORMALIZATION_EPSILON = 1e-12
}
