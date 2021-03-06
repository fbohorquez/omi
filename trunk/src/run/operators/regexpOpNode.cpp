//regexOpNode.cpp
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
#include "regexpOpNode.h"
#include "../../interpreter.h"
#include "../../error.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//matchNode
matchNode::matchNode (runNode* str, runNode* regexp) : str_ (str), regexp_(regexp) {}

runNode *matchNode::asMethod() {  
   idNode *id_regexp = new idNode("~regexp");
   listNode *params = new listNode(id_regexp, NULL);
   matchNode *node = new matchNode (new thisNode(), id_regexp);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}

void matchNode::run () {   
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux1 = str_;
   runNode *node_aux2 = regexp_;
   nexpNode::resolved (node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved (node_aux2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   string s = stringNode::to_str(node_aux1);
   if (regexpNode *ex = dynamic_cast<regexpNode*> (node_aux2)) {
      cmatch what;
      boolvalue_ = regex_match(s.c_str(), what, ex->exvalue ());
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif      
   }
   else 
      boolvalue_ = (s == stringNode::to_str(node_aux2));
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif      
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//newregexNode
newregexpNode::newregexpNode (runNode* str) : str_ (str) {}

void newregexpNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux1 = str_;
   nexpNode::resolved (node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (stringNode * str = dynamic_cast<stringNode*>(node_aux1)){
      runNode *r = new regexpNode ( str->strvalue ());
      noderef(r);
      #if JSON==1
         interpreter::to_jsonSetValue(this, r);
      #endif
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//searchNode
searchNode::searchNode (runNode* str, runNode* regexp) : str_ (str), regexp_(regexp), key_(NULL) {}

searchNode::searchNode (runNode* str, runNode* regexp, runNode* key) : str_ (str), regexp_(regexp), key_ (key) {}

runNode *searchNode::asMethod() {  
   idNode *id_regexp = new idNode("~regexp");
   listNode *params = new listNode(id_regexp, NULL);
   searchNode *node = new searchNode (new thisNode(), id_regexp);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}

void searchNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux1 = str_;
   runNode *node_aux2 = regexp_;
   vector<runNode*> keys;
   nexpNode::resolved(node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   nexpNode::resolved(node_aux2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (listNode * list = dynamic_cast<listNode*> (key_)) {
      list->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      keys = list->listvalue ();
   }
   if (arrayNode * n_array = dynamic_cast<arrayNode*>(node_aux1)) {
      symbols* array = n_array->getArray ();
      isym iter = --array->end();
      listNode *list = NULL;
      for (; iter != array->begin(); iter--) {
         searchNode search (iter.second, node_aux2, key_);
         search.run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif         
         list = new listNode (search.nodeval (), list);
      }
      if (array->begin() != array->end()) {
         searchNode search (iter.second, node_aux2, key_);
         search.run();
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif         
         list = new listNode (search.nodeval (), list);
      }
      noderef(new arrayNode (list));
      #if JSON==1
         interpreter::to_jsonSetValue(this, new arrayNode (list));
      #endif
   }else{
      string s = stringNode::to_str(node_aux1);
      if (regexpNode *ex = dynamic_cast<regexpNode*> (node_aux2)) {
         regex e = ex->exvalue ();
         string::const_iterator start, end;
         start = s.begin();
         end = s.end();
         match_results<std::string::const_iterator> what;
         arrayNode *resp;
         match_flag_type flags = boost::match_default;
         listNode *list_array = NULL;
         vector<arrayNode*> vec_result;
         bool first = true;
         while (start != end && regex_search(start,end, what, e, flags)) {
            int n = what.size ();
            listNode *list = NULL;
            runNode * insert = NULL;
            strNode* str_key;
            if (n == 1) {
               if (key_ && !keys.empty () && (str_key = dynamic_cast<strNode*>(keys[0]))) {
                  insert = new mapNode (new strNode (str_key->strvalue()), new strNode (string (what[0].first, what[0].second)));
               } else {
                  insert = new strNode (string (what[0].first, what[0].second));
               }
               list = new listNode (insert, list);
            } else {
               for (int i = n - 1; i > 0; i--) {
                  if (key_ && keys.size () >= i && (str_key = dynamic_cast<strNode*>(keys[i-1]))) {
                     insert = new mapNode (new strNode (str_key->strvalue()), new strNode (string (what[i].first, what[i].second)));
                  } else {
                     insert = new strNode (string (what[i].first, what[i].second));
                  }
                  list = new listNode (insert, list);
               }
            }
            resp = new arrayNode (list);
            resp->run();
            #if JSON==1
               interpreter::to_jsonRun(this);
            #endif            
            vec_result.push_back (resp);
            if (what[0].first == what[0].second)
               start ++;
            else
               start = what[0].second;
         }
         if (vec_result.size()) {
            listNode *list = NULL;
            for (int i = vec_result.size() - 1; i >= 0; --i)
               list = new listNode (vec_result[i], list);
            runNode * r = new arrayNode (list);
            noderef (r);
            #if JSON==1
               interpreter::to_jsonSetValue(this, r);
            #endif            
         } else {
            runNode * r = new arrayNode ();
            noderef(r);
            #if JSON==1
               interpreter::to_jsonSetValue(this, r);
            #endif
         }            
      }else{
         throw errorException ("Unknow operand", "searchNode: node 2 must be regular expresion", 1);
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
