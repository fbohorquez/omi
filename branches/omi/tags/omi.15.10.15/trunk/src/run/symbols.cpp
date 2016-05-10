//symbols.cpp
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
#include "symbols.h"
#include "expNode.h"
#include "typeNode.h"
#include "../error.h"
//----------------------------------------------------------------------

//----------------------------------------------------------------------
symbolsTable::symbolsTable (symbolsTable* table) {
   if (table){
      for (int i = 0; i < table->table_.size(); ++i){
         refNode * ref = new refNode (table->table_[i]);
         
         ref->setRef (table->table_[i]->getRef());
         ref->getRef()->addRef ();
         table_.push_back (ref);
      }
   }
}

runNode* &symbolsTable::operator[] (refNode* key) {
   int pos = -1;
   if ( (pos = this->findPosition (key)) > -1 ) {
      return this->table_[pos]->getRef();
   }
   nullNode * null_value = new nullNode ();
   key->setRef (null_value);
   return this->push_back (key)->getRef();
}
//----------------------------------------------------------------------
runNode* &symbolsTable::operator[] (runNode* key) {
   return this->operator[](new refNode(key));
}

runNode* &symbolsTable::operator[] (int val) {
   if (val <= table_.size())
      return this->table_[val]->getRef();
   else 
      throw errorException ("Wrong index of symbols table", "symbolsTable: wrong index", 1);
}

refNode * &symbolsTable::getRef (int val){
   if (val <= table_.size())
      return this->table_[val];
   else 
      throw errorException ("Wrong index of symbols table", "symbolsTable: wrong index", 1);
}

void symbolsTable::erase (isymTable key){
   
}

refNode* symbolsTable::findRef (runNode* node, runNode* default_node) {
   refNode *ref = new refNode(node);
   for (int i = 0; i < table_.size(); ++i){
      if (!cmp_runNode().operator () (ref, table_[i]) && !cmp_runNode().operator ()(table_[i], ref)){
         if (default_node) delete default_node;
         delete ref;
         return this->table_[i];
      }
   }
   if (default_node){
      ref->setRef (default_node);
      default_node->addRef();
      return this->push_back (ref);
   }else{
      return NULL;
   }
}

void symbolsTable::insert (isymTable i, refNode * element) {
   int pos = i.getPos();
   int count = 0;
   vector<refNode*>::iterator ini = table_.begin();
   for(; count < pos && ini != table_.end(); ++ini){
      count ++;
   }
   table_.insert(ini, element);
} 
      

void symbolsTable::insert (int pos, refNode * element) {
   int count = 0;
   vector<refNode*>::iterator ini = table_.begin();
   for(; count < pos && ini != table_.end(); ++ini){
      count ++;
   }
   ini = table_.insert(ini, element);
   ++ini;
} 

void symbolsTable::erase (runNode* key) {
   int count = 0;
   int n = table_.size();
   vector<refNode*>::iterator ini = table_.begin();
   bool isnum = true;
   for(; ini != table_.end(); ++ini){
      if (isnum)
         isnum = strNode(table_[count]->getKey()).is_numvalue ();
      if (table_[count]->getKey() == stringNode::to_str (key)){
         ini = table_.erase (ini);
         if (isnum) {
            for (;count < table_.size(); ++count){
               table_[count]->setKey(numNode(strNode(table_[count]->getKey()).to_num() - 1).to_str());
            }
         }
         break;
      }
      count ++;
   }
} 
      

void symbolsTable::erase_position (unsigned int i) {
   if (i < table_.size ())
      table_.erase(table_.begin() + i);
} 
      
//----------------------------------------------------------------------

//----------------------------------------------------------------------
isymTable symbolsTable::begin () {
   return isymTable(this, 0);
}

isymTable symbolsTable::end () {
   return isymTable(this, table_.size());
}
isymTable symbolsTable::begin () const {
   return isymTable(this, 0);
}

isymTable symbolsTable::end () const {
   return isymTable(this, table_.size());
}

isymTable symbolsTable::find (runNode* node) {
   for (int i = 0; i < table_.size(); ++i){
      if (!cmp_runNode().operator () (node, table_[i]) && !cmp_runNode().operator ()(table_[i], node)){
         return isymTable (this, i);
      }
   }
   return end(); 
} 

symbolsTable symbolsTable::copyRef (symbolsTable *sym) {
   symbols resp;
   int n = sym->table_.size();
   for (int i = 0; i < n; ++i){
      refNode * r = new refNode (sym->table_[i]->strvalue());
      runNode * node = sym->table_[i]->getRef();
      node->addRef();
      r->setRef (node);
      resp.table_.push_back (r);
   }
   return resp;
}
//----------------------------------------------------------------------
runNode* symbolsTable::findKey (string key) const {
   refNode *ref = new refNode(key);
   for (int i = 0; i < table_.size(); ++i){
      if (!cmp_runNode().operator () (ref, table_[i]) && !cmp_runNode().operator ()(table_[i], ref)){
         delete ref;
         return this->table_[i]->getRef();
      }
   }
   return NULL;
}

void symbolsTable::clear () {
  
   for (int i = 0; i < table_.size(); ++i) {
      if (!dynamic_cast<refNode*>(table_[i]->getRef())) table_[i]->getRef()->rmRef();
      table_[i]->del();
   }
   table_.clear();
} 

void symbolsTable::clearRef () {
   table_.clear();
} 

void symbolsTable::print () {
   cout << "Table: " << this << endl;
   for (int i = 0; i < table_.size(); ++i ){
      if (table_[i]->getRef()){
         cout << "Ref (" << table_[i] << ") [" << table_[i]->strvalue() << "] => " 
            << table_[i]->getRef() << " [" << typeofNode::type (table_[i]->getRef()) << "]" << endl;
         }
   }
}
