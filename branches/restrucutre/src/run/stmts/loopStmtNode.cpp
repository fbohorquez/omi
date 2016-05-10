//loopStmtNode.cpp
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
#include "loopStmtNode.h"
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
//whileNode

whileNode::whileNode (runNode* exp, runNode* rb): 
   exp_ (exp), rb_ (rb) {}

void whileNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   bool exit = false;
   runNode* exp = exp_;
   nexpNode::resolved(exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   try {
      while (logicNode::to_bool(exp) && !exit) {
         try {
            rb_->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif  
         } catch (continueException& c) {
            c.end();
         }
         exp = nexpNode::resolv(exp_);
         exp->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif  
      }
   } catch (breakException& b) {
      b.end();
      exit = true;
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//dowhileNode
dowhileNode::dowhileNode (runNode* exp, runNode* rb): 
   exp_ (exp), rb_ (rb) {}

void dowhileNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   bool exit = false;
   runNode* exp = exp_;
   exp = nexpNode::resolv(exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   try {
      do {
         try {
            rb_->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif             
         } catch (continueException& c) {
            c.end();
         }
         exp = nexpNode::resolv(exp_);
         exp->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif           
      } while (logicNode::to_bool(exp) && !exit);
   } catch (breakException& b) {
      b.end();
      exit = true;
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//foreachNode
foreachNode::foreachNode (
   runNode* val, 
   runNode* exp, 
   runNode* rb, 
   runNode* key
):
   val_ (val),
   exp_ (exp),
   key_ (key),
   rb_ (rb) {}

void foreachNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   runNode * exp = exp_;
   nexpNode::resolved(exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   try {
      if (numNode * n = dynamic_cast<numNode*> (exp))
         this->run_case_num (n);
      else if (arrayNode* a = dynamic_cast<arrayNode*>(exp))
         this->run_case_array (a);
      else if (stringNode* s = dynamic_cast<stringNode*>(exp)) {
         if (s->is_numvalue()) {
            numNode n (s->numvalue());
            this->run_case_num (&n);
         } else
            this->run_case_str (s);
      } else if (logicNode* l = dynamic_cast<logicNode*>(exp))
         this->run_case_bool (l);
   } catch (breakException& b) {
      b.end();
   }
}

void foreachNode::run_case_num ( numNode * n) {
   if (n->numvalue () > 0) {
      for (int i = 0; i < n->numvalue(); i+= 1) {
         numNode num ((float)i);
         asigNode (val_, &num).run();
         try {
            rb_->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif  
         } catch (continueException& c) {
            c.end();
         }
      }
   }
}

void foreachNode::run_case_str ( stringNode * s) {
   int len = s->numvalue ();
   getNode_strInterface* istr = new getNode_strInterface (s);
   for (int i = 0; i < len; i+= 1) {
      istr->setn (i);
      istr->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif       
      asigNode (val_, istr).run();   
      try {
         rb_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif  
      } catch (continueException& c) {
         c.end();
      }
   }
}

void foreachNode::run_case_bool ( logicNode * l) {
   runNode * exp = exp_;
   while (l->boolvalue ()) {
      boolNode b = boolNode (true);
      asigNode (val_, &b).run();
      try {
         rb_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif          
      } catch (continueException& c) {
         c.end();
      }
      nexpNode::resolved(exp);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      if (l = dynamic_cast<logicNode*>(exp)) {
         l->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif  
      }
      else
         break;
   }
}

void foreachNode::run_case_array ( arrayNode * a) {
   symbols *a_map = a->getArray ();
   isym m_iter;
   for (m_iter  = a_map->begin(); m_iter != a_map->end(); ++ m_iter) {
      asigNode * a = new asigNode (val_,  m_iter.second);
      a->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif        
      if (key_) {
         if (refNode * ref = dynamic_cast<refNode*>(m_iter.first)){
            strNode *str = new strNode (ref->strvalue());
            asigNode * b  = new asigNode (key_,  str);
            b->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif             
         }
      }
      try {
         rb_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif           
      } catch (continueException& c) {
         c.end();
      }
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
// foreachGeneratorNode
foreachGeneratorNode::foreachGeneratorNode (
   runNode *elem, 
   runNode* val, 
   runNode* exp, 
   runNode* rb, 
   runNode* key, 
   runNode *if_cond, 
   runNode * elem_key
):
   elem_ (elem),
   elem_key_ (elem_key),
   if_cond_ (if_cond),
   val_ (val),
   exp_ (exp),
   key_ (key),
   rb_ (rb) {}

void foreachGeneratorNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   runNode * exp = exp_;
   nexpNode::resolved(exp);
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   if (numNode * n = dynamic_cast<numNode*> (exp))
      this->run_case_num (n);
   else if (arrayNode* a = dynamic_cast<arrayNode*>(exp))
      this->run_case_array (a);
   else if (stringNode* s = dynamic_cast<stringNode*>(exp))
      this->run_case_str (s);
   else if (logicNode* l = dynamic_cast<logicNode*>(exp))
      this->run_case_bool (l);
}

void foreachGeneratorNode::run_case_num ( numNode * n) {
   if (n->numvalue () > 0) {
      for (int i = 0; i < n->numvalue(); i+= 1) {
         numNode num ((float)i);
         asigNode (val_, &num).run();
         if (rb_) {
            rb_->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif 
         }  
         this->generator ();
      }
   }
}

void foreachGeneratorNode::run_case_str ( stringNode * s) {
   int len = s->numvalue ();
   getNode_strInterface* istr = new getNode_strInterface (s);
   for (int i = 0; i < len; i+= 1) {
      istr->setn (i);
      istr->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif        
      asigNode (val_, istr).run();    
      if (rb_) {
         rb_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif   
      }     
      this->generator ();
   }
}

void foreachGeneratorNode::run_case_bool ( logicNode * l) {
   runNode * exp = exp_;
   int i = 0;
   while (l->boolvalue ()) {
      numNode b = numNode (i);
      asigNode (val_, &b).run();    
      nexpNode::resolved(exp);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif        
      if (l = dynamic_cast<logicNode*>(exp)){
         l->run(); 
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif          
         if (l->boolvalue()){
            if (rb_) {
               rb_->run();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif   
           }               
            this->generator ();
         }
      }else
         break;
       ++i;
   }
}

void foreachGeneratorNode::run_case_array ( arrayNode * a) {
   symbols *a_map = a->getArray ();
   isym m_iter;
   for (m_iter  = a_map->begin(); m_iter != a_map->end(); ++ m_iter) {
      asigNode (val_, m_iter.second).run();
      if (key_) 
         asigNode (key_, new strNode(m_iter.first->strvalue())).run();
      if (rb_) {
         rb_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif    
      }  
      this->generator ();
   }
}

void foreachGeneratorNode::generator () {
   bool ch = true;
   if (if_cond_) {
      runNode * if_ =  if_cond_;
      nexpNode::resolved (if_);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif   
      ch = logicNode::to_bool (if_);
   }
   if (ch && dynamic_cast<expNode*> (elem_)) {
      runNode *elem = elem_;
      runNode * key = elem_key_;
      expNode * e, *ek;
      nexpNode::resolved(elem);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif   
      if (key){
         nexpNode::resolved(key);
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif   
      }          
      else
         key = new numNode(this->getCount());
      if (
         (e = dynamic_cast<expNode*> (elem)) && 
         (ek = dynamic_cast<expNode*> (key))
      ) {
         this->insert (ek, nexpNode::clone(e) );
      }
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//iloopNode
vector <runNode*> iloopNode::ielement;
int iloopNode::icount = 0;

vector<int> iloopNode::stack_icount;
vector<vector<runNode*> > iloopNode::stack_ielement;

iloopNode::iloopNode (
   runNode* iter, 
   runNode* stmt, 
   runNode *id, 
   runNode *second_id, 
   runNode *inc
):
   iter_ (iter),
   stmt_ (stmt),
   id_ (id),
   second_id_ (second_id),
   inc_ (inc) {}

runNode * iloopNode::get_ielement () {
   if (iloopNode::icount > 0) {
      runNode* node = iloopNode::ielement[iloopNode::icount - 1];
      return node;
   }
   return NULL;
}

runNode * iloopNode::get_ielement_n (int i) {
   if (i >= 0 && i < iloopNode::icount)
      return iloopNode::ielement[i];
   throw errorException (
      "Wrong index", "get_ielement_n: overflow iloop cache", 
      1
   );
}

runNode * iloopNode::set_ielement (runNode* node) {
   runNode * back = iloopNode::pop_ielement();
   iloopNode::push_ielement (node);
   return back;
}

runNode * iloopNode::push_ielement (runNode* node) {
   node->addRef();
   iloopNode::ielement.push_back (node);
   iloopNode::icount ++;
}

runNode * iloopNode::pop_ielement () {
   runNode * back = iloopNode::ielement.back();
   iloopNode::icount --;
   iloopNode::ielement.pop_back ();
   return back;
}

void iloopNode::push_level () {
   iloopNode::stack_ielement.push_back (iloopNode::ielement);
   iloopNode::stack_icount.push_back (icount);
   ielement = vector <runNode*> ();
   icount = 0;
}

void iloopNode::pop_level () {
   iloopNode::ielement = iloopNode::stack_ielement.back ();
   iloopNode::icount = iloopNode::stack_icount.back ();
   iloopNode::stack_ielement.pop_back ();
   iloopNode::stack_icount.pop_back ();
}

void iloopNode::run () {
    #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode * iter = iter_;
   nexpNode::resolved(iter);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif  
   try {
      if (numNode * n = dynamic_cast<numNode*> (iter))
         this->run_case_num (n);
      else if (arrayNode* a = dynamic_cast<arrayNode*>(iter))
         this->run_case_array (a);
      else if (stringNode* s = dynamic_cast<stringNode*>(iter))
         this->run_case_str (s);
      else if (logicNode* l = dynamic_cast<logicNode*>(iter))
         this->run_case_bool (l);
   } catch (breakException& b) {
      b.end();
   }
}

void iloopNode::run_case_num ( numNode * n) {
   if (n->numvalue () > 0) {
      runNode * inode =  new numNode ((float)0);
      iloopNode::push_ielement (inode);
      int inc = (
         (inc_)
         ?arithNode::to_num (nexpNode::resolv(inc_), true)
         :(num) 1
      );
      for (int i = 0; i < n->numvalue(); i+= inc) {
         numNode *num = new numNode ((float)i);
         this->setId (num);
         iloopNode::set_ielement (num);
         try {
            stmt_->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif  
         } catch (continueException& c) {
            if (!c.islast()) {
               iloopNode::pop_ielement();
            }
            c.end();
         }
         delete num;
      }
      iloopNode::pop_ielement();
   }
}

void iloopNode::run_case_str ( stringNode * s) {
   int len = s->numvalue ();
   if (
      stringNode* sep = 
         dynamic_cast<stringNode*>(nexpNode::resolv(inc_))
   ) {
      explodeNode* expl = new explodeNode (sep,  s);
      expl->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif       
      if (arrayNode* a = dynamic_cast<arrayNode*>(expl->nodeval()))
         return this->run_case_array (a);
   }
   int inc = (
      (inc_)
      ?arithNode::to_num (nexpNode::resolv(inc_), true)
      :(num)1
   );
   getNode_strInterface* istr = new getNode_strInterface (s);
   for (int i = 0; i < len; i+= inc) {
      istr->setn (i);
      istr->run();
      this->setId (istr);
      if (!i)
         iloopNode::push_ielement (istr);
      else
         iloopNode::set_ielement (istr);
      try {
         stmt_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif  
      }catch (continueException& c) {
         if (!c.islast()) 
            iloopNode::pop_ielement();
         c.end();
      }
   }
   if (len) iloopNode::pop_ielement();
}

void iloopNode::run_case_bool ( logicNode * l) {
   iloopNode::push_ielement (l);
   while (l->boolvalue ()) {
      try {
         stmt_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif           
      }
      catch (continueException& c) {
         if (!c.islast()) 
            iloopNode::pop_ielement();
         c.end();
      }
      l->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif  
      this->setId (l);
      iloopNode::set_ielement (l);
   }
   iloopNode::pop_ielement();
}

void iloopNode::run_case_array ( arrayNode * a) {
   symbols *a_map = a->getArray ();
   isym m_iter;
   int inc = (
      (inc_)
      ?arithNode::to_num (nexpNode::resolv(inc_), true)
      :(num)1
   );
   
   for (m_iter  = a_map->begin(); m_iter != a_map->end(); ) {
      if (m_iter == a_map->begin())
         iloopNode::push_ielement (m_iter.second);
      else
         iloopNode::set_ielement (m_iter.second);
      this->setId (m_iter.second);
      this->setId (m_iter.first, true);
      try {
         stmt_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif  
      } catch (continueException& c) {
         if (!c.islast()) iloopNode::pop_ielement();
         c.end();
      }
      for (int i = 0; i < inc; ++i) m_iter ++;
   }
   if (m_iter != a_map->begin()) iloopNode::pop_ielement();
}

void iloopNode::setId (runNode * node, bool second) {
   if (
      idNode* id = 
         dynamic_cast<idNode*> ((!second)?id_:second_id_)
   ) {
      asigNode* asig = new asigNode (id, node);
      asig->run ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif  
      delete asig;
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//incloopNode
incloopNode::incloopNode (
   runNode* id, 
   runNode* max, 
   runNode* stmt
):
   id_ (id),
   max_ (max),
   stmt_ (stmt) {}

void incloopNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   idNode* id = dynamic_cast<idNode*> (id_);
   runNode *exp;
   if (id) exp = nexpNode::resolv(id);
   asigNode* asig = NULL;
   if (numNode* max = dynamic_cast<numNode*> (max_)) {
      num ini = arithNode::to_num (id?exp:id_, false);
      runNode * inode =  new numNode ((float)ini);
      if (id) {
         asig = new asigNode (id, inode);
         asig->run ();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif           
      }
      iloopNode::push_ielement (inode);
      for (int i = ini; i < max->numvalue(); ++i) {
         numNode *num = new numNode ((float)i);
         if (id) {
            asig = new asigNode (id, num);
            asig->run ();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif              
         }
         iloopNode::set_ielement (num);
         stmt_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif         
      }
      iloopNode::pop_ielement();
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//continueNode
continueNode::continueNode (int n): n_ (n) {}

void continueNode::run () { 
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   throw continueException(n_); 
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//continueException
continueException::continueException (int n ): n_(n) {}

const char* continueException::what() const throw() {
   return "Continue fuera de bloque.";
}

void continueException::end () {
   if (n_ != 1) throw continueException (n_ - 1);
}
bool continueException::islast () {
   return n_ == 1;

}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//forNode
forNode::forNode (
   runNode* asig, 
   runNode* exp, 
   runNode* inc, 
   runNode* rb
):
   asig_ (asig),
   exp_ (exp),
   inc_ (inc),
   rb_ (rb) {}
   
void forNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   asig_->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif     
   runNode* exp = exp_;
   if (exp) {
      nexpNode::resolved(exp);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif        
      try {
         while (logicNode::to_bool(exp)) {
            try {
               if (rb_) {
                  rb_->run();
                  #if JSON==1
                     interpreter::to_jsonRun(this);
                  #endif
               }  
            } catch (continueException&c) {
               c.end();
            }
            inc_->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif  
            exp = nexpNode::resolv(exp_);
            exp->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif              
         }
      } catch (breakException& b) {
         b.end();
      }
   } else
      cerr << "Tipos incorrectos" << endl;
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
