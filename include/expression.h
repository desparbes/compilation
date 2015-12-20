#ifndef EXPRESSION_H
#define EXPRESSION_H


void comparison_expression(gen_t* $$, gen_t* $1, char* cond, gen_t* $3) {
  $$->var = newvar();
  $$->type = INT_T;
  asprintf(&$$->code, "%s%s%s = alloca %s \n%s = fcmp %s %s %s, %s\n",
    $1->code, $3->code, $$->var, get_type($$->type), $$->var, cond, get_type($$->type), $1->var,$3->var);
}

void operation_expression(gen_t* $$, gen_t* $1, char op, gen_t* $3) {
  $$->var = newvar();
  if ($1->type == FLOAT_T || $3->type == FLOAT_T)
    $$->type = FLOAT_T;
  else
    $$->type = INT_T;
  char* operation;
  switch(op) {
    case '/':
    operation = get_div($$->type); break;
    case '*':
    operation = get_mul($$->type); break;
    case '+':
    operation = get_add($$->type); break;
    case '-':
    operation = get_sub($$->type); break;
  }
  asprintf(&$$->code, "%s%s%s = alloca %s \n%s = %s %s %s, %s\n",
    $1->code, $3->code, $$->var, get_type($$->type), $$->var, operation, get_type($$->type), $1->var,$3->var);
}



#endif
