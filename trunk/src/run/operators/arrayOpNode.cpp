//arrayOpNode.cpp
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
#include "arrayOpNode.h"
#include "../../error.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//reduceNode
reduceNode::reduceNode (runNode* elem, runNode* func) : elem_ (elem), func_(func) {}

void reduceNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   runNode *elem = elem_, *func = func_;
   nexpNode::resolvedAsFunction (func)->run();
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   nexpNode::resolved (elem);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   if (arrayNode* array = dynamic_cast<arrayNode*> (elem)){
      if (functionNode* f = dynamic_cast<functionNode*> (func)){
         runNode *partial = NULL;
         symbols *m = array->getArray();
         isym i = m->begin();
         if (i != m->end()){
            partial = i.second;
            i ++;
         }
         for (;i != m->end(); ++i){
            listNode *list = new listNode (partial, i.second);
            partial = f->call (list);
            delete list;
         }
         noderef(partial);
         #if JSON==1
            interpreter::to_jsonSetValue(this, partial);
         #endif         
      }
   }else{
      throw errorException ("Unknown operand", "reduceNode: node is unknown operand ", 1); 
   }
}

runNode* reduceNode::asMethod (){
   idNode *id_func = new idNode("~func");
   listNode *params = new listNode(id_func, NULL);
   reduceNode *node = new reduceNode (new thisNode(), id_func);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arrayChunkNode
arrayChunkNode::arrayChunkNode (runNode * array, runNode * size) : size_ (size), array_(array) {}
 
 void arrayChunkNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode * size = size_, *array = array_;
   nexpNode::resolved (size);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved (array);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   int s = arithNode::to_num (size);
   if (arrayNode * a = dynamic_cast<arrayNode*> (array)){
      if (s > 0) {
         symbols *map = a->getArray ();
         isym i;
         int count = 0;
         listNode * l = NULL, *la = NULL;
         for (i = map->begin(); i != map->end(); ++i){
            mapNode *p = new mapNode (new numNode(count - (s * (int)(count / s))), i.second);
            l = new listNode (l, p);
            if (count % s == s - 1) {
               arrayNode * a = new arrayNode (l);
               la = new listNode (la, a);
               l = NULL;
            }
            count ++;
         }
         if ((count - 1) % s != s - 1){
            arrayNode * a = new arrayNode (l);
            la = new listNode (la, a);
         }
         arrayNode * a = new arrayNode (la);
         noderef(a);
         #if JSON==1
            interpreter::to_jsonSetValue(this, a);
         #endif
      }else{
         noderef(array);
      #if JSON==1
         interpreter::to_jsonSetValue(this, array);
      #endif
      }
   }
 }
 runNode *arrayChunkNode::asMethod() {
   idNode *id = new idNode("~size");
   listNode *params = new listNode(id, NULL);
   arrayChunkNode * a = new arrayChunkNode (new thisNode(), id);
   runNode *body = new returnNode(a);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//implodeNode
implodeNode::implodeNode(runNode * str, runNode * array):str_(str),
   array_(array) {}

void
implodeNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux1 = str_;
   runNode *node_aux2 = array_;
   nexpNode::resolved(node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(node_aux2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   strNode s = stringNode::to_str(node_aux1);
   ostringstream oss(ostringstream::out);
   if(arrayNode * array = dynamic_cast < arrayNode * >(node_aux2)) {
      symbols *v_array = array->getArray();
      isym iter;
      isym iter_e = v_array->end();
      if(v_array->size())
         iter_e--;
      for(iter = v_array->begin(); iter != v_array->end(); ++iter) {
         if(arrayNode * array_s =
                  dynamic_cast < arrayNode * >(iter.second)) {
            implodeNode i(str_, array_s);
            i.run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif            
            oss << i.strvalue();
         } else {
            strNode s(iter.second);
            oss << s.strvalue();
         }
         if(iter != iter_e)
            oss << s.strvalue();
      }
   }else 
      throw errorException("Wrong type", "implodeNode: node must be array", 1);
   string resp = oss.str();
   strvalue_ = resp;
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif
}

runNode *implodeNode::asMethod() {  
   idNode *id = new idNode("~substr");
   listNode *params = new listNode(id, NULL);
   implodeNode *node = new implodeNode (id, new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arraylastNode
arraylastNode::arraylastNode (runNode* array): array_ (array) {}

void arraylastNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *exp = array_;
   nexpNode::resolved(exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (arrayNode* array = dynamic_cast<arrayNode*>(exp)){
         symbols *v_array = array->getArray();
         if (array->size()){
            if (!(ref_ = v_array->last())){
               ref_ = new refNode ("_key");
               ref_->setRef(new nullNode());
            }
         }else{
            ref_ = new refNode ("_key");
            ref_->setRef(new nullNode());
         }
   }else{
      throw errorException (
         "Wrong data type", "arraylastNode: array is a wrong type", 1
      );
   }
}

runNode* arraylastNode::asMethod (){
   arraylastNode *node = new arraylastNode (new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, NULL, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arrayfirstNode
arrayfirstNode::arrayfirstNode (runNode* array): array_ (array) {}

void arrayfirstNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *exp = array_;
   nexpNode::resolved(exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (arrayNode* array = dynamic_cast<arrayNode*>(exp)){
         symbols *v_array = array->getArray();
         if (!(ref_ = v_array->first())){
            runNode * r = new nullNode();
            noderef (r);
            #if JSON==1
               interpreter::to_jsonSetValue(this, r);
            #endif
         }
   }else{
      throw errorException (
         "Wrong data type", "arraylastNode: array is a wrong type", 1
      );
   }
}

runNode* arrayfirstNode::asMethod (){
   arrayfirstNode *node = new arrayfirstNode (new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, NULL, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arrayinsertNode
arrayinsertNode::arrayinsertNode (runNode* array, runNode* index, runNode *element): array_ (array), index_(index), element_(element) {}

void arrayinsertNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *array_exp = array_, *index_exp = index_, *element_exp = element_;
   nexpNode::resolved(array_exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(index_exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(element_exp);
      #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (arrayNode* array_const = dynamic_cast<arrayNode*>(array_exp)){
      arrayNode * array = (
         (!dynamic_cast<arrayConstNode*>(array_exp))
         ?array_const
         :new arrayNode (array_const)
      );
      if (arithNode* index_num = dynamic_cast<arithNode*>(index_exp)){
         symbols *v_array = array->getArray();
         isymTable ini = v_array->begin();
         isymTable end = v_array->end();
         int i = (int)index_num->numvalue();
         if (i >= 0 && i < v_array->size()){
            int count = 0;
            while (count < i) {
               ++ini;
               ++count;
            }
            refNode *now = ini.first;
            refNode * insert_element = new refNode (now->getKey());
            insert_element->setRef (element_exp);
            v_array->insert(ini, insert_element);
            refNode *aux = NULL;
            ++ini;
            end = v_array->end();
            while (ini != end) {
               aux = ini.first;
               now->setKey (aux->getKey());
               ini.first = now;
               ini.second = now->getRef();
               now = aux;
               ++ini;
            }
            ostringstream oss;
            oss << v_array->size() - 1;
            v_array->last()->setKey(oss.str());
            noderef (array);
            #if JSON==1
               interpreter::to_jsonSetValue(this, array);
            #endif
         }else if (i == v_array->size()){
            ostringstream oss;
            oss << v_array->size();
            refNode* r = new refNode (oss.str());
            r->setRef(element_exp);
            v_array->push_back(r);
            noderef (array);
            #if JSON==1
               interpreter::to_jsonSetValue(this, array);
            #endif
         }
         else{
            throw errorException (
            "Wrong index", "arrayinsertNode: index is a wrong number", 1
            );
         }
      }else{
         throw errorException (
            "Wrong data type", "arrayinsertNode: index is a wrong type", 1
         );
      }
   }else{
      throw errorException (
         "Wrong data type", "arrayinsertNode: array is a wrong type", 1
      );
   }
}

runNode* arrayinsertNode::asMethod (){
   idNode *id_index = new idNode("~index");
   idNode *id_element = new idNode("~element");
   listNode *params = new listNode(id_index, id_element);
   arrayinsertNode *node = new arrayinsertNode (new thisNode(), id_index, id_element);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arraydeleteNode
arraydeleteNode::arraydeleteNode (runNode* array, runNode* index): array_ (array), index_(index) {}

void arraydeleteNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *array_exp = array_, *index_exp = index_;
   nexpNode::resolved(array_exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(index_exp);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (arrayNode* array_const = dynamic_cast<arrayNode*>(array_exp)){
      arrayNode * array = (
         (!dynamic_cast<arrayConstNode*>(array_exp))
         ?array_const
         :new arrayNode (array_const)
      );
      if (arithNode* index = dynamic_cast<arithNode*>(index_exp))
         array->del(index_exp, false, true);
      else
         array->del(index_exp);
      noderef (array);
      #if JSON==1
         interpreter::to_jsonSetValue(this, array);
      #endif
   }else{
      throw errorException (
         "Wrong data type", "arrayinsertNode: array is a wrong type", 1
      );
   }
}

runNode* arraydeleteNode::asMethod (){
  idNode *id_index = new idNode("~index");
   listNode *params = new listNode(id_index, NULL);
   arraydeleteNode *node = new arraydeleteNode (new thisNode(), id_index);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arrayunshift
arrayunshiftNode::arrayunshiftNode (runNode* array, runNode* element): arrayinsertNode (array, new numNode((num)0), element) {
}

runNode* arrayunshiftNode::asMethod (){
   idNode *id_element = new idNode("~element");
   listNode *params = new listNode(id_element, NULL);
   arrayunshiftNode *node = new arrayunshiftNode (new thisNode(), id_element);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arraypushNode:
arraypushNode::arraypushNode (runNode* array, runNode* element): arrayinsertNode (array, NULL, element) {}

void arraypushNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode * array = array_;
   nexpNode::resolved (array);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (arrayNode* array_exp = dynamic_cast<arrayNode*>(array)){
      numNode num (array_exp->size());
      index_ = &num;
      arrayinsertNode::run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   else{
      throw errorException (
         "Wrong data type", "arraypushNode: array is a wrong type", 1
      );
   }
}

runNode* arraypushNode::asMethod (){
   idNode *id_element = new idNode("~element");
   listNode *params = new listNode(id_element, NULL);
   arraypushNode *node = new arraypushNode (new thisNode(), id_element);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arrayshiftNode
arrayshiftNode::arrayshiftNode (runNode* array): arraydeleteNode (array, new numNode((num)0)) {}

void arrayshiftNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *array = array_;
   nexpNode::resolved(array);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (dynamic_cast<arrayNode*>(array)){
      arrayfirstNode *first = new arrayfirstNode(array);
      first->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      first->nodeval()->ref_count_ ++;
      if(!dynamic_cast<arrayConstNode*>(array)){      
         arraydeleteNode::run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif
      }
      noderef (first->nodeval());
   #if JSON==1
      interpreter::to_jsonSetValue(this, first->nodeval());
   #endif      
   }else{
       throw errorException (
         "Wrong data type", "arrayshiftNode: array is a wrong type", 1
      );
   }
}

runNode* arrayshiftNode::asMethod (){
   arrayshiftNode *node = new arrayshiftNode (new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, NULL, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//arraypopNode
arraypopNode::arraypopNode (runNode* array): arraydeleteNode (array, NULL) {}

void arraypopNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *array = array_;
   nexpNode::resolved(array);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (arrayNode* array_exp = dynamic_cast<arrayNode*>(array)){
      arraylastNode *last = new arraylastNode(array);
      last->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      last->nodeval()->ref_count_ ++;
      if(!dynamic_cast<arrayConstNode*>(array)){     
         numNode num (array_exp->size() - 1);
         index_ = &num; 
         arraydeleteNode::run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif
      }
      noderef (last->nodeval());
      #if JSON==1
         interpreter::to_jsonSetValue(this, last->nodeval());
      #endif     
   }else{
       throw errorException (
         "Wrong data type", "arrayshiftNode: array is a wrong type", 1
      );
   }
}

runNode* arraypopNode::asMethod (){
   arraypopNode *node = new arraypopNode (new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, NULL, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla

