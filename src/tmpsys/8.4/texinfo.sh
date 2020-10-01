#!/bin/bash

cd $LFS/sources/
tar -xf texinfo-6.5.tar.xz
cd texinfo-6.5

./configure --prefix=/tools
             
make -j1 
make install

rm -rf $LFS/sources/texinfo-6.5
