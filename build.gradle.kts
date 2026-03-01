import org.gradle.api.tasks.Exec
import java.io.ByteArrayOutputStream

plugins {
    // this is necessary to avoid the plugins to be loaded multiple times
    // in each subproject's classloader
    alias(libs.plugins.androidApplication) apply false
    alias(libs.plugins.androidLibrary) apply false
    alias(libs.plugins.jetbrainsCompose) apply false
    alias(libs.plugins.compose.compiler) apply false
    alias(libs.plugins.kotlinMultiplatform) apply false
}

fun detectPowerShellExecutable(): String {
    return try {
        val process = ProcessBuilder("where", "pwsh.exe")
            .redirectErrorStream(true)
            .start()
        val output = process.inputStream.bufferedReader().use { it.readText() }
        val exitCode = process.waitFor()
        if (exitCode == 0 && output.isNotBlank()) "pwsh.exe" else "powershell.exe"
    } catch (_: Exception) {
        "powershell.exe"
    }
}

fun Exec.configureNativeScript(scriptRelativePath: String, vararg scriptArgs: String) {
    doFirst {
        if (!org.gradle.internal.os.OperatingSystem.current().isWindows) {
            throw GradleException("Native Windows build scripts are only supported on Windows.")
        }
        val shell = detectPowerShellExecutable()
        val scriptFile = project.layout.projectDirectory.file(scriptRelativePath).asFile
        this@configureNativeScript.commandLine(
            shell,
            "-NoProfile",
            "-ExecutionPolicy",
            "Bypass",
            "-File",
            scriptFile.absolutePath,
            *scriptArgs
        )
        this@configureNativeScript.workingDir = project.layout.projectDirectory.asFile
    }
}

tasks.register<Exec>("nativeBuild") {
    group = "native"
    description = "Build native JNI backend (CPU)."
    configureNativeScript("scripts/build-native.ps1")
}

tasks.register<Exec>("nativeBuildCuda") {
    group = "native"
    description = "Build native JNI backend with CUDA support."
    configureNativeScript("scripts/build-native.ps1", "-Cuda")
}

tasks.register<Exec>("packageWindows") {
    group = "distribution"
    description = "Build Windows portable package (CPU)."
    configureNativeScript("scripts/package-windows.ps1")
}

tasks.register<Exec>("packageWindowsCuda") {
    group = "distribution"
    description = "Build Windows portable package with CUDA backend."
    configureNativeScript("scripts/package-windows.ps1", "-Cuda")
}
