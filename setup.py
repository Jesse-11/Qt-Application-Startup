import os
import subprocess
import sys
import platform
import shutil

# Created Using AI SUPPORT and human modification. Multi os install to help mult member collaboration

def command_exists(cmd):
    return subprocess.call(["which", cmd] if platform.system() != "Windows" else ["where", cmd],
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL) == 0

def install_cmake():
    system = platform.system().lower()
    if system == "linux":
        if command_exists("apt-get"):
            subprocess.run(["sudo", "apt-get", "update"])
            subprocess.run(["sudo", "apt-get", "install", "-y", "cmake"])
        elif command_exists("dnf"):
            subprocess.run(["sudo", "dnf", "install", "-y", "cmake"])
        else:
            print("Unsupported Linux distribution. Please install CMake manually.")
            print("Visit https://cmake.org/download/ for installation instructions.")
            sys.exit(1)
    elif system == "darwin":
        if command_exists("brew"):
            subprocess.run(["brew", "install", "cmake"])
        else:
            print("Homebrew not found. Please install Homebrew and then run: brew install cmake")
            print("Or visit https://cmake.org/download/ for alternative installation methods.")
            sys.exit(1)
    elif system == "windows":
        print("Please download and install CMake from https://cmake.org/download/")
        print("Make sure to add CMake to your PATH during installation.")
        sys.exit(1)
    else:
        print(f"Unsupported operating system: {system}")
        sys.exit(1)

def install_qt5():
    system = platform.system().lower()
    if system == "linux":
        if command_exists("apt-get"):
            subprocess.run(["sudo", "apt-get", "update"])
            subprocess.run(["sudo", "apt-get", "install", "-y", "qtbase5-dev", "qt5-qmake", "qtbase5-dev-tools"])
        elif command_exists("dnf"):
            subprocess.run(["sudo", "dnf", "install", "-y", "qt5-qtbase-devel"])
        else:
            print("Unsupported Linux distribution. Please install Qt5 manually.")
            sys.exit(1)
    elif system == "darwin":
        if command_exists("brew"):
            subprocess.run(["brew", "install", "qt@5"])
        else:
            print("Homebrew not found. Please install Homebrew and then run: brew install qt@5")
            sys.exit(1)
    elif system == "windows":
        print("Please download and install Qt5 from https://www.qt.io/download-open-source")
        print("Then add the Qt5 bin directory to your PATH environment variable.")
        sys.exit(1)
    else:
        print(f"Unsupported operating system: {system}")
        sys.exit(1)

def create_windows_batch_file():
    batch_content = '''
@echo off
setlocal enabledelayedexpansion

if "%1"=="setup" (
    call :setup_app
) else if "%1"=="build" (
    call :build_app
) else if "%1"=="run" (
    call :run_app
) else if "%1"=="clean" (
    call :clean_app
) else if "%1"=="all" (
    call :build_app
    call :run_app
) else (
    echo Usage: %0 {setup^|build^|run^|clean^|all}
    echo   setup: Run initial setup and install dependencies
    echo   build: Compile the application
    echo   run: Run the compiled application
    echo   clean: Clean build files
    echo   all: Build and run the application
    exit /b 1
)
exit /b 0

:setup_app
echo Setting up the application...
python setup.py
exit /b 0

:build_app
echo Building the application...
if not exist build mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
cd ..
exit /b 0

:run_app
echo Running the application...
.\\build\\SampleApp.exe
exit /b 0

:clean_app
echo Cleaning the application...
if exist build rmdir /s /q build
if exist CMakeCache.txt del CMakeCache.txt
if exist CMakeFiles rmdir /s /q CMakeFiles
exit /b 0
'''
    with open('manage_app.bat', 'w') as bat_file:
        bat_file.write(batch_content)

def grant_execute_permissions():
    if platform.system() != "Windows":
        print("Granting execute permissions to manage_app.sh and clean.sh...")
        subprocess.run(["chmod", "+x", "manage_app.sh"])
        subprocess.run(["chmod", "+x", "clean.sh"])
    else:
        create_windows_batch_file()
        print("Created manage_app.bat for Windows users.")


def main():
    if not command_exists("cmake"):
        print("CMake not found. Attempting to install...")
        install_cmake()
        if not command_exists("cmake"):
            print("CMake installation failed. Please install CMake manually and try again.")
            sys.exit(1)
    
    if not command_exists("qmake") or not command_exists("moc"):
        print("Qt5 not found or incomplete. Attempting to install...")
        install_qt5()
        if not command_exists("qmake") or not command_exists("moc"):
            print("Qt5 installation failed. Please install Qt5 manually and try again.")
            sys.exit(1)

    grant_execute_permissions()

    if platform.system() == "Windows":
        print("Setup complete. You can now use manage_app.bat for building and running the application.")
        print("Use 'manage_app.bat build' to build, 'manage_app.bat run' to run, and 'manage_app.bat clean' to clean the project.")
    else:
        print("Setup complete. You can now use ./manage_app.sh for building and running the application.")
        print("Use './manage_app.sh build' to build, './manage_app.sh run' to run, and './clean.sh' to clean the project.")

if __name__ == "__main__":
    main()