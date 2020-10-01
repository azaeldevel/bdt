#!/bin/bash
set -e


tar -xf $1/ncurses-6.1.tar.gz
cd ncurses-6.1

sed -i s/mawk// configure

./configure --prefix=/tools \
            --with-shared   \
            --without-debug \
            --without-ada   \
            --enable-widec  \
            --enable-overwrite
             
make -j1
make install
ln -s libncursesw.so /tools/lib/libncurses.so


rm -rf $4/ncurses-6.1
