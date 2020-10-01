#!/bin/bash
set -e


tar -xf $1/bison-3.3.2.tar.xz
cd bison-3.3.2


./configure --prefix=/tools

             
make -j1
make install

rm -rf $4/bison-3.3.2
