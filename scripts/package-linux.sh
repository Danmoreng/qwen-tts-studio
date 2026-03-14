#!/bin/bash
set -e

# Configuration
CONFIG=${1:-Release}
CUDA=${CUDA:-OFF}
CLEAN=${CLEAN:-false}
BUILD_DEB=${BUILD_DEB:-false}

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SCRIPTS_DIR="$REPO_ROOT/scripts"
COMPOSE_APP_DIR="$REPO_ROOT/composeApp"
GRADLE_WRAPPER="$REPO_ROOT/gradlew"

# 1. Build native libraries
echo "Step 1/3: Building native libraries..."
chmod +x "$SCRIPTS_DIR/build-native.sh"
CUDA=$CUDA CLEAN=$CLEAN "$SCRIPTS_DIR/build-native.sh" "$CONFIG"

# 2. Build Compose distributable
echo "Step 2/3: Building Compose distributable..."
chmod +x "$GRADLE_WRAPPER"
"$GRADLE_WRAPPER" :composeApp:createDistributable

# 3. Copy native libraries into the packaged app
echo "Step 3/3: Copying native libraries into packaged app..."

# The default path for Compose Multiplatform distributables on Linux
# Adjusting name to match packageName in build.gradle.kts
APP_NAME="qwen-tts-studio"
DIST_DIR="$COMPOSE_APP_DIR/build/compose/binaries/main/app/$APP_NAME"

if [ ! -d "$DIST_DIR" ]; then
    echo "Error: Distributable directory not found at $DIST_DIR"
    exit 1
fi

# Native libraries to copy from repo root (where build-native.sh puts them)
NATIVE_LIBS=("libqwen3_tts.so" "libggml.so" "libggml-base.so" "libggml-cpu.so")
if [ "$CUDA" = "ON" ]; then
    NATIVE_LIBS+=("libggml-cuda.so")
fi

# Copy into the lib folder of the distributable
LIB_DIR="$DIST_DIR/lib"
mkdir -p "$LIB_DIR"

for lib in "${NATIVE_LIBS[@]}"; do
    SRC="$REPO_ROOT/$lib"
    if [ -f "$SRC" ]; then
        echo "Copying $lib to $LIB_DIR"
        cp "$SRC" "$LIB_DIR/"
    else
        echo "Warning: Native library $lib not found in repo root. Skipping."
    fi
done

# Optional: Build DEB package
if [ "$BUILD_DEB" = "true" ]; then
    echo "Building DEB package..."
    "$GRADLE_WRAPPER" :composeApp:packageDeb
    # Note: For DEB/RPM, Compose doesn't automatically include the side-loaded native libs 
    # unless they are in the classpath or specifically configured.
    # For now, we focus on the portable distributable.
    echo "DEB package created in composeApp/build/compose/binaries/main/deb"
fi

echo "Packaging complete!"
echo "Standalone application is available at: $DIST_DIR"
echo "You can run it using: $DIST_DIR/bin/$APP_NAME"
