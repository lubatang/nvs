dnl
dnl @synopsis CHECK_APR
dnl
dnl @summary check apache runtime support
dnl
dnl Luba Tang <lubatang@gmail.com>

AC_DEFUN([CHECK_APR],
[dnl
  AC_MSG_CHECKING([for Apache Runtime Support (APR)])

  APR_CONFIGS="apr-config apr-1-config /usr/local/apr/bin/apr-config"
  AC_ARG_WITH(apr-config,
    [  --with-apr-config=FILE    Use the given path to apr-config when determining
                                 APR configuration; defaults to "apr-config"],
    [
      if test "$withval" != "yes" -a "$withval" != ""; then
        APR_CONFIGS=$withval
      fi
    ])

  APR_CONFIG=""
  for VALUE in $APR_CONFIGS ; do
    if $VALUE --cflags >/dev/null 2>&1; then
      APR_CONFIG=$VALUE
      break
    fi
  done

  if test $APR_CONFIG ; then
    AC_MSG_RESULT([found])
  else
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([APR is required. Try --with-apr-config.])
  fi

  APR_CPPFLAGS="`$APR_CONFIG --cppflags` `$APR_CONFIG --includes`"
  APR_LIBS=`$APR_CONFIG --link-ld --libs`
])
