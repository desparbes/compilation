%{
    #include <stdio.h>
    #include "../include/parse.h"
    #define _GNU_SOURCE 1
    extern int yylineno;
    int yylex ();
    int yyerror ();

    char *newvar() 
    {
        static unsigned int i = 0;
	char *s;
	asprintf(&s, "x%d", i++);
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
	    return "";
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
	    return "";
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
	    return "subf";
	    break;
        default:
	    return "";
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
	    return "mulf";
	    break;
        default:
	    return "";
	    break;
        }
    }

    char *get_div(int type)
    {
        switch(type) {
        case INT_T:
	    return "adiv";
	    break;
        case FLOAT_T:
	    return "adivf";
	    break;
        default:
	    return "";
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
%type <g> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression
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
    $$.var = "";
    $$.code = "";
    $$.type = INT_T;
}
| CONSTANTI { 
    $$.var = newvar();
    asprintf(&$$.code, "%s = add i32 %d, 0;\n", $$.var, $1);
    $$.type = INT_T;
}
| CONSTANTF { 
    $$.var = newvar();
    asprintf(&$$.code, "%s = add f32 %f, 0;\n", $$.var, $1);
    $$.type = FLOAT_T;
}
| '(' expression ')' { 
    $$.var = "";
    $$.code = "";
    $$.type = INT_T;
}
| MAP '(' postfix_expression ',' postfix_expression ')' { 
    $$.var = "";
    $$.code = "";
    $$.type = INT_T;
}
| REDUCE '(' postfix_expression ',' postfix_expression ')' { 
    $$.var = "";
    $$.code = "";
    $$.type = INT_T;
}
| IDENTIFIER '(' ')' { 
    $$.var = "";
    $$.code = "";
    $$.type = INT_T;
}
| IDENTIFIER '(' argument_expression_list ')' { 
    $$.var = "";
    $$.code = "";
    $$.type = INT_T;
}
| IDENTIFIER INC_OP { 
    $$.var = "";
    $$.code = "";
    $$.type = INT_T;
}
| IDENTIFIER DEC_OP { 
    $$.var = "";
    $$.code = "";
    $$.type = INT_T;
}
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
| unary_operator unary_expression { $$ = $2; }
;

unary_operator
: '-'
;
//duplication...
multiplicative_expression
: unary_expression
| multiplicative_expression '*' unary_expression {
    $$.var = newvar();
    $$.type = $1.type; //faux
    asprintf(&$$.code, "%s%s%s = %s %s %s, %s;\n", $1.code, $3.code, 
	 $$.var, get_mul($$.type), get_type($$.type),  $1.var, $3.var);
 }
| multiplicative_expression '/' unary_expression {
    $$.var = newvar();
    $$.type = $1.type; //faux
    asprintf(&$$.code, "%s%s%s = %s %s %s, %s;\n", $1.code, $3.code, 
	 $$.var, get_div($$.type), get_type($$.type),  $1.var, $3.var);
 }
;

additive_expression
: multiplicative_expression
| additive_expression '+' multiplicative_expression {
    $$.var = newvar();
    $$.type = $1.type; //faux
    asprintf(&$$.code, "%s%s%s = %s %s %s, %s;\n", $1.code, $3.code, 
	 $$.var, get_mul($$.type), get_type($$.type),  $1.var, $3.var);
 }
| additive_expression '-' multiplicative_expression {
    $$.var = newvar();
    $$.type = $1.type; //faux
    asprintf(&$$.code, "%s%s%s = %s %s %s, %s;\n", $1.code, $3.code, 
	 $$.var, get_sub($$.type), get_type($$.type),  $1.var, $3.var);
 }
;

comparison_expression
: additive_expression {
    printf("%s", $1.code);
}
| additive_expression '<' additive_expression
| additive_expression '>' additive_expression
| additive_expression LE_OP additive_expression
| additive_expression GE_OP additive_expression
| additive_expression EQ_OP additive_expression
| additive_expression NE_OP additive_expression
;

expression
: unary_expression assignment_operator comparison_expression
| comparison_expression
;

assignment_operator
: '='
| MUL_ASSIGN
| ADD_ASSIGN
| SUB_ASSIGN
;

declaration
: type_name declarator_list ';'
| EXTERN type_name declarator_list ';'
;

declarator_list
: declarator
| declarator_list ',' declarator
;

type_name
: VOID  
| INT   
| FLOAT
;

declarator
: IDENTIFIER  
| '(' declarator ')'
| declarator '[' CONSTANTI ']'
| declarator '[' ']'
| declarator '(' parameter_list ')'
| declarator '(' ')'
;

parameter_list
: parameter_declaration
| parameter_list ',' parameter_declaration
;

parameter_declaration
: type_name declarator
;

statement
: compound_statement
| expression_statement 
| selection_statement
| iteration_statement
| jump_statement
;

compound_statement
: '{' '}'
| '{' statement_list '}'
| '{' declaration_list statement_list '}'
;

declaration_list
: declaration
| declaration_list declaration
;

statement_list
: statement
| statement_list statement
;

expression_statement
: ';'
| expression ';'
;

selection_statement
: IF '(' expression ')' statement
| IF '(' expression ')' statement ELSE statement
| FOR '(' expression_statement expression_statement expression ')' statement
;

iteration_statement
: WHILE '(' expression ')' statement
;

jump_statement
: RETURN ';'
| RETURN expression ';'
;

program
: external_declaration
| program external_declaration
;

external_declaration
: function_definition
| declaration
;

function_definition
: type_name declarator compound_statement
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
    yyparse ();
    free (file_name);
    return 0;
}
