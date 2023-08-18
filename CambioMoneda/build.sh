#!/bin/sh

set -xe

CC=clang
CXXFLAGS="-ggdb -Wall -Wextra"
CPPFLAGS=-std=c++17
SRC=CambioMoneda.cpp
INC="-I../codigo/Small_Vector.h"

$CC $CXXFLAGS $CPPFLAGS $SRC $INC -o CambioMoneda
