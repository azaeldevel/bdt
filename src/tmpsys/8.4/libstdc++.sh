#!/bin/bash
set -e

LFS_SOURCES=$1
LFS=$2
LFS_TGT=$3 
SANDBOX=$4


tar -xf $1/gcc-8.2.0.tar.xz
cd gcc-8.2.0

mkdir -v build
cd       build
../libstdc++-v3/configure           \
    --host=$3                  \
    --prefix=/tools                 \
    --disable-multilib              \
    --disable-nls                   \
    --disable-libstdcxx-threads     \
    --disable-libstdcxx-pch         \
    --with-gxx-include-dir=/tools/$3/include/c++/8.2.0
make -j1
make install

rm -rf $4/gcc-8.2.0
