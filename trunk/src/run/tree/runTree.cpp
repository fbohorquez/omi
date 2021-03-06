//runTree.cpp
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
#include "runTree.h"
#include "typeNode.h"
#include "../../interpreter.h"

//----------------------------------------------------------------------

//----------------------------------------------------------------------
//runNode

runNode::runNode (string str) : ref_count_ (1) {
   if (stringNode* s = dynamic_cast<stringNode*> (this)){
      s->setStrValue(str);
   }
}

runNode::runNode () : ref_count_ (0), isprivate_ (false) {}

 void runNode::addRef () {
   ref_count_ ++;
}

void runNode::rmRef () {
   ref_count_ --;
   if (ref_count_ == 0) {
      #if JSON==1
         interpreter::to_jsonDelete(this);
      #endif
      delete this;
   }
}

bool runNode::compare(runNode  *node1, runNode *node2, int op) {
   
   runNode* node_aux1 = node1;
   runNode* node_aux2 = node2;
   idNode* id = dynamic_cast<idNode*> (node_aux1);
   if (id) node_aux1 = id->nodeval();
   id = dynamic_cast<idNode*> (node_aux2);
   if (id) node_aux2 = id->nodeval();
   expNode* exp = dynamic_cast<expNode*> (node_aux1);
   if (exp) {
      node_aux1 = exp;
   }
   exp = dynamic_cast<expNode*> (node_aux2);
   if (exp) {
      exp->run();
      node_aux2 = exp;
   }
   node_aux1->run();
   node_aux2->run();
   logicNode *l1, *l2;
   arithNode *n1, *n2;
   stringNode *s1, *s2;
   refNode *k1, *k2;
   l1 = dynamic_cast<logicNode*>(node_aux1);
   l2 = dynamic_cast<logicNode*>(node_aux2);
   n1 = dynamic_cast<arithNode*>(node_aux1);
   n2 = dynamic_cast<arithNode*>(node_aux2);
   s1 = dynamic_cast<stringNode*>(node_aux1);
   s2 = dynamic_cast<stringNode*>(node_aux2);
   k1 = dynamic_cast<refNode*>(node_aux1);
   k2 = dynamic_cast<refNode*>(node_aux2);
   if (k1) {
      if (s2) {
         switch (op) {
         case 0: return (k1->strvalue() == s2->strvalue());
         case 1: return (k1->strvalue() != s2->strvalue());
         case 2:	 return (k1->strvalue() > s2->strvalue());
         case 3:	 return (k1->strvalue() < s2->strvalue());
         case 4:	 return (k1->strvalue() >= s2->strvalue());
         case 5:	 return (k1->strvalue() <= s2->strvalue());
         case 6: return (k1->strvalue() == s2->strvalue());
         }
     } else if (k2) {
         switch (op) {
         case 0: return (k1->strvalue() == k2->strvalue());
         case 1: return (k1->strvalue() != k2->strvalue());
         case 2:	 return (k1->strvalue() > k2->strvalue());
         case 3:	 return (k1->strvalue() < k2->strvalue());
         case 4:	 return (k1->strvalue() >= k2->strvalue());
         case 5:	 return (k1->strvalue() <= k2->strvalue());
         case 6: return (k1->strvalue() == k2->strvalue());
         }
      } else if (n2) {
         switch (op) {
         case 0: return (k1->numvalue() == n2->numvalue());
         case 1: return (k1->numvalue() != n2->numvalue());
         case 2:	 return (k1->numvalue() > n2->numvalue());
         case 3:	 return (k1->numvalue() < n2->numvalue());
         case 4:	 return (k1->numvalue() >= n2->numvalue());
         case 5:	 return (k1->numvalue() <= n2->numvalue());
         case 6: return false;
         }
      } else if (l2) {
         switch (op) {
         case 0: return (k1->boolvalue() == l2->boolvalue());
         case 1: return (k1->boolvalue() != l2->boolvalue());
         case 2:	 return (k1->boolvalue() > l2->boolvalue());
         case 3:	 return (k1->boolvalue() < l2->boolvalue());
         case 4:	 return (k1->boolvalue() >= l2->boolvalue());
         case 5:	 return (k1->boolvalue() <= l2->boolvalue());
         case 6: return false;
         }
      } else {
         switch (op) {
         case 0: return false;
         case 1: return true;
         case 2:	 return false;
         case 3:	 return true;
         case 4:	 return false;
         case 5:	 return true;
         case 6: return false;
         }
      }
   } else if (s1) {
      if (s2) {
         switch (op) {
         case 0: return (s1->strvalue() == s2->strvalue());
         case 1: return (s1->strvalue() != s2->strvalue());
         case 2:	 return (s1->strvalue() > s2->strvalue());
         case 3:	 return (s1->strvalue() < s2->strvalue());
         case 4:	 return (s1->strvalue() >= s2->strvalue());
         case 5:	 return (s1->strvalue() <= s2->strvalue());
         case 6: return (s1->strvalue() == s2->strvalue());
         }
     } else if (k2) {
         switch (op) {
         case 0: return (s1->strvalue() == k2->strvalue());
         case 1: return (s1->strvalue() != k2->strvalue());
         case 2:	 return (s1->strvalue() > k2->strvalue());
         case 3:	 return (s1->strvalue() < k2->strvalue());
         case 4:	 return (s1->strvalue() >= k2->strvalue());
         case 5:	 return (s1->strvalue() <= k2->strvalue());
         case 6: return (s1->strvalue() == k2->strvalue());
         }
      } else if (n2) {
         switch (op) {
         case 0: return (s1->numvalue() == n2->numvalue());
         case 1: return (s1->numvalue() != n2->numvalue());
         case 2:	 return (s1->numvalue() > n2->numvalue());
         case 3:	 return (s1->numvalue() < n2->numvalue());
         case 4:	 return (s1->numvalue() >= n2->numvalue());
         case 5:	 return (s1->numvalue() <= n2->numvalue());
         case 6: return false;
         }
      } else if (l2) {
         switch (op) {
         case 0: return (s1->boolvalue() == l2->boolvalue());
         case 1: return (s1->boolvalue() != l2->boolvalue());
         case 2:	 return (s1->boolvalue() > l2->boolvalue());
         case 3:	 return (s1->boolvalue() < l2->boolvalue());
         case 4:	 return (s1->boolvalue() >= l2->boolvalue());
         case 5:	 return (s1->boolvalue() <= l2->boolvalue());
         case 6: return false;
         }
      } else {
         switch (op) {
         case 0: return false;
         case 1: return true;
         case 2:	 return false;
         case 3:	 return true;
         case 4:	 return false;
         case 5:	 return true;
         case 6: return false;
         }
      }
   } else if (n1) {
      if (s2) {
         switch (op) {
         case 0: return (n1->numvalue() == s2->numvalue());
         case 1: return (n1->numvalue() != s2->numvalue());
         case 2:	 return (n1->numvalue() > s2->numvalue());
         case 3:	 return (n1->numvalue() < s2->numvalue());
         case 4:	 return (n1->numvalue() >= s2->numvalue());
         case 5:	 return (n1->numvalue() <= s2->numvalue());
         case 6: return false;
         }
      } else if (k2) {
         switch (op) {
         case 0: return (n1->numvalue() == k2->numvalue());
         case 1: return (n1->numvalue() != k2->numvalue());
         case 2:	 return (n1->numvalue() > k2->numvalue());
         case 3:	 return (n1->numvalue() < k2->numvalue());
         case 4:	 return (n1->numvalue() >= k2->numvalue());
         case 5:	 return (n1->numvalue() <= k2->numvalue());
         case 6: return false;
         }
      } else if (n2) {
         switch (op) {
         case 0: return (n1->numvalue() == n2->numvalue());
         case 1: return (n1->numvalue() != n2->numvalue());
         case 2:	 return (n1->numvalue() > n2->numvalue());
         case 3:	 return (n1->numvalue() < n2->numvalue());
         case 4:	 return (n1->numvalue() >= n2->numvalue());
         case 5:	 return (n1->numvalue() <= n2->numvalue());
         case 6: return (n1->numvalue() == n2->numvalue());
         }
      } else if (l2) {
         switch (op) {
         case 0: return (n1->boolvalue() == l2->boolvalue());
         case 1: return (n1->boolvalue() != l2->boolvalue());
         case 2:	 return (n1->boolvalue() > l2->boolvalue());
         case 3:	 return (n1->boolvalue() < l2->boolvalue());
         case 4:	 return (n1->boolvalue() >= l2->boolvalue());
         case 5:	 return (n1->boolvalue() <= l2->boolvalue());
         case 6: return false;
         }
      } else {
         switch (op) {
         case 0: return false;
         case 1: return true;
         case 2:	 return false;
         case 3:	 return true;
         case 4:	 return false;
         case 5:	 return true;
         case 6: return false;
         }
      }
   } else if (l1) {
      if (s2) {
         switch (op) {
         case 0: return (l1->boolvalue() == s2->boolvalue());
         case 1: return (l1->boolvalue() != s2->boolvalue());
         case 2:	 return (l1->boolvalue() > s2->boolvalue());
         case 3:	 return (l1->boolvalue() < s2->boolvalue());
         case 4:	 return (l1->boolvalue() >= s2->boolvalue());
         case 5:	 return (l1->boolvalue() <= s2->boolvalue());
         case 6: return false;
         }
      } else if (k2) {
         switch (op) {
         case 0: return (l1->boolvalue() == k2->boolvalue());
         case 1: return (l1->boolvalue() != k2->boolvalue());
         case 2:	 return (l1->boolvalue() > k2->boolvalue());
         case 3:	 return (l1->boolvalue() < k2->boolvalue());
         case 4:	 return (l1->boolvalue() >= k2->boolvalue());
         case 5:	 return (l1->boolvalue() <= k2->boolvalue());
         case 6: return false;
         }
      } else if (n2) {
         switch (op) {
         case 0: return (l1->boolvalue() == n2->boolvalue());
         case 1: return (l1->boolvalue() != n2->boolvalue());
         case 2:	 return (l1->boolvalue() > n2->boolvalue());
         case 3:	 return (l1->boolvalue() < n2->boolvalue());
         case 4:	 return (l1->boolvalue() >= n2->boolvalue());
         case 5:	 return (l1->boolvalue() <= n2->boolvalue());
         case 6: return false;
         }
      } else if (l2) {
         switch (op) {
         case 0: return (l1->boolvalue() == l2->boolvalue());
         case 1: return (l1->boolvalue() != l2->boolvalue());
         case 2:	 return (l1->boolvalue() > l2->boolvalue());
         case 3:	 return (l1->boolvalue() < l2->boolvalue());
         case 4:	 return (l1->boolvalue() >= l2->boolvalue());
         case 5:	 return (l1->boolvalue() <= l2->boolvalue());
         case 6: return (l1->boolvalue() == l2->boolvalue());
         }
      } else {
         switch (op) {
         case 0: return false;
         case 1: return true;
         case 2:	 return false;
         case 3:	 return true;
         case 4:	 return false;
         case 5:	 return true;
         case 6: return false;
         }
      }
   }
   switch (op) {
   case 0: return true;
   case 1: return false;
   case 2:	 return true;
   case 3:	 return false;
   case 4:	 return true;
   case 5:	 return false;
   case 6: return false;
   }
   return false;
}

//~ void runNode::runRev (vector<runNode*> params) {  }

bool runNode::is_print () const {
   return true;
}

bool runNode::is_runlist () const {
   return false;
}

bool runNode::is_string () const {
   return false;
}

//~ runNode* runNode::cloneNode (runNode* node) {
   //~ return NULL;
//~ }

string runNode::getPtrString () {
   std::stringstream ss;
   ss << this; 
   return ss.str();
}

#if JSON==1  
string runNode::toJson (string name, string type, runNode** rel, string* relname, int rel_n, string value, string key) {
   std::stringstream ss;
   dexpNode* d  = NULL;
   ss << this;  
   string s = "{";
   s += "\"id\":\"" + ss.str() + "\",";
   s += "\"name\":\"" + ((name.find("Node") !=  string::npos)?name.substr(0, name.length()-4):name) + "\",";
   s += "\"type\":\"" + type + "\"," ;
   ss.str("");
   ss << sizeof *this;
   s += "\"size\":\"" + ss.str() + "Bytes\",";
   if (value != ""){
      s += "\"value\":\"" + value + "\",";
   }
   else if ((d = dynamic_cast<dexpNode*> (this)) && (interpreter::get()->json_init)){
      s += "\"value\":\"" + d->strvalue() + "\",";
   }
   if (key != "") {
      s += "\"key\": \"" + key +"\",";
   }
   if (rel_n){
      s += "\"rel\": [";
      for (int i = 0; i < rel_n; ++i) {
         s += rel[i]->json + ",";
      }
      s += "],";
   }
   if (rel_n && relname){
      s += "\"relname\": [";
      for (int i = 0; i < rel_n; ++i) {
         s += "\"" + relname[i] +  "\",";
      }
      s += "],";
   }
   s += "}";
   return json = s;
} 

string runNode::toJson (string name, string type, runNode** rel, string* relname, int rel_n, num value) {
   std::stringstream ss;
   ss << value;
   return toJson (name, type, rel, relname, rel_n, ss.str());
} 
#endif

bool runNode::to_bool () { 
   return logicNode::to_bool (this);
}

num runNode::to_num () { 
   return arithNode::to_num(this);
}

string runNode::to_str () { 
   return stringNode::to_str (this);
}

runNode::~runNode () {}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//refNode
refNode::refNode() : keyvalue_ (""), refSymbol_ (NULL){}

refNode::refNode(string str) : keyvalue_ (str), refSymbol_ (NULL){}

refNode::refNode(runNode* data) : keyvalue_ (""), refSymbol_ (NULL) {
   if (refNode * aux = dynamic_cast<refNode*> (data)) {
      keyvalue_ = aux->keyvalue_;
      refSymbol_ = aux->refSymbol_;
   }
   else if (stringNode * str = dynamic_cast<stringNode*>(data)){
      keyvalue_ = str->strvalue();
   }
   else {
      keyvalue_ = stringNode::to_str(data);
   }
}

refNode::refNode (refNode *a) : keyvalue_ (a->keyvalue_), refSymbol_ (a->refSymbol_){}

void refNode::setRef (runNode* node ) {
   refSymbol_ = node;
}

runNode* refNode::getRef () const {
   return refSymbol_ ;
}

runNode* &refNode::getRef () {
   return refSymbol_ ;
}
void refNode::run () {}

void refNode::rmRef () {}

void refNode::del () {
   if (!ref_count_)
      delete this;
}

string refNode::strvalue () {
   return keyvalue_;
}

int refNode::numvalue () {
   return keyvalue_.size();
}

bool refNode::boolvalue () {
   return keyvalue_ == "";
}

string refNode::print () const {
   if (printableNode* p = (printableNode*)dynamic_cast<printableNode*>(this->getRef()))
      return p->print();
   return "";
}

void refNode::setKey (string s) {
   keyvalue_ = s;
}

string refNode::getKey () {
   return keyvalue_;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//objectTypeNode
objectTypeNode::objectTypeNode () : custom_class_ (NULL){}

runNode* objectTypeNode::getMethod (runNode *key) {
   if (classNode * c = dynamic_cast<classNode*> (getClass())) {
      return c->getMethod (key);
   }
}

refNode* objectTypeNode::getMethodRef (runNode *key) {
   if (classNode * c = dynamic_cast<classNode*> (getClass())) {
      return c->getMethodRef (key);
   }
}

runNode * objectTypeNode::getClass () {
   return NULL;
}

 void objectTypeNode::setClass (runNode * c) {
   custom_class_ = c;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla

