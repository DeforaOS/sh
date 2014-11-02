TARGETS	= $(OBJDIR)sh
OBJDIR	=
PREFIX	= /usr/local
DESTDIR	=
BINDIR	= $(PREFIX)/bin
SBINDIR	= $(PREFIX)/sbin
CC	= cc
CPPFLAGSF=
CPPFLAGS=
CFLAGSF	= -W
CFLAGS	= -Wall -g -O2 -pedantic
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: $(TARGETS)

sh_OBJS = $(OBJDIR)token.o $(OBJDIR)scanner.o $(OBJDIR)parser.o $(OBJDIR)builtin.o $(OBJDIR)job.o $(OBJDIR)sh.o
sh_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)
sh_LDFLAGS = $(LDFLAGSF) $(LDFLAGS)

$(OBJDIR)sh: $(sh_OBJS)
	$(CC) -o $(OBJDIR)sh $(sh_OBJS) $(sh_LDFLAGS)

$(OBJDIR)token.o: token.c
	$(CC) $(sh_CFLAGS) -o $(OBJDIR)token.o -c token.c

$(OBJDIR)scanner.o: scanner.c
	$(CC) $(sh_CFLAGS) -o $(OBJDIR)scanner.o -c scanner.c

$(OBJDIR)parser.o: parser.c
	$(CC) $(sh_CFLAGS) -o $(OBJDIR)parser.o -c parser.c

$(OBJDIR)builtin.o: builtin.c
	$(CC) $(sh_CFLAGS) -o $(OBJDIR)builtin.o -c builtin.c

$(OBJDIR)job.o: job.c
	$(CC) $(sh_CFLAGS) -o $(OBJDIR)job.o -c job.c

$(OBJDIR)sh.o: sh.c
	$(CC) $(sh_CFLAGS) -o $(OBJDIR)sh.o -c sh.c

clean:
	$(RM) -- $(sh_OBJS)

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)
	$(MKDIR) $(DESTDIR)$(BINDIR)
	$(INSTALL) -m 0755 $(OBJDIR)sh $(DESTDIR)$(BINDIR)/sh

uninstall:
	$(RM) -- $(DESTDIR)$(BINDIR)/sh

.PHONY: all clean distclean install uninstall
