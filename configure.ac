#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Ising1D], [0.0.1], [odarbelaeze@gmail.com])
AC_CONFIG_SRCDIR([src/ising1D.cc])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
m4_include([m4/ax_cxx_compile_stdcxx_11.m4])
AX_CXX_COMPILE_STDCXX_11

# Enable automake
AM_INIT_AUTOMAKE([subdir-objects])
AM_PATH_CPPUNIT(1.9.6)
AC_CONFIG_FILES([Makefile])

# Checks for libraries.
AC_CHECK_LIB([boost_program_options], [store])
AC_PROG_RANLIB

# Checks for header files.

AC_LANG([C++])

AC_HEADER_STDC
AC_CHECK_HEADERS([iostream])
AC_CHECK_HEADERS([cmath])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([pow sqrt])

AC_OUTPUT
