AC_PREREQ([2.60])
AC_INIT([mpi-with-c11], [0.1], [whateva@example.com])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(config)

AM_INIT_AUTOMAKE([1.11 dist-bzip2 foreign -Wall -Werror])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PROG_CC_C99
AC_PROG_CXX

AM_PROG_AR

LT_INIT

# Check for C11 generics
AC_MSG_CHECKING([For C11 generics])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <stdio.h>
int  fooi(int  x) { return x; }
long fool(long x) { return -x; }
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L)
#define foo(x) _Generic((x), int:  fooi, long: fool)(x)
#else
#error your compiler sux
#endif
]],[[
    int  x = 3;
    long y = -3;
    printf("%ld\n",foo(x));
    printf("%ld\n",foo(y));
]])], [AC_MSG_RESULT([yes])],
     [AC_MSG_RESULT([no])
      AC_MSG_ERROR([Cannot continue])])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
