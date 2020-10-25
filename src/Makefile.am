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

dist_bin_SCRIPTS = bdt-prephost-download bdt-prephost-formatdisk \
		bdt-prephost-install bdt-prephost-remove bdt-prephost-sync \
		bdt-prephost-user bdt-version-check-8.4 bdt-version-check-10.0 \
		bdt-basichost-chroot bdt-basichost-directories bdt-basichost-populate



libbdt_la_SOURCES = header.cc 
libbdt_la_LIBADD = $(OCTETOS_CORE_LIBS) $(OCTETOS_COREUTILS_LIBS)
libbdt_la_CPPFLAGS = $(OCTETOS_CORE_CFLAGS) $(OCTETOS_COREUTILS_CFLAGS)


bdt_SOURCES = \
	main.cc \
	commands.cc 
bdt_LDFLAGS = 
bdt_LDADD = $(OCTETOS_CORE_LIBS) $(OCTETOS_COREUTILS_LIBS) $(LIBCURL_LIBS) libbdt.la 
bdt_CPPFLAGS = $(OCTETOS_CORE_CFLAGS) $(OCTETOS_COREUTILS_CFLAGS) $(LIBCURL_CFLAGS)


bdt_includedir = $(includedir)/bdt
bdt_include_HEADERS = header.hh

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = bdt.pc

bdtdir = $(datadir)/bdt
bdt_DATA =  

EXTRA_DIST = bdt.pc.in
