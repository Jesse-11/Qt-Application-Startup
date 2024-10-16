#!/bin/bash
export QT_LOGGING_RULES="qt.qpa.xcb=false"
if [ -f "./SampleApp" ]; then
    ./SampleApp "$@"
else
    echo "Error: SampleApp not found. Please ensure the build was successful."
    exit 1
fi
