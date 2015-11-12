LEX=lex
YACC=bison
SRCDIR=src
OBJDIR=build
CFLAGS=-Wall
CC=gcc

.PHONY: test grammar.c grammar.y scanner.c scanner.l clean parse

all: parse

test:
	./test.sh

parse: grammar.c scanner.c
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(OBJDIR) -o $(OBJDIR)/$@ $(addprefix $(OBJDIR)/,$^)

grammar.c: grammar.y
	$(YACC) -d -o $(OBJDIR)/$@ --defines=$(OBJDIR)/grammar.tab.h $(addprefix $(SRCDIR)/,$^)

scanner.c: scanner.l
	$(LEX) -o $(OBJDIR)/$@ $(addprefix $(SRCDIR)/,$^)

clean:
	rm -rf $(OBJDIR)/*
