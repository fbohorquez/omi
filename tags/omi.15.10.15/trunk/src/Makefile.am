bin_PROGRAMS = omi
AM_YFLAGS = -dv
CC = g++

#~ db_header = run/$(db)DbNode.h

omi_SOURCES = \
interpreter.h \
interpreter.cpp \
error.h \
error.cpp \
plugin.h \
plugin.cpp \
run/numData.h \
run/numData.cpp \
run/runTree.h \
run/runTree.cpp \
run/symbols.h \
run/symbols.cpp \
run/expNode.h \
run/expNode.cpp \
run/sTable.h \
run/sTable.cpp \
run/typeNode.h \
run/typeNode.cpp \
run/operatorNode.h \
run/operatorNode.cpp \
run/operatorStrNode.h \
run/operatorStrNode.cpp \
run/operatorArrayNode.h \
run/operatorArrayNode.cpp \
run/operatorDateNode.h \
run/operatorDateNode.cpp \
run/operatorRegexpNode.h \
run/operatorRegexpNode.cpp \
run/fileNode.h \
run/fileNode.cpp \
run/processNode.h \
run/processNode.cpp \
run/componentNode.h \
run/componentNode.cpp \
run/stmtNode.h \
run/stmtNode.cpp \
run/sqliteDb.cpp \
lshParser.y \
lshScanner.l

#~ if MYSQL
#~ liesh_SOURCES += run/mysqlDbNode.h run/mysqlDbNode.cpp
#~ endif


AM_CPPFLAGS = -fPIC -DJSON='$(JSON)' -DSERVER='$(JSON)'  -DDATADIR='"$(datadir)"' -DDATABASE='"$(db_header)"' -DNUMTYPE='$(numType)' -DNUMPRECISION='$(numPrecision)' -DREFCTYPE='$(refCType)' -O3  -ansi -pedantic -g $(db_flag)
AM_CCFLAGS = -DJSON='"$(JSON)" -DDATADIR='"$(datadir)"' -DDATABASE='"$(db_header)"' -O3  -ansi -pedantic -g $(db_flag)
AM_LDFLAGS = -rdynamic -g 
LDADD =  -L/usr/include/boost/   -lm $(db_lib) -lsqlite3 -ldl

dev: $(am_omi_OBJECTS)
	ar rcs libomi.a $(am_omi_OBJECTS)  
	
install-dev: dev
	mkdir -p /usr/include/omi/run/
	cp run/*.h	/usr/include/omi/run
	cp plugin.h /usr/include/omi/
	cp error.h /usr/include/omi/
	cp lshParser.h /usr/include/omi/
	cp interpreter.h /usr/include/omi/
	cp omi.h /usr/include/omi/
	cp libomi.a /usr/lib
