#!/bin/bash
set -e


tar -xf $1/coreutils-8.30.tar.xz 
cd coreutils-8.30


./configure --prefix=/tools --enable-install-program=hostname
             
make -j1
make install

rm -rf $4/coreutils-8.30
