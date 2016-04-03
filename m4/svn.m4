dnl
dnl @synopsis CHECK_APR
dnl
dnl @summary check apache runtime support
dnl
dnl Luba Tang <lubatang@gmail.com>

AC_DEFUN([CHECK_SVN],
[dnl
  AC_MSG_CHECKING([for Subversion headers])

  SVN_INCLUDES="/usr/local/include /usr/include /opt/local/include"
  AC_ARG_WITH(svn-include,
    [  --with-svn-include=DIR   Use the given path to the subversion headers.],
    [
      if test "$withval" != "yes" -a "$withval" != ""; then
        SVN_INCLUDES=$withval
      fi
    ])

  SVN_INCLUDE=""
  for VALUE in $SVN_INCLUDES; do
    if test -f $VALUE/subversion-1/svn_types.h; then
      SVN_INCLUDE=$VALUE
      break
    fi
  done
  if test $SVN_INCLUDE ; then
    AC_MSG_RESULT([found])
  else
    AC_MSG_RESULT([headers not found])
    AC_MSG_ERROR([Subversion headers are required. Try --with-svn-include.])
  fi
  SVN_CPPFLAGS="-I$SVN_INCLUDE/subversion-1"

  AC_MSG_CHECKING([for Subversion libraries])
  SVN_LIBS="/usr/lib64 /usr/local/lib /usr/lib /opt/local/lib"
  AC_ARG_WITH(svn-lib,
    [  --with-svn-lib=DIR  Use the given path to the subversion libraries.],
    [
      if test "$withval" != "yes" -a "$withval" != ""; then
        SVN_LIBS=$withval
      fi
    ])
  SVN_LIB=""
  for VALUE in $SVN_LIBS ; do
    if ls $VALUE/libsvn_client-1.* >/dev/null 2>&1; then
      SVN_LIB=$VALUE
      break
    fi
  done

  if test -d "$SVN_LIB"; then
    AC_MSG_RESULT([found])
  else
    AC_MSG_RESULT([libraries not found])
    AC_MSG_ERROR([Subversion libraries are required. Try --with-svn-lib.])
  fi
  SVN_LIBS="-L$SVN_LIB -lsvn_client-1 -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_subr-1"

  AC_SUBST(SVN_CPPFLAGS)
  AC_SUBST(SVN_LIBS)
])
