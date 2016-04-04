AM_CPPFLAGS = -I${abs_srcdir} -I${abs_top_srcdir}/include @APR_CPPFLAGS@ @SVN_CPPFLAGS@ -std=c++11
bin_PROGRAMS = nvs
nvs_LDFLAGS = -L${abs_top_builddir}/libNVSWidget -L${abs_top_builddir}/libNVSCpp
nvs_LDADD = -lNVSWidget -lNVSCpp
dist_nvs_SOURCES = main.cpp \
	NVSView.h \
	NVSView.cpp \
	SVNClient.h \
	SVNClient.cpp \
	Screen.h \
	Screen.cpp
