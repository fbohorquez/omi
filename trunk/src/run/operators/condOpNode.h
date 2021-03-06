//condOpNode.h
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
 * \file condOpNode.h
 * \brief Nodos operadores codicionales.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores condicionales.
 * Estos son modelados mediante clases de objetos. 
*/

#ifndef _RUN_OPERATORS_CONDOPNODE_
#define _RUN_OPERATORS_CONDOPNODE_

#include "../tree/typeNode.h"

//-------------------------------------------------------------------------------------------

/**
 * \class ternNode
 * \brief Node operador ternario
 *
 * El operador ternario se inicializa a partir de un nodo condición, un nodo
 * de caso positivo y un nodo de caso negativo.
 * 
 * El  operador evalúa  de forma lógica el nodo condición y toma como valor 
 * el nodo correspondiente al resultado de la evaluación.
 */
class ternNode : public nexpNode {
 public:
   /**
   *  Constructor de la clase. 
   * \param cond Nodo de condición
   * \param yes Nodo de caso positivo
   * \param no Nodo de caso negativo
   */
   ternNode (runNode* cond, runNode* yes, runNode* no);
   /**
   * Método que ejecuta el nodo. Procede a la ejecución del nodo condición
   * y evalúa el valor lógico de este. Toma como valor el nodo de caso positivo
   * o de caso negativo según el resultado.
   */
   void run ();
 private:
   runNode *cond_;
   runNode *yes_;
   runNode *no_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class notnullNode
 * \brief Node operador fusión de  nulos
 * 
 * Este nodo define el operador fusión de nudos que consiste en la evaluación de
 * un listado de nodos, tomando como valor el último nodo evaluado que
 * no sea nulo.
 */
class notnullNode : public nexpNode {
 public:
    /**
   *  Constructor de la clase. 
   * \param list Nodo lista de nodos
   */
   notnullNode (runNode* list);
   /**
   * Método que ejecuta el nodo. Procede a la ejecución del nodo lista
   * comprobando cada uno de los nodos contenidos en ella,
   * tomando como valor el último nodo evaluado que no sea nulo
   */
  
   void run ();
 private:
   runNode	 *list_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
