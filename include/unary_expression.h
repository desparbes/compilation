#ifndef UNARAY_EXPRESSION
#define UNARAY_EXPRESSION

void ue_inc(gen_t* $$, gen_t* $2) {
  if ($2->type != INT_T && $2->type != FLOAT_T) {
    printf("Argument must be a variable");
    exit(EXIT_FAILURE);
  }
  $$->var = $2->var;
  $$->type = $2->type;
  asprintf(&$$->code, "%s = %s %s 1, %s\n",
    $$->var, get_add($$->type), get_type($$->type), $2->var);
}

void ue_dec(gen_t* $$, gen_t* $2) {
  $$->var = $2->var;
  $$->type = $2->type;
  asprintf(&$$->code, "%s%s = %s %s 1, %s\n",
    $2->code, $$->var, get_sub($$->type), get_type($$->type), $2->var);
}

void ue_unaray_operator(gen_t *$$, gen_t *$2) {
  $$->var = $2->var;
  $$->type = $2->type;
  asprintf(&$$->code, "%s%s = %s %s 0, %s\n",
    $2->code, $$->var, get_sub($$->type), get_type($$->type), $2->var);
}

#endif

