package com.qwen.tts.studio.embedding

import kotlin.math.abs
import kotlin.math.acos
import kotlin.math.max
import kotlin.math.min
import kotlin.math.sqrt

data class EmbeddingPoint2D(
    val x: Double,
    val y: Double
)

data class MorphDifferenceBin(
    val sourceToTargetRms: Double,
    val sourceToMixRms: Double,
    val mixToTargetRms: Double
)

data class MorphEmbeddingAnalysis(
    val dimension: Int,
    val source: EmbeddingPoint2D,
    val target: EmbeddingPoint2D,
    val mixed: EmbeddingPoint2D,
    val actualPathSegments: List<List<EmbeddingPoint2D>>,
    val cosineSimilarity: Double?,
    val angleDegrees: Double?,
    val sourceDistance: Double,
    val symmetricRelativeSourceDistance: Double?,
    val sourceNorm: Double,
    val mixedNorm: Double,
    val targetNorm: Double,
    val chordPosition: Double?,
    val relativeOrthogonalDeviation: Double?,
    val differenceBins: List<MorphDifferenceBin>
)

/**
 * Geometry and diagnostics for complete speaker-embedding vectors.
 *
 * The resulting two-dimensional plane is local to the selected source vectors.
 * Its axes are embedding directions, not time, Hertz, pitch, or learned semantic labels.
 */
object EmbeddingVisualization {
    fun analyzeMorph(
        source: FloatArray,
        target: FloatArray,
        amount: Float,
        preserveAverageNorm: Boolean,
        pathSampleCount: Int = 33,
        differenceBinCount: Int = 32
    ): MorphEmbeddingAnalysis {
        require(source.isNotEmpty()) { "Embedding must not be empty." }
        require(source.size == target.size) { "Embedding dimensions do not match." }
        require(source.all { it.isFinite() } && target.all { it.isFinite() }) {
            "Embedding contains invalid values."
        }
        require(amount.isFinite() && amount in 0f..1f) { "Morph amount must be between 0 and 1." }
        require(pathSampleCount >= 2) { "At least two path samples are required." }
        require(differenceBinCount > 0) { "At least one difference bin is required." }

        val sourceNorm = EmbeddingArithmetic.l2Norm(source)
        val targetNorm = EmbeddingArithmetic.l2Norm(target)
        val mixedVector = morph(source, target, amount, preserveAverageNorm)
        val mixedNorm = EmbeddingArithmetic.l2Norm(mixedVector)

        val direction = DoubleArray(source.size) { index ->
            target[index].toDouble() - source[index].toDouble()
        }
        val sourceDistance = l2Norm(direction)
        val firstAxis = if (sourceDistance > EPSILON) {
            DoubleArray(direction.size) { index -> direction[index] / sourceDistance }
        } else {
            DoubleArray(direction.size)
        }

        val sourceProjection = dot(source, firstAxis)
        val sourceResidual = DoubleArray(source.size) { index ->
            source[index].toDouble() - sourceProjection * firstAxis[index]
        }
        val residualNorm = l2Norm(sourceResidual)
        val secondAxis = if (residualNorm > EPSILON) {
            DoubleArray(sourceResidual.size) { index -> sourceResidual[index] / residualNorm }
        } else {
            DoubleArray(sourceResidual.size)
        }

        fun project(vector: FloatArray): EmbeddingPoint2D {
            var x = 0.0
            var y = 0.0
            for (index in vector.indices) {
                val centered = vector[index].toDouble() - source[index].toDouble()
                x += centered * firstAxis[index]
                y += centered * secondAxis[index]
            }
            return EmbeddingPoint2D(x, y)
        }

        val sourcePoint = EmbeddingPoint2D(0.0, 0.0)
        val targetPoint = project(target)
        val mixedPoint = project(mixedVector)
        val pathSegments = mutableListOf<MutableList<EmbeddingPoint2D>>()
        var currentSegment = mutableListOf<EmbeddingPoint2D>()
        repeat(pathSampleCount) { sampleIndex ->
            val sampleAmount = sampleIndex.toFloat() / (pathSampleCount - 1).toFloat()
            val point = try {
                project(morph(source, target, sampleAmount, preserveAverageNorm))
            } catch (_: IllegalArgumentException) {
                null
            }
            if (point != null) {
                currentSegment += point
            } else if (currentSegment.isNotEmpty()) {
                pathSegments += currentSegment
                currentSegment = mutableListOf()
            }
        }
        if (currentSegment.isNotEmpty()) pathSegments += currentSegment

        val normProduct = sourceNorm * targetNorm
        val cosine = if (normProduct > EPSILON) {
            (dot(source, target) / normProduct).coerceIn(-1.0, 1.0)
        } else {
            null
        }
        val relativeDistance = (sourceNorm + targetNorm)
            .takeIf { it > EPSILON }
            ?.let { 2.0 * sourceDistance / it }
        val chordPosition = sourceDistance
            .takeIf { it > EPSILON }
            ?.let { mixedPoint.x / it }
        val relativeDeviation = sourceDistance
            .takeIf { it > EPSILON }
            ?.let { abs(mixedPoint.y) / it }

        return MorphEmbeddingAnalysis(
            dimension = source.size,
            source = sourcePoint,
            target = targetPoint,
            mixed = mixedPoint,
            actualPathSegments = pathSegments,
            cosineSimilarity = cosine,
            angleDegrees = cosine?.let { acos(it) * 180.0 / kotlin.math.PI },
            sourceDistance = sourceDistance,
            symmetricRelativeSourceDistance = relativeDistance,
            sourceNorm = sourceNorm,
            mixedNorm = mixedNorm,
            targetNorm = targetNorm,
            chordPosition = chordPosition,
            relativeOrthogonalDeviation = relativeDeviation,
            differenceBins = differenceBins(source, mixedVector, target, differenceBinCount)
        )
    }

    private fun morph(
        source: FloatArray,
        target: FloatArray,
        amount: Float,
        preserveAverageNorm: Boolean
    ): FloatArray {
        if (amount <= 0f) return source.copyOf()
        if (amount >= 1f) return target.copyOf()

        return EmbeddingArithmetic.weightedMean(
            vectors = listOf(
                EmbeddingArithmetic.WeightedVector(1f - amount, source),
                EmbeddingArithmetic.WeightedVector(amount, target)
            ),
            preserveAverageNorm = preserveAverageNorm
        )
    }

    private fun differenceBins(
        source: FloatArray,
        mixed: FloatArray,
        target: FloatArray,
        requestedBinCount: Int
    ): List<MorphDifferenceBin> {
        val binCount = min(requestedBinCount, source.size)
        return List(binCount) { binIndex ->
            val start = binIndex * source.size / binCount
            val end = max(start + 1, (binIndex + 1) * source.size / binCount)

            var sourceToTargetSquared = 0.0
            var sourceToMixSquared = 0.0
            var mixToTargetSquared = 0.0
            for (index in start until end) {
                val sourceToTarget = source[index].toDouble() - target[index].toDouble()
                val sourceToMixed = source[index].toDouble() - mixed[index].toDouble()
                val mixedToTarget = mixed[index].toDouble() - target[index].toDouble()
                sourceToTargetSquared += sourceToTarget * sourceToTarget
                sourceToMixSquared += sourceToMixed * sourceToMixed
                mixToTargetSquared += mixedToTarget * mixedToTarget
            }
            val count = (end - start).toDouble()
            MorphDifferenceBin(
                sourceToTargetRms = sqrt(sourceToTargetSquared / count),
                sourceToMixRms = sqrt(sourceToMixSquared / count),
                mixToTargetRms = sqrt(mixToTargetSquared / count)
            )
        }
    }

    private fun dot(left: FloatArray, right: FloatArray): Double {
        var sum = 0.0
        for (index in left.indices) {
            sum += left[index].toDouble() * right[index].toDouble()
        }
        return sum
    }

    private fun dot(left: FloatArray, right: DoubleArray): Double {
        var sum = 0.0
        for (index in left.indices) {
            sum += left[index].toDouble() * right[index]
        }
        return sum
    }

    private fun l2Norm(vector: DoubleArray): Double {
        var squaredSum = 0.0
        for (value in vector) squaredSum += value * value
        return sqrt(squaredSum)
    }

    private const val EPSILON = 1e-12
}
