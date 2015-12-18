#ifndef MULTIPLICATIVE_EXPRESSION_H
#define MULTIPLICATIVE_EXPRESSION_H

void me_mul(gen_t* $$, gen_t* $1, gen_t* $3) {
  $$->var = newvar();
  if ($1->type == $3->type)
    $$->type = $1->type;
  else if ($1->type == FLOAT_T || $3->type == FLOAT_T)
    $$->type = FLOAT_T;
  asprintf(&$$->code, "%s%s%s = %s %s %s, %s\n",
    $1->code, $3->code, $$->var, get_mul($$->type), get_type($$->type),  $1->var, $3->var);
}

void me_div(gen_t* $$, gen_t* $1, gen_t* $3) {
  $$->var = newvar();
  if ($1->type == $3->type)
    $$->type = $1->type;
  else if ($1->type == FLOAT_T || $3->type == FLOAT_T)
    $$->type = FLOAT_T;
  asprintf(&$$->code, "%s%s%s = %s %s %s, %s\n",
    $1->code, $3->code, $$->var, get_div($$->type), get_type($$->type),  $1->var, $3->var);
}

#endif
