#!/bin/bash
set -e


tar -xf $1/gettext-0.19.8.1.tar.xz 
cd gettext-0.19.8.1

cd gettext-tools
EMACS="no" ./configure --prefix=/tools --disable-shared
             
make -j1 -C gnulib-lib
make -j1  -C intl pluralx.c
make -j1  -C src msgfmt
make -j1  -C src msgmerge
make -j1  -C src xgettext
cp -v src/{msgfmt,msgmerge,xgettext} /tools/bin

rm -rf $4/gettext-0.19.8.1
