//convOpNode.h
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
 * \file convOpNode.h
 * \brief Nodos operadores para la conversión de tipos.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores para la conversión de tipos.
 * Estos son modelados mediante clases de objetos. 
*/

#ifndef _RUN_OPERATORS_CONVOPNODE_
#define _RUN_OPERATORS_CONVOPNODE_

#include "../tree/typeNode.h"
 
//-------------------------------------------------------------------------------------------

/**
 * \class boolconvNode
 * \brief Nodo de conversión a booleano.
 *
 * Este nodo fuerza la conversión a booleano del valor de un nodo.
 *
 * Si el nodo es booleano toma su propio valor.
 * Si el nodo es aritmético toma el valor booleano del nodo.
 * Si el nodo es cadena de texto toma verdadero si la cadena no es vacía.
 * Si el nodo es array toma verdadero si el array no está vacío.
 *
 */
class boolconvNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */
   boolconvNode (runNode* node);
   /**
    * Tras ser ejecutado el operador toma como valor el resultado de la 
    * conversión a booleano del nodo asociado.
    */
   void run ();
   /**
   * Convierte un nodo a su valor booleano.
    * \param node Nodo operando.
    * \return Valor de la operación.
    */
   static num do_boolconv (runNode *node);
 private:
   runNode *node_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class intconvNode
 * \brief Nodo de conversión a entero.
 *
 * Este nodo fuerza la conversión a entero del valor de un nodo.
 *
 * Si el nodo es booleano toma el valor de 0 ó 1.
 * Si el nodo es aritmético toma el valor entero del nodo.
 * Si el nodo es cadena de texto tomo el valor entero significativo
 * de la cadena, en el caso de ser numérico. En caso contrario toma el 
 * tamaño de la cadena.
 * Si el nodo es array toma el número de elementos del mismo.
 */
class intconvNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */
   intconvNode (runNode* node);
   /**
    * Tras ser ejecutado el operador toma como valor el resultado de la 
    * conversión a entero del nodo asociado.
    */
   void run ();
   /**
    * Convierte un nodo a su valor entero.
    * \param node Nodo operando.
    * \return Valor de la operación.
    */
   static int do_intconv (runNode *node);
 private:
   runNode *node_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class floatconvNode
 * \brief Nodo de conversión a flotante.
 *
 * Este nodo fuerza la conversión a flotante del valor de un nodo.
 *
 * Si el nodo es booleano toma el valor de 0 ó 1.
 * Si el nodo es aritmético toma el valor flotante del nodo.
 * Si el nodo es cadena de texto toma el valor flotante significativo
 * de la cadena, en el caso de ser numérico. En caso contario toma el 
 * tamaño de la cadena.
 * Si el nodo es array toma el número de elementos del mismo.
 *
 */
class floatconvNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */
   floatconvNode (runNode* node);
   /**
    * Tras ser ejecutado el operador toma como valor el resultado de la 
    * conversión a flotante del nodo asociado.
    */
   void run ();
   /**
    * Convierte un nodo a su valor flotante.
    * \param node Nodo operando.
    * \return Valor de la operación.
    */
   static num do_floatconv (runNode *node);
 private:
   runNode *node_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class strconvNode
 * \brief Nodo de conversión a cadena de caracteres.
 *
 * Este nodo fuerza la conversión a cadena de caracteres del valor de un nodo.
 *
 * Si el nodo es booleano toma el valor de "1" en el caso verdadero o  
 * cadena vacía en el caso falso. 
 * Si el nodo es aritmético toma la cadena correspondiente al número que 
 * representa.
 * Si el nodo es array toma la cadena vacía.
 */
class strconvNode :
   public stringNode {
 public:
   /**
   * Constructor de la clase. Asocia el nodo operador a un nodo.
   * \param node Nodo operando.
   */  
   strconvNode (runNode* node);
   /**
   * Tras ser ejecutado el operador toma como valor el resultado de la 
   * conversión a cadena de caracteres del nodo asociado.
   */ 
   void run ();
 private:
   runNode *node_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
