#ifndef DECLARATION_H
#define DECLARATION_H

void declaration(gen_t* $$, gen_t* $1, gen_t* $2) {
  $$->var = $2->var;
  $$->type = $2->type;
  asprintf(&$$->code, "%s", $2->code);
}



#endif
