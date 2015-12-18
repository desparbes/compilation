#ifndef FUNCTION_DEFINITION_H
#define FUNCTION_DEFINITION_H

void function_def(gen_t* $$, gen_t* $1, gen_t* $2, gen_t* $3) {
  $$->var = $2->var;
  $$->type = $1->type;

}

#endif
