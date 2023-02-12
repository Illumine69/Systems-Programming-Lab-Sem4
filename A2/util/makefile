CC = gcc
CFLAGS = -Wall -fPIC -I.
LIBNAME = libwordutils.so
OBJFILES = dictload.o dictutils.o
RM = rm -f
LIBDIR = /usr/local/lib
INCLUDEDIR = /usr/include
INCLUDESUBDIR = $(INCLUDEDIR)/wordutils

library : $(OBJFILES)
	gcc -shared -o $(LIBNAME) $(OBJFILES)

clean :
	-$(RM) $(OBJFILES) $(LIBNAME)
	-$(RM) $(LIBDIR)/$(LIBNAME) $(INCLUDEDIR)/wordutils.h
	-$(RM) -r $(INCLUDESUBDIR)

install : library
	cp $(LIBNAME) $(LIBDIR)
	-mkdir $(INCLUDESUBDIR)
	cp dictload.h dicttype.h dictutils.h $(INCLUDESUBDIR)
	cp wordutils.h $(INCLUDEDIR)

$(OBJFILES) : wordutils.h