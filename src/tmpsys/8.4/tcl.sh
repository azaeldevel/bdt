#!/bin/bash
set -e


tar xvzf $1/tcl8.6.9-src.tar.gz
cd tcl8.6.9-src

cd unix
./configure --prefix=/tools
             
make -j1
TZ=UTC make test
make install
chmod -v u+w /tools/lib/libtcl8.6.so
make install-private-headers
ln -sv tclsh8.6 /tools/bin/tclsh


rm -rf $4/tcl8.6.9-src
