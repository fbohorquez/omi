//symbolOpNode.h
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
 * \file symbolOpNode.h
 * \brief Nodos operadores sobre símbolos variables.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores que trabajan sobre los símbolos variables presentes 
 * en las tablas de símbolos . Estos son modelados mediante clases de 
 * objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_OPERATORS_SYMBOLOPNODE_
#define _RUN_OPERATORS_SYMBOLOPNODE_

#include "../tree/typeNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class asigNode
 * \brief Nodo asignación
 *
 * Asigna el valor del nodo2 al nodo1. Nodo1 debe ser un nodo id y nodo2
 * un nodo expresión.
 *
 * Toma el valor de nodo2 y lo copia, luego hace que la referencia de
 * a la que hace nodo1 apunte a el objeto elemento de la copia.
 * Por tanto se realiza una copia/asignación en vez de una simple asignación.
 * Esto es debido a que, en caso contrario, si el elemento node2 cambiara
 * (por ejemplo es una variable) el elemento al que se le ha asigndo también cambiará.
 * Véase un ejemplo de esto:
 *
 * a = 1;
 * b = a;
 * echo a; #imprime: 1
 * echo b; #imprime: 1
 * a = 2;
 * echo a; #imprime: 2
 * echo b; #imprime: 2 y debería ser 1
 *
 * El nodo asignación es por si mismo una expresión cuyo valor tras la ejecución
 * será el nodo recien creado y asignado. Esto hace posible que se puedan
 * procesar expresiones como estas: "a = b = 1;", "echo a = b;", "!(a = --c )", ...
 */
class asigNode :
   public nexpNode {
 public:
   /**
    * Construcutor de la clase que asocia los nodos al nodo operación
    * de asignación
    */
   asigNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Se lleva a cabo la asignación,
    * para ello se procesa el lado derecho de la asignación, se copia
    * el valor del mismo como valor interno. Luego este valor es asignado a
    * como referencia del lado izquierdo.
    *
    * Generalmente el lado izquierdo de la expresión será un identificador.
    *
    * \note Cada vez que se añada un nuevo tipo de dato se debe añadir
    * al algoritmo de ejecución.
    */
   void run ();
   void runLevel ();
   /**
    * Asigna como referencia el valor de un nodo dado al nodo del
    * lado izquierdo del operador
    */
   void setValue (runNode* node);

   runNode* getLeft ();
   runNode* getRight ();
   bool is_runlist () const;
 private:
   bool isRefNode (runNode* node);
   vector<nexpNode*> nexp_;
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class asigrefNode
 * \brief Nodo asignación
 *
 * Asigna una referencia del nodo2 desde el nodo1. Nodo1 debe ser un nodo de tipo no defindo puro y nodo2
 * otro.
 *
 * Obtiene el valor de nodo2, luego hace que la referencia de
 * nodo1 sea hacia el elemento valor de node2.
 *
 * AL contrario q de la operación asignación esta operación no realiza una copia del
 * elemento de nodo2 sino que utiliza directamente al elemento para la asignación.
 *
 * Gracias a esto es posible crear una referencia a un elemento de la tabla de símbolos
 * Véase un ejemplo de esto:
 *
 * a = 1;
 * b = &a;
 * echo a; #imprime: 1
 * echo b; #imprime: 1
 * a = 2;
 * echo a; #imprime: 2
 * echo b; #imprime: 2
 *
 * Debido la aignacción de referencia es importante que cuando se reasigna un
 * elemento de la tabla símbolo a un nuevo nodo creado dinámicamente se reasigne
 * también todos los elementos de la tabla que hacian referencia al mismo nodo.
 *
 * El nodo asignación es por si mismo una expresión cuyo valor tras la ejecución
 * será el nodo recien asignado. Esto hace posible que se puedan
 * procesar expresiones como estas: "a = b = 1;", "echo a = b;", "!(a = --c )", ...
 */
class asigrefNode :
   public nexpNode {
 public:
   /**
    * Construcutor de la clase que asocia los nodos al nodo operación
    * de asignación de referencia
    */
   asigrefNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Se lleva a cabo la asignación,
    * para ello se procesa el lado derecho de la asignación, se obtiene
    * el valor del mismo como valor interno. Luego este valor es asignado
    * como referencia del lado izquierdo.
    *
    * Generalmente el lado izquierdo de la expresión será un identificador.
    *
    */
   void run ();
   /**
    * Asigna como referencia el valor de un nodo dado al nodo del
    * lado izquierdo del operador
    */
   void setValue (runNode* node);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------

class getRefNode :
   public nexpNode {
 public:

   getRefNode (runNode* node);

   void run ();

 private:
   runNode *node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getNode
 * \brief Nodo de acceso
 *
 * Obtienen una referencia a un nodo concreto dentro de tipos compuestos
 * Se considernan nodos de tipos compuestos los siguientes elementos:
 *
 * - cadenas
 * - arrays
 *
 * Este nodo opera sobre un nodo de tipo compuesto y una lista de claves.
 * La ejecución conciste en obtener una referencia a un elemento concreto
 * del nodo compuesto.
 *
 * Según el tipo de nodo compuesto el acceso se realiza de una forma determinada.
 *
 * En el caso de los array el acceso se hace en multiples niveles donde la
 * lista de claves determina a que elemento acceder en cada nivel. Si el elemento
 * de un determinado nivel no existe crea un nuevo elemento que, será un nuevo array
 * vacio, en el caso de que el nivel sea intermedio, o un string vacio en el caso de
 * que el nivel de acceso sea final.
 *
 * Es posible acceder al final del array usandose una clave de tipo getNode_endValue
 * en la lista lista de claves
 *
 * En los string el acceso se hace en un solo nivel por lo que la lista de claves solo deberá
 * contener un valor, en caso contrario los demás valores se desecharán. Para acceder a un determinado
 * caracter dentro de un nodo string se obtiene una referencia al string interno del nodo mediante
 * la clase getNode_strInterface. Esta clase se encarga de interactuar con el string obtenido y modificando
 * el valor de la posición.
 */
class getNode:
   public nexpNode {
 public:
   getNode (runNode* array, runNode* key, bool resolv = true);
   void run ();
   void noderef (runNode* node);
   void setFunctionCall ();
   bool getFunctionCall ();
   runNode* getKey ();
 private:
   void run_case_array (arrayNode* array, runNode* key);
   void run_case_str (strNode* str, runNode* num);
   void setNodeValue (arrayNode *array, runNode * key);
   void setDefaultValue (symbols *map, runNode * key);
   refNode * noderefAnidate ();
   runNode * array_, *key_;
   short unsigned int type_;
   bool exec_, is_this_node_, resolv_, is_const_, functioncall_;
   getNode *next_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getNode_endValue
 * \brief Nodo operador de acceso a final de secuencia 
 *
 * Realmente define a un pseudo tipo de dato ya que no guarda ningun valor real.
 * Representa el final de un elemento compuesto de una forma secuencial,
 * como por ejemplo un array o una cadena de caracteres  
 *
 * Gracias a este nodo es posible contruir expresiones como "a[] = 2"
 *
 * Este tipo de objeto es utilizado por la gramática y el operador de
 * acceso para obtener una referencia a la posición final, entendiéndose por
 * esta a la siguiente posición del último elemento. Como este elemento aún
 * no se ha creado se utiliza un nodo nulo como valor. 
 */
class getNode_endValue:
   public runNode {
 public:
   /**
    * La ejecución de este nodo, no lleva a cabo ninguna tarea ya que es
    * utilizado semánticamente por otros nodos.
    * 
    */
   void run ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getNode_strInterface
 * \brief Node interfaz de acceso a cadena de caracteres
 *
 * Este nodo crea una referncia a una posición determina de una cadena 
 * de carecteres
 * Es utilizado por el operador de acceso para obtener carácteres especificos de
 * una cadena de texto.
 */
class getNode_strInterface:
   public nexpNode {
 public:
   /**
    * Constructor de la clase
    * \param node Cadena de caracteres 
    * \param is_const Determina si la cadena es constante 
    */
   getNode_strInterface (stringNode* node, bool is_const = false);
   /**
    * Modifica el valor de la referencia
    * \param node Nuevo valor
    */
   void noderef (runNode* node);
   /**
    * Obtiene el valor al que se hace referencia
    * \return Nodo que representa el valor al que se hace referencia
    */
   runNode* nodeval () const;
   /**
    * Obtiene la posición de la cadena a la que
    * se va ha acceder
    *  \return Entero que representa la posición de la cadena 
    */
   int getn () const;
   /**
    * Establece la posición de la cadena a la que
    * se va a acceder
    *\param n Posición de la cadena
    */
   void setn ( int n);
   /**
    * Accede a la posición de la cadena creando un nuevo  nodo cadena 
    * de caracteres compuesto por el caracter en dicha posición
    */
   void run ();
 private:
   string* strref_;
   runNode* str_;
   int refn_;
   bool is_const_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getiNode
 * \brief Node operador acceso a iterador
 *
 */
class getiNode : public nexpNode {
 public:
   getiNode (runNode *node = NULL);
   void run ();
 private:
   runNode* node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getEnvNode
 * \brief Node operador acceso a variable de entorno
 *
 * Este nodo sirve como acceso a las variables definidas en el entorno en 
 * el que se  ejecuta el programa. Toma como valor el de la variable de 
 * entorno correspondiente a un nombre dado.
 */
class getEnvNode : public stringNode {
 public:
   /**
    * Constructor de la clase
    * \param node Nombre de la variable
    */ 
   getEnvNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo que hace
    * de nombre de la variable. Accede al entorno en el que se ejecuta el programa 
    * y obtiene el valor de la variable correspondiente. Si la variable no está 
    * definida se toma como valor el nodo nulo.
    */
   void run ();
 private:
   runNode	 *node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getclassNode
 * \brief Nodo operador obtener clase
 *
 * Dado un nodo objecto, este operador toma como valor la cadena
 * correspondiente al nombre de la clase a la que este  pertenece.
 */
class getclassNode : public stringNode {
 public:
    /**
    * Constructor de la clase
    * \param node Nodo objeto
    */ 
   getclassNode (runNode* node);
    /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo  asociado
    * que hace de objeto. Toma como valor la cadena de caracteres correspondiente
    *  al nombre dela clase, si el nodono representa un objeto se toma la cadena vacia.
    */
   void run ();
 private:
   runNode *node_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
