AM_CPPFLAGS = -I${abs_top_srcdir}/include -std=c++11

lib_LTLIBRARIES = libNVSWidget.la

libNVSWidget_la_SOURCES = ../include/Widget/Point.cpp \
	../include/Widget/Application.cpp \
	../include/Widget/Color.cpp \
	../include/Widget/Cursor.cpp \
	../include/Widget/Layout.cpp \
	../include/Widget/Widget.cpp \
	../include/Widget/Event.cpp \
	../include/Widget/Rect.cpp \
	../include/Widget/Label.cpp \
	../include/Widget/MainWindow.cpp \
	../include/Widget/Palette.cpp \
	../include/Widget/Panel.cpp \
	../include/Widget/Window.cpp \
	../include/Support/ManagedStatic.cpp

libNVSWidget_la_LIBADD = -lcurses -lpanel
