//symbolOpNode.cpp
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
#include "symbolOpNode.h"
#include "../../interpreter.h"
#include "../../error.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//asigNode
asigNode::asigNode (runNode* node1, runNode* node2): node1_ (node1), node2_(node2) {}

void asigNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux = node2_, *nodeR_ = NULL;
   ref_ = NULL;
   nexpNode::resolvedRef (node_aux);
   #if JSON==1
      if (node2_ != node_aux)
         interpreter::to_jsonRun(this);
   #endif
   if (!(bool)dynamic_cast<functionNode*>(node_aux) && node2_ == node_aux) {
      node_aux->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   
   
   nodeR_ = this->isRefNode (node_aux)?node_aux:expNode::clone (node_aux);
   

   noderef(nodeR_);
   #if JSON==1
      interpreter::to_jsonSetValue(this, nodeR_);
   #endif
   setValue (nodeR_);
}

void asigNode::runLevel () {
   runNode *node_aux = node2_, *nodeR_ = NULL;
   ref_ = NULL;
   sTable::sTable_use->setLevel (sTable::sTable_use->getLevel() - 1);
   nexpNode::resolved (node_aux); 
   sTable::sTable_use->setLevel (sTable::sTable_use->getLevel() + 1);
   nodeR_ = this->isRefNode (node_aux)?node_aux:expNode::clone (node_aux);
   noderef(nodeR_);
   setValue (nodeR_);
}

bool asigNode::isRefNode (runNode* node){
   //~ return (dynamic_cast<nexpNode*>(node2_) || dynamic_cast<objectNode*>(node2_) || dynamic_cast<refNode*>(node2_) || dynamic_cast<fexpNode*>(node2_)) ;
   return (
      dynamic_cast<returnNode*>(node2_) || 
      dynamic_cast<getRefNode*>(node2_) || 
      dynamic_cast<idNode*>(node2_) || 
      dynamic_cast<getNode*>(node2_) || 
      dynamic_cast<objectNode*>(node2_) || 
      dynamic_cast<objectNode*>(node) || 
      dynamic_cast<refNode*>(node2_) || 
      dynamic_cast<refNode*>(node) || 
      dynamic_cast<fexpNode*>(node2_)
   ) ;
}

void asigNode::setValue (runNode* node) { 
   if (nexpNode* nexp = dynamic_cast<nexpNode*> (node1_)) {
      nexp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      nexp->noderef(node);
      ref_ = nexp->ref();
   }else{
      throw errorException ("assigning constant", "asigNode: Node 1 is const ", 1); 
   }
}

runNode* asigNode::getLeft () {
   return node1_;
}  
 
runNode* asigNode::getRight () {
   return node2_;
}

bool asigNode::is_runlist () const{
   return true;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//asigrefNode
asigrefNode::asigrefNode (runNode* node1, runNode* node2): node1_ (node1), node2_(node2) {}

void asigrefNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux = node2_, *nodeR_ = NULL;
   if (nexpNode* n_id = dynamic_cast<nexpNode*> (node_aux)) {
      n_id->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
     noderef(n_id->getRef());
     #if JSON==1
         interpreter::to_jsonSetValue(this, n_id->getRef());
      #endif
     nodeR_ = n_id->getRef();
   } else if (expNode* exp = dynamic_cast<expNode*> (node_aux)) {
      exp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      noderef(exp);
      #if JSON==1
         interpreter::to_jsonSetValue(this, exp);
      #endif
      nodeR_ = exp;
   }
   setValue (nodeR_);
}

void asigrefNode::setValue (runNode* node) { 
   if (nexpNode* nexp = dynamic_cast<nexpNode*> (node1_)) {
      nexp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      if (node != nexp->getRef())
         nexp->noderef (node);
      else
         throw errorException ("Reference to same symbol", "asigrefNode: Reference recursive ", 1); 
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getRefNode
getRefNode::getRefNode (runNode* node): node_ (node) {}

void getRefNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux = node_;
   if (nexpNode* n_id = dynamic_cast<nexpNode*> (node_aux)) {
      n_id->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
     noderef(n_id->getRef());
      #if JSON==1
         interpreter::to_jsonSetValue(this, n_id->getRef());
      #endif     
   } else if (expNode* exp = dynamic_cast<expNode*> (node_aux)) {
      exp->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      noderef(exp);
      #if JSON==1
         interpreter::to_jsonSetValue(this, exp);
      #endif      
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getNode
getNode::getNode (runNode* array, runNode* key, bool resolv): array_ (array), key_ (key), next_ (NULL), exec_ (true), resolv_(resolv), is_const_ (false), functioncall_ (false) { }

void getNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   idNode* id = NULL;
   expNode * exp = NULL;
   stringNode * key_str = NULL;
   runNode *array = array_, *key = key_;
   runNode* method = NULL;
   sTable *aux = NULL;
   is_this_node_ = false;
   if (thisNode * thisn = dynamic_cast<thisNode*>(array)){
      is_this_node_ = true;
   }
   isym iter;
   if(getNode* get = dynamic_cast<getNode*>(array)) {
      get->next_ = this;
   }
   
   if (parentNode * parent = dynamic_cast<parentNode*> (array)){ //Parent
      type_ = 0;
      idNode::resolvedAsStr (key, false, !is_this_node_, NULL, true);
      nexpNode::resolved (key);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      if (runNode *r = parent->get(key)){
         noderef(r);
      #if JSON==1
         interpreter::to_jsonSetValue(this, r);
      #endif         
         functioncall_ = false;
         return;
      }else{
         thisNode thisn;
         thisn.run();
         array = dynamic_cast<arrayNode*>(thisn.nodeval());
      }
   }else {
      runNode *node_ini = array;
      idNode::resolved (array, new arrayNode ());
      nexpNode::resolved (array);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif 
      is_const_ = (node_ini == array);
      if (objectNode * obj = dynamic_cast<objectNode*> (array)){ // OBJETO DENTRO DE UN METODO DE LA MISMA CLASE 
         if (classNode* c = dynamic_cast<classNode*>(obj->getClass ())){
            if (functionNode::class_link && c->name() == functionNode::class_link->name())
               is_this_node_ = true;
            else
               aux = c->insideTable();
         }
      }      
      if (idgetNode * idget = dynamic_cast<idgetNode*>(key)){
         idget->run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif         
         key = idget->getId();
      }
      idNode::resolvedAsStr (key, false, !is_this_node_, aux, !resolv_);
      nexpNode::resolved (key);
      #if JSON==1
         if (!is_this_node_)
            interpreter::to_jsonRun(this);
      #endif      
   }
   if (arrayNode * array_aux = dynamic_cast<arrayNode*> (array)) {
      type_ = 0;
      //~ if (!dynamic_cast<dataCNode*>(array)){
         //~ array_aux->run();
      //~ }
      run_case_array(array_aux, key);
   } else if(
      (exp = dynamic_cast<expNode*>(array)) &&
      (key_str = dynamic_cast<stringNode*> (key)) &&
      (method = exp->getMethod (key_str))
   ) {
      type_ = 3; //???
      noderef(method);
      #if JSON==1
         interpreter::to_jsonSetValue(this, method);
      #endif      
      objectTypeNode *obj  = NULL;
      functionNode * func = NULL;
      if ((obj = dynamic_cast<objectTypeNode*> (array)) && (func = dynamic_cast<functionNode*>(method))) {
         func->setObj (obj);
         if (classNode * c = dynamic_cast<classNode*>(obj->getClass())){
            func->setParent (c->getExtendClass ());
         }
      }
      functioncall_ = false;
   } else if (strNode* str = dynamic_cast<strNode*> (array)) {
      type_ = 1;
      run_case_str (str, key);
      functioncall_ = false;
   } else
      throw errorException ("Wrong type data", "getNode: node must be array or string", 1);
}

void getNode::run_case_array (arrayNode* array, runNode* key) { //array[x]
   if (dynamic_cast<getNode_endValue*> (key))
      key = new numNode (array->size());
   setNodeValue(array, key);
}

void getNode::run_case_str (strNode* str, runNode* num) { //string[n]
   getNode_strInterface* istr = NULL;
   if (dexpNode *exp = dynamic_cast<dexpNode*>(num)){
      //~ if (!(istr = dynamic_cast<getNode_strInterface*>(nodeval())))
          istr = new getNode_strInterface (str, is_const_);
      #if JSON==1
         interpreter::to_jsonNewNode(istr, true);
      #endif    
      istr->setn (exp->numvalue());
      istr->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      if (!ref_) {
         ref_ = new refNode("index");  
         #if JSON==1
            interpreter::to_jsonNewNode(ref_, true);
         #endif   
      }
      ref_->setRef(istr);
      #if JSON==1
         interpreter::to_jsonSetRef(this, ref_, istr);
      #endif
   }
}

void getNode::setNodeValue (arrayNode *array, runNode * key) {
   expNode * exp = NULL;
   stringNode * key_str = NULL;
   refNode* method = NULL;
   symbols *map = array->getArray ();
   bool clearfuncall = true;
   if (map->find(key) != map->end()) {
      ref_ = map->findRef(key);
      #if JSON==1
         interpreter::to_jsonSetRef(this, ref_, array);
      #endif
   } 
   else if(
      (exp = dynamic_cast<expNode*>(array)) &&
      (key_str = dynamic_cast<stringNode*> (key)) &&
      (method = exp->getMethodRef (key_str))
   ) {
      #if JSON==1
         interpreter::to_jsonNewNode(method, true);
         interpreter::to_jsonNewNode(method->getRef(), true);
      #endif
      ref_ = method;
      #if JSON==1
         interpreter::to_jsonSetRef(this, ref_, array);
      #endif
   }
   else if (objectNode * obj = dynamic_cast<objectNode*>(array)){
      if (functioncall_) {
         strNode str ("_call");
         if(
            (exp = dynamic_cast<expNode*>(array)) &&
            (key_str = dynamic_cast<stringNode*> (key)) &&
            (method = exp->getMethodRef (&str))
         ) {
            ref_ = method;
            #if JSON==1
               interpreter::to_jsonSetRef(this, ref_, array);
            #endif
            clearfuncall = false;
         }
         else{
            setDefaultValue (map, key);
         }
      }else {
         strNode str ("_get");
         if(
            (exp = dynamic_cast<expNode*>(array)) &&
            (key_str = dynamic_cast<stringNode*> (key)) &&
            (method = exp->getMethodRef (&str))
         ) {
            ref_ = method;
            if (fexpNode * funget = dynamic_cast<fexpNode*> (ref_->getRef())){
               listNode l (key);
               functioncallNode f (funget, &l);
               f.run();
               #if JSON==1
                  interpreter::to_jsonRun(this);
               #endif
               ref_ = f.getRef();
            }
         }else{
            setDefaultValue (map, key);
         } 
      }
   }
   else {
     setDefaultValue (map, key);
   }
   objectTypeNode *obj  = NULL;
   functionNode * func = NULL;
   if ((obj = dynamic_cast<objectTypeNode*> (array)) && (func = dynamic_cast<functionNode*>(nodeval()))) {
      func->setObj (obj);
      if (classNode * c = dynamic_cast<classNode*>(obj->getClass())){
         func->setParent (c->getExtendClass ());
      }
   }
   if (clearfuncall)
      functioncall_ = false;
}

void getNode::noderef (runNode* node) {
   if (!ref_) ref_ = new refNode();
   node->addRef();
   if (type_ == 1) {
      if (getNode_strInterface *istr = dynamic_cast<getNode_strInterface*> (ref_->getRef()))
         istr->noderef(node);
      else{
         ref_->setRef(node);
         #if JSON==1
            interpreter::to_jsonChangeRef(ref_, node);
         #endif
      }
   } else if (type_ == 3){
      ref_->setRef(node);
      #if JSON==1
         interpreter::to_jsonChangeRef(ref_, node);
      #endif
   }else {
      runNode * before = NULL;
      if (refNode *aux = noderefAnidate ()){
         ref_ = aux;
      }else{
         before = ref_->getRef();
      }
      ref_->setRef(node);
      #if JSON==1
         interpreter::to_jsonChangeRef(ref_, node);
      #endif
      if (before) before->rmRef();
   }
}

refNode * getNode::noderefAnidate (){
   if (nexpNode *nexp = dynamic_cast<nexpNode*>(array_)){
         if(refNode *ref = nexp->ref()){
            if(runNode* before = ref->getRef()){
               if (before->ref_count_ > 1 && !dynamic_cast<getiNode*>(nexp)){
                  if (arrayNode* a = dynamic_cast<arrayNode*>(before)){
                     refNode *nr = ref_;
                     arrayNode * na = new arrayNode (a, nr);
                     #if JSON==1
                        interpreter::to_jsonNewNode(na);
                        na->toJsonSymbols();
                     #endif
                     na->addRef();
                     ref->setRef (na);
                     #if JSON==1
                           interpreter::to_jsonChangeRef(ref, na);
                     #endif
                     before->rmRef();
                     return nr;
                  }else{
                     //~ cerr << "No es Array" << endl;
                  }
               }else{
                  if (getNode* lget = dynamic_cast<getNode*>(array_)){
                     refNode *newref = lget->noderefAnidate ();
                     if (newref) {
                        if (arrayNode* a = dynamic_cast<arrayNode*>(before)){
                           refNode *nr = ref_;
                           arrayNode * na = new arrayNode (a, nr);
                           #if JSON==1
                              interpreter::to_jsonNewNode(na);
                              na->toJsonSymbols();
                           #endif
                           na->addRef();
                           newref->setRef (na);
                           #if JSON==1
                                 interpreter::to_jsonChangeRef(newref, na);
                           #endif
                           return nr;
                        }else{
                           //~ cerr << "No es Array" << endl;
                        }
                     }
                     return newref;
                  }
                  if (idNode *lid = dynamic_cast<idNode*>(array_)){
                     return NULL;
                  } 
                  else{
                     //No se me ocurre el caso
                  }
               }
            }
         } 
      }else{
         //~ cerr << "CASO CONSTANTE" << endl; 
      }
      return NULL;
}

void getNode::setFunctionCall () {
      functioncall_ = true;
}

bool getNode::getFunctionCall () {
      return functioncall_;
}

void getNode::setDefaultValue (symbols *map, runNode * key){
   if (dynamic_cast<stringNode*> (key))
      key = new strNode (stringNode::to_str(key));
   runNode *value = ((this->next_)?((runNode*)new arrayNode()):((runNode*)new strNode ("")));
   value->addRef();
   (*map)[key] = value;
   
   ref_ = map->findRef(key);
}

runNode* getNode::getKey () { 
   if (idNode * id = dynamic_cast<idNode*>(key_)){
      return new strNode (id->name());
   }
   return key_; 
}

//---------------------------------------------------------------------

//----------------------------------------------------------------------
//getNode_endValue
void getNode_endValue::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   }
//---------------------------------------------------------------------

//----------------------------------------------------------------------
//getNode_strInterface
getNode_strInterface::getNode_strInterface (stringNode* node, bool is_const): refn_ (0), is_const_ (is_const), str_ (node) {
   strref_ = node->strref();
}

void getNode_strInterface::run () {
   //~ #if JSON==1
      //~ interpreter::to_jsonRun(this);
   //~ #endif
}
   
runNode* getNode_strInterface::nodeval () const {
   if (refn_ >= strref_->size()){
      return new nullNode();
   }
         //~ throw errorException ("wrong string index", "string index is out of range", 1); 
   char c[] = {(*strref_)[refn_]};
   string a (c);
   runNode *r = new strNode (a);
   #if JSON==1
      interpreter::to_jsonNewNode (r);
   #endif
   return  r;
}

void getNode_strInterface::noderef (runNode* node) {
   if (!is_const_){
      if (!ref_) ref_ = new refNode ();
      if (refn_ >= strref_->size()){
         throw errorException ("wrong string index", "string index is out of range", 1);
      }
      if (stringNode* str = dynamic_cast<stringNode*> (node)) {
         string s = str->strvalue();
         if (s.length () == 1)
            (*strref_)[refn_]  = str->strvalue()[0];
         else
            strref_->replace (refn_, 1,str->strvalue());
      }
      else if (arithNode* arith = dynamic_cast<arithNode*> (node)) {
         strNode s (arith);
         if (s.strvalue().length () == 1)
            (*strref_)[refn_]  = s.strvalue()[0];
         else
            strref_->replace (refn_, 1,s.strvalue());           
      }else if (logicNode* l = dynamic_cast<logicNode*> (node)) {
         string s = (l->boolvalue())?"1":"";
         node = nexpNode::clone (node);
         if (s.length () == 1)
            (*strref_)[refn_]  = s[0];
         else
            strref_->replace (refn_, 1,s);
      }else {
         string s = stringNode::to_str(node);
         if (s.length () == 1)
            (*strref_)[refn_]  = s[0];
         else
            strref_->replace (refn_, 1,s);
      }
      #if JSON==1
         interpreter::to_jsonChangeValue(str_, *strref_);
      #endif   
    }else{
      throw errorException ("Change reference of const node", "getNode_strInterface: node must be symbol", 1);
    }  
}

void getNode_strInterface::setn ( int n) {
   refn_ = n;
}

int getNode_strInterface::getn () const {
   return refn_;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getEnvNode
getEnvNode::getEnvNode (runNode* node) : node_ (node) {}

void getEnvNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode * node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   string str = stringNode::to_str (node);
   if (char* c = getenv (str.c_str())) {
      this->strvalue_ = c;
      #if JSON==1
         interpreter::to_jsonSetValue(this, this->strvalue_);
      #endif      
   }else {
      this->strvalue_ = "";
      #if JSON==1
         interpreter::to_jsonSetValue(this, this->strvalue_);
      #endif   
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getclass
getclassNode::getclassNode (runNode* node) : node_ (node) {}

void getclassNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode * node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (objectNode * obj = dynamic_cast<objectNode*>(node)){
      if (classNode * c = dynamic_cast<classNode*>(obj->getClass())){
         strvalue_ = c->name();
         #if JSON==1
            interpreter::to_jsonSetValue(this, strvalue_);
         #endif
         return;
      }
   }
   strvalue_ = "";
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------


//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
