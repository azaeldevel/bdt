#!/bin/bash

cd $LFS/sources/
tar -xf sed-4.7.tar.xz 
cd sed-4.7

./configure --prefix=/tools

             
make  -j1 
make install

rm -rf $LFS/sources/sed-4.7
