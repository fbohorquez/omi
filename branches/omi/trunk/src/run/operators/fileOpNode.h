//fileOpNode.h
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
 * \file fileOpNode.h
 * \brief Nodos operadores y funciones sobre ficheros.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores y funciones aplicables a ficheros. Estos son modelados 
 * mediante clases de objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_OPERATORS_FILEOPNODE_
#define _RUN_OPERATORS_FILEOPNODE_

#include "../tree/typeNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class fileNode
 * \brief Nodo fichero .
 * 
 * Este nodo abre un descriptor de fichero segun una ruta dada y un modo.   
 * 
 * El modo puede ser:
 *    - r: Solo lectura
 *    - r+: Lectura y/o escritura
 *    - w: Escritura truncando el fichero
 *    - w+: Lectura y/o escritura truncando el fichero
 *    - a: Escritura posicionando el puntero al final del fichero
 *    - a+: Lectura y/o escritura posicionando el puntero al final del fichero
 * 
 */   
class fileNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo que representa la ruta de un fichero 
    * \param mode. Nodo que representa la cadena que determina el modo
    */
   fileNode (runNode * file, runNode * mode = NULL);
   /**
    * Método  de ejecución. Abre el descriptor de fichero y lo toma como valor.
    */    
   void run ();
   /**
    * Obtiene el descriptor de fichero interno
    * \return Descriptor de fichero
    */    
   inline fstream *get () const {
      return f_;
   }
   /**
    * Obtiene el modo
    * \return Cadena correspondiente al modo
    */ 
   inline string getMode () {
      return stringNode::to_str(mode_);
   }
 private:
   runNode *file_, *mode_;
   fstream *f_;
   bool exec;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fputNode
 * \brief Node función escribir en descriptor de fichero .
 * 
 * Este nodo se encarga escribir en la posición en la que se encuentra un
 * descriptor de fichero una cadena.
 */   
class fputNode : public arithNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo que reresenta el descriptor de fichero
    * \param val. Nodo que representa la cadena a escribir
    */
   fputNode (runNode * file, runNode * val);
   /**
    * Método  de ejecución. Escribe en la posición en la 
    * que se enncuentra el descriptor de fichero la cadena dada. 
    * 
    * Toma como valor el número de caracteres escritos.
    */     
   void run ();
 private:
   runNode *file_, *val_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fgetNode
 * \brief Nodo función leer de descriptor de fichero 
 * 
 * Este nodo se encarga de leer desde la posición en la que se encuentra 
 * un descriptor de fichero un número de caracteres.
 */   
class fgetNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo descriptor de fichero
    * \param size. Nodo que representa el número de caracteres que serán 
    * leídos. Si no es dado se toma hasta el siguiente salto de línea.
    */  
   fgetNode (runNode * file, runNode *size = NULL);
   /**
    * Método  de ejecución. Lee del fichero el número de caracteres establecidos.
    * Toma como valor la cadena leída.
    */     
   void run ();
 private:
   runNode *file_, *size_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class freadNode
 * \brief Node función leer fichero.
 * 
 * Este nodo se encarga de leer todo el contenido de un fichero y tomar la
 * cadena correspondiente como valor. 
 */   
class freadNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo que representa la ruta del fichero a leer.
    */
   freadNode (runNode * file);
   /**
    * Método de ejecución. Procede a la lectura del fichero y toma 
    * como valor la cadena resultante. Si el fichero 
    * no existe se produce un error.
    */     
   void run ();
 private:
   runNode *file_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fwriteNode
 * \brief Node función escribir fichero .
 * 
 * Escribe una cadena de caracteres como contenido de un fichero.
 * 
 */   
class fwriteNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file. Nodo que representa la ruta del fichero en el que se escribirá.
    * \param str. Nodo que representa la cadena que se escribirá
    */   
   fwriteNode (runNode * file, runNode* str);
   /**
    * Método  de ejecución. Escribe la cadena de caracteres como contenido
    * del fichero. Si el fichero no existe es creado. Toma como valor la cadena escrita.
    */     
   void run ();
 private:
   runNode *file_, *str_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fappendNode
 * \brief Nodo función añadir a fichero .
 * 
 * Escribe una cadena de caracteres al final de un fichero.  
 * 
 */   
class fappendNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo que representa la ruta del fichero en el que se escribirá.
    * \param str. Nodo que representa la cadena que se escribirá
    */ 
   fappendNode (runNode * file, runNode* str);
    /**
    * Método  de ejecución. Añade la cadena al final de un fichero.  Si el fichero 
    * no existe es creado. Como valor toma la cadena escrita.
    */    
   void run ();
 private:
   runNode *file_, *str_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fsekNode
 * \brief Nodo función cambiar puntero de descriptor de fichero.
 * 
 * Este nodo se encarga de cambiar la posición del puntero que 
 * representa el descriptor a un fichero.  
 * 
 */   
 class fseekNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo que representa el descrtiptor de fichero
    * \param offset. Offset aplicado en bytes
    * \param pos. Posición que se toma como referencia.
    */ 
   fseekNode  (runNode * file, runNode* offset, int pos = 0);
   /**
    * Método que ejecuta el nodo. Cambia la posición del 
    * puntero que representa el descriptor de un fichero. Toma 
    * como valor un booleano que indica si el proceso se realizó
    * correctamente.
    */     
   void run ();
 private:
   runNode *file_, *offset_;
   int pos_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class ftellNode
 * \brief Nodo función obtener puntero de descriptor de fichero.
 * 
 * Este nodo se encarga de obtener la poscición del puntero de un descriptor de
 * fichero. 
 */   
class ftellNode : public arithNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo que representa el descriptor de fichero.
    */ 
   ftellNode  (runNode * file);
   /**
    * Método  de ejecución. Toma como valor un entero correspondiente
    * a la posición del puntero de un descriptor de fichero.
    */     
   void run ();
 private:
   runNode *file_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fclosedNode
 * \brief Nodo función que cierra un descriptor de fichero.
 * 
 * La ejecución de este nodo conlleva el cierre de un descriptor de fichero.
 */   
class fcloseNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo que representa el descriptor de fichero
    */ 
   fcloseNode  (runNode * file);
    /**
    * Método  de ejecución. Procede a cerrar el descriptor de fichero 
    * finalizando todas las operaciones pendientes. Toma como valor
    * un booleano que indica si el proceso se llevó a cabo correctamente. 
    */    
   void run ();
 private:
   runNode *file_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
