//symbolOpNode.h
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
 * \file symbolOpNode.h
 * \brief Nodos operadores sobre símbolos variables.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores que trabajan sobre los símbolos variables presentes 
 * en las tablas de símbolos . Estos son modelados mediante clases de 
 * objetos. 
*/

#ifndef _RUN_OPERATORS_SYMBOLOPNODE_
#define _RUN_OPERATORS_SYMBOLOPNODE_

#include "../tree/typeNode.h"

//-------------------------------------------------------------------------------------------

/**
 * \class asigNode
 * \brief Nodo asignación.
 *
 * Asigna el valor de un nodo a otro. La asignación se debe realizar sobre 
 * una expresión de tipo no definido, modificándose la referencia interna 
 * de este al nodo asignado.
 *
 * Si el nodo que es asignado es constante será clonado y se asignará la copia.
 * Si el nodo es dinámico se asigna el propio nodo aumentándose el
 * número de referencias del mismo.
 * 
 * La asignación es en si misma una expresión de tipo no definido cuyo
 * valor tras la ejecución será el nodo asignado.
 */
class asigNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase que asocia los nodos al nodo operación
    * de asignación.
    * \param node1 Nodo sobre el que se realizará la asignación.
    * \param node2 Nodo que será asignado.
    */
   asigNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Se lleva a cabo la asignación,
    * para ello se procesa el lado derecho de la asignación. 
    * Luego este valor es asignado como referencia del lado izquierdo.
    * 
    * Tras la ejecución se toma como valor el nodo asignado.
    */
   void run ();
    /**
    * Método que ejecuta el nodo entre niveles de la tabla de símbolos.
    * Se lleva a cabo la asignación, para ello se procesa el lado derecho 
    * de la asignación en el nivel anterior de la tabla de símbolos. 
    * Luego este valor es asignado como referencia del lado izquierdo 
    * en el nivel actual de la tabla de símbolos.
    *
    * Generalmente el lado izquierdo de la expresión será un identificador.
    * 
    * Tras la ejecución se toma como valor el nodo asignado.
    */
   void runLevel ();
   /**
    * Asigna el valor de un nodo dado, como referencia del nodo del lado 
    * izquierdo del operador.
    */
   void setValue (runNode* node);
   /**
    * Obtiene la parte izquierda del operador.
    * \return Nodo de la parte izquierda del operador.
    */
   runNode* getLeft ();
   /**
    * Obtiene la parte derecha del operador.
    * \return Nodo de la parte derecha del operador.
    */
   runNode* getRight ();
   /**
    * Las asignaciones deben ser ejecutadas cunado se encuentran dentro 
    * de una lista.
    * \return devuleve true.
    */
   bool is_runlist () const;
 private:
   bool isRefNode (runNode* node);
   vector<nexpNode*> nexp_;
   runNode *node1_, *node2_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class asigrefNode
 * \brief Nodo asignación.
 *
 * Este nodo es utilizado en las listas de parámetros e indica que un 
 * parámetro debe ser pasado por referencia. 
 * 
 * Al ejecutarse se asigna una referencia al nodo.
 */
class asigrefNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase que asocia los nodos al nodo operación
    * de asignación de referencia.
    * \param node1 Nodo sobre el que se realizará la asignación.
    * \param node2 Nodo que será asignado.
    */
   asigrefNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Se lleva a cabo la asignación,
    * para ello se procesa el lado derecho de la asignación, se obtiene
    * una referencia al mismo como valor interno. Luego este valor es 
    * asignado como referencia del lado izquierdo.
    */
   void run ();
   /**
    * Asigna el valor de un nodo dado como referencia del nodo del
    * lado izquierdo del operador.
    */
   void setValue (runNode* node);
 private:
   runNode *node1_, *node2_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class getRefNode
 * \brief Nodo operador obtener referencia.
 * 
 * Dado un nodo expresión de tipo no definido obtiene como valor la 
 * referencia interna del mismo.
 */
class getRefNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase.
    * \param node Nodo al que se obtendrá la referencia.
    */
   getRefNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Obtiene la referencia del nodo y la asigna 
    * como valor interno.
    */
   void run ();
 private:
   runNode *node_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class getNode
 * \brief Nodo de acceso.
 *
 * Obtiene una referencia concreta dentro de la tabla de símbolos interna 
 * de un nodo. Para ello se parte de una clave o índice. 
 * 
 * Los nodos sobre los que se le puede aplicar el operador de acceso 
 * son aquellos que representan arrays, cadenas, objetos o clases.
 * 
 */
class getNode:
   public nexpNode {
 public:
   /**
    * Constructor de la clase. 
    * \param array Nodo que representa el elemento al que se accederá.
    * \param key Nodo que representa la clave que se usará.
    * \param resolv Indica si la clave debe ser resuelta para el acceso.
    */ 
   getNode (runNode* array, runNode* key, bool resolv = true);
   /**
    * Método que ejecuta el nodo. Consiste en acceder a la referencia
    * dada por la clave en el elemento. Si la clave no existe se toma una 
    * referencia a un nodo nulo. 
    */
   void run ();
   /**
    * Método que cambia el valor de la referencia del nodo.
    * \param node Nodo que representa el nuevo valor.
    */
   void noderef (runNode* node);
   /**
    * Establece que el nodo se encuentra dentro del contexto de una 
    * llamada a función.
    */
   void setFunctionCall ();
   /**
    * Obtiene si el nodo se ejecuta dentro del contexto de una llamada
    * a función.
    * \return Booleano que indica si el nodo se ejecuta en el contexto
    * de una llamada a función.
    */
   bool getFunctionCall ();
   /**
    * Obtiene el nodo que hace de clave.
    * \return Nodo clave.
    */
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

//-------------------------------------------------------------------------------------------

/**
 * \class getNode_endValue
 * \brief Nodo operador de acceso a final de secuencia. 
 *
 * Realmente define a un pseudo tipo de dato ya que no guarda ningún 
 * valor real.
 * Representa el final de un elemento compuesto de una forma secuencial,
 * como por ejemplo un array o una cadena de caracteres.  
 *
 * Gracias a este nodo es posible construir expresiones como "a[] = 2".
 *
 * Este tipo de objeto es utilizado por la gramática y el operador de
 * acceso para obtener una referencia a la posición final, entendiéndose 
 * por esta a la siguiente posición del último elemento. Como este elemento 
 * aún no se ha creado se utiliza un nodo nulo como valor. 
 */
class getNode_endValue:
   public runNode {
 public:
   /**
    * La ejecución de este nodo, no lleva a cabo ninguna tarea ya que es
    * utilizado semánticamente por otros nodos.
    */
   void run ();
};

//-------------------------------------------------------------------------------------------

/**
 * \class getNode_strInterface
 * \brief Nodo interfaz de acceso a cadena de caracteres.
 *
 * Este nodo crea una referencia a una posición determina de una cadena 
 * de caracteres
 * Es utilizado por el operador de acceso para obtener caracteres específicos 
 * de una cadena de texto.
 */
class getNode_strInterface:
   public nexpNode {
 public:
   /**
    * Constructor de la clase.
    * \param node Cadena de caracteres. 
    * \param is_const Determina si la cadena es constante. 
    */
   getNode_strInterface (stringNode* node, bool is_const = false);
   /**
    * Modifica el valor de la referencia.
    * \param node Nuevo valor.
    */
   void noderef (runNode* node);
   /**
    * Obtiene el valor al que se hace referencia.
    * \return Nodo que representa el valor al que se hace referencia.
    */
   runNode* nodeval () const;
   /**
    * Obtiene la posición de la cadena a la que se va ha acceder.
    *  \return Entero que representa la posición de la cadena. 
    */
   int getn () const;
   /**
    * Establece la posición de la cadena a la que se va a acceder.
    *\param n Posición de la cadena.
    */
   void setn ( int n);
   /**
    * Accede a la posición de la cadena creando un nuevo nodo cadena 
    * de caracteres compuesto por el carácter en dicha posición.
    */
   void run ();
 private:
   string* strref_;
   runNode* str_;
   int refn_;
   bool is_const_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class getEnvNode
 * \brief Node operador acceso a variable de entorno.
 *
 * Este nodo sirve como acceso a las variables definidas en el entorno en 
 * el que se  ejecuta el programa. Toma como valor el de la variable de 
 * entorno correspondiente a un nombre dado.
 */
class getEnvNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param node Nombre de la variable.
    */ 
   getEnvNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo que hace
    * de nombre de la variable. Accede al entorno en el que se ejecuta el 
    * programa y obtiene el valor de la variable correspondiente. Si la variable 
    * no está definida se toma como valor el nodo nulo.
    */
   void run ();
 private:
   runNode	 *node_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class getclassNode
 * \brief Nodo operador obtener clase.
 *
 * Dado un nodo objeto, este operador toma como valor la cadena
 * correspondiente al nombre de la clase a la que este  pertenece.
 */
class getclassNode : public stringNode {
 public:
    /**
    * Constructor de la clase.
    * \param node Nodo objeto.
    */ 
   getclassNode (runNode* node);
    /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo  asociado
    * que hace de objeto. Toma como valor la cadena de caracteres 
    * correspondiente al nombre dela clase, si el nodo no representa un 
    * objeto se toma la cadena vacia.
    */
   void run ();
 private:
   runNode *node_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
