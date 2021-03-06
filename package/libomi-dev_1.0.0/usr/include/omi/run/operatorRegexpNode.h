//operatorRegexpNode.h
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
 * \file operatorRegexpNode.h
 * \brief Nodos operadores de expresiones regulares
 *
 * Los nodos ejecutables de operadores de expresiones regulares realiza
 * una operación sobre uno, dos o más nodos de expresiones regulares.
 *
 * Se puede realizar una gran variedad de operaciones sobre
 * una expresión regular.
 */
//----------------------------------------------------------------------
#ifndef _OPERATORREGEXPNODE_
#define _OPERATORREGEXPNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <iostream>
#include <stdlib.h>
#include "runTree.h"
#include "typeNode.h"
#include "stmtNode.h"
#include "sTable.h"
#include "../error.h"
using namespace std;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class matchNode
 * \brief Nodo operador comparación
 *
 * Este nodo se comprueba si una determinada cadena de texto pertenece al lenguaje definido por una
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
   static runNode* asMethod ();
 private:
   runNode *regexp_, *str_;
};
//----------------------------------------------------------------------
/**
 * \class newregexpNode
 * \brief Operador de definición de expresión regular
 *
 * Este nodo se encarga de crear una expresión regular a partir de una cadena de
 * texto.
 *
 * En liesh una expresión regular se puede definir utilizando el delimitador "`", o
 * bien mediante la ejecución de este nodo, el cual se corresponde con la sentencia "regexp"
 *
 * Tras la ejecución el ndo toma como valor interno la expresión regular definida.
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
    * Método correspondiente a la ejecuciçón del nodo.
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
/**
 * \class searchNode
 * \brief Nodo operador de búsqueda estructurada
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
   static runNode* asMethod ();
 private:
   runNode *regexp_, *str_, *key_;
};
//----------------------------------------------------------------------
#endif
