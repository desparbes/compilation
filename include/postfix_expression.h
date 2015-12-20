#ifndef POSTFIX_EXPRESSION
#define POSTFIX_EXPRESSION


void pe_table(gen_t* $$, gen_t* $1 , gen_t* $3) {
  // access to table element
  $$->var = newvar();
  $$->type = $1->type-1;
  asprintf(&$$->code, "%s = getelementptr %s %s, %s %s\n", $$->var, get_type($$->type), $1->var, get_type($3->type), $3->var);
}
#endif
