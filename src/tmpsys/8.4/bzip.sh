#!/bin/bash
set -e


tar -xf $1/bzip2-1.0.6.tar.gz
cd bzip2-1.0.6

make -j1
make PREFIX=/tools install

rm -rf $4/bzip2-1.0.6
