#!/bin/sh

if [ ! -d "build/CMakeFiles" ]; then
    cd build/
    cmake ..
    cd ..
fi

cd build/
make
cd ..
./bin/main
