#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([libomi_gettext], [0.1], [fbohorquez@omi.org])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/libomi_gettext.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
case $CXX in
:) AC_MSG_ERROR([No CXX program found]);;
esac
AC_PROG_CC
case $CC in
:) AC_MSG_ERROR([No CC program found]);;
esac


PKG_PROG_PKG_CONFIG

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lreadline':
AC_CHECK_LIB([omi], [main], [], [AC_MSG_ERROR([omi library was not found in system])])


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


AC_ARG_VAR([numType],[Numeric intenal type])
AC_ARG_VAR([numPrecision],[Numeric output precision])
AC_ARG_VAR([refCType],[Reference count internal type])
AC_ARG_VAR([sizeNode],[Node size mode])

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
