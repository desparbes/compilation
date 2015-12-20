%{
    #define _GNU_SOURCE 1
    #include <stdio.h>
    #include <stdlib.h>
    #include "parse.h"
    #include "hash_table.h"
    #include "symbol.h"
    #include "llvm.h"


    extern int yylineno;
    int yylex ();
    int yyerror ();
    int last_type = -1;
    int func_env = 0;
    struct hash_table *ht;
    struct hash_table *ext_ht;
    char *file_name = NULL;

    void todo(gen_t *g) {
      g->var = NULL;
      g->code = NULL;
      g->type = 0;
    }

    char *newvar() {
      static unsigned int i = 0;
      char *s;
      asprintf(&s, "%%x%d", i++);
      return s;
    }

    char *newfunc() {
      static unsigned int i = 0;
      char *s;
      asprintf(&s, "@y%d", i++);
      return s;
    }

    // Regles semantiques
    #include "assignment_operator.h"
    #include "primary_expression.h"
    #include "unary_expression.h"
    #include "declarator.h"
    #include "declaration.h"
    #include "external_declaration.h"
    #include "postfix_expression.h"
    #include "expression.h"
    #include "program.h"
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
: IDENTIFIER                                               {  pe_identifier(&$$, $1); }
| CONSTANTI                                                {  pe_constanti(&$$, $1); }
| CONSTANTF                                                {  pe_constantf(&$$, $1); }
| '(' expression ')'                                       {  $$ = $2; }
| MAP '(' postfix_expression ',' postfix_expression ')'    {  todo(&$$); }
| REDUCE '(' postfix_expression ',' postfix_expression ')' {  todo(&$$); }
| IDENTIFIER '(' ')'                                       {  pe_function_void(&$$, $1); }
| IDENTIFIER '(' argument_expression_list ')'              {  pe_function_param(&$$, $1, &$3); }
| IDENTIFIER INC_OP                                        {  pe_identifier_inc(&$$, $1); }
| IDENTIFIER DEC_OP                                        {  pe_identifier_dec(&$$, $1); }
;

postfix_expression
: primary_expression { $$ = $1; }
| postfix_expression '[' expression ']' { pe_table(&$$, &$1, &$3);}
;

argument_expression_list
: expression { $$ = $1; asprintf(&$$.var, "%s %s", get_type($1.type), $1.var);  }
| argument_expression_list ',' expression
  {
    $$.type = $1.type;
    asprintf(&$$.code, "%s%s", $1.code, $3.code);
    asprintf(&$$.var, "%s, %s %s", $1.var, get_type($3.type), $3.var);
  }
;

unary_expression
: postfix_expression              { $$ = $1; }
| INC_OP unary_expression         { ue_inc(&$$, &$2); }
| DEC_OP unary_expression         { ue_dec(&$$, &$2); }
| unary_operator unary_expression { ue_opposite(&$$, &$1); }
;

unary_operator
: '-' {}
;

//duplication...
multiplicative_expression
: unary_expression { $$ = $1;}
| multiplicative_expression '*' unary_expression { operation_expression(&$$, &$1,'*', &$3); }
| multiplicative_expression '/' unary_expression { operation_expression(&$$, &$1,'/', &$3); }
;

additive_expression
: multiplicative_expression { $$ = $1; }
| additive_expression '+' multiplicative_expression { operation_expression(&$$, &$1,'+', &$3); }
| additive_expression '-' multiplicative_expression { operation_expression(&$$, &$1,'-', &$3); }
;

comparison_expression
: additive_expression { $$ = $1; }
| additive_expression '<' additive_expression   { comparison_expression(&$$, &$1, "olt", &$3); }
| additive_expression '>' additive_expression   { comparison_expression(&$$, &$1, "ogt", &$3); }
| additive_expression LE_OP additive_expression { comparison_expression(&$$, &$1, "ole", &$3); }
| additive_expression GE_OP additive_expression { comparison_expression(&$$, &$1, "oge", &$3); }
| additive_expression EQ_OP additive_expression { comparison_expression(&$$, &$1, "oeq", &$3); }
| additive_expression NE_OP additive_expression { comparison_expression(&$$, &$1, "one", &$3); }
;

expression
: unary_expression assignment_operator comparison_expression { assigne_value(&$$, &$1, &$2, &$3); }
| comparison_expression { $$ = $1; }
;

assignment_operator
: '=' { $$.type = ASSIGN_T; }
| MUL_ASSIGN { $$.type = MUL_ASSIGN_T; }
| ADD_ASSIGN { $$.type = ADD_ASSIGN_T; }
| SUB_ASSIGN { $$.type = SUB_ASSIGN_T; }
;

declaration
: type_name declarator_list ';' { declaration(&$$, &$1, &$2); }
| EXTERN type_name declarator_list ';'
  {
    declaration(&$$, &$2, &$3);
    asprintf(&$$.code, "declare %s", $$.code);
  }
;

declaration_list
: declaration { $$ = $1; }
| declaration_list declaration { asprintf(&$$.code, "%s%s", $1.code, $2.code); }
;

type_name
: VOID
  {
    $$.type = VOID_T;
    last_type = VOID_T;
  }
| INT
  {
    $$.type = INT_T;
    last_type = INT_T;
  }
| FLOAT
  {
    $$.type = FLOAT_T;
    last_type = FLOAT_T;
  }
;

declarator
: IDENTIFIER                        { declarator_identifier(&$$, $1);}
| '(' declarator ')'                { $$ = $2; }
| declarator '[' CONSTANTI ']'      { declarator_array(&$$, &$1, $3); }
| declarator '[' ']'                { declarator_array_ptr(&$$, &$1); }
| declarator '(' parameter_list ')' { declarator_function_param(&$$, &$1, &$3); }
| declarator '(' ')'                { declarator_function_void(&$$, &$1); }
;

declarator_list
: declarator { $$ = $1; }
| declarator_list ',' declarator { asprintf(&$$.code, "%s%s", $1.code, $3.code); }
;

parameter_list
: parameter_declaration { $$ = $1;}
| parameter_list ',' parameter_declaration { asprintf(&$$.code, "%s, %s", $1.code, $3.code); }
;

parameter_declaration
: type_name declarator { $$ = $2; asprintf(&$$.code, "%s %s", get_type($2.type), $2.var); }
;

statement
: compound_statement   { $$ = $1; }
| expression_statement { $$ = $1; }
| selection_statement  { $$ = $1; }
| iteration_statement  { $$ = $1; }
| jump_statement       { $$ = $1; }
;

compound_statement
: '{' '}' { asprintf(&$$.code, "{}"); }
| '{' statement_list '}' { $$ = $2; asprintf(&$$.code, "{\n%s}", $2.code); }
| '{' declaration_list statement_list '}' { $$ = $3; asprintf(&$$.code, "{\n%s%s}", $2.code, $3.code); }
;


statement_list
: statement { $$ = $1; }
| statement_list statement { $$ = $2; asprintf(&$$.code, "%s%s", $1.code, $2.code);}
;

expression_statement
: ';' {}
| expression ';' {$$ = $1;}
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
: RETURN ';'
  {
    $$.var = newvar();
    $$.type = VOID_T;
    asprintf(&$$.code, "ret void\n");
  }
| RETURN expression ';'
  {
    $$.var = $2.var;
    $$.type = $2.type;
    asprintf(&$$.code, "%sret %s %s\n",$2.code, get_type($2.type), $2.var);
  }
;

program
: external_declaration { generate_code($1.code); }
| program external_declaration { generate_code($2.code); }
;

external_declaration
: function_definition { $$ = $1; ht_free(ht); ht = ht_create(0, NULL); }
| declaration { external_declaration(&$$, &$1); }
;

function_definition
: type_name declarator compound_statement { function_definition(&$$, &$1, &$2, &$3); }
;

%%
#include <stdio.h>
#include <string.h>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

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
  ext_ht = ht_create(0, NULL);
  yyparse();
  free(file_name);
  ht_free(ht);
  ht_free(ext_ht);
  return 0;
}
