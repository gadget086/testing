AC_INIT([amhello], [1.0], [bug-automake@gnu.org])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_PROG_CC
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

AC_CHECK_LIB([cunit],[CU_initialize_registry])
AC_CHECK_HEADERS([limits.h stddef.h stdin.h])

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/hello/Makefile
 tests/Makefile
])
AC_OUTPUT
