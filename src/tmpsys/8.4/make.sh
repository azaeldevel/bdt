#!/bin/bash
set -e


tar xjf $1/make-4.2.1.tar.bz2 
cd make-4.2.1

sed -i '211,217 d; 219,229 d; 232 d' glob/glob.c
./configure --prefix=/tools --without-guile
             
make -j1 
make install

rm -rf $4/make-4.2.1
