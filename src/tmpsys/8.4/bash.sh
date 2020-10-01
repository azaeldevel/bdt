#!/bin/bash
set -e

tar -xf $1/bash-5.0.tar.gz 
cd bash-5.0

./configure --prefix=/tools --without-bash-malloc
             
make -j1
make install
ln -sv bash /tools/bin/sh

rm -rf $4/bash-5.0
