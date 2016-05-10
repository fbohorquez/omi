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
 * \brief Nodo función fork.
 * 
 * El nodo fork crea una bifurcación en el proceso actual. Cuando este
 * nodo es ejecutado se crea un proceso (hijo) copia del proceso actual (padre). 
 * En el proceso hijo el nodo tomará como valor aritmético 0, mientras
 * que en el proceso padre tomará como valor el identificador de proceso
 * del hijo. 
 * 
 */
class forkNode: public arithNode {
 public:
   /**
    * Constructor de la clase. 
    */  
   forkNode ();
   /**
    * Metodo  de ejecución. Crea una bifurcación en el proceso actual. Cuando este
    * nodo es ejecutado se crea un proceso (hijo) copia del proceso actual (padre). 
    * En el proceso hijo el nodo tomará como valor aritmético 0, mientras
    * que en el proceso padre tomará como valor el identificador de proceso
    * del hijo. 
    */    
   void run ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class waitNode
 * \brief Nodo función espera de proceso .
 * 
 * Para la ejecución del proceso hasta que finaliza la ejecución de todos 
 * sus procesos hijos o uno dado.
 */
class waitNode: public arithNode {
 public:
   /**
    * Constructor de la clase.
    * \param  pID Identificador de proceso al que se debe esperar. Si es NULL
    * se esperan todos los procesos hijos.
    */  
   waitNode (runNode * pID = NULL);
   /**
    * Metodo  de ejecución. Para la ejecución del proceso hasta que 
    * finaliza la ejecución de todos sus procesos hijos o uno dado.
    */       
   void run ();
 private:
   runNode * pID_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class  getpidNode
 * \brief Nodo función obtener identificador de proceso.
 * 
 * Nodo que obtiene el identificador del proceso.
 * 
 */
class getpidNode: public arithNode {
 public:
  /**
    * Constructor de la clase.
    */   
   getpidNode ();
    /**
    * Metodo  de ejecución. Toma como valor el identificador 
    * de proceso del proceso actual
    */      
   void run ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getppidNode
 * \brief Nodo función obtener identificador de proceso padre.
 * 
 * Nodo que obtiene el identificador del proceso padre.
 */
class getppidNode: public arithNode {
 public:
   /**
    * Constructor de la clase.
    */ 
   getppidNode ();
   /**
    * Metodo  de ejecución. Toma como valor el identificador 
    * de proceso del proceso padre
    */           
   void run ();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class processNode
 * \brief Nodo llamada concurrente.
 * 
 * Nodo que llama a una función dada como otro proceso.
 */
class processNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param  Nodo que hace de función
    * \param Nodo que representa la lista de parámetros
    */   
   processNode (runNode* func, runNode* params = NULL);
   /**
    * Metodo  de ejecución. Crea un nuevo proceso y llama a la función
    * dada pasándole la lista de parámetros. Como valor se toma 
    * un valor booleano que indica si el proceso se llevó a cabo de forma correcta.
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
 * \brief Nodo función finalización de proceso.
 * 
 * Finaliza la ejecución del proceso actual
 * 
 */
class exitProcessNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    */   
   exitProcessNode ();
   /**
    * Metodo  de ejecución. Finaliza la ejecución del proceso actua. 
    * Como valor se toma un valor booleano que indica si el proceso 
    * se llevó a cabo de forma correcta.
    */      
   void run();
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class  signalNode
 * \brief Node función envío de señal a proceso .
 * 
 * Nodo que envía una señal a un proceso a partir de su identificador 
 * de proceso. La señal se representa mediante un entero según el
 * modelo de códigos Unix.
 */
class signalNode : public logicNode {
 public:
  /**
    * Constructor de la clase.
    * \param  pid Nodo que representa el identificador de proceso
    * \param signal Nodo que representa la señal.
    */ 
   signalNode (runNode* pid, runNode* signal);
    /**
      * Metodo  de ejecución. Envía una señal a un proceso a partir de su identificador 
      * de proceso. Como valor se toma un valor booleano que indica si el proceso 
      * se llevó a cabo de forma correcta.
    */      
   void run();
 private:
   runNode* pid_, *signal_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class signalhandlerNode
 * \brief Nodo función manejadora de señales.
 * 
 * Nodo que permite asociar una función como manejador de una determinada 
 * señal de proceso.  La función no recibirá parámetros algunos.
 * 
 */
class signalhandlerNode : public logicNode {
 public:
   /**
    * Constructor de la clase.
    * \param signal Nodo que representa la señal a la que se le asociará la función
    * \param function Nodo función.
    */   
   signalhandlerNode (runNode* signal, runNode* function);
   /**
    * Metodo  de ejecución.  Asocia la función como manejador de la
    * señal de proceso. Como valor se toma un valor booleano que indica si el proceso 
      * se llevó a cabo de forma correcta.
    */      
   void run();
   /**
    * Llama al manejador asociad a la señal dada
    * \param signum Idetificador de señal
    */
   static void callHandlers (int signum);
 private:
   runNode* function_, *signal_;
   static vector<runNode *> instances;
};
//----------------------------------------------------------------------
#endif
//----------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
