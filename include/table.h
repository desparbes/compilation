#include <stdio.h>
#include <string.h>
#define SIZE 1013 

typedef struct {
    char *name;
    int type;
    char *code;
    char *var;
} symbol_t;

symbol_t EMPTY={"",0,"",""}; // un symbole vide
symbol_t hachtab[SIZE];

int hachage(char *s);
symbol_t findtab(char *s);
void addtab(char *s,int type);
void init();
