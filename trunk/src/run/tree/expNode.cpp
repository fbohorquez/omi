//expNode.cpp
//-------------------------------------------------------------------------------------------
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>

#include "expNode.h"
#include "../table/classNode.h"
#include "../operators/opNode.h"
#include "../../interpreter.h"
#include "../../error.h"
#include "typeNode.h"

using namespace std;
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//expnode
runNode* expNode::clone (runNode* node) {
   runNode * r = NULL;
   if (dynamic_cast<nullNode*> (node)){
      r = new nullNode ();
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "nullNode", "data"); 
      #endif
   }else if (objectNode * obj = dynamic_cast<objectNode*>(node)){
      r = new objectNode (obj);
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "objectNode", "data"); 
      #endif
   }else if (stringNode* str = dynamic_cast<stringNode*> (node)){
      r = new strNode (str->strvalue());
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "strNode", "data"); 
      #endif
   }else if (dynamic_cast<fileNode*> (node)) {
      r = node;
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "fileNode", "data"); 
      #endif
   }else if (arithNode* n_arith = dynamic_cast<arithNode*> (node)){
      r = new numNode (n_arith->numvalue());
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "numNode", "data"); 
      #endif
   }else if (logicNode* n_bool = dynamic_cast<logicNode*> (node)) {
      r = new boolNode (n_bool->boolvalue());
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "boolNode", "data"); 
      #endif
   }else if (arrayConstNode * n_array = dynamic_cast<arrayConstNode*> (node)){
      arrayNode * a = new arrayNode(n_array);
      r = a;
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "arrayNode", "data"); 
         a->toJsonSymbols ();
      #endif
   }else if (arrayNode * n_array = dynamic_cast<arrayNode*> (node)) {
      arrayNode * a = new arrayNode(n_array);
      r = a;
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "array", "data"); 
         a->toJsonSymbols ();
      #endif
   }else if (regexpNode * n_exp = dynamic_cast<regexpNode*> (node)){
      r = new regexpNode (n_exp);
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "regexNode", "data"); 
      #endif
   }else if (classNode* class_ = dynamic_cast<classNode*> (node)){
      r = new classNode (class_);
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "classNode", "data"); 
      #endif
   }else if (functionNode* f = dynamic_cast<functionNode*> (node)){
      r = new functionNode (*f);
      #if JSON==1 
         interpreter::to_jsonClone (r, node, "functionNode", "data"); 
      #endif
   }
   
   return r;
}

 void expNode::setNodeValue (runNode* node) {}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//dexpNode
bool dexpNode::boolvalue () const { return false; }
num dexpNode::numvalue () const { return 0; }
string dexpNode::strvalue () const { return ""; }
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//nexpNode
nexpNode::nexpNode () : ref_ (NULL) {}

refNode* nexpNode::ref () {
   return ref_;
}
   
void nexpNode::noderef (runNode* node){
   if (!ref_) ref_ = new refNode ();
   ref_->setRef(node);
}

runNode* nexpNode::nodeval () const {
   if (ref_)
      return ref_->getRef();
   else
      return NULL;
}

void nexpNode::setRef (refNode* node){
   ref_ = node;
}

refNode* nexpNode::getRef (){
   return ref_;
}

runNode* nexpNode::resolved (runNode* &node) {
   nexpNode* nexp;
   refNode* ref;
   bool is_dexp = (bool)(dynamic_cast<dexpNode*> (node));
   while ((nexp = dynamic_cast<nexpNode*> (node)) && !dynamic_cast<fexpNode*> (node) && !dynamic_cast<arrayNode*>(node)&& !dynamic_cast<stringNode*>(node)) {
      nexp->run();
      node = nexp->nodeval();
   }
   
   if (is_dexp || dynamic_cast<fexpNode*>(node)) 
      node->run();
   return node;
}

runNode* nexpNode::resolvedRef (runNode* &node) {
   nexpNode* nexp;
   refNode* ref;
   while ((nexp = dynamic_cast<nexpNode*> (node)) && !dynamic_cast<fexpNode*> (node) && !dynamic_cast<arrayNode*>(node)&& !dynamic_cast<stringNode*>(node)) {
      nexp->run();
      node = nexp->nodeval();
   }
   return node;
}

void nexpNode::asig (runNode* &node, bool run ) {
   runNode * node_ = node;
   if (run) {      
      nexpNode::resolved(node_);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
   }
   if (expNode * exp = dynamic_cast<expNode*> (node_)) {
      noderef (exp);
      #if JSON==1
         interpreter::to_jsonSetValue(this, exp);
      #endif      
   }
}

runNode* nexpNode::resolved (runNode* &node, runNode* &ref) {
   nexpNode* nexp;
   while ((nexp = dynamic_cast<nexpNode*> (node)) && !dynamic_cast<fexpNode*> (node) && !dynamic_cast<arrayNode*>(node)&& !dynamic_cast<stringNode*>(node)) {
      nexp->run();
      
      ref = nexp->getRef();
      node = nexp->nodeval();
   }
   return node;
}

runNode* nexpNode::resolvedAsFunction (runNode* &node) {
   if (idNode * idf = dynamic_cast<idNode*> (node)){
      if (idf->existfunction ()){
         idf->runf();
         node =  idf->nodevalf();
      }
   }
   return nexpNode::resolved (node);
}
runNode* nexpNode::resolvedAsFunction (runNode* &node, runNode* &ref) {
   if (idNode * idf = dynamic_cast<idNode*> (node)){
      if (idf->existfunction ()){
         idf->runf();
         ref = idf->getReff();
         node =  idf->nodevalf();
      }
   }
   return nexpNode::resolved (node, ref);
}
runNode* nexpNode::resolv (runNode* node) {
   if (nexpNode* nexp = dynamic_cast<nexpNode*> (node)) {
      nexp->run();
      node = nexp->nodeval();
   }
   return node;
}

void nexpNode::setVal (runNode * node ) {
   noderef (node);
}

string nexpNode::print () const  {
   if (printableNode * p = dynamic_cast<printableNode*> (ref_->getRef())){
      return p->print();
   }
   return "";
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//logicNode
 logicNode::logicNode () : boolvalue_ (false){}
 
 runNode * logicNode::class_ = NULL;
void logicNode::generateClass () {
   idNode id ("logicClass");
   classNode * c = new classNode (&id, NULL);
   c->run();
   c->newelement_ = new boolNode (false);
   logicNode::class_ =  c;
}

bool logicNode::boolvalue () const {
   return boolvalue_;
}

string logicNode::print () const {
   return (boolvalue_)?"true":"false";
}

runNode* logicNode::nodeval () const {
   return new boolNode (boolvalue_);
}

bool logicNode::to_bool (runNode* node) {
   if (dexpNode * dexp = dynamic_cast<dexpNode*>(node))
      return dexp->boolvalue();
   else if (dynamic_cast<fexpNode*> (node))
      return true;
   return false;
}

num logicNode::numvalue () const {
   return (int)boolvalue_;
}

string logicNode::strvalue () const {
   return (boolvalue_)? "1":"";
}

runNode * logicNode::getClass () {
   return custom_class_?custom_class_:logicNode::class_;
}

void  logicNode::setNodeValue (runNode* node)  {
   boolvalue_ = logicNode::to_bool (node);
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//arithNode
runNode * arithNode::class_ = NULL;

void arithNode::generateClass () {
   idNode id ("arithClass");
   classNode * c = new classNode (&id, NULL);
   c->run();
   c->newelement_ = new boolNode (false);
   arithNode::class_ =  c;
}

string arithNode::print () const {
   ostringstream oss;
   oss << setprecision(NUMPRECISION);
   oss << numvalue_;
   return oss.str();
}

runNode* arithNode::nodeval () const {
   return new numNode (numvalue_);
}

num arithNode::numvalue () const {
   return numvalue_;
}

num arithNode::to_num (runNode* node, bool exception ) {
   if (dexpNode * dexp = dynamic_cast<dexpNode*>(node))
      return dexp->numvalue();
   else if (exception)
      throw errorException ("Unknown type", "to_num: node  is unknown type ", 1);
   return 0;
}

string arithNode::strvalue () const{
   ostringstream oss;
   oss << setprecision(NUMPRECISION);
   oss << this->numvalue();
   return oss.str();
}

bool arithNode::boolvalue () const{ return numvalue_; }

runNode * arithNode::getClass () {
   return custom_class_?custom_class_:arithNode::class_;
}

 void arithNode::setNodeValue (runNode* node)  {
   numvalue_ = arithNode::to_num (node);
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//stringNode
 runNode * stringNode::class_ = NULL;
 
void stringNode::generateClass () {
   idNode id ("stringClass");
   classNode * c = new classNode (&id, NULL);
   c->run();
   c->setMethod (new strNode ("explode"), explodeNode::asMethod());
   c->setMethod (new strNode ("find"), findNode::asMethod());
   c->setMethod (new strNode ("lower"), lowerNode::asMethod());
   c->setMethod (new strNode ("upper"), upperNode::asMethod());
   c->setMethod (new strNode ("replace"), replaceNode::asMethod());
   c->setMethod (new strNode ("replace_sub"), subreplaceNode::asMethod());
   c->setMethod (new strNode ("search"), searchNode::asMethod());
   c->setMethod (new strNode ("match"), matchNode::asMethod());
   c->newelement_ = new strNode ("");
   stringNode::class_ =  c;
}

stringNode::stringNode () {

}

string stringNode::print () const {
   ostringstream oss;
   oss << strvalue_;
   return oss.str();
}

runNode* stringNode::nodeval () const {
   return new strNode (strvalue_);
}

string stringNode::strvalue () const {
   return strvalue_;
}

num stringNode::numvalue () const {
   std::istringstream inpStream (strvalue_);
   num inpValue = 0.0;
   if ((inpStream >> inpValue) && strvalue_.find(" ") == string::npos)
      return inpValue;
   return strvalue_.length();
}
bool stringNode::is_numvalue () const {
   std::istringstream inpStream (strvalue_);
   num inpValue = 0.0;
   inpStream >> inpValue;
   if (strvalue_ == "0" || (inpValue && strvalue_.find(" ") == string::npos)){
      return true;
   }
   return false;
}

string stringNode::to_str (runNode* node) {
   if (objectNode* object = dynamic_cast<objectNode*>(node)){
      strNode str("_str");
      classNode * c = dynamic_cast<classNode*>(object->getClass ());
      if (c && c->getMethod(&str)){
         if (functionNode *f = dynamic_cast<functionNode*>(c->getMethod(&str))){
            f->setObj(object);
            functioncallNode* call = new functioncallNode(f, NULL);
            runNode* val;
            call->run();
            if (stringNode* str_val = dynamic_cast<stringNode*> (call->nodeval())){
               return str_val->strvalue();
            }
         }
      }
      return "";
   }
   else if (arrayNode* array = dynamic_cast<arrayNode*>(node)){      
      strNode str("_str");
      if (fexpNode* func = dynamic_cast<fexpNode*>(array->get(&str, false))){
         functioncallNode* call = new functioncallNode(func, NULL);
         call->run();
         if (stringNode* str_val = dynamic_cast<stringNode*> (call->nodeval())){
            return str_val->strvalue();
         }
      }
      return "";
   }else if (dexpNode *dexp = dynamic_cast<dexpNode*>(node)){
      return dexp->strvalue();
   }else if (refNode * ref = dynamic_cast<refNode*>(node)) {
      return ref->strvalue();
   }
   else 
      throw errorException ("Unknown operand", "stringNode: not node to string ", 1);
}

string* stringNode::strref () {
   return &strvalue_;
}

runNode * stringNode::getClass () {
   return custom_class_?custom_class_:stringNode::class_;
}

void stringNode::setStrValue (string s) {
   strvalue_ = s;
}

bool stringNode::boolvalue () const { return numvalue(); }

void  stringNode::setNodeValue (runNode* node)  {
   strvalue_ = stringNode::to_str (node);
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Comprobación de *node1 < *node2
bool cmp_runNode::operator()(runNode  *node1, runNode *node2) {
   runNode* node_aux1 = node1;
   runNode* node_aux2 = node2;
   idNode* id = dynamic_cast<idNode*> (node_aux1);
   if (id)
      node_aux1 = id->nodeval();
   id = dynamic_cast<idNode*> (node_aux2);
   if (id)
      node_aux2 = id->nodeval();
   expNode* exp = dynamic_cast<expNode*> (node_aux1);
   if (exp)
      node_aux1 = exp;
   exp = dynamic_cast<expNode*> (node_aux2);
   logicNode *l1, *l2; 
   arithNode *n1, *n2;
   stringNode *s1, *s2;
   refNode *k1, *k2;
   l1 = dynamic_cast<logicNode*>(node_aux1);
   l2 = dynamic_cast<logicNode*>(node_aux2);
   n1 = dynamic_cast<arithNode*>(node_aux1);
   n2 = dynamic_cast<arithNode*>(node_aux2);
   s1 = dynamic_cast<stringNode*>(node_aux1);
   s2 = dynamic_cast<stringNode*>(node_aux2);
   k1 = dynamic_cast<refNode*>(node_aux1);
   k2 = dynamic_cast<refNode*>(node_aux2);
   if (s1) {
      if (s2) {
         return s1->strvalue() < s2->strvalue();
      } else if (n2) {
         std::istringstream inpStream(s1->strvalue());
         num inpValue = 0.0;
         if (inpStream >> inpValue)
            return (atof(s1->strvalue().c_str()) < n2->numvalue());
         else
            return false;
      } else if (l2) {
         return (atof(s1->strvalue().c_str()) < l2->boolvalue());
      } else if (k2) {
         return s1->strvalue() < k2->strvalue();
      } else {
         return node1 < node2;
      }
   } else if (k1) {
      if (k2) {
         return k1->strvalue() < k2->strvalue();
      } else if (s2) {
         return k1->strvalue() < s2->strvalue();
      } else if (n2) {
         std::istringstream inpStream(k1->strvalue());
         num inpValue = 0.0;
         if (inpStream >> inpValue)
            return (atof(k1->strvalue().c_str()) < n2->numvalue());
         else
            return false;
      } else if (l2) {
         return (atof(k1->strvalue().c_str()) < l2->boolvalue());
      }  else {
         return node1 < node2;
      }
   } else if (n1) {
      if (s2) {
         std::istringstream inpStream(s2->strvalue());
         num inpValue = 0.0;
         if (inpStream >> inpValue)
            return (n1->numvalue () < atof (s2->strvalue().c_str()));
         else
            return true;
      }else if (k2) {
         std::istringstream inpStream(k2->strvalue());
         num inpValue = 0.0;
         if (inpStream >> inpValue)
            return (n1->numvalue () < atof (k2->strvalue().c_str()));
         else
            return true;
      } else if (n2) {
         return (n1->numvalue() < n2->numvalue());
      } else if (l2) {
         return (n1->numvalue() < l2->boolvalue());
      } else {
         return node1 < node2;
      }
   } else if (l1) {
      if (s2) {
         return (l1->boolvalue () < atof (s2->strvalue().c_str()));
      }else if (k2) {
         return (l1->boolvalue () < atof (k2->strvalue().c_str()));
      } else if (n2) {
         return (l1->boolvalue() < n2->numvalue());
      } else if (l2) {
         return (l1->boolvalue() < l2->boolvalue());
      } else {
         return node1 < node2;
      }
   } else {
      return node1 < node2;
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//fexpNode
bool fexpNode::is_print () const {
   return false;
}

bool fexpNode::is_runlist () const {
   return false;
}

void fexpNode::rmRef () {}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//Fco.javier Bohórquez Ogalla
