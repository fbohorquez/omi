//loopStmtNode.h
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
 * \file loopStmtNode.h
 * \brief Nodos sentencias iterativas.
 * 
 * En este fichero se define los nodos correspondientes a las distintas sentencias
 * de control iterativas. Estos son modelados mediante clases de objetos. 
*/

#ifndef _RUN_STMTS_FILEOPNODE_
#define _RUN_STMTS_FILEOPNODE_

#include "../tree/typeNode.h"
#include "../operators/opNode.h"
#include "../../error.h"
#include "../../interpreter.h"
 
//-------------------------------------------------------------------------------------------

/**
 * \class whileNode
 * \brief Nodo sentencia while.
 * 
 * Este nodo representa una sentencia iterativa while. Esta consta de 
 * una condición y un bloque de sentencias. El bloque de sentencias 
 * será ejecutado mientras la evaluación de la condición sea verdadera. 
*/
class whileNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    * \param exp Nodo que representa la expresión de condición.
    * \param rb Nodo que representa el bloque de sentencias.
    */      
   whileNode (runNode* exp, runNode* rb);
   /**
    * Método que ejecuta el nodo. Ejecuta y evalúa la condición y si esta
    * es positiva ejecuta el bloque de sentencias. Luego vuelve a repetir 
    * el proceso hasta que la condición sea evaluada como falsa.
    */
   void run ();
 private:
   runNode *exp_, *rb_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class dowhileNode
 * \brief Nodo sentencia do..while.
 * 
 * Este nodo representa una sentencia iterativa do...while. Esta consta de 
 * una condición y un bloque de sentencias. El bloque de sentencias 
 * será ejecutado mientras la evaluación de la condición sea verdadera,  
 * ejecutándose el bloque al menos una vez.
 * 
*/
class dowhileNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    * \param exp Nodo que representa la expresión de condición.
    * \param rb Nodo que representa el bloque de sentencias.
    */         
   dowhileNode (runNode* exp, runNode* rb);
   /**
    * Método que ejecuta el nodo. Ejecuta el bloque de sentencias, luego 
    * ejecuta y evalúa la condición. Si esta es positiva vuelve a repetir el proceso. 
    */   
   void run ();
 private:
   runNode *exp_, *rb_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class foreachNode
 * \brief Nodo sentencia foreach.
 * 
 * Este nodo representa una sentencia foreach. Permite ejecutar un bloque
 * de sentencias para cada elemento contenido en un conjunto.
 *  
 * Se construye a partir un nodo que hace de conjunto a recorrer, un nodo 
 * que hace de identificador, el cual referenciará al elemento actual en cada
 * iteración y un nodo que hace de bloque de sentencias que se ejecutará 
 * para cada elemento. Es posible además especificar un nodo que hará 
 * de identificador en el que se guardará las claves de las referencias 
 * a los elementos recorridos.
*/
class foreachNode :
   public runNode {
 public:
    /**
    * Constructor de la clase. 
    * \param val Nodo que hace de identificador para el valor de cada iteración.
    * \param exp Nodo que hace de conjunto de elementos.
    * \param rb Nodo que hace de bloque de sentencias.
    * \param key Nodo que hace de identificador para la clave de cada iteración.
    */   
   foreachNode (runNode* val, runNode* exp, runNode* rb = NULL, runNode* key = NULL);
   /**
    * Método de ejecución del nodo. Ejecuta el bloque de sentencias para 
    * cada elemento contenido en el conjunto, asignado el elemento al 
    * identificador del valor y la clave al identificador de clave si se facilitó. 
    */     
   void run ();
 private:
   void run_case_num ( numNode * n);
   void run_case_array ( arrayNode * a);
   void run_case_bool ( logicNode * l);
   void run_case_str ( stringNode * s);
   runNode *exp_, *rb_, *val_, *key_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class foreachGeneratorNode
 * \brief Nodo para la lista por compresión
 * 
 * Representa una expresión cuyo valor es obtenido a partir de una 
 * sentencia iterativa. 
 *
 * La forma más simple de crear una lista por compresión es mediante 
 * una expresión de generación y una variable que iterará sobre una expresión conjunto. 
 * En cada iteración la variable iteradora tomará un valor del conjunto. 
 * Para cada elemento se calculará el valor de la expresión generadora, 
 * la cual normalmente contendrá la variable iteradora, y será introducido 
 * en un array que será tomado como valor.
 * 
 * El conjunto sobre el que se itera dependerá del tipo de dato obtenido 
 * al evaluar la expresión conjunto:
 *    - Booleano: Se itera hasta que se evalúa como falso. En cada iteración
 *      se asigna el entero correspondiente al número de la misma.   
 *    - Numérico: Si es positivo se itera desde cero hasta el valor sin incluirlo. 
 *      Si es negativo no se itera.
 *    - Cadena de caracteres: Se itera por cada carácter en la cadena.
 *    - Array: Se itera por cada elemento en el array.
 *
 * Es posible filtrar los datos que serán incluidos en el array, añadiendo 
 * una condición que se deba cumplir.
 * 
 * También se puede especificar una identificador que guarde la clave 
 * de la referencia del elemento iterado. 
 * 
 * El array resultado puede ser generado mediante la expresión de generación
 * y otra expresión que se corresponda con la clave del elemento creado. 
 * 
 * Antes de generar el elemento del array que se tomará como valor 
 * es posible ejecutar un bloque de sentencias.
 */
class foreachGeneratorNode :
   public arrayNode {
 public:
   /**
    * Constructor de la clase.
    * \param elem Nodo que representa el conjunto de elementos.
    * \param val Nodo que hace de identificador para el valor de cada iteración.
    * \param exp Nodo que hace de expresión generadora.
    * \param rb Nodo que representa el bloque de sentencias que será ejecutada en cada iteración.
    * \param key Nodo que hace de identificador para la clave de cada itereación.
    * \param if_cond Nodo que hace de condición para que se lleve a cabo la insercción de los elementos de la iteración.
    *  \param elem_key Nodo que representa la expresión generadora de la clave del elemento en la iteración.
    */
   foreachGeneratorNode (runNode *elem, runNode* val, runNode* exp, runNode* rb, runNode* key = NULL, runNode *if_cond = NULL, runNode * elem_key = NULL);
   /**
    * Método que lleva a cabo la ejecución del modo. Toma como valor el array 
    * generado de forma iterativa.
    */
   void run ();
 private:
   void run_case_num ( numNode * n);
   void run_case_array ( arrayNode * a);
   void run_case_bool ( logicNode * l);
   void run_case_str ( stringNode * s);
   void generator ();
   runNode *elem_, *exp_, *rb_, *val_, *key_, *if_cond_, *elem_key_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class iloopNode
 * \brief Nodo de sentencia de iteración ágil.
 * 
 * Esta sentencia permite iterar un conjunto de elementos de forma simple y rápida. 
 * Para ello solo precisa de un elemento a iterar y un bloque de sentencias. 
 * 
 * Internamente el valor de cada iteración es introducido en una estructura 
 * de datos y podrá ser consultado desde el bloque de sentencias 
 * mediante el uso del nodo \see getiNode . Esta estructura se organiza 
 * por niveles, cada uno de los cuales contendrá una pila de valores. 
 * Con cada sentencia iterativa ágil anidada se añadirá un elemento a la 
 * pila del nivel actual, y con cada llamada a función se incrementará el nivel en uso.
 * 
 * El conjunto sobre el que se itera dependerá del tipo de dato obtenido 
 * al evaluar la expresión conjunto:
 *    - Booleano: Se itera hasta que se evalúa como falso. En cada iteración 
 *      se asigna el entero correspondiente al número de la misma.   
 *    - Numérico: Si es positivo se itera desde cero hasta el valor sin incluirlo. 
 *      Si es negativo no se itera.
 *    - Cadena de caracteres: Se itera por cada carácter en la cadena.
 *    - Array: Se itera por cada elemento en el array.
 * 
 * Se podrá indicar un identificador para referenciar al valor y la clave 
 * generada en cada iteración. Además se podrá dar una expresión de 
 * incremento que será ejecutada en cada iteración. 
 */
class iloopNode :
   public runNode {
 public:
   /**
    * Constructor de la clase.
    * \param iter Nodo que hace de conjunto sobre el que  iterar.
    * \param stmt Nodo que representa el bloque  de sentencias que 
    * se ejecutarán en cada iteración.
    * \param id Nodo identificador para el valor.
    * \param second_id Nodo identificador para la clave.
    * \param inc Nodo que representa la expresión de incremento.
    */
   iloopNode (runNode* iter, runNode* stmt, runNode *id = NULL, runNode *second_id = NULL, runNode *inc = NULL);
   /**
    * Método que ejecuta el nodo.  Ejecuta el bloque de sentencias
    * para cada elemento en el conjunto. Introduciendo el elemento 
    * en el nivel actual de la pila iloop.
    */
   void run ();
   /**
    * Obtiene valor encima de la pila iloop.
    * \return Valor cima de la pila.
    */
   static runNode * get_ielement ();
   /**
    * Obtiene valor indicado de la pila iloop.
    * \param i Profundidad de la pila.
    * \return Valor de la pila determinado.
    */
   static runNode * get_ielement_n (int i);
   /**
    * Cambia el valor en la cima de la pila.
    * \param node Nuevo valor de la cima de la pila.
    * \return Valor anterior.
    */
   static runNode * set_ielement (runNode* node);
   /**
    * Introduce un nuevo valor en la cima de la pila.
    * \param node Nodo ha introducir en la pila.
    * \return Anterior valor en la cima.
    */
   static runNode * push_ielement (runNode* node);
   /**
    * Saca un elemento de la pila.
    * \return Elemento sacado de la pila.
    */
   static runNode * pop_ielement ();
   /**
    * Crea un nuevo nivel de pilas iloop.
    */
   static void push_level ();
   /**
    * Elimina un nivel de pilas iloop.
    */
   static void pop_level ();
    /**
    * Establece el identificador que referenciará al valor o la clave, según 
    * se indique, en cada iteración.
    * \param node Identificador.
    * \param second Determina si se referenciará al valor o la clave.    
    */
   void setId (runNode * node, bool second = false);
 private:
   void run_case_num ( numNode * n);
   void run_case_array ( arrayNode * a);
   void run_case_bool ( logicNode * l);
   void run_case_str ( stringNode * s);
   static int icount;
   static vector<runNode*> ielement;
   static vector<int> stack_icount;
   static vector<vector<runNode*> > stack_ielement;
   runNode *iter_, *stmt_, *id_, *second_id_, *inc_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class getiNode
 * \brief Node operador acceso a iterador.
 * 
 * Este nodo permite acceder a un elemento guadado en la estructura de
 * datos definida por el nodo de iteración ágil (\see iloopNode).
 *
 */
class getiNode : public nexpNode {
 public:
   /**
    * Cosntructor de la clase.
    * \param node Nodo que representa el índice para el acceso a la pila iloop. 
    * Si es NULL se accede al tope de la pila.
    */
   getiNode (runNode *node = NULL);
   /**
    * Método que ejecuta el nodo. Se toma como valor elemento concreto 
    * de la pila iloop actual.
    */
   void run ();
 private:
   runNode* node_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class incloopNode
 * \brief Nodo sentencia iterativa de incremento.
 * 
 * Ejecuta un bloque de sentencias tantas veces como se establezca. 
 * Para ello se precisa de un nodo que establece el número máximo de iteraciones, 
 * un identificador que referenciará el valor numérico de cada iteración
 * y el bloque de sentencias.
 */ 
class incloopNode :
   public runNode {
 public:
   /**
    * Constructor de la clase.
    * \param id Nodo que representa un identificador.
    * \param max Nodo que representa el número máximo de iteraciones.
    * \param stmt Nodo que representa el bloque de sentencias.
    */
   incloopNode (runNode* id, runNode* max, runNode* stmt);
   /**
    * Método que ejecuta el nodo. Ejecuta el bloque de sentencias 
    * tantas veces como se haya establecido. Asignando el valor 
    * numérico de la iteración al identificador dado.
    */
   void run ();
 private:
   runNode *id_, *max_, *stmt_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class continueNode
 * \brief Nodo sentencia continue.
 * 
 * Este nodo se utiliza para finalizar la iteración actual de un bloque de 
 * sentencias en una sentencia iterativa. Prosiguiendo así con la 
 * evaluación de la siguiente iteración.  
 * 
 * Es posible especificar un valor que indica el número de sentencias 
 * iterativas que se saltarán.
 * 
 * Internamente se lanza una excepción (\see continueException) que será
 * atrapada por las sentencias iterativas.
 */
class continueNode:
   public runNode {
 public:
   /**
    * Cosntructor de la clase.
    * \param n Entero que indica el número de sentencias iterativas anidadas que se saltarán.
    */
   continueNode (int n = 1);
   /**
    * Método que lleva a cabo la ejecución del nodo.  Lanza una excepción 
    * continue que obliga a las sentencias iterativas a seguir con la siguiente iteración.
    */
   void run ();
 private:
   int n_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class continueException
 * \brief Excepción lanzada cuando se produce una sentencia continue.
 * 
 * Esta excepción es lanzada cuando se ejecuta una sentencia continue, será
 * atrapada por una sentencia iterativa y producirá que esta avance hasta 
 * la siguiente iteración.
 * 
 * Es posible indicar mediante un entero el número de sentencias iterativas
 * anidadas que serán saltadas.
*/
class continueException :
   public std::exception {
 public:
    /**
    * Constructor de la clase. 
    * \param n Número de sentencias iterativas anidadas que serán saltadas.
    */      
   continueException (int n = 1);
   /**
    * Método que será llamado si la excepción no es capturada. Produciéndose un
    * error
    */
   const char* what() const throw();
   /**
    * Si el número de bloques anidados es mayor que uno lanza
    * una excepción continue decrementando el número de bloques anidados.
    */
   void end ();
    /**
    * Comprueba si es el último de los bloques anidados.
    * \return Booleano que indica si el bloque es el últimos 
    * de los bloques anidados que se desean saltar.
    */
   bool islast ();
 private:
   int n_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class forNode
 * \brief Nodo sentencia iterativa for.
 * 
 * Este nodo consta de una expresión de asignación, una condición, 
 * una expresión de incremento y un bloque de sentencias.  Se ejecuta 
 * la expresión de asignación, luego mientras se cumpla la condición se 
 * ejecuta el bloque de sentencias y la expresión de incremento.
 */
class forNode :public runNode {
 public:
   /**
    * Constructor de la clase.
    * \param asig Nodo que representa la expresión de asignación.
    * \param exp Nodo que representa la expresión de condición.
    * \param inc Nodo que representa la expresión de incremento.
    * \param rb Nodo que representa el bloque de sentencias.
    */
   forNode (runNode* asig, runNode* exp, runNode* inc, runNode* rb);
   /**
    * Método que ejecuta el nodo. Ejecuta el nodo que hace de la 
    * expresión de asignación. Luego ejecuta y evalua la condición. 
    * Si se da un resultado verdadero se ejecuta el bloque de sentencias
    * y la expresión de incremento. Entonces la condición se vuelve 
    * a evaluar repitiéndose el proceso desde este punto hasta que es
    * evaluada como falsa.
    */ 
   void run (); 
 private:
   runNode *exp_, *rb_, *asig_, *inc_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
