#ifndef DECLARATOR_H
 #define DECLARATOR_H

void declarator_identifier(gen_t* $$, char* $1) {
  if (ht_has_entry(ht, $1)) {
    printf("Logic error: variable %s already defined.", $1);
    return;
  }
  else {
    $$->var = newvar();
    $$->id = $1;
    $$->type = last_type;
    asprintf(&$$->code, "%s = alloca %s\n", $$->var, get_type($$->type));
    symbol* s=init_symbol($1, $$->type, $$->code, $$->var);
    ht_add_entry(ht, $1, s);
  }
}

void declarator_array(gen_t* $$, gen_t* $1, int $3) {
  $$->type = $1->type;
  $$->var = $1->var;
  asprintf(&$$->code, "%s = alloca [%d x %s]\n", $$->var, $3, get_type($1->type));
}

void declarator_array_ptr(gen_t* $$, gen_t* $1) {
  $$->type = $1->type;
  $$->var = $1->var;
  asprintf(&$$->code, "%s = alloca %s*\n", $$->var, get_type($1->type));
}

// prototypes
void declarator_function_param(gen_t* $$, gen_t* $1, gen_t* $3) {
  $$->type = $1->type;
  $$->var = $1->var;
  asprintf(&$$->code, "%s(%s)\n", $1->var, $3->code);
}

void declarator_function_void(gen_t* $$, gen_t* $1) {
  $$->type = $1->type;
  $$->var = $1->var;
  asprintf(&$$->code, "%s(void)\n", $1->var);
}


#endif //DECLARATOR_H
