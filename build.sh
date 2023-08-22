#!/bin/bash

rm -rf build
mkdir build 
cd build 
cmake ../
make
make install
make clean
ldconfig
cd ../
rm -rf build