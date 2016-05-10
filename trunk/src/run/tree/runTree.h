//runTree.h
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
 * \file runTree.h
 * \brief Árbol de ejecución
 *
 * Un árbol de ejecución es una estructura de datos funcional. Está
 * formado por nodos ejecutables. Existen una gran variedad de
 * especializaciones de nodos ejecutables.
 *
 * Tras un análisis léxico y sintáctico del código fuente
 * se construye el árbol de ejecución con los nodos
 * correspondientes a las distintas sentencias que forman el programa.
 *
 * El nodo raíz del árbol será ejecutado, lo que normalmente conllevará
 * la ejecución de sus nodos asociados, que a su vez ejecutarán los suyos 
 * propios, y así sucesivamente. Esto produce un recorrido del árbol, donde 
 * los nodos son ejecutados. El recorrido tenderá a ser en profundidad, 
 * aunque estará muy condicionado por la propia ejecución de los nodos. 
 * 
 * Existen gran variedad de tipos de nodos de ejecución, cada uno de los 
 * cuales encierra un significado semántico propio y se define a partir de unos datos concretos.  
 * El analizador sintáctico forma el árbol con la relación de nodos 
 * correspondientes al código fuente procesado, luego la ejecución de estos 
 * produce el resultado semántico.
 *
 * En el fichero runTree.h se define e implementa la clase genérica
 * runNode que modela un nodo ejecutable. Además se especifican las
 * clases que derivan inmediatamente de esta y que, aunque siguen
 * teniendo un propósito general, definen subtipos de nodos ejecutables
 * con propiedades afines.
 */

#ifndef _RUN_TREE_RUNTREE_
#define _RUN_TREE_RUNTREE_

#include <string>
#include <vector>
#include <map>
#include <iostream>

typedef NUMTYPE num;
typedef REFCTYPE refC;

using namespace std;
 
//-------------------------------------------------------------------------------------------

/**
 * \class runNode
 * \brief Nodo ejecutable
 *
 * Un nodo de ejecución representa la unidad funcional básica de un
 * programa OMI. Un programa estará formado por una serie de
 * nodos relacionados entre si, donde cada nodo produce un resultado
 * semántico al ejecutarse. Un árbol de ejecución consiste en una 
 * referencia al nodo que hace de raíz.
 *
 * Se definen una gran variedad de tipos de nodos ejecutables. Así
 * existirá un nodo de ejecución por cada tipo de dato, sentencia,
 * operador... Cada uno de estos tipos realizará una
 * función diferente sobre los datos y elementos que los forma, que
 * igualmente serán nodos de ejecución.
 *
 * Por ejemplo una sentencia "if" se corresponderá con un nodo de
 * ejecución que a su vez enlaza a 3 nodos. El primero de
 * los cuales representa una expresión booleana que será evaluada al
 * ejecutarse el nodo "if". Si la expresión booleana resulta verdadera
 * se ejecutará uno de los otros nodos, el cual representará el bloque
 * de sentencias "then". Por el contrario si la expresión resulta falsa
 * se ejecutará el otro que representa el bloque de sentencias "else".
 *
 * Existen diferentes niveles de abstracción en la definición de los
 * nodos ejecutables.
 *
 * Los nodos genéricos definen clases de nodos con atributos y métodos
 * afines. Por ejemplo los nodos lógicos tendrán un valor booleano
 * asociado, los nodos imprimibles podrán ser procesados para conformar
 * una salida, etc. Estos nodos son tipos de datos incompletos o interfaces.
 *
 * Los nodos específicos suelen derivar de los anteriores, es decir, son
 * especializaciones de los nodos genéricos. Algunos de estos nodos
 * pueden ser el operador "or", la sentencia "if", el dato cadena ....
 *
 * Los nodos pueden ser referenciados desde otros nodos. Las tablas
 * de símbolos son estructuras que guardan nodos que sirven de
 * referencia a otros nodos. Durante la ejecución del árbol pueden
 * crearse nuevos nodos y ser referenciados desde estas estructuras.
 * De esta forma se pueden dar mecanismos como las variables,
 * funciones o clases. 
 * 
 * Todo nodo presenta un valor numérico que indica el número de referencias
 * que tiene. Cuando este número es disminuido a cero el nodo es
 * destruido y liberado de memoria. Los nodos creados en el análisis sintáctico
 * no serán liberados hasta que finalice la ejecución.
 */
class runNode {
 public:
    /**
    * Constructor de la clase.
    */
   runNode (string str);
    /**
    * Constructor de la clase.
    */
   runNode ();
   /**
    * Método virtual de ejecución. Este método debe ser implementado
    * por todas las clases específicas de nodos ejecutables.
    *
    * La implementación de este método definirá la función que se
    * llevará a cabo al ejecutarse el nodo. Encierra el significado 
    * semántico del nodo.
    *
    * En esencia los distintos nodos se diferencia entre si por
    * la forma en que implementan esta función.
    */
   virtual void run () = 0;
   /**
    * Aumenta en uno el número de referencias del nodo.
    */
   virtual void addRef ();
   /**
    * Disminuye en uno el número de referencias del nodo. 
    * Si queda reducido a 0 el nodo es destruido y liberado de memoria.
    */
   virtual void rmRef ();
   /**
    * Compara dos runNode.
    *
    * \param node1, node2 Nodos a comparar.
    * \param op
    * 	Operador a aplicar
   		case 0:  ==
   		case 1:  !=
   		case 2:	 >
   		case 3:	 <
   		case 4:	 >=
   		case 5:	 <=
   		case 6: ===
   */
   static bool compare(runNode  *node1, runNode *node2, int op = 0);
   /**
    * Método que indica si el nodo es imprimible y puede
    * ser escrito en la salida estándar.
    * \return Booleano que indica si es imprimible.
    */
   virtual bool is_print () const;
   /**
    * Método que indica si el nodo debe ser ejecutado cuando
    * se procesa una lista de nodos.
    * \return Booleano que indica si es imprimible.
    */
   virtual bool is_runlist () const;
   /**
    * Método que indica si el nodo puede ser representado mediante 
    * una cadena de caracteres.
    * \return Booleano que indica si puede ser representado mediante una cadena.
    */
   virtual bool is_string () const;
   /**
    * Obtiene una cadena de caracteres correspondiente a la
    * posición de memoria en la que se encuentra el nodo.
    * \return Cadena que representa la posición de memoria.
    */
   string getPtrString ();   
#if JSON==1  
   /**
    * Obtiene una representación en formato JSON que describe el nodo y sus relaciones.
    * \param name Nombre del nodo.
    * \param type Tipo del nodo.
    * \param rel Array de nodos relacionados. 
    * \param relname Array de nombre de relaciones.
    * \param value Cadena que representa el valor del nodo.
    * \param key Cadena que representa la clave del nodo.
    *  \return Cadena de caracteres correspondiente a la descripción del nodo en formato JSON.
    */
   string toJson (string name, string type, runNode** rel = NULL, string* relname = NULL, int rel_n = 0, string value = "", string key = "");
   /**
    * Obtiene una representación en formato JSON que describe el nodo y sus relaciones.
    * \param name Nombre del nodo.
    * \param type Tipo del nodo.
    * \param rel Array de nodos relacionados. 
    * \param relname Array de nombre de relaciones.
    * \param value Numérico que representa el valor del nodo.
    *  \return Cadena de caracteres correspondiente a la descripción del nodo en formato JSON.
    */
   string toJson (string name, string type, runNode** rel, string* relname, int rel_n, num value);
   string json;
#endif
   virtual bool to_bool ();
   virtual num to_num ();
   virtual string to_str ();
   virtual ~runNode ();
   refC ref_count_;
   bool isprivate_;
   
};
 
//-------------------------------------------------------------------------------------------

/**
 * Estructura que define la comparación de elementos runNode.
 *
 * Esta estructura hace posible la ordenación de elementos
 * puntero a nodo ejecutable por su valor interno.
 *
 */
struct cmp_runNode {
   /**
    * Realiza la comparación del valor de *node1 con el valor de *node2
    * Y determina si *node1 < *node2
    */
   bool operator()(runNode  *node1, runNode *node2);

};
 
//-------------------------------------------------------------------------------------------

/**
 * \class printableNode
 * \brief Nodos imprimible.
 *
 * Los nodos imprimibles implementan un método "print" que devuelve una
 * cadena de texto que representa el contenido del nodo.
 *
 */
class printableNode: public runNode {
 public:
   /**
    * Método virtual que devuelve la cadena de texto asociada al
    * nodo.
    */
   virtual string print () const = 0;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class refNode
 * \brief Nodo referencia
 * 
 * Los nodos referencia son un tipo de nodos cuya funcionalidad consiste 
 * en referenciar a otros nodos. Son una pieza fundamental del sistema ya que permiten 
 * acceder a los nodos creados de forma dinámica. 
 * 
 * Una referencia tiene una cadena como clave que permite referirse a la misma. Las referencias
 * suelen quedar agrupadas en otras estructuras de datos como las tablas de símbolos.
 * 
 * Existen nodos que tienen un valor asociado. El tipo de este valor mucha veces no es
 * conocido por lo que guardan una referencia a otro nodo como valor.
 */ 
class refNode : public printableNode {
  public:
      /**
       * Método constructor que crea e inicializa un nodo referencia sin clave
       * y con la referencia nula.
       */
      refNode();
      /**
       * Método constructor que crea e inicializa un nodo referencia a partir de una
       * clave dada. Tendrá una referencia nula.
       */
      refNode(string str);
      /**
       * Método constructor que crea e inicializa un nodo referencia a partir de un nodo que 
       * hace de clave. Tendrá una referencia nula.
       */
      refNode(runNode* data);
      /**
       * Método constructor que crea e inicializa un nodo referencia a partir de otro. 
       * Tendrá la misma referencia que el nodo copiado.
       */
      refNode (refNode *a);
       /**
       * Establece la referencia al nodo dado.
       * \param node Nodo al que apuntará la referencia
       */
      void setRef (runNode* node );
      /**
       * Devuelve el nodo referenciado.
       * \return Nodo referenciado.
       */
      runNode* getRef () const;
      /**
       * Devuelve la referencia interna al nodo.
       * \return Referencia.
       */
      runNode* &getRef ();
      /**
       * Ejecuta el nodo referencia. 
       */
      void run ();
      /**
       * Sobrecarga el método de eliminación para que una referencia 
       * no se elimine como al disminuir a cero el número de referencias.
       */
      void rmRef ();
      /**
       * Elimina una referencia y libera la memoria que ocupa.
       */
      void del ();
      /**
       * Obtienen la cadena que hace de clave de la referencia .
       * \return Cadena correspondiente a la clave.
       */
      string strvalue ();
      /**
       * Obtiene el número de caracteres de la clave.
       * \return Número de caracteres.
       */
      int numvalue ();
      /**
       * Si la referencia tiene clave devuelve verdadero, falso en caso contrario.
       * \return Booleano que indica si la referencia tiene una clave.
       */
      bool boolvalue ();
      /**
       * Devuelve una cadena que representa el nodo al que apunta la referencia.
       * \return Cadena correspondiente al valor de la referencia.
       */
      string print () const;
      /**
       * Establece la clave de la referencia
       * \param s Nueva clave
       */
      void setKey (string s);
      /**
       * Obtiene la clave de la referencia.
       * \return Cadena que representa la clave de la referencia.
       */
      string getKey ();
   private:
      string keyvalue_;
      runNode * refSymbol_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class objectTypeNode
 * \brief Nodo tipo de objeto.
 * 
 * Un nodo tipo de objeto referencia a un nodo que hace de clase y lo dota de
 * ciertos métodos y atributos.
 * 
 * Otros nodos pueden extender de este para poder ser asociado internamente
 * a una clase. Así es posible hacer uso del valor del nodo como un objeto.
 * 
 * Esto hace posible que se puedan utilizar expresiones u otros datos 
 * como objetos. "1234"->find("2");
 */ 
class objectTypeNode: public printableNode {
 public:
   /**
    * Constructor de la clase.
    */
   objectTypeNode ();
   /**
    * Obtiene el método de la clase según la clave dada. 
    * \param key Nodo que hace de cadena.
    * \return Nodo que representa el método. Si no se encuentra la clave NULL.
    */
   runNode* getMethod (runNode* key);
   /**
    * Obtiene una referencia al método de la clase según la clave dada. 
    * \param key Nodo que hace de cadena.
    * \return Referencia al método. Si no se encuentra la clave NULL.
    */
   refNode* getMethodRef (runNode* key);
   /**
    * Obtiene la clase a la que pertenece el nodo. Este método 
    * deberá ser escrito por los nodos derivados.
    *\return Nodo que representa la clase asociada al nodo.
    */
   virtual runNode * getClass ();
   /**
    * Establece un nodo como clase del tipo de objeto.
    * \param c Nodo que hace de clase.
    */
   virtual void setClass (runNode * c);
   protected:
      runNode * custom_class_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla

