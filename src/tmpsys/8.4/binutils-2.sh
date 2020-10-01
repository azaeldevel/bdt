#!/bin/bash
set -e

LFS_SOURCES=$1
LFS=$2
LFS_TGT=$3 
SANDBOX=$4

tar -xf $1/binutils-2.32.tar.xz 
cd binutils-2.32
mkdir -v build
cd       build

CC=$3-gcc                \
AR=$3-ar                 \
RANLIB=$3-ranlib         \
../configure --prefix=/tools --disable-nls  --disable-werror --with-lib-path=/tools/lib --with-sysroot
             
make -j1
make install
make -C ld clean
make -C ld LIB_PATH=/usr/lib:/lib
cp -v ld/ld-new /tools/bin


rm -rf $4/binutils-2.32
