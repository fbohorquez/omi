//arrayOpNode.h
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
 * \file arrayOpNode.h
 * \brief Nodos operadores y funciones sobre array.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores y funciones aplicables a datos de tipo array.
 * Estos son modelados mediante clases de objetos. 
*/

#ifndef _RUN_OPERATORS_ARRAYOPNODE_
#define _RUN_OPERATORS_ARRAYOPNODE_

#include "../tree/typeNode.h"

//-------------------------------------------------------------------------------------------

/**
 * \class reduceNode
 * \brief Nodo reduccion de array.
 *
 * Recorre un nodo array aplicando una función para cada elemento,  
 * manteniendo un acumulador que sera devuelto al final del recorrido. 
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

//-------------------------------------------------------------------------------------------

/**
 * \class arrayChunkNode
 * \brief Nodo division de array.
 *
 * Nodo cuya ejecución consiste en la división de un array en varios 
 * fragmentos determinados por un tamaño
 */
class arrayChunkNode : public nexpNode {
   public:
   /**
    * Constructor de la clase. Este nodo se inicializa a partir de un array
    * y el tamaño de cada fragmento.
    * \param array  Nodo que hace de Array.
    * \param size  Nodo que hace de tamaño.
    */
   arrayChunkNode (runNode* array, runNode* size);
    /**
   * Método que ejecuta el nodo. Se encarga de dividir el array de elementos 
   * en varios fragmentos según el tamaño dado. Toma como valor otro
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

//-------------------------------------------------------------------------------------------

/**
 * \class implodeNode
 * \brief Nodo unión de elementos de array. 
 *
 * Este nodo une los elementos de un array en una cadena de texto utilizado
 * como separador entre elementos la cadena especificada.
 *
 * El nodo toma como valor la cadena resultante.
 */
class implodeNode : public stringNode {
 public:
   /**
    * Constructor de la clase. Este nodo se inicializa a partir de una cadena 
    * separadora y un array de elementos.
    * \param str  Nodo cadena separadora.
    * \param array  Nodo que hace de array.
    */
   implodeNode (runNode* str, runNode* array);
   /**
    * Lleva a cabo la ejecución del nodo, uniendo los elementos del
    * array, separados por la cadena separador, en una única cadena.
    *
    * Tra la ejecución el nodo toma el valor de la cadena de texto generada.
    */
   void run ();
   /**
   * Devuelve un nodo unión de elementos  de array como cuerpo de un 
   * nodo función, siendo un nodo this el array de elementos.
   * \return Método implode.
   */ 
   static runNode* asMethod ();
 private:
   runNode *array_, *str_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class arraylastNode
 * \brief Nodo obtener último elemento de array.
 * 
 * Este nodo se utiliza para obtener el último elemento de un array, o 
 * un nodo nulo si este está vacío. 
 */
class arraylastNode : public nexpNode {
 public:
   /**
    * Constructor de la clase
    * \param array Nodo que representa el array.
    */
   arraylastNode (runNode* array);
   /**
    * Método que ejecuta el nodo. Toma como valor una referencia al último 
    * elemento de un array, o a un nodo nulo si el array está vacío.
    */
   void run ();
   /**
   * Devuelve un nodo último elemento de array como cuerpo de un nodo 
   * función, siendo un nodo this el array de elementos.
   * \return Método last.
   */ 
   static runNode* asMethod ();
 private:
   runNode *array_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class arrayfirstNode
 * \brief Nodo función primer elemento de array.
 * 
 * Este nodo se utiliza para obtener el primer elemento de un array, o 
 * un nodo nulo si este está vacío. 
 *
 */
class arrayfirstNode : public nexpNode {
 public:
 /**
    * Constructor de la clase.
    * \param array Nodo que representa el array.
    */
   arrayfirstNode (runNode* array);
   /**
    * Método que ejecuta el nodo. Toma como valor una referencia al primer 
    * elemento de un array, o a un nodo nulo si el array está vacío.
    */
   void run ();
   /**
   * Devuelve un nodo primer elemento de array como cuerpo de un nodo 
   * función, siendo un nodo this el array de elementos.
   * \return Método first.
   */ 
   static runNode* asMethod ();
 private:
   runNode *array_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class arrayinsertNode
 * \brief Nodo función insertar elemento en array.
 * 
 * Se encarga de insertar un elemento en una posición dada de un array.
 * Si la posición se encuentra fuera de rango se produce un error.
 *
 */
class arrayinsertNode : public nexpNode {
 public:
   /**
    * Constructor de la clase.
    * \param array Nodo que representa el array.
    * \param index Nodo que representa la posición en la que se llevará a cabo la inserción.
    * \param element Nodo que representa el elemento que será insertado.
    */
   arrayinsertNode (runNode* array, runNode* index, runNode *element);
   /**
    * Método que lleva a cabo la ejecución del nodo. Inserta el elemento en
    * la posición dada y toma como valor una referencia al array con el 
    * elemento insertado.
    */
   void run ();
   /**
   * Devuelve un nodo insertar elemento en array como cuerpo de un nodo
   * función, siendo un nodo this el array de elementos.
   * \return Método insert.
   */ 
   static runNode* asMethod ();
 protected:
   runNode *array_, *index_, *element_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class arraydeleteNode
 * \brief Nodo función eliminar elemento de array.
 * 
 * Este nodo se encarga de eliminar el elemento que ocupa una determinada 
 * posición dentro de un array.  Si la posición se encuentra fuera de rango 
 * se produce un error.
 */
class arraydeleteNode : public nexpNode {
 public:
   /**
    * Constructor de la clase.
    * \param array Nodo que representa el array.
    * \param index Nodo que representa la posición.
    */
   arraydeleteNode (runNode* array, runNode* index);
   /**
    * Método que ejecuta el nodo. Elimina el elemento que ocupa la posición 
    * dada dentro del array. Toma como valor una referencia al array con 
    * el elemento eliminado.
    */
   void run ();
   /**
   * Devuelve un nodo eliminar elemento de array como cuerpo de 
   * un nodo función, siendo un nodo this el array de elementos.
   * \return Método delete.
   */ 
   static runNode* asMethod ();
 protected:
   runNode *array_, *index_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class arrayunshiftNode
 * \brief Nodo función insertar al inicio de array.
 * 
 * Inserta un determinado elemento al inicio de un array.
 */
class arrayunshiftNode : public arrayinsertNode {
 public:
   /**
    * Constructor de la clase.
    * \param array Nodo que representa el array de elementos.
    * \param element Nodo que representa el elemento a insertar.
    */
   arrayunshiftNode (runNode* array, runNode* element);
   /**
   * Devuelve un nodo insertar al inicio de array como cuerpo de un nodo 
   * función, siendo un nodo this el array de elementos.
   * \return Método unshift.
   */ 
   static runNode* asMethod ();
};

//-------------------------------------------------------------------------------------------

/**
 * \class arraypushNode
 * \brief Nodo funcion inserta al final del array.
 * 
 * Este nodo se encarga de insertar un elemento al final de un array de 
 * elementos.
 */
class arraypushNode : public arrayinsertNode {
 public:
   /**
    * Constructor de la clase.
    * \param array Nodo que representa el array de elementos.
    * \param element Nodo que representa el elemento a insertar.
    */
   arraypushNode (runNode* array, runNode* element);
   /**
    * Método que ejecuta el nodo. Inserta el elemento al final del array. 
    * Se toma como valor una referencia al array con el elemento insertado.
    */
   void run();
   /**
   * Devuelve un nodo insertar al final del array como cuerpo de un nodo 
   * función, siendo un nodo this el array de elementos.
   * \return Método push.
   */ 
   static runNode* asMethod ();
};

//-------------------------------------------------------------------------------------------

/**
 * \class arrayshiftNode.
 * \brief Nodo función elimina y devuelve el primer elemento de array.
 * 
 * La ejecución de este nodo elimina el primer elemento de un array tras
 * tomarlo como valor.  
 */
class arrayshiftNode : public arraydeleteNode {
 public:
    /**
    * Constructor de la clase.
    * \param array Nodo que representa el array de elementos.
    */
   arrayshiftNode (runNode* array);
   /**
    * Método que ejecuta el nodo. Toma como valor el primer elemento de 
    * un array y lo elimina del mismo. Si el array está vacío toma como valor 
    * un nodo nulo.
    */
   void run ();
   /**
   * Devuelve un nodo  elimina y devuelve el primer elemento de array 
   * como cuerpo de un nodo función, siendo un nodo this el array de elementos.
   * \return Método shift.
   */ 
   static runNode* asMethod ();
};

//-------------------------------------------------------------------------------------------

/**
 * \class arraypopNode
 * \brief Nodo función elimina y devuelve el último elemento de array.
 * 
 * La ejecución de este nodo elimina el último elemento de un array tras
 * tomarlo como valor.  
 *
 */
class arraypopNode : public arraydeleteNode {
 public:
  /**
    * Constructor de la clase.
    * \param array Nodo que representa el array de elementos.
    */
   arraypopNode (runNode* array);
   /**
    * Método que ejecuta el nodo. Toma como valor el último elemento 
    * de un array y lo elimina del mismo. Si el array está vacío toma como 
    * valor un nodo nulo.
    */
   void run ();
   /**
   * Devuelve un nodo  elimina y devuelve el último elemento de array 
   * como cuerpo de un nodo función, siendo un nodo this el array de elementos.
   * \return Método pop.
   */ 
   static runNode* asMethod ();
};

#endif
//-------------------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
