LEX=lex
YACC=bison
SRC=src
BUILD=build
CFLAGS=-Wall -std=gnu99
CC=gcc
INCLUDE=include
SCRIPT=script

.PHONY: test grammar.c grammar.y scanner.c scanner.l clean parse table.c

all: parse

test:
	$(SCRIPT)/test.sh

parse: grammar.c scanner.c cfiles
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(BUILD) -o $(BUILD)/$@ $(BUILD)/*.c

grammar.c: grammar.y
	$(YACC) -d -o $(BUILD)/$@ --defines=$(BUILD)/grammar.tab.h $(addprefix $(SRC)/, $^)

scanner.c: scanner.l
	$(LEX) -o $(BUILD)/$@ $(addprefix $(SRC)/, $^)

cfiles:
	cp $(SRC)/*.c $(BUILD)

clean:
	rm -rf $(BUILD)/*
