//typeNode.h
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
 * \file typeNode.h
 * \brief Nodos de tipos de datos básicos.
 *
 * En este fichero se incluyen los nodos ejecutables que definen tipos
 * de datos básicos.
 *
 * Se pueden encontrar tipos de datos de diferentes naturaleza, como
 * enteros, cadenas, booleanos, arrays ...
 */

#ifndef _RUN_TREE_TYPENODE_
#define _RUN_TREE_TYPENODE_

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <sstream>
#include <boost/regex.hpp>

#include "../table/classNode.h"
#include "expNode.h"

using namespace std;
using namespace boost;

//-------------------------------------------------------------------------------------------

/**
 * \class boolNode
 * \brief Nodo booleano.
 *
 * Representa un dato booleano, "true" o "false".
 */
class boolNode :
   public logicNode {
 public:
   /**
    * Constructor que asigna el valor del nodo.
    * \param data Dato booleano.
    */
   boolNode (bool data);
   /**
    * Constructor de copia.
    * \param data Nodo booleano.
    */
   boolNode (boolNode* data);
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   void run ();
};

//-------------------------------------------------------------------------------------------

/**
 * \class boolConstNode
 * \brief Nodo boleano constante.
 * 
 * Un nodo constante sobrecarga el método de eliminar referencia para
 * que no pueda ser eliminado de la forma normal.
 */
class boolConstNode : public boolNode {
   public:
   /**
    * Constructor de la clase.
    * \param data Valor booleano del nodo.
    */
      boolConstNode (bool data);
      /**
       * Sobrecarga del método para eliminar referencias.
       */
      void rmRef();
};

//-------------------------------------------------------------------------------------------

/**
 * 	\class numNode
 * 	\brief Nodo numérico.
 *
 * 	Tiene un valor numérico asociado. Internamente este valor se representa
 * 	mediante el tipo num, el cual es establecido en tiempo de compilación.
 */
class numNode :
   public arithNode {
 public:
   /**
    * Constructor a partir de dato numérico.
    */
   numNode (num data);
   /**
    * Constructor a partir de un string.
    *
    * Si el string es numérico guarda el significado simbólico del
    * mismo, así la cadena "2.3" es igual al numérico 2.3
    * de esta forma se puede operar con cadenas como si fueran números.
    *
    * Si el string no es numérico se guarda el tamaño del mismo.
    *
    */
   numNode (string data);
   /**
    * Constructor de copia
    * \param data Nodo numérico
    */
   numNode (numNode* data);
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   void run ();
};

//-------------------------------------------------------------------------------------------

/**
 * \class numConstNode
 * \brief Nodo numérico constante.
 * 
 * Un nodo constante sobrecarga el método de eliminar referencia para
 * que no pueda ser eliminado de la forma normal.
 */
class numConstNode : public numNode {
   public:
   /**
    * Constructor de la clase.
    * \param data Valor numérico del nodo.
    */
      numConstNode (num data);
      /**
       * Sobrecarga del método para eliminar referencias.
       */
      void rmRef();
};

//-------------------------------------------------------------------------------------------

/**
 * \class strNode
 * \brief Nodo cadena de caracteres.
 *
 * Representa un nodo cadena de texto. Una cadena de texto
 * se representa mediante un conjunto de caracteres, un valor numérico
 * que se corresponde con la longitud de la misma y un valor booleano
 * que indica si la cadena está vacía.
 */
class strNode :
   public stringNode {
 public:
   /**
    * Constructor del nodo a partir de una cadena de caracteres
    * \param data Nodo cadena de texto.
    */
   strNode (string data);
   /**
    * Constructor de copia.
    * \param data Nodo cadena de texto.
    */
   strNode (strNode* data);
   /**
    * Constructor de conversión.
    * \param data Nodo cadena de texto.
    */
   strNode (runNode* data);
/**
    * Constructor de conversión.
    * \param data Nodo cadena de texto.
    * \param id Determina si se debe tomar la clave en el caso de que data sea id.
    */
   strNode (runNode* data, bool id );
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   void run ();
   /**
    * Sobrecarga este método para devolver verdadero.
    * \return Devuelve verdadero.
    */
   bool is_string () const;
};

//-------------------------------------------------------------------------------------------

/**
 * \class strConstNode
 * \brief Nodo cadena de caracteres constante.
 * 
 * Un nodo constante sobrecarga el método de eliminar referencia para
 * que no pueda ser eliminado de la forma normal.
 */
class strConstNode : public strNode {
   public:
   /**
    * Constructor de la clase.
    * \param data Valor cadena del nodo.
    */
      strConstNode (string data);
       /**
       * Sobrecarga del método para eliminar referencias.
       */
      void rmRef();
};

//-------------------------------------------------------------------------------------------

/**
 * \class nullNode
 * \brief Nodo nulo.
 * 
 * Nodo que representa el valor nulo.
 */
class nullNode :
   public dexpNode {
 public:
   /**
    * Constructor de la clase.
    */
   nullNode ();
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   void run ();
   /**
    * Método de impresión. Devuelve la cadena vacía. 
    * \return Cadena vacía.
    */
   string print () const;
};

//-------------------------------------------------------------------------------------------

/**
 * \class listNode
 * \brief Nodo lista de elementos.
 *
 * Una lista de elementos se representa mediante un vector de nodos ejecutables.
 *
 * Un nodo lista se enlaza con otros dos nodos ejecutables. En la práctica
 * uno de estos nodos será otro nodo lista o NULL, mientras que él otro 
 * será de cualquier otro tipo, formándose así una lista de nodos. 
 * Cada nodo en  la lista ocupará una posición en función de los nodos 
 * listas anidados.
 *
 * Tras la ejecución de una lista de nodos de este tipo, cada nodo guarda 
 * un vector con los valores de los nodos hijos y el suyo mismo. 
 * Así el primero de la lista guardará un vector con todos los valores de la lista. 
 * Esto hace posible que cada nodo hijo se libere tras la ejecución del padre 
 * ya que este ya hará referencia a los elementos que guardaban su hijos. 
 * Gracias ha esto la ejecución de un nodo lista sólo se lleva a cabo una vez.
 */
class listNode :
   public runNode {
 public:
   /**
    * Método constructor.
    * \param ele1 Nodo primer elemento .
    * \param ele2 Nodo segundo elemento.
    */
   listNode (runNode* ele1, runNode* ele2 = NULL);
   /**
    * Ejecuta el nodo, para ello ejecuta sus hijos. Luego, en el caso de que
    * alguno sea otro nodo lista guarda el contenido del vector de este en 
    * el suyo propio, luego elimina el nodo lista. En el caso  contrario 
    * introduce el nodo en su propio vector.
    */
   void run ();
   /**
    * Devuelve el número de elementos del nodo lista una vez ejecutado.
    * \return Número de elementos.
    */
   int size ();
   /**
    * Obtiene el valor de la lista como un vector de nodos ejecutables.
    * \return Lista de valores como vector de nodos.
    */
   vector<runNode*> listvalue () const;
   /**
    * Comprueba si algunos de los elementos de la lista es una asignación.
    * \return Booleano que indica si algunos de los elementos de la
    * lista es una asignación.
    */
   bool isAsigList ();
   /**
    * Devuelve el nodo lista donde los nodos asignaciones presentes
    * son el valor asignado en los mismos.
    * \return Lista sin nodos asignaciones.
    */
   listNode* quitAsig ();
   /**
    * Sobre carga este método para que la lista sea ejecutada
    * de forma recursiva.
    * \return Devuelve el valor booleano true.
    */
    bool is_runlist () const;
 private:
   runNode* ele1_, *ele2_;
   vector<runNode*> list_;
   bool exec_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class mapNode
 * \brief Nodo asociativo.
 *
 * Un nodo asociativo establece una relación entre un par de elementos
 * denominados clave y valor.
 *
 * Un nodo asociativo se puede utilizar para crear arrays asociativos.
 */
class mapNode :
   public runNode {
 public:
   /**
    * Costructor de la clase.
    * \param key Nodo clave.
    * \param value Nodo valor.
    */
   mapNode (runNode* key, runNode* value);
   /**
    * Método de ejecución: Ejecuta tanto la clave como el valor.
    */
   void run ();
   /**
    * Devuelve el nodo clave asignado.
    * \return Nodo clave.
    */
   runNode* key () const;
   /**
    * Devuelve el nodo valor asignado.
    * \return Nodo valor.
    */
   runNode* value () const;
 private:
   runNode *key_, *value_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class arrayNode
 * \brief Nodo array.
 *
 * Representa un vector de elementos. Los array son nodos que presenta
 *  una tabla de símbolos interna en la que almacena referencias a cada 
 * uno de los elementos en el array.
 *
 * En la inicialización del árbol de ejecución el nodo array se asocia
 * con una lista de nodos de listas (listNode).
 *
 * En la ejecución del nodo array los valores de la lista  son guardados
 * en la tabla de símbolos del array. En el caso de que los valores sean nodos 
 * asociativos (\see mapNode) se establece la clave como referencia. En caso 
 * contrario se utiliza como referencia un entero correspondiente a la
 * posición del elemento en la lista.
 * 
 * Todo nodo array tiene asociado un nodo clase "arrayClass".
 */
class arrayNode :
   public dexpNode {
 public:
   /**
    * Constructor de clase.
    * \param list Nodo lista.
    */
   arrayNode (listNode* list);
   /**
    * Constructor de array vacío.
    */
   arrayNode ();
   /**
    * Constructor copia.
    * \param array Nodo array para la copia.
    */
   arrayNode (arrayNode* array);
   /**
    * Constructor copia. Durante la creación del objeto busca una referencia
    * en el nodo copiado que toma el valor de la nueva referencia en el nodo.
    * \param array Nodo array para la copia.
    * \param refSearch Valor que será buscado.
    */
   arrayNode (arrayNode* array, refNode* &refSearch);
   /**
    * La ejecución de un array consiste en recorrer la lista de elementos
    * asociadas al mismo y guardarlos en la tabla de símbolos.
    */
   void run ();
   /**
    * Determina cómo se imprime un nodo array.
    * \return Valor cadena del array.
    */
   string print () const;
   /**
    * Obtiene la tabla de símbolos interna del nodo.
    * \param Tabla de símbolos interna.
    */
   symbols* getArray ();
   /**
    * Inserta un elemento en el array.
    * \param key Nodo clave del elemento.
    * \param val Nodo valor del elemento.
    * \param str Determina si las clave será forzada a tomarse como cadena.
    */
   void insert (runNode* key, runNode* val, bool str = false);
   /**
   * Elimina un elemento del array.
   * \param key Nodo clave.
   * \param str Determina si las clave será forzada a tomarse como cadena.
   * \param force_position Fuerza a que la clave sea tomada como posición numérica. 
   */
   void del (runNode* key, bool str = false, bool force_position = false );
   /**
    * Obtiene un  elemento a partir de una clave.
    * \param key Nodo clave.
    * \param str Determina si las clave será forzada a tomarse como cadena.
    * \return Nodo correspondiente a la clave. NULL si no existe.
    */
   runNode *get (runNode* key, bool str = false);
   /**
    * Obtiene el número de elementos del array.
    * \return Tamaño del array.
    */
   int size () const;
   /**
    * Compara elemento a elemento el nodo array con el nodo pasado como
    * parámetro.
    *
    * \param node Nodo a comparar.
    * \param op.
    * 	Operador a aplicar
   		case 0:  ==
   		case 1:  !=
   		case 2:	 >
   		case 3:	 <
   		case 4:	 >=
   		case 5:	 <=
   		case 6: ===
      \return Booleano resultado de la operación.
    */
   bool compare (runNode* node, int op = 0);
   /**
    * Obtiene el índice numérico actual.
    * \return Numérico que indica el índice mayor.
    */
   int getCount () const;
   /**
    * Busca en los elementos del array toda referencia al
    * nodo node_search y la cambia por una referencia a node_new.
    *
    * Si algún elemento es otro array se busca de igual forma
    * en el mismo.
    * 
    * \param node_search Nodo a buscar.
    * \param node_new Nodo nuevo.
    */
   void cAll (runNode* node_search, runNode* node_new);
   /**
    * Dado un nodo ejecutable devuelve un booleano que indica si en el 
    * array se encuentra alguna referencia a dicho nodo.
    *
    * Si algún elemento es otro array se busca de igual forma en el mismo.
    * 
    * \param node Nodo a buscar.
    * \return Booleano que indica si el array mantiene alguna referencia.
    */
   bool isref (runNode* node);
   /**
    * Elimina todos los elementos del array.
    */
   void clear ();
   /**
    * Elimina únicamente las referencias en el array.
    */
   void clearRef ();
   /**
    * Establece una tabla de símbolos como la tabla del array.
    * \param array Tabla de símbolos .
    */
   void setArray (symbols array);
   /**
    * Añade un nodo al final del array con el siguiente índice numérico. 
    * \param node Nodo que será añadido.
    */
   void push (runNode* node);
   /**
    * Copia el contenido de un array en otro nuevo.
    * \param a Array a copiar.
    * \return Array resultado de la copia.
    */
   virtual runNode * copyArray (arrayNode * a);
   /**
    * Obtiene el nodo clase asociado a la clase.
    * \return Nodo clase.
    */
   runNode * getClass ();
    /**
    * Genera la clase "arrayClass" asociada a todo array.
    */
   static void generateClass  ();
   /**
    * Obtiene el valor booleano del array. El cual indica si este es vacío.
    * \return Valor booleano del array.
    */
   bool boolvalue () const;
   /**
    * Obtiene el valor numérico del array el cual es 0.
    * \return Valor numérico del array.
    */
   num numvalue () const;
   /**
    * Obtiene el valor cadena de caracteres del array. 
    * \return Valor cadena del array.
    */
   string strvalue () const;
   /**
    * Método destructor del array. El cual consiste en la eliminación de los
    * elementos en la tabla de símbolos.
    */
   ~arrayNode ();
   /**
    * Imprime un objeto JSON correspondiente a la tabla de símbolos del array.
    */
#if JSON==1 
   void toJsonSymbols ();
#endif
 protected:
   string printLevel (short int level) const;
   void fromList (listNode * l, bool addref = false);
   static runNode *copy(arrayNode *a, arrayNode *b);
   static classNode *class_;
   bool asociative_;
   symbols array_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class arrayConstNode
 * \brief Nodo array constante.
 * 
 * Un nodo constante sobrecarga el método de eliminar referencia para
 * que no pueda ser elimado de la forma normal.
 */
class arrayConstNode : public arrayNode {
   public:
   /**
    * Constructor de la clase.
    * \param data Valor lista del nodo.
    */
      arrayConstNode (listNode* list);
      /**
    * La ejecución de un array consiste en recorrer la lista de elementos
    * asociadas al mismo y guardarlos en la tabla de símbolos.
    */
      void run ();
      /**
       * Sobrecarga del método para eliminar referencias.
       */
      void rmRef();
      /**
       * Establece si el nodo ha sido clonado.
       * \param cloned Determinará si el nodo fue clonado.
       */
      inline void isCloned (bool cloned) {cloned_ = cloned;}
   private:
      listNode* list_;
      bool cloned_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class objectNode
 * \brief Nodo objeto.
 * 
 * Un nodo objeto es como uno array en el sentido de que tiene una tabla de
 * símbolos asociada. Pero a diferencia de este la clase a la que se asocia 
 * es dada en tiempo de ejecución.
 * 
 * Los objetos son creados mediante instanciación de clases.
 */
class objectNode : public arrayNode {
 public:
   /**
    * Constructor de la clase.
    * \param c Clase a la que queda asociado el objeto.
    */
   objectNode (classNode * c = NULL);
   /**
    * Constructor de la clase.
    * \param s Tabla de símbolos a la que queda asociado el objeto.
    * \param c Clase a la que queda asociado el objeto.
    */
   objectNode (symbols* s, classNode * c = NULL);
   /**
    * Constructor de la clase.
    * \param l Nodo lista a partir del cual se establecerán los atributos del objeto.
    * \param c Clase a la que queda asociado el objeto.
    */
   objectNode (listNode* l, classNode * c = NULL);
   /**
    * Constructor que crea un objeto a partir de un array.
    * \param a Array que dará valor al objeto.
    */
   objectNode (arrayNode* a);
   /**
    * Constructor que crea un objeto a partir de otro.
    * \param a Objeto que será copiado.
    */
   objectNode (objectNode* a);
   /**
    * Obtiene la clase asociada al objeto.
    * \return Clase asociada al objeto.
    */
   runNode * getClass ();
   /**
    * Método de impresión. Obtiene una cadena de caracteres correspondiente
    * a la representación textual del objeto. Si el objeto dispone de un 
    * método "_str" se llamará a dicho método.
    * \return Cadena de caracteres correspondiente a la representación textual.
    */
   string print () const ;
 private:
   classNode * class_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class regexpNode
 * \brief Nodo expresión regular.
 *
 * Este nodo representa el tipo de dato expresión regular. Las expresiones
 * regulares constituyen una forma de representar lenguajes formales 
 * y se construyen utilizando caracteres del alfabeto sobre el cual se define el lenguaje.
 *
 * Las expresiones regulares presentan la sintaxis de Perl.
 *
 * Internamente una expresión regular se representa mediante una máquina
 * de estado finita. La inicialización de un nodo de este tipo consistirá en la
 * creación de la máquina de estado a partir de una cadena que denominaremos patrón.
 */
class regexpNode:
   public dexpNode {
 public:
   /**
    * Constructor principal del nodo expresión regular.
    * Crea la máquina de estado a partir de la cadena str.
    * \param str Cadena que representa la expresión regular en  formato Perl.
    */
   regexpNode (string str);
   /**
    * Constructor copia.
    * \param r Nodo expresión regular para la copia.
    */
   regexpNode (regexpNode* r);
   /**
    * Obtiene la expresión regular asociada al nodo.
    * \return Expresión regular asociada al nodo.
    */
   regex exvalue () const;
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   void run ();
   /**
    * Devuelve el valor cadena caracteres del nodo correspondiente a
    * la cadena que representa la expresión regular.
    * \return Cadena que representa la expresión regular.
    */
   string strvalue () const;
   /**
    * Devuelve el valor booleano del nodo. Que indica la expresión 
    * regular que denota el lenguaje formado por la cadena vacía.
    * \return Valor booleano
    */
   bool boolvalue () const;
   /**
    * Obtiene el valor numérico del nodo correspondiente al número 
    * de caracteres que forma la cadena que define la expresión regular.
    * \return Valor numérico.
    */
   num numvalue () const;
   /**
    * Método de impresión. Obtiene el valor textual del nodo el cual es
    * la cadena vacía.
    * \return Cadena vacía.
    */
   string print () const;
 private:
   string str_;
   regex ex_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class regexpConstNode
 * \brief Nodo expresión regular constante.
 * 
 * Un nodo constante sobrecarga el método de eliminar referencia para
 * que no pueda ser eliminado de la forma normal
 */
class regexpConstNode : public regexpNode {
   public:
      /**
       * Sobrecarga del método para eliminar referencias.
       */
   void rmRef();
};

//-------------------------------------------------------------------------------------------

template <typename T>
runNode *create(listNode* list) {
  return new T(list);
}

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla


