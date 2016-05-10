bin_PROGRAMS = omi
AM_YFLAGS = -dv
CC = g++

#~ db_header = run/$(db)DbNode.h

omi_SOURCES = \
main.cpp \
interpreter.h \
interpreter.cpp \
error.h \
error.cpp \
plugin.h \
plugin.cpp \
run/tree/runTree.h \
run/tree/runTree.cpp \
run/tree/expNode.h \
run/tree/expNode.cpp \
run/tree/typeNode.h \
run/tree/typeNode.cpp \
run/table/symbols.h \
run/table/symbols.cpp \
run/table/classNode.h \
run/table/classNode.cpp \
run/table/funcNode.h \
run/table/funcNode.cpp \
run/table/idNode.h \
run/table/idNode.cpp \
run/table/sTable.h \
run/table/sTable.cpp \
run/stmts/condStmtNode.h \
run/stmts/condStmtNode.cpp \
run/stmts/ioStmtNode.h \
run/stmts/ioStmtNode.cpp \
run/stmts/loopStmtNode.h \
run/stmts/loopStmtNode.cpp \
run/stmts/stmtNode.h \
run/stmts/stmtNode.cpp \
run/operators/arithOpNode.h \
run/operators/arithOpNode.cpp \
run/operators/arrayOpNode.h \
run/operators/arrayOpNode.cpp \
run/operators/condOpNode.h \
run/operators/condOpNode.cpp \
run/operators/convOpNode.h \
run/operators/convOpNode.cpp \
run/operators/dateOpNode.h \
run/operators/dateOpNode.cpp \
run/operators/fileOpNode.h \ 
run/operators/fileOpNode.cpp \ 
run/operators/logicOpNode.h \
run/operators/logicOpNode.cpp \
run/operators/opNode.h \
run/operators/processOpNode.h \
run/operators/processOpNode.cpp \
run/operators/regexpOpNode.h \ 
run/operators/regexpOpNode.cpp \ 
run/operators/strOpNode.h \
run/operators/strOpNode.cpp \
run/operators/symbolOpNode.h \
run/operators/symbolOpNode.cpp \
lshParser.y \
lshScanner.l

AM_CPPFLAGS = -fPIC -DJSON='$(JSON)' -DSERVER='$(JSON)'  -DDATADIR='"$(datadir)"' -DDATABASE='"$(db_header)"' -DNUMTYPE='$(numType)' -DNUMPRECISION='$(numPrecision)' -DREFCTYPE='$(refCType)' -O3  -ansi -pedantic -g $(db_flag)
AM_CCFLAGS = -DJSON='"$(JSON)" -DDATADIR='"$(datadir)"' -DDATABASE='"$(db_header)"' -O3  -ansi -pedantic -g $(db_flag)
AM_LDFLAGS = -rdynamic -g 
LDADD =  -L/usr/include/boost/   -lm $(db_lib) -ldl

dev: $(filter-out main.o, $(am_omi_OBJECTS))
	ar rcs libomi.a $(filter-out main.o, $(am_omi_OBJECTS))  
install-dev: dev
	mkdir -p /usr/include/omi/run/
	cp -R run/*	/usr/include/omi/run
	cp plugin.h /usr/include/omi/
	cp error.h /usr/include/omi/
	cp lshParser.h /usr/include/omi/
	cp interpreter.h /usr/include/omi/
	cp omi.h /usr/include/omi/
	cp libomi.a /usr/lib
