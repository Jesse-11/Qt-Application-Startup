#!/bin/bash

# Function to check if a command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Check if we're on a Debian-based system
if command_exists apt-get; then
    echo "Debian-based system detected."
    
    # Check if Qt is installed
    if ! command_exists qmake; then
        echo "Qt not found. Installing..."
        sudo apt-get update
        sudo apt-get install -y qt5-default qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
    else
        echo "Qt is already installed."
    fi

# Check if we're on a Red Hat-based system
elif command_exists dnf; then
    echo "Red Hat-based system detected."
    
    # Check if Qt is installed
    if ! command_exists qmake; then
        echo "Qt not found. Installing..."
        sudo dnf install -y qt5-qtbase-devel
    else
        echo "Qt is already installed."
    fi

else
    echo "Unsupported system. Please install Qt manually."
    exit 1
fi

# Check if installation was successful
if command_exists qmake; then
    echo "Qt installation successful."
    qmake --version
else
    echo "Qt installation failed. Please install manually."
    exit 1
fi

# Run qmake and make
echo "Building the project..."
qmake SampleApp.pro
make

echo "Setup complete. You can now run the application with ./SampleApp"