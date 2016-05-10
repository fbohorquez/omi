//symbols.h
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
 * \file symbols.h
 * \brief Tabla de símbolos
 *
 */
//----------------------------------------------------------------------
#ifndef _SYMBOLS_
#define _SYMBOLS_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <vector>
#include <iostream>
#include "runTree.h"
using namespace std;
//----------------------------------------------------------------------

class isymTable;
//----------------------------------------------------------------------
class symbolsTable {
   public:
      symbolsTable () {}
      symbolsTable (const symbolsTable* table) : table_(table->table_) {}
      symbolsTable (symbolsTable* table);
      refNode* &push_back (refNode* node) {
         table_.push_back (node);
         return table_.back();
      } 
      void pop_back () {
         if (table_.size() > 0)
            table_.pop_back ();
      }
      static symbolsTable copyRef (symbolsTable *sym);
      isymTable begin ();
      isymTable end ();
      isymTable begin () const;
      isymTable end () const;
      isymTable find (runNode* node); 
      refNode* findRef (runNode* node, runNode* default_node = NULL); 
      int findPosition (refNode* node) {
         for (int i = 0; i < table_.size(); ++i){
            if (!cmp_runNode().operator () (node, table_[i]) && !cmp_runNode().operator ()(table_[i], node))
               return i;
         }
         return -1; 
      } 
      void clear ();
      void clearRef ();
      bool empty () {
         return table_.empty();
      }
      int size () const {
         return table_.size();
      }
     runNode* &operator[] (const string key) {
         refNode *ref = new refNode(key);
         return this->operator[] (ref);
      }
     runNode* findKey (string key) const;
      runNode* &operator[] (refNode* key);
      runNode* &operator[] (runNode* key);
      runNode* &operator[] (int val);
      refNode * &getRef (int val) ;
      void erase (runNode* key);
      void erase_position (unsigned int i);
      void erase (isymTable key);
      void print ();
      refNode* last () {
         return table_.back();
      }
      refNode* first () {
         if (table_.size())
            return table_.front();
         else
            return NULL;
      }
      void insert (isymTable i, refNode * element); 
      void insert (int pos, refNode * element); 
   private:
      vector<refNode*> table_;
};

class isymTable {
   public:
      isymTable () : sym_ (NULL), pos_ (-1), first(NULL), second(NULL) {}
      isymTable (symbolsTable* sym, unsigned int pos) : sym_ (sym), pos_ (pos), first(NULL), second(NULL) {
         setPair();
      }
      isymTable (const symbolsTable* sym , unsigned int pos) : sym_ (new symbolsTable(sym)), pos_ (pos), first(NULL), second(NULL) {
         setPair();
      }
      bool operator==(const isymTable &elem) const {
         return (elem.pos_ == this->pos_);
      }
      bool operator!=(const isymTable &elem) const {
         return (elem.pos_ != this->pos_);
      }
      isymTable& operator++() {
         this->pos_ ++;
         setPair();
         return *this;
      }
      isymTable& operator--() {
         this->pos_ --;
         setPair();
         return *this;
      }
 
      isymTable operator++(int) {
         this->pos_ ++;
         setPair();
         return *this;
      }
      isymTable operator--(int){
         this->pos_ --;
         setPair();
         return *this;
      }
      string print () {
         cerr << pos_ << endl;
      }
      unsigned int getPos () { return pos_;}
      refNode *first;
      runNode * second;
   private:
      void setPair () {
         if (pos_ < sym_->size () && (first = sym_->getRef(pos_)))
            second = first->getRef();
      }
      symbolsTable* sym_; 
      unsigned int pos_;
   
};
//----------------------------------------------------------------------
typedef symbolsTable symbols;
typedef isymTable isym;
//----------------------------------------------------------------------
#endif


