param(
    [string]$Configuration = "Release",
    [switch]$BuildMsi,
    [int]$GradleRetries = 3,
    [switch]$Cuda,
    [switch]$UseNinja
)

$ErrorActionPreference = "Stop"

$RepoRoot = Split-Path -Parent $PSScriptRoot
$ComposeAppDir = Join-Path $RepoRoot "composeApp"
$GradleWrapper = Join-Path $RepoRoot "gradlew.bat"

function Test-JavaHome([string]$JavaHomePath, [switch]$RequireJPackage) {
    if ([string]::IsNullOrWhiteSpace($JavaHomePath)) { return $false }

    $required = @("bin\java.exe")
    if ($RequireJPackage) {
        $required += "bin\jpackage.exe"
    }

    foreach ($relativePath in $required) {
        if (-not (Test-Path (Join-Path $JavaHomePath $relativePath))) {
            return $false
        }
    }

    return $true
}

function Resolve-JavaHome([switch]$RequireJPackage) {
    if (Test-JavaHome $env:JAVA_HOME -RequireJPackage:$RequireJPackage) {
        return $env:JAVA_HOME
    }

    $javaCmd = Get-Command java -ErrorAction SilentlyContinue
    if ($javaCmd -and $javaCmd.Path) {
        $javaHome = Split-Path -Parent (Split-Path -Parent $javaCmd.Path)
        if (Test-JavaHome $javaHome -RequireJPackage:$RequireJPackage) {
            return $javaHome
        }
    }

    $candidates = @()
    $localAppData = [Environment]::GetFolderPath("LocalApplicationData")
    $programFiles = ${env:ProgramFiles}
    $userProfile = $env:USERPROFILE

    $candidates += (Join-Path $localAppData "Programs\Android Studio\jbr")
    $candidates += (Join-Path $programFiles "Android\Android Studio\jbr")
    $candidates += (Join-Path $localAppData "JetBrains\Toolbox\apps\AndroidStudio\ch-0")

    $gradleJdks = Join-Path $userProfile ".gradle\jdks"
    if (Test-Path $gradleJdks) {
        $latestGradleJdk = Get-ChildItem $gradleJdks -Directory -ErrorAction SilentlyContinue |
            Where-Object { Test-JavaHome $_.FullName -RequireJPackage:$RequireJPackage } |
            Sort-Object LastWriteTime -Descending |
            Select-Object -First 1
        if ($latestGradleJdk) {
            $candidates += $latestGradleJdk.FullName
        }
    }

    foreach ($candidate in $candidates) {
        if (Test-JavaHome $candidate -RequireJPackage:$RequireJPackage) {
            return $candidate
        }
    }

    return $null
}

function Invoke-Gradle([string[]]$Tasks, [int]$Retries = 1) {
    $attempt = 1
    while ($attempt -le [Math]::Max($Retries, 1)) {
        Write-Host "Running Gradle (attempt $attempt/$Retries): $($Tasks -join ' ')" -ForegroundColor DarkCyan
        & $GradleWrapper `
            "-Dorg.gradle.internal.http.connectionTimeout=120000" `
            "-Dorg.gradle.internal.http.socketTimeout=180000" `
            @Tasks

        if ($LASTEXITCODE -eq 0) {
            return
        }

        if ($attempt -lt $Retries) {
            Start-Sleep -Seconds (5 * $attempt)
        }
        $attempt++
    }

    throw "Gradle failed (exit code $LASTEXITCODE): $($Tasks -join ' ')"
}

if (-not (Test-Path $GradleWrapper)) {
    throw "gradlew.bat not found at $GradleWrapper"
}

$ResolvedJavaHome = Resolve-JavaHome -RequireJPackage
if (-not $ResolvedJavaHome) {
    throw @"
No Java runtime with jpackage found for Gradle packaging.
Set JAVA_HOME manually to a full JDK/JBR, or install Android Studio / IntelliJ (JBR), then retry.
"@
}

$env:JAVA_HOME = $ResolvedJavaHome
$env:Path = (Join-Path $ResolvedJavaHome "bin") + ";" + $env:Path
Write-Host "Using JAVA_HOME: $ResolvedJavaHome" -ForegroundColor DarkCyan

Write-Host "Step 1/3: Build native DLLs..." -ForegroundColor Cyan
& (Join-Path $PSScriptRoot "build-native.ps1") -Configuration $Configuration -CopyToRoot -Cuda:$Cuda -UseNinja:$UseNinja

Write-Host "Step 2/3: Build Compose distributable..." -ForegroundColor Cyan
Invoke-Gradle @(":composeApp:createDistributable") -Retries $GradleRetries

if ($BuildMsi) {
    Write-Host "Building MSI installer..." -ForegroundColor Cyan
    try {
        Invoke-Gradle @(":composeApp:packageMsi") -Retries $GradleRetries
    } catch {
        Write-Warning "MSI packaging failed. Portable app is still usable."
        Write-Warning $_
    }
}

$AppRoot = Join-Path $ComposeAppDir "build\compose\binaries\main\app\qwen-tts-studio"
if (-not (Test-Path $AppRoot)) {
    throw "Could not find packaged app root: $AppRoot"
}

$NativeDlls = @("qwen3_tts.dll", "ggml.dll", "ggml-base.dll", "ggml-cpu.dll")
if ($Cuda) {
    $cudaBackend = Join-Path $RepoRoot "ggml-cuda.dll"
    if (-not (Test-Path $cudaBackend)) {
        throw "CUDA packaging requested, but missing backend DLL: $cudaBackend"
    }

    $NativeDlls += "ggml-cuda.dll"

    $cudaRuntimeCopied = $false
    $cudaRuntimePatterns = @("cudart64_*.dll", "cublas64_*.dll", "cublasLt64_*.dll")
    foreach ($pattern in $cudaRuntimePatterns) {
        $runtimeDll = Get-ChildItem -Path $RepoRoot -Filter $pattern -File -ErrorAction SilentlyContinue |
            Sort-Object LastWriteTime -Descending |
            Select-Object -First 1
        if ($runtimeDll) {
            $NativeDlls += $runtimeDll.Name
            $cudaRuntimeCopied = $true
        }
    }

    if (-not $cudaRuntimeCopied) {
        Write-Warning "CUDA packaging was requested, but CUDA runtime DLLs were not found in the repo root. The packaged app may require a local CUDA installation on the target machine."
    }
}
$NativeDlls = $NativeDlls | Select-Object -Unique
Write-Host "Step 3/3: Copy native DLLs into packaged app..." -ForegroundColor Cyan
foreach ($dll in $NativeDlls) {
    $src = Join-Path $RepoRoot $dll
    if (-not (Test-Path $src)) {
        throw "Missing native DLL in repo root: $src"
    }
    Copy-Item $src $AppRoot -Force
}

Write-Host "Packaging complete." -ForegroundColor Green
Write-Host "Portable app: $AppRoot" -ForegroundColor Green
if ($BuildMsi) {
    Write-Host "MSI output is under: composeApp\build\compose\binaries\main\msi" -ForegroundColor Green
}
