import org.jetbrains.compose.desktop.application.dsl.TargetFormat
import org.jetbrains.compose.desktop.application.tasks.AbstractJPackageTask
import org.gradle.api.tasks.JavaExec
import org.gradle.jvm.toolchain.JavaLanguageVersion
import org.jetbrains.kotlin.gradle.dsl.JvmTarget

plugins {
    alias(libs.plugins.kotlinMultiplatform)
    alias(libs.plugins.jetbrainsCompose)
    alias(libs.plugins.compose.compiler)
}

kotlin {
    jvmToolchain(25)

    jvm("desktop") {
        compilerOptions {
            jvmTarget.set(JvmTarget.fromTarget("25"))
        }
    }

    sourceSets {
        val desktopMain = getByName("desktopMain")
        val commonTest = getByName("commonTest")

        commonMain.dependencies {
            implementation(compose.runtime)
            implementation(compose.foundation)
            implementation(compose.material3)
            implementation(compose.ui)
            implementation(compose.components.resources)
            implementation(compose.components.uiToolingPreview)
            implementation(libs.androidx.lifecycle.viewmodel.compose)
            implementation("org.jetbrains.compose.material:material-icons-extended:1.7.3")
            implementation(libs.kotlinx.coroutines.core)
            implementation(libs.filekit.compose)
        }

        commonTest.dependencies {
            implementation(kotlin("test"))
        }
        
        desktopMain.dependencies {
            implementation(compose.desktop.currentOs)
            implementation(libs.jna)
            implementation(libs.kotlinx.coroutines.swing)
        }
    }
}

tasks.withType<JavaExec>().configureEach {
    javaLauncher.set(
        javaToolchains.launcherFor {
            languageVersion.set(JavaLanguageVersion.of(25))
        }
    )
}

compose.desktop {
    application {
        mainClass = "com.qwen.tts.studio.MainKt"
        javaHome = javaToolchains.launcherFor {
            languageVersion.set(JavaLanguageVersion.of(25))
        }.get().metadata.installationPath.asFile.absolutePath

        jvmArgs += "-Xss16m"
        jvmArgs += "-Djna.protected=false"

        nativeDistributions {
            targetFormats(TargetFormat.Dmg, TargetFormat.Msi, TargetFormat.Deb)
            packageName = "qwen-tts-studio"
            packageVersion = providers.environmentVariable("APP_VERSION").orElse("1.0.0").get()

            modules("java.base", "java.desktop", "java.logging", "java.naming", "java.net.http", "java.sql", "jdk.unsupported", "jdk.security.auth")

            windows {
                iconFile.set(project.file("src/desktopMain/resources/icons/app-icon.ico"))
            }

            linux {
                iconFile.set(project.file("src/desktopMain/resources/icons/app-icon.png"))
            }
        }
    }
}

tasks.withType<AbstractJPackageTask>().configureEach {
    if (name == "createDistributable" && System.getProperty("os.name").startsWith("Windows", ignoreCase = true)) {
        iconFile.set(project.file("src/desktopMain/resources/icons/app-icon.ico"))
    }
}
