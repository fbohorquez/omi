//stmtNode.h
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
 * \file stmtNode.h
 * \brief Nodos de sentencias
 *
 * Este fichero incluye nodos que representan sentencias.
 *
 * Liesh proporciona sentencias de diferente naturaleza y funcionalidad.
 * Las sentencias se pueden categorizar en dos grupos.
 *
 * \li Sentencias de control.
 * \li Sentencias de función.
 *
 * Las sentencias de control permiten influir en la secuencia de
 * ejecución del programa. Algunos ejemplos son las sentencias "if",
 * "while"...
 *
 * Las sentencias de función realizan una determinada operación sobre
 * un nodo y el valor de interno de este. Como ejemplos pueden ser
 * la sentencia "print", "read",...
 *
 *
 */
//----------------------------------------------------------------------
#ifndef _STMTNODE_
#define _STMTNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

#include "runTree.h"
#include "sTable.h"
#include "typeNode.h"
#include "operatorNode.h"
#include "componentNode.h"
#include "../error.h"
#include "../lshParser.h"
using namespace std;
extern int yylineno;
extern int yyparse ();
extern void yyrestart(FILE*);
extern FILE* yyin;
//----------------------------------------------------------------------
class noNode :
   public runNode {
 public:
   noNode ();
   void run ();
};
//----------------------------------------------------------------------
class breakException :
   public std::exception {
 public:
   breakException (int n = 1);
   const char* what() const throw();
   void end ();
 private:
   int n_;
};
//----------------------------------------------------------------------
class continueException :
   public std::exception {
 public:
   continueException (int n = 1);
   const char* what() const throw();
   void end ();
   bool islast ();
 private:
   int n_;
};
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
class includeNode :
   public runNode {
 public:
   includeNode (runNode* file);
   void run ();
 private:
   runNode* file_;
};
//----------------------------------------------------------------------
/**
 * \class printNode
 * \brief Nodo sentencia print
 *
 * Esta clase define el nodo correspondiente a la sentencia "print".
 *
 * La sentencia "print" se encarga de imprimir la cadena del nodo imprimible
 * asociado en la salida estandar.
 */
class printNode : public runNode {
 public:
   /**
    * Constructor de clase. Asocia un nodo hijo al
    * nodo sentnecia print.
    *
    * \param exp Nodo sobre el que se ejecutará la sentencia print.
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
//----------------------------------------------------------------------
class ifNode :
   public runNode {
 public:
   ifNode (runNode* exp, runNode* ifb, runNode* elseb);
   void run ();
 private:
   runNode *exp_, *ifb_, *elseb_;
};
//----------------------------------------------------------------------
class whileNode :
   public runNode {
 public:
   whileNode (runNode* exp, runNode* rb);
   void run ();
 private:
   runNode *exp_, *rb_;
};
//----------------------------------------------------------------------
class dowhileNode :
   public runNode {
 public:
   dowhileNode (runNode* exp, runNode* rb);
   void run ();
 private:
   runNode *exp_, *rb_;
};
//----------------------------------------------------------------------
class foreachNode :
   public runNode {
 public:
   foreachNode (runNode* val, runNode* exp, runNode* rb = NULL, runNode* key = NULL);
   void run ();
 private:
   void run_case_num ( numNode * n);
   void run_case_array ( arrayNode * a);
   void run_case_bool ( logicNode * l);
   void run_case_str ( stringNode * s);
   runNode *exp_, *rb_, *val_, *key_;
};
//----------------------------------------------------------------------
class foreachGeneratorNode :
   public arrayNode {
 public:
   foreachGeneratorNode (runNode *elem, runNode* val, runNode* exp, runNode* rb, runNode* key = NULL, runNode *if_cond = NULL, runNode * elem_key = NULL);
   void run ();
 private:
   void run_case_num ( numNode * n);
   void run_case_array ( arrayNode * a);
   void run_case_bool ( logicNode * l);
   void run_case_str ( stringNode * s);
   void generator ();
   runNode *elem_, *exp_, *rb_, *val_, *key_, *if_cond_, *elem_key_;
};
//----------------------------------------------------------------------
class iloopNode :
   public runNode {
 public:
   iloopNode (runNode* iter, runNode* stmt, runNode *id = NULL, runNode *second_id = NULL, runNode *inc = NULL);
   void run ();
   static runNode * get_ielement ();
   static runNode * get_ielement_n (int i);
   static runNode * set_ielement (runNode* node);
   static runNode * push_ielement (runNode* node);
   static runNode * pop_ielement ();
   static void push_level ();
   static void pop_level ();
   void setId (runNode * node, bool second = false);
 private:
   void run_case_num ( numNode * n);
   void run_case_array ( arrayNode * a);
   void run_case_bool ( logicNode * l);
   void run_case_str ( stringNode * s);
   static int icount;
   static vector<runNode*> ielement;
   static vector<int> stack_icount;
   static vector<vector<runNode*> > stack_ielement;
   runNode *iter_, *stmt_, *id_, *second_id_, *inc_;
};
//----------------------------------------------------------------------
class incloopNode :
   public runNode {
 public:
   incloopNode (runNode* id, runNode* max, runNode* stmt);
   void run ();
 private:
   runNode *id_, *max_, *stmt_;
};
//----------------------------------------------------------------------
class caseNode :
   public runNode {
 public:
   caseNode (runNode* exp, runNode* cb, runNode* cases);
   void run (runNode* eval);
   void run ();
 private:
   runNode *exp_, *cb_;
   runNode* cases_;
   bool runall_;
};
//----------------------------------------------------------------------
class switchNode :
   public runNode {
 public:
   switchNode (runNode* eval, runNode* cases);
   void run ();
 private:
   runNode* eval_;
   runNode* cases_;
};
//----------------------------------------------------------------------
class typeofNode :
   public runNode {
 public:
   typeofNode (idNode* id);
   void run ();
   static string type (runNode *r);
 private:
   idNode *id_;
};
//----------------------------------------------------------------------
class breakNode:
   public runNode {
 public:
   breakNode (int n = 1);
   void run ();
 private:
   int n_;
};
//----------------------------------------------------------------------
class continueNode:
   public runNode {
 public:
   continueNode (int n = 1);
   void run ();
 private:
   int n_;
};
//----------------------------------------------------------------------
class exitNode:
   public runNode {
 public:
   void run ();
};
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
class gotoException :
   public std::exception {
 public:
   /**
    * Método que se ejecuta cuando la excepción no es atrapada
    */
   const char* what() const throw();
};
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
/**
 * \class inputNode
 * \brief Nodo de entrada de usuario
 *
 * Lee de la entrada estandar del usuario y guarda el contenido en
 * un nodo string.
 *
 * La entrada puede ser de dos tipos
 *
 * tipo 0: correspondiente a la sentencia "input id" toma valores del teclado hasta que
 * se hace un doble salto de línea
 *
 * tipo 1: correspondiente a la sentencia "inputline id" toma valores del teclado hasta que
 * se hace un salto de linea
 *
 *
 * Es posible especificar un prompt para la entra mediante la sentencia "input<prompt> id"
 */
class inputNode :
   public stringNode {
 public:
   /**
    * Constructor de la clase
    * Recibe el identificador que se utilizará para referenciar en la tabla de simbolos el
    * la cadena rebicida, el tipo de entrada, y el prompt a utilizar
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
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
class sizeOfNode : public arithNode {
   public:
      sizeOfNode (runNode* node);
      void run ();
   private:
      runNode * node_;
};
//----------------------------------------------------------------------
class datInfoNode : public runNode {
   public:
      datInfoNode (runNode* node);
      void run ();
   private:
      runNode * node_;
};
//----------------------------------------------------------------------
class throwException :
   public std::exception {
 public:
   throwException (runNode* resp);
   const char* what() const throw();
   runNode* val () const;
 private:
   runNode* resp_;
};
//----------------------------------------------------------------------
class throwNode : public runNode {
   public:
      throwNode (runNode* obj);
      void run ();
   private:
      runNode *obj_;
};
//----------------------------------------------------------------------
class tryNode : public runNode {
   public:
      tryNode (runNode* tryblock, runNode *id, runNode *catchblock);
      void run ();
   private:
      runNode * tryblock_, *id_, *catchblock_;
};
//----------------------------------------------------------------------
class forNode :
   public runNode {
 public:
   forNode (runNode* asig, runNode* exp, runNode* inc, runNode* rb);
   void run (); 
 private:
   runNode *exp_, *rb_, *asig_, *inc_;
};
//----------------------------------------------------------------------
#endif
//----------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
