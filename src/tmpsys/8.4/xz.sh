#!/bin/bash

cd $LFS/sources/
tar -xf xz-5.2.4.tar.xz 
cd xz-5.2.4

./configure --prefix=/tools

             
make  -j1 
make install

rm -rf $LFS/sources/xz-5.2.4
