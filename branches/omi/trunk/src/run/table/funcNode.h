//funcNode.h
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
 * \file funcNode.h
 * \brief Nodos relacionados con funciones
 *
 * En este fichero se encuentran los nodos relacionados con funciones. 
 * Estos son modelados mediante clase de objetos.
 *
 */
//-------------------------------------------------------------------------------------------
#ifndef _RUN_TABLE_FUNCNODE_
#define _RUN_TABLE_FUNCNODE_

#include "idNode.h"
#include "../tree/expNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class functionNode
 * \brief Nodo función
 *
 * Un nodo función representa la declaración de una función. Internamente sirve como interfaz
 * tanto para la declaración de funciones en las tablas de símbolos como para tratar las llamadas a estas.
 *
 *  Para su inicialización precisa de un nodo identificador, una lista de parámetros para la declaración y un cuerpo
 *
 * La declaración de la función hace uso del nodo identificador para acceder a la tabla de funciones
 * y crear una referencia al propio nodo función.
 *
 * El cuerpo de la función consistirá en listado de nodos sentencias, que se ejecutarán en cada llamada
 *
 * Para la llamada a una función se hace uso de la clase de nodo "llamada a función".
 * Esta clase de nodo rescata de la tabla de funciones el nodo función referenciado mediante una determinada clave
 * y ejecuta el método call de la misma pasándole los valores de los parámetros. El método call es el encargado de copiar el
 * valor de los parámetros a un nuevo nivel de la tabla de variables usando como clave los identificadores de la lista de parámetros
 * pasada en la inicialización de forma posicional. Después de copiar el valor de los parámetros ejecuta el cuerpo de la función en su totalidad
 * oa hasta que se reciba una excepción de tipo return.
 *
 * La lista de parámetros para la declaración será una lista de nodos identificadores o nodos refparamNode. Estos últimos
 * son nodos que referencian a un identificador, de forma que cuando el método call lea de la lista de parámetros para la declaración
 * un nodo de este tipo en vez de copiar el valor creará una referencia al mismo.
 *
 * Los nodos de tipo función son expresiones cuyo valor es la propia función. Esto hace posible que se pueda asignar funciones, permitiendo construir
 * expresiones como "fun = function (a) { echo a; };" o "{ 'success' : function () { echo "Ok";} }
 *
 * Internamente los métodos definidos en una clase se representan como funciones que se encuentran referenciadas en la tabla de símbolos
 * interna de la clase.
 *
 */
class functionNode :
   public fexpNode {
 public:
   /**
    * Constructor de la clase.
    * \param id Identificador que se utilizará para manipular al la función en la tabla de simbolos.
    * \param params Lista de parámetros de declaración que podrá contener nodos identificadores o
    * nodos refparamNode (los identificadores utilizados en la lista serán los nombres de los parámetros de la función).
    * \param body Lista de sentencias que forman el cuerpo de la función
    * \param priv La función tiene la etiqueta de privada
    */
   functionNode (runNode* id, runNode* params, runNode* body, bool priv = false);
   /**
    * Guarda en la tabla de símbolos activa una referencia al nodo función haciendo uso
    * del identificador pasado en la inicialización
    */
    void run ();
   /**
    * Devuelve la cadena que se debe imprimir como la declaración de la
    * función, la cual siempre será la cadena vacía.
    * 
    * \return Cadena vacía.
    */
   string print () const;
   
   /**
    * Procesa una llamada a la función.
    * Recibe una lista de valores de parámetros que será copiados en un nuevo nivel de la
    * tabla de variables activa. Luego ejecuta el la lista de sentencias que representa el cuerpo de
    * la función en su totalidad o hasta que sucede una excepción return en cuyo caso devolverá el valor de la
    * excepción.
   *
   * Si la función ha sido configurada con llamada externa los parámetros serán copiados desde el nivel actual de la tabla de
   * variables indicada, al próximo nivel de la tabla de variables activa, luego se volverá a configurar la función con
   * llamada interna.
   *
   * Si la función se encuentra configurada con llamada interna los parámetros serán copiados o referenciados desde
   * el nivel actual de la tabla de variables activa.
   *
   * Si algún parámetro de la lista dada en la inicialización de la función es de tipo referencia, la copia del
   * parámetro se realizará por referencia.
    */
   runNode* call (runNode* params, sTable * context = NULL);
   /**
    * Obtiene el ID de la función
    * \return ID de la función-
    */
   runNode* getID ();
   /**
    * Modifica el ID de la función
    * \param id Nuevo ID
    * \return ID asignado
    */
   runNode* setID (runNode* id);
   /**
    * Obtiene el nombre del ID de la función
    * \return Nombre del ID
    */
   string name ();
   /**
    * Obtiene la lista de parámtros de la función
    * \return Parámetros de la función
    */
   runNode * getParams ();
   /**
    * Obtiene el cuerpo de la función
    * \return Cuerpo de la función
    */
   runNode * getBody ();
   /**
    * Establece la función como método de un objeto dado
    * \param obj Objeto asociado al método
    */
   void setObj (runNode * obj );
   /**
    * Establece la el nodo clase asociado como enlace estático
    * durante la llamada a la función.
    * \param static_link Clase que se usará como enlace estático
    */
   void setStaticLink (runNode * static_link );
   /**
    * Establece el nodo clase asociado como padre
    * durante la llamada a la función.
    * \param parent Clase que se usará como padre.
    */
   void setParent (classNode * parent );
    static classNode * class_link;
 protected:
   runNode *id_, *params_, *body_;
 private:
   sTable *extern_s_;
   symbols *level_create;
   bool extern_;
   runNode *object_, *static_link_, *id_save_;
   classNode *parent_;
   bool exec_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class functioncallNode
 * \brief Node de llamada a función
 *
 * Este nodo representa una llamada a función. Parte de un identificador y
 * una lista de valores que hacen de parámetros.
 *
 * Su ejecución conciste en, haciendo uso del identificador, obtener la función
 * de la tabla de símbolos y ejecutar el cuerpo de esta pasándole la lista de
 * valores como parámetros.
 *
 * Una llamada a función es un nodo de tipo expresión no definida, que referencia el
 * valor devuelto por la ejecución.
 */
class functioncallNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase
    * \param id Identificador de la funcion
    * \param params lista de valores para los parámetros.
    */
   functioncallNode (runNode* id, runNode* params);
   /**
    * Ejecución del nodo. Haciendo uso del identificador obtiene la función
    * de la tabla de símbolos y llamar al método call de la misma pasándole la lista de
    * valores como parámetros, lo que significa que se llevará a cabo la ejecución de
    * la función.
    * Como valor se obtiene un nodo ejecutable creado a partir de una exepción return durante
    * la ejecución. En caso de no suceder dicha excepción se toma como valor nulo
    * 
    * \param excep Determina si se lanza una exepción en el caso de que no exista una función con
    * el identificador dado.
    * \param obj Objeto que se asociará a la función para que sea ejecutada comp método.
    * \param parent Clase que se usará como padre en la llamada a función.
    * \param context Contexto del cual se obtendrán las tablas de símbolos.
    */
   void run (bool excep, runNode* obj = NULL, classNode* parent = NULL, sTable * context = NULL);
   /**
    * Ejecución del nodo. Haciendo uso del identificador obtiene la función
    * de la tabla de símbolos y llamar al método call de la misma pasándole la lista de
    * valores como parámetros, lo que significa que se llevará a cabo la ejecución de
    * la función.
    * Como valor se obtiene un nodo ejecutable creado a partir de una exepción return durante
    * la ejecución. En caso de no suceder dicha excepción se toma como valor nulo
    */
   void run ();
 private:
   runNode *id_, *params_;
   bool exec_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class functiongetNode
 * \brief Nodo obtener función
 * 
 * Obtiene de la tabla de símbolos de funciones del contexto actual 
 * la función correspondiente con un identificador dado.
 */
class functiongetNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase
    * \param id Identificador de la funcion
    */
   functiongetNode (runNode* id);
   /**
    * Ejecuta el nodo asociado como identificador y 
    * toma como valor la función correspondiente 
    * en la tabla de símbolos del contexto actual.
    */
   void run ();
 private:
   runNode *id_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class returnException
 * \brief Exepcion return
 *
 * Se lanza en la ejecución de un nodo return. Esto hace que se
 * detenga la ejecución de una función y se guarde el valor especificado en el
 * nodo return. Este valor será el que tome el nodo de llamada a función
 */
class returnException :
   public exception {
 public:
   /**
    * Constructor.
    * \param resp Nodo ejecutable que se desea devolver
    */
   returnException (runNode* resp);
   /**
    * Método que se ejecuta cuando la excepción no es atrapada
    */
   const char* what() const throw();
   /**
    * Obtiene el valor de la excepción
    */
   runNode* val () const;
 private:
   runNode* resp_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class returnNode
 * \brief Nodo return
 *
 * Todo nodo return tienen un valor asociado que será el que se asigne a la
 * llamada a función cuya ejecución lo originó.
 *
 * Internamente lanza una excepción return con el valor indicado, haciendo que
 * se detenga la ejecución de la función y que la llamada tome valor
 */
class returnNode :
   public runNode {
 public:
   /**
    * Constructor
    * \param value Valor a ser devuelto
    */
   returnNode (runNode* value);
   /**
    * Lanza una excepción de tipo return con el valor
    * especificado en la inicialización
    */
   void run ();
 private:
   runNode* value_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class refparamNode
 * \brief Nodo de parámetro por referencia
 *
 * Internamente estos nodos guardan una referencia a un nodo 
 * que hace de identificador.
 *
 * Esta clase de nodos es utilizada en lista de parámetros de la
 * declaración de una función. En la llamada a la función, cuando los
 * los parámetros son pasados, si se detecta un nodo de este 
 * tipo en la definición se hará por referencia y no por valor.
 */
class refparamNode :
   public runNode {
 public:
   /**
    * Constructor
    * \param value Identificador que se utilizará para el paso por
    * referencia
    */
   refparamNode (runNode* value);
   /**
    * Este nodo solo sirve para que otros nodos cambien su comporamiento
    * por lo que su ejecución es vacía
    */
   void run ();
   /**
    * Método observador que obtiene el identificador asociado
    */
   inline runNode* getValue () { return value_; }
 private:
   runNode* value_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class contextFunction
 * \brief Función de contexto
 * 
 * Nodo que obtiene la función de contexto. Esta es la funcición actualmente 
 * en ejecución o la función utilizada en un decorador
 */
class contextFunction : public nexpNode {
 public:
   /**
    * Constructor de la clase
    */
   contextFunction ();
   /**
    * Toma como refernecia la función de contexto. Esta es la
    * función actual.
    */ 
   void run ();
};
//-------------------------------------------------------------------------------------------
/**
 * \class partialFunctionNode
 * \brief Nodo aplicación parcial
 * 
 * Nodo que lleva a cabo la aplicación parcial de una función. A partir de
 * la función se obtiene otra donde un subconjunto de sus parámetros 
 * tienen un valor dado.
 */
class partialFunctionNode : public nexpNode {
   public:
      /**
       * Constructor de la clase
       * \param params Lista de parámetros que tendrán un valor en la función generada. Tiene que esta formada 
       * por asignaciones.
       * \param id ID de la función a partir de la cual se obtendrá la función con los valores dados
       * \param isrun Determina si la función debe ser ejecutada tras ser obtenida
       */
      partialFunctionNode (runNode * params, runNode *id, bool isrun = false);
      /**
       * Tras la ejecución el nodo toma como valor la función correspondiente
       * a la aplicación parcial de la función correspondiente al id dado 
       * con los parámetros facilitados
       */ 
      void run();
      /**
       * Obtiene un nodo lista que contiene los parámetros de fparams que 
       * no se encuentran en pparams
       * \param pparams Listado de subconjunto
       * \param fparams Listado de conjunto
       * \return Lista de elementos de fparams que no se encuentran en pparams
       */
      static runNode* diffParams (runNode *pparams, runNode *fparams);
      /**
       * Obtiene un valor booleano que determna si todos los parámetros de
       * pparams se encuentran en fparams.
       * \param pparams Listado de subconjunto
       * \param fparams Listado de conjunto
       * \return  Booleano que indica si todos los parámetros de pparams se encuentran 
       * fparams
       */
      static bool existAllParams (runNode *pparams, runNode *fparams);
   private:
      runNode * params_, *id_;
      bool isrun_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
