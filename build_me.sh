#!/bin/bash

SCRIPT_LOCATION="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

if [ ! -d "build" ]; then
    mkdir build
fi
if [ "$#" -eq 1 ] && [ "$1" = "-d" ]; then
    echo "-- DEBUG MODE"
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
else
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
fi

cmake --build build -j
