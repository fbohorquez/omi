bin_PROGRAMS = libomi_gettext
EXEEXT = .so
zAM_YFLAGS = -dv
CC = g++

libomi_gettext_SOURCES = \
libomi_gettext.h \
libomi_gettext.cpp

AM_CPPFLAGS = -fPIC -DDATADIR='"$(datadir)"' -DDATABASE='"$(db_header)"' -DNUMTYPE='$(numType)' -DNUMPRECISION='$(numPrecision)' -DREFCTYPE='$(refCType)' -O3  -ansi -pedantic -g $(db_flag)  -std=c++11
AM_LDFLAGS = -shared -rdynamic -g 
LDADD =  -lomi

install: libomi_gettext.so
	test -d @datadir@/omi/libs/ || mkdir -p @datadir@/omi/libs/; \
	cp libomi_gettext.so @datadir@/omi/libs/; \
	test -f @datadir@/omi/libs.ini || touch @datadir@/omi/libs.ini; \
	echo "@datadir@/omi/libs/libomi_gettext.so" > @datadir@/omi/libs.ini

uninstall: 
	test -f @datadir@/omi/libs/libomi_gettext.so || exit 0; \
	test -f @datadir@/omi/libs/libomi_gettext.so && rm -vR @datadir@/omi/libs/libomi_gettext.so; \
	list=`ls -A @datadir@/omi/libs/`; \
	list="`grep -v "@datadir@/omi/libs/libomi_gettext.so" @datadir@/omi/libs.ini`"; \
	echo "$$list" > @datadir@/omi/libs.ini; 
