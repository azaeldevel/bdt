#!/bin/bash

cd $LFS/sources/
tar -xf perl-5.28.1.tar.xz 
cd perl-5.28.1

sh Configure -des -Dprefix=/tools -Dlibs=-lm -Uloclibpth -Ulocincpth
             
make  -j1 
cp -v perl cpan/podlators/scripts/pod2man /tools/bin
mkdir -pv /tools/lib/perl5/5.28.1
cp -Rv lib/* /tools/lib/perl5/5.28.1

rm -rf $LFS/sources/perl-5.28.1
