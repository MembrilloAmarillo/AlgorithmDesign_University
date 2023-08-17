#!/bin/sh

set -xe

CC=clang
CXXFLAGS="-ggdb -Wall -Wextra"
CPPFLAGS=-std=c++17
SRC=CambioMoneda.cpp

$CC $CXXFLAGS $CPPFLAGS $SRC -o CambioMoneda
