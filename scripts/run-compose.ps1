# Qwen-TTS Studio Compose Desktop Launch Script
param(
    [string]$JavaHome = "",
    [switch]$BuildNative,
    [switch]$Cuda,
    [switch]$UseNinja,
    [switch]$CleanNative,
    [switch]$DryRun
)

$ErrorActionPreference = "Stop"

$ScriptDir = $PSScriptRoot
$ProjectRoot = Split-Path -Parent $ScriptDir
$GradleWrapper = Join-Path $ProjectRoot "gradlew.bat"
$RequiredJavaMajor = 21

function Get-JavaMajorVersion([string]$JavaHomePath) {
    if ([string]::IsNullOrWhiteSpace($JavaHomePath)) { return $null }

    $releaseFile = Join-Path $JavaHomePath "release"
    if (Test-Path $releaseFile) {
        $versionLine = Get-Content $releaseFile | Where-Object { $_ -match '^JAVA_VERSION="([0-9]+)' } | Select-Object -First 1
        if ($versionLine -and $matches[1]) {
            return [int]$matches[1]
        }
    }

    $javaExe = Join-Path $JavaHomePath "bin\java.exe"
    if (Test-Path $javaExe) {
        $versionOutput = & $javaExe -version 2>&1 | Select-Object -First 1
        if ($versionOutput -match 'version "([0-9]+)') {
            return [int]$matches[1]
        }
    }

    return $null
}

function Test-JavaHome([string]$JavaHomePath) {
    if ([string]::IsNullOrWhiteSpace($JavaHomePath)) { return $false }
    if (-not (Test-Path (Join-Path $JavaHomePath "bin\java.exe"))) { return $false }
    $major = Get-JavaMajorVersion $JavaHomePath
    return $major -and $major -ge $RequiredJavaMajor
}

function Resolve-JavaHome([string]$RequestedJavaHome) {
    if (Test-JavaHome $RequestedJavaHome) { return $RequestedJavaHome }
    if (Test-JavaHome $env:JAVA_HOME) { return $env:JAVA_HOME }

    $javaCmd = Get-Command java -ErrorAction SilentlyContinue
    if ($javaCmd -and $javaCmd.Path) {
        $javaHomeFromPath = Split-Path -Parent (Split-Path -Parent $javaCmd.Path)
        if (Test-JavaHome $javaHomeFromPath) { return $javaHomeFromPath }
    }

    $candidates = @()
    $userProfile = $env:USERPROFILE
    $localAppData = [Environment]::GetFolderPath("LocalApplicationData")
    $programFiles = ${env:ProgramFiles}

    if ($userProfile) {
        $gradleJdks = Join-Path $userProfile ".gradle\jdks"
        if (Test-Path $gradleJdks) {
            Get-ChildItem $gradleJdks -Directory -ErrorAction SilentlyContinue |
                Sort-Object LastWriteTime -Descending |
                ForEach-Object { $candidates += $_.FullName }
        }
    }
    if ($localAppData) {
        $candidates += (Join-Path $localAppData "Programs\Android Studio\jbr")
        $candidates += (Join-Path $localAppData "JetBrains\Toolbox\apps\AndroidStudio\ch-0")
    }
    if ($programFiles) {
        $candidates += (Join-Path $programFiles "Android\Android Studio\jbr")
    }

    foreach ($candidate in $candidates | Select-Object -Unique) {
        if (Test-JavaHome $candidate) { return $candidate }
    }

    return $null
}

if (-not (Test-Path $GradleWrapper)) {
    Write-Host "Error: gradlew.bat not found at $GradleWrapper" -ForegroundColor Red
    exit 1
}

$JavaHome = Resolve-JavaHome $JavaHome
if (-not $JavaHome) {
    Write-Host "Error: Java runtime not found." -ForegroundColor Red
    Write-Host "Qwen-TTS Studio requires Java $RequiredJavaMajor or newer for Compose desktop." -ForegroundColor Yellow
    Write-Host "Set JAVA_HOME or pass a JDK/JBR path with: .\scripts\run-compose.ps1 -JavaHome `"C:\Path\To\jdk`"" -ForegroundColor Yellow
    exit 1
}

$JavaBin = Join-Path $JavaHome "bin"
$env:JAVA_HOME = $JavaHome
$pathPrefixes = @($JavaBin, $ProjectRoot)
if ($env:CUDA_PATH) {
    $cudaBin = Join-Path $env:CUDA_PATH "bin"
    $cudaBinX64 = Join-Path $env:CUDA_PATH "bin\x64"
    if (Test-Path $cudaBin) { $pathPrefixes += $cudaBin }
    if (Test-Path $cudaBinX64) { $pathPrefixes += $cudaBinX64 }
}
$env:PATH = ($pathPrefixes -join ";") + ";" + $env:PATH
$CudaDll = Join-Path $ProjectRoot "ggml-cuda.dll"
$CudaRuntimeDll = Get-ChildItem -Path $ProjectRoot -Filter "cudart64_*.dll" -File -ErrorAction SilentlyContinue | Select-Object -First 1
$ExistingCudaBackend = (Test-Path $CudaDll) -and $null -ne $CudaRuntimeDll
if ($Cuda) {
    $env:QWEN_TTS_BACKEND = "cuda"
}

Write-Host "Starting Qwen-TTS Studio Compose Desktop..." -ForegroundColor Cyan
Write-Host "Project: $ProjectRoot"
Write-Host "Java: $JavaHome"
Write-Host "Build native before run: $BuildNative"
Write-Host "Requested CUDA backend: $Cuda"
Write-Host "Existing CUDA backend DLLs: $ExistingCudaBackend"
Write-Host "-------------------------------------------"

if ($BuildNative) {
    $nativeArgs = @()
    if ($Cuda) { $nativeArgs += "-Cuda" }
    if ($UseNinja) { $nativeArgs += "-UseNinja" }
    if ($CleanNative) { $nativeArgs += "-Clean" }

    if ($DryRun) {
        Write-Host "Dry run: would execute scripts\build-native.ps1 $($nativeArgs -join ' ')"
    } else {
        & (Join-Path $ScriptDir "build-native.ps1") @nativeArgs
        if ($LASTEXITCODE -ne 0) {
            throw "Native build failed with exit code $LASTEXITCODE"
        }
    }
}

Set-Location $ProjectRoot
if ($DryRun) {
    Write-Host "Dry run: would execute $GradleWrapper :composeApp:run"
    exit 0
}

& $GradleWrapper ":composeApp:run"
