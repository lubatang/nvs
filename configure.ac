##############################################################################
#
#                       NVS Configuration
#
##############################################################################

####################
#  Autoconf/Automake Initialization

dnl AC_INIT(PKG_NAME, BUILD_VERSION, BUG_REPORTER)
AC_INIT([NVS],[hsinchu],[lubatang@gmail.com])
AC_PREREQ(2.59)

AC_CONFIG_SRCDIR([LICENSE])
AC_CONFIG_AUX_DIR([scripts])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.9 dist-bzip2 foreign nostdinc subdir-objects])

####################
#  Versioning, see VERSION
MAJOR=0
MINOR=0
MICRO=0
AGE=0
PKG=2016

DEV_VERSION=$MAJOR:$MINOR:$AGE
PKG_VERSION=$MAJOR.$MINOR.$MICRO-$PKG
NVS_VERSION=$DEV_VERSION
AC_SUBST(NVS_VERSION)

####################
#  Languages
AC_PROG_CC
AC_PROG_CXX
AC_LANG([C++])
AC_PROG_RANLIB
AC_PROG_LEX
AC_PROG_YACC
AM_CONDITIONAL(GCC, test "$GCC" = yes)   # let the Makefile know if we're gcc
LT_INIT

####################
# OUTPUT
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([src/Makefile])

AC_OUTPUT
