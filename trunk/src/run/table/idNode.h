//idNode.h
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
 * \file idNode.h
 * \brief Nodos relacionados con identificadores
 *
 * En este fichero se encuentran los nodos relacionados con los 
 * identificadores. Estos son modelados mediante clase de objetos.
 *
 */

#ifndef _RUN_TABLE_IDNODE_
#define _RUN_TABLE_IDNODE_

#include "sTable.h"
#include "../tree/expNode.h"
 
//-------------------------------------------------------------------------------------------

/**
 * \class idNode
 * \brief Nodo identificador.
 *
 * Guarda una referencia a una clave de la tabla de símbolos. 
 * 
 * Su ejecución consiste en el acceso a  la tabla de símbolos del contexto
 * actual para obtener la clave, y por tanto el valor, que se corresponde 
 * al nombre del identificador.
 * 
 * Presenta un método run para el acceso a cada tabla de símbolos.
 * 
 * idNode es un nodo de tipo expresión no definida, por lo que 
 * toma como valor una referencia a un nodo.
 */
class idNode :
   public nexpNode {
 public:
   /**
    * Constructor del nodo.
    * \param id Nombre del identificador.
    */
   idNode (string id);
   /**
    * Accede a la tabla de símbolos de variables en el nivel actual 
    * y toma como valor la referencia correspondiente al nombre.
    * 
    * Si no existe una referencia en la tabla de símbolos correspondiente
    * al nombre del identificador esta es creada y apuntada a un nodo 
    * de tipo nulo.
    * 
    * Si la referencia tomada como valor es otra referencia, toma  esta 
    * última como valor, procediendo de la misma forma hasta que la 
    * referencia tomada como valor no apunte ha otra referencia. 
    * Este proceso se denomina resolver la referencia o clave.
    */
   void run ();
   /**
    * Accede a la tabla de símbolos de variables en el nivel actual 
    * y toma como valor la referencia correspondiente al nombre.
    * \param resolvkey Si es verdadero resuelve la referencia. 
    */
   virtual void run (bool resolvkey);
   /**
    * Accede a la tabla de símbolos de funciones
    * y toma como valor la referencia correspondiente al nombre.
    */
   virtual void runf ();
  /**
    * Accede a la tabla de símbolos de clases
    * y toma como valor la referencia correspondiente al nombre.
    */
   virtual void runc ();
   /**
    * Obtiene el valor referencia tomado por el nodo en la tabla de variables.
    * \return Referencia de la tabla de variables tomada como valor.
    */
   inline refNode* ref () {
      return ref_;
   }
   /**
    * Obtiene el valor referencia tomado por el nodo en la tabla de funciones.
    * \return Referencia de la tabla de funciones tomada como valor.
    */
   inline refNode* reff () { return reff_; }
   /**
    * Obtiene el valor referencia tomado por el nodo en la tabla de clases.
    * \return Referencia de la tabla de funciones tomada como valor.
    */
   inline refNode* refc () { return refc_; }
   /**
    * Obtiene el nodo al que apunta la referencia que el nodo tiene como
    * valor. 
    * \return Valor del id en el nivel actual de la tabla de variables.
    */
   inline runNode* nodeval () const { return ref_?ref_->getRef():NULL; }
   /**
    * Obtiene el elemento referenciado por el par (clave, referencia) de la tabla de
    * funciones
    * \return Valor del id en la tabla de funciones.
    */
   inline runNode* nodevalf () const { return reff_?reff_->getRef():NULL; }
   /**
    * Obtiene el elemento referenciado por el par (clave, referencia) de la tabla de
    * clases
    * \return Valor del id en la tabla de clases.
    */
   inline runNode* nodevalc () const {
      return refc_?refc_->getRef():NULL;
   }
   /**
    * Limpia el valor de la referencia, borrándola de la tabla de variables.
    */
   void clear ();
   /**
    * Cambia el valor que tiene la referencia con la clave correspondiente 
    * al identificador en el nivel actual la tabla de variables.
    * \param node Nodo valor de la referencia.
    */
   void noderef (runNode* node);
   /**
    * Cambia el valor que tiene la referencia con la clave correspondiente 
    * al identificador en  la tabla de funciones.
    * \param node Nodo valor de la referencia.
    */
   void nodereff (runNode* node);
   /**
    * Cambia el valor que tiene la referencia con la clave correspondiente 
    * al identificador en la tabla de clases.
    * \param node Nodo valor de la referencia.     
    */
   void noderefc (runNode* node);
   /**
    * Tras la ejecución del nodo devuelve si existía la referencia en el nivel
    * actual de la tabla de símbolos de variables.
    * \param func Comprueba además si existe como función.
    * \return Booleano que indica si la variable existía .
    */
   virtual bool exist (bool func = true);
   /**
    * Tras la ejecución del nodo devuelve si existía la referencia en la 
    * tabla de símbolos de funciones.
    * \return Booleano que indica si la función existía . 
    */
   inline bool existf () const {
      return existf_;
   }
   /**
    * Tras la ejecución del nodo devuelve si existía la referencia en la 
    * tabla de símbolos de funciones.
    * \return Booleano que indica si la clase existía .
    */
   inline bool existc () const {
      return existc_;
   }
   /**
    * Comprueba si existe la referencia correspondiente al nodo en la
    * tabla de funciones. No necesita ejecutar el nodo.
    * \return Booleano que indica si la función existe.
    */
   virtual bool existfunction ();
    /**
    * Resuelve la referencia correspondiente al nombre del nodo id en la 
    * tablas de símbolos del contexto indicado y la asigna como valor de id. .
    *
    * \param id Nodo ejecutable que será tratado como el nodo identificador. 
    * Si no es identificador no se lleva a cabo ninguna acción.
    * \param default_val Valor por defecto que devolverá si no existe.
    * \param check_private Comprueba si tiene acceso privado
    * \param check_table Entorno de tablas de símbolos que se usará.
    */
   static runNode* resolved (runNode* &id, runNode* default_val=NULL, bool check_privat = false, sTable* check_table = NULL);
   /**
    * Resuelve la referencia correspondiente al nombre del nodo id en la 
    * tablas de símbolos del contexto indicado y la asigna como valor de id. 
    * Si esta no existe asignará como valor un nodo cadena correspondiente 
    * al nombre del identificador.
    * \param id Nodo ejecutable que será tratado como el nodo identificador. 
    * Si no es identificador no se lleva a cabo ninguna acción.
    * \param isfunc Comprueba en la tabla de símbolos de funciones.
    * \param check_private Comprueba si tiene acceso privado.
    * \param check_table Entorno de tablas de símbolos que se usará.
    * \param force_str Convierte el nodo en un nodo cadena si no 
    * encuentra la referencia. 
    */
   static runNode* resolvedAsStr (runNode* &id, bool isfunc = true, bool check_private = false, sTable* check_table = NULL, bool force_str = false);
   /**
    * Obtiene el nombre del id
    * \return Nombre
    */
   inline string name () const { return id_; }
   /**
    * Establece el nombre del identificador.
    * \param name Nombre
    */
   inline void setName (string name) { id_ = name; }
   /**
    * Obtiene la referencia en la tabla de símbolos de variables.
    * \return Referencia en la tabla de símbolos de variables.
    */
   refNode* getRef () const;
   /**
    * Obtiene la referencia en la tabla de símbolos de funciones.
    * \return Referencia en la tabla de símbolos de funciones.
    */
   refNode* getReff () const;
   /**
    * Obtiene la referencia en la tabla de símbolos de clases.
    * \return Referencia en la tabla de símbolos de clases.
    */
   refNode* getRefc () const;
 protected:
   string id_;
   bool exist_;
   refNode* reff_;
   bool existf_;
   refNode* refc_;
   bool existc_;
   runNode * key_point_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class idgetNode
 * \brief Nodo  identificador obtenido.
 * 
 * Este nodo es un nodo identificador tal que su nombre es 
 * obtenido mediante la evaluación de un nodo ejecutable.
 * 
 * Su ejecución implica obtener el nombre del identificador, para luego 
 * acceder a una la tabla de símbolos del contexto actual para obtener la 
 * clave, y por tanto el valor, que se corresponde al nombre obtenido.
*/
class idgetNode: public idNode {
   public:
      /**
       * Constructor del nodo. 
       * \param exp Nodo ejecutable correspondiente, cuya ejecución
       * determina el nombre del identificador.
       */
      idgetNode (runNode *exp);
      /**
       * Ejecuta el nodo asociado como expresión para obtener el 
       * nombre del identificador.
       * 
       * Accede a la tabla de símbolos de variables en el nivel actual 
       * y toma como valor la referencia correspondiente al nombre.
       * 
       * Si no existe una referencia en la tabla de símbolos correspondiente
       * al nombre del identificador esta es creada y apuntada a un nodo 
       * de tipo nulo.
       * 
       * Si la referencia tomada como valor es otra referencia, toma  esta 
       * última como valor, procediendo de la misma forma hasta que la 
       * referencia tomada como valor no apunte ha otra referencia. 
       * Este proceso se denomina resolver la referencia o clave.
       */
      void run ();
      /**
       * Ejecuta el nodo asociado como expresión para obtener el 
       * nombre del identificador.
       * 
       * Accede a la tabla de símbolos de variables en el nivel actual 
       * y toma como valor la referencia correspondiente al nombre.
       * \param resolvkey Si es verdadero resuelve la referencia. 
       * 
       */
      void run (bool resolvkey);
      /**
       * Ejecuta el nodo asociado como expresión para obtener el 
       * nombre del identificador.
       * 
       * Accede a la tabla de símbolos de funciones
       * y toma como valor la referencia correspondiente al nombre.
       */
      virtual void runf ();
     /**
       * Ejecuta el nodo asociado como expresión para obtener el 
       * nombre del identificador.
       * 
      * Accede a la tabla de símbolos de clases
      * y toma como valor la referencia correspondiente al nombre.
      */
      void runc ();
      /**
       * Limpia el valor de la referencia, borrándola de
       * la tabla de variables.
       */
      void clear ();
      /**
       * Tras la ejecución del nodo devuelve si existía la referencia en el nivel
       * actual de la tabla de símbolos de variables.
       * \param func Comprueba además si existe como función.
       * \return Booleano que indica si la variable existe.
      */
      bool exist (bool func = true);
      /**
       * Tras la ejecución del nodo devuelve si existía la referencia en la 
       * tabla de símbolos de funciones.
       * \return Booleano que indica si la función existe.
       */
      bool existf () const;
      /**
       * Tras la ejecución del nodo devuelve si existía la referencia en la 
       * tabla de símbolos de clases.
       * \return Booleano que indica si la clase existe.
       */
      bool existc () const;
      /**
       * Obtiene el nombre calculado en la ejecución del nodo.
       * \return Nombre
       */
      string name () const;
      /**
       * Comprueba si existe la referencia correspondiente al nodo en la
       * tabla de funciones. No necesita ejecutar el nodo.
       * \return Booleano que indica si la función existe.
       */
      bool existfunction ();
      /**
       * Obtiene el Identificador relativo al nombre calculado en la ejecución
       * del nodo.
       * \return Nodo identificador.
       */
      idNode* getId ();
   private: 
      void setId ();
      runNode *exp_;
      idNode *id_;
};
 
//-------------------------------------------------------------------------------------------

/**      
 * \class globalNode
 * \brief Nodo identificador global.
 * 
 * Este nodo establece un identificador como global, lo que permite que 
 * la referencia que tiene como valor sea accesible desde cualquier 
 * contexto y sea cual sea el nivel de la tabla de símbolos.
 */
class globalNode :
   public runNode {
 public:
   /**
    * Constructor de la clase.
    * \param id Identificador que se hará global.
    */
   globalNode (runNode* id);
   /**
    * Ejecución del nodo. Se comprueba que el nodo sea un identificador,
    * se ejecuta y se guarda una referencia de su valor en la tabla de
    * elementos globales.
    */
   void run ();
 private:
   runNode *id_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
