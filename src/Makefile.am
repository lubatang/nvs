AM_CPPFLAGS = -I${abs_srcdir} -I${abs_top_srcdir}/include
bin_PROGRAMS = nvs
nvs_LDFLAGS = -L${abs_top_builddir}/libNVSWidget
nvs_LDADD = -lNVSWidget
dist_nvs_SOURCES = main.cpp \
	NVSApplication.h \
	NVSApplication.cpp \
	NVSView.h \
	NVSView.cpp \
	SVNClient.h \
	SVNClient.cpp \
	Screen.h \
	Screen.cpp
