#!/bin/bash
set -e

# Configuration
CONFIG=${1:-Release}
CUDA=${CUDA:-OFF}
CLEAN=${CLEAN:-false}

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
EXTERNAL_DIR="$REPO_ROOT/external"
BUILD_DIR="$EXTERNAL_DIR/build-linux"

if [ "$CLEAN" = "true" ]; then
    echo "Cleaning build directory: $BUILD_DIR"
    rm -rf "$BUILD_DIR"
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

echo "Configuring native build (CUDA=$CUDA, Config=$CONFIG)..."
cmake -S "$EXTERNAL_DIR" -B "$BUILD_DIR" \
    -DCMAKE_BUILD_TYPE="$CONFIG" \
    -DQWEN3_TTS_CUDA="$CUDA" \
    -DGGML_CUDA="$CUDA"

echo "Building native targets..."
cmake --build "$BUILD_DIR" -j$(nproc)

# Identify artifacts
SHARED_LIB="libqwen3_tts.so"
GGML_LIBS=("libggml.so" "libggml-base.so" "libggml-cpu.so")

if [ "$CUDA" = "ON" ]; then
    GGML_LIBS+=("libggml-cuda.so")
fi

echo "Copying artifacts to repository root..."
cp "$BUILD_DIR/$SHARED_LIB" "$REPO_ROOT/"
for lib in "${GGML_LIBS[@]}"; do
    # ggml libs are in build/qwen3-tts-cpp/ggml/src/
    find "$BUILD_DIR/qwen3-tts-cpp/ggml/src" -name "$lib" -exec cp {} "$REPO_ROOT/" \;
done

# Also copy CLI
find "$BUILD_DIR" -name "qwen3-tts-cli" -exec cp {} "$REPO_ROOT/" \;

echo "Native build complete."
