ACLOCAL_AMFLAGS=-I m4

AUTOMAKE_OPTIONS = foreign

SUBDIRS = libNVSWidget include src

EXTRA_DIST = ./autogen.sh

doc-clean:
	@rm -rf docs

doc: doc-clean doxygen-doc
