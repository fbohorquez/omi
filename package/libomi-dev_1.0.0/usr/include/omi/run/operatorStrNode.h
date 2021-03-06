//operatorStrNode.h
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
 * \file operatorStrNode.h
 * \brief Nodos operadores de cadena de texto.
 *
 * Los nodos ejecutables de operadores de cadenas realiza
 * una operación sobre uno, dos o más nodos de cadena de texto.
 *
 * Se puede realizar una gran variedad de operaciones sobre
 * una cadena de texto, desde búsqueda de subcadenas
 * hasta encriptaciones
 */
//----------------------------------------------------------------------
#ifndef _OPERATORSTRNODE_
#define _OPERATORSTRNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <iostream>
#include <stdlib.h>
#include "runTree.h"
#include "numData.h"
#include "typeNode.h"
#include "stmtNode.h"
#include "sTable.h"
#include "../error.h"
#define END_STR -1
using namespace std;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class explodeNode
 * \brief Nodo operador explode
 *
 * Este operador permite dividir en partes una cadena de texto a partir
 * de una subcadena denominada separador
 *
 * El nodo toma como valor un array que contedrá cada una de las subscadenas
 * en que queda dividida la cadena principal por el separador.
 */
class explodeNode : public nexpNode {
 public:
   /**
    * Constructor principal a partir de la subcadena separador
    * y la cadena a dividir
    */
   explodeNode (runNode* substr, runNode* str);
   /**
    * La ejecución del nodo consite en dividir la cadena principal
    * haciendo uso del separador. Cada una de las subcadenas en la que queda
    * dividida la cadena principal se guardan en un array por orden posicional.
    *
    * El nodo tomará como valor el array resultante.
    */
   void run ();

  static runNode* asMethod ();
 private:
   runNode *substr_, *str_;
   runNode **ref_;
};
//----------------------------------------------------------------------


//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class sprintfNode
 * \brief Nodo operador cadena con formato
 *
 * Este nodo se encarga producir una cadena de texto formatada a partir de
 * una cadena que utiliza cierta sintaxis para especificar un formato y una
 * serie de valores que serán formateados.
 *
 * La cadena de formato conciste en una cadena de texto que incluye directivas de formatos.
 * Estas directivas serán sustituidas por el valor correspondiente, según posición, de la
 * lista de parámetros. Cuando se reliza cada sustitución el valor es formateado según la directiva.
 *
 * Las directivas de formato tienen el siguiente formato
 *
 * %[operador][presición][formato]
 *
 * Los opreadores son los siguientes:
 * - + Fuerza la impresión del símbolo + cuando se formatean números positivos
 * - ^ Convierte el carácteres a mayúsculas cuando se formatean cadenas de texto
 * - # Añade el caracter 0x cuando se formatean números hexadecimales y el carácter 0 cuando se formatean octales
 *
 * La presición se refiere al número de decimales que se imprimirán en el caso de formatear
 * números o el número de carácteres en el caso de formatear cadenas
 *
 * El carácter de formato indica que tipo de formato se le dará al valor. Liesh
 * interpreta los siguientes tipos de formato:
 * - i|d Número entero
 * - u Sin signo
 * - f Coma flotante
 * - % Carácter %
 * - e Notación científica
 * - o Octal
 * - x Hexadecimal
 * - s|c Cadena de texto
 *
 * Para inicializar un nodo de este tipo es necesario una lista de nodos ejecutables, donde
 * el primer nodo de la lista será la cadena de formato y los siguientes serán los valores.
 *
 */
class sprintfNode : public stringNode {
 public:
   /**
    * Constructor principal.
    *
    * Recibe una lista de nodos ejecutables, donde el primer nodo
    * es la cadena formato y los sucesivos son los valores a formatear
    */
   sprintfNode (runNode* list);
   /**
    * Lleva a cabo la ejecución del nodo ejecutable.
    *
    * Realiza las sustituciones en la cadena de formato.
    */
   void run ();
 private:
   runNode *list_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class findNode
 * \brief Nodo operador búsqueda de subcadena
 *
 * Este operador busca una subcadena de texto dentro de una cadena dada.
 *
 * Para la búsqueda se precisa la cadena principal y la subcadena a buscar. Además
 * es posible indicar a partir de qué posición se comenzará la búsqueda.
 *
 * Tras la ejecución el nodo toma como valor interno el valor de la posición de la primera ocurrencia
 * de la subcadena a partir de la posición indicada. Si la subcadena no se encuentra
 * el nodo tomará el valor -1
 *
 * Adicionalmente es posible utilizar como subcadena una expresión regular.
 */
class findNode : public arithNode {
 public:
   /**
    * Constructor principal. Toma como argumentos la cadena principal
    * la subcadena de búsqueda, que puede ser una cadena de texto o una
    * expresión regular, y la posición a partir de la cual comenzará la
    * búsqueda.
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
   static runNode* asMethod ();
 private:
   runNode *cad_, *ini_pos_, *subcad_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class replaceNode
 * \brief Nodo operador de remplazo
 *
 * Busca las ocurrencia de una subcadena dada en una cadena principal, sustituyendolas
 * por una cadena de remplazo. Este operador admite el número de sustituciones que
 * se llevarán a cabo.
 *
 * Como valor interno tras la ejecución toma la cadena resultante de sustituir en
 * la cadena principal las ocurrencias de la subcadenas por la cadena de remplazo.
 *
 * Adicionalemnte la subcadena de búsqueda puede ser una expresión regular, en cuyo caso
 * se buscará subcadenas que pertenezcan al conjunto de las palabras definido por la
 * expresión regular.
 *
 * Si se utiliza una expresión regular como patrón de búsqueda es posible
 * utilizar en la cadena de remplazo parte de la subcadena
 * que concuerda con la expresión regular. Para ello se forma la expresión regular mediante
 * subexpresiones delimitadas por "()". En la cadena de remplazo se puede hacer referencia,
 * de forma posicional, a las subcadenas correspondientes a cada una de las subexpresiones.
 * Para ello se utiliza la expresión \{posicion} en la cadena de remplazo

 */
class replaceNode : public stringNode {
 public:
   /**
    * Contructor principal.
    *
    * \param search Subcadena a buscar
    * \param replace Cadena de remplazo
    * \param cad Cadena principal
    * \param num_replace Número de remplazos
    */
   replaceNode (runNode* search, runNode *replace, runNode *cad, runNode* num_replace);
   /**
    * Método que se encarga de ejecutar el nodo. Consiste en
    * buscar las ocurrencias de la subcadena en la cadena principal y sustituirlas
    * por la cadena de remplazo, llevándose a cabo el número dado de remplazos.
    */
   void run ();
   static runNode* asMethod ();
 private:
   runNode* search_, *replace_, *cad_,  *num_replace_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
class subreplaceNode : public stringNode {
   public:
      subreplaceNode (runNode* ini, runNode *len, runNode *replace, runNode* str);
      void run ();
      static runNode* asMethod ();
   private:
      runNode* ini_, *len_, *replace_, * str_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class upperNode
 * \brief Nodo operador mayúsculas
 *
 * Este nodo se encarga de tomar una cadena de texto y pasar todos los carácteres
 * que la forman a mayúsculas.
 *
 * Tras su ejecución el nodo toma como valor interno la cadena de texto resultante.
 */
class upperNode : public stringNode {
 public:
   /**
    * Constructor de principal.
    *
    * \param cad Cadena de texto que será transforamda a mayúsculas.
    */
   upperNode (runNode* cad);
   /**
    * Ejecución del nodo. Se encarga de transformar la cadena de texto
    * en mayúsculas.
    */
   void run ();
   static runNode* asMethod ();
 private:
   runNode *cad_;
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
/**
 * \class lowerNode
 * \brief Nodo operador minúsculas
 *
 * Este nodo se encarga de tomar una cadena de texto y pasar todos los carácteres
 * que la forman a minúsculas
 *
 * Tras su ejecución el nodo toma como valor interno la cadena de texto resultante.
 */
class lowerNode : public stringNode {
 public:
   /**
    * Constructor principal.
    *
    * \param cad Cadena de texto que será transformada a minúsculas
    */
   lowerNode (runNode* cad);
   /**
    * Ejecución del nodo. Se encarga de transformar la cadena de texto
    * en minúsculas.
    */
   void run ();
   static runNode* asMethod ();
 private:
   runNode *cad_;
};
//----------------------------------------------------------------------
#endif
