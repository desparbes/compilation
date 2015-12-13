/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/grammar.y" /* yacc.c:339  */

    #define _GNU_SOURCE 1
    #include <stdio.h>
    #include <stdlib.h>
    #include "parse.h"
    #include "hash_table.h"
    #include "symbol.h"
    #include "llvm.h"
    #include "exception.h"

    extern int yylineno;
    int yylex ();
    int yyerror ();
    int last_type = -1;
    struct hash_table *ht;

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

    // Regles sementiques
    #include "primary_expression.h"
    #include "unary_expression.h"

#line 100 "build/grammar.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
#ifndef YY_YY_BUILD_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_BUILD_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANTI = 259,
    CONSTANTF = 260,
    MAP = 261,
    REDUCE = 262,
    EXTERN = 263,
    INC_OP = 264,
    DEC_OP = 265,
    LE_OP = 266,
    GE_OP = 267,
    EQ_OP = 268,
    NE_OP = 269,
    SUB_ASSIGN = 270,
    MUL_ASSIGN = 271,
    ADD_ASSIGN = 272,
    TYPE_NAME = 273,
    INT = 274,
    FLOAT = 275,
    VOID = 276,
    IF = 277,
    ELSE = 278,
    WHILE = 279,
    RETURN = 280,
    FOR = 281
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 47 "src/grammar.y" /* yacc.c:355  */

  char *string;
  int n;
  float f;
  gen_t g;

#line 174 "build/grammar.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 189 "build/grammar.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    28,    33,    35,    29,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      36,    38,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    69,    70,    77,    78,    82,    83,    84,    85,
      89,    94,    95,   105,   118,   119,   128,   140,   144,   145,
     146,   147,   148,   149,   153,   157,   161,   162,   163,   164,
     168,   172,   176,   179,   183,   187,   191,   198,   205,   206,
     207,   208,   209,   213,   214,   218,   222,   223,   224,   225,
     226,   230,   231,   232,   236,   237,   241,   242,   246,   247,
     251,   252,   253,   257,   261,   262,   266,   267,   271,   272,
     276
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANTI", "CONSTANTF",
  "MAP", "REDUCE", "EXTERN", "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "SUB_ASSIGN", "MUL_ASSIGN", "ADD_ASSIGN", "TYPE_NAME", "INT",
  "FLOAT", "VOID", "IF", "ELSE", "WHILE", "RETURN", "FOR", "'('", "')'",
  "','", "'['", "']'", "'-'", "'*'", "'/'", "'+'", "'<'", "'>'", "'='",
  "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "comparison_expression", "expression", "assignment_operator",
  "declaration", "declarator_list", "type_name", "declarator",
  "parameter_list", "parameter_declaration", "statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    40,    41,    44,
      91,    93,    45,    42,    47,    43,    60,    62,    61,    59,
     123,   125
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     111,   118,   -80,   -80,   -80,   -80,    24,   156,   -80,   -80,
      24,   -80,    24,   -20,    50,   -80,   -80,    23,   -22,    -5,
      24,   -80,    97,    14,   102,   -80,   -80,   -80,   -22,   -80,
      24,    56,   -80,    -3,   -80,    11,   -80,   -80,    13,    27,
     274,   274,    34,    61,   227,    65,   274,   -80,   -80,   -80,
     -80,    20,    98,   274,   136,    46,   -80,    81,   -80,    24,
     -80,   -80,   180,     7,   -80,   -80,   -80,   -80,   -22,   -80,
     118,   -80,   -80,   -80,   266,    64,    64,   -80,   -80,   274,
     274,   -80,   101,   258,   121,   274,   -80,   -80,   -80,   -80,
     274,   -80,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   -80,   -80,   141,   -80,   -80,   -80,   -80,   143,
     -80,   149,   162,   129,   133,   -80,   258,   -80,   164,   -80,
     -80,   -80,   -80,    44,    44,    44,    44,   136,   136,    44,
      44,   -80,   -80,   274,    64,    64,   218,   218,   274,   -80,
     -80,   105,   132,   151,   -80,   168,   -80,   -80,   218,   218,
     -80,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    45,    46,    44,    79,     0,     0,    76,    78,
       0,    47,     0,     0,    42,     1,    77,     0,    42,     0,
       0,    40,     0,     0,     0,    80,    41,    48,    43,    52,
       0,     0,    53,     0,    50,     2,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    68,    61,
      12,    16,    21,     0,    24,    27,    35,     0,    64,     0,
      66,    56,     0,     0,    57,    58,    59,    60,    55,    51,
       0,    49,    10,    11,     0,     0,     0,    17,    18,     0,
       0,    74,     0,     0,     0,     0,    39,    37,    38,    36,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    65,     0,    62,    67,    54,     8,     0,
      14,     0,     0,     0,     0,    75,     0,     5,     0,    21,
      34,    22,    23,    30,    31,    32,    33,    26,    25,    28,
      29,    63,     9,     0,     0,     0,     0,     0,     0,    13,
      15,     0,     0,    70,    73,     0,     6,     7,     0,     0,
      71,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -69,   -80,     3,   -80,    95,    58,   107,   -44,
     -80,    -9,   188,     2,    43,   -80,   138,   -62,   189,   -80,
     147,   -79,   -80,   -80,   -80,   -80,   203,   -80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    50,    51,   109,    52,    53,    54,    55,    56,    57,
      90,     5,    13,     6,    18,    31,    32,    60,    61,    62,
      63,    64,    65,    66,    67,     7,     8,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      82,   106,    84,    10,   116,    22,   111,   112,    23,    20,
      35,    36,    37,    38,    39,    58,    40,    41,    33,    21,
      72,    73,    22,    27,    30,    23,    59,    11,    71,    42,
     110,    43,    44,    45,    46,   113,   114,   138,    74,    47,
      75,   118,   106,    77,    78,    34,    48,    24,   105,    14,
      85,    12,    20,   103,    76,    19,    91,    94,    95,    96,
      97,    79,    26,    28,    59,   141,   142,    35,    36,    37,
      38,    39,    30,    68,   143,   144,    98,    22,    98,    99,
      23,    99,   100,   101,    69,    70,   150,   151,    80,   140,
      24,    46,    83,   119,   145,   121,   122,   119,   119,   119,
     119,   119,   119,   119,   119,    35,    36,    37,    38,    39,
       1,    40,    41,    86,    87,    88,     2,     3,     4,     1,
     102,     2,     3,     4,    42,    29,    43,    44,    45,    46,
       2,     3,     4,   146,    47,    85,    89,     2,     3,     4,
     115,    48,    24,    49,    35,    36,    37,    38,    39,   117,
      40,    41,   123,   124,   125,   126,    15,   136,   129,   130,
     147,   137,    85,    42,     1,    43,    44,    45,    46,    92,
      93,   132,   133,    47,   148,     2,     3,     4,   134,    85,
      48,    24,   131,    35,    36,    37,    38,    39,     1,    40,
      41,   135,    85,   127,   128,   139,   149,   120,    17,     2,
       3,     4,    42,    25,    43,    44,    45,    46,   107,   104,
      16,     0,    47,     0,     0,     0,     0,     0,     0,    48,
      24,    35,    36,    37,    38,    39,     0,    40,    41,     0,
      35,    36,    37,    38,    39,     0,    40,    41,     0,     0,
      42,     0,    43,    44,    45,    46,     0,     0,     0,     0,
      47,     0,     0,     0,    46,     0,     0,    48,    24,    47,
       0,    35,    36,    37,    38,    39,    81,    40,    41,    35,
      36,    37,    38,    39,     0,    40,    41,    35,    36,    37,
      38,    39,     0,    40,    41,    46,     0,     0,     0,     0,
      47,     0,     0,    46,   108,     0,     0,    48,    47,     0,
       0,    46,     0,     0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      44,    63,    46,     1,    83,    27,    75,    76,    30,    29,
       3,     4,     5,     6,     7,    24,     9,    10,     4,    39,
       9,    10,    27,    28,    22,    30,    24,     3,    31,    22,
      74,    24,    25,    26,    27,    79,    80,   116,    27,    32,
      27,    85,   104,    40,    41,    31,    39,    40,    41,     6,
      30,    27,    29,    62,    27,    12,    53,    11,    12,    13,
      14,    27,    39,    20,    62,   134,   135,     3,     4,     5,
       6,     7,    70,    30,   136,   137,    32,    27,    32,    35,
      30,    35,    36,    37,    28,    29,   148,   149,    27,   133,
      40,    27,    27,    90,   138,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,     3,     4,     5,     6,     7,
       8,     9,    10,    15,    16,    17,    19,    20,    21,     8,
      39,    19,    20,    21,    22,    28,    24,    25,    26,    27,
      19,    20,    21,    28,    32,    30,    38,    19,    20,    21,
      39,    39,    40,    41,     3,     4,     5,     6,     7,    28,
       9,    10,    94,    95,    96,    97,     0,    28,   100,   101,
      28,    28,    30,    22,     8,    24,    25,    26,    27,    33,
      34,    28,    29,    32,    23,    19,    20,    21,    29,    30,
      39,    40,    41,     3,     4,     5,     6,     7,     8,     9,
      10,    29,    30,    98,    99,    31,    28,    90,    10,    19,
      20,    21,    22,    14,    24,    25,    26,    27,    70,    62,
       7,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    27,    -1,    -1,    39,    40,    32,
      -1,     3,     4,     5,     6,     7,    39,     9,    10,     3,
       4,     5,     6,     7,    -1,     9,    10,     3,     4,     5,
       6,     7,    -1,     9,    10,    27,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    27,    28,    -1,    -1,    39,    32,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    19,    20,    21,    53,    55,    67,    68,    69,
      55,     3,    27,    54,    56,     0,    68,    54,    56,    56,
      29,    39,    27,    30,    40,    60,    39,    28,    56,    28,
      55,    57,    58,     4,    31,     3,     4,     5,     6,     7,
       9,    10,    22,    24,    25,    26,    27,    32,    39,    41,
      43,    44,    46,    47,    48,    49,    50,    51,    53,    55,
      59,    60,    61,    62,    63,    64,    65,    66,    56,    28,
      29,    31,     9,    10,    27,    27,    27,    46,    46,    27,
      27,    39,    51,    27,    51,    30,    15,    16,    17,    38,
      52,    46,    33,    34,    11,    12,    13,    14,    32,    35,
      36,    37,    39,    53,    62,    41,    59,    58,    28,    45,
      51,    44,    44,    51,    51,    39,    63,    28,    51,    46,
      50,    46,    46,    49,    49,    49,    49,    48,    48,    49,
      49,    41,    28,    29,    29,    29,    28,    28,    63,    31,
      51,    44,    44,    59,    59,    51,    28,    28,    23,    28,
      59,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      47,    48,    48,    48,    49,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    59,    59,    59,    59,
      59,    60,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    65,    66,    66,    67,    67,    68,    68,
      69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     6,     6,     3,     4,
       2,     2,     1,     4,     1,     3,     1,     2,     2,     2,
       1,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     3,     4,
       3,     4,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     2,     3,     4,     1,     2,     1,     2,     1,     2,
       5,     7,     7,     5,     2,     3,     1,     2,     1,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 56 "src/grammar.y" /* yacc.c:1646  */
    {  pe_identifier(&(yyval.g), (yyvsp[0].string)); }
#line 1407 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "src/grammar.y" /* yacc.c:1646  */
    {  pe_constanti(&(yyval.g), (yyvsp[0].n)); }
#line 1413 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "src/grammar.y" /* yacc.c:1646  */
    {  pe_constantf(&(yyval.g), (yyvsp[0].f)); }
#line 1419 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "src/grammar.y" /* yacc.c:1646  */
    {  todo(&(yyval.g)); }
#line 1425 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "src/grammar.y" /* yacc.c:1646  */
    {  todo(&(yyval.g)); }
#line 1431 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "src/grammar.y" /* yacc.c:1646  */
    {  todo(&(yyval.g)); }
#line 1437 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 8:
#line 62 "src/grammar.y" /* yacc.c:1646  */
    {  todo(&(yyval.g)); }
#line 1443 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 9:
#line 63 "src/grammar.y" /* yacc.c:1646  */
    {  todo(&(yyval.g)); }
#line 1449 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 10:
#line 64 "src/grammar.y" /* yacc.c:1646  */
    {  todo(&(yyval.g)); }
#line 1455 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 65 "src/grammar.y" /* yacc.c:1646  */
    {  todo(&(yyval.g)); }
#line 1461 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 69 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.g) = (yyvsp[0].g); }
#line 1467 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 13:
#line 71 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g) = (yyvsp[-3].g);
  }
#line 1475 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 16:
#line 82 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.g) = (yyvsp[0].g); }
#line 1481 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 83 "src/grammar.y" /* yacc.c:1646  */
    { ue_inc(&(yyval.g), &(yyvsp[0].g)); }
#line 1487 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 84 "src/grammar.y" /* yacc.c:1646  */
    { ue_dec(&(yyval.g), &(yyvsp[0].g)); }
#line 1493 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 19:
#line 85 "src/grammar.y" /* yacc.c:1646  */
    { ue_unaray_operator(&(yyval.g), &(yyvsp[-1].g)); }
#line 1499 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1505 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 94 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.g) = (yyvsp[0].g);}
#line 1511 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 96 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).var = newvar();
    if ((yyvsp[-2].g).type == (yyvsp[0].g).type)
      (yyval.g).type = (yyvsp[-2].g).type;
    else if ((yyvsp[-2].g).type == FLOAT_T || (yyvsp[0].g).type == FLOAT_T)
      (yyval.g).type = FLOAT_T;
    asprintf(&(yyval.g).code, "%s%s%s = %s %s %s, %s\n",
      (yyvsp[-2].g).code, (yyvsp[0].g).code, (yyval.g).var, get_mul((yyval.g).type), get_type((yyval.g).type),  (yyvsp[-2].g).var, (yyvsp[0].g).var);
  }
#line 1525 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 106 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).var = newvar();
    if ((yyvsp[-2].g).type == (yyvsp[0].g).type)
      (yyval.g).type = (yyvsp[-2].g).type;
    else if ((yyvsp[-2].g).type == FLOAT_T || (yyvsp[0].g).type == FLOAT_T)
      (yyval.g).type = FLOAT_T;
    asprintf(&(yyval.g).code, "%s%s%s = %s %s %s, %s\n",
      (yyvsp[-2].g).code, (yyvsp[0].g).code, (yyval.g).var, get_div((yyval.g).type), get_type((yyval.g).type),  (yyvsp[-2].g).var, (yyvsp[0].g).var);
  }
#line 1539 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 118 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1545 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 25:
#line 119 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).var = newvar();
    if ((yyvsp[-2].g).type == (yyvsp[0].g).type)
	(yyval.g).type = (yyvsp[-2].g).type;
    else if ((yyvsp[-2].g).type == FLOAT_T || (yyvsp[0].g).type == FLOAT_T)
	(yyval.g).type = FLOAT_T;
    asprintf(&(yyval.g).code, "%s%s%s = %s %s %s, %s\n", (yyvsp[-2].g).code, (yyvsp[0].g).code,
	 (yyval.g).var, get_mul((yyval.g).type), get_type((yyval.g).type),  (yyvsp[-2].g).var, (yyvsp[0].g).var);
 }
#line 1559 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 26:
#line 128 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).var = newvar();
    if ((yyvsp[-2].g).type == (yyvsp[0].g).type)
	(yyval.g).type = (yyvsp[-2].g).type;
    else if ((yyvsp[-2].g).type == FLOAT_T || (yyvsp[0].g).type == FLOAT_T)
	(yyval.g).type = FLOAT_T;
    asprintf(&(yyval.g).code, "%s%s%s = %s %s %s, %s\n", (yyvsp[-2].g).code, (yyvsp[0].g).code,
	 (yyval.g).var, get_sub((yyval.g).type), get_type((yyval.g).type),  (yyvsp[-2].g).var, (yyvsp[0].g).var);
 }
#line 1573 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 27:
#line 140 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g) = (yyvsp[0].g);
//    printf("%s", $1.code);
}
#line 1582 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 153 "src/grammar.y" /* yacc.c:1646  */
    {
    asprintf(&(yyval.g).code, "%sstore %s %s, %s %s\n",
      (yyvsp[0].g).code, get_type((yyvsp[0].g).type), (yyvsp[0].g).var, get_type_var((yyvsp[-2].g).type), (yyvsp[-2].g).var);
 }
#line 1591 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 35:
#line 157 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1597 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1603 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 37:
#line 162 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1609 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 38:
#line 163 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1615 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 164 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1621 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 168 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).type = (yyvsp[-2].g).type;
    (yyval.g).code = (yyvsp[-1].g).code;
 }
#line 1630 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 172 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1636 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).code = (yyvsp[0].g).code;
 }
#line 1644 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 179 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1650 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 183 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).type = VOID_T;
    last_type = VOID_T;
}
#line 1659 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 45:
#line 187 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).type = INT_T;
    last_type = INT_T;
}
#line 1668 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 191 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).type = FLOAT_T;
    last_type = FLOAT_T;
}
#line 1677 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 47:
#line 198 "src/grammar.y" /* yacc.c:1646  */
    {
    (yyval.g).var = newvar();
    (yyval.g).type = last_type;
    asprintf(&(yyval.g).code, "%s = alloca %s\n", (yyval.g).var, get_type(last_type));
    symbol *s = init_symbol((yyvsp[0].string), (yyval.g).type, NULL, (yyval.g).var);
    ht_add_entry(ht, (yyvsp[0].string), s);
 }
#line 1689 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 205 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1695 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 206 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1701 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 50:
#line 207 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1707 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 208 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1713 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1719 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 56:
#line 222 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[0].g).code;}
#line 1725 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 57:
#line 223 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[0].g).code;}
#line 1731 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 224 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[0].g).code;}
#line 1737 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 59:
#line 225 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[0].g).code;}
#line 1743 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 226 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[0].g).code;}
#line 1749 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 230 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1755 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 62:
#line 231 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[-1].g).code;}
#line 1761 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 232 "src/grammar.y" /* yacc.c:1646  */
    {asprintf(&(yyval.g).code, "%s%s", (yyvsp[-2].g).code, (yyvsp[-1].g).code);}
#line 1767 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 236 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[0].g).code;}
#line 1773 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 66:
#line 241 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[0].g).code;}
#line 1779 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 242 "src/grammar.y" /* yacc.c:1646  */
    {asprintf(&(yyval.g).code, "%s%s", (yyvsp[-1].g).code, (yyvsp[0].g).code);}
#line 1785 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 68:
#line 246 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1791 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 69:
#line 247 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[-1].g).code;}
#line 1797 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 251 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1803 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 252 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1809 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 253 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1815 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 73:
#line 257 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1821 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 261 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1827 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 262 "src/grammar.y" /* yacc.c:1646  */
    {todo(&(yyval.g));}
#line 1833 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 266 "src/grammar.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].g).code);}
#line 1839 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 267 "src/grammar.y" /* yacc.c:1646  */
    {}
#line 1845 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 271 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g) = (yyvsp[0].g);}
#line 1851 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 272 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g) = (yyvsp[0].g);}
#line 1857 "build/grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 276 "src/grammar.y" /* yacc.c:1646  */
    {(yyval.g).code = (yyvsp[0].g).code;}
#line 1863 "build/grammar.c" /* yacc.c:1646  */
    break;


#line 1867 "build/grammar.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 279 "src/grammar.y" /* yacc.c:1906  */

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