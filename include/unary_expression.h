#ifndef UNARAY_EXPRESSION
#define UNARAY_EXPRESSION

void ue_inc(gen_t* $$, gen_t* $2) {
  $$->var = newvar();
  $$->type = $2->type;
  asprintf(&$$->code, "%s = %s %s 1, %s \n%s = alloc %s \nstore %s %s, %s %s\n",
    $2->var, get_add($2->type), get_type($2->type), $2->var,
    $$->var, get_type($$->type),
    get_type($2->type), $2->var, get_type($$->type), $$->var );
}

void ue_dec(gen_t* $$, gen_t* $2) {
  $$->var = newvar();
  $$->type = $2->type;
  asprintf(&$$->code, "%s = %s %s 1, %s \n%s = alloc %s \nstore %s %s, %s %s\n",
    $2->var, get_sub($2->type), get_type($2->type), $2->var,
    $$->var, get_type($$->type),
    get_type($2->type), $2->var, get_type($$->type), $$->var );
}

void ue_opposite(gen_t *$$, gen_t *$2) {
  $$->var = newvar();
  $$->type = $2->type;
  asprintf(&$$->code, "%s = %s %s 0, %s \n%s = alloc %s \nstore %s %s, %s %s\n",
    $2->var, get_sub($2->type), get_type($2->type), $2->var,
    $$->var, get_type($$->type),
    get_type($2->type), $2->var, get_type($$->type), $$->var );
}

#endif

