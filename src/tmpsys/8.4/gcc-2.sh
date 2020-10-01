#!/bin/bash
set -e

LFS_SOURCES=$1
LFS=$2
LFS_TGT=$3 
SANDBOX=$4

tar -xf $1/gcc-8.2.0.tar.xz
cd gcc-8.2.0

cat gcc/limitx.h gcc/glimits.h gcc/limity.h > \
  `dirname $($3-gcc -print-libgcc-file-name)`/include-fixed/limits.h
  
for file in gcc/config/{linux,i386/linux{,64}}.h
do
  cp -uv $file{,.orig}
  sed -e 's@/lib\(64\)\?\(32\)\?/ld@/tools&@g' \
      -e 's@/usr@/tools@g' $file.orig > $file
  echo '
#undef STANDARD_STARTFILE_PREFIX_1
#undef STANDARD_STARTFILE_PREFIX_2
#define STANDARD_STARTFILE_PREFIX_1 "/tools/lib/"
#define STANDARD_STARTFILE_PREFIX_2 ""' >> $file
  touch $file.orig
done

case $(uname -m) in
  x86_64)
    sed -e '/m64=/s/lib64/lib/' \
        -i.orig gcc/config/i386/t-linux64
  ;;
esac

tar -xf $1/mpfr-4.0.2.tar.xz
mv -v mpfr-4.0.2 mpfr
tar -xf $1/gmp-6.1.2.tar.xz
mv -v gmp-6.1.2 gmp
tar -xf $1/mpc-1.1.0.tar.gz
mv -v mpc-1.1.0 mpc

mkdir -v build
cd       build

CC=$3-gcc                                    \
CXX=$3-g++                                   \
AR=$3-ar                                     \
RANLIB=$3-ranlib                             \
../configure                                       \
    --prefix=/tools                                \
    --with-local-prefix=/tools                     \
    --with-native-system-header-dir=/tools/include \
    --enable-languages=c,c++                       \
    --disable-libstdcxx-pch                        \
    --disable-multilib                             \
    --disable-bootstrap                            \
    --disable-libgomp

make -j1
make install
ln -sv gcc /tools/bin/cc

rm -rf $4/gcc-8.2.0
