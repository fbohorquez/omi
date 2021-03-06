//sTable.h
//-------------------------------------------------------------------------------------------
/*
 * Fco. Javier Bohórquez Ogalla
 * 75766599-E
 * Puerto Real (Cádiz)
 * powersgame@gmail.com
 */
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
/**
 * \file sTable.h
 * \brief Tabla de símbolos.
 *
 * La tabla de símbolos es una estructura de datos que contiene referencias
 * al valor de cada variable o función. Se podría decir que la
 * tabla de simbolos es un diccionario de variables.
 *
 */
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#include "sTable.h"
#include "../tree/typeNode.h"
#include "../../interpreter.h"

//-------------------------------------------------------------------------------------------
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

refNode* sTable::access (runNode *str) {
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

int sTable::getLevel () const {
   return level_;
}

int sTable::getLevelTop () const {
   return tables_.size() - 1;
}

void sTable::setLevel (int l) {
   level_ = l;
}

void sTable::clear (runNode *str) {
   (*tables_ [level_]).erase (str);
}

void sTable::setNodeUse (runNode* node) {
   node_use_ = node;
}

runNode* sTable::getNodeUse () const {
   return node_use_;
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
   return -1;
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

symbols * sTable::getTable () {
   return tables_ [level_];
}

symbols sTable::getFunctions () {
   return functions_;
}

void sTable::setGlobal (runNode* node) {
   if (idNode* id = dynamic_cast<idNode*> (node)) {
      
      globals_[new refNode (id->name())] = id->ref();
   }
}

void sTable::setDeleteCurrentLevel (bool del) {
   delete_current_level_ = del;
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
