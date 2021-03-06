%{
//lshScanner.l
//----------------------------------------------------------------------
/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

//----------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

#include "run/stmts/stmtNode.h"
#include "lshParser.h"

#undef YY_INPUT
%}
%x cm
%x strd
%x strs
%x rexp
%x endrexp
%x endcm
%x endstrd
%x endstrs
%option noyywrap
%option yylineno

%%

   /*=================================================================*/
   /* Comentarios */

"/*"  BEGIN(cm);
<cm>[^*\n]*       
<cm>"*"+[^*/\n]*  
<cm>\n   stmtNode::newLine ();
<cm>"*"+"/" BEGIN(INITIAL);

\#.*\n   stmtNode::newLine ();

"//".*\n stmtNode::newLine ();

   /*=================================================================*/							
   /* Espaciado */

[ \t]+					

[\n\r]   stmtNode::newLine ();

<<EOF>>  {  stmtNode::newLine (); yyterminate(); }
							
   /*=================================================================*/
   /* Null */
   
"null"|"NULL"  return NULLTOKEN;

   /*=================================================================*/
   /* Booleanos */
   						
"true"   return TRUE;
	
"false"  return FALSE;

   /*=================================================================*/
   /* Numéricos */
   						
[0-9]+(\.[0-9]+)?	 {
   yylval.fval = new num (atof (yytext));
   return NUM;
}
							
[\-\+]?[0-9]+(\.[0-9]+)?   {
   yylval.fval = new num (atof (yytext));
   return SNUM;
}
   /*=================================================================*/
   /* Cadenas de texto */

\" BEGIN(strd);
<strd>((\\\")*([^\"])*)*	{
   yylval.str = new string (yytext);
   BEGIN(endstrd);
   return STR;
}
<strd>\" {
   yylval.str = new string ("");
   BEGIN(INITIAL);
   return STR;
}
<endstrd>\" {
   BEGIN(INITIAL);
}
							
\' BEGIN(strs);
<strs>((\\\')*[^\']*)*	{
   yylval.str = new string (yytext);
   BEGIN(endstrs);
   return STR;
}
<strs>\' {
   yylval.str = new string ("");
   BEGIN(INITIAL);
   return STR;
}					
<endstrs>\' BEGIN(INITIAL);

   /*=================================================================*/
   /* Expresiones regulares */							
   
\` BEGIN(rexp);		
<rexp>((\\\`)*[^\n\`]*)*   {
   yylval.str = new string (yytext);
   BEGIN(endrexp);
   return REXP;
}
<rexp>\` {	
   yylval.str = new string ("");
   BEGIN(INITIAL);
   return REXP;
}
<endrexp>\` BEGIN(INITIAL);

   /*=================================================================*/
   /* Variables */

"global" return GLOBAL;

"getenv" return GETENV;

   /*=================================================================*/
   /* Funciones */
   						
"function"  return FUNCTION;
							
"~~" return DECORATOR;

"P"   return PARTIALFUNC;

"~>"  return CONTEXTFUNC;

"return" return RET;

   /*=================================================================*/
   /* Clases */
   		
"class"  return CLASS;
							
"new" return NEW;

"private"   return PRIVATE;
              
"->"  return CLASSACCESS;

"extends"   return EXTENDS;
              
"this"   return THIS;

"parent" return PARENT;
                     
"static" return STATIC;

"::"  return NAMESPACE;

"getclass" return GETCLASS;

   /*=================================================================*/
   /* Sentencias de control */

"include"   return INCLUDE;

"if"|"+>"   return IF;

"else"|":_" return ELSE;

"elseif"|"elif"|":>" return ELSEIF;

"with"   return WITH;

"do"  return DO;

"while"  return WHILE;

"for" return FOR;

"as"  return AS;

"in"  return IN;

"switch" return SWITCH;

"case"   return CASE; 
							
"default"   return DEFAULT; 
               		
"break"  return BREAK;

"continue"  return CONTINUE;

"exit"   return EXIT;

"goto"   return GOTO;

"¡<"  return OPINC;

"throw" return THROW;

"catch" return CATCH;

"try" return TRY;

   /*=================================================================*/
   /* Entrada/salida */

"print"|"echo"  return PRINT;

"input"  return INPUT;

"inputline"|">>"  return INPUTLINE;

   /*=================================================================*/
   /* Operadores */

"<<"  return FLOW;

"<."  return FLOWLINE;

"typeof"|"typeOf" return TYPEOF;

"sizeof"|"sizeOf" return SIZEOF;

"datinfo"|"datInfo" return DATINFO;

   /*=================================================================*/
   /* Operadores lógicos */

"empty"  return EMPTY;

"isnull" return ISNULL;

"isbool" return ISBOOL;

"isnum" return ISNUM;

"isstring" return ISSTRING;

"isarray" return ISARRAY;

"isobject" return ISOBJECT;

"=="  return EQL;

"===" return IDEN;

"!==" return NIDEN;

"AND"|"and"|"&&"  return AND_OP;

"OR"|"or"|"||" return OR_OP;

   /*=================================================================*/
   /* Operadores aritméticos */

"size"   return SIZE;

"sqrt"   return SQRT;

"++"  return INC;

"--"  return DEC;

"+="  return ADDASIG;

"-="  return SUBASIG;

"*="  return PRODASIG;

"/="  return DIVASIG;

"^="  return POWASIG;

"%="  return MODASIG;

".="  return CATASIG;

   /*=================================================================*/
   /* Operadores cadenas */

"str_explode"|"array_explode"   return EXPLODE; 

"array_implode"|"str_implode"   return IMPLODE;

"str_find"|"str_pos"   return FIND;
  
"str_replace"   return REPLACE;

"str_replace_sub"  return SUBREPLACE;
              
"str_upper"  return UPPER;

"str_lower"  return LOWER;
              
"sprintf"   return SPRINTF;

   /*=================================================================*/
   /* Operadores expresiones regulares */
"str_search" return SEARCH;

"regexp" return REGEXP;

"str_match"  return MATCH;
                
   /*=================================================================*/
   /* Operadores array */

"array_reduce" return REDUCE;

"array_chunk"     {  return ARRAYCHUNK;  }

"array_search" return SEARCH;

"array_last" return ARRAYLAST;

"array_first" return ARRAYFIRST;

"array_insert" return ARRAYINSERT;

"array_delete" return ARRAYDELETE;

"array_unshift" return ARRAYUNSHIFT;

"array_shift" return ARRAYSHIFT;

"array_pop" return ARRAYPOP;

"array_push" return ARRAYPUSH;

   /*=================================================================*/
   /* Conversión de tipos */
"int" return CINT;

"float"  return CFLOAT;

"bool"   return CBOOL;

"string" return CSTR;

   /*=================================================================*/
   /* Fechas */

"date"   return DATE;

"time"   return TIME;

"sleep"  return SLEEP;

   /*=================================================================*/
   /* Ficheros */

"file"|"fopen" return FTOKEN;

"fput"|"f>:"   return FPUT;
					
"fget"|"f<:"   return FGET;
					
"fread"  return FREAD;
					
"fwrite" return FWRITE;
					
"fappend"|"fapp"  return FAPP;

"fclose" return FCLOSE;

"ftell"  return FTELL;

"fseek"  return FSEEK;

"fSET"|"FSET"   return FSET;

"fCUR"|"FCUR"   return FCUR;

"fEND"|"FEND"   return FEND;

   /*=================================================================*/
   /* Procesos */

"exec"   return EXEC;

"eval"   return EVAL;

"fork"   return FORK;
					
"wait"   return WAIT;
					
"getpid" return GETPID;
					
"getppid"   return GETPPID;
					
"process"   return PROCESSTOKEN;

"signal"|"kill"   return SIGNAL;

"shandler"  return SHANDLER;

"exit_process"  return EXITPROCESS;

   /*=================================================================*/
   /* Extensiones */

"load"   return LOAD_MODULE;
   
   /*=================================================================*/
   /* Identificadores */
   
[a-zA-Z_][a-zA-Z0-9_]*  {
   yylval.str = new string (yytext);
   return ID;
}		

   /*=================================================================*/
   /* Otros */		
   					
(\;)+ return ';';

[\.\&\|\(\)\<\>\+\-\*\/\%\^\[\]\!\=\:\{\}\?\@\,\~\$\?\¡\»\«]   return *yytext;	

.  cout << "Error: lexical error, unexpected character (" << yytext << ")\n";

   /*=================================================================*/
   /* Fco. Javier Bohórquez Ogalla */
