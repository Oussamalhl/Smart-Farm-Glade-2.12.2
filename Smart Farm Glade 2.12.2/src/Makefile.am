## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projettv

projettv_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	capteur.c capteur.h \
	client.c client.h \
	ouvrier.c ouvrier.h \
	troupeau.c troupeau.h \
	seche.c seche.h \
	reservation.c reservation.h \
	equipement.c equipement.h \
	ekbelalarmante.c ekbelalarmante.h

projettv_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

