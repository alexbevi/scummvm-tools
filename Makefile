# $URL$
# $Id$

#######################################################################
# Default compilation parameters. Normally don't edit these           #
#######################################################################

srcdir      ?= .

DEFINES     := -DHAVE_CONFIG_H
LDFLAGS     :=
INCLUDES    := -I. -I$(srcdir)
LIBS        :=
OBJS        :=
DEPDIR      := .deps

MODULES     :=
MODULE_DIRS :=

STANDALONE  :=
# This one will go away once all tools are converted
NO_MAIN     := -DEXPORT_MAIN


# Load the make rules generated by configure
-include config.mk

ifeq "$(HAVE_GCC)" "1"
	# Additional warnings
	CXXFLAGS:= -Wall $(CXXFLAGS)
	# Turn off some annoying and not-so-useful warnings
	CXXFLAGS+= -Wno-long-long -Wno-multichar -Wno-unknown-pragmas -Wno-reorder
	# Enable even more warnings...
	#CXXFLAGS+= -pedantic	# -pedantic is too pedantic, at least on Mac OS X
	CXXFLAGS+= -Wpointer-arith -Wcast-align
	CXXFLAGS+= -Wno-shadow -Wimplicit -Wundef -Wnon-virtual-dtor -Wwrite-strings

	# Enable checking of pointers returned by "new"
	CXXFLAGS+= -fcheck-new

	# There is a nice extra warning that flags variables that are potentially
	# used before being initialized. Very handy to catch a certain kind of
	# bugs. Unfortunately, it only works when optimizations are turned on,
	# which is why we normally don't use it.
	#CXXFLAGS+= -O -Wuninitialized
endif

ifeq "$(HAVE_CLANG)" "1"
	CXXFLAGS+= -Wno-conversion -Wno-shorten-64-to-32 -Wno-sign-compare -Wno-four-char-constants
endif

#######################################################################
# Default commands - put the necessary replacements in config.mk      #
#######################################################################

CAT     ?= cat
CP      ?= cp
ECHO    ?= printf
INSTALL ?= install
MKDIR   ?= mkdir -p
RM      ?= rm -f
RM_REC  ?= $(RM) -r
ZIP     ?= zip -q

#######################################################################

include $(srcdir)/Makefile.common

# check if configure has been run or has been changed since last run
config.h config.mk: $(srcdir)/configure
ifeq "$(findstring config.mk,$(MAKEFILE_LIST))" "config.mk"
	@echo "Running $(srcdir)/configure with the last specified parameters"
	@sleep 2
	LDFLAGS="$(SAVED_LDFLAGS)" CXX="$(SAVED_CXX)" \
			CXXFLAGS="$(SAVED_CXXFLAGS)" CPPFLAGS="$(SAVED_CPPFLAGS)" \
			ASFLAGS="$(SAVED_ASFLAGS)" WINDRESFLAGS="$(SAVED_WINDRESFLAGS)" \
			$(srcdir)/configure $(SAVED_CONFIGFLAGS)
else
	$(error You need to run $(srcdir)/configure before you can run make. Check $(srcdir)/configure --help for a list of parameters)
endif

# Special target to create a win32 tools snapshot binary
WIN32PATH=C:/scummvm

win32dist:   all
	mkdir -p $(WIN32PATH)
	mkdir -p $(WIN32PATH)/tools
	mkdir -p $(WIN32PATH)/tools/media
	cp gui/media/detaillogo.jpg $(WIN32PATH)/tools/media/
	cp gui/media/logo.jpg $(WIN32PATH)/tools/media/
	cp gui/media/tile.gif $(WIN32PATH)/tools/media/
	strip decine.exe -o $(WIN32PATH)/tools/decine.exe
	strip degob.exe -o $(WIN32PATH)/tools/degob.exe
	strip dekyra.exe -o $(WIN32PATH)/tools/dekyra.exe
	strip deriven.exe -o $(WIN32PATH)/tools/deriven.exe
	strip descumm.exe -o $(WIN32PATH)/tools/descumm.exe
	strip desword2.exe -o $(WIN32PATH)/tools/desword2.exe
	strip extract_mohawk.exe -o $(WIN32PATH)/tools/extract_mohawk.exe
	strip construct_mohawk.exe -o $(WIN32PATH)/tools/construct_mohawk.exe
	strip gob_loadcalc.exe -o $(WIN32PATH)/tools/gob_loadcalc.exe
	strip scummvm-tools.exe -o $(WIN32PATH)/tools/scummvm-tools.exe
	strip scummvm-tools-cli.exe -o $(WIN32PATH)/tools/scummvm-tools-cli.exe
	cp *.bat $(WIN32PATH)/tools
	cp COPYING $(WIN32PATH)/tools/COPYING.txt
	cp README $(WIN32PATH)/tools/README.txt
	u2d $(WIN32PATH)/tools/*.txt
