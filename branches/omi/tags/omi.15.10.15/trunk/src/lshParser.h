/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 61 "lshParser.y" /* yacc.c:1909  */

  num* fval;
  string* str; 
  idNode* idnode;
  listNode* listnode;
  runNode* data;
  runNode** ref;
  vector<string>* mval;

#line 346 "lshParser.h" /* yacc.c:1909  */
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
