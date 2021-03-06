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
%}

%defines

%token NUM SNUM REXP STR NULLTOKEN TRUE FALSE ID OP PRINT INC DEC  NAMESPACE INCLUDE GLOBAL
%token ISNULL EQL AND_OP OR_OP ISARRAY ISNUM ISBOOL ISSTRING ISOBJECT 
%token FUNCTION PARTIALFUNC RET DECORATOR CONTEXTFUNC
%token CLASS NEW CLASSACCESS THIS PARENT PRIVATE STATIC EXTENDS GETCLASS
%token IF ELSE ELSEIF WITH DO WHILE AS OPINC FOR IN GOTO SWITCH CASE DEFAULT TYPEOF SIZEOF DATINFO BREAK EXIT SIZE EMPTY CONTINUE TRY CATCH THROW FLOW FLOWLINE SQRT
%token ADDASIG SUBASIG PRODASIG DIVASIG POWASIG MODASIG CATASIG IDEN NIDEN
%token EXPLODE IMPLODE SPRINTF FIND REPLACE SUBREPLACE UPPER LOWER DATE TIME SLEEP GETENV
%token REDUCE 
%token FTOKEN FPUT FGET FSEEK FEND FCUR FSET FTELL FCLOSE FREAD FWRITE FAPP
%token FORK WAIT GETPID GETPPID PROCESSTOKEN EXITPROCESS SIGNAL SHANDLER
%token INPUT INPUTLINE
%token MATCH REGEXP SEARCH 
%token EXEC EVAL
%token ARRAYCHUNK ARRAYLAST ARRAYFIRST ARRAYINSERT ARRAYDELETE ARRAYUNSHIFT ARRAYPUSH ARRAYSHIFT ARRAYPOP
%token LOAD_MODULE
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
%type <data> stmts_level stmts stmt stmtb exp label cases define function function_exp function_partial class
%type <data> if elseif with while dowhile for break switch iloop trycatch
%type <data> lblock lexp lop1 lop2 lop3 lop4 
%type <data> aexp aop1 aop2 aop3  
%type <data> sexp sop1 sop2
%type <data> arrayop
%type <data> extra_operator tern notnull exp_generator unity
%type <data> assignation inc_dec lop_unity aop_unity sop_unity class_exp arrayexp date file process environment regexp_op iloop_access 
%type <data> function_lambda
%type <data> params params_default list
%type <data> identity call_identity assig  parray 
%type <data> namespace 
%type <listnode> array map 
%type <data> mapelement  
%type <idnode> id 
%type <data> cexp

%printer { fprintf (yyoutput, "%s", *$$); } ID;


%%

//======================================================================
program		
   :  stmts    { 
         #if JSON==1
          if (interpreter::get()->json){
            interpreter::jsonInit();
            interpreter::get()->steps_count = 1;
            interpreter::to_json($1->json);
         }
         #endif
         $1->run(); 
         #if JSON==1
         if (interpreter::get()->json){
            interpreter::jsonEnd();
         }
         #endif
      }
 	|  %empty   { ;} 
   ;

stmts 		
   :  stmt ';' stmts { 
         runNode * r = new stmtNode ($1, $3, @1, true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 2);
         }
         #endif
         $$ = r;
      } 
 	|  stmtb stmts { 
         runNode * r = new stmtNode ($1, $2, @1, true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$2};
            r->toJson ("stmtNode", "stmt", a, NULL, 2);
         }
         #endif
         $$ = r;
      } 
   |	stmtb {    
         runNode * r = new stmtNode ($1, NULL, @1, true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1,};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r;
      }
 	|  stmt  { 
         runNode * r = new stmtNode ($1, NULL, @1, true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1,};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r;
      }
 	|  stmt ';' { 
         runNode * r = new stmtNode ($1, NULL, @1, true);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r;
      }
   |	label stmts { 
         runNode * r =new labelNode ($1, $2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$2};
            r->toJson ("labelNode", "label", a, NULL, 2);
         }
         #endif
         $$ = r;
      } 
 	|  error ';' stmts   { $$ = $3; }
   |	';'   { 
         $$ = new noNode ();
      }
   ;

stmts_level 		
   :  stmt ';' stmts_level { 
         runNode * r =new stmtNode ($1, $3, @1, false);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 2);
         }
         #endif
         $$ = r; 
      } 
 	|  stmtb stmts_level { 
         runNode * r =new stmtNode ($1, $2, @1, false);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$2};
            r->toJson ("stmtNode", "stmt", a, NULL, 2);
         }
         #endif
         $$ = r; 
      }
   |	stmtb {
         runNode * r =new stmtNode ($1, NULL, @1, false);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
 	|  stmt  {
         runNode * r =new stmtNode ($1, NULL, @1, false); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
 	|  stmt ';' {
         runNode * r =new stmtNode ($1, NULL, @1, false);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |	label stmts_level { 
         runNode * r =new labelNode ($1, $2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$2};
            r->toJson ("labelNode", "label", a, NULL, 2);
         }
         #endif
         $$ = r; 
      } 
 	|  error ';' stmts_level   { $$ = $3; }
   |	';'   {$$ = new noNode ();}
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
   |  PRINT exp { 
         runNode * r =new printNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("printNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |  FLOW exp {       
         runNode * r =  new printNode ($2, true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("printNode", "stmt", a, NULL, 1);
         }
         #endif
            $$ = r;
      }
   |  FLOWLINE exp { 
         runNode * r =new printNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("printNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |	GOTO id { 
         runNode * r =new gotoNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("gotoNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }	 
   |	INCLUDE	exp {
         runNode * r =new includeNode ( $2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("includeNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |	RET	exp {
         runNode * r =new returnNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("returnNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |	RET { 
         runNode * r =new returnNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("returnNode", "stmt", NULL, 0);
         }
         #endif
         $$ = r; 
      }
   |	SLEEP '(' exp ')' { 
         runNode * r =new sleepNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("sleepNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
 	|  LOAD_MODULE '(' exp ')' { 
         loadNode * r =new loadNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("loadNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r;  
      }
 	|  STATIC  exp  { 
         runNode * r =new staticNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("staticNode", "class", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
 	|  PRIVATE  exp  {
         runNode * r =new privateNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("privateNode", "class", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
 	|  PRIVATE STATIC  function  {                   
         runNode *r = new staticNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
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
         $$ = d; 
      }
 	|  PRIVATE STATIC  exp  { 
         runNode * r =new staticNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
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
         $$ = d; 
      }
 	|  STATIC PRIVATE  function  { 
         runNode * r =new staticNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
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
         $$ = d; 
      }
 	|  STATIC PRIVATE  exp  {
         runNode * r =new staticNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
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
         $$ = d; 
      }
 	|  TYPEOF id   { 
         runNode * r = new typeofNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("typeofNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |  TYPEOF '(' id ')' {
         runNode * r =new typeofNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("typeofNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
 	|  DATINFO exp   { 
         runNode * r =new datInfoNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("datInfoNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |  DATINFO '(' exp ')' { 
         runNode * r =new datInfoNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("datInfoNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |	EXIT  {
         runNode * r =new exitNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("exitNode", "stmt", NULL,0);
         }
         #endif
         $$ = r; 
      } 
   |  THROW exp  { 
         runNode * r =new throwNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("throwNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   ;
   
label 		
   :  id ':'  { $$ = $1; }
   ;
//======================================================================  
define  
   :  function  { $$ = $1; }
 	|	class { $$ = $1; }   
   //|	component  { $$ = $1; }
 	|	GLOBAL identity ';' { 
         runNode * r =new globalNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("globalNode", "stmt", a, NULL, 1);
         }
         #endif
         $$ = r;  
      } 
   ;
   
if
   :	IF  lblock  '{'  '}'  {
         runNode * r =new ifNode ($2,new noNode (),0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            string b[1] = {"cond"};
            r->toJson ("ifNode", "stmt", a, b, 1);
         }
         #endif
         $$ = r; 
      }
   |	IF  lblock '{' stmts_level '}'  { 
         runNode * r =new ifNode ($2,$4,0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2,$4};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r; 
      }
   |	IF  lblock stmt ';'  { 
         runNode * r =new stmtNode ($3,NULL,@1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ($2,r,0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2,r};
            string b[2] = {"cond","ifb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d; 
      }
   |	IF  lblock stmtb   { 
         runNode * r =new ifNode ($2, $3, 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2,$3};
            string b[2] = {"cond","ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r; 
      }
   |	IF  lblock '{' '}' ELSE '{' stmts_level '}' { 
         runNode * r =new ifNode ($2, new noNode (), $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2,$7};
            string b[2] = {"cond","elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r; 
      }
   |	IF  lblock '{' stmts_level '}' ELSE '{' '}' { 
         runNode * r =new ifNode ($2, $4, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2,$4};
            string b[2] = {"cond","ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r; 
      }
   |	IF  lblock '{' stmts_level '}' ELSE '{' stmts_level '}' { 
         runNode * r =new ifNode ($2, $4, $8);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $8};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r; 
      }
   |	IF  lblock '{' '}' ELSE  stmt ';' {
         runNode * r =new stmtNode ($6, NULL, @1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$6};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ($2, new noNode (), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, r};
            string b[2] = {"cond", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d; 
      }
   |	IF  lblock '{' stmts_level '}' ELSE  stmt ';' { 
         runNode * r =new stmtNode ($7, NULL, @1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$7};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ($2, $4, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, r};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d; 
      }
   |	IF  lblock '{' '}' ELSE  stmtb  {
         runNode * r = new ifNode ($2, new noNode (), $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2,$6};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	IF  lblock '{' stmts_level '}' ELSE  stmtb  { 
         runNode * r = new ifNode ($2, $4, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $7};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	IF  lblock stmt ';' ELSE '{' '}' { 
         runNode * r =new stmtNode ($3, NULL, @1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ($2, r, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, r};
            string b[2] = {"cond", "ifb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d; 
      }
   |	IF  lblock stmt ';' ELSE '{' stmts_level '}' { 
         runNode * r =new stmtNode ($3, NULL, @1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ($2, r, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, r, $7};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d; 
      }
   |	IF  lblock stmt ';' ELSE  stmt ';' { 
         runNode * r =new stmtNode ($3, NULL, @1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * m =new stmtNode ($6, NULL, @1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$6};
            m->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ($2, r, m);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, r, m};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d; 
      }
   |	IF  lblock stmt ';' ELSE  stmtb { 
         runNode * r =new stmtNode ($3, NULL, @1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode *d = new ifNode ($2, r, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, r, $6};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d;
      }
   |	IF  lblock stmtb  ELSE '{'  '}' { 
         runNode * r =new ifNode ($2, $3, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2,$3};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r; 
      }
   |	IF  lblock stmtb  ELSE '{' stmts_level '}' { 
         runNode * r =new ifNode ($2, $3,$6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $3, $6};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	IF  lblock stmtb  ELSE  stmt ';' { 
         runNode * r =new stmtNode ($5, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$5};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ($2, $3,r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $3, r};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;
      }
   |	IF  lblock stmtb  ELSE  stmtb  { 
         runNode * r =new ifNode ($2, $3,$5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $3, $5};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	IF  lblock '{' '}' elseif { 
         runNode * r =new ifNode ($2,new noNode (), $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $5};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	IF  lblock '{' stmts_level '}' elseif {
         runNode * r =new ifNode ($2, $4, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $6};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	IF  lblock stmt ';' elseif { 
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] =  {$3};
            string b[1] =  {"cond"};
            r->toJson ("stmtNode", "stmt", a, b, 1);
         }
         #endif
         runNode * d =new ifNode ($2, r,$5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, r, $5};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;
      }
   |	IF  lblock stmtb  elseif { 
         runNode * r =new ifNode ($2, $3,$4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $3, $4};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   ;
  
elseif
   :  ELSEIF  lblock '{'  '}'  { 
         runNode * r =new ifNode ($2, new noNode (), 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            string b[1] = {"cond"};
            r->toJson ("ifNode", "stmt", a, b, 1);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock '{' stmts_level '}'  { 
         runNode * r =new ifNode ($2,$4, 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock stmt ';'  { 
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ($2, r, 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, r};
            string b[2] = {"cond", "ifb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d;
      }
   |	ELSEIF  lblock stmtb   { 
         runNode * r=new ifNode ($2, $3, 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $3};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;  
      }
   |	ELSEIF  lblock '{' stmts_level '}' ELSE '{'  '}' {
         runNode * r=new ifNode ($2, $4, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;  
      }
   |	ELSEIF  lblock '{'  '}' ELSE '{' stmts_level '}' { 
         runNode * r=new ifNode ($2, new noNode (), $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $7};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;  
      }
   |	ELSEIF  lblock '{' stmts_level '}' ELSE '{' stmts_level '}' {
         runNode * r =new ifNode ($2, $4, $8);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $8};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock '{'  '}' ELSE  stmt ';' {
         runNode * r =new stmtNode ($6, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$6};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d=new ifNode ($2, new noNode (), r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, r};
            string b[2] = {"cond", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d;  
      }
   |	ELSEIF  lblock '{' stmts_level '}' ELSE  stmt ';' {
         runNode * r =new stmtNode ($7, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$7};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d=new ifNode ($2, $4, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, r};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;  
      }
   |	ELSEIF  lblock '{'  '}' ELSE  stmtb  { 
         runNode * r =new ifNode ($2, new noNode (), $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $6};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock '{' stmts_level '}' ELSE  stmtb  { 
         runNode * r =new ifNode ($2, $4, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $7};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;     
      }
   |	ELSEIF  lblock stmt ';' ELSE '{'  '}' {
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ($2, r, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, r};
            string b[2] = {"cond", "ifb"};
            d->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d;     
      }
   |	ELSEIF  lblock stmt ';' ELSE '{' stmts_level '}' { 
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ($2, r, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, r, $7};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;     
      }
   |	ELSEIF  lblock stmt ';' ELSE  stmt ';' { 
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
          runNode * d =new stmtNode ($6, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$6};
            d->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * m =new ifNode ($2, r, d);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, r, d};
            string b[3] = {"cond", "ifb", "elseb"};
            m->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = m; 
      }
   |	ELSEIF  lblock stmt ';' ELSE  stmtb { 
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ($2, r, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, r, $6};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;  
      }
   |	ELSEIF  lblock stmtb  ELSE '{'  '}' { 
         runNode * r =new ifNode ($2, $3, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $3};
            string b[2] = {"cond", "ifb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock stmtb  ELSE '{' stmts_level '}' { 
         runNode * r =new ifNode ($2, $3, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $3, $6};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock stmtb  ELSE  stmt ';' { 
         runNode * r =new stmtNode ($5, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$5};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ($2, $3, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $3, r};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;  
      }
   |	ELSEIF  lblock stmtb  ELSE  stmtb  {
         runNode * r =new ifNode ($2, $3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $3, $5};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock '{'  '}' elseif { 
         runNode * r =new ifNode ($2, new noNode (), $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $5};
            string b[2] = {"cond", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock '{' stmts_level '}' elseif {
         runNode * r =new ifNode ($2, $4, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $6};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	ELSEIF  lblock stmt ';' elseif {
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new ifNode ($2, r,$5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, r, $5};
            string b[3] = {"cond", "ifb", "elseb"};
            d->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;  
      }
   |	ELSEIF  lblock stmtb  elseif {
         runNode * r =new ifNode ($2, $3, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $3, $4};
            string b[3] = {"cond", "ifb", "elseb"};
            r->toJson ("ifNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   ;

with
   :  WITH exp '{' stmts_level '}' {
         runNode * r =new withNode ($2, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"obj", "stmts"};
            r->toJson ("withNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
 	|	WITH exp  stmt ';' {
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new withNode ($2, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, r};
            string b[2] = {"obj", "stmts"};
            d->toJson ("withNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d;  
      }
   ;
   
while
   :  WHILE lblock '{' '}'  { 
         runNode * r =new whileNode ($2, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            string b[1] = {"cond"};
            r->toJson ("whileNode", "stmt", a, b, 1);
         }
         #endif
         $$ = r;
      }
   |	WHILE lblock '{' stmts_level '}'  { 
         runNode * r =new whileNode ($2, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"cond", "stmts"};
            r->toJson ("whileNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	WHILE lblock  stmt ';'  {
         runNode * r =new stmtNode ($3, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new whileNode ($2, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, r};
            string b[2] = {"cond", "stmts"};
            d->toJson ("whileNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d;  
      }
   |	WHILE lblock  stmtb   {
         runNode * r =new whileNode ($2, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $3};
            string b[2] = {"cond", "stmts"};
            r->toJson ("whileNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   ;

dowhile
   :  DO  '{' '}' WHILE lblock  ';' { 
         runNode * r =new dowhileNode ($5,new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$5};
            string b[1] = {"cond"};
            r->toJson ("dowhileNode", "stmt", a, b, 1);
         }
         #endif
         $$ = r;
      }
 	|	DO  '{' stmts_level '}' WHILE lblock  ';' {
         runNode * r =new dowhileNode ($6, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $6};
            string b[2] = {"stmts", "cond"};
            r->toJson ("dowhileNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	DO  stmt ';' WHILE lblock  ';' { 
         runNode * r =new stmtNode ($2, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new dowhileNode ($5, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r, $5};
            string b[2] = {"stmts", "cond"};
            d->toJson ("dowhileNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d;     
      }
   |	DO  stmtb  WHILE lblock ';' { 
         runNode * r =new dowhileNode ($4, $2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"stmts", "cond"};
            r->toJson ("dowhileNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
   ;

for
   :  FOR '(' exp ';' lexp ';' exp ')' '{'  '}'  { 
         runNode * r =new forNode ($3, $5, $7, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $5, $7};
            string b[3] = {"asig", "cond", "inc"};
            r->toJson ("forNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
   |	FOR '(' exp ';' lexp ';' exp ')' '{' stmts_level '}'  { 
         runNode * r =new forNode ($3, $5, $7, $10);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $5, $7, $10};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            r->toJson ("forNode", "stmt", a, NULL, 4);
         }
         #endif
         $$ = r;
      } 
   |	FOR '(' exp ';' lexp ';' exp ')'  stmt ';'  { 
         runNode * r =new stmtNode ($9, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$9};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new forNode ($3, $5, $7, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $5, $7, r};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            d->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         $$ = d;
      } 
   |	FOR '(' exp ';' lexp ';' exp ')'  stmtb   { 
         runNode * r =new forNode ($3, $5, $7, $9);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $5, $7, $9};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            r->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;
      } 
   |	FOR  exp ';' lexp ';' exp  '{'  '}'  { 
         runNode * r =new forNode ($2, $4, $6, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $6};
            string b[3] = {"asig", "cond", "inc"};
            r->toJson ("forNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      } 
   |	FOR  exp ';' lexp ';' exp  '{' stmts_level '}'  { 
         runNode * r =new forNode ($2, $4, $6, $8);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $6, $8};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            r->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;   
      } 
   |	FOR  exp ';' lexp ';' exp   stmt ';'  {
         runNode * r = new stmtNode ($7, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$7};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new forNode ($2, $4, $6, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $6, r};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            d->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         $$ = d;     
      } 
   |	FOR  exp ';' lexp ';' exp   stmtb   { 
         runNode * r =new forNode ($2, $4, $6, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $6, $7};
            string b[4] = {"asig", "cond", "inc", "stmts"};
            r->toJson ("forNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;     
      } 
 	|	FOR '(' id IN exp ')' '{' '}' { 
         runNode * r =new foreachNode ($3, $5, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"val", "elems"};
            r->toJson ("foreachNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;     
      } 
 	|	FOR '(' id IN exp ')' '{' stmts_level '}' { 
         runNode * r =new foreachNode ($3, $5, $8);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $5, $8};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      } 
 	|	FOR '(' id IN exp ')' stmt ';' { 
         runNode * r =new foreachNode ($3, $5, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $5, $7};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
 	|	FOR id IN exp '{'  '}'  { 
         runNode * r =new foreachNode ($2, $4, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"val", "elems"};
            r->toJson ("foreachNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;
      }
 	|	FOR id IN exp '{' stmts_level '}'  { 
         runNode * r =new foreachNode ($2, $4, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $6};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
 	|	FOR id IN exp stmt ';' { 
         runNode * r =new foreachNode ($2, $4, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $5};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
 	|	FOR '(' id ':' id IN exp ')' '{'  '}' {
         runNode * r =new foreachNode ($5, $7, new noNode (), $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$5, $7, $3};
            string b[3] = {"val", "elems", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
 	|	FOR '(' id ':' id IN exp ')' '{' stmts_level '}' { 
         runNode * r =new foreachNode ($5, $7, $10, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$5, $7, $10, $3};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;
      }
 	|	FOR '(' id ':' id IN exp ')' stmt ';' { 
         runNode * r =new foreachNode ($5, $7, $9, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$5, $7, $9, $3};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;
      }
 	|	FOR id ':' id IN exp '{'  '}' { 
         runNode * r =new foreachNode ($4, $6, new noNode (), $2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$4, $6, $2};
            string b[3] = {"val", "elems", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;   
      }
 	|	FOR id ':' id IN exp '{' stmts_level '}' {
         runNode * r =new foreachNode ($4, $6, $8, $2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$4, $6, $8, $2};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;    
      }
 	|	FOR id ':' id IN exp stmt ';' { 
         runNode * r =new foreachNode ($4, $6, $7, $2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$4, $6, $7, $2};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;      
      }
 	|	FOR '(' exp AS id ')' '{'  '}' { 
         runNode * r =new foreachNode ($5, $3, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$5, $3};
            string b[2] = {"val", "elems"};
            r->toJson ("foreachNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;   
      } 
 	|	FOR '(' exp AS id ')' '{' stmts_level '}' { 
         runNode * r =new foreachNode ($5, $3, $8);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$5, $3, $8};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;   
      } 
 	|	FOR '(' exp AS id ')' stmt ';' { 
         runNode * r =new foreachNode ($5, $3, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$5, $3, $7};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;   
      }
 	|	FOR exp AS id '{' '}'  { 
         runNode * r =new foreachNode ($4, $2, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$4, $2};
            string b[2] = {"val", "elems"};
            r->toJson ("foreachNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;   
      }
 	|	FOR exp AS id '{' stmts_level '}'  { 
         runNode * r =new foreachNode ($4, $2, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$4, $2, $6};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;   
      }
 	|	FOR exp AS id stmt ';' { 
         runNode * r =new foreachNode ($4, $2, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$4, $2, $5};
            string b[3] = {"val", "elems", "stmts"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;
      }
 	|	FOR '(' exp AS id ':' id ')' '{' '}' { 
         runNode * r =new foreachNode ($7, $3, new noNode (), $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$7, $3, $5};
            string b[3] = {"val", "elems", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;   
      }
 	|	FOR '(' exp AS id ':' id ')' '{' stmts_level '}' { 
         runNode * r =new foreachNode ($7, $3, $10, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$7, $3, $10, $5};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;   
      }
 	|	FOR '(' exp AS id ':' id ')' stmt ';' { 
         runNode * r =new foreachNode ($7, $3, $9, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$7, $3, $9, $5};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;     
      }
 	|	FOR exp AS id ':' id '{'  '}' { 
         runNode * r =new foreachNode ($6, $2, new noNode (), $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$6, $2, $4};
            string b[3] = {"val", "elems", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;     
      }
 	|	FOR exp AS id ':' id '{' stmts_level '}' { 
         runNode * r =new foreachNode ($6, $2, $8, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$6, $2, $8, $4};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;     
      }
 	|	FOR exp AS id ':' id stmt ';' { 
         runNode * r =new foreachNode ($6, $2, $7, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$6, $2, $7, $4};
            string b[4] = {"val", "elems", "stmts", "key"};
            r->toJson ("foreachNode", "stmt", a, NULL, 4);
         }
         #endif
         $$ = r;     
      }
   ;

break
   :  BREAK ';'	{ 
         runNode * r =new breakNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("breakNode", "stmt", NULL, 0);
         }
         #endif
         $$ = r;     
      }
 	|	BREAK NUM ';'	{ 
         runNode * r =new breakNode (*$2);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("breakNode", "stmt", NULL, NULL, 0, *$2);
         }
         #endif
         $$ = r;     
      }		
 	|	CONTINUE ';'	{ 
         runNode * r =new continueNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("continueNode", "stmt", NULL, 0);
         }
         #endif
         $$ = r;     
      }
 	|	CONTINUE NUM ';'	{ 
         runNode * r =new continueNode (*$2);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("continueNode", "stmt", NULL, NULL, 0, *$2);
         }
         #endif
         $$ = r;
      }   
   ;
   
switch
   :  SWITCH '(' exp ')''{'  '}' { 
         runNode * r =new switchNode ($3, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            string b[1] = {"eval"};
            r->toJson ("switchNode", "stmt", a, b, 1);
         }
         #endif
         $$ = r;      
      }
 	|	SWITCH '(' exp ')''{' cases '}' { 
         runNode * r =new switchNode ($3, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $6};
            string b[2] = {"eval", "case"};
            r->toJson ("switchNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r; 
      }
   ;

cases 		
   :  CASE exp ':' stmts_level cases  { 
         runNode * r =new caseNode ($2, $4, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $5};
            string b[3] = {"exp", "stmts", "case"};
            r->toJson ("caseNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;      
      }
 	|	CASE exp ':' stmts_level  { 
         runNode * r =new caseNode ($2, $4, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"exp", "stmts"};
            r->toJson ("caseNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;      
      }
 	|	CASE exp ':' cases  {
         runNode * r =new caseNode ($2, NULL, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"exp", "case"};
            r->toJson ("caseNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;      
      }
 	|	DEFAULT ':' stmts_level { 
         runNode * r =new caseNode (NULL, $3, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            string b[1] = {"stmts"};
            r->toJson ("caseNode", "stmt", a, b, 1);
         }
         #endif
         $$ = r;      
      }
   ;
   
iloop
   :  '$''(' exp OPINC  NUM ')' '{'  '}'  { 
         runNode * r =new numConstNode(*$5);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0,*$5);
         }
         #endif
         runNode * d =new incloopNode ($3, r, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3,r};
            string b[2] = {"val", "max"};
            d->toJson ("incloopNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d; 
      } 
 	|	'$''(' exp OPINC  NUM ')' '{' stmts_level '}'  { 
         runNode * r =new numConstNode(*$5);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0,*$5);
         }
         #endif
         runNode * d =new incloopNode ($3, r, $8);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, r, $8};
            string b[3] = {"val", "max", "stmts"};
            d->toJson ("incloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d; 
      } 
   |	'$''(' exp OPINC  NUM ')' stmt ';'  {
         runNode * d =new numConstNode (*$5);
         #if JSON==1
         if (interpreter::get()->json){
            d->toJson ("numConstNode", "data", NULL, NULL, 0, *$5);
         }
         #endif
         
         runNode * r =new stmtNode($7, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$7};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         
         runNode * m =new incloopNode ($3, d, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, d, r};
            string b[3] = {"val", "max", "stmts"};
            m->toJson ("incloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = m;     
      } 
   |	'$''(' exp OPINC  NUM ')' stmtb  { 
         runNode * r =new numConstNode(*$5);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0,*$5);
         }
         #endif
         runNode * d =new incloopNode ($3, r, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, r, $7};
            string b[3] = {"val", "max", "stmts"};
            d->toJson ("incloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;    
      } 
   |	'$''(' exp ')' '{'  '}'  { 
         runNode * r =new iloopNode ($3, new noNode ());
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            string b[1] = {"elems"};
            r->toJson ("iloopNode", "stmt", a, b, 1);
         }
         #endif
         $$ = r;       
      } 
   |	'$''(' exp ')' '{' stmts_level '}'  { 
         runNode * r =new iloopNode ($3, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $6};
            string b[2] = {"elems", "stmts"};
            r->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;   
      } 
   |	'$''(' exp ')' stmt ';'  { 
         runNode * r =new stmtNode($5, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
         runNode*a[1] = {$5};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ($3,r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3,r};
            string b[2] = {"elems", "stmts"};
            d->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         $$ = d;       
      } 
   |	'$''(' exp ')' stmtb  { 
         runNode * r =new iloopNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"elems", "stmts"};
            r->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;          
      } 
   |	'$''(' exp AS id ')' '{'  '}'  {
         runNode * r =new iloopNode ($3,new noNode (), $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"elems", "id"};
            r->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;          
      } 
   |	'$''(' exp AS id ')' '{' stmts_level '}'  { 
         runNode * r =new iloopNode ($3, $8, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $8, $5};
            string b[3] = {"elems", "stmts", "id"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;          
      } 
   |	'$''(' exp AS id ')' stmt ';'  { 
         runNode * r =new stmtNode ($7, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$7};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ($3, r, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, r, $5};
            string b[3] = {"elems", "stmts", "id"};
            d->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;
      } 
   |	'$''(' exp AS id ')' stmtb  { 
         runNode * r =new iloopNode ($3, $7, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $7, $5};
            string b[3] = {"elems", "stmts", "id"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;          
      } 
   |	'$''(' exp AS id ':' id ')' '{'  '}'  { 
         runNode * r =new iloopNode ($3, new noNode (), $7, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $7, $5};
            string b[3] = {"elems", "id", "key"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;          
      } 
   |	'$''(' exp AS id ':' id ')' '{' stmts_level '}'  { 
         runNode * r =new iloopNode ($3, $10, $7, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $10, $7, $5};
            string b[4] = {"elems", "stmts", "id", "key"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;          
      } 
   |	'$''(' exp AS id ':' id ')' stmt ';'  { 
         runNode * r =new stmtNode ($9, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$9};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ($3, r, $7, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, r, $7, $5};
            string b[4] = {"elems", "stmts", "id", "key"};
            d->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         $$ = d;                  
      } 
   |	'$''(' exp AS id ':' id ')' stmtb  { 
         runNode * r =new iloopNode ($3, $9, $7, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $9, $7, $5};
            string b[4] = {"elems", "stmts", "id", "key"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp ',' exp ')' '{'  '}'  { 
         runNode * r =new iloopNode ($3, new noNode (), NULL, NULL, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"elems", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 2);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp ',' exp ')' '{' stmts_level '}'  { 
         runNode * r =new iloopNode ($3, $8, NULL, NULL, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $8, $5};
            string b[3] = {"elems", "stmts", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp ',' exp ')' stmt ';'  { 
         runNode * r =new stmtNode ($7, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$7};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ($3, r, NULL, NULL, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, r, $5};
            string b[3] = {"elems", "stmts", "inc"};
            d->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;                  
      } 
   |	'$''(' exp ',' exp ')' stmtb  { 
         runNode * r =new iloopNode ($3, $7, NULL, NULL, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $7, $5};
            string b[3] = {"elems", "stmts", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp AS id ',' exp ')' '{'  '}'  { 
         runNode * r =new iloopNode ($3, new noNode (), $5, NULL, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $5, $7};
            string b[3] = {"elems", "id", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp AS id ',' exp ')' '{' stmts_level '}'  { 
         runNode * r =new iloopNode ($3, $10, $5, NULL, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $10, $5, $7};
            string b[4] = {"elems", "stmts", "id", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp AS id ',' exp ')' stmt ';'  { 
         runNode * r =new stmtNode ($9, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$9};
            r->toJson ("stmtNode", "stmt", a, NULL, 4);
         }
         #endif
         runNode * d =new iloopNode ($3, r, $5, NULL, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, r, $5, $7};
            string b[4] = {"elems", "stmts", "id", "inc"};
            d->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         $$ = d;                  
      } 
   |	'$''(' exp AS id ',' exp ')' stmtb  { 
         runNode * r =new iloopNode ($3, $9, $5, NULL, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $9, $5, $7};
            string b[4] = {"elems", "stmts", "id", "inc"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp AS id ':' id ',' exp ')' '{'  '}'  { 
         runNode * r =new iloopNode ($3, new noNode (), $7, $5, $9);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $7, $5, $9};
            string b[4] = {"elems", "id", "key","inc"};
            r->toJson ("iloopNode", "stmt", a, b, 4);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp AS id ':' id ',' exp ')' '{' stmts_level '}'  { 
         runNode * r =new iloopNode ($3, $12, $7, $5, $9);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$3, $12, $7, $5, $9};
            string b[5] = {"elems", "stmts", "id", "key","inc"};
            r->toJson ("iloopNode", "stmt", a, b, 5);
         }
         #endif
         $$ = r;                  
      } 
   |	'$''(' exp AS id ':' id ',' exp ')' stmt ';'  { 
         runNode * r =new stmtNode ($11, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$11};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new iloopNode ($3, r, $7, $5, $9);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$3, r, $7, $5, $9};
            string b[5] = {"elems", "stmts", "id", "key","inc"};
            d->toJson ("iloopNode", "stmt", a, b, 5);
         }
         #endif
         $$ = d;                  
      } 
   |	'$''(' exp AS id ':' id ',' exp ')' stmtb  { 
         runNode * r =new iloopNode ($3, $11, $7, $5, $9);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$3, $11, $7, $5, $9};
            string b[5] = {"elems", "stmts", "id", "key","inc"};
            r->toJson ("iloopNode", "stmt", a, NULL, 5);
         }
         #endif
         $$ = r;                  
      } 
   ;


trycatch 
   :  TRY '{' stmts_level '}' CATCH '(' id ')' '{' stmts_level '}'   { 
         runNode * r =new tryNode ($3, $7, $10);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $7, $10};
            string b[3] = {"stmts", "exc", "catch"};
            r->toJson ("tryNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;                  
      }
   |  TRY  stmt ';' CATCH '(' id ')' '{' stmts_level '}'   { 
         runNode * r =new stmtNode ($2, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new tryNode (r, $6, $9);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {r, $6, $9};
            string b[3] = {"stmts", "exc", "catch"};
            d->toJson ("tryNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;                  
      }
   |  TRY  stmt ';' CATCH '(' id ')'  stmt ';'   {
         runNode * r =new stmtNode ($2, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d=new stmtNode ($8, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$8};
           d->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif   
         runNode * m =new tryNode (r, $6, m);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {r, $6, m};
            string b[3] = {"stmts", "exc", "catch"};
           m->toJson ("tryNode", "stmt", a, b, 3);
         }
         #endif
         $$ = m;    
      }
   |  TRY  '{' stmts_level '}' CATCH '(' id ')'  stmt ';'   { 
         runNode * r =new stmtNode ($9, NULL, @1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$9};
            r->toJson ("stmtNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d =new tryNode ($3, $7, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $7,r};
            string b[3] = {"stmts", "exc", "catch"};
            d->toJson ("tryNode", "stmt", a, b, 3);
         }
         #endif
         $$ = d;                
      }
   ;
   
lblock 
   : '(' lexp ')' { $$ = $2; }
   ;
   
//======================================================================
function  
   :  FUNCTION id '(' params_default ')' '{' stmts_level '}'  { 
         runNode * r =new functionNode ($2, $4, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $7};
            string b[3] = {"id", "params", "body"};
            r->toJson ("functionNode", "function", a, b, 3);
         }
         #endif
         $$ = r;    
      }													
 	|  FUNCTION id '(' params_default ')' '{' '}'  { 
            runNode * r =new functionNode ($2, $4, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"id", "params"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         $$ = r;  
      }													
 	|  FUNCTION id '('')' '{' stmts_level '}'  { 
         runNode * r =new functionNode ($2, NULL, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $6};
            string b[2] = {"id", "body"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         $$ = r;     
      }	
 	|  FUNCTION id '('')' '{' '}'  { 
         runNode * r =new functionNode ($2, NULL, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            string b[1] = {"id"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         $$ = r;     
      }	
 	|  '~' id '(' params_default ')' '{' stmts_level '}'  { 
         runNode * r =new functionNode ($2, $4, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $7};
            string b[3] = {"id", "params", "body"};
            r->toJson ("functionNode", "function", a, b, 3);
         }
         #endif
         $$ = r;     
      }													
 	|  '~' id '(' params_default ')' '{' '}'  { 
         runNode * r =new functionNode ($2, $4, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"id", "params"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         $$ = r;  
      }													
 	|  '~' id '('')' '{' stmts_level '}'  { 
         runNode * r =new functionNode ($2, NULL, $6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $6};
            string b[2] = {"id", "body"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         $$ = r;  
      }	
 	|  '~' id '('')' '{' '}'  { 
         runNode * r =new functionNode ($2, NULL, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            string b[1] = {"id"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         $$ = r;  
      }	
 	|  DECORATOR id '(' params_default ')' '{' stmts_level '}'  { 
         runNode * ctx = new idNode ("_f");
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
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
         runNode* func = new functionNode (NULL,$4,$7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$4,$7};
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
         runNode *r = new functionNode ($2, params_dec, body_dec);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, params_dec, body_dec};
            string b[3] = {"id", "params", "body"};
            r->toJson ("returnNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;   
      }													
 	|  DECORATOR id '(' params_default ')' '{' '}'  { 
         runNode * ctx = new idNode ("_f");
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
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
         runNode* func = new functionNode (NULL,$4,NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$4};
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
         runNode *r = new functionNode ($2, params_dec, body_dec);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, params_dec, body_dec};
            string b[3] = {"id", "params", "body"};
            r->toJson ("returnNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;     
      }													
 	|  DECORATOR id '('')' '{' stmts_level '}'  { 
         runNode * ctx = new idNode ("_f");
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
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
         runNode* func = new functionNode (NULL,NULL,$6);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$6};
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
         runNode *r = new functionNode ($2, params_dec, body_dec);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, params_dec, body_dec};
            string b[3] = {"id", "params", "body"};
            r->toJson ("returnNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r; 
      }	
 	|	DECORATOR id '('')' '{' '}'  { 
         runNode * ctx = new idNode ("_f");
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
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
         runNode *r = new functionNode ($2, params_dec, body_dec);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, params_dec, body_dec};
            string b[3] = {"id", "params", "body"};
            r->toJson ("returnNode", "stmt", a, b, 3);
         }
         #endif
         $$ = r;  
      }	
   ;   

//======================================================================      
class 
   :  CLASS id '{' stmts_level '}'  {  
         runNode * r =new classNode ($2, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"id","body"};
            r->toJson ("classNode", "class", a, b, 2);
         }
         #endif
         $$ = r;  
      }
 	|  CLASS id EXTENDS id '{' stmts_level '}' { 
         runNode * r =new classNode ($2, $6, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $6, $4};
            string b[3] = {"id","body", "extends"};
            r->toJson ("classNode", "class", a, b, 3);
         }
         #endif
         $$ = r;      
      }		
 	|  STATIC function { 
         runNode * r =new staticNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("staticNode", "class", a, NULL, 1);
         }
         #endif
         $$ = r;  
      }
 	|	PRIVATE function { 
         runNode * r =new privateNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("privateNode", "class", a, NULL, 1);
         }
         #endif
         $$ = r;       
      }										
   ;
   
//======================================================================
params_default
   :  params_default ',' id '=' identity { 
         asigNode * r = new asigNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"var", "exp"};
            r->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         runNode * d =new listNode ($1,r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            d->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         $$ = d;  
      }
 	|	params ',' id '=' identity { 
         runNode * r = new asigNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"var", "exp"};
            r->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         runNode * d =new listNode ($1,r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            d->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         $$ = d;     
      }
 	|	id '=' identity { 
         runNode * r = new asigNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
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
         $$ = d;   
      }
 	|	params { $$ = $1; }
   ;

//======================================================================  
params		
   :	params ',' id { 
         runNode * r =new listNode ($1,$3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            r->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         $$ = r;      
      } 
   |	params ',' '&' id { 
         runNode * r = new refparamNode ($4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$4};
            r->toJson ("refparamNode", "function", a, NULL, 1);
         }
         #endif
         runNode * d =new listNode ($1, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            d->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         $$ = d;       
      }
   |	id  { 
         runNode * r =new listNode ($1,NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         $$ = r;  
      }
   |	'&' id  { 
         runNode * r = new refparamNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
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
         $$ = d;          
      }
   ;
						
//======================================================================
exp 	
   :  lexp  { $$ = $1; }
   ;

lexp 		
   :  lop1  { $$ = $1; }
   ;

lop1 		
   :  lop1 OR_OP lop2  { 
         runNode * r =  new orNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            string b[2] = {"op1", "op2"};
            r->toJson ("orNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |  lop2  { $$ = $1; }
   ;
			
lop2		
   :  lop2 AND_OP lop3  { 
         runNode * r = new andNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            string b[2] = {"op1", "op2"};
            r->toJson ("andNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |  lop3  { $$ = $1;  }
   ;
			
lop3		
   :  '!' lop3  { 
         runNode * r = new notNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("notNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;
      }
	|  lop4  { $$ = $1;}
   ;
			
lop4	
   :	aexp '<' aexp {
         runNode * r = new lthNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("lthNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	aexp '<''=' aexp  { 
         runNode * r = new leqNode ($1, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $4};
            string b[2] = {"op1", "op2"};
            r->toJson ("leqNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	aexp '>' aexp { 
         runNode * r = new gthNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("gthNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	aexp '>''=' aexp  { 
         runNode * r = new geqNode ($1, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $4};
            string b[2] = {"op1", "op2"};
            r->toJson ("geqNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	aexp EQL aexp { 
         runNode * r = new eqNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("eqNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	aexp IDEN aexp  { 
         runNode * r = new idenNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("idenNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	aexp NIDEN aexp { 
         runNode * r = new nidenNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("nidenNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      }
   |	aexp '!''=' aexp  { 
         runNode * r = new neqNode ($1, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $4};
            string b[2] = {"op1", "op2"};
            r->toJson ("neqNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;
      } 
   |	aexp  { $$ = $1; }
   ;
   
//======================================================================
aexp	
   :  aop1  { $$ = $1; }
   ;

aop1		
   :	aop1 '+' aop2 { 
         runNode * r = new addNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("addNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;   
      }
   |	aop1 '-' aop2 { 
         runNode * r = new subNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("subNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;   
      }
   |  aop1 SNUM	{
         if ($2 < 0){
            runNode * r = new numConstNode (*$2);
            #if JSON==1
            if (interpreter::get()->json){
               r->toJson ("numConstNode", "data", NULL, NULL, 0, *$2);
            }
            #endif
            runNode * d = new subNode ($1, r);
            #if JSON==1
            if (interpreter::get()->json){
               runNode*a[2] = {$1, r};
               string b[2] = {"op1", "op2"};
               d->toJson ("subNode", "operator", a, b, 2);
            }
            #endif
            $$ = d;  
         }
         else{
            runNode * r = new numConstNode (*$2);
            #if JSON==1
            if (interpreter::get()->json){
               r->toJson ("numConstNode", "data", NULL, NULL, 0, *$2);
            }
            #endif
            runNode * d = new addNode ($1, r);
            #if JSON==1
            if (interpreter::get()->json){
               runNode*a[2] = {$1, r};
               string b[2] = {"op1", "op2"};
               d->toJson ("addNode", "operator", a, b, 2);
            }
            #endif
            $$ = d; 
         }
      }
   |	aop2  { $$ = $1; }
   ;
			
aop2		
   :   aop2 '*' aop3 { 
         runNode * r = new prodNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("prodNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;      
      }
   |   aop2 '/' aop3 { 
         runNode * r = new divNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("divNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;      
      }
   |  aop3  { $$ = $1; }
   ;
			
aop3		
   :  aop3 '^' sexp { 
         runNode * r = new powNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("powNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;      
      }
   |  aop3 '%' sexp { 
         runNode * r = new modNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("modNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;      
      }
   |  sexp  { $$ = $1; }
   ;
   
//======================================================================
sexp 		
   :  sop1  { $$ = $1;}					
   ;

sop1		
   :  sop2 '.' sop1  { 
         runNode * r = new catNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("catNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;      
      }
   |  sop2 FLOW sop1  { 
         runNode * r = new catNode ($1, $3, true);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("catNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;      
      }
   |  sop2 FLOWLINE sop1  { 
         runNode * r = new catNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("catNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;    
      }
   |  sop2  { $$ = $1; }
   ;

sop2		
   :  INPUT id  { 
         runNode * r = new inputNode ($2, 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("inputNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;    
      }
   |  INPUTLINE id  { 
         runNode * r = new inputNode ($2, 1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("inputNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;       
      }
   |	INPUT '[' exp ']'	id  { 
         runNode * r = new inputNode ($5, 0, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$5, $3};
            string b[2] = {"", "prompt"};
            r->toJson ("inputNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;       
      }	 
   |	INPUTLINE '[' exp ']'	id  { 
         runNode * r = new inputNode ($5, 1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$5, $3};
             string b[2] = {"", "prompt"};
            r->toJson ("inputNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;    
      }	 
   |	INPUT { 
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
         $$ = d;    
      }
   |	INPUTLINE { 
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
         $$ = d;    
      }
   |	INPUT '[' exp ']'  { 
         idNode * r = new idNode ("user");
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", "user");
         }
         #endif
         runNode * d = new inputNode (r, 0, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r, $3};
            string b[2] = {"", "prompt"};
            d->toJson ("inputNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;   
      }
   |	INPUTLINE '[' exp ']'  { 
         idNode * r = new idNode ("user");
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", "user");
         }
         #endif
         runNode * d = new inputNode (r, 1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r,$3};
            string b[2] = {"", "prompt"};
            d->toJson ("inputNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;   
      }
	|	call_identity  { $$ = $1;}
   ;
   
//======================================================================
call_identity
   :  call_identity '(' list	')' { 
         runNode * r = new functioncallNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"id", "params"};
            r->toJson ("callNode", "function", a, b, 2); 
         }
         #endif
         $$ = r;     
      }
   |	call_identity '('')' { 
         runNode * r = new functioncallNode ($1, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            string b[2] = {"id"};
            r->toJson ("callNode", "function", a, b, 1);
         }
         #endif
         $$ = r;   
      }
   |  extra_operator { $$ = $1; }
   ;
   
//======================================================================
extra_operator
   :	tern { $$ = $1; }
   ;
   
tern
   :  unity '?' exp ':' exp { 
         runNode * r = new ternNode ($1, $3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$1, $3, $5};
            string b[3] = {"cond", "true", "false"};
            r->toJson ("ternNode", "operator", a, b, 3);
         }
         #endif
         $$ = r;    
      }
	|	unity '?'':' exp { 
         runNode * r = new ternNode ($1, NULL, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $4};
            string b[2] = {"cond", "false"};
            r->toJson ("ternNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;    
      }
   |  unity '?' exp { 
         runNode * r = new ternNode ($1, $3, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"cond", "true"};
            r->toJson ("ternNode", "operator", a, b, 2);
         }
         #endif
         $$ = r;    
      }
   |	notnull { $$ = $1; }
   ;
   
notnull
   :  '[''[' list ']'']' { 
         runNode * r = new notnullNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("notnullNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  unity { $$ = $1; }
   ;   
   
//======================================================================
unity
   :  inc_dec  {$$ = $1; }
   |	cexp  { $$ = $1;}
   |  lop_unity { $$ = $1; }
   |  aop_unity { $$ = $1; }
   |  sop_unity { $$ = $1; }
  // |  class_exp { $$ = $1; }
   //|	arrayexp  { $$ = $1; }
   |  date  { $$ = $1; }
   |  file  { $$ = $1; }
   |  process  { $$ = $1; }
   |	exp_generator { $$ = $1; }
   |  environment { $$ = $1; }
   |  regexp_op { $$ = $1; }
   |  iloop_access { $$ = $1; }
   //|  component_unity { $$ = $1; }
    // | identity { $$ = $1; }
   |  function_exp { $$ = $1; } 
   |  '&' exp { 
         runNode * r = new getRefNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("getRefNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;      
      }
	;

inc_dec
   :	INC assignation	  { 
         runNode * r = new incasigNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("incasigNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;      
      }
   |	assignation	INC { 
         runNode * r = new incasigNode ($1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("incasigNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r; 
      }
   |	DEC assignation { 
         runNode * r = new decasigNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("decasigNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |	assignation	DEC { 
         runNode * r = new asigdecNode ($1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("asigdecNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  assignation { $$ = $1; }
   ;

assignation
   :  assig ADDASIG exp { 
         runNode * r = new addNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            string b[2] = {"op1", "op2"};
            r->toJson ("addNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ($1, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;   
      } 
   |	assig SUBASIG exp { 
         runNode * r = new subNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            string b[2] = {"op1", "op2"};
            r->toJson ("subNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ($1, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;   
      } 
   |	assig PRODASIG exp  { 
         runNode * r = new prodNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            string b[2] = {"op1", "op2"};
            r->toJson ("prodNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ($1, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;      
      } 
   |	assig DIVASIG exp { 
         runNode * r = new divNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            string b[2] = {"op1", "op2"};
            r->toJson ("divNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ($1, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;      
      } 
   |	assig POWASIG exp { 
         runNode * r = new powNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            string b[2] = {"op1", "op2"};
            r->toJson ("powNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ($1, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;      
      } 
   |	assig MODASIG exp { 
         runNode * r = new modNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"op1", "op2"};
            r->toJson ("modNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ($1, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;      
      } 
   |	assig CATASIG exp { 
         runNode * r = new catNode ($1, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1,$3};
            string b[2] = {"op1", "op2"};
            r->toJson ("catNode", "operator", a, b, 2);
         }
         #endif
         runNode * d = new asigNode ($1, r);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"var", "exp"};
            d->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         $$ = d;   
      } 
   |	assig  { $$ = $1; }
   ;

cexp 		
   :	CINT unity { 
         runNode * r = new intconvNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("intconvNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |	CFLOAT unity {
         runNode * r = new floatconvNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("floatconvNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |	CBOOL unity  { 
         runNode * r = new boolconvNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("boolconvNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |	CSTR unity  { 
         runNode * r = new strconvNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("strconvNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }	
   |  '(' CINT ')' unity { 
         runNode * r = new intconvNode ($4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$4};
            r->toJson ("intconvNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;      
      }
   |	'(' CFLOAT ')' unity { 
         runNode * r = new floatconvNode ($4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$4};
            r->toJson ("floatconvNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |	'(' CBOOL ')' unity  { 
         runNode * r = new boolconvNode ($4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$4};
            r->toJson ("boolconvNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |	'(' CSTR ')' unity  { 
         runNode * r = new strconvNode ($4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$4};
            r->toJson ("strconvNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   ;
  
lop_unity
   :  ISNULL exp { 
         runNode * r = new isNullNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("isNullNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  ISBOOL exp { 
         runNode * r = new isBoolNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("isBoolNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  ISNUM exp { 
         runNode * r = new isNumNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("isNumNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  ISSTRING exp { 
         runNode * r = new isStringNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("isStringNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  ISOBJECT exp { 
         runNode * r = new isObjectNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("isObjectNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  ISARRAY exp { 
         runNode * r = new isArrayNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("isArrayNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |	EMPTY '(' exp ')' { 
         runNode * r = new emptyNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("emptyNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   ;
  
aop_unity
   :  SIZE exp  { 
         runNode * r = new sizeNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("sizeNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  SQRT exp { 
         runNode * r = new sqrtNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("sqrtNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  SIZEOF exp  { 
         runNode * r = new sizeOfNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("sizeOfNode", "operator", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  SIZEOF  { 
         runNode * r = new sizeOfNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("sizeOfNode", "operator", NULL, 0);
         }
         #endif
         $$ = r;   
      }
   ;

//======================================================================
sop_unity
   :  EXPLODE '(' exp ',' exp ')' { 
         runNode * r = new explodeNode ($5, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"str", "dlm"};
            r->toJson ("explodeNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
	|	IMPLODE '(' exp ',' exp ')' { 
         runNode * r = new implodeNode ($5, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"array", "dlm"};
            r->toJson ("implodeNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
	|	SPRINTF '(' list ')' { 
         runNode * r = new sprintfNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("sprintfNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  FIND '(' exp ',' exp ',' exp ')' { 
         runNode * r = new findNode ($3, $5, $7);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $5, $7};
            string b[3] = {"str", "sub", "ipos"};
            r->toJson ("findNode", "function", a, b, 3);
         }
         #endif
         $$ = r;   
      }
	|	FIND '(' exp ',' exp ')' { 
         runNode * r = new findNode ($3, $5, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"str", "sub"};
            r->toJson ("findNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
	|	REPLACE '(' exp ',' exp ',' exp ',' exp ')' {; 
         runNode * r = new replaceNode ($5, $7, $3, $9);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $5, $7, $9};
            string b[4] = {"str", "search", "replace", "nreplace"};
            r->toJson ("replaceNode", "function", a, b, 4);
         }
         #endif
         $$ = r;   
      }
	|	REPLACE '(' exp ',' exp ',' exp ')' { 
         runNode * r = new replaceNode ($5, $7, $3, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $5, $7};
            string b[3] = {"str", "search", "replace",};
            r->toJson ("replaceNode", "function", a, b, 3);
         }
         #endif
         $$ = r;   
      }
	|	SUBREPLACE '(' exp ',' exp ',' exp ',' exp ')' { 
         runNode * r = new subreplaceNode ($5, $7, $9, $3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$3, $5, $7, $9};
            string b[4] = {"str", "ini", "len", "replace"};
            r->toJson ("subreplaceNode", "function", a, NULL, 4);
         }
         #endif
         $$ = r;   
      }
	|	UPPER '(' exp  ')' { 
         runNode * r = new upperNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("upperNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
	|	LOWER '(' exp  ')' { 
         runNode * r = new lowerNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("lowerNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   ;
//======================================================================
class_exp
   :	NEW id '('')' { 
         runNode * r = new newNode ($2, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            string b[1] = {"class"};
            r->toJson ("newNode", "class", a, NULL, 1);
         }
         #endif
         $$ = r;     
      }
   |	NEW id  { 
         runNode * r = new newNode ($2, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            string b[1] = {"class"};
            r->toJson ("newNode", "class", a, b, 1);
         }
         #endif
         $$ = r;    
      }
   |	NEW id '(' list ')' {
         runNode * r = new newNode ($2, $4);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"class", "params"};
            r->toJson ("newNode", "class", a, b, 2);
         }
         #endif
         $$ = r;    
      }
	|	THIS  { 
         runNode * r = new thisNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("thisNode", "class", NULL, 0);
         }
         #endif
         $$ = r; 
      }
	|	PARENT  { 
         runNode * r = new parentNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("parentNode", "class", NULL, 0);
         }
         #endif
         $$ = r;    
      }
   |	namespace  { $$ = $1; }
   |	GETCLASS '(' exp ')' { 
         runNode * r = new getclassNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("getclassNode", "class", a, NULL, 1);
         }
         #endif
         $$ = r;    
      }
   ;
//======================================================================
arrayexp	
   :  '{' array '}' { 
         runNode * r = new arrayConstNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("arrayConstNode", "data", a, NULL, 1);
         }
         #endif
         $$ = r;    
      }
   |  '{' map '}' { 
          runNode * r = new arrayConstNode ($2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$2};
            r->toJson ("arrayConstNode", "data", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |  '{''}'  { 
         runNode * r = new arrayConstNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("arrayConstNode", "data", NULL, 0);
         }
         #endif
         $$ = r;    
      }
   |  parray { $$ = $1; }
   |	arrayop { $$ = $1; }
   ;

date
   :	DATE '(' exp ')' { 
         runNode * r = new dateNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            string b[1] = {"format"};
            r->toJson ("dateNode", "data", a, b, 1);
         }
         #endif
         $$ = r;   
      }
   |	DATE '(' exp ',' exp ')' {
         runNode * r = new dateNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"format", "time"};
            r->toJson ("dateNode", "data", a, b, 2);
         }
         #endif
         $$ = r;    
      }
	|	TIME '(' ')' { 
         runNode * r = new timeNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("timeNode", "data", NULL, 0);
         }
         #endif
         $$ = r;    
      }
	|	TIME { 
         runNode * r = new timeNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("timeNode", "data", NULL, 0);
         }
         #endif
         $$ = r;   
      }
   ;

file
   :  FTOKEN '(' exp ',' exp ')' { 
         runNode * r = new fileNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"file", "mode"};
            r->toJson ("fileNode", "data", a, b, 2);
         }
         #endif
         $$ = r;    
      }
	|	FTOKEN '(' exp ')' { 
         runNode * r = new fileNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            string b[1] = {"file"};
            r->toJson ("fileNode", "data", a, b, 1);
         }
         #endif
         $$ = r;    
      }
	|	FPUT '(' exp ',' exp ')' { 
         runNode * r = new fputNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"file", "content"};
            r->toJson ("fputNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      } 
	|	FWRITE '(' exp ',' exp ')' { 
         runNode * r = new fwriteNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"file", "content"};
            r->toJson ("fwriteNode", "function", a, b, 2);
         }
         #endif
         $$ = r;    
      }
	|	FAPP '(' exp ',' exp ')' { 
         runNode * r = new fappendNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"file", "content"};
            r->toJson ("fappend", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
	|	FGET '(' exp ')' { 
         runNode * r = new fgetNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            string b[1] = {"file"};
            r->toJson ("fgetNode", "function", a, b, 1);
         }
         #endif
         $$ = r;    
      }
	|	FGET '(' exp ',' exp ')' { 
         runNode * r = new fgetNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"file", "size"};
            r->toJson ("fgetNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
	|	FREAD '(' exp ')' {  
         runNode * r = new freadNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("freadNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;    
      }
	|	FCLOSE '(' exp ')' {
         runNode * r = new fcloseNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("fcloseNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
	|	FSEEK '(' exp ',' exp ')' { 
         runNode * r = new fseekNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"file", "offset"};
            r->toJson ("fseekNode", "function", a, b, 2);
         }
         #endif
         $$ = r;    
      }
	|	FSEEK '(' exp ',' exp ',' FSET ')' { 
         runNode * r = new fseekNode ($3, $5, 0);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
             string b[2] = {"file", "offset"};
            r->toJson ("fseekNode", "function", a, b, 2);
         }
         #endif
         $$ = r;    
      }
	|	FSEEK '(' exp ',' exp ',' FCUR ')' { 
         runNode * r = new fseekNode ($3, $5, 1);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
             string b[2] = {"file", "offset"};
            r->toJson ("fseekNode", "function", a, b, 2);
         }
         #endif
         $$ = r;    
      }
	|	FSEEK '(' exp ',' exp ',' FEND ')' {
          runNode * r = new fseekNode ($3, $5, 2);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
             string b[2] = {"file", "offset"};
            r->toJson ("fseekNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
	|	FTELL '(' exp ')' { 
         runNode * r = new ftellNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("ftellNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
	;

process
   :	EXEC '(' exp ')'	{ 
         runNode * r = new execNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("execNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;    
      }
	|	EVAL '(' exp ')'	{ 
         runNode * r = new evalNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("evalNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;    
      }
   |	FORK '(' ')' { 
         runNode * r = new forkNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("forkNode", "function", NULL, 0);
         }
         #endif
         $$ = r;   
      }
	|	WAIT '(' exp ')' {  
         runNode * r = new waitNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("waitNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;     
      }
	|	WAIT '(' ')' {
         runNode * r = new waitNode (NULL);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("waitNode", "function", NULL, 0);
         }
         #endif
         $$ = r;    
      }
	|	SIGNAL '(' exp ',' exp ')' { 
         runNode * r = new signalNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
             string b[2] = {"pid", "signal"};
            r->toJson ("signalNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
   
      }
	|	SHANDLER '(' exp ',' exp ')' { 
         runNode * r = new signalhandlerNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"signal", "function"};
            r->toJson ("signalhandlerNode", "function", a, b, 2);
         }
         #endif
         $$ = r;    
      }
	|	EXITPROCESS '(' ')' { 
         runNode * r = new exitProcessNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("exitProcessNode", "function", NULL, 0);
         }
         #endif
         $$ = r;    
   }
	|	GETPID '(' ')' { 
         runNode * r = new getpidNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getpidNode", "function", NULL, 0);
         }
         #endif
         $$ = r;      
      }
	|	GETPPID '(' ')' {  
         runNode * r = new getppidNode ();
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getppidNode", "function", NULL, 0);
         }
         #endif
         $$ = r;    
      }
	|	PROCESSTOKEN '(' exp ',' list ')' { 
         runNode * r = new processNode ($3, $5);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"function", "params"};
            r->toJson ("processNode", "function", a, b, 2);
         }
         #endif
         $$ = r;     
      }
	|	PROCESSTOKEN '(' exp ')' { 
         runNode * r = new processNode ($3, NULL);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            string b[1] = {"function"};
            r->toJson ("processNode", "function", a, b, 1);
         }
         #endif
         $$ = r;     
      }
   ;

environment
   :  GETENV '(' exp ')' { 
         runNode * r = new getEnvNode ($3);
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("getEnvNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;    
      }
   ;
   
exp_generator
   :  '(' exp FOR id IN exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $4, $6, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $4, $6};
            string b[3] = {"out", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 3);
         }
         #endif
         $$ = r;      
      } 
	|	'(' exp FOR id IN exp '{' stmts_level '}' ')' { 
         runNode * r = new foreachGeneratorNode ($2, $4, $6, $8); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $6, $8};
            string b[4] = {"out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp FOR id IN exp  stmt ')' { 
         runNode * r = new foreachGeneratorNode ($2, $4, $6, $7); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $6, $7};
            string b[4] = {"out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;   
      } 
	|	'(' exp FOR id IN exp IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $4, $6, NULL, NULL, $8); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $6, $8};
            string b[4] = {"out", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;   
      } 
	|	'(' exp FOR id IN exp '{' stmts_level '}' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $4, $6, $8, NULL, $11); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $8, $11};
            string b[5] = {"out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp FOR id IN exp  stmt IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $4, $6, $7, NULL, $9); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $7, $9};
            string b[5] = {"out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp FOR '(' id IN exp ')' ')' { 
         runNode * r = new foreachGeneratorNode ($2, $5, $7, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$2, $5, $7};
            string b[3] = {"out", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 3);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp FOR '(' id IN exp ')' '{' stmts_level '}' ')' { 
         runNode * r = new foreachGeneratorNode ($2, $5, $7, $10); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $5, $7, $10};
            string b[4] = {"out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp FOR '(' id IN exp ')' stmt ')' {  
         runNode * r = new foreachGeneratorNode ($2, $5, $7, $9); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $5, $7, $9};
            string b[4] = {"out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp FOR '(' id IN exp ')' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $5, $7, NULL, NULL, $10); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $5, $7, $10};
            string b[4] = {"out", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp FOR '(' id IN exp ')' '{' stmts_level '}' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $5, $7, $10, NULL, $13); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $5, $7, $10, $13};
            string b[5] = {"out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp FOR '(' id IN exp ')'  stmt IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $5, $7, $9, NULL, $11); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $5, $7, $9, $11};
            string b[5] = {"out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp FOR id ':' id IN exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $6, $8, NULL, $4); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $6, $8};
            string b[4] = {"out", "key", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp FOR id ':' id IN exp '{' stmts_level '}' ')' { 
         runNode * r = new foreachGeneratorNode ($2, $6, $8, $10, $4); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $8, $10};
            string b[5] = {"out", "key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;      
      } 
	|	'(' exp FOR id ':' id IN exp  stmt ')' { 
         runNode * r = new foreachGeneratorNode ($2, $6, $8, $9, $4); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $8, $9};
            string b[5] = {"out", "key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;      
      } 
	|	'(' exp FOR id ':' id IN exp IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $6, $8, NULL, $4, $10); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $8, $10};
            string b[5] = {"out", "key", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;   
      } 
	|	'(' exp FOR id ':' id IN exp '{' stmts_level '}' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $6, $8, $10, $4, $13); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $6, $8, $10, $13};
            string b[6] = {"out", "key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp FOR id ':' id IN exp  stmt IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $6, $8, $9, $4, $11); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $6, $8, $9, $11};
            string b[6] = {"out", "key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp FOR '(' id ':' id IN exp ')' ')' { 
         runNode * r = new foreachGeneratorNode ($2, $7, $9, NULL, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $5, $7, $9};
             string b[4] = {"out", "key", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp FOR '(' id ':' id IN exp ')' '{' stmts_level '}' ')' { 
         runNode * r = new foreachGeneratorNode ($2, $7, $9, $12, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $5, $7, $9, $12};
             string b[5] = {"out", "key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;         
      } 
	|	'(' exp FOR '(' id ':' id IN exp ')' stmt ')' { 
         runNode * r = new foreachGeneratorNode ($2, $7, $9, $11, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $5, $7, $9, $11};
             string b[5] = {"out", "key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp FOR '(' id ':' id IN exp ')' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $7, $9, NULL, $5, $12); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $5, $7, $9, $12};
            string b[5] = {"out", "key", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp FOR '(' id ':' id IN exp ')' '{' stmts_level '}' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $7, $9, $12, $5, $15); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $5, $7, $9, $12, $15};
            string b[6] = {"out", "key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp FOR '(' id ':' id IN exp ')'  stmt IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($2, $7, $9, $11, $5, $13); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $5, $7, $9, $11, $13};
            string b[6] = {"out", "key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp ':' exp FOR id IN exp ')' { 
         runNode * r = new foreachGeneratorNode ($4, $6, $8, NULL, NULL, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $6, $8};
            string b[4] = {"kout", "out", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp ':' exp FOR id IN exp '{' stmts_level '}' ')' { 
         runNode * r = new foreachGeneratorNode ($4, $6, $8, $10, NULL, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $8, $10};
            string b[5] = {"kout", "out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp ':' exp FOR id IN exp  stmt ')' {  
         runNode * r = new foreachGeneratorNode ($4, $6, $8, $9, NULL, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $8, $9};
            string b[5] = {"kout", "out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;      
      } 
	|	'(' exp ':' exp FOR id IN exp IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($4, $6, $8, NULL, NULL, $10, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $8, $10};
            string b[5] = {"kout", "out", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp ':' exp FOR id IN exp '{' stmts_level '}' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($4, $6, $8, $10, NULL, $13, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $6, $8, $10, $13};
            string b[6] = {"kout", "out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;     
      } 
	|	'(' exp ':' exp FOR id IN exp  stmt IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($4, $6, $8, $9, NULL, $11, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $6, $8, $9, $11};
            string b[6] = {"kout", "out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;       
      } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' ')' { 
         runNode * r = new foreachGeneratorNode ($4, $7, $9, NULL, NULL, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[4] = {$2, $4, $7, $9};
            string b[4] = {"kout", "out", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 4);
         }
         #endif
         $$ = r;                               
      } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' '{' stmts_level '}' ')' {  
         runNode * r = new foreachGeneratorNode ($4, $7, $9, $12, NULL, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $7, $9, $12};
            string b[5] = {"kout", "out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, NULL, 5);
         }
         #endif
         $$ = r;   
      } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' stmt ')' { 
         runNode * r = new foreachGeneratorNode ($4, $7, $9, $11, NULL, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $7, $9, $11};
            string b[5] = {"kout", "out", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;      
      } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' IF exp ')' {  
         runNode * r = new foreachGeneratorNode ($4, $7, $9, NULL, NULL, $12, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $7, $9, $12};
            string b[5] = {"kout", "out", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;      
      } 
	|	'(' exp ':' exp FOR '(' id IN exp ')' '{' stmts_level '}' IF exp ')' {  
         runNode * r = new foreachGeneratorNode ($4, $7, $9, $12, NULL, $15, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $7, $9, $12, $15};
            string b[6] = {"kout", "out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;      
      } 
	|	'(' exp ':' exp FOR '(' id IN exp ')'  stmt IF exp ')' {  
         runNode * r = new foreachGeneratorNode ($4, $7, $9, $11, NULL, $13, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $7, $9, $11, $13};
            string b[6] = {"kout", "out", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;      
   
      } 
	|	'(' exp ':' exp FOR id ':' id IN exp ')' {  
         runNode * r = new foreachGeneratorNode ($4, $8, $10, NULL, $6, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $6, $8, $10};
            string b[5] = {"kout", "out","key", "val", "exp"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;         
      } 
	|	'(' exp ':' exp FOR id ':' id IN exp '{' stmts_level '}' ')' { 
         runNode * r = new foreachGeneratorNode ($4, $8, $10, $12, $6, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $6, $8, $10, $12};
            string b[6] = {"kout", "out","key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;   
      } 
	|	'(' exp ':' exp FOR id ':' id IN exp  stmt ')' {  
         runNode * r = new foreachGeneratorNode ($4, $8, $10, $11, $6, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $6, $8, $10, $11};
            string b[6] = {"kout", "out","key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp ':' exp FOR id ':' id IN exp IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($4, $8, $10, NULL, $6, $12, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $6, $8, $10, $12};
            string b[6] = {"kout", "out","key", "val", "exp", "if"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp ':' exp FOR id ':' id IN exp '{' stmts_level '}' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($4, $8, $10, $12, $6, $15, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[7] = {$2, $4, $6, $8, $10, $12, $15};
            string b[7] = {"kout", "out","key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 7);
         }
         #endif
         $$ = r;   
      } 
	|	'(' exp ':' exp FOR id ':' id IN exp  stmt IF exp ')' {  
          runNode * r = new foreachGeneratorNode ($4, $8, $10, $11, $6, $13, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[7] = {$2, $4, $6, $8, $10, $11, $13};
            string b[7] = {"kout", "out","key", "val", "exp", "stmts", "if"};           
            r->toJson ("generatorNode", "data", a, b, 7);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' ')' { 
         runNode * r = new foreachGeneratorNode ($4, $9, $11, NULL, $7, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[5] = {$2, $4, $7, $9};
            string b[5] = {"kout", "out","key", "val"};
            r->toJson ("generatorNode", "data", a, b, 5);
         }
         #endif
         $$ = r;            
      } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' '{' stmts_level '}' ')' {  
         runNode * r = new foreachGeneratorNode ($4, $9, $11, $14, $7, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $7, $9, $11, $14};
            string b[6] = {"kout", "out","key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' stmt ')' {  
         runNode * r = new foreachGeneratorNode ($4, $9, $11, $13, $7, NULL, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $7, $9, $11, $13};
            string b[6] = {"kout", "out","key", "val", "exp", "stmts"};
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;   
      } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' IF exp ')' {  
         runNode * r = new foreachGeneratorNode ($4, $9, $11, NULL, $7, $14, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[6] = {$2, $4, $7, $9, $11, $14};
            string b[6] = {"kout", "out","key", "val", "exp", "if"};            
            r->toJson ("generatorNode", "data", a, b, 6);
         }
         #endif
         $$ = r;   
      } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')' '{' stmts_level '}' IF exp ')' { 
         runNode * r = new foreachGeneratorNode ($4, $9, $11, $14, $7, $17, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[7] = {$2, $4, $7, $9, $11, $14, $17};
            string b[7] = {"kout", "out","key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 7);
         }
         #endif
         $$ = r;    
      } 
	|	'(' exp ':' exp FOR '(' id ':' id IN exp ')'  stmt IF exp ')' {  
         runNode * r = new foreachGeneratorNode ($4, $9, $11, $13, $7, $15, $2); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[7] = {$2, $4, $7, $9, $11, $13, $15};
            string b[7] = {"kout", "out","key", "val", "exp", "stmts", "if"};
            r->toJson ("generatorNode", "data", a, b, 7);
         }
         #endif
         $$ = r;   
      } 
   ;

regexp_op
   :	REGEXP '(' exp ')' {  
         runNode * r = new newregexpNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            r->toJson ("newregexpNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
	|	SEARCH '(' exp ',' exp ')' { 
         runNode * r = new searchNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5} ;
            string b[2] = {"str", "regexp"};
            r->toJson ("searchNode", "function", a, b, 2);
         }
         #endif
         $$ = r;      
      }
	|	SEARCH '(' exp ',' exp ',' list ')' { 
         runNode * r = new searchNode ($3, $5, $7); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $5, $7} ;
            string b[3] = {"str", "regexp", "key"};
            r->toJson ("searchNode", "function", a, NULL, 3);
         }
         #endif
         $$ = r;         
      }
	|	MATCH '(' exp ',' exp ')'  { 
         runNode * r = new matchNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5} ;
            string b[2] = {"str", "regexp"};
            r->toJson ("matchNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
   ;

iloop_access
   :	'$' { 
         runNode * r = new getiNode (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getiNode", "symbol", NULL, 0);
         }
         #endif
         $$ = r;    
      }
	|	'$' '{' NUM '}' {  
         runNode * r = new numConstNode (*$3); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *$3);
         }
         #endif
         runNode * d = new getiNode (r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {r};
            d->toJson ("getiNode", "symbol", a, NULL, 1);
         }
         #endif
         $$ = d;      
      }
   ;

identity	
   :	NUM { 
         runNode * r = new numConstNode (*$1);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *$1);
         }
         #endif
         $$ = r;
      }
   |	TRUE  { 
         runNode * r = new boolConstNode (true);
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("boolConstNode", "data", NULL, NULL, 0, "true");
         }
         #endif
         $$ = r;
      }
	|	FALSE { 
         runNode * r = new boolConstNode (false); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("boolConstNode", "data", NULL, NULL, 0, "false");
         }
         #endif
         $$  = r;
      }
	|	NULLTOKEN { 
         runNode * r = new nullNode (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("nullNode", "data", NULL, 0);
         }
         #endif
         $$  = r;   
      }
	|	SNUM  { 
         runNode * r = new numConstNode (*$1); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *$1);
         }
         #endif
         $$  = r;
      } 
   |	STR { 
         runNode * r = new strConstNode (*$1); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("strConstNode", "data", NULL, NULL, 0, *$1);
         }
         #endif
         $$  = r;   
      }
   |	REXP  { 
         runNode * r = new regexpNode (*$1); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("regexpNode", "data", NULL, NULL, 0, *$1);
         }
         #endif
         $$  = r;   
      }
   |	'+' NUM { 
         runNode * r = new numConstNode (*$2); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, *$2);
         }
         #endif
         $$  = r;
      }
   |	'-' NUM { 
         runNode * r = new numConstNode (-1 * (*$2)); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("numConstNode", "data", NULL, NULL, 0, (-1 * (*$2)));
         }
         #endif
         $$  = r;
      } 
	|	id  { $$ = $1;}
   |  '(' exp ')' { $$ = $2; }
   ;
  
function_exp
   :  function_lambda { $$ = $1; }
	|	function_partial { $$ = $1; }
   |	CONTEXTFUNC { 
         runNode * r = new contextFunction (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("contextFunction", "function", NULL, 0);
         }
         #endif
         $$  = r;   
      }
   ;

//======================================================================
function_lambda
   :	FUNCTION '('')' '{' stmts_level '}'  { 
         runNode * r = new functionNode (NULL, NULL, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$5} ;
            string b[1] = {"body"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         $$ = r;   
      }	
   |	FUNCTION '(' params_default ')' '{' stmts_level '}'  { 
         runNode * r = new functionNode (NULL, $3, $6); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $6} ;
            string b[2] = {"params", "body"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         $$ = r;    
      }	
   |	FUNCTION '(' params_default ')' '{' '}'  { 
         runNode * r = new functionNode (NULL, $3, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3};
            string b[2] = {"params"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         $$ = r;    
      }	
   |	FUNCTION '('')' '{' '}'  { 
         runNode * r = new functionNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("functionNode", "function", NULL, 0);
         }
         #endif
         $$ = r;   
      }
   |	FUNCTION '&' id {  
         runNode * r = new functiongetNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3} ;
            r->toJson ("functiongetNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
   |	'~' '('')' '{' stmts_level '}'  {  
         runNode * r = new functionNode (NULL, NULL, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$5} ;
            string b[1] = {"body"};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         $$ = r;     
      }	
   |	'~' '(' params_default ')' '{' stmts_level '}'  { 
         runNode * r = new functionNode (NULL, $3, $6); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $6} ;
            string b[2] = {"params", "body"};
            r->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         $$ = r;     
      }	
   |	'~' '(' params_default ')' '{' '}'  {  
         runNode * r = new functionNode (NULL, $3, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3} ;
            string b[1] = {"params",};
            r->toJson ("functionNode", "function", a, b, 1);
         }
         #endif
         $$ = r;     
      }	
   |	'~' '('')' '{' '}'  {  
         runNode * r = new functionNode (NULL, NULL, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("functionNode", "function", NULL, 0);
         }
         #endif
         $$ = r;   
      }
	|	'~' '&' id {  
         runNode * r = new functiongetNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3} ;
            r->toJson ("functiongetNode", "function", a, NULL, 1);
         }
         #endif
         $$ = r;   
      }
	|	'~' params_default ':' exp  { 
         runNode * r = new returnNode ($4); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$4} ;
            r->toJson ("returnNode", "stmt", a, NULL, 1);
         }
         #endif
         runNode * d = new functionNode ( NULL, $2, r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2,r} ;
            string b[2] = {"params", "body"} ;
            d->toJson ("functionNode", "function", a, b, 2);
         }
         #endif
         $$ = d;   
      } 
   ;
   
function_partial 
 	:	PARTIALFUNC '[' params_default ']' function_exp  { 
         runNode * r = new partialFunctionNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         $$ = r;        
      }
 	|	PARTIALFUNC '[' params_default ']' arrayexp  {
         runNode * r = new partialFunctionNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
 	|	PARTIALFUNC '[' params_default ']' '(' id ')' {
         runNode * r = new partialFunctionNode ($3, $6); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $6};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         $$ = r;   
      }
 	|	PARTIALFUNC '[' params_default ']' '(' function_exp ')'  { 
         runNode * r = new partialFunctionNode ($3, $6); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $6};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         $$ = r;      
      }
 	|	PARTIALFUNC '[' params_default ']' '(' arrayexp ')'  {
         runNode * r = new partialFunctionNode ($3, $6); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $6};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         $$ = r;      
      }
 	|	'[' params_default ']' unity  { 
         runNode * r = new partialFunctionNode ($2, $4, true); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$2, $4};
            string b[2] = {"defparams", "id"};
            r->toJson ("partFuncNode", "function", a, b, 2);
         }
         #endif
         $$ = r;      
      }
   ;

//======================================================================
list 		
   :  list ','   { 
         runNode * r = new listNode ($1, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         $$ = r;     
      }
   |  list ',' exp  { 
         runNode * r = new listNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            r->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         $$ = r;   
      }
   |	exp { 
         runNode * r = new listNode ($1, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1} ;
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         $$ = r;    
      }
   ;
	
map			
   :	map ',' mapelement  { 
         listNode * r = new listNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3} ;
            r->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         $$ = r;    
      }
	|	map ','  { 
         listNode * r = new listNode ($1, NULL); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1} ;
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         $$ = r;     
      }
	|	mapelement  {  
         listNode * r = new listNode ($1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         $$ = r;     
      }
   ;
   
mapelement	
   :	exp ':' exp { 
         runNode * r = new mapNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"key", "value"};
            r->toJson ("mapNode", "data", a, b, 2);
         }
         #endif
         $$ = r;    
      }
   |	function { $$ = $1; }
   ;  
   
//======================================================================
assig		
   :  arrayexp '=' exp { 
         runNode * r = new asigNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"var", "exp"};
            r->toJson ("asigNode", "operator", a, b, 2);
         }
         #endif
         $$  = r;      
      }
   |  arrayexp { $$ = $1; }
   ;
   
//======================================================================
array		
  :	array ',' exp { 
         listNode * r = new listNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            r->toJson ("listNode", "data", a, NULL, 2);
         }
         #endif
         $$  = r;
      }	
  |	exp { 
         listNode * r = new listNode ($1); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$1};
            r->toJson ("listNode", "data", a, NULL, 1);
         }
         #endif
         $$  = r;   
      }
  ;

parray      
	:  parray CLASSACCESS id {  
         runNode * r = new getNode ($1, $3, false); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         $$  = r;
      }
	|	parray '[' exp ']'	{ 
         runNode * r = new getNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         $$  = r;  
      }
	|	call_identity CLASSACCESS id	{
         runNode * r = new getNode ($1, $3, false); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         $$  = r;   
      }
	|	unity '[' exp ']'	{ 
         runNode * r = new getNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         $$  = r;   
      }
	|	call_identity '[' exp ']'	{ 
         runNode * r = new getNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"elem", "key"};
            r->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         $$  = r;   
      }
	|	parray '['']' { 
         runNode * r = new getNode_endValue (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("endValue", "operator", NULL, 0);
         }
         #endif
         runNode * d = new getNode ($1, r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"elem", "key"};
            d->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         $$  = d;    
      }
	|	unity '['']'  {
         runNode * r = new getNode_endValue (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("getNode", "operator", NULL, 0);
         }
         #endif
         runNode * d = new getNode ($1, r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"elem", "key"};
            d->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         $$  = d;  
      }
   |  call_identity '['']'  {
         runNode * r = new getNode_endValue (); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("endValue", "operator", NULL, 0);
         }
         #endif
         runNode * d = new getNode ($1, r); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, r};
            string b[2] = {"elem", "key"};
            d->toJson ("getNode", "operator", a, b, 2);
         }
         #endif
         $$  = d;       
      }
   |  identity { $$ = $1; }
   |  class_exp { $$ = $1; }
	;

arrayop 
  :   ARRAYCHUNK '(' exp ',' exp ')' { 
         runNode * r = new arrayChunkNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"array", "size"};
            r->toJson ("arrayChunkNode", "function", a, b, 2);
         }
         #endif
         $$ = r;    
      }
   |  ARRAYLAST '(' exp ')' { 
         runNode * r = new arraylastNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3} ;
            r->toJson ("arraylastNode", "function", a, NULL, 1);
         }
         #endif  
         $$ = r; 
      }
   |  ARRAYFIRST '(' exp ')' { 
         runNode * r = new arrayfirstNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3} ;
            r->toJson ("arrayfirstNode", "function", a, NULL, 1);
         }
         #endif  
         $$ = r;
      }
   |  ARRAYINSERT '(' exp ',' exp ',' exp ')' {
         runNode * r = new arrayinsertNode ($3, $5, $7); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[3] = {$3, $5, $7};
            string b[3] = {"array", "index", "elem"};
            r->toJson ("arrayinsertNode", "function", a, b, 3);
         }
         #endif  
         $$ = r;   
      }
   |  ARRAYDELETE '(' exp ',' exp  ')' { 
         runNode * r = new arraydeleteNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"array", "index"};
            r->toJson ("arrayinsertNode", "function", a, b, 2);
         }
         #endif  
         $$ = r;    
      }
   |  ARRAYUNSHIFT '(' exp ',' exp  ')' { 
         runNode * r = new arrayunshiftNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"array", "elem"};
            r->toJson ("arrayunshiftNode", "function", a, b, 2);
         }
         #endif  
         $$ = r;     
      }
   |  ARRAYPUSH '(' exp ',' exp  ')' { 
         runNode * r = new arraypushNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"array", "elem"};
            r->toJson ("arraypushNode", "function", a, b, 2);
         }
         #endif  
         $$ = r;       
      }
   |  ARRAYSHIFT '(' exp  ')' { 
         runNode * r = new arrayshiftNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3} ;
            r->toJson ("arrayshiftNode", "function", a, NULL, 1);
         }
         #endif  
         $$ = r;   
      }
   |  ARRAYPOP '(' exp  ')' { 
         runNode * r = new arraypopNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3} ;
            r->toJson ("arraypopNode", "function", a, NULL, 1);
         }
         #endif  
         $$ = r;     
      }
   |  REDUCE '(' exp ',' exp ')' { 
         runNode * r = new reduceNode ($3, $5); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$3, $5};
            string b[2] = {"array", "func"};
            r->toJson ("reduceNode", "function", a, b, 2);
         }
         #endif  
         $$ = r;    
      }
  ;

//======================================================================
namespace      
   :  namespace NAMESPACE id { 
         runNode * r = new namespaceNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"name", "key"};
            r->toJson ("namespaceNode", "function", a, b, 2);
         }
         #endif  
         $$ = r;     
      }
	|	id NAMESPACE id	{ 
         runNode * r = new namespaceNode ($1, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {$1, $3};
            string b[2] = {"name", "key"};
            r->toJson ("namespaceNode", "function", a, b, 2);
         }
         #endif  
         $$ = r;     
      }
	|	PARENT NAMESPACE id	{ 
         runNode * r = new  parentNode(); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("parentNode", "function", NULL, 0);
         }
         #endif  
         runNode * d = new namespaceNode (r, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r, $3};
            string b[2] = {"name", "key"};
            d->toJson ("namespaceNode", "function", a, b, 2);
         }
         #endif  
         $$ = d;              
      }
	|	STATIC NAMESPACE id	{ 
         runNode * r = new   staticNode(); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson (" staticNode", "class", NULL, 0);
         }
         #endif  
         runNode * d = new namespaceNode (r, $3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[2] = {r, $3};
            string b[2] = {"name", "key"};
            d->toJson ("namespaceNode", "function", a, b, 2);
         }
         #endif  
         $$ = d;                 
      }
	;
   
//======================================================================
id 			
  :	ID  { 
         idNode * r = new idNode (*$1); 
         #if JSON==1
         if (interpreter::get()->json){
            r->toJson ("idNode", "symbol", NULL, NULL, 0, "", *$1);
         }
         #endif
         $$  = r;
      }
  |   '@' '{' exp '}' { 
         idNode * r = new idgetNode ($3); 
         #if JSON==1
         if (interpreter::get()->json){
            runNode*a[1] = {$3} ;
            r->toJson ("idgetNode", "reflection", a, NULL, 1);
         }
         #endif  
         $$ = r;  
      }
  ;

//======================================================================
%%

//======================================================================
// Fco. Javier Bohórquez Ogalla
