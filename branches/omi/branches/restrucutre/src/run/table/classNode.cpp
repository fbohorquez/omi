//classNode.cpp
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
#include "classNode.h"
#include "../tree/typeNode.h"
#include "../stmts/stmtNode.h"
#include "../operators/opNode.h"
#include "../../error.h"
#include "../../interpreter.h"
//-------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------
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
   if (idNode* id = dynamic_cast<idNode*> (id_))
      classname = id->name();
   classNode* c = this;
   sTable* aux = sTable::sTable_use;
   sTable::sTable_use = c->inside_; 
   idNode *id_aux = (idNode*)dynamic_cast<idNode*>(id_);
   strNode str = id_aux->name();
   if ( this != staticNode::link && this != functionNode::class_link && sTable::sTable_use->isPrivate (&str))
      throw errorException ("Access to private element", "idNode: element is private. ", 1);
   runNode* obj = c->toObject();
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
   return obj;
}
runNode * classNode::toObject () {
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//thisNode
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//parentNode
classNode *parentNode::link = NULL;

parentNode::parentNode () {}

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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//staticNode
runNode* staticNode::link = NULL;

staticNode::staticNode () : stmt_ (NULL) {}

staticNode::staticNode (runNode *stmt) : stmt_ (stmt) {}

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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//privateNode
bool privateNode::is = false;

privateNode::privateNode (runNode * stmt) : stmt_ (stmt) {}

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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//namespaceNode
namespaceNode::namespaceNode (runNode *space, runNode * key) : space_ (space), key_(key) {}

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
      if (!(c = dynamic_cast<classNode*>(sTable::sTable_use->getNodeUse ())))
         if (objectNode *o = dynamic_cast<objectNode*>(sTable::sTable_use->getNodeUse ()))
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
