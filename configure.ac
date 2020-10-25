
AC_INIT(bdt, 0.9.1-alpha, azael.devel@gmail.com)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])

AM_SILENT_RULES([yes])

AM_PROG_AS
AC_LANG_CPLUSPLUS
AC_PROG_CXX
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL





PKG_CHECK_MODULES(OCTETOS_CORE,octetos-core)

PKG_CHECK_MODULES(OCTETOS_COREUTILS,octetos-coreutils)

PKG_CHECK_MODULES(LIBCURL,libcurl)

PKG_CHECK_MODULES(PKMT,pkmt)

AC_DEFINE_UNQUOTED([DATADIRBDT], ["$datadir/bdt"],[Define to the read-only architecture-independent data directory.])




AC_OUTPUT([
Makefile
src/Makefile
])
