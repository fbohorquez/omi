#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([omi], [0.1], [fbohorquez@omi.org])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/lshParser.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
#~ AC_PROG_YACC
#~ case $YACC in
#~ :) AC_MSG_ERROR([No yacc program found]);;
#~ esac
AC_PROG_CXX
case $CXX in
:) AC_MSG_ERROR([No CXX program found]);;
esac
AC_PROG_CC
case $CC in
:) AC_MSG_ERROR([No CC program found]);;
esac
#~ AC_PROG_LEX
#~ case $LEX in
#~ :) AC_MSG_ERROR([No lex program found]);;
#~ esac

PKG_PROG_PKG_CONFIG

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lreadline':
AC_CHECK_LIB([readline], [readline], [], [AC_MSG_ERROR([readline was not found in system])])
AC_CHECK_LIB([boost_regex], [main], [], [AC_MSG_ERROR([boost_regex was not found in system])])

# Checks for header files.
AC_FUNC_ALLOCA
AC_CHECK_HEADERS([inttypes.h libintl.h malloc.h stddef.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset pow])

#~ AC_ARG_VAR([db],[Data Base System])
#~ 
#~ case "$db" in
  #~ "mysql")
  #~ AC_SUBST([MYSQL])
  #~ db="mysql"
  #~ db_lib="`mysql_config --libs`"
  #~ db_flag="`mysql_config --cflags`"
  #~ AC_CHECK_PROG([FOUND], [mysql_config], ["yes"],["No mysql_config found"], [$PATH])
  #~ ;;
  #~ *)
  #~ AC_SUBST([MYSQL])
  #~ db="mysql"
  #~ db_lib="`mysql_config --libs`"
  #~ db_flag="`mysql_config --cflags`"
  #~ AC_CHECK_PROG([FOUND], [mysql_config], ["yes"], ["No mysql_config found"], [$PATH])
#~ ;;
#~ esac

#~ AM_CONDITIONAL([MYSQL], [test x$db = xmysql])
#~ 
#~ echo "data base system: $db"

AC_ARG_VAR([numType],[Numeric intenal type])
AC_ARG_VAR([numPrecision],[Numeric output precision])
AC_ARG_VAR([refCType],[Reference count internal type])
AC_ARG_VAR([sizeNode],[Node size mode])
AC_ARG_VAR([JSON],[Print process parser in JSON])
AC_ARG_VAR([SERVER],[Run as server])

numP=15

case "$sizeNode" in
   "small")
      numType="float"
      refCType="unsigned int"
      numPrecision=6
      ;;
   "normal")
      numType="double"
      refCType="unsigned int"
      numPrecision=15
      ;;
   "big")
      numType="long double"
      refCType="unsigned int"
      numPrecision=18
      ;;
esac

case "$numType" in
   "4bytes")
      numType="float"
      numPrecision=6
      ;;
   "8bytes")
      numType="double"
      numP=15
      ;;
   "16bytes")
      numType="long double"
      numP=18
      ;;
   "")
      numType="double"
      numP=15
      ;;
esac

case "$numPrecision" in
   "")
      numPrecision=$numP
      ;;
   *)
      numPrecision=$numPrecision
      ;;
esac

case "$refCType" in
   "2bytes")
      refCType="short unsigned int"
      ;;
   "8bytes")
      refCType="unsigned int"
      ;;
   "")
      refCType="unsigned int"
      ;;
   *)
      refCType=$refCType
      ;;
esac

case "$JSON" in
   "1"|"true"| "TRUE")
      echo "Print parser process in JSON"
      JSON="1"
      ;;
   *)
      JSON="0"
      ;;
esac

case "$SERVER" in
   "1"|"true"|"TRUE")
      echo "Run as server"
      SERVER="1"
      ;;
   *)
      SERVER="1"
      ;;
esac
echo "config num internal type: $numType"
echo "config num output precision: $numPrecision"
echo "config reference count internal type: $refCType"

AC_SUBST([db])
AC_SUBST([db_lib])
AC_SUBST([db_flag])
AC_SUBST([AM_CXXFLAGS], [-fpic -Wall -Wextra -03])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
