SUBDIRS = src lib
EXTRA_DIST = AUTHORS ChangeLog NEWS README THANKS \
lib/libs
#~ pkgdata_DATA = libs
AM_CXXFLAGS = -fpic -Wall -Wextra

install-exec-local:
	test -d @datadir@/omi/ || mkdir @datadir@/omi/ ; \
	touch @datadir@/omi/libs.ini
	
uninstall-local:
	test -n /usr/local/share/omi && rm -vR /usr/local/share/omi
	
check:
	../test/test.sh

dev:
	make -C src dev
	
install-dev:
	make -C src install-dev
	
uninstall-dev:
	test -d /usr/include/omi || exit 0;  \
	test -d /usr/include/omi && rm -vR /usr/include/omi; \
	test -f /usr/lib/libomi.a && rm -vR /usr/lib/libomi.a
