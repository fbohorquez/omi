//symbols.h
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
 * \file symbols.h
 * \brief Tabla de símbolos.
 * 
 * En este fichero se define las estructuras denominadas tablas de
 * símbolos y mecanismos para su manipulación.
 *
 */

#ifndef _RUN_TABLE_SYMBOLS_
#define _RUN_TABLE_SYMBOLS_

#include <string>
#include <vector>
#include <iostream>
#include "../tree/runTree.h"

using namespace std;

class isymTable;

//-------------------------------------------------------------------------------------------

/**
 * \class symbolsTable
 * \brief Tabla de símbolos.
 * 
 * Una tabla de símbolos es una estructura de datos que guarda
 * una serie de referencias que apunta a otros nodos. Generalmente
 * los nodos referenciados por la tabla de símbolos serán creados de 
 * forma dinámica, fruto de la ejecución del árbol sintáctico. 
 * 
 * Las tablas de símbolos pueden contener nodos que guarden cierta 
 * relación. Por ejemplo se puede utilizar una tabla para las variables, 
 * otras paras las funciones...
 * 
 * \see refNode
 */
class symbolsTable {
   public:
      /**
       * Constructor de la clase. Crea una tabla de símbolos vacía.
       */
      symbolsTable ();
      /**
       * Constructor de la clase. Crea una tabla de símbolos a partir de otra
       * con el atributo de constante.
       * \param table Tabla de símbolos constante.
       */
      symbolsTable (const symbolsTable* table);
      /**
       * Constructor de la clase. Crea una tabla de símbolos a partir de otra.
       * \param table Tabla de símbolos.
       */
      symbolsTable (symbolsTable* table);
      /**
       * Añade una referencia al final de la tabla de símbolos.
       * \param node Referencia.
       * \return Referencia recién añadida.
       */
      refNode* &push_back (refNode* node);
      /**
       * Elimina de la tabla de símbolos la última referencia .
       */
      void pop_back ();
      /**
       * Crea y devuelve una tabla de símbolos cuyas referencias han sido 
       * copiadas a partir de otras.
       * \param sym Tabla de símbolos base.
       * \return Nueva tabla de símbolos con las referencias de la tabla facilitada.
       */
      static symbolsTable copyRef (symbolsTable *sym);
      /**
       * Obtiene un iterador de tabla de símbolos a la primera referencia.
       * \return Obtiene un iterador de la tabla de símbolos que apunta 
       * a la primera referencia.
       */
      isymTable begin ();
      /**
       * Obtiene un iterador de tabla de símbolos al final de la tabla
       * \return Obtiene un iterador de la tabla de símbolos que apunta 
       * al final de la tabla.
       */
      isymTable end ();
      /**
       * Obtiene un iterador de tabla de símbolos a la primera referencia.
       * \return Obtiene un iterador de la tabla de símbolos que apunta 
       * a la primera referencia.
       */
      isymTable begin () const;
       /**
       * Obtiene un iterador de tabla de símbolos al final de la tabla.
       * \return Obtiene un iterador de la tabla de símbolos que apunta 
       * al final de la tabla.
       */
      isymTable end () const;
      /**
       * Busca y devuelve un iterador posicionado en el elemento de la tabla 
       * de símbolos que apunta al nodo dado, según la función de comparación 
       * de nodos. 
       * \param node Nodo a buscar.
       * \return Iterador a la referencia del elemento buscado. Al final de 
       * la tabla si no se encuentra.
       */
      isymTable find (runNode* node); 
      /**
       * Busca y devuelve la referencia de la tabla que apunta a un nodo 
       * dado, según la función de comparación de nodos. Si no es 
       * encontrado se crea una referencia en la tabla cuyo valor es el nodo 
       * por defecto. Si es encontrado el nodo por defecto es liberado.
       * \param node Nodo a buscar.
       * \param default_node Valor por defecto si no es encontrado.
       * \return Referencia al nodo buscado o al nodo por defecto si no es encontrado.
       */
      refNode* findRef (runNode* node, runNode* default_node = NULL); 
      /**
       * Vacia la tabla de símbolos eliminado las referencias.
       */
      void clear ();
      /**
       * Vacia la tabla de símbolo sin eliminar las referencias.
       */
      void clearRef ();
      /**
       * Determina si la tabla de símbolos está vacía.
       * \return Booleano que determina si la tabla está vacía.
       */
      bool empty () ;
      /**
       * Obtiene el tamaño de la tabla de símbolos.
       * \return Entero que representa el tamaño.
       */
      int size () const;
      /**
       * Sobrecarga el operador de acceso. Permite acceder a una referencia
       * de la tabla de símbolos a partir de una clave. Si la clave no es encontrada 
       * devuelve un nodo nulo.
       * \param key Clave correspondiente a la referencia a buscar.
       * \return Nodo al que apunta la referencia dada por la clave. 
       * Si no existe una referencia se devuelve el nodo nulo.
       */
     runNode* &operator[] (const string key);
      /**
       * Permite acceder a una referencia de la tabla de símbolos a partir 
       * de una clave. Si la clave no es encontrada devuelve un nodo nulo.
       * \param key Clave correspondiente a la referencia a buscar.
       * \return Nodo al que apunta la referencia dada por la clave. 
       * Si no existe una referencia se devuelve el nodo nulo.
       */
     runNode* findKey (string key) const;
     /**
       * Sobrecarga el operador de acceso. Permite acceder a una referencia
       * de la tabla de símbolos a partir otra referencia, comparándose las claves. 
       * Si no es encontrada devuelve un nodo nulo.
       * \param key Clave correspodiente a la referencia a buscar.
       * \return Nodo al que apunta la referencia dada por la clave. 
       * Si no se encuentra una referencia se devuelve el nodo nulo.
       */
      runNode* &operator[] (refNode* key);
      /**
       * Sobrecarga el operador de acceso. Permite acceder a una referencia
       * de la tabla de símbolos a partir un nodo que hará de referencia, 
       * comparándose las claves. Si  no es encontrada devuelve un nodo nulo.
       * \param key Referencia a buscar.
       * \return Nodo al que apunta la referencia dada por la clave. 
       * Si no se encuentra una referencia se devuelve el nodo nulo.
       */
      runNode* &operator[] (runNode* key);
      /**
       * Sobrecarga el operador de acceso. Permite acceder a una referencia
       * de la tabla de símbolos a partir una posición. Si  no es encontrada 
       * devuelve un nodo nulo.
       * \param key Nodo que representa la referencia a buscar.
       * \return Nodo al que apunta la referencia dada por la clave. 
       * Si no se encuentra una referencia se devuelve el nodo nulo.
       */
      runNode* &operator[] (int val);
      /**
       * Obtiene la referencia de la tabla de símbolos en la posición dada. 
       * Si está fuera de rango se devuelve NULL.
       * \param val Posición.
       * \return Referencia que ocupa la posición dada. NULL si fuera de rango.
       */
      refNode * &getRef (int val);
      /**
       * Elimina la referencia determinada por un nodo que hace de clave.
       * Si no existe no se lleva a cabo ninguna acción.
       * \param key Nodo que hace de clave.
       */
      void erase (runNode* key);
      /**
       * Elimina la referencia que ocupa una determinada posición de la tabla 
       * de símbolos. Si está fuera de rango no se lleva a cabo ninguna acción.
       * \param i Posición.
       */
      void erase_position (unsigned int i);
      /**
       * Imprime la tabla de símbolos por la salida estándar.
       */
      void print ();
      /**
       * Obtiene al última referencia de la tabla de símbolos.
       * \return Última referencia de la tabla de símbolos.
       */
      refNode* last ();
      /**
       * Obtiene la primera referencia de la tabla de símbolos.
       * \return Primera referencia de la tabla.
       */
      refNode* first ();
      /**
       * Inserta una referencia tras un iterador dado.
       * \param i Iterador tras el cual se realizará la operación.
       * \param element Referencia a insertar.
       */
      void insert (isymTable i, refNode * element); 
      /**
       * Inserta una referencia en una posición dada.
       * \param pos Posición en la cual se realizará la operación.
       * \param element Referencia a insertar.
       */
      void insert (int pos, refNode * element); 
   private:
      int findPosition (refNode* node); 
      vector<refNode*> table_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class isymTable
 * \brief Iterador de tabla de símbolos.
 * 
 * Un iterador de tabla de símbolos permite recorrer la tabla secuencialmente.
 * 
 * El iterador representa una posición de la tabla de símbolos 
 * y se compone de dos referencias, una a la referencia correspondiente en 
 * la tabla de símbolos y otra a su valor. 
 * 
 * Al incrementar o decrementar el iterador este puede desplazarse por la tabla. 
 * 
 */
class isymTable {
   public:
      /**
       * Método constructor vacío.
       */
      isymTable ();
      /**
       * Constructor de la clase. Crea un iterador en una determinada 
       * posición de una tabla de símbolos.
       * \param sym Tabla de símbolos.
       * \param pos Posición.
       */
      isymTable (const symbolsTable* sym , unsigned int pos);
      /**
       * Sobrecarga de operador de igualdad. Compara el iterador
       * con otro dado mediante la relación de igualdad.
       * \param elem Iterador a comparar.
       */
      bool operator==(const isymTable &elem) const;
      /**
       * Sobrecarga de operador de desigualdad. Compara el iterador
       * con otro dado mediante la relación de desigualdad.
       * \param elem Iterador a comparar.
       */
      bool operator!=(const isymTable &elem) const;
      /**
       * Sobrecarga del operador de incremento y asignación. Avanza el 
       * iterador una posición en la tabla de símbolos.
       * \return Devuelve el iterador en la nueva posición.
       */
      isymTable& operator++();
      /**
       * Sobrecarga del operador de decremento y asignación. Retrocede 
       * el iterador una posición en la tabla de símbolos.
       * \return Devuelve el iterador en la nueva posición.
       */
      isymTable& operator--();
   /**
       * Sobrecarga del operador de asignación e incremento. Avanza el 
       * iterador una posición en la tabla de símbolos.
       * \return Devuelve el iterador en la nueva posición.
       */
      isymTable operator++(int);
       /**
       * Sobrecarga del operador de asignación e decremento. Retrocede 
       * el iterador una posición en la tabla de símbolos.
       * \return Devuelve el iterador en la nueva posición.
       */
      isymTable operator--(int);
       /**
       * Obtiene la posición numérica del iterador
       * \return Posición del iterador.
       */
      unsigned int getPos ();
      /**
       * Referencia del iterador.
       */
      refNode *first;
      /**
       * Valor de la referencia del iterador.
       */
      runNode * second;
   private:
      void setPair ();
      symbolsTable* sym_; 
      unsigned int pos_;
   
};

//-------------------------------------------------------------------------------------------

typedef symbolsTable symbols;
typedef isymTable isym;


#endif

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla

