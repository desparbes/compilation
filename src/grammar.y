%{
    #define _GNU_SOURCE 1
    #include <stdio.h>
    #include <stdlib.h>
    #include "parse.h"
    #include "hash_table.h"
    #include "symbol.h"

    extern int yylineno;
    int yylex ();
    int yyerror ();
    int last_type = -1;
    struct hash_table *ht;
    
    void todo(gen_t *g)
    {
        g->var = NULL;
        g->code = NULL;
        g->type = 0;
    }
    
    char *newvar() 
    {
        static unsigned int i = 0;
	char *s;
	asprintf(&s, "%%x%d", i++);
	return s;
    }

    char *get_type(int type)
    {
        switch(type) {
        case INT_T:
	    return "i32";
	    break;
        case FLOAT_T:
	    return "f32";
	    break;
        default:
	    return "unknown type";
	    break;
        }
    }

    char *get_type_var(int type)
    {
        switch(type) {
        case INT_T:
	    return "i32*";
	    break;
        case FLOAT_T:
	    return "f32*";
	    break;
        default:
	    return "unknown type";
	    break;
        }
    }
    
    char *get_add(int type)
    {
        switch(type) {
        case INT_T:
	    return "add";
	    break;
        case FLOAT_T:
	    return "addf";
	    break;
        default:
	    return "unknown addition";
	    break;
        }
    }

    char *get_sub(int type)
    {
        switch(type) {
        case INT_T:
	    return "sub";
	    break;
        case FLOAT_T:
	    return "fsub";
	    break;
        default:
	    return "unknown substraction";
	    break;
        }
    }

    char *get_mul(int type)
    {
        switch(type) {
        case INT_T:
	    return "mul";
	    break;
        case FLOAT_T:
	    return "fmul";
	    break;
        default:
	    return "unknown multiplication";
	    break;
        }
    }

    char *get_div(int type)
    {
        switch(type) {
        case INT_T:
	    return "sdiv";
	    break;
        case FLOAT_T:
	    return "fdiv";
	    break;
        default:
	    return "unknown division";
	    break;
        }
    } 
%}

%token <string> IDENTIFIER 
%token <n> CONSTANTI
%token <f> CONSTANTF
%token MAP REDUCE EXTERN
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token SUB_ASSIGN MUL_ASSIGN ADD_ASSIGN
%token TYPE_NAME
%token INT FLOAT VOID
%token IF ELSE WHILE RETURN FOR
%type <g> primary_expression postfix_expression argument_expression_list unary_expression unary_operator multiplicative_expression additive_expression comparison_expression expression assignment_operator declaration declarator_list type_name declarator parameter_list parameter_declaration statement compound_statement declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement program external_declaration function_definition

%start program
%union {
  char *string;
  int n;
  float f;
  gen_t g;
}
%%

primary_expression
: IDENTIFIER { 
    if (!ht_has_entry(ht, $1)) {
	printf("Cannot find symbol %s\n", $1);
	exit(EXIT_FAILURE);
    }
    symbol *s;
    ht_get_entry(ht, $1, &s);
    $$.var = s->var;
    $$.code = s->code;
    $$.type = s->type;
    //printf("primary_expression: $1: %s, %s, %s, %d\n", $1, s->var, s->code, s->type);
}
| CONSTANTI { 
    $$.var = newvar();
    asprintf(&$$.code, "%s = add i32 %d, 0\n", $$.var, $1);
    //printf("$1: %d\n", $1);
    $$.type = INT_T;
}
| CONSTANTF { 
    $$.var = newvar();
    asprintf(&$$.code, "%s = addf float %f, 0\n", $$.var, $1);
    $$.type = FLOAT_T;
}
| '(' expression ')' {todo(&$$);}
| MAP '(' postfix_expression ',' postfix_expression ')' {todo(&$$);}
| REDUCE '(' postfix_expression ',' postfix_expression ')' {todo(&$$);}
| IDENTIFIER '(' ')' {todo(&$$);}
| IDENTIFIER '(' argument_expression_list ')' {todo(&$$);}
| IDENTIFIER INC_OP {todo(&$$);}
| IDENTIFIER DEC_OP {todo(&$$);}
;

postfix_expression
: primary_expression { $$ = $1; }
| postfix_expression '[' expression ']' { $$ = $1; }
;

argument_expression_list
: expression
| argument_expression_list ',' expression
;

unary_expression
: postfix_expression { $$ = $1; }
| INC_OP unary_expression { $$ = $2; }
| DEC_OP unary_expression { $$ = $2; }
| unary_operator unary_expression { 
    $$.var = $2.var;
    $$.type = $2.type;
    asprintf(&$$.code, "%s%s = %s %s 0, %s\n", $2.code, 
	     $$.var, get_sub($$.type), get_type($$.type), $2.var);
}
;

unary_operator
: '-' {}
;
//duplication...
multiplicative_expression
: unary_expression {}
| multiplicative_expression '*' unary_expression {
    $$.var = newvar();
    if ($1.type == $3.type)
	$$.type = $1.type;
    else if ($1.type == FLOAT_T || $3.type == FLOAT_T)
	$$.type = FLOAT_T;
    asprintf(&$$.code, "%s%s%s = %s %s %s, %s\n", $1.code, $3.code, 
	 $$.var, get_mul($$.type), get_type($$.type),  $1.var, $3.var);
 }
| multiplicative_expression '/' unary_expression {
    $$.var = newvar();
    if ($1.type == $3.type)
	$$.type = $1.type;
    else if ($1.type == FLOAT_T || $3.type == FLOAT_T)
	$$.type = FLOAT_T;
    asprintf(&$$.code, "%s%s%s = %s %s %s, %s\n", $1.code, $3.code, 
	 $$.var, get_div($$.type), get_type($$.type),  $1.var, $3.var);
 }
;

additive_expression
: multiplicative_expression {}
| additive_expression '+' multiplicative_expression {
    $$.var = newvar();
    if ($1.type == $3.type)
	$$.type = $1.type;
    else if ($1.type == FLOAT_T || $3.type == FLOAT_T)
	$$.type = FLOAT_T;
    asprintf(&$$.code, "%s%s%s = %s %s %s, %s\n", $1.code, $3.code, 
	 $$.var, get_mul($$.type), get_type($$.type),  $1.var, $3.var);
 }
| additive_expression '-' multiplicative_expression {
    $$.var = newvar();
    if ($1.type == $3.type)
	$$.type = $1.type;
    else if ($1.type == FLOAT_T || $3.type == FLOAT_T)
	$$.type = FLOAT_T;
    asprintf(&$$.code, "%s%s%s = %s %s %s, %s\n", $1.code, $3.code, 
	 $$.var, get_sub($$.type), get_type($$.type),  $1.var, $3.var);
 }
;

comparison_expression
: additive_expression {
    $$ = $1;
//    printf("%s", $1.code);
}
| additive_expression '<' additive_expression
| additive_expression '>' additive_expression
| additive_expression LE_OP additive_expression
| additive_expression GE_OP additive_expression
| additive_expression EQ_OP additive_expression
| additive_expression NE_OP additive_expression
;

expression
: unary_expression assignment_operator comparison_expression {
    asprintf(&$$.code, "%sstore %s %s, %s %s\n", 
	     $3.code, get_type($3.type), $3.var, get_type_var($1.type), $1.var);
 }
| comparison_expression {}
;

assignment_operator
: '=' {todo(&$$);}
| MUL_ASSIGN {todo(&$$);}
| ADD_ASSIGN {todo(&$$);}
| SUB_ASSIGN {todo(&$$);}
;

declaration
: type_name declarator_list ';' {
    $$.type = $1.type;
    $$.code = $2.code;
 }
| EXTERN type_name declarator_list ';' {}
;

declarator_list
: declarator {
    $$.code = $1.code;
 }
| declarator_list ',' declarator {}
;

type_name
: VOID {
    $$.type = VOID_T;
    last_type = VOID_T;
}
| INT {
    $$.type = INT_T;
    last_type = INT_T;
}   
| FLOAT {
    $$.type = FLOAT_T;
    last_type = FLOAT_T;
}
;

declarator
: IDENTIFIER {
    $$.var = newvar();
    $$.type = last_type;
    asprintf(&$$.code, "%s = alloca %s\n", $$.var, get_type(last_type));
    symbol *s = init_symbol($1, $$.type, NULL, $$.var);    
    ht_add_entry(ht, $1, s);
 }
| '(' declarator ')' {}
| declarator '[' CONSTANTI ']' {}
| declarator '[' ']' {}
| declarator '(' parameter_list ')' {}
| declarator '(' ')' {}
;

parameter_list
: parameter_declaration
| parameter_list ',' parameter_declaration
;

parameter_declaration
: type_name declarator
;

statement
: compound_statement {$$.code = $1.code;}
| expression_statement {$$.code = $1.code;}
| selection_statement {$$.code = $1.code;}
| iteration_statement {$$.code = $1.code;}
| jump_statement {$$.code = $1.code;}
;

compound_statement
: '{' '}' {todo(&$$);}
| '{' statement_list '}' {$$.code = $2.code;}
| '{' declaration_list statement_list '}' {asprintf(&$$.code, "%s%s", $2.code, $3.code);}
;

declaration_list
: declaration {$$.code = $1.code;}
| declaration_list declaration
;

statement_list
: statement {$$.code = $1.code;}
| statement_list statement {asprintf(&$$.code, "%s%s", $1.code, $2.code);}
;

expression_statement
: ';' {todo(&$$);}
| expression ';' {$$.code = $1.code;}
;

selection_statement
: IF '(' expression ')' statement {todo(&$$);}
| IF '(' expression ')' statement ELSE statement {todo(&$$);}
| FOR '(' expression_statement expression_statement expression ')' statement {todo(&$$);}
;

iteration_statement
: WHILE '(' expression ')' statement {todo(&$$);}
;

jump_statement
: RETURN ';' {todo(&$$);}
| RETURN expression ';' {todo(&$$);}
;

program
: external_declaration {printf("%s", $1.code);}
| program external_declaration {}
;

external_declaration
: function_definition {$$ = $1;}
| declaration {$$ = $1;}
;

function_definition
: type_name declarator compound_statement {$$.code = $3.code;}
;

%%
#include <stdio.h>
#include <string.h>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    return 0;
}


int main (int argc, char *argv[]) {
    FILE *input = NULL;
    if (argc==2) {
	input = fopen (argv[1], "r");
	file_name = strdup (argv[1]);
	if (input) {
	    yyin = input;
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }
    ht = ht_create(0, NULL);
    yyparse();
    
    free(file_name);
    ht_free(ht);
    return 0;
}
