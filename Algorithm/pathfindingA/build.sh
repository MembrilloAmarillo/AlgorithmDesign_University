#!/bin/bash

set -xe

pushd .

mkdir -p build/
cd build

LOCAL_PATH=/home/polaris/local
RAYLIB=$LOCAL_PATH/raylib/src
CFLAGS="-std=c++17 -ggdb"
LDFLAGS="-lglfw -L$RAYLIB -lraylib"

INC="-I$LOCAL_PATH -I$LOCAL_PATH/raylib/src"

g++ $CFLAGS $INC -o PathFind ../main.cpp $LDFLAGS
popd