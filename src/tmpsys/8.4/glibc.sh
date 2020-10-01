#!/bin/bash
set -e

LFS_SOURCES=$1
LFS=$2
LFS_TGT=$3 
SANDBOX=$4


tar -xf $LFS_SOURCES/glibc-2.29.tar.xz
cd glibc-2.29

mkdir -v build
cd       build
../configure                             \
      --prefix=/tools                    \
      --host=$LFS_TGT                    \
      --build=$(../scripts/config.guess) \
      --enable-kernel=3.2                \
      --with-headers=/tools/include
make
make install

cd ../..
rm -rf $SANDBOX/glibc-2.29
