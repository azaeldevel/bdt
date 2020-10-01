#!/bin/bash
set -e


tar -xf $1/gzip-1.10.tar.xz 
cd gzip-1.10

./configure --prefix=/tools
             
make -j1 
make install

rm -rf $4/gzip-1.10
