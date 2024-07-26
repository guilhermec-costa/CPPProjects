#!/sbin/env bash
debug_build_path="./out/build/"
cmake -S ./ -B ./out/build/ && cd ./out/build/ && make

