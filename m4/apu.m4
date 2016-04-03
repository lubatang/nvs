dnl
dnl @synopsis CHECK_APU
dnl
dnl @summary check apache runtime utilities
dnl
dnl Luba Tang <lubatang@gmail.com>

AC_DEFUN([CHECK_APU],
[dnl
  AC_MSG_CHECKING([for Apache Runtime Utilities (APU)])

  APU_CONFIGS="apu-config apu-1-config /usr/local/apr/bin/apu-config"
  AC_ARG_WITH(apu-config,
    [  --with-apu-config=FILE    Use the given path to apu-config when determining
                                 APR utils configuration; defaults to "apu-config"],
    [
      if test "$withval" != "yes" -a "$withval" != ""; then
        APU_CONFIGS=$withval
      fi
    ])

  APU_CONFIG=""
  for VALUE in $APU_CONFIGS ; do
    if $VALUE --includes >/dev/null 2>&1; then
      APU_CONFIG=$VALUE
      break
    fi
  done

  if test $APU_CONFIG ; then
    AC_MSG_RESULT([found])
  else
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([APR utils is required. Try --with-apu-config.])
  fi

  APU_CPPFLAGS=`$APU_CONFIG --includes`
  APU_LIBS=`$APU_CONFIG --link-ld --libs`

  AC_SUBST(APU_CPPFLAGS)
  AC_SUBST(APU_LIBS)
])
