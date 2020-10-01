#!/bin/bash
set -e


tar -xvzf $1/expect5.45.4.tar.gz 
cd expect5.45.4
cp -v configure{,.orig}
sed 's:/usr/local/bin:/bin:' configure.orig > configure

./configure --prefix=/tools       \
            --with-tcl=/tools/lib \
            --with-tclinclude=/tools/include


             
make -j1
make SCRIPTS="" install


rm -rf $4/expect5.45.4
