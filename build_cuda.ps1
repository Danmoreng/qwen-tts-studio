# build_cuda.ps1
# Build script for Qwen-TTS Studio C++ Bridge with CUDA support

$BuildDir = "external/build"
$ReleaseDir = "$BuildDir/Release"

# 1. Create build directory
if (!(Test-Path $BuildDir)) {
    New-Item -ItemType Directory -Path $BuildDir
}

# 2. Configure with CMake
# We enable CUDA and specify that we want the shared library
Write-Host "Configuring CMake with CUDA support..." -ForegroundColor Cyan
cmake -S external -B $BuildDir `
    -DQWEN3_TTS_CUDA=ON `
    -DGGML_CUDA=ON `
    -DCMAKE_BUILD_TYPE=Release `
    -A x64

if ($LASTEXITCODE -ne 0) {
    Write-Error "CMake configuration failed."
    exit $LASTEXITCODE
}

# 3. Build the project
Write-Host "Building project (Release)..." -ForegroundColor Cyan
cmake --build $BuildDir --config Release --parallel

if ($LASTEXITCODE -ne 0) {
    Write-Error "Build failed."
    exit $LASTEXITCODE
}

# 4. Copy the resulting DLLs to the root for JNA to find them
# JNA looks in the working directory by default
Write-Host "Deployment: Copying DLLs to root..." -ForegroundColor Green
$BinDir = "$BuildDir/bin/Release"

if (Test-Path "$ReleaseDir/qwen3_tts.dll") {
    Copy-Item "$ReleaseDir/qwen3_tts.dll" . -Force
}

# GGML dependencies
$GgmlDlls = @("ggml.dll", "ggml-base.dll", "ggml-cuda.dll", "ggml-cpu.dll")
foreach ($dll in $GgmlDlls) {
    if (Test-Path "$BinDir/$dll") {
        Copy-Item "$BinDir/$dll" . -Force
        Write-Host "  Copied $dll"
    }
}

# 5. Copy CUDA runtime if found
if ($env:CUDA_PATH) {
    $CudaBin = "$env:CUDA_PATH/bin"
    $CudaRuntime = Get-ChildItem -Path $CudaBin -Filter "cudart64_*.dll" | Select-Object -First 1
    if ($CudaRuntime) {
        Copy-Item $CudaRuntime.FullName . -Force
        Write-Host "  Copied $($CudaRuntime.Name) from CUDA_PATH"
    }
}

Write-Host "Deployment: Running Unblock-File on all DLLs..." -ForegroundColor Cyan
Get-ChildItem -Filter *.dll | Unblock-File

Write-Host "Build complete! qwen3_tts.dll is ready in the root folder." -ForegroundColor Green
