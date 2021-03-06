//condStmtNode.cpp
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
#include "condStmtNode.h"
#include "../../interpreter.h"
#include "../../error.h"
#include "../tree/typeNode.h"
#include "stmtNode.h"

//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//ifnode
ifNode::ifNode (runNode* exp, runNode* ifb, runNode* elseb): 
   exp_ (exp), ifb_ (ifb), elseb_ (elseb) {}

void ifNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif      
   runNode* exp = exp_;
   nexpNode::resolved(exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif      
   bool chck = logicNode::to_bool(exp);
   if (chck && ifb_) {
      ifb_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif 
   }     
   if (!chck && elseb_){
      elseb_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif  
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//caseNode
caseNode::caseNode (runNode* exp, runNode* cb, runNode* cases):
   exp_ (exp),
   cb_ (cb),
   cases_(cases), runall_(false) {}
   
void caseNode::run (runNode* eval) {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   logicNode *l1, *l2;
   arithNode *a1, *a2;
   stringNode *s1, *s2;
   bool go = false;
   nexpNode * id = dynamic_cast<nexpNode*> (eval);
   if (id) {
      id->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif       
      eval = id->nodeval();
   }
   id = dynamic_cast<nexpNode*> (exp_);
   if (id) {
      id->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      exp_ = id->nodeval();
   }
   l1 = dynamic_cast<logicNode*> (eval);
   l2 = dynamic_cast<logicNode*> (exp_);
   a1 = dynamic_cast<arithNode*> (eval);
   a2 = dynamic_cast<arithNode*> (exp_);
   s1 = dynamic_cast<stringNode*> (eval);
   s2 = dynamic_cast<stringNode*> (exp_);
   if (s1) {
      if (s2) {
         if (s1->strvalue() == s2->strvalue()) {
            if (cb_) {
            cb_->run ();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif 
         }
         } else {
            go = true;
         }
      } else if (a2) {
         ostringstream out;
         out << a2->numvalue();
         if (s1->strvalue() == out.str()) {
            if (cb_) {
               cb_->run ();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif 
            }
         } else {
            go = true;
         }
      } else if (l2) {
         if (s1->boolvalue() == l2->boolvalue()) {
            if (cb_) {
               cb_->run ();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif 
            }
         } else {
            go = true;
         }
      } else {
         if (cb_) {
            cb_->run ();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif 
         }
      }
   } else if (a1) {
      if (s2) {
         ostringstream out;
         out << a1->numvalue();
         if (s2->strvalue() == out.str()) {
            if (cb_) {
               cb_->run ();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif 
            }
         } else {
            go = true;
         }
      } else if (a2) {
         if (a1->numvalue() == a2->numvalue()) {
            if (cb_) {
               cb_->run ();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif 
            }
         } else {
            go = true;
         }
      } else if (l2) {
         if (a1->boolvalue() == l2->boolvalue()) {
            if (cb_) {
               cb_->run ();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif 
            }
         } else {
            go = true;
         }
      } else {
         if (cb_) {
            cb_->run ();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif 
         }
      }
   } else if (l1) {
      if (s2) {
         if (l1->boolvalue() == s2->boolvalue()) {
            if (cb_) {
               cb_->run ();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif 
            }
         } else {
            go = true;
         }
      } else if (a2) {
         if (l1->boolvalue() == a2->boolvalue()) {
            if (cb_) {
               cb_->run ();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif 
            }
         } else {
            go = true;
         }
      } else if (l2) {
         if (l1->boolvalue() == l2->boolvalue()) {
            if (cb_) {
               cb_->run ();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif
            } 
         } else {
            go = true;
         }
      } else {
         if (cb_) {
            cb_->run ();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif 
         }
      }
   } else {
      if (cb_) {
         cb_->run ();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif 
      }
   }
   if (runall_ && go ) {
      cb_->run ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif 
   }
   if (caseNode * c = dynamic_cast<caseNode*> (cases_)) {
      c->runall_ = runall_?runall_:!go;
      c->run(eval);
   }
}

void caseNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   cb_->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   if (cases_){
      cases_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif 
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//switchNode
switchNode::switchNode  (runNode* eval, runNode* cases):
   eval_(eval),
   cases_ (cases) {}
 
void switchNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   eval_->run ();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   if (caseNode*c = dynamic_cast<caseNode*> (cases_)) {
      try {
         c->run (eval_);
      } catch (breakException& b) {
         b.end();
      }
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
