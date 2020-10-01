#!/bin/bash
set -e

LFS_SOURCES=$1
LFS=$2
LFS_TGT=$3 
SANDBOX=$4

tar -xf $LFS_SOURCES/binutils-2.32.tar.xz 
cd binutils-2.32
mkdir -v build
cd       build

../configure --prefix=/tools            \
             --with-sysroot=$LFS        \
             --with-lib-path=/tools/lib \
             --target=$LFS_TGT          \
             --disable-nls              \
             --disable-werror
             
make -j1
case $(uname -m) in
  x86_64) mkdir -v /tools/lib && ln -sv /tools/lib /tools/lib64 ;;
esac
make install

rm -rf $SANDBOX/binutils-2.32
