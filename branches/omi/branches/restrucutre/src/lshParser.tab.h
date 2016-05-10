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

#ifndef YY_YY_LSHPARSER_TAB_H_INCLUDED
# define YY_YY_LSHPARSER_TAB_H_INCLUDED
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
    FUNCTION = 277,
    PARTIALFUNC = 278,
    RET = 279,
    DECORATOR = 280,
    CONTEXTFUNC = 281,
    CLASS = 282,
    NEW = 283,
    CLASSACCESS = 284,
    THIS = 285,
    PARENT = 286,
    PRIVATE = 287,
    STATIC = 288,
    EXTENDS = 289,
    IF = 290,
    ELSE = 291,
    ELSEIF = 292,
    WITH = 293,
    DO = 294,
    WHILE = 295,
    AS = 296,
    OPINC = 297,
    FOR = 298,
    IN = 299,
    GOTO = 300,
    SWITCH = 301,
    CASE = 302,
    DEFAULT = 303,
    TYPEOF = 304,
    SIZEOF = 305,
    DATINFO = 306,
    BREAK = 307,
    EXIT = 308,
    SIZE = 309,
    EMPTY = 310,
    CONTINUE = 311,
    TRY = 312,
    CATCH = 313,
    THROW = 314,
    FLOW = 315,
    ADDASIG = 316,
    SUBASIG = 317,
    PRODASIG = 318,
    DIVASIG = 319,
    POWASIG = 320,
    MODASIG = 321,
    CATASIG = 322,
    IDEN = 323,
    NIDEN = 324,
    EXPLODE = 325,
    IMPLODE = 326,
    SPRINTF = 327,
    FIND = 328,
    REPLACE = 329,
    SUBREPLACE = 330,
    UPPER = 331,
    LOWER = 332,
    DATE = 333,
    TIME = 334,
    SLEEP = 335,
    GETENV = 336,
    REDUCE = 337,
    FTOKEN = 338,
    FPUT = 339,
    FGET = 340,
    FSEEK = 341,
    FEND = 342,
    FCUR = 343,
    FSET = 344,
    FTELL = 345,
    FCLOSE = 346,
    FREAD = 347,
    FWRITE = 348,
    FAPP = 349,
    FORK = 350,
    WAIT = 351,
    GETPID = 352,
    GETPPID = 353,
    PROCESSTOKEN = 354,
    EXITPROCESS = 355,
    SIGNAL = 356,
    SHANDLER = 357,
    INPUT = 358,
    INPUTLINE = 359,
    MATCH = 360,
    REGEXP = 361,
    SEARCH = 362,
    EXEC = 363,
    EVAL = 364,
    ARRAYCHUNK = 365,
    LOAD_MODULE = 366,
    DEF = 367,
    CDATA = 368,
    DDATA = 369,
    SDATA = 370,
    REFDEF = 371,
    REFREL = 372,
    FROM = 373,
    EXIST = 374,
    IDDEF = 375,
    LIKE = 376,
    CINT = 377,
    CFLOAT = 378,
    CBOOL = 379,
    CSTR = 380
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 64 "lshParser.y" /* yacc.c:1909  */

  num* fval;
  string* str; 
  idNode* idnode;
  listNode* listnode;
  runNode* data;
  runNode** ref;
  vector<string>* mval;

#line 190 "lshParser.tab.h" /* yacc.c:1909  */
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

#endif /* !YY_YY_LSHPARSER_TAB_H_INCLUDED  */
