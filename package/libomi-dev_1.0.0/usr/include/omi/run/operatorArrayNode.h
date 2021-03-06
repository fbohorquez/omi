//operatorArrayNode.h
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
 * \file operatorArrayNode.h
 * \brief Nodos funciones sobre arrays.
 *
 * 
 */
//----------------------------------------------------------------------
#ifndef _OPERATORARRAYNODE_
#define _OPERATORARRAYNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <vector>
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
class arrayChunkNode : public nexpNode {
   public:
      arrayChunkNode (runNode* array, runNode* size);
      static runNode *asMethod();
      void run ();
   private:
      runNode *array_, *size_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//~ class arrayColumnNode : public nexpNode {
   //~ public:
      //~ arrayColumnNode (runNode* array, runNode* column_key, runNode* index_key);
      //~ static runNode *asMethod();
      //~ void run ();
   //~ private:
      //~ runNode *array_, *size_;
//~ };
//----------------------------------------------------------------------

//----------------------------------------------------------------------

/**
 * \class implodeNode
 * \brief Nodo operador implode
 *
 * Este nodo une los elementos de un array en una cadena de texto utilizado
 * como separador entre elementos la cadena especificada.
 *
 * El nodo toma como valor la cadena resultante.
 */
class implodeNode : public stringNode {
 public:
   /**
    * Construcutor principal a partir de un array de elementos
    * y una cadena separador.
    */
   implodeNode (runNode* str, runNode* array);
   /**
    * Lleva a cabo la ejecución del nodo, uniendo los elementos del
    * array, separdos por la cadena separador, en una única cadena.
    *
    * Tra la ejecución el nodo toma el valor de la cadena de texto generada
    */
   void run ();
   
   static runNode* asMethod ();
 private:
   runNode *array_, *str_;
};


class arraylastNode : public nexpNode {
 public:
   arraylastNode (runNode* array);
   void run ();
   static runNode* asMethod ();
 private:
   runNode *array_;
};

class arrayfirstNode : public nexpNode {
 public:
   arrayfirstNode (runNode* array);
   void run ();
   static runNode* asMethod ();
 private:
   runNode *array_;
};

class arrayinsertNode : public nexpNode {
 public:
   arrayinsertNode (runNode* array, runNode* index, runNode *element);
   void run ();
   static runNode* asMethod ();
 protected:
   runNode *array_, *index_, *element_;
};

class arraydeleteNode : public nexpNode {
 public:
   arraydeleteNode (runNode* array, runNode* index);
   void run ();
   static runNode* asMethod ();
 protected:
   runNode *array_, *index_;
};

class arrayunshiftNode : public arrayinsertNode {
 public:
   arrayunshiftNode (runNode* array, runNode* element);
   static runNode* asMethod ();
};

class arraypushNode : public arrayinsertNode {
 public:
   arraypushNode (runNode* array, runNode* element);
   void run();
   static runNode* asMethod ();
};

class arrayshiftNode : public arraydeleteNode {
 public:
   arrayshiftNode (runNode* array);
   void run ();
   static runNode* asMethod ();
};

class arraypopNode : public arraydeleteNode {
 public:
   arraypopNode (runNode* array);
   void run ();
   static runNode* asMethod ();
};
//----------------------------------------------------------------------
#endif


