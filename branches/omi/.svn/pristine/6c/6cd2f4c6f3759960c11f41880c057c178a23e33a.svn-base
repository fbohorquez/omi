//processOpNode.h
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
 * \file processOpNode.h
 * \brief Nodos operadores sobre procesos.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores y funciones aplicables sobre procesos.
 * Estos son modelados mediante clases de objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_OPERATORS_PROCESSOPNODE_
#define _RUN_OPERATORS_PROCESSOPNODE_

#include "../tree/typeNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class execNode
 * \brief Node operador ejecución de comando.
 * 
 * Este nodo se encarga de ejecutar un comando en el sistema tomando
 * como valor la salida del mismo.  
 * 
 */
class execNode : public stringNode {
 public:
   /**
    * Constructor de la clase.
    * \param  node.  Nodo comando
    */
   execNode (runNode* node);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo que hace de 
    * comando. Toma como valor el resultado de la ejecución de este en 
    * el sistema
    */   
   void run ();
 private:
   runNode	 *node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class evalNode
 * \brief Node operador evaluación.
 * 
 * Este nodo procesa y evalua una cadena como si de codigo fuente se 
 * tratase. Como valor toma el resultado devuelto por la primera sentencia 
 * return ejecutada al evaluar la cadena.
 */
class evalNode : public nexpNode {
 public:
   /**
    * Constructor de la clase.
    * \param  node.  Nodo que representa la cadena que será interpretada
    */
   evalNode (runNode* node);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    * que representa una cadena de codigo fuente. Toma como valor el resultado 
    * devuelto por la primera sentencia return evaluada, si no se ejecuta  una sentencia
    * return al procesar la cadena se tomará como valor el nodo nulo. 
    */      
   void run ();
 private:
   runNode	 *node_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class forkNode
 * \brief Node operador .
 * 
 */
class forkNode: public arithNode {
 public:
   /**
    * Constructor de la clase.
    * \param  
    */  
   forkNode ();
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    */    
   void run ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class waitNode
 * \brief Node operador .
 * 
 */
class waitNode: public arithNode {
 public:
   /**
    * Constructor de la clase.
    * \param  
    */  
   waitNode (runNode * pID = NULL);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    */       
   void run ();
 private:
   runNode * pID_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class  getpidNode
 * \brief Node operador .
 * 
 */
class getpidNode: public arithNode {
 public:
  /**
    * Constructor de la clase.
    * \param  
    */   
   getpidNode ();
    /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    */      
   void run ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getppidNode
 * \brief Node operador .
 * 
 */
class getppidNode: public arithNode {
 public:
   /**
    * Constructor de la clase.
    * \param  
    */ 
   getppidNode ();
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    */       
   void run ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class processNode
 * \brief Node operador .
 * 
 */
class processNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  
    * \param
    */   
   processNode (runNode* func, runNode* params = NULL);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    */       
   void run();
 private:
   static void *processRun (void *ptr);
   runNode *func_, *params_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class exitProcessNode
 * \brief Node operador .
 * 
 */
class exitProcessNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  
    */   
   exitProcessNode ();
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    */      
   void run();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class  signalNode
 * \brief Node operador .
 * 
 */
class signalNode : public logicNode {
 public:
  /**
    * Constructor de la clase.
    * \param  
    * \param
    */ 
   signalNode (runNode* pid, runNode* signal);
    /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    */      
   void run();
 private:
   runNode* pid_, *signal_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class signalhandlerNode
 * \brief Node operador .
 * 
 */
class signalhandlerNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param
    *   
    */   
   signalhandlerNode (runNode* signal, runNode* function);
   /**
    * Metodo  de ejecución. Procede a la ejecución  del nodo asociado 
    */      
   void run();
   static void callHandlers (int signum);
 private:
   runNode* function_, *signal_;
   static vector<runNode *> instances;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
