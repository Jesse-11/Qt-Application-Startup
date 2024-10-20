#!/bin/bash

function setup_app() {
    echo "Setting up the dependencies..."
    python3 setup.py
}

function build_app() {
    echo "Building the application..."
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
}

function run_app() {
    echo "Running the application..."
    ./build/SampleApp
}

function clean_app() {
    echo "Cleaning the application..."
    ./clean.sh
}

case "$1" in
    setup)
        setup_app
        ;;
    build)
        build_app
        ;;
    run)
        run_app
        ;;
    clean)
        clean_app
        ;;
    all)
        build_app
        run_app
        ;;
    *)
        echo "Usage: $0 {setup|build|run|clean|all}"
        echo "  setup: Run initial setup and install dependencies"
        echo "  build: Compile the application"
        echo "  run: Run the compiled application"
        echo "  clean: Clean build files"
        echo "  all: Build and run the application"
        exit 1
esac