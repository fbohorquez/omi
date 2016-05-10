//sTable.h
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
/**
 * \file sTable.h
 * \brief Tabla de símbolos.
 *
 * La tabla de símbolos es una estructura de datos que contiene referencias
 * al valor de cada variable o función. Se podría decir que la
 * tabla de simbolos es un diccionario de variables.
 *
 */
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include "sTable.h"
#include "typeNode.h"
#include "stmtNode.h"
#include "../error.h"
#include "../lshParser.h"
#include "../plugin.h"
#include "../interpreter.h"
#include <semaphore.h>

//----------------------------------------------------------------------
//sTable

symbols sTable::class_;

vector<sTable*> sTable::sTables_;

sTable* sTable::sTable_use = NULL;

sTable* sTable::sTable_ini = NULL;

sTable::sTable () : level_(0), node_use_ (NULL), delete_current_level_(true) {
   symbols *level = new symbols();
   tables_.push_back (level);
}

map<runNode*, refNode*, cmp_runNode> sTable::globals_;

sTable::sTable (sTable* s) : delete_current_level_(true) {
   vector<symbols *>::iterator iter;
   symbols global = (*sTable::sTables_[0]->tables_[0]);
   for (iter = s->tables_.begin (); iter != s->tables_.end (); ++iter) {
      symbols *newmap = new symbols();
      symbols * aux = *iter;
      for ( isym m_iter = aux->begin(); m_iter != aux->end(); ++m_iter) {
         if (global.find (m_iter.first) != global.end()) {
            (*newmap)[m_iter.first] = m_iter.second;
         } else {
            if (boolNode* log = dynamic_cast<boolNode*> (m_iter.second)) {
               (*newmap)[m_iter.first] = new boolNode (log->boolvalue ());
            } else if (numNode* num = dynamic_cast<numNode*> (m_iter.second)) {
               (*newmap)[m_iter.first] = new numNode (num->numvalue ());
            } else if (strNode* str = dynamic_cast<strNode*> (m_iter.second)) {
               (*newmap)[m_iter.first] = new refNode (str->strvalue ());
            } else if (arrayNode* array = dynamic_cast<arrayNode*> (m_iter.second)) {
               (*newmap)[m_iter.first] = new arrayNode (array);
            }else if (nullNode *n = dynamic_cast<nullNode*>(m_iter.second)){
               (*newmap)[m_iter.first] = new nullNode ();
            }else {
               (*newmap)[m_iter.first] = m_iter.second;
            }
         }
      }
      tables_.push_back (newmap);
   }
   symbols functions = new symbols();
   for (isymTable m_iter = s->functions_.begin(); m_iter != s->functions_.end(); ++m_iter){
      refNode *ref = new refNode (m_iter.first);
      ref->setRef (m_iter.second);
      functions.push_back(ref);
   }
   functions_ = functions;
   class_ = s->class_;
   level_ = 0;
   node_use_ = s->node_use_;
}

void sTable::mklevel (symbols *default_level) {
   level_ ++;
   if (tables_.empty ()) {
      symbols *level_aux = new symbols();
      tables_.push_back (level_aux);
   }
   symbols *level = new symbols (default_level);
   for (map<runNode*, refNode*, cmp_runNode>::iterator iter = globals_.begin(); iter != globals_.end(); iter ++)
      (*level)[new refNode (iter->first)] = iter->second;
   tables_.push_back (level);
}

symbols* sTable::currentlevel () {
   return tables_.back();
}

void sTable::rmlevel () {
   if (delete_current_level_){
      (*tables_ [level_]).clear ();
   }else
      delete_current_level_ = true;
   tables_.pop_back ();
   if (level_)
      level_ --;
   #if JSON==1
      if (level_ + 1)
         interpreter::to_jsonRemoveLevel(level_ + 1);
   #endif
}


void sTable::add (runNode* str, runNode* node) {
   isym iter;
   if ((iter = (*tables_ [level_]).find (str)) != (*tables_ [level_]).end()){
      iter.second->rmRef();
   }
   (*tables_ [level_])[str] = node;
}

void sTable::addfunction (runNode *str, runNode* node) {
   isym iter;
   if ((iter = functions_.find (str)) != functions_.end())
      iter.second->rmRef();
   functions_ [str] = node;
}

void sTable::addclass (runNode *str, runNode* node) {
   isym iter;
   if ((iter = class_.find (str)) != class_.end())
      iter.second->rmRef();
   class_ [str] = node;
}

refNode* sTable::access (runNode *str, runNode* &key_point) {
   refNode *r = tables_ [level_]->findRef (str, new nullNode ());
   #if JSON==1
      interpreter::to_jsonAccessVar(this, level_, str, r, r->getRef());
   #endif
   return r;
}

refNode* sTable::accessfunction (runNode *str) {
   refNode *r = functions_.findRef (str, new nullNode ());
   #if JSON==1
      interpreter::to_jsonAccessFunction(this, str, r, r->getRef());
   #endif  
   return r;
}

refNode* sTable::accessclass (runNode *str) {
   refNode* r = class_.findRef (str, new nullNode ());
   #if JSON==1
      interpreter::to_jsonAccessClass(this, str, r, r->getRef());
   #endif  
   return r;
}

runNode* sTable::getFunction (runNode *key) {
   if (functions_.find (key) != functions_.end())
      return functions_[key];
   return NULL;
}
refNode* sTable::getFunctionRef (runNode *key) {
   if (functions_.find (key) != functions_.end())
      return functions_.findRef(key);
   return NULL;
}

runNode* sTable::getElement (runNode *key) {
   if (tables_[level_]->find (key) != tables_[level_]->end())
      return (*tables_[level_])[key];
   return NULL;
}
refNode* sTable::getElementRef (runNode *key) {
   
    if (tables_[level_]->find (key) != tables_[level_]->end())
      return tables_[level_]->findRef(key);
   return NULL;
}

void sTable::setFunction (runNode *key, runNode* exp) {
   functions_[key] = exp;
}

void sTable::setPrivate (runNode *str) {
   private_.push_back (str);
}

bool sTable::isPrivate (runNode *str) {
   bool resp = false;
   for (int i = 0; i < private_.size() && !resp; ++i)
      resp = (!(cmp_runNode().operator()(str, private_[i])) && !(cmp_runNode().operator()(private_[i],str))); 
   return resp;
}

bool sTable::exist (runNode *str) {
   return !(tables_ [level_]->find (str) == tables_ [level_]->end()) ;
}

bool sTable::existfunction (runNode *str) {
   return !(functions_.find (str) == functions_.end());
}

bool sTable::existclass (runNode *str) {
   isym iter;
   if ((iter = class_.find (str)) == class_.end())
      return false;
   return true;
}

void sTable::clear (runNode *str) {
   isym iter;
   if ((iter = (*tables_ [level_]).find (str)) != (*tables_ [level_]).end())
      (*tables_ [level_]).erase (iter);
}

void sTable::setNodeUse (runNode* node) {
   node_use_ = node;
}

runNode* sTable::getNodeUse () const {
   return node_use_;
}

void sTable::cAll (runNode* node_ini, runNode* node_end) {
   for (int k = 0; k < sTables_.size(); ++k) {
      isym iter;
      for (int level = 0; level < sTables_[k]->tables_.size(); level ++) {
         for (iter = sTables_[k]->tables_ [level]->begin(); iter != sTables_[k]->tables_ [level]->end(); iter++) {
            if (iter.second == node_ini) {
               iter.second = node_end;
            } else {
               if (arrayNode* array = dynamic_cast<arrayNode*> (iter.second)) {
                  array->cAll (node_ini, node_end);
               }
            }
         }
      }
   }
}

sTable* sTable::new_sTable (bool level_default) {
   sTable *s = new sTable ();
   if (!sTables_.empty ()) {
      sTable *first = sTables_[0];
      symbols *m = new symbols();
      if (level_default){
         delete m;
         m = first->tables_[0];
      }
      s->tables_[0] = m;
      s->functions_ = first->functions_;
      isym iter;
      for (iter = first->class_.begin(); iter != first->class_.end(); ++iter) {
         s->class_[iter.first] = iter.second;
      }
   }
   sTables_.push_back (s);
   return s;
}

sTable* sTable::new_sTable (sTable *s, bool level_default) {
   sTable *table;
   if (s) {
      table = new sTable (s);
   } else {
      table = new sTable ();
      if (!sTables_.empty ()) {
         sTable *first = sTables_[0];
         symbols *m = new symbols();
         if (level_default){
            delete m;
            m = first->tables_[0];
         }
         table->tables_[0] = m;
         table->functions_ = first->functions_;
         isym iter;
         for (iter = first->class_.begin(); iter != first->class_.end(); ++iter) {
            table->class_[iter.first] = iter.second;
         }
      }
   }
   sTables_.push_back (table);


   return table;
}

sTable* sTable::sys_sTable () {
   sTables_.clear();
   sTable_ini = sTable_use = new_sTable();
   return sTable_ini;
}

void sTable::add_sTable (sTable* s) {
   sTables_.push_back (s);
}

int sTable::search_sTable (sTable* s) {
   for (int i = 0; i < sTables_.size(); ++i)
      if (sTables_[i] == s)
         return i;
}

bool sTable::isref (runNode* node, int level_see) {
   isym iter;
   bool resp = false;
   for (int level = 0; level < tables_.size() && !resp; level ++) {
      for (iter = tables_ [level]->begin(); iter != tables_ [level]->end(); iter++) {
         if (level_see != level) {
            if (iter.second == node) {
               resp = true;
            } else {
               if (arrayNode* array  = dynamic_cast<arrayNode*> (iter.second)) {
                  resp = array->isref (node);
               }
            }
         }
      }
   }
   return resp;
}

bool sTable::isrefAll (runNode* node, int level_see) {
   bool resp = false;

   for (int i = 0; i < sTables_.size(); ++i) {
      isym iter;
      for (int level = 0; level < sTables_[i]->tables_.size() && !resp; level ++) {
         for (iter = sTables_[i]->tables_ [level]->begin(); iter != sTables_[i]->tables_ [level]->end(); iter++) {
            if (level_see != level || sTables_[i] != this) {
               if (iter.second == node) {
                  return true;
               } else {

                  if (arrayNode* array  = dynamic_cast<arrayNode*> (iter.second)) {
                     resp = array->isref (node);
                  }
               }
            }
         }
      }
   }

   return resp;
}

void sTable::printAll () {
   cout << "Size: " << sTables_.size() << endl;
   for (int k = 0; k < sTables_.size(); ++k) {
      isym iter;
      cout << "Tabla " << k << ":" << endl;
      for (int level = 0; level < sTables_[k]->tables_.size(); level ++) {
         cout << "Level " << level << ":" << endl;
         for (iter = sTables_[k]->tables_ [level]->begin(); iter != sTables_[k]->tables_ [level]->end(); iter++) {
            typeofNode::type (iter.second);
            cout << iter.first << " - " << iter.second;
         }
         cout << endl;
      }

   }
}

void sTable::fprintAll () {
   cout << "Size: " << sTables_.size() << endl;
   for (int k = 0; k < sTables_.size(); ++k) {
      isym iter;
      cout << "Tabla " << k << ":" << endl;
      sTables_[k]->fprint();
      cout << endl;
   }
}

void sTable::cprintAll () {
   cerr << "Size: " << sTables_.size() << endl;
   for (int k = 0; k < sTables_.size(); ++k) {
      isym iter;
      cout << "Tabla " << k << ":" << endl;
      sTables_[k]->cprint();
      cerr << endl;
   }
}

void sTable::print () {
   for (int level = 0; level < tables_.size(); level ++) {
      cout << "Level " << level << ":" << endl;
      tables_[level]->print();
   }
}

void sTable::fprint () {
   isym iter;
   for (iter = functions_.begin(); iter != functions_.end(); iter++) {
      cout << "function: " << iter.first << endl;
   }
}

void sTable::cprint () {
   isym iter;
   for (iter = class_.begin(); iter != class_.end(); iter++) {
      cout << "clase: " << iter.first << " " << iter.second << endl;
   }
}

void sTable::setGlobal (runNode* node) {
   if (idNode* id = dynamic_cast<idNode*> (node)) {
      
      globals_[new refNode (id->name())] = id->ref();
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
void idNode::run (bool resolvkey) {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   sTable *table_ = sTable::sTable_use;
   refNode *str = new refNode(id_);
   exist_ = table_->exist (str);
   ref_ = table_->access (str, key_point_);
   delete str;
   runNode *val = ref_->getRef();
   refNode * key = NULL;
   
   while ((key = dynamic_cast<refNode*>(val)) && resolvkey){
      ref_ = key;
      val = key->getRef();
   }
   if (privateNode::is){
      table_->setPrivate(new refNode (id_));
   }
   if (!ref_->isprivate_)
      ref_->isprivate_ = privateNode::is;
#if JSON==1
      interpreter::to_jsonSetValue(this, val);
#endif
}

bool idNode::exist (bool func) {
   if (!exist_){
      strNode str = id_;
      exist_ = sTable::sTable_use->exist (&str) || (func && sTable::sTable_use->existfunction (&str));
   }
   return exist_;
}
bool idNode::existfunction () {
   strNode str = id_;
   return sTable::sTable_use->existfunction (&str);
}

void idNode::runf () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif  
   strNode str = id_;
   sTable *table_ = sTable::sTable_use;
   existf_ = table_->existfunction (&str);
   reff_ = table_->accessfunction(new refNode(id_));
   if (privateNode::is) {
      table_->setPrivate(new refNode(id_));
   }
   if (!reff_->isprivate_)
      reff_->isprivate_ = privateNode::is;
}

void idNode::runc () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   sTable *table_ = sTable::sTable_use;
   strNode str = id_;
   existc_ = table_->existclass (&str);
   refc_ = table_->accessclass(new refNode (id_));
   if (privateNode::is) 
      table_->setPrivate(new refNode (id_));
   if (!refc_->isprivate_)
      refc_->isprivate_ = privateNode::is;
}
void idNode::noderef (runNode* node) {
   sTable *table_ = sTable::sTable_use;
   refNode* key = NULL;
   runNode* before = nodeval();
   node->addRef ();
   ref_->setRef(node);
   #if JSON==1
         interpreter::to_jsonChangeRef(ref_, node);
   #endif
   
   if (before) {
      before->rmRef();
   }
   #if JSON==1
         interpreter::to_jsonSetValue(this, node);
   #endif
}

void idNode::nodereff (runNode* node) {
   runNode* before = NULL;
   if (reff_){
      before = reff_->getRef();
   }
   reff_->setRef(node);
   #if JSON==1
         interpreter::to_jsonChangeRef(reff_, node);
   #endif
   if (before) {
      before->rmRef();
   }
}

void idNode::noderefc (runNode* node) {
   runNode* before = NULL;
   if (reff_){
      before = refc_->getRef();
   }
   refc_->setRef(node);
   #if JSON==1
         interpreter::to_jsonChangeRef(refc_, node);
   #endif
   if (before) {
      before->rmRef();
   }
}

void idNode::clear () {
   strNode str = id_;
   return sTable::sTable_use->clear(&str);
}

runNode* idNode::resolved (runNode* &id, runNode* default_val, bool check_private, sTable* check_table) {
   
   if (idNode *id_ = dynamic_cast<idNode*> (id)) {
      if (check_private && (!staticNode::link || staticNode::link != sTable::sTable_use->getNodeUse())) {
         strNode str = id_->name();
         if (check_table->isPrivate (&str)){
            throw errorException ("Access to private element", "idNode: element is private. ", 1);
         }
      } 
      if (!id_->exist()) {
         asigNode asig (id_, default_val);
         asig.run();
         id_->run();
      } else if (default_val)
         delete default_val;
      id_->run();
      id = id_->nodeval();
   }
   return id;
}

runNode* idNode::resolvedAsStr (runNode* &id, bool isfunc, bool check_private, sTable* check_table, bool force_str) {
   if (idNode *id_ = dynamic_cast<idNode*> (id)) {
      if (check_private && check_table && (!staticNode::link || staticNode::link != sTable::sTable_use->getNodeUse())) {
         strNode str = id_->name();
         if (check_table->isPrivate (&str)){
            throw errorException ("Access to private element", "idNode: element is private. ", 1);
         }
      } 
      if (force_str){
         id = new strNode (id_->name());
         return id;
      }
      if (!id_->exist(isfunc)) {
         id = new strNode (id_->name());
      } else {
         if (id_->existfunction () && isfunc) {
            id_->runf ();
            id = id_->nodevalf();
         } else {
            id_->run();
            id = id_->nodeval();
         }
      }
   }
   return id;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------

void idgetNode::setId () {
   runNode * aux = exp_;
   nexpNode::resolved(aux)->run();
   string name = stringNode::to_str (aux);
   if (id_) {
      delete id_;
   }
   id_ = new idNode (name);
}
void idgetNode::run (bool resolvkey) {
      setId();
      id_->run(resolvkey);
      ref_ = id_->getRef();
}

void idgetNode::runf (){
   setId();
   id_->runf();
   reff_ = id_->getReff();
}

void idgetNode::runc (){
   setId();
   id_->runc();
   refc_ = id_->getRefc();
}

void idgetNode::clear () {
   strNode str = name();
   return sTable::sTable_use->clear(&str);
}

  
  bool idgetNode::exist (bool func) {
   if (!exist_){
      strNode str = name();
      exist_ = sTable::sTable_use->exist (&str) || (func && sTable::sTable_use->existfunction (&str));
   }
   return exist_;
}
   
  bool idgetNode::existfunction () {
      strNode str = name();
      return sTable::sTable_use->existfunction (&str);
   }
   
   bool idgetNode::existf () const {
      if (id_)
         return id_->existf ();
      return false;
   }

   bool idgetNode::existc () const {
      if (id_)
         return id_->existc ();
      return false;
   }

   string idgetNode::name () const {
      runNode * aux = exp_;
      nexpNode::resolved(aux)->run();
      return stringNode::to_str (aux);
   }
   

//----------------------------------------------------------------------

//----------------------------------------------------------------------
//global node
void globalNode::run () {
    #if JSON==1
      interpreter::to_jsonRunGlobal(this);
   #endif
   if(idNode* id = dynamic_cast<idNode*>(id_)) {
      id->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      sTable::setGlobal(id);
      #if JSON==1
         interpreter::to_jsonEndGlobal(this);
      #endif
   } else {
      throw errorException ("worng identifier", "globalNode: unknown identifier", 1);
   }
}
//----------------------------------------------------------------------
//functionNode
classNode * functionNode::class_link = NULL;

functionNode::functionNode (runNode* id, runNode* params, runNode* body, bool priv):
   id_(id),
   params_(params),
   body_ (body),
   extern_s_ (sTable::sTable_ini),
   object_(NULL),
   id_save_ (NULL),
   static_link_ (NULL), parent_ (NULL), exec_ (false), level_create (NULL){
   myselft_ = new functionNode (*this);
}

void functionNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif  
   //~ if (!exec_){
      idNode* id;
      listNode *params;
      stmtNode *body;
      sTable *s_ = sTable::sTable_use;
      if (s_->getLevel()){
         level_create = s_->currentlevel();
         s_->setDeleteCurrentLevel (false);
      }
      
      if (id_ != NULL) {
         if (id = dynamic_cast<idNode*> (id_)) {
            id->runf ();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif 
            id->nodereff(this);
            id_save_ = id_;
            id_ = NULL;
         } else {
            throw errorException ("worng identifier", "functionNode: unknown identifier", 1);
         }
      }
      extern_s_ = sTable::sTable_use; // >>>>>>>>>>>>>>> AQUI PROBAR
      exec_ = true;
   //~ }
}


runNode* functionNode::call (runNode* params, sTable* context) {
   #if JSON==1
      interpreter::to_jsonRun(this, "Llamada a función '" + this->name() + "'");
   #endif
   iloopNode::push_level ();
   sTable *s_, *aux, *aux_context;
   runNode *obj = NULL, *link = NULL;
   classNode *parent = NULL, *current_class = functionNode::class_link;
   s_ = sTable::sTable_use;
   listNode *list0, *list1;
   callStack::call_push (object_, this);
   //Ejecuta parámetros
   if (params) {
      if(extern_) {
         aux = sTable::sTable_use;
         sTable::sTable_use = extern_s_;
      }
      params->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      if(extern_)
         sTable::sTable_use = aux;
   }
   s_->mklevel (level_create);
   if (params_) {
      params_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   int level = s_->getLevelTop ();
   //Copia de parámtros
   if ((list0 = dynamic_cast<listNode*> (params_)) && (list1 = dynamic_cast<listNode*> (params))) {
      if (list0->size() != list1->size()) { 
         if (list0->size () > list1->size()) { //Copia los valores por defecto que no estén 
            vector<runNode*> v0 = list0->listvalue ();
            vector<runNode*> v1 = list1->listvalue ();
            vector<runNode*>::iterator i0 = v0.begin();
            vector<runNode*>::iterator i1 = v1.begin ();
            while (i1 != v1.end()) {
               i1 ++; i0 ++;
            }
            bool ok = true;
            while (i0 != v0.end() && ok) {
               if (!dynamic_cast<asigNode*>(*i0))
                  ok = false;
               i0 ++;
            }
            if (!ok)
               throw errorException ("Number of params", "functionNode: incorrect number of parameters", 1);
         } else
            throw errorException ("Number of params", "functionNode: incorrect number of parameters", 1);
      }
      vector<runNode*> v0 = list0->listvalue ();
      vector<runNode*> v1 = list1->listvalue ();
      vector<runNode*>::iterator i0 = v0.begin();
      vector<runNode*>::iterator i1 = v1.begin ();
      while (i0 != v0.end() && i1 != v1.end()) {
         if (context){
            aux_context = sTable::sTable_use;
            sTable::sTable_use = context;
         }else
            s_->setLevel (level - 1);
         if(extern_) {
            aux = sTable::sTable_use;
            sTable::sTable_use = extern_s_;
         }
         if (idNode* id0 = dynamic_cast<idNode*> (*i0)) { //Por valor
            runNode* val = *i1;
            //~ nexpNode::resolved(val);
            //~ #if JSON==1
               //~ interpreter::to_jsonRun(this);
            //~ #endif
            if(extern_) sTable::sTable_use = aux;
            if (context)
               sTable::sTable_use = aux_context;
            else
               s_->setLevel(level);
            asigNode a (id0, val);
            a.runLevel();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif
         } else if (asigNode* as0 = dynamic_cast<asigNode*>(*i0)) { //Por valor con valores por defecto
            if (idNode* id0 = dynamic_cast<idNode*> (as0->getLeft ())) {
               runNode* val = *i1;
               nexpNode::resolved(val)->run();
               if(extern_) sTable::sTable_use = aux;
               if (context)
                  sTable::sTable_use = aux_context;
               else
                  s_->setLevel(level);
               asigNode a (id0, val);
               a.runLevel();
            }
         } else if (refparamNode* rid0 = dynamic_cast<refparamNode*> (*i0)) { //Por referencia
            if (idNode* id0 = dynamic_cast<idNode*> (rid0->getValue())) {
               if (nexpNode* id1 = dynamic_cast<nexpNode*> (*i1)) {
                  refNode *key = NULL;
                  if (idNode * id = dynamic_cast<idNode*>(id1)){
                     id->run(false);
                     if (!(key = dynamic_cast<refNode*>(id->nodeval()))){
                        key = new refNode ();
                        key->setRef (id->ref());
                     }
                  }else{
                     key = new refNode ();
                     id1->run();
                     key->setRef (id1->ref());
                  }
                  if(extern_) 
                     sTable::sTable_use = aux;
                  if (context)
                     sTable::sTable_use = aux_context;
                  else
                     s_->setLevel(level);
                  id0->run(false);
                  id0->noderef(key);
               } else {
                  throw errorException ("icorrect referer params", "functionNode: referer is const", 1);
               }
            }
         }
         i0++; i1++;
      }
   } else if ((list0 = dynamic_cast<listNode*> (params_)) && !params) { //Caso todo son valores por defecto
      vector<runNode*> v0 = list0->listvalue ();
      vector<runNode*>::iterator i0 = v0.begin();
      bool ok = true;
      while (i0 != v0.end() && ok) {
         if (!dynamic_cast<asigNode*>(*i0))
            ok = false;
         i0 ++;
      }
      if (!ok)
         throw errorException ("Number of params", "functionNode: incorrect number of parameters", 1);
   } else if (!params_ && params)
      throw errorException ("Number of params", "functionNode: incorrect number of parameters", 1);
   if (extern_)
      extern_ = false;
   //Ejecución del cuerpo de la función
   runNode * resp = NULL;
  
   if (object_){
      obj = sTable::sTable_use->getNodeUse (); //this
      sTable::sTable_use->setNodeUse (object_);
      if (objectNode* o = dynamic_cast<objectNode*> (object_))
         functionNode::class_link = dynamic_cast<classNode*>(o->getClass());
      if (classNode* c = dynamic_cast<classNode*> (object_))
          functionNode::class_link = c;
      link = staticNode::link; //static link
      staticNode::link = static_link_?static_link_:functionNode::class_link;
      parent = parentNode::link; //parent
      parentNode::link = parent_;
   }
   if (body_) {
      strNode str = (string)"_f";
      if (!sTable::sTable_use->exist(&str)) {
         idNode id_context("_f");
         id_context.run();
         asigNode b = asigNode(&id_context, this);
         b.run();
         #if JSON==1
               interpreter::to_jsonRun(this);
         #endif
      } else {
         idNode id_context("_f");
         id_context.run();
         if (!dynamic_cast<functionNode*>(id_context.nodeval())) {
            asigNode b = asigNode(&id_context, this);
            b.run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif
         }
      }
      if (runNode* run = dynamic_cast<runNode*> (body_)) { //Nodo simple
         try	{
            run->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif
         } catch (returnException& r) { //Valor devuelto
            resp = r.val();
         }
      }
   }
   s_->rmlevel ();
   if (object_){
      sTable::sTable_use->setNodeUse (obj);
      staticNode::link = link;
      parentNode::link = parent;
      functionNode::class_link = current_class;
   }
   callStack::call_pop ();
   if (!resp) 
      resp = new nullNode ();
   #if JSON==1
      if (resp) interpreter::to_jsonReturn(this, resp);
   #endif
   iloopNode::pop_level ();
   return resp;
}

void functionNode::isExtern (sTable* s) {
   extern_s_ = s;
   extern_ = true;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
bool privateNode::is = false;

void privateNode::run () {
   #if JSON==1
      interpreter::to_jsonRunPrivate(this);
   #endif
   privateNode::is = true;
   stmt_->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   privateNode::is = false;
   #if JSON==1
      interpreter::to_jsonEndPrivate(this);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
void functiongetNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (idNode* id = dynamic_cast<idNode*> (id_)) {
      id->runf();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      runNode *aux =  id->nodevalf();
      if (functionNode* f = dynamic_cast<functionNode*>(aux)) {
         f->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif
         noderef (f);
         #if JSON==1
            interpreter::to_jsonSetValue(this, f);
         #endif
      } else
         throw errorException ("wrong function", "functiongetNode: unknown function", 1);
   } else {
      throw errorException ("wrong identifier", "functiongetNode: unknown identifier", 1);
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
void functioncallNode::run (bool excep, runNode* obj, classNode* parent, sTable* context) {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   idNode *id;
   runNode *aux = id_;
   nexpNode* nexp;
   //Acceso a variables, y expresiones de tipos no definidos
   aux = idNode::resolvedAsStr (aux); 
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   if (getNode* getnode = dynamic_cast<getNode*>(aux)){
      getnode->setFunctionCall ();
      getnode->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      aux =  getnode->nodeval();
      if (getnode->getFunctionCall ()){
         params_ = new listNode (getnode->getKey(), new arrayNode (dynamic_cast<listNode*>(params_)));
      }
   }
   else if ((nexp= dynamic_cast<nexpNode*> (aux)) && !dynamic_cast<functionNode*>(aux)) {
      nexp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      aux =  nexp->nodeval();
   }
   if (functionNode *f = dynamic_cast<functionNode*>(aux)) {
      if (obj) f->setObj (obj);
      if (parent) f->setParent (parent);
      runNode * aux = f->call (params_, context);
      noderef(aux);
      #if JSON==1
         interpreter::to_jsonSetValue(this, aux);
      #endif
   } else {
      
      if (id = dynamic_cast<idNode*> (id_)) {
         
         if (id->existfunction ()) {
            
            id->runf();
            aux =  id->nodevalf();
            exec_ = true;
            if (f = dynamic_cast<functionNode*>(aux)) {
               if (obj) f->setObj (obj);
               if (parent) f->setParent (parent);
               runNode * aux = f->call (params_);
               noderef(aux);
               #if JSON==1
                  interpreter::to_jsonSetValue(this, aux);
               #endif
            }
         } else {
            listNode *list = NULL;
            listNode *resolv_list = NULL;
            if (list = dynamic_cast<listNode*> (params_)) {
               list->run();
               vector<runNode*> v = list->listvalue ();
               int n = v.size();
               for (int i = n - 1; i >= 0; --i) {
                  runNode * elem = v[i];
                  nexpNode::resolved(elem);
                  resolv_list = new listNode (elem, resolv_list);
               }
            }
            if (runNode * result = libs->get(id->name(), resolv_list)) {
               result->run();
               noderef(result);
               #if JSON==1
                  interpreter::to_jsonSetValue(this, result);
               #endif
            }else if (runNode * with = withNode::get_with ()){
               getNode * get = new getNode (with, id);
               functioncallNode *fc = new functioncallNode (get, params_);
               fc->run();
               noderef(fc->nodeval());
               #if JSON==1
                  interpreter::to_jsonSetValue(this, fc->nodeval());
               #endif
            }else if (excep) {
               throw errorException ("worng identifier", "functionNode: unknown identifier", 3);
            }
         }
      } else if (excep) {
         throw errorException ("worng identifier", "functionNode: unknown identifier", 1);
      }
   }
   
}
//----------------------------------------------------------------------
vector<callStackElement> callStack::call_stack;
int callStack::call_top = -1;
//----------------------------------------------------------------------
void returnNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* node_aux = value_;
   nexpNode::resolved(node_aux);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   
   //~ node_aux->addRef();
   //~ if (functionNode* n_fun = dynamic_cast<functionNode*>(node_aux)){
      //~ n_fun->run();
      //~ throw returnException (new functionNode (*n_fun));
   //~ }else{
      //~ node_aux->run();
      //~ throw returnException (node_aux);
   //~ }
   if (objectNode * obj = dynamic_cast<objectNode*>(node_aux))
      throw returnException (obj);
   else if (nullNode* str = dynamic_cast<nullNode*> (node_aux)) 
      throw returnException(new nullNode ());
   else if (stringNode* str = dynamic_cast<stringNode*> (node_aux)) 
      throw returnException(new strNode (str->strvalue()));
    else if (arithNode* n_arith = dynamic_cast<arithNode*> (node_aux))
      throw returnException (new numNode (n_arith->numvalue()));
   else if (logicNode* n_bool = dynamic_cast<logicNode*> (node_aux))
      throw returnException (new boolNode (n_bool->boolvalue()));
   else if (arrayNode * n_array = dynamic_cast<arrayNode*> (node_aux))
      throw returnException (new arrayNode (n_array));
   else if (functionNode* n_fun = dynamic_cast<functionNode*>(node_aux))
      throw returnException (new functionNode (*n_fun));
   else if (refNode* n_ref = dynamic_cast<refNode*>(node_aux)){
      n_ref->getRef()->ref_count_ ++;
      n_ref->ref_count_ ++;
      throw returnException (n_ref);
   }
   if (expNode* n_exp = dynamic_cast<expNode*> (node_aux)){
      throw returnException (n_exp);
   }else {
      throw returnException(new nullNode ());
   }
}
//----------------------------------------------------------------------
//classNode
sTable* classNode::static_class = NULL;

classNode::classNode (classNode* node){
   body_ = node->body_;
   inside_ = new sTable (node->inside_);
   static_ = new sTable (node->static_);
   inside_->setNodeUse (this);
   sTable::add_sTable (inside_);
   id_ = node->id_;
   extends_ = node->extends_;
   extend_class_ = node->extend_class_;
   sTable* aux = sTable::sTable_use;
   sTable::sTable_use = inside_;
   sTable::sTable_use = aux;
}

classNode::classNode (runNode* id, runNode* body, runNode* extends):
   id_ (id),
   body_(body),
   extends_ (extends),
   inside_(NULL), static_ (NULL), extend_class_ (NULL), newelement_(NULL) { }

void classNode::run () {
   #if JSON==1
      interpreter::to_jsonRunClass(this);
   #endif
   sTable *t_extends = NULL, *t_static = NULL;
   if (extends_) {
      if (idNode *id = dynamic_cast<idNode*> (extends_)) {
         id->runc ();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif
         if (classNode* c = dynamic_cast<classNode*> (id->nodevalc ())){
            #if JSON==1
               interpreter::to_jsonSetParent(this, c);
            #endif
            t_extends = c->inside_;
            t_static = c->static_;
            extend_class_ = c;
            extend_class_->newelement_ = c->newelement_;
         }
      }
   }
   sTable* aux_table = classNode::static_class;
   if (!inside_) {
      inside_ = sTable::new_sTable (t_extends, false);
   }
   if (!static_ ){
      static_ = sTable::new_sTable (t_static, false);
      classNode::static_class = static_;
   }
   if (idNode *id = dynamic_cast<idNode*> (id_)) {
      id->runc ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      if (id->existc() && dynamic_cast<classNode*>(id->nodevalc()))
         inside_ = dynamic_cast<classNode*>(id->nodevalc())->insideTable ();
      id->noderefc(this);
   }
   sTable* aux = sTable::sTable_use;
   sTable::sTable_use = inside_;
   if (extends_) {
      if (idNode *parent_construct = dynamic_cast<idNode*> (extends_)){
         if (parent_construct->existfunction ()){
            parent_construct->runf ();
            if (idNode * child_construct = (idNode*)dynamic_cast<idNode*>(id_)){
               child_construct->runf ();
               child_construct->nodereff (parent_construct->getReff()->getRef());
            }
         }
      }
   }
   if (body_) {
      body_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   #if JSON==1
      interpreter::to_jsonEndClass(this);
   #endif
   sTable::sTable_use = aux;
   classNode::static_class = aux_table;
}

runNode* classNode::newcall (runNode *params) {
   string classname = "";
   if (idNode* id = dynamic_cast<idNode*> (id_)) {
      classname = id->name();
   }
   classNode* c = this;
   sTable* aux = sTable::sTable_use;
   sTable::sTable_use = c->inside_; 
   //~ idNode *id_aux = new idNode (classname);
   idNode *id_aux = (idNode*)dynamic_cast<idNode*>(id_);
   strNode str = id_aux->name();
   if ( this != staticNode::link && this != functionNode::class_link && sTable::sTable_use->isPrivate (&str)){
      throw errorException ("Access to private element", "idNode: element is private. ", 1);
   }
   runNode* obj = c->toArray();
   if (extend_class_ && extend_class_->newelement_) {
      obj = expNode::clone(extend_class_->newelement_);
      if (objectTypeNode * o = dynamic_cast<objectTypeNode*>(obj)){
         o->setClass(this);
         obj = o;
      }
   }
   
   
   sTable::sTable_use->setNodeUse (obj);
   functioncallNode* constructor = new functioncallNode(id_aux, params);
   constructor->run(false, obj, this->getExtendClass(), aux);
   sTable::sTable_use = aux;
   //~ #if JSON==1
      //~ if (arrayNode * a = dynamic_cast<arrayNode*>(obj)){
         //~ a->toJsonSymbols();
      //~ }
   //~ #endif
   return obj;
}

runNode * classNode::toArray () {
   objectNode* obj =  new objectNode (this);
   #if JSON==1
      interpreter::to_jsonNewNode(obj);
   #endif
   symbols * st = this->inside_->getTable ();
   symbols * inside = new symbols ();
   
   #if JSON==1
      if (interpreter::get()->json)
         obj->toJsonSymbols ();
   #endif
   for (isym i = st->begin(); i != st->end(); ++i){
      refNode * r = new refNode (i.first);
      if (runNode * node = expNode::clone (i.second)){
         r->setRef (node);
         node->addRef();
         inside->push_back (r);
         #if JSON==1
            interpreter::to_jsonSymbols(obj, r, node);
         #endif
      }  
      
   }
   //~ return new objectNode (new symbols (this->inside_->getTable ()), this);
   //~ return new objectNode (inside, this);
   obj->setArray (*inside);
   return obj;
}

runNode * classNode::getMethod (runNode * key){
   return this->inside_->getFunction(key);
}

refNode * classNode::getMethodRef (runNode * key){ 
   return this->inside_->getFunctionRef(key);
}

void classNode::setMethod (runNode * key, runNode * func){
   this->inside_->setFunction(key, func);
}

runNode *classNode::getFromStatic (runNode* key) {
   sTable *aux = sTable::sTable_use;
   sTable::sTable_use = static_;
   runNode *ref = NULL;
   key->run();
   nexpNode::resolvedAsFunction (key, ref)->run();
   if (!dynamic_cast<fexpNode*> (key))
      if (refNode * r = dynamic_cast<refNode*>(ref)) 
         key = ref;
   sTable::sTable_use = aux;
   return ref?ref:key;
}

void classNode::setFromStatic (runNode *key, runNode* val) {
   sTable *aux = sTable::sTable_use;
   sTable::sTable_use = static_;
   asigNode asig (key, val);
   asig.run();
   sTable::sTable_use = aux;
}
//----------------------------------------------------------------------
//newNode

newNode::newNode (runNode* id, runNode* params):
   id_ (id),
   params_ (params) {}

void newNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   idNode* id;
   runNode *aux;
   if (id = dynamic_cast<idNode*> (id_)) {
      id->runc();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      aux =  id->nodevalc();
      if (params_) {
         params_->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif
      }
      if (classNode *c = dynamic_cast<classNode*>(aux)){
         runNode * r = c->newcall (params_);
         noderef(r);
         #if JSON==1
            interpreter::to_jsonSetValue(this, r);
         #endif
      }else
         throw errorException ("worng class identifier", "classNode: unknown identifier", 1);
   } else 
      throw errorException ("worng class identifier", "classNode: unknown identifier", 1);
}

//----------------------------------------------------------------------
//thisNode
static runNode* thisval = NULL;
void thisNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (objectNode* a = dynamic_cast<objectNode*> (sTable::sTable_use->getNodeUse ())){
      noderef(a);
      #if JSON==1
         interpreter::to_jsonSetValue(this, a);
      #endif
   }else if (runNode *nodeR = sTable::sTable_use->getNodeUse ()){
       if (!ref_) 
         ref_ = new refNode ();
      ref_->setRef(nodeR);
   }else
      throw errorException ("incorrect use of this", "thisNode: bad level", 1);
}
void thisNode::noderef (runNode* node){
      if (!ref_) {
         ref_ = new refNode ();
      }else{
         if (!dynamic_cast<objectNode*>(ref_->getRef())){
            if (dexpNode * exp = dynamic_cast<dexpNode*>(ref_->getRef())){
               exp->setNodeValue (node);
               return;
            }
         }
      }
      ref_->setRef(node);
   }
//----------------------------------------------------------------------
classNode *parentNode::link = NULL;

runNode * parentNode::get (runNode* key) {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (parentNode::link) {
      if(functionNode * f = dynamic_cast<functionNode*> (parentNode::link->getMethod (key))){
         thisNode thisn;
         thisn.run();
         f->setObj (thisn.nodeval());
         f->setParent (parentNode::link->getExtendClass());
         #if JSON==1
            interpreter::to_jsonSetValue(this, parentNode::link->getExtendClass());
         #endif
         return f;
      }else
         throw errorException ("incorrect use of parent", "parentNode: in not child", 1);
   }else
       throw errorException ("incorrect use of parent", "parentNode: in not child", 1);
}
//----------------------------------------------------------------------
runNode* staticNode::link = NULL;

void staticNode::run () {
   #if JSON==1
      interpreter::to_jsonRunStatic(this);
   #endif
   sTable* aux = NULL;
   if (classNode::static_class) {
      aux = sTable::sTable_use;
      sTable::sTable_use = classNode::static_class;
   }
   
   if (stmt_) {
      stmt_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   if (classNode::static_class) 
      sTable::sTable_use = aux;
   #if JSON==1
      interpreter::to_jsonEndStatic(this);
   #endif
}
//----------------------------------------------------------------------
void namespaceNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   classNode *c = NULL;
   runNode *static_link = NULL;
   if (idNode * id = dynamic_cast<idNode*>(space_)){
      id->runc();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      c = dynamic_cast<classNode*> (id->nodevalc());
      static_link = staticNode::link?staticNode::link:c;
   }
   else if (parentNode * parent = dynamic_cast<parentNode*> (space_)){
      callStackElement call = callStack::call_get ();
      if (!(c = dynamic_cast<classNode*>(call.obj())))
         if (objectNode *o = dynamic_cast<objectNode*>(call.obj()))
            c = dynamic_cast<classNode*>(o->getClass());
      static_link = staticNode::link?staticNode::link:c;
      c = c->getExtendClass();
   }
   else if (staticNode * st = dynamic_cast<staticNode*> (space_)){
      c = dynamic_cast<classNode*> (staticNode::link);
      static_link = staticNode::link;
   }
   if (c) {
      runNode * node = c->getFromStatic (key_);
      
      if ((node->isprivate_) && (!functionNode::class_link || functionNode::class_link !=  c )){
         throw errorException ("Access to private element", "idNode: element is private. ", 1);
      }
      if (refNode *r = dynamic_cast<refNode*>(node)) {
         ref_ = r;
      }else {
         noderef(node);
         #if JSON==1
            interpreter::to_jsonSetValue(this, node);
         #endif
      }
      if (functionNode * f = dynamic_cast<functionNode*> (ref_->getRef())){
         
         f->setObj (c);
         f->setStaticLink (static_link);
      }
   }
}

//----------------------------------------------------------------------
decoratorNode::decoratorNode (runNode* id, runNode* params, runNode* body) : functionNode (id, params, body) {
   listNode * params_dec = new listNode (new idNode ("_f"), NULL);
   runNode * body_dec = new returnNode (new functionNode (NULL, params, body));
   this->params_ = params_dec;
   this->body_ = body_dec;
}
//----------------------------------------------------------------------
void contextFunction::run () {
   idNode id("_f");
   id.run();
   setVal (id.nodeval());
}
//----------------------------------------------------------------------
partialFunctionNode::partialFunctionNode (runNode * params, runNode *id, bool isrun) : params_ (params), id_(id), isrun_(isrun) {}

void partialFunctionNode::run(){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *params = params_, *id = id_;
   listNode * pparams; functionNode *func;
   nexpNode::resolvedAsFunction (id)->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if ((pparams = dynamic_cast<listNode*>(params)) && (func = dynamic_cast<functionNode*>(id))){
      listNode *fparams = dynamic_cast<listNode*> (func->getParams());
      vector<runNode*> v_fparams = fparams->listvalue ();
      vector<runNode*> v_pparams = pparams->listvalue ();
      
		if (v_fparams.size() >= v_pparams.size()) {
         if (pparams->isAsigList () && partialFunctionNode::existAllParams(pparams, fparams)){
          
           listNode *params_no_def = dynamic_cast<listNode*> (partialFunctionNode::diffParams (pparams, fparams));
           runNode *body_func = func->getBody();
           listNode *cp_pparams = new listNode (pparams);
           functionNode *ret = new functionNode (NULL, params_no_def, body_func);
           stmtNode * stmts = new stmtNode ((runNode*)cp_pparams, (runNode*)new returnNode (ret));
           functionNode *aux = new functionNode (NULL, NULL, stmts);
           aux->run();
           #if JSON==1
               interpreter::to_jsonRun(this);
           #endif
           noderef(aux->call(NULL));
           functionNode *frun = dynamic_cast<functionNode*>(ref_->getRef());
           if (isrun_ && frun) 
               noderef(frun->call(NULL));
           return;
         }
		} else
			cerr << "Wrong number parameters" << endl;
   }
   cerr << "Error " << endl;
}

bool partialFunctionNode::existAllParams (runNode *pparams, runNode *fparams) {
   listNode *pparams_ = (dynamic_cast<listNode*>(pparams))->quitAsig ();
   listNode *fparams_ = (dynamic_cast<listNode*>(fparams))->quitAsig ();
   pparams->run();
   fparams->run();
   vector<runNode*> v_fparams_ = fparams_->listvalue ();
   vector<runNode*> v_pparams_ = pparams_->listvalue ();
   int n = v_pparams_.size();
   int m = v_fparams_.size();
   bool allexist = true;
   for (int i = 0; i < n && allexist; ++i){
      if (idNode * idp = dynamic_cast<idNode*>(v_pparams_[i])){
         idp->run();
         bool exist = false;
         for (int j = 0; j < m && !exist; ++j){
            if (idNode * idf = dynamic_cast<idNode*>(v_fparams_[j])){
               idf->run();
               exist = idp->name() == idf->name();
            }else {
               break;
            }
         }
         allexist = exist;
      }else
         allexist = false;
   }
   return allexist;
}

runNode* partialFunctionNode::diffParams (runNode *pparams, runNode *fparams) {
   listNode *pparams_ = (dynamic_cast<listNode*>(pparams))->quitAsig ();
   listNode *fparams_ = (dynamic_cast<listNode*>(fparams))->quitAsig ();
   pparams_->run();
   fparams_->run();
   vector<runNode*> v_fparams_ = fparams_->listvalue ();
   vector<runNode*> v_pparams_ = pparams_->listvalue ();
   listNode *resp = NULL;
   int n = v_fparams_.size();
   int m = v_pparams_.size();
   for (int i = 0; i < n; ++i){
      if (idNode * idf = dynamic_cast<idNode*>(v_fparams_[i])){
         idf->run();
         bool exist = false;
         for (int j = 0; j < m && !exist; ++j){
            if (idNode * idp = dynamic_cast<idNode*>(v_pparams_[j])){
               idp->run();
               exist = idp->name() == idf->name();
            }else {
               exist = false;
               break;
            }
         }
         if (!exist)
            resp = new listNode (idf, resp);
      }
   }
   return resp;
}
//----------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
