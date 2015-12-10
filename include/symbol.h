#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct {
    char *name;
    int type;
    char *code;
    char *var;
} symbol;

symbol *init_symbol(char *name, int type, char *code, char *var);
int is_void_symbol(symbol *s);
void free_symbol(symbol *s);

#endif //SYMBOL_H
