//strOpNode.cpp
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
#include "strOpNode.h"
#include "../../interpreter.h"
#include "../../error.h"

#define END_STR -1
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//catNode
catNode::catNode (runNode* node1, runNode*node2, bool newline):
   node1_ (node1),
   node2_(node2),
   newline_(newline) {}

void catNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   strvalue_ = catNode::do_cat (op1,op2, this->newline_);
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif
}

string catNode::do_cat (runNode *op1, runNode *op2, bool newline) {
   ostringstream oss;
   oss << stringNode::to_str(op1);
   if (newline)
     oss << endl; 
   oss << stringNode::to_str(op2);
   return oss.str();
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// explodeNode
explodeNode::explodeNode(runNode * substr, runNode * str):
   str_(str),
   substr_(substr) {}

void
explodeNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node_aux1 = substr_;
   runNode *node_aux2 = str_;
   nexpNode::resolved(node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(node_aux2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   arrayNode *array = new arrayNode();
   symbols *v_array = array->getArray();
   int count = 0;
   int pos = 0;
   string substr = stringNode::to_str(node_aux1);
   string str = stringNode::to_str(node_aux2);
   if(substr != "") {
      string elem = str;
      while((pos = str.find(substr)) != string::npos) {
         elem = str.substr(0, pos);
         str = str.substr(pos + substr.size());
         (*v_array)[new numNode(count)] = new strNode(elem);
         count++;
      }
      (*v_array)[new numNode(count)] = new strNode(str);
   } else
      for(; count < str.size(); ++count)
         (*v_array)[new numNode(count)] = new strNode(str.substr(count, 1));
   runNode *node = array;
   noderef (node);
   #if JSON==1
      interpreter::to_jsonSetValue(this, node);
   #endif   
}
runNode *explodeNode::asMethod() {  
   idNode *id = new idNode("~substr");
   listNode *params = new listNode(id, NULL);
   explodeNode *node = new explodeNode (id, new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//sprintfNode
sprintfNode::sprintfNode(runNode * list):list_(list) {}

void
sprintfNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   strvalue_ = "";
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif   
   if(listNode * l = dynamic_cast < listNode * >(list_)) {
      l->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      vector < runNode * >vec = l->listvalue();
      if(vec.size() != 0) {
         vector < runNode * >::iterator iter = vec.begin();
         runNode *node_aux = *iter;
         nexpNode::resolved(node_aux);
         #if JSON==1
            interpreter::to_jsonRun(this);
         #endif         
         string s = stringNode::to_str(node_aux);
         vector < runNode * >vec_param;
         for(++iter; iter != vec.end(); ++iter) {
            vec_param.push_back(*iter);
         }
         int pos = -2;
         int count = 0;
         while((pos = s.find("%", pos + 2)) != string::npos) {
            count++;
            if(s[pos + 1] == '%')
               count--;
         }
         if(count == vec_param.size()) {
            int pos_vec = 0;
            pos = 0;
            while((pos = s.find("%", pos)) != string::npos) {
               bool use_param = true;
               runNode *node_aux_p;
               if(pos_vec < vec_param.size()) {
                  node_aux_p = vec_param[pos_vec];
                  nexpNode::resolved(node_aux_p);
                  #if JSON==1
                     interpreter::to_jsonRun(this);
                  #endif
               }
               int end_exp = s.size();
               int frist_op = s.find('d', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('i', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('u', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('f', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('F', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('e', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('o', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('s', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('c', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('x', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('X', pos);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               frist_op = s.find('%', pos + 1);
               if(frist_op != string::npos && end_exp > frist_op)
                  end_exp = frist_op;
               string expresion = s.substr(pos + 1, end_exp - pos);
               ostringstream out(ostringstream::out);
               out << expresion[expresion.size() - 1];
               string cad = out.str();
               char flag = ' ';
               if(expresion[0] == '+')
                  flag = '+';
               else if(expresion[0] == '#')
                  flag = '#';
               else if(expresion[0] == '^')
                  flag = '^';
               int precision = 0;
               if(expresion.substr(((flag != ' ') ? 1 : 0), expresion.size() - 1) != "") {
                  istringstream ini(expresion.substr(0, expresion.size () - 1));
                  ini >> precision;
               }
               if(cad == "d" || cad == "i") {
                  //~ istringstream ini(stringNode::to_str(node_aux_p));
                  //~ int integer;
                  //~ ini >> integer;
                  int integer = arithNode::to_num (node_aux_p);
                  ostringstream outi(ostringstream::out);
                  ostringstream outk(ostringstream::out);
                  outi << integer;
                  if(flag == '+') {
                     if(integer > 0)
                        outk << "+";
                  }
                  if(precision) {
                     if(precision - outi.str().size() > 0) {
                        for(int i = 0;
                              i <
                              precision - outi.str().size();
                              i++) {
                           outk << "0";
                        }
                     }
                  }
                  outk << outi.str();
                  s = s.replace(pos, expresion.size() + 1, outk.str());
               } else if(cad == "u") {
                     istringstream ini(stringNode::to_str(node_aux_p));
                     int integer;
                     ini >> integer;
                     integer = abs(integer);
                     ostringstream outi(ostringstream::out);
                     ostringstream outk(ostringstream::out);
                     outi << integer;
                     if(precision) {
                        if(precision - outi.str().size() > 0) {
                           for(int i = 0; i < precision - outi.str().size(); i++) { outk << "0";
                           }
                        }
                     }
                     outk << outi.str();
                     s = s.replace(pos, expresion.size() + 1,outk.str());
               } else if(cad == "f") {
                     istringstream ini(stringNode::to_str(node_aux_p));
                     num doub;
                     ini >> doub;
                     ostringstream outi(ostringstream::out);
                     if(precision) outi.precision(precision);
                     if(flag == '+')
                        if(doub > 0) 
                           outi << "+";
                     outi << doub;
                     s = s.replace(pos, expresion.size() + 1, outi.str());
               } else if(cad == "F") {
                     istringstream ini(stringNode::to_str(node_aux_p));
                     num doub;
                     ini >> doub;
                     ostringstream outi(ostringstream::out);
                     outi.flags(ios_base::uppercase);
                     if(precision)
                        outi.precision(precision);
                     if(flag == '+')
                        if(doub > 0)
                           outi << "+";
                     outi << doub;
                     string upper = outi.str();
                     std::transform(upper.begin(), upper.end(), upper.begin(),::toupper);
                     s = s.replace(pos, expresion.size() + 1, upper);
               } else if(cad == "%") {
                  s = s.replace(pos, expresion.size() + 1, "%");
                  use_param = false;
               } else if(cad == "e") {
                     istringstream ini(stringNode::to_str(node_aux_p));
                     num doub;
                     ini >> doub;
                     ostringstream outi(ostringstream::out);
                     outi.flags(ios_base::scientific);
                     if(precision)
                        outi.precision(precision);
                     if(flag == '+')
                        if(doub > 0)
                           outi << "+";
                     outi << doub;
                     s = s.replace(pos, expresion.size() + 1, outi.str());
               } else if(cad == "E") {
                     istringstream ini(stringNode::to_str(node_aux_p));
                     num doub;
                     ini >> doub;
                     ostringstream outi(ostringstream::out);
                     outi.flags(ios_base::scientific | ios_base::uppercase);
                     if(precision)
                        outi.precision(precision);
                     if(flag == '+')
                        if(doub > 0)
                           outi << "+";
                     outi << doub;
                     s = s.replace(pos, expresion.size() + 1, outi.str());
               } else if(cad == "o") {
                     istringstream ini(stringNode::to_str(node_aux_p));
                     int integer;
                     ini >> integer;
                     integer = abs(integer);
                     ostringstream outi(ostringstream::out);
                     ostringstream outk(ostringstream::out);
                     if(flag == '#') {
                        outi.flags(ios_base::oct | ios::showbase);
                        outk.flags(ios_base::oct | ios::showbase);
                     } else {
                        outi.flags(ios_base::oct);
                        outk.flags(ios_base::oct);
                     }
                     outi << integer;
                     if(precision) {
                        if(precision - outi.str().size() > 0) {
                           for(int i = 0; i < precision - outi.str().size(); i++) {
                              outk << "0";
                           }
                        }
                     }
                     outk << outi.str();
                     s = s.replace(pos, expresion.size() + 1, outk.str());
               } else if(cad == "x") {
                     istringstream ini(stringNode::to_str(node_aux_p));
                     int integer;
                     ini >> integer;
                     integer = abs(integer);
                     ostringstream outi(ostringstream::out);
                     ostringstream outk(ostringstream::out);
                     if(flag == '#') {
                        outi.flags(ios_base::hex | ios::showbase);
                        outk.flags(ios_base::hex | ios::showbase);
                     } else {
                        outi.flags(ios_base::hex);
                        outk.flags(ios_base::hex);
                     }
                     outi << integer;
                     if(precision) {
                        if(precision - outi.str().size() > 0) {
                           for(int i = 0; i < precision - outi.str().size(); i++) { outk << "0";
                           }
                        }
                     }
                     outk << outi.str();
                     s = s.replace(pos, expresion.size() + 1, outk.str());
               } else if(cad == "X") {
                     istringstream ini(stringNode::to_str(node_aux_p));
                     int integer;
                     ini >> integer;
                     integer = abs(integer);
                     ostringstream outi(ostringstream::out);
                     ostringstream outk(ostringstream::out);
                     if(flag == '#') {
                        outi.flags(ios_base::hex | ios_base::uppercase | ios::showbase);
                        outk.flags(ios_base::hex | ios_base::uppercase | ios::showbase);
                     } else {
                        outi.flags(ios_base::hex);
                        outk.flags(ios_base::hex);
                     }
                     outi << integer;
                     if(precision) {
                        if(precision - outi.str().size() > 0) {
                           for(int i = 0; i < precision - outi.str().size(); i++) outk << "0";
                        }
                     }
                     outk << outi.str();
                     s = s.replace(pos, expresion.size() + 1, outk.str());
               } else if(cad == "s" || cad == "c") {
                  if(stringNode * value =
                           dynamic_cast < stringNode * >(node_aux_p)) {
                     string val = value->strvalue();
                     if(flag == '^') {
                        std::transform(val.begin(), val.end(), val.begin(),::toupper);
                     }
                     if(precision) {
                        if(precision - val.size() > 0) {
                           val = val.substr(0, precision);
                        }
                     }
                     s.replace(pos, expresion.size() + 1, val);
                  } else if(arithNode * d =
                               dynamic_cast < arithNode * >(node_aux_p)) {
                     strNode value(d);
                     s = s.replace(pos, expresion.size() + 1, value.strvalue());
                  }
               }
               if(use_param) pos_vec++;
               pos += expresion.size() + 1;
            }
            strvalue_ = s;
            #if JSON==1
               interpreter::to_jsonSetValue(this, strvalue_);
            #endif
         } else {
            throw errorException("number of parameters", "sprintfNode: wrong number of parameters ", 1);
         }
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//findNode
runNode *findNode::asMethod() {  
   
   idNode *id = new idNode("~substr");
   idNode *idpos = new idNode("~pos");
   numNode * default_pos = new numNode ((num)0);
   asigNode *a = new asigNode (idpos, default_pos);
   listNode *params = new listNode(id, a);
   findNode *node = new findNode (new thisNode(), id, idpos);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}

findNode::findNode(runNode * cad, runNode * subcad, runNode * ini_pos):cad_(cad), subcad_(subcad), ini_pos_ (ini_pos) {}

void
findNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux1 = cad_, *node_aux2 = subcad_, *node_aux3 = ini_pos_;
   nexpNode::resolved(node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(node_aux2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (node_aux3) {
      nexpNode::resolved(node_aux3);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }   
   string s = stringNode::to_str (node_aux1);
   if(!dynamic_cast < regexpNode * >(node_aux2)) {
      string subs = stringNode::to_str (node_aux2);
      int ini = 0;
      if(node_aux3 != NULL) 
         ini = arithNode::to_num (node_aux3);
      if(s.find(subs, ini) != string::npos){
         numvalue_ = s.find(subs, ini);
         #if JSON==1
            interpreter::to_jsonSetValue(this, numvalue_);
         #endif         
      }else{
         numvalue_ = END_STR;
         #if JSON==1
            interpreter::to_jsonSetValue(this, numvalue_);
         #endif         
      }
   } else {
      string::iterator ini = s.begin();
      int i = 0;
      if(regexpNode * reg = dynamic_cast < regexpNode * >(node_aux2)) {
         regex r = reg->exvalue();
         if(arithNode * num1 = dynamic_cast < arithNode * >(node_aux3)) {
            i = num1->numvalue();
            for(int k = 0; k < i; k++) ini++;
         } else if(stringNode * str1 = dynamic_cast < stringNode * >(node_aux3)) {
            numNode num1(str1->strvalue());
            i = num1.numvalue();
            for(int k = 0; k < i; k++) ini++;
         }
         match_results < std::string::iterator > what;
         if(regex_search(ini, s.end(), what, r)) {
            numvalue_ = distance(s.begin(), what[0].first);
            #if JSON==1
               interpreter::to_jsonSetValue(this, numvalue_);
            #endif
         } else {
            numvalue_ = -1;
            #if JSON==1
               interpreter::to_jsonSetValue(this, numvalue_);
            #endif
         }
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//replaceNode
runNode *replaceNode::asMethod() {  
   idNode *id = new idNode("~substr");
   idNode *idnumremplace = new idNode("~numreplace");
   idNode *idreplace = new idNode("~replace");
   nullNode * default_numremplace = new nullNode();
   asigNode *a = new asigNode (idnumremplace, default_numremplace);
   listNode *params = new listNode(id, new listNode (idreplace, a));
   replaceNode *node = new replaceNode (id, idreplace, new thisNode(), idnumremplace);
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}

replaceNode::replaceNode(runNode * search, runNode * replace, runNode * cad, runNode * num_replace):
   search_(search),
   replace_(replace), cad_(cad), num_replace_(num_replace) {}

void
replaceNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux1 = search_, *node_aux2 = replace_, *node_aux3 = cad_, *node_aux4 = num_replace_;
   nexpNode::resolved(node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(node_aux2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(node_aux3);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if(node_aux4){ 
      nexpNode::resolved(node_aux4);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }  
   string s_replace = stringNode::to_str(node_aux2), s_cad = stringNode::to_str(node_aux3);
   if(!dynamic_cast < regexpNode * >(node_aux1)) {
         string s_search = stringNode::to_str(node_aux1);
         if (s_search == "") {
            strvalue_ = s_cad;
            #if JSON==1
               interpreter::to_jsonSetValue(this, strvalue_);
            #endif
            return ;
         }
         if(node_aux4 != NULL && !dynamic_cast<nullNode*>(node_aux4)) {
            int n_replace = arithNode::to_num(node_aux4);
            int count = 0;
            int pos = 0;
            if(n_replace < 0) {
               string aux = s_cad;
               s_cad.clear();
               for(int i = aux.size() - 1; i >= 0; --i) {
                  s_cad.push_back(aux[i]);
               }
               aux = s_search;
               s_search.clear();
               for(int i = aux.size() - 1; i >= 0; --i) {
                  s_search.push_back(aux[i]);
               }
               aux = s_replace;
               s_replace.clear();
               for(int i = aux.size() - 1; i >= 0; --i) {
                  s_replace.push_back(aux[i]);
               }
            }
            while(count < abs(n_replace) &&((pos = s_cad.find(s_search, pos)) != string::npos)) {
               s_cad = s_cad.replace(pos, s_search.size(), s_replace);
               pos += s_replace.size();
               count++;
            }
            if(n_replace < 0) {
               string aux = s_cad;
               s_cad.clear();
               for(int i = aux.size() - 1; i >= 0; --i) {
                  s_cad.push_back(aux[i]);
               }
            }
         } else {
            int pos = 0;
            while((pos = s_cad.find(s_search, pos)) != string::npos) {
               s_cad = s_cad.replace(pos, s_search.size(), s_replace);
               pos += s_replace.size();
            }
         }
         strvalue_ = s_cad;
         #if JSON==1
            interpreter::to_jsonSetValue(this, strvalue_);
         #endif
   } else {
      if(regexpNode * reg = dynamic_cast < regexpNode * >(node_aux1)) {
         match_results < std::string::const_iterator > what;
         match_flag_type flags = boost::match_default;
         regex r = reg->exvalue();
         string::const_iterator start, end;
         start = s_cad.begin();
         end = s_cad.end();
         int pos = 0;
         string aux_cad = s_cad;
         while(start != end && regex_search(start, end, what, r, flags)) {
            string::iterator iter_count = s_cad.begin();
            int count = 0;
            while(iter_count != what[0].first) {
               iter_count++;
               count++;
            }
            string aux_replace = s_replace;
            if((pos = aux_replace.find("\\0")) != string::npos)
               aux_replace = aux_replace.replace (pos, 2, string(what[0]. first, what[0].second));
            if(what.size() > 1) {
               for(int i = 1; i < what.size(); i++) {
                  ostringstream oss(ostringstream::out);
                  oss << '\\' << i;
                  if((pos = aux_replace.find(oss.str())) != string::npos)
                     aux_replace = aux_replace.replace(pos, 2, string(what[i].first, what[i].second));
               }
            }
            string::iterator iter_first = s_cad.begin(), iter_second;
            while(iter_first != what[0].first && iter_first != s_cad.end())
               iter_first++;
            iter_second = iter_first;
            while(iter_second != what[0].second && iter_second != s_cad.end())
               iter_second++;
            int size_b = s_cad.size();
            s_cad = s_cad.replace(iter_first, iter_second, aux_replace);
            start = s_cad.begin();
            end = s_cad.end();
            while(count > 0) {
               start++;
               count--;
            }
            for(int i = 0; i < aux_replace.size(); i++) {
               start++;
            }
            if(what[0].first == what[0].second)
               start++;
         }
         strvalue_ = s_cad;
         #if JSON==1
            interpreter::to_jsonSetValue(this, strvalue_);
         #endif
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//subreplaceNode
runNode *subreplaceNode::asMethod() {  
   idNode *id_ini = new idNode("~ini");
   idNode *id_len = new idNode("~len");
   idNode *id_replace = new idNode("~replace");
   listNode *params = new listNode(id_ini, new listNode (id_len, id_replace));
   subreplaceNode *node = new subreplaceNode (id_ini, id_len, id_replace, new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, params, body);
}

subreplaceNode::subreplaceNode (runNode* ini, runNode *len, runNode *replace, runNode* str):
   ini_ (ini),
   len_ (len),
   replace_ (replace),
   str_ (str) {}
   
void 
subreplaceNode::run (){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *ini = ini_, *len = len_, *replace = replace_, *str = str_;
   nexpNode::resolved(ini);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(len);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(replace);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(str);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   string s = stringNode::to_str (str), r = stringNode::to_str (replace);
   int i = arithNode::to_num (ini), l = arithNode::to_num (len);
   if (i >= 0 && i < s.size()) {
      strvalue_ = s.replace (i, l, r);
      #if JSON==1
         interpreter::to_jsonSetValue(this, strvalue_);
      #endif
   }else
      throw errorException("Wrong index", "subreplaceNode: init index is wrong", 1);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//upperNode
upperNode::upperNode(runNode * cad):cad_(cad) {}

runNode*
upperNode::asMethod() {  
   upperNode *node = new upperNode (new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, NULL, body);
}

void
upperNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux1 = cad_;
   nexpNode::resolved(node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   string value = stringNode::to_str(node_aux1);
   transform(value.begin(), value.end(), value.begin(),::toupper);
   strvalue_ = value;
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif   
}

//----------------------------------------------------------------------

//----------------------------------------------------------------------
//lowerNode
lowerNode::lowerNode(runNode * cad):cad_(cad) {}

runNode*
lowerNode::asMethod() {  
   lowerNode *node = new lowerNode (new thisNode());
   runNode *body = new returnNode(node);
   return new functionNode(NULL, NULL, body);
}

void
lowerNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node_aux1 = cad_;
   nexpNode::resolved(node_aux1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   string value = stringNode::to_str (node_aux1);
   transform(value.begin(), value.end(), value.begin(),::tolower);
   strvalue_ = value;
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif   
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
