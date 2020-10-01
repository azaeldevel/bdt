#!/bin/bash

cd $LFS/sources/
tar -xf patch-2.7.6.tar.xz 
cd patch-2.7.6

./configure --prefix=/tools
             
make  -j1 
make install

rm -rf $LFS/sources/patch-2.7.6
