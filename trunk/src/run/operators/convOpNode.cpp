//convOpNode.cpp
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
#include "convOpNode.h"
#include "../../interpreter.h"
#include "../../error.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
