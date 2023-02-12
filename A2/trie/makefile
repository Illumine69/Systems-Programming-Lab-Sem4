CC = gcc
CFLAGS = -Wall -fPIC -I.
LIBNAME = libtrie.so
OBJFILES = trie.o
RM = rm -f
LIBDIR = /usr/local/lib
INCLUDEDIR = /usr/include

library : $(OBJFILES)
	gcc -shared -o $(LIBNAME) $(OBJFILES)

clean :
	-$(RM) $(OBJFILES) $(LIBNAME)
	-$(RM) $(LIBDIR)/$(LIBNAME) $(INCLUDEDIR)/trie.h

install :  library
	cp $(LIBNAME) $(LIBDIR)
	cp trie.h $(INCLUDEDIR)

$(OBJFILES): trie.h