//srrOpNode.h
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
 * \file strOpNode.h
 * \brief Nodos operadores sobre cadenas de caracteres.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores sobre cadenas de caracteres. Estos son modelados 
 * mediante clases de objetos. 
*/

#ifndef _RUN_OPERATORS_STROPNODE_
#define _RUN_OPERATORS_STROPNODE_

#include "../tree/typeNode.h"

//-------------------------------------------------------------------------------------------

/**
 * \class catNode
 * \brief Nodo función concatenación.
 *
 * Este nodo implementa la operación concatenación sobre dos
 * nodos asociados.
 *
 * Si algún nodo no es una cadena de caracteres, fuerza la conversión a 
 * este tipo para realizar la operación.
 *
 * El resultado de evaluar la expresión es un valor cadena de caracteres.
 */
class catNode :
   public stringNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Segundo nodo operando.
    * \param newline Determina si se debe concatenar un salto de línea
    * al resultado de la operación.
    */
   catNode (runNode* node1, runNode* node2, bool newline = false);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor cadena de caracteres del nodo
    * mediante la operación concatenación entre el valor textual de los 
    * dos nodos.
    * 
    * Concatena un salto de línea si asì se especifico en la inicialización.
    */
   void run ();
   /**
    * Ejecuta la operación concatenación sobre dos nodos dados.
    * \param node1 Primer nodo operando.
    * \param node2 Segundo nodo operando.
    * \param newline Determina si se debe concatenar un salto de línea
    * al resultado de la operación.
    * \return Resultado de la operación.
    */
   static string do_cat (runNode *op1, runNode *op2, bool newline = false);
 private:
   runNode *node1_, *node2_;
   bool newline_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class explodeNode
 * \brief Nodo operador explode.
 *
 * Este operador permite dividir en partes una cadena de texto a partir
 * de una subcadena denominada separador.
 *
 * El nodo toma como valor un array que contendrá cada una de las 
 * subcadenas en que queda dividida la cadena principal por el separador.
 */
class explodeNode : public nexpNode {
 public:
   /**
    * Constructor principal a partir de la subcadena separador
    * y la cadena a dividir.
    * \param substr Nodo subcadena que se usará como separador.
    * \param str Nodo cadena al que se realizará la operación.
    */
   explodeNode (runNode* substr, runNode* str);
   /**
    * La ejecución del nodo consiste en dividir la cadena principal
    * haciendo uso del separador. Cada una de las subcadenas en la que 
    * queda dividida la cadena principal se guardan en un array por orden 
    * posicional.
    *
    * El nodo tomará como valor el array resultante.
    */
   void run ();
    /**
   * Devuelve un nodo explode como cuerpo de un nodo función,
   * siendo un nodo this la cadena.
   * \return Método explode.
   */ 
  static runNode* asMethod ();
 private:
   runNode *substr_, *str_;
   runNode **ref_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class sprintfNode
 * \brief Nodo función cadena con formato.
 *
 * Este nodo se encarga producir una cadena de texto formada a partir de
 * una cadena que utiliza cierta sintaxis para especificar un formato, y una
 * serie de valores que serán formateados.
 *
 * La cadena de formato consiste en una cadena de texto que incluye 
 * directivas de formatos.
 * Estas directivas serán sustituidas por el valor correspondiente, según 
 * posición, de la ista de parámetros. Cuando se realiza cada sustitución 
 * el valor es formateado según la directiva.
 *
 * Las directivas de formato tienen el siguiente formato
 *
 * %[operador][precisión][formato]
 *
 * Los operadores son los siguientes:
 * - + Fuerza la impresión del símbolo + cuando se formatean números 
 * positivos
 * - ^ Convierte el caracteres a mayúsculas cuando se formatean cadenas 
 * de texto
 * - # Añade el carácter 0x cuando se formatean números hexadecimales 
 * y el carácter 0 cuando se formatean octales
 *
 * La precisión se refiere al número de decimales que se imprimirán en el 
 * caso de formatear números o el número de caracteres en el caso de 
 * formatear cadenas.
 *
 * El carácter de formato indica qué tipo de formato se le dará al valor. 
 * Los siguientes tipos de formato son válidos:
 * - i|d Número entero
 * - u Sin signo
 * - f Coma flotante
 * - % Carácter %
 * - e Notación científica
 * - o Octal
 * - x Hexadecimal
 * - s|c Cadena de texto
 *
 * Para inicializar un nodo de este tipo es necesario una lista de nodos 
 * ejecutables, donde el primer nodo de la lista será la cadena de formato 
 * y los siguientes serán los valores.
 */
class sprintfNode : public stringNode {
 public:
   /**
    * Constructor principal.
    * Recibe una lista de nodos ejecutables, donde el primer nodo
    * es la cadena formato y los sucesivos son los valores a formatear.
    * \param list Lista de parámetros.
    */
   sprintfNode (runNode* list);
   /**
    * Lleva a cabo la ejecución del nodo ejecutable.
    * Realiza las sustituciones en la cadena de formato.
    * Toma como valor el resultado de la operación
    */
   void run ();
 private:
   runNode *list_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class findNode
 * \brief Nodo función búsqueda de subcadena.
 *
 * Este operador busca una subcadena de texto dentro de una cadena dada.
 *
 * Para la búsqueda se precisa la cadena principal y la subcadena a buscar. 
 * Además es posible indicar a partir de qué posición se comenzará la búsqueda.
 *
 * Tras la ejecución el nodo toma como valor interno el valor de la posición 
 * de la primera ocurrencia de la subcadena a partir de la posición indicada. 
 * Si la subcadena no se encuentra el nodo tomará el valor -1
 *
 * Adicionalmente es posible utilizar como subcadena una expresión regular.
 */
class findNode : public arithNode {
 public:
   /**
    * Constructor del nodo. Toma como argumentos la cadena principal,
    * la subcadena de búsqueda (que puede ser una cadena de texto o una
    * expresión regular) y la posición a partir de la cual comenzará la
    * operación.
    * \param Nodo cadena.
    * \param Nodo subcadena.
    * \param Nodo posición.
    */
   findNode (runNode* cad, runNode *subcad, runNode* ini_pos);
   /**
    * Lleva a cabo la ejecución del nodo, buscando la subcadena dentro de
    * la cadena principal a partir de la posición indicada.
    *
    * Tras la ejecución el nodo toma como valor interno la primera posición
    * en la que se encuentra la primera ocurrencia de la subcadena.
    *
    * Si la subcadena no se encuentra se tomará como valor interno el entero -1.
    */
   void run ();
   /**
   * Devuelve un nodo find como cuerpo de un nodo función,
   * siendo un nodo this la cadena.
   * \return Método find.
   */ 
   static runNode* asMethod ();
 private:
   runNode *cad_, *ini_pos_, *subcad_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class replaceNode
 * \brief Nodo función de remplazo.
 *
 * Busca las ocurrencias de una subcadena dada en una cadena principal, 
 * sustituyéndolas por una cadena de remplazo. Este operador admite 
 * el número de sustituciones que se llevarán a cabo.
 *
 * Como valor interno tras la ejecución tomará la cadena resultante de 
 * sustituir, en la cadena principal, las ocurrencias de la subcadenas por la 
 * cadena de remplazo.
 *
 * Adicionalmente la subcadena de búsqueda puede ser una expresión 
 * regular, en cuyo caso se buscará subcadenas que pertenezcan al 
 * conjunto de las palabras definido por la expresión regular.
 *
 * Si se utiliza una expresión regular como patrón de búsqueda es posible
 * utilizar en la cadena de remplazo parte de la subcadena
 * que concuerda con la expresión regular. Para ello se forma la expresión 
 * regular mediante subexpresiones delimitadas por "()". En la cadena de 
 * remplazo se puede hacer referencia, de forma posicional, a las subcadenas 
 * correspondientes a cada una de las subexpresiones.
 * Para ello se utiliza la expresión \{posición} en la cadena de remplazo

 */
class replaceNode : public stringNode {
 public:
   /**
    * Contructor principal.
    * \param search Subcadena a buscar.
    * \param replace Cadena de remplazo.
    * \param cad Cadena principal.
    * \param num_replace Número de remplazos.
    */
   replaceNode (runNode* search, runNode *replace, runNode *cad, runNode* num_replace);
   /**
    * Método que se encarga de ejecutar el nodo. Consiste en
    * buscar las ocurrencias de la subcadena en la cadena principal y 
    * sustituirlas por la cadena de remplazo, llevándose a cabo el número 
    * dado de remplazos.
    */
   void run ();
   /**
   * Devuelve un nodo replace como cuerpo de un nodo función,
   * siendo un nodo this la cadena.
   * \return Método replace.
   */ 
   static runNode* asMethod ();
 private:
   runNode* search_, *replace_, *cad_,  *num_replace_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class subreplaceNode
 * \brief Nodo función remplazo de subcadena.
 * 
 * Este nodo se encarga de remplazar una subcadena dentro de 
 * una cadena por otra dada. La subcadena se determina mediante 
 * una posición inicial y una longitud.
 *
 */
class subreplaceNode : public stringNode {
   public:
      /**
       * Método constructor.
       * \param ini Posición inicial.
       * \param len Longitud .
       * \param replace Cadena de remplazo.
       * \param str Cadena sobre la que se realizará la operación.
       */
      subreplaceNode (runNode* ini, runNode *len, runNode *replace, runNode* str);
      /**
       * Método que ejecuta el nodo.  Lleva acabo el remplazo de la cadena 
       * delimitada por una posición inicial y una longitud por la cadena de 
       * remplazo dentro de la cadena dada.  
       * 
       * Tras la ejecución toma la cadena con el remplazo
       */
      void run ();
      /**
         * Devuelve un nodo subreplace como cuerpo de un nodo función,
         * siendo un nodo this la cadena.
         * \return Método subreplace.
         */ 
      static runNode* asMethod ();
   private:
      runNode* ini_, *len_, *replace_, * str_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class upperNode
 * \brief Nodo función conversión a mayúsculas.
 *
 * Este nodo se encarga de tomar una cadena de texto y pasar todos los 
 * caracteres que la forman a mayúsculas.
 *
 * Tras su ejecución el nodo toma como valor interno la cadena de texto 
 * resultante.
 */
class upperNode : public stringNode {
 public:
   /**
    * Constructor principal.
    * \param cad Cadena de texto que será transformada a mayúsculas.
    */
   upperNode (runNode* cad);
   /**
    * Ejecución del nodo. Se encarga de transformar la cadena de texto
    * en mayúsculas. Toma como valor la cadena resultado.
    */
   void run ();
   /**
      * Devuelve un nodo upper como cuerpo de un nodo función,
      * siendo un nodo this la cadena.
      * \return Método upper.
      */ 
   static runNode* asMethod ();
 private:
   runNode *cad_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class lowerNode
 * \brief Nodo función conversión minúsculas.
 *
 * Este nodo se encarga de tomar una cadena de texto y pasar todos los 
 * caracteres que la forman a minúsculas.
 *
 * Tras su ejecución el nodo toma como valor interno la cadena de texto 
 * resultante.
 */
class lowerNode : public stringNode {
 public:
   /**
    * Constructor principal.
    * \param cad Cadena de texto que será transformada a minúsculas.
    */
   lowerNode (runNode* cad);
   /**
    * Ejecución del nodo. Se encarga de transformar la cadena de texto
    * en minúsculas. Toma como valor la cadena resultado.
    */
   void run ();
   /**
      * Devuelve un nodo lower como cuerpo de un nodo función,
      * siendo un nodo this la cadena.
      * \return Método lower.
      */ 
   static runNode* asMethod ();
 private:
   runNode *cad_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
