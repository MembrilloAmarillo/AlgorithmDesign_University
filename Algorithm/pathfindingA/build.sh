#!/bin/bash

set -xe

pushd .

mkdir -p build/
cd build

LOCAL_PATH=/home/polaris/local
RAYLIB=$LOCAL_PATH/raylib/src
# EASY_PROFILER=$LOCAL_PATH/easy_profiler
EASY_PROFILER_INC=/home/polaris/local/easy_profiler/easy_profiler_core/include/
EASY_PROFILER_LIB=/home/polaris/local/easy_profiler/build/bin/
CFLAGS="-std=c++17 -ggdb"
LDFLAGS="-lglfw -L$RAYLIB -lraylib -L$EASY_PROFILER_LIB -leasy_profiler"

INC="-I$LOCAL_PATH -I$LOCAL_PATH/raylib/src -I$EASY_PROFILER_INC"

g++ $CFLAGS $INC -o PathFind ../main.cpp $LDFLAGS
popd
