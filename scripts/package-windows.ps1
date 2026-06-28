param(
    [string]$Configuration = "Release",
    [switch]$BuildMsi,
    [switch]$RequireMsi,
    [switch]$SkipNativeBuild,
    [switch]$Clean,
    [int]$GradleRetries = 3,
    [switch]$Cuda,
    [switch]$UseNinja,
    [switch]$BundleCudaRuntime
)

$ErrorActionPreference = "Stop"

$RepoRoot = Split-Path -Parent $PSScriptRoot
$ComposeAppDir = Join-Path $RepoRoot "composeApp"
$GradleWrapper = Join-Path $RepoRoot "gradlew.bat"
$PackageName = "qwen-tts-studio"
$PackageVersion = if ([string]::IsNullOrWhiteSpace($env:APP_VERSION)) { "1.0.0" } else { $env:APP_VERSION }
$PreferredJavaMajor = if ([string]::IsNullOrWhiteSpace($env:PACKAGE_JAVA_MAJOR)) { 25 } else { [int]$env:PACKAGE_JAVA_MAJOR }
$PortableCudaArchitectures = if ([string]::IsNullOrWhiteSpace($env:QWEN_TTS_PACKAGE_CUDA_ARCHITECTURES)) {
    "75-real;80-real;86-real;89-real;90-real;100-real;110-real;120-real"
} else {
    $env:QWEN_TTS_PACKAGE_CUDA_ARCHITECTURES
}

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

function Get-JavaMajorVersion([string]$JavaHomePath) {
    if (-not (Test-JavaHome $JavaHomePath)) { return $null }

    try {
        $versionOutput = & (Join-Path $JavaHomePath "bin\java.exe") "-version" 2>&1 |
            Select-Object -First 1
        if ($versionOutput -match '"(\d+)(?:\.|")') {
            return [int]$Matches[1]
        }
    } catch {
        return $null
    }

    return $null
}

function Resolve-JavaHome([switch]$RequireJPackage) {
    $candidates = @()

    if (-not [string]::IsNullOrWhiteSpace($env:JAVA_HOME)) {
        $candidates += $env:JAVA_HOME
    }

    $javaCmd = Get-Command java -ErrorAction SilentlyContinue
    if ($javaCmd -and $javaCmd.Path) {
        $javaHome = Split-Path -Parent (Split-Path -Parent $javaCmd.Path)
        $candidates += $javaHome
    }

    $localAppData = [Environment]::GetFolderPath("LocalApplicationData")
    $programFiles = ${env:ProgramFiles}
    $userProfile = $env:USERPROFILE

    $candidates += (Join-Path $localAppData "Programs\Android Studio\jbr")
    $candidates += (Join-Path $programFiles "Android\Android Studio\jbr")
    $candidates += (Join-Path $localAppData "JetBrains\Toolbox\apps\AndroidStudio\ch-0")

    $gradleJdks = Join-Path $userProfile ".gradle\jdks"
    if (Test-Path $gradleJdks) {
        $candidates += Get-ChildItem $gradleJdks -Directory -ErrorAction SilentlyContinue |
            Where-Object { Test-JavaHome $_.FullName -RequireJPackage:$RequireJPackage } |
            Sort-Object LastWriteTime -Descending |
            ForEach-Object { $_.FullName }
    }

    $validCandidates = $candidates |
        Where-Object { Test-JavaHome $_ -RequireJPackage:$RequireJPackage } |
        Select-Object -Unique

    $preferredJdk = $validCandidates |
        Where-Object { (Get-JavaMajorVersion $_) -eq $PreferredJavaMajor } |
        Select-Object -First 1
    if ($preferredJdk) {
        return $preferredJdk
    }

    foreach ($candidate in $validCandidates) {
        return $candidate
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

function Find-CudaRuntimeDlls {
    $patterns = @("cudart64_*.dll", "cublas64_*.dll", "cublasLt64_*.dll")
    $searchDirs = @($RepoRoot)

    foreach ($cudaRoot in @($env:CUDA_PATH, $env:CUDAToolkit_ROOT)) {
        if (-not [string]::IsNullOrWhiteSpace($cudaRoot)) {
            $searchDirs += (Join-Path $cudaRoot "bin")
            $searchDirs += (Join-Path $cudaRoot "bin\x64")
        }
    }

    $cudaBase = "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA"
    if (Test-Path $cudaBase) {
        $searchDirs += Get-ChildItem -Path $cudaBase -Directory -ErrorAction SilentlyContinue |
            Sort-Object Name -Descending |
            ForEach-Object {
                Join-Path $_.FullName "bin"
                Join-Path $_.FullName "bin\x64"
            }
    }

    $runtimeDlls = @()
    foreach ($pattern in $patterns) {
        $dll = $null
        foreach ($dir in ($searchDirs | Select-Object -Unique)) {
            if (-not (Test-Path $dir)) {
                continue
            }

            $dll = Get-ChildItem -Path $dir -Filter $pattern -File -ErrorAction SilentlyContinue |
                Sort-Object LastWriteTime -Descending |
                Select-Object -First 1
            if ($dll) {
                break
            }
        }

        if ($dll) {
            $runtimeDlls += $dll
        }
    }

    return $runtimeDlls
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
    $nativeBuildArgs = @("-Configuration", $Configuration, "-CopyToRoot")
    if ($Cuda) {
        $nativeBuildArgs += "-Cuda"
        $nativeBuildArgs += @("-CudaArchitectures", $PortableCudaArchitectures)
    }
    if ($UseNinja) { $nativeBuildArgs += "-UseNinja" }
    if ($Clean) { $nativeBuildArgs += "-Clean" }
    & (Join-Path $PSScriptRoot "build-native.ps1") @nativeBuildArgs
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

    if ($BundleCudaRuntime) {
        $cudaRuntimeDlls = Find-CudaRuntimeDlls
        foreach ($runtimeDll in $cudaRuntimeDlls) {
            $destination = Join-Path $RepoRoot $runtimeDll.Name
            $sourcePath = [System.IO.Path]::GetFullPath($runtimeDll.FullName)
            $destinationPath = [System.IO.Path]::GetFullPath($destination)
            if ($sourcePath -ine $destinationPath) {
                Copy-Item $runtimeDll.FullName $destination -Force
            }
            $NativeDlls += $runtimeDll.Name
        }

        if ($cudaRuntimeDlls.Count -eq 0) {
            Write-Warning "CUDA runtime bundling was requested, but CUDA runtime DLLs were not found. The packaged app may require a local CUDA installation on the target machine."
        }
    } else {
        Write-Host "CUDA runtime DLLs will not be bundled. The target machine must provide CUDA runtime DLLs via CUDA_PATH or PATH." -ForegroundColor Yellow
    }
}
$NativeDlls = $NativeDlls | Select-Object -Unique
Write-Host "Step 3/4: Copy native DLLs into packaged app..." -ForegroundColor Cyan

$staleNativePatterns = @(
    "qwen3_tts.dll",
    "ggml*.dll",
    "cudart64_*.dll",
    "cublas64_*.dll",
    "cublasLt64_*.dll"
)
foreach ($pattern in $staleNativePatterns) {
    Get-ChildItem -Path $AppRoot -Filter $pattern -File -ErrorAction SilentlyContinue |
        Remove-Item -Force
}

foreach ($dll in $NativeDlls) {
    $src = Join-Path $RepoRoot $dll
    if (-not (Test-Path $src)) {
        throw "Missing native DLL in repo root: $src"
    }
    Copy-Item $src $AppRoot -Force
}

$DebugLauncherPath = Join-Path $AppRoot "$PackageName-debug.ps1"
@'
$ErrorActionPreference = "Stop"

$appRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$logDir = Join-Path $appRoot "logs"
New-Item -ItemType Directory -Path $logDir -Force | Out-Null

$timestamp = Get-Date -Format "yyyyMMdd-HHmmss"
$logFile = Join-Path $logDir "qwen-tts-studio-$timestamp.log"
$env:PATH = "$appRoot;$env:PATH"

Write-Host "Starting Qwen-TTS Studio with native logging..."
Write-Host "Log file: $logFile"

& (Join-Path $appRoot "qwen-tts-studio.exe") *> $logFile
$exitCode = $LASTEXITCODE

Write-Host "Qwen-TTS Studio exited with code $exitCode"
Write-Host "Log file: $logFile"
exit $exitCode
'@ | Set-Content -Path $DebugLauncherPath -Encoding UTF8

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
