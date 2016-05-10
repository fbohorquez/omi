//lStmtNode.cpp
//-------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#include "stmtNode.h"
//~ #include "stmtNode.h"
//~ #include "../error.h"
//~ #include <math.h>
//~ #include <stdlib.h>
//~ #include <string>
//~ #include <iostream>
//~ #include <stdio.h>
//~ #include "interpreter.h"
//~ #include "lshParser.h"
//~ #include "operatorRegexpNode.h"
//~ #include "../interpreter.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//noNode
noNode::noNode () {}

void noNode::run () {}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//breakException
breakException::breakException (int n): n_(n) {}

const char* breakException::what() const throw() {
   return "Break fuera de bloque.";
}

void breakException::end () {
   if (n_ != 1) throw breakException (n_ - 1);
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//stmtNode
int stmtNode::row_ = 2;

stmtNode::stmtNode (
   runNode* node1, 
   runNode* node2, 
   YYLTYPE bloq, 
   bool firstlevel
): 
   node1_ (node1), 
   node2_ (node2), 
   line_(bloq.first_line),
   firstlevel_(firstlevel) {}
   
stmtNode::stmtNode (
   runNode* node1, 
   runNode* node2, 
   YYLTYPE bloq 
): 
   node1_ (node1), 
   node2_ (node2), 
   line_(bloq.first_line),
   firstlevel_(false) {}
   
stmtNode::stmtNode (
   runNode* node1, 
   runNode* node2
): 
   node1_ (node1), 
   node2_ (node2), 
   line_(0), 
   firstlevel_(false) {}

void stmtNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (!compile_error) {
      try {
         if (node1_) {
            node1_->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif
         }
      } catch (errorException& e) {
         e.error(infile, line_);
      } catch (gotoException& e) {
         if (firstlevel_) 
            return;
         else
            throw gotoException();
      }
      warningQueue::warning (infile, line_);
      try {
         if (node2_)  {
            node2_->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif
         }
      } catch (errorException& e) {
         e.error(infile ,line_);
      }catch (gotoException& e) {
         if (firstlevel_) 
            return;
         else
            throw gotoException();
      }
   }
}

void stmtNode::newLine (void) {
   yylloc.first_line = row_;
   row_ ++;
}

bool stmtNode::compile_error = false;
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//includeNode
includeNode::includeNode (runNode* file): file_(file) {}

void includeNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   string file_aux;
   int line_aux;
   runNode* aux = file_;
   nexpNode::resolved(aux);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   if (stringNode* str = dynamic_cast<stringNode*> (aux)) {
      string s = str->strvalue();
      string ruta = infile.substr(0,infile.find_last_of("/\\") + 1);
      s = ruta.append (s.c_str());
      if (FILE *file_descriptor = fopen (s.c_str(),"r")){
         yyin = file_descriptor;
         file_aux = infile;
         line_aux = stmtNode::row_;
         stmtNode::row_= 2;
         infile = s;
         yyrestart (yyin);
         yyparse();
         infile = file_aux;
         stmtNode::row_ = line_aux;
      } else 
         cerr << "El fichero " << s << " no existe" << endl;
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//typeofNode
typeofNode::typeofNode (idNode* id): id_(id) {}
      
void typeofNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   logicNode* l;
   arithNode* a;
   stringNode* s;
   arrayNode* array;
   stringstream ss1;
   if (id_) {
      id_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif  
      if (
         id_->ref() && 
         id_->nodeval() && 
         dynamic_cast<classNode*>(id_->nodeval())
      )
         ss1 << "Class" << endl;
      if (dynamic_cast<stringNode*>(id_->nodeval()))
         ss1 << "String" << endl;
      else if (array = dynamic_cast<arrayNode*>(id_->nodeval()))
         ss1 << "Array (" << array->getArray()->size() << ")" << endl;
      else if (dynamic_cast<arithNode*>(id_->nodeval()))
         ss1 << "Arithmetic" << endl;
      else if (dynamic_cast<logicNode*>(id_->nodeval()))
         ss1 << "Boolean" << endl;
      else if (dynamic_cast<functionNode*>(id_->nodeval()))
         ss1 << "Function" << endl;
      else if (dynamic_cast<idNode*>(id_->nodeval()))
         ss1 << "ID" << endl;
      else if (dynamic_cast<listNode*>(id_->nodeval()))
         ss1 << "List" << endl;
      cout << ss1.str();
      #if JSON==1
         interpreter::to_jsonOut(this, ss1.str());
      #endif
   }
}
      
string typeofNode::type (runNode *r) {
   refNode* ref;
   logicNode* l;
   arithNode* a;
   stringNode* s;
   arrayNode* array;
   objectNode* obj;
   nexpNode  *id;
   id = dynamic_cast<nexpNode*> (r);
   ostringstream os;
   if (dynamic_cast<fexpNode*> (r)) {
      os << "Function";
      return os.str();
   }
   if (id = dynamic_cast<nexpNode*> (r)) {
      os << "ID: ";
      id->run();
      r = id->nodeval();
   }
   if (ref = dynamic_cast<refNode*>(r))
      os << "Ref: " << ref->strvalue() ;
   else if (nullNode* nu = dynamic_cast<nullNode*>(r))
      os << "NULL" ;
   else if (dynamic_cast<strNode*>(r))
      os << "strNode" ;
   else if (s = dynamic_cast<stringNode*>(r))
      os << "String: " << s->strvalue() ;
   else if (dynamic_cast<numNode*>(r))
      os << "numNode";
   else if (a = dynamic_cast<arithNode*>(r))
      os << "Arithmetic: " << a->numvalue() ;
   else if (dynamic_cast<boolNode*>(r))
      os << "boolNode";
   else if (l = dynamic_cast<logicNode*>(r))
      os << "Boolean: " << l->boolvalue();
   else if (obj = dynamic_cast<objectNode*>(r)){
      string class_name = "";
      if (classNode* c = dynamic_cast<classNode*>(obj->getClass()))
         class_name = " (" + c->name() + ")";
      os << "Object" << class_name ;
   }else if (array = dynamic_cast<arrayNode*>(r))
      os << "arrayNode" ;
   else if (dynamic_cast<functionNode*>(r))
      os << "Function" ;
   else if (dynamic_cast<listNode*>(r))
      os << "List" ;
   else if (dynamic_cast<expNode*>(r))
      os << "Expresion" ;
   else if (dynamic_cast<printableNode*>(r))
      os << "Printable" ;
   return os.str();
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//breakNode
breakNode::breakNode (int n): n_ (n) {}

void breakNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   throw breakException(n_);
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//exitNode
void exitNode::run () {
   #if JSON==1
      if (interpreter::get()->json){
         interpreter::to_jsonRun(this); 
         interpreter::jsonEnd();
      }
   #endif 
   _exit (0);
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//labelNode
labelNode::labelNode (runNode* node1, runNode* node2): 
   node1_ (node1), node2_(node2) {}

void labelNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   if (idNode* id = dynamic_cast<idNode*>(node1_)){
      id->setName ("~label:" + id->name());
   }
   node1_->run ();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   idNode* id = dynamic_cast<idNode*> (node1_);
   if (id) {
      id->noderef(node2_);
   } else
      throw errorException (
         "Wrong label", "labelNode: node 2 is unknown operand ", 
         0
      );
   node2_->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//gotoException
const char* gotoException::what() const throw() {
   return "goto exception";
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//gotoNode
gotoNode::gotoNode (runNode* node): node1_ (node) {}

void gotoNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode* node_aux1 = node1_;
   if (idNode* id = dynamic_cast<idNode*>(node_aux1)){
      id->setName ("~label:" + id->name());
   }
   node_aux1 = nexpNode::resolved (node_aux1);
   if (stmtNode* stmt = dynamic_cast<stmtNode*> (node_aux1)) {
      stmt->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }      
   throw gotoException ();
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//withNode
vector<runNode *> withNode::stack_with;

int withNode::top_with = -1;

withNode::withNode (runNode* node, runNode *stmts): 
   node_ (node), stmts_(stmts) {}

void withNode::run(){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   push_with(node_);
   stmts_->run();
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   pop_with ();
}

void withNode::push_with (runNode* node_) {
   stack_with.push_back (node_);
   top_with ++;
}

runNode *withNode::get_with () {
   if (!stack_with.empty())
      return stack_with[top_with];
   return NULL;
}

void withNode::pop_with () {
   if (!stack_with.empty()){
      stack_with.pop_back ();
      top_with --;
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//sizeOfNode
sizeOfNode::sizeOfNode (runNode* node) : node_ (node){}

void sizeOfNode::run () {
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode * node = node_;
   if (node){ 
      nexpNode::resolved (node);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif       
      numvalue_ = sizeof (*node);
      #if JSON==1
         interpreter::to_jsonSetValue(this, numvalue_);
      #endif        
   }else {
      cerr << "symbols: " << sizeof(symbols) << endl;
      cerr << "sTable: " << sizeof(sTable) << endl;
      cerr << "runNode: " << sizeof(runNode) << endl;
      cerr << "\tobjectTypeNode: " << sizeof (objectTypeNode) << endl;
      cerr << "\t\tprintableNode: " << sizeof (printableNode) << endl;
      cerr << "\t\t\texpNode: " << sizeof (expNode) << endl;
      cerr << "\t\t\t\tdexpNode: " << sizeof (dexpNode) << endl;
      cerr << "\t\t\t\t\tlogicNode: " << sizeof (logicNode) << endl;
      cerr << "\t\t\t\t\tarithNode: " << sizeof (arithNode) << endl;
      cerr << "\t\t\t\t\tstringNode: " << sizeof (stringNode) << endl;
      cerr << "\t\t\t\tnexpNode: " << sizeof (nexpNode) << endl;
      cerr << "\t\t\t\tarrayNode: " << sizeof (arrayNode) << endl;
      cerr << "\t\t\trefNode: " << sizeof (refNode) << endl;
      cerr << "\t\t\tvector<refNode*>: " 
         << sizeof (vector<refNode*>) << endl;
      numvalue_ = 0;
       #if JSON==1
         interpreter::to_jsonSetValue(this, numvalue_);
      #endif   
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//datInfoNode
datInfoNode::datInfoNode (runNode* node) : node_ (node){}

void datInfoNode::run () {
   stringstream ss1;
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode * node = node_;
   nexpNode::resolved (node);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   ss1 << "ptr(" << node << "), type(" << typeofNode::type (node) 
      << "), refs(" << node->ref_count_ << ")" << endl; 
   cout << ss1.str();
   #if JSON==1
      interpreter::to_jsonOut(this, ss1.str());
   #endif
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//throwException
throwException::throwException (runNode* resp): resp_(resp) {}

const char* throwException::what() const throw() {
   return "throw statement out of try block";
}
 
runNode* throwException::val () const {
   return resp_;
}  
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//throwNode
throwNode::throwNode (runNode* obj) : obj_ (obj) {}

void throwNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
  runNode * obj = obj_;
  nexpNode::resolved (obj);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
  throw throwException(expNode::clone(obj)); 
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//tryNode

tryNode::tryNode (
   runNode* tryblock, 
   runNode *id, 
   runNode *catchblock
): 
   tryblock_ (tryblock), 
   id_ (id), 
   catchblock_ (catchblock) {}

void tryNode::run () {
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
  try {
   tryblock_->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
  }catch (throwException& r) {
   runNode * obj = r.val();
   asigNode asig (id_, obj);
   asig.run();  
   catchblock_->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
  } 
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
