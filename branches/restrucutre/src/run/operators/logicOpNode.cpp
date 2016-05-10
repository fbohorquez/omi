//logicOpNode.cpp
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
#include "logicOpNode.h"
//~ #include "stmtNode.h"
#include "../../error.h"
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------

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
//isNullNode
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
//isBoolNode
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
//isStringNode
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
//isNumNode
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
//isObjectNode
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
//emptyNode
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
