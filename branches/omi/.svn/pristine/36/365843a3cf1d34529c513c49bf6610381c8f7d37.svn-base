//condStmtNode.h
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
 * \file condStmtNode.h
 * \brief Nodos de sentencias condicionales.
 * 
 * En este fichero se define los nodos correspondientes a las distintas sentencias
 * de control condicionales. Estos son modelados 
 * mediante clases de objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_STMTS_CONDSTMTNODE_
#define _RUN_STMTS_CONDSTMTNODE_

#include "../tree/runTree.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \file ifNode
 * \brief Nodo setencia if .
 * 
 * Este nodo consiste en una sentencia if formada por una condición, 
 * un caso positivo y un caso negativo. Se evalua la condición y se ejecuta 
 * el caso correspondiente. 
*/
class ifNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    * \param exp Nodo condición.
    * \param ifb Nodo caso positivo.
    * \param elseb Nodo caso negativo.
    */    
   ifNode (runNode* exp, runNode* ifb, runNode* elseb);
   /**
    * Método de ejecución del nodo.
    *La ejecución consiste en la evaluación de la condición y se ejecuta el 
    * nodo de caso positivo o  el nodo de caso negativo según el resultado 
    * de la evaluación.
    */     
   void run ();
 private:
   runNode *exp_, *ifb_, *elseb_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class caseNode :
   public runNode {
 public:
   caseNode (runNode* exp, runNode* cb, runNode* cases);
   void run (runNode* eval);
   void run ();
 private:
   runNode *exp_, *cb_;
   runNode* cases_;
   bool runall_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class switchNode :
   public runNode {
 public:
   switchNode (runNode* eval, runNode* cases);
   void run ();
 private:
   runNode* eval_;
   runNode* cases_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
