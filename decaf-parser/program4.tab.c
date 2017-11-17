/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 11 "program4.y" /* yacc.c:339  */


#include <iostream>
#include <vector>
#include <typeinfo>
#include <FlexLexer.h>
#include "program4.hpp"

using namespace std;

/*
 * These are declared in "main" so that we can pass values between
 * the two portions of the program.
 */

extern Node *tree;
extern yyFlexLexer scanner;
extern int yylineno;

/*
 * Need to do this define, an "acceptable" hack to interface
 * the C++ scanner with the C parser.
 */

#define yylex() scanner.yylex()

// need the function prototype for the parser.

void yyerror(const char *, int, int);
void yyerror(const char *);


#line 99 "program4.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "program4.tab.h".  */
#ifndef YY_YY_PROGRAM4_TAB_H_INCLUDED
# define YY_YY_PROGRAM4_TAB_H_INCLUDED
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
    ID = 258,
    NUMBER = 259,
    NLL = 260,
    THIS = 261,
    VOID = 262,
    NEW = 263,
    READ = 264,
    PRINT = 265,
    CLASS = 266,
    IF = 267,
    WHILE = 268,
    RETURN = 269,
    INT = 270,
    LP = 271,
    LC = 272,
    COMMA = 273,
    SEMICOLON = 274,
    RC = 275,
    RS = 276,
    RP = 277,
    DOT = 278,
    LS = 279,
    ASSIGN = 280,
    OROR = 281,
    ANDAND = 282,
    EQUALS = 283,
    NOTEQL = 284,
    GREATER = 285,
    LESS = 286,
    LESSGRT = 287,
    MOREGRT = 288,
    PLUS = 289,
    MINUS = 290,
    MULT = 291,
    DIV = 292,
    REMAINDER = 293,
    ELSE = 295,
    NOT = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 58 "program4.y" /* yacc.c:355  */

  Node *ttype;

#line 184 "program4.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PROGRAM4_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "program4.tab.c" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 54 "program4.y" /* yacc.c:359  */

  #define YYLTYPE YYLTYPE

#line 221 "program4.tab.c" /* yacc.c:359  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   119,   125,   130,   136,   141,   146,   151,
     156,   165,   172,   178,   184,   190,   195,   200,   205,   210,
     214,   219,   220,   228,   232,   236,   241,   249,   253,   257,
     266,   270,   278,   282,   289,   300,   304,   309,   315,   321,
     327,   334,   345,   346,   356,   357,   365,   370,   374,   379,
     388,   394,   399,   404,   412,   413,   421,   430,   434,   442,
     446,   452,   458,   463,   468,   474,   479,   488,   494,   502,
     507,   511,   516,   526,   530,   538,   539,   547,   548,   558,
     559,   568,   573,   577,   581,   587,   591,   596,   601,   606,
     611,   617,   623,   629,   635,   641,   647,   653,   659,   665,
     671,   677,   683,   689,   697,   702,   708,   714,   719,   728,
     729
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "NLL", "THIS", "VOID",
  "NEW", "READ", "PRINT", "CLASS", "IF", "WHILE", "RETURN", "INT", "LP",
  "LC", "COMMA", "SEMICOLON", "RC", "RS", "RP", "DOT", "LS", "ASSIGN",
  "OROR", "ANDAND", "EQUALS", "NOTEQL", "GREATER", "LESS", "LESSGRT",
  "MOREGRT", "PLUS", "MINUS", "MULT", "DIV", "REMAINDER", "\"then\"",
  "ELSE", "NOT", "$accept", "start", "program", "class_decl", "class_body",
  "var_declmore", "multi_brackets", "var_decl", "type_other", "type",
  "constructor_declmore", "constructor_decl", "method_declmore",
  "method_decl", "parameter_list", "mult_parameters", "parameter", "block",
  "local_var_declmore", "local_var_decl", "statements", "statement",
  "conditional_statement", "name_other", "name", "arg_lists", "arg_list",
  "optional_expression", "expression", "new_expression",
  "exprsn_in_brackets", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -31

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-31)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     100,     6,    13,    62,   132,  -141,    57,    58,    28,  -141,
    -141,   251,   251,   251,   251,    32,    96,     4,    93,   251,
    -141,   384,  -141,   385,  -141,   114,   118,   107,   137,     0,
     123,     7,   139,   138,    10,  -141,  -141,   384,   385,    49,
      14,  -141,   385,    43,  -141,  -141,  -141,  -141,  -141,     0,
    -141,    44,    48,   140,  -141,  -141,   144,   150,     0,     0,
    -141,   154,   385,   164,    90,   169,    91,   181,  -141,    92,
    -141,    94,   149,   200,     0,  -141,  -141,   197,   198,     0,
    -141,   205,   220,   149,  -141,  -141,   250,  -141,     0,   215,
     149,   149,   216,  -141,    95,  -141,   223,   239,   241,    55,
    -141,  -141,  -141,    88,   256,  -141,   265,  -141,   280,  -141,
    -141,    46,   115,  -141,   149,  -141,  -141,   149,   101,    55,
      55,    55,   237,  -141,  -141,     3,   257,    55,    55,    55,
      55,   258,   253,   335,  -141,   255,   262,  -141,  -141,   292,
    -141,  -141,   284,    55,    55,    55,  -141,  -141,  -141,   178,
     266,   335,   288,   305,    55,   273,  -141,   269,   322,   145,
     145,  -141,    55,  -141,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,  -141,  -141,  -141,
    -141,   196,   274,   160,  -141,   282,   285,   155,   155,    55,
     283,   283,  -141,  -141,   286,   348,   348,   373,   373,   382,
     382,   382,   382,   145,   145,  -141,  -141,  -141,  -141,   294,
    -141,  -141,    55,   289,  -141,   306,   143,   321,   321,  -141,
    -141,   335,   155,  -141,   214,  -141,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     0,     0,     1,
       5,    18,    18,    18,    18,     0,     0,     0,     0,    16,
      20,    17,    33,    15,    36,     0,     0,     0,     0,    42,
       0,     0,     0,     0,     0,     7,    19,    12,    13,     0,
       0,    32,    14,     0,    35,     8,     9,    10,     6,    42,
      23,     0,     0,     0,    44,    21,     0,     0,    42,    42,
      24,     0,    11,     0,     0,     0,     0,     0,    46,     0,
      47,     0,     0,    43,    42,    25,    22,     0,     0,    42,
      26,     0,     0,     0,    48,    49,     0,    34,     0,     0,
       0,     0,     0,    38,    73,    69,     0,     0,     0,    79,
      27,    59,    53,    31,     0,    66,     0,    54,     0,    57,
      62,    74,     0,    45,     0,    39,    37,     0,     0,    77,
       0,     0,    73,    82,    83,     0,     0,     0,     0,     0,
       0,    81,     0,    80,    86,     0,     0,    51,    55,     0,
      52,    58,     0,     0,    77,     0,    41,    40,    28,     0,
       0,    75,     0,     0,     0,   109,   109,     0,     0,    87,
      88,    89,    77,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    56,    50,
      71,     0,     0,     0,    70,     0,    78,     0,     0,    77,
     108,   107,    85,   103,     0,    98,   102,    90,    91,    94,
      95,    92,    93,    96,    97,    99,   100,   101,    72,     0,
      60,    63,     0,    67,    64,     0,     0,   106,   105,    84,
      61,    76,     0,   104,     0,    68,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,   326,   188,  -141,   -15,   327,  -141,  -141,
     328,   104,   102,   -18,    71,  -141,   301,   -64,  -141,   287,
     290,   -96,  -141,  -141,   -85,  -141,  -140,  -141,   -88,  -141,
     234
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    18,    19,    64,    20,   103,   104,
      21,    22,    23,    24,    53,    73,    54,   105,   106,   107,
     108,   109,   110,   111,   131,   186,   150,   132,   151,   134,
     190
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   112,    34,    51,   182,    44,   155,    33,    87,     6,
      56,   133,   141,    61,     7,    52,     8,    65,   156,    93,
      44,   112,   194,   112,    44,    66,   115,   116,    30,    13,
     149,    57,   152,   153,    57,    28,    69,    71,    30,   158,
     159,   160,   161,   141,    44,    14,    63,    68,    29,   215,
     146,    70,    63,   147,   112,   181,    30,   183,   122,   123,
     124,    95,     9,   125,   126,    29,   149,    30,    30,   142,
     143,   127,    30,    30,    11,    12,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   128,
     129,   213,   214,    81,    82,    84,   130,    85,   -30,    32,
      -2,     1,   112,   112,   122,   123,   124,    95,    47,   125,
     126,     2,   135,    35,    57,    57,    57,   127,    57,   118,
      67,    38,   148,    42,   221,    41,   225,    48,   224,    77,
      78,   144,    -3,     1,    45,   128,   129,   112,    46,    62,
     145,    41,   130,     2,    55,    89,   122,   123,   124,    95,
      92,   125,   126,    49,    59,    58,    50,    60,   122,   127,
      74,    95,    72,    75,    55,    96,    86,    97,    98,    99,
      79,    76,    86,    80,   101,   217,   218,   128,   129,   210,
      49,   174,   175,   176,   130,    59,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   184,
      25,    26,    27,    83,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   208,    88,    90,
      91,    74,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   226,    79,   114,   117,   119,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    94,    15,   120,    95,   121,    16,   136,
      96,   154,    97,    98,    99,   100,    17,    86,    94,   101,
     102,    95,   163,   157,   162,    96,   177,    97,    98,    99,
     100,   178,    86,   122,   101,   137,    95,   180,   185,   189,
      96,   192,    97,    98,    99,   122,   209,    86,    95,   101,
     140,   211,    96,   212,    97,    98,    99,   216,   219,    86,
     187,   101,   179,   220,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   188,   223,   222,
      10,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   193,    57,    36,    37,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   -31,   -31,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    39,    43,   113,
     191,    16,    16,   138,     0,     0,   139,     0,     0,    40,
      40,   -31,   -31,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   -31,   -31,   -31,   -31,   172,   173,   174,   175,
     176
};

static const yytype_int16 yycheck[] =
{
      15,    86,    17,     3,   144,    23,     3,     3,    72,     3,
       3,    99,   108,     3,     1,    15,     3,     3,    15,    83,
      38,   106,   162,   108,    42,    40,    90,    91,    24,     1,
     118,    24,   120,   121,    24,     3,    51,    52,    24,   127,
     128,   129,   130,   139,    62,    17,     3,     3,    16,   189,
     114,     3,     3,   117,   139,   143,    24,   145,     3,     4,
       5,     6,     0,     8,     9,    16,   154,    24,    24,    23,
      24,    16,    24,    24,    17,    17,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    34,
      35,   187,   188,     3,     3,     3,    41,     3,     3,     3,
       0,     1,   187,   188,     3,     4,     5,     6,     1,     8,
       9,    11,    24,    20,    24,    24,    24,    16,    24,    24,
      49,    19,    21,    21,   212,    21,   222,    20,   216,    58,
      59,    16,     0,     1,    20,    34,    35,   222,    20,    37,
      25,    37,    41,    11,    21,    74,     3,     4,     5,     6,
      79,     8,     9,    16,    16,    16,    19,    19,     3,    16,
      16,     6,    22,    19,    21,    10,    17,    12,    13,    14,
      16,    21,    17,    19,    19,   190,   191,    34,    35,    19,
      16,    36,    37,    38,    41,    16,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    21,
      12,    13,    14,    22,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    21,    18,    22,
      22,    16,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    21,    16,    22,    22,    16,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,     3,     3,    16,     6,    16,     7,     3,
      10,    24,    12,    13,    14,    15,    15,    17,     3,    19,
      20,     6,    19,    16,    16,    10,    21,    12,    13,    14,
      15,    19,    17,     3,    19,    20,     6,     3,    22,    16,
      10,    22,    12,    13,    14,     3,    22,    17,     6,    19,
      20,    19,    10,    18,    12,    13,    14,    24,    22,    17,
      22,    19,    20,    19,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    22,    22,    40,
       4,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    22,    24,    19,    19,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     3,     3,    88,
     156,     7,     7,   106,    -1,    -1,   106,    -1,    -1,    15,
      15,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    30,    31,    32,    33,    34,    35,    36,    37,
      38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    11,    43,    44,    45,     3,     1,     3,     0,
      45,    17,    17,     1,    17,     3,     7,    15,    46,    47,
      49,    52,    53,    54,    55,    46,    46,    46,     3,    16,
      24,    48,     3,     3,    48,    20,    49,    52,    54,     3,
      15,    53,    54,     3,    55,    20,    20,     1,    20,    16,
      19,     3,    15,    56,    58,    21,     3,    24,    16,    16,
      19,     3,    54,     3,    48,     3,    48,    56,     3,    48,
       3,    48,    22,    57,    16,    19,    21,    56,    56,    16,
      19,     3,     3,    22,     3,     3,    17,    59,    18,    56,
      22,    22,    56,    59,     3,     6,    10,    12,    13,    14,
      15,    19,    20,    50,    51,    59,    60,    61,    62,    63,
      64,    65,    66,    58,    22,    59,    59,    22,    24,    16,
      16,    16,     3,     4,     5,     8,     9,    16,    34,    35,
      41,    66,    69,    70,    71,    24,     3,    20,    61,    62,
      20,    63,    23,    24,    16,    25,    59,    59,    21,    70,
      68,    70,    70,    70,    24,     3,    15,    16,    70,    70,
      70,    70,    16,    19,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    21,    19,    20,
       3,    70,    68,    70,    21,    22,    67,    22,    22,    16,
      72,    72,    22,    22,    68,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    21,    22,
      19,    19,    18,    63,    63,    68,    24,    48,    48,    22,
      19,    70,    40,    22,    70,    63,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    47,
      47,    48,    48,    49,    49,    49,    49,    50,    50,    50,
      51,    51,    52,    52,    53,    54,    54,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      59,    59,    59,    59,    60,    60,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    65,
      65,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    71,    71,    71,    72,
      72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     5,     5,     5,     5,
       5,     3,     2,     2,     2,     1,     1,     1,     0,     2,
       1,     2,     3,     3,     3,     4,     4,     1,     3,     3,
       1,     1,     2,     1,     5,     2,     1,     6,     6,     6,
       7,     7,     0,     2,     0,     3,     2,     2,     3,     3,
       4,     3,     3,     2,     1,     2,     3,     1,     2,     1,
       4,     5,     1,     5,     5,     3,     1,     5,     7,     1,
       4,     3,     4,     1,     1,     0,     3,     0,     2,     0,
       1,     1,     1,     1,     4,     3,     1,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     3,     3,     0,
       4
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 119 "program4.y" /* yacc.c:1646  */
    {
              tree = (yyvsp[0].ttype);
            }
#line 1591 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 125 "program4.y" /* yacc.c:1646  */
    {
               (yyval.ttype) = new Node;
               (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
               (yyval.ttype)->setValProd("<Program> --> <ClassDeclaration>+");
             }
#line 1601 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 130 "program4.y" /* yacc.c:1646  */
    {
                         (yyval.ttype) = (yyvsp[-1].ttype);
                         (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
                       }
#line 1610 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 136 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->setValProd("\n<ClassDeclaration> --> class identifier <ClassBody>");
  }
#line 1620 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "program4.y" /* yacc.c:1646  */
    {
    yyerrok;
    yyerror("Parse error on class", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    yyclearin;
  }
#line 1630 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 146 "program4.y" /* yacc.c:1646  */
    {
    yyerrok;
    yyerror("Parse error on identifier", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    yyclearin;
  }
#line 1640 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 151 "program4.y" /* yacc.c:1646  */
    {
    yyerrok;
    yyerror("Parse error on [", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    yyclearin;
  }
#line 1650 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "program4.y" /* yacc.c:1646  */
    {
    yyerrok;
    yyerror("Parse error on ]", (yylsp[0]).first_line, (yylsp[0]).first_column);
    yyclearin;
  }
#line 1660 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <VarDeclaration>+ <ConstructorDeclaration>+ <MethodDeclaration>+ }");
  }
#line 1672 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 172 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <VarDeclaration>+ <ConstructorDeclaration>+ }");
  }
#line 1683 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 178 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <VarDeclaration>+ <MethodDeclaration>+ }");
  }
#line 1694 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 184 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <ConstructorDeclaration>+ <MethodDeclaration>+ }");
  }
#line 1705 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 190 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <MethodDeclaration>+ }");
  }
#line 1715 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 195 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <VarDeclaration>+ }");
  }
#line 1725 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 200 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <ConstructorDeclaration>+ }");
  }
#line 1735 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 205 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 1741 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 210 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1750 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 214 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype)); }
#line 1756 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 219 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->setValProd("<[]>* --> []"); }
#line 1762 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 220 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<[]>* --> []");
  }
#line 1772 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 228 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<VarDeclaration> --> identifier identifier ;");
  }
#line 1781 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 232 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<VarDeclaration> --> int identifier ;");
  }
#line 1790 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 236 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<VarDeclaration> --> identifier <[]>* identifier ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
  }
#line 1800 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 241 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<VarDeclaration> --> int <[]>* identifier ;");
  }
#line 1809 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 249 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Type> --> int");
  }
#line 1818 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 253 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Type> --> identifier []");
  }
#line 1827 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 257 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<Type> --> <Type> [ ]");
  }
#line 1837 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 266 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Type> --> identifier");
  }
#line 1846 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 270 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1855 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 278 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1864 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 282 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1873 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 289 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<ConstructorDeclaration> --> identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-4].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1885 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 300 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1894 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 304 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype)); }
#line 1900 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 309 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> int identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1911 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 315 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> identifier identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1922 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 321 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> void identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1933 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 327 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> int <[]>* identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-5].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1945 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 334 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> identifier <[]>* identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-5].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1957 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 345 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 1963 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 346 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<ParameterList> --> <Parameter> <, <Parameter> >*");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1974 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 356 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 1980 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 357 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-2].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1989 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 365 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Parameter> --> identifier identifier");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 1999 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 370 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Parameter> --> int identifier");
  }
#line 2008 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 374 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Parameter> --> identifier <[]>* identifier");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2018 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 379 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Parameter> --> int <[]>* identifier");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2028 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 388 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2039 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 394 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2049 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 399 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2059 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 404 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
  }
#line 2068 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 412 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype)); }
#line 2074 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 413 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2083 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 421 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<LocalVarDeclaration> --> <Type> identifier ;");
  }
#line 2093 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 430 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2102 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 434 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2111 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 442 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> ;");
  }
#line 2120 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 446 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> <Name> = <Expression> ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-3].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2131 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 452 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> <Name> ( <ArgList> ) ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-4].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
  }
#line 2142 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 458 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> <ConditionalStatement>");
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2152 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 463 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> print ( <ArgList> ) ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
  }
#line 2162 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 468 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> while ( <Expression> ) <Statement>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2173 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 474 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> return <OptionalExpression> ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2183 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 479 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2193 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 488 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<ConditionalStatement> --> if ( <Expression> ) <Statement>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2204 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 494 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<ConditionalStatement> --> if ( <Expression> ) <Statement> else <Statement>");
  }
#line 2213 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 502 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValKeyw("this");
    (yyval.ttype)->setValProd("<Name> --> this");
  }
#line 2223 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 507 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Name> --> identifier [ <Expression> ]");
  }
#line 2232 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 511 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<Name> --> <Name> . identifier");
  }
#line 2242 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 516 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-3].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->setValProd("<Name> --> <Name> [ <Expression> ]");
  }
#line 2253 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 526 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Name> --> identifier");
  }
#line 2262 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 530 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2271 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 538 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 2277 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 539 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-2].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2286 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 547 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 2292 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 548 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<ArgList> --> <Expression> <,<Expression> >*");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2303 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 558 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->setValProd("<OptionalExpression> --> epsilon"); }
#line 2309 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 559 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<OptionalExpression> --> <Expression>");
  }
#line 2319 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 568 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Name>");
  }
#line 2329 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 573 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Expression> --> number");
  }
#line 2338 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 577 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Expression> --> null");
  }
#line 2347 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 581 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Expression> --> <Name> ( <ArgList> )");
    (yyval.ttype)->pushNonTerminal((yyvsp[-3].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2358 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 587 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Expression> --> read ( )");
  }
#line 2367 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 591 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <NewExpression>");
  }
#line 2377 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 596 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> + <Expression>");
  }
#line 2387 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 601 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> - <Expression>");
  }
#line 2397 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 606 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> ! <Expression>");
  }
#line 2407 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 611 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> == <Expression>");
  }
#line 2418 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 617 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> != <Expression>");
  }
#line 2429 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 623 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> <= <Expression>");
  }
#line 2440 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 629 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> >= <Expression>");
  }
#line 2451 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 635 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> > <Expression>");
  }
#line 2462 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 641 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> < <Expression>");
  }
#line 2473 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 647 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> + <Expression>");
  }
#line 2484 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 653 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> - <Expression>");
  }
#line 2495 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 659 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> || <Expression>");
  }
#line 2506 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 665 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> * <Expression>");
  }
#line 2517 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 671 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> / <Expression>");
  }
#line 2528 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 677 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> % <Expression>");
  }
#line 2539 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 683 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> && <Expression>");
  }
#line 2550 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 689 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->setValProd("<Expression> --> ( <Expression> )");
  }
#line 2560 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 697 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new identifier ( <ArgList> )");
  }
#line 2570 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 702 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new int <[ Expression ]>* <[ ]>+");
  }
#line 2581 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 708 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new identifier <[ Expression ]>* <[ ]>*");
  }
#line 2592 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 714 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new int <[ Expression ]>*");
  }
#line 2602 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 719 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new identifier <[ Expression ]>*");
  }
#line 2612 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 728 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 2618 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 729 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-3].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2627 "program4.tab.c" /* yacc.c:1646  */
    break;


#line 2631 "program4.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 735 "program4.y" /* yacc.c:1906  */

