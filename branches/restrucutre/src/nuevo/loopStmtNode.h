//loopStmtNode.h
//-------------------------------------------------------------------------------------------
/*
 * Fco. Javier Bohórquez Ogalla
 * 75766599-E
 * Puerto Real (Cádiz)
 * powersgame@gmail.com
 */
//-------------------------------------------------------------------------------------------

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
/**
 * \file loopStmtNode.h
 * \brief Nodos sentencias iterativas.
 * 
 * En este fichero se define los nodos correspondientes a las distintas sentencias
 * de control iterativas. Estos son modelados mediante clases de objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_STMTS_FILEOPNODE_
#define _RUN_STMTS_FILEOPNODE_

#include "../tree/typeNode.h"
#include "../operators/opNode.h"
#include "../../error.h"
#include "../../interpreter.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \file whileNode
 * \brief Nodos operadores y funciones sobre .
 * 
*/
class whileNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    * \param exp Nodo .
    * \param rb Nodo
    */      
   whileNode (runNode* exp, runNode* rb);
   void run ();
 private:
   runNode *exp_, *rb_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \file dowhileNode
 * \brief Nodos operadores y funciones sobre .
 * 
*/
class dowhileNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    * \param exp Nodo .
    * \param rb Nodo
    */   
   dowhileNode (runNode* exp, runNode* rb);
   /**
    * Método de ejecución del nodo.
    *
    */     
   void run ();
 private:
   runNode *exp_, *rb_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \file foreachNode
 * \brief Nodos operadores y funciones sobre .
 * 
*/
class foreachNode :
   public runNode {
 public:
    /**
    * Constructor de la clase. 
    * \param val Nodo .
    * \param exp
    * \param rb Nodo .
    * \param key
    */   
   foreachNode (runNode* val, runNode* exp, runNode* rb = NULL, runNode* key = NULL);
   /**
    * Método de ejecución del nodo.
    *
    */     
   void run ();
 private:
   /**
    * Método de ejecución del nodo.
    *
    */    
   void run_case_num ( numNode * n);
   /**
    * Método de ejecución del nodo.
    *
    */     
   void run_case_array ( arrayNode * a);
   /**
    * Método de ejecución del nodo.
    *
    */     
   void run_case_bool ( logicNode * l);
   /**
    * Método de ejecución del nodo.
    *
    */     
   void run_case_str ( stringNode * s);
   runNode *exp_, *rb_, *val_, *key_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class foreachGeneratorNode :
   public arrayNode {
 public:
   foreachGeneratorNode (runNode *elem, runNode* val, runNode* exp, runNode* rb, runNode* key = NULL, runNode *if_cond = NULL, runNode * elem_key = NULL);
   void run ();
 private:
   void run_case_num ( numNode * n);
   void run_case_array ( arrayNode * a);
   void run_case_bool ( logicNode * l);
   void run_case_str ( stringNode * s);
   void generator ();
   runNode *elem_, *exp_, *rb_, *val_, *key_, *if_cond_, *elem_key_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class iloopNode :
   public runNode {
 public:
   iloopNode (runNode* iter, runNode* stmt, runNode *id = NULL, runNode *second_id = NULL, runNode *inc = NULL);
   void run ();
   static runNode * get_ielement ();
   static runNode * get_ielement_n (int i);
   static runNode * set_ielement (runNode* node);
   static runNode * push_ielement (runNode* node);
   static runNode * pop_ielement ();
   static void push_level ();
   static void pop_level ();
   void setId (runNode * node, bool second = false);
 private:
   void run_case_num ( numNode * n);
   void run_case_array ( arrayNode * a);
   void run_case_bool ( logicNode * l);
   void run_case_str ( stringNode * s);
   static int icount;
   static vector<runNode*> ielement;
   static vector<int> stack_icount;
   static vector<vector<runNode*> > stack_ielement;
   runNode *iter_, *stmt_, *id_, *second_id_, *inc_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class incloopNode :
   public runNode {
 public:
   incloopNode (runNode* id, runNode* max, runNode* stmt);
   void run ();
 private:
   runNode *id_, *max_, *stmt_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class continueNode:
   public runNode {
 public:
   continueNode (int n = 1);
   void run ();
 private:
   int n_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \file continueException
 * \brief Excepción lanzada cuando se produce una sentencia continue.
 * 
 * Esta excepción es lanzada cuando se ejecuta una sentencia continue, será
 * atrapada por una sentencia iterativa y producira que esta avance hasta 
 * la siguiente iteración.
 * 
 * Es posible indicar mediante un entero el número de sentencias iterativas
 * anidadas que serán saltadas 
*/
class continueException :
   public std::exception {
 public:
    /**
    * Constructor de la clase. 
    * \param int Nodo .
    */      
   continueException (int n = 1);
   const char* what() const throw();
   void end ();
   bool islast ();
 private:
   int n_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class forNode :public runNode {
 public:
   forNode (runNode* asig, runNode* exp, runNode* inc, runNode* rb);
   void run (); 
 private:
   runNode *exp_, *rb_, *asig_, *inc_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
