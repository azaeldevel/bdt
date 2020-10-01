#!/bin/bash
set -e


tar -xf $1/file-5.36.tar.gz 
cd file-5.36

./configure --prefix=/tools
             
make -j1
make install

rm -rf $4/file-5.36
