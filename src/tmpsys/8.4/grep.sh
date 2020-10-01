#!/bin/bash
set -e


tar -xf $1/grep-3.3.tar.xz 
cd grep-3.3

./configure --prefix=/tools
             
make  -j1 
make install

rm -rf $4/grep-3.3
