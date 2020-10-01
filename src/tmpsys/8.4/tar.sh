#!/bin/bash

cd $LFS/sources/
tar -xf tar-1.31.tar.xz 
cd tar-1.31

./configure --prefix=/tools
             
make  -j1 
make install

rm -rf $LFS/sources/tar-1.31
