//arithOpNode.cpp
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
#include "arithOpNode.h"
#include "../../error.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
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
incasigNode::incasigNode (runNode* node):
   node_ (node) {}

void incasigNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (nexpNode * nexp = dynamic_cast<nexpNode*> (node_)) {
      numNode num (1);
      addNode exp (nexp, &num);
      asigNode asig (nexp, &exp);
      asig.run ();
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
         throw errorException ("Unknown operand", "incasigNode: node is unknown operand ", 1);
   } else
      throw errorException ("Unknown operand", "incasigNode: node is unknown operand ", 1);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//asigincNode
asigincNode::asigincNode (runNode* node):
   node_ (node) {}

void asigincNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux = node_;
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
         addNode exp (node_, &num);
         asigNode asig (node_, &exp);
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
decasigNode::decasigNode (runNode* node):
   node_ (node) {}

void decasigNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (nexpNode * nexp = dynamic_cast<nexpNode*> (node_)) {
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
//asidecNode
asigdecNode::asigdecNode (runNode* node):
   node_ (node) {}

void asigdecNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux = node_;
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
         subNode exp (node_, &num);
         asigNode asig (node_, &exp);
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



//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
