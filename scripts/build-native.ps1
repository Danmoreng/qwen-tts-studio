param(
    [string]$Configuration = "Release",
    [string]$Platform = "x64",
    [switch]$CopyToRoot = $true,
    [switch]$Cuda,
    [switch]$UseNinja,
    [switch]$Clean
)

$ErrorActionPreference = "Stop"

function Test-JniSdkHome([string]$PathCandidate) {
    if ([string]::IsNullOrWhiteSpace($PathCandidate)) { return $false }
    $required = @(
        (Join-Path $PathCandidate "include\jni.h"),
        (Join-Path $PathCandidate "include\win32\jni_md.h"),
        (Join-Path $PathCandidate "lib\jawt.lib"),
        (Join-Path $PathCandidate "lib\jvm.lib")
    )
    foreach ($p in $required) {
        if (-not (Test-Path $p)) { return $false }
    }
    return $true
}

function Resolve-JniSdkHome {
    if (Test-JniSdkHome $env:JAVA_HOME) {
        return $env:JAVA_HOME
    }

    $candidates = @()
    $userProfile = $env:USERPROFILE
    $localAppData = [Environment]::GetFolderPath("LocalApplicationData")
    $programFiles = ${env:ProgramFiles}

    $gradleJdks = Join-Path $userProfile ".gradle\jdks"
    if (Test-Path $gradleJdks) {
        $candidates += Get-ChildItem $gradleJdks -Directory -ErrorAction SilentlyContinue |
            Sort-Object LastWriteTime -Descending |
            ForEach-Object { $_.FullName }
    }

    $javaCmd = Get-Command java -ErrorAction SilentlyContinue
    if ($javaCmd -and $javaCmd.Path) {
        $candidates += (Split-Path -Parent (Split-Path -Parent $javaCmd.Path))
    }

    $candidates += (Join-Path $localAppData "Programs\Android Studio\jbr")
    $candidates += (Join-Path $programFiles "Android\Android Studio\jbr")

    foreach ($candidate in $candidates | Select-Object -Unique) {
        if (Test-JniSdkHome $candidate) {
            return $candidate
        }
    }
    return $null
}

function Import-VSEnv {
    $vswhere = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"
    if (-not (Test-Path $vswhere)) { return $false }

    $vsRoot = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath 2>$null
    if ([string]::IsNullOrWhiteSpace($vsRoot)) { return $false }

    $vcvars = Join-Path $vsRoot "VC\Auxiliary\Build\vcvars64.bat"
    if (-not (Test-Path $vcvars)) { return $false }

    Write-Host "Loading Visual Studio C++ environment..." -ForegroundColor DarkCyan
    $envDump = cmd /c "call `"$vcvars`" > nul && set"
    foreach ($line in $envDump) {
        if ($line -match "^([^=]+)=(.*)$") {
            Set-Item -Path "Env:$($matches[1])" -Value $matches[2]
        }
    }
    return $true
}

$RepoRoot = Split-Path -Parent $PSScriptRoot
$ExternalDir = Join-Path $RepoRoot "external"
$hasNinja = $null -ne (Get-Command ninja -ErrorAction SilentlyContinue)
$generator = if ($UseNinja -or $hasNinja) { "Ninja" } else { $null }
$generatorSuffix = if ($generator) { "ninja" } else { "msvc" }
$BuildDirName = if ($Cuda) { "build-cuda-$generatorSuffix" } else { "build-$generatorSuffix" }
$BuildDir = Join-Path $ExternalDir $BuildDirName
if ($Clean -and (Test-Path $BuildDir)) {
    Write-Host "Cleaning build directory: $BuildDir" -ForegroundColor Cyan
    Remove-Item -Recurse -Force $BuildDir
}

if ($generator) {
    $BinDir = Join-Path $BuildDir "bin"
    $SharedDir = $BuildDir
} else {
    $BinDir = Join-Path $BuildDir "bin\$Configuration"
    $SharedDir = Join-Path $BuildDir $Configuration
}

$jniSdk = Resolve-JniSdkHome
if (-not $jniSdk) {
    throw @"
No full JDK with JNI development files found.
Set JAVA_HOME to a JDK containing include/jni.h and lib/jawt.lib (e.g. a Gradle-downloaded JDK).
"@
}
$env:JAVA_HOME = $jniSdk
$env:Path = (Join-Path $jniSdk "bin") + ";" + $env:Path
Write-Host "Using JNI JDK: $jniSdk" -ForegroundColor DarkCyan

if ($generator) {
    if (-not (Get-Command cl.exe -ErrorAction SilentlyContinue)) {
        $loaded = Import-VSEnv
        if (-not $loaded) {
            throw "Ninja build requires MSVC toolchain (cl.exe), but Visual Studio Build Tools environment could not be loaded."
        }
    }
    if (-not (Get-Command cl.exe -ErrorAction SilentlyContinue)) {
        throw "MSVC compiler (cl.exe) not found on PATH after loading Visual Studio environment."
    }
}

Write-Host "Configuring native build (CUDA=$Cuda)..." -ForegroundColor Cyan
$cmakeArgs = @("-S", $ExternalDir, "-B", $BuildDir)
if ($generator) {
    $cmakeArgs += @("-G", $generator)
    $cmakeArgs += @("-DCMAKE_BUILD_TYPE=$Configuration")
    Write-Host "Using CMake generator: $generator" -ForegroundColor DarkCyan
} else {
    $cmakeArgs += @("-A", $Platform)
    Write-Host "Using CMake generator: Visual Studio ($Platform)" -ForegroundColor DarkCyan
}
if ($Cuda) {
    $cmakeArgs += @("-DQWEN3_TTS_CUDA=ON", "-DGGML_CUDA=ON")
} else {
    $cmakeArgs += @("-DQWEN3_TTS_CUDA=OFF", "-DGGML_CUDA=OFF")
}
cmake @cmakeArgs
if ($LASTEXITCODE -ne 0) {
    throw "CMake configure failed with exit code $LASTEXITCODE"
}

Write-Host "Building native JNI library..." -ForegroundColor Cyan
$buildArgs = @("--build", $BuildDir, "--target", "qwen3_tts_shared")
if (-not $generator) {
    $buildArgs += @("--config", $Configuration)
}
cmake @buildArgs
if ($LASTEXITCODE -ne 0) {
    throw "CMake build failed with exit code $LASTEXITCODE"
}

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

$OptionalNativeFiles = @()
if ($Cuda) {
    $cudaBackend = Join-Path $BinDir "ggml-cuda.dll"
    if (-not (Test-Path $cudaBackend)) {
        throw "CUDA build requested, but missing backend DLL: $cudaBackend"
    }
    $OptionalNativeFiles += $cudaBackend

    if ($env:CUDA_PATH) {
        $cudaBinCandidates = @(
            (Join-Path $env:CUDA_PATH "bin"),
            (Join-Path $env:CUDA_PATH "bin\x64")
        ) | Select-Object -Unique

        $cudaRuntimePatterns = @("cudart64_*.dll", "cublas64_*.dll", "cublasLt64_*.dll")
        foreach ($pattern in $cudaRuntimePatterns) {
            $dll = $null
            foreach ($cudaBin in $cudaBinCandidates) {
                if (-not (Test-Path $cudaBin)) {
                    continue
                }

                $dll = Get-ChildItem -Path $cudaBin -Filter $pattern -File -ErrorAction SilentlyContinue |
                    Sort-Object LastWriteTime -Descending |
                    Select-Object -First 1
                if ($dll) {
                    break
                }
            }

            if ($dll) {
                $OptionalNativeFiles += $dll.FullName
            }
        }
    }
}

if ($CopyToRoot) {
    Write-Host "Copying native DLLs to repository root..." -ForegroundColor Cyan
    foreach ($f in ($NativeFiles + $OptionalNativeFiles)) {
        Copy-Item $f $RepoRoot -Force
    }
}

Write-Host "Native build complete." -ForegroundColor Green

