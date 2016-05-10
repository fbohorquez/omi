%{
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

// #include DATABASE

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
%}

%defines

%token NUM SNUM REXP STR NULLTOKEN TRUE FALSE ID OP PRINT INC DEC  NAMESPACE INCLUDE GLOBAL
%token ISNULL EQL AND_OP OR_OP
%token FUNCTION PARTIALFUNC RET DECORATOR CONTEXTFUNC
%token CLASS NEW CLASSACCESS THIS PARENT PRIVATE STATIC EXTENDS 
%token IF ELSE ELSEIF WITH DO WHILE AS OPINC FOR IN GOTO SWITCH CASE DEFAULT TYPEOF SIZEOF DATINFO BREAK EXIT SIZE EMPTY CONTINUE TRY CATCH THROW FLOW
%token ADDASIG SUBASIG PRODASIG DIVASIG POWASIG MODASIG CATASIG IDEN NIDEN
%token EXPLODE IMPLODE SPRINTF FIND REPLACE SUBREPLACE UPPER LOWER DATE TIME SLEEP GETENV
%token REDUCE 
%token FTOKEN FPUT FGET FSEEK FEND FCUR FSET FTELL FCLOSE FREAD FWRITE FAPP
%token FORK WAIT GETPID GETPPID PROCESSTOKEN EXITPROCESS SIGNAL SHANDLER
%token INPUT INPUTLINE
%token MATCH REGEXP SEARCH
%token EXEC EVAL
%token ARRAYCHUNK
%token LOAD_MODULE
%token DEF CDATA DDATA SDATA REFDEF REFREL FROM EXIST IDDEF LIKE
%token CINT CFLOAT CBOOL CSTR

%union {
  num* fval;
  string* str; 
  idNode* idnode;
  listNode* listnode;
  runNode* data;
  runNode** ref;
  vector<string>* mval;
}

%type <fval> NUM SNUM
%type <str> STR ID REXP
%type <mval> OP
%type <data> stmts stmt stmtb exp label cases define function function_exp function_partial class
%type <data> if elseif with while dowhile for break switch iloop trycatch
%type <data> lexp lop1 lop2 lop3 lop4 
%type <data> aexp aop1 aop2 aop3  
%type <data> sexp sop1 sop2
%type <data> arrayop
%type <data> extra_operator tern notnull exp_generator unity
%type <data> assignation inc_dec lop_unity aop_unity sop_unity class_exp arrayexp date file process environment regexp_op iloop_access component_unity
%type <data> function_decorator function_lambda
%type <data> params params_default list
%type <data> identity call_identity assig  parray 
%type <data> namespace 
%type <data> component 
%type <listnode> array map 
%type <data> mapelement  
%type <idnode> id 
%type <data> cexp

%printer { fprintf (yyoutput, "%s", *$$); } ID;


%%

//======================================================================
program		
   :  stmts    { $1->run(); }
 	|  %empty   { ;} 
   ;

stmts 		
   :  stmt ';' stmts { $$ = new stmtNode ($1, $3, @1); } 
 	|  stmtb stmts { $$ = new stmtNode ($1, $2, @1); }
   |	stmtb { $$ = new stmtNode ($1, NULL, @1); }
 	|  stmt  { $$ = new stmtNode ($1, NULL, @1); }
 	|  stmt ';' { $$ = new stmtNode ($1, NULL, @1); }
   |	label stmts { $$ = new labelNode ($1, $2); } 
 	|  error ';' stmts   { $$ = $3; }
   |	';'   { $$ = new noNode (); }
   ;

//======================================================================
stmtb 		
   :  define  { $$ = $1; }
 	|	if { $$ = $1;  }
 	|	with { $$ = $1;  }
 	|	while { $$ = $1; }
 	|	dowhile { $$ = $1; }
 	|	for { $$ = $1; }
 	|	break { $$ = $1; }
 	|	switch { $$ = $1; }
 	|	iloop { $$ = $1; }
   |  trycatch { $$ = $1; }
   ;

stmt	 	
   :	exp { $$ = $1; }
   |  PRINT exp { $$ = new printNode ($2); }
   |  FLOW exp { $$ = new printNode ($2); }
   |	GOTO id { $$ = new gotoNode ($2); }	 
   |	INCLUDE	exp { $$ = new includeNode ($2); }
   |	RET	exp { $$ = new returnNode ($2); }
   |	RET { $$ = new returnNode (NULL);}
   |	SLEEP '(' exp ')' { $$ = new sleepNode ($3);}
 	|  LOAD_MODULE '(' exp ')' { $$ = new loadNode ($3); }
 	|  STATIC  exp  { $$ = new staticNode ($2); }
 	|  PRIVATE  exp  { $$ = new privateNode ($2); }
 	|  TYPEOF id   { $$ = new typeofNode ($2); }
   |  TYPEOF '(' id ')' { $$ = new typeofNode ($3); }
 	|  DATINFO exp   { $$ = new datInfoNode ($2); }
   |  DATINFO '(' exp ')' { $$ = new datInfoNode ($3); }
   |	EXIT  { $$ = new exitNode (); } 
   |  THROW exp  { $$ = new throwNode ($2); }
   ;
   
label 		
   :  id ':'  { $$ = $1; }
   ;
//======================================================================  
define  
   :  function  { $$ = $1; }
 	|	class { $$ = $1; }   
   |	component  { $$ = $1; }
 	|	GLOBAL identity ';' { $$ = new globalNode ($2); } 
   ;
   
if
   :	IF  lexp '{'  '}'  { $$ = new ifNode ($2,new noNode (),0); }
   |	IF  lexp '{' stmts '}'  { $$ = new ifNode ($2, $4, 0); }
   |	IF  lexp stmt ';'  { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), 0); }
   |	IF  lexp stmtb   { $$ = new ifNode ($2, $3, 0); }
   |	IF  lexp '{' '}' ELSE '{' stmts '}' { $$ = new ifNode ($2, new noNode (), $7); }
   |	IF  lexp '{' stmts '}' ELSE '{' '}' { $$ = new ifNode ($2, $4, new noNode ()); }
   |	IF  lexp '{' stmts '}' ELSE '{' stmts '}' { $$ = new ifNode ($2, $4, $8); }
   |	IF  lexp '{' '}' ELSE  stmt ';' { $$ = new ifNode ($2, new noNode (), new stmtNode ($6, NULL, @1)); }
   |	IF  lexp '{' stmts '}' ELSE  stmt ';' { $$ = new ifNode ($2, $4, new stmtNode ($7, NULL, @1)); }
   |	IF  lexp '{' '}' ELSE  stmtb  { $$ = new ifNode ($2, new noNode (), $6); }
   |	IF  lexp '{' stmts '}' ELSE  stmtb  { $$ = new ifNode ($2, $4, $7); }
   |	IF  lexp stmt ';' ELSE '{' '}' { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), new noNode ()); }
   |	IF  lexp stmt ';' ELSE '{' stmts '}' { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), $7); }
   |	IF  lexp stmt ';' ELSE  stmt ';' { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), new stmtNode ($6, NULL, @1)); }
   |	IF  lexp stmt ';' ELSE  stmtb { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), $6); }
   |	IF  lexp stmtb  ELSE '{'  '}' { $$ = new ifNode ($2, $3, new noNode ()); }
   |	IF  lexp stmtb  ELSE '{' stmts '}' { $$ = new ifNode ($2, $3, $6); }
   |	IF  lexp stmtb  ELSE  stmt ';' { $$ = new ifNode ($2, $3, new stmtNode ($5, NULL, @1)); }
   |	IF  lexp stmtb  ELSE  stmtb  { $$ = new ifNode ($2, $3, $5); }
   |	IF  lexp '{' '}' elseif { $$ = new ifNode ($2, new noNode (), $5); }
   |	IF  lexp '{' stmts '}' elseif { $$ = new ifNode ($2, $4, $6); }
   |	IF  lexp stmt ';' elseif { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), $5); }
   |	IF  lexp stmtb  elseif { $$ = new ifNode ($2, $3, $4); }
   ;
  
elseif
   :  ELSEIF  lexp '{'  '}'  { $$ = new ifNode ($2, new noNode (), 0); }
   |	ELSEIF  lexp '{' stmts '}'  { $$ = new ifNode ($2, $4, 0); }
   |	ELSEIF  lexp stmt ';'  { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), 0); }
   |	ELSEIF  lexp stmtb   { $$ = new ifNode ($2, $3, 0); }
   |	ELSEIF  lexp '{' stmts '}' ELSE '{'  '}' { $$ = new ifNode ($2, $4, new noNode ()); }
   |	ELSEIF  lexp '{'  '}' ELSE '{' stmts '}' { $$ = new ifNode ($2, new noNode (), $7); }
   |	ELSEIF  lexp '{' stmts '}' ELSE '{' stmts '}' { $$ = new ifNode ($2, $4, $8); }
   |	ELSEIF  lexp '{'  '}' ELSE  stmt ';' { $$ = new ifNode ($2, new noNode (), new stmtNode ($6, NULL, @1)); }
   |	ELSEIF  lexp '{' stmts '}' ELSE  stmt ';' { $$ = new ifNode ($2, $4, new stmtNode ($7, NULL, @1)); }
   |	ELSEIF  lexp '{'  '}' ELSE  stmtb  { $$ = new ifNode ($2, new noNode (), $6); }
   |	ELSEIF  lexp '{' stmts '}' ELSE  stmtb  { $$ = new ifNode ($2, $4, $7); }
   |	ELSEIF  lexp stmt ';' ELSE '{'  '}' { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), new noNode ()); }
   |	ELSEIF  lexp stmt ';' ELSE '{' stmts '}' { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), $7); }
   |	ELSEIF  lexp stmt ';' ELSE  stmt ';' { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), new stmtNode ($6, NULL, @1)); }
   |	ELSEIF  lexp stmt ';' ELSE  stmtb { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), $6); }
   |	ELSEIF  lexp stmtb  ELSE '{'  '}' { $$ = new ifNode ($2, $3, new noNode ()); }
   |	ELSEIF  lexp stmtb  ELSE '{' stmts '}' { $$ = new ifNode ($2, $3, $6); }
   |	ELSEIF  lexp stmtb  ELSE  stmt ';' { $$ = new ifNode ($2, $3, new stmtNode ($5, NULL, @1)); }
   |	ELSEIF  lexp stmtb  ELSE  stmtb  { $$ = new ifNode ($2, $3, $5); }
   |	ELSEIF  lexp '{'  '}' elseif { $$ = new ifNode ($2, new noNode (), $5); }
   |	ELSEIF  lexp '{' stmts '}' elseif { $$ = new ifNode ($2, $4, $6); }
   |	ELSEIF  lexp stmt ';' elseif { $$ = new ifNode ($2, new stmtNode ($3, NULL, @1), $5); }
   |	ELSEIF  lexp stmtb  elseif { $$ = new ifNode ($2, $3, $4); }
   ;

with
   :  WITH exp '{' stmts '}' { $$ = new withNode ($2, $4); }
 	|	 WITH exp  stmt ';' { $$ = new withNode ($2, new stmtNode ($3, NULL, @1)); }
   ;
   
while
   :  WHILE lexp '{' '}'  { $$ = new whileNode ($2,new noNode ()); }
   |	WHILE lexp '{' stmts '}'  { $$ = new whileNode ($2,$4); }
   |	WHILE lexp  stmt ';'  { $$ = new whileNode ($2,new stmtNode ($3, NULL, @1)); }
   |	WHILE lexp  stmtb   { $$ = new whileNode ($2,$3); }
   ;

dowhile
   :  DO  '{' '}' WHILE lexp  ';' { $$ = new dowhileNode ($5,new noNode ()); }
 	|	DO  '{' stmts '}' WHILE lexp  ';' { $$ = new dowhileNode ($6,$3); }
   |	DO  stmt ';' WHILE lexp  ';' { $$ = new dowhileNode ($5,new stmtNode ($2, NULL, @1)); }
   |	DO  stmtb  WHILE lexp ';' { $$ = new dowhileNode ($4,$2); }
   ;

for
   :  FOR '(' exp ';' lexp ';' exp ')' '{'  '}'  { $$ = new forNode ($3, $5, $7, new noNode ()); } 
   |	FOR '(' exp ';' lexp ';' exp ')' '{' stmts '}'  { $$ = new forNode ($3, $5, $7, $10); } 
   |	FOR '(' exp ';' lexp ';' exp ')'  stmt ';'  { $$ = new forNode ($3, $5, $7, new stmtNode ($9, NULL, @1)); } 
   |	FOR '(' exp ';' lexp ';' exp ')'  stmtb   { $$ = new forNode ($3, $5, $7, $9); } 
   |	FOR  exp ';' lexp ';' exp  '{'  '}'  { $$ = new forNode ($2, $4, $6, new noNode ()); } 
   |	FOR  exp ';' lexp ';' exp  '{' stmts '}'  { $$ = new forNode ($2, $4, $6, $8); } 
   |	FOR  exp ';' lexp ';' exp   stmt ';'  { $$ = new forNode ($2, $4, $6, new stmtNode ($7, NULL, @1)); } 
   |	FOR  exp ';' lexp ';' exp   stmtb   { $$ = new forNode ($2, $4, $6, $7); } 
 	|	FOR '(' id IN exp ')' '{' '}' { $$ = new foreachNode ($3, $5, new noNode ()); } 
 	|	FOR '(' id IN exp ')' '{' stmts '}' { $$ = new foreachNode ($3, $5, $8); } 
 	|	FOR '(' id IN exp ')' stmt ';' { $$ = new foreachNode ($3, $5, $7); }
 	|	FOR id IN exp '{'  '}'  { $$ = new foreachNode ($2, $4, new noNode ()); }
 	|	FOR id IN exp '{' stmts '}'  { $$ = new foreachNode ($2, $4, $6); }
 	|	FOR id IN exp stmt ';' { $$ = new foreachNode ($2, $4, $5); }
 	|	FOR '(' id ':' id IN exp ')' '{'  '}' { $$ = new foreachNode ($5, $7, new noNode (), $3); }
 	|	FOR '(' id ':' id IN exp ')' '{' stmts '}' { $$ = new foreachNode ($5, $7, $10, $3); }
 	|	FOR '(' id ':' id IN exp ')' stmt ';' { $$ = new foreachNode ($5, $7, $9, $3); }
 	|	FOR id ':' id IN exp '{'  '}' { $$ = new foreachNode ($4, $6, new noNode (), $2); }
 	|	FOR id ':' id IN exp '{' stmts '}' { $$ = new foreachNode ($4, $6, $8, $2); }
 	|	FOR id ':' id IN exp stmt ';' { $$ = new foreachNode ($4, $6, $7, $2); }
 	|	FOR '(' exp AS id ')' '{'  '}' { $$ = new foreachNode ($5, $3, new noNode ()); } 
 	|	FOR '(' exp AS id ')' '{' stmts '}' { $$ = new foreachNode ($5, $3, $8); } 
 	|	FOR '(' exp AS id ')' stmt ';' { $$ = new foreachNode ($5, $3, $7); }
 	|	FOR exp AS id '{' '}'  { $$ = new foreachNode ($4, $2, new noNode ()); }
 	|	FOR exp AS id '{' stmts '}'  { $$ = new foreachNode ($4, $2, $6); }
 	|	FOR exp AS id stmt ';' { $$ = new foreachNode ($4, $2, $5); }
 	|	FOR '(' exp AS id ':' id ')' '{' '}' { $$ = new foreachNode ($7, $3, new noNode (), $5); }
 	|	FOR '(' exp AS id ':' id ')' '{' stmts '}' { $$ = new foreachNode ($7, $3, $10, $5); }
 	|	FOR '(' exp AS id ':' id ')' stmt ';' { $$ = new foreachNode ($7, $3, $9, $5); }
 	|	FOR exp AS id ':' id '{'  '}' { $$ = new foreachNode ($6, $2, new noNode (), $4); }
 	|	FOR exp AS id ':' id '{' stmts '}' { $$ = new foreachNode ($6, $2, $8, $4); }
 	|	FOR exp AS id ':' id stmt ';' { $$ = new foreachNode ($6, $2, $7, $4); }
   ;

break
   :  BREAK ';'	{ $$ = new breakNode (); }
 	|	BREAK NUM ';'	{ $$ = new breakNode (*$2); }		
 	|	CONTINUE ';'	{ $$ = new continueNode (); }
 	|	CONTINUE NUM ';'	{ $$ = new continueNode (*$2); }	
   ;
   
switch
   :  SWITCH '(' exp ')''{'  '}' { $$ = new switchNode ($3, new noNode ()); }
 	|	SWITCH '(' exp ')''{' cases '}' { $$ = new switchNode ($3, $6); }
   ;

cases 		
   :  CASE exp ':' stmts cases  { $$ = new caseNode ($2, $4, $5); }
 	|	CASE exp ':' stmts  { $$ = new caseNode ($2, $4, NULL);}
 	|	CASE exp ':' cases  { $$ = new caseNode ($2, NULL, $4);}
 	|	DEFAULT ':' stmts { $$ = new caseNode (NULL, $3, NULL);}
   ;
   
iloop
   :  '$''(' exp OPINC  NUM ')' '{'  '}'  { $$ = new incloopNode ($3, new numConstNode(*$5), new noNode ()); } 
 	|	 '$''(' exp OPINC  NUM ')' '{' stmts '}'  { $$ = new incloopNode ($3, new numConstNode(*$5), $8); } 
   |	'$''(' exp OPINC  NUM ')' stmt ';'  { $$ = new incloopNode ($3, new numConstNode(*$5), new stmtNode ($7, NULL, @1)); } 
   |	'$''(' exp OPINC  NUM ')' stmtb  { $$ = new incloopNode ($3, new numConstNode(*$5), $7); } 
   |	'$''(' exp ')' '{'  '}'  { $$ = new iloopNode ($3, new noNode ()); } 
   |	'$''(' exp ')' '{' stmts '}'  { $$ = new iloopNode ($3, $6); } 
   |	'$''(' exp ')' stmt ';'  { $$ = new iloopNode ($3, new stmtNode ($5, NULL, @1)); } 
   |	'$''(' exp ')' stmtb  { $$ = new iloopNode ($3, $5); } 
   |	'$''(' exp AS id ')' '{'  '}'  { $$ = new iloopNode ($3, new noNode (), $5); } 
   |	'$''(' exp AS id ')' '{' stmts '}'  { $$ = new iloopNode ($3, $8, $5); } 
   |	'$''(' exp AS id ')' stmt ';'  { $$ = new iloopNode ($3, new stmtNode ($7, NULL, @1), $5); } 
   |	'$''(' exp AS id ')' stmtb  { $$ = new iloopNode ($3, $7, $5); } 
   |	'$''(' exp AS id ':' id ')' '{'  '}'  { $$ = new iloopNode ($3, new noNode (), $7, $5); } 
   |	'$''(' exp AS id ':' id ')' '{' stmts '}'  { $$ = new iloopNode ($3, $10, $7, $5); } 
   |	'$''(' exp AS id ':' id ')' stmt ';'  { $$ = new iloopNode ($3, new stmtNode ($9, NULL, @1), $7, $5); } 
   |	'$''(' exp AS id ':' id ')' stmtb  { $$ = new iloopNode ($3, $9, $7, $5); } 
   |	'$''(' exp ',' exp ')' '{'  '}'  { $$ = new iloopNode ($3, new noNode (), NULL, NULL, $5); } 
   |	'$''(' exp ',' exp ')' '{' stmts '}'  { $$ = new iloopNode ($3, $8, NULL, NULL, $5); } 
   |	'$''(' exp ',' exp ')' stmt ';'  { $$ = new iloopNode ($3,  new stmtNode ($7, NULL, @1), NULL, NULL, $5); } 
   |	'$''(' exp ',' exp ')' stmtb  { $$ = new iloopNode ($3, $7, NULL, NULL, $5); } 
   |	'$''(' exp AS id ',' exp ')' '{'  '}'  { $$ = new iloopNode ($3, new noNode (), $5, NULL, $7); } 
   |	'$''(' exp AS id ',' exp ')' '{' stmts '}'  { $$ = new iloopNode ($3, $10, $5, NULL, $7); } 
   |	'$''(' exp AS id ',' exp ')' stmt ';'  { $$ = new iloopNode ($3, new stmtNode ($9, NULL, @1), $5, NULL, $7); } 
   |	'$''(' exp AS id ',' exp ')' stmtb  { $$ = new iloopNode ($3, $9, $5, NULL, $7); } 
   |	'$''(' exp AS id ':' id ',' exp ')' '{'  '}'  { $$ = new iloopNode ($3, new noNode (), $7, $5, $9); } 
   |	'$''(' exp AS id ':' id ',' exp ')' '{' stmts '}'  { $$ = new iloopNode ($3, $12, $7, $5, $9); } 
   |	'$''(' exp AS id ':' id ',' exp ')' stmt ';'  { $$ = new iloopNode ($3, new stmtNode ($11, NULL, @1), $7, $5, $9); } 
   |	'$''(' exp AS id ':' id ',' exp ')' stmtb  { $$ = new iloopNode ($3, $11, $7, $5, $9); } 
   ;

trycatch 
   :  TRY '{' stmts '}' CATCH '(' id ')' '{' stmts '}'   { $$ = new tryNode ($3, $7, $10); }
   |  TRY  stmt ';' CATCH '(' id ')' '{' stmts '}'   { $$ = new tryNode (new stmtNode ($2, NULL, @1), $6, $9); }
   |  TRY  stmt ';' CATCH '(' id ')'  stmt ';'   { $$ = new tryNode (new stmtNode ($2, NULL, @1), $6, new stmtNode ($8, NULL, @1)); }
   |  TRY  '{' stmts '}' CATCH '(' id ')'  stmt ';'   { $$ = new tryNode ($3, $7, new stmtNode ($9, NULL, @1)); }
   ;

//======================================================================
function  
   :  FUNCTION id '(' params_default ')' '{' stmts '}'  { $$ = new functionNode ($2, $4, $7); }													
 	|	 FUNCTION id '(' params_default ')' '{' '}'  { $$ = new functionNode ($2, $4, NULL); }													
 	|	 FUNCTION id '('')' '{' stmts '}'  { $$ = new functionNode ($2, NULL, $6); }	
 	|	 FUNCTION id '('')' '{' '}'  { $$ = new functionNode ($2, NULL, NULL); }	
 	|	 '~' id '(' params_default ')' '{' stmts '}'  { $$ = new functionNode ($2, $4, $7); }													
 	|	 '~' id '(' params_default ')' '{' '}'  { $$ = new functionNode ($2, $4, NULL); }													
 	|	 '~' id '('')' '{' stmts '}'  { $$ = new functionNode ($2, NULL, $6); }	
 	|	 '~' id '('')' '{' '}'  { $$ = new functionNode ($2, NULL, NULL); }	
 	|	 DECORATOR id '(' params_default ')' '{' stmts '}'  { $$ = new decoratorNode ($2, $4, $7); }													
 	|	 DECORATOR id '(' params_default ')' '{' '}'  { $$ = new decoratorNode ($2, $4, NULL); }													
 	|	 DECORATOR id '('')' '{' stmts '}'  { $$ = new decoratorNode ($2, NULL, $6); }	
 	|	 DECORATOR id '('')' '{' '}'  { $$ = new decoratorNode ($2, NULL, NULL); }	
   ;   
      
class 
   :  CLASS id '{' stmts '}'  { $$ = new classNode ($2, $4); }
 	|	 CLASS id EXTENDS id '{' stmts '}' { $$ = new classNode ($2, $6, $4); }		
 	|	 STATIC function { $$ = new staticNode ($2); }
 	|	 PRIVATE function { $$ = new privateNode ($2); }										
   ;

params_default
   :   params_default ',' id '=' identity { $$ = new listNode ($1, new asigNode ($3, $5)); }
 	|	  params ',' id '=' identity { $$ = new listNode ($1, new asigNode ($3, $5)); }
 	|	  id '=' identity { $$ = new listNode (new asigNode ($1, $3), NULL); }
 	|	  params { $$ = $1; }
   ;
  
params		
   :	params ',' id { $$ = new listNode ($1, $3); } 
   |	params ',' '&' id { $$ = new listNode ($1, new refparamNode($4));}
   |	id  { $$ = new listNode ($1, NULL);}
   |	'&' id  { $$ =  new listNode (new refparamNode ($2), NULL); }
   ;

component 
   : DEF exp '{' stmts '}' { $$ = new defCNode ($2, $4); }
	|	DEF exp '{' stmts '}' FROM exp ';' { $$ = new defCNode ($2, $4, NULL, $7); }
	|	DEF exp '{' stmts '}' '!' EXIST '{' stmts '}' { $$ = new defCNode ($2, $4, $9); }
	|	DEF exp '{' stmts '}' '!' EXIST '{' stmts '}' FROM exp ';' { $$ = new defCNode ($2, $4, $9, $12); }
	|	DEF exp LIKE exp '{' stmts '}' { $$ = new defCNode ($2, $6, NULL, NULL, $4); }
	|	DEF exp LIKE exp '{' stmts '}' FROM exp ';' { $$ = new defCNode ($2, $6, NULL, $9, $4); }
	|	DEF exp LIKE exp '{' stmts '}' '!' EXIST '{' stmts '}' { $$ = new defCNode ($2, $6, $11, NULL, $4); }
	|	DEF exp LIKE exp '{' stmts '}' '!' EXIST '{' stmts '}' FROM exp ';' { $$ = new defCNode ($2, $6, $11, $14, $4); }
	|	DEF exp EXTENDS exp '{' stmts '}' { $$ = new defCNode ($2, $6, NULL, NULL, NULL, $4); }
	|	DEF exp EXTENDS exp '{' stmts '}' FROM exp ';' { $$ = new defCNode ($2, $6, NULL, $9, NULL, $4); }
	|	DEF exp EXTENDS exp '{' stmts '}' '!' EXIST '{' stmts '}' { $$ = new defCNode ($2, $6, $11, NULL, NULL, $4); }
	|	DEF exp EXTENDS exp '{' stmts '}' '!' EXIST '{' stmts '}' FROM exp ';' { $$ = new defCNode ($2, $6, $11, $14, NULL, $4); }
	|	CDATA exp '{' stmts '}' { $$ = new dataCNode ($2, $4); } 
	|	exp '=''>' exp '=''>' exp ';' { $$ = new setCNode ($1, $4, $7); }
	|	exp '=''>' exp ';' { $$ = new setCNode (NULL, $1, $4); }
	|	exp '=''>' exp '{' exp '}' ';' { $$ = new setCNode (NULL, $1, $4, false, false, $6); }
	|	exp REFDEF exp ';' { $$ = new setCNode (NULL, $1, $3, true); }
	|	exp REFREL exp ';' { $$ = new setRelCNode ($1, $3); }
	|	exp IDDEF exp ';' { $$ = new setCNode (NULL, $1, $3, false, true); }
	|	exp CDATA exp '{' stmts '}' { $$ = new setCNode (NULL, $1, new dataCNode ($3, $5)); } 
	|	exp '{' stmts '}'  { $$ = new relCNode ($1, $3); }
	|	CDATA exp ';'  { $$ = new setExistRelCNode ($2); }
  ;
						
//======================================================================
exp 	
   :  lexp  { $$ = $1; }
   ;

lexp 		
   :  lop1  { $$ = $1; }
   ;

lop1 		
   :  lop1 OR_OP lop2  { $$ = new orNode ($1, $3); }
   |  lop2  { $$ = $1; }
   ;
			
lop2		
   :  lop2 AND_OP lop3  { $$ = new andNode ($1, $3); }
   |  lop3  { $$ = $1;  }
   ;
			
lop3		
   :  '!' lop3  { $$ = new notNode ($2);}
	|  lop4  { $$ = $1;}
   ;
			
lop4	
   :	aexp '<' aexp { $$ = new lthNode ($1, $3); }
   |	aexp '<''=' aexp  { $$ = new leqNode ($1, $4); }
   |	aexp '>' aexp { $$ = new gthNode ($1, $3); }
   |	aexp '>''=' aexp  { $$ = new geqNode ($1, $4); }
   |	aexp EQL aexp { $$ = new eqNode ($1, $3); }
   |	aexp IDEN aexp  { $$ = new idenNode ($1, $3); }
   |	aexp NIDEN aexp { $$ = new nidenNode ($1, $3); }
   |	aexp '!''=' aexp  { $$ = new neqNode ($1, $4); } 
   |	aexp  { $$ = $1; }
   ;
   
//======================================================================
aexp	
   :  aop1  { $$ = $1; }
   ;

aop1		
   :	aop1 '+' aop2 { $$ = new addNode ($1, $3); }
   |	aop1 '-' aop2 { $$ = new subNode ($1, $3); }
   |  aop1 SNUM	{
         if ($2 < 0)
         $$ = new subNode ($1, new numConstNode (*$2));
         else
         $$ = new addNode ($1, new numConstNode (*$2));
      }
   |	aop2  { $$ = $1; }
   ;
			
aop2		
   :   aop2 '*' aop3 { $$ = new prodNode ($1, $3); }
   |   aop2 '/' aop3 { $$ = new divNode ($1, $3); }
   |  aop3  { $$ = $1; }
   ;
			
aop3		
   :  aop3 '^' sexp { $$ = new powNode ($1, $3); }
   |  aop3 '%' sexp { $$ = new modNode ($1, $3); }
   |  sexp  { $$ = $1; }
   ;
   
//======================================================================
sexp 		
   :  sop1  { $$ = $1;}					
   ;

sop1		
   :  sop2 '.' sop1  { $$ = new catNode ($1, $3); }
   |  sop2 FLOW sop1  { $$ = new catNode ($1, $3); }
   |  sop2  { $$ = $1; }
   ;

sop2		
   :  INPUT id  { $$ = new inputNode ($2, 0); }
   |  INPUTLINE id  { $$ = new inputNode ($2, 1); }
   |	INPUT '[' exp ']'	id  { $$ = new inputNode ($5, 0, $3); }	 
   |	INPUTLINE '[' exp ']'	id  { $$ = new inputNode ($5, 1, $3); }	 
   |	INPUT { $$ = new inputNode (new idNode ("user") , 0); }
   |	INPUTLINE { $$ = new inputNode (new idNode ("user") , 1); }
   |	INPUT '[' exp ']'  { $$ = new inputNode (new idNode ("user"), 0, $3); }
   |	INPUTLINE '[' exp ']'  { $$ = new inputNode (new idNode ("user"), 1, $3); }
	|	call_identity  { $$ = $1;}
   ;
   
//======================================================================
call_identity
   :  call_identity '(' list	')' { $$ = new functioncallNode ($1, $3); }
   |	call_identity '('')' { $$ = new functioncallNode ($1, NULL);}
   |  extra_operator { $$ = $1; }
   ;
   
//======================================================================
extra_operator
   :	tern { $$ = $1; }
	|	notnull { $$ = $1; }
   |  unity { $$ = $1; }
   ;
   
tern
   :  exp '?' exp ':' exp { $$ = new ternNode ( $1, $3, $5 ); }
	|	exp '?'':' exp { $$ = new ternNode ( $1, NULL, $4 ); }
	|	exp '?' exp { $$ = new ternNode ( $1, $3, NULL ); }
   ;
   
notnull
   :  '[''[' list ']'']' { $$ = new notnullNode ($3); }
   ;   
   
//======================================================================
unity
   :  inc_dec  {$$ = $1; }
   |  assignation { $$ = $1; }
   |	cexp  { $$ = $1;}
   |  lop_unity { $$ = $1; }
   |  aop_unity { $$ = $1; }
   |  sop_unity { $$ = $1; }
   |  class_exp { $$ = $1; }
   |	arrayexp  { $$ = $1; }
   |  date  { $$ = $1; }
   |  file  { $$ = $1; }
   |  process  { $$ = $1; }
   |	exp_generator { $$ = $1; }
   |  environment { $$ = $1; }
   |  regexp_op { $$ = $1; }
   |  iloop_access { $$ = $1; }
   |  component_unity { $$ = $1; }
   |  identity { $$ = $1; }
   |  function_exp { $$ = $1; } 
	;

inc_dec
   :	INC exp	  { $$ = new incasigNode ($2); }
   |	exp	INC { $$ = new asigincNode ($1); }
   |	DEC exp { $$ = new decasigNode ($2); }
   |	exp	DEC { $$ = new asigdecNode ($1); }
   ;

assignation
   :  exp ADDASIG exp { $$ = new asigNode ($1, new addNode ($1, $3));} 
   |	exp SUBASIG exp { $$ = new asigNode ($1, new subNode ($1, $3));} 
   |	exp PRODASIG exp  { $$ = new asigNode ($1, new prodNode ($1, $3));} 
   |	exp DIVASIG exp { $$ = new asigNode ($1, new divNode ($1, $3));} 
   |	exp POWASIG exp { $$ = new asigNode ($1, new powNode ($1, $3));} 
   |	exp MODASIG exp { $$ = new asigNode ($1, new modNode ($1, $3));} 
   |	exp CATASIG exp { $$ = new asigNode ($1, new catNode ($1, $3));} 
   |	assig  { $$ = $1; }
   ;

cexp 		
   :	CINT unity { $$ = new intconvNode ($2);}
   |	CFLOAT unity { $$ = new floatconvNode ($2);}
   |	CBOOL unity  { $$ = new boolconvNode ($2);}
   |	CSTR unity  { $$ = new strconvNode ($2);}	
   |  '(' CINT ')' unity { $$ = new intconvNode ($4);}
   |	'(' CFLOAT ')' unity { $$ = new floatconvNode ($4);}
   |	'(' CBOOL ')' unity  { $$ = new boolconvNode ($4);}
   |	'(' CSTR ')' unity  { $$ = new strconvNode ($4);}
   ;
  
lop_unity
   :  ISNULL exp { $$ = new isNullNode ($2); }
   :  ISARRAY exp { $$ = new isArrayNode ($2); }
   |	EMPTY '(' exp ')' { $$ = new emptyNode ( $3 ); }
   ;
  
aop_unity
   :  SIZE exp  { $$ = new sizeNode ($2);}
   |  SIZEOF exp  { $$ = new sizeOfNode ($2);}
   |  SIZEOF  { $$ = new sizeOfNode (NULL);}
   ;

sop_unity
   :  EXPLODE '(' exp ',' exp ')' { $$ = new explodeNode ($5, $3); }
	|	IMPLODE '(' exp ',' exp ')' { $$ = new implodeNode ($5, $3 ); }
	|	SPRINTF '(' list ')' { $$ = new sprintfNode ( $3 ); }
   |  FIND '(' exp ',' exp ',' exp ')' { $$ = new findNode ( $3, $5, $7); }
	|	FIND '(' exp ',' exp ')' { $$ = new findNode ( $3, $5, NULL); }
	|	REPLACE '(' exp ',' exp ',' exp ',' exp ')' { $$ = new replaceNode ( $5, $7, $3, $9); }
	|	REPLACE '(' exp ',' exp ',' exp ')' { $$ = new replaceNode ( $5, $7, $3, NULL); }
	|	SUBREPLACE '(' exp ',' exp ',' exp ',' exp ')' { $$ = new subreplaceNode ( $5, $7, $9, $3); }
	|	UPPER '(' exp  ')' { $$ = new upperNode ( $3 ); }
	|	LOWER '(' exp  ')' { $$ = new lowerNode ( $3 ); }
   ;

class_exp
   :	NEW id '('')' { $$ = new newNode ($2, NULL);}
   |	NEW id  { $$ = new newNode ($2, NULL);}
   |	NEW id '(' list ')' { $$ = new newNode ($2, $4);}
	|	THIS  { $$ = new thisNode (); }
	|	PARENT  { $$ = new parentNode (); }
   |	namespace  { $$ = $1; }
   ;

arrayexp	
   :  '{' array '}' { $$ = new arrayConstNode ($2); }
   |  '{' map '}' { $$ = new arrayConstNode ($2); }
   |  '{''}'  { $$ = new arrayNode (); }
   |  parray { $$ = $1; }
   |	arrayop { $$ = $1; }
   ;

date
   :	DATE '(' exp ')' { $$ = new dateNode ( $3 ); }
	|	TIME '(' ')' { $$ = new timeNode ( ); }
	|	TIME { $$ = new timeNode ( ); }
   ;

file
   :  FTOKEN '(' exp ',' exp ')' { $$ = new fileNode ($3, $5); }
	|	FTOKEN '(' exp ')' { $$ = new fileNode ($3); }
	|	FPUT '(' exp ',' exp ')' { $$ = new fputNode ($3, $5); } 
	|	FWRITE '(' exp ',' exp ')' { $$ = new fwriteNode ($3, $5); }
	|	FAPP '(' exp ',' exp ')' { $$ = new fappendNode ($3, $5); }
	|	FGET '(' exp ')' { $$ = new fgetNode ($3); }
	|	FGET '(' exp ',' exp ')' { $$ = new fgetNode ($3, $5); }
	|	FREAD '(' exp ')' { $$ = new freadNode ($3); }
	|	FCLOSE '(' exp ')' { $$ = new fcloseNode ($3); }
	|	FSEEK '(' exp ',' exp ')' { $$ = new fseekNode ($3, $5); }
	|	FSEEK '(' exp ',' exp ',' FSET ')' { $$ = new fseekNode ($3, $5, 0); }
	|	FSEEK '(' exp ',' exp ',' FCUR ')' { $$ = new fseekNode ($3, $5, 1); }
	|	FSEEK '(' exp ',' exp ',' FEND ')' { $$ = new fseekNode ($3, $5, 2); }
	|	FTELL '(' exp ')' { $$ = new ftellNode ($3); }
	;

process
   :	EXEC '(' exp ')'	{ $$ = new execNode ($3); }
	|	EVAL '(' exp ')'	{ $$ = new evalNode ($3); }
   |	FORK '(' ')' { $$ = new forkNode (); }
	|	WAIT '(' exp ')' { $$ = new waitNode ( $3 ); }
	|	WAIT '(' ')' { $$ = new waitNode ( NULL ); }
	|	SIGNAL '(' exp ',' exp ')' { $$ = new signalNode ( $3,$5 ); }
	|	SHANDLER '(' exp ',' exp ')' { $$ = new signalhandlerNode ( $3,$5 ); }
	|	EXITPROCESS '(' ')' { $$ = new exitProcessNode (  ); }
	|	GETPID '(' ')' { $$ = new getpidNode (  ); }
	|	GETPPID '(' ')' { $$ = new getppidNode (  ); }
	|	PROCESSTOKEN '(' exp ',' list ')' { $$ = new processNode ($3, $5 ); }
	|	PROCESSTOKEN '(' exp ')' { $$ = new processNode ($3, NULL ); }
   ;

environment
   :  GETENV '(' exp ')' { $$ = new getEnvNode ($3); }
   ;
   
exp_generator
   :  '(' exp FOR id IN exp ')' { $$ = new foreachGeneratorNode ($2, $4, $6, NULL); } 
	|	'(' exp FOR id IN exp '{' stmts '}' ')' { $$ = new foreachGeneratorNode ($2, $4, $6, $8); } 
	|	'(' exp FOR id IN exp  stmt ')' { $$ = new foreachGeneratorNode ($2, $4, $6, $7); } 
	|	'(' exp FOR id IN exp IF exp ')' { $$ = new foreachGeneratorNode ($2, $4, $6, NULL, NULL, $8); } 
	|	'(' exp FOR id IN exp '{' stmts '}' IF exp ')' { $$ = new foreachGeneratorNode ($2, $4, $6, $8, NULL, $11); } 
	|	'(' exp FOR id IN exp  stmt IF exp ')' { $$ = new foreachGeneratorNode ($2, $4, $6, $7, NULL, $9); } 
	|	'(' exp FOR '(' id IN exp ')' ')' { $$ = new foreachGeneratorNode ($2, $5, $7, NULL); } 
	|	'(' exp FOR '(' id IN exp ')' '{' stmts '}' ')' { $$ = new foreachGeneratorNode ($2, $5, $7, $10); } 
	|	'(' exp FOR '(' id IN exp ')' stmt ')' { $$ = new foreachGeneratorNode ($2, $5, $7, $9); } 
	|	'(' exp FOR '(' id IN exp ')' IF exp ')' { $$ = new foreachGeneratorNode ($2, $5, $7, NULL, NULL, $10); } 
	|	'(' exp FOR '(' id IN exp ')' '{' stmts '}' IF exp ')' { $$ = new foreachGeneratorNode ($2, $5, $7, $10, NULL, $13); } 
	|	'(' exp FOR '(' id IN exp ')'  stmt IF exp ')' { $$ = new foreachGeneratorNode ($2, $5, $7, $9, NULL, $11); } 
	|	'(' exp FOR id ':' id IN exp ')' { $$ = new foreachGeneratorNode ($2, $6, $8, NULL, $4); } 
	|	'(' exp FOR id ':' id IN exp '{' stmts '}' ')' { $$ = new foreachGeneratorNode ($2, $6, $8, $10, $4); } 
	|	'(' exp FOR id ':' id IN exp  stmt ')' { $$ = new foreachGeneratorNode ($2, $6, $8, $9, $4); } 
	|	'(' exp FOR id ':' id IN exp IF exp ')' { $$ = new foreachGeneratorNode ($2, $6, $8, NULL, $4, $10); } 
	|	'(' exp FOR id ':' id IN exp '{' stmts '}' IF exp ')' { $$ = new foreachGeneratorNode ($2, $6, $8, $10, $4, $13); } 
	|	'(' exp FOR id ':' id IN exp  stmt IF exp ')' { $$ = new foreachGeneratorNode ($2, $6, $8, $9, $4, $11); } 
	|	'(' exp FOR '(' id ':' id IN exp ')' ')' { $$ = new foreachGeneratorNode ($2, $7, $9, NULL, $5); } 
	|	'(' exp FOR '(' id ':' id IN exp ')' '{' stmts '}' ')' { $$ = new foreachGeneratorNode ($2, $7, $9, $12, $5); } 
	|	'(' exp FOR '(' id ':' id IN exp ')' stmt ')' { $$ = new foreachGeneratorNode ($2, $7, $9, $11, $5); } 
	|	'(' exp FOR '(' id ':' id IN exp ')' IF exp ')' { $$ = new foreachGeneratorNode ($2, $7, $9, NULL, $5, $12); } 
	|	'(' exp FOR '(' id ':' id IN exp ')' '{' stmts '}' IF exp ')' { $$ = new foreachGeneratorNode ($2, $7, $9, $12, $5, $15); } 
	|	'(' exp FOR '(' id ':' id IN exp ')'  stmt IF exp ')' { $$ = new foreachGeneratorNode ($2, $7, $9, $11, $5, $13); } 
	|	'(' exp ':' exp FOR id IN exp ')' { $$ = new foreachGeneratorNode ($4, $6, $8, NULL, NULL, NULL, $2); } 
	|	'(' exp ':' exp FOR id IN exp '{' stmts '}' ')' { $$ = new foreachGeneratorNode ($4, $6, $8, $10, NULL, NULL, $2); } 
	|	'(' exp ':' exp FOR id IN exp  stmt ')' { $$ = new foreachGeneratorNode ($4, $6, $8, $9, NULL, NULL, $2); } 
	|	'(' exp ':' exp FOR id IN exp IF exp ')' { $$ = new foreachGeneratorNode ($4, $6, $8, NULL, NULL, $10, $2); } 
	|	'(' exp ':' exp FOR id IN exp '{' stmts '}' IF exp ')' { $$ = new foreachGeneratorNode ($4, $6, $8, $10, NULL, $13, $2); } 
	|	'(' exp ':' exp FOR id IN exp  stmt IF exp ')' { $$ = new foreachGeneratorNode ($4, $6, $8, $9, NULL, $11, $2); } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' ')' { $$ = new foreachGeneratorNode ($4, $7, $9, NULL, NULL, NULL, $2); } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' '{' stmts '}' ')' { $$ = new foreachGeneratorNode ($4, $7, $9, $12, NULL, NULL, $2); } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' stmt ')' { $$ = new foreachGeneratorNode ($4, $7, $9, $11, NULL, NULL, $2); } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' IF exp ')' { $$ = new foreachGeneratorNode ($4, $7, $9, NULL, NULL, $12, $2); } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' '{' stmts '}' IF exp ')' { $$ = new foreachGeneratorNode ($4, $7, $9, $12, NULL, $15, $2); } 
	|	'(' exp ':' exp FOR '(' id IN exp ')'  stmt IF exp ')' { $$ = new foreachGeneratorNode ($4, $7, $9, $11, NULL, $13, $2); } 
	|	'(' exp ':' exp FOR id ':' id IN exp ')' { $$ = new foreachGeneratorNode ($4, $8, $10, NULL, $6, NULL, $2); } 
	|	'(' exp ':' exp FOR id ':' id IN exp '{' stmts '}' ')' { $$ = new foreachGeneratorNode ($4, $8, $10, $12, $6, NULL, $2); } 
	|	'(' exp ':' exp FOR id ':' id IN exp  stmt ')' { $$ = new foreachGeneratorNode ($4, $8, $10, $11, $6, NULL, $2); } 
	|	'(' exp ':' exp FOR id ':' id IN exp IF exp ')' { $$ = new foreachGeneratorNode ($4, $8, $10, NULL, $6, $12, $2); } 
	|	'(' exp ':' exp FOR id ':' id IN exp '{' stmts '}' IF exp ')' { $$ = new foreachGeneratorNode ($4, $8, $10, $12, $6, $15, $2); } 
	|	'(' exp ':' exp FOR id ':' id IN exp  stmt IF exp ')' { $$ = new foreachGeneratorNode ($4, $8, $10, $11, $6, $13, $2); } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' ')' { $$ = new foreachGeneratorNode ($4, $9, $11, NULL, $7, NULL, $2); } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' '{' stmts '}' ')' { $$ = new foreachGeneratorNode ($4, $9, $11, $14, $7, NULL, $2); } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' stmt ')' { $$ = new foreachGeneratorNode ($4, $9, $11, $13, $7, NULL, $2); } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' IF exp ')' { $$ = new foreachGeneratorNode ($4, $9, $11, NULL, $7, $14, $2); } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' '{' stmts '}' IF exp ')' { $$ = new foreachGeneratorNode ($4, $9, $11, $14, $7, $17, $2); } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')'  stmt IF exp ')' { $$ = new foreachGeneratorNode ($4, $9, $11, $13, $7, $15, $2); } 
   ;

regexp_op
   :	REGEXP '(' exp ')' { $$ = new newregexpNode ( $3 ); }
	|	SEARCH '(' exp ',' exp ')' { $$ = new searchNode ( $3, $5 ); }
	|	SEARCH '(' exp ',' exp ',' list ')' { $$ = new searchNode ( $3, $5, $7 ); }
	|	MATCH '(' exp ',' exp ')'  { $$ = new matchNode ( $3, $5);}
   ;

iloop_access
   :	'$' { $$ = new getiNode (); }
	|	'$' '{' NUM '}' { $$ = new getiNode (new numConstNode (*$3)); }
   ;

component_unity
   :	 SDATA '('exp ','  exp ')'   { $$ = new selCNode ($3, $5); }
	|	 exp '@' NUM   { $$ = new selCNode ($1, new numConstNode (*$3), true); }
	|	 exp '@' STR   { $$ = new selCNode ($1, new strConstNode (*$3), true); }
	|	 exp '@' id   { $$ = new selCNode ($1, $3, true); }
	|	 exp '@' '$'   { $$ = new selCNode ($1, new getiNode (), true); }
	|	 SDATA '('exp')'   { $$ = new selCNode ($3, NULL); }
	|	 DDATA '('exp ','  exp ')'   { $$ = new delCNode ($3, $5); }
	|	 DDATA '('exp')'   { $$ = new delCNode ($3, NULL); }
	|	 EXIST exp { $$ = new existDefCNode ($2); }
   ;

identity	
   :	NUM { $$ = new numConstNode (*$1); }
   |	TRUE  { $$ = new boolConstNode (true); }
	|	FALSE { $$ = new boolConstNode (false); }
	|	NULLTOKEN { $$ = new nullNode (); }
	|	SNUM  { $$ = new numConstNode (*$1); } 
   |	STR { $$ = new strConstNode(*$1);}
   |	REXP  { $$ = new regexpNode(*$1);}
   |	'+' NUM { $$ = new numConstNode (*$2); }
   |	'-' NUM { $$ = new numConstNode (-1 * (*$2)); } 
	|	id  { $$ = $1;}
   ;
  
function_exp
   :  function_lambda { $$ = $1; }
   |  function_decorator   { $$ = $1; }
	|	function_partial { $$ = $1; }
   |	CONTEXTFUNC { $$ = new contextFunction(); }
   ;

//======================================================================
function_lambda
   :	FUNCTION '('')' '{' stmts '}'  { $$ = new functionNode (NULL, NULL, $5); }	
   |	FUNCTION '(' params_default ')' '{' stmts '}'  { $$ = new functionNode (NULL, $3, $6); }	
   |	FUNCTION '(' params_default ')' '{' '}'  { $$ = new functionNode (NULL, $3, NULL); }	
   |	FUNCTION '('')' '{' '}'  { $$ = new functionNode (NULL, NULL, NULL); }
   |	FUNCTION '&' id { $$ = new functiongetNode ($3); }
   |	'~' '('')' '{' stmts '}'  { $$ = new functionNode (NULL, NULL, $5); }	
   |	'~' '(' params_default ')' '{' stmts '}'  { $$ = new functionNode (NULL, $3, $6); }	
   |	'~' '(' params_default ')' '{' '}'  { $$ = new functionNode (NULL, $3, NULL); }	
   |	'~' '('')' '{' '}'  { $$ = new functionNode (NULL, NULL, NULL); }
	|	'~' '&' id { $$ = new functiongetNode ($3); }
	|	'~' params_default ':' exp  { $$ = new functionLambdaNode ($2, $4); } 
   ;
   
function_decorator
   :	DECORATOR '('')' '{' stmts '}'  { $$ = new decoratorNode (NULL, NULL, $5); }	
   |	DECORATOR '(' params_default ')' '{' stmts '}'  { $$ = new decoratorNode (NULL, $3, $6); }	
   |	DECORATOR '(' params_default ')' '{' '}'  { $$ = new decoratorNode (NULL, $3, NULL); }	
   |	DECORATOR '('')' '{' '}'  { $$ = new decoratorNode (NULL, NULL, NULL); }
   ;
   
function_partial 
   :  PARTIALFUNC '[' params_default ']' id  { $$ = new partialFunctionNode ($3, $5); }
 	|	PARTIALFUNC '[' params_default ']' function_exp  { $$ = new partialFunctionNode ($3, $5); }
 	|	PARTIALFUNC '[' params_default ']' arrayexp  { $$ = new partialFunctionNode ($3, $5); }
 	|	PARTIALFUNC '[' params_default ']' '(' id ')' { $$ = new partialFunctionNode ($3, $6); }
 	|	PARTIALFUNC '[' params_default ']' '(' function_exp ')'  { $$ = new partialFunctionNode ($3, $6); }
 	|	PARTIALFUNC '[' params_default ']' '(' arrayexp ')'  { $$ = new partialFunctionNode ($3, $6); }
 	|	'[' params_default ']' unity  { $$ = new partialFunctionNode ($2, $4, true); }
   ;

//======================================================================
list 		
   :  list ','   { $$ = new listNode ($1, NULL);}
   |  list ',' exp  { $$ = new listNode ($1, $3);}
   |	exp { $$ = new listNode ($1, NULL); }
   ;
	
map			
   :	map ',' mapelement  { $$ = new listNode ($1, $3); }
	|	map ','  { $$ = new listNode ($1, NULL); }
	|	mapelement  { $$ = new listNode ($1); }
   ;
   
mapelement	
   :	exp ':' exp { $$ = new mapNode ($1, $3); }
   |	function { $$ = $1; }
   ;  
   
//======================================================================
assig		
   :  exp '=' exp { $$ = new asigNode	 ($1, $3); } 
   |  exp '=' '&' id  { $$ = new asigrefNode ($1, $4); }
   |  '(' exp ')' { $$ = $2; }
	|  exp '=' function { $$ = new asigNode ($1, $3); }
   ;
   
//======================================================================
array		
  :	array ',' exp { $$ = new listNode ($1, $3); }		
  |	exp { $$ = new listNode ($1); }
  ;

parray      
	:   parray CLASSACCESS id { $$ = new getNode ($1, $3, false); }
	|	parray '[' exp ']'	{ $$ = new getNode ($1, $3); }
	|	call_identity CLASSACCESS id	{ $$ = new getNode ($1, $3, false);}
	|	unity '[' exp ']'	{ $$ = new getNode ($1, $3);}
	|	call_identity '[' exp ']'	{ $$ = new getNode ($1, $3);}
	|	parray '['']' {$$ = $$ = new getNode ($1, new getNode_endValue ());}
	|	unity '['']'  {$$ = new getNode ($1, new getNode_endValue ());}
	|	call_identity '['']'  {$$ = new getNode ($1, new getNode_endValue ());}
	;

arrayop 
  :   ARRAYCHUNK '(' exp ',' exp ')' { $$ = new arrayChunkNode ($3, $5); }
  |   REDUCE '(' exp ',' exp ')' { $$ = new reduceNode ($3, $5); }
  ;

//======================================================================
namespace      
	:  namespace NAMESPACE id { $$ = new namespaceNode ($1, $3); }
	|	id NAMESPACE id	{ $$ = new namespaceNode ($1, $3); }
	|	PARENT NAMESPACE id	{ $$ = new namespaceNode (new parentNode(), $3); }
	|	STATIC NAMESPACE id	{ $$ = new namespaceNode (new staticNode(), $3); }
	;
   
//======================================================================
id 			
  :	ID  { $$ = new idNode (*$1); }
  ;

//======================================================================
%%
int main(int argc, char *argv[]) {
	interpreter::init(argc, argv)->run();
}
//======================================================================
