#!/bin/bash
set -e


tar -xf $1/diffutils-3.7.tar.xz 
cd diffutils-3.7

./configure --prefix=/tools


             
make -j1
make install

rm -rf $4/diffutils-3.7
