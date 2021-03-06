//condOpNode.cpp
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
#include "condOpNode.h"
#include "../../error.h"
#include "../../interpreter.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//ternNode
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
//notnull
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


//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
