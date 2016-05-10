//operatorNode.cpp
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

//----------------------------------------------------------------------
#include "operatorNode.h"
//~ #include DATABASE
#include "stmtNode.h"
#include "componentNode.h"
#include "../error.h"
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include "interpreter.h"
#include "lshParser.h"
#include "operatorRegexpNode.h"
#include "../interpreter.h"
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//asigNode
asigNode::asigNode (runNode* node1, runNode* node2): node1_ (node1), node2_(node2) {}

void asigNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux = node2_, *nodeR_ = NULL;
   ref_ = NULL;
   nexpNode::resolvedRef (node_aux);
   #if JSON==1
      if (node2_ != node_aux)
         interpreter::to_jsonRun(this);
   #endif
   if (!(bool)dynamic_cast<functionNode*>(node_aux) && node2_ == node_aux) {
      node_aux->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   
   
   nodeR_ = this->isRefNode (node_aux)?node_aux:expNode::clone (node_aux);
   

   noderef(nodeR_);
   #if JSON==1
      interpreter::to_jsonSetValue(this, nodeR_);
   #endif
   setValue (nodeR_);
}

void asigNode::runLevel () {
   runNode *node_aux = node2_, *nodeR_ = NULL;
   ref_ = NULL;
   sTable::sTable_use->setLevel (sTable::sTable_use->getLevel() - 1);
   nexpNode::resolved (node_aux); 
   sTable::sTable_use->setLevel (sTable::sTable_use->getLevel() + 1);
   nodeR_ = this->isRefNode (node_aux)?node_aux:expNode::clone (node_aux);
   noderef(nodeR_);
   setValue (nodeR_);
}

bool asigNode::isRefNode (runNode* node){
   //~ return (dynamic_cast<nexpNode*>(node2_) || dynamic_cast<objectNode*>(node2_) || dynamic_cast<refNode*>(node2_) || dynamic_cast<fexpNode*>(node2_)) ;
   return (
      dynamic_cast<returnNode*>(node2_) || 
      dynamic_cast<getRefNode*>(node2_) || 
      dynamic_cast<idNode*>(node2_) || 
      dynamic_cast<getNode*>(node2_) || 
      dynamic_cast<objectNode*>(node2_) || 
      dynamic_cast<objectNode*>(node) || 
      dynamic_cast<refNode*>(node2_) || 
      dynamic_cast<refNode*>(node) || 
      dynamic_cast<fexpNode*>(node2_)
   ) ;
}

void asigNode::setValue (runNode* node) { 
   if (nexpNode* nexp = dynamic_cast<nexpNode*> (node1_)) {
      revConnectNode::init("asigNode");
      nexp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      nexp->noderef(node);
      ref_ = nexp->ref();
      revConnectNode::run_rev ("asigNode", node, 1);
      revConnectNode::end("asigNode");
   }else{
      throw errorException ("assigning constant", "asigNode: Node 1 is const ", 1); 
   }
}

runNode* asigNode::getLeft () {
   return node1_;
}  
 
runNode* asigNode::getRight () {
   return node2_;
}

bool asigNode::is_runlist () const{
   return true;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//asigrefNode
asigrefNode::asigrefNode (runNode* node1, runNode* node2): node1_ (node1), node2_(node2) {}

void asigrefNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux = node2_, *nodeR_ = NULL;
   if (nexpNode* n_id = dynamic_cast<nexpNode*> (node_aux)) {
      n_id->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
     noderef(n_id->getRef());
     #if JSON==1
         interpreter::to_jsonSetValue(this, n_id->getRef());
      #endif
     nodeR_ = n_id->getRef();
   } else if (expNode* exp = dynamic_cast<expNode*> (node_aux)) {
      exp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      noderef(exp);
      #if JSON==1
         interpreter::to_jsonSetValue(this, exp);
      #endif
      nodeR_ = exp;
   }
   setValue (nodeR_);
}

void asigrefNode::setValue (runNode* node) { 
   if (nexpNode* nexp = dynamic_cast<nexpNode*> (node1_)) {
      nexp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      if (node != nexp->getRef())
         nexp->noderef (node);
      else
         throw errorException ("Reference to same symbol", "asigrefNode: Reference recursive ", 1); 
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getRefNode
getRefNode::getRefNode (runNode* node): node_ (node) {}

void getRefNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux = node_;
   if (nexpNode* n_id = dynamic_cast<nexpNode*> (node_aux)) {
      n_id->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
     noderef(n_id->getRef());
      #if JSON==1
         interpreter::to_jsonSetValue(this, n_id->getRef());
      #endif     
   } else if (expNode* exp = dynamic_cast<expNode*> (node_aux)) {
      exp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      noderef(exp);
      #if JSON==1
         interpreter::to_jsonSetValue(this, exp);
      #endif      
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//orNode
orNode::orNode (runNode* op1, runNode* op2): op1_ (op1), op2_ (op2) {}

void orNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = op1_;
   runNode* op2 = op2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (logicNode::to_bool(op1)) {
      noderef(op1);
      #if JSON==1
         interpreter::to_jsonSetValue(this, op1);
      #endif
   } else {
      nexpNode::resolved (op2);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      noderef(op2);
      #if JSON==1
         interpreter::to_jsonSetValue(this, op2);
      #endif
   }
}

bool orNode::do_or (runNode* op1, runNode* op2) {
   return logicNode::to_bool(op1) || logicNode::to_bool (op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//andNode
andNode::andNode (runNode* op1, runNode* op2): op1_ (op1), op2_ (op2) {}

void andNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = op1_;
   runNode* op2 = op2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (logicNode::to_bool(op1)) {
      nexpNode::resolved (op2);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      noderef(op2);
      #if JSON==1
         interpreter::to_jsonSetValue(this, op2);
      #endif
   } else {
      noderef(op1);
      #if JSON==1
         interpreter::to_jsonSetValue(this, op1);
      #endif
   }
}

bool andNode::do_and (runNode* op1, runNode* op2) {
   return logicNode::to_bool(op1) && logicNode::to_bool (op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//notNode
notNode::notNode (runNode* op): op_ (op) {}

void notNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op = op_;
   nexpNode::resolved (op);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = notNode::do_not (op);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool notNode::do_not (runNode* op) {
   return !logicNode::to_bool(op);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//lthNode
lthNode::lthNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void lthNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = lthNode::do_lth (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool lthNode::do_lth (runNode *op1, runNode *op2) {
   if (dynamic_cast<regexpNode*>(op1) || dynamic_cast<regexpNode*>(op2)) {
      return (stringNode::to_str (op1) < stringNode::to_str (op2)) && !eqNode::do_eq (op1,op2);
   } 
   else if (dynamic_cast<nullNode*>(op1) || dynamic_cast<nullNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return node1->boolvalue () < node2->boolvalue();
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
   else if (dynamic_cast<logicNode*>(op1) || dynamic_cast<logicNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return node1->boolvalue () < node2->boolvalue();
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
   else if (dynamic_cast<arithNode*>(op1) || dynamic_cast<arithNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return node1->numvalue () < node2->numvalue();
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
   else if (dynamic_cast<stringNode*>(op1) || dynamic_cast<stringNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return node1->strvalue () < node2->strvalue();
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
   else if (dynamic_cast<arrayNode*>(op1) || dynamic_cast<arrayNode*>(op2)) {
      if (arrayNode *node2 = dynamic_cast<arrayNode*>(op2)){
         if (arrayNode * node1 = dynamic_cast<arrayNode*>(op1)){
            return node1->numvalue () < node2->numvalue();;
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//leqNode
leqNode::leqNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void leqNode::run () {
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = leqNode::do_leq (op1, op2);
    #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool leqNode::do_leq (runNode *op1, runNode *op2) {
   return lthNode::do_lth(op1, op2) || eqNode::do_eq(op1,op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//gthNode
gthNode::gthNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void gthNode::run () {
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = gthNode::do_gth (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool gthNode::do_gth (runNode *op1, runNode *op2) {
   return !leqNode::do_leq(op1,op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//geqNode
geqNode::geqNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void geqNode::run () {
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = geqNode::do_geq (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool geqNode::do_geq (runNode *op1, runNode *op2) {
   return !lthNode::do_lth(op1,op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//eqNode
eqNode::eqNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void eqNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = eqNode::do_eq (op1, op2);
    #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool eqNode::do_eq (runNode *op1, runNode* op2) {
   if (dynamic_cast<regexpNode*>(op1)) {
      if (dynamic_cast<regexpNode*>(op2))
         return stringNode::to_str (op1) == stringNode::to_str (op2);
      strNode str (stringNode::to_str(op2));
      matchNode m (&str, op1);
      m.run();
      return m.boolvalue();
   } 
   else if (dynamic_cast<regexpNode*>(op2)) {
      strNode str (stringNode::to_str(op1));
      matchNode m (&str, op2);
      m.run();
      return m.boolvalue();
   } 
   else if (dynamic_cast<nullNode*>(op1) || dynamic_cast<nullNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return node1->boolvalue () == node2->boolvalue();
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
   else if (dynamic_cast<logicNode*>(op1) || dynamic_cast<logicNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return node1->boolvalue () == node2->boolvalue();
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
   else if (dynamic_cast<arithNode*>(op1) || dynamic_cast<arithNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return node1->numvalue () == node2->numvalue();
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   }
   else if (dynamic_cast<stringNode*>(op1) || dynamic_cast<stringNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return node1->strvalue () == node2->strvalue();
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
   else if (dynamic_cast<arrayNode*>(op1) && dynamic_cast<arrayNode*>(op2)) {
      if (arrayNode *node2 = dynamic_cast<arrayNode*>(op2)){
         if (arrayNode * node1 = dynamic_cast<arrayNode*>(op1)){
            return node1->compare (node2);
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
   else if (dynamic_cast<arrayNode*>(op1) || dynamic_cast<arrayNode*>(op2)) {
      if (dexpNode *node2 = dynamic_cast<dexpNode*>(op2)){
         if (dexpNode * node1 = dynamic_cast<dexpNode*>(op1)){
            return false;
         }else
            throw errorException ("Unknown operand", "eqNode: node 1 is unknown operand ", 1);
      }else
         throw errorException ("Unknown operand", "eqNode: node 2 is unknown operand ", 1);
   } 
    
   
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//idenNode
idenNode::idenNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void idenNode::run () {
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = idenNode::do_iden (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool idenNode::do_iden (runNode* op1, runNode* op2) {
   if (eqNode::do_eq (op1, op2)) {
      if (dynamic_cast<nullNode*>(op1))
         return (bool)dynamic_cast<nullNode*>(op2);
      if (dynamic_cast<stringNode*>(op1))
         return (bool)dynamic_cast<stringNode*>(op2);
      else if (dynamic_cast<arithNode*>(op1))
         return (bool) dynamic_cast<arithNode*>(op2);
      else if (dynamic_cast<logicNode*>(op1))
         return (bool) dynamic_cast<logicNode*>(op2);
      else if (dynamic_cast<arrayNode*>(op1))
         return (bool) dynamic_cast<arrayNode*>(op2);
   }
   return false;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//neqNode
neqNode::neqNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void neqNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = neqNode::do_neq (op1, op2);
     #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool neqNode::do_neq (runNode* op1, runNode* op2) {
   return !eqNode::do_eq (op1, op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//nidenNode
nidenNode::nidenNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void nidenNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   boolvalue_ = nidenNode::do_niden (op1, op2);
    #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

bool nidenNode::do_niden (runNode* op1, runNode* op2) {
   return !idenNode::do_iden (op1, op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
isNullNode::isNullNode (runNode* node) : node_ (node) {}

void isNullNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   boolvalue_ = (bool)dynamic_cast<nullNode*>(node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif   
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
isBoolNode::isBoolNode (runNode* node) : node_ (node) {}

void isBoolNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   boolvalue_ = (bool)dynamic_cast<boolNode*>(node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
isStringNode::isStringNode (runNode* node) : node_ (node) {}

void isStringNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   boolvalue_ = (bool)dynamic_cast<strNode*>(node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
isNumNode::isNumNode (runNode* node) : node_ (node) {}

void isNumNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   boolvalue_ = (bool)dynamic_cast<numNode*>(node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
isArrayNode::isArrayNode (runNode* node) : node_ (node) {}

void isArrayNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   boolvalue_ = (bool)dynamic_cast<arrayNode*>(node) && !((bool)dynamic_cast<objectNode*>(node));
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
isObjectNode::isObjectNode (runNode* node) : node_ (node) {}

void isObjectNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif      
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif      
   boolvalue_ = (bool)dynamic_cast<objectNode*>(node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//addNode
addNode::addNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void addNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif         
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
      #if JSON==1
      interpreter::to_jsonRun(this);
   #endif      
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif         
   numvalue_ = addNode::do_add (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

num addNode::do_add (runNode *op1, runNode *op2) {
   return arithNode::to_num(op1) + arithNode::to_num(op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//catNode
catNode::catNode (runNode* node1, runNode*node2, bool newline):
   node1_ (node1),
   node2_(node2),
   newline_(newline) {}

void catNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   strvalue_ = catNode::do_cat (op1,op2, this->newline_);
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif
}

string catNode::do_cat (runNode *op1, runNode *op2, bool newline) {
   ostringstream oss;
   oss << stringNode::to_str(op1);
   if (newline)
     oss << endl; 
   oss << stringNode::to_str(op2);
   return oss.str();
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//sizeNode
sizeNode::sizeNode (runNode* node):
   node_ (node) {}

void sizeNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode* node = node_;
   nexpNode::resolved(node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   numvalue_ = sizeNode::do_size (node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

num sizeNode::do_size (runNode* node) {
   if (stringNode *s = dynamic_cast<stringNode*>(node))
      return s->strvalue().length();
   else if (arithNode *n = dynamic_cast<arithNode*>(node)) {
      int count = 0;
      num aux = n->numvalue();
      while (aux >= 1) {
         aux /= 10;
         count ++;
      }
      return count;
   } else if (logicNode *l = dynamic_cast<logicNode*>(node))
      return l->boolvalue();
   else if (arrayNode *a = dynamic_cast<arrayNode*>(node))
      return a->size();
   else
      throw errorException ("Unknown operand", "sizeNode: node is unknown operand ", 1);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//subNode
subNode::subNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void subNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   numvalue_ = subNode::do_sub (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

num subNode::do_sub (runNode *op1, runNode *op2) {
   return arithNode::to_num(op1) - arithNode::to_num(op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//prodNode
prodNode::prodNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void prodNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   numvalue_ = prodNode::do_prod (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

num prodNode::do_prod (runNode *op1, runNode *op2) {
   return arithNode::to_num(op1) * arithNode::to_num(op2);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//divNode
divNode::divNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void divNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (op2);
   numvalue_ = divNode::do_div (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

num divNode::do_div (runNode *op1, runNode *op2) {
   if (num op2_d = arithNode::to_num(op2))
      return arithNode::to_num(op1) / op2_d;
   throw errorException ("Division by zero", "modNode: node 2 is 0");
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//powNode
powNode::powNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void powNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   numvalue_ = powNode::do_pow (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

num powNode::do_pow (runNode *op1, runNode *op2) {
   return pow (arithNode::to_num(op1) , arithNode::to_num(op2));
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//sqrtNode
sqrtNode::sqrtNode (runNode* node):
   node_ (node) {}

void sqrtNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* op = node_;
   nexpNode::resolved (op);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   numvalue_ = sqrtNode::do_sqrt (op);
    #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif  
}

num sqrtNode::do_sqrt (runNode *op) {
   return sqrt (arithNode::to_num(op));
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//modNode
modNode::modNode (runNode* node1, runNode*node2):
   node1_ (node1),
   node2_(node2) {}

void modNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   numvalue_ = modNode::do_mod (op1, op2);
    #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

num modNode::do_mod (runNode *op1, runNode *op2) {
   if (num op2_d = arithNode::to_num(op2))
      return ((int)arithNode::to_num(op1)) % (int)op2_d;
   throw errorException ("Division by zero", "modNode: node 2 is 0");
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//incasigNode
incasigNode::incasigNode (runNode* node1):
   node1_ (node1) {}

void incasigNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (nexpNode * nexp = dynamic_cast<nexpNode*> (node1_)) {
      numNode num (1);
      addNode exp (nexp, &num);
      asigNode asig (nexp, &exp);
      asig.run ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      //~ nexp->run();
      //~ #if JSON==1
         //~ interpreter::to_jsonRun(this);
      //~ #endif
      nexp->nodeval()->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      if (arithNode *n = dynamic_cast<arithNode*>(nexp->nodeval())) {
         numvalue_ = (n->numvalue());
         #if JSON==1
            interpreter::to_jsonSetValue(this, numvalue_);
         #endif     
      } else
         throw errorException ("Unknown operand", "incasigNode: node is unknown operand ", 1);
   } else
      throw errorException ("Unknown operand", "incasigNode: node is unknown operand ", 1);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//asigincNode
asigincNode::asigincNode (runNode* node1):
   node1_ (node1) {}

void asigincNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux = node1_;
   if (nexpNode* nexp = dynamic_cast<nexpNode*>(node_aux)) {
      nexp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      node_aux = nexp->nodeval();
      if (arithNode *n1 = dynamic_cast<arithNode*>(node_aux)) {
         numvalue_ = (n1->numvalue());
      #if JSON==1
         interpreter::to_jsonSetValue(this, numvalue_);
      #endif         
         numNode num (1);
         addNode exp (node1_, &num);
         asigNode asig (node1_, &exp);
         asig.run ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      } else
         throw errorException ("Unknown operand", "asigincNode: node is unknown operand ", 1);
   } else
      throw errorException ("Unknown operand", "asigincNode: node is unknown operand ", 1);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//decasigNode
decasigNode::decasigNode (runNode* node1):
   node1_ (node1) {}

void decasigNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (nexpNode * nexp = dynamic_cast<nexpNode*> (node1_)) {
      numNode num (1);
      subNode exp (nexp, &num);
      asigNode asig (nexp, &exp);
      asig.run ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      nexp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      nexp->nodeval()->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      if (arithNode *n = dynamic_cast<arithNode*>(nexp->nodeval())) {
         numvalue_ = (n->numvalue());
      #if JSON==1
         interpreter::to_jsonSetValue(this, numvalue_);
      #endif         
      } else
         throw errorException ("Unknown operand", "decasigNode: node is unknown operand ", 1);
   } else
      throw errorException ("Unknown operand", "decasigNode: node is unknown operand ", 1);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//asigincNode
asigdecNode::asigdecNode (runNode* node1):
   node1_ (node1) {}

void asigdecNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux = node1_;
   if (nexpNode* nexp = dynamic_cast<nexpNode*>(node_aux)) {
      nexp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      node_aux = nexp->nodeval();
      if (arithNode *n = dynamic_cast<arithNode*>(node_aux)) {
         numvalue_ = (n->numvalue());
         #if JSON==1
            interpreter::to_jsonSetValue(this, numvalue_);
         #endif
         numNode num (1);
         subNode exp (node1_, &num);
         asigNode asig (node1_, &exp);
         asig.run ();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif         
      } else
         throw errorException ("Unknown operand", "asigdecNode: node is unknown operand ", 1);
   } else
      throw errorException ("Unknown operand", "asigdecNode: node is unknown operand ", 1);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//intconvNode
intconvNode::intconvNode (runNode* node): node_ (node) {}

void intconvNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* node = node_;
   nexpNode::resolved(node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   numvalue_ = intconvNode::do_intconv (node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

int intconvNode::do_intconv (runNode *node) {
   return (int)arithNode::to_num (node);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//floatconvNode
floatconvNode::floatconvNode (runNode* node): node_ (node) {}

void floatconvNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* node = node_;
   nexpNode::resolved(node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   numvalue_ = floatconvNode::do_floatconv (node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}

num floatconvNode::do_floatconv (runNode *node) {
   return (int)arithNode::to_num (node);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//boolconvNode
boolconvNode::boolconvNode (runNode* node): node_ (node) {}

void boolconvNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode* node = node_;
   nexpNode::resolved(node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   boolvalue_ = boolconvNode::do_boolconv (node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

num boolconvNode::do_boolconv (runNode *node) {
   return (bool)arithNode::to_num (node);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//strconvNode
strconvNode::strconvNode (runNode* node): node_ (node) {}

void strconvNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif       
   runNode* node = node_;
   nexpNode::resolved(node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif       
   strvalue_ = stringNode::to_str (node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getNode_strInterface
getNode_strInterface::getNode_strInterface (stringNode* node, bool is_const): refn_ (0), is_const_ (is_const), str_ (node) {
   strref_ = node->strref();
}

void getNode_strInterface::run () {
   //~ #if JSON==1
      //~ interpreter::to_jsonRun(this);
   //~ #endif
}
   
runNode* getNode_strInterface::nodeval () const {
   if (refn_ >= strref_->size()){
      return new nullNode();
   }
         //~ throw errorException ("wrong string index", "string index is out of range", 1); 
   char c[] = {(*strref_)[refn_]};
   string a (c);
   runNode *r = new strNode (a);
   #if JSON==1
      interpreter::to_jsonNewNode (r);
   #endif
   return  r;
}

void getNode_strInterface::noderef (runNode* node) {
   if (!is_const_){
      if (!ref_) ref_ = new refNode ();
      if (refn_ >= strref_->size()){
         throw errorException ("wrong string index", "string index is out of range", 1);
      }
      if (stringNode* str = dynamic_cast<stringNode*> (node)) {
         string s = str->strvalue();
         if (s.length () == 1)
            (*strref_)[refn_]  = str->strvalue()[0];
         else
            strref_->replace (refn_, 1,str->strvalue());
      }
      else if (arithNode* arith = dynamic_cast<arithNode*> (node)) {
         strNode s (arith);
         if (s.strvalue().length () == 1)
            (*strref_)[refn_]  = s.strvalue()[0];
         else
            strref_->replace (refn_, 1,s.strvalue());           
      }else if (logicNode* l = dynamic_cast<logicNode*> (node)) {
         string s = (l->boolvalue())?"1":"";
         node = nexpNode::clone (node);
         if (s.length () == 1)
            (*strref_)[refn_]  = s[0];
         else
            strref_->replace (refn_, 1,s);
      }else {
         string s = stringNode::to_str(node);
         if (s.length () == 1)
            (*strref_)[refn_]  = s[0];
         else
            strref_->replace (refn_, 1,s);
      }
      #if JSON==1
         interpreter::to_jsonChangeValue(str_, *strref_);
      #endif   
    }else{
      throw errorException ("Change reference of const node", "getNode_strInterface: node must be symbol", 1);
    }  
}

void getNode_strInterface::setn ( int n) {
   refn_ = n;
}

int getNode_strInterface::getn () const {
   return refn_;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getNode
getNode::getNode (runNode* array, runNode* key, bool resolv): array_ (array), key_ (key), next_ (NULL), exec_ (true), resolv_(resolv), is_const_ (false), functioncall_ (false) { }

void getNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   idNode* id = NULL;
   expNode * exp = NULL;
   stringNode * key_str = NULL;
   runNode *array = array_, *key = key_;
   runNode* method = NULL;
   sTable *aux = NULL;
   is_this_node_ = false;
   if (thisNode * thisn = dynamic_cast<thisNode*>(array)){
      is_this_node_ = true;
   }
   isym iter;
   if(getNode* get = dynamic_cast<getNode*>(array)) {
      get->next_ = this;
   }
   
   if (parentNode * parent = dynamic_cast<parentNode*> (array)){ //Parent
      type_ = 0;
      idNode::resolvedAsStr (key, false, !is_this_node_, NULL, true);
      nexpNode::resolved (key);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      if (runNode *r = parent->get(key)){
         noderef(r);
      #if JSON==1
         interpreter::to_jsonSetValue(this, r);
      #endif         
         functioncall_ = false;
         return;
      }else{
         thisNode thisn;
         thisn.run();
         array = dynamic_cast<arrayNode*>(thisn.nodeval());
      }
   }else {
      runNode *node_ini = array;
      idNode::resolved (array, new arrayNode ());
      nexpNode::resolved (array);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif 
      is_const_ = (node_ini == array);
      if (objectNode * obj = dynamic_cast<objectNode*> (array)){ // OBJETO DENTRO DE UN METODO DE LA MISMA CLASE 
         if (classNode* c = dynamic_cast<classNode*>(obj->getClass ())){
            if (functionNode::class_link && c->name() == functionNode::class_link->name())
               is_this_node_ = true;
            else
               aux = c->insideTable();
         }
      }      
      if (idgetNode * idget = dynamic_cast<idgetNode*>(key)){
         idget->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif         
         key = idget->getId();
      }
      idNode::resolvedAsStr (key, false, !is_this_node_, aux, !resolv_);
      nexpNode::resolved (key);
      #if JSON==1
         if (!is_this_node_)
            interpreter::to_jsonRun(this);
      #endif      
   }
   if (arrayNode * array_aux = dynamic_cast<arrayNode*> (array)) {
      type_ = 0;
      //~ if (!dynamic_cast<dataCNode*>(array)){
         //~ array_aux->run();
      //~ }
      run_case_array(array_aux, key);
   } else if(
      (exp = dynamic_cast<expNode*>(array)) &&
      (key_str = dynamic_cast<stringNode*> (key)) &&
      (method = exp->getMethod (key_str))
   ) {
      type_ = 3; //???
      noderef(method);
      #if JSON==1
         interpreter::to_jsonSetValue(this, method);
      #endif      
      objectTypeNode *obj  = NULL;
      functionNode * func = NULL;
      if ((obj = dynamic_cast<objectTypeNode*> (array)) && (func = dynamic_cast<functionNode*>(method))) {
         func->setObj (obj);
         if (classNode * c = dynamic_cast<classNode*>(obj->getClass())){
            func->setParent (c->getExtendClass ());
         }
      }
      functioncall_ = false;
   } else if (strNode* str = dynamic_cast<strNode*> (array)) {
      type_ = 1;
      run_case_str (str, key);
      functioncall_ = false;
   } else
      throw errorException ("Wrong type data", "getNode: node must be array or string", 1);
}

void getNode::run_case_array (arrayNode* array, runNode* key) { //array[x]
   if (dynamic_cast<getNode_endValue*> (key))
      key = new numNode (array->size());
   setNodeValue(array, key);
}

void getNode::run_case_str (strNode* str, runNode* num) { //string[n]
   getNode_strInterface* istr = NULL;
   if (dexpNode *exp = dynamic_cast<dexpNode*>(num)){
      //~ if (!(istr = dynamic_cast<getNode_strInterface*>(nodeval())))
          istr = new getNode_strInterface (str, is_const_);
      #if JSON==1
         interpreter::to_jsonNewNode(istr, true);
      #endif    
      istr->setn (exp->numvalue());
      istr->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      if (!ref_) {
         ref_ = new refNode("index");  
         #if JSON==1
            interpreter::to_jsonNewNode(ref_, true);
         #endif   
      }
      ref_->setRef(istr);
      #if JSON==1
         interpreter::to_jsonSetRef(this, ref_, istr);
      #endif
   }
}

void getNode::setNodeValue (arrayNode *array, runNode * key) {
   expNode * exp = NULL;
   stringNode * key_str = NULL;
   refNode* method = NULL;
   symbols *map = array->getArray ();
   bool clearfuncall = true;
   //dataCNode
   if (dataCNode * data = dynamic_cast<dataCNode*> (array)) {
      //Accede a los datos de un componente
      // Configura una llama inversa para la asignación de atributos
      data->run_get (); //llamada inversa
      data->runArray();
      data->last_access_key = key;
      defCNode * def = listC::get_defCNode (new strNode(data->getNameTable()));
      if (def && (map->find(key) != map->end())) {
         runNode *type = def->getElement (key);
         if (def = dynamic_cast<defCNode*> (type)) {
            noderef(dataCNode::getById (def, (*map)[key]));
            #if JSON==1
               interpreter::to_jsonSetValue(this, dataCNode::getById (def, (*map)[key]));
            #endif
            return;
         }
      }
   } else if (relCNode *rel = dynamic_cast<relCNode *> (array)) {
      //Accede a uno de los datos de una relación
      //Configura una llamada inversa para la asignación de un componente en la relación
      rel->run_getData (key);
   }
   if (map->find(key) != map->end()) {
      ref_ = map->findRef(key);
      #if JSON==1
         interpreter::to_jsonSetRef(this, ref_, array);
      #endif
   } 
   else if(
      (exp = dynamic_cast<expNode*>(array)) &&
      (key_str = dynamic_cast<stringNode*> (key)) &&
      (method = exp->getMethodRef (key_str))
   ) {
      #if JSON==1
         interpreter::to_jsonNewNode(method, true);
         interpreter::to_jsonNewNode(method->getRef(), true);
      #endif
      ref_ = method;
      #if JSON==1
         interpreter::to_jsonSetRef(this, ref_, array);
      #endif
   }
   else if (objectNode * obj = dynamic_cast<objectNode*>(array)){
      if (functioncall_) {
         strNode str ("_call");
         if(
            (exp = dynamic_cast<expNode*>(array)) &&
            (key_str = dynamic_cast<stringNode*> (key)) &&
            (method = exp->getMethodRef (&str))
         ) {
            ref_ = method;
            #if JSON==1
               interpreter::to_jsonSetRef(this, ref_, array);
            #endif
            clearfuncall = false;
         }
         else{
            setDefaultValue (map, key);
         }
      }else {
         strNode str ("_get");
         if(
            (exp = dynamic_cast<expNode*>(array)) &&
            (key_str = dynamic_cast<stringNode*> (key)) &&
            (method = exp->getMethodRef (&str))
         ) {
            ref_ = method;
            if (fexpNode * funget = dynamic_cast<fexpNode*> (ref_->getRef())){
               listNode l (key);
               functioncallNode f (funget, &l);
               f.run();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif
               ref_ = f.getRef();
            }
         }else{
            setDefaultValue (map, key);
         } 
      }
   }
   else {
     setDefaultValue (map, key);
   }
   if (relCNode *rel = dynamic_cast<relCNode*> (nodeval())) {
      //Accede a los datos de una relación
      //Configura una llamada inversa para la asignación de la relación
      rel->run_get ();
      stringNode *str;
      if (next_ && (str = dynamic_cast<stringNode*>(next_->key_))) {
         if (!str->is_numvalue ()) {
            rel->setWhere (next_->key_);
            next_->exec_ = false;
         }
      }
      //Realiza una busqueda para obtener la relación
      rel->processData ();
   }
   objectTypeNode *obj  = NULL;
   functionNode * func = NULL;
   if ((obj = dynamic_cast<objectTypeNode*> (array)) && (func = dynamic_cast<functionNode*>(nodeval()))) {
      func->setObj (obj);
      if (classNode * c = dynamic_cast<classNode*>(obj->getClass())){
         func->setParent (c->getExtendClass ());
      }
   }
   if (clearfuncall)
      functioncall_ = false;
}

void getNode::noderef (runNode* node) {
   if (!ref_) ref_ = new refNode();
   node->addRef();
   if (type_ == 1) {
      if (getNode_strInterface *istr = dynamic_cast<getNode_strInterface*> (ref_->getRef()))
         istr->noderef(node);
      else{
         ref_->setRef(node);
         #if JSON==1
            interpreter::to_jsonChangeRef(ref_, node);
         #endif
      }
   } else if (type_ == 3){
      ref_->setRef(node);
      #if JSON==1
         interpreter::to_jsonChangeRef(ref_, node);
      #endif
   }else {
      runNode * before = NULL;
      if (refNode *aux = noderefAnidate ()){
         ref_ = aux;
      }else{
         before = ref_->getRef();
      }
      ref_->setRef(node);
      #if JSON==1
         interpreter::to_jsonChangeRef(ref_, node);
      #endif
      if (before) before->rmRef();
   }
}

refNode * getNode::noderefAnidate (){
   if (nexpNode *nexp = dynamic_cast<nexpNode*>(array_)){
         if(refNode *ref = nexp->ref()){
            if(runNode* before = ref->getRef()){
               if (before->ref_count_ > 1 && !dynamic_cast<getiNode*>(nexp)){
                  if (arrayNode* a = dynamic_cast<arrayNode*>(before)){
                     refNode *nr = ref_;
                     arrayNode * na = new arrayNode (a, nr);
                     #if JSON==1
                        interpreter::to_jsonNewNode(na);
                        na->toJsonSymbols();
                     #endif
                     na->addRef();
                     ref->setRef (na);
                     #if JSON==1
                           interpreter::to_jsonChangeRef(ref, na);
                     #endif
                     before->rmRef();
                     return nr;
                  }else{
                     //~ cerr << "No es Array" << endl;
                  }
               }else{
                  if (getNode* lget = dynamic_cast<getNode*>(array_)){
                     refNode *newref = lget->noderefAnidate ();
                     if (newref) {
                        if (arrayNode* a = dynamic_cast<arrayNode*>(before)){
                           refNode *nr = ref_;
                           arrayNode * na = new arrayNode (a, nr);
                           #if JSON==1
                              interpreter::to_jsonNewNode(na);
                              na->toJsonSymbols();
                           #endif
                           na->addRef();
                           newref->setRef (na);
                           #if JSON==1
                                 interpreter::to_jsonChangeRef(newref, na);
                           #endif
                           return nr;
                        }else{
                           //~ cerr << "No es Array" << endl;
                        }
                     }
                     return newref;
                  }
                  if (idNode *lid = dynamic_cast<idNode*>(array_)){
                     return NULL;
                  } 
                  else{
                     //No se me ocurre el caso
                  }
               }
            }
         } 
      }else{
         //~ cerr << "CASO CONSTANTE" << endl; 
      }
      return NULL;
}

void getNode::setFunctionCall () {
      functioncall_ = true;
}

bool getNode::getFunctionCall () {
      return functioncall_;
}

void getNode::setDefaultValue (symbols *map, runNode * key){
   if (dynamic_cast<stringNode*> (key))
      key = new strNode (stringNode::to_str(key));
   runNode *value = ((this->next_)?((runNode*)new arrayNode()):((runNode*)new strNode ("")));
   value->addRef();
   (*map)[key] = value;
   
   ref_ = map->findRef(key);
}

runNode* getNode::getKey () { 
   if (idNode * id = dynamic_cast<idNode*>(key_)){
      return new strNode (id->name());
   }
   return key_; 
}

//---------------------------------------------------------------------

//----------------------------------------------------------------------
void getNode_endValue::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   }
//---------------------------------------------------------------------

//----------------------------------------------------------------------
emptyNode::emptyNode (runNode* elem): elem_(elem) {}

void emptyNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode* node_aux = elem_;
   nexpNode::resolved (node_aux);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (logicNode *b = dynamic_cast<logicNode*> (node_aux)){
      boolvalue_ = !b->boolvalue ();
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif
      }
   else if (arithNode *n = dynamic_cast<arithNode*> (node_aux)){
      boolvalue_ = !n->boolvalue ();
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif     
      } 
   else if (stringNode *str = dynamic_cast<stringNode*> (node_aux)){
      boolvalue_ = !str->boolvalue();
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif      
      }
   else if (arrayNode *a = dynamic_cast<arrayNode*> (node_aux)){
      boolvalue_ = !a->size();
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif      
      }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
ternNode::ternNode (runNode* cond, runNode* yes, runNode* no ): cond_(cond), yes_(yes), no_(no) {}

void ternNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode* cond = nexpNode::resolv(cond_);
   cond->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (logicNode::to_bool(cond)) {
      if (yes_){
         this->asig(yes_);
      }else {
         this->asig(cond, false);
      }
   }else {
      if (no_) {
         this->asig(no_);
      }else {
         runNode* b = new boolNode (false);
         this->asig(b);
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
getiNode::getiNode (runNode *node): node_ (node) {}

void getiNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *elem ;
   numNode * n_node;
   if (!node_ && iloopNode::get_ielement ())
      elem = iloopNode::get_ielement();
   else if (node_ && (n_node = dynamic_cast<numNode*>(node_)))
      elem = iloopNode::get_ielement_n(n_node->numvalue());
   else
      ;//Exc
   noderef (elem);
   #if JSON==1
      interpreter::to_jsonSetValue(this, elem);
   #endif   
   //~ this->asig(elem, false);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
execNode::execNode (runNode* node) : node_(node) {}

void execNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   string cmd = stringNode::to_str (node);
   FILE* pipe = popen(cmd.c_str(), "r");
   if (!pipe) cerr << "ERROR" << endl;
   char buffer[128];
   std::string result = "";
   while(!feof(pipe)) {
      if(fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }
   pclose(pipe);
   strvalue_ = result;
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif   
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
evalNode::evalNode (runNode* node) : node_(node) {}

void evalNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   try {
      string code = stringNode::to_str (node);
      interpreter::get()->scan_string(code.c_str());
      yyparse();
      nullNode*s = new nullNode ();
      noderef(s);
      #if JSON==1
         interpreter::to_jsonSetValue(this, s);
      #endif      
   } catch (returnException& e) {
      noderef(e.val());
      #if JSON==1
         interpreter::to_jsonSetValue(this, e.val());
      #endif
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
notnullNode::notnullNode (runNode* list) : list_(list) {}

void notnullNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (listNode *list = dynamic_cast<listNode*> (list_)) {
      runNode* key;
      list->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      vector<runNode*> v = list->listvalue ();
      vector<runNode*>::iterator iter;
      for (iter = v.begin(); iter != v.end(); iter ++) {
         key = *iter;
         nexpNode::resolved(key)->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif                                    
         if (expNode* exp = dynamic_cast<expNode*>(key)) {
            if (logicNode::to_bool(exp)) {
               //~ if (log->boolvalue()) {
                  noderef(key);
                  #if JSON==1
                     interpreter::to_jsonSetValue(this, key);
                  #endif
                  break;
               //~ }
            }
         }
      }
      if (!ref_ || !ref_->getRef()) {
         boolNode* b = new boolNode (false);
         b->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif   
         noderef(b->nodeval());
         #if JSON==1
            interpreter::to_jsonSetValue(this, b->nodeval());
         #endif
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
getEnvNode::getEnvNode (runNode* node) : node_ (node) {}

void getEnvNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode * node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   string str = stringNode::to_str (node);
   if (char* c = getenv (str.c_str())) {
      this->strvalue_ = c;
      #if JSON==1
         interpreter::to_jsonSetValue(this, this->strvalue_);
      #endif      
   }else {
      this->strvalue_ = "";
      #if JSON==1
         interpreter::to_jsonSetValue(this, this->strvalue_);
      #endif   
   }
}
//----------------------------------------------------------------------
reduceNode::reduceNode (runNode* elem, runNode* func) : elem_ (elem), func_(func) {}

void reduceNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   runNode *elem = elem_, *func = func_;
   nexpNode::resolvedAsFunction (func)->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   nexpNode::resolved (elem);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   if (arrayNode* array = dynamic_cast<arrayNode*> (elem)){
      if (functionNode* f = dynamic_cast<functionNode*> (func)){
         runNode *partial = NULL;
         symbols *m = array->getArray();
         isym i = m->begin();
         if (i != m->end()){
            partial = i.second;
            i ++;
         }
         for (;i != m->end(); ++i){
            listNode *list = new listNode (partial, i.second);
            partial = f->call (list);
            delete list;
         }
         noderef(partial);
         #if JSON==1
            interpreter::to_jsonSetValue(this, partial);
         #endif         
      }
   }else{
      throw errorException ("Unknown operand", "reduceNode: node is unknown operand ", 1); 
   }
}

runNode* reduceNode::asMethod (){
   idNode *id_func = new idNode("~func");
   listNode *params = new listNode(id_func, NULL);
   reduceNode *node = new reduceNode (new thisNode(), id_func);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
getclassNode::getclassNode (runNode* node) : node_ (node) {}

void getclassNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode * node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (objectNode * obj = dynamic_cast<objectNode*>(node)){
      if (classNode * c = dynamic_cast<classNode*>(obj->getClass())){
         strvalue_ = c->name();
         #if JSON==1
            interpreter::to_jsonSetValue(this, strvalue_);
         #endif
         return;
      }
   }
   strvalue_ = "";
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla