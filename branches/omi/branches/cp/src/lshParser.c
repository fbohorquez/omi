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
#include "run/componentNode.h"
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

#line 106 "lshParser.c" /* yacc.c:339  */

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
    DEF = 383,
    CDATA = 384,
    DDATA = 385,
    SDATA = 386,
    REFDEF = 387,
    REFREL = 388,
    FROM = 389,
    EXIST = 390,
    IDDEF = 391,
    LIKE = 392,
    CINT = 393,
    CFLOAT = 394,
    CBOOL = 395,
    CSTR = 396
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
#define DEF 383
#define CDATA 384
#define DDATA 385
#define SDATA 386
#define REFDEF 387
#define REFREL 388
#define FROM 389
#define EXIST 390
#define IDDEF 391
#define LIKE 392
#define CINT 393
#define CFLOAT 394
#define CBOOL 395
#define CSTR 396

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 61 "lshParser.y" /* yacc.c:355  */

  num* fval;
  string* str; 
  idNode* idnode;
  listNode* listnode;
  runNode* data;
  runNode** ref;
  vector<string>* mval;

#line 438 "lshParser.c" /* yacc.c:355  */
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

#line 467 "lshParser.c" /* yacc.c:358  */

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
#define YYLAST   21733

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  167
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  489
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1240

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   396

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   153,     2,     2,   148,   161,   152,     2,
     143,   144,   158,   156,   149,   157,   162,   159,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   145,   142,
     154,   151,   155,   165,   166,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   163,     2,   164,   160,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   146,     2,   147,   150,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   113,   117,   127,   137,   147,   157,   167,
     177,   178,   184,   194,   204,   214,   224,   234,   244,   245,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     263,   264,   274,   284,   294,   304,   314,   324,   333,   343,
     353,   363,   373,   390,   407,   424,   441,   451,   461,   471,
     481,   490,   503,   507,   508,   510,   523,   534,   545,   563,
     574,   585,   596,   607,   625,   643,   654,   665,   683,   701,
     726,   744,   755,   766,   784,   795,   806,   817,   836,   850,
     861,   872,   890,   901,   912,   923,   934,   952,   970,   981,
     992,  1010,  1028,  1053,  1071,  1082,  1093,  1111,  1122,  1133,
    1144,  1162,  1176,  1187,  1208,  1219,  1230,  1248,  1262,  1273,
    1284,  1302,  1316,  1327,  1338,  1356,  1367,  1378,  1389,  1407,
    1418,  1429,  1440,  1451,  1462,  1473,  1484,  1495,  1506,  1517,
    1528,  1539,  1550,  1561,  1572,  1583,  1594,  1605,  1616,  1627,
    1638,  1649,  1660,  1671,  1685,  1694,  1703,  1712,  1724,  1735,
    1749,  1760,  1771,  1782,  1796,  1813,  1830,  1856,  1873,  1884,
    1895,  1913,  1924,  1935,  1946,  1964,  1975,  1986,  1997,  2015,
    2026,  2037,  2048,  2066,  2077,  2088,  2099,  2117,  2128,  2139,
    2150,  2168,  2183,  2194,  2212,  2237,  2258,  2263,  2274,  2285,
    2296,  2307,  2318,  2329,  2340,  2351,  2362,  2373,  2384,  2399,
    2410,  2421,  2431,  2445,  2463,  2481,  2499,  2504,  2514,  2531,
    2541,  2562,  2566,  2570,  2581,  2585,  2596,  2600,  2610,  2614,
    2625,  2636,  2647,  2658,  2669,  2680,  2691,  2702,  2707,  2711,
    2722,  2733,  2769,  2773,  2784,  2795,  2799,  2810,  2821,  2826,
    2830,  2841,  2852,  2863,  2867,  2877,  2887,  2898,  2909,  2925,
    2941,  2958,  2975,  2980,  2991,  3002,  3007,  3011,  3022,  3033,
    3044,  3048,  3058,  3063,  3064,  3065,  3066,  3067,  3070,  3071,
    3072,  3073,  3074,  3075,  3076,  3079,  3080,  3093,  3103,  3113,
    3123,  3133,  3137,  3156,  3175,  3194,  3213,  3232,  3251,  3270,
    3274,  3284,  3294,  3304,  3314,  3324,  3334,  3344,  3357,  3367,
    3377,  3387,  3397,  3407,  3417,  3430,  3440,  3450,  3460,  3473,
    3484,  3495,  3505,  3516,  3527,  3538,  3549,  3560,  3570,  3583,
    3594,  3605,  3616,  3625,  3634,  3635,  3648,  3658,  3668,  3677,
    3678,  3682,  3693,  3704,  3713,  3725,  3736,  3747,  3758,  3769,
    3780,  3791,  3802,  3812,  3822,  3833,  3844,  3855,  3866,  3879,
    3889,  3899,  3908,  3918,  3927,  3939,  3950,  3959,  3968,  3977,
    3988,  4002,  4015,  4026,  4037,  4048,  4059,  4070,  4081,  4092,
    4103,  4114,  4125,  4136,  4147,  4158,  4169,  4180,  4191,  4202,
    4213,  4224,  4235,  4246,  4257,  4268,  4279,  4290,  4301,  4312,
    4323,  4334,  4345,  4356,  4367,  4378,  4389,  4400,  4412,  4423,
    4434,  4445,  4456,  4467,  4478,  4489,  4500,  4511,  4522,  4533,
    4547,  4557,  4568,  4579,  4593,  4602,  4621,  4630,  4639,  4648,
    4657,  4666,  4675,  4684,  4693,  4702,  4703,  4707,  4708,  4709,
    4710,  4723,  4734,  4745,  4756,  4765,  4775,  4786,  4797,  4808,
    4817,  4827,  4841,  4852,  4863,  4874,  4886,  4897,  4908,  4919,
    4930,  4941,  4956,  4966,  4976,  4989,  4999,  5009,  5022,  5033,
    5038,  5049,  5054,  5064,  5077,  5088,  5099,  5110,  5121,  5132,
    5149,  5166,  5183,  5184,  5188,  5199,  5209,  5219,  5230,  5241,
    5252,  5263,  5273,  5283,  5298,  5309,  5320,  5337,  5358,  5367
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
  "ARRAYSHIFT", "ARRAYPOP", "LOAD_MODULE", "DEF", "CDATA", "DDATA",
  "SDATA", "REFDEF", "REFREL", "FROM", "EXIST", "IDDEF", "LIKE", "CINT",
  "CFLOAT", "CBOOL", "CSTR", "';'", "'('", "')'", "':'", "'{'", "'}'",
  "'$'", "','", "'~'", "'='", "'&'", "'!'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'^'", "'%'", "'.'", "'['", "']'", "'?'", "'@'", "$accept",
  "program", "stmts", "stmts_level", "stmtb", "stmt", "label", "define",
  "if", "elseif", "with", "while", "dowhile", "for", "break", "switch",
  "cases", "iloop", "trycatch", "lblock", "function", "class",
  "params_default", "params", "exp", "lexp", "lop1", "lop2", "lop3",
  "lop4", "aexp", "aop1", "aop2", "aop3", "sexp", "sop1", "sop2",
  "call_identity", "extra_operator", "tern", "notnull", "unity", "inc_dec",
  "assignation", "cexp", "lop_unity", "aop_unity", "sop_unity",
  "class_exp", "arrayexp", "date", "file", "process", "environment",
  "exp_generator", "regexp_op", "iloop_access", "identity", "function_exp",
  "function_lambda", "function_decorator", "function_partial", "list",
  "map", "mapelement", "assig", "array", "parray", "arrayop", "namespace",
  "id", YY_NULLPTR
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,    59,    40,    41,    58,   123,   125,    36,    44,
     126,    61,    38,    33,    60,    62,    43,    45,    42,    47,
      94,    37,    46,    91,    93,    63,    64
};
# endif

#define YYPACT_NINF -925

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-925)))

#define YYTABLE_NINF -464

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2707,   -63,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
   19107, 21403, 21403, 19107,    56, 19107, 19107, 19107, 19107, 19107,
   19107,     7,   -53, 19107,    24,  -925,    16,    16,  -925,    85,
   19271, 17303,   -28,    15, 19107, 10579,    15, 19435,    16,    46,
      26, 19107, 19599,    41,  -925, 19107,    55,    68, 15499, 19107,
   19107, 19107, 19107,    63,   300,   302,   313,   323,   326,   328,
     330,   337,   341,   350,   354,   365,   368,   372,   376,   377,
     378,   379,   383,   384,   385,   387,   388,   390,   393,   394,
     395,   397,   398,   127,   128,   399,   401,   402,   404,   405,
     406,   407,   417,   418,   419,   420,   421,   423,   424,   425,
   21403, 21403, 21403, 21403,  -925, 19763, 17631,    -7,     8, 19107,
   19107,   146,   167,     9,    38,   374,  -925,  2871,   235, 10251,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,   382,   409,  -925,  -925,   296,   103,
     172,   250,  -925,  -925,   269,   154,  -925,  -925,  -925,   202,
    -925,   400,  -925,  -925,  -925,  -925,  -925,   289,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
      50,    60,  -925,   433,    36, 10251,   -59,   426,   447,   340,
       8,  -925,   528,   154,   400,   400,  -925, 19107,   428,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,    12,    16,   429,    64,
    -925,    27,   430,    34,   436,    16, 17795,  -925,  -925,    16,
   19927,  -925,  -925, 19107, 19107, 10743, 15663,  3691,   525,   442,
   10907, 19763,    10,    40,  -925, 19107,    16,  -925,  -925, 19763,
    -925,   443,  -925,  -925, 19107,   444,  -925, 20091, 17467,  3855,
     446,  -925,  -925,  -925,  -925, 19107, 19107, 19107, 19107, 19107,
   19107, 19107, 19107, 19107,   450, 19107, 19107, 19107, 19107, 19107,
   19107, 19107, 19107, 19107, 19107, 19107, 19107,   455, 17959,   458,
     459, 19107,   463, 19107, 19107, 19107,  -925, 19107,  -925, 19107,
   19107, 19107, 19107, 19107, 19107, 19107, 19107, 19107, 19107, 19107,
   19107, 19107, 19107, 19107,   163,   163,   163,   163, 20747, 20911,
   21075, 21239,    -1,  -925,  -925,   465,     6,  -925,   314, 19107,
     588,    42,    16,   -67,   464,   -71,  -925,  -925,  -925,  -925,
      16, 19107,   -81,   461, 19107,  -925,  -925,  3035,  -925, 19107,
   19107, 20583, 20583, 20583,   470, 20255, 20419,  -925, 20583, 20583,
   20583, 20583, 20583, 20583, 20583, 20583, 20583,    16, 18123, 18287,
   18451, 18615,  -925,  -925, 19107, 19107, 19107, 19107, 19107, 19107,
   19107, 19107,    16, 18779,    16,    16,  -925,  -925,   471,  -925,
     462,   -32,  -925,    43,   -79,   476,   -17,   156,    16, 10415,
   18943,  -925,  -925,  -925,  -925,  -925,  -925,   472,   479,  4019,
     375,   492,  3855,   493,   497,  -925,   599,   501,  3199,   507,
   10415,   502,   -36,    15,   604,  4183,  -925,   510,   280,    76,
      16, 19107, 19107,    16,   509,   511,   276,  -925,   512,  -925,
     513,   590,   508,   514,  -925,   -16,   515,   518,   519,   517,
     526,    -9,  -925,   527,   529,   520,    -2,   523,   208,   530,
     531,   532,   533,   534,   535,  -925,  -925,   537,  -925,  -925,
     211,  -925,   536,   538,   494,   498,   539,   542,   540,   546,
     547,   543,   549,   550,   548,   551,   554,   556,   552,   563,
     564, 21403, 21403, 21403, 21403,    48,  -925, 19107, 19107,  -925,
   19927,  -925, 19107,   286,   565,   572,   219,   -15, 19107,    16,
     155,   166,    56,  -925,   -72, 21403,   574,  -925,   409,  -925,
    -925,  -925,  -925, 20583, 20583,  -925, 20583,  -925,   172,   172,
     250,   250,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   231,
    -925,   558,  -925,   559, 19107,   553,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,   560,  -925,  -925,  4347,
     573,   579,   232, 21567,  4511,   580,   581,   234,   582,   583,
    -925,   241,  -925,  -925,   482,   584, 11071,    15,  -925,   422,
     585,  -925, 10415,    15,   628,  -925,  3363,  -925,   569,    15,
    1278,   586,  -925,    16, 19107, 19107,    16, 15335,   587, 15827,
     632,   591,  -925,   343,  -925,   614,   593, 19107, 19107,  -925,
   19107, 19107, 19107, 19107,  -925,  -925,  -925, 19107,  -925,  -925,
   19107,  -925, 19107, 19107,  -925, 19107, 19107,  -925,  -925,  -925,
   19107, 19107,  -925,  -925, 19107, 19107, 19107,    16,    16, 19107,
    -925, 19107,  -925,  -925, 19107,  -925,  -925, 19107, 19107, 19107,
   19107,  -925,  -925,  -925,   163,   163,   163,   163,    16,    17,
     646,  -925,   465,  -925,  -925,    16,   731, 11235, 19107,  -925,
    4675,   592,  -925,   594,    16,   596,   595,   245,  -925,   575,
     163,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925, 19107,
    -925,  -925,   601,  4839,  5003,   597, 19763,   289,   228,  -925,
     602,  5167,  5331,   605, 10415,  -925,  -925, 11399,  -925,   440,
    5495,  -925,   600, 11563, 11727,  -925,  -925,  -925,   608,    15,
    -925,  -925,   610,  -925,   344,   611,   612,   704,    16,  5659,
     613, 19107,  5823,   615, 19107,   305,   616,    16,   617,   618,
    -925,   256,   609,   619,   620,   621,   622,   623,   625,   260,
     627,   629,   263,   630,   631,  -925,  -925,   633,   284,   635,
     634,   636,   638,   640,   216, 19107,    16,    59,   -47,   641,
    5987,  -925,   644,   643,  -925,   645,  6151,    56,  -925,    56,
    6315,   626,  -925,  -925,  -925,  -925,   647,  -925,   648,  6479,
     -43,   649,    61,  -925,  -925,   650,  -925,   651,  6643,   652,
    3855,  -925,   654, 11891,  -925,  1278,   653,  -925,  6807,   449,
     660,  6971,  -925,   661,  -925,   662,  -925, 15991,    16, 19107,
   16155, 19107, 16319,  1278,   658,  -925, 12055,  1278,   659,  -925,
   16483, 19107,   663,  -925,   666,    16,   665,  -925,  -925,  -925,
   19107, 19107, 19107,  -925,  -925,  -925,  -925,  -925,  -925,   291,
    -925,  -925,  -925,  -925,  -925,  -925,  -925, 19107,  -925, 19107,
    -925,  -925,  -925, 19107,    16, 14023,   710,    16,   287, 12219,
      16, 19107, 12383,  1278,   667,  -925, 12547,  -925,  -925,   668,
    -925,  -925,  -925,   669,  7135,  -925,  -925,  -925,   670,  -925,
    -925,  -925,  -925,  -925,  -925,   671,  -925,   672,  -925,  7299,
    -925,   678,  -925,   555,   674, 12711,  -925,   453,  1278,   675,
    -925,  -925,  7463,   681,   680,   682,  7627,   683,   684,  7791,
     688,  -925,  7955,  -925,   689,  -925,  8119,   690,   691, 10415,
    -925,   693, 16647,   694,   295,   639,   695,   696,   698,   297,
     699,   700,   713, 19107,  -925,  3855,    13, 19107,   292, 19107,
      16,  8283,  -925,   692,   298,   701,  8447,  -925,   705,  -925,
    8611,  -925,   706,  -925,  -925,  -925,   702,  -925,  -925,  -925,
    1278,   703,  -925, 12875,  -925,   457,  8775,  -925,   709, 13039,
    -925,  -925,  1278,   707,  -925, 16811, 13203,  1278,   708,  -925,
   16975,  1278,   711,  -925,  1278,   712,  -925,  1278,   714,  -925,
    3527,  -925, 17139,  3855,   715,  -925,  -925, 19107, 19107,  -925,
    -925,  -925,  -925,  -925, 14187, 19107,   716,   717, 19107,  -925,
   14351, 19107,    16, 14515,   726,  1278,   718,  -925, 13367, 19107,
   13531,  1278,   719,  -925,  1278,   720,  -925,  -925,  -925,  3855,
    -925,   721, 13695,  -925,  1278,   723,  -925,  8939,  -925,   729,
    -925,  9103,   730,  9267,  -925,   732,  -925,  9431,   734,  -925,
    -925,  -925,   451,  -925,  3855,   735,   733,  -925,   724,   737,
   19107,  -925,  3855,    88,   739,  -925,    90,   740, 19107,  -925,
    3855,   100,   741,   757, 19107,  -925,  3855,   113, 19107,  -925,
    9595,  -925,   736,   743,  9759,  -925,   746,  -925,  -925,   744,
    -925,  9923,  -925,   748,  -925,  1278,   747,  -925,  1278,   750,
    -925,  1278,   751,  -925,  1278,   752,  -925,  -925,   753,  -925,
    -925,  -925,  -925,   749,   754, 19107,  -925, 14679, 19107,  -925,
    -925,   758,   756, 19107,  -925, 14843, 19107,   760,   759, 19107,
    -925, 15007,  1278,   761,  -925, 13859,  1278,   762,  -925,  -925,
    1278,   763,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   248,
     768, 19107,  -925,  3855,   254,   770,  -925,   255,   772, 19107,
    -925,  3855,   257,   774,  -925,   264,   776, 19107,  -925,  3855,
     271,  -925, 10087,  -925,   765,  -925,  -925, 19107,  -925,  -925,
     778,   777, 19107,  -925,  -925, 19107,  -925,  -925,   779,   780,
   19107,  -925, 15171, 19107,  -925,  -925,   784,   782, 19107,  -925,
    1278,   786,  -925,   787,  -925,   272,   790,   792,  -925,   275,
     795, 19107,  -925,  3855,   279,   796,  -925,   282,   797,  -925,
    -925, 19107,  -925,  -925,  -925, 19107,  -925,  -925,   798,   800,
   19107,  -925,  -925, 19107,  -925,  -925,   799,   801,  -925,   283,
     806,   808,  -925,  -925, 19107,  -925,  -925,  -925,   809,  -925
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
    -925,  -925,   -94,  1547,   319,  1066,    29,  -925,  -925,  -521,
    -925,  -925,  -925,  -925,  -925,  -925,  -924,  -925,  -925,   -34,
    1128,  -925,   -85,  -925,   -10,  -210,  -925,   524,   -99,  -925,
    -286,  -925,   168,   169,   170,   109,  -925,     3,  -925,  -925,
    -925,   -14,  -925,   506,  -925,  -925,  -925,  -925,  -925,  -531,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,   -13,  -513,  -925,
    -925,  -925,  -305,  -925,   310,  -925,  -925,  -925,  -925,  -925,
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
     195,   317,   677,   200,   183,   183,   494,     9,     9,     9,
     208,   212,     9,   326,   216,   328,     9,   222,   322,   119,
     678,   228,   230,   688,     9,   233,     9,     9,   695,   241,
     242,   243,   244,   519,   231,   500,   501,   502,   475,   505,
     507,   365,     9,     9,   998,   365,  1043,   410,     9,     2,
       3,     4,     5,     6,     7,     8,     9,   745,   489,     9,
     489,   235,   491,   378,     9,   551,   365,   590,   488,   175,
     492,   367,   489,   495,   196,   543,   294,   295,   296,   297,
     412,   365,   659,   197,   362,   302,   305,   849,   850,   316,
     205,   869,   851,   183,   183,   183,   183,   337,   354,   478,
     199,   371,   540,  -463,   374,   213,   376,   489,  1097,   355,
     356,   357,   358,   359,   360,   361,   575,   545,   589,  1105,
    -210,  1108,   489,   590,  -210,   596,   309,     9,     9,   310,
     597,  1113,   601,   476,   477,   770,   119,   602,   119,   318,
     196,   311,   411,   479,  1119,   480,   370,   999,   214,   197,
     312,   320,   746,   771,   320,     9,     9,   201,   784,   226,
     319,   375,   321,   114,   114,   114,     9,   368,   114,   320,
     379,   366,   114,   232,   324,   413,   485,   541,   347,   225,
     114,   638,   114,   114,   320,   320,   383,  -262,   234,   187,
     386,   578,   847,   387,   119,   871,   245,   402,   114,   114,
     236,   408,   111,   112,   114,   414,   320,   662,   663,   416,
     664,   576,   114,   363,   418,   114,   486,   208,   212,   402,
     114,   499,  1106,   497,  1109,   422,   423,   424,   426,   427,
     428,   429,   430,   431,  1114,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,  1120,   447,   338,
     339,   450,  -275,   452,   453,   454,   843,   455,   886,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   294,   295,   296,   297,   542,  1167,
     275,   277,   547,   114,   114,  1172,  1175,   348,  1180,   483,
     546,   183,   183,   183,   183,  1183,  -262,   654,   320,   732,
     656,   424,  1188,  1211,   496,   331,  1215,   349,   320,   117,
    1220,   114,   114,  1223,  1234,   475,   350,   573,   351,   475,
     340,   341,   114,   645,   646,   344,   345,   929,   424,   521,
     523,   525,  1001,   -49,   526,   527,   528,   529,   530,   531,
     532,   533,   604,   536,   218,   613,   119,   605,   811,   812,
     614,   844,   954,   651,   705,   350,   960,   351,   489,   568,
     424,  -275,   332,   333,   325,   665,   675,   327,   683,   402,
     590,   489,   402,   489,   -49,   686,   916,   917,   918,   761,
     590,  -275,  1168,  -275,   489,   402,   -49,   -49,  1173,  1176,
     819,  1181,   579,   329,   828,   820,   657,   832,  1184,   829,
     342,   343,   590,   352,   353,  1189,  1212,   556,   557,  1216,
     583,   477,   574,  1221,   476,   477,  1224,  1235,   836,   330,
     647,   346,   930,   837,  1023,   648,   117,  1002,   117,   986,
     354,   992,  1008,   246,   987,   247,   590,  1009,   364,   334,
     335,   336,   813,   514,   515,   516,   248,   634,   635,   636,
     637,   481,   209,   482,   694,   557,   249,   640,   641,   250,
     642,   251,   644,   252,   183,   183,   183,   183,   652,   658,
     253,   660,   783,   557,   254,   -49,   310,   -49,   797,   798,
     -49,   885,   557,   255,   117,   959,   557,   256,   183,  1022,
     557,  -328,  -328,  -328,   811,   812,   508,   509,   257,   510,
     511,   258,   512,   513,   668,   259,  -328,   184,   185,   260,
     261,   262,   263,   693,   687,   557,   264,   265,   266,   698,
     267,   268,   919,   269,   390,   702,   270,   271,   272,   406,
     273,   274,   279,   365,   280,   281,   183,   282,   283,   284,
     285,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
     286,   287,   288,   289,   290,   706,   291,   292,   293,   201,
     369,   403,   373,   377,  -328,  -328,  -328,   718,   719,   380,
     720,   721,   722,   723,   404,   417,   419,   724,   421,  -328,
     725,   484,   726,   727,   432,   728,   729,   953,   557,   445,
     730,   731,   448,   449,   424,   733,   734,   451,   539,   737,
     478,   738,   492,   490,   739,   476,   552,   740,   741,   742,
     743,   503,   544,   553,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,   559,   561,  -328,  -328,   753,   562,
    -328,  -328,  -328,  -328,  -328,   563,   117,  -328,   564,   566,
     569,  -459,   572,   581,   586,   582,   584,   587,   617,   763,
     585,   594,   618,   588,   591,   795,   302,   592,   593,   600,
     595,   598,   603,   599,   699,   607,   608,   609,   716,   606,
     402,   612,   714,   610,   611,   615,   620,   616,   619,   621,
     622,   623,   624,   625,   626,   747,   631,   627,   669,   402,
     628,   806,   402,   629,   810,   630,  -328,   632,   633,  -328,
    -328,   701,   649,  -328,  -328,  -328,  -328,  -328,   650,   673,
    -328,   661,   666,   667,   670,   674,   681,   682,   684,   711,
     685,   689,   696,   703,   749,   845,   717,   715,   756,   762,
     402,   760,   787,   769,   860,   757,   861,   759,   764,   773,
     794,   778,   796,   799,   801,   805,   800,   809,   821,   815,
     927,   817,   818,   995,   823,   824,   825,   826,   822,   827,
     402,   830,   864,   831,   833,   834,  1068,   835,   402,   838,
     840,   402,   841,   839,   842,   852,   855,   856,   988,   895,
     643,   898,   857,   870,   865,   866,   878,   872,   873,   876,
     882,   908,   887,   890,   891,   901,   905,  1116,   909,   912,
     913,   914,   915,   910,   939,   943,   944,   947,   948,   949,
     952,   955,   961,   964,   965,   969,   966,   424,   970,   920,
     973,   976,   979,   921,  1007,     0,   980,   982,   985,   989,
     990,   935,   991,   993,   994,  1010,     0,  1013,  1016,  1017,
    1018,  1026,     0,   498,  1030,  1036,     0,  1047,  1039,  1040,
    1055,  1041,     0,  1080,  1056,  1069,  1077,  1078,  1101,   402,
    1084,  1087,  1090,     0,  1093,   691,  1096,  1099,  1124,     0,
    1100,  1102,   402,  1107,  1110,  1115,   402,  1125,  1128,   402,
    1132,  1129,   402,  1138,  1133,     0,   402,  1134,  1135,  1136,
    1137,  1139,  1146,  1147,  1154,     0,  1155,  1192,  1161,  1165,
    1166,   174,  1169,   996,  1174,   402,  1177,  1000,  1182,  1003,
    1185,   402,  1194,  1198,  1195,   189,   402,  1199,  1206,  1207,
     402,  1210,   198,  1209,  1213,   202,  1214,   203,   204,  1217,
    1222,  1225,  1228,  1232,     0,  1233,   402,  1229,   223,   224,
    1236,   227,  1237,  1239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   751,     0,     0,     0,
       0,     0,     0,   402,     0,     0,     0,  1048,  1049,     0,
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
     174,     0,     0,     0,     0,     0,     0,  -328,  -328,  -328,
     174,     0,     0,   174,     0,     0,     0,     0,     0,   174,
       0,   174,  -328,     0,     0,     0,   174,     0,     0,     0,
       0,   577,     0,     0,   580,     0,     0,  1071,     0,  1075,
       0,     0,     0,     0,   382,     0,     0,     0,   385,     0,
       0,  1082,     0,     0,     0,   401,     0,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   639,     0,     0,     0,
       0,     0,     0,   118,     0,     0,     0,     0,     0,     0,
     653,   655,   323,   189,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -328,
       0,     0,  -328,  -328,     0,     0,  -328,  -328,  -328,  -328,
    -328,     0,     0,  -328,  1163,     0,     0,     0,     0,     0,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   395,   105,     0,     0,   106,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   395,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   395,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,   105,     0,     0,   389,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,   105,     0,     0,   788,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,   105,     0,     0,   936,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,   105,     0,     0,  1033,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,   105,   924,     0,   925,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,  1065,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,   105,  1150,     0,  1151,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,   105,     0,     0,   392,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,   105,     0,     0,   906,
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
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   221,     0,
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
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,     0,
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
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
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
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
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
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,   105,   473,
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
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
     676,     0,     0,   106,     0,   179,     0,   180,     0,   109,
       0,     0,     0,   111,   112,     0,     0,     0,     0,     0,
     113,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      10,    14,    36,    13,   214,    15,    16,    17,    18,    19,
      20,   110,   543,    23,    11,    12,   321,    10,    10,    10,
      30,    31,    10,   117,    34,   119,    10,    37,   113,     0,
     543,    41,    42,   554,    10,    45,    10,    10,   559,    49,
      50,    51,    52,   348,     3,   331,   332,   333,    49,   335,
     336,    15,    10,    10,    41,    15,   980,    47,    10,     3,
       4,     5,     6,     7,     8,     9,    10,    50,   149,    10,
     149,     3,   143,    39,    10,   380,    15,   149,   145,   142,
     151,   175,   149,   164,   143,   164,   100,   101,   102,   103,
      50,    15,   164,   152,    34,   105,   106,   144,   145,   109,
      15,   144,   149,   100,   101,   102,   103,     4,   151,   145,
     163,   196,   144,   149,   199,   143,   201,   149,  1042,    69,
      70,    71,    72,    73,    74,    75,    50,   144,   144,    41,
     145,    41,   149,   149,   149,   144,   143,    10,    10,   146,
     149,    41,   144,   144,   145,   676,   117,   149,   119,     3,
     143,   143,   142,   147,    41,   149,   144,   144,   143,   152,
     152,   152,   145,   676,   152,    10,    10,   143,   689,   143,
       3,   144,   163,   166,   166,   166,    10,   187,   166,   152,
     146,   145,   166,   142,   146,   145,   144,   144,    34,   143,
     166,   143,   166,   166,   152,   152,   206,    34,   143,   143,
     210,   411,   143,   213,   175,   144,   143,   217,   166,   166,
     142,   221,   156,   157,   166,   225,   152,   503,   504,   229,
     506,   145,   166,   163,   234,   166,   311,   237,   238,   239,
     166,   330,   144,   327,   144,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   144,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   144,   268,   156,
     157,   271,    34,   273,   274,   275,    50,   277,   789,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   298,   299,   300,   301,   373,    41,
     163,   163,   377,   166,   166,    41,    41,   143,    41,   309,
     144,   298,   299,   300,   301,    41,   143,   152,   152,   614,
     144,   321,    41,    41,   324,    19,    41,   163,   152,     0,
      41,   166,   166,    41,    41,    49,   163,    47,   165,    49,
     158,   159,   166,    47,    48,    66,    67,    50,   348,   349,
     350,   351,    50,     0,   354,   355,   356,   357,   358,   359,
     360,   361,   144,   363,    35,   144,   327,   149,    53,    54,
     149,   145,   883,   144,   574,   163,   887,   165,   149,   403,
     380,   143,    76,    77,     0,   144,   144,   142,   144,   389,
     149,   149,   392,   149,    41,   144,    95,    96,    97,   144,
     149,   163,   144,   165,   149,   405,    53,    54,   144,   144,
     144,   144,   412,    21,   144,   149,   491,   144,   144,   149,
     160,   161,   149,    13,    14,   144,   144,    42,    43,   144,
     144,   145,   142,   144,   144,   145,   144,   144,   144,    20,
     144,   162,   145,   149,   955,   149,   117,   145,   119,   144,
     151,   144,   144,   143,   149,   143,   149,   149,    15,   153,
     154,   155,   147,   344,   345,   346,   143,   471,   472,   473,
     474,   147,    15,   149,    42,    43,   143,   477,   478,   143,
     480,   143,   482,   143,   471,   472,   473,   474,   488,   492,
     143,   495,    42,    43,   143,   142,   146,   144,   144,   145,
     147,    42,    43,   143,   175,    42,    43,   143,   495,    42,
      43,    19,    20,    21,    53,    54,   338,   339,   143,   340,
     341,   143,   342,   343,   524,   143,    34,    11,    12,   143,
     143,   143,   143,   557,    42,    43,   143,   143,   143,   563,
     143,   143,   837,   143,   215,   569,   143,   143,   143,   220,
     143,   143,   143,    15,   143,   143,   543,   143,   143,   143,
     143,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     143,   143,   143,   143,   143,   575,   143,   143,   143,   143,
     142,    46,   143,   143,    19,    20,    21,   587,   588,   143,
     590,   591,   592,   593,   142,   142,   142,   597,   142,    34,
     600,     3,   602,   603,   144,   605,   606,    42,    43,   144,
     610,   611,   144,   144,   614,   615,   616,   144,   146,   619,
     145,   621,   151,   149,   624,   144,   144,   627,   628,   629,
     630,   151,   146,   144,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   151,   142,   142,   154,   155,   648,   142,
     158,   159,   160,   161,   162,    46,   327,   165,   147,   142,
      46,   149,   142,   144,    64,   144,   144,   149,   164,   669,
     147,   144,   164,   149,   149,   699,   676,   149,   149,   149,
     144,   144,   149,   144,    46,   144,   144,   144,    64,   149,
     690,   144,    50,   149,   149,   149,   144,   149,   149,   149,
     144,   144,   149,   144,   144,    49,   144,   149,   145,   709,
     149,   711,   712,   149,   714,   149,   151,   144,   144,   154,
     155,   142,   147,   158,   159,   160,   161,   162,   146,   146,
     165,   147,   164,   164,   164,   146,   146,   146,   146,   142,
     147,   147,   147,   147,     3,   745,   143,   146,   146,   164,
     750,   146,   142,   146,   757,   151,   759,   151,   147,   147,
     142,   146,   142,   142,    50,   142,   144,   142,   149,   143,
      50,   144,   144,    50,   144,   144,   144,   144,   149,   144,
     780,   144,   146,   144,   144,   144,    50,   144,   788,   144,
     144,   791,   144,   149,   144,   144,   142,   144,   149,   799,
     480,   801,   147,   144,   147,   147,   142,   147,   147,   147,
     147,   811,   142,   142,   142,   147,   147,    50,   145,   144,
     820,   821,   822,   147,   147,   147,   147,   147,   147,   147,
     142,   147,   147,   142,   144,   142,   144,   837,   144,   839,
     142,   142,   142,   843,   142,    -1,   145,   144,   144,   144,
     144,   851,   144,   144,   144,   144,    -1,   142,   142,   147,
     147,   142,    -1,   329,   147,   147,    -1,   142,   147,   147,
     144,   147,    -1,   142,   147,   147,   147,   147,   144,   879,
     147,   142,   142,    -1,   142,   556,   142,   142,   142,    -1,
     147,   144,   892,   144,   144,   144,   896,   144,   142,   899,
     142,   147,   902,   144,   147,    -1,   906,   147,   147,   147,
     147,   147,   144,   147,   144,    -1,   147,   142,   147,   147,
     147,     0,   144,   923,   144,   925,   144,   927,   144,   929,
     144,   931,   144,   144,   147,    14,   936,   147,   144,   147,
     940,   144,    21,   147,   144,    24,   144,    26,    27,   144,
     144,   144,   144,   144,    -1,   144,   956,   147,    37,    38,
     144,    40,   144,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   647,    -1,    -1,    -1,
      -1,    -1,    -1,   983,    -1,    -1,    -1,   987,   988,    -1,
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
     379,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
     389,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,   398,
      -1,   400,    34,    -1,    -1,    -1,   405,    -1,    -1,    -1,
      -1,   410,    -1,    -1,   413,    -1,    -1,  1008,    -1,  1010,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,    -1,
      -1,  1022,    -1,    -1,    -1,   217,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,    -1,
     489,   490,   491,   492,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,   154,   155,    -1,    -1,   158,   159,   160,   161,
     162,    -1,    -1,   165,  1125,    -1,    -1,    -1,    -1,    -1,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,     0,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,     0,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
       1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,    -1,    -1,   146,   147,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,     1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,     1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,     1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,   144,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,   144,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,   144,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,   144,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,   144,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,   144,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,   144,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,   144,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
     145,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,   147,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,   144,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,   144,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,   164,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,   164,    -1,   166,     3,     4,
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
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
     145,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,   164,    -1,   166,     3,     4,     5,     6,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,   144,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,    -1,
      -1,   146,    -1,   148,    -1,   150,   151,   152,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,   144,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166,     3,     4,     5,     6,     7,     8,
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
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   143,   144,    -1,   146,    -1,   148,
      -1,   150,    -1,   152,    -1,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   166,     3,     4,
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
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,   144,
      -1,   146,    -1,   148,    -1,   150,    -1,   152,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,     3,     4,     5,     6,     7,     8,     9,    10,
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
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,    -1,   143,   144,    -1,   146,    -1,   148,    -1,   150,
      -1,   152,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,     3,     4,     5,     6,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,    -1,   146,
      -1,   148,    -1,   150,    -1,   152,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,   166,
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
     123,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,
     143,    -1,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   166
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
     138,   139,   140,   141,   142,   143,   146,   148,   150,   152,
     153,   156,   157,   163,   166,   168,   169,   171,   172,   173,
     174,   175,   177,   178,   179,   180,   181,   182,   184,   185,
     187,   188,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     232,   234,   235,   236,   237,   142,    27,    30,    38,   148,
     150,   191,   237,   204,   210,   210,   191,   143,   224,   237,
     191,   191,   191,   191,   191,   191,   143,   152,   237,   163,
     191,   143,   237,   237,   237,    15,    38,   187,   191,    15,
      37,   187,   191,   143,   143,   186,   191,   146,   171,   172,
     186,   143,   191,   237,   237,   143,   143,   237,   191,   143,
     191,     3,   142,   191,   143,     3,   142,    37,    38,   146,
     172,   191,   191,   191,   191,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   163,   237,   163,   237,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   208,   208,   208,   208,   138,   139,
     140,   141,   191,   147,   187,   191,   230,   231,   233,   143,
     146,   143,   152,   189,   190,   237,   191,   195,     3,     3,
     152,   163,   189,   237,   146,     0,   169,   142,   169,    21,
      20,    19,    76,    77,   153,   154,   155,     4,   156,   157,
     158,   159,   160,   161,    66,    67,   162,    34,   143,   163,
     163,   165,    13,    14,   151,    69,    70,    71,    72,    73,
      74,    75,    34,   163,    15,    15,   145,   169,   191,   142,
     144,   189,   237,   143,   189,   144,   189,   143,    39,   146,
     143,   237,   187,   191,   237,   187,   191,   191,   192,   146,
     171,   172,   146,   172,     1,   142,   147,   170,   171,   172,
     173,   187,   191,    46,   142,   146,   171,   172,   191,   237,
      47,   142,    50,   145,   191,   237,   191,   142,   191,   142,
     170,   142,   191,   191,   191,   229,   191,   191,   191,   191,
     191,   191,   144,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   144,   144,   191,   144,   144,
     191,   144,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   144,   144,   144,   144,    49,   144,   145,   145,   147,
     149,   147,   149,   191,     3,   144,   189,   237,   145,   149,
     149,   143,   151,   237,   229,   164,   191,   169,   194,   195,
     197,   197,   197,   151,   151,   197,   151,   197,   199,   199,
     200,   200,   201,   201,   202,   202,   202,   237,   144,   229,
     164,   191,   164,   191,   145,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   237,   164,   191,   237,   237,   146,
     144,   144,   189,   164,   146,   144,   144,   189,   237,   170,
     144,   229,   144,   144,   147,   170,    42,    43,   176,   142,
     170,   142,   142,    46,   147,   170,   142,   170,   186,    46,
     147,   170,   142,    47,   142,    50,   145,   237,   192,   191,
     237,   144,   144,   144,   144,   147,    64,   149,   149,   144,
     149,   149,   149,   149,   144,   144,   144,   149,   144,   144,
     149,   144,   149,   149,   144,   149,   149,   144,   144,   144,
     149,   149,   144,   144,   149,   149,   149,   164,   164,   149,
     144,   149,   144,   144,   149,   144,   144,   149,   149,   149,
     149,   144,   144,   144,   208,   208,   208,   208,   143,   237,
     191,   191,   191,   231,   191,    47,    48,   144,   149,   147,
     146,   144,   191,   237,   152,   237,   144,   189,   224,   164,
     208,   147,   197,   197,   197,   144,   164,   164,   191,   145,
     164,   147,   170,   146,   146,   144,   143,   216,   225,   147,
     170,   146,   146,   144,   146,   147,   144,    42,   176,   147,
     146,   171,   172,   186,    42,   176,   147,   170,   186,    46,
     170,   142,   186,   147,   237,   192,   191,   237,   145,   146,
     172,   142,   146,   172,    50,   146,    64,   143,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   229,   191,   191,   237,   237,   191,   191,   191,
     191,   191,   191,   191,   237,    50,   145,    49,   237,     3,
     146,   171,   172,   191,   147,   170,   146,   151,   237,   151,
     146,   144,   164,   191,   147,   147,   170,   147,   170,   146,
     216,   225,   237,   147,   147,   170,   147,   170,   146,   170,
     146,   171,   172,    42,   176,   147,   170,   142,   146,   171,
     172,   146,   171,   172,   142,   186,   142,   144,   145,   142,
     144,    50,   237,   147,   170,   142,   191,   147,   170,   142,
     191,    53,    54,   147,   183,   143,   237,   144,   144,   144,
     149,   149,   149,   144,   144,   144,   144,   144,   144,   149,
     144,   144,   144,   144,   144,   144,   144,   149,   144,   149,
     144,   144,   144,    50,   145,   191,   237,   143,   237,   144,
     145,   149,   144,   147,   170,   142,   144,   147,   147,   170,
     224,   224,   147,   170,   146,   147,   147,   147,   170,   144,
     144,   144,   147,   147,   147,   170,   147,   170,   142,   146,
     171,   172,   147,   147,   170,    42,   176,   142,   147,   170,
     142,   142,   146,   172,   237,   191,   146,   172,   191,   146,
     172,   147,   146,   171,   172,   147,   146,   172,   191,   145,
     147,   237,   144,   191,   191,   191,    95,    96,    97,   229,
     191,   191,   237,    41,   144,   146,   172,    50,   237,    50,
     145,   146,   171,   172,   237,   191,   146,   171,   172,   147,
     146,   171,   172,   147,   147,   147,   170,   147,   147,   147,
     147,   170,   142,    42,   176,   147,   146,   171,   172,    42,
     176,   147,   147,   170,   142,   144,   144,   147,   170,   142,
     144,   147,   170,   142,   147,   170,   142,   147,   170,   142,
     145,   170,   144,   146,   172,   144,   144,   149,   149,   144,
     144,   144,   144,   144,   144,    50,   191,   170,    41,   144,
     191,    50,   145,   191,   237,   147,   170,   142,   144,   149,
     144,   147,   170,   142,   147,   170,   142,   147,   147,   146,
     171,   172,    42,   176,   147,   170,   142,   146,   171,   172,
     147,   146,   172,   146,   171,   172,   147,   146,   172,   147,
     147,   147,   170,   183,   146,   172,   170,   142,   191,   191,
      41,   144,   146,   172,   191,   144,   147,   191,    41,   144,
     146,   172,   191,   237,    41,   144,   146,   172,    50,   147,
     146,   171,   172,   191,   146,   171,   172,   147,   147,   170,
     142,   146,   171,   172,   147,   147,   170,   142,   147,   170,
     142,   147,   170,   142,   147,   170,   142,   183,   170,   142,
     147,   144,   144,   191,   170,    41,   144,   144,    41,   144,
     144,   191,   170,    41,   144,   144,    50,   191,   170,    41,
     144,   191,   147,   170,   142,   144,   147,   170,   142,   147,
     147,   170,   142,   147,   147,   147,   147,   147,   144,   147,
     191,    41,   144,   146,   172,   191,   144,   147,   191,    41,
     144,   146,   172,   191,   144,   147,   191,    41,   144,   146,
     172,   147,   146,   171,   172,   147,   147,    41,   144,   144,
     191,   170,    41,   144,   144,    41,   144,   144,   191,   170,
      41,   144,   144,    41,   144,   144,   191,   170,    41,   144,
     147,   170,   142,   191,   144,   147,   191,   191,   144,   147,
     191,    41,   144,   146,   172,   191,   144,   147,   191,   147,
     144,    41,   144,   144,   144,    41,   144,   144,   191,   170,
      41,   144,   144,    41,   144,   144,   191,   191,   144,   147,
     191,   191,   144,   144,    41,   144,   144,   144,   191,   144
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   167,   168,   168,   169,   169,   169,   169,   169,   169,
     169,   169,   170,   170,   170,   170,   170,   170,   170,   170,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   173,   174,   174,   174,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   177,   177,   178,   178,   178,   178,   179,   179,
     179,   179,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   181,   181,   181,   181,   182,   182,
     183,   183,   183,   183,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   185,   185,   185,   185,   186,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   188,
     188,   188,   188,   189,   189,   189,   189,   190,   190,   190,
     190,   191,   192,   193,   193,   194,   194,   195,   195,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   197,   198,
     198,   198,   198,   199,   199,   199,   200,   200,   200,   201,
     202,   202,   202,   202,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   204,   204,   204,   205,   206,   206,   206,
     206,   207,   207,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   209,   209,   209,
     209,   209,   210,   210,   210,   210,   210,   210,   210,   210,
     211,   211,   211,   211,   211,   211,   211,   211,   212,   212,
     212,   212,   212,   212,   212,   213,   213,   213,   213,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   215,
     215,   215,   215,   215,   215,   215,   216,   216,   216,   216,
     216,   217,   217,   217,   217,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   220,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     222,   222,   222,   222,   223,   223,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   225,   225,   225,
     225,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   228,   228,   228,   228,
     228,   228,   229,   229,   229,   230,   230,   230,   231,   231,
     232,   232,   233,   233,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   236,   236,   236,   236,   237,   237
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
#line 91 "lshParser.y" /* yacc.c:684  */
      { fprintf (yyoutput, "%s", *((*yyvaluep).str)); }
#line 5948 "lshParser.c" /* yacc.c:684  */
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
#line 98 "lshParser.y" /* yacc.c:1646  */
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
#line 6588 "lshParser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 113 "lshParser.y" /* yacc.c:1646  */
    { ;}
#line 6594 "lshParser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "lshParser.y" /* yacc.c:1646  */
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
#line 6609 "lshParser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 127 "lshParser.y" /* yacc.c:1646  */
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
#line 6624 "lshParser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 137 "lshParser.y" /* yacc.c:1646  */
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
#line 6639 "lshParser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 147 "lshParser.y" /* yacc.c:1646  */
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
#line 6654 "lshParser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 157 "lshParser.y" /* yacc.c:1646  */
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
#line 6669 "lshParser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 167 "lshParser.y" /* yacc.c:1646  */
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
#line 6684 "lshParser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 177 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6690 "lshParser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 178 "lshParser.y" /* yacc.c:1646  */
    { 
         (yyval.data) = new noNode ();
      }
#line 6698 "lshParser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "lshParser.y" /* yacc.c:1646  */
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
#line 6713 "lshParser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 194 "lshParser.y" /* yacc.c:1646  */
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
#line 6728 "lshParser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 204 "lshParser.y" /* yacc.c:1646  */
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
#line 6743 "lshParser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 214 "lshParser.y" /* yacc.c:1646  */
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
#line 6758 "lshParser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 224 "lshParser.y" /* yacc.c:1646  */
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
#line 6773 "lshParser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 234 "lshParser.y" /* yacc.c:1646  */
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
#line 6788 "lshParser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 244 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6794 "lshParser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 245 "lshParser.y" /* yacc.c:1646  */
    {(yyval.data) = new noNode ();}
#line 6800 "lshParser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 250 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6806 "lshParser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 6812 "lshParser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 252 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 6818 "lshParser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 253 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6824 "lshParser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 254 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6830 "lshParser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 255 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6836 "lshParser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 256 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6842 "lshParser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 257 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6848 "lshParser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 258 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6854 "lshParser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 259 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6860 "lshParser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 263 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 6866 "lshParser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 264 "lshParser.y" /* yacc.c:1646  */
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
#line 6881 "lshParser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 274 "lshParser.y" /* yacc.c:1646  */
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
#line 6896 "lshParser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 284 "lshParser.y" /* yacc.c:1646  */
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
#line 6911 "lshParser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 294 "lshParser.y" /* yacc.c:1646  */
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
#line 6926 "lshParser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 304 "lshParser.y" /* yacc.c:1646  */
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
#line 6941 "lshParser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 314 "lshParser.y" /* yacc.c:1646  */
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
#line 6956 "lshParser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 324 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new returnNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("returnNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 6970 "lshParser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 333 "lshParser.y" /* yacc.c:1646  */
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
#line 6985 "lshParser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 343 "lshParser.y" /* yacc.c:1646  */
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
#line 7000 "lshParser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 353 "lshParser.y" /* yacc.c:1646  */
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
#line 7015 "lshParser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 363 "lshParser.y" /* yacc.c:1646  */
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
#line 7030 "lshParser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 373 "lshParser.y" /* yacc.c:1646  */
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
#line 7052 "lshParser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 390 "lshParser.y" /* yacc.c:1646  */
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
#line 7074 "lshParser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 407 "lshParser.y" /* yacc.c:1646  */
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
#line 7096 "lshParser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 424 "lshParser.y" /* yacc.c:1646  */
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
#line 7118 "lshParser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 441 "lshParser.y" /* yacc.c:1646  */
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
#line 7133 "lshParser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 451 "lshParser.y" /* yacc.c:1646  */
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
#line 7148 "lshParser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 461 "lshParser.y" /* yacc.c:1646  */
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
#line 7163 "lshParser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 471 "lshParser.y" /* yacc.c:1646  */
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
#line 7178 "lshParser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 481 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r =new exitNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("exitNode", "stmt", NULL,0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 7192 "lshParser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 490 "lshParser.y" /* yacc.c:1646  */
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
#line 7207 "lshParser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 503 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].idnode); }
#line 7213 "lshParser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 507 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 7219 "lshParser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 508 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 7225 "lshParser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 510 "lshParser.y" /* yacc.c:1646  */
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
#line 7240 "lshParser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 523 "lshParser.y" /* yacc.c:1646  */
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
#line 7256 "lshParser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 534 "lshParser.y" /* yacc.c:1646  */
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
#line 7272 "lshParser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 545 "lshParser.y" /* yacc.c:1646  */
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
#line 7295 "lshParser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 563 "lshParser.y" /* yacc.c:1646  */
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
#line 7311 "lshParser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 574 "lshParser.y" /* yacc.c:1646  */
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
#line 7327 "lshParser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 585 "lshParser.y" /* yacc.c:1646  */
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
#line 7343 "lshParser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 596 "lshParser.y" /* yacc.c:1646  */
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
#line 7359 "lshParser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 607 "lshParser.y" /* yacc.c:1646  */
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
#line 7382 "lshParser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 625 "lshParser.y" /* yacc.c:1646  */
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
#line 7405 "lshParser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 643 "lshParser.y" /* yacc.c:1646  */
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
#line 7421 "lshParser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 654 "lshParser.y" /* yacc.c:1646  */
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
#line 7437 "lshParser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 665 "lshParser.y" /* yacc.c:1646  */
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
#line 7460 "lshParser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 683 "lshParser.y" /* yacc.c:1646  */
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
#line 7483 "lshParser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 701 "lshParser.y" /* yacc.c:1646  */
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
#line 7513 "lshParser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 726 "lshParser.y" /* yacc.c:1646  */
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
#line 7536 "lshParser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 744 "lshParser.y" /* yacc.c:1646  */
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
#line 7552 "lshParser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 755 "lshParser.y" /* yacc.c:1646  */
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
#line 7568 "lshParser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 766 "lshParser.y" /* yacc.c:1646  */
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
#line 7591 "lshParser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 784 "lshParser.y" /* yacc.c:1646  */
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
#line 7607 "lshParser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 795 "lshParser.y" /* yacc.c:1646  */
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
#line 7623 "lshParser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 806 "lshParser.y" /* yacc.c:1646  */
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
#line 7639 "lshParser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 817 "lshParser.y" /* yacc.c:1646  */
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
#line 7663 "lshParser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 836 "lshParser.y" /* yacc.c:1646  */
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
#line 7679 "lshParser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 850 "lshParser.y" /* yacc.c:1646  */
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
#line 7695 "lshParser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 861 "lshParser.y" /* yacc.c:1646  */
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
#line 7711 "lshParser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 872 "lshParser.y" /* yacc.c:1646  */
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
#line 7734 "lshParser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 890 "lshParser.y" /* yacc.c:1646  */
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
#line 7750 "lshParser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 901 "lshParser.y" /* yacc.c:1646  */
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
#line 7766 "lshParser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 912 "lshParser.y" /* yacc.c:1646  */
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
#line 7782 "lshParser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 923 "lshParser.y" /* yacc.c:1646  */
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
#line 7798 "lshParser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 934 "lshParser.y" /* yacc.c:1646  */
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
#line 7821 "lshParser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 952 "lshParser.y" /* yacc.c:1646  */
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
#line 7844 "lshParser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 970 "lshParser.y" /* yacc.c:1646  */
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
#line 7860 "lshParser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 981 "lshParser.y" /* yacc.c:1646  */
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
#line 7876 "lshParser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 992 "lshParser.y" /* yacc.c:1646  */
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
#line 7899 "lshParser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1010 "lshParser.y" /* yacc.c:1646  */
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
#line 7922 "lshParser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1028 "lshParser.y" /* yacc.c:1646  */
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
#line 7952 "lshParser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1053 "lshParser.y" /* yacc.c:1646  */
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
#line 7975 "lshParser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1071 "lshParser.y" /* yacc.c:1646  */
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
#line 7991 "lshParser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1082 "lshParser.y" /* yacc.c:1646  */
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
#line 8007 "lshParser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1093 "lshParser.y" /* yacc.c:1646  */
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
#line 8030 "lshParser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1111 "lshParser.y" /* yacc.c:1646  */
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
#line 8046 "lshParser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1122 "lshParser.y" /* yacc.c:1646  */
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
#line 8062 "lshParser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1133 "lshParser.y" /* yacc.c:1646  */
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
#line 8078 "lshParser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1144 "lshParser.y" /* yacc.c:1646  */
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
#line 8101 "lshParser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1162 "lshParser.y" /* yacc.c:1646  */
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
#line 8117 "lshParser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1176 "lshParser.y" /* yacc.c:1646  */
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
#line 8133 "lshParser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1187 "lshParser.y" /* yacc.c:1646  */
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
#line 8156 "lshParser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1208 "lshParser.y" /* yacc.c:1646  */
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
#line 8172 "lshParser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1219 "lshParser.y" /* yacc.c:1646  */
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
#line 8188 "lshParser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1230 "lshParser.y" /* yacc.c:1646  */
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
#line 8211 "lshParser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1248 "lshParser.y" /* yacc.c:1646  */
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
#line 8227 "lshParser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1262 "lshParser.y" /* yacc.c:1646  */
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
#line 8243 "lshParser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1273 "lshParser.y" /* yacc.c:1646  */
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
#line 8259 "lshParser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1284 "lshParser.y" /* yacc.c:1646  */
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
#line 8282 "lshParser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1302 "lshParser.y" /* yacc.c:1646  */
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
#line 8298 "lshParser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1316 "lshParser.y" /* yacc.c:1646  */
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
#line 8314 "lshParser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1327 "lshParser.y" /* yacc.c:1646  */
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
#line 8330 "lshParser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1338 "lshParser.y" /* yacc.c:1646  */
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
#line 8353 "lshParser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1356 "lshParser.y" /* yacc.c:1646  */
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
#line 8369 "lshParser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1367 "lshParser.y" /* yacc.c:1646  */
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
#line 8385 "lshParser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1378 "lshParser.y" /* yacc.c:1646  */
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
#line 8401 "lshParser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1389 "lshParser.y" /* yacc.c:1646  */
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
#line 8424 "lshParser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1407 "lshParser.y" /* yacc.c:1646  */
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
#line 8440 "lshParser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1418 "lshParser.y" /* yacc.c:1646  */
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
#line 8456 "lshParser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1429 "lshParser.y" /* yacc.c:1646  */
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
#line 8472 "lshParser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1440 "lshParser.y" /* yacc.c:1646  */
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
#line 8488 "lshParser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1451 "lshParser.y" /* yacc.c:1646  */
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
#line 8504 "lshParser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1462 "lshParser.y" /* yacc.c:1646  */
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
#line 8520 "lshParser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1473 "lshParser.y" /* yacc.c:1646  */
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
#line 8536 "lshParser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1484 "lshParser.y" /* yacc.c:1646  */
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
#line 8552 "lshParser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1495 "lshParser.y" /* yacc.c:1646  */
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
#line 8568 "lshParser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1506 "lshParser.y" /* yacc.c:1646  */
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
#line 8584 "lshParser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1517 "lshParser.y" /* yacc.c:1646  */
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
#line 8600 "lshParser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1528 "lshParser.y" /* yacc.c:1646  */
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
#line 8616 "lshParser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1539 "lshParser.y" /* yacc.c:1646  */
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
#line 8632 "lshParser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1550 "lshParser.y" /* yacc.c:1646  */
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
#line 8648 "lshParser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1561 "lshParser.y" /* yacc.c:1646  */
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
#line 8664 "lshParser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1572 "lshParser.y" /* yacc.c:1646  */
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
#line 8680 "lshParser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1583 "lshParser.y" /* yacc.c:1646  */
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
#line 8696 "lshParser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1594 "lshParser.y" /* yacc.c:1646  */
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
#line 8712 "lshParser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1605 "lshParser.y" /* yacc.c:1646  */
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
#line 8728 "lshParser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1616 "lshParser.y" /* yacc.c:1646  */
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
#line 8744 "lshParser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1627 "lshParser.y" /* yacc.c:1646  */
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
#line 8760 "lshParser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1638 "lshParser.y" /* yacc.c:1646  */
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
#line 8776 "lshParser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1649 "lshParser.y" /* yacc.c:1646  */
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
#line 8792 "lshParser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1660 "lshParser.y" /* yacc.c:1646  */
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
#line 8808 "lshParser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1671 "lshParser.y" /* yacc.c:1646  */
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
#line 8824 "lshParser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1685 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new breakNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("breakNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8838 "lshParser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1694 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new breakNode (*(yyvsp[-1].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("breakNode", "stmt", NULL, NULL, 0, *(yyvsp[-1].fval));
         }
         #endif
         (yyval.data) = r;     
      }
#line 8852 "lshParser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1703 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new continueNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("continueNode", "stmt", NULL, 0);
         }
         #endif
         (yyval.data) = r;     
      }
#line 8866 "lshParser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1712 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r =new continueNode (*(yyvsp[-1].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("continueNode", "stmt", NULL, NULL, 0, *(yyvsp[-1].fval));
         }
         #endif
         (yyval.data) = r;
      }
#line 8880 "lshParser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1724 "lshParser.y" /* yacc.c:1646  */
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
#line 8896 "lshParser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1735 "lshParser.y" /* yacc.c:1646  */
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
#line 8912 "lshParser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1749 "lshParser.y" /* yacc.c:1646  */
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
#line 8928 "lshParser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1760 "lshParser.y" /* yacc.c:1646  */
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
#line 8944 "lshParser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1771 "lshParser.y" /* yacc.c:1646  */
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
#line 8960 "lshParser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1782 "lshParser.y" /* yacc.c:1646  */
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
#line 8976 "lshParser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1796 "lshParser.y" /* yacc.c:1646  */
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
#line 8998 "lshParser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1813 "lshParser.y" /* yacc.c:1646  */
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
#line 9020 "lshParser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1830 "lshParser.y" /* yacc.c:1646  */
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
#line 9051 "lshParser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1856 "lshParser.y" /* yacc.c:1646  */
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
#line 9073 "lshParser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1873 "lshParser.y" /* yacc.c:1646  */
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
#line 9089 "lshParser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1884 "lshParser.y" /* yacc.c:1646  */
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
#line 9105 "lshParser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1895 "lshParser.y" /* yacc.c:1646  */
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
#line 9128 "lshParser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1913 "lshParser.y" /* yacc.c:1646  */
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
#line 9144 "lshParser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1924 "lshParser.y" /* yacc.c:1646  */
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
#line 9160 "lshParser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1935 "lshParser.y" /* yacc.c:1646  */
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
#line 9176 "lshParser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1946 "lshParser.y" /* yacc.c:1646  */
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
#line 9199 "lshParser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1964 "lshParser.y" /* yacc.c:1646  */
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
#line 9215 "lshParser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1975 "lshParser.y" /* yacc.c:1646  */
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
#line 9231 "lshParser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1986 "lshParser.y" /* yacc.c:1646  */
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
#line 9247 "lshParser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1997 "lshParser.y" /* yacc.c:1646  */
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
#line 9270 "lshParser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2015 "lshParser.y" /* yacc.c:1646  */
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
#line 9286 "lshParser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2026 "lshParser.y" /* yacc.c:1646  */
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
#line 9302 "lshParser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2037 "lshParser.y" /* yacc.c:1646  */
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
#line 9318 "lshParser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 2048 "lshParser.y" /* yacc.c:1646  */
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
#line 9341 "lshParser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 2066 "lshParser.y" /* yacc.c:1646  */
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
#line 9357 "lshParser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 2077 "lshParser.y" /* yacc.c:1646  */
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
#line 9373 "lshParser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 2088 "lshParser.y" /* yacc.c:1646  */
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
#line 9389 "lshParser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 2099 "lshParser.y" /* yacc.c:1646  */
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
#line 9412 "lshParser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 2117 "lshParser.y" /* yacc.c:1646  */
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
#line 9428 "lshParser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 2128 "lshParser.y" /* yacc.c:1646  */
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
#line 9444 "lshParser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 2139 "lshParser.y" /* yacc.c:1646  */
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
#line 9460 "lshParser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 2150 "lshParser.y" /* yacc.c:1646  */
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
#line 9483 "lshParser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 2168 "lshParser.y" /* yacc.c:1646  */
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
#line 9499 "lshParser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 2183 "lshParser.y" /* yacc.c:1646  */
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
#line 9515 "lshParser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 2194 "lshParser.y" /* yacc.c:1646  */
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
#line 9538 "lshParser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 2212 "lshParser.y" /* yacc.c:1646  */
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
#line 9568 "lshParser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 2237 "lshParser.y" /* yacc.c:1646  */
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
#line 9591 "lshParser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 2258 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].data); }
#line 9597 "lshParser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 2263 "lshParser.y" /* yacc.c:1646  */
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
#line 9613 "lshParser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 2274 "lshParser.y" /* yacc.c:1646  */
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
#line 9629 "lshParser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 2285 "lshParser.y" /* yacc.c:1646  */
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
#line 9645 "lshParser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 2296 "lshParser.y" /* yacc.c:1646  */
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
#line 9661 "lshParser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 2307 "lshParser.y" /* yacc.c:1646  */
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
#line 9677 "lshParser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 2318 "lshParser.y" /* yacc.c:1646  */
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
#line 9693 "lshParser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 2329 "lshParser.y" /* yacc.c:1646  */
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
#line 9709 "lshParser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 2340 "lshParser.y" /* yacc.c:1646  */
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
#line 9725 "lshParser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 2351 "lshParser.y" /* yacc.c:1646  */
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
#line 9741 "lshParser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 2362 "lshParser.y" /* yacc.c:1646  */
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
#line 9757 "lshParser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 2373 "lshParser.y" /* yacc.c:1646  */
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
#line 9773 "lshParser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 2384 "lshParser.y" /* yacc.c:1646  */
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
#line 9789 "lshParser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 2399 "lshParser.y" /* yacc.c:1646  */
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
#line 9805 "lshParser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 2410 "lshParser.y" /* yacc.c:1646  */
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
#line 9821 "lshParser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 2421 "lshParser.y" /* yacc.c:1646  */
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
#line 9836 "lshParser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 2431 "lshParser.y" /* yacc.c:1646  */
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
#line 9851 "lshParser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 2445 "lshParser.y" /* yacc.c:1646  */
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
#line 9874 "lshParser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 2463 "lshParser.y" /* yacc.c:1646  */
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
#line 9897 "lshParser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 2481 "lshParser.y" /* yacc.c:1646  */
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
#line 9920 "lshParser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 2499 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 9926 "lshParser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 2504 "lshParser.y" /* yacc.c:1646  */
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
#line 9941 "lshParser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 2514 "lshParser.y" /* yacc.c:1646  */
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
#line 9963 "lshParser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 2531 "lshParser.y" /* yacc.c:1646  */
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
#line 9978 "lshParser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 2541 "lshParser.y" /* yacc.c:1646  */
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
#line 10000 "lshParser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 2562 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10006 "lshParser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 2566 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10012 "lshParser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 2570 "lshParser.y" /* yacc.c:1646  */
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
#line 10028 "lshParser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 2581 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10034 "lshParser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 2585 "lshParser.y" /* yacc.c:1646  */
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
#line 10050 "lshParser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 2596 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);  }
#line 10056 "lshParser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 2600 "lshParser.y" /* yacc.c:1646  */
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
#line 10071 "lshParser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 2610 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10077 "lshParser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 2614 "lshParser.y" /* yacc.c:1646  */
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
#line 10093 "lshParser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 2625 "lshParser.y" /* yacc.c:1646  */
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
#line 10109 "lshParser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 2636 "lshParser.y" /* yacc.c:1646  */
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
#line 10125 "lshParser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 2647 "lshParser.y" /* yacc.c:1646  */
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
#line 10141 "lshParser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 2658 "lshParser.y" /* yacc.c:1646  */
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
#line 10157 "lshParser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 2669 "lshParser.y" /* yacc.c:1646  */
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
#line 10173 "lshParser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 2680 "lshParser.y" /* yacc.c:1646  */
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
#line 10189 "lshParser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 2691 "lshParser.y" /* yacc.c:1646  */
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
#line 10205 "lshParser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 2702 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10211 "lshParser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 2707 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10217 "lshParser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 2711 "lshParser.y" /* yacc.c:1646  */
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
#line 10233 "lshParser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 2722 "lshParser.y" /* yacc.c:1646  */
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
#line 10249 "lshParser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 2733 "lshParser.y" /* yacc.c:1646  */
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
#line 10290 "lshParser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 2769 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10296 "lshParser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 2773 "lshParser.y" /* yacc.c:1646  */
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
#line 10312 "lshParser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 2784 "lshParser.y" /* yacc.c:1646  */
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
#line 10328 "lshParser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 2795 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10334 "lshParser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 2799 "lshParser.y" /* yacc.c:1646  */
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
#line 10350 "lshParser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 2810 "lshParser.y" /* yacc.c:1646  */
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
#line 10366 "lshParser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 2821 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10372 "lshParser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 2826 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10378 "lshParser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 2830 "lshParser.y" /* yacc.c:1646  */
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
#line 10394 "lshParser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 2841 "lshParser.y" /* yacc.c:1646  */
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
#line 10410 "lshParser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 2852 "lshParser.y" /* yacc.c:1646  */
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
#line 10426 "lshParser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 2863 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10432 "lshParser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 2867 "lshParser.y" /* yacc.c:1646  */
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
#line 10447 "lshParser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 2877 "lshParser.y" /* yacc.c:1646  */
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
#line 10462 "lshParser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 2887 "lshParser.y" /* yacc.c:1646  */
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
#line 10478 "lshParser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 2898 "lshParser.y" /* yacc.c:1646  */
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
#line 10494 "lshParser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 2909 "lshParser.y" /* yacc.c:1646  */
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
#line 10515 "lshParser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 2925 "lshParser.y" /* yacc.c:1646  */
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
#line 10536 "lshParser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 2941 "lshParser.y" /* yacc.c:1646  */
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
#line 10558 "lshParser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 2958 "lshParser.y" /* yacc.c:1646  */
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
#line 10580 "lshParser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 2975 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10586 "lshParser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 2980 "lshParser.y" /* yacc.c:1646  */
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
#line 10602 "lshParser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 2991 "lshParser.y" /* yacc.c:1646  */
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
#line 10618 "lshParser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 3002 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10624 "lshParser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 3007 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10630 "lshParser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 3011 "lshParser.y" /* yacc.c:1646  */
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
#line 10646 "lshParser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 3022 "lshParser.y" /* yacc.c:1646  */
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
#line 10662 "lshParser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 3033 "lshParser.y" /* yacc.c:1646  */
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
#line 10678 "lshParser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 3044 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10684 "lshParser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 3048 "lshParser.y" /* yacc.c:1646  */
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
#line 10699 "lshParser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 3058 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10705 "lshParser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 3063 "lshParser.y" /* yacc.c:1646  */
    {(yyval.data) = (yyvsp[0].data); }
#line 10711 "lshParser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 3064 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data);}
#line 10717 "lshParser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 3065 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10723 "lshParser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 3066 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10729 "lshParser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 3067 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10735 "lshParser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 3070 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10741 "lshParser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 3071 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10747 "lshParser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 3072 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10753 "lshParser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 3073 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10759 "lshParser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 3074 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10765 "lshParser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 3075 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10771 "lshParser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 3076 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10777 "lshParser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 3079 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10783 "lshParser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 3080 "lshParser.y" /* yacc.c:1646  */
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
#line 10798 "lshParser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 3093 "lshParser.y" /* yacc.c:1646  */
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
#line 10813 "lshParser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 3103 "lshParser.y" /* yacc.c:1646  */
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
#line 10828 "lshParser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 3113 "lshParser.y" /* yacc.c:1646  */
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
#line 10843 "lshParser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 3123 "lshParser.y" /* yacc.c:1646  */
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
#line 10858 "lshParser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 3133 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 10864 "lshParser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 3137 "lshParser.y" /* yacc.c:1646  */
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
#line 10888 "lshParser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 3156 "lshParser.y" /* yacc.c:1646  */
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
#line 10912 "lshParser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 3175 "lshParser.y" /* yacc.c:1646  */
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
#line 10936 "lshParser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 3194 "lshParser.y" /* yacc.c:1646  */
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
#line 10960 "lshParser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 3213 "lshParser.y" /* yacc.c:1646  */
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
#line 10984 "lshParser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 3232 "lshParser.y" /* yacc.c:1646  */
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
#line 11008 "lshParser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 3251 "lshParser.y" /* yacc.c:1646  */
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
#line 11032 "lshParser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 3270 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11038 "lshParser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 3274 "lshParser.y" /* yacc.c:1646  */
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
#line 11053 "lshParser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 3284 "lshParser.y" /* yacc.c:1646  */
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
#line 11068 "lshParser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 3294 "lshParser.y" /* yacc.c:1646  */
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
#line 11083 "lshParser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 3304 "lshParser.y" /* yacc.c:1646  */
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
#line 11098 "lshParser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 3314 "lshParser.y" /* yacc.c:1646  */
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
#line 11113 "lshParser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 3324 "lshParser.y" /* yacc.c:1646  */
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
#line 11128 "lshParser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 3334 "lshParser.y" /* yacc.c:1646  */
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
#line 11143 "lshParser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 3344 "lshParser.y" /* yacc.c:1646  */
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
#line 11158 "lshParser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 3357 "lshParser.y" /* yacc.c:1646  */
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
#line 11173 "lshParser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 3367 "lshParser.y" /* yacc.c:1646  */
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
#line 11188 "lshParser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 3377 "lshParser.y" /* yacc.c:1646  */
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
#line 11203 "lshParser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 3387 "lshParser.y" /* yacc.c:1646  */
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
#line 11218 "lshParser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 3397 "lshParser.y" /* yacc.c:1646  */
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
#line 11233 "lshParser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 3407 "lshParser.y" /* yacc.c:1646  */
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
#line 11248 "lshParser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 3417 "lshParser.y" /* yacc.c:1646  */
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
#line 11263 "lshParser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 3430 "lshParser.y" /* yacc.c:1646  */
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
#line 11278 "lshParser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 3440 "lshParser.y" /* yacc.c:1646  */
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
#line 11293 "lshParser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 3450 "lshParser.y" /* yacc.c:1646  */
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
#line 11308 "lshParser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 3460 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new sizeOfNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("sizeOfNode", "operator", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11322 "lshParser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 3473 "lshParser.y" /* yacc.c:1646  */
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
#line 11338 "lshParser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 3484 "lshParser.y" /* yacc.c:1646  */
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
#line 11354 "lshParser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 3495 "lshParser.y" /* yacc.c:1646  */
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
#line 11369 "lshParser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 3505 "lshParser.y" /* yacc.c:1646  */
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
#line 11385 "lshParser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 3516 "lshParser.y" /* yacc.c:1646  */
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
#line 11401 "lshParser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 3527 "lshParser.y" /* yacc.c:1646  */
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
#line 11417 "lshParser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 3538 "lshParser.y" /* yacc.c:1646  */
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
#line 11433 "lshParser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 3549 "lshParser.y" /* yacc.c:1646  */
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
#line 11449 "lshParser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 3560 "lshParser.y" /* yacc.c:1646  */
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
#line 11464 "lshParser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 3570 "lshParser.y" /* yacc.c:1646  */
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
#line 11479 "lshParser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 3583 "lshParser.y" /* yacc.c:1646  */
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
#line 11495 "lshParser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 3594 "lshParser.y" /* yacc.c:1646  */
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
#line 11511 "lshParser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 3605 "lshParser.y" /* yacc.c:1646  */
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
#line 11527 "lshParser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 3616 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new thisNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("thisNode", "class", NULL, 0);
         }
         #endif
         (yyval.data) = r; 
      }
#line 11541 "lshParser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 3625 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new parentNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("parentNode", "class", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11555 "lshParser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 3634 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11561 "lshParser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 3635 "lshParser.y" /* yacc.c:1646  */
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
#line 11576 "lshParser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 3648 "lshParser.y" /* yacc.c:1646  */
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
#line 11591 "lshParser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 3658 "lshParser.y" /* yacc.c:1646  */
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
#line 11606 "lshParser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 3668 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new arrayConstNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("arrayConstNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11620 "lshParser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 3677 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11626 "lshParser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 3678 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 11632 "lshParser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 3682 "lshParser.y" /* yacc.c:1646  */
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
#line 11648 "lshParser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 3693 "lshParser.y" /* yacc.c:1646  */
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
#line 11664 "lshParser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 3704 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new timeNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("timeNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11678 "lshParser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 3713 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new timeNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("timeNode", "data", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11692 "lshParser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 3725 "lshParser.y" /* yacc.c:1646  */
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
#line 11708 "lshParser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 3736 "lshParser.y" /* yacc.c:1646  */
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
#line 11724 "lshParser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 3747 "lshParser.y" /* yacc.c:1646  */
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
#line 11740 "lshParser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 3758 "lshParser.y" /* yacc.c:1646  */
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
#line 11756 "lshParser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 3769 "lshParser.y" /* yacc.c:1646  */
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
#line 11772 "lshParser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 3780 "lshParser.y" /* yacc.c:1646  */
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
#line 11788 "lshParser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 3791 "lshParser.y" /* yacc.c:1646  */
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
#line 11804 "lshParser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 3802 "lshParser.y" /* yacc.c:1646  */
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
#line 11819 "lshParser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 3812 "lshParser.y" /* yacc.c:1646  */
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
#line 11834 "lshParser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 3822 "lshParser.y" /* yacc.c:1646  */
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
#line 11850 "lshParser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 3833 "lshParser.y" /* yacc.c:1646  */
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
#line 11866 "lshParser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 3844 "lshParser.y" /* yacc.c:1646  */
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
#line 11882 "lshParser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 3855 "lshParser.y" /* yacc.c:1646  */
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
#line 11898 "lshParser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 3866 "lshParser.y" /* yacc.c:1646  */
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
#line 11913 "lshParser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 3879 "lshParser.y" /* yacc.c:1646  */
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
#line 11928 "lshParser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 3889 "lshParser.y" /* yacc.c:1646  */
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
#line 11943 "lshParser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 3899 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new forkNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("forkNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 11957 "lshParser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 3908 "lshParser.y" /* yacc.c:1646  */
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
#line 11972 "lshParser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 3918 "lshParser.y" /* yacc.c:1646  */
    {
         runNode * r = new waitNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("waitNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 11986 "lshParser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 3927 "lshParser.y" /* yacc.c:1646  */
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
#line 12003 "lshParser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 3939 "lshParser.y" /* yacc.c:1646  */
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
#line 12019 "lshParser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 3950 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new exitProcessNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("exitProcessNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
   }
#line 12033 "lshParser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 3959 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getpidNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getpidNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;      
      }
#line 12047 "lshParser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 3968 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new getppidNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getppidNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12061 "lshParser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 3977 "lshParser.y" /* yacc.c:1646  */
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
#line 12077 "lshParser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 3988 "lshParser.y" /* yacc.c:1646  */
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
#line 12093 "lshParser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 4002 "lshParser.y" /* yacc.c:1646  */
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
#line 12108 "lshParser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 4015 "lshParser.y" /* yacc.c:1646  */
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
#line 12124 "lshParser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 4026 "lshParser.y" /* yacc.c:1646  */
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
#line 12140 "lshParser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 4037 "lshParser.y" /* yacc.c:1646  */
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
#line 12156 "lshParser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 4048 "lshParser.y" /* yacc.c:1646  */
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
#line 12172 "lshParser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 4059 "lshParser.y" /* yacc.c:1646  */
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
#line 12188 "lshParser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 4070 "lshParser.y" /* yacc.c:1646  */
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
#line 12204 "lshParser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 4081 "lshParser.y" /* yacc.c:1646  */
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
#line 12220 "lshParser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 4092 "lshParser.y" /* yacc.c:1646  */
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
#line 12236 "lshParser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 4103 "lshParser.y" /* yacc.c:1646  */
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
#line 12252 "lshParser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 4114 "lshParser.y" /* yacc.c:1646  */
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
#line 12268 "lshParser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 4125 "lshParser.y" /* yacc.c:1646  */
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
#line 12284 "lshParser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 4136 "lshParser.y" /* yacc.c:1646  */
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
#line 12300 "lshParser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 4147 "lshParser.y" /* yacc.c:1646  */
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
#line 12316 "lshParser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 4158 "lshParser.y" /* yacc.c:1646  */
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
#line 12332 "lshParser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 4169 "lshParser.y" /* yacc.c:1646  */
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
#line 12348 "lshParser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 4180 "lshParser.y" /* yacc.c:1646  */
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
#line 12364 "lshParser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 4191 "lshParser.y" /* yacc.c:1646  */
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
#line 12380 "lshParser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 4202 "lshParser.y" /* yacc.c:1646  */
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
#line 12396 "lshParser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 4213 "lshParser.y" /* yacc.c:1646  */
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
#line 12412 "lshParser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 4224 "lshParser.y" /* yacc.c:1646  */
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
#line 12428 "lshParser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 4235 "lshParser.y" /* yacc.c:1646  */
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
#line 12444 "lshParser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 4246 "lshParser.y" /* yacc.c:1646  */
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
#line 12460 "lshParser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 4257 "lshParser.y" /* yacc.c:1646  */
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
#line 12476 "lshParser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 4268 "lshParser.y" /* yacc.c:1646  */
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
#line 12492 "lshParser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 4279 "lshParser.y" /* yacc.c:1646  */
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
#line 12508 "lshParser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 4290 "lshParser.y" /* yacc.c:1646  */
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
#line 12524 "lshParser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 4301 "lshParser.y" /* yacc.c:1646  */
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
#line 12540 "lshParser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 4312 "lshParser.y" /* yacc.c:1646  */
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
#line 12556 "lshParser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 4323 "lshParser.y" /* yacc.c:1646  */
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
#line 12572 "lshParser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 4334 "lshParser.y" /* yacc.c:1646  */
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
#line 12588 "lshParser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 4345 "lshParser.y" /* yacc.c:1646  */
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
#line 12604 "lshParser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 4356 "lshParser.y" /* yacc.c:1646  */
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
#line 12620 "lshParser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 4367 "lshParser.y" /* yacc.c:1646  */
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
#line 12636 "lshParser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 4378 "lshParser.y" /* yacc.c:1646  */
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
#line 12652 "lshParser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 4389 "lshParser.y" /* yacc.c:1646  */
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
#line 12668 "lshParser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 4400 "lshParser.y" /* yacc.c:1646  */
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
#line 12685 "lshParser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 4412 "lshParser.y" /* yacc.c:1646  */
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
#line 12701 "lshParser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 4423 "lshParser.y" /* yacc.c:1646  */
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
#line 12717 "lshParser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 4434 "lshParser.y" /* yacc.c:1646  */
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
#line 12733 "lshParser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 4445 "lshParser.y" /* yacc.c:1646  */
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
#line 12749 "lshParser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 4456 "lshParser.y" /* yacc.c:1646  */
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
#line 12765 "lshParser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 4467 "lshParser.y" /* yacc.c:1646  */
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
#line 12781 "lshParser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 4478 "lshParser.y" /* yacc.c:1646  */
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
#line 12797 "lshParser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 4489 "lshParser.y" /* yacc.c:1646  */
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
#line 12813 "lshParser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 4500 "lshParser.y" /* yacc.c:1646  */
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
#line 12829 "lshParser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 4511 "lshParser.y" /* yacc.c:1646  */
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
#line 12845 "lshParser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 4522 "lshParser.y" /* yacc.c:1646  */
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
#line 12861 "lshParser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 4533 "lshParser.y" /* yacc.c:1646  */
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
#line 12877 "lshParser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 4547 "lshParser.y" /* yacc.c:1646  */
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
#line 12892 "lshParser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 4557 "lshParser.y" /* yacc.c:1646  */
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
#line 12908 "lshParser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 4568 "lshParser.y" /* yacc.c:1646  */
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
#line 12924 "lshParser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 4579 "lshParser.y" /* yacc.c:1646  */
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
#line 12940 "lshParser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 4593 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new getiNode (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getiNode", "symbol", NULL, 0);
         }
         #endif
         (yyval.data) = r;    
      }
#line 12954 "lshParser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 4602 "lshParser.y" /* yacc.c:1646  */
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
#line 12975 "lshParser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 4621 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval));
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data) = r;
      }
#line 12989 "lshParser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 4630 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new boolConstNode (true);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("boolConstNode", "data", NULL, NULL, 0, "true");
         }
         #endif
         (yyval.data) = r;
      }
#line 13003 "lshParser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 4639 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new boolConstNode (false); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("boolConstNode", "data", NULL, NULL, 0, "false");
         }
         #endif
         (yyval.data)  = r;
      }
#line 13017 "lshParser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 4648 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new nullNode (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("nullNode", "data", NULL, 0);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 13031 "lshParser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 4657 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data)  = r;
      }
#line 13045 "lshParser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 4666 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new strConstNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("strConstNode", "data", NULL, NULL, 0, *(yyvsp[0].str));
         }
         #endif
         (yyval.data)  = r;   
      }
#line 13059 "lshParser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 4675 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new regexpNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("regexpNode", "data", NULL, NULL, 0, *(yyvsp[0].str));
         }
         #endif
         (yyval.data)  = r;   
      }
#line 13073 "lshParser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 4684 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (*(yyvsp[0].fval)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *(yyvsp[0].fval));
         }
         #endif
         (yyval.data)  = r;
      }
#line 13087 "lshParser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 4693 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new numConstNode (-1 * (*(yyvsp[0].fval))); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, (-1 * (*(yyvsp[0].fval))));
         }
         #endif
         (yyval.data)  = r;
      }
#line 13101 "lshParser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 4702 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].idnode);}
#line 13107 "lshParser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 4703 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[-1].data); }
#line 13113 "lshParser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 4707 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13119 "lshParser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 4708 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13125 "lshParser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 4709 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13131 "lshParser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 4710 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new contextFunction (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("contextFunction", "function", NULL, 0);
         }
         #endif
         (yyval.data)  = r;   
      }
#line 13145 "lshParser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 4723 "lshParser.y" /* yacc.c:1646  */
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
#line 13161 "lshParser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 4734 "lshParser.y" /* yacc.c:1646  */
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
#line 13177 "lshParser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 4745 "lshParser.y" /* yacc.c:1646  */
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
#line 13193 "lshParser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 4756 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new functionNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("functionNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13207 "lshParser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 4765 "lshParser.y" /* yacc.c:1646  */
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
#line 13222 "lshParser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 4775 "lshParser.y" /* yacc.c:1646  */
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
#line 13238 "lshParser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 4786 "lshParser.y" /* yacc.c:1646  */
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
#line 13254 "lshParser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 4797 "lshParser.y" /* yacc.c:1646  */
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
#line 13270 "lshParser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 4808 "lshParser.y" /* yacc.c:1646  */
    {  
         runNode * r = new functionNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("functionNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;   
      }
#line 13284 "lshParser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 4817 "lshParser.y" /* yacc.c:1646  */
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
#line 13299 "lshParser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 4827 "lshParser.y" /* yacc.c:1646  */
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
#line 13315 "lshParser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 4841 "lshParser.y" /* yacc.c:1646  */
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
#line 13331 "lshParser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 4852 "lshParser.y" /* yacc.c:1646  */
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
#line 13347 "lshParser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 4863 "lshParser.y" /* yacc.c:1646  */
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
#line 13363 "lshParser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 4874 "lshParser.y" /* yacc.c:1646  */
    { 
         runNode * r = new decoratorNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("decoratorNode", "function", NULL, 0);
         }
         #endif
         (yyval.data) = r;        
      }
#line 13377 "lshParser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 4886 "lshParser.y" /* yacc.c:1646  */
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
#line 13393 "lshParser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 4897 "lshParser.y" /* yacc.c:1646  */
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
#line 13409 "lshParser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 4908 "lshParser.y" /* yacc.c:1646  */
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
#line 13425 "lshParser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 4919 "lshParser.y" /* yacc.c:1646  */
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
#line 13441 "lshParser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 4930 "lshParser.y" /* yacc.c:1646  */
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
#line 13457 "lshParser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 4941 "lshParser.y" /* yacc.c:1646  */
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
#line 13473 "lshParser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 4956 "lshParser.y" /* yacc.c:1646  */
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
#line 13488 "lshParser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 4966 "lshParser.y" /* yacc.c:1646  */
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
#line 13503 "lshParser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 4976 "lshParser.y" /* yacc.c:1646  */
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
#line 13518 "lshParser.c" /* yacc.c:1646  */
    break;

  case 455:
#line 4989 "lshParser.y" /* yacc.c:1646  */
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
#line 13533 "lshParser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 4999 "lshParser.y" /* yacc.c:1646  */
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
#line 13548 "lshParser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 5009 "lshParser.y" /* yacc.c:1646  */
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
#line 13563 "lshParser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 5022 "lshParser.y" /* yacc.c:1646  */
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
#line 13579 "lshParser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 5033 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13585 "lshParser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 5038 "lshParser.y" /* yacc.c:1646  */
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
#line 13601 "lshParser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 5049 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13607 "lshParser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 5054 "lshParser.y" /* yacc.c:1646  */
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
#line 13622 "lshParser.c" /* yacc.c:1646  */
    break;

  case 463:
#line 5064 "lshParser.y" /* yacc.c:1646  */
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
#line 13637 "lshParser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 5077 "lshParser.y" /* yacc.c:1646  */
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
#line 13653 "lshParser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 5088 "lshParser.y" /* yacc.c:1646  */
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
#line 13669 "lshParser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 5099 "lshParser.y" /* yacc.c:1646  */
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
#line 13685 "lshParser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 5110 "lshParser.y" /* yacc.c:1646  */
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
#line 13701 "lshParser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 5121 "lshParser.y" /* yacc.c:1646  */
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
#line 13717 "lshParser.c" /* yacc.c:1646  */
    break;

  case 469:
#line 5132 "lshParser.y" /* yacc.c:1646  */
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
#line 13739 "lshParser.c" /* yacc.c:1646  */
    break;

  case 470:
#line 5149 "lshParser.y" /* yacc.c:1646  */
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
#line 13761 "lshParser.c" /* yacc.c:1646  */
    break;

  case 471:
#line 5166 "lshParser.y" /* yacc.c:1646  */
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
#line 13783 "lshParser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 5183 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13789 "lshParser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 5184 "lshParser.y" /* yacc.c:1646  */
    { (yyval.data) = (yyvsp[0].data); }
#line 13795 "lshParser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 5188 "lshParser.y" /* yacc.c:1646  */
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
#line 13811 "lshParser.c" /* yacc.c:1646  */
    break;

  case 475:
#line 5199 "lshParser.y" /* yacc.c:1646  */
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
#line 13826 "lshParser.c" /* yacc.c:1646  */
    break;

  case 476:
#line 5209 "lshParser.y" /* yacc.c:1646  */
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
#line 13841 "lshParser.c" /* yacc.c:1646  */
    break;

  case 477:
#line 5219 "lshParser.y" /* yacc.c:1646  */
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
#line 13857 "lshParser.c" /* yacc.c:1646  */
    break;

  case 478:
#line 5230 "lshParser.y" /* yacc.c:1646  */
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
#line 13873 "lshParser.c" /* yacc.c:1646  */
    break;

  case 479:
#line 5241 "lshParser.y" /* yacc.c:1646  */
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
#line 13889 "lshParser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 5252 "lshParser.y" /* yacc.c:1646  */
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
#line 13905 "lshParser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 5263 "lshParser.y" /* yacc.c:1646  */
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
#line 13920 "lshParser.c" /* yacc.c:1646  */
    break;

  case 482:
#line 5273 "lshParser.y" /* yacc.c:1646  */
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
#line 13935 "lshParser.c" /* yacc.c:1646  */
    break;

  case 483:
#line 5283 "lshParser.y" /* yacc.c:1646  */
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
#line 13951 "lshParser.c" /* yacc.c:1646  */
    break;

  case 484:
#line 5298 "lshParser.y" /* yacc.c:1646  */
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
#line 13967 "lshParser.c" /* yacc.c:1646  */
    break;

  case 485:
#line 5309 "lshParser.y" /* yacc.c:1646  */
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
#line 13983 "lshParser.c" /* yacc.c:1646  */
    break;

  case 486:
#line 5320 "lshParser.y" /* yacc.c:1646  */
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
#line 14005 "lshParser.c" /* yacc.c:1646  */
    break;

  case 487:
#line 5337 "lshParser.y" /* yacc.c:1646  */
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
#line 14027 "lshParser.c" /* yacc.c:1646  */
    break;

  case 488:
#line 5358 "lshParser.y" /* yacc.c:1646  */
    { 
         idNode * r = new idNode (*(yyvsp[0].str)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", *(yyvsp[0].str));
         }
         #endif
         (yyval.idnode)  = r;
      }
#line 14041 "lshParser.c" /* yacc.c:1646  */
    break;

  case 489:
#line 5367 "lshParser.y" /* yacc.c:1646  */
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
#line 14056 "lshParser.c" /* yacc.c:1646  */
    break;


#line 14060 "lshParser.c" /* yacc.c:1646  */
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
#line 5380 "lshParser.y" /* yacc.c:1906  */

int main(int argc, char *argv[]) {
	interpreter::init(argc, argv)->run();
   _exit(0);
}
//======================================================================
// Fco. Javier Bohórquez Ogalla
