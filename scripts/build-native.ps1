param(
    [string]$Configuration = "Release",
    [string]$Platform = "x64",
    [switch]$CopyToRoot = $true
)

$ErrorActionPreference = "Stop"

$RepoRoot = Split-Path -Parent $PSScriptRoot
$ExternalDir = Join-Path $RepoRoot "external"
$BuildDir = Join-Path $ExternalDir "build"
$BinDir = Join-Path $BuildDir "bin\$Configuration"
$SharedDir = Join-Path $BuildDir $Configuration

Write-Host "Configuring native build..." -ForegroundColor Cyan
cmake -S $ExternalDir -B $BuildDir -A $Platform

Write-Host "Building native JNI library..." -ForegroundColor Cyan
cmake --build $BuildDir --config $Configuration --target qwen3_tts_shared

$NativeFiles = @(
    (Join-Path $SharedDir "qwen3_tts.dll"),
    (Join-Path $BinDir "ggml.dll"),
    (Join-Path $BinDir "ggml-base.dll"),
    (Join-Path $BinDir "ggml-cpu.dll")
)

foreach ($f in $NativeFiles) {
    if (-not (Test-Path $f)) {
        throw "Missing expected native artifact: $f"
    }
}

if ($CopyToRoot) {
    Write-Host "Copying native DLLs to repository root..." -ForegroundColor Cyan
    foreach ($f in $NativeFiles) {
        Copy-Item $f $RepoRoot -Force
    }
}

Write-Host "Native build complete." -ForegroundColor Green
