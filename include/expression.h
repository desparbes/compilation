#ifndef EXPRESSION_H
#define EXPRESSION_H


void assigne_value(gen_t* $$, gen_t* $1, gen_t* $2, gen_t* $3) {
  switch($2->type) {
    case ASSIGN_T:
    asprintf(&$$->code, "%sstore %s %s, %s %s\n",
      $3->code, get_type($3->type), $3->var, get_type($1->type), $1->var);
    break;
    case ADD_ASSIGN_T:
    asprintf(&$$->code, "%s%s = %s %s, %s\n",
      $3->code, $1->var, get_add($1->type), get_type($1->type), $3->var);
    break;
    case MUL_ASSIGN_T:
    asprintf(&$$->code, "%s%s = %s %s, %s\n",
      $3->code, $1->var, get_mul($1->type), get_type($1->type), $3->var);
    break;
    case SUB_ASSIGN_T:
    asprintf(&$$->code, "%s%s = %s %s, %s\n",
      $3->code, $1->var, get_sub($1->type), get_type($1->type), $3->var);
    break;
  }
}


#endif
