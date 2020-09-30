AUTOMAKE_OPTIONS=foreign 1.4


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = libbdt.la

bin_PROGRAMS = bdt

dist_bin_SCRIPTS = bdt-prephost-download bdt-prephost-formatdisk bdt-prephost-install bdt-prephost-remove bdt-prephost-sync bdt-prephost-user bdt-version-check



libbdt_la_SOURCES = header.cc



bdt_SOURCES = \
	main.cc \
	commands.cc 

bdt_LDFLAGS = 

bdt_LDADD = libbdt.la



bdt_includedir = $(includedir)/bdt
bdt_include_HEADERS = header.hh

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = bdt.pc

EXTRA_DIST = bdt.pc.in
