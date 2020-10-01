#!/bin/bash

cd $LFS/sources/
tar -xf Python-3.7.2.tar.xz 
cd Python-3.7.2

sed -i '/def add_multiarch_paths/a \        return' setup.py
./configure --prefix=/tools --without-ensurepip

make
make install

rm -rf $LFS/sources/Python-3.7.2
