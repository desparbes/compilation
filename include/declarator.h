#ifndef DECLARATOR_H
#define DECLARATOR_H

void declarator_identifier(gen_t* $$, char* $1) {
  $$->var = newvar();
  $$->type = last_type;
  //asprintf(&$$->code, "%s = alloca %s\n", $$->var, get_type(last_type));
  symbol *s = init_symbol($1, $$->type, "", $$->var);
  ht_add_entry(ht, $1, s);
}

void declarator_array(gen_t* $$, gen_t* $1, int $3) {
  $$->var = $1->var;
  $$->type = $1->type;
  //asprintf(&$$->code, "%s", $1->code);
  asprintf(&$$->code, "%s = alloca [%d x %s]\n", $$->var, $3, get_type(last_type));
}

void declarator_array_ptr(gen_t* $$, gen_t* $1) {
  $$->var = $1->var;
  $$->type = $1->type;
  //asprintf(&$$->code, "%s", $1->code);
  asprintf(&$$->code, "%s = alloca %s*\n", $$->var, get_type(last_type));
}

void declarator_function_param(gen_t* $$, gen_t* $1, gen_t* $3) {

}


#endif //DECLARATOR_H
