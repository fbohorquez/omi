//regexpOpNode.h
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
 * \file regexpNode.h
 * \brief Nodos operadores y funciones sobre expresiones.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores y funciones aplicables a expresiones regulares. Estos son modelados 
 * mediante clases de objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_OPERATORS_REGEXOPNODE_
#define _RUN_OPERATORS_REGEXOPNODE_

#include "../tree/typeNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class matchNode
 * \brief Nodo función comprobación cadena sobre expresión regular
 *
 * Este nodo comprueba si una determinada cadena de texto pertenece al lenguaje definido por una
 * expresión regular dada.
 *
 * El nodo toma como valor interno un booleano que indica si la cadena pertenece al lenguaje definido por la
 * expresión regular.
 *
 * Para que el resultado sea positivo la cadena debe pertenecer al conjunto de palabras delimitadas
 * por la expresión regular. Si tan solo existe correspondencia parcial el resultado será negativo.
 */
class matchNode : public logicNode {
 public:
   /**
    * Constructor principal
    *
    * \param str Cadena que se comprobará
    * \param regexp Expresión regular que se utilizará en la comprobación
    */
   matchNode (runNode* str, runNode* regexp);
   /**
    * Lleva a cabo la ejecución del nodo. Para ello comprueba si la cadena
    * pertenece al conjunto de palabras determinado por la expresión regular.
    */
   void run ();
   /**
   * Devuelve un nodo match como cuerpo de un nodo función,
   * siendo un nodo this la cadena.
   * \return Método match.
   */ 
   static runNode* asMethod ();
 private:
   runNode *regexp_, *str_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class newregexpNode
 * \brief Operador de definición de expresión regular
 *
 * Este nodo se encarga de crear una expresión regular a partir de una cadena de
 * texto.
 *
 * Tras la ejecución el nodo toma como valor interno la expresión regular definida.
 */
class newregexpNode : public nexpNode {
 public:
   /**
    * Constructor principal de la clase
    *
    * \param str Cadena de texto corespondiente al patrón
    */
   newregexpNode (runNode* str);
   /**
    * Método correspondiente a la ejecución del nodo.
    *
    * Crea una expresión a partir de una cadena de texto.
    *
    * Tras la ejecución el nodo toma como valor interno la expresión regular creada.
    */
   void run ();
 private:
   runNode *str_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class searchNode
 * \brief Nodo función búsqueda estructurada
 *
 * Este nodo realiza una búsqueda estructurada, es decir, obtiene una estructura de datos
 * condicionada por los patrones de búsqueda y el elemento sobre el que se realiza.
 *
 * En el caso básico de ejección de este nodo operará buscando en una cadena
 * de texto subcadenas que pertenezcan al conjunto definido por una expresión regular, introduciendo
 * cada subcadena en un array.
 *
 * Adicionalmente la expresión regular puede estar formada por subexpresiones delimitadas
 * por "()". En dicho caso se buscará en la cadena principal subcadenas que pertenezcan al
 * conjunto delimitado por la expresión regular. Por cada subcadena encontrada se creará un array
 * con las correspondencias de cada subexpresión. Cada uno de los arrays resultantes se
 * guardan en otro que será el que tome como valor interno el nodo.
 *
 * Si se utiliza una expresión regular formada por subexpresiones los arrays correspondientes
 * a cada subcadena tendrán índices numéricos. Es posible, sin embargo, especificar una
 * lista ordenada de claves para crear un array asociativo.
 *
 * También es posible ampliar la búsqueda sobre un array de cadenas. En este caso se
 * aplicará el algoritmo de búsqueda recursivamente en cada elemento del array
 */
class searchNode : public nexpNode {
 public:
   /**
    * Constructor inicializa el nodo de búsqueda estructurada
    * a partir de una cadena o array de cadenas y una expresión regular
    *
    * \param str Cadena de texto o array de cadenas
    * \param regexp Expresión regular.
    */
   searchNode (runNode* str, runNode* regexp);
   /**
    * Constructor que inicializa el nodo de búsqueda estructurada
    * a partir de una cadena o array de cadenas, una expresión regular
    * y una lista de claves que serán utilizado par crear un array
    * asociativo
    *
    * \param str Cadena de texto o array de cadenas
    * \param regexp Expresión regular
    * \param keys Lista de claves para el array asociativo
    */
   searchNode (runNode* str, runNode* regexp, runNode* keys);
   /**
    * Lleva a cabo la búsqueda estructura. Tras la ejecución del
    * nodo este toma como valor interno el array resultado.
    */
   void run ();
   /**
   * Devuelve un nodo search como cuerpo de un nodo función,
   * siendo un nodo this la cadena.
   * \return Método search.
   */ 
   static runNode* asMethod ();
 private:
   runNode *regexp_, *str_, *key_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
