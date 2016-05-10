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
 * \brief Node operador .
 * 
 * Este nodo se encarga   
 * 
 */   
class fileNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    * \param mode. Nodo
    */
   fileNode (runNode * file, runNode * mode = NULL);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
    */    
   void run ();
   inline fstream *get () const {
      return f_;
   }
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
 * \brief Node operador .
 * 
 * Este nodo se encarga 
 * 
 */   
class fputNode : public arithNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    * \param val. Nodo
    */
   fputNode (runNode * file, runNode * val);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
    */     
   void run ();
 private:
   runNode *file_, *val_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fgetNode
 * \brief Node operador.
 * 
 * Este nodo se encarga de .  
 * 
 */   
class fgetNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    * \param size. Nodo
    */  
   fgetNode (runNode * file, runNode *size = NULL);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
    */     
   void run ();
 private:
   runNode *file_, *size_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class freadNode
 * \brief Node operador .
 * 
 * Este nodo se encarga de .  
 * 
 */   
class freadNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    */
   freadNode (runNode * file);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
    */     
   void run ();
 private:
   runNode *file_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fwriteNode
 * \brief Node operador .
 * 
 * Este nodo se encarga de .  
 * 
 */   
class fwriteNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    * \param str. Nodo
    */   
   fwriteNode (runNode * file, runNode* str);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
    */     
   void run ();
 private:
   runNode *file_, *str_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fappendNode
 * \brief Node operador .
 * 
 * Este nodo se encarga de .  
 * 
 */   
class fappendNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    * \param str. Nodo
    */ 
   fappendNode (runNode * file, runNode* str);
    /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
    */    
   void run ();
 private:
   runNode *file_, *str_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fsekNode
 * \brief Node operador .
 * 
 * Este nodo se encarga de .  
 * 
 */   
 class fseekNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    * \param int. Nodo
    */ 
   fseekNode  (runNode * file, runNode* offset, int pos = 0);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
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
 * \brief Node operador .
 * 
 * Este nodo se encarga de ejecutar .  
 * 
 */   
class ftellNode : public arithNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    */ 
   ftellNode  (runNode * file);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
    */     
   void run ();
 private:
   runNode *file_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class fclosedNode
 * \brief Node operador .
 * 
 * Este nodo se encarga de .  
 * 
 */   
class fcloseNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  file.  Nodo 
    */ 
   fcloseNode  (runNode * file);
    /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo. 
    * 
    * Toma como valor el resultado de la ejecución de este en 
    */    
   void run ();
 private:
   runNode *file_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
