//typeNode.cpp
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
#include "typeNode.h"
#include "stmtNode.h"
#include "componentNode.h"
#include "operatorArrayNode.h"
#include "interpreter.h"

//----------------------------------------------------------------------
//boolNode
boolNode::boolNode (bool data) {
   boolvalue_ = data;
}

void boolNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//numNode
numNode::numNode (string data) {
   std::istringstream inpStream(data);
   num inpValue = 0.0;
   if (inpStream >> inpValue) 
      numvalue_ = atof (data.c_str());
   else 
      numvalue_ = data.length();
}

numNode::numNode (numNode* data){
   if (data)
      numvalue_ = data->numvalue();
}

numNode::numNode (num data){
   if (data == -0) data = 0;
   numvalue_ = data;
}

void numNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//listNode
void listNode::run () {
   #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   exec_ = true;
   list_.clear();
   vector<runNode*> aux;
   vector<runNode*>::iterator iter;
   listNode *l;
   if (ele1_ && ele1_->is_runlist()){ 
      ele1_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   if (ele2_ && ele2_->is_runlist()){ 
      ele2_->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   if (ele1_) {
      if (l = dynamic_cast<listNode*> (ele1_)) {
         aux = l->listvalue ();
         for (iter = aux.begin(); iter != aux.end(); ++iter)
            list_.insert (list_.end(), *iter);
      } else
         list_.insert (list_.end(), ele1_);
   }
   if (ele2_) {
      if (l = dynamic_cast<listNode*> (ele2_)) {
         aux = l->listvalue ();
         for (iter = aux.begin(); iter != aux.end(); ++iter)
            list_.insert (list_.end(), *iter);
      } else
         list_.insert (list_.end(), ele2_);
   }
}

int listNode::size () {
   return list_.size ();
}

vector<runNode*> listNode::listvalue () const {
   return list_;
}

void listNode::print () const {
   vector<runNode*> v = this->listvalue ();
   int n = v.size();
   for (int i = 0; i < n ; ++i) 
      cerr << typeofNode::type(v[i]) << endl;
}

bool listNode::isAsigList () {
   vector<runNode*> v = this->listvalue ();
   int n = v.size();
   bool is = true;
   for (int i = 0; i < n && is; ++i) 
      is = (bool)dynamic_cast<asigNode*>(v[i]);
   return is;
}

listNode* listNode::quitAsig () {
   this->run();
   vector<runNode*> v = this->listvalue ();
   int n = v.size();
   bool is = true;
   listNode * resp = NULL;
   for (int i = 0; i < n && is; ++i) {
      if (asigNode* a = dynamic_cast<asigNode*>(v[i])){
         resp = new listNode (a->getLeft(), resp);
      }else{
          resp = new listNode (v[i], resp);
      }
   }
   return resp;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
strNode::strNode (string data) {
   int pos = 0;
   while ((pos = data.find ("\\n", pos)) != string::npos) {
      data = data.replace (pos, 2, 1,'\n');
   }
   pos = 0;
   while ((pos = data.find ("\\\"", pos)) != string::npos) {
      data = data.replace (pos, 2, 1,'"');

   }
   pos = 0;
   while ((pos = data.find ("\\\'", pos)) != string::npos) {
      data = data.replace (pos, 2, 1,'\'');

   }
   strvalue_ = data;
}

strNode::strNode (strNode* data) {
   if (data) 
      strvalue_ = data->strvalue();
}
strNode::strNode (runNode* data, bool id ) {
   if (idNode *id = dynamic_cast<idNode*> (data)) 
      strvalue_ = id->name ();
}
strNode::strNode (runNode* data) {
   runNode* node_aux = data;
   nexpNode::resolved(node_aux)->run();
   if (dexpNode *node = dynamic_cast<dexpNode*>(node_aux))
      strvalue_ = node->strvalue();
   else 
      throw errorException ("Wrong conversion", "strNode: wrong node type", 1);
}
void strNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
nullNode::nullNode () {}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//mapNode
mapNode::mapNode (runNode* key, runNode* value):key_ (key), value_(value) {}

void mapNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (key_ && !dynamic_cast<idNode*>(key_)) {
      key_->run ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   if (value_){ 
      value_->run ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
}

runNode* mapNode::key () const {
   return key_;
}

runNode* mapNode::value () const {
   return value_;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arrayNode
classNode *arrayNode::class_ = NULL;
void arrayNode::generateClass  () {
   idNode *id = new idNode ("arrayClass");
   classNode * c = new classNode (id, NULL);
   c->run();
   
   c->setMethod (new strNode("reduce"), reduceNode::asMethod());
   c->setMethod (new strNode("last"), arraylastNode::asMethod());
   c->setMethod (new strNode("first"), arrayfirstNode::asMethod());
   c->setMethod (new strNode("insert"), arrayinsertNode::asMethod());
   c->setMethod (new strNode("delete"), arraydeleteNode::asMethod());
   c->setMethod (new strNode("unshift"), arrayunshiftNode::asMethod());
   c->setMethod (new strNode("push"), arraypushNode::asMethod());
   c->setMethod (new strNode("shift"), arrayshiftNode::asMethod());
   c->setMethod (new strNode("pop"), arraypopNode::asMethod());
   c->setMethod (new strNode("chunk"), arrayChunkNode::asMethod());
   c->setMethod (new strNode("implode"), implodeNode::asMethod());
   c->newelement_ = new arrayNode ();
   arrayNode::class_ = c;
}

arrayNode::arrayNode (listNode* list) : asociative_ (true) { 
      fromList(list, true);
}

arrayNode::arrayNode () : asociative_ (true) {}

arrayNode::arrayNode (arrayNode* array) : asociative_ (true) {
   symbols *m = array->getArray();
   runNode *key, *value;
   asociative_ = array->asociative_;
   for (isym iter = m->begin (); iter != m->end(); ++ iter) {
      if (!(dynamic_cast<arrayConstNode*> (array))) {
         iter.second->addRef ();
      }
      refNode * r = new refNode(iter.first);
      this->array_[r] = iter.second;
   }
   if (arrayConstNode* carray = dynamic_cast<arrayConstNode*> (array)){
      carray->array_.clearRef ();
      carray->isCloned (true);
   }
}
#if JSON==1 
void arrayNode::toJsonSymbols () {
   this->run();
   symbols *m = this->getArray();
   for (isym iter = m->begin (); iter != m->end(); ++ iter) {
         interpreter::to_jsonSymbols(this, iter.first, iter.second);
   }
}
#endif

arrayNode::arrayNode (arrayNode* array, refNode* &refSearch) : asociative_ (true) {
   symbols *m = array->getArray();
   runNode *key, *value;
   asociative_ = array->asociative_;
   for (isym iter = m->begin (); iter != m->end(); ++ iter) {
      refNode * ref = new refNode(iter.first);
      if (iter.first == refSearch)
         refSearch = ref;
      else
         iter.second->addRef ();
      array_[ref] = iter.second;
   }
}

void arrayNode::run () {
   //~ fromList(list_);
}

void arrayNode::fromList (listNode * l, bool addref) {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (l && array_.size() == 0) {
      vector<runNode*> aux;
      vector<runNode*>::iterator iter;
      l->run ();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      aux = l->listvalue ();
      for (iter = aux.begin(); iter != aux.end (); iter ++) {
         mapNode* m;
         if (functionNode* f = dynamic_cast<functionNode*> (*iter)) {
            if (idNode* id_f = dynamic_cast<idNode*>(f->getID())) {
               runNode* name = new strNode (id_f->name());
               f->setID (NULL);
               *iter = new mapNode (name, f);
               (*iter)->run();
            }
         }
         if (m = dynamic_cast<mapNode*> (*iter)) {
            runNode  *key = m->key(), *value =  m->value();
            idNode::resolvedAsStr (key, false);
            nexpNode::resolved(value);
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif
            if (!dynamic_cast<nexpNode*>(m->value()))
               value = expNode::clone (value);
            value = expNode::clone (value);
            if (dynamic_cast<arrayConstNode*> (this) || addref)
               value->addRef();
            refNode * r = new refNode (key);
            array_ [r] = value;
            #if JSON==1
               interpreter::to_jsonSymbols(this, r, value);
            #endif
            asociative_ = true;
         } else {
            runNode* value = *iter;
            nexpNode::resolved(value);
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif
            if (!dynamic_cast<nexpNode*>(*iter) || addref)
               value = expNode::clone (value);
            if (dynamic_cast<arrayConstNode*> (this))
               value->addRef();
            runNode * key = new numNode (array_.size());
            array_ [key] = value;
            #if JSON==1
               interpreter::to_jsonSymbols(this, key, value);
            #endif
            asociative_ = false;
         }
      }
   }
}

string arrayNode::printLevel (short int level) const {
   ostringstream oss;
   printableNode* p;
   arrayNode* a;
   fexpNode* fstr ;
   isym iter = array_.begin();
   isym iter_r = array_.end();
   if (array_.findKey("_str") && (fstr = dynamic_cast<fexpNode*>(array_.findKey("_str")))) {
      functioncallNode* call = new functioncallNode(fstr, NULL);
      call->run();
      if (printableNode* p = dynamic_cast<printableNode*>(call->nodeval())) 
         oss << p->print();
   } else {
      if (array_.size () != 0 )
         iter_r --;
      for (iter = array_.begin(); iter != array_.end(); iter ++) {
         if (!dynamic_cast<fexpNode*>(iter.second) && iter.second->is_print()) {
            for (int i = 0; i < level; i ++) oss << '\t';
            if (refNode * ref = dynamic_cast<refNode*>(iter.first))
               oss << '[' << ref->strvalue() << ']';
            else if (p = dynamic_cast<printableNode*> (iter.first))
               oss << '[' << p->print() << ']';
            if (p = dynamic_cast<printableNode*> (iter.second)) {
               oss << " => ";
               if (a = dynamic_cast<arrayNode*> (iter.second)) {
                  oss << '{' ;
                  if (a->size()) oss << endl;
                     else oss << '}';
                  oss << a->printLevel (level + 1);
               }else
                  oss << p->print();
            }
         }
         if (iter != iter_r ) {
            if (!dynamic_cast<fexpNode*>(iter.second) && iter.second->is_print())
               oss << endl;
         } else if (level != 0) {
            if (!dynamic_cast<fexpNode*>(iter.second) && iter.second->is_print())
               oss << endl;
            for (int i = 0; i < level-1; i ++) oss << '\t';
            oss << '}';
         }
      }
   }
   return oss.str ();
}

string arrayNode::print () const {
   return printLevel (0);
}

runNode* 
arrayNode::copy(arrayNode *a, arrayNode *b) {
   symbols *m = a->getArray();
   isym iter;
   runNode *key, *value;
   for (iter = m->begin (); iter != m->end(); ++ iter) {
      key = new refNode(iter.first);
      value = iter.second;
      b->array_[key] = value;
   }
   b->asociative_ = a->asociative_;
   return b;
}

symbols*
arrayNode::getArray () {
   return &array_;
}

int arrayNode::size () const {
   return array_.size();
}

bool arrayNode::compare (runNode* node, int op) {
   runNode* run;
   bool resp = true;
   run = node;
   if (nexpNode* nexp = dynamic_cast<nexpNode*> (run)) {
      nexp->run();
      run = nexp->nodeval();
   }
   run->run();
   if (arrayNode* aux = dynamic_cast<arrayNode*> (run)) {
      symbols* array_op = aux->getArray ();
      isym iter0, iter1;
      iter0 = array_.begin();
      iter1 = array_op->begin();
      switch (op) {
      case 0:
         if (size() != aux->size ())
            return false;
         break;
      case 1:
         if (size() != aux->size ())
            return true;
         break;
      case 2:
         if (size () > aux->size ())
            return true;
         if (size () < aux->size ())
            return false;
         break;
      case 3:
         if (size () < aux->size ())
            return true;
         if (size () > aux->size ())
            return false;
         break;
      case 4:
         if (size () > aux->size ())
            return true;
         if (size () < aux->size ())
            return false;
         break;
      case 5:
         if (size () < aux->size ())
            return true;
         if (size () > aux->size ())
            return false;
         break;
      case 6:
         if (size() != aux->size ())
            return false;
         break;
      }
      while (resp && iter0 != array_.end() && iter1 != array_op->end()) {
         resp = runNode::compare(iter0.first, iter1.first, op) && runNode::compare(iter0.second, iter1.second, op);
         iter0 ++;
         iter1 ++;
      }

   }
   return resp;

}

int arrayNode::getCount () const {
   return size();
}

void arrayNode::cAll (runNode* node_search, runNode* node_new) {
   isym iter;

   for (iter = array_.begin(); iter != array_.end(); iter ++) {
      if (iter.second == node_search) {
         iter.second = node_new;
      } else {
         if (arrayNode* array = dynamic_cast<arrayNode*> (iter.second)) {
            array->cAll (node_search, node_new);
         }
      }
   }
}

bool arrayNode::isref (runNode* node) {
   bool resp = false;
   isym iter;
  
   for (iter = array_.begin(); iter != array_.end() && !resp ; iter ++) {
      if (iter.second == node) {
         resp = true;
      } else {
         if (arrayNode* array = dynamic_cast<arrayNode*> (iter.second)) {
            resp = array->isref (node);
         }
      }
   }
   return resp;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
arrayConstNode::arrayConstNode(listNode* list) : list_ (list), cloned_ (false) {}

void arrayConstNode::run () {
   if (!cloned_){ 
      
      array_.clear ();
   }
   fromList(list_);
}
//----------------------------------------------------------------------
