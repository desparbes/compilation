#ifndef FUNCTION_DEFINITION_H
#define FUNCTION_DEFINITION_H

void function_def(gen_t* $$, gen_t* $1, gen_t* $2, gen_t* $3) {
  $2->var = newfunc();
  symbol* s;
  ht_get_entry(ht, $2->id, &s);
  s->var = $2->var;
  asprintf(&$$->code, "define %s %s %s\n", get_type($2->type), $2->var, $3->code);
}

#endif
