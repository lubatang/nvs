AM_CPPFLAGS = -I${abs_top_srcdir}/include @APR_CPPFLAGS@ @SVN_CPPFLAGS@ -std=c++11

lib_LTLIBRARIES = libNVSCpp.la

libNVSCpp_la_SOURCES = ../include/Subversion/Client.cpp \
	../include/Subversion/ClientAnnotate.cpp \
	../include/Subversion/ClientCat.cpp \
	../include/Subversion/ClientDiff.cpp \
	../include/Subversion/ClientList.cpp \
	../include/Subversion/ClientModify.cpp \
	../include/Subversion/ClientProperty.cpp \
	../include/Subversion/ClientStatus.cpp \
	../include/Subversion/Context.cpp \
	../include/Subversion/ContextData.cpp \
	../include/Subversion/Datetime.cpp \
	../include/Subversion/Dirent.cpp \
	../include/Subversion/Entry.cpp \
	../include/Subversion/Exception.cpp \
	../include/Subversion/Info.cpp \
	../include/Subversion/LogEntry.cpp \
	../include/Subversion/Path.cpp \
	../include/Subversion/Pool.cpp \
	../include/Subversion/Property.cpp \
	../include/Subversion/Revision.cpp \
	../include/Subversion/Status.cpp \
	../include/Subversion/StatusSelection.cpp \
	../include/Subversion/Targets.cpp \
	../include/Subversion/URL.cpp \
	../include/Subversion/Wc.cpp

libNVSCpp_la_LIBADD = @APR_LIBS@ @SVN_LIBS@
