#!/bin/bash

# Function to check if a command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Function to check if Qt Charts is installed on Debian
check_qt_charts_debian() {
    dpkg -l | grep -q libqt5charts5-dev
    return $?
}

# Function to install Qt on Debian-based systems
install_qt_debian() {
    echo "Installing Qt..."
    sudo apt-get update
    sudo apt-get install -y qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools libqt5charts5-dev
    
    # Check if installation was successful
    if ! command_exists qmake; then
        echo "Qt installation failed. Please install manually using the following commands:"
        echo "sudo apt-get update"
        echo "sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools libqt5charts5-dev"
        return 1
    fi
    return 0
}

# Function to install Qt Charts on Debian
install_qt_charts_debian() {
    echo "Installing Qt Charts..."
    sudo apt-get update
    sudo apt-get install -y libqt5charts5-dev
    
    # Verify charts installation
    if ! check_qt_charts_debian; then
        echo "Qt Charts installation failed. Please install manually using:"
        echo "sudo apt-get install libqt5charts5-dev"
        return 1
    fi
    return 0
}

# Function to install Qt on Red Hat-based systems
install_qt_redhat() {
    echo "Installing Qt..."
    sudo dnf install -y qt5-qtbase-devel qt5-qtcharts-devel
    
    # Check if installation was successful
    if ! command_exists qmake; then
        echo "Qt installation failed. Please install manually using the following command:"
        echo "sudo dnf install qt5-qtbase-devel qt5-qtcharts-devel"
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


    # Always check for Qt Charts, even if Qt is installed
    if ! check_qt_charts_debian; then
        install_qt_charts_debian || exit 1
    else
        echo "Qt Charts is already installed."
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

# Check if build was successful and SampleApp was created
if [ $? -eq 0 ] && [ -f "./SampleApp" ]; then
    echo "Build successful."
else
    echo "Build failed or SampleApp not created. Please check the error messages above."
    exit 1
fi

# Create run_app.sh
echo '#!/bin/bash
export QT_LOGGING_RULES="qt.qpa.xcb=false"
if [ -f "./SampleApp" ]; then
    ./SampleApp "$@"
else
    echo "Error: SampleApp not found. Please ensure the build was successful."
    exit 1
fi' > run_app.sh

chmod +x run_app.sh
echo "Setup complete. You can now run the application with ./run_app.sh"