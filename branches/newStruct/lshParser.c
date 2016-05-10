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
#include "run/numData.h"
#include "run/runTree.h"
#include "run/sTable.h"
#include "run/typeNode.h"
#include "run/operatorNode.h"
#include "run/operatorStrNode.h"
#include "run/operatorArrayNode.h"
#include "run/operatorDateNode.h"
#include "run/operatorRegexpNode.h"
#include "run/fileNode.h"
#include "run/processNode.h"
#include "error.h"
#include "interpreter.h"
#include "run/sqliteDb.h"
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
#include "run/stmtNode.h"

#line 105 "lshParser.c" /* yacc.c:339  */

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
#line 59 "lshParser.y" /* yacc.c:355  */

  num* fval;
  string* str; 
  idNode* idnode;
  listNode* listnode;
  runNode* data;
  runNode** ref;
  vector<string>* mval;

#line 417 "lshParser.c" /* yacc.c:355  */
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

#line 446 "lshParser.c" /* yacc.c:358  */

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
#define YYFINAL  325
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   20573

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  157
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  489
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1240

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
       0,    96,    96,   111,   115,   125,   135,   145,   155,   165,
     175,   176,   182,   192,   202,   212,   222,   232,   242,   243,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     261,   262,   272,   282,   292,   302,   312,   322,   331,   341,
     351,   361,   371,   388,   405,   422,   439,   449,   459,   469,
     479,   488,   501,   505,   506,   508,   521,   532,   543,   561,
     572,   583,   594,   605,   623,   641,   652,   663,   681,   699,
     724,   742,   753,   764,   782,   793,   804,   815,   834,   848,
     859,   870,   888,   899,   910,   921,   932,   950,   968,   979,
     990,  1008,  1026,  1051,  1069,  1080,  1091,  1109,  1120,  1131,
    1142,  1160,  1174,  1185,  1206,  1217,  1228,  1246,  1260,  1271,
    1282,  1300,  1314,  1325,  1336,  1354,  1365,  1376,  1387,  1405,
    1416,  1427,  1438,  1449,  1460,  1471,  1482,  1493,  1504,  1515,
    1526,  1537,  1548,  1559,  1570,  1581,  1592,  1603,  1614,  1625,
    1636,  1647,  1658,  1669,  1683,  1692,  1701,  1710,  1722,  1733,
    1747,  1758,  1769,  1780,  1794,  1811,  1828,  1854,  1871,  1882,
    1893,  1911,  1922,  1933,  1944,  1962,  1973,  1984,  1995,  2013,
    2024,  2035,  2046,  2064,  2075,  2086,  2097,  2115,  2126,  2137,
    2148,  2166,  2181,  2192,  2210,  2235,  2256,  2261,  2272,  2283,
    2294,  2305,  2316,  2327,  2338,  2349,  2360,  2371,  2382,  2397,
    2408,  2419,  2429,  2443,  2461,  2479,  2497,  2502,  2512,  2529,
    2539,  2560,  2564,  2568,  2579,  2583,  2594,  2598,  2608,  2612,
    2623,  2634,  2645,  2656,  2667,  2678,  2689,  2700,  2705,  2709,
    2720,  2731,  2767,  2771,  2782,  2793,  2797,  2808,  2819,  2824,
    2828,  2839,  2850,  2861,  2865,  2875,  2885,  2896,  2907,  2923,
    2939,  2956,  2973,  2978,  2989,  3000,  3005,  3009,  3020,  3031,
    3042,  3046,  3056,  3061,  3062,  3063,  3064,  3065,  3068,  3069,
    3070,  3071,  3072,  3073,  3074,  3077,  3078,  3091,  3101,  3111,
    3121,  3131,  3135,  3154,  3173,  3192,  3211,  3230,  3249,  3268,
    3272,  3282,  3292,  3302,  3312,  3322,  3332,  3342,  3355,  3365,
    3375,  3385,  3395,  3405,  3415,  3428,  3438,  3448,  3458,  3471,
    3482,  3493,  3503,  3514,  3525,  3536,  3547,  3558,  3568,  3581,
    3592,  3603,  3614,  3623,  3632,  3633,  3646,  3656,  3666,  3675,
    3676,  3680,  3691,  3702,  3711,  3723,  3734,  3745,  3756,  3767,
    3778,  3789,  3800,  3810,  3820,  3831,  3842,  3853,  3864,  3877,
    3887,  3897,  3906,  3916,  3925,  3937,  3948,  3957,  3966,  3975,
    3986,  4000,  4013,  4024,  4035,  4046,  4057,  4068,  4079,  4090,
    4101,  4112,  4123,  4134,  4145,  4156,  4167,  4178,  4189,  4200,
    4211,  4222,  4233,  4244,  4255,  4266,  4277,  4288,  4299,  4310,
    4321,  4332,  4343,  4354,  4365,  4376,  4387,  4398,  4410,  4421,
    4432,  4443,  4454,  4465,  4476,  4487,  4498,  4509,  4520,  4531,
    4545,  4555,  4566,  4577,  4591,  4600,  4619,  4628,  4637,  4646,
    4655,  4664,  4673,  4682,  4691,  4700,  4701,  4705,  4706,  4707,
    4708,  4721,  4732,  4743,  4754,  4763,  4773,  4784,  4795,  4806,
    4815,  4825,  4839,  4850,  4861,  4872,  4884,  4895,  4906,  4917,
    4928,  4939,  4954,  4964,  4974,  4987,  4997,  5007,  5020,  5031,
    5036,  5047,  5052,  5062,  5075,  5086,  5097,  5108,  5119,  5130,
    5147,  5164,  5181,  5182,  5186,  5197,  5207,  5217,  5228,  5239,
    5250,  5261,  5271,  5281,  5296,  5307,  5318,  5335,  5356,  5365
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
  "function_decorator", "function_partial", "list", "map", "mapelement",
  "assig", "array", "parray", "arrayop", "namespace", "id", YY_NULLPTR
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

#define YYPACT_NINF -917

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-917)))

#define YYTABLE_NINF -464

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2707,   -56,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
   18107, 20263, 20263, 18107,    52, 18107, 18107, 18107, 18107, 18107,
   18107,     2,   -80, 18107,    26,  -917,    67,    67,  -917,    92,
   18261, 16413,   -18,    12, 18107, 10099,    12, 18415,    67,    19,
      34, 18107, 18569,    23,  -917, 18107,    27,    49, 14719, 18107,
   18107, 18107, 18107,    51,   101,   184,   196,   203,   225,   232,
     238,   314,   329,   340,   353,   360,   362,   384,   405,   407,
     412,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,    57,   137,   433,   434,   446,   451,   452,
     453,   455,   456,   458,   461,   464,   465,   469,   470,   474,
   20263, 20263, 20263, 20263,  -917, 18723, 16721,     6,     7, 18107,
   18107,   119,   185,     8,   153,   170,  -917,  2861,   272,  9791,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,   476,   396,  -917,  -917,   247,   113,
     -11,   146,  -917,  -917,   268,   -12,  -917,  -917,  -917,   231,
    -917,   364,  -917,  -917,  -917,  -917,  -917,   292,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
     380,     0,  -917,   513,    97,  9791,   -59,   475,   584,   477,
       7,  -917,   595,   -12,   364,   364,  -917, 18107,   480,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,     9,    67,   489,    60,
    -917,    20,   490,    43,   491,    67, 16875,  -917,  -917,    67,
   18877,  -917,  -917, 18107, 18107, 10253, 14873,  3631,   569,   493,
   10407, 18723,   286,    86,  -917, 18107,    67,  -917,  -917, 18723,
    -917,   494,  -917,  -917, 18107,   495,  -917, 19031, 16567,  3785,
     496,  -917,  -917,  -917,  -917, 18107, 18107, 18107, 18107, 18107,
   18107, 18107, 18107, 18107,   487, 18107, 18107, 18107, 18107, 18107,
   18107, 18107, 18107, 18107, 18107, 18107, 18107,   497, 17029,   498,
     500, 18107,   501, 18107, 18107, 18107,  -917, 18107,  -917, 18107,
   18107, 18107, 18107, 18107, 18107, 18107, 18107, 18107, 18107, 18107,
   18107, 18107, 18107, 18107,   172,   172,   172,   172, 19647, 19801,
   19955, 20109,    22,  -917,  -917,   481,   257,  -917,   326, 18107,
     626,    38,    67,    -8,   502,   -31,  -917,  -917,  -917,  -917,
      67, 18107,   -74,   492, 18107,  -917,  -917,  3015,  -917, 18107,
   18107, 19493, 19493, 19493,   504, 19185, 19339,  -917, 19493, 19493,
   19493, 19493, 19493, 19493, 19493, 19493, 19493,    67, 17183, 17337,
   17491, 17645,  -917,  -917, 18107, 18107, 18107, 18107, 18107, 18107,
   18107, 18107,    67, 17799,    67,    67,  -917,  -917,   503,  -917,
     506,   -16,  -917,    41,   -70,   516,   -15,    53,    67,  9945,
   17953,  -917,  -917,  -917,  -917,  -917,  -917,   505,   519,  3939,
     459,   523,  3785,   524,   525,  -917,   590,   521,  3169,   528,
    9945,   522,   284,    12,   616,  4093,  -917,   531,   308,   276,
      67, 18107, 18107,    67,   530,   533,   208,  -917,   534,  -917,
     532,   566,   537,   539,  -917,    -9,   540,   542,   543,   536,
     549,    -6,  -917,   550,   551,   547,    -5,   548,   179,   552,
     555,   556,   558,   554,   557,  -917,  -917,   560,  -917,  -917,
     198,  -917,   559,   561,   517,   518,   564,   563,   567,   571,
     573,   570,   574,   576,   572,   575,   577,   578,   579,   581,
     585, 20263, 20263, 20263, 20263,    56,  -917, 18107, 18107,  -917,
   18877,  -917, 18107,   283,   583,   541,   233,   300, 18107,    67,
     156,    88,    52,  -917,   -60, 20263,   596,  -917,   396,  -917,
    -917,  -917,  -917, 19493, 19493,  -917, 19493,  -917,   -11,   -11,
     146,   146,  -917,  -917,  -917,  -917,  -917,  -917,  -917,   234,
    -917,   568,  -917,   580, 18107,   586,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,   582,  -917,  -917,  4247,
     601,   602,   246, 20417,  4401,   603,   605,   271,   606,   608,
    -917,   273,  -917,  -917,   355,   610, 10561,    12,  -917,   466,
     611,  -917,  9945,    12,   649,  -917,  3323,  -917,   600,    12,
     654,   612,  -917,    67, 18107, 18107,    67, 14565,   618, 15027,
     662,   607,  -917,    37,  -917,   687,   619, 18107, 18107,  -917,
   18107, 18107, 18107, 18107,  -917,  -917,  -917, 18107,  -917,  -917,
   18107,  -917, 18107, 18107,  -917, 18107, 18107,  -917,  -917,  -917,
   18107, 18107,  -917,  -917, 18107, 18107, 18107,    67,    67, 18107,
    -917, 18107,  -917,  -917, 18107,  -917,  -917, 18107, 18107, 18107,
   18107,  -917,  -917,  -917,   172,   172,   172,   172,    67,   302,
     669,  -917,   481,  -917,  -917,    67,   750, 10715, 18107,  -917,
    4555,   620,  -917,   613,    67,   614,   621,   307,  -917,   604,
     172,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917, 18107,
    -917,  -917,   622,  4709,  4863,   624, 18723,   292,   228,  -917,
     625,  5017,  5171,   627,  9945,  -917,  -917, 10869,  -917,   473,
    5325,  -917,   629, 11023, 11177,  -917,  -917,  -917,   632,    12,
    -917,  -917,   633,  -917,   387,   634,   635,   717,    67,  5479,
     636, 18107,  5633,   639, 18107,    55,   640,    67,   638,   641,
    -917,   322,   637,   643,   645,   646,   650,   651,   652,   330,
     653,   656,   332,   658,   659,  -917,  -917,   660,   346,   663,
     644,   666,   673,   674,   309, 18107,    67,    58,   -42,   679,
    5787,  -917,   642,   680,  -917,   678,  5941,    52,  -917,    52,
    6095,   681,  -917,  -917,  -917,  -917,   682,  -917,   683,  6249,
     -21,   684,    39,  -917,  -917,   685,  -917,   686,  6403,   688,
    3785,  -917,   664, 11331,  -917,   654,   689,  -917,  6557,   482,
     692,  6711,  -917,   696,  -917,   698,  -917, 15181,    67, 18107,
   15335, 18107, 15489,   654,   694,  -917, 11485,   654,   695,  -917,
   15643, 18107,   699,  -917,   700,    67,   701,  -917,  -917,  -917,
   18107, 18107, 18107,  -917,  -917,  -917,  -917,  -917,  -917,   395,
    -917,  -917,  -917,  -917,  -917,  -917,  -917, 18107,  -917, 18107,
    -917,  -917,  -917, 18107,    67, 13333,   727,    67,   310, 11639,
      67, 18107, 11793,   654,   702,  -917, 11947,  -917,  -917,   703,
    -917,  -917,  -917,   705,  6865,  -917,  -917,  -917,   706,  -917,
    -917,  -917,  -917,  -917,  -917,   707,  -917,   708,  -917,  7019,
    -917,   704,  -917,   499,   709, 12101,  -917,   484,   654,   710,
    -917,  -917,  7173,   716,   715,   718,  7327,   719,   720,  7481,
     721,  -917,  7635,  -917,   723,  -917,  7789,   724,   722,  9945,
    -917,   725, 15797,   726,   348,   677,   728,   729,   730,   349,
     731,   732,   738, 18107,  -917,  3785,    44, 18107,   313, 18107,
      67,  7943,  -917,   735,   350,   734,  8097,  -917,   739,  -917,
    8251,  -917,   740,  -917,  -917,  -917,   713,  -917,  -917,  -917,
     654,   733,  -917, 12255,  -917,   488,  8405,  -917,   741, 12409,
    -917,  -917,   654,   737,  -917, 15951, 12563,   654,   742,  -917,
   16105,   654,   743,  -917,   654,   744,  -917,   654,   746,  -917,
    3477,  -917, 16259,  3785,   745,  -917,  -917, 18107, 18107,  -917,
    -917,  -917,  -917,  -917, 13487, 18107,   751,   747, 18107,  -917,
   13641, 18107,    67, 13795,   771,   654,   753,  -917, 12717, 18107,
   12871,   654,   754,  -917,   654,   756,  -917,  -917,  -917,  3785,
    -917,   755, 13025,  -917,   654,   757,  -917,  8559,  -917,   763,
    -917,  8713,   765,  8867,  -917,   766,  -917,  9021,   767,  -917,
    -917,  -917,   483,  -917,  3785,   768,   764,  -917,   769,   770,
   18107,  -917,  3785,    59,   772,  -917,    91,   773, 18107,  -917,
    3785,   253,   774,   788, 18107,  -917,  3785,   254, 18107,  -917,
    9175,  -917,   777,   776,  9329,  -917,   780,  -917,  -917,   779,
    -917,  9483,  -917,   782,  -917,   654,   781,  -917,   654,   783,
    -917,   654,   785,  -917,   654,   786,  -917,  -917,   787,  -917,
    -917,  -917,  -917,   793,   791, 18107,  -917, 13949, 18107,  -917,
    -917,   795,   794, 18107,  -917, 14103, 18107,   799,   797, 18107,
    -917, 14257,   654,   802,  -917, 13179,   654,   803,  -917,  -917,
     654,   804,  -917,  -917,  -917,  -917,  -917,  -917,  -917,   259,
     808, 18107,  -917,  3785,   265,   809,  -917,   266,   810, 18107,
    -917,  3785,   267,   811,  -917,   269,   813, 18107,  -917,  3785,
     274,  -917,  9637,  -917,   818,  -917,  -917, 18107,  -917,  -917,
     819,   815, 18107,  -917,  -917, 18107,  -917,  -917,   820,   821,
   18107,  -917, 14411, 18107,  -917,  -917,   822,   823, 18107,  -917,
     654,   824,  -917,   825,  -917,   275,   828,   829,  -917,   279,
     830, 18107,  -917,  3785,   280,   831,  -917,   281,   833,  -917,
    -917, 18107,  -917,  -917,  -917, 18107,  -917,  -917,   834,   832,
   18107,  -917,  -917, 18107,  -917,  -917,   836,   837,  -917,   287,
     838,   840,  -917,  -917, 18107,  -917,  -917,  -917,   841,  -917
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   416,   420,   422,   421,   419,   417,   418,   488,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,   430,     0,     0,   322,   323,
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
     263,   281,   264,   265,   266,   267,   473,   461,   268,   269,
     270,   272,   271,   273,   274,   472,   275,   427,   428,   429,
     289,   329,   330,   324,   425,     0,     0,     0,     0,   414,
       0,    31,   425,     0,   277,   279,    35,     0,     0,   425,
     298,   303,   300,   299,   301,   302,     0,     0,     0,     0,
      36,     0,     0,     0,   320,     0,     0,   202,    41,     0,
       0,   201,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   425,    34,     0,     0,    46,   307,     0,
      48,     0,   144,   305,     0,     0,   146,     0,     0,     0,
       0,    51,    32,    33,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,   291,   292,   293,     0,     0,
       0,     0,     0,   328,   459,   463,     0,   457,     0,     0,
       0,     0,     0,     0,   206,   209,   276,   217,   423,   424,
       0,     0,     0,   209,     0,     1,     5,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    10,     0,    55,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,   486,    42,    43,   487,    44,    45,     0,     0,     0,
      59,     0,     0,     0,     0,    19,   328,     0,     0,    15,
       0,    53,    30,     0,     0,     0,   107,     0,     0,   425,
       0,     0,     0,     0,     0,     0,     0,   145,     0,   147,
       0,     0,     0,     0,   454,     0,     0,     0,     0,     0,
       0,     0,   333,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   351,   353,     0,   357,   358,
       0,   356,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   426,     0,     0,   327,
     456,   326,     0,     0,     0,     0,     0,   440,     0,     0,
       0,     0,     0,   210,     0,     0,     0,     4,   213,   215,
     223,   224,   225,     0,     0,   219,     0,   221,   229,   230,
     233,   234,   236,   237,   241,   242,   240,   466,   254,     0,
     471,     0,   470,     0,     0,   259,   460,   282,   283,   284,
     285,   286,   287,   288,   464,   469,     0,   484,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,   325,   186,    56,     0,     0,     0,    78,    58,
       0,   103,     0,     0,     0,    13,     0,    17,     0,     0,
     104,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,   426,   304,     0,     0,     0,     0,   311,
     452,     0,     0,     0,   317,   318,   331,     0,    38,   361,
       0,   336,     0,     0,   340,     0,     0,   348,   343,   342,
       0,     0,   352,   360,     0,     0,     0,   250,   251,     0,
     410,     0,   349,   350,     0,   475,   476,     0,     0,     0,
       0,   481,   482,    39,   294,   295,   296,   297,     0,     0,
       0,   458,     0,   455,   462,     0,     0,     0,     0,   415,
       0,     0,   441,     0,     0,   207,     0,     0,   205,     0,
     451,   489,   226,   220,   222,   253,   468,   467,   258,     0,
     465,   434,     0,     0,     0,     0,     0,   447,   446,   445,
       0,     0,     0,     0,     0,   199,   321,     0,    75,    57,
       0,    74,     0,     0,     0,    77,   102,    18,     0,     0,
      12,   111,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     453,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   439,     0,     0,     0,   208,     0,
       0,     0,   261,   257,   431,   433,     0,   190,     0,     0,
     461,   275,   425,   442,   444,     0,   198,     0,     0,     0,
       0,    65,     0,     0,    76,    71,     0,    73,     0,    82,
       0,     0,    70,     0,   108,     0,   110,     0,     0,     0,
       0,     0,     0,   135,     0,   137,     0,   123,     0,   125,
       0,     0,     0,   148,     0,     0,     0,   309,   310,   313,
       0,     0,     0,   332,   483,   335,   337,   341,   344,     0,
     338,   339,   359,   354,   355,   413,   411,     0,   474,     0,
     478,   479,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,     0,   160,     0,   436,   438,     0,
     203,   204,   194,     0,     0,   432,   189,   188,     0,   450,
     449,   448,   443,   197,   196,     0,   200,     0,    63,     0,
      66,     0,    72,    79,     0,     0,   101,    81,    67,     0,
      69,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,   119,     0,   124,     0,     0,     0,     0,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   362,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   157,     0,   159,
       0,   173,     0,   437,   193,   192,     0,   187,   195,    60,
      61,     0,    64,     0,    98,    80,     0,    97,     0,     0,
     100,    68,   132,     0,   134,     0,     0,   120,     0,   122,
       0,   141,     0,   143,   116,     0,   118,   129,     0,   131,
       0,   153,     0,     0,     0,   312,   315,     0,     0,   347,
     346,   345,   412,   477,     0,     0,     0,     0,     0,   364,
       0,     0,     0,     0,     0,   162,     0,   164,     0,     0,
       0,   154,     0,   156,   170,     0,   172,   191,    62,     0,
      88,     0,     0,    99,    94,     0,    96,     0,    93,     0,
     133,     0,     0,     0,   115,     0,   121,     0,     0,   142,
     117,   130,   151,   152,     0,     0,     0,   184,     0,     0,
       0,   368,     0,     0,     0,   365,     0,     0,     0,   374,
       0,     0,     0,     0,     0,   386,     0,     0,     0,   163,
       0,   169,     0,     0,     0,   177,     0,   155,   171,     0,
      86,     0,    89,     0,    95,    90,     0,    92,   138,     0,
     140,   112,     0,   114,   126,     0,   128,   150,     0,   185,
     183,   314,   316,     0,     0,     0,   370,     0,     0,   363,
     367,     0,     0,     0,   376,     0,     0,     0,     0,     0,
     388,     0,   166,     0,   168,     0,   174,     0,   176,    84,
      83,     0,    87,    91,   139,   113,   127,   182,   371,     0,
       0,     0,   380,     0,     0,     0,   377,     0,     0,     0,
     392,     0,     0,     0,   389,     0,     0,     0,   398,     0,
       0,   167,     0,   181,     0,   175,    85,     0,   369,   373,
       0,     0,     0,   382,   366,     0,   375,   379,     0,     0,
       0,   394,     0,     0,   387,   391,     0,     0,     0,   400,
     178,     0,   180,     0,   383,     0,     0,     0,   395,     0,
       0,     0,   404,     0,     0,     0,   401,     0,     0,   179,
     372,     0,   381,   385,   378,     0,   393,   397,     0,     0,
       0,   406,   390,     0,   399,   403,     0,     0,   407,     0,
       0,     0,   384,   396,     0,   405,   409,   402,     0,   408
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -917,  -917,   -94,  1547,   319,  1066,    29,  -917,  -917,  -521,
    -917,  -917,  -917,  -917,  -917,  -917,  -916,  -917,  -917,   -34,
    1128,  -917,   -85,  -917,   -10,  -210,  -917,   529,   -99,  -917,
    -286,  -917,   205,   207,   209,   167,  -917,     3,  -917,  -917,
    -917,   -14,  -917,   538,  -917,  -917,  -917,  -917,  -917,  -490,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,   -13,  -471,  -917,
    -917,  -917,  -305,  -917,   381,  -917,  -917,  -917,  -917,  -917,
     911
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   115,   116,   397,   398,   399,   400,   120,   121,   558,
     122,   123,   124,   125,   126,   127,   814,   128,   129,   215,
     130,   131,   313,   314,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   425,   306,   307,   170,   308,   171,   172,   173,
     182
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     181,   188,   220,   186,   388,   190,   191,   192,   193,   194,
     195,   317,     9,   200,   183,   183,   494,     9,     9,     9,
     208,   212,   347,   326,   216,   328,   231,   222,   322,   119,
       9,   228,   230,   688,   362,   233,     9,   -49,   695,   241,
     242,   243,   244,   519,     9,   500,   501,   502,     9,   505,
     507,     9,   235,   677,   365,     2,     3,     4,     5,     6,
       7,     8,     9,     9,  1043,   489,     9,     9,     9,   489,
       9,   475,   678,   199,   196,   551,   175,     9,   -49,   590,
     495,   367,   378,   197,   543,   998,   294,   295,   296,   297,
     -49,   -49,   849,   850,   659,   302,   305,   851,     9,   316,
    1105,   365,   491,   183,   183,   183,   183,   205,   811,   812,
     492,   371,   365,   869,   374,   213,   376,   337,   540,   545,
     354,   348,   318,   489,   489,   589,  1097,   488,   596,   601,
     590,   489,  1108,   597,   602,   196,   412,   340,   341,   309,
     311,   349,   310,   370,   197,   214,   119,     9,   119,   312,
     320,   320,   225,   363,   375,   232,   476,   477,   114,   201,
     234,   321,   320,   114,   114,   114,     9,   226,   784,   -49,
     325,   -49,   485,   871,   -49,   541,   114,   368,   999,   379,
     320,   236,   114,   320,   245,   187,   770,   546,   319,   638,
     114,   847,   813,  1106,   114,   320,   383,   114,   111,   112,
     386,   578,   320,   387,   119,   771,  -262,   402,   114,   114,
     275,   408,   114,   114,   114,   414,   114,   662,   663,   416,
     664,   413,   656,   114,   418,  1109,   486,   208,   212,   402,
     320,   499,   366,   497,   246,   422,   423,   424,   426,   427,
     428,   429,   430,   431,   114,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   475,   447,   338,
     339,   450,  -275,   452,   453,   454,   331,   455,   886,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   294,   295,   296,   297,   542,   324,
     277,   365,   547,   114,  1113,  1119,   342,   343,   654,   483,
    1167,   183,   183,   183,   183,  -262,  1172,  1175,  1180,   732,
    1183,   424,   114,   604,   496,  1188,  1211,   247,   605,   117,
    1215,  1220,  1223,   332,   333,   350,   575,   351,  1234,   248,
     645,   646,   613,   410,   344,   345,   249,   614,   424,   521,
     523,   525,   583,   477,   526,   527,   528,   529,   530,   531,
     532,   533,   745,   536,   218,   573,   119,   475,   250,   843,
     929,  -275,   954,  1001,   705,   251,   960,   651,   665,   568,
     424,   252,   489,   590,  -328,  -328,  -328,   352,   353,   402,
     675,  -275,   402,  -275,   350,   489,   351,  1114,  1120,  -328,
     334,   335,   336,  1168,   479,   402,   480,   687,   557,  1173,
    1176,  1181,   579,  1184,   327,   683,   657,   686,  1189,  1212,
     489,   576,   590,  1216,  1221,  1224,   330,   647,   411,   478,
     346,  1235,   648,  -463,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,   354,  1023,  -210,   117,   746,   117,  -210,
     574,   761,   476,   477,   844,   930,   489,   253,  1002,   355,
     356,   357,   358,   359,   360,   361,   819,   634,   635,   636,
     637,   820,   254,   481,   828,   482,   832,   640,   641,   829,
     642,   590,   644,   255,   183,   183,   183,   183,   652,   658,
     836,   660,   986,   992,  1008,   837,   256,   987,   590,  1009,
     916,   917,   918,   257,   117,   258,  -328,   329,   183,  -328,
    -328,   556,   557,  -328,  -328,  -328,  -328,  -328,   694,   557,
    -328,   514,   515,   516,   668,   783,   557,   259,  -328,  -328,
    -328,   797,   798,   693,   885,   557,   959,   557,   364,   698,
    1022,   557,   919,  -328,   390,   702,   811,   812,   260,   406,
     261,   953,   557,   508,   509,   262,   183,   510,   511,   184,
     185,   512,   513,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   706,   279,   280,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,   718,   719,   281,
     720,   721,   722,   723,   282,   283,   284,   724,   285,   286,
     725,   287,   726,   727,   288,   728,   729,   289,   290,   209,
     730,   731,   291,   292,   424,   733,   734,   293,   201,   737,
     365,   738,   369,   310,   739,   403,   478,   740,   741,   742,
     743,   432,   373,   377,   380,   404,   417,   419,   421,   484,
     586,   445,   448,   492,   449,   451,   563,   476,   753,   552,
    -328,   490,   539,  -328,  -328,   503,   117,  -328,  -328,  -328,
    -328,  -328,   544,   553,  -328,   559,   561,   562,   564,   763,
     566,  -459,   569,   572,   581,   795,   302,   582,   584,   585,
     594,   617,   618,  -328,  -328,  -328,   587,   650,   588,   591,
     402,   592,   593,   595,   598,   599,   600,   603,  -328,   607,
     608,   606,   609,   610,   612,   699,   611,   620,   615,   402,
     616,   806,   402,   619,   810,   622,   621,   623,   625,   624,
     626,   627,   714,   631,   628,   632,   629,   630,   747,   633,
     649,   669,   666,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,   701,   661,   667,   845,   670,   673,   674,   681,
     402,   682,   684,   715,   860,   685,   861,   689,   696,   703,
     711,   716,   717,   749,   757,   759,   756,   760,   762,   764,
     769,   787,   773,   778,   794,   796,   799,   801,   805,   800,
     402,   809,   817,   815,   855,   818,   821,   927,   402,   823,
     824,   402,   822,   839,   825,   826,   827,   830,   995,   895,
     831,   898,   833,   834,   835,  -328,   878,   838,  -328,  -328,
     840,   908,  -328,  -328,  -328,  -328,  -328,   841,   842,  -328,
     913,   914,   915,   852,   856,   857,   988,   864,   870,   865,
     866,  1068,   872,   873,   887,   876,   882,   424,   890,   920,
     891,   901,   905,   921,   909,   912,   952,   910,  1116,   939,
     943,   935,   944,   947,   948,   949,   955,   961,   964,   965,
    1017,   969,   966,   973,   970,   976,   979,   980,   498,   982,
     985,   643,   989,   990,   991,   993,   994,  1007,  1010,   402,
    1018,  1013,  1016,  1026,  1030,   691,     0,  1047,     0,  1036,
    1039,  1040,   402,  1041,  1056,  1055,   402,  1080,     0,   402,
    1069,  1077,   402,  1078,  1084,  1087,   402,  1090,  1093,  1096,
    1099,  1100,     0,  1101,  1102,     0,  1107,  1110,  1115,  1124,
    1125,   174,  1128,   996,  1132,   402,  1129,  1000,  1133,  1003,
    1134,   402,  1135,  1136,  1137,   189,   402,  1138,  1139,  1146,
     402,  1147,   198,  1154,  1155,   202,     0,   203,   204,  1161,
    1165,  1166,  1169,  1174,  1177,  1182,   402,  1185,   223,   224,
    1192,   227,  1195,  1194,  1198,     0,  1206,     0,  1199,  1210,
    1207,  1209,  1213,  1214,  1217,  1222,   751,  1225,  1228,  1229,
    1232,  1233,  1236,   402,  1237,  1239,     0,  1048,  1049,     0,
       0,     0,     0,     0,     0,  1054,     0,     0,  1057,     0,
       0,  1062,     0,     0,   276,   278,     0,     0,     0,  1073,
       0,     0,     0,     0,     0,     0,   781,     0,     0,   402,
       0,     0,   789,   792,     0,     0,     0,   402,     0,   315,
       0,   402,     0,   402,   323,     0,     0,   402,   174,     0,
     174,     0,     0,     0,   402,     0,     0,     0,     0,     0,
    1103,     0,   402,     0,     0,     0,     0,     0,  1111,     0,
     402,     0,     0,     0,  1117,     0,   402,     0,  1121,     0,
     402,     0,     0,     0,   402,     0,   118,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
       0,   323,     0,     0,     0,  1140,     0,     0,  1145,     0,
       0,   219,   880,  1148,     0,     0,  1153,   323,   372,  1156,
     323,     0,   323,     0,   240,     0,   381,     0,     0,     0,
     384,     0,     0,     0,     0,   903,     0,     0,   174,     0,
       0,  1170,   409,   402,     0,     0,     0,   415,     0,  1178,
       0,   402,     0,     0,     0,     0,     0,  1186,     0,   402,
     174,     0,   402,     0,     0,     0,     0,  1193,   207,   211,
       0,     0,  1196,     0,     0,  1197,     0,     0,   932,     0,
    1200,   937,     0,  1205,     0,   941,     0,     0,  1208,     0,
       0,     0,     0,   118,     0,   118,     0,     0,     0,     0,
       0,  1218,     0,   402,     0,     0,     0,     0,     0,     0,
       0,  1226,     0,     0,   957,  1227,     0,     0,     0,     0,
    1230,     0,     0,  1231,     0,     0,     0,     0,     0,     0,
       0,     0,   323,   487,  1238,     0,     0,     0,     0,     0,
       0,   493,     0,     0,   304,     0,     0,     0,   174,     0,
       0,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1020,   534,     0,   537,   538,     0,  1028,     0,
       0,   391,   393,     0,   323,  1034,   407,     0,   323,   548,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,     0,     0,   174,     0,     0,     0,     0,     0,   174,
       0,   174,     0,     0,     0,     0,   174,     0,     0,     0,
       0,   577,     0,     0,   580,     0,     0,  1071,     0,  1075,
       0,     0,     0,     0,   382,     0,     0,     0,   385,     0,
       0,  1082,     0,     0,     0,   401,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   639,     0,     0,     0,
       0,     0,     0,   118,     0,     0,     0,     0,     0,     0,
     653,   655,   323,   189,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1163,     0,     0,     0,     0,     0,
     174,     0,     0,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,   704,     0,     0,   707,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   401,     0,     0,
     401,     0,     0,     0,     0,     0,     0,     0,   735,   736,
       0,     0,     0,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   744,
       0,     0,     0,     0,     0,     0,   748,     0,     0,     0,
       0,   174,     0,     0,     0,   758,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   174,   174,     0,   772,     0,     0,
       0,     0,   174,   174,     0,   174,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   802,
     174,     0,   692,   174,     0,     0,     0,     0,   816,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   710,     0,   713,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   846,   848,     0,
       0,   174,     0,     0,     0,     0,     0,   174,   189,     0,
     189,   174,     0,     0,     0,     0,     0,     0,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0,   174,     0,     0,     0,     0,     0,     0,     0,   174,
       0,     0,   174,     0,     0,     0,     0,     0,     0,   894,
       0,     0,     0,   752,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   911,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   782,     0,   922,     0,     0,   928,   790,
     793,   934,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   420,     0,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,   174,     0,     0,
     174,     0,     0,   174,     0,     0,     0,   174,   401,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,   401,     0,     0,
     401,  1004,   174,     0,     0,     0,     0,   174,     0,   881,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   893,     0,     0,   897,   174,   900,     0,
       0,     0,   904,     0,     0,     0,   907,     0,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,     0,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   401,     0,
       0,   926,     0,  1063,     0,   933,   401,     0,   938,   401,
       0,     0,   942,     0,     0,     0,   549,     0,     0,     0,
     174,     0,     0,     0,     0,     0,   555,     0,   174,   560,
       0,     0,   174,     0,   174,   565,     0,   567,   174,     0,
       0,   958,   571,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,   174,   984,     0,
       0,   174,     0,     0,     0,   174,     0,     0,     0,     0,
       0,     0,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1021,
     401,     0,     0,     0,   401,  1029,     0,   401,     0,     0,
     401,  1032,  1035,     0,   401,     0,  1038,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1045,     0,
       0,     0,     0,   401,   174,     0,     0,     0,     0,   401,
    1053,     0,   174,     0,   401,     0,  1061,     0,   401,  1067,
     174,     0,     0,   174,  1072,     0,  1076,     0,     0,     0,
       0,     0,     0,     0,   401,     0,   672,     0,  1083,     0,
       0,   680,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   697,
       0,   401,     0,   700,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   401,     0,     0,
       0,     0,     0,     0,     0,   401,     0,     0,     0,   401,
       0,   401,     0,     0,     0,   401,     0,     0,     0,     0,
       0,     0,   401,  1144,     0,     0,     0,     0,     0,     0,
     401,  1152,     0,     0,     0,     0,     0,  1160,   401,     0,
       0,  1164,     0,     0,   401,     0,     0,   755,   401,     0,
       0,     0,   401,     0,     0,     0,     0,     0,     0,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     766,   768,     0,     0,     0,     0,     0,     0,   775,   777,
       0,   779,     0,     0,     0,     0,     0,   786,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1204,     0,
       0,     0,     0,     0,     0,     0,   804,     0,     0,   808,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,     0,     0,     0,     0,     0,     0,     0,   401,
       0,     0,     0,     0,     0,     0,     0,   401,     0,     0,
     401,     0,     0,     0,     0,     0,     0,   854,     0,     0,
       0,     0,     0,   859,     0,     0,     0,   863,     0,     0,
       0,     0,     0,     0,     0,     0,   868,     0,     0,     0,
       0,     0,     0,     0,     0,   875,     0,   877,     0,     0,
       0,   401,     0,     0,     0,   884,     0,     0,   889,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   946,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   951,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,     0,   968,     0,     0,   972,     0,     0,   975,
       0,     0,     0,   978,     0,     0,   981,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   997,     0,     0,     0,     0,     0,  1006,     0,
       0,     0,     0,  1012,     0,     0,     0,  1015,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1025,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1042,     0,     0,
    1046,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1079,     0,     0,     0,
       0,     0,     0,     0,  1086,     0,     0,     0,  1089,     0,
    1092,     0,     0,     0,  1095,     0,     0,     0,     0,     0,
       0,  1098,     0,     0,     0,     0,     0,     0,     0,  1104,
       0,     0,     0,     0,     0,     0,     0,  1112,     0,     0,
       0,     0,     0,  1118,     0,     0,     0,  1123,     0,     0,
       0,  1127,     0,     0,     0,     0,     0,     0,  1131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1171,     0,     0,     0,     0,     0,     0,     0,  1179,     0,
       0,     0,     0,     0,     0,     0,  1187,    -3,     1,  1191,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
    1219,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,   106,     0,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,    -6,     1,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,   106,     0,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,    -8,     1,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,   -14,   -14,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,   -14,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,   -16,   -16,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
     -16,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
     811,   812,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,     0,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,   394,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   395,   105,     0,     0,   106,   396,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,   303,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,   554,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
     570,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,   671,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,   394,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   395,   105,     0,     0,   106,   679,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,   754,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,   765,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
     767,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,   774,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,   394,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   395,   105,     0,     0,   106,   776,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,   785,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,   803,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
     807,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,   853,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,   394,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   395,   105,     0,     0,   106,   858,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,   862,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,   867,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
     874,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,   883,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,   394,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   395,   105,     0,     0,   106,   888,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,   945,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,   950,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
     962,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,   967,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,   394,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   395,   105,     0,     0,   106,   971,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,   974,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,   977,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
    1005,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,  1011,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,   394,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   395,   105,     0,     0,   106,  1014,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,  1024,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,  1085,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
    1088,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,  1091,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,   394,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   395,   105,     0,     0,   106,  1094,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,  1122,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
     394,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   395,   105,     0,     0,   106,  1126,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,   394,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   395,   105,     0,     0,   106,
    1130,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,   394,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   395,
     105,     0,     0,   106,  1190,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     1,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,   106,     0,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,   394,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   395,   105,     0,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,     0,     0,   217,     0,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   105,     0,     0,   389,
       0,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     105,     0,     0,   405,     0,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   105,     0,     0,   690,     0,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   105,     0,
       0,   750,     0,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,     0,     0,   780,     0,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   105,     0,     0,   788,
       0,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     105,     0,     0,   791,     0,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   105,     0,     0,   879,     0,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   105,     0,
       0,   902,     0,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,     0,     0,   931,     0,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   105,     0,     0,   936,
       0,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     105,     0,     0,   940,     0,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   105,     0,     0,   956,     0,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   105,     0,
       0,  1019,     0,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,     0,     0,  1027,     0,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,     0,    37,     0,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   105,     0,     0,  1033,
       0,   107,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,     0,    37,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     105,     0,     0,  1070,     0,   107,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,     0,
      37,     0,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   105,     0,     0,  1074,     0,   107,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    37,     0,    38,    39,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   105,     0,
       0,  1081,     0,   107,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,     0,    37,     0,
      38,    39,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,     0,     0,  1162,     0,   107,     0,   108,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,    23,   177,    25,     0,    27,     0,    28,    29,
     237,   238,     0,    32,   923,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,    40,    41,
      42,     0,    44,    45,    46,     0,     0,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   105,   924,     0,   925,
       0,   179,     0,   180,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,    23,   177,    25,     0,
      27,     0,    28,    29,   237,   238,     0,    32,  1050,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,    40,    41,    42,     0,    44,    45,    46,     0,
       0,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     105,  1051,     0,  1052,     0,   179,     0,   180,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,   176,    22,
      23,   177,    25,     0,    27,     0,    28,    29,   237,   238,
       0,    32,  1058,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,    40,    41,    42,     0,
      44,    45,    46,     0,     0,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   105,  1059,     0,  1060,     0,   179,
       0,   180,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,   176,    22,    23,   177,    25,     0,    27,     0,
      28,    29,   237,   238,     0,    32,  1064,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
      40,    41,    42,     0,    44,    45,    46,     0,     0,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   105,  1065,
       0,  1066,     0,   179,     0,   180,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,    23,   177,
      25,     0,    27,     0,    28,    29,   237,   238,     0,    32,
    1141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,    40,    41,    42,     0,    44,    45,
      46,     0,     0,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,  1142,     0,  1143,     0,   179,     0,   180,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,    23,   177,    25,     0,    27,     0,    28,    29,
     237,   238,     0,    32,  1149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,    40,    41,
      42,     0,    44,    45,    46,     0,     0,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   105,  1150,     0,  1151,
       0,   179,     0,   180,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,    23,   177,    25,     0,
      27,     0,    28,    29,   237,   238,     0,    32,  1157,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,    40,    41,    42,     0,    44,    45,    46,     0,
       0,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     105,  1158,     0,  1159,     0,   179,     0,   180,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,   176,    22,
      23,   177,    25,     0,    27,     0,    28,    29,   237,   238,
       0,    32,  1201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,    40,    41,    42,     0,
      44,    45,    46,     0,     0,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   105,  1202,     0,  1203,     0,   179,
       0,   180,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,   176,    22,    23,   177,    25,     0,    27,     0,
      28,    29,   237,   238,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
      40,    41,    42,     0,    44,    45,    46,     0,     0,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   105,     0,
     708,   709,     0,   179,     0,   180,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,    23,   177,
      25,     0,    27,     0,    28,    29,   237,   238,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,    40,    41,    42,     0,    44,    45,
      46,     0,     0,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,     0,     0,   239,     0,   179,     0,   180,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,    23,   177,    25,     0,    27,     0,    28,    29,
     237,   238,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,    40,    41,
      42,     0,    44,    45,    46,     0,     0,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   105,     0,     0,   392,
       0,   179,     0,   180,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,    23,   177,    25,     0,
      27,     0,    28,    29,   237,   238,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,    40,    41,    42,     0,    44,    45,    46,     0,
       0,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     105,     0,     0,   712,     0,   179,     0,   180,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,   176,    22,
      23,   177,    25,     0,    27,     0,    28,    29,   237,   238,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,    40,    41,    42,     0,
      44,    45,    46,     0,     0,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   105,     0,     0,   892,     0,   179,
       0,   180,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,   176,    22,    23,   177,    25,     0,    27,     0,
      28,    29,   237,   238,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
      40,    41,    42,     0,    44,    45,    46,     0,     0,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   105,     0,
       0,   896,     0,   179,     0,   180,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,    23,   177,
      25,     0,    27,     0,    28,    29,   237,   238,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,    40,    41,    42,     0,    44,    45,
      46,     0,     0,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,     0,     0,   899,     0,   179,     0,   180,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,    23,   177,    25,     0,    27,     0,    28,    29,
     237,   238,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,    40,    41,
      42,     0,    44,    45,    46,     0,     0,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   105,     0,     0,   906,
       0,   179,     0,   180,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,    23,   177,    25,     0,
      27,     0,    28,    29,   237,   238,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,    40,    41,    42,     0,    44,    45,    46,     0,
       0,     0,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     105,     0,     0,   983,     0,   179,     0,   180,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,    13,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,   176,    22,
      23,   177,    25,     0,    27,     0,    28,    29,   237,   238,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,    40,    41,    42,     0,
      44,    45,    46,     0,     0,     0,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   105,     0,     0,  1031,     0,   179,
       0,   180,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,    13,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,   176,    22,    23,   177,    25,     0,    27,     0,
      28,    29,   237,   238,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
      40,    41,    42,     0,    44,    45,    46,     0,     0,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   105,     0,
       0,  1037,     0,   179,     0,   180,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,    13,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,    23,   177,
      25,     0,    27,     0,    28,    29,   237,   238,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,    40,    41,    42,     0,    44,    45,
      46,     0,     0,     0,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   105,     0,     0,  1044,     0,   179,     0,   180,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,    11,    12,   209,     0,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    24,    25,     0,    27,     0,    28,    29,
     210,   178,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   100,   101,   102,   103,     0,   105,     0,     0,   106,
       0,   179,     0,   108,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      11,    12,   209,     0,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,     0,   177,    25,     0,
      27,     0,    28,    29,   210,   178,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,   100,   101,   102,   103,     0,
     105,     0,     0,   106,     0,   179,     0,   180,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    11,    12,     0,     0,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    24,    25,     0,    27,     0,    28,    29,     0,   178,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    45,    46,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,   100,
     101,   102,   103,     0,   105,     0,     0,   106,   303,   179,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,    11,    12,
     209,     0,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,     0,    24,    25,     0,    27,     0,
      28,    29,     0,   178,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,   100,   101,   102,   103,     0,   105,     0,
       0,   106,     0,   179,     0,   108,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    11,    12,     0,     0,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,     0,   177,
      25,     0,    27,     0,    28,    29,     0,   178,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,   100,   101,   102,
     103,     0,   105,   446,     0,   106,     0,   179,     0,   180,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,    11,    12,     0,     0,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,     0,   177,    25,     0,    27,     0,    28,    29,
       0,   178,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   100,   101,   102,   103,     0,   105,   518,     0,   106,
       0,   179,     0,   180,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      11,    12,     0,     0,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,     0,   177,    25,     0,
      27,     0,    28,    29,     0,   178,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,   100,   101,   102,   103,     0,
     105,     0,     0,   106,     0,   179,     0,   180,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,   520,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    11,    12,     0,     0,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,   176,    22,
       0,   177,    25,     0,    27,     0,    28,    29,     0,   178,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    45,    46,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,   100,
     101,   102,   103,     0,   105,     0,     0,   106,     0,   179,
       0,   180,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,   522,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,    11,    12,
       0,     0,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,   176,    22,     0,   177,    25,     0,    27,     0,
      28,    29,     0,   178,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,   100,   101,   102,   103,     0,   105,     0,
     524,   106,     0,   179,     0,   180,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    11,    12,     0,     0,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,     0,   177,
      25,     0,    27,     0,    28,    29,     0,   178,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,   100,   101,   102,
     103,     0,   105,     0,     0,   106,     0,   179,     0,   180,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,   535,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,    11,    12,     0,     0,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,     0,   177,    25,     0,    27,     0,    28,    29,
       0,   178,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   100,   101,   102,   103,     0,   105,   550,     0,   106,
       0,   179,     0,   180,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      11,    12,     0,     0,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,     0,   177,    25,     0,
      27,     0,    28,    29,     0,   178,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,   100,   101,   102,   103,     0,
     105,     0,     0,   106,     0,   179,     0,   180,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    11,    12,     0,     0,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
       0,    24,    25,     0,    27,     0,    28,    29,     0,   206,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    45,    46,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,   100,
     101,   102,   103,     0,   105,     0,     0,   106,     0,   179,
       0,   108,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,    11,    12,
       0,     0,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,   176,    22,     0,   177,    25,     0,    27,     0,
      28,    29,     0,   178,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,   100,   101,   102,   103,     0,   221,     0,
       0,   106,     0,   179,     0,   180,     0,   109,   110,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    11,    12,     0,     0,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,     0,   177,
      25,     0,    27,     0,    28,    29,     0,   178,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,   100,   101,   102,
     103,     0,   229,     0,     0,   106,     0,   179,     0,   180,
       0,   109,   110,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,    11,    12,     0,     0,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,     0,   177,    25,     0,    27,     0,    28,    29,
       0,   178,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   298,   299,   300,   301,     0,   105,     0,     0,   106,
       0,   179,     0,   180,     0,   109,   110,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      11,    12,     0,     0,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,     0,    24,    25,     0,
      27,     0,    28,    29,     0,   178,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,   100,   101,   102,   103,     0,
     105,     0,     0,   106,     0,   179,     0,   108,     0,   109,
     110,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    11,    12,     0,     0,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,   176,    22,
       0,   177,    25,     0,    27,     0,    28,    29,     0,   206,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    45,    46,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,   100,
     101,   102,   103,     0,   105,     0,     0,   106,     0,   179,
       0,   180,     0,   109,   110,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,    11,    12,
       0,     0,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,   176,    22,     0,   177,    25,     0,    27,     0,
      28,    29,     0,   178,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,   100,   101,   102,   103,     0,   105,     0,
       0,   106,     0,   179,     0,   180,   504,   109,     0,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    11,    12,     0,     0,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,     0,   177,
      25,     0,    27,     0,    28,    29,     0,   178,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,   100,   101,   102,
     103,     0,   105,     0,     0,   106,     0,   179,     0,   180,
     506,   109,     0,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,    11,    12,     0,     0,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,     0,   177,    25,     0,    27,     0,    28,    29,
       0,   178,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   100,   101,   102,   103,     0,   105,     0,     0,   106,
       0,   179,     0,   180,     0,   109,     0,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      11,    12,     0,     0,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,     0,   177,    25,     0,
      27,     0,    28,    29,     0,   178,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,   100,   101,   102,   103,     0,
     105,   471,     0,   106,     0,   179,     0,   180,     0,   109,
       0,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    11,    12,     0,     0,     0,    15,
       0,     0,     0,    16,    17,    18,    19,    20,   176,    22,
       0,   177,    25,     0,    27,     0,    28,    29,     0,   178,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    45,    46,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,   100,
     101,   102,   103,     0,   105,   472,     0,   106,     0,   179,
       0,   180,     0,   109,     0,     0,     0,   111,   112,     0,
       0,     0,     0,     0,   113,     0,     0,   114,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,    11,    12,
       0,     0,     0,    15,     0,     0,     0,    16,    17,    18,
      19,    20,   176,    22,     0,   177,    25,     0,    27,     0,
      28,    29,     0,   178,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,   100,   101,   102,   103,     0,   105,   473,
       0,   106,     0,   179,     0,   180,     0,   109,     0,     0,
       0,   111,   112,     0,     0,     0,     0,     0,   113,     0,
       0,   114,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    11,    12,     0,     0,     0,    15,     0,     0,
       0,    16,    17,    18,    19,    20,   176,    22,     0,   177,
      25,     0,    27,     0,    28,    29,     0,   178,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,   100,   101,   102,
     103,     0,   105,   474,     0,   106,     0,   179,     0,   180,
       0,   109,     0,     0,     0,   111,   112,     0,     0,     0,
       0,     0,   113,     0,     0,   114,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,    11,    12,     0,     0,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
     176,    22,     0,   177,    25,     0,    27,     0,    28,    29,
       0,   178,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   100,   101,   102,   103,     0,   105,     0,     0,   106,
       0,   179,     0,   180,     0,   109,     0,     0,     0,   111,
     112,     0,     0,     0,     0,     0,   113,     0,     0,   114,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      11,    12,     0,     0,     0,    15,     0,     0,     0,    16,
      17,    18,    19,    20,   176,    22,     0,   177,    25,     0,
      27,     0,    28,    29,     0,   178,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,   100,   101,   102,   103,     0,
     676,     0,     0,   106,     0,   179,     0,   180,     0,   109,
       0,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      10,    14,    36,    13,   214,    15,    16,    17,    18,    19,
      20,   110,    10,    23,    11,    12,   321,    10,    10,    10,
      30,    31,    34,   117,    34,   119,     3,    37,   113,     0,
      10,    41,    42,   554,    34,    45,    10,     0,   559,    49,
      50,    51,    52,   348,    10,   331,   332,   333,    10,   335,
     336,    10,     3,   543,    15,     3,     4,     5,     6,     7,
       8,     9,    10,    10,   980,   139,    10,    10,    10,   139,
      10,    49,   543,   153,   133,   380,   132,    10,    41,   139,
     154,   175,    39,   142,   154,    41,   100,   101,   102,   103,
      53,    54,   134,   135,   154,   105,   106,   139,    10,   109,
      41,    15,   133,   100,   101,   102,   103,    15,    53,    54,
     141,   196,    15,   134,   199,   133,   201,     4,   134,   134,
     141,   133,     3,   139,   139,   134,  1042,   135,   134,   134,
     139,   139,    41,   139,   139,   133,    50,   148,   149,   133,
     133,   153,   136,   134,   142,   133,   117,    10,   119,   142,
     142,   142,   133,   153,   134,   132,   134,   135,   156,   133,
     133,   153,   142,   156,   156,   156,    10,   133,   689,   132,
       0,   134,   134,   134,   137,   134,   156,   187,   134,   136,
     142,   132,   156,   142,   133,   133,   676,   134,     3,   133,
     156,   133,   137,   134,   156,   142,   206,   156,   146,   147,
     210,   411,   142,   213,   175,   676,    34,   217,   156,   156,
     153,   221,   156,   156,   156,   225,   156,   503,   504,   229,
     506,   135,   134,   156,   234,   134,   311,   237,   238,   239,
     142,   330,   135,   327,   133,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   156,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,    49,   268,   146,
     147,   271,    34,   273,   274,   275,    19,   277,   789,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   298,   299,   300,   301,   373,   136,
     153,    15,   377,   156,    41,    41,   150,   151,   142,   309,
      41,   298,   299,   300,   301,   133,    41,    41,    41,   614,
      41,   321,   156,   134,   324,    41,    41,   133,   139,     0,
      41,    41,    41,    76,    77,   153,    50,   155,    41,   133,
      47,    48,   134,    47,    66,    67,   133,   139,   348,   349,
     350,   351,   134,   135,   354,   355,   356,   357,   358,   359,
     360,   361,    50,   363,    35,    47,   327,    49,   133,    50,
      50,   133,   883,    50,   574,   133,   887,   134,   134,   403,
     380,   133,   139,   139,    19,    20,    21,    13,    14,   389,
     134,   153,   392,   155,   153,   139,   155,   134,   134,    34,
     143,   144,   145,   134,   137,   405,   139,    42,    43,   134,
     134,   134,   412,   134,   132,   134,   491,   134,   134,   134,
     139,   135,   139,   134,   134,   134,    20,   134,   132,   135,
     152,   134,   139,   139,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   141,   955,   135,   117,   135,   119,   139,
     132,   134,   134,   135,   135,   135,   139,   133,   135,    69,
      70,    71,    72,    73,    74,    75,   134,   471,   472,   473,
     474,   139,   133,   137,   134,   139,   134,   477,   478,   139,
     480,   139,   482,   133,   471,   472,   473,   474,   488,   492,
     134,   495,   134,   134,   134,   139,   133,   139,   139,   139,
      95,    96,    97,   133,   175,   133,   141,    21,   495,   144,
     145,    42,    43,   148,   149,   150,   151,   152,    42,    43,
     155,   344,   345,   346,   524,    42,    43,   133,    19,    20,
      21,   134,   135,   557,    42,    43,    42,    43,    15,   563,
      42,    43,   837,    34,   215,   569,    53,    54,   133,   220,
     133,    42,    43,   338,   339,   133,   543,   340,   341,    11,
      12,   342,   343,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   575,   133,   133,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   587,   588,   133,
     590,   591,   592,   593,   133,   133,   133,   597,   133,   133,
     600,   133,   602,   603,   133,   605,   606,   133,   133,    15,
     610,   611,   133,   133,   614,   615,   616,   133,   133,   619,
      15,   621,   132,   136,   624,    46,   135,   627,   628,   629,
     630,   134,   133,   133,   133,   132,   132,   132,   132,     3,
      64,   134,   134,   141,   134,   134,    46,   134,   648,   134,
     141,   139,   136,   144,   145,   141,   327,   148,   149,   150,
     151,   152,   136,   134,   155,   132,   132,   132,   137,   669,
     132,   139,    46,   132,   134,   699,   676,   134,   134,   137,
     134,   154,   154,    19,    20,    21,   139,   136,   139,   139,
     690,   139,   139,   134,   134,   134,   139,   139,    34,   134,
     134,   139,   134,   139,   134,    46,   139,   134,   139,   709,
     139,   711,   712,   139,   714,   134,   139,   134,   134,   139,
     134,   139,    50,   134,   139,   134,   139,   139,    49,   134,
     137,   135,   154,    69,    70,    71,    72,    73,    74,    75,
      76,    77,   132,   137,   154,   745,   154,   136,   136,   136,
     750,   136,   136,   136,   757,   137,   759,   137,   137,   137,
     132,    64,   133,     3,   141,   141,   136,   136,   154,   137,
     136,   132,   137,   136,   132,   132,   132,    50,   132,   134,
     780,   132,   134,   133,   132,   134,   139,    50,   788,   134,
     134,   791,   139,   139,   134,   134,   134,   134,    50,   799,
     134,   801,   134,   134,   134,   141,   132,   134,   144,   145,
     134,   811,   148,   149,   150,   151,   152,   134,   134,   155,
     820,   821,   822,   134,   134,   137,   139,   136,   134,   137,
     137,    50,   137,   137,   132,   137,   137,   837,   132,   839,
     132,   137,   137,   843,   135,   134,   132,   137,    50,   137,
     137,   851,   137,   137,   137,   137,   137,   137,   132,   134,
     137,   132,   134,   132,   134,   132,   132,   135,   329,   134,
     134,   480,   134,   134,   134,   134,   134,   132,   134,   879,
     137,   132,   132,   132,   137,   556,    -1,   132,    -1,   137,
     137,   137,   892,   137,   137,   134,   896,   132,    -1,   899,
     137,   137,   902,   137,   137,   132,   906,   132,   132,   132,
     132,   137,    -1,   134,   134,    -1,   134,   134,   134,   132,
     134,     0,   132,   923,   132,   925,   137,   927,   137,   929,
     137,   931,   137,   137,   137,    14,   936,   134,   137,   134,
     940,   137,    21,   134,   137,    24,    -1,    26,    27,   137,
     137,   137,   134,   134,   134,   134,   956,   134,    37,    38,
     132,    40,   137,   134,   134,    -1,   134,    -1,   137,   134,
     137,   137,   134,   134,   134,   134,   647,   134,   134,   137,
     134,   134,   134,   983,   134,   134,    -1,   987,   988,    -1,
      -1,    -1,    -1,    -1,    -1,   995,    -1,    -1,   998,    -1,
      -1,  1001,    -1,    -1,    83,    84,    -1,    -1,    -1,  1009,
      -1,    -1,    -1,    -1,    -1,    -1,   687,    -1,    -1,  1019,
      -1,    -1,   693,   694,    -1,    -1,    -1,  1027,    -1,   108,
      -1,  1031,    -1,  1033,   113,    -1,    -1,  1037,   117,    -1,
     119,    -1,    -1,    -1,  1044,    -1,    -1,    -1,    -1,    -1,
    1050,    -1,  1052,    -1,    -1,    -1,    -1,    -1,  1058,    -1,
    1060,    -1,    -1,    -1,  1064,    -1,  1066,    -1,  1068,    -1,
    1070,    -1,    -1,    -1,  1074,    -1,     0,    -1,    -1,    -1,
      -1,  1081,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,  1105,    -1,    -1,  1108,    -1,
      -1,    35,   783,  1113,    -1,    -1,  1116,   196,   197,  1119,
     199,    -1,   201,    -1,    48,    -1,   205,    -1,    -1,    -1,
     209,    -1,    -1,    -1,    -1,   806,    -1,    -1,   217,    -1,
      -1,  1141,   221,  1143,    -1,    -1,    -1,   226,    -1,  1149,
      -1,  1151,    -1,    -1,    -1,    -1,    -1,  1157,    -1,  1159,
     239,    -1,  1162,    -1,    -1,    -1,    -1,  1167,    30,    31,
      -1,    -1,  1172,    -1,    -1,  1175,    -1,    -1,   849,    -1,
    1180,   852,    -1,  1183,    -1,   856,    -1,    -1,  1188,    -1,
      -1,    -1,    -1,   117,    -1,   119,    -1,    -1,    -1,    -1,
      -1,  1201,    -1,  1203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1211,    -1,    -1,   885,  1215,    -1,    -1,    -1,    -1,
    1220,    -1,    -1,  1223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,  1234,    -1,    -1,    -1,    -1,    -1,
      -1,   320,    -1,    -1,   106,    -1,    -1,    -1,   327,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   953,   362,    -1,   364,   365,    -1,   959,    -1,
      -1,   215,   216,    -1,   373,   966,   220,    -1,   377,   378,
     379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     389,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,   398,
      -1,   400,    -1,    -1,    -1,    -1,   405,    -1,    -1,    -1,
      -1,   410,    -1,    -1,   413,    -1,    -1,  1008,    -1,  1010,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,    -1,
      -1,  1022,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,    -1,
     489,   490,   491,   492,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1125,    -1,    -1,    -1,    -1,    -1,
     539,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   562,    -1,    -1,    -1,   566,    -1,    -1,
      -1,    -1,    -1,    -1,   573,    -1,    -1,   576,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,    -1,    -1,
     392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   617,   618,
      -1,    -1,    -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,
      -1,    -1,    -1,    -1,    -1,    -1,   645,    -1,    -1,    -1,
      -1,   650,    -1,    -1,    -1,   654,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   673,   674,    -1,   676,    -1,    -1,
      -1,    -1,   681,   682,    -1,   684,    -1,    -1,    -1,    -1,
      -1,   690,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   708,
     709,    -1,   556,   712,    -1,    -1,    -1,    -1,   717,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   577,    -1,   579,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   746,   747,    -1,
      -1,   750,    -1,    -1,    -1,    -1,    -1,   756,   757,    -1,
     759,   760,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     769,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   778,
      -1,   780,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   788,
      -1,    -1,   791,    -1,    -1,    -1,    -1,    -1,    -1,   798,
      -1,    -1,    -1,   647,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   815,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   687,    -1,   844,    -1,    -1,   847,   693,
     694,   850,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   864,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
     879,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   892,    -1,    -1,    -1,   896,    -1,    -1,
     899,    -1,    -1,   902,    -1,    -1,    -1,   906,   690,    -1,
     909,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   925,   709,    -1,    -1,
     712,   930,   931,    -1,    -1,    -1,    -1,   936,    -1,   783,
      -1,   940,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   797,    -1,    -1,   800,   956,   802,    -1,
      -1,    -1,   806,    -1,    -1,    -1,   810,    -1,   750,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   980,    -1,    -1,   983,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   780,    -1,
      -1,   845,    -1,  1002,    -1,   849,   788,    -1,   852,   791,
      -1,    -1,   856,    -1,    -1,    -1,   379,    -1,    -1,    -1,
    1019,    -1,    -1,    -1,    -1,    -1,   389,    -1,  1027,   392,
      -1,    -1,  1031,    -1,  1033,   398,    -1,   400,  1037,    -1,
      -1,   885,   405,    -1,    -1,  1044,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1052,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1060,    -1,    -1,    -1,    -1,    -1,  1066,   912,    -1,
      -1,  1070,    -1,    -1,    -1,  1074,    -1,    -1,    -1,    -1,
      -1,    -1,  1081,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   879,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   953,
     892,    -1,    -1,    -1,   896,   959,    -1,   899,    -1,    -1,
     902,   965,   966,    -1,   906,    -1,   970,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   982,    -1,
      -1,    -1,    -1,   925,  1143,    -1,    -1,    -1,    -1,   931,
     994,    -1,  1151,    -1,   936,    -1,  1000,    -1,   940,  1003,
    1159,    -1,    -1,  1162,  1008,    -1,  1010,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   956,    -1,   539,    -1,  1022,    -1,
      -1,   544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   562,
      -1,   983,    -1,   566,  1203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1019,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1027,    -1,    -1,    -1,  1031,
      -1,  1033,    -1,    -1,    -1,  1037,    -1,    -1,    -1,    -1,
      -1,    -1,  1044,  1107,    -1,    -1,    -1,    -1,    -1,    -1,
    1052,  1115,    -1,    -1,    -1,    -1,    -1,  1121,  1060,    -1,
      -1,  1125,    -1,    -1,  1066,    -1,    -1,   650,  1070,    -1,
      -1,    -1,  1074,    -1,    -1,    -1,    -1,    -1,    -1,  1081,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     673,   674,    -1,    -1,    -1,    -1,    -1,    -1,   681,   682,
      -1,   684,    -1,    -1,    -1,    -1,    -1,   690,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   709,    -1,    -1,   712,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1159,    -1,    -1,
    1162,    -1,    -1,    -1,    -1,    -1,    -1,   750,    -1,    -1,
      -1,    -1,    -1,   756,    -1,    -1,    -1,   760,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   769,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   778,    -1,   780,    -1,    -1,
      -1,  1203,    -1,    -1,    -1,   788,    -1,    -1,   791,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   864,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   879,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   892,
      -1,    -1,    -1,   896,    -1,    -1,   899,    -1,    -1,   902,
      -1,    -1,    -1,   906,    -1,    -1,   909,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   925,    -1,    -1,    -1,    -1,    -1,   931,    -1,
      -1,    -1,    -1,   936,    -1,    -1,    -1,   940,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   956,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   980,    -1,    -1,
     983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1019,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1027,    -1,    -1,    -1,  1031,    -1,
    1033,    -1,    -1,    -1,  1037,    -1,    -1,    -1,    -1,    -1,
      -1,  1044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,
      -1,    -1,    -1,  1066,    -1,    -1,    -1,  1070,    -1,    -1,
      -1,  1074,    -1,    -1,    -1,    -1,    -1,    -1,  1081,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1159,     0,     1,  1162,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
    1203,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,     0,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,     0,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
       1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,     1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,     1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,     1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,     1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56,
      57,    -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,   134,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    55,    56,    57,    -1,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,   134,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,   134,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56,
      57,    -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,   134,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    55,    56,    57,    -1,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,   134,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56,
      57,    -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    55,    56,    57,    -1,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56,
      57,    -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    55,    56,    57,    -1,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    14,    15,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,   154,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,   154,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,   154,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,   143,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
     143,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,   143,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
     141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,    -1,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,   134,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,   131,    -1,   133,   134,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,    -1,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,    -1,   133,   134,
      -1,   136,    -1,   138,    -1,   140,    -1,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,   140,
      -1,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,    -1,   142,    -1,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156
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
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     222,   224,   225,   226,   227,   132,    27,    30,    38,   138,
     140,   181,   227,   194,   200,   200,   181,   133,   214,   227,
     181,   181,   181,   181,   181,   181,   133,   142,   227,   153,
     181,   133,   227,   227,   227,    15,    38,   177,   181,    15,
      37,   177,   181,   133,   133,   176,   181,   136,   161,   162,
     176,   133,   181,   227,   227,   133,   133,   227,   181,   133,
     181,     3,   132,   181,   133,     3,   132,    37,    38,   136,
     162,   181,   181,   181,   181,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   153,   227,   153,   227,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   198,   198,   198,   198,   128,   129,
     130,   131,   181,   137,   177,   181,   220,   221,   223,   133,
     136,   133,   142,   179,   180,   227,   181,   185,     3,     3,
     142,   153,   179,   227,   136,     0,   159,   132,   159,    21,
      20,    19,    76,    77,   143,   144,   145,     4,   146,   147,
     148,   149,   150,   151,    66,    67,   152,    34,   133,   153,
     153,   155,    13,    14,   141,    69,    70,    71,    72,    73,
      74,    75,    34,   153,    15,    15,   135,   159,   181,   132,
     134,   179,   227,   133,   179,   134,   179,   133,    39,   136,
     133,   227,   177,   181,   227,   177,   181,   181,   182,   136,
     161,   162,   136,   162,     1,   132,   137,   160,   161,   162,
     163,   177,   181,    46,   132,   136,   161,   162,   181,   227,
      47,   132,    50,   135,   181,   227,   181,   132,   181,   132,
     160,   132,   181,   181,   181,   219,   181,   181,   181,   181,
     181,   181,   134,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   134,   134,   181,   134,   134,
     181,   134,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   134,   134,   134,   134,    49,   134,   135,   135,   137,
     139,   137,   139,   181,     3,   134,   179,   227,   135,   139,
     139,   133,   141,   227,   219,   154,   181,   159,   184,   185,
     187,   187,   187,   141,   141,   187,   141,   187,   189,   189,
     190,   190,   191,   191,   192,   192,   192,   227,   134,   219,
     154,   181,   154,   181,   135,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   227,   154,   181,   227,   227,   136,
     134,   134,   179,   154,   136,   134,   134,   179,   227,   160,
     134,   219,   134,   134,   137,   160,    42,    43,   166,   132,
     160,   132,   132,    46,   137,   160,   132,   160,   176,    46,
     137,   160,   132,    47,   132,    50,   135,   227,   182,   181,
     227,   134,   134,   134,   134,   137,    64,   139,   139,   134,
     139,   139,   139,   139,   134,   134,   134,   139,   134,   134,
     139,   134,   139,   139,   134,   139,   139,   134,   134,   134,
     139,   139,   134,   134,   139,   139,   139,   154,   154,   139,
     134,   139,   134,   134,   139,   134,   134,   139,   139,   139,
     139,   134,   134,   134,   198,   198,   198,   198,   133,   227,
     181,   181,   181,   221,   181,    47,    48,   134,   139,   137,
     136,   134,   181,   227,   142,   227,   134,   179,   214,   154,
     198,   137,   187,   187,   187,   134,   154,   154,   181,   135,
     154,   137,   160,   136,   136,   134,   133,   206,   215,   137,
     160,   136,   136,   134,   136,   137,   134,    42,   166,   137,
     136,   161,   162,   176,    42,   166,   137,   160,   176,    46,
     160,   132,   176,   137,   227,   182,   181,   227,   135,   136,
     162,   132,   136,   162,    50,   136,    64,   133,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   219,   181,   181,   227,   227,   181,   181,   181,
     181,   181,   181,   181,   227,    50,   135,    49,   227,     3,
     136,   161,   162,   181,   137,   160,   136,   141,   227,   141,
     136,   134,   154,   181,   137,   137,   160,   137,   160,   136,
     206,   215,   227,   137,   137,   160,   137,   160,   136,   160,
     136,   161,   162,    42,   166,   137,   160,   132,   136,   161,
     162,   136,   161,   162,   132,   176,   132,   134,   135,   132,
     134,    50,   227,   137,   160,   132,   181,   137,   160,   132,
     181,    53,    54,   137,   173,   133,   227,   134,   134,   134,
     139,   139,   139,   134,   134,   134,   134,   134,   134,   139,
     134,   134,   134,   134,   134,   134,   134,   139,   134,   139,
     134,   134,   134,    50,   135,   181,   227,   133,   227,   134,
     135,   139,   134,   137,   160,   132,   134,   137,   137,   160,
     214,   214,   137,   160,   136,   137,   137,   137,   160,   134,
     134,   134,   137,   137,   137,   160,   137,   160,   132,   136,
     161,   162,   137,   137,   160,    42,   166,   132,   137,   160,
     132,   132,   136,   162,   227,   181,   136,   162,   181,   136,
     162,   137,   136,   161,   162,   137,   136,   162,   181,   135,
     137,   227,   134,   181,   181,   181,    95,    96,    97,   219,
     181,   181,   227,    41,   134,   136,   162,    50,   227,    50,
     135,   136,   161,   162,   227,   181,   136,   161,   162,   137,
     136,   161,   162,   137,   137,   137,   160,   137,   137,   137,
     137,   160,   132,    42,   166,   137,   136,   161,   162,    42,
     166,   137,   137,   160,   132,   134,   134,   137,   160,   132,
     134,   137,   160,   132,   137,   160,   132,   137,   160,   132,
     135,   160,   134,   136,   162,   134,   134,   139,   139,   134,
     134,   134,   134,   134,   134,    50,   181,   160,    41,   134,
     181,    50,   135,   181,   227,   137,   160,   132,   134,   139,
     134,   137,   160,   132,   137,   160,   132,   137,   137,   136,
     161,   162,    42,   166,   137,   160,   132,   136,   161,   162,
     137,   136,   162,   136,   161,   162,   137,   136,   162,   137,
     137,   137,   160,   173,   136,   162,   160,   132,   181,   181,
      41,   134,   136,   162,   181,   134,   137,   181,    41,   134,
     136,   162,   181,   227,    41,   134,   136,   162,    50,   137,
     136,   161,   162,   181,   136,   161,   162,   137,   137,   160,
     132,   136,   161,   162,   137,   137,   160,   132,   137,   160,
     132,   137,   160,   132,   137,   160,   132,   173,   160,   132,
     137,   134,   134,   181,   160,    41,   134,   134,    41,   134,
     134,   181,   160,    41,   134,   134,    50,   181,   160,    41,
     134,   181,   137,   160,   132,   134,   137,   160,   132,   137,
     137,   160,   132,   137,   137,   137,   137,   137,   134,   137,
     181,    41,   134,   136,   162,   181,   134,   137,   181,    41,
     134,   136,   162,   181,   134,   137,   181,    41,   134,   136,
     162,   137,   136,   161,   162,   137,   137,    41,   134,   134,
     181,   160,    41,   134,   134,    41,   134,   134,   181,   160,
      41,   134,   134,    41,   134,   134,   181,   160,    41,   134,
     137,   160,   132,   181,   134,   137,   181,   181,   134,   137,
     181,    41,   134,   136,   162,   181,   134,   137,   181,   137,
     134,    41,   134,   134,   134,    41,   134,   134,   181,   160,
      41,   134,   134,    41,   134,   134,   181,   181,   134,   137,
     181,   181,   134,   134,    41,   134,   134,   134,   181,   134
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
     215,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   217,   217,   217,   217,   218,   218,   218,   218,
     218,   218,   219,   219,   219,   220,   220,   220,   221,   221,
     222,   222,   223,   223,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   226,   226,   226,   226,   227,   227
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
       1,     6,     7,     6,     5,     3,     6,     7,     6,     5,
       3,     4,     6,     7,     6,     5,     5,     5,     7,     7,
       7,     4,     2,     3,     1,     3,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     4,     3,     4,     4,     3,
       3,     3,     1,     1,     6,     4,     4,     8,     6,     6,
       6,     4,     4,     6,     3,     3,     3,     3,     1,     4
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
#line 89 "lshParser.y" /* yacc.c:684  */
      { fprintf (yyoutput, "%s", *((*yyvaluep).str)); }
#line 5691 "lshParser.c" /* yacc.c:684  */
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
#line 96 "lshParser.y" /* yacc.c:1646  */
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
#line 6331 "lshParser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "lshParser.y" /* yacc.c:1646  */
    { ;}
#line 6337 "lshParser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 115 "lshParser.y" /* yacc.c:1646  */
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
#line 6352 "lshParser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 125 "lshParser.y" /* yacc.c:1646  */
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
#line 6367 "lshParser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 135 "lshParser.y" /* yacc.c:1646  */
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
#line 6382 "lshParser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 145 "lshParser.y" /* yacc.c:1646  */
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
#line 6397 "lshParser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 155 "lshParser.y" /* yacc.c:1646  */
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
#line 6412 "lshParser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 165 "lshParser.y" /* yacc.c:1646  */
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
#line 6427 "lshParser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 175 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6433 "lshParser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 176 "lshParser.y" /* yacc.c:1646  */
    { 
         (yyval.data) = new noNode ();
      }
#line 6441 "lshParser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 182 "lshParser.y" /* yacc.c:1646  */
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
#line 6456 "lshParser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "lshParser.y" /* yacc.c:1646  */
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
#line 6471 "lshParser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 202 "lshParser.y" /* yacc.c:1646  */
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
#line 6486 "lshParser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 212 "lshParser.y" /* yacc.c:1646  */
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
#line 6501 "lshParser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 222 "lshParser.y" /* yacc.c:1646  */
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
#line 6516 "lshParser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 232 "lshParser.y" /* yacc.c:1646  */
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
#line 6531 "lshParser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 242 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6537 "lshParser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "lshParser.y" /* yacc.c:1646  */
    {(yyval.data) = new noNode ();}
#line 6543 "lshParser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 248 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6549 "lshParser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 249 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 6555 "lshParser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 250 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 6561 "lshParser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 251 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6567 "lshParser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 252 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6573 "lshParser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 253 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6579 "lshParser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 254 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6585 "lshParser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 255 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6591 "lshParser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 256 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6597 "lshParser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 257 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6603 "lshParser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 261 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6609 "lshParser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 262 "lshParser.y" /* yacc.c:1646  */
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
#line 6624 "lshParser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 272 "lshParser.y" /* yacc.c:1646  */
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
#line 6639 "lshParser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 282 "lshParser.y" /* yacc.c:1646  */
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
#line 6654 "lshParser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 292 "lshParser.y" /* yacc.c:1646  */
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
#line 6669 "lshParser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 302 "lshParser.y" /* yacc.c:1646  */
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
#line 6684 "lshParser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 312 "lshParser.y" /* yacc.c:1646  */
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
#line 6699 "lshParser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 322 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new returnNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("returnNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6713 "lshParser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 331 "lshParser.y" /* yacc.c:1646  */
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
#line 6728 "lshParser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 341 "lshParser.y" /* yacc.c:1646  */
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
#line 6743 "lshParser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 351 "lshParser.y" /* yacc.c:1646  */
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
#line 6758 "lshParser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 361 "lshParser.y" /* yacc.c:1646  */
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
#line 6773 "lshParser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 371 "lshParser.y" /* yacc.c:1646  */
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
#line 6795 "lshParser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 388 "lshParser.y" /* yacc.c:1646  */
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
#line 6817 "lshParser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 405 "lshParser.y" /* yacc.c:1646  */
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
#line 6839 "lshParser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 422 "lshParser.y" /* yacc.c:1646  */
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
#line 6861 "lshParser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 439 "lshParser.y" /* yacc.c:1646  */
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
#line 6876 "lshParser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 449 "lshParser.y" /* yacc.c:1646  */
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
#line 6891 "lshParser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 459 "lshParser.y" /* yacc.c:1646  */
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
#line 6906 "lshParser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 469 "lshParser.y" /* yacc.c:1646  */
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
#line 6921 "lshParser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 479 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new exitNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("exitNode", "stmt", NULL,0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6935 "lshParser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 488 "lshParser.y" /* yacc.c:1646  */
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
#line 6950 "lshParser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 501 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].idnode); }
#line 6956 "lshParser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 505 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6962 "lshParser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 506 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6968 "lshParser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 508 "lshParser.y" /* yacc.c:1646  */
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
#line 6983 "lshParser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 521 "lshParser.y" /* yacc.c:1646  */
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
#line 6999 "lshParser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 532 "lshParser.y" /* yacc.c:1646  */
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
#line 7015 "lshParser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 543 "lshParser.y" /* yacc.c:1646  */
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
#line 7038 "lshParser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 561 "lshParser.y" /* yacc.c:1646  */
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
#line 7054 "lshParser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 572 "lshParser.y" /* yacc.c:1646  */
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
#line 7070 "lshParser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 583 "lshParser.y" /* yacc.c:1646  */
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
#line 7086 "lshParser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 594 "lshParser.y" /* yacc.c:1646  */
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
#line 7102 "lshParser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 605 "lshParser.y" /* yacc.c:1646  */
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
#line 7125 "lshParser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 623 "lshParser.y" /* yacc.c:1646  */
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
#line 7148 "lshParser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 641 "lshParser.y" /* yacc.c:1646  */
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
#line 7164 "lshParser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 652 "lshParser.y" /* yacc.c:1646  */
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
#line 7180 "lshParser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 663 "lshParser.y" /* yacc.c:1646  */
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
#line 7203 "lshParser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 681 "lshParser.y" /* yacc.c:1646  */
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
#line 7226 "lshParser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 699 "lshParser.y" /* yacc.c:1646  */
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
#line 7256 "lshParser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 724 "lshParser.y" /* yacc.c:1646  */
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
#line 7279 "lshParser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 742 "lshParser.y" /* yacc.c:1646  */
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
#line 7295 "lshParser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 753 "lshParser.y" /* yacc.c:1646  */
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
#line 7311 "lshParser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 764 "lshParser.y" /* yacc.c:1646  */
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
#line 7334 "lshParser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 782 "lshParser.y" /* yacc.c:1646  */
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
#line 7350 "lshParser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 793 "lshParser.y" /* yacc.c:1646  */
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
#line 7366 "lshParser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 804 "lshParser.y" /* yacc.c:1646  */
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
#line 7382 "lshParser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 815 "lshParser.y" /* yacc.c:1646  */
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
#line 7406 "lshParser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 834 "lshParser.y" /* yacc.c:1646  */
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
#line 7422 "lshParser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 848 "lshParser.y" /* yacc.c:1646  */
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
#line 7438 "lshParser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 859 "lshParser.y" /* yacc.c:1646  */
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
#line 7454 "lshParser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 870 "lshParser.y" /* yacc.c:1646  */
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
#line 7477 "lshParser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 888 "lshParser.y" /* yacc.c:1646  */
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
#line 7493 "lshParser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 899 "lshParser.y" /* yacc.c:1646  */
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
#line 7509 "lshParser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 910 "lshParser.y" /* yacc.c:1646  */
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
#line 7525 "lshParser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 921 "lshParser.y" /* yacc.c:1646  */
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
#line 7541 "lshParser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 932 "lshParser.y" /* yacc.c:1646  */
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
#line 7564 "lshParser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 950 "lshParser.y" /* yacc.c:1646  */
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
#line 7587 "lshParser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 968 "lshParser.y" /* yacc.c:1646  */
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
#line 7603 "lshParser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 979 "lshParser.y" /* yacc.c:1646  */
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
#line 7619 "lshParser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 990 "lshParser.y" /* yacc.c:1646  */
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
#line 7642 "lshParser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1008 "lshParser.y" /* yacc.c:1646  */
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
#line 7665 "lshParser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1026 "lshParser.y" /* yacc.c:1646  */
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
#line 7695 "lshParser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1051 "lshParser.y" /* yacc.c:1646  */
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
#line 7718 "lshParser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1069 "lshParser.y" /* yacc.c:1646  */
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
#line 7734 "lshParser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1080 "lshParser.y" /* yacc.c:1646  */
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
#line 7750 "lshParser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1091 "lshParser.y" /* yacc.c:1646  */
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
#line 7773 "lshParser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1109 "lshParser.y" /* yacc.c:1646  */
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
#line 7789 "lshParser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1120 "lshParser.y" /* yacc.c:1646  */
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
#line 7805 "lshParser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1131 "lshParser.y" /* yacc.c:1646  */
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
#line 7821 "lshParser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1142 "lshParser.y" /* yacc.c:1646  */
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
#line 7844 "lshParser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1160 "lshParser.y" /* yacc.c:1646  */
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
#line 7860 "lshParser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1174 "lshParser.y" /* yacc.c:1646  */
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
#line 7876 "lshParser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1185 "lshParser.y" /* yacc.c:1646  */
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
#line 7899 "lshParser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1206 "lshParser.y" /* yacc.c:1646  */
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
#line 7915 "lshParser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1217 "lshParser.y" /* yacc.c:1646  */
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
#line 7931 "lshParser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1228 "lshParser.y" /* yacc.c:1646  */
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
#line 7954 "lshParser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1246 "lshParser.y" /* yacc.c:1646  */
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
#line 7970 "lshParser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1260 "lshParser.y" /* yacc.c:1646  */
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
#line 7986 "lshParser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1271 "lshParser.y" /* yacc.c:1646  */
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
#line 8002 "lshParser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1282 "lshParser.y" /* yacc.c:1646  */
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
#line 8025 "lshParser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1300 "lshParser.y" /* yacc.c:1646  */
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
#line 8041 "lshParser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1314 "lshParser.y" /* yacc.c:1646  */
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
#line 8057 "lshParser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1325 "lshParser.y" /* yacc.c:1646  */
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
#line 8073 "lshParser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1336 "lshParser.y" /* yacc.c:1646  */
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
#line 8096 "lshParser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1354 "lshParser.y" /* yacc.c:1646  */
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
#line 8112 "lshParser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1365 "lshParser.y" /* yacc.c:1646  */
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
#line 8128 "lshParser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1376 "lshParser.y" /* yacc.c:1646  */
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
#line 8144 "lshParser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1387 "lshParser.y" /* yacc.c:1646  */
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
#line 8167 "lshParser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1405 "lshParser.y" /* yacc.c:1646  */
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
#line 8183 "lshParser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1416 "lshParser.y" /* yacc.c:1646  */
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
#line 8199 "lshParser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1427 "lshParser.y" /* yacc.c:1646  */
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
#line 8215 "lshParser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1438 "lshParser.y" /* yacc.c:1646  */
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
#line 8231 "lshParser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1449 "lshParser.y" /* yacc.c:1646  */
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
#line 8247 "lshParser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1460 "lshParser.y" /* yacc.c:1646  */
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
#line 8263 "lshParser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1471 "lshParser.y" /* yacc.c:1646  */
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
#line 8279 "lshParser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1482 "lshParser.y" /* yacc.c:1646  */
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
#line 8295 "lshParser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1493 "lshParser.y" /* yacc.c:1646  */
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
#line 8311 "lshParser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1504 "lshParser.y" /* yacc.c:1646  */
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
#line 8327 "lshParser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1515 "lshParser.y" /* yacc.c:1646  */
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
#line 8343 "lshParser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1526 "lshParser.y" /* yacc.c:1646  */
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
#line 8359 "lshParser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1537 "lshParser.y" /* yacc.c:1646  */
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
#line 8375 "lshParser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1548 "lshParser.y" /* yacc.c:1646  */
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
#line 8391 "lshParser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1559 "lshParser.y" /* yacc.c:1646  */
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
#line 8407 "lshParser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1570 "lshParser.y" /* yacc.c:1646  */
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
#line 8423 "lshParser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1581 "lshParser.y" /* yacc.c:1646  */
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
#line 8439 "lshParser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1592 "lshParser.y" /* yacc.c:1646  */
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
#line 8455 "lshParser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1603 "lshParser.y" /* yacc.c:1646  */
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
#line 8471 "lshParser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1614 "lshParser.y" /* yacc.c:1646  */
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
#line 8487 "lshParser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1625 "lshParser.y" /* yacc.c:1646  */
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
#line 8503 "lshParser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1636 "lshParser.y" /* yacc.c:1646  */
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
#line 8519 "lshParser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1647 "lshParser.y" /* yacc.c:1646  */
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
#line 8535 "lshParser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1658 "lshParser.y" /* yacc.c:1646  */
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
#line 8551 "lshParser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1669 "lshParser.y" /* yacc.c:1646  */
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
#line 8567 "lshParser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1683 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new breakNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("breakNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8581 "lshParser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1692 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new breakNode (*(yyvsp[-1].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("breakNode", "stmt", NULL, NULL, 0, *(yyvsp[-1].fval));
         }
         #endif
         (yyval.data) = r;     
      }
#line 8595 "lshParser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1701 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new continueNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("continueNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8609 "lshParser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1710 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new continueNode (*(yyvsp[-1].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("continueNode", "stmt", NULL, NULL, 0, *(yyvsp[-1].fval));
         }
         #endif
         (yyval.data) = r;
      }
#line 8623 "lshParser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1722 "lshParser.y" /* yacc.c:1646  */
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
#line 8639 "lshParser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1733 "lshParser.y" /* yacc.c:1646  */
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
#line 8655 "lshParser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1747 "lshParser.y" /* yacc.c:1646  */
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
#line 8671 "lshParser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1758 "lshParser.y" /* yacc.c:1646  */
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
#line 8687 "lshParser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1769 "lshParser.y" /* yacc.c:1646  */
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
#line 8703 "lshParser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1780 "lshParser.y" /* yacc.c:1646  */
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
#line 8719 "lshParser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1794 "lshParser.y" /* yacc.c:1646  */
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
#line 8741 "lshParser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1811 "lshParser.y" /* yacc.c:1646  */
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
#line 8763 "lshParser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1828 "lshParser.y" /* yacc.c:1646  */
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
#line 8794 "lshParser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1854 "lshParser.y" /* yacc.c:1646  */
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
#line 8816 "lshParser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1871 "lshParser.y" /* yacc.c:1646  */
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
#line 8832 "lshParser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1882 "lshParser.y" /* yacc.c:1646  */
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
#line 8848 "lshParser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1893 "lshParser.y" /* yacc.c:1646  */
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
#line 8871 "lshParser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1911 "lshParser.y" /* yacc.c:1646  */
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
#line 8887 "lshParser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1922 "lshParser.y" /* yacc.c:1646  */
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
#line 8903 "lshParser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1933 "lshParser.y" /* yacc.c:1646  */
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
#line 8919 "lshParser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1944 "lshParser.y" /* yacc.c:1646  */
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
#line 8942 "lshParser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1962 "lshParser.y" /* yacc.c:1646  */
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
#line 8958 "lshParser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1973 "lshParser.y" /* yacc.c:1646  */
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
#line 8974 "lshParser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1984 "lshParser.y" /* yacc.c:1646  */
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
#line 8990 "lshParser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1995 "lshParser.y" /* yacc.c:1646  */
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
#line 9013 "lshParser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2013 "lshParser.y" /* yacc.c:1646  */
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
#line 9029 "lshParser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2024 "lshParser.y" /* yacc.c:1646  */
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
#line 9045 "lshParser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2035 "lshParser.y" /* yacc.c:1646  */
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
#line 9061 "lshParser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 2046 "lshParser.y" /* yacc.c:1646  */
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
#line 9084 "lshParser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 2064 "lshParser.y" /* yacc.c:1646  */
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
#line 9100 "lshParser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 2075 "lshParser.y" /* yacc.c:1646  */
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
#line 9116 "lshParser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 2086 "lshParser.y" /* yacc.c:1646  */
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
#line 9132 "lshParser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 2097 "lshParser.y" /* yacc.c:1646  */
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
#line 9155 "lshParser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 2115 "lshParser.y" /* yacc.c:1646  */
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
#line 9171 "lshParser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 2126 "lshParser.y" /* yacc.c:1646  */
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
#line 9187 "lshParser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 2137 "lshParser.y" /* yacc.c:1646  */
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
#line 9203 "lshParser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 2148 "lshParser.y" /* yacc.c:1646  */
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
#line 9226 "lshParser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 2166 "lshParser.y" /* yacc.c:1646  */
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
#line 9242 "lshParser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 2181 "lshParser.y" /* yacc.c:1646  */
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
#line 9258 "lshParser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 2192 "lshParser.y" /* yacc.c:1646  */
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
#line 9281 "lshParser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 2210 "lshParser.y" /* yacc.c:1646  */
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
#line 9311 "lshParser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 2235 "lshParser.y" /* yacc.c:1646  */
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
#line 9334 "lshParser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 2256 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].data); }
#line 9340 "lshParser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 2261 "lshParser.y" /* yacc.c:1646  */
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
#line 9356 "lshParser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 2272 "lshParser.y" /* yacc.c:1646  */
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
#line 9372 "lshParser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 2283 "lshParser.y" /* yacc.c:1646  */
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
#line 9388 "lshParser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 2294 "lshParser.y" /* yacc.c:1646  */
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
#line 9404 "lshParser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 2305 "lshParser.y" /* yacc.c:1646  */
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
#line 9420 "lshParser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 2316 "lshParser.y" /* yacc.c:1646  */
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
#line 9436 "lshParser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 2327 "lshParser.y" /* yacc.c:1646  */
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
#line 9452 "lshParser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 2338 "lshParser.y" /* yacc.c:1646  */
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
#line 9468 "lshParser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 2349 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new decoratorNode ((yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {(yyvsp[-6].idnode), (yyvsp[-4].data), (yyvsp[-1].data)};
            string b[3] = {"id", "params", "body"};
            r->toJson ("decoratorNode", "function", a, b, 3);
         }
         #endif
         (yyval.data) = r;     
      }
#line 9484 "lshParser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 2360 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new decoratorNode ((yyvsp[-5].idnode), (yyvsp[-3].data), NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].idnode), (yyvsp[-3].data)};
            string b[2] = {"id", "params"};
            r->toJson ("decoratorNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;     
      }
#line 9500 "lshParser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 2371 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new decoratorNode ((yyvsp[-5].idnode), NULL, (yyvsp[-1].data));
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-5].idnode), (yyvsp[-1].data)};
            string b[2] = {"id", "body"};
            r->toJson ("decoratorNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;  
      }
#line 9516 "lshParser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 2382 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new decoratorNode ((yyvsp[-4].idnode), NULL, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-4].idnode)};
            string b[1] = {"id"};
            r->toJson ("decoratorNode", "function", a, NULL, 1);
         }
         #endif
         (yyval.data) = r;   
      }
#line 9532 "lshParser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 2397 "lshParser.y" /* yacc.c:1646  */
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
#line 9548 "lshParser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 2408 "lshParser.y" /* yacc.c:1646  */
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
#line 9564 "lshParser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 2419 "lshParser.y" /* yacc.c:1646  */
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
#line 9579 "lshParser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 2429 "lshParser.y" /* yacc.c:1646  */
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
#line 9594 "lshParser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 2443 "lshParser.y" /* yacc.c:1646  */
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
#line 9617 "lshParser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 2461 "lshParser.y" /* yacc.c:1646  */
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
#line 9640 "lshParser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 2479 "lshParser.y" /* yacc.c:1646  */
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
#line 9663 "lshParser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 2497 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9669 "lshParser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 2502 "lshParser.y" /* yacc.c:1646  */
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
#line 9684 "lshParser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 2512 "lshParser.y" /* yacc.c:1646  */
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
#line 9706 "lshParser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 2529 "lshParser.y" /* yacc.c:1646  */
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
#line 9721 "lshParser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 2539 "lshParser.y" /* yacc.c:1646  */
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
#line 9743 "lshParser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 2560 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9749 "lshParser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 2564 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9755 "lshParser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 2568 "lshParser.y" /* yacc.c:1646  */
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
#line 9771 "lshParser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 2579 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9777 "lshParser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 2583 "lshParser.y" /* yacc.c:1646  */
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
#line 9793 "lshParser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 2594 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 9799 "lshParser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 2598 "lshParser.y" /* yacc.c:1646  */
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
#line 9814 "lshParser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 2608 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 9820 "lshParser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 2612 "lshParser.y" /* yacc.c:1646  */
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
#line 9836 "lshParser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 2623 "lshParser.y" /* yacc.c:1646  */
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
#line 9852 "lshParser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 2634 "lshParser.y" /* yacc.c:1646  */
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
#line 9868 "lshParser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 2645 "lshParser.y" /* yacc.c:1646  */
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
#line 9884 "lshParser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 2656 "lshParser.y" /* yacc.c:1646  */
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
#line 9900 "lshParser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 2667 "lshParser.y" /* yacc.c:1646  */
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
#line 9916 "lshParser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 2678 "lshParser.y" /* yacc.c:1646  */
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
#line 9932 "lshParser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 2689 "lshParser.y" /* yacc.c:1646  */
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
#line 9948 "lshParser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 2700 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9954 "lshParser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 2705 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9960 "lshParser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 2709 "lshParser.y" /* yacc.c:1646  */
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
#line 9976 "lshParser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 2720 "lshParser.y" /* yacc.c:1646  */
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
#line 9992 "lshParser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 2731 "lshParser.y" /* yacc.c:1646  */
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
#line 10033 "lshParser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 2767 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10039 "lshParser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 2771 "lshParser.y" /* yacc.c:1646  */
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
#line 10055 "lshParser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 2782 "lshParser.y" /* yacc.c:1646  */
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
#line 10071 "lshParser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 2793 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10077 "lshParser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 2797 "lshParser.y" /* yacc.c:1646  */
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
#line 10093 "lshParser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 2808 "lshParser.y" /* yacc.c:1646  */
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
#line 10109 "lshParser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 2819 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10115 "lshParser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 2824 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10121 "lshParser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 2828 "lshParser.y" /* yacc.c:1646  */
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
#line 10137 "lshParser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 2839 "lshParser.y" /* yacc.c:1646  */
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
#line 10153 "lshParser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 2850 "lshParser.y" /* yacc.c:1646  */
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
#line 10169 "lshParser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 2861 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10175 "lshParser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 2865 "lshParser.y" /* yacc.c:1646  */
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
#line 10190 "lshParser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 2875 "lshParser.y" /* yacc.c:1646  */
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
#line 10205 "lshParser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 2885 "lshParser.y" /* yacc.c:1646  */
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
#line 10221 "lshParser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 2896 "lshParser.y" /* yacc.c:1646  */
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
#line 10237 "lshParser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 2907 "lshParser.y" /* yacc.c:1646  */
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
#line 10258 "lshParser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 2923 "lshParser.y" /* yacc.c:1646  */
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
#line 10279 "lshParser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 2939 "lshParser.y" /* yacc.c:1646  */
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
#line 10301 "lshParser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 2956 "lshParser.y" /* yacc.c:1646  */
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
#line 10323 "lshParser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 2973 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10329 "lshParser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 2978 "lshParser.y" /* yacc.c:1646  */
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
#line 10345 "lshParser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 2989 "lshParser.y" /* yacc.c:1646  */
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
#line 10361 "lshParser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 3000 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10367 "lshParser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 3005 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10373 "lshParser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 3009 "lshParser.y" /* yacc.c:1646  */
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
#line 10389 "lshParser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 3020 "lshParser.y" /* yacc.c:1646  */
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
#line 10405 "lshParser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 3031 "lshParser.y" /* yacc.c:1646  */
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
#line 10421 "lshParser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 3042 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10427 "lshParser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 3046 "lshParser.y" /* yacc.c:1646  */
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
#line 10442 "lshParser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 3056 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10448 "lshParser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 3061 "lshParser.y" /* yacc.c:1646  */
    {(yyval.data) = (yyvsp[0].data); }
#line 10454 "lshParser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 3062 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10460 "lshParser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 3063 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10466 "lshParser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 3064 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10472 "lshParser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 3065 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10478 "lshParser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 3068 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10484 "lshParser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 3069 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10490 "lshParser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 3070 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10496 "lshParser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 3071 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10502 "lshParser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 3072 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10508 "lshParser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 3073 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10514 "lshParser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 3074 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10520 "lshParser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 3077 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10526 "lshParser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 3078 "lshParser.y" /* yacc.c:1646  */
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
#line 10541 "lshParser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 3091 "lshParser.y" /* yacc.c:1646  */
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
#line 10556 "lshParser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 3101 "lshParser.y" /* yacc.c:1646  */
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
#line 10571 "lshParser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 3111 "lshParser.y" /* yacc.c:1646  */
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
#line 10586 "lshParser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 3121 "lshParser.y" /* yacc.c:1646  */
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
#line 10601 "lshParser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 3131 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10607 "lshParser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 3135 "lshParser.y" /* yacc.c:1646  */
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
#line 10631 "lshParser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 3154 "lshParser.y" /* yacc.c:1646  */
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
#line 10655 "lshParser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 3173 "lshParser.y" /* yacc.c:1646  */
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
#line 10679 "lshParser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 3192 "lshParser.y" /* yacc.c:1646  */
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
#line 10703 "lshParser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 3211 "lshParser.y" /* yacc.c:1646  */
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
#line 10727 "lshParser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 3230 "lshParser.y" /* yacc.c:1646  */
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
#line 10751 "lshParser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 3249 "lshParser.y" /* yacc.c:1646  */
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
#line 10775 "lshParser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 3268 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10781 "lshParser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 3272 "lshParser.y" /* yacc.c:1646  */
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
#line 10796 "lshParser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 3282 "lshParser.y" /* yacc.c:1646  */
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
#line 10811 "lshParser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 3292 "lshParser.y" /* yacc.c:1646  */
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
#line 10826 "lshParser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 3302 "lshParser.y" /* yacc.c:1646  */
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
#line 10841 "lshParser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 3312 "lshParser.y" /* yacc.c:1646  */
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
#line 10856 "lshParser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 3322 "lshParser.y" /* yacc.c:1646  */
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
#line 10871 "lshParser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 3332 "lshParser.y" /* yacc.c:1646  */
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
#line 10886 "lshParser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 3342 "lshParser.y" /* yacc.c:1646  */
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
#line 10901 "lshParser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 3355 "lshParser.y" /* yacc.c:1646  */
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
#line 10916 "lshParser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 3365 "lshParser.y" /* yacc.c:1646  */
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
#line 10931 "lshParser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 3375 "lshParser.y" /* yacc.c:1646  */
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
#line 10946 "lshParser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 3385 "lshParser.y" /* yacc.c:1646  */
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
#line 10961 "lshParser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 3395 "lshParser.y" /* yacc.c:1646  */
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
#line 10976 "lshParser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 3405 "lshParser.y" /* yacc.c:1646  */
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
#line 10991 "lshParser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 3415 "lshParser.y" /* yacc.c:1646  */
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
#line 11006 "lshParser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 3428 "lshParser.y" /* yacc.c:1646  */
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
#line 11021 "lshParser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 3438 "lshParser.y" /* yacc.c:1646  */
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
#line 11036 "lshParser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 3448 "lshParser.y" /* yacc.c:1646  */
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
#line 11051 "lshParser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 3458 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new sizeOfNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("sizeOfNode", "operator", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11065 "lshParser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 3471 "lshParser.y" /* yacc.c:1646  */
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
#line 11081 "lshParser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 3482 "lshParser.y" /* yacc.c:1646  */
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
#line 11097 "lshParser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 3493 "lshParser.y" /* yacc.c:1646  */
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
#line 11112 "lshParser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 3503 "lshParser.y" /* yacc.c:1646  */
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
#line 11128 "lshParser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 3514 "lshParser.y" /* yacc.c:1646  */
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
#line 11144 "lshParser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 3525 "lshParser.y" /* yacc.c:1646  */
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
#line 11160 "lshParser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 3536 "lshParser.y" /* yacc.c:1646  */
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
#line 11176 "lshParser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 3547 "lshParser.y" /* yacc.c:1646  */
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
#line 11192 "lshParser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 3558 "lshParser.y" /* yacc.c:1646  */
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
#line 11207 "lshParser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 3568 "lshParser.y" /* yacc.c:1646  */
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
#line 11222 "lshParser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 3581 "lshParser.y" /* yacc.c:1646  */
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
#line 11238 "lshParser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 3592 "lshParser.y" /* yacc.c:1646  */
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
#line 11254 "lshParser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 3603 "lshParser.y" /* yacc.c:1646  */
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
#line 11270 "lshParser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 3614 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new thisNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("thisNode", "class", NULL, 0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 11284 "lshParser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 3623 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new parentNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("parentNode", "class", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11298 "lshParser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 3632 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11304 "lshParser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 3633 "lshParser.y" /* yacc.c:1646  */
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
#line 11319 "lshParser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 3646 "lshParser.y" /* yacc.c:1646  */
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
#line 11334 "lshParser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 3656 "lshParser.y" /* yacc.c:1646  */
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
#line 11349 "lshParser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 3666 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arrayConstNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("arrayConstNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11363 "lshParser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 3675 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11369 "lshParser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 3676 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11375 "lshParser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 3680 "lshParser.y" /* yacc.c:1646  */
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
#line 11391 "lshParser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 3691 "lshParser.y" /* yacc.c:1646  */
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
#line 11407 "lshParser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 3702 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new timeNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("timeNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11421 "lshParser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 3711 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new timeNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("timeNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11435 "lshParser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 3723 "lshParser.y" /* yacc.c:1646  */
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
#line 11451 "lshParser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 3734 "lshParser.y" /* yacc.c:1646  */
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
#line 11467 "lshParser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 3745 "lshParser.y" /* yacc.c:1646  */
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
#line 11483 "lshParser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 3756 "lshParser.y" /* yacc.c:1646  */
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
#line 11499 "lshParser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 3767 "lshParser.y" /* yacc.c:1646  */
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
#line 11515 "lshParser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 3778 "lshParser.y" /* yacc.c:1646  */
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
#line 11531 "lshParser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 3789 "lshParser.y" /* yacc.c:1646  */
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
#line 11547 "lshParser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 3800 "lshParser.y" /* yacc.c:1646  */
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
#line 11562 "lshParser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 3810 "lshParser.y" /* yacc.c:1646  */
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
#line 11577 "lshParser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 3820 "lshParser.y" /* yacc.c:1646  */
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
#line 11593 "lshParser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 3831 "lshParser.y" /* yacc.c:1646  */
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
#line 11609 "lshParser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 3842 "lshParser.y" /* yacc.c:1646  */
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
#line 11625 "lshParser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 3853 "lshParser.y" /* yacc.c:1646  */
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
#line 11641 "lshParser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 3864 "lshParser.y" /* yacc.c:1646  */
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
#line 11656 "lshParser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 3877 "lshParser.y" /* yacc.c:1646  */
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
#line 11671 "lshParser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 3887 "lshParser.y" /* yacc.c:1646  */
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
#line 11686 "lshParser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 3897 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new forkNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("forkNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11700 "lshParser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 3906 "lshParser.y" /* yacc.c:1646  */
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
#line 11715 "lshParser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 3916 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new waitNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("waitNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11729 "lshParser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 3925 "lshParser.y" /* yacc.c:1646  */
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
#line 11746 "lshParser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 3937 "lshParser.y" /* yacc.c:1646  */
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
#line 11762 "lshParser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 3948 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new exitProcessNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("exitProcessNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
   }
#line 11776 "lshParser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 3957 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getpidNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getpidNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;      
      }
#line 11790 "lshParser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 3966 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new getppidNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getppidNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11804 "lshParser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 3975 "lshParser.y" /* yacc.c:1646  */
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
#line 11820 "lshParser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 3986 "lshParser.y" /* yacc.c:1646  */
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
#line 11836 "lshParser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 4000 "lshParser.y" /* yacc.c:1646  */
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
#line 11851 "lshParser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 4013 "lshParser.y" /* yacc.c:1646  */
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
#line 11867 "lshParser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 4024 "lshParser.y" /* yacc.c:1646  */
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
#line 11883 "lshParser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 4035 "lshParser.y" /* yacc.c:1646  */
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
#line 11899 "lshParser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 4046 "lshParser.y" /* yacc.c:1646  */
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
#line 11915 "lshParser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 4057 "lshParser.y" /* yacc.c:1646  */
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
#line 11931 "lshParser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 4068 "lshParser.y" /* yacc.c:1646  */
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
#line 11947 "lshParser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 4079 "lshParser.y" /* yacc.c:1646  */
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
#line 11963 "lshParser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 4090 "lshParser.y" /* yacc.c:1646  */
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
#line 11979 "lshParser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 4101 "lshParser.y" /* yacc.c:1646  */
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
#line 11995 "lshParser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 4112 "lshParser.y" /* yacc.c:1646  */
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
#line 12011 "lshParser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 4123 "lshParser.y" /* yacc.c:1646  */
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
#line 12027 "lshParser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 4134 "lshParser.y" /* yacc.c:1646  */
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
#line 12043 "lshParser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 4145 "lshParser.y" /* yacc.c:1646  */
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
#line 12059 "lshParser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 4156 "lshParser.y" /* yacc.c:1646  */
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
#line 12075 "lshParser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 4167 "lshParser.y" /* yacc.c:1646  */
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
#line 12091 "lshParser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 4178 "lshParser.y" /* yacc.c:1646  */
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
#line 12107 "lshParser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 4189 "lshParser.y" /* yacc.c:1646  */
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
#line 12123 "lshParser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 4200 "lshParser.y" /* yacc.c:1646  */
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
#line 12139 "lshParser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 4211 "lshParser.y" /* yacc.c:1646  */
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
#line 12155 "lshParser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 4222 "lshParser.y" /* yacc.c:1646  */
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
#line 12171 "lshParser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 4233 "lshParser.y" /* yacc.c:1646  */
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
#line 12187 "lshParser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 4244 "lshParser.y" /* yacc.c:1646  */
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
#line 12203 "lshParser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 4255 "lshParser.y" /* yacc.c:1646  */
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
#line 12219 "lshParser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 4266 "lshParser.y" /* yacc.c:1646  */
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
#line 12235 "lshParser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 4277 "lshParser.y" /* yacc.c:1646  */
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
#line 12251 "lshParser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 4288 "lshParser.y" /* yacc.c:1646  */
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
#line 12267 "lshParser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 4299 "lshParser.y" /* yacc.c:1646  */
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
#line 12283 "lshParser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 4310 "lshParser.y" /* yacc.c:1646  */
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
#line 12299 "lshParser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 4321 "lshParser.y" /* yacc.c:1646  */
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
#line 12315 "lshParser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 4332 "lshParser.y" /* yacc.c:1646  */
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
#line 12331 "lshParser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 4343 "lshParser.y" /* yacc.c:1646  */
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
#line 12347 "lshParser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 4354 "lshParser.y" /* yacc.c:1646  */
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
#line 12363 "lshParser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 4365 "lshParser.y" /* yacc.c:1646  */
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
#line 12379 "lshParser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 4376 "lshParser.y" /* yacc.c:1646  */
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
#line 12395 "lshParser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 4387 "lshParser.y" /* yacc.c:1646  */
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
#line 12411 "lshParser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 4398 "lshParser.y" /* yacc.c:1646  */
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
#line 12428 "lshParser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 4410 "lshParser.y" /* yacc.c:1646  */
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
#line 12444 "lshParser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 4421 "lshParser.y" /* yacc.c:1646  */
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
#line 12460 "lshParser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 4432 "lshParser.y" /* yacc.c:1646  */
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
#line 12476 "lshParser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 4443 "lshParser.y" /* yacc.c:1646  */
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
#line 12492 "lshParser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 4454 "lshParser.y" /* yacc.c:1646  */
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
#line 12508 "lshParser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 4465 "lshParser.y" /* yacc.c:1646  */
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
#line 12524 "lshParser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 4476 "lshParser.y" /* yacc.c:1646  */
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
#line 12540 "lshParser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 4487 "lshParser.y" /* yacc.c:1646  */
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
#line 12556 "lshParser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 4498 "lshParser.y" /* yacc.c:1646  */
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
#line 12572 "lshParser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 4509 "lshParser.y" /* yacc.c:1646  */
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
#line 12588 "lshParser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 4520 "lshParser.y" /* yacc.c:1646  */
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
#line 12604 "lshParser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 4531 "lshParser.y" /* yacc.c:1646  */
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
#line 12620 "lshParser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 4545 "lshParser.y" /* yacc.c:1646  */
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
#line 12635 "lshParser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 4555 "lshParser.y" /* yacc.c:1646  */
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
#line 12651 "lshParser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 4566 "lshParser.y" /* yacc.c:1646  */
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
#line 12667 "lshParser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 4577 "lshParser.y" /* yacc.c:1646  */
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
#line 12683 "lshParser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 4591 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getiNode (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getiNode", "symbol", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12697 "lshParser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 4600 "lshParser.y" /* yacc.c:1646  */
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
#line 12718 "lshParser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 4619 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data) = r;
      }
#line 12732 "lshParser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 4628 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new boolConstNode (true);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("boolConstNode", "data", NULL, NULL, 0, "true");
         }
         #endif
         (yyval.data) = r;
      }
#line 12746 "lshParser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 4637 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new boolConstNode (false); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("boolConstNode", "data", NULL, NULL, 0, "false");
         }
         #endif
         (yyval.data)  = r;
      }
#line 12760 "lshParser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 4646 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new nullNode (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("nullNode", "data", NULL, 0);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 12774 "lshParser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 4655 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data)  = r;
      }
#line 12788 "lshParser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 4664 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new strConstNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("strConstNode", "data", NULL, NULL, 0, *(yyvsp[0].str));
         }
         #endif
         (yyval.data)  = r;   
      }
#line 12802 "lshParser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 4673 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new regexpNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("regexpNode", "data", NULL, NULL, 0, *(yyvsp[0].str));
         }
         #endif
         (yyval.data)  = r;   
      }
#line 12816 "lshParser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 4682 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data)  = r;
      }
#line 12830 "lshParser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 4691 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (-1 * (*(yyvsp[0].fval))); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, (-1 * (*(yyvsp[0].fval))));
         }
         #endif
         (yyval.data)  = r;
      }
#line 12844 "lshParser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 4700 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].idnode);}
#line 12850 "lshParser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 4701 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].data); }
#line 12856 "lshParser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 4705 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 12862 "lshParser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 4706 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 12868 "lshParser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 4707 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 12874 "lshParser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 4708 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new contextFunction (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("contextFunction", "function", NULL, 0);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 12888 "lshParser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 4721 "lshParser.y" /* yacc.c:1646  */
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
#line 12904 "lshParser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 4732 "lshParser.y" /* yacc.c:1646  */
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
#line 12920 "lshParser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 4743 "lshParser.y" /* yacc.c:1646  */
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
#line 12936 "lshParser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 4754 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functionNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("functionNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 12950 "lshParser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 4763 "lshParser.y" /* yacc.c:1646  */
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
#line 12965 "lshParser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 4773 "lshParser.y" /* yacc.c:1646  */
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
#line 12981 "lshParser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 4784 "lshParser.y" /* yacc.c:1646  */
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
#line 12997 "lshParser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 4795 "lshParser.y" /* yacc.c:1646  */
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
#line 13013 "lshParser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 4806 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new functionNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("functionNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13027 "lshParser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 4815 "lshParser.y" /* yacc.c:1646  */
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
#line 13042 "lshParser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 4825 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functionLambdaNode ((yyvsp[-2].data), (yyvsp[0].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-2].data), (yyvsp[0].data)} ;
            string b[2] = {"params", "return"};
            r->toJson ("functionLambdaNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13058 "lshParser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 4839 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new decoratorNode (NULL, NULL, (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-1].data)} ;
            string b[1] = {"body"};
            r->toJson ("decoratorNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;     
      }
#line 13074 "lshParser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 4850 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new decoratorNode (NULL, (yyvsp[-4].data), (yyvsp[-1].data)); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {(yyvsp[-4].data), (yyvsp[-1].data)} ;
            string b[2] = {"params", "body"};
            r->toJson ("decoratorNode", "function", a, b, 2);
         }
         #endif
         (yyval.data) = r;        
      }
#line 13090 "lshParser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 4861 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new decoratorNode (NULL, (yyvsp[-3].data), NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {(yyvsp[-3].data)} ;
            string b[1] = {"params"};
            r->toJson ("decoratorNode", "function", a, b, 1);
         }
         #endif
         (yyval.data) = r;        
      }
#line 13106 "lshParser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 4872 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new decoratorNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("decoratorNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;        
      }
#line 13120 "lshParser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 4884 "lshParser.y" /* yacc.c:1646  */
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
#line 13136 "lshParser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 4895 "lshParser.y" /* yacc.c:1646  */
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
#line 13152 "lshParser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 4906 "lshParser.y" /* yacc.c:1646  */
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
#line 13168 "lshParser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 4917 "lshParser.y" /* yacc.c:1646  */
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
#line 13184 "lshParser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 4928 "lshParser.y" /* yacc.c:1646  */
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
#line 13200 "lshParser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 4939 "lshParser.y" /* yacc.c:1646  */
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
#line 13216 "lshParser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 4954 "lshParser.y" /* yacc.c:1646  */
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
#line 13231 "lshParser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 4964 "lshParser.y" /* yacc.c:1646  */
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
#line 13246 "lshParser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 4974 "lshParser.y" /* yacc.c:1646  */
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
#line 13261 "lshParser.c" /* yacc.c:1646  */
    break;

  case 455:
#line 4987 "lshParser.y" /* yacc.c:1646  */
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
#line 13276 "lshParser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 4997 "lshParser.y" /* yacc.c:1646  */
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
#line 13291 "lshParser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 5007 "lshParser.y" /* yacc.c:1646  */
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
#line 13306 "lshParser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 5020 "lshParser.y" /* yacc.c:1646  */
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
#line 13322 "lshParser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 5031 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13328 "lshParser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 5036 "lshParser.y" /* yacc.c:1646  */
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
#line 13344 "lshParser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 5047 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13350 "lshParser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 5052 "lshParser.y" /* yacc.c:1646  */
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
#line 13365 "lshParser.c" /* yacc.c:1646  */
    break;

  case 463:
#line 5062 "lshParser.y" /* yacc.c:1646  */
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
#line 13380 "lshParser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 5075 "lshParser.y" /* yacc.c:1646  */
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
#line 13396 "lshParser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 5086 "lshParser.y" /* yacc.c:1646  */
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
#line 13412 "lshParser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 5097 "lshParser.y" /* yacc.c:1646  */
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
#line 13428 "lshParser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 5108 "lshParser.y" /* yacc.c:1646  */
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
#line 13444 "lshParser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 5119 "lshParser.y" /* yacc.c:1646  */
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
#line 13460 "lshParser.c" /* yacc.c:1646  */
    break;

  case 469:
#line 5130 "lshParser.y" /* yacc.c:1646  */
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
#line 13482 "lshParser.c" /* yacc.c:1646  */
    break;

  case 470:
#line 5147 "lshParser.y" /* yacc.c:1646  */
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
#line 13504 "lshParser.c" /* yacc.c:1646  */
    break;

  case 471:
#line 5164 "lshParser.y" /* yacc.c:1646  */
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
#line 13526 "lshParser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 5181 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13532 "lshParser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 5182 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13538 "lshParser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 5186 "lshParser.y" /* yacc.c:1646  */
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
#line 13554 "lshParser.c" /* yacc.c:1646  */
    break;

  case 475:
#line 5197 "lshParser.y" /* yacc.c:1646  */
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
#line 13569 "lshParser.c" /* yacc.c:1646  */
    break;

  case 476:
#line 5207 "lshParser.y" /* yacc.c:1646  */
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
#line 13584 "lshParser.c" /* yacc.c:1646  */
    break;

  case 477:
#line 5217 "lshParser.y" /* yacc.c:1646  */
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
#line 13600 "lshParser.c" /* yacc.c:1646  */
    break;

  case 478:
#line 5228 "lshParser.y" /* yacc.c:1646  */
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
#line 13616 "lshParser.c" /* yacc.c:1646  */
    break;

  case 479:
#line 5239 "lshParser.y" /* yacc.c:1646  */
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
#line 13632 "lshParser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 5250 "lshParser.y" /* yacc.c:1646  */
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
#line 13648 "lshParser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 5261 "lshParser.y" /* yacc.c:1646  */
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
#line 13663 "lshParser.c" /* yacc.c:1646  */
    break;

  case 482:
#line 5271 "lshParser.y" /* yacc.c:1646  */
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
#line 13678 "lshParser.c" /* yacc.c:1646  */
    break;

  case 483:
#line 5281 "lshParser.y" /* yacc.c:1646  */
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
#line 13694 "lshParser.c" /* yacc.c:1646  */
    break;

  case 484:
#line 5296 "lshParser.y" /* yacc.c:1646  */
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
#line 13710 "lshParser.c" /* yacc.c:1646  */
    break;

  case 485:
#line 5307 "lshParser.y" /* yacc.c:1646  */
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
#line 13726 "lshParser.c" /* yacc.c:1646  */
    break;

  case 486:
#line 5318 "lshParser.y" /* yacc.c:1646  */
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
#line 13748 "lshParser.c" /* yacc.c:1646  */
    break;

  case 487:
#line 5335 "lshParser.y" /* yacc.c:1646  */
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
#line 13770 "lshParser.c" /* yacc.c:1646  */
    break;

  case 488:
#line 5356 "lshParser.y" /* yacc.c:1646  */
    { 
         idNode * r = new idNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", *(yyvsp[0].str));
         }
         #endif
         (yyval.idnode)  = r;
      }
#line 13784 "lshParser.c" /* yacc.c:1646  */
    break;

  case 489:
#line 5365 "lshParser.y" /* yacc.c:1646  */
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
#line 13799 "lshParser.c" /* yacc.c:1646  */
    break;


#line 13803 "lshParser.c" /* yacc.c:1646  */
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
#line 5378 "lshParser.y" /* yacc.c:1906  */


//======================================================================
// Fco. Javier Bohórquez Ogalla
