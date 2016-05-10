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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 53 "lshParser.y" /* yacc.c:1909  */

  num* fval;
  string* str; 
  idNode* idnode;
  listNode* listnode;
  runNode* data;
  runNode** ref;
  vector<string>* mval;

#line 196 "lshParser.tab.h" /* yacc.c:1909  */
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
