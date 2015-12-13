#ifndef PRIMARY_EXPRESSION
#define PRIMARY_EXPRESSION


void pe_identifier(gen_t *$$, char* $1) {
    if (!ht_has_entry(ht, $1)) {
      printf("Cannot find symbol %s\n", $1);
    }
    symbol *s;
    ht_get_entry(ht, $1, &s);
    $$->var = s->var;
    $$->code = s->code;
    $$->type = s->type;
      //printf("primary_expression: $1: %s, %s, %s, %d\n", $1, s->var, s->code, s->type);
}

void pe_constanti(gen_t *$$, int $1){
  $$->var = newvar();
  $$->type = INT_T;
  asprintf(&$$->code, "%s = add i32 %d, 0\n", $$->var, $1);
    //printf("$1: %d\n", $1);
}

void pe_constantf(gen_t *$$, float $1) {
  $$->var = newvar();
  $$->type = FLOAT_T;
  asprintf(&$$->code, "%s = addf float %f, 0\n", $$->var, $1);
}

#endif
