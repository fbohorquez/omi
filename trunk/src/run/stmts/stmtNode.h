//stmtNode.h
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
 * \file stmtNode.h
 * \brief Nodos de sentencias generales.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes
 * a las sentencias básicas, así como los nodos necesarios para definir el
 * concepto de sentencia . Estos son modelados mediante clases de objetos. 
*/

#ifndef _RUN_STMTS_STMTNODE_
#define _RUN_STMTS_STMTNODE_

#include "../tree/runTree.h"

#include "condStmtNode.h"
#include "ioStmtNode.h"
#include "loopStmtNode.h"
#include "../../lshParser.h"

extern int yylineno;
extern int yyparse ();
extern void yyrestart(FILE*);
extern FILE* yyin;
extern string infile;

//-------------------------------------------------------------------------------------------

/**
 * \class noNode
 * \brief Nodo sentencia vacía.
 * 
 * Este nodo representa una sentencia que no hace nada. 
*/
class noNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    */   
   noNode ();
   /**
    * Su ejecución no produce ningún resultado
    */
   void run ();
};

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
 * Haciendo un uso anidado del mismo es posible enlazar varios nodos
 * de ejecución.
 * 
 * Las sentencias pueden presentarse en un primer nivel si no se encuentra
 * dentro de ningún bloque, o dentro de otras sentencias en forma de bloque. 
 */
class stmtNode :public runNode  {
 public:
   /**
    * Constructor de la clase.
    * \param node1 Nodo que se ejecutará en primer lugar.
    * \param node2 Nodo que se ejecutará en segundo lugar.
    * \param bloq Determina en la línea en la que se encuentra la sentencia 
    * dentro del fichero
    * \param fistlevel Determina si la sentencia es de primer nivel
    */
   stmtNode (runNode* node1, runNode* node2, YYLTYPE bloq = YYLTYPE(), bool firstlevel = false);
   /**
    * Método de ejecución del nodo.
    * Ejecuta secuencialmente los nodos asociados en la
    * construcción del objeto.
    */
   void run ();
   /**
    * Añade una nueva línea para el control de líneas en la que se
    * encuentra cada sentencia
    */
   static void newLine (void);
   /**
    * Líneas en el fichero
    */
   static int row_;
   /**
    * Determina si se ha llevado a cabo un error al procesar el código fuente
    */
   static bool compile_error;
 private:
   runNode *node1_, *node2_;
   int line_;
   bool firstlevel_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class includeNode
 * \brief Nodo sentencia inclusión de fichero.
 * 
 * Incluye un fichero que será interpretado. 
 * 
*/
class includeNode :
   public runNode {
 public:
   /**
    * Constructor de la clase. 
    * \param file Nodo que representa la ruta al fichero.
    */   
   includeNode (runNode* file);
   /**
    * Método de ejecución del nodo. Accede y lee el contenido 
    * de un fichero que será tratado como código fuente y será
    * interpretado.  Si el fichero no existe se produce un error. 
    */   
   void run ();
 private:
   runNode* file_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class typeofNode
 * \brief Nodo impresión de tipo.
 * 
 * Este nodo imprime el tipo de un nodo dado.  El nodo dado debe ser 
 * un identificador.
 */
class typeofNode :
   public runNode {
 public:
   /**
    * Constructor de clase.
    * \param id Nodo identificador.
    */
   typeofNode (idNode* id);
   /**
    * Método que ejecuta el nodo. Imprime en la salida estándar el 
    * tipo de dato que guarda como valor el identificar dado
    */
   void run ();
   /**
    * Devuelve el tipo de un nodo dado como una cadena. 
    * \param r Nodo al que se obtiene el tipo.
    * \return Cadena que representa el tipo del nodo.
    */
   static string type (runNode *r);
 private:
   idNode *id_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class breakException
 * \brief Excepción rotura de bloque.
 * 
 * Dado un bloque de sentencias este nodo permite romper la secuencia
 * de ejecución hasta la salida del bloque. Esta excepción es lanzada 
 * por la sentencia break (\see breakNode).
 * 
*/
class breakException :
   public std::exception {
 public:
   /**
    * Constructor de la clase.
    * \param init. Número de bloques anidados de los que se saldrá.
    */ 
   breakException (int n = 1);
   /**
    * Método que será llamado cuando no se capture la función, esta situación 
    * se dará cuando se produzca una sentencia break fuera de un bloque de 
    * sentencias. 
    */
   const char* what() const throw();
   /**
    * Si el número de bloques anidados es mayor que uno lanza
    * una excepción break decrementando el número de bloques anidados,
    */
   void end ();
 private:
   int n_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class breakNode
 * \brief Nodo sentencia rotura de bloque.
 * 
 * Este nodo representa una sentencia break, la cual consiste en finalizar la 
 * secuencia de sentencias en un bloque de estas, siguiendo en la siguiente
 * sentencia del bloque. Adicionalmente se puede especificar el número 
 * de bloques anidados de los que se desea salir. 
 * 
 * Si se utiliza la sentencia break fuera de un bloque de sentencias se produce un error.
 */
class breakNode:
   public runNode {
 public:
   /** 
    * Constructor de la clase.
    * \param n Número de bloques anidados de los que se saldrá.
    */
   breakNode (int n = 1);
   /**
    * Método que ejecuta el nodo. Finaliza la ejecución del bloque 
    * de sentencias determinado.
    */
   void run ();
 private:
   int n_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class exitNode
 * \brief Nodo sentencia de finalización.
 * 
 * Nodo que finaliza la ejecución del programa.
 */
class exitNode:
   public runNode {
 public:
   /**
    * Método que ejecuta el nodo. Finaliza la ejecución del programa
    * con un estado de 0.
    */
   void run ();
};

//-------------------------------------------------------------------------------------------

/**
 * \class labelNode
 * \brief Nodo etiqueta.
 *
 * Un nodo etiqueta permite el acceso a una rama de árbol de ejecución
 * a partir de un un identificador.
 *
 * Internamente guarda en la tabla de símbolos una referencia a un nodo 
 * sentencia determinado del árbol de ejecución.
 *
 * \see gotoNode
 */
class labelNode :
   public runNode {
 public:
   /**
   * Constructor de la clase.
   * \param id Identificador de la etiqueta.
   * \param stmt Nodo sentencia que será ejecutado lal llamarse. 
   */
   labelNode (runNode* id, runNode* stmt);
   /**
    * Añade a la tabla de símbolos una referencia al nodo dado como 
    * sentencia y prosigue la ejecución del mismo.
    */
   void run ();
 private:
   runNode *id_, *stmt_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class gotoException
 * \brief Excepción de salto a etiqueta.
 * 
 * Esta excepción se produce cuando se ejecuta una sentencia goto. 
 * Sirve para que no se siga la ejecución en la siguiente sentencia.
 */
class gotoException :
   public std::exception {
 public:
   /**
    * Método que se ejecuta cuando la excepción no es atrapada.
    */
   const char* what() const throw();
};

//-------------------------------------------------------------------------------------------

/**
 * \class gotoNode
 * \brief Nodo de salto.
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
    * Constructor de clase.
    * \param node Nodo que se corresponde con el identificador de la etiqueta. 
    */
   gotoNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Accede al nodo sentencia referenciado 
    * por el identificador de etiqueta pasado en la inicialización y lo ejecuta.
    * Tras la ejecución lanza una excepción para que no se siga las sentencias
    * siguientes. Si la etiqueta no existe no se hace ninguna acción.
    */
   void run ();
 private:
   runNode *node1_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class withNode
 * \brief Nodo bloque en el contexto de un objeto.
 * 
 * Establece un objeto como contexto principal para un bloque de sentencias, 
 * de forma que las tablas de símbolos a las que se accederá será a la 
 * del objeto, y si el recurso solicitado no se encuentra se hará sobre el 
 * contexto en uso.
 * 
 * Se mantiene una pila de contextos principales al que se le introduce 
 * los contextos derivados de sentencias with anidadas.
 */
class withNode : public runNode {
   public: 
      /**
       * Constructor de la clase.
       * \param node Nodo que representa el objeto.
       * \param node Nodo que representa el bloque de sentencias.
       */
      withNode (runNode* node, runNode *stmts);
      /**
       * Método que ejecuta el nodo. Establece el contexto 
       * del objeto como contexto principal. 
       */
      void run();
      /**
       * Añade un nodo como objeto de contexto principal en la pila de objetos.
       * \param node Nodo que será añadido.
       */
      static void push_with (runNode* node);
      /**
       * Obtiene el objeto en uso de la pila.
       * \return Objeto en uso.
       */
      static runNode *get_with ();
      /**
       * Elimina el último elemento de la pila.
       */
      static void pop_with ();
      
   private:
      static vector<runNode *> stack_with;
      static int top_with;
      runNode *node_, *stmts_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class sizeOfNode 
 * \brief Nodo sentencia espacio de memoria.
 * 
 * Nodo que obtiene el espacio de memoria ocupado por un nodo.
 */
class sizeOfNode : public arithNode {
   public:
      /**
       * Constructor de la clase.
       * \param node Nodo a calcular tamaño.
       */
      sizeOfNode (runNode* node);
      /**
       * Método que ejecuta el nodo. Toma como 
       * valor el espacio de memoria en bytes que ocupa el nodo dado.
       */
      void run ();
   private:
      runNode * node_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class datInfoNode
 * \brief Nodo información sobre dato.
 * 
 * La ejecución de este nodo consiste en imprimir datos internos
 * del nodo tales como la posición de memoria que ocupa, el tipo o el
 * número de referencias.
 */
class datInfoNode : public runNode {
   public:
      /**
       * Constructor de la clase.
       * \param node Nodo que será consultado.
       */
      datInfoNode (runNode* node);
      /**
       * Ejecución del nodo. Imprime en la salida estandar el tipo del nodo, 
       * identificador asociado si tuviera, número de elementos en caso de
       * ser compuesto, el valor  y el número de referencias.
       */
      void run ();
   private:
      runNode * node_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class throwException 
 * \brief Excepción de exepción lanzada.
 * 
 * Esta excepción se produce cuando se ejecuta 
 * una sentencia throw (\see throwNode).  Será atrapada por una 
 * sentencia try...catch (\see tryNode), produciéndose la ejecución de las 
 * sentencias correspondiente al bloque catch.
 * 
 * La excepción guarda un valor que podrá ser usado en el bloque catch.
 */
class throwException :
   public std::exception {
 public:
   /**
    * Constructor de la excepción .
    * \param resp Valor de la excepción.
    */
   throwException (runNode* resp);
   /**
    * Método que será ejecutado cuando la excepción no es atrapada.
    */
   const char* what() const throw();
   /**
    * Obtiene  el valor de la excepción.
    * \return Valor de la excepción.
    */
   runNode* val () const;
 private:
   runNode* resp_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class throwNode
 * \brief Nodo lazar excepción.
 * 
 * Este nodo permite lanzar una excepción para que sea capturada en 
 * un bloque try...catch (\see tryNode). La excepción puede tener un valor
 * que será pasado al bloque catch.
 */ 
class throwNode : public runNode {
   public:
      /**
       * Constructor de la clase.
       * \param obj Nodo que representa el valor de la excepción.
       */
      throwNode (runNode* obj);
      /**
       * Método que ejecuta el nodo. Lanza la excepción para que sea 
       * capturada por un bloque try..catch. Si la excepción no es capturada
       * se produce un error.
       */
      void run ();
   private:
      runNode *obj_;
};

//-------------------------------------------------------------------------------------------

/**
 * \class tryNode
 * \brief Nodo sentencia try...catch.
 * 
 * Este nodo permite escribir una sentencia try..catch. Esta sentencia
 * consta de dos bloques. El bloque try se ejecuta normalmente, pero 
 * si se lanza una excepción throw esta será capturada y pasará a ejecutarse
 * el bloque catch. Además el bloque catch es precedido de una expresión
 * en el que se especifica un id al que será asignado el valor de la excepción.
 */
class tryNode : public runNode {
   public:
      /**
       * Constructor de la clase.
       * \param tryblock Nodo correspondiente al bloque try.
       * \param id Nodo que hace de id al que se le asignará el valor de la excepción.
       * \param catchblock Nodo correspondiente al bloque catch.
       */
      tryNode (runNode* tryblock, runNode *id, runNode *catchblock);
      /**
       * Método que lleva a cabo la ejecución del nodo. Se ejecuta el 
       * bloque de sentencias try y si se produce una excepción se 
       * pasa la ejecución al bloque de sentencias catch asignándose el 
       * valor de la excepción en el identificador. 
       */
      void run ();
   private:
      runNode * tryblock_, *id_, *catchblock_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
