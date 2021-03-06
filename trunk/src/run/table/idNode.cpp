//idNode.cpp
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

//-------------------------------------------------------------------------------------------
#include "idNode.h"
#include "classNode.h"
#include "../tree/typeNode.h"
#include "../operators/opNode.h"
#include "../../error.h"
#include "../../interpreter.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//idnode
idNode::idNode (string id):id_(id), exist_(false), key_point_(NULL) { }

void idNode::run () { run (true);} 

void idNode::run (bool resolvkey) {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   sTable *table_ = sTable::sTable_use;
   refNode *str = new refNode(id_);
   exist_ = table_->exist (str);
   ref_ = table_->access (str);
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

refNode* idNode::getRef () const {
   
   return ref_;
}

refNode* idNode::getReff () const {
   
   return reff_;
}

refNode* idNode::getRefc () const {
   
   return refc_;
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//idgetNode
idgetNode::idgetNode (runNode *exp):exp_(exp), id_(NULL), idNode (""){ }

void idgetNode::run () { run (true);} 

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
   
idNode* idgetNode::getId () { return id_; }
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//global node
globalNode::globalNode (runNode* id) : id_(id) {}

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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
