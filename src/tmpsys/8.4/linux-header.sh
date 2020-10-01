#!/bin/bash
set -e

tar -xf $1/linux-4.20.12.tar.xz
cd linux-4.20.12

make mrproper
make INSTALL_HDR_PATH=dest headers_install
cp -rv dest/include/* /tools/include


rm -rf $4/linux-4.20.12
