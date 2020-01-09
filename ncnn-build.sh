#!/bin/bash

arch=$(uname -i)

if [[ $arch == x86_64* ]]; then
  cmake -D NCNN_VULKAN=OFF ..
elif  [[ $arch == arm* ]]; then
  cmake -D NCNN_VULKAN=OFF \
  -D CMAKE_TOOLCHAIN_FILE=../toolchains/pi3.toolchain.cmake \
  -D PI3=ON ..
fi
