//arrayOpNode.h
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
 * \file arrayOpNode.h
 * \brief Nodos operadores y fiunciones sobre array.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores y funciones aplicables a datos de tipo array.
 * Estos son modelados mediante clases de objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_OPERATORS_ARRAYOPNODE_
#define _RUN_OPERATORS_ARRAYOPNODE_

#include "../tree/typeNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class reduceNode
 * \brief Nodo reduccion de array
 *
 * Recorre un nodo array aplicando una función para cada elemento,  manteniendo
 * un acumulador que sera devuelto al final del recorrido. 
 *  
 * La función constará de dos parámetros que se corresponderán al acumulador
 * y al elemento actual en el recorrido.  Y devuelve el siguiente acumulador.
 */
class reduceNode : public nexpNode {
 public:
   /**
   * Constructor de la clase. Crea e inicializa un nodo reducción de array 
   * a partir de un nodo array y otro función.
   * \param elem  Nodo que hace de array
   * \param func Nodo que hace de función 
   */ 
   reduceNode (runNode* elem, runNode* func);
   /**
   * Método que ejecuta el nodo. Se encarga de recorrer el array de elementos 
   * aplicando una función por cada uno y manteniendo un acumulador. 
   */ 
   void run ();
   /**
   * Devuelve un nodo reducción de array como cuerpo de un nodo función,
   * siendo un nodo this el array de elementos.
   * \return Método reduce.
   */ 
   static runNode* asMethod ();
 private:
   runNode *elem_, *func_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arrayChunkNode
 * \brief Nodo division de array
 *
 * Nodo cuya ejecución consiste en la división de un array en varios fragmentos
 * determinados por un tamaño
 */
class arrayChunkNode : public nexpNode {
   public:
   /**
    * Constructor de la clase. Este nodo se inicializa a partir de un array
    * y el tamaño de cada fragmento.
    * \param array  Nodo que hace de Array
    * \param size  Nodo que hace de tamaño
    */
   arrayChunkNode (runNode* array, runNode* size);
    /**
   * Método que ejecuta el nodo. Se encarga de dividir el array de elementos 
   * en varios fragmentos segun el tamaño dado. Toma como valor otro
   * array cuyos elementos son cada uno de los fragmentos.
   */      
   void run ();     
   /**
   * Devuelve un nodo división de array como cuerpo de un nodo función,
   * siendo un nodo this el array de elementos.
   * \return Método chunk.
   */ 
   static runNode *asMethod();
   private:
      runNode *array_, *size_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class implodeNode
 * \brief Nodo unión de elementos de array 
 *
 * Este nodo une los elementos de un array en una cadena de texto utilizado
 * como separador entre elementos la cadena especificada.
 *
 * El nodo toma como valor la cadena resultante.
 */
class implodeNode : public stringNode {
 public:
   /**
    * Constructor de la clase. Este nodo se inicialia a partir de una cadena separadora
    * y un array de elementos.
    * \param str  Nodo cadena separadora
    * \param array  Nodo que hace de array
    */
   implodeNode (runNode* str, runNode* array);
   /**
    * Lleva a cabo la ejecución del nodo, uniendo los elementos del
    * array, separdos por la cadena separador, en una única cadena.
    *
    * Tra la ejecución el nodo toma el valor de la cadena de texto generada
    */
   void run ();
   /**
   * Devuelve un nodo uniń de elementos  de array como cuerpo de un nodo función,
   * siendo un nodo this el array de elementos.
   * \return Método implode.
   */ 
   static runNode* asMethod ();
 private:
   runNode *array_, *str_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arraylastNode
 * \brief Nodo operador 
 *
 */
class arraylastNode : public nexpNode {
 public:
   arraylastNode (runNode* array);
   void run ();
   static runNode* asMethod ();
 private:
   runNode *array_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arrayfirstNode
 * \brief Nodo operador 
 *
 */
class arrayfirstNode : public nexpNode {
 public:
   arrayfirstNode (runNode* array);
   void run ();
   static runNode* asMethod ();
 private:
   runNode *array_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arrayinsertNode
 * \brief Nodo operador 
 *
 */
class arrayinsertNode : public nexpNode {
 public:
   arrayinsertNode (runNode* array, runNode* index, runNode *element);
   void run ();
   static runNode* asMethod ();
 protected:
   runNode *array_, *index_, *element_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arraydeleteNode
 * \brief Nodo operador 
 *
 */
class arraydeleteNode : public nexpNode {
 public:
   arraydeleteNode (runNode* array, runNode* index);
   void run ();
   static runNode* asMethod ();
 protected:
   runNode *array_, *index_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arrayunshiftNode
 * \brief Nodo operador 
 *
 */
class arrayunshiftNode : public arrayinsertNode {
 public:
   arrayunshiftNode (runNode* array, runNode* element);
   static runNode* asMethod ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arraypushNode
 * \brief Nodo operador 
 *
 */
class arraypushNode : public arrayinsertNode {
 public:
   arraypushNode (runNode* array, runNode* element);
   void run();
   static runNode* asMethod ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arrayshiftNode
 * \brief Nodo operador 
 *
 */
class arrayshiftNode : public arraydeleteNode {
 public:
   arrayshiftNode (runNode* array);
   void run ();
   static runNode* asMethod ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arraypopNode
 * \brief Nodo operador 
 *
 */
class arraypopNode : public arraydeleteNode {
 public:
   arraypopNode (runNode* array);
   void run ();
   static runNode* asMethod ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
