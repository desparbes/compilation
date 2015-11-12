LEX=lex
YACC=bison
CFLAGS=-Wall
CC=gcc
BUILD=build
TEST=test

.PHONY: test

all:parse

test: 
	./test.sh

parse: grammar.c scanner.c
	mkdir $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^

grammar.c: grammar.y
	$(YACC) -d -o $@ --defines=grammar.tab.h $^

%.c: %.l
	$(LEX) -o $@ $^

clean:
	rm -rf build grammar.c scanner.c grammar.tab.h *~ *#
