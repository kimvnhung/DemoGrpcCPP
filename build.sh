#!/bin/bash

rm -rf build
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR ../
make