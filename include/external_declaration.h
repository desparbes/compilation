#ifndef EXTERNAL_DECLARATION_H
#define EXTERNAL_DECLARATION_H

#include <string.h>

void function_definition(gen_t* $$, gen_t* $1, gen_t* $2, gen_t* $3) {
  if (ht_has_entry(ext_ht, $2->id)) {
    printf("Logic error: function name \"%s\" alreay used.\n", $2->id);
    exit(0) ;
  }
  // return verification
  if ($3->var == NULL ) {
    printf("Logic error: function must return something.\n");
    exit(0) ;
  } else if ( $3->type != $1->type) {
    printf("Logic error: function \"%s\" returns variable of type \"%s\" instead of type \"%s\".\n", $2->id, get_type($3->type), get_type($1->type));
    exit(0) ;
  }
  symbol* s;
  ht_get_entry(ht, $2->id, &s);
  if (strcmp($2->id, "main") == 0)
      $2->var = "@main";
  else
      $2->var = newfunc();
  s->var = $2->var;
  asprintf(&$$->code, "define %s %s%s%s", get_type($2->type), $2->var, $2->code, $3->code);
  symbol* func=init_symbol(s->name, s->type, s->code, s->var);
  ht_add_entry(ext_ht, s->name, func);
}

void external_declaration(gen_t* $$, gen_t* $1) {
  if (ht_has_entry(ext_ht, $1->id)) {
    printf("Logic error: variable name \"%s\" alreay used.\n", $1->id);
    exit(0) ;
  }
  $$ = $1;
  symbol* s = init_symbol($1->id, $$->type, $$->code, $$->var);
  ht_add_entry(ext_ht, $1->id, s);
}

#endif
