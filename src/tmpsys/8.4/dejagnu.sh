#!/bin/bash
set -e


tar -xf $1/dejagnu-1.6.2.tar.gz
cd dejagnu-1.6.2
./configure --prefix=/tools

make install

rm -rf $4/dejagnu-1.6.2
