AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([src/main.c])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CC

AC_CHECK_LIB([cunit],[CU_initialize_registry])
AC_CHECK_HEADERS([limits.h stddef.h stdin.h])

AC_TYPE_UINT64_T

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/hello/Makefile
 tests/Makefile
])
AC_OUTPUT
