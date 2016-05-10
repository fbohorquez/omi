//sTable.h
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
 * \file sTable.h
 * \brief Contexto de tablas de símbolos.
 * 
 * En este fichero se define un contexto de tabla de símbolos.
 *
 * Las tablas de símbolos son estructuras de datos que contiene referencias
 * al valor de variables, funciones, clases, objetos y, en definitiva,
 * a cualquier elemento del lenguaje definido por el usuario.
 *
 * Una tabla de símbolos es un diccionario de referencias a los elementos
 * creados en memoria dinámica, por lo que es importante limpiar los datos
 * a los que hace referencia una determinada clave cunado esta toma un nuevo
 * valor.
 *
 * Para que sea posible la modificación de una tabla de símbolos se
 * hace uso de una serie de nodos que funcionan como interfaz.
 * 
 * Se crea un contexto de tablas de símbolos donde cada una tiene un propósito
 * o referencian a nodos de diferente tipo.
 *
 */

#ifndef _RUN_TABLE_STABLE_
#define _RUN_TABLE_STABLE_

#include <string>
#include <vector>
#include "symbols.h"

using namespace std;
class classNode;

//-------------------------------------------------------------------------------------------

/**
 * \class sTable
 * \brief Contexto de tablas de símbolos.
 *
 * La tabla de símbolos es una estructura de datos que sirve para guardar
 * referencias a nodos creados dinámicamente.
 *
 * Gracias a la tabla de símbolos es posible que durante el recorrido de una
 * determinada rama del árbol de ejecución se cree un nodo en memoria 
 * dinámica que será utilizado en ramas posteriores. Para ello en la tabla 
 * de símbolos se crea un nodo referencia que apunta al valor creado. 
 * De esta forma, con solo conocer la clave de la referencia, es posible acceder 
 * al nodo creado en cualquier momento posterior de la ejecución.
 *
 * El contexto se define mediante tres tablas de símbolos:
 *
 * - Tabla de variables
 * - Tabla de funciones
 * - Tabla de clases
 *
 * Adicionalmente puede tener una tabla de símbolos de acceso global.
 * 
 * La primera puede contener referencias a cualquier tipo de nodo, aunque 
 * la gramática hace que sólo existan referencias a nodos de tipos de datos 
 * (arrays, strings...) o a nodos etiquetas. La tabla de funciones guarda 
 * referencia a nodos de este tipo. Análogamente, la tabla de clases guarda 
 * referencias a las nodos de tipo clase.
 *
 * La tabla de variables se estructura en varios niveles. Así las claves de 
 * un nivel generalmente no son accesibles desde ejecuciones que se realicen 
 * en otro. Esto establece un ámbito para las claves de la tabla de símbolo.
 *
 * La tabla de funciones y de clases solo consta de un nivel.
 *
 * Para acceder a la tabla de símbolos se utilizan una serie de clases de
 * nodos que funcionan como interfaz.
 *
 * Se debe destacar que puede haber más de una tabla de un contexto. 
 * Elementos como las clases disponen de su propio contexto.
 * Se define pues el concepto de contexto activo, que no es más que
 * una referencia al contexto sobre la que se debe operar. 
 * 
 * Los contextos puede tener ligados un nodo ejecutable. Este nodo, 
 * denominado nodo en uso o activo,  es aquel que trabaja sobre los 
 * elementos de las tablas. Así un nodo clase, por ejemplo, el contexto 
 * de una clase estará relacionado con la propia clase. 
 * Se crea así una referencia en doble sentido que permite, conociendo 
 * un contexto, obtener el elemento que opera sobra ella.
 *
 * Se define el contexto principal como el primer  contexto que se crea 
 * en la ejecución.  Este es añadido a una lista de contextos. Cuando otro
 * contexto fuera a ser usado es puesto al final de la lista hasta que finaliza su uso.
 *
 * Esta clase proporciona métodos estáticos para manipular el sistema 
 * de tablas en ejecución.
 *
 * \see symbols
 */

class sTable {
 public:
   /**
    * Constructor que inicializa un nuevo contexto de tablas de símbolos.
    */
   sTable ();
   /**
    * Constructor copia. Crea un contexto a partir de otro. Para ello se
    * copian por valor los elementos de las distintas estructuras
    * que los forman.
    * \param s Contexto a copiar
    */
   sTable (sTable* s);
   /**
    * Crea un nivel en la tabla de variables
    */
   void mklevel (symbols *default_level = NULL );
   /**
    * Obtiene el nivel actual de la tabla de variables
    * \return Tabla de variables correspondiente al nivel actual.
    */
   symbols *currentlevel ();
   /**
    * Elimina las referencias del nivel actual. Por último
    * cambia el nivel actual al nivel anterior.
    */
   void rmlevel ();
   /**
    * Añade un referencia con la clave dada en el nivel actual de la 
    * tabla de variables. La referencia apuntará al nodo dado. 
    * Si ya existía una referencia con dicha clave 
    * se elimina el valor anterior.
    * \param str Clave para la referencia.
    * \param node Nodo al que apuntará la referencia.
    */
   void add (runNode* str, runNode* node);
   /**
    * Añade un referencia con la clave dada a la tabla de funciones. 
    * La referencia apuntará al nodo dado.
    * Si ya existía una referencia con dicha clave se elimina el valor anterior.
    * \param str Clave para la referencia.
    * \param node Nodo al que apuntará la referencia.
    */
   void addfunction (runNode* str, runNode* node);
   /**
    * Añade un referencia con la clave dada a la tabla de clases. 
    * La referencia apuntará al nodo dado.
    * Si ya existía una referencia con dicha clave se elimina el valor anterior.
    * \param str Clave para la referencia.
    * \param node Nodo al que apuntará la referencia.
    */
   void addclass (runNode *str, runNode* node);
   /**
    * Obtiene la referencia del nivel actual de la tabla de variables
    * correspondiente a la clave dada. Si la clave no se encuentra se
    * crea y devuelve una referencia que apunta a un nodo nulo.
    * \param str Clave relativa a la referencia.
    * \return Referencia  dada por la clave.
    */
   refNode *access (runNode *str);
   /**
    * Obtiene la referencia de la tabla de funciones correspondiente a la 
    * clave dada. Si la clave no se encuentra se crea y devuelve una 
    * referencia que apunta a un nodo nulo.
    * \param str Clave relativa a la referencia.
    * \return Referencia  dada por la clave.
    */
   refNode *accessfunction (runNode *str);
   /**
    * Obtiene la referencia de la tabla de clases correspondiente a la clave
    *  dada. Si la clave no se encuentra se crea y devuelve una referencia
    *  que apunta a un nodo nulo.
    * \param str Clave relativa a la referencia.
    * \return Referencia  dada por la clave.
    */
   refNode* accessclass (runNode *str);
   /**
    * Elimina el elemento del nivel actual de la tabla de variables
    * referenciado por la clave dada. Luego elimina la referencia.
    */
   void clear (runNode *str);
   /**
    * Devuelve un booleano que indica si existe en el nivel actual
    * de la tabla de variables una clave str.
    * \return Booleano que determina si existe una variable dada.
    */
   bool exist (runNode *str);
   /**
    * Devuelve un booleano que indica si existe en la tabla de funciones
    * una clave str.
    * \return Booleano que determina si existe una función dada.
    */
   bool existfunction (runNode *str);
   /**
    * Devuelve un booleano que indica si existe en la tabla de clases
    * una clave str.
    * \return Booleano que determina si existe una clase dada.
    */
   bool existclass (runNode *str);
   /**
    * Obtiene el nivel actual de la tabla de variables.
    * \return Entero que indica el nivel actual de la tabla de símbolos de 
    * variables.
    */
   int getLevel () const;
   /**
    * Obtiene el nivel superior de la tabla de variables.
    * \return Entero que representa el nivel superior de la tabla de variables.
    */
   int getLevelTop () const; 
   /**
    * Método modificador que cambia el nivel actual de la tabla de variables.
    * \param l Nivel
    */
   void setLevel (int l);
   /**
    * Método para la depuración del intérprete que imprime
    * el contenido de la tabla de variables.
    */
   void print ();
   /**
    * Método para la depuración del intérprete que imprime
    * el contenido de la tabla de funciones.
    */
   void fprint ();
   /**
    * Método para la depuración del intérprete que imprime
    * el contenido de la tabla de clases.
    */
   void cprint ();
   /**
    * Obtiene la tabla de símbolos variables.
    * \return Tabla de variables.
    */
   symbols *getTable ();
   /**
    * Obtiene la tabla de símbolos funciones.
    * \return Tabla de funciones.
    */
   symbols getFunctions ();
   /**
    * Obtiene el valor la referencia dada por la clave facilitada en la 
    * tabla de funciones.
    * \param key Clave.
    * \return Nodo función o NULL si no existe la referencia.
    */
   runNode* getFunction (runNode *key);
   /**
    * Obtiene la referencia dada por la clave facilitada en la 
    * tabla de funciones.
    * \param key Clave .
    * \return Nodo referencia o NULL si no existe la referencia.
    */
   refNode* getFunctionRef (runNode *key);
   /**
    * Se añade una referencia a la tabla de funciones que apunta al nodo 
    * dado. 
    * \param key Clave. 
    * \param exp Valor. 
    */
   void setFunction (runNode *key, runNode* exp);
    /**
    * Obtiene el valor de la referencia dada por la clave facilitada en el nivel 
    * actual de la tabla de variables.
    * \param key Clave. 
    * \return Nodo o NULL si no existe la referencia.
    */
   runNode* getElement (runNode *key);
   /**
    * Obtiene  la referencia dada por la clave facilitada en el nivel actual 
    * de la tabla de variables.
    * \param key Clave. 
    * \return Referencia o NULL si no existe la referencia.
    */
   refNode* getElementRef (runNode *key);
   /**
    * Asigna el elemento en uso. Este elemento será aquel asociado 
    * al contexto.
    * \param node Nodo que hace uso del contexto.
    */
   void setNodeUse (runNode* node);
   /**
    * Devuelve el elemento en uso. Este elemento será aquel asociado 
    * al contexto.
    * \return Nodo que hace uso del contexto.
    */
   runNode* getNodeUse () const;
   /**
    * Le añade a un identificador la etiqueta de privado dentro del contexto.
    * \param str Nodo que hace de identificador.
    */
   void setPrivate (runNode *str);
   /**
    * Determina si un identificador presenta la etiqueta de privado dentro 
    * del contexto.
    * \param str Nodo que hace de identificador
    * \return Booleano que determina si el identificador es privado.
    */
   bool isPrivate (runNode *str);
   /**
    * Inicializa el sistema de contextos de tablas de símbolos. Para ello
    * crea un nuevo contexto que será el inicial, y lo introduce en la lista 
    * de contextos en ejecución.
    * \return Contexto creado
    */
   static sTable* sys_sTable ();
   /**
    * Guarda una referencia a la tabla de símbolos activa.
    * Si se cambia el valor de atributo
    * todos los nodos trabajarán con la nueva tabla de símbolos.
    */
   static sTable* sTable_use;
   /**
    * Guarda una referencia a la tabla de símbolos inicial.
    */
   static sTable* sTable_ini;
   /**
    * Crea una contexto nuevo y lo introduce en 
    * la lista de contextos en ejecución. 
    * \param level_default Indica si la tabla de variables
    * del contexto creado comienza con el primer nivel 
    * de la tabla del contexto actual.
    * \return Contexto creado.
    */
   static sTable* new_sTable (bool level_default = true);
   /**
    * Devuelve un contexto nuevo, creado a partir
    * de uno dado. Además mete en la lista de tablas de símbolos en 
    * ejecución la nueva tabla. La tabla creada contiene el primer
    * nivel de la tabla variables de la tabla de símbolos inicial,
    * además de la tabla de funciones y de clases.
    */
   static sTable* new_sTable (sTable* s, bool level_default = true);
   /**
    * Añade un contexto a la lista de contextos en ejecución.
    * \param s Contexto a añadir.
    */
   static void add_sTable (sTable* s);
   /**
    * Busca un contexto en la lista de contextos en ejecución. Devuelve la
    * posición en la que se encuentra.
    * \param s Contexto a buscar.
    * \return Posición en la que se encuentra o -1 en caso de no encontrarse.
    * 
    */
   static int search_sTable (sTable* s);
   /**
    * Busca una tabla de símbolos en la lista de tablas en ejecución. Devuelve
    * la posición en la que se encuentra en la tabla.
    */
   static void setGlobal (runNode* node);
   /**
    * Determina si el nivel actual de la tabla de símbolos de variables debe
    * ser eliminado al disminuir el nivel.
    * \param del Booleano que indica si se ha de eliminar el nivel actual de la
    * tabla del símbolos.
    */
   void setDeleteCurrentLevel (bool del);
   /**
    * Determina si existe una referencia a un nodo
    * desde un nivel distinto a level_see.
    */
   bool isref (runNode* node, int level_see);
   /**
    * Determina si existe una referencia a un nodo
    * desde cualquier tabla de símbolos.
    */
   bool isrefAll (runNode* node, int level_see);
   /**
    * Lista de Tabla de variables.
    */
   vector<symbols *> tables_;
   /**
    * Nivel máximo de la tabla de variables.
    */
   int level_;
   /**
    * Tabla de funciones.
    */
   symbols functions_;
   vector<runNode*> private_;
   /**
    * Tabla de clases.
    */
   static symbols class_;
   /**
    * Lista de tablas en ejecución.
    */
   static vector<sTable*> sTables_;
   /**
    * Tabla de elementos globales.
    */
   static map<runNode*, refNode*, cmp_runNode> globals_;
   /**
    * Referencia al nodo asociado al contexto. Representa el nodo en uso.
    *
    * Si es NULL significa que el contexto no se encuentra ligado
    * a ningún elemento concreto y se trata con carácter global.
    */
   runNode *node_use_;
private:   
   bool delete_current_level_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla


