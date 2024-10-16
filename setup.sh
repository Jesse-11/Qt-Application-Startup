#!/bin/bash

# Function to check if a command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Function to install Qt on Debian-based systems
install_qt_debian() {
    echo "Installing Qt..."
    sudo apt-get update
    sudo apt-get install -y qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
    
    # Check if installation was successful
    if ! command_exists qmake; then
        echo "Qt installation failed. Please install manually using the following commands:"
        echo "sudo apt-get update"
        echo "sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools"
        return 1
    fi
    return 0
}

# Function to install Qt on Red Hat-based systems
install_qt_redhat() {
    echo "Installing Qt..."
    sudo dnf install -y qt5-qtbase-devel
    
    # Check if installation was successful
    if ! command_exists qmake; then
        echo "Qt installation failed. Please install manually using the following command:"
        echo "sudo dnf install qt5-qtbase-devel"
        return 1
    fi
    return 0
}

# Check the operating system and install Qt if necessary
if command_exists apt-get; then
    echo "Debian-based system detected."
    
    if ! command_exists qmake; then
        install_qt_debian || exit 1
    else
        echo "Qt is already installed."
    fi

elif command_exists dnf; then
    echo "Red Hat-based system detected."
    
    if ! command_exists qmake; then
        install_qt_redhat || exit 1
    else
        echo "Qt is already installed."
    fi

else
    echo "Unsupported system. Please install Qt manually."
    exit 1
fi

# Verify Qt installation
echo "Verifying Qt installation..."
qmake --version

# Run qmake and make
echo "Building the project..."
qmake SampleApp.pro
make

# Check if build was successful
if [ $? -eq 0 ]; then
    echo "Build successful. You can now run the application with ./SampleApp"
else
    echo "Build failed. Please check the error messages above."
    exit 1
fi

echo "Setup complete."