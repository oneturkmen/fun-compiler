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
    ELSE = 268,
    WHILE = 269,
    RETURN = 270,
    INT = 271,
    LP = 272,
    LC = 273,
    COMMA = 274,
    SEMICOLON = 275,
    RC = 276,
    RS = 277,
    RP = 278,
    DOT = 279,
    LS = 280,
    ASSIGN = 281,
    OROR = 282,
    ANDAND = 283,
    EQUALS = 284,
    NOTEQL = 285,
    GREATER = 286,
    LESS = 287,
    LESSGRT = 288,
    MOREGRT = 289,
    PLUS = 290,
    MINUS = 291,
    MULT = 292,
    DIV = 293,
    REMAINDER = 294,
    NOT = 295
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
#define YYLAST   392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   117,   123,   128,   134,   139,   144,   149,
     154,   163,   170,   176,   182,   188,   193,   198,   203,   208,
     212,   217,   218,   226,   230,   234,   239,   247,   251,   255,
     264,   268,   276,   280,   287,   298,   302,   307,   313,   319,
     325,   332,   343,   344,   354,   355,   363,   368,   372,   377,
     386,   392,   397,   402,   410,   411,   419,   428,   432,   440,
     444,   450,   456,   461,   467,   472,   481,   486,   490,   495,
     505,   509,   517,   518,   526,   527,   537,   538,   547,   552,
     556,   560,   566,   570,   575,   580,   585,   590,   596,   602,
     608,   614,   620,   626,   632,   638,   644,   650,   656,   662,
     668,   676,   681,   687,   693,   698,   707,   708
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "NLL", "THIS", "VOID",
  "NEW", "READ", "PRINT", "CLASS", "IF", "ELSE", "WHILE", "RETURN", "INT",
  "LP", "LC", "COMMA", "SEMICOLON", "RC", "RS", "RP", "DOT", "LS",
  "ASSIGN", "OROR", "ANDAND", "EQUALS", "NOTEQL", "GREATER", "LESS",
  "LESSGRT", "MOREGRT", "PLUS", "MINUS", "MULT", "DIV", "REMAINDER", "NOT",
  "$accept", "start", "program", "class_decl", "class_body",
  "var_declmore", "multi_brackets", "var_decl", "type_other", "type",
  "constructor_declmore", "constructor_decl", "method_declmore",
  "method_decl", "parameter_list", "mult_parameters", "parameter", "block",
  "local_var_declmore", "local_var_decl", "statements", "statement",
  "name_other", "name", "arg_lists", "arg_list", "optional_expression",
  "expression", "new_expression", "exprsn_in_brackets", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF -128

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-128)))

#define YYTABLE_NINF -31

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-31)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,    39,   147,    46,   194,  -128,    33,    34,   143,  -128,
    -128,   140,   140,   140,   140,    31,    83,    55,    84,   140,
    -128,   183,  -128,   330,  -128,   104,   136,    40,   -11,    90,
      89,    73,   150,    -7,    74,  -128,  -128,   183,   330,    37,
      75,  -128,   330,   106,  -128,  -128,  -128,  -128,  -128,    90,
    -128,   109,   113,   164,  -128,  -128,    87,   167,    90,    90,
    -128,   135,   330,   174,   114,   176,   115,   184,  -128,   117,
    -128,   120,   188,   196,    90,  -128,  -128,   199,   200,    90,
    -128,   204,   216,   188,  -128,  -128,   182,  -128,    90,   207,
     188,   188,   228,  -128,   121,  -128,   233,   235,   124,  -128,
    -128,  -128,   243,   250,  -128,   198,  -128,   148,  -128,   -13,
     -10,  -128,   188,  -128,  -128,   188,    79,   124,   124,   244,
    -128,  -128,   133,   253,   124,   124,   124,   124,   254,   266,
     320,  -128,   265,   269,  -128,  -128,   214,  -128,  -128,   287,
     124,   124,   124,  -128,  -128,  -128,   209,   268,   320,   276,
     124,   277,  -128,   270,   293,   172,   172,  -128,   124,  -128,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,  -128,  -128,  -128,  -128,   227,   272,   145,
    -128,   278,   298,   282,   124,   294,   294,  -128,  -128,   295,
     333,   333,   344,   344,   353,   353,   353,   353,   172,   172,
    -128,  -128,  -128,  -128,   281,  -128,  -128,   124,  -128,   311,
      86,   310,   310,  -128,  -128,   320,  -128,   245,  -128
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
       0,     0,     0,    38,    70,    66,     0,     0,    76,    27,
      59,    53,    31,     0,    65,     0,    54,     0,    57,    71,
       0,    45,     0,    39,    37,     0,     0,    74,     0,    70,
      79,    80,     0,     0,     0,     0,     0,     0,    78,     0,
      77,    83,     0,     0,    51,    55,     0,    52,    58,     0,
       0,    74,     0,    41,    40,    28,     0,     0,    72,     0,
       0,   106,   106,     0,     0,    84,    85,    86,    74,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    56,    50,    68,     0,     0,     0,
      67,     0,    75,     0,    74,   105,   104,    82,   100,     0,
      95,    99,    87,    88,    91,    92,    89,    90,    93,    94,
      96,    97,    98,    69,     0,    60,    62,     0,    63,     0,
       0,   103,   102,    81,    61,    73,   101,     0,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,   332,   213,  -128,   -15,   319,  -128,  -128,
     321,    60,   116,    -3,   -41,  -128,   251,   -68,  -128,   236,
     237,  -104,  -128,   -81,  -128,  -127,  -128,   -97,  -128,   191
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    18,    19,    64,    20,   102,   103,
      21,    22,    23,    24,    53,    73,    54,   104,   105,   106,
     107,   108,   109,   128,   182,   147,   129,   148,   131,   185
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   130,    34,   138,    87,   110,    49,   141,    67,    50,
      59,   139,   140,    60,   178,    93,   142,    77,    78,   146,
      44,   149,   113,   114,   110,    66,   110,   154,   155,   156,
     157,   189,   138,    89,    28,    44,    69,    71,    92,    44,
      63,    47,     6,   177,   143,   179,     9,   144,    29,    -2,
       1,    11,    12,   146,    29,   110,    30,   209,    33,    44,
       2,    48,    30,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    56,    61,    65,   208,
      30,    41,   119,   120,   121,    95,    32,   122,   123,   119,
     120,   121,    95,    51,   122,   123,   124,    41,    57,    57,
      30,   145,   110,   124,    74,    35,    52,    75,    55,    63,
     215,    55,    68,   217,   125,   126,    70,    81,    82,   127,
      84,   125,   126,    85,   -30,    45,   127,   119,   120,   121,
      95,    30,   122,   123,    30,    38,   151,    42,    30,    57,
      57,   124,    57,    15,    13,    57,   116,    16,     7,   152,
       8,   119,    79,    62,    95,    80,    17,    46,    96,   125,
     126,    14,    97,    98,   127,   205,    86,    58,   100,   137,
     211,   212,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    94,    39,    72,    95,    76,
      16,    49,    96,    59,    -3,     1,    97,    98,    99,    40,
      86,    94,   100,   101,    95,     2,    86,    83,    96,   170,
     171,   172,    97,    98,    99,    88,    86,   119,   100,   134,
      95,    74,    90,    91,    96,    25,    26,    27,    97,    98,
     112,   180,    86,    79,   100,   175,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   203,
     117,   115,   118,   133,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   218,   132,   150,
     153,   158,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   119,   159,   173,    95,   174,
     176,   181,    96,   187,   184,   204,    97,    98,   206,   183,
      86,   214,   100,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   188,   207,   213,   210,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    43,   216,    57,    10,    16,    36,   111,
      37,   135,   136,   186,     0,     0,    40,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     -31,   -31,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   -31,   -31,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   -31,   -31,   -31,   -31,   168,   169,
     170,   171,   172
};

static const yytype_int16 yycheck[] =
{
      15,    98,    17,   107,    72,    86,    17,    17,    49,    20,
      17,    24,    25,    20,   141,    83,    26,    58,    59,   116,
      23,   118,    90,    91,   105,    40,   107,   124,   125,   126,
     127,   158,   136,    74,     3,    38,    51,    52,    79,    42,
       3,     1,     3,   140,   112,   142,     0,   115,    17,     0,
       1,    18,    18,   150,    17,   136,    25,   184,     3,    62,
      11,    21,    25,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     3,     3,     3,   183,
      25,    21,     3,     4,     5,     6,     3,     8,     9,     3,
       4,     5,     6,     3,     8,     9,    17,    37,    25,    25,
      25,    22,   183,    17,    17,    21,    16,    20,    22,     3,
     207,    22,     3,   210,    35,    36,     3,     3,     3,    40,
       3,    35,    36,     3,     3,    21,    40,     3,     4,     5,
       6,    25,     8,     9,    25,    19,     3,    21,    25,    25,
      25,    17,    25,     3,     1,    25,    25,     7,     1,    16,
       3,     3,    17,    37,     6,    20,    16,    21,    10,    35,
      36,    18,    14,    15,    40,    20,    18,    17,    20,    21,
     185,   186,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     3,     3,    23,     6,    22,
       7,    17,    10,    17,     0,     1,    14,    15,    16,    16,
      18,     3,    20,    21,     6,    11,    18,    23,    10,    37,
      38,    39,    14,    15,    16,    19,    18,     3,    20,    21,
       6,    17,    23,    23,    10,    12,    13,    14,    14,    15,
      23,    22,    18,    17,    20,    21,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    22,
      17,    23,    17,     3,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    22,    25,    25,
      17,    17,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     3,    20,    22,     6,    20,
       3,    23,    10,    23,    17,    23,    14,    15,    20,    23,
      18,    20,    20,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    23,    19,    23,    25,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     3,    23,    25,     4,     7,    19,    88,
      19,   105,   105,   152,    -1,    -1,    16,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    31,    32,    33,    34,    35,    36,
      37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    11,    42,    43,    44,     3,     1,     3,     0,
      44,    18,    18,     1,    18,     3,     7,    16,    45,    46,
      48,    51,    52,    53,    54,    45,    45,    45,     3,    17,
      25,    47,     3,     3,    47,    21,    48,    51,    53,     3,
      16,    52,    53,     3,    54,    21,    21,     1,    21,    17,
      20,     3,    16,    55,    57,    22,     3,    25,    17,    17,
      20,     3,    53,     3,    47,     3,    47,    55,     3,    47,
       3,    47,    23,    56,    17,    20,    22,    55,    55,    17,
      20,     3,     3,    23,     3,     3,    18,    58,    19,    55,
      23,    23,    55,    58,     3,     6,    10,    14,    15,    16,
      20,    21,    49,    50,    58,    59,    60,    61,    62,    63,
      64,    57,    23,    58,    58,    23,    25,    17,    17,     3,
       4,     5,     8,     9,    17,    35,    36,    40,    64,    67,
      68,    69,    25,     3,    21,    60,    61,    21,    62,    24,
      25,    17,    26,    58,    58,    22,    68,    66,    68,    68,
      25,     3,    16,    17,    68,    68,    68,    68,    17,    20,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    22,    20,    21,     3,    68,    66,    68,
      22,    23,    65,    23,    17,    70,    70,    23,    23,    66,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    22,    23,    20,    20,    19,    62,    66,
      25,    47,    47,    23,    20,    68,    23,    68,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    48,    48,    48,    48,    49,    49,    49,
      50,    50,    51,    51,    52,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      58,    58,    58,    58,    59,    59,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    69,    69,    69,    70,    70
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
       4,     5,     5,     5,     3,     1,     1,     4,     3,     4,
       1,     1,     0,     3,     0,     2,     0,     1,     1,     1,
       1,     4,     3,     1,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     3,     3,     0,     4
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
#line 117 "program4.y" /* yacc.c:1646  */
    {
              tree = (yyvsp[0].ttype);
            }
#line 1576 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 123 "program4.y" /* yacc.c:1646  */
    {
               (yyval.ttype) = new Node;
               (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
               (yyval.ttype)->setValProd("<Program> --> <ClassDeclaration>+");
             }
#line 1586 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 128 "program4.y" /* yacc.c:1646  */
    {
                         (yyval.ttype) = (yyvsp[-1].ttype);
                         (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
                       }
#line 1595 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 134 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->setValProd("\n<ClassDeclaration> --> class identifier <ClassBody>");
  }
#line 1605 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 139 "program4.y" /* yacc.c:1646  */
    {
    yyerrok;
    yyerror("Parse error on class", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    yyclearin;
  }
#line 1615 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 144 "program4.y" /* yacc.c:1646  */
    {
    yyerrok;
    yyerror("Parse error on identifier", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    yyclearin;
  }
#line 1625 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 149 "program4.y" /* yacc.c:1646  */
    {
    yyerrok;
    yyerror("Parse error on [", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    yyclearin;
  }
#line 1635 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 154 "program4.y" /* yacc.c:1646  */
    {
    yyerrok;
    yyerror("Parse error on ]", (yylsp[0]).first_line, (yylsp[0]).first_column);
    yyclearin;
  }
#line 1645 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 163 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <VarDeclaration>+ <ConstructorDeclaration>+ <MethodDeclaration>+ }");
  }
#line 1657 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 170 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <VarDeclaration>+ <ConstructorDeclaration>+ }");
  }
#line 1668 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 176 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <VarDeclaration>+ <MethodDeclaration>+ }");
  }
#line 1679 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 182 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <ConstructorDeclaration>+ <MethodDeclaration>+ }");
  }
#line 1690 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 188 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <MethodDeclaration>+ }");
  }
#line 1700 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 193 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <VarDeclaration>+ }");
  }
#line 1710 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 198 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<ClassBody> --> { <ConstructorDeclaration>+ }");
  }
#line 1720 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 203 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 1726 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 208 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1735 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 212 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype)); }
#line 1741 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 217 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->setValProd("<[]>* --> []"); }
#line 1747 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 218 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<[]>* --> []");
  }
#line 1757 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 226 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<VarDeclaration> --> identifier identifier ;");
  }
#line 1766 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 230 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<VarDeclaration> --> int identifier ;");
  }
#line 1775 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 234 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<VarDeclaration> --> identifier <[]>* identifier ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
  }
#line 1785 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 239 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<VarDeclaration> --> int <[]>* identifier ;");
  }
#line 1794 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 247 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Type> --> int");
  }
#line 1803 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 251 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Type> --> identifier []");
  }
#line 1812 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 255 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<Type> --> <Type> [ ]");
  }
#line 1822 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 264 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Type> --> identifier");
  }
#line 1831 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 268 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1840 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 276 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1849 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 280 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1858 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 287 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<ConstructorDeclaration> --> identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-4].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1870 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 298 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1879 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 302 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype)); }
#line 1885 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 307 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> int identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1896 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 313 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> identifier identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1907 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 319 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> void identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1918 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 325 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> int <[]>* identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-5].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1930 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 332 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<MethodDeclaration> --> identifier <[]>* identifier ( <ParameterList> ) <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-5].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1942 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 343 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 1948 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 344 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<ParameterList> --> <Parameter> <, <Parameter> >*");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1959 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 354 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 1965 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 355 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-2].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 1974 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 363 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Parameter> --> identifier identifier");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 1984 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 368 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Parameter> --> int identifier");
  }
#line 1993 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 372 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Parameter> --> identifier <[]>* identifier");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2003 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 377 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Parameter> --> int <[]>* identifier");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2013 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 386 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2024 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 392 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2034 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 397 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2044 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 402 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
  }
#line 2053 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 410 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype)); }
#line 2059 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 411 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2068 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 419 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<LocalVarDeclaration> --> <Type> identifier ;");
  }
#line 2078 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 428 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2087 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 432 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-1].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2096 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 440 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> ;");
  }
#line 2105 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 444 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> <Name> = <Expression> ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-3].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2116 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 450 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> <Name> ( <ArgList> ) ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-4].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
  }
#line 2127 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 456 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> print ( <ArgList> ) ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
  }
#line 2137 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 461 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> while ( <Expression> ) <Statement>");
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2148 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 467 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> return <OptionalExpression> ;");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2158 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 472 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Statement> --> <Block>");
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2168 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 481 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValKeyw("this");
    (yyval.ttype)->setValProd("<Name> --> this");
  }
#line 2178 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 486 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Name> --> identifier [ <Expression> ]");
  }
#line 2187 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 490 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->setValProd("<Name> --> <Name> . identifier");
  }
#line 2197 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 495 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-3].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->setValProd("<Name> --> <Name> [ <Expression> ]");
  }
#line 2208 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 505 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Name> --> identifier");
  }
#line 2217 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 509 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2226 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 517 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 2232 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 518 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-2].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2241 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 526 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 2247 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 527 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<ArgList> --> <Expression> <,<Expression> >*");
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
  }
#line 2258 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 537 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; (yyval.ttype)->setValProd("<OptionalExpression> --> epsilon"); }
#line 2264 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 538 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<OptionalExpression> --> <Expression>");
  }
#line 2274 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 547 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Name>");
  }
#line 2284 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 552 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Expression> --> number");
  }
#line 2293 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 556 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Expression> --> null");
  }
#line 2302 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 560 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Expression> --> <Name> ( <ArgList> )");
    (yyval.ttype)->pushNonTerminal((yyvsp[-3].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2313 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 566 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->setValProd("<Expression> --> read ( )");
  }
#line 2322 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 570 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <NewExpression>");
  }
#line 2332 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 575 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> + <Expression>");
  }
#line 2342 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 580 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> - <Expression>");
  }
#line 2352 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 585 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> ! <Expression>");
  }
#line 2362 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 590 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> == <Expression>");
  }
#line 2373 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 596 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> != <Expression>");
  }
#line 2384 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 602 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> <= <Expression>");
  }
#line 2395 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 608 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> >= <Expression>");
  }
#line 2406 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 614 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> > <Expression>");
  }
#line 2417 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 620 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> < <Expression>");
  }
#line 2428 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 626 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> + <Expression>");
  }
#line 2439 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 632 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> - <Expression>");
  }
#line 2450 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 638 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> || <Expression>");
  }
#line 2461 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 644 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> * <Expression>");
  }
#line 2472 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 650 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> / <Expression>");
  }
#line 2483 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 656 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> % <Expression>");
  }
#line 2494 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 662 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-2].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<Expression> --> <Expression> && <Expression>");
  }
#line 2505 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 668 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->setValProd("<Expression> --> ( <Expression> )");
  }
#line 2515 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 676 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new identifier ( <ArgList> )");
  }
#line 2525 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 681 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new int <[ Expression ]>* <[ ]>+");
  }
#line 2536 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 687 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new identifier <[ Expression ]>* <[ ]>*");
  }
#line 2547 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 693 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new int <[ Expression ]>*");
  }
#line 2557 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 698 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = new Node;
    (yyval.ttype)->pushNonTerminal((yyvsp[0].ttype));
    (yyval.ttype)->setValProd("<NewExpression> --> new identifier <[ Expression ]>*");
  }
#line 2567 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 707 "program4.y" /* yacc.c:1646  */
    { (yyval.ttype) = new Node; }
#line 2573 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 708 "program4.y" /* yacc.c:1646  */
    {
    (yyval.ttype) = (yyvsp[-3].ttype);
    (yyval.ttype)->pushNonTerminal((yyvsp[-1].ttype));
  }
#line 2582 "program4.tab.c" /* yacc.c:1646  */
    break;


#line 2586 "program4.tab.c" /* yacc.c:1646  */
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
#line 714 "program4.y" /* yacc.c:1906  */

