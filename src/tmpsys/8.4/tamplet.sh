#!/bin/bash

cd $LFS/sources/
tar -xf .tar.xz 
cd 
mkdir -v build
cd       build




             
make
make install

rm -rf $LFS/sources/#
