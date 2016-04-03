AM_CPPFLAGS = -I${abs_top_srcdir}/include ${APR_CPPFLAGS} ${APU_CPPFLAGS} ${SVN_CPPFLAGS} -std=c++11

lib_LTLIBRARIES = libNVSCpp.la

libNVSCpp_la_SOURCES = ../include/NVSCpp/Apr.cpp

libNVSCpp_la_LIBADD = ${APR_LIBS} ${APU_LIBS} ${SVN_LIBS}
