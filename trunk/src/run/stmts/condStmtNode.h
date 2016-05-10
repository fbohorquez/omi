//condStmtNode.h
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
/**
 * \file condStmtNode.h
 * \brief Nodos de sentencias condicionales.
 * 
 * En este fichero se definen los nodos correspondientes a las distintas 
 * sentencias de control condicionales. Estos son modelados 
 * mediante clases de objetos. 
*/

#ifndef _RUN_STMTS_CONDSTMTNODE_
#define _RUN_STMTS_CONDSTMTNODE_

#include "../tree/runTree.h"
 
//-------------------------------------------------------------------------------------------

/**
 * \class ifNode
 * \brief Nodo setencia if.
 * 
 * Este nodo consiste en una sentencia if formada por una condición, 
 * un caso positivo y un caso negativo. Se evalúa la condición y se ejecuta 
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
    * La ejecución consiste en la evaluación de la condición y se ejecuta el 
    * nodo de caso positivo o el nodo de caso negativo según el resultado 
    * de la evaluación.
    */     
   void run ();
 private:
   runNode *exp_, *ifb_, *elseb_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class caseNode
 * \brief Nodo casos switch.
 *
 * Este nodo representa una lista de casos switch. 
 * Un caso switch se define mediante una expresión para la comparación,
 * un bloque de sentencias y un enlace al siguiente caso.
 * 
 * Para que el caso sea evaluado se ha de facilitar una expresión a evaluar. 
 * Se comprobará si la esta es igual a la expresión de comparación. Si lo es 
 * se ejecuta el bloque de sentencias de el caso y todos los casos siguientes.
 * Si la evaluación dio un resultado negativo se comprueba el
 * siguiente caso.
 * 
 * \see switchNode
 */
class caseNode :
   public runNode {
 public:
   /**
    * Constructor de la clase.
    * \param exp Nodo que representa la expresión de comparación.
    * \param cb Nodo que representa el bloque de sentencias del caso.
    * \param cases Nodo que representa el siguiente caso. 
    */
   caseNode (runNode* exp, runNode* cb, runNode* cases);
   /**
    * Método de ejecución del nodo. Evalúa un nodo dado como parámetro
    * comparándolo con la expresión de comparación.  Si el resultado es
    * positivo se ejecuta el bloque de sentencias y los bloques de los casos
    * siguientes. Si el resultado es falso se ejecuta la evaluación del caso siguiente.
    * \param eval Nodo que representa la expresión que será comparada
    * con la expresión del caso.
    */
   void run (runNode* eval);
   /**
    * Método de ejecución. Ejecuta el caso sin llevar a cabo la evaluación, 
    * lo que conlleva la ejecución del bloque de sentencias y el caso siguiente.
    */
   void run ();
 private:
   runNode *exp_, *cb_;
   runNode* cases_;
   bool runall_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class switchNode
 * \brief Nodo sentencia switch.
 * 
 * Se compone de un nodo que representa una expresión evaluación y 
 * un nodo que representa una lista de casos. El nodo evaluación será 
 * comparado con cada uno de los casos, si uno de estos da un resultado 
 * de comparación positivo se ejecuta su bloque de sentencias y todos los
 * bloques de sentencias de los casos siguientes.
 * 
 * \see caseNode
 */
class switchNode :
   public runNode {
 public:
   /**
    * Constructor de clase.
    * \param eval Nodo que representa la expresión a evaluar.
    * \param cases Nodo que representa el listado de casos.
    */
   switchNode (runNode* eval, runNode* cases);
   /**
    * Método que lleva a cabo la ejecución del nodo. Ejecuta el listado de
    * casos comparándolos con la expresión de evaluación.
    */
   void run ();
 private:
   runNode* eval_;
   runNode* cases_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
