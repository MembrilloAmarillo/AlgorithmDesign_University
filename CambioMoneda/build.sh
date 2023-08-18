#!/bin/sh

set -xe

CC=clang
CXXFLAGS="-ggdb -Wall -Wextra"
CPPFLAGS=-std=c++17
SRC=CambioMoneda.cpp
INC="-I../Algorithm/"

$CC $CXXFLAGS $CPPFLAGS $SRC $INC -o CambioMoneda
