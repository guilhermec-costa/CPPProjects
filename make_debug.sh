#!/sbin/env bash
debug_build_path="./out/build/Debug"
if [ ! -d $debug_build_path ]; then
    mkdir $debug_build_path
fi
cmake -S ./ -B ./out/build/Debug/ -DCMAKE_BUILD_TYPE=Debug && cd ./out/build/Debug/ && make

