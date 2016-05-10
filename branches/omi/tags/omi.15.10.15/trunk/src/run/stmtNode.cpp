//stmtNode.cpp
//----------------------------------------------------------------------
/*
 * Fco. Javier Bohórquez Ogalla
 * 75766599-E
 * Puerto Real (Cádiz)
 * powersgame@gmail.com
 */
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
#include "stmtNode.h"
#include "operatorStrNode.h"
#include "interpreter.h"
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//noNode

noNode::noNode () {}

void noNode::run () {}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//breakException

breakException::breakException (int n): n_(n) {}

const char* breakException::what() const throw() {
   return "Break fuera de bloque.";
}

void breakException::end () {
   if (n_ != 1) throw breakException (n_ - 1);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//breakNode

breakNode::breakNode (int n): n_ (n) {}

void breakNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   throw breakException(n_);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//continueNode
continueNode::continueNode (int n): n_ (n) {}

void continueNode::run () { 
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   throw continueException(n_); 
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//exitNode
void exitNode::run () {
   #if JSON==1
      if (interpreter::get()->json){
         interpreter::to_jsonRun(this); 
         interpreter::jsonEnd();
      }
   #endif 
   exit (0);
   
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//gotoException
const char* gotoException::what() const throw() {
   return "goto exception";
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//printNode

printNode::printNode (runNode* exp, bool newline): 
   exp_ (exp), newline_(newline) {}

void printNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   printableNode *pn;
   runNode *aux;
   arrayNode *a;
   if (exp_) {
      aux = exp_;
      nexpNode::resolved (aux);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      if (objectNode* obj = dynamic_cast<objectNode*>(aux)){
         cout << stringNode::to_str(obj);
         #if JSON==1
            interpreter::to_jsonOut(this, stringNode::to_str(obj) + (newline_?"\n":""));
         #endif
      }
      else if (
         (pn = dynamic_cast<printableNode*>(aux)) && 
         !((bool)dynamic_cast<nullNode*>(aux))
      ) {
         cout << pn->print ();
         #if JSON==1
            interpreter::to_jsonOut(this, pn->print ()  + (newline_?"\n":""));
         #endif
      }
      if (newline_){
            cout << endl;
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//inputNode
inputNode::inputNode (idNode* id, int type, runNode* prompt): 
   id_(id), type_ (type), prompt_ (prompt) {}

void inputNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   string aux0, aux1;
   char c, e;
   if (prompt_) {
      runNode *prompt = prompt_;
      nexpNode::resolved(prompt);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      ostringstream oss;
      if (stringNode *s = dynamic_cast<stringNode*>(prompt)) {
         oss << s->strvalue ();
      } else if (arithNode *n = dynamic_cast<arithNode*>(prompt)) {
         oss << n->numvalue ();
      } else if (logicNode *l = dynamic_cast<logicNode*>(prompt)) {
         oss << l->boolvalue ();
      } else {
         throw errorException (
            "Wrong data type", "inputNode: prompt is a wrong type", 
            1
         );
      }
      cout << oss.str();
      #if JSON==1
         interpreter::to_jsonOut(this, oss.str() + ((type_ == 1)?" ":"\n"));
      #endif
      switch (type_) {
      default:
      case 0:
         cout << endl;
         break;
      case 1:
         cout << " ";
         break;
      }
   }
   #if JSON==1
   if(interpreter::get()->json) {
      aux0 = interpreter::to_jsonInput(this);
   }else {
   #endif
      switch (type_) {
         default:
         case 0:
            getline(cin, aux0);;
            while (true) {
               getline(cin, aux1);
               if (aux1.empty()) {
                  break;
               } else {
                  aux0 += ('\n' + aux1);
               }
            }
            break;
         case 1:
            getline(cin, aux0);
            break;
      }
   #if JSON==1
   }
   #endif
   strNode s (aux0);
   asigNode asig (id_, &s);
   asig.run ();    
   strvalue_ = aux0;
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif    
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
   relCNode *rel;
   dataCNode *data;
   defCNode *def;
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
   else if (def = dynamic_cast<defCNode*>(r))
      os << "DefC (" << def->getArray()->size() << ")" ;
   else if (data = dynamic_cast<dataCNode*>(r))
      os << "DataC (" << data->getArray()->size() << ")" ;
   else if (rel = dynamic_cast<relCNode*>(r))
      os << "RelC (" << rel->getArray()->size() << ")" ;
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//throwException

throwException::throwException (runNode* resp): resp_(resp) {}

const char* throwException::what() const throw() {
   return "throw statement out of try block";
}
 
runNode* throwException::val () const {
   return resp_;
}  
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Fco. Javier Bohórquez Ogalla