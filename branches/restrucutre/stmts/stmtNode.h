//stmtNode.h
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
 * \file stmtNode.h
 * \brief Nodos de sentencias generales .
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes
 * a las sentencias básicas, así como los nodos necesarios para definir el
 * concepto de sentencia . Estos son modelados mediante clases de objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_STMTS_STMTNODE_
#define _RUN_STMTS_STMTNODE_

#include "../tree/runTree.h"

#include "condStmtNode.h"
#include "ioStmtNode.h"
#include "loopStmtNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \file noNode
 * \brief Nodos operadores y funciones sobre .
 * 
*/
class noNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    */   
   noNode ();
   void run ();
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \file breakException
 * \brief Nodos operadores y funciones sobre .
 * 
*/
class breakException :
   public std::exception {
 public:
   /**
    * Constructor de la clase.
    * \param init. Nodo 
    */ 
   breakException (int n = 1);
   const char* what() const throw();
   void end ();
 private:
   int n_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class stmtNode
 * \brief Nodo de sentencia
 *
 * La funcionalidad de este nodo es meramente constructiva. Su función
 * es enlazar dos nodos de diferente naturaleza.
 *
 * El nodo de sentencia es asociado a otros dos nodos. Su ejecución
 * consistirá en ejecutar ambos nodos de forma secuencial.
 *
 * Haciendo un uso recursivo del mismo es posible enlazar varios nodos
 * de ejecución.
 */
extern string infile;
class stmtNode :public runNode  {
 public:
   /**
    * Constructor de la clase. Enlaza el nodo a otros dos nodos
    * hijos.
    *
    * \param node1 Nodo que se ejecutará en primer lugar.
    * \param node2 Nodo que se ejecutará en segundo lugar.
    */
   stmtNode (runNode* node1, runNode* node2, YYLTYPE bloq, bool firstlevel);
   stmtNode (runNode* node1, runNode* node2, YYLTYPE bloq);
   stmtNode (runNode* node1, runNode* node2);
   /**
    * Método de ejecución del nodo.
    *
    * Ejecuta secuencialmente los nodos asociados en la
    * construcción del objeto.
    */
   void run ();
   static bool compile_error;
   static void newLine (void);
   static int row_;
 private:
   runNode *node1_, *node2_;
   int line_;
   bool firstlevel_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \file includeNode
 * \brief Nodos operadores y funciones sobre .
 * 
*/
class includeNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    * \param file Nodo .
    */   
   includeNode (runNode* file);
   /**
    * Método de ejecución del nodo.
    *
    */   
   void run ();
 private:
   runNode* file_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class typeofNode :
   public runNode {
 public:
   typeofNode (idNode* id);
   void run ();
   static string type (runNode *r);
 private:
   idNode *id_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class breakNode:
   public runNode {
 public:
   breakNode (int n = 1);
   void run ();
 private:
   int n_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class exitNode:
   public runNode {
 public:
   void run ();
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class labelNode
 * \brief Nodo etiqueta
 *
 * Un nodo etiqueta permite el acceso a una rama de árbol de ejecución
 * a partir de un un identificador.
 *
 * Internamente guarda en la tabla de símbolos una referencia a un nodo sentencia determinado
 * del árbol de ejecución.
 *
 * Para acceder ejecutar el nodo y por consecuente todos sus hijos se define el nodo gotoNode
 *
 */
class labelNode :
   public runNode {
 public:
   /**
   * Constructor de la clase.
   *
   * El primer parámetro debe ser un nodo identificador, el segundo un
   * nodo sentencia.
   */
   labelNode (runNode* node1, runNode* node2);
   /**
    * Ejecuta el nodo guardando en la tabla de símbolos una referencia
    * al nodo sentencia con el identificador facilitado.
    */
   void run ();
 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class gotoException :
   public std::exception {
 public:
   /**
    * Método que se ejecuta cuando la excepción no es atrapada
    */
   const char* what() const throw();
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class gotoNode
 * \brief Nodo de salto
 *
 * Este nodo permite saltar a una línea del código especificada por
 * una etiqueta. Para ello obtiene de la tabla de símbolos la sentencia a
 * la que hace referencia el identificador pasado en su inicialización. Luego
 * ejecuta el nodo sentencia.
 */
class gotoNode :
   public runNode {
 public:
   /**
    * Constructor de clase
    *
    * Crea un nodo salto a partir de un identificador
    */
   gotoNode (runNode* node);
   /**
    * Ejecuta el nodo accediendo en la tabla de símbolos al nodo sentencia
    * referenciado por el identificador pasado en la inicialización
    */
   void run ();
 private:
   runNode *node1_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class withNode : public runNode {
   public: 
      withNode (runNode* node, runNode *stmts);
      void run();
      static void push_with (runNode* node_);
      static runNode *get_with ();
      static void pop_with ();
      
   private:
      static vector<runNode *> stack_with;
      static int top_with;
      runNode *node_, *stmts_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class sizeOfNode : public arithNode {
   public:
      sizeOfNode (runNode* node);
      void run ();
   private:
      runNode * node_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class datInfoNode : public runNode {
   public:
      datInfoNode (runNode* node);
      void run ();
   private:
      runNode * node_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class throwException :
   public std::exception {
 public:
   throwException (runNode* resp);
   const char* what() const throw();
   runNode* val () const;
 private:
   runNode* resp_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class throwNode : public runNode {
   public:
      throwNode (runNode* obj);
      void run ();
   private:
      runNode *obj_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
class tryNode : public runNode {
   public:
      tryNode (runNode* tryblock, runNode *id, runNode *catchblock);
      void run ();
   private:
      runNode * tryblock_, *id_, *catchblock_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
