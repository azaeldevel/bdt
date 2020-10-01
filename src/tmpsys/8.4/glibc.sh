#!/bin/bash
set -e


tar -xf $1/glibc-2.29.tar.xz
cd glibc-2.29

mkdir -v build
cd       build
../configure                             \
      --prefix=/tools                    \
      --host=$3                    \
      --build=$(../scripts/config.guess) \
      --enable-kernel=3.2                \
      --with-headers=/tools/include
make
make install

cd ../..
rm -rf $4/glibc-2.29
