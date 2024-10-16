#!/bin/bash

# Suppress Qt warnings about runtime directory permissions
export QT_LOGGING_RULES="qt.qpa.xcb=false"

# Run the actual application
./SampleApp "$@"