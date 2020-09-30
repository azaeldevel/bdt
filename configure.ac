
AC_INIT(bdt, 0.1.4-alpha, azael.devel@gmail.com)

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

#AC_DEFINE_UNQUOTED([DATADIR], ["$datadir"],[Define to the read-only architecture-independent data directory.])
AC_DEFINE_UNQUOTED([DATADIRBDT], ["$datadir/bdt"],[Define to the read-only architecture-independent data directory.])




AC_OUTPUT([
Makefile
src/Makefile
src/bdt.pc
])
