//typeNode.h
//----------------------------------------------------------------------
/*
 * Fco. Javier Bohórquez Ogalla
 * 75766599-E
 * Puerto Real (Cádiz)
 * powersgame@gmail.com
 */
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
/**
 * \file typeNode.h
 * \brief Nodos de tipos de datos básicos
 *
 * En este fichero se incluyen los nodos ejecutables que definen tipos
 * de datos básicos.
 *
 * Se pueden encontrar tipos de datos de diferentes naturaleza, como
 * enteros, cadenas, booleanos, expresiones regulares ...
 *
 * Los tipos de datos en liesh se clasifican de la siguiente forma:
 *
 * - Definidos: Son datos cuyo valor es conocido. Un nodo de tipo de
 * dato definido tiene un valor asociado de una naturaleza concreta.
 * En este grupo se encuentran los tipos booleanos, numéricos, cadenas
 * de texto ... Tras la ejecución de un nodo de tipo de dato definido el
 * nodo tomará un valor concreto.
 *
 * - No definidos: Estos tipos de datos son de naturaleza variable. Un
 * tipo de dato no definido se presenta como una referencia a otro tipo
 * de dato, definido o no. A pesar de que un tipo de dato no definido
 * puede referenciar a otro de la misma naturaleza la cadena de
 * referencias formada finalizará en un tipo definido. Tras la ejecución
 * de un nodo de tipo de dato no definido el nodo guardará una referencia
 * a otro elemento. Las variables, arrays, listas, etc. se encuentran
 * entre los nodo de este tipo.
 */
//----------------------------------------------------------------------
#ifndef _TYPENODE_
#define _TYPENODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <sstream>
#include <boost/regex.hpp>

#include "sTable.h"
#include "runTree.h"
#include "expNode.h"

using namespace std;
using namespace boost;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
    * Constructor de copia
    * \param data Nodo booleano
    */
   boolNode (boolNode* data) {
      if (data) {
         boolvalue_ = data->boolvalue();
      }
   }
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   void run ();

};
//----------------------------------------------------------------------
class boolConstNode : public boolNode {
   public:
      boolConstNode (bool data) :boolNode (data){}
      void rmRef() {}
};
//----------------------------------------------------------------------
/**
 * 	\class numNode
 * 	\brief Nodo numérico
 *
 * 	Tiene un valor numérico asociado. Internemante este valor se represeta
 * 	mediante un double. Por lo que esta clase engloba tanto numeros enteros como
 * 	decimales entre [1.175494351 E – 38, 3.402823466 E + 38]. Para valores fuera
 *  del conjunto el software puede mostrar un comportamiento inesperado.
 */
class numNode :
   public arithNode {
 public:
   /**
    * Constructor a partir de un double
    */
   numNode (num data);
   /**
    * Constructor a partir de un string.
    *
    * Si el string es numérico guarda el significado simbólico del
    * mismo en un double, asi la cadena "2.3" es igual al numérico 2.3
    * de esta forma se puede operar con cadenas como si fueran números.
    *
    * Si el string no es numérico se guarda el tamaño del mismo.
    *
    */
   numNode (string data);
   /**
    * Constructor de copia
    * \param data Nodo numerico
    */
   numNode (numNode* data);
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   void run () {}
};
//----------------------------------------------------------------------
//----------------------------------------------------------------------
class numConstNode : public numNode {
   public:
      numConstNode (num data) : numNode (data) {}
      void rmRef() {}
};
//----------------------------------------------------------------------
/**
 * \class strNode
 * \brief Nodo cadena de texto
 *
 * Representa un nodo cadena de texto. Una cadena de texto
 * se representa mediante un conjunto de carácteres, un valor numérico
 * que se corresponde con la longitud de la misma y un valor booleano
 * que indica si la cadena está vacía.
 *
 */
class strNode :
   public stringNode {
 public:
   /**
    * Constructor de asignación
    * \param data Nodo cadena de texto
    */
   strNode (string data);
   /**
    * Constructor de copia
    * \param data Nodo cadena de texto
    */
   strNode (strNode* data);
   /**
    * Constructor de conversión
    * \param data Nodo cadena de texto
    */
   strNode (runNode* data);

   strNode (runNode* data, bool id );
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   bool is_string () const {
      return true;
   }
   void run () {}
};

//----------------------------------------------------------------------
class strConstNode : public strNode {
   public:
      strConstNode (string data) : strNode (data) {}
      void rmRef() {}
};
class nullNode :
   public dexpNode {
 public:
   /**
    * Constructor de asignación
    */
   nullNode ();
   /**
    * Función de ejecución vacía.
    *
    * Esta función no realiza ninguna acción ya que el valor del
    * nodo es asignado en la construcción.
    */
   void run () {}
   
   string print () const {
      return "";
   }
};
//----------------------------------------------------------------------
/**
 * \class listNode
 * \brief Nodo lista de elementos
 *
 * Una lista de elementos se representa mediante un vector de nodos ejecutables
 *
 * Un nodo lista se enlaza con otros dos nodos ejecutables. En la práctica uno de estos nodos
 * ejecutables será otro nodo lista o NULL, mientras que él otro será de cualquier otro tipo,
 * formándose así una listas de nodos listas. En estos casos denominaremos los nodos de otros tipos
 * como valor de la lista de en la posición determinada por el número de nodos listas antes.
 *
 * Tras la ejecución de una lista de nodos de este tipo, cada nodo guarda un vector con los valores
 * de los nodos hijos y el suyo mismo. Así el primero de la lista guardará un vector con todos los valores
 * de la lista. Esto hace posible que cada nodo hijo se libere tras la ejecución del padre ya que este ya hará referencia
 * a los elementos que guardaban su hijos. Gracias ha esto la ejecución de un nodo lista sólo se lleva a cabo una vez.
 */
class listNode :
   public runNode {
 public:
   listNode (runNode* ele1, runNode* ele2 = NULL):ele1_ (ele1), ele2_(ele2), exec_(false) {}
   /**
    * Ejecuta el nodo, para ello ejecuta sus hijos. Luego, en el caso de que alguno sea otro
    * nodo lista guarda el contenido del vector de este en el suyo propio, luego elimina el
    * nodo lista. En el caso  contrario introduce el nodo en su propio
    * vector.
    */
   void run ();
   /**
    * Devuelve el número de elementos del nódo lista una vez ejecutado.
    */
   int size ();
   /**
    * Obtiene el valor de la lista como un vector de nodos ejecutables
    */
   vector<runNode*> listvalue () const;
   bool isAsigList ();
   listNode* quitAsig ();
    bool is_runlist () const {
      return true;
   }
   void print () const;
 private:
   runNode* ele1_, *ele2_;
   vector<runNode*> list_;
   bool exec_;
};
//----------------------------------------------------------------------
/**
 * \class mapNode
 * \brief Nodo asociativo
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
    * Costructor de asignación
    */
   mapNode (runNode* key, runNode* value);
   /**
    * Método de ejecución: Ejecuta tanto la clave como el valor.
    */
   void run ();
   /**
    * Devuelve el nodo clave asignado
    */
   runNode* key () const;
   /**
    * Devuelve el nodo valor asignado
    */
   runNode* value () const;
 private:
   runNode *key_, *value_;
};

//----------------------------------------------------------------------
/**
 * \class arrayNode
 * \brief Nodo array
 *
 * Representa un vector de elementos. Todo array se representa de forma
 * interna como un array asociativo ordenado (map), donde tanto las claves como los
 * valores son nodos ejecutables.
 *
 * En la inicialización del árbol de ejecución el nodo array se asocia
 * con una lista de nodos de listas (listNode).
 *
 * En la ejecución del nodo array los valores la lista de se copian en
 * el map del mismo. En el caso de que los valores sean nodos asociativos
 * guarda utiliza la clave como clave y el valor como valor. En caso contrario
 * como clave utiliza un número entero según la posición.
 *
 */
class arrayNode :
   public dexpNode {
 public:
   /**
    * Constructor de asignación directa de lista.
    */
   arrayNode (listNode* list);
   /**
    * Constructor de array vacio
    */
   arrayNode ();
   /**
    * Constructor copia
    * Para copiar un array se copia todos los elementos del array del mismo en un
    * nodo array nuevo.
    */
   arrayNode (arrayNode* array);
   arrayNode (arrayNode* array, refNode* &refSearch);
   /**
    * La ejecucion de un array conciste en recorrer la lista de elementos
    * asociadas al mismo y guardarlos en el array asociativo de foram ordenada
    *
    * Por cada elemento de la lista asociada crea un par formado por una clave numérica
    * controlada mediante un contador y el valor del elemento de de la lista. Salvo
    * que el valor del elemento sea un nodo asociatio, en cuyo caso como clave se utiliza
    * la clave del mismo.
    */
   void run ();
   /**
    * Determina cómo se imprime un nodo array
    */
   string print () const;
   /**
    * Obtiene el array que representa al nodo
    */
   symbols* getArray ();
   /**
    * Inserta un valor en el array interno
    */
   void insert (runNode* key, runNode* val, bool str = false) {
      if (str) {
         key = new strNode (stringNode::to_str(key));
      }
      array_[key] = val;
   }
   /**
   * Elimina un valor del array interno
   */
   void del (runNode* key, bool str = false, bool force_position = false ) {
      if (str) {
         key = new strNode (stringNode::to_str(key));
      }
      if (asociative_ && !force_position)
         array_.erase (key);
      else
         array_.erase_position (arithNode::to_num (key));
   }
   /**
    * Obtiene un valor en el array interno
    */
   runNode *get (runNode* key, bool str = false) {
      if (str) {
         key = new strNode (stringNode::to_str(key));
      }
      return
         (array_.find(key) != array_.end())
         ?(array_[key])
         :(NULL);
   }
   /**
    * Obtiene el número de elementos del array
    */
   int size () const;
   /**
    * Devuelve si el array es dibujable
    */
   inline bool isPrintable ()  {
      refNode *r = new refNode ("_str");
      bool resp = (array_.find(r) != array_.end());
      delete r;
      return resp;
   };
   /**
    * Compara elemento a elemento el nodo array con el nodo pasado como
    * parámetro
    *
    * \param node Nodo a comparar
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
   bool compare (runNode* node, int op = 0);
   /**
    * Obtiene el índice numérico actual.
    */
   int getCount () const;
   /**
    * Busca en los elementos del array toda referencia al
    * node node_search y la cambia por una referencia a node_new
    *
    * Si algún elemento es otro array se busca de igual forma
    * en el mismo.
    */
   void cAll (runNode* node_search, runNode* node_new);
   /**
    * Dado un nodo ejecutable devuelve un booleano que
    * indica si en el array se encuentra alguna referencia
    * a dicho nodo.
    *
    * Si algún elemento es otro array se busca de igual forma
    * en el mismo.
    */
   bool isref (runNode* node);

   void clear () {
      array_.clear();
   }
   void clearRef () {
      array_.clearRef();
   }
   void setArray (symbols array) {
      array_ = array;
   }
   void push (runNode* node) {
      this->insert (new numNode (this->getCount()), node);
   }
   virtual runNode * copyArray (arrayNode * a) {
      return arrayNode::copy(a,new arrayNode());
   }
   runNode * getClass () {
      return custom_class_?custom_class_:arrayNode::class_;
   }

   static void generateClass  ();
   
   bool boolvalue () const {
      return size();
   }
   
   num numvalue () const {
      return 0;
   }
   
   string strvalue () const {
      return "";
   }
   ~arrayNode () {
      array_.clear();
   }
   
 protected:
   string printLevel (short int level) const;
   void fromList (listNode * l, bool addref = false);
   static runNode *copy(arrayNode *a, arrayNode *b);
   static classNode *class_;
   bool asociative_;
   symbols array_;
};
//----------------------------------------------------------------------
class arrayConstNode : public arrayNode {
   public:
      arrayConstNode (listNode* list);
      void run ();
      void rmRef() {}
      inline bool isCloned (bool cloned) {cloned_ = cloned;}
   private:
      listNode* list_;
      bool cloned_;
};
//----------------------------------------------------------------------
class objectNode : public arrayNode {
 public:
   objectNode (symbols* s, classNode * c = NULL) : class_ (c) { array_ = *s;}
   objectNode (listNode* l, classNode * c = NULL) : arrayNode (l), class_ (c) {}
   objectNode (arrayNode* a) : arrayNode (a), class_ (NULL) {
      if (objectNode* obj = dynamic_cast<objectNode*> (a)){
         class_ = obj->class_;
      }
   }
   objectNode (objectNode* a) : arrayNode (a), class_(a->class_) {}
   runNode * copyArray (arrayNode * a) {
      return new objectNode (a);
   }
   runNode * getClass () {
      return class_;
   }
   string print () const {
      ostringstream oss;
      strNode * s = new strNode("_str");
      if (class_ && class_->getMethod(s)){
         functioncallNode* call = new functioncallNode(class_->getMethod(s), NULL);
         runNode* val;
         call->run();
         if (printableNode* p = dynamic_cast<printableNode*>(call->nodeval())) 
            oss << p->print ();
      }else
         oss << arrayNode::printLevel (0);
      delete s;
      return oss.str ();
   }
 private:
   classNode * class_;
};
//----------------------------------------------------------------------
/**
 * \class regexpNode
 * \brief Nodo expresión regular
 *
 * Este nodo representa el tipo de dato expresión regular. Las expresiones
 * regulares constituyen una forma de representar lenguajes formales y se construyen
 * utilizando carácteres del alfabeto sobre el cual se define el lenguaje.
 *
 * Las expresiones regulares en liesh presentan la sintaxis de Perl
 *
 * Internamente una expresión regular se representa mediante una
 * máquina de estado finita. La inicialización de un nodo de este tipo consistirá en
 * la creación de la máquina  de estado a partir de una cadena que denominaremos patrón.
 */
class regexpNode:
   public dexpNode {
 public:
   /**
    * Constructor principal del nodo expresión regular
    * Crea la máquina de estado a partir de la cadena str
    */
   regexpNode (string str): str_(str) {
      strNode s_node (str);
      ex_ = regex(s_node.strvalue());
   }
   /**
    * Constructor copia
    */
   regexpNode (regexpNode* r) {
      str_ = r->str_;
      ex_ = r->ex_;
   }
   /**
    * Obtiene la expresión regular asociada al nodo
    */
   regex exvalue () const {
      return ex_ ;
   }
   /**
    * Ejecución del nodo
    */
   void run () {}
   string strvalue () const {
      return str_;
   }
   bool boolvalue () const {
      return str_ != "";
   }
   num numvalue () const {
      return str_.size();
   }
   string print () const { 
      return "";
   }
 private:
   string str_;
   regex ex_;
};
//----------------------------------------------------------------------
class regexpConstNode : public regexpNode {
   public:
      void rmRef() {}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#endif


