//classNode.h
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
 * \file classNode.h
 * \brief Nodos relacionados con clases de objetos.
 *
 * En este fichero se encuentran los nodos relacionados con clases de 
 * objetos. Estos son modelados mediante clase de objetos.
 *
 */
//-------------------------------------------------------------------------------------------
#ifndef _RUN_TABLE_CLASSNODE_
#define _RUN_TABLE_CLASSNODE_

#include "funcNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class classNode
 * \brief Nodo clase
 *
 * Un nodo clase representa la
 * definición de una clase. Una clase es una estructura funcional utilizada
 * en la programación orientada a objetos.
 *
 * Un nodo clase sirve como interfaz para definir y manipular las clases
 * en ejecución.
 *
 * Todo nodo clase tiene un contexto de tablas de símbolos  donde se referencia
 * a los atributos y métodos de la misma.
 *
 * Para inicializar un nodo clase se precisa del identificador de la misma y un
 * cuerpo.
 *
 * El cuerpo de la clase consite en una serie de sentencias, que por limitaciones
 * de gramática sólo pueden ser declaraciones de funciones o variables.
 *
 * La ejecución de un nodo clase se corresponde con la declaración de la misma.
 * Primero crea una referencia a si misma en la tabla de clases activa. Luego crea
 * un nuevo contexto de tablas de símbolos, que usará de forma interna. Para finalizar
 * cambia el contexto activo al iterno y se lleva a cabo la ejecución del cuerpo.
 *
 * Los nodos funciones declarados en el cuerpo de la clase serán referenciados
 * desde la tabla de funciones de la clase y son considerados los métodos de la msima.
 * De igual forma las variables son referenciadas mediante al tabla de variables y 
 * son consideradas como los atributos.
 *
 * En omi una determinada clase puede extender a otra, lo significa que heredará sus
 * métodos y atributos.
 *
 * Los nodos clase presentan un mecanismo para crear nuevas instancias de las
 * mismos denomidas objetos. Este mecanismo es utilizado por nodos como el
 * nodo "nueva instancia" (\see newNode). Cuando se crear una nueva instancia se
 * genera una copia de la tabla de símbolos de variables en un nodo de tipo objeto
 * Este objeto además referencia a la clase para acceder a los métodos. 
 * El objeto se puede asignar a una un nodo id como si fuera un tipo de dato, 
 * guardándose asi una referencia en la tabla de variables activa.
 * 
 * Las clases disponen de un contexto inteno con tablas para funciones y variables 
 * que será aplicables a los objetos como atributos y métodos. Además disponen
 * de un contexto estático que guarda los métodos y atributos aplicables a la propia 
 * clase.
 *
 */
class classNode :
   public runNode {
 public:
   /**
    * Constructor copia. Crea un nodo clase a partir de otro.
    * Para ello referencia al cuerpo y al identificador del nodo clase dado,
    * y copia la tabla de símbolos interna.
    */
   classNode (classNode* node);
   /**
    * Constructor que inicializa un nodo clase a partir de un
    * nodo identificador y un nodo cuerpo.
    * \param id Identificador de la clase
    * \param body Cuerpo de la clase
    * \param extends Clasa de la que extiende si es el caso
    */
   classNode (runNode* id, runNode* body, runNode *extends = NULL);
   /**
    * Lleva a cabo la ejecución del nodo clase corresponidiente
    * a la declaración de la misma. Para ello crea una referencia
    * en la tabla de clases activa a si misma, genera el contexto
    * interno, y luego, tras cambiar el contexto en uso, ejecuta el cuerpo.
    */
   void run ();
   /**
    * Crea y devuelve una instancia de la clase. Para ello
    * copia la tabla de variables del contexto de  la clase  en un nodo objeto,
    * y busca una función en la tabla de funciones
    * correspondiente al nombre de la clase. Esta función, considerada constructor,
    * será ejecutada con los parámetros indicados.
    */
   runNode* newcall (runNode *params);
   /**
    * Devuelve el contexto interno del nodo clase
    * \return Contexto interno.
    */
   inline sTable* insideTable () const { return inside_; }
   /**
    * Obtiene la clase padre con la que fue inicializada
    * \return Clase padre
    */
   inline classNode * getExtendClass () { return extend_class_; }
   /**
    * Obtiene el identificador con el que fue inicializada
    * \return ID de la clase
    */   
   inline runNode* getID () {return id_;}
   /**
    * Obtiene el identificador de la clase como una cadena
    * \return ID de la clase como cadena
    */
   inline string name(){
      if (idNode* id = dynamic_cast<idNode*>(id_))
         return id->name();
      return "";
   }
   /**
    * A partir de una clave obtiene el método cuyo identificador
    * se corresponde con la misma. Si no existe se devuelve NULL.
    * \param key Nombre del método
    * \return Método correspondiete a la clave.
    */
   runNode * getMethod (runNode * key);
   /**
    * A partir de una clave obtiene una la referencia al método cuyo identificador
    * se corresponde con la misma. Si no existe se devuelve NULL.
    * \param key Nombre del método
    * \return Referencia al método correspondiete a la clave.
    */
   refNode * getMethodRef (runNode * key);
   /**
    * Asocia una función como método de la clase con el identificador dado
    * \param key Clave que se utilizará como identificador
    * \param func Función que se asociará como método
    */
   void setMethod (runNode * key, runNode * func);
   /**
    * Obtiene un método estático de la clase a partir de una clave
    * \param key Nombre del método
    * \return Método estático correspondiente a la clave
    */ 
   runNode * getFromStatic (runNode *key);
   /**
    * Asocia una función como método estático de la clase con el identificador dado
    * \param key Clave que se utilizará como identificador
    * \param func Función que se asociará como método estático
    */
   void setFromStatic (runNode *key, runNode* val);
   /**
    * Devuelve un objeto con una tabla de símbolos correspondiente a la 
    * tabla de variables de la clase. Además asocia la clase  al objeto.
    * \return Objeto instancia de la clase
    */
   runNode * toObject ();
   static sTable* static_class;
   runNode * newelement_;
 private:
   runNode *id_, *body_, *extends_;
   sTable *inside_, *static_;
   bool exec_;
   classNode *extend_class_;
};
//-------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------
/**
 * \class newNode
 * \brief Nodo nueva instacia
 *
 * Este nodo es el encargado de crear una instancia de una clase como
 * un objeto.
 *
 * Un nodo newNode es un nodo de tipo no definido por lo que guarda una
 * referencia a otro nodo. Tras la ejecución un nodo newNode se tomará
 * como referencia una instancia de la clase determinada por un 
 * identificador dado.
 *
 * Cuando la instancia es creada se busca un método en la tabla de funciones
 * del contexto de la clase que se llame igual que la esta, este
 * método es llamado como método constructor. 
 */
class newNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase que se inicializa a partir de un nodo
    * identificador y una lista de parámetros
    * \param id Identificador de la clase que será instanciada
    * \param params Parámetros que será pasados al método 
    * constructor.
    */
   newNode (runNode* id, runNode* params);
   /**
    * Lleva a cabo la ejecución del nodo. Para ello busca en la
    * tabla de clases activa el nodo correspondiente al identificador
    * utilizado en la inicialización. Crea un objeto a partir de la
    * tabla de símbolos de variables de la clase. Luego accede y ejecuta 
    * el método constructor  de la clase, pasándole los parámetros con el que 
    * fue inicializado. Por último toma como valor la instancia creada.
    */
   void run ();
 private:
   runNode *id_, *params_;
   runNode * nodeR_;
};
//-------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------
/**
 * \class thisNode
 * \brief Nodo referencia al objeto
 *
 * Este nodo es del tipo expresión no definida. Toma como valor el objeto
 * que opera sobre la tabla de símbolos actual, que se corresponderá con
 * el nodo en uso del contexto actual.
 *
 */
class thisNode :
   public nexpNode {
 public:
   /**
    * Busca en el contexto activo el nodo en uso y toma
    * dicho valor.
    *
    * Si el contexto activo no tiene un nodo en uso se produce un error.
    */
   void run ();
   /**
    * Asigna el nodo dado como valor de la referencia interna
    * \param node Nodo que será asignado
    */
   virtual void noderef (runNode* node);
 private:
   runNode *nodeR_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class parentNode
 * \brief Node referencia a objeto padre
 *
 * Este nodo es del tipo expresión no definida. Toma como valor la clase padre del 
 * objeto que opera sobre la tabla de símbolos actual.
 *
 */
class parentNode : public thisNode {
   public:
      /**
       * Constructor de la clase
       */
      parentNode ();
      /**
       * Obtiene el método correspondiete a la clave dada de la clase 
       * que opera como padre en el cotnexto actual
       * \param key Clave que se usará para buscar el método
       * \return Método de la clase padre al que se accederá
       */
      runNode * get (runNode * key); 
      static classNode *link;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class staticNode
 * \brief Nodo estático
 * 
 * Cualquier nodo función o variable que sea definido durante la 
 * ejecución de este nodo tendrá el atributo de estático por lo
 * que pertenecerá a la propia clase. 
 */
class staticNode : public runNode {
   public:
      /**
       * Constructor de la clase
       */
      staticNode ();
      /**
       * Constructor de la clase
       * \param stmt Sentencia que será ejecutada como estática.
       */
      staticNode (runNode *stmt);
      /**
       * Ejecuta la sentencia asociada estableciendo cualquier 
       * definición como estática.
       */
      void run () ;
      static runNode* link;
   private:
      runNode * stmt_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class privateNode
 * \brief Nodo de acceso privado
 * 
 * Cualquier nodo función o variable que sea definido durante la 
 * ejecución de este nodo tendrá el atributo de privado por lo que 
 * solo puede ser accedido si el acceso se produce sin que exista un 
 * cambio de contexto. 
 * 
 */
class privateNode : public runNode {
   public:
      /**
       * Constructor de la clase
       * \param stmt Sentencia que será ejecutada como privada.
       */
      privateNode (runNode * stmt);
      /**
       * Ejecuta la sentencia asociada estableciendo el acceso como privado.
       */
      void run();
      static bool is;
   private:
      runNode * stmt_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class namespaceNode
 * \brief Node de espacio de nombre
 * 
 * Este nodo se corresponde con el operador de espacio de nombre. Se
 * utiliza para acceder a atributos y métodos de la clase o la clase 
 * padre.
 */
class namespaceNode : public nexpNode {
   public:
      /**
       * Constructor de la clase
       * \param space Identificador usará para acceder 
       * al contexto. Puede ser un nodo identificador, un nodo estático o 
       * un nodo padre.
       * \param key Clave utilizada para obtener el elemento.
       */
      namespaceNode (runNode *space, runNode * key);
      /**
       * Según el nodo dado como espacio sea ccede al contexto de una
       * clase, y se toma como valor el atributo o método determinado por la 
       * clave.
       */
      void run () ;
   private:
      runNode * space_, *key_;
};
#endif
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
