import os
import subprocess
import sys
import platform
import shutil

# Created Using AI SUPPORT. Multi os install to help mult member collaboration

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

def grant_execute_permissions():
    if platform.system() != "Windows":
        print("Granting execute permissions to manage_app.sh and clean.sh...")
        subprocess.run(["chmod", "+x", "manage_app.sh"])
        subprocess.run(["chmod", "+x", "clean.sh"])
    else:
        print("Note: On Windows, .sh files are not directly executable.")
        print("You may need to run them using a bash shell or convert them to .bat files.")

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

    print("Setup complete. You can now build and run the application using the manage_app.sh script.")
    print("To build the app run: ./manage_app.sh build")
    print("To run the app run: ./manage_app.sh run")
    print("To clean the build directory run: ./manage_app.sh clean")

if __name__ == "__main__":
    main()