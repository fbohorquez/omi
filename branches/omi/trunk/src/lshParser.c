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
#line 1 "lshParser.y" /* yacc.c:339  */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "run/tree/typeNode.h"
#include "run/table/classNode.h"
#include "run/operators/opNode.h"
//#include "run/stmts/stmtNode.h"

#include "error.h"
#include "interpreter.h"
#include "plugin.h"

using namespace std;

#define YYERROR_VERBOSE
extern int yylex(void);
extern void yy_scan_string (const char*);
extern char* yytext;
extern FILE *yyin;
extern int yylineno;
string infile ("");
bool inline_param = false; 
//#include "run/stmtNode.h"

#line 99 "lshParser.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_LSHPARSER_H_INCLUDED
# define YY_YY_LSHPARSER_H_INCLUDED
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
    NUM = 258,
    SNUM = 259,
    REXP = 260,
    STR = 261,
    NULLTOKEN = 262,
    TRUE = 263,
    FALSE = 264,
    ID = 265,
    OP = 266,
    PRINT = 267,
    INC = 268,
    DEC = 269,
    NAMESPACE = 270,
    INCLUDE = 271,
    GLOBAL = 272,
    ISNULL = 273,
    EQL = 274,
    AND_OP = 275,
    OR_OP = 276,
    ISARRAY = 277,
    ISNUM = 278,
    ISBOOL = 279,
    ISSTRING = 280,
    ISOBJECT = 281,
    FUNCTION = 282,
    PARTIALFUNC = 283,
    RET = 284,
    DECORATOR = 285,
    CONTEXTFUNC = 286,
    CLASS = 287,
    NEW = 288,
    CLASSACCESS = 289,
    THIS = 290,
    PARENT = 291,
    PRIVATE = 292,
    STATIC = 293,
    EXTENDS = 294,
    GETCLASS = 295,
    IF = 296,
    ELSE = 297,
    ELSEIF = 298,
    WITH = 299,
    DO = 300,
    WHILE = 301,
    AS = 302,
    OPINC = 303,
    FOR = 304,
    IN = 305,
    GOTO = 306,
    SWITCH = 307,
    CASE = 308,
    DEFAULT = 309,
    TYPEOF = 310,
    SIZEOF = 311,
    DATINFO = 312,
    BREAK = 313,
    EXIT = 314,
    SIZE = 315,
    EMPTY = 316,
    CONTINUE = 317,
    TRY = 318,
    CATCH = 319,
    THROW = 320,
    FLOW = 321,
    FLOWLINE = 322,
    SQRT = 323,
    ADDASIG = 324,
    SUBASIG = 325,
    PRODASIG = 326,
    DIVASIG = 327,
    POWASIG = 328,
    MODASIG = 329,
    CATASIG = 330,
    IDEN = 331,
    NIDEN = 332,
    EXPLODE = 333,
    IMPLODE = 334,
    SPRINTF = 335,
    FIND = 336,
    REPLACE = 337,
    SUBREPLACE = 338,
    UPPER = 339,
    LOWER = 340,
    DATE = 341,
    TIME = 342,
    SLEEP = 343,
    GETENV = 344,
    REDUCE = 345,
    FTOKEN = 346,
    FPUT = 347,
    FGET = 348,
    FSEEK = 349,
    FEND = 350,
    FCUR = 351,
    FSET = 352,
    FTELL = 353,
    FCLOSE = 354,
    FREAD = 355,
    FWRITE = 356,
    FAPP = 357,
    FORK = 358,
    WAIT = 359,
    GETPID = 360,
    GETPPID = 361,
    PROCESSTOKEN = 362,
    EXITPROCESS = 363,
    SIGNAL = 364,
    SHANDLER = 365,
    INPUT = 366,
    INPUTLINE = 367,
    MATCH = 368,
    REGEXP = 369,
    SEARCH = 370,
    EXEC = 371,
    EVAL = 372,
    ARRAYCHUNK = 373,
    ARRAYLAST = 374,
    ARRAYFIRST = 375,
    ARRAYINSERT = 376,
    ARRAYDELETE = 377,
    ARRAYUNSHIFT = 378,
    ARRAYPUSH = 379,
    ARRAYSHIFT = 380,
    ARRAYPOP = 381,
    LOAD_MODULE = 382,
    CINT = 383,
    CFLOAT = 384,
    CBOOL = 385,
    CSTR = 386
  };
#endif
/* Tokens.  */
#define NUM 258
#define SNUM 259
#define REXP 260
#define STR 261
#define NULLTOKEN 262
#define TRUE 263
#define FALSE 264
#define ID 265
#define OP 266
#define PRINT 267
#define INC 268
#define DEC 269
#define NAMESPACE 270
#define INCLUDE 271
#define GLOBAL 272
#define ISNULL 273
#define EQL 274
#define AND_OP 275
#define OR_OP 276
#define ISARRAY 277
#define ISNUM 278
#define ISBOOL 279
#define ISSTRING 280
#define ISOBJECT 281
#define FUNCTION 282
#define PARTIALFUNC 283
#define RET 284
#define DECORATOR 285
#define CONTEXTFUNC 286
#define CLASS 287
#define NEW 288
#define CLASSACCESS 289
#define THIS 290
#define PARENT 291
#define PRIVATE 292
#define STATIC 293
#define EXTENDS 294
#define GETCLASS 295
#define IF 296
#define ELSE 297
#define ELSEIF 298
#define WITH 299
#define DO 300
#define WHILE 301
#define AS 302
#define OPINC 303
#define FOR 304
#define IN 305
#define GOTO 306
#define SWITCH 307
#define CASE 308
#define DEFAULT 309
#define TYPEOF 310
#define SIZEOF 311
#define DATINFO 312
#define BREAK 313
#define EXIT 314
#define SIZE 315
#define EMPTY 316
#define CONTINUE 317
#define TRY 318
#define CATCH 319
#define THROW 320
#define FLOW 321
#define FLOWLINE 322
#define SQRT 323
#define ADDASIG 324
#define SUBASIG 325
#define PRODASIG 326
#define DIVASIG 327
#define POWASIG 328
#define MODASIG 329
#define CATASIG 330
#define IDEN 331
#define NIDEN 332
#define EXPLODE 333
#define IMPLODE 334
#define SPRINTF 335
#define FIND 336
#define REPLACE 337
#define SUBREPLACE 338
#define UPPER 339
#define LOWER 340
#define DATE 341
#define TIME 342
#define SLEEP 343
#define GETENV 344
#define REDUCE 345
#define FTOKEN 346
#define FPUT 347
#define FGET 348
#define FSEEK 349
#define FEND 350
#define FCUR 351
#define FSET 352
#define FTELL 353
#define FCLOSE 354
#define FREAD 355
#define FWRITE 356
#define FAPP 357
#define FORK 358
#define WAIT 359
#define GETPID 360
#define GETPPID 361
#define PROCESSTOKEN 362
#define EXITPROCESS 363
#define SIGNAL 364
#define SHANDLER 365
#define INPUT 366
#define INPUTLINE 367
#define MATCH 368
#define REGEXP 369
#define SEARCH 370
#define EXEC 371
#define EVAL 372
#define ARRAYCHUNK 373
#define ARRAYLAST 374
#define ARRAYFIRST 375
#define ARRAYINSERT 376
#define ARRAYDELETE 377
#define ARRAYUNSHIFT 378
#define ARRAYPUSH 379
#define ARRAYSHIFT 380
#define ARRAYPOP 381
#define LOAD_MODULE 382
#define CINT 383
#define CFLOAT 384
#define CBOOL 385
#define CSTR 386

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 53 "lshParser.y" /* yacc.c:355  */

  num* fval;
  string* str; 
  idNode* idnode;
  listNode* listnode;
  runNode* data;
  runNode** ref;
  vector<string>* mval;

#line 411 "lshParser.c" /* yacc.c:355  */
};
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

#endif /* !YY_YY_LSHPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 440 "lshParser.c" /* yacc.c:358  */

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
#define YYFINAL  322
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   20070

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  157
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  484
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1226

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   386

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   143,     2,     2,   138,   151,   142,     2,
     133,   134,   148,   146,   139,   147,   152,   149,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   135,   132,
     144,   141,   145,   155,   156,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   153,     2,   154,   150,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   136,     2,   137,   140,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,   105,   109,   119,   129,   139,   149,   159,
     169,   170,   176,   186,   196,   206,   216,   226,   236,   237,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     255,   256,   266,   276,   286,   296,   306,   316,   325,   335,
     345,   355,   365,   382,   399,   416,   433,   443,   453,   463,
     473,   482,   495,   499,   500,   502,   515,   526,   537,   555,
     566,   577,   588,   599,   617,   635,   646,   657,   675,   693,
     718,   736,   747,   758,   776,   787,   798,   809,   828,   842,
     853,   864,   882,   893,   904,   915,   926,   944,   962,   973,
     984,  1002,  1020,  1045,  1063,  1074,  1085,  1103,  1114,  1125,
    1136,  1154,  1168,  1179,  1200,  1211,  1222,  1240,  1254,  1265,
    1276,  1294,  1308,  1319,  1330,  1348,  1359,  1370,  1381,  1399,
    1410,  1421,  1432,  1443,  1454,  1465,  1476,  1487,  1498,  1509,
    1520,  1531,  1542,  1553,  1564,  1575,  1586,  1597,  1608,  1619,
    1630,  1641,  1652,  1663,  1677,  1686,  1695,  1704,  1716,  1727,
    1741,  1752,  1763,  1774,  1788,  1805,  1822,  1848,  1865,  1876,
    1887,  1905,  1916,  1927,  1938,  1956,  1967,  1978,  1989,  2007,
    2018,  2029,  2040,  2058,  2069,  2080,  2091,  2109,  2120,  2131,
    2142,  2160,  2175,  2186,  2204,  2229,  2250,  2255,  2266,  2277,
    2288,  2299,  2310,  2321,  2332,  2343,  2383,  2423,  2463,  2505,
    2516,  2527,  2537,  2551,  2569,  2587,  2605,  2610,  2620,  2637,
    2647,  2668,  2672,  2676,  2687,  2691,  2702,  2706,  2716,  2720,
    2731,  2742,  2753,  2764,  2775,  2786,  2797,  2808,  2813,  2817,
    2828,  2839,  2875,  2879,  2890,  2901,  2905,  2916,  2927,  2932,
    2936,  2947,  2958,  2969,  2973,  2983,  2993,  3004,  3015,  3031,
    3047,  3064,  3081,  3086,  3097,  3108,  3113,  3117,  3128,  3139,
    3150,  3154,  3164,  3169,  3170,  3171,  3172,  3173,  3176,  3177,
    3178,  3179,  3180,  3181,  3182,  3185,  3186,  3199,  3209,  3219,
    3229,  3239,  3243,  3262,  3281,  3300,  3319,  3338,  3357,  3376,
    3380,  3390,  3400,  3410,  3420,  3430,  3440,  3450,  3463,  3473,
    3483,  3493,  3503,  3513,  3523,  3536,  3546,  3556,  3566,  3579,
    3590,  3601,  3611,  3622,  3633,  3644,  3655,  3666,  3676,  3689,
    3700,  3711,  3722,  3731,  3740,  3741,  3754,  3764,  3774,  3783,
    3784,  3788,  3799,  3810,  3819,  3831,  3842,  3853,  3864,  3875,
    3886,  3897,  3908,  3918,  3928,  3939,  3950,  3961,  3972,  3985,
    3995,  4005,  4014,  4024,  4033,  4045,  4056,  4065,  4074,  4083,
    4094,  4108,  4121,  4132,  4143,  4154,  4165,  4176,  4187,  4198,
    4209,  4220,  4231,  4242,  4253,  4264,  4275,  4286,  4297,  4308,
    4319,  4330,  4341,  4352,  4363,  4374,  4385,  4396,  4407,  4418,
    4429,  4440,  4451,  4462,  4473,  4484,  4495,  4506,  4518,  4529,
    4540,  4551,  4562,  4573,  4584,  4595,  4606,  4617,  4628,  4639,
    4653,  4663,  4674,  4685,  4699,  4708,  4727,  4736,  4745,  4754,
    4763,  4772,  4781,  4790,  4799,  4808,  4809,  4813,  4814,  4815,
    4828,  4839,  4850,  4861,  4870,  4880,  4891,  4902,  4913,  4922,
    4932,  4953,  4964,  4975,  4986,  4997,  5008,  5023,  5033,  5043,
    5056,  5066,  5076,  5089,  5100,  5105,  5116,  5121,  5131,  5144,
    5155,  5166,  5177,  5188,  5199,  5216,  5233,  5250,  5251,  5255,
    5266,  5276,  5286,  5297,  5308,  5319,  5330,  5340,  5350,  5365,
    5376,  5387,  5404,  5425,  5434
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "SNUM", "REXP", "STR",
  "NULLTOKEN", "TRUE", "FALSE", "ID", "OP", "PRINT", "INC", "DEC",
  "NAMESPACE", "INCLUDE", "GLOBAL", "ISNULL", "EQL", "AND_OP", "OR_OP",
  "ISARRAY", "ISNUM", "ISBOOL", "ISSTRING", "ISOBJECT", "FUNCTION",
  "PARTIALFUNC", "RET", "DECORATOR", "CONTEXTFUNC", "CLASS", "NEW",
  "CLASSACCESS", "THIS", "PARENT", "PRIVATE", "STATIC", "EXTENDS",
  "GETCLASS", "IF", "ELSE", "ELSEIF", "WITH", "DO", "WHILE", "AS", "OPINC",
  "FOR", "IN", "GOTO", "SWITCH", "CASE", "DEFAULT", "TYPEOF", "SIZEOF",
  "DATINFO", "BREAK", "EXIT", "SIZE", "EMPTY", "CONTINUE", "TRY", "CATCH",
  "THROW", "FLOW", "FLOWLINE", "SQRT", "ADDASIG", "SUBASIG", "PRODASIG",
  "DIVASIG", "POWASIG", "MODASIG", "CATASIG", "IDEN", "NIDEN", "EXPLODE",
  "IMPLODE", "SPRINTF", "FIND", "REPLACE", "SUBREPLACE", "UPPER", "LOWER",
  "DATE", "TIME", "SLEEP", "GETENV", "REDUCE", "FTOKEN", "FPUT", "FGET",
  "FSEEK", "FEND", "FCUR", "FSET", "FTELL", "FCLOSE", "FREAD", "FWRITE",
  "FAPP", "FORK", "WAIT", "GETPID", "GETPPID", "PROCESSTOKEN",
  "EXITPROCESS", "SIGNAL", "SHANDLER", "INPUT", "INPUTLINE", "MATCH",
  "REGEXP", "SEARCH", "EXEC", "EVAL", "ARRAYCHUNK", "ARRAYLAST",
  "ARRAYFIRST", "ARRAYINSERT", "ARRAYDELETE", "ARRAYUNSHIFT", "ARRAYPUSH",
  "ARRAYSHIFT", "ARRAYPOP", "LOAD_MODULE", "CINT", "CFLOAT", "CBOOL",
  "CSTR", "';'", "'('", "')'", "':'", "'{'", "'}'", "'$'", "','", "'~'",
  "'='", "'&'", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'^'",
  "'%'", "'.'", "'['", "']'", "'?'", "'@'", "$accept", "program", "stmts",
  "stmts_level", "stmtb", "stmt", "label", "define", "if", "elseif",
  "with", "while", "dowhile", "for", "break", "switch", "cases", "iloop",
  "trycatch", "lblock", "function", "class", "params_default", "params",
  "exp", "lexp", "lop1", "lop2", "lop3", "lop4", "aexp", "aop1", "aop2",
  "aop3", "sexp", "sop1", "sop2", "call_identity", "extra_operator",
  "tern", "notnull", "unity", "inc_dec", "assignation", "cexp",
  "lop_unity", "aop_unity", "sop_unity", "class_exp", "arrayexp", "date",
  "file", "process", "environment", "exp_generator", "regexp_op",
  "iloop_access", "identity", "function_exp", "function_lambda",
  "function_partial", "list", "map", "mapelement", "assig", "array",
  "parray", "arrayop", "namespace", "id", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,    59,    40,    41,    58,   123,   125,    36,    44,
     126,    61,    38,    33,    60,    62,    43,    45,    42,    47,
      94,    37,    46,    91,    93,    63,    64
};
# endif

#define YYPACT_NINF -906

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-906)))

#define YYTABLE_NINF -459

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2512,   -46,  -906,  -906,  -906,  -906,  -906,  -906,  -906,  -906,
   17912, 19760, 19760, 17912,    59, 17912, 17912, 17912, 17912, 17912,
   17912,     1,   -78, 17912,    47,  -906,    47,    47,  -906,    94,
   16526, 15910,   -21,   -11, 17912,  9596,   -11, 18066,    47,    -4,
      20, 17912, 18220,    23,  -906, 17912,     7,    81, 14216, 17912,
   17912, 17912, 17912,    11,   124,   164,   192,   206,   226,   333,
     335,   369,   375,   382,   391,   392,   393,   394,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     409,   410,   411,    28,    33,   412,   413,   414,   415,   416,
     417,   419,   420,   421,   422,   423,   426,   427,   428,   429,
   19760, 19760, 19760, 19760,  -906, 18374, 16064,   236,     8, 17912,
   17912,   133,   139,     9,   176,   149,  -906,  2666,   186,  9288,
    -906,  -906,  -906,  -906,  -906,  -906,  -906,  -906,  -906,  -906,
    -906,  -906,  -906,  -906,   330,   365,  -906,  -906,   212,    25,
     184,   -58,  -906,  -906,   237,   220,  -906,  -906,  -906,   -27,
    -906,   357,  -906,  -906,  -906,  -906,  -906,   349,  -906,  -906,
    -906,  -906,  -906,  -906,  -906,  -906,  -906,  -906,  -906,   348,
      66,  -906,   378,    92,  9288,   -48,   386,   430,     8,  -906,
     536,   220,   357,   357,  -906, 17912,   431,  -906,  -906,  -906,
    -906,  -906,  -906,  -906,    12,    47,   432,    35,  -906,   435,
      31,   436,    47, 16218,  -906,  -906,    47, 16680,  -906,  -906,
   17912, 17912,  9750, 14370,  3436,   518,   447,  9904, 18374,    91,
      63,  -906, 17912,    47,  -906,  -906, 18374,  -906,   449,  -906,
    -906, 17912,   450,  -906, 18528, 16372,  3590,   455,  -906,  -906,
    -906,  -906, 17912, 17912, 17912, 17912, 17912, 17912, 17912, 17912,
   17912,   438, 17912, 17912, 17912, 17912, 17912, 17912, 17912, 17912,
   17912, 17912, 17912, 17912,   443, 16834,   444,   456, 17912,   457,
   17912, 17912, 17912,  -906, 17912,  -906, 17912, 17912, 17912, 17912,
   17912, 17912, 17912, 17912, 17912, 17912, 17912, 17912, 17912, 17912,
   17912,   160,   160,   160,   160, 19144, 19298, 19452, 19606,   232,
    -906,  -906,   460,   239,  -906,   303, 17912,   581,    18,    47,
     340,   462,   -60,  -906,  -906,  -906,  -906,    47, 17912,   -67,
     459, 17912,  -906,  -906,  2820,  -906, 17912, 17912, 18990, 18990,
   18990,   464, 18682, 18836,  -906, 18990, 18990, 18990, 18990, 18990,
   18990, 18990, 18990, 18990,    47, 16988, 17142, 17296, 17450,  -906,
    -906, 17912, 17912, 17912, 17912, 17912, 17912, 17912, 17912,    47,
   17604,    47,    47,  -906,  -906,   469,  -906,   470,   -18,  -906,
      24,   -57,    27,    47,  9442, 17758,  -906,  -906,  -906,  -906,
    -906,  -906,   474,   475,  3744,   418,   482,  3590,   483,   484,
    -906,   550,   480,  2974,   486,  9442,   481,   341,   -11,   573,
    3898,  -906,   489,   279,    87,    47, 17912, 17912,    47,   488,
     490,   274,  -906,   491,  -906,   492,   559,   487,   493,  -906,
     -15,   494,   495,   496,   502,   503,   -14,  -906,   504,   505,
     501,    -7,   506,   185,   507,   508,   510,   513,   511,   512,
    -906,  -906,   514,  -906,  -906,   188,  -906,   515,   517,   473,
     476,   519,   523,   521,   527,   528,   524,   531,   532,   530,
     533,   534,   538,   537,   544,   545, 19760, 19760, 19760, 19760,
      26,  -906, 17912, 17912,  -906, 16680,  -906, 17912,   273,   516,
     546,   195,   342, 17912,    47,    46,    45,    59,  -906,   -56,
   19760,   543,  -906,   365,  -906,  -906,  -906,  -906, 18990, 18990,
    -906, 18990,  -906,   184,   184,   -58,   -58,  -906,  -906,  -906,
    -906,  -906,  -906,  -906,   215,  -906,   529,  -906,   539, 17912,
     549,  -906,  -906,  -906,  -906,  -906,  -906,  -906,  -906,  -906,
    -906,   541,  -906,  -906,  4052,   551,   552,   229, 19914,   554,
     252,   560,   548,  -906,   253,  -906,  -906,   362,   561, 10058,
     -11,  -906,   440,   562,  -906,  9442,   -11,   582,  -906,  3128,
    -906,   535,   -11,  1554,   563,  -906,    47, 17912, 17912,    47,
   14062,   569, 14524,   591,   566,  -906,    77,  -906,   579,   553,
   17912, 17912,  -906, 17912, 17912, 17912, 17912,  -906,  -906,  -906,
   17912,  -906,  -906, 17912,  -906, 17912, 17912,  -906, 17912, 17912,
    -906,  -906,  -906, 17912, 17912,  -906,  -906, 17912, 17912, 17912,
      47,    47, 17912,  -906, 17912,  -906,  -906, 17912,  -906,  -906,
   17912, 17912, 17912, 17912,  -906,  -906,  -906,   160,   160,   160,
     160,    47,    10,   600,  -906,   460,  -906,  -906,    47,   678,
   10212, 17912,  -906,  4206,   567,  -906,   564,    47,   565,   568,
     260,  -906,   555,   160,  -906,  -906,  -906,  -906,  -906,  -906,
    -906,  -906, 17912,  -906,  -906,   570,  4360,  4514,   572, 18374,
     349,   161,  4668,   574,  9442,  -906,  -906, 10366,  -906,   442,
    4822,  -906,   580, 10520, 10674,  -906,  -906,  -906,   583,   -11,
    -906,  -906,   584,  -906,   352,   585,   577,   663,    47,  4976,
     586, 17912,  5130,   587, 17912,   308,   588,    47,   589,   590,
    -906,   290,   575,   593,   592,   594,   595,   599,   601,   291,
     603,   604,   307,   605,   606,  -906,  -906,   607,   309,   608,
     609,   610,   611,   612,    21, 17912,    47,    40,   -24,   613,
    5284,  -906,   617,   616,  -906,   614,  5438,    59,  -906,    59,
    5592,   618,  -906,  -906,  -906,  -906,   615,  -906,   619,  5746,
     -33,   621,    44,  -906,   622,  5900,   623,  3590,  -906,   626,
   10828,  -906,  1554,   624,  -906,  6054,   446,   630,  6208,  -906,
     631,  -906,   632,  -906, 14678,    47, 17912, 14832, 17912, 14986,
    1554,   629,  -906, 10982,  1554,   633,  -906, 15140, 17912,   636,
    -906,   635,    47,   639,  -906,  -906,  -906, 17912, 17912, 17912,
    -906,  -906,  -906,  -906,  -906,  -906,   331,  -906,  -906,  -906,
    -906,  -906,  -906,  -906, 17912,  -906, 17912,  -906,  -906,  -906,
   17912,    47, 12830,   670,    47,   280, 11136,    47, 17912, 11290,
    1554,   638,  -906, 11444,  -906,  -906,   640,  -906,  -906,  -906,
     642,  6362,  -906,  -906,  -906,   643,  -906,  -906,  -906,  -906,
    -906,   644,  -906,   645,  -906,  6516,  -906,   651,  -906,   817,
     647, 11598,  -906,   452,  1554,   648,  -906,  -906,  6670,   654,
     653,   655,  6824,   658,   657,  6978,   660,  -906,  7132,  -906,
     661,  -906,  7286,   662,   665,  9442,  -906,   667, 15294,   668,
     310,   628,   669,   671,   672,   319,   673,   674,   677, 17912,
    -906,  3590,     5, 17912,   281, 17912,    47,  7440,  -906,   664,
     325,   675,  7594,  -906,   679,  -906,  7748,  -906,   680,  -906,
    -906,  -906,   676,  -906,  -906,  -906,  1554,   681,  -906, 11752,
    -906,   454,  7902,  -906,   683, 11906,  -906,  -906,  1554,   682,
    -906, 15448, 12060,  1554,   684,  -906, 15602,  1554,   685,  -906,
    1554,   686,  -906,  1554,   687,  -906,  3282,  -906, 15756,  3590,
     693,  -906,  -906, 17912, 17912,  -906,  -906,  -906,  -906,  -906,
   12984, 17912,   692,   690, 17912,  -906, 13138, 17912,    47, 13292,
     703,  1554,   694,  -906, 12214, 17912, 12368,  1554,   695,  -906,
    1554,   696,  -906,  -906,  -906,  3590,  -906,   697, 12522,  -906,
    1554,   698,  -906,  8056,  -906,   702,  -906,  8210,   707,  8364,
    -906,   708,  -906,  8518,   709,  -906,  -906,  -906,   445,  -906,
    3590,   710,   706,  -906,   712,   713, 17912,  -906,  3590,    13,
     715,  -906,   107,   716, 17912,  -906,  3590,   122,   718,   745,
   17912,  -906,  3590,   129, 17912,  -906,  8672,  -906,   721,   720,
    8826,  -906,   724,  -906,  -906,   725,  -906,  8980,  -906,   726,
    -906,  1554,   727,  -906,  1554,   728,  -906,  1554,   729,  -906,
    1554,   730,  -906,  -906,   732,  -906,  -906,  -906,  -906,   723,
     733, 17912,  -906, 13446, 17912,  -906,  -906,   737,   736, 17912,
    -906, 13600, 17912,   740,   739, 17912,  -906, 13754,  1554,   742,
    -906, 12676,  1554,   743,  -906,  -906,  1554,   746,  -906,  -906,
    -906,  -906,  -906,  -906,  -906,   218,   750, 17912,  -906,  3590,
     224,   761,  -906,   246,   762, 17912,  -906,  3590,   250,   763,
    -906,   254,   764, 17912,  -906,  3590,   261,  -906,  9134,  -906,
     731,  -906,  -906, 17912,  -906,  -906,   766,   765, 17912,  -906,
    -906, 17912,  -906,  -906,   770,   769, 17912,  -906, 13908, 17912,
    -906,  -906,   774,   772, 17912,  -906,  1554,   773,  -906,   777,
    -906,   264,   779,   780,  -906,   266,   781, 17912,  -906,  3590,
     268,   783,  -906,   269,   784,  -906,  -906, 17912,  -906,  -906,
    -906, 17912,  -906,  -906,   785,   786, 17912,  -906,  -906, 17912,
    -906,  -906,   787,   788,  -906,   276,   790,   791,  -906,  -906,
   17912,  -906,  -906,  -906,   792,  -906
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   416,   420,   422,   421,   419,   417,   418,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,   429,     0,     0,   322,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   308,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,   414,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     7,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      53,    54,    30,   211,   212,   214,   216,   218,   227,   228,
     232,   235,   238,   239,   243,   252,   255,   256,   260,   262,
     263,   281,   264,   265,   266,   267,   468,   456,   268,   269,
     270,   272,   271,   273,   274,   467,   275,   427,   428,   289,
     329,   330,   324,   425,     0,     0,     0,   414,     0,    31,
     425,     0,   277,   279,    35,     0,     0,   425,   298,   303,
     300,   299,   301,   302,     0,     0,     0,     0,    36,     0,
       0,   320,     0,     0,   202,    41,     0,     0,   201,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     425,    34,     0,     0,    46,   307,     0,    48,     0,   144,
     305,     0,     0,   146,     0,     0,     0,     0,    51,    32,
      33,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,   245,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,   291,   292,   293,     0,     0,     0,     0,     0,
     328,   454,   458,     0,   452,     0,     0,     0,     0,     0,
       0,   206,   209,   276,   217,   423,   424,     0,     0,     0,
     209,     0,     1,     5,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    10,     0,    55,     0,     0,   434,
       0,     0,     0,     0,     0,     0,   481,    42,    43,   482,
      44,    45,     0,     0,     0,    59,     0,     0,     0,     0,
      19,   328,     0,     0,    15,     0,    53,    30,     0,     0,
       0,   107,     0,     0,   425,     0,     0,     0,     0,     0,
       0,     0,   145,     0,   147,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,     0,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     351,   353,     0,   357,   358,     0,   356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,     0,     0,   327,   451,   326,     0,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,   210,     0,
       0,     0,     4,   213,   215,   223,   224,   225,     0,     0,
     219,     0,   221,   229,   230,   233,   234,   236,   237,   241,
     242,   240,   461,   254,     0,   466,     0,   465,     0,     0,
     259,   455,   282,   283,   284,   285,   286,   287,   288,   459,
     464,     0,   479,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,   325,   186,    56,     0,     0,
       0,    78,    58,     0,   103,     0,     0,     0,    13,     0,
      17,     0,     0,   104,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,   426,   304,     0,     0,
       0,     0,   311,   447,     0,     0,     0,   317,   318,   331,
       0,    38,   361,     0,   336,     0,     0,   340,     0,     0,
     348,   343,   342,     0,     0,   352,   360,     0,     0,     0,
     250,   251,     0,   410,     0,   349,   350,     0,   470,   471,
       0,     0,     0,     0,   476,   477,    39,   294,   295,   296,
     297,     0,     0,     0,   453,     0,   450,   457,     0,     0,
       0,     0,   415,     0,     0,   440,     0,     0,   207,     0,
       0,   205,     0,   446,   484,   226,   220,   222,   253,   463,
     462,   258,     0,   460,   433,     0,     0,     0,     0,     0,
     442,   441,     0,     0,     0,   199,   321,     0,    75,    57,
       0,    74,     0,     0,     0,    77,   102,    18,     0,     0,
      12,   111,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     448,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   438,     0,     0,     0,   208,     0,
       0,     0,   261,   257,   430,   432,     0,   190,     0,     0,
     456,   275,   425,   198,     0,     0,     0,     0,    65,     0,
       0,    76,    71,     0,    73,     0,    82,     0,     0,    70,
       0,   108,     0,   110,     0,     0,     0,     0,     0,     0,
     135,     0,   137,     0,   123,     0,   125,     0,     0,     0,
     148,     0,     0,     0,   309,   310,   313,     0,     0,     0,
     332,   478,   335,   337,   341,   344,     0,   338,   339,   359,
     354,   355,   413,   411,     0,   469,     0,   473,   474,   475,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,     0,   160,     0,   435,   437,     0,   203,   204,   194,
       0,     0,   431,   189,   188,     0,   445,   444,   443,   197,
     196,     0,   200,     0,    63,     0,    66,     0,    72,    79,
       0,     0,   101,    81,    67,     0,    69,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,   119,
       0,   124,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     362,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   157,     0,   159,     0,   173,     0,   436,
     193,   192,     0,   187,   195,    60,    61,     0,    64,     0,
      98,    80,     0,    97,     0,     0,   100,    68,   132,     0,
     134,     0,     0,   120,     0,   122,     0,   141,     0,   143,
     116,     0,   118,   129,     0,   131,     0,   153,     0,     0,
       0,   312,   315,     0,     0,   347,   346,   345,   412,   472,
       0,     0,     0,     0,     0,   364,     0,     0,     0,     0,
       0,   162,     0,   164,     0,     0,     0,   154,     0,   156,
     170,     0,   172,   191,    62,     0,    88,     0,     0,    99,
      94,     0,    96,     0,    93,     0,   133,     0,     0,     0,
     115,     0,   121,     0,     0,   142,   117,   130,   151,   152,
       0,     0,     0,   184,     0,     0,     0,   368,     0,     0,
       0,   365,     0,     0,     0,   374,     0,     0,     0,     0,
       0,   386,     0,     0,     0,   163,     0,   169,     0,     0,
       0,   177,     0,   155,   171,     0,    86,     0,    89,     0,
      95,    90,     0,    92,   138,     0,   140,   112,     0,   114,
     126,     0,   128,   150,     0,   185,   183,   314,   316,     0,
       0,     0,   370,     0,     0,   363,   367,     0,     0,     0,
     376,     0,     0,     0,     0,     0,   388,     0,   166,     0,
     168,     0,   174,     0,   176,    84,    83,     0,    87,    91,
     139,   113,   127,   182,   371,     0,     0,     0,   380,     0,
       0,     0,   377,     0,     0,     0,   392,     0,     0,     0,
     389,     0,     0,     0,   398,     0,     0,   167,     0,   181,
       0,   175,    85,     0,   369,   373,     0,     0,     0,   382,
     366,     0,   375,   379,     0,     0,     0,   394,     0,     0,
     387,   391,     0,     0,     0,   400,   178,     0,   180,     0,
     383,     0,     0,     0,   395,     0,     0,     0,   404,     0,
       0,     0,   401,     0,     0,   179,   372,     0,   381,   385,
     378,     0,   393,   397,     0,     0,     0,   406,   390,     0,
     399,   403,     0,     0,   407,     0,     0,     0,   384,   396,
       0,   405,   409,   402,     0,   408
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -906,  -906,   -94,  1366,   557,   885,    16,  -906,  -906,  -494,
    -906,  -906,  -906,  -906,  -906,  -906,  -905,  -906,  -906,   -34,
     461,  -906,   -80,  -906,   -10,  -207,  -906,   478,   -98,  -906,
    -281,  -906,   165,   167,   179,   109,  -906,     3,  -906,  -906,
    -906,   -12,  -906,   509,  -906,  -906,  -906,  -906,  -906,  -462,
    -906,  -906,  -906,  -906,  -906,  -906,  -906,   -13,  -459,  -906,
    -906,  -301,  -906,   247,  -906,  -906,  -906,  -906,  -906,  1053
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   115,   116,   392,   393,   394,   395,   120,   121,   551,
     122,   123,   124,   125,   126,   127,   801,   128,   129,   212,
     130,   131,   310,   311,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   420,   303,   304,   169,   305,   170,   171,   172,   180
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     179,   186,   217,   184,   383,   188,   189,   190,   191,   192,
     193,     9,   314,   198,   181,   181,   119,   489,     9,     9,
     205,   209,     9,   323,   213,   325,   228,   219,     9,   334,
       9,   225,   227,   319,     9,   230,     9,     9,     9,   238,
     239,   240,   241,     9,   514,     9,   984,   495,   496,   497,
       9,   500,   502,   678,  1091,     9,     9,     9,   685,   362,
     735,  1029,     2,     3,     4,     5,     6,     7,     8,     9,
     373,   830,   484,   486,   544,   197,   670,   -49,   362,   671,
     364,   487,   484,   583,   232,   194,   174,   490,   291,   292,
     293,   294,   339,   340,   195,   299,   302,   538,   652,   313,
     359,   856,   362,   181,   181,   181,   181,   362,   351,   202,
     836,   837,   210,   407,   368,   838,   535,   371,   -49,   582,
     589,   484,   211,  1083,   583,   590,   347,   594,   348,   222,
     -49,   -49,   595,   119,   194,   119,   315,   568,   405,   985,
     231,   308,   316,   195,   242,   736,   367,  1092,  1094,   322,
     309,   317,   480,   223,   317,   229,   831,   114,   536,   631,
     317,   539,   318,  1099,   114,   114,   317,   374,   114,   317,
    1105,   335,   336,   834,   114,   365,   114,   317,   858,   649,
     114,   272,   114,   114,   114,   771,   274,   317,   647,   114,
     119,   114,   185,   378,  -262,  -275,   114,   381,   408,   571,
     382,   114,   114,   114,   397,   111,   112,   760,   403,   -49,
     761,   -49,   409,   233,   -49,   114,   411,   655,   656,   360,
     657,   413,   569,   406,   205,   209,   397,   363,   481,   494,
     492,   328,   417,   418,   419,   421,   422,   423,   424,   425,
     426,  1095,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   344,   442,  1100,   243,   445,  1153,
     447,   448,   449,  1106,   450,  1158,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   470,   872,   291,   292,   293,   294,  1161,   329,   330,
     537,  1166,   540,  -262,  -275,  1169,   478,   244,   181,   181,
     181,   181,  1174,   341,   342,  1197,   722,  1201,   419,  1206,
    1209,   491,   321,   347,  -275,   348,  -275,  1220,   324,   597,
     638,   639,   606,   470,   598,   245,   566,   607,   470,   644,
     915,   987,   337,   338,   484,   419,   516,   518,   520,   246,
     119,   521,   522,   523,   524,   525,   526,   527,   528,   658,
     531,   326,  1154,   345,   583,   331,   332,   333,  1159,   247,
     695,   798,   799,   668,   561,   419,   471,   472,   484,   306,
     349,   350,   307,   346,   397,   940,   474,   397,   475,   946,
    1162,  -328,  -328,  -328,  1167,   327,   673,   676,  1170,   343,
     397,   484,   583,   361,   751,  1175,  -328,   572,  1198,   484,
    1202,   206,  1207,  1210,   677,   550,   650,   640,   576,   472,
    1221,   567,   641,   471,   472,   916,   988,   352,   353,   354,
     355,   356,   357,   358,   806,   815,   902,   903,   904,   807,
     816,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
     476,   819,   477,   823,   972,   800,   583,  1009,   824,   973,
     509,   510,   511,   978,   627,   628,   629,   630,   583,   994,
     549,   550,   633,   634,   995,   635,   248,   637,   249,   181,
     181,   181,   181,   645,   651,   483,   473,  -210,   653,   484,
    -458,  -210,   684,   550,   770,   550,   784,   785,   871,   550,
     351,   204,   208,   181,   945,   550,  1008,   550,   798,   799,
     503,   504,   250,  -328,   505,   506,  -328,  -328,   251,   661,
    -328,  -328,  -328,  -328,  -328,   252,   683,  -328,   507,   508,
     182,   183,   688,   905,   253,   254,   255,   256,   692,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   181,   269,   270,   271,   276,   277,   278,   279,   280,
     281,   362,   282,   283,   284,   285,   286,   117,   696,   287,
     288,   289,   290,   366,   398,   370,   307,   301,   372,   375,
     708,   709,   427,   710,   711,   712,   713,   440,   443,   399,
     714,   412,   414,   715,   479,   716,   717,   416,   718,   719,
     444,   446,   215,   720,   721,   473,   556,   419,   723,   724,
     487,   485,   727,   471,   728,   498,   534,   729,   545,   546,
     730,   731,   732,   733,   552,   554,   555,   557,   559,   562,
    -454,   565,   574,   579,   575,   577,   580,   610,   689,   578,
     611,   743,   581,   584,   585,   586,   587,   588,   591,   592,
     593,   704,   600,   706,   601,   596,   599,   602,   605,   737,
     603,   604,   753,   642,   608,   782,   609,   613,   612,   299,
     614,   615,   616,   617,   377,   618,   619,   691,   380,   620,
     397,   624,   621,   622,   117,   396,   117,   623,   625,   626,
     654,   739,   643,   659,   662,   675,   707,   666,   667,   397,
     672,   793,   397,   660,   797,   663,   674,   396,   679,   686,
     693,   701,   705,   746,   750,   747,   749,   754,   759,   752,
     765,   787,   774,   788,   808,   781,   783,   786,   792,   796,
     913,   802,   636,   804,   805,   832,   810,   981,   811,   812,
     397,   117,   809,   813,   847,   814,   848,   817,   818,   820,
     821,   822,   825,     0,   827,   828,   829,   839,   826,   842,
     843,   844,   852,  1054,   851,   857,   853,   397,   864,   859,
     862,   868,   873,   876,   877,   397,   887,   974,   397,   385,
     891,   895,   896,   898,   401,   925,   881,   929,   884,   930,
     933,   934,   935,   938,   941,   947,   950,   951,   894,   952,
     955,   956,   959,   962,   965,  1102,   993,   899,   900,   901,
     966,   968,   971,   975,   493,   976,   977,   979,   980,   996,
       0,   999,  1002,  1003,   419,  1012,   906,     0,  1004,  1016,
     907,  1022,  1025,  1026,  1027,  1033,  1041,  1042,   921,  1066,
       0,  1055,  1063,  1064,  1073,  1070,  -328,  -328,  -328,  1076,
    1079,  1082,  1085,  1086,     0,   396,  1087,  1088,   396,  1093,
    1096,  -328,  1101,  1110,  1111,   397,  1114,  1124,  1118,   939,
     550,   396,  1115,  1178,  1119,  1120,  1121,  1122,   397,  1123,
    1125,  1132,   397,  1133,  1140,   397,  1141,     0,   397,  1147,
    1151,   117,   397,  1152,  1155,   118,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  1160,  1163,  1168,  1171,   982,
    1180,   397,  1181,   986,  1184,   989,  1185,   397,  1192,  1193,
    1195,  1196,   397,  1199,  1200,  1203,   397,  1208,  1211,  1214,
     216,  1218,  1219,  1215,  1222,  1223,  1225,     0,     0,     0,
       0,     0,   397,   237,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -328,   397,
       0,  -328,  -328,  1034,  1035,  -328,  -328,  -328,  -328,  -328,
       0,  1040,  -328,     0,  1043,     0,     0,  1048,     0,     0,
       0,     0,     0,     0,     0,  1059,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   397,     0,     0,     0,     0,
       0,     0,   118,   397,   118,     0,     0,   397,     0,   397,
       0,     0,     0,   397,     0,     0,     0,     0,     0,     0,
     397,     0,     0,     0,     0,     0,  1089,     0,   397,     0,
       0,     0,     0,     0,  1097,     0,   397,     0,     0,     0,
    1103,     0,   397,     0,  1107,     0,   397,     0,     0,     0,
     397,     0,     0,   173,     0,     0,     0,   397,     0,   118,
       0,     0,     0,     0,     0,     0,     0,   187,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   199,     0,   200,
     201,  1126,     0,     0,  1131,     0,     0,     0,     0,  1134,
     220,   221,  1139,   224,     0,  1142,     0,   386,   388,     0,
       0,     0,   402,     0,     0,     0,   681,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1156,     0,   397,
       0,     0,     0,     0,     0,  1164,     0,   397,     0,     0,
       0,     0,     0,  1172,     0,   397,   273,   275,   397,     0,
       0,   396,     0,  1179,     0,     0,     0,     0,  1182,     0,
       0,  1183,     0,     0,     0,     0,  1186,     0,     0,  1191,
     396,   312,     0,   396,  1194,     0,   320,     0,     0,     0,
     173,     0,   173,     0,     0,     0,     0,  1204,     0,   397,
       0,     0,     0,     0,     0,     0,     0,  1212,     0,     0,
       0,  1213,     0,     0,     0,     0,  1216,   741,     0,  1217,
       0,   396,     0,     0,     0,     0,     0,     0,     0,   118,
    1224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   396,     0,
       0,   320,     0,     0,   768,     0,   396,     0,     0,   396,
     776,   779,     0,     0,     0,     0,     0,   320,   369,     0,
     320,     0,     0,     0,     0,   376,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,   173,     0,     0,
       0,   404,     0,     0,     0,     0,   410,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   396,   866,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   396,
       0,     0,     0,   396,     0,     0,   396,     0,     0,   396,
     889,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,   320,   482,     0,     0,     0,     0,     0,     0,     0,
     488,     0,   396,     0,     0,     0,     0,   173,   396,     0,
       0,     0,     0,   396,     0,     0,     0,   396,     0,     0,
       0,     0,     0,   918,     0,     0,   923,   512,     0,     0,
     927,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,     0,   529,     0,   532,   533,     0,     0,     0,     0,
       0,     0,     0,   320,     0,   320,   541,   173,   943,     0,
     396,     0,     0,     0,   682,     0,     0,   173,     0,     0,
     173,     0,     0,     0,     0,     0,   173,     0,   173,     0,
       0,     0,     0,   173,     0,   700,     0,   703,   570,     0,
       0,   573,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,   396,     0,     0,     0,   396,     0,
     396,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,   396,     0,     0,     0,     0,  1006,     0,     0,   396,
       0,     0,  1014,     0,     0,     0,     0,   396,     0,  1020,
       0,     0,     0,   396,     0,     0,     0,   396,     0,     0,
       0,   396,     0,   632,     0,   742,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,   646,   648,   320,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1057,     0,  1061,     0,     0,     0,     0,     0,     0,
       0,     0,   769,     0,     0,  1068,     0,     0,   777,   780,
       0,     0,     0,  -328,  -328,  -328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,  -328,     0,
     396,     0,     0,     0,     0,     0,     0,     0,   396,     0,
       0,     0,   415,     0,     0,     0,   396,     0,   173,   396,
       0,     0,   173,     0,     0,     0,     0,     0,     0,   694,
       0,     0,   697,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     396,     0,     0,     0,     0,   867,     0,     0,     0,     0,
       0,     0,     0,   725,   726,     0,     0,     0,  1149,   879,
       0,     0,   883,     0,   886,     0,     0,     0,   890,     0,
       0,     0,   893,     0,   734,     0,     0,     0,     0,     0,
       0,   738,     0,     0,     0,  -328,   173,     0,  -328,  -328,
     748,     0,  -328,  -328,  -328,  -328,  -328,     0,     0,  -328,
       0,     0,     0,     0,     0,     0,     0,   912,     0,   173,
     173,   919,   762,     0,   924,   173,     0,   173,   928,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
     542,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     548,   789,   173,   553,     0,   173,   944,     0,     0,   558,
     803,   560,     0,     0,     0,     0,   564,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   970,     0,     0,     0,     0,     0,   833,
     835,     0,     0,   173,     0,     0,     0,     0,     0,   173,
     187,     0,   187,   173,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,   173,     0,
     173,     0,     0,     0,  1007,     0,     0,     0,   173,     0,
    1015,   173,     0,     0,     0,     0,  1018,  1021,   880,     0,
       0,  1024,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1031,     0,   897,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1039,     0,     0,     0,     0,
       0,  1047,     0,     0,  1053,     0,     0,     0,     0,  1058,
       0,  1062,     0,     0,   908,     0,     0,   914,     0,     0,
     920,     0,     0,  1069,     0,     0,     0,     0,     0,     0,
     665,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,   687,     0,     0,     0,   690,     0,     0,     0,     0,
       0,   173,     0,     0,     0,   173,     0,     0,   173,     0,
       0,   173,     0,     0,     0,   173,     0,     0,   173,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,     0,     0,     0,     0,   990,
     173,     0,     0,     0,     0,   173,     0,     0,  1130,   173,
       0,     0,     0,     0,     0,     0,  1138,     0,     0,     0,
       0,     0,  1146,     0,     0,   173,  1150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   745,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   756,   758,     0,     0,     0,     0,   764,     0,
     766,  1049,     0,     0,     0,     0,   773,     0,     0,     0,
       0,     0,     0,  1190,     0,     0,     0,     0,   173,     0,
       0,     0,     0,     0,     0,   791,   173,     0,   795,     0,
     173,     0,   173,     0,     0,     0,   173,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,     0,     0,     0,   173,   841,     0,     0,   173,
       0,     0,   846,   173,     0,     0,   850,     0,     0,     0,
     173,     0,     0,     0,     0,   855,     0,     0,     0,     0,
       0,   861,     0,   863,     0,     0,     0,     0,     0,     0,
       0,   870,     0,     0,   875,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   932,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   937,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,   949,     0,     0,     0,   954,     0,
       0,   958,     0,     0,   961,     0,     0,     0,   964,     0,
       0,   967,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   983,     0,     0,
       0,     0,     0,   992,     0,     0,     0,     0,   998,     0,
       0,     0,  1001,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1011,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1028,     0,     0,  1032,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1065,     0,     0,     0,     0,     0,     0,     0,  1072,
       0,     0,     0,  1075,     0,  1078,     0,     0,     0,  1081,
       0,     0,     0,     0,     0,     0,  1084,     0,     0,     0,
       0,     0,     0,     0,  1090,     0,     0,     0,     0,     0,
       0,     0,  1098,     0,     0,     0,     0,     0,  1104,     0,
       0,     0,  1109,     0,     0,     0,  1113,     0,     0,     0,
       0,     0,     0,  1117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1157,     0,     0,     0,     0,
       0,     0,     0,  1165,     0,     0,     0,     0,     0,     0,
       0,  1173,    -3,     1,  1177,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,  1205,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,   106,     0,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,    -6,     1,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,   106,     0,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
      -8,     1,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,   106,     0,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,   -14,   -14,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,   -14,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,   389,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,   -16,   -16,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     390,   105,     0,     0,   106,   -16,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,   798,   799,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,     0,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,   389,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   390,   105,
       0,     0,   106,   391,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,   389,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   390,   105,     0,     0,   106,   300,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,   547,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,   389,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     390,   105,     0,     0,   106,   563,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,   664,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,   389,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   390,   105,
       0,     0,   106,   744,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,   389,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   390,   105,     0,     0,   106,   755,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,   757,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,   389,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     390,   105,     0,     0,   106,   763,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,   772,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,   389,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   390,   105,
       0,     0,   106,   790,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,   389,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   390,   105,     0,     0,   106,   794,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,   840,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,   389,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     390,   105,     0,     0,   106,   845,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,   849,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,   389,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   390,   105,
       0,     0,   106,   854,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,   389,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   390,   105,     0,     0,   106,   860,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,   869,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,   389,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     390,   105,     0,     0,   106,   874,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,   931,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,   389,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   390,   105,
       0,     0,   106,   936,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,   389,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   390,   105,     0,     0,   106,   948,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,   953,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,   389,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     390,   105,     0,     0,   106,   957,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,   960,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,   389,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   390,   105,
       0,     0,   106,   963,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,   389,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   390,   105,     0,     0,   106,   991,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,   997,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,   389,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     390,   105,     0,     0,   106,  1000,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,  1010,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,   389,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   390,   105,
       0,     0,   106,  1071,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,   389,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   390,   105,     0,     0,   106,  1074,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,  1077,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,   389,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     390,   105,     0,     0,   106,  1080,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,  1108,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,   389,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   390,   105,
       0,     0,   106,  1112,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,   389,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   390,   105,     0,     0,   106,  1116,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,   389,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   390,   105,     0,     0,
     106,  1176,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     1,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,   106,     0,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,   389,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   390,   105,     0,     0,   106,     0,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
       0,     0,   214,     0,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   105,     0,     0,   384,     0,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   105,     0,     0,
     400,     0,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   105,     0,     0,   680,     0,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   105,     0,     0,   740,     0,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
       0,     0,   767,     0,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   105,     0,     0,   775,     0,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   105,     0,     0,
     778,     0,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   105,     0,     0,   865,     0,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   105,     0,     0,   888,     0,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
       0,     0,   917,     0,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   105,     0,     0,   922,     0,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   105,     0,     0,
     926,     0,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   105,     0,     0,   942,     0,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   105,     0,     0,  1005,     0,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
       0,     0,  1013,     0,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,     0,    37,
       0,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   105,     0,     0,  1019,     0,   107,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,     0,    37,     0,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   105,     0,     0,
    1056,     0,   107,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,    14,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,    38,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   105,     0,     0,  1060,     0,   107,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
       0,    37,     0,    38,    39,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   105,     0,     0,  1067,     0,
     107,     0,   108,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,     0,    37,     0,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
       0,     0,  1148,     0,   107,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,   175,    22,    23,
       0,    25,     0,    27,     0,    28,    29,   234,   235,     0,
      32,   909,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,    40,    41,    42,     0,    44,
      45,    46,     0,     0,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   105,   910,     0,   911,     0,   177,     0,
     178,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,    23,     0,    25,     0,    27,     0,    28,
      29,   234,   235,     0,    32,  1036,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,    40,
      41,    42,     0,    44,    45,    46,     0,     0,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   105,  1037,     0,
    1038,     0,   177,     0,   178,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,   175,    22,    23,     0,    25,
       0,    27,     0,    28,    29,   234,   235,     0,    32,  1044,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,    40,    41,    42,     0,    44,    45,    46,
       0,     0,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   105,  1045,     0,  1046,     0,   177,     0,   178,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,    23,     0,    25,     0,    27,     0,    28,    29,   234,
     235,     0,    32,  1050,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,    40,    41,    42,
       0,    44,    45,    46,     0,     0,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   105,  1051,     0,  1052,     0,
     177,     0,   178,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,   175,    22,    23,     0,    25,     0,    27,
       0,    28,    29,   234,   235,     0,    32,  1127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,    41,    42,     0,    44,    45,    46,     0,     0,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
    1128,     0,  1129,     0,   177,     0,   178,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,   175,    22,    23,
       0,    25,     0,    27,     0,    28,    29,   234,   235,     0,
      32,  1135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,    40,    41,    42,     0,    44,
      45,    46,     0,     0,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   105,  1136,     0,  1137,     0,   177,     0,
     178,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,    23,     0,    25,     0,    27,     0,    28,
      29,   234,   235,     0,    32,  1143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,    40,
      41,    42,     0,    44,    45,    46,     0,     0,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   105,  1144,     0,
    1145,     0,   177,     0,   178,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,   175,    22,    23,     0,    25,
       0,    27,     0,    28,    29,   234,   235,     0,    32,  1187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,    40,    41,    42,     0,    44,    45,    46,
       0,     0,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   105,  1188,     0,  1189,     0,   177,     0,   178,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,    23,     0,    25,     0,    27,     0,    28,    29,   234,
     235,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,    40,    41,    42,
       0,    44,    45,    46,     0,     0,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   105,     0,   698,   699,     0,
     177,     0,   178,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,   175,    22,    23,     0,    25,     0,    27,
       0,    28,    29,   234,   235,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,    41,    42,     0,    44,    45,    46,     0,     0,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
       0,     0,   236,     0,   177,     0,   178,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,   175,    22,    23,
       0,    25,     0,    27,     0,    28,    29,   234,   235,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,    40,    41,    42,     0,    44,
      45,    46,     0,     0,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   105,     0,     0,   387,     0,   177,     0,
     178,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,    23,     0,    25,     0,    27,     0,    28,
      29,   234,   235,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,    40,
      41,    42,     0,    44,    45,    46,     0,     0,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   105,     0,     0,
     702,     0,   177,     0,   178,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,   175,    22,    23,     0,    25,
       0,    27,     0,    28,    29,   234,   235,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,    40,    41,    42,     0,    44,    45,    46,
       0,     0,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   105,     0,     0,   878,     0,   177,     0,   178,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,    23,     0,    25,     0,    27,     0,    28,    29,   234,
     235,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,    40,    41,    42,
       0,    44,    45,    46,     0,     0,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   105,     0,     0,   882,     0,
     177,     0,   178,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,   175,    22,    23,     0,    25,     0,    27,
       0,    28,    29,   234,   235,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,    41,    42,     0,    44,    45,    46,     0,     0,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
       0,     0,   885,     0,   177,     0,   178,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,    13,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,   175,    22,    23,
       0,    25,     0,    27,     0,    28,    29,   234,   235,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,    40,    41,    42,     0,    44,
      45,    46,     0,     0,     0,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   105,     0,     0,   892,     0,   177,     0,
     178,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
      13,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,    23,     0,    25,     0,    27,     0,    28,
      29,   234,   235,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,    40,
      41,    42,     0,    44,    45,    46,     0,     0,     0,    49,
      50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   105,     0,     0,
     969,     0,   177,     0,   178,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,     0,    13,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,   175,    22,    23,     0,    25,
       0,    27,     0,    28,    29,   234,   235,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,    40,    41,    42,     0,    44,    45,    46,
       0,     0,     0,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   105,     0,     0,  1017,     0,   177,     0,   178,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,    13,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,    23,     0,    25,     0,    27,     0,    28,    29,   234,
     235,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,    40,    41,    42,
       0,    44,    45,    46,     0,     0,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   105,     0,     0,  1023,     0,
     177,     0,   178,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,    13,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,   175,    22,    23,     0,    25,     0,    27,
       0,    28,    29,   234,   235,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,    41,    42,     0,    44,    45,    46,     0,     0,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   105,
       0,     0,  1030,     0,   177,     0,   178,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    11,    12,   206,     0,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      24,    25,     0,    27,     0,    28,    29,   207,   176,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,   100,   101,
     102,   103,     0,   105,     0,     0,   106,     0,   177,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    11,    12,     0,
       0,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    24,    25,     0,    27,     0,    28,
      29,     0,   176,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,   100,   101,   102,   103,     0,   105,     0,     0,
     106,   300,   177,     0,   108,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    11,    12,   206,     0,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    24,    25,
       0,    27,     0,    28,    29,     0,   176,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    45,    46,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,   100,   101,   102,   103,
       0,   105,     0,     0,   106,     0,   177,     0,   108,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,    11,    12,   206,     0,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,     0,     0,    25,     0,    27,     0,    28,    29,   207,
     176,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
     100,   101,   102,   103,     0,   105,     0,     0,   106,     0,
     177,     0,   178,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    11,
      12,     0,     0,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,     0,    24,    25,     0,    27,
       0,    28,    29,     0,   203,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   100,   101,   102,   103,     0,   105,
       0,     0,   106,     0,   177,     0,   108,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    11,    12,     0,     0,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      24,    25,     0,    27,     0,    28,    29,     0,   176,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,   100,   101,
     102,   103,     0,   105,     0,     0,   106,     0,   177,     0,
     108,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    11,    12,     0,
       0,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,     0,     0,    25,     0,    27,     0,    28,
      29,     0,   176,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,   100,   101,   102,   103,     0,   105,   441,     0,
     106,     0,   177,     0,   178,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    11,    12,     0,     0,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,   175,    22,     0,     0,    25,
       0,    27,     0,    28,    29,     0,   176,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    45,    46,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,   100,   101,   102,   103,
       0,   105,   513,     0,   106,     0,   177,     0,   178,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,    11,    12,     0,     0,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,     0,     0,    25,     0,    27,     0,    28,    29,     0,
     176,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
     100,   101,   102,   103,     0,   105,     0,     0,   106,     0,
     177,     0,   178,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,   515,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    11,
      12,     0,     0,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,   175,    22,     0,     0,    25,     0,    27,
       0,    28,    29,     0,   176,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   100,   101,   102,   103,     0,   105,
       0,     0,   106,     0,   177,     0,   178,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
     517,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    11,    12,     0,     0,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,   175,    22,     0,
       0,    25,     0,    27,     0,    28,    29,     0,   176,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,   100,   101,
     102,   103,     0,   105,     0,   519,   106,     0,   177,     0,
     178,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    11,    12,     0,
       0,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,     0,     0,    25,     0,    27,     0,    28,
      29,     0,   176,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,   100,   101,   102,   103,     0,   105,     0,     0,
     106,     0,   177,     0,   178,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,   530,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    11,    12,     0,     0,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,   175,    22,     0,     0,    25,
       0,    27,     0,    28,    29,     0,   176,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    45,    46,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,   100,   101,   102,   103,
       0,   105,   543,     0,   106,     0,   177,     0,   178,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,    11,    12,     0,     0,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,     0,     0,    25,     0,    27,     0,    28,    29,     0,
     176,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
     100,   101,   102,   103,     0,   105,     0,     0,   106,     0,
     177,     0,   178,     0,   109,   110,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    11,
      12,     0,     0,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,   175,    22,     0,     0,    25,     0,    27,
       0,    28,    29,     0,   176,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   100,   101,   102,   103,     0,   218,
       0,     0,   106,     0,   177,     0,   178,     0,   109,   110,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    11,    12,     0,     0,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,   175,    22,     0,
       0,    25,     0,    27,     0,    28,    29,     0,   176,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,   100,   101,
     102,   103,     0,   226,     0,     0,   106,     0,   177,     0,
     178,     0,   109,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    11,    12,     0,
       0,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,     0,     0,    25,     0,    27,     0,    28,
      29,     0,   176,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,   295,   296,   297,   298,     0,   105,     0,     0,
     106,     0,   177,     0,   178,     0,   109,   110,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    11,    12,     0,     0,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,   175,    22,     0,     0,    25,
       0,    27,     0,    28,    29,     0,   203,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    45,    46,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,   100,   101,   102,   103,
       0,   105,     0,     0,   106,     0,   177,     0,   178,     0,
     109,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,    11,    12,     0,     0,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,     0,     0,    25,     0,    27,     0,    28,    29,     0,
     176,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
     100,   101,   102,   103,     0,   105,     0,     0,   106,     0,
     177,     0,   178,   499,   109,     0,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    11,
      12,     0,     0,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,   175,    22,     0,     0,    25,     0,    27,
       0,    28,    29,     0,   176,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   100,   101,   102,   103,     0,   105,
       0,     0,   106,     0,   177,     0,   178,   501,   109,     0,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    11,    12,     0,     0,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,   175,    22,     0,
       0,    25,     0,    27,     0,    28,    29,     0,   176,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,   100,   101,
     102,   103,     0,   105,     0,     0,   106,     0,   177,     0,
     178,     0,   109,     0,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    11,    12,     0,
       0,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,     0,     0,    25,     0,    27,     0,    28,
      29,     0,   176,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,   100,   101,   102,   103,     0,   105,   466,     0,
     106,     0,   177,     0,   178,     0,   109,     0,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    11,    12,     0,     0,     0,    15,     0,     0,     0,
      16,    17,    18,    19,    20,   175,    22,     0,     0,    25,
       0,    27,     0,    28,    29,     0,   176,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    45,    46,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,   100,   101,   102,   103,
       0,   105,   467,     0,   106,     0,   177,     0,   178,     0,
     109,     0,     0,     0,   111,   112,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,    11,    12,     0,     0,     0,
      15,     0,     0,     0,    16,    17,    18,    19,    20,   175,
      22,     0,     0,    25,     0,    27,     0,    28,    29,     0,
     176,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
     100,   101,   102,   103,     0,   105,   468,     0,   106,     0,
     177,     0,   178,     0,   109,     0,     0,     0,   111,   112,
       0,     0,     0,     0,     0,   113,     0,     0,   114,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    11,
      12,     0,     0,     0,    15,     0,     0,     0,    16,    17,
      18,    19,    20,   175,    22,     0,     0,    25,     0,    27,
       0,    28,    29,     0,   176,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   100,   101,   102,   103,     0,   105,
     469,     0,   106,     0,   177,     0,   178,     0,   109,     0,
       0,     0,   111,   112,     0,     0,     0,     0,     0,   113,
       0,     0,   114,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    11,    12,     0,     0,     0,    15,     0,
       0,     0,    16,    17,    18,    19,    20,   175,    22,     0,
       0,    25,     0,    27,     0,    28,    29,     0,   176,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,   100,   101,
     102,   103,     0,   105,     0,     0,   106,     0,   177,     0,
     178,     0,   109,     0,     0,     0,   111,   112,     0,     0,
       0,     0,     0,   113,     0,     0,   114,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    11,    12,     0,
       0,     0,    15,     0,     0,     0,    16,    17,    18,    19,
      20,   175,    22,     0,     0,    25,     0,    27,     0,    28,
      29,     0,   176,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,   100,   101,   102,   103,     0,   669,     0,     0,
     106,     0,   177,     0,   178,     0,   109,     0,     0,     0,
     111,   112,     0,     0,     0,     0,     0,   113,     0,     0,
     114
};

static const yytype_int16 yycheck[] =
{
      10,    14,    36,    13,   211,    15,    16,    17,    18,    19,
      20,    10,   110,    23,    11,    12,     0,   318,    10,    10,
      30,    31,    10,   117,    34,   119,     3,    37,    10,     4,
      10,    41,    42,   113,    10,    45,    10,    10,    10,    49,
      50,    51,    52,    10,   345,    10,    41,   328,   329,   330,
      10,   332,   333,   547,    41,    10,    10,    10,   552,    15,
      50,   966,     3,     4,     5,     6,     7,     8,     9,    10,
      39,    50,   139,   133,   375,   153,   538,     0,    15,   538,
     174,   141,   139,   139,     3,   133,   132,   154,   100,   101,
     102,   103,   150,   151,   142,   105,   106,   154,   154,   109,
      34,   134,    15,   100,   101,   102,   103,    15,   141,    15,
     134,   135,   133,    50,   194,   139,   134,   197,    41,   134,
     134,   139,   133,  1028,   139,   139,   153,   134,   155,   133,
      53,    54,   139,   117,   133,   119,     3,    50,    47,   134,
     133,   133,     3,   142,   133,   135,   134,   134,    41,     0,
     142,   142,   134,   133,   142,   132,   135,   156,   134,   133,
     142,   134,   153,    41,   156,   156,   142,   136,   156,   142,
      41,   146,   147,   133,   156,   185,   156,   142,   134,   134,
     156,   153,   156,   156,   156,   679,   153,   142,   142,   156,
     174,   156,   133,   203,    34,    34,   156,   207,   135,   406,
     210,   156,   156,   156,   214,   146,   147,   669,   218,   132,
     669,   134,   222,   132,   137,   156,   226,   498,   499,   153,
     501,   231,   135,   132,   234,   235,   236,   135,   308,   327,
     324,    19,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   134,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    34,   265,   134,   133,   268,    41,
     270,   271,   272,   134,   274,    41,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,    49,   776,   295,   296,   297,   298,    41,    76,    77,
     370,    41,   372,   133,   133,    41,   306,   133,   295,   296,
     297,   298,    41,    66,    67,    41,   607,    41,   318,    41,
      41,   321,   136,   153,   153,   155,   155,    41,   132,   134,
      47,    48,   134,    49,   139,   133,    47,   139,    49,   134,
      50,    50,   148,   149,   139,   345,   346,   347,   348,   133,
     324,   351,   352,   353,   354,   355,   356,   357,   358,   134,
     360,    21,   134,   133,   139,   143,   144,   145,   134,   133,
     567,    53,    54,   134,   398,   375,   134,   135,   139,   133,
      13,    14,   136,   153,   384,   869,   137,   387,   139,   873,
     134,    19,    20,    21,   134,    20,   134,   134,   134,   152,
     400,   139,   139,    15,   134,   134,    34,   407,   134,   139,
     134,    15,   134,   134,    42,    43,   486,   134,   134,   135,
     134,   132,   139,   134,   135,   135,   135,    69,    70,    71,
      72,    73,    74,    75,   134,   134,    95,    96,    97,   139,
     139,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     137,   134,   139,   134,   134,   137,   139,   941,   139,   139,
     341,   342,   343,   134,   466,   467,   468,   469,   139,   134,
      42,    43,   472,   473,   139,   475,   133,   477,   133,   466,
     467,   468,   469,   483,   487,   135,   135,   135,   490,   139,
     139,   139,    42,    43,    42,    43,   134,   135,    42,    43,
     141,    30,    31,   490,    42,    43,    42,    43,    53,    54,
     335,   336,   133,   141,   337,   338,   144,   145,   133,   519,
     148,   149,   150,   151,   152,   133,   550,   155,   339,   340,
      11,    12,   556,   824,   133,   133,   133,   133,   562,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   538,   133,   133,   133,   133,   133,   133,   133,   133,
     133,    15,   133,   133,   133,   133,   133,     0,   568,   133,
     133,   133,   133,   132,    46,   133,   136,   106,   133,   133,
     580,   581,   134,   583,   584,   585,   586,   134,   134,   132,
     590,   132,   132,   593,     3,   595,   596,   132,   598,   599,
     134,   134,    35,   603,   604,   135,    46,   607,   608,   609,
     141,   139,   612,   134,   614,   141,   136,   617,   134,   134,
     620,   621,   622,   623,   132,   132,   132,   137,   132,    46,
     139,   132,   134,    64,   134,   134,   139,   154,    46,   137,
     154,   641,   139,   139,   139,   139,   134,   134,   134,   134,
     139,    50,   134,    64,   134,   139,   139,   134,   134,    49,
     139,   139,   662,   137,   139,   689,   139,   134,   139,   669,
     139,   134,   134,   139,   203,   134,   134,   132,   207,   139,
     680,   134,   139,   139,   117,   214,   119,   139,   134,   134,
     137,     3,   136,   154,   135,   137,   133,   136,   136,   699,
     136,   701,   702,   154,   704,   154,   136,   236,   137,   137,
     137,   132,   136,   136,   136,   141,   141,   137,   136,   154,
     136,   134,   132,    50,   139,   132,   132,   132,   132,   132,
      50,   133,   475,   134,   134,   735,   134,    50,   134,   134,
     740,   174,   139,   134,   747,   134,   749,   134,   134,   134,
     134,   134,   134,    -1,   134,   134,   134,   134,   139,   132,
     134,   137,   137,    50,   136,   134,   137,   767,   132,   137,
     137,   137,   132,   132,   132,   775,   137,   139,   778,   212,
     137,   135,   137,   134,   217,   137,   786,   137,   788,   137,
     137,   137,   137,   132,   137,   137,   132,   134,   798,   134,
     132,   134,   132,   132,   132,    50,   132,   807,   808,   809,
     135,   134,   134,   134,   326,   134,   134,   134,   134,   134,
      -1,   132,   132,   137,   824,   132,   826,    -1,   137,   137,
     830,   137,   137,   137,   137,   132,   134,   137,   838,   132,
      -1,   137,   137,   137,   132,   137,    19,    20,    21,   132,
     132,   132,   132,   137,    -1,   384,   134,   134,   387,   134,
     134,    34,   134,   132,   134,   865,   132,   134,   132,    42,
      43,   400,   137,   132,   137,   137,   137,   137,   878,   137,
     137,   134,   882,   137,   134,   885,   137,    -1,   888,   137,
     137,   324,   892,   137,   134,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   134,   134,   134,   134,   909,
     134,   911,   137,   913,   134,   915,   137,   917,   134,   137,
     137,   134,   922,   134,   134,   134,   926,   134,   134,   134,
      35,   134,   134,   137,   134,   134,   134,    -1,    -1,    -1,
      -1,    -1,   942,    48,    -1,    -1,   475,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   969,
      -1,   144,   145,   973,   974,   148,   149,   150,   151,   152,
      -1,   981,   155,    -1,   984,    -1,    -1,   987,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   995,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1005,    -1,    -1,    -1,    -1,
      -1,    -1,   117,  1013,   119,    -1,    -1,  1017,    -1,  1019,
      -1,    -1,    -1,  1023,    -1,    -1,    -1,    -1,    -1,    -1,
    1030,    -1,    -1,    -1,    -1,    -1,  1036,    -1,  1038,    -1,
      -1,    -1,    -1,    -1,  1044,    -1,  1046,    -1,    -1,    -1,
    1050,    -1,  1052,    -1,  1054,    -1,  1056,    -1,    -1,    -1,
    1060,    -1,    -1,     0,    -1,    -1,    -1,  1067,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    -1,    26,
      27,  1091,    -1,    -1,  1094,    -1,    -1,    -1,    -1,  1099,
      37,    38,  1102,    40,    -1,  1105,    -1,   212,   213,    -1,
      -1,    -1,   217,    -1,    -1,    -1,   549,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1127,    -1,  1129,
      -1,    -1,    -1,    -1,    -1,  1135,    -1,  1137,    -1,    -1,
      -1,    -1,    -1,  1143,    -1,  1145,    83,    84,  1148,    -1,
      -1,   680,    -1,  1153,    -1,    -1,    -1,    -1,  1158,    -1,
      -1,  1161,    -1,    -1,    -1,    -1,  1166,    -1,    -1,  1169,
     699,   108,    -1,   702,  1174,    -1,   113,    -1,    -1,    -1,
     117,    -1,   119,    -1,    -1,    -1,    -1,  1187,    -1,  1189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1197,    -1,    -1,
      -1,  1201,    -1,    -1,    -1,    -1,  1206,   640,    -1,  1209,
      -1,   740,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
    1220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   767,    -1,
      -1,   178,    -1,    -1,   677,    -1,   775,    -1,    -1,   778,
     683,   684,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,
     197,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   865,   770,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   878,
      -1,    -1,    -1,   882,    -1,    -1,   885,    -1,    -1,   888,
     793,    -1,    -1,   892,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     317,    -1,   911,    -1,    -1,    -1,    -1,   324,   917,    -1,
      -1,    -1,    -1,   922,    -1,    -1,    -1,   926,    -1,    -1,
      -1,    -1,    -1,   836,    -1,    -1,   839,   344,    -1,    -1,
     843,    -1,    -1,   942,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   359,    -1,   361,   362,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   370,    -1,   372,   373,   374,   871,    -1,
     969,    -1,    -1,    -1,   549,    -1,    -1,   384,    -1,    -1,
     387,    -1,    -1,    -1,    -1,    -1,   393,    -1,   395,    -1,
      -1,    -1,    -1,   400,    -1,   570,    -1,   572,   405,    -1,
      -1,   408,    -1,    -1,    -1,    -1,  1005,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1013,    -1,    -1,    -1,  1017,    -1,
    1019,    -1,    -1,    -1,  1023,    -1,    -1,    -1,    -1,    -1,
      -1,  1030,    -1,    -1,    -1,    -1,   939,    -1,    -1,  1038,
      -1,    -1,   945,    -1,    -1,    -1,    -1,  1046,    -1,   952,
      -1,    -1,    -1,  1052,    -1,    -1,    -1,  1056,    -1,    -1,
      -1,  1060,    -1,   470,    -1,   640,    -1,    -1,  1067,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   484,   485,   486,
     487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   994,    -1,   996,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   677,    -1,    -1,  1008,    -1,    -1,   683,   684,
      -1,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   534,    34,    -1,
    1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1137,    -1,
      -1,    -1,   236,    -1,    -1,    -1,  1145,    -1,   555,  1148,
      -1,    -1,   559,    -1,    -1,    -1,    -1,    -1,    -1,   566,
      -1,    -1,   569,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1189,    -1,    -1,    -1,    -1,   770,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   610,   611,    -1,    -1,    -1,  1111,   784,
      -1,    -1,   787,    -1,   789,    -1,    -1,    -1,   793,    -1,
      -1,    -1,   797,    -1,   631,    -1,    -1,    -1,    -1,    -1,
      -1,   638,    -1,    -1,    -1,   141,   643,    -1,   144,   145,
     647,    -1,   148,   149,   150,   151,   152,    -1,    -1,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,    -1,   666,
     667,   836,   669,    -1,   839,   672,    -1,   674,   843,    -1,
      -1,    -1,    -1,   680,    -1,    -1,    -1,    -1,    -1,    -1,
     374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     384,   698,   699,   387,    -1,   702,   871,    -1,    -1,   393,
     707,   395,    -1,    -1,    -1,    -1,   400,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   898,    -1,    -1,    -1,    -1,    -1,   736,
     737,    -1,    -1,   740,    -1,    -1,    -1,    -1,    -1,   746,
     747,    -1,   749,   750,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   759,    -1,    -1,    -1,    -1,    -1,   765,    -1,
     767,    -1,    -1,    -1,   939,    -1,    -1,    -1,   775,    -1,
     945,   778,    -1,    -1,    -1,    -1,   951,   952,   785,    -1,
      -1,   956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   968,    -1,   802,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   980,    -1,    -1,    -1,    -1,
      -1,   986,    -1,    -1,   989,    -1,    -1,    -1,    -1,   994,
      -1,   996,    -1,    -1,   831,    -1,    -1,   834,    -1,    -1,
     837,    -1,    -1,  1008,    -1,    -1,    -1,    -1,    -1,    -1,
     534,    -1,    -1,    -1,   851,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,    -1,
      -1,   555,    -1,    -1,    -1,   559,    -1,    -1,    -1,    -1,
      -1,   878,    -1,    -1,    -1,   882,    -1,    -1,   885,    -1,
      -1,   888,    -1,    -1,    -1,   892,    -1,    -1,   895,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   911,    -1,    -1,    -1,    -1,   916,
     917,    -1,    -1,    -1,    -1,   922,    -1,    -1,  1093,   926,
      -1,    -1,    -1,    -1,    -1,    -1,  1101,    -1,    -1,    -1,
      -1,    -1,  1107,    -1,    -1,   942,  1111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   966,
      -1,    -1,   969,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   666,   667,    -1,    -1,    -1,    -1,   672,    -1,
     674,   988,    -1,    -1,    -1,    -1,   680,    -1,    -1,    -1,
      -1,    -1,    -1,  1168,    -1,    -1,    -1,    -1,  1005,    -1,
      -1,    -1,    -1,    -1,    -1,   699,  1013,    -1,   702,    -1,
    1017,    -1,  1019,    -1,    -1,    -1,  1023,    -1,    -1,    -1,
      -1,    -1,    -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1038,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1046,
      -1,    -1,    -1,    -1,    -1,  1052,   740,    -1,    -1,  1056,
      -1,    -1,   746,  1060,    -1,    -1,   750,    -1,    -1,    -1,
    1067,    -1,    -1,    -1,    -1,   759,    -1,    -1,    -1,    -1,
      -1,   765,    -1,   767,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   775,    -1,    -1,   778,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1145,    -1,
      -1,  1148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   851,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   865,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1189,    -1,   878,    -1,    -1,    -1,   882,    -1,
      -1,   885,    -1,    -1,   888,    -1,    -1,    -1,   892,    -1,
      -1,   895,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   911,    -1,    -1,
      -1,    -1,    -1,   917,    -1,    -1,    -1,    -1,   922,    -1,
      -1,    -1,   926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   942,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   966,    -1,    -1,   969,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1005,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1013,
      -1,    -1,    -1,  1017,    -1,  1019,    -1,    -1,    -1,  1023,
      -1,    -1,    -1,    -1,    -1,    -1,  1030,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1038,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1046,    -1,    -1,    -1,    -1,    -1,  1052,    -1,
      -1,    -1,  1056,    -1,    -1,    -1,  1060,    -1,    -1,    -1,
      -1,    -1,    -1,  1067,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1145,     0,     1,  1148,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,  1189,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,     0,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
       0,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,     1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    55,    56,    57,    -1,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,
      56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    33,    -1,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    33,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
     134,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    33,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    55,    56,    57,    -1,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    33,    -1,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,
      56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    33,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    33,    -1,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,    -1,   135,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    33,
      -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    33,    -1,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    55,    56,    57,    -1,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    33,    -1,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,
      56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    33,    -1,    35,    36,    37,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    33,    -1,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    33,
      -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    33,    -1,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    55,    56,    57,    -1,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    33,    -1,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,
      56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    33,    -1,    35,    36,    37,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    33,    -1,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    33,
      -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,    15,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    33,    -1,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    33,    -1,    35,
      36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    14,    15,    -1,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    33,
      -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,   134,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    35,    36,    -1,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    -1,    33,
      -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,   135,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    35,    36,    -1,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    -1,    33,
      -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    35,    36,    -1,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    -1,    33,
      -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,   141,   142,    -1,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,   134,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,    -1,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,   140,    -1,
     142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    35,    36,    -1,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,   140,    -1,   142,    -1,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    -1,    33,
      -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
     134,    -1,   136,    -1,   138,    -1,   140,    -1,   142,    -1,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
     136,    -1,   138,    -1,   140,    -1,   142,    -1,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     156
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    13,    14,    16,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    35,    36,
      37,    38,    40,    41,    44,    45,    46,    49,    51,    52,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    65,
      66,    67,    68,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   136,   138,   140,   142,
     143,   146,   147,   153,   156,   158,   159,   161,   162,   163,
     164,   165,   167,   168,   169,   170,   171,   172,   174,   175,
     177,   178,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
     223,   224,   225,   226,   132,    27,    38,   138,   140,   181,
     226,   194,   200,   200,   181,   133,   214,   226,   181,   181,
     181,   181,   181,   181,   133,   142,   226,   153,   181,   226,
     226,   226,    15,    38,   177,   181,    15,    37,   177,   181,
     133,   133,   176,   181,   136,   161,   162,   176,   133,   181,
     226,   226,   133,   133,   226,   181,   133,   181,     3,   132,
     181,   133,     3,   132,    37,    38,   136,   162,   181,   181,
     181,   181,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   153,   226,   153,   226,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   198,   198,   198,   198,   128,   129,   130,   131,   181,
     137,   177,   181,   219,   220,   222,   133,   136,   133,   142,
     179,   180,   226,   181,   185,     3,     3,   142,   153,   179,
     226,   136,     0,   159,   132,   159,    21,    20,    19,    76,
      77,   143,   144,   145,     4,   146,   147,   148,   149,   150,
     151,    66,    67,   152,    34,   133,   153,   153,   155,    13,
      14,   141,    69,    70,    71,    72,    73,    74,    75,    34,
     153,    15,    15,   135,   159,   181,   132,   134,   179,   226,
     133,   179,   133,    39,   136,   133,   226,   177,   181,   226,
     177,   181,   181,   182,   136,   161,   162,   136,   162,     1,
     132,   137,   160,   161,   162,   163,   177,   181,    46,   132,
     136,   161,   162,   181,   226,    47,   132,    50,   135,   181,
     226,   181,   132,   181,   132,   160,   132,   181,   181,   181,
     218,   181,   181,   181,   181,   181,   181,   134,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     134,   134,   181,   134,   134,   181,   134,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   134,   134,   134,   134,
      49,   134,   135,   135,   137,   139,   137,   139,   181,     3,
     134,   179,   226,   135,   139,   139,   133,   141,   226,   218,
     154,   181,   159,   184,   185,   187,   187,   187,   141,   141,
     187,   141,   187,   189,   189,   190,   190,   191,   191,   192,
     192,   192,   226,   134,   218,   154,   181,   154,   181,   135,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   226,
     154,   181,   226,   226,   136,   134,   134,   179,   154,   134,
     179,   226,   160,   134,   218,   134,   134,   137,   160,    42,
      43,   166,   132,   160,   132,   132,    46,   137,   160,   132,
     160,   176,    46,   137,   160,   132,    47,   132,    50,   135,
     226,   182,   181,   226,   134,   134,   134,   134,   137,    64,
     139,   139,   134,   139,   139,   139,   139,   134,   134,   134,
     139,   134,   134,   139,   134,   139,   139,   134,   139,   139,
     134,   134,   134,   139,   139,   134,   134,   139,   139,   139,
     154,   154,   139,   134,   139,   134,   134,   139,   134,   134,
     139,   139,   139,   139,   134,   134,   134,   198,   198,   198,
     198,   133,   226,   181,   181,   181,   220,   181,    47,    48,
     134,   139,   137,   136,   134,   181,   226,   142,   226,   134,
     179,   214,   154,   198,   137,   187,   187,   187,   134,   154,
     154,   181,   135,   154,   137,   160,   136,   136,   134,   133,
     206,   215,   136,   134,   136,   137,   134,    42,   166,   137,
     136,   161,   162,   176,    42,   166,   137,   160,   176,    46,
     160,   132,   176,   137,   226,   182,   181,   226,   135,   136,
     162,   132,   136,   162,    50,   136,    64,   133,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   218,   181,   181,   226,   226,   181,   181,   181,
     181,   181,   181,   181,   226,    50,   135,    49,   226,     3,
     136,   161,   162,   181,   137,   160,   136,   141,   226,   141,
     136,   134,   154,   181,   137,   137,   160,   137,   160,   136,
     206,   215,   226,   137,   160,   136,   160,   136,   161,   162,
      42,   166,   137,   160,   132,   136,   161,   162,   136,   161,
     162,   132,   176,   132,   134,   135,   132,   134,    50,   226,
     137,   160,   132,   181,   137,   160,   132,   181,    53,    54,
     137,   173,   133,   226,   134,   134,   134,   139,   139,   139,
     134,   134,   134,   134,   134,   134,   139,   134,   134,   134,
     134,   134,   134,   134,   139,   134,   139,   134,   134,   134,
      50,   135,   181,   226,   133,   226,   134,   135,   139,   134,
     137,   160,   132,   134,   137,   137,   160,   214,   214,   137,
     160,   136,   137,   137,   137,   160,   134,   134,   134,   137,
     137,   160,   137,   160,   132,   136,   161,   162,   137,   137,
     160,    42,   166,   132,   137,   160,   132,   132,   136,   162,
     226,   181,   136,   162,   181,   136,   162,   137,   136,   161,
     162,   137,   136,   162,   181,   135,   137,   226,   134,   181,
     181,   181,    95,    96,    97,   218,   181,   181,   226,    41,
     134,   136,   162,    50,   226,    50,   135,   136,   161,   162,
     226,   181,   136,   161,   162,   137,   136,   161,   162,   137,
     137,   137,   160,   137,   137,   137,   137,   160,   132,    42,
     166,   137,   136,   161,   162,    42,   166,   137,   137,   160,
     132,   134,   134,   137,   160,   132,   134,   137,   160,   132,
     137,   160,   132,   137,   160,   132,   135,   160,   134,   136,
     162,   134,   134,   139,   139,   134,   134,   134,   134,   134,
     134,    50,   181,   160,    41,   134,   181,    50,   135,   181,
     226,   137,   160,   132,   134,   139,   134,   137,   160,   132,
     137,   160,   132,   137,   137,   136,   161,   162,    42,   166,
     137,   160,   132,   136,   161,   162,   137,   136,   162,   136,
     161,   162,   137,   136,   162,   137,   137,   137,   160,   173,
     136,   162,   160,   132,   181,   181,    41,   134,   136,   162,
     181,   134,   137,   181,    41,   134,   136,   162,   181,   226,
      41,   134,   136,   162,    50,   137,   136,   161,   162,   181,
     136,   161,   162,   137,   137,   160,   132,   136,   161,   162,
     137,   137,   160,   132,   137,   160,   132,   137,   160,   132,
     137,   160,   132,   173,   160,   132,   137,   134,   134,   181,
     160,    41,   134,   134,    41,   134,   134,   181,   160,    41,
     134,   134,    50,   181,   160,    41,   134,   181,   137,   160,
     132,   134,   137,   160,   132,   137,   137,   160,   132,   137,
     137,   137,   137,   137,   134,   137,   181,    41,   134,   136,
     162,   181,   134,   137,   181,    41,   134,   136,   162,   181,
     134,   137,   181,    41,   134,   136,   162,   137,   136,   161,
     162,   137,   137,    41,   134,   134,   181,   160,    41,   134,
     134,    41,   134,   134,   181,   160,    41,   134,   134,    41,
     134,   134,   181,   160,    41,   134,   137,   160,   132,   181,
     134,   137,   181,   181,   134,   137,   181,    41,   134,   136,
     162,   181,   134,   137,   181,   137,   134,    41,   134,   134,
     134,    41,   134,   134,   181,   160,    41,   134,   134,    41,
     134,   134,   181,   181,   134,   137,   181,   181,   134,   134,
      41,   134,   134,   134,   181,   134
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   157,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   160,   160,   160,   160,   160,   160,   160,   160,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   163,   164,   164,   164,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   167,   167,   168,   168,   168,   168,   169,   169,
     169,   169,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   171,   171,   171,   171,   172,   172,
     173,   173,   173,   173,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   175,   175,   175,   175,   176,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   178,
     178,   178,   178,   179,   179,   179,   179,   180,   180,   180,
     180,   181,   182,   183,   183,   184,   184,   185,   185,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   187,   188,
     188,   188,   188,   189,   189,   189,   190,   190,   190,   191,
     192,   192,   192,   192,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   194,   194,   194,   195,   196,   196,   196,
     196,   197,   197,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   199,   199,   199,
     199,   199,   200,   200,   200,   200,   200,   200,   200,   200,
     201,   201,   201,   201,   201,   201,   201,   201,   202,   202,
     202,   202,   202,   202,   202,   203,   203,   203,   203,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   205,
     205,   205,   205,   205,   205,   205,   206,   206,   206,   206,
     206,   207,   207,   207,   207,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   210,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     212,   212,   212,   212,   213,   213,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   215,   215,   215,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   217,   217,   217,   217,   217,   217,   218,   218,   218,
     219,   219,   219,   220,   220,   221,   221,   222,   222,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   225,
     225,   225,   225,   226,   226
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     2,     1,     1,     2,     2,
       3,     1,     3,     2,     1,     1,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     1,     4,     4,
       2,     2,     3,     3,     3,     3,     2,     4,     2,     4,
       1,     2,     2,     1,     1,     3,     4,     5,     4,     3,
       8,     8,     9,     7,     8,     6,     7,     7,     8,     7,
       6,     6,     7,     6,     5,     5,     6,     5,     4,     4,
       5,     4,     3,     8,     8,     9,     7,     8,     6,     7,
       7,     8,     7,     6,     6,     7,     6,     5,     5,     6,
       5,     4,     5,     4,     4,     5,     4,     3,     6,     7,
       6,     5,    10,    11,    10,     9,     8,     9,     8,     7,
       8,     9,     8,     6,     7,     6,    10,    11,    10,     8,
       9,     8,     8,     9,     8,     6,     7,     6,    10,    11,
      10,     8,     9,     8,     2,     3,     2,     3,     6,     7,
       5,     4,     4,     3,     8,     9,     8,     7,     6,     7,
       6,     5,     8,     9,     8,     7,    10,    11,    10,     9,
       8,     9,     8,     7,    10,    11,    10,     9,    12,    13,
      12,    11,    11,    10,     9,    10,     3,     8,     7,     7,
       6,     8,     7,     7,     6,     8,     7,     7,     6,     5,
       7,     2,     2,     5,     5,     3,     1,     3,     4,     1,
       2,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       4,     3,     4,     3,     3,     3,     4,     1,     1,     3,
       3,     2,     1,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     3,     1,     2,     2,     5,     5,     1,     1,
       4,     4,     1,     4,     3,     1,     1,     5,     4,     3,
       1,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     2,     2,     2,     4,     4,     4,     4,     2,     2,
       2,     2,     2,     2,     4,     2,     2,     2,     1,     6,
       6,     4,     8,     6,    10,     8,    10,     4,     4,     4,
       2,     5,     1,     1,     1,     4,     3,     3,     2,     1,
       1,     4,     6,     3,     1,     6,     4,     6,     6,     6,
       4,     6,     4,     4,     6,     8,     8,     8,     4,     4,
       4,     3,     4,     3,     6,     6,     3,     3,     3,     6,
       4,     4,     7,    10,     8,     9,    12,    10,     9,    12,
      10,    11,    14,    12,     9,    12,    10,    11,    14,    12,
      11,    14,    12,    13,    16,    14,     9,    12,    10,    11,
      14,    12,    11,    14,    12,    13,    16,    14,    11,    14,
      12,    13,    16,    14,    13,    16,    14,    15,    18,    16,
       4,     6,     8,     6,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     3,     1,     1,     1,
       6,     7,     6,     5,     3,     6,     7,     6,     5,     3,
       4,     5,     5,     7,     7,     7,     4,     2,     3,     1,
       3,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       4,     3,     4,     4,     3,     3,     3,     1,     1,     6,
       4,     4,     8,     6,     6,     6,     4,     4,     6,     3,
       3,     3,     3,     1,     4
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
  switch (yytype)
    {
          case 10: /* ID  */
#line 83 "lshParser.y" /* yacc.c:684  */
      { fprintf (yyoutput, "%s", *((*yyvaluep).str)); }
#line 5580 "lshParser.c" /* yacc.c:684  */
        break;


      default:
        break;
    }
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
        case 2:
#line 90 "lshParser.y" /* yacc.c:1646  */
    { 
         #if JSON==1
          if (interpreter::get()->json){
            interpreter::jsonInit();
            interpreter::get()->steps_count = 1;
            interpreter::to_json((yyvsp[0].data)->json);
         }
         #endif
         (yyvsp[0].data)->run(); 
         #if JSON==1
         if (interpreter::get()->json){
            interpreter::jsonEnd();
         }
         #endif
      }
#line 6220 "lshParser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 105 "lshParser.y" /* yacc.c:1646  */
    { ;}
#line 6226 "lshParser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new stmtNode ((yyvsp[-2].data), (yyvsp[0].data), (yylsp[-2]), true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 6241 "lshParser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new stmtNode ((yyvsp[-1].data), (yyvsp[0].data), (yylsp[-1]), true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-1].data),(yyvsp[0].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 6256 "lshParser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "lshParser.y" /* yacc.c:1646  */
    {    
         runNode * r = new stmtNode ((yyvsp[0].data), NULL, (yylsp[0]), true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data),};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;
      }
#line 6271 "lshParser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 139 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new stmtNode ((yyvsp[0].data), NULL, (yylsp[0]), true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data),};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;
      }
#line 6286 "lshParser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 149 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-1]), true);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;
      }
#line 6301 "lshParser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new labelNode ((yyvsp[-1].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-1].data),(yyvsp[0].data)};
            r->toJson ("labelNode", "label", a, NULL, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 6316 "lshParser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 169 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6322 "lshParser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "lshParser.y" /* yacc.c:1646  */
    { 
         (yyval.data) = new noNode ();
      }
#line 6330 "lshParser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-2].data), (yyvsp[0].data), (yylsp[-2]), false);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6345 "lshParser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 186 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), (yyvsp[0].data), (yylsp[-1]), false);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-1].data),(yyvsp[0].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6360 "lshParser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 196 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[0].data), NULL, (yylsp[0]), false);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6375 "lshParser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 206 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[0].data), NULL, (yylsp[0]), false); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6390 "lshParser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 216 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-1]), false);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6405 "lshParser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 226 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new labelNode ((yyvsp[-1].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-1].data),(yyvsp[0].data)};
            r->toJson ("labelNode", "label", a, NULL, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6420 "lshParser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 236 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6426 "lshParser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 237 "lshParser.y" /* yacc.c:1646  */
    {(yyval.data) = new noNode ();}
#line 6432 "lshParser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 242 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6438 "lshParser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 243 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 6444 "lshParser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 244 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 6450 "lshParser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 245 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6456 "lshParser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 246 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6462 "lshParser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 247 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6468 "lshParser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 248 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6474 "lshParser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 249 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6480 "lshParser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 250 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6486 "lshParser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 251 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6492 "lshParser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 255 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6498 "lshParser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 256 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new printNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("printNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6513 "lshParser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 266 "lshParser.y" /* yacc.c:1646  */
    {       
         runNode * r =  new printNode ((yyvsp[0].data), true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("printNode", "stmt", a, NULL, 1);
         }
         #endif
            (yyval.data) = r;
      }
#line 6528 "lshParser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 276 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new printNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("printNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6543 "lshParser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 286 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new gotoNode ((yyvsp[0].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)};
            r->toJson ("gotoNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6558 "lshParser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 296 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new includeNode ( (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("includeNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6573 "lshParser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 306 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new returnNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("returnNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6588 "lshParser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 316 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new returnNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("returnNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6602 "lshParser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 325 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new sleepNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("sleepNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6617 "lshParser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 335 "lshParser.y" /* yacc.c:1646  */
    { 
         loadNode * r =new loadNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("loadNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;  
      }
#line 6632 "lshParser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 345 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new staticNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("staticNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6647 "lshParser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 355 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new privateNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("privateNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6662 "lshParser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 365 "lshParser.y" /* yacc.c:1646  */
    {                   
         runNode *r = new staticNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("staticNode", "class", a, NULL, 1);
         }
         #endif
         runNode *d = new privateNode (r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("privateNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = d; 
      }
#line 6684 "lshParser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 382 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new staticNode ((yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("staticNode", "class", a, NULL, 1);
         }
         #endif
         runNode *d = new privateNode (r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("privateNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = d; 
      }
#line 6706 "lshParser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 399 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new staticNode ((yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("staticNode", "class", a, NULL, 1);
         }
         #endif
         runNode *d = new privateNode (r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("privateNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = d; 
      }
#line 6728 "lshParser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 416 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new staticNode ((yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("staticNode", "class", a, NULL, 1);
         }
         #endif
         runNode *d = new privateNode (r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("privateNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = d; 
      }
#line 6750 "lshParser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 433 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new typeofNode ((yyvsp[0].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)};
            r->toJson ("typeofNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6765 "lshParser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 443 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new typeofNode ((yyvsp[-1].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].idnode)};
            r->toJson ("typeofNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6780 "lshParser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 453 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new datInfoNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("datInfoNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6795 "lshParser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 463 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new datInfoNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("datInfoNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6810 "lshParser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 473 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new exitNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("exitNode", "stmt", NULL,0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6824 "lshParser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 482 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new throwNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("throwNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6839 "lshParser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 495 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].idnode); }
#line 6845 "lshParser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 499 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6851 "lshParser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 500 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6857 "lshParser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 502 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new globalNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("globalNode", "stmt", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;  
      }
#line 6872 "lshParser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 515 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new ifNode ((yyvsp[-2].data),new noNode (),0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-2].data)};
            string b[1] = {"cond"};
            r->toJson ("ifNode", "stmt", a, b, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6888 "lshParser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 526 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-3].data),(yyvsp[-1].data),0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data),(yyvsp[-1].data)};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6904 "lshParser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 537 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data),NULL,(yylsp[-3])); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ((yyvsp[-2].data),r,0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),r};
            string b[2] = {"cond","ifb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d; 
      }
#line 6927 "lshParser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 555 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-1].data), (yyvsp[0].data), 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-1].data),(yyvsp[0].data)};
            string b[2] = {"cond","ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6943 "lshParser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 566 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-6].data), new noNode (), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-6].data),(yyvsp[-1].data)};
            string b[2] = {"cond","elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6959 "lshParser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 577 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-6].data), (yyvsp[-4].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-6].data),(yyvsp[-4].data)};
            string b[2] = {"cond","ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6975 "lshParser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 588 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-1].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6991 "lshParser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 599 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-6])); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ((yyvsp[-5].data), new noNode (), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), r};
            string b[2] = {"cond", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d; 
      }
#line 7014 "lshParser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 617 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-7])); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ((yyvsp[-6].data), (yyvsp[-4].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].data), (yyvsp[-4].data), r};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d; 
      }
#line 7037 "lshParser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 635 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new ifNode ((yyvsp[-4].data), new noNode (), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data),(yyvsp[0].data)};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7053 "lshParser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 646 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new ifNode ((yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7069 "lshParser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 657 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-4].data), NULL, (yylsp[-6])); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ((yyvsp[-5].data), r, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), r};
            string b[2] = {"cond", "ifb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d; 
      }
#line 7092 "lshParser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 675 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-5].data), NULL, (yylsp[-7])); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-5].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ((yyvsp[-6].data), r, (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].data), r, (yyvsp[-1].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d; 
      }
#line 7115 "lshParser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 693 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-4].data), NULL, (yylsp[-6])); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * m =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-6])); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            m->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ((yyvsp[-5].data), r, m);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), r, m};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d; 
      }
#line 7145 "lshParser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 718 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-3].data), NULL, (yylsp[-5])); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-3].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ((yyvsp[-4].data), r, (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), r, (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d;
      }
#line 7168 "lshParser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 736 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-4].data), (yyvsp[-3].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data),(yyvsp[-3].data)};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 7184 "lshParser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 747 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-5].data), (yyvsp[-4].data),(yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7200 "lshParser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 758 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-5]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ((yyvsp[-4].data), (yyvsp[-3].data),r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), (yyvsp[-3].data), r};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;
      }
#line 7223 "lshParser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 776 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-3].data), (yyvsp[-2].data),(yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-3].data), (yyvsp[-2].data), (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7239 "lshParser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 787 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-3].data),new noNode (), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[0].data)};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7255 "lshParser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 798 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new ifNode ((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7271 "lshParser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 809 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-2].data), NULL, (yylsp[-4]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] =  {(yyvsp[-2].data)};
            string b[1] =  {"cond"};
            r->toJson ("stmtNode", "stmt", a, b, 1);
         }
         #endif
         runNode * d =new ifNode ((yyvsp[-3].data), r,(yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-3].data), r, (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;
      }
#line 7295 "lshParser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 828 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-2].data), (yyvsp[-1].data),(yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-2].data), (yyvsp[-1].data), (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7311 "lshParser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 842 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-2].data), new noNode (), 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-2].data)};
            string b[1] = {"cond"};
            r->toJson ("ifNode", "stmt", a, b, 1);
         }
         #endif
         (yyval.data) = r;
      }
#line 7327 "lshParser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 853 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-3].data),(yyvsp[-1].data), 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7343 "lshParser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 864 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-3]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ((yyvsp[-2].data), r, 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"cond", "ifb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d;
      }
#line 7366 "lshParser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 882 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r=new ifNode ((yyvsp[-1].data), (yyvsp[0].data), 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-1].data), (yyvsp[0].data)};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;  
      }
#line 7382 "lshParser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 893 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r=new ifNode ((yyvsp[-6].data), (yyvsp[-4].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-6].data), (yyvsp[-4].data)};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;  
      }
#line 7398 "lshParser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 904 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r=new ifNode ((yyvsp[-6].data), new noNode (), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-6].data), (yyvsp[-1].data)};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;  
      }
#line 7414 "lshParser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 915 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new ifNode ((yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-1].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7430 "lshParser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 926 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-6]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d=new ifNode ((yyvsp[-5].data), new noNode (), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), r};
            string b[2] = {"cond", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d;  
      }
#line 7453 "lshParser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 944 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-7]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d=new ifNode ((yyvsp[-6].data), (yyvsp[-4].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].data), (yyvsp[-4].data), r};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;  
      }
#line 7476 "lshParser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 962 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-4].data), new noNode (), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[0].data)};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7492 "lshParser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 973 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;     
      }
#line 7508 "lshParser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 984 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-4].data), NULL, (yylsp[-6]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ((yyvsp[-5].data), r, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), r};
            string b[2] = {"cond", "ifb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d;     
      }
#line 7531 "lshParser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1002 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-5].data), NULL, (yylsp[-7]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-5].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ((yyvsp[-6].data), r, (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].data), r, (yyvsp[-1].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;     
      }
#line 7554 "lshParser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1020 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-4].data), NULL, (yylsp[-6]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
          runNode * d =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-6]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            d->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * m =new ifNode ((yyvsp[-5].data), r, d);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), r, d};
            string b[3] = {"cond", "ifb", "elseb"};
            m->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = m; 
      }
#line 7584 "lshParser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1045 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-3].data), NULL, (yylsp[-5]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-3].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ((yyvsp[-4].data), r, (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), r, (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;  
      }
#line 7607 "lshParser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1063 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-4].data), (yyvsp[-3].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-3].data)};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7623 "lshParser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1074 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-5].data), (yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7639 "lshParser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1085 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-5]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ((yyvsp[-4].data), (yyvsp[-3].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), (yyvsp[-3].data), r};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;  
      }
#line 7662 "lshParser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1103 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new ifNode ((yyvsp[-3].data), (yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-3].data), (yyvsp[-2].data), (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7678 "lshParser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1114 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new ifNode ((yyvsp[-3].data), new noNode (), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[0].data)};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7694 "lshParser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1125 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new ifNode ((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7710 "lshParser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1136 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-2].data), NULL, (yylsp[-4]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-2].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ((yyvsp[-3].data), r,(yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-3].data), r, (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;  
      }
#line 7733 "lshParser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1154 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new ifNode ((yyvsp[-2].data), (yyvsp[-1].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-2].data), (yyvsp[-1].data), (yyvsp[0].data)};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7749 "lshParser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1168 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new withNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"obj", "stmts"};
            r->toJson ("withNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7765 "lshParser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1179 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-3]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new withNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"obj", "stmts"};
            d->toJson ("withNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d;  
      }
#line 7788 "lshParser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1200 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new whileNode ((yyvsp[-2].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-2].data)};
            string b[1] = {"cond"};
            r->toJson ("whileNode", "stmt", a, b, 1);
         }
         #endif
         (yyval.data) = r;
      }
#line 7804 "lshParser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1211 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new whileNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"cond", "stmts"};
            r->toJson ("whileNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7820 "lshParser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1222 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-3]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new whileNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"cond", "stmts"};
            d->toJson ("whileNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d;  
      }
#line 7843 "lshParser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1240 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new whileNode ((yyvsp[-1].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-1].data), (yyvsp[0].data)};
            string b[2] = {"cond", "stmts"};
            r->toJson ("whileNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7859 "lshParser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1254 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new dowhileNode ((yyvsp[-1].data),new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            string b[1] = {"cond"};
            r->toJson ("dowhileNode", "stmt", a, b, 1);
         }
         #endif
         (yyval.data) = r;
      }
#line 7875 "lshParser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1265 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new dowhileNode ((yyvsp[-1].data), (yyvsp[-4].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].data)};
            string b[2] = {"stmts", "cond"};
            r->toJson ("dowhileNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7891 "lshParser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1276 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-4].data), NULL, (yylsp[-5]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new dowhileNode ((yyvsp[-1].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r, (yyvsp[-1].data)};
            string b[2] = {"stmts", "cond"};
            d->toJson ("dowhileNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d;     
      }
#line 7914 "lshParser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1294 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new dowhileNode ((yyvsp[-1].data), (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"stmts", "cond"};
            r->toJson ("dowhileNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 7930 "lshParser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1308 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new forNode ((yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].data)};
            string b[3] = {"asig", "cond", "inc"};
            r->toJson ("forNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 7946 "lshParser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1319 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new forNode ((yyvsp[-8].data), (yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-8].data), (yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            r->toJson ("forNode", "stmt", a, NULL, 4);
         }
         #endif
         (yyval.data) = r;
      }
#line 7962 "lshParser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1330 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-9]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new forNode ((yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].data), r};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            d->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = d;
      }
#line 7985 "lshParser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1348 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new forNode ((yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data)};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            r->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;
      }
#line 8001 "lshParser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1359 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new forNode ((yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-2].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-2].data)};
            string b[3] = {"asig", "cond", "inc"};
            r->toJson ("forNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 8017 "lshParser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1370 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new forNode ((yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            r->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8033 "lshParser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1381 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-7]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new forNode ((yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-2].data), r};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            d->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = d;     
      }
#line 8056 "lshParser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1399 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new forNode ((yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[0].data)};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            r->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8072 "lshParser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1410 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-5].idnode), (yyvsp[-3].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].idnode), (yyvsp[-3].data)};
            string b[2] = {"val", "elems"};
            r->toJson ("foreachNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8088 "lshParser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1421 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 8104 "lshParser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1432 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 8120 "lshParser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1443 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-4].idnode), (yyvsp[-2].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].idnode), (yyvsp[-2].data)};
            string b[2] = {"val", "elems"};
            r->toJson ("foreachNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 8136 "lshParser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1454 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 8152 "lshParser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1465 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data)};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 8168 "lshParser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1476 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new foreachNode ((yyvsp[-5].idnode), (yyvsp[-3].data), new noNode (), (yyvsp[-7].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-7].idnode)};
            string b[3] = {"val", "elems", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 8184 "lshParser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1487 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data), (yyvsp[-8].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data), (yyvsp[-8].idnode)};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;
      }
#line 8200 "lshParser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1498 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[-7].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[-7].idnode)};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;
      }
#line 8216 "lshParser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1509 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-4].idnode), (yyvsp[-2].data), new noNode (), (yyvsp[-6].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-6].idnode)};
            string b[3] = {"val", "elems", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8232 "lshParser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1520 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new foreachNode ((yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[-7].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[-7].idnode)};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;    
      }
#line 8248 "lshParser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1531 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data), (yyvsp[-6].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data), (yyvsp[-6].idnode)};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;      
      }
#line 8264 "lshParser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1542 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-3].idnode), (yyvsp[-5].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].idnode), (yyvsp[-5].data)};
            string b[2] = {"val", "elems"};
            r->toJson ("foreachNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8280 "lshParser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1553 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-4].idnode), (yyvsp[-6].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].idnode), (yyvsp[-6].data), (yyvsp[-1].data)};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8296 "lshParser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1564 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-3].idnode), (yyvsp[-5].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-3].idnode), (yyvsp[-5].data), (yyvsp[-1].data)};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8312 "lshParser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1575 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-2].idnode), (yyvsp[-4].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].idnode), (yyvsp[-4].data)};
            string b[2] = {"val", "elems"};
            r->toJson ("foreachNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8328 "lshParser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1586 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-3].idnode), (yyvsp[-5].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-3].idnode), (yyvsp[-5].data), (yyvsp[-1].data)};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8344 "lshParser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1597 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-2].idnode), (yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-2].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;
      }
#line 8360 "lshParser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1608 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-3].idnode), (yyvsp[-7].data), new noNode (), (yyvsp[-5].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-3].idnode), (yyvsp[-7].data), (yyvsp[-5].idnode)};
            string b[3] = {"val", "elems", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8376 "lshParser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1619 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-4].idnode), (yyvsp[-8].data), (yyvsp[-1].data), (yyvsp[-6].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-4].idnode), (yyvsp[-8].data), (yyvsp[-1].data), (yyvsp[-6].idnode)};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8392 "lshParser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1630 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-3].idnode), (yyvsp[-7].data), (yyvsp[-1].data), (yyvsp[-5].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-3].idnode), (yyvsp[-7].data), (yyvsp[-1].data), (yyvsp[-5].idnode)};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8408 "lshParser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1641 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-2].idnode), (yyvsp[-6].data), new noNode (), (yyvsp[-4].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-2].idnode), (yyvsp[-6].data), (yyvsp[-4].idnode)};
            string b[3] = {"val", "elems", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8424 "lshParser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1652 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-3].idnode), (yyvsp[-7].data), (yyvsp[-1].data), (yyvsp[-5].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-3].idnode), (yyvsp[-7].data), (yyvsp[-1].data), (yyvsp[-5].idnode)};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8440 "lshParser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1663 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new foreachNode ((yyvsp[-2].idnode), (yyvsp[-6].data), (yyvsp[-1].data), (yyvsp[-4].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-2].idnode), (yyvsp[-6].data), (yyvsp[-1].data), (yyvsp[-4].idnode)};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, NULL, 4);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8456 "lshParser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1677 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new breakNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("breakNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8470 "lshParser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1686 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new breakNode (*(yyvsp[-1].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("breakNode", "stmt", NULL, NULL, 0, *(yyvsp[-1].fval));
         }
         #endif
         (yyval.data) = r;     
      }
#line 8484 "lshParser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1695 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new continueNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("continueNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8498 "lshParser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1704 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new continueNode (*(yyvsp[-1].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("continueNode", "stmt", NULL, NULL, 0, *(yyvsp[-1].fval));
         }
         #endif
         (yyval.data) = r;
      }
#line 8512 "lshParser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1716 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new switchNode ((yyvsp[-3].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-3].data)};
            string b[1] = {"eval"};
            r->toJson ("switchNode", "stmt", a, b, 1);
         }
         #endif
         (yyval.data) = r;      
      }
#line 8528 "lshParser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1727 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new switchNode ((yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].data)};
            string b[2] = {"eval", "case"};
            r->toJson ("switchNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r; 
      }
#line 8544 "lshParser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1741 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new caseNode ((yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[0].data)};
            string b[3] = {"exp", "stmts", "case"};
            r->toJson ("caseNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;      
      }
#line 8560 "lshParser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1752 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new caseNode ((yyvsp[-2].data), (yyvsp[0].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"exp", "stmts"};
            r->toJson ("caseNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 8576 "lshParser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1763 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new caseNode ((yyvsp[-2].data), NULL, (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"exp", "case"};
            r->toJson ("caseNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 8592 "lshParser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1774 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new caseNode (NULL, (yyvsp[0].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            string b[1] = {"stmts"};
            r->toJson ("caseNode", "stmt", a, b, 1);
         }
         #endif
         (yyval.data) = r;      
      }
#line 8608 "lshParser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1788 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new numConstNode(*(yyvsp[-3].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0,*(yyvsp[-3].fval));
         }
         #endif
         runNode * d =new incloopNode ((yyvsp[-5].data), r, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data),r};
            string b[2] = {"val", "max"};
            d->toJson ("incloopNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d; 
      }
#line 8630 "lshParser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1805 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new numConstNode(*(yyvsp[-4].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0,*(yyvsp[-4].fval));
         }
         #endif
         runNode * d =new incloopNode ((yyvsp[-6].data), r, (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].data), r, (yyvsp[-1].data)};
            string b[3] = {"val", "max", "stmts"};
            d->toJson ("incloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d; 
      }
#line 8652 "lshParser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1822 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * d =new numConstNode (*(yyvsp[-3].fval));
         #if JSON==1
         if (interpreter::get()->json){
            d->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[-3].fval));
         }
         #endif
         
         runNode * r =new stmtNode((yyvsp[-1].data), NULL, (yylsp[-7]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         
         runNode * m =new incloopNode ((yyvsp[-5].data), d, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), d, r};
            string b[3] = {"val", "max", "stmts"};
            m->toJson ("incloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = m;     
      }
#line 8683 "lshParser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1848 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new numConstNode(*(yyvsp[-2].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0,*(yyvsp[-2].fval));
         }
         #endif
         runNode * d =new incloopNode ((yyvsp[-4].data), r, (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), r, (yyvsp[0].data)};
            string b[3] = {"val", "max", "stmts"};
            d->toJson ("incloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;    
      }
#line 8705 "lshParser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1865 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-3].data), new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-3].data)};
            string b[1] = {"elems"};
            r->toJson ("iloopNode", "stmt", a, b, 1);
         }
         #endif
         (yyval.data) = r;       
      }
#line 8721 "lshParser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1876 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].data)};
            string b[2] = {"elems", "stmts"};
            r->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 8737 "lshParser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1887 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode((yyvsp[-1].data), NULL, (yylsp[-5]));
         #if JSON==1
         if (interpreter::get()->json){
         runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ((yyvsp[-3].data),r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data),r};
            string b[2] = {"elems", "stmts"};
            d->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = d;       
      }
#line 8760 "lshParser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1905 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"elems", "stmts"};
            r->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;          
      }
#line 8776 "lshParser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1916 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new iloopNode ((yyvsp[-5].data),new noNode (), (yyvsp[-3].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), (yyvsp[-3].idnode)};
            string b[2] = {"elems", "id"};
            r->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;          
      }
#line 8792 "lshParser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1927 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-6].data), (yyvsp[-1].data), (yyvsp[-4].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].data), (yyvsp[-1].data), (yyvsp[-4].idnode)};
            string b[3] = {"elems", "stmts", "id"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;          
      }
#line 8808 "lshParser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1938 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-7]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ((yyvsp[-5].data), r, (yyvsp[-3].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), r, (yyvsp[-3].idnode)};
            string b[3] = {"elems", "stmts", "id"};
            d->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;
      }
#line 8831 "lshParser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1956 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-4].data), (yyvsp[0].data), (yyvsp[-2].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), (yyvsp[0].data), (yyvsp[-2].idnode)};
            string b[3] = {"elems", "stmts", "id"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;          
      }
#line 8847 "lshParser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1967 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-7].data), new noNode (), (yyvsp[-3].idnode), (yyvsp[-5].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-7].data), (yyvsp[-3].idnode), (yyvsp[-5].idnode)};
            string b[3] = {"elems", "id", "key"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;          
      }
#line 8863 "lshParser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1978 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-8].data), (yyvsp[-1].data), (yyvsp[-4].idnode), (yyvsp[-6].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-8].data), (yyvsp[-1].data), (yyvsp[-4].idnode), (yyvsp[-6].idnode)};
            string b[4] = {"elems", "stmts", "id", "key"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;          
      }
#line 8879 "lshParser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1989 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-9]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ((yyvsp[-7].data), r, (yyvsp[-3].idnode), (yyvsp[-5].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), r, (yyvsp[-3].idnode), (yyvsp[-5].idnode)};
            string b[4] = {"elems", "stmts", "id", "key"};
            d->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = d;                  
      }
#line 8902 "lshParser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2007 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-6].data), (yyvsp[0].data), (yyvsp[-2].idnode), (yyvsp[-4].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-6].data), (yyvsp[0].data), (yyvsp[-2].idnode), (yyvsp[-4].idnode)};
            string b[4] = {"elems", "stmts", "id", "key"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 8918 "lshParser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2018 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-5].data), new noNode (), NULL, NULL, (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), (yyvsp[-3].data)};
            string b[2] = {"elems", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 8934 "lshParser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2029 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-6].data), (yyvsp[-1].data), NULL, NULL, (yyvsp[-4].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].data), (yyvsp[-1].data), (yyvsp[-4].data)};
            string b[3] = {"elems", "stmts", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 8950 "lshParser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 2040 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-7]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ((yyvsp[-5].data), r, NULL, NULL, (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), r, (yyvsp[-3].data)};
            string b[3] = {"elems", "stmts", "inc"};
            d->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;                  
      }
#line 8973 "lshParser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 2058 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-4].data), (yyvsp[0].data), NULL, NULL, (yyvsp[-2].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), (yyvsp[0].data), (yyvsp[-2].data)};
            string b[3] = {"elems", "stmts", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 8989 "lshParser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 2069 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-7].data), new noNode (), (yyvsp[-5].idnode), NULL, (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-7].data), (yyvsp[-5].idnode), (yyvsp[-3].data)};
            string b[3] = {"elems", "id", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 9005 "lshParser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 2080 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-8].data), (yyvsp[-1].data), (yyvsp[-6].idnode), NULL, (yyvsp[-4].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-8].data), (yyvsp[-1].data), (yyvsp[-6].idnode), (yyvsp[-4].data)};
            string b[4] = {"elems", "stmts", "id", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 9021 "lshParser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 2091 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-9]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 4);
         }
         #endif
         runNode * d =new iloopNode ((yyvsp[-7].data), r, (yyvsp[-5].idnode), NULL, (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), r, (yyvsp[-5].idnode), (yyvsp[-3].data)};
            string b[4] = {"elems", "stmts", "id", "inc"};
            d->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = d;                  
      }
#line 9044 "lshParser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 2109 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-6].data), (yyvsp[0].data), (yyvsp[-4].idnode), NULL, (yyvsp[-2].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-6].data), (yyvsp[0].data), (yyvsp[-4].idnode), (yyvsp[-2].data)};
            string b[4] = {"elems", "stmts", "id", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 9060 "lshParser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 2120 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-9].data), new noNode (), (yyvsp[-5].idnode), (yyvsp[-7].idnode), (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-9].data), (yyvsp[-5].idnode), (yyvsp[-7].idnode), (yyvsp[-3].data)};
            string b[4] = {"elems", "id", "key","inc"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 9076 "lshParser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 2131 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-10].data), (yyvsp[-1].data), (yyvsp[-6].idnode), (yyvsp[-8].idnode), (yyvsp[-4].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-10].data), (yyvsp[-1].data), (yyvsp[-6].idnode), (yyvsp[-8].idnode), (yyvsp[-4].data)};
            string b[5] = {"elems", "stmts", "id", "key","inc"};
            r->toJson ("iloopNode", "stmt", a, b, 5);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 9092 "lshParser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 2142 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-11]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ((yyvsp[-9].data), r, (yyvsp[-5].idnode), (yyvsp[-7].idnode), (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-9].data), r, (yyvsp[-5].idnode), (yyvsp[-7].idnode), (yyvsp[-3].data)};
            string b[5] = {"elems", "stmts", "id", "key","inc"};
            d->toJson ("iloopNode", "stmt", a, b, 5);
         }
         #endif
         (yyval.data) = d;                  
      }
#line 9115 "lshParser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 2160 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new iloopNode ((yyvsp[-8].data), (yyvsp[0].data), (yyvsp[-4].idnode), (yyvsp[-6].idnode), (yyvsp[-2].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-8].data), (yyvsp[0].data), (yyvsp[-4].idnode), (yyvsp[-6].idnode), (yyvsp[-2].data)};
            string b[5] = {"elems", "stmts", "id", "key","inc"};
            r->toJson ("iloopNode", "stmt", a, NULL, 5);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 9131 "lshParser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 2175 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new tryNode ((yyvsp[-8].data), (yyvsp[-4].idnode), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-8].data), (yyvsp[-4].idnode), (yyvsp[-1].data)};
            string b[3] = {"stmts", "exc", "catch"};
            r->toJson ("tryNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;                  
      }
#line 9147 "lshParser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 2186 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-8].data), NULL, (yylsp[-9]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-8].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new tryNode (r, (yyvsp[-4].idnode), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {r, (yyvsp[-4].idnode), (yyvsp[-1].data)};
            string b[3] = {"stmts", "exc", "catch"};
            d->toJson ("tryNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;                  
      }
#line 9170 "lshParser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 2204 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new stmtNode ((yyvsp[-7].data), NULL, (yylsp[-8]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-7].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d=new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-8]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
           d->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif   
         runNode * m =new tryNode (r, (yyvsp[-3].idnode), m);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {r, (yyvsp[-3].idnode), m};
            string b[3] = {"stmts", "exc", "catch"};
           m->toJson ("tryNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = m;    
      }
#line 9200 "lshParser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 2229 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new stmtNode ((yyvsp[-1].data), NULL, (yylsp[-9]));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new tryNode ((yyvsp[-7].data), (yyvsp[-3].idnode), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-7].data), (yyvsp[-3].idnode),r};
            string b[3] = {"stmts", "exc", "catch"};
            d->toJson ("tryNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = d;                
      }
#line 9223 "lshParser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 2250 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].data); }
#line 9229 "lshParser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 2255 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new functionNode ((yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[3] = {"id", "params", "body"};
            r->toJson ("functionNode", "function", a, b, 3);
         }
         #endif
         (yyval.data) = r;    
      }
#line 9245 "lshParser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 2266 "lshParser.y" /* yacc.c:1646  */
    { 
            runNode * r =new functionNode ((yyvsp[-5].idnode), (yyvsp[-3].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].idnode), (yyvsp[-3].data)};
            string b[2] = {"id", "params"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9261 "lshParser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 2277 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new functionNode ((yyvsp[-5].idnode), NULL, (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].idnode), (yyvsp[-1].data)};
            string b[2] = {"id", "body"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;     
      }
#line 9277 "lshParser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 2288 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new functionNode ((yyvsp[-4].idnode), NULL, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].idnode)};
            string b[1] = {"id"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;     
      }
#line 9293 "lshParser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 2299 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new functionNode ((yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[3] = {"id", "params", "body"};
            r->toJson ("functionNode", "function", a, b, 3);
         }
         #endif
         (yyval.data) = r;     
      }
#line 9309 "lshParser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 2310 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new functionNode ((yyvsp[-5].idnode), (yyvsp[-3].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].idnode), (yyvsp[-3].data)};
            string b[2] = {"id", "params"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9325 "lshParser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 2321 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new functionNode ((yyvsp[-5].idnode), NULL, (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].idnode), (yyvsp[-1].data)};
            string b[2] = {"id", "body"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9341 "lshParser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 2332 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new functionNode ((yyvsp[-4].idnode), NULL, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].idnode)};
            string b[1] = {"id"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9357 "lshParser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 2343 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * ctx = new idNode ("_f");
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-6].idnode)};
            ctx->toJson ("idNode", "symbol", a, NULL, 1,"", "_f");
         }
         #endif
         listNode * params_dec = new listNode (ctx, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {ctx};
            params_dec->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         runNode* func = new functionNode (NULL,(yyvsp[-4].data),(yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data),(yyvsp[-1].data)};
            string b[2] = {"params", "body"};
            func->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         runNode * body_dec = new returnNode (func);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {func};
            body_dec->toJson ("returnNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *r = new functionNode ((yyvsp[-6].idnode), params_dec, body_dec);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].idnode), params_dec, body_dec};
            string b[3] = {"id", "params", "body"};
            r->toJson ("returnNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;   
      }
#line 9402 "lshParser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 2383 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * ctx = new idNode ("_f");
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-5].idnode)};
            ctx->toJson ("idNode", "symbol", a, NULL, 1,"", "_f");
         }
         #endif
         listNode * params_dec = new listNode (ctx, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {ctx};
            params_dec->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         runNode* func = new functionNode (NULL,(yyvsp[-3].data),NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-3].data)};
            string b[1] = {"params",};
            func->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         runNode * body_dec = new returnNode (func);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {func};
            body_dec->toJson ("returnNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *r = new functionNode ((yyvsp[-5].idnode), params_dec, body_dec);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].idnode), params_dec, body_dec};
            string b[3] = {"id", "params", "body"};
            r->toJson ("returnNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;     
      }
#line 9447 "lshParser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 2423 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * ctx = new idNode ("_f");
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-5].idnode)};
            ctx->toJson ("idNode", "symbol", a, NULL, 1,"", "_f");
         }
         #endif
         listNode * params_dec = new listNode (ctx, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {ctx};
            params_dec->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         runNode* func = new functionNode (NULL,NULL,(yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            string b[1] = {"body",};
            func->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         runNode * body_dec = new returnNode (func);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {func};
            body_dec->toJson ("returnNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *r = new functionNode ((yyvsp[-5].idnode), params_dec, body_dec);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].idnode), params_dec, body_dec};
            string b[3] = {"id", "params", "body"};
            r->toJson ("returnNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r; 
      }
#line 9492 "lshParser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 2463 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * ctx = new idNode ("_f");
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].idnode)};
            ctx->toJson ("idNode", "symbol", a, NULL, 1,"", "_f");
         }
         #endif
         listNode * params_dec = new listNode (ctx, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {ctx};
            params_dec->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         runNode* func = new functionNode (NULL,NULL,NULL);
         #if JSON==1
         if (interpreter::get()->json){
            func->toJson ("functionNode", "function");
         }
         #endif
         runNode * body_dec = new returnNode (func);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {func};
            body_dec->toJson ("returnNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *r = new functionNode ((yyvsp[-4].idnode), params_dec, body_dec);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].idnode), params_dec, body_dec};
            string b[3] = {"id", "params", "body"};
            r->toJson ("returnNode", "stmt", a, b, 3);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9535 "lshParser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 2505 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r =new classNode ((yyvsp[-3].idnode), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].idnode), (yyvsp[-1].data)};
            string b[2] = {"id","body"};
            r->toJson ("classNode", "class", a, b, 2);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9551 "lshParser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 2516 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new classNode ((yyvsp[-5].idnode), (yyvsp[-1].data), (yyvsp[-3].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].idnode), (yyvsp[-1].data), (yyvsp[-3].idnode)};
            string b[3] = {"id","body", "extends"};
            r->toJson ("classNode", "class", a, b, 3);
         }
         #endif
         (yyval.data) = r;      
      }
#line 9567 "lshParser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 2527 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new staticNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("staticNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9582 "lshParser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 2537 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new privateNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("privateNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;       
      }
#line 9597 "lshParser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 2551 "lshParser.y" /* yacc.c:1646  */
    { 
         asigNode * r = new asigNode ((yyvsp[-2].idnode), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].idnode), (yyvsp[0].data)};
            string b[2] = {"var", "exp"};
            r->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         runNode * d =new listNode ((yyvsp[-4].data),r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), r};
            d->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         (yyval.data) = d;  
      }
#line 9620 "lshParser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 2569 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new asigNode ((yyvsp[-2].idnode), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].idnode), (yyvsp[0].data)};
            string b[2] = {"var", "exp"};
            r->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         runNode * d =new listNode ((yyvsp[-4].data),r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), r};
            d->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         (yyval.data) = d;     
      }
#line 9643 "lshParser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 2587 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new asigNode ((yyvsp[-2].idnode), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].idnode), (yyvsp[0].data)};
            string b[2] = {"var", "exp"};
            r->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         runNode * d =new listNode (r, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.data) = d;   
      }
#line 9666 "lshParser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 2605 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9672 "lshParser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 2610 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new listNode ((yyvsp[-2].data),(yyvsp[0].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].idnode)};
            r->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 9687 "lshParser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 2620 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new refparamNode ((yyvsp[0].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)};
            r->toJson ("refparamNode", "function", a, NULL, 1);
         }
         #endif
         runNode * d =new listNode ((yyvsp[-3].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), r};
            d->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         (yyval.data) = d;       
      }
#line 9709 "lshParser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 2637 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new listNode ((yyvsp[0].idnode),NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)};
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9724 "lshParser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 2647 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new refparamNode ((yyvsp[0].idnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)};
            r->toJson ("refparamNode", "function", a, NULL, 1);
         }
         #endif
         runNode * d =new listNode (r, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.data) = d;          
      }
#line 9746 "lshParser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 2668 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9752 "lshParser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 2672 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9758 "lshParser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 2676 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =  new orNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("orNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9774 "lshParser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 2687 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9780 "lshParser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 2691 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new andNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("andNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9796 "lshParser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 2702 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 9802 "lshParser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 2706 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new notNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("notNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;
      }
#line 9817 "lshParser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 2716 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 9823 "lshParser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 2720 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new lthNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("lthNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9839 "lshParser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 2731 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new leqNode ((yyvsp[-3].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("leqNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9855 "lshParser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 2742 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new gthNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("gthNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9871 "lshParser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 2753 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new geqNode ((yyvsp[-3].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("geqNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9887 "lshParser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 2764 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new eqNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("eqNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9903 "lshParser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 2775 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new idenNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("idenNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9919 "lshParser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 2786 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new nidenNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("nidenNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9935 "lshParser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 2797 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new neqNode ((yyvsp[-3].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("neqNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;
      }
#line 9951 "lshParser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 2808 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9957 "lshParser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 2813 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9963 "lshParser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 2817 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new addNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("addNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 9979 "lshParser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 2828 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new subNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("subNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 9995 "lshParser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 2839 "lshParser.y" /* yacc.c:1646  */
    {
         if ((yyvsp[0].fval) < 0){
            runNode * r = new numConstNode (*(yyvsp[0].fval));
            #if JSON==1
            if (interpreter::get()->json){
               r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
            }
            #endif
            runNode * d = new subNode ((yyvsp[-1].data), r);
            #if JSON==1
            if (interpreter::get()->json){
               runNode*a[2] = {(yyvsp[-1].data), r};
               string b[2] = {"op1", "op2"};
               d->toJson ("subNode", "operator", a, b, 2);
            }
            #endif
            (yyval.data) = d;  
         }
         else{
            runNode * r = new numConstNode (*(yyvsp[0].fval));
            #if JSON==1
            if (interpreter::get()->json){
               r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
            }
            #endif
            runNode * d = new addNode ((yyvsp[-1].data), r);
            #if JSON==1
            if (interpreter::get()->json){
               runNode*a[2] = {(yyvsp[-1].data), r};
               string b[2] = {"op1", "op2"};
               d->toJson ("addNode", "operator", a, b, 2);
            }
            #endif
            (yyval.data) = d; 
         }
      }
#line 10036 "lshParser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 2875 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10042 "lshParser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 2879 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new prodNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("prodNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10058 "lshParser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 2890 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new divNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("divNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10074 "lshParser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 2901 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10080 "lshParser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 2905 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new powNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("powNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10096 "lshParser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 2916 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new modNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("modNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10112 "lshParser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 2927 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10118 "lshParser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 2932 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10124 "lshParser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 2936 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new catNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("catNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10140 "lshParser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 2947 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new catNode ((yyvsp[-2].data), (yyvsp[0].data), true);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("catNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10156 "lshParser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 2958 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new catNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("catNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 10172 "lshParser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 2969 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10178 "lshParser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 2973 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new inputNode ((yyvsp[0].idnode), 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)};
            r->toJson ("inputNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 10193 "lshParser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 2983 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new inputNode ((yyvsp[0].idnode), 1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)};
            r->toJson ("inputNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;       
      }
#line 10208 "lshParser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 2993 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new inputNode ((yyvsp[0].idnode), 0, (yyvsp[-2].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[0].idnode), (yyvsp[-2].data)};
            string b[2] = {"", "prompt"};
            r->toJson ("inputNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;       
      }
#line 10224 "lshParser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 3004 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new inputNode ((yyvsp[0].idnode), 1, (yyvsp[-2].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[0].idnode), (yyvsp[-2].data)};
             string b[2] = {"", "prompt"};
            r->toJson ("inputNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 10240 "lshParser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 3015 "lshParser.y" /* yacc.c:1646  */
    { 
         idNode * r = new idNode ("user");
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", "user");
         }
         #endif
         runNode * d = new inputNode (r, 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("inputNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = d;    
      }
#line 10261 "lshParser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 3031 "lshParser.y" /* yacc.c:1646  */
    { 
         idNode * r = new idNode ("user");
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", "user");
         }
         #endif
         runNode * d = new inputNode (r, 1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("inputNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = d;    
      }
#line 10282 "lshParser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 3047 "lshParser.y" /* yacc.c:1646  */
    { 
         idNode * r = new idNode ("user");
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", "user");
         }
         #endif
         runNode * d = new inputNode (r, 0, (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r, (yyvsp[-1].data)};
            string b[2] = {"", "prompt"};
            d->toJson ("inputNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;   
      }
#line 10304 "lshParser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 3064 "lshParser.y" /* yacc.c:1646  */
    { 
         idNode * r = new idNode ("user");
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", "user");
         }
         #endif
         runNode * d = new inputNode (r, 1, (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r,(yyvsp[-1].data)};
            string b[2] = {"", "prompt"};
            d->toJson ("inputNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;   
      }
#line 10326 "lshParser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 3081 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10332 "lshParser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 3086 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functioncallNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"id", "params"};
            r->toJson ("callNode", "function", a, b, 2); 
         }
         #endif
         (yyval.data) = r;     
      }
#line 10348 "lshParser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 3097 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functioncallNode ((yyvsp[-2].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-2].data)};
            string b[2] = {"id"};
            r->toJson ("callNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10364 "lshParser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 3108 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10370 "lshParser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 3113 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10376 "lshParser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 3117 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new ternNode ((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data)};
            string b[3] = {"cond", "true", "false"};
            r->toJson ("ternNode", "operator", a, b, 3);
         }
         #endif
         (yyval.data) = r;    
      }
#line 10392 "lshParser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 3128 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new ternNode ((yyvsp[-3].data), NULL, (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[0].data)};
            string b[2] = {"cond", "false"};
            r->toJson ("ternNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 10408 "lshParser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 3139 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new ternNode ((yyvsp[-2].data), (yyvsp[0].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"cond", "true"};
            r->toJson ("ternNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 10424 "lshParser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 3150 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10430 "lshParser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 3154 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new notnullNode ((yyvsp[-2].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-2].data)};
            r->toJson ("notnullNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10445 "lshParser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 3164 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10451 "lshParser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 3169 "lshParser.y" /* yacc.c:1646  */
    {(yyval.data) = (yyvsp[0].data); }
#line 10457 "lshParser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 3170 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10463 "lshParser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 3171 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10469 "lshParser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 3172 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10475 "lshParser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 3173 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10481 "lshParser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 3176 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10487 "lshParser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 3177 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10493 "lshParser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 3178 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10499 "lshParser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 3179 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10505 "lshParser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 3180 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10511 "lshParser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 3181 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10517 "lshParser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 3182 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10523 "lshParser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 3185 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10529 "lshParser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 3186 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getRefNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("getRefNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10544 "lshParser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 3199 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new incasigNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("incasigNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10559 "lshParser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 3209 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new incasigNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("incasigNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r; 
      }
#line 10574 "lshParser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 3219 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new decasigNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("decasigNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10589 "lshParser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 3229 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new asigdecNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("asigdecNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10604 "lshParser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 3239 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10610 "lshParser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 3243 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new addNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("addNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;   
      }
#line 10634 "lshParser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 3262 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new subNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("subNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;   
      }
#line 10658 "lshParser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 3281 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new prodNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("prodNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;      
      }
#line 10682 "lshParser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 3300 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new divNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("divNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;      
      }
#line 10706 "lshParser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 3319 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new powNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("powNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;      
      }
#line 10730 "lshParser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 3338 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new modNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("modNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;      
      }
#line 10754 "lshParser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 3357 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new catNode ((yyvsp[-2].data), (yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),(yyvsp[0].data)};
            string b[2] = {"op1", "op2"};
            r->toJson ("catNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ((yyvsp[-2].data), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data) = d;   
      }
#line 10778 "lshParser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 3376 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10784 "lshParser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 3380 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new intconvNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("intconvNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10799 "lshParser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 3390 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new floatconvNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("floatconvNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10814 "lshParser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 3400 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new boolconvNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("boolconvNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10829 "lshParser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 3410 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new strconvNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("strconvNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10844 "lshParser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 3420 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new intconvNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("intconvNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;      
      }
#line 10859 "lshParser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 3430 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new floatconvNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("floatconvNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10874 "lshParser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 3440 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new boolconvNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("boolconvNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10889 "lshParser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 3450 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new strconvNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("strconvNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10904 "lshParser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 3463 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new isNullNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("isNullNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10919 "lshParser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 3473 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new isBoolNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("isBoolNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10934 "lshParser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 3483 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new isNumNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("isNumNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10949 "lshParser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 3493 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new isStringNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("isStringNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10964 "lshParser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 3503 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new isObjectNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("isObjectNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10979 "lshParser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 3513 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new isArrayNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("isArrayNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 10994 "lshParser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 3523 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new emptyNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("emptyNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11009 "lshParser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 3536 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new sizeNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("sizeNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11024 "lshParser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 3546 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new sqrtNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("sqrtNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11039 "lshParser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 3556 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new sizeOfNode ((yyvsp[0].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("sizeOfNode", "operator", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11054 "lshParser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 3566 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new sizeOfNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("sizeOfNode", "operator", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11068 "lshParser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 3579 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new explodeNode ((yyvsp[-1].data), (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"str", "dlm"};
            r->toJson ("explodeNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11084 "lshParser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 3590 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new implodeNode ((yyvsp[-1].data), (yyvsp[-3].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"array", "dlm"};
            r->toJson ("implodeNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11100 "lshParser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 3601 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new sprintfNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("sprintfNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11115 "lshParser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 3611 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new findNode ((yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[3] = {"str", "sub", "ipos"};
            r->toJson ("findNode", "function", a, b, 3);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11131 "lshParser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 3622 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new findNode ((yyvsp[-3].data), (yyvsp[-1].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"str", "sub"};
            r->toJson ("findNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11147 "lshParser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 3633 "lshParser.y" /* yacc.c:1646  */
    {; 
         runNode * r = new replaceNode ((yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-7].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[4] = {"str", "search", "replace", "nreplace"};
            r->toJson ("replaceNode", "function", a, b, 4);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11163 "lshParser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 3644 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new replaceNode ((yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[-5].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[3] = {"str", "search", "replace",};
            r->toJson ("replaceNode", "function", a, b, 3);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11179 "lshParser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 3655 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new subreplaceNode ((yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[-7].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[4] = {"str", "ini", "len", "replace"};
            r->toJson ("subreplaceNode", "function", a, NULL, 4);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11195 "lshParser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 3666 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new upperNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("upperNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11210 "lshParser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 3676 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new lowerNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("lowerNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11225 "lshParser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 3689 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new newNode ((yyvsp[-2].idnode), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-2].idnode)};
            string b[1] = {"class"};
            r->toJson ("newNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;     
      }
#line 11241 "lshParser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 3700 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new newNode ((yyvsp[0].idnode), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)};
            string b[1] = {"class"};
            r->toJson ("newNode", "class", a, b, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11257 "lshParser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 3711 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new newNode ((yyvsp[-3].idnode), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].idnode), (yyvsp[-1].data)};
            string b[2] = {"class", "params"};
            r->toJson ("newNode", "class", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11273 "lshParser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 3722 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new thisNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("thisNode", "class", NULL, 0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 11287 "lshParser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 3731 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new parentNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("parentNode", "class", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11301 "lshParser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 3740 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11307 "lshParser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 3741 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getclassNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("getclassNode", "class", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11322 "lshParser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 3754 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arrayConstNode ((yyvsp[-1].listnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].listnode)};
            r->toJson ("arrayConstNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11337 "lshParser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 3764 "lshParser.y" /* yacc.c:1646  */
    { 
          runNode * r = new arrayConstNode ((yyvsp[-1].listnode));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].listnode)};
            r->toJson ("arrayConstNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11352 "lshParser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 3774 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arrayConstNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("arrayConstNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11366 "lshParser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 3783 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11372 "lshParser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 3784 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11378 "lshParser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 3788 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new dateNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            string b[1] = {"format"};
            r->toJson ("dateNode", "data", a, b, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11394 "lshParser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 3799 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new dateNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"format", "time"};
            r->toJson ("dateNode", "data", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11410 "lshParser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 3810 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new timeNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("timeNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11424 "lshParser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 3819 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new timeNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("timeNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11438 "lshParser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 3831 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fileNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"file", "mode"};
            r->toJson ("fileNode", "data", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11454 "lshParser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 3842 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fileNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            string b[1] = {"file"};
            r->toJson ("fileNode", "data", a, b, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11470 "lshParser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 3853 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fputNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"file", "content"};
            r->toJson ("fputNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11486 "lshParser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 3864 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fwriteNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"file", "content"};
            r->toJson ("fwriteNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11502 "lshParser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 3875 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fappendNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"file", "content"};
            r->toJson ("fappend", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11518 "lshParser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 3886 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fgetNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            string b[1] = {"file"};
            r->toJson ("fgetNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11534 "lshParser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 3897 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fgetNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"file", "size"};
            r->toJson ("fgetNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11550 "lshParser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 3908 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new freadNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("freadNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11565 "lshParser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 3918 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new fcloseNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("fcloseNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11580 "lshParser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 3928 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fseekNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"file", "offset"};
            r->toJson ("fseekNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11596 "lshParser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 3939 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fseekNode ((yyvsp[-5].data), (yyvsp[-3].data), 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), (yyvsp[-3].data)};
             string b[2] = {"file", "offset"};
            r->toJson ("fseekNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11612 "lshParser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 3950 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new fseekNode ((yyvsp[-5].data), (yyvsp[-3].data), 1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), (yyvsp[-3].data)};
             string b[2] = {"file", "offset"};
            r->toJson ("fseekNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11628 "lshParser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 3961 "lshParser.y" /* yacc.c:1646  */
    {
          runNode * r = new fseekNode ((yyvsp[-5].data), (yyvsp[-3].data), 2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].data), (yyvsp[-3].data)};
             string b[2] = {"file", "offset"};
            r->toJson ("fseekNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11644 "lshParser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 3972 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new ftellNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("ftellNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11659 "lshParser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 3985 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new execNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("execNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11674 "lshParser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 3995 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new evalNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("evalNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11689 "lshParser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 4005 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new forkNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("forkNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11703 "lshParser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 4014 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new waitNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("waitNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;     
      }
#line 11718 "lshParser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 4024 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new waitNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("waitNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11732 "lshParser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 4033 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new signalNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
             string b[2] = {"pid", "signal"};
            r->toJson ("signalNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
   
      }
#line 11749 "lshParser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 4045 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new signalhandlerNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"signal", "function"};
            r->toJson ("signalhandlerNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11765 "lshParser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 4056 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new exitProcessNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("exitProcessNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
   }
#line 11779 "lshParser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 4065 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getpidNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getpidNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;      
      }
#line 11793 "lshParser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 4074 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new getppidNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getppidNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11807 "lshParser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 4083 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new processNode ((yyvsp[-3].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"function", "params"};
            r->toJson ("processNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;     
      }
#line 11823 "lshParser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 4094 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new processNode ((yyvsp[-1].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            string b[1] = {"function"};
            r->toJson ("processNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;     
      }
#line 11839 "lshParser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 4108 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getEnvNode ((yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("getEnvNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11854 "lshParser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 4121 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-5].data), (yyvsp[-3].idnode), (yyvsp[-1].data), NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-3].idnode), (yyvsp[-1].data)};
            string b[3] = {"out", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 3);
         }
         #endif
         (yyval.data) = r;      
      }
#line 11870 "lshParser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 4132 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-2].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-2].data)};
            string b[4] = {"out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11886 "lshParser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 4143 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-6].data), (yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-6].data), (yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data)};
            string b[4] = {"out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11902 "lshParser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 4154 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-7].data), (yyvsp[-5].idnode), (yyvsp[-3].data), NULL, NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[4] = {"out", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11918 "lshParser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 4165 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-8].idnode), (yyvsp[-6].data), (yyvsp[-4].data), NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-10].data), (yyvsp[-8].idnode), (yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[5] = {"out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11934 "lshParser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 4176 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-3].data), NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[5] = {"out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11950 "lshParser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 4187 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-7].data), (yyvsp[-4].idnode), (yyvsp[-2].data), NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-7].data), (yyvsp[-4].idnode), (yyvsp[-2].data)};
            string b[3] = {"out", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 3);
         }
         #endif
         (yyval.data) = r;     
      }
#line 11966 "lshParser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 4198 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-2].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-2].data)};
            string b[4] = {"out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;     
      }
#line 11982 "lshParser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 4209 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-8].data), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-8].data), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[4] = {"out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11998 "lshParser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 4220 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-9].data), (yyvsp[-6].idnode), (yyvsp[-4].data), NULL, NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-9].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[4] = {"out", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12014 "lshParser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 4231 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-12].data), (yyvsp[-9].idnode), (yyvsp[-7].data), (yyvsp[-4].data), NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-12].data), (yyvsp[-9].idnode), (yyvsp[-7].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[5] = {"out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12030 "lshParser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 4242 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-3].data), NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[5] = {"out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12046 "lshParser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 4253 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-7].data), (yyvsp[-3].idnode), (yyvsp[-1].data), NULL, (yyvsp[-5].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), (yyvsp[-5].idnode), (yyvsp[-3].idnode), (yyvsp[-1].data)};
            string b[4] = {"out", "key", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12062 "lshParser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 4264 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[-8].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-10].data), (yyvsp[-8].idnode), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-2].data)};
            string b[5] = {"out", "key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;      
      }
#line 12078 "lshParser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 4275 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-8].data), (yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data), (yyvsp[-6].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data)};
            string b[5] = {"out", "key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;      
      }
#line 12094 "lshParser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 4286 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-9].data), (yyvsp[-5].idnode), (yyvsp[-3].data), NULL, (yyvsp[-7].idnode), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-9].data), (yyvsp[-7].idnode), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[5] = {"out", "key", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12110 "lshParser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 4297 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-12].data), (yyvsp[-8].idnode), (yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-10].idnode), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-12].data), (yyvsp[-10].idnode), (yyvsp[-8].idnode), (yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[6] = {"out", "key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12126 "lshParser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 4308 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-3].data), (yyvsp[-8].idnode), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-10].data), (yyvsp[-8].idnode), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[6] = {"out", "key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12142 "lshParser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 4319 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-9].data), (yyvsp[-4].idnode), (yyvsp[-2].data), NULL, (yyvsp[-6].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-9].data), (yyvsp[-6].idnode), (yyvsp[-4].idnode), (yyvsp[-2].data)};
             string b[4] = {"out", "key", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12158 "lshParser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 4330 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-12].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-2].data), (yyvsp[-9].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-12].data), (yyvsp[-9].idnode), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-2].data)};
             string b[5] = {"out", "key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;         
      }
#line 12174 "lshParser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 4341 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[-7].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
             string b[5] = {"out", "key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12190 "lshParser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 4352 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-11].data), (yyvsp[-6].idnode), (yyvsp[-4].data), NULL, (yyvsp[-8].idnode), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-11].data), (yyvsp[-8].idnode), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[5] = {"out", "key", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12206 "lshParser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 4363 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-14].data), (yyvsp[-9].idnode), (yyvsp[-7].data), (yyvsp[-4].data), (yyvsp[-11].idnode), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-14].data), (yyvsp[-11].idnode), (yyvsp[-9].idnode), (yyvsp[-7].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[6] = {"out", "key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12222 "lshParser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 4374 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-12].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-9].idnode), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-12].data), (yyvsp[-9].idnode), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[6] = {"out", "key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12238 "lshParser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 4385 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-5].data), (yyvsp[-3].idnode), (yyvsp[-1].data), NULL, NULL, NULL, (yyvsp[-7].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-7].data), (yyvsp[-5].data), (yyvsp[-3].idnode), (yyvsp[-1].data)};
            string b[4] = {"kout", "out", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12254 "lshParser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 4396 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-2].data), NULL, NULL, (yyvsp[-10].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-10].data), (yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-2].data)};
            string b[5] = {"kout", "out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12270 "lshParser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 4407 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-6].data), (yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data), NULL, NULL, (yyvsp[-8].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-8].data), (yyvsp[-6].data), (yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data)};
            string b[5] = {"kout", "out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;      
      }
#line 12286 "lshParser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 4418 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-7].data), (yyvsp[-5].idnode), (yyvsp[-3].data), NULL, NULL, (yyvsp[-1].data), (yyvsp[-9].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-9].data), (yyvsp[-7].data), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[5] = {"kout", "out", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12302 "lshParser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 4429 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-8].idnode), (yyvsp[-6].data), (yyvsp[-4].data), NULL, (yyvsp[-1].data), (yyvsp[-12].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-12].data), (yyvsp[-10].data), (yyvsp[-8].idnode), (yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[6] = {"kout", "out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12318 "lshParser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 4440 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-3].data), NULL, (yyvsp[-1].data), (yyvsp[-10].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-10].data), (yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[6] = {"kout", "out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;       
      }
#line 12334 "lshParser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 4451 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-7].data), (yyvsp[-4].idnode), (yyvsp[-2].data), NULL, NULL, NULL, (yyvsp[-9].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {(yyvsp[-9].data), (yyvsp[-7].data), (yyvsp[-4].idnode), (yyvsp[-2].data)};
            string b[4] = {"kout", "out", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         (yyval.data) = r;                               
      }
#line 12350 "lshParser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 4462 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-2].data), NULL, NULL, (yyvsp[-12].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-12].data), (yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-2].data)};
            string b[5] = {"kout", "out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, NULL, 5);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12366 "lshParser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 4473 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-8].data), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data), NULL, NULL, (yyvsp[-10].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-10].data), (yyvsp[-8].data), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[5] = {"kout", "out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;      
      }
#line 12382 "lshParser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 4484 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-9].data), (yyvsp[-6].idnode), (yyvsp[-4].data), NULL, NULL, (yyvsp[-1].data), (yyvsp[-11].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-11].data), (yyvsp[-9].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[5] = {"kout", "out", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;      
      }
#line 12398 "lshParser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 4495 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-12].data), (yyvsp[-9].idnode), (yyvsp[-7].data), (yyvsp[-4].data), NULL, (yyvsp[-1].data), (yyvsp[-14].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-14].data), (yyvsp[-12].data), (yyvsp[-9].idnode), (yyvsp[-7].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[6] = {"kout", "out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;      
      }
#line 12414 "lshParser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 4506 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-3].data), NULL, (yyvsp[-1].data), (yyvsp[-12].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-12].data), (yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[6] = {"kout", "out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;      
   
      }
#line 12431 "lshParser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 4518 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-7].data), (yyvsp[-3].idnode), (yyvsp[-1].data), NULL, (yyvsp[-5].idnode), NULL, (yyvsp[-9].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-9].data), (yyvsp[-7].data), (yyvsp[-5].idnode), (yyvsp[-3].idnode), (yyvsp[-1].data)};
            string b[5] = {"kout", "out","key", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;         
      }
#line 12447 "lshParser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 4529 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[-8].idnode), NULL, (yyvsp[-12].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-12].data), (yyvsp[-10].data), (yyvsp[-8].idnode), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-2].data)};
            string b[6] = {"kout", "out","key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12463 "lshParser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 4540 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-8].data), (yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data), (yyvsp[-6].idnode), NULL, (yyvsp[-10].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-10].data), (yyvsp[-8].data), (yyvsp[-6].idnode), (yyvsp[-4].idnode), (yyvsp[-2].data), (yyvsp[-1].data)};
            string b[6] = {"kout", "out","key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12479 "lshParser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 4551 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-9].data), (yyvsp[-5].idnode), (yyvsp[-3].data), NULL, (yyvsp[-7].idnode), (yyvsp[-1].data), (yyvsp[-11].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-11].data), (yyvsp[-9].data), (yyvsp[-7].idnode), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[6] = {"kout", "out","key", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12495 "lshParser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 4562 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-12].data), (yyvsp[-8].idnode), (yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-10].idnode), (yyvsp[-1].data), (yyvsp[-14].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[7] = {(yyvsp[-14].data), (yyvsp[-12].data), (yyvsp[-10].idnode), (yyvsp[-8].idnode), (yyvsp[-6].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[7] = {"kout", "out","key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 7);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12511 "lshParser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 4573 "lshParser.y" /* yacc.c:1646  */
    {  
          runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-3].data), (yyvsp[-8].idnode), (yyvsp[-1].data), (yyvsp[-12].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[7] = {(yyvsp[-12].data), (yyvsp[-10].data), (yyvsp[-8].idnode), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[7] = {"kout", "out","key", "val", "exp", "stmts", "if"};           
            r->toJson ("generatorNode", "data", a, b, 7);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12527 "lshParser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 4584 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-9].data), (yyvsp[-4].idnode), (yyvsp[-2].data), NULL, (yyvsp[-6].idnode), NULL, (yyvsp[-11].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {(yyvsp[-11].data), (yyvsp[-9].data), (yyvsp[-6].idnode), (yyvsp[-4].idnode)};
            string b[5] = {"kout", "out","key", "val"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         (yyval.data) = r;            
      }
#line 12543 "lshParser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 4595 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-12].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-2].data), (yyvsp[-9].idnode), NULL, (yyvsp[-14].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-14].data), (yyvsp[-12].data), (yyvsp[-9].idnode), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-2].data)};
            string b[6] = {"kout", "out","key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12559 "lshParser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 4606 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-10].data), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data), (yyvsp[-7].idnode), NULL, (yyvsp[-12].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-12].data), (yyvsp[-10].data), (yyvsp[-7].idnode), (yyvsp[-5].idnode), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[6] = {"kout", "out","key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12575 "lshParser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 4617 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-11].data), (yyvsp[-6].idnode), (yyvsp[-4].data), NULL, (yyvsp[-8].idnode), (yyvsp[-1].data), (yyvsp[-13].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {(yyvsp[-13].data), (yyvsp[-11].data), (yyvsp[-8].idnode), (yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[6] = {"kout", "out","key", "val", "exp", "if"};            
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12591 "lshParser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 4628 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new foreachGeneratorNode ((yyvsp[-14].data), (yyvsp[-9].idnode), (yyvsp[-7].data), (yyvsp[-4].data), (yyvsp[-11].idnode), (yyvsp[-1].data), (yyvsp[-16].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[7] = {(yyvsp[-16].data), (yyvsp[-14].data), (yyvsp[-11].idnode), (yyvsp[-9].idnode), (yyvsp[-7].data), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[7] = {"kout", "out","key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 7);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12607 "lshParser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 4639 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new foreachGeneratorNode ((yyvsp[-12].data), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-9].idnode), (yyvsp[-1].data), (yyvsp[-14].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[7] = {(yyvsp[-14].data), (yyvsp[-12].data), (yyvsp[-9].idnode), (yyvsp[-7].idnode), (yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[7] = {"kout", "out","key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 7);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12623 "lshParser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 4653 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new newregexpNode ((yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("newregexpNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12638 "lshParser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 4663 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new searchNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)} ;
            string b[2] = {"str", "regexp"};
            r->toJson ("searchNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 12654 "lshParser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 4674 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new searchNode ((yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)} ;
            string b[3] = {"str", "regexp", "key"};
            r->toJson ("searchNode", "function", a, NULL, 3);
         }
         #endif
         (yyval.data) = r;         
      }
#line 12670 "lshParser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 4685 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new matchNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)} ;
            string b[2] = {"str", "regexp"};
            r->toJson ("matchNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12686 "lshParser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 4699 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getiNode (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getiNode", "symbol", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12700 "lshParser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 4708 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new numConstNode (*(yyvsp[-1].fval)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[-1].fval));
         }
         #endif
         runNode * d = new getiNode (r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("getiNode", "symbol", a, NULL, 1);
         }
         #endif
         (yyval.data) = d;      
      }
#line 12721 "lshParser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 4727 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data) = r;
      }
#line 12735 "lshParser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 4736 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new boolConstNode (true);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("boolConstNode", "data", NULL, NULL, 0, "true");
         }
         #endif
         (yyval.data) = r;
      }
#line 12749 "lshParser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 4745 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new boolConstNode (false); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("boolConstNode", "data", NULL, NULL, 0, "false");
         }
         #endif
         (yyval.data)  = r;
      }
#line 12763 "lshParser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 4754 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new nullNode (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("nullNode", "data", NULL, 0);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 12777 "lshParser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 4763 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data)  = r;
      }
#line 12791 "lshParser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 4772 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new strConstNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("strConstNode", "data", NULL, NULL, 0, *(yyvsp[0].str));
         }
         #endif
         (yyval.data)  = r;   
      }
#line 12805 "lshParser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 4781 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new regexpNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("regexpNode", "data", NULL, NULL, 0, *(yyvsp[0].str));
         }
         #endif
         (yyval.data)  = r;   
      }
#line 12819 "lshParser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 4790 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data)  = r;
      }
#line 12833 "lshParser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 4799 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (-1 * (*(yyvsp[0].fval))); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, (-1 * (*(yyvsp[0].fval))));
         }
         #endif
         (yyval.data)  = r;
      }
#line 12847 "lshParser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 4808 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].idnode);}
#line 12853 "lshParser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 4809 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].data); }
#line 12859 "lshParser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 4813 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 12865 "lshParser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 4814 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 12871 "lshParser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 4815 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new contextFunction (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("contextFunction", "function", NULL, 0);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 12885 "lshParser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 4828 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functionNode (NULL, NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)} ;
            string b[1] = {"body"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12901 "lshParser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 4839 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functionNode (NULL, (yyvsp[-4].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].data)} ;
            string b[2] = {"params", "body"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12917 "lshParser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 4850 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functionNode (NULL, (yyvsp[-3].data), NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-3].data)};
            string b[2] = {"params"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12933 "lshParser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 4861 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functionNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("functionNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12947 "lshParser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 4870 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new functiongetNode ((yyvsp[0].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)} ;
            r->toJson ("functiongetNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12962 "lshParser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 4880 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new functionNode (NULL, NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)} ;
            string b[1] = {"body"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12978 "lshParser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 4891 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functionNode (NULL, (yyvsp[-4].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].data)} ;
            string b[2] = {"params", "body"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;     
      }
#line 12994 "lshParser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 4902 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new functionNode (NULL, (yyvsp[-3].data), NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-3].data)} ;
            string b[1] = {"params",};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;     
      }
#line 13010 "lshParser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 4913 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new functionNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("functionNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13024 "lshParser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 4922 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new functiongetNode ((yyvsp[0].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].idnode)} ;
            r->toJson ("functiongetNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13039 "lshParser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 4932 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new returnNode ((yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)} ;
            r->toJson ("returnNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d = new functionNode ( NULL, (yyvsp[-2].data), r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data),r} ;
            string b[2] = {"params", "body"} ;
            d->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = d;   
      }
#line 13062 "lshParser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 4953 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new partialFunctionNode ((yyvsp[-2].data), (yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;        
      }
#line 13078 "lshParser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 4964 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new partialFunctionNode ((yyvsp[-2].data), (yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13094 "lshParser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 4975 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new partialFunctionNode ((yyvsp[-4].data), (yyvsp[-1].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].idnode)};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13110 "lshParser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 4986 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new partialFunctionNode ((yyvsp[-4].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].data)};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 13126 "lshParser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 4997 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new partialFunctionNode ((yyvsp[-4].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].data)};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 13142 "lshParser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 5008 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new partialFunctionNode ((yyvsp[-2].data), (yyvsp[0].data), true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;      
      }
#line 13158 "lshParser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 5023 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new listNode ((yyvsp[-1].data), NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)};
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;     
      }
#line 13173 "lshParser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 5033 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new listNode ((yyvsp[-2].data), (yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            r->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13188 "lshParser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 5043 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new listNode ((yyvsp[0].data), NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)} ;
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;    
      }
#line 13203 "lshParser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 5056 "lshParser.y" /* yacc.c:1646  */
    { 
         listNode * r = new listNode ((yyvsp[-2].listnode), (yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].listnode), (yyvsp[0].data)} ;
            r->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         (yyval.listnode) = r;    
      }
#line 13218 "lshParser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 5066 "lshParser.y" /* yacc.c:1646  */
    { 
         listNode * r = new listNode ((yyvsp[-1].listnode), NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].listnode)} ;
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.listnode) = r;     
      }
#line 13233 "lshParser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 5076 "lshParser.y" /* yacc.c:1646  */
    {  
         listNode * r = new listNode ((yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.listnode) = r;     
      }
#line 13248 "lshParser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 5089 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new mapNode ((yyvsp[-2].data), (yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"key", "value"};
            r->toJson ("mapNode", "data", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 13264 "lshParser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 5100 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13270 "lshParser.c" /* yacc.c:1646  */
    break;

  case 455:
#line 5105 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new asigNode ((yyvsp[-2].data), (yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)};
            string b[2] = {"var", "exp"};
            r->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = r;      
      }
#line 13286 "lshParser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 5116 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13292 "lshParser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 5121 "lshParser.y" /* yacc.c:1646  */
    { 
         listNode * r = new listNode ((yyvsp[-2].listnode), (yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].listnode), (yyvsp[0].data)};
            r->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         (yyval.listnode)  = r;
      }
#line 13307 "lshParser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 5131 "lshParser.y" /* yacc.c:1646  */
    { 
         listNode * r = new listNode ((yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[0].data)};
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         (yyval.listnode)  = r;   
      }
#line 13322 "lshParser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 5144 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new getNode ((yyvsp[-2].data), (yyvsp[0].idnode), false); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].idnode)};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = r;
      }
#line 13338 "lshParser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 5155 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = r;  
      }
#line 13354 "lshParser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 5166 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new getNode ((yyvsp[-2].data), (yyvsp[0].idnode), false); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].idnode)};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 13370 "lshParser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 5177 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 13386 "lshParser.c" /* yacc.c:1646  */
    break;

  case 463:
#line 5188 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 13402 "lshParser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 5199 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getNode_endValue (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("endValue", "operator", NULL, 0);
         }
         #endif
         runNode * d = new getNode ((yyvsp[-2].data), r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"elem", "key"};
            d->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = d;    
      }
#line 13424 "lshParser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 5216 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new getNode_endValue (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getNode", "operator", NULL, 0);
         }
         #endif
         runNode * d = new getNode ((yyvsp[-2].data), r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"elem", "key"};
            d->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = d;  
      }
#line 13446 "lshParser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 5233 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new getNode_endValue (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("endValue", "operator", NULL, 0);
         }
         #endif
         runNode * d = new getNode ((yyvsp[-2].data), r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), r};
            string b[2] = {"elem", "key"};
            d->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         (yyval.data)  = d;       
      }
#line 13468 "lshParser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 5250 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13474 "lshParser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 5251 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13480 "lshParser.c" /* yacc.c:1646  */
    break;

  case 469:
#line 5255 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arrayChunkNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"array", "size"};
            r->toJson ("arrayChunkNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;    
      }
#line 13496 "lshParser.c" /* yacc.c:1646  */
    break;

  case 470:
#line 5266 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arraylastNode ((yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)} ;
            r->toJson ("arraylastNode", "function", a, NULL, 1);
         }
         #endif  
         (yyval.data) = r; 
      }
#line 13511 "lshParser.c" /* yacc.c:1646  */
    break;

  case 471:
#line 5276 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arrayfirstNode ((yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)} ;
            r->toJson ("arrayfirstNode", "function", a, NULL, 1);
         }
         #endif  
         (yyval.data) = r;
      }
#line 13526 "lshParser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 5286 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new arrayinsertNode ((yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-5].data), (yyvsp[-3].data), (yyvsp[-1].data)};
            string b[3] = {"array", "index", "elem"};
            r->toJson ("arrayinsertNode", "function", a, b, 3);
         }
         #endif  
         (yyval.data) = r;   
      }
#line 13542 "lshParser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 5297 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arraydeleteNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"array", "index"};
            r->toJson ("arrayinsertNode", "function", a, b, 2);
         }
         #endif  
         (yyval.data) = r;    
      }
#line 13558 "lshParser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 5308 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arrayunshiftNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"array", "elem"};
            r->toJson ("arrayunshiftNode", "function", a, b, 2);
         }
         #endif  
         (yyval.data) = r;     
      }
#line 13574 "lshParser.c" /* yacc.c:1646  */
    break;

  case 475:
#line 5319 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arraypushNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"array", "elem"};
            r->toJson ("arraypushNode", "function", a, b, 2);
         }
         #endif  
         (yyval.data) = r;       
      }
#line 13590 "lshParser.c" /* yacc.c:1646  */
    break;

  case 476:
#line 5330 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arrayshiftNode ((yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)} ;
            r->toJson ("arrayshiftNode", "function", a, NULL, 1);
         }
         #endif  
         (yyval.data) = r;   
      }
#line 13605 "lshParser.c" /* yacc.c:1646  */
    break;

  case 477:
#line 5340 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arraypopNode ((yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)} ;
            r->toJson ("arraypopNode", "function", a, NULL, 1);
         }
         #endif  
         (yyval.data) = r;     
      }
#line 13620 "lshParser.c" /* yacc.c:1646  */
    break;

  case 478:
#line 5350 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new reduceNode ((yyvsp[-3].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-3].data), (yyvsp[-1].data)};
            string b[2] = {"array", "func"};
            r->toJson ("reduceNode", "function", a, b, 2);
         }
         #endif  
         (yyval.data) = r;    
      }
#line 13636 "lshParser.c" /* yacc.c:1646  */
    break;

  case 479:
#line 5365 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new namespaceNode ((yyvsp[-2].data), (yyvsp[0].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].idnode)};
            string b[2] = {"name", "key"};
            r->toJson ("namespaceNode", "function", a, b, 2);
         }
         #endif  
         (yyval.data) = r;     
      }
#line 13652 "lshParser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 5376 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new namespaceNode ((yyvsp[-2].idnode), (yyvsp[0].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].idnode), (yyvsp[0].idnode)};
            string b[2] = {"name", "key"};
            r->toJson ("namespaceNode", "function", a, b, 2);
         }
         #endif  
         (yyval.data) = r;     
      }
#line 13668 "lshParser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 5387 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new  parentNode(); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("parentNode", "function", NULL, 0);
         }
         #endif  
         runNode * d = new namespaceNode (r, (yyvsp[0].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r, (yyvsp[0].idnode)};
            string b[2] = {"name", "key"};
            d->toJson ("namespaceNode", "function", a, b, 2);
         }
         #endif  
         (yyval.data) = d;              
      }
#line 13690 "lshParser.c" /* yacc.c:1646  */
    break;

  case 482:
#line 5404 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new   staticNode(); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson (" staticNode", "class", NULL, 0);
         }
         #endif  
         runNode * d = new namespaceNode (r, (yyvsp[0].idnode)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r, (yyvsp[0].idnode)};
            string b[2] = {"name", "key"};
            d->toJson ("namespaceNode", "function", a, b, 2);
         }
         #endif  
         (yyval.data) = d;                 
      }
#line 13712 "lshParser.c" /* yacc.c:1646  */
    break;

  case 483:
#line 5425 "lshParser.y" /* yacc.c:1646  */
    { 
         idNode * r = new idNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", *(yyvsp[0].str));
         }
         #endif
         (yyval.idnode)  = r;
      }
#line 13726 "lshParser.c" /* yacc.c:1646  */
    break;

  case 484:
#line 5434 "lshParser.y" /* yacc.c:1646  */
    { 
         idNode * r = new idgetNode ((yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)} ;
            r->toJson ("idgetNode", "reflection", a, NULL, 1);
         }
         #endif  
         (yyval.idnode) = r;  
      }
#line 13741 "lshParser.c" /* yacc.c:1646  */
    break;


#line 13745 "lshParser.c" /* yacc.c:1646  */
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
#line 5447 "lshParser.y" /* yacc.c:1906  */


//======================================================================
// Fco. Javier Bohórquez Ogalla
