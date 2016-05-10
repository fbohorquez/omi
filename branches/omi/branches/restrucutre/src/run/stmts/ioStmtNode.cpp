//ioStmtNode.cpp
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
#include "ioStmtNode.h"
#include "../../interpreter.h"
#include "../../error.h"
#include "../operators/opNode.h"
//~ #include "stmtNode.h"
//~ #include "../error.h"
//~ #include <math.h>
//~ #include <stdlib.h>
//~ #include <string>
//~ #include <iostream>
//~ #include <stdio.h>
//~ #include "interpreter.h"
//~ #include "lshParser.h"
//~ #include "operatorRegexpNode.h"
//~ #include "../interpreter.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//printNode
printNode::printNode (runNode* exp, bool newline): 
   exp_ (exp), newline_(newline) {}

void printNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   printableNode *pn;
   runNode *aux;
   arrayNode *a;
   if (exp_) {
      aux = exp_;
      nexpNode::resolved (aux);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      if (objectNode* obj = dynamic_cast<objectNode*>(aux)){
         cout << stringNode::to_str(obj);
         #if JSON==1
            interpreter::to_jsonOut(this, stringNode::to_str(obj) + (newline_?"\n":""));
         #endif
      }
      else if (
         (pn = dynamic_cast<printableNode*>(aux)) && 
         !((bool)dynamic_cast<nullNode*>(aux))
      ) {
         cout << pn->print ();
         #if JSON==1
            interpreter::to_jsonOut(this, pn->print ()  + (newline_?"\n":""));
         #endif
      }
      if (newline_){
            cout << endl;
      }
   }
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//inputNode
inputNode::inputNode (idNode* id, int type, runNode* prompt): 
   id_(id), type_ (type), prompt_ (prompt) {}

void inputNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   string aux0, aux1;
   char c, e;
   if (prompt_) {
      runNode *prompt = prompt_;
      nexpNode::resolved(prompt);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      ostringstream oss;
      if (stringNode *s = dynamic_cast<stringNode*>(prompt)) {
         oss << s->strvalue ();
      } else if (arithNode *n = dynamic_cast<arithNode*>(prompt)) {
         oss << n->numvalue ();
      } else if (logicNode *l = dynamic_cast<logicNode*>(prompt)) {
         oss << l->boolvalue ();
      } else {
         throw errorException (
            "Wrong data type", "inputNode: prompt is a wrong type", 
            1
         );
      }
      cout << oss.str();
      #if JSON==1
         interpreter::to_jsonOut(this, oss.str() + ((type_ == 1)?" ":"\n"));
      #endif
      switch (type_) {
      default:
      case 0:
         cout << endl;
         break;
      case 1:
         cout << " ";
         break;
      }
   }
   #if JSON==1
   if(interpreter::get()->json) {
      aux0 = interpreter::to_jsonInput(this);
   }else {
   #endif
      switch (type_) {
         default:
         case 0:
            getline(cin, aux0);;
            while (true) {
               getline(cin, aux1);
               if (aux1.empty()) {
                  break;
               } else {
                  aux0 += ('\n' + aux1);
               }
            }
            break;
         case 1:
            getline(cin, aux0);
            break;
      }
   #if JSON==1
   }
   #endif
   strNode s (aux0);
   asigNode asig (id_, &s);
   asig.run ();    
   strvalue_ = aux0;
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif    
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
