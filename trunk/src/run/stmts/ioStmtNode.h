//ioStmtNode.h
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
 * \file ioStmtNode.h
 * \brief Nodos sentencias de entrada y salida.
 * 
 * En este fichero se define los nodos correspondientes a las distintas sentencias
 * de entrada y salida. Estos son modelados mediante clases de objetos. 
*/

#ifndef _RUN_STMTS_IOSTMTNODE_
#define _RUN_STMTS_IOSTMTNODE_

#include "../tree/typeNode.h"
 
//-------------------------------------------------------------------------------------------

/**
 * \class printNode
 * \brief Nodo sentencia print.
 *
 * Esta clase define el nodo correspondiente a la sentencia "print".
 *
 * La sentencia "print" se encarga de imprimir la cadena asociada a un nodo 
 * imprimible.
 */
class printNode : public runNode {
 public:
   /**
    * Constructor de clase. 
    *
    * \param exp Nodo sobre el que se ejecutará la sentencia print.
    * \param newline Booleano que determina si se ha de imprimir 
    * un salto de línea al final.
    *
    * El nodo asociado debe ser un nodo imprimible, en caso contrario
    * se producirá un error de tipos.
    */
   printNode (runNode* exp, bool newline = false);
   /**
    * Función de ejecución del nodo. Ejecuta el nodo imprimible
    * asociado e imprime la cadena interna de este en la salida
    * estándar.
    */
   void run ();
 private:
   runNode* exp_;
   bool newline_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class inputNode
 * \brief Nodo de entrada de usuario.
 *
 * Lee de la entrada estándar del usuario y guarda el contenido en
 * un nodo string.
 *
 * La entrada puede ser de dos tipos:
 *
 * tipo 0: correspondiente a la sentencia "input id" toma valores del teclado 
 * hasta que se hace un doble salto de línea.
 *
 * tipo 1: correspondiente a la sentencia "inputline id" toma valores del 
 * teclado hasta que se hace un salto de linea.
 *
 *
 * Es posible especificar un prompt para la entra mediante la sentencia
 * "input<prompt> id"
 */
class inputNode :
   public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param id Nodo identificador .
    * \param type Entero que especifica el tipo.
    * \param prompt Nodo que representa la cadena que se usará como prompt.
    */
   inputNode (idNode* id, int type = 0, runNode* prompt = NULL);
   /**
    * Imprime el prompt, recibe una cadena del usuario y la guarda
    * en la tabla de símbolos mediante un nodo cadena.
    */
   void run ();
 private:
   idNode *id_;
   runNode *prompt_;
   int type_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
