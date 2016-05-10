//funcNode.cpp
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
#include "funcNode.h"
#include "../tree/typeNode.h"
#include "../stmts/stmtNode.h"
#include "../operators/opNode.h"
#include "../../plugin.h"
#include "../../interpreter.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
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
}

void functionNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif  
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
      extern_s_ = sTable::sTable_use;
      exec_ = true;

}

string functionNode::print () const { return ""; }

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
      link = staticNode::link;
      staticNode::link = static_link_?static_link_:functionNode::class_link;
      parent = parentNode::link; 
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
      if (runNode* run = dynamic_cast<runNode*> (body_)) {
         try	{
            run->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif
         } catch (returnException& r) { 
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
   if (!resp) 
      resp = new nullNode ();
   #if JSON==1
      if (resp) interpreter::to_jsonReturn(this, resp);
   #endif
   iloopNode::pop_level ();
   return resp;
}

runNode* functionNode::getID () {
   return id_;
}

runNode* functionNode::setID (runNode* id) {
   id_ = id;
   return id;
}

string functionNode::name () {
   if (idNode * id = dynamic_cast<idNode*>(id_))
      return id->name();
   else if (idNode * id = dynamic_cast<idNode*>(id_save_))
      return id->name();
   return "";
}

runNode* functionNode::getParams () {
   return params_;
}

runNode * functionNode::getBody () {
   return body_;
}

void functionNode::setObj (runNode * obj ) {
   object_ = obj;
}

void functionNode::setStaticLink (runNode * static_link ) {
   static_link_ = static_link;
}

void functionNode::setParent (classNode * parent ) {
   parent_ = parent;
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//functioncallNode
functioncallNode::functioncallNode (runNode* id, runNode* params) : id_(id), params_(params), exec_(false) {}

void functioncallNode::run (bool excep, runNode* obj, classNode* parent, sTable* context) {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   idNode *id;
   runNode *aux = id_;
   nexpNode* nexp;
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

void functioncallNode::run () { run (true); }
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//functiongetNode
functiongetNode::functiongetNode (runNode* id) : id_(id) {}

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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//returnException
returnException::returnException (runNode* resp): resp_(resp) {}

const char* returnException::what() const throw() {
   return "return fuera de función";
}

runNode* returnException::val () const {
   return resp_;
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//returnNode
returnNode::returnNode (runNode* value): value_(value) {}

void returnNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode* node_aux = value_;
   nexpNode::resolved(node_aux);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//refparamNode
refparamNode::refparamNode (runNode* value): value_(value) {}

 void refparamNode::run () {}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//contextFunction
contextFunction::contextFunction () {}

void contextFunction::run () {
   idNode id("_f");
   id.run();
   setVal (id.nodeval());
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//partialFunction
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
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
