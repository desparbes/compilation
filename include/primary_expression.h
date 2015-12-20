#ifndef PRIMARY_EXPRESSION
#define PRIMARY_EXPRESSION


void pe_identifier(gen_t *$$, char* $1) {
    if (!ht_has_entry(ht, $1)) {
	printf("Cannot find identifier %s\n", $1);
	exit(EXIT_FAILURE);
    }
    symbol *s;
    ht_get_entry(ht, $1, &s);
    $$->var = newvar();
    $$->adr = s->var;
    $$->type = s->type;
    $$->id = s->name;
    asprintf(&$$->code, "%s = load %s %s\n", $$->var, get_type_adr($$->type), $$->adr);
}

void pe_constanti(gen_t *$$, int $1){
    $$->var = newvar();
    $$->type = INT_T;
    asprintf(&$$->code, "%s = add i32 %d, 0\n", $$->var, $1);
}

void pe_constantf(gen_t *$$, float $1) {
    $$->var = newvar();
    $$->type = FLOAT_T;
    asprintf(&$$->code, "%s = fadd float %f, 0.\n", $$->var, $1);
}

void pe_function_void(gen_t* $$, char* $1) {
    if (!ht_has_entry(ht, $1)) {
	printf("Cannot find function %s\n", $1);
	exit(EXIT_FAILURE);
    }
    symbol *s;
    ht_get_entry(ht, $1, &s);
    $$->var = newvar();
    $$->type = s->type;
    if (s->type == VOID_T)
	asprintf(&$$->code, "call %s %s(void)\n", get_type(s->type), s->var);
    else
	asprintf(&$$->code, "%s = call %s %s(void)\n", $$->var, get_type(s->type), s->var);
}

void pe_function_param(gen_t* $$, char* $1, gen_t* $3) {
    if (!ht_has_entry(ht, $1)) {
	printf("Cannot find function %s\n", $1);
	exit(EXIT_FAILURE);
    }
    symbol *s;
    ht_get_entry(ht, $1, &s);
    $$->var = newvar();
    $$->type = s->type;
    if (s->type == VOID_T)
	asprintf(&$$->code, "%scall %s %s(%s)\n", $3->code, get_type(s->type), s->var, $3->var);
    else
	asprintf(&$$->code, "%s%s = call %s %s(%s)\n", $3->code, $$->var, get_type(s->type), s->var, $3->var);
}

void pe_identifier_inc(gen_t *$$, char* $1) {
    if (!ht_has_entry(ht, $1)) {
	printf("Cannot find symbol %s\n", $1);
	exit(EXIT_FAILURE);
    }
    symbol *s;
    ht_get_entry(ht, $1, &s);
    $$->var = newvar();
    $$->type = s->type;
    asprintf(&$$->code, "%s = alloc %s \nstore %s %s, %s %s \n%s = %s %s 1, %s \n",
	     $$->var, get_type($$->type),
	     get_type(s->type), s->var, get_type($$->type), $$->var ,
	     s->var, get_add(s->type), get_type(s->type), s->var );
}

void pe_identifier_dec(gen_t *$$, char* $1) {
    if (!ht_has_entry(ht, $1)) {
	printf("Cannot find symbol %s\n", $1);
	exit(EXIT_FAILURE);
    }
    symbol *s;
    ht_get_entry(ht, $1, &s);
    $$->var = newvar();
    $$->type = s->type;
    asprintf(&$$->code, "%s = alloc %s \nstore %s %s, %s %s \n%s = %s %s 1, %s \n",
	     $$->var, get_type($$->type),
	     get_type(s->type), s->var, get_type($$->type), $$->var ,
	     s->var, get_sub(s->type), get_type(s->type), s->var );
}

#endif
