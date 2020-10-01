#!/bin/bash
set -e


tar -xf gawk-4.2.1.tar.xz
cd gawk-4.2.1

./configure --prefix=/tools


make -j1
make install

rm -rf $4/gawk-4.2.1
