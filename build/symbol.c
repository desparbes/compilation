#include <stdio.h>
#include <stdlib.h>

#include "symbol.h"

symbol *init_symbol(char *name, int type, char *code, char *var)
{
    symbol *s = malloc(sizeof(symbol));
    s->name = name;
    s->type = type;
    s->code = code;
    s->var = var;
    return s;
}

int is_void_symbol(symbol *s)
{
    return (s->name == NULL && s->type == 0 &&
	    s->code == NULL && s->var == NULL);
}

void free_symbol(symbol *s)
{
    free(s);
}
