@echo off

mkdir build
pushd build

@set SRC=..\mochila_discreta.cpp 

cl /nologo /W4 /Zi /MD %SRC% /std:c++17

popd
