param(
    [string]$Configuration = "Release",
    [switch]$BuildMsi,
    [switch]$RequireMsi,
    [switch]$SkipNativeBuild,
    [switch]$Clean,
    [int]$GradleRetries = 3,
    [switch]$Cuda,
    [switch]$UseNinja
)

$ErrorActionPreference = "Stop"

$RepoRoot = Split-Path -Parent $PSScriptRoot
$ComposeAppDir = Join-Path $RepoRoot "composeApp"
$GradleWrapper = Join-Path $RepoRoot "gradlew.bat"
$PackageName = "qwen-tts-studio"
$PackageVersion = if ([string]::IsNullOrWhiteSpace($env:APP_VERSION)) { "1.0.0" } else { $env:APP_VERSION }

if ($RequireMsi) {
    $BuildMsi = $true
}

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

function Add-WixToolsToPath {
    $candidateDirs = @(
        (Join-Path $RepoRoot "build\wix311"),
        (Join-Path $ComposeAppDir "build\wix311")
    )

    foreach ($dir in $candidateDirs) {
        if ((Test-Path (Join-Path $dir "wix.exe")) -or
            ((Test-Path (Join-Path $dir "candle.exe")) -and (Test-Path (Join-Path $dir "light.exe")))) {
            $env:Path = $dir + ";" + $env:Path
            Write-Host "Using WiX tools: $dir" -ForegroundColor DarkCyan
            return $true
        }
    }

    $wixTool = Get-Command wix.exe -ErrorAction SilentlyContinue
    if ($wixTool) { return $true }

    $candleTool = Get-Command candle.exe -ErrorAction SilentlyContinue
    $lightTool = Get-Command light.exe -ErrorAction SilentlyContinue
    return [bool]($candleTool -and $lightTool)
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

if (-not $SkipNativeBuild) {
    Write-Host "Step 1/4: Build native DLLs..." -ForegroundColor Cyan
    & (Join-Path $PSScriptRoot "build-native.ps1") -Configuration $Configuration -CopyToRoot -Cuda:$Cuda -UseNinja:$UseNinja -Clean:$Clean
    if ($LASTEXITCODE -ne 0) {
        throw "Native build failed with exit code $LASTEXITCODE"
    }
} else {
    Write-Host "Step 1/4: Skipping native build." -ForegroundColor Yellow
}

Write-Host "Step 2/4: Build Compose distributable..." -ForegroundColor Cyan
Invoke-Gradle @(":composeApp:createDistributable") -Retries $GradleRetries

$AppRoot = Join-Path $ComposeAppDir "build\compose\binaries\main\app\$PackageName"
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
Write-Host "Step 3/4: Copy native DLLs into packaged app..." -ForegroundColor Cyan
foreach ($dll in $NativeDlls) {
    $src = Join-Path $RepoRoot $dll
    if (-not (Test-Path $src)) {
        throw "Missing native DLL in repo root: $src"
    }
    Copy-Item $src $AppRoot -Force
}

Write-Host "Step 4/4: Create portable zip..." -ForegroundColor Cyan
$ZipDir = Join-Path $ComposeAppDir "build\compose\binaries\main\portable"
New-Item -ItemType Directory -Path $ZipDir -Force | Out-Null
$ZipPath = Join-Path $ZipDir "$PackageName-windows-portable.zip"
if (Test-Path $ZipPath) {
    Remove-Item $ZipPath -Force
}
Compress-Archive -Path $AppRoot -DestinationPath $ZipPath -Force

if ($BuildMsi) {
    Write-Host "Building MSI installer from packaged app image..." -ForegroundColor Cyan
    if (-not (Add-WixToolsToPath)) {
        throw "WiX tools were not found. Run Gradle packaging once to download WiX or install WiX and retry."
    }

    $MsiDir = Join-Path $ComposeAppDir "build\compose\binaries\main\msi"
    New-Item -ItemType Directory -Path $MsiDir -Force | Out-Null
    Get-ChildItem -Path $MsiDir -Filter "*.msi" -File -ErrorAction SilentlyContinue | Remove-Item -Force

    try {
        & (Join-Path $ResolvedJavaHome "bin\jpackage.exe") `
            "--type" "msi" `
            "--name" $PackageName `
            "--app-image" $AppRoot `
            "--dest" $MsiDir `
            "--app-version" $PackageVersion `
            "--win-menu" `
            "--win-shortcut"

        if ($LASTEXITCODE -ne 0) {
            throw "jpackage failed with exit code $LASTEXITCODE"
        }

        $msi = Get-ChildItem -Path $MsiDir -Filter "*.msi" -File -ErrorAction SilentlyContinue | Select-Object -First 1
        if (-not $msi) {
            throw "jpackage completed but no MSI was written to $MsiDir"
        }
    } catch {
        if ($RequireMsi) {
            throw
        } else {
            Write-Warning "MSI packaging failed. Portable app is still usable."
            Write-Warning $_
        }
    }
}

Write-Host "Packaging complete." -ForegroundColor Green
Write-Host "Portable app: $AppRoot" -ForegroundColor Green
Write-Host "Portable zip: $ZipPath" -ForegroundColor Green
if ($BuildMsi) {
    Write-Host "MSI output is under: composeApp\build\compose\binaries\main\msi" -ForegroundColor Green
}
