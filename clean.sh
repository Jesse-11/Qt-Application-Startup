#!/bin/bash

# Remove build directory
rm -rf build

# Remove CMake generated files
rm -f CMakeCache.txt
rm -rf CMakeFiles
rm -f cmake_install.cmake
rm -f Makefile

# Remove Qt generated files
find . -name "moc_*.cpp" -delete
find . -name "ui_*.h" -delete
find . -name "qrc_*.cpp" -delete

# Remove any object files or executables
find . -name "*.o" -delete
find . -name "*.exe" -delete

echo "Project cleaned."