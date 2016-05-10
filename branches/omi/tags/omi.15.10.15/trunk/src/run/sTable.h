//sTable.h
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
 * \file sTable.h
 * \brief Tablas de símbolos.
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
 * hace uso una serie de nodos que funcionan como interfaz.
 *
 */
//----------------------------------------------------------------------
#ifndef _STABLE_
#define _STABLE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "runTree.h"
#include "symbols.h"
#include "expNode.h"
using namespace std;
class classNode;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class sTable
 * \brief Tabla de símbolos
 *
 * La tabla de símbolos es una estructura de datos que sirve para guardar
 * referencias a nodos creados dinámicamente.
 *
 * Gracias a la tabla de símbolos es posible que durante el recorrido de una
 * determinada rama del árbol de ejecución se cree un nodo en memoria dinámica
 * que será utilizado en ramas posteriores. Para ello en la tabla de símbolos se crea un par
 * clave, nodo ejecutable. De esta forma, con solo conocer la clave, es posible acceder al
 * nodo creado, en cualquier momento posterior de la ejecución.
 *
 * La tabla de símbolos se define mediante tres estructuras de datos:
 *
 * - Tabla de variables
 * - Tabla de funciones
 * - Tabla de clases
 *
 * La primera puede contener referencias a cualquier tipo de nodo, aunque la gramática
 * hace que sólo exitan referencias a nodos de tipos de datos (arrays, strings...) o a nodos
 * etiquetas. La tabla de funciones guarda referencia a nodos de este tipo. Análogamente,
 * la tabla de clases guarda referencias a las nodos de tipo clase.
 *
 * La tabla de variables se estructura en varios niveles. Asi las claves de un nivel generalmente no
 * son accesibles desde ejecuciones que se realicen en otro. Esto establece un ámbito para las claves de
 * la tabla de símbolo. Por contrapartida si es posible hacer una referencia desde una clave
 * de un nivel a un elemento de otro, esto se denomina claves o identificadores de referencia.
 *
 * En la tabla de varibles tan sólo el primer nivel, denominado el nivel global, es accesible desde los
 * demás nivel. Para ello cada vez que se crea un nivel nuevo el contenido del primer nivel es copiado.
 *
 * La tabla de funciones solo consta de un nivel.
 *
 * Para acceder a la tabla de símbolos se utilizan una serie de clases de
 * nodos que funcionan como interfaz.
 *
 * Se debe destacar que puede haber más de una tabla de símbolos en memoria al mismo
 * tiempo. Elementos como las clases disponen de su propia tabla de símbolos internas.
 * Se define pues el concepto de tabla de símbolos en uso o activa, que no es más que
 * una referencia a la tabla de símbolos sobre la que se debe operar. Además
 * las tablas de simbolos se pueden relacionar entre si. Supongase el caso de que tenemos
 * tres tablas de simbolos con con referencias al mismo elemento
 * si se cambia el elemento la referencia debería cambiar en las tres.
 *
 * Una tabla de símbolos puede tener ligada un nodo ejecutable. Este nodo, denominado nodo en uso o activo, es aquel que trabaja sobre
 * los elementos de la tabla. Así un nodo clase, por ejemplo, tendrá ligado una tabla de símbolos interna, que a su
 * vez estará relacionada con el mismo nodo. Se crea así una referencia en doble sentido que permite,
 * conociendo una tabla de símbolos, obtener el elemento que opera sobra ella.
 *
 * Se define la tabla de símbolos principal como la primera tabla de símbolos
 * que se crea en la ejecución. Es posible acceder a los elementos del nivel global de esta tabla
 * desde cualquier parte del árbol de ejecución. Cuando se crea una nueva tabla de símbolos
 * el primer nivel de la tabla principal se copia a la nueva tabla. Además la copia se vuelve a
 * realizar cada vez que una tabla de símbolos es activada.
 *
 * Las tablas en ejecición se referencia mediante un estructura de datos ordenada por
 * tiempo de creación. Esta estructura se denomina lista de tablas en ejecución. Además
 * la tabla en uso es referenciada en todo momento por una variable, de forma que se pueda acceder y modificar
 * fácilmente.
 *
 * Esta clase proporciona métodos estáticos para manipular el sistema de tablas
 * en ejecución.
 *
 *
 * \note Cada vez que se implemente un nuevo tipo de dato se debe añadir al constructor
 * copia.
 */



class sTable {
 public:
   /**
    * Constructor que inicializa una nueva tabla de símbolos y la
    * mete en la lista de tablas en ejecución.
    */
   sTable ();
   /**
    * Constructor copia. Crea una tabla de símbolos a partir de otra. Para ello se
    * copian por valor los elementos de las distintas estructuras
    * que las forman, con la salvedad de que si un elemento de los copiados se encuentra en
    * el nivel de variables globales de la tabla de símbolos inicial la copia se hace por referencia.
    */
   sTable (sTable* s);
   /**
    * Crea un nivel en la estructura de variables de la tabla de símbolos
    */
   void mklevel (symbols *default_level = NULL );
   /**
    * Obtiene el nivel actual
    */
   symbols *currentlevel ();
   /**
    * Elimina todos los elementos a los que se hace referencia desde el nivel actual
    * de la tabla de variables, solo si el elemento
    * a eliminar no tiene referencias desde otros niveles. Por último
    * cambia el nivel actual al nivel anterior.
    */
   void rmlevel ();
   /**
    * Elimina todos los elementos a los que se hace referencia desde el nivel actual
    * de la tabla de variables, solo si el elemento
    * a eliminar no tiene referencias desde otros niveles. A diferencia
    * de rmlevel no cambia el nivel actual al nivel anterior.
    */
   //~ void clearlevel ();
   /**
    * Añade un referencia en el nivel actua de la tabla de variables
    * mediante la clave str al nodo node
    */
   void add (runNode* str, runNode* node);
   /**
    * Añade una referencia en la tabla de funciones mediante la
    * clave str al nodo node
    */
   void addfunction (runNode* str, runNode* node);
   /**
    * Añade una referencia en la tabla de clases mediante la
    * clave str al nodo node
    */
   void addclass (runNode *str, runNode* node);
   /**
    * Obtiene el nodo al que hace referencia la clave str del nivel actual
    * de la tabla de variables
    */
   refNode *access (runNode *str, runNode* &key_point);
   /**
    * Obtienen el nodo al que hace referencia la clave str de la
    * tabla de funciones
    */
   refNode *accessfunction (runNode *str);
   /**
    * Obtienen el nodo al que hace referencia la clave str de la
    * tabla de clases
    */
   refNode* accessclass (runNode *str);
   /**
    * Elimina el elemento del nivel actual de la tabla de variables
    * referenciado por la clave str. Luego elimina el par clave referencia.
    */
   void clear (runNode *str);
   /**
    * Devuelve un booleano que indica si existe en el nivel actual
    * de la tabla de variables una clave str.
    */
   bool exist (runNode *str);
   /**
    * Devuelve un booleano que indica si existe en la tabla de funciones
    * una clave str.
    */
   bool existfunction (runNode *str);
   /**
    * Devuelve un booleano que indica si existe en la tabla de clases
    * una clave str.
    */
   bool existclass (runNode *str);
   /**
    * Obtiene el nivel actual de la tabla de variables
    */
   int getLevel () const {
      return level_;
   }
   /**
    * Obtiene el nivel superior de la tabla de variables
    */
   int getLevelTop () const {
      return tables_.size() - 1;
   }
   /**
    * Método modificador que cambiar el nivel
    * actual de la tabla de variables
    */
   void setLevel (int l) {
      level_ = l;
   }
   /**
    * Recorre todas las tabla de simbolos creadas y hace que toda referencia que
    * apunte a node_ini sea reasignada para que apunte a node_end
    *
    * Esto es asi por que existen muchos elementos en la tabla de simbolos
    * que son referencias de otros por lo que al cambiar el elemento inicial
    * deverán cambiar todos los que le hacian referencia.
    *
    * Esta funcion busca también de forma recursiva en los elementos de tipo
    * array. Esto hace posible que se pueda actualizar las referencias de elementos
    * internos de los arrays.
    */
   void static cAll (runNode* node_ini, runNode* node_end);
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

   symbols *getTable () {
      return tables_ [level_];
   }
   symbols getFunctions () {
      return functions_;
   }
   runNode* getFunction (runNode *key);
   refNode* getFunctionRef (runNode *key);
   void setFunction (runNode *key, runNode* exp);
   
   runNode* getElement (runNode *key);
   refNode* getElementRef (runNode *key);
   
   /**
    * Asigna el elemento en uso. Este elemento será aquel que utilice
    * la tabla de símbolos.
    */
   void setNodeUse (runNode* node);
   /**
    * Devuelve el elemento en uso
    */
   runNode* getNodeUse () const;
   
   void setPrivate (runNode *str);
   bool isPrivate (runNode *str);
   
   /**
    * Método para la depuración del intérprete que imprime
    * el contenido de todas tabla de variables.
    */
   static void printAll ();
   /**
    * Método para la depuración del intérprete que imprime
    * el contenido de todas tabla de funciones.
    */
   static void fprintAll ();
   /**
    * Método para la depuración del intérprete que imprime
    * el contenido de todas tabla de clases.
    */
   static void cprintAll ();
   /**
    * Inicializa el sistema de tabla de símbolos. Para ello
    * crea una nueva tabla de símbolos que será la
    * tabla de símbolos inicial, y la introduce en la lista de
    * tablas en ejecución.
    *
    * Devuelve la tabla creada.
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
    * Devuelve una tabla de símbolos nueva. Además
    * mete en la lista de tablas de símbolos en ejecución
    * la nueva tabla. La tabla creada contiene el primer
    * nivel de la tabla variables de la tabla de símbolos inicial,
    * además de la tabla de funciones y de clases.
    */
   static sTable* new_sTable (bool level_default = true);
   /**
    * Devuelve una tabla de símbolos nueva, creada a partir
    * de la tabla de símbolos dada. Además
    * mete en la lista de tablas de símbolos en ejecución
    * la nueva tabla. La tabla creada contiene el primer
    * nivel de la tabla variables de la tabla de símbolos inicial,
    * además de la tabla de funciones y de clases.
    */
   static sTable* new_sTable (sTable* s, bool level_default = true);
   /**
    * Añade una tabla de símbolos a la lista de tablas en ejecución.
    */
   static void add_sTable (sTable* s);
   /**
    * Busca una tabla de símbolos en la lista de tablas en
    * ejecución. Devuelve la posición en la que se encuentra en la tabla
    */
   static int search_sTable (sTable* s);
   /**
    * Busca una tabla de símbolos en la lista de tablas en
    * ejecución. Devuelve la posición en la que se encuentra en la tabla
    */
   static void setGlobal (runNode* node);
   
   void setDeleteCurrentLevel (bool del) {
      delete_current_level_ = del;
   }
   
   bool setDeleteCurrentLevel () const {
      return delete_current_level_;
   }
   /**
   private:
   	/**
   	 * Determina si existe una referencia a un nodo
   	 * desde un nivel distinto a level_see
   	 */
   bool isref (runNode* node, int level_see);
   /**
    * Determina si existe una referencia a un nodo
    * desde cualquier tabla de símbolos
    */
   bool isrefAll (runNode* node, int level_see);
   /**
    * Lista de Tabla de variables
    */
   vector<symbols *> tables_;
   /**
    * Nivel máximo de la tabla de variables
    */
   int level_;
   /**
    * Tabla de funciones
    */
   symbols functions_;
   vector<runNode*> private_;
   /**
    * Tabla de clases
    */
   static symbols class_;
   /**
    * Lista de tablas en ejecución
    */
   static vector<sTable*> sTables_;
   /**
    * Tabla de elementos globales
    */
   static map<runNode*, refNode*, cmp_runNode> globals_;
   /**
    * Referencia al nodo que trabaja sobre la tabla de símbolos. Representa
    * el nodo en uso
    *
    * Si es NULL significa que la tabla de simbolos no se encuentra ligada
    * a ningún elemento concreto y se trata con carácter global.
    */
   runNode *node_use_;
   
   bool delete_current_level_;
};


//----------------------------------------------------------------------
/**
 * \class idNode
 * \brief Nodo identificador
 *
 * Los nodo identificadores se pueden ver como una interfaz a la tabla de simbolos, ya que permiten
 * la manipulación de esta de una forma transparente.
 *
 * Un nodo identificador se inicializa mediante un cadena de texto. El nodo
 * manipulará la tabla de símbolos activa en la clave que coincida con la cadena de texto.
 *
 * Es importante entender que el nodo identificador opera sobre la tabla de símbolos en uso.
 * Así dos ejecuciones de un mismo nodo podría manipular distintas tablas, si la tabla de
 * símbolo activa varía entre ambas ejecuciones
 *
 * Los nodos identificadores son expresiones de tipo no definidos y como toda expresión de
 * tipo no definido intenamente pueden mantener dos tipos de referencia:
 *
 * - Referencia a un nodo ejecutable (referencia simple), que será al nodo al que se hace
 * referencia en el par (clave, referencia) de la tabla de simbolos.
 *
 * - Referencia a una referencia a un nodo ejecutable (referencia doble), que será a la referencia del par
 * (clave, referencia) de la tabla de simbolos.
 *
 * Tras la ejecución de un elemento id se obtiene estas dos referencia en la tabla de símbolos activa.
 *
 * La doble referencia se debe que si el nodo referenciado cambia desde
 * la referencia simple del nodo identificador, la referencia de la tabla de símbolos deberia cambiar
 * también apuntado al nuevo nodo.
 *
 * idNode sirve como interfaz tanto para la tabla de variables como para
 * la de funciones y clases.  Para manipular una tabla u otra  se deberá hacer uso de métodos
 * especificos. Nunca se deberá dar el caso de que un mismo nodo id
 * referencie a un elemento de cada tabla.
 *
 */
class idNode :
   public nexpNode {
 public:
   /**
    * Constructor del nodo recibe una cadena de texto (id)
    */
   idNode (string id):id_(id), exist_(false), key_point_(NULL) { }
   /**
    * Tras su ejecucion el nodo identificador hará referencia al elemento
    * apuntado por la clave (indicada en la inicializacion) del nivel acutal de la
    * tabla de variables (indicada en la inicialización). Además guardará una referecia
    * a la refereciencia de la tabla de variables
    */
   void run () { run (true);} 
   virtual void run (bool resolvkey);
   /**
    * Tras su ejecucion el nodo identificador hará referencia al elemento
    * apuntado por la clave (indicada en la inicializacion) de la tabla
    * de funciones (indicada en la inicialización). Además guardará una referecia
    * a la refereciencia de la tabla de funciones
    */
   virtual void runf ();
   /**
    * Tras su ejecucion el nodo identificador hará referencia al elemento
    * apuntado por la clave (indicada en la inicializacion) de la tabla
    * de clases (indicada en la inicialización). Además guardará una referecia
    * a la refereciencia de la tabla de clases
    */
   virtual void runc ();
   /**
    * Obtiene la referencia del par (clave, referencia) de la tabla de variables
    * en el nivel actual
    */
   inline refNode* ref () {
      return ref_;
   }
   /**
    * Obtiene la referencia del par (clave, referencia) de la tabla de funciones
    */
   inline refNode* reff () {
      return reff_;
   }
   /**
    * Obtiene la referencia del par (clave, referencia) de la tabla de clases
    */
   inline refNode* refc () {
      return refc_;
   }
   /**
    * Obtiene el elemento referenciado por el par (clave, referencia) de la tabla de variables
    * en el nivel actual
    */
   inline runNode* nodeval () const {
      return ref_->getRef();
   }
   /**
    * Obtiene el elemento referenciado por el par (clave, referencia) de la tabla de
    * funciones
    */
   inline runNode* nodevalf () const {
      return reff_->getRef();
   }
   /**
    * Obtiene el elemento referenciado por el par (clave, referencia) de la tabla de
    * clases
    */
   inline runNode* nodevalc () const {
      return refc_->getRef();
   }
   /**
    * Limpia el valor de la referencia, borrándola de
    * la tabla de variables
    */
   void clear ();
   /**
    * Cambia a node al nodo que se hace referencia desde el
    * par (clave, referencia) del nivel actual la tabla de variables.
    */
   void noderef (runNode* node);
   /**
    * Cambia a node al nodo que se hace referencia desde el
    * par (clave, referencia) de la tabla de funciones
    */
   void nodereff (runNode* node);
   /**
    * Cambia a node al nodo que se hace referencia desde el
    * par (clave, referencia) de la tabla de clases
    */
   void noderefc (runNode* node);
   /**
    * Determina si ya existia un par (clave, referencia) correspondiente al nodo
    * en el nivel actual de la tabla de variables.
    */
   virtual bool exist (bool func = true);
   virtual bool existfunction ();
   /**
    * Determina si ya existia un par (clave, referencia) correspondiente al nodo
    * en la tabla de funciones.
    */
   inline bool existf () const {
      return existf_;
   }
   /**
    * Determina si ya existia un par (clave, referencia) correspondiente al nodo
    * en la tabla de clases.
    */
   inline bool existc () const {
      return existc_;
   }
   /**
    * Resuelve el contenido de id en la tabla de simbolos y lo asigna
    * a si mismo si existe.
    *
    * Si no existe en posible pasar un valor por defecto que será
    * asignado. Este valor será liberado si no es asignado
    */
   static runNode* resolved (runNode* &id, runNode* default_val=NULL, bool check_privat = false, sTable* check_table = NULL);
   /**
    * Resuelve el contenido de id en la tabla de simbolos y lo asigna
    * a si mismo si existe.
    *
    * Si no existe asigna el valor nombre del id.
    */
   static runNode* resolvedAsStr (runNode* &id, bool isfunc = true, bool check_private = false, sTable* check_table = NULL, bool force_str = false);
   /**
    * Obtiene el nombre de la variable
    */
   inline string name () const {
      return id_;
   }
   inline void setName (string name) {
      id_ = name;
   }
   runNode* getKey () {
      return key_point_;
   }
   void setRef (refNode* ref) {
      ref_ = ref;
   }
   refNode* getRef () const {
      
      return ref_;
   }
   refNode* getReff () const {
      
      return reff_;
   }
   refNode* getRefc () const {
      
      return refc_;
   }
 protected:
   string id_;
   bool exist_;
   refNode* reff_;
   bool existf_;
   refNode* refc_;
   bool existc_;
   runNode * key_point_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
class idgetNode: public idNode {
   public:
      idgetNode (runNode *exp):exp_(exp), id_(NULL), idNode (""){ }
      void run () { run (true);} 
      void run (bool resolvkey);
      void runf ();
      void runc ();
      void clear ();
      bool exist (bool func = true);
      bool existfunction ();
      bool existf () const;
      bool existc () const;
      string name () const;
      idNode *getId () { return id_; }
   private: 
      void setId ();
      runNode *exp_;
      idNode *id_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
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
 * La llamada a un nodo función se puede realizar de forma interna o externa respecto la tabla de símbolo activa.
 * Si la llamada a fúnción se realiza de forma interna los parámetros con los que se realiza a llama estarán en la tabla
 * de símbolos activa, mientras que si se realiza de forma externa estarán en otra tabla de símbolos distinta. Un caso práctico
 * en el que se aprecie esta distinción podría ser en la llamada de un método de una clase desde fuera de la misma. Los parámetros que se
 * pasan en la llamada se encuentran en la tabla de símbolos externa y deben ser copiados o referenciados desde la tabla de símbolos interna.
 * Por el contrario si se llama a un metódo de la clase desde la propia clase los parámetros están en la tabla de símbolos interna
 * por lo que la copia se realizará entre distintos niveles de la misma tabla.
 *
 */
class fexpNode : public expNode {
 public:
   bool is_print () const {
      return false;
   }
   bool is_runlist () const {
      return false;
   }
   void rmRef () {}
};
class functionNode :
   public fexpNode {
 public:
   /**
    * Constructor de la clase.
    * \param id Identificador que se utilizará para manipular al la función en la tabla de simbolos.
    * \param params Lista de parámetros de declaración que podrá contener nodos identificadores o
    * nodos refparamNode (los identificadores utilizados en la lista serán los nombres de los parámetros de la función).
    * \param body Lista de sentencias que forman el cuerpo de la función
    */
   functionNode (runNode* id, runNode* params, runNode* body, bool priv = false);
   /**
    * Guarda en la tabla de símbolos activa una referencia al nodo función haciendo uso
    * del identificador pasado en la inicialización
    */
    void run ();
   
   string print () const { return ""; }
   
   /**
    * Procesa una llamada a la función.
    * Recibe una lista de valores de parámetros que será copiados en un nuevo nivel de la
    * tabla de variables activa. Se crea pues  una referencia desde las claves especificadas en la lista
    * de parámetros de declaración (params). Luego ejecuta el la lista de sentencias que representa el cuerpo de
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
    * Configura la próxima llamada a la función como externa, de forma que
    * los parámetros se obtendrán de la tabla de símbolos dada
    */
   void isExtern (sTable* s);
   /**
    * Método derivado de la clase nodo expresión de tipo no defenido
    * pero que carece de sentido en las funciones ya que
    * la referencia no cambia durante toda la ejecución.
    */
   void noderef (runNode* node) {}
   /**
    * Método derivado de la clase nodo expresión de tipo no defenido.
    */
   refNode *ref () {
      refNode * r = new refNode ("");
      r->setRef (myselft_);
      return r;
   }
   /**
    * Obtienen una referencia al nodo función
    */
   runNode* nodeval () const {
      return myselft_;
   }
   /**
    * Obtiene el ID de la función
    */
   runNode* getID () {
      return id_;
   }
   /**
    * Modifica el ID de la función
    */
   runNode* setID (runNode* id) {
      id_ = id;
   }
   /**
    * Obtiene el ID de la función
    */
   string name () {
      if (idNode * id = dynamic_cast<idNode*>(id_))
         return id->name();
      else if (idNode * id = dynamic_cast<idNode*>(id_save_))
         return id->name();
      return "";
   }
   runNode * getParams () {
      return params_;
   }
   runNode * getBody () {
      return body_;
   }
   void setObj (runNode * obj ) {
      object_ = obj;
   }
   void setStaticLink (runNode * static_link ) {
      static_link_ = static_link;
   }
   void setParent (classNode * parent ) {
      parent_ = parent;
   }
   static classNode * class_link;
   sTable * getExternTable () {
      return extern_s_;
   } 
 protected:
   runNode *id_, *params_, *body_;
 private:
   functionNode* myselft_;
   sTable *extern_s_;
   symbols *level_create;
   bool extern_;
   runNode *object_, *static_link_, *id_save_;
   classNode *parent_;
   bool exec_;
};

//----------------------------------------------------------------------
/**
 * \class functioncallNode
 * \brief Node de llamada a función
 *
 * Este nodo representa una llamada a función, para ello parte de un identificador y
 * una lista de valores de parámetros.
 *
 * Su ejecución conciste en, haciendo uso del identificador, obtener la función
 * de la tabla de símbolos y llamar al método call de la misma pasándole la lista de
 * valores de parámetros, lo que significa que se llevará a cabo la ejecución de
 * la función.
 *
 * Una llamada a función es un nodo de tipo expresión no definida, que referencia el
 * valor creado a partir de una excepción return sucedida en la ejecuciión de la función
 * a la que llama
 */
class functioncallNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase
    * \param id Identificador de la funcion
    * \param params lista de valores para los parámetros.
    */
   functioncallNode (runNode* id, runNode* params) : id_(id), params_(params), exec_(false) {}
   /**
    * Ejecución del nodo. Haciendo uso del identificador obtiene la función
    * de la tabla de simbolos y llamar al método call de la misma pasándole la lista de
    * valores de parámetros, lo que significa que se llevará a cabo la ejecución de
    * la función.
    * Como valor se obtiene un nodo ejecutable creado a partir de una exepción return durante
    * la ejecución. En caso de no suceder dicha excepción se tomo como valor la cade vacia
    */
   void run (bool excep, runNode* obj = NULL, classNode* parent = NULL, sTable * context = NULL);
   void run () { run (true); }
 private:
   runNode *id_, *params_;
   bool exec_;
};
//----------------------------------------------------------------------
class callStackElement {
   public:
      callStackElement (runNode* obj, runNode* func): obj_ (obj), func_ (func) {}
      inline runNode * obj () { return obj_;}
      inline runNode * func () { return func_;}
   private:
      runNode *obj_, *func_;
};
//----------------------------------------------------------------------
class callStack {
   public:
      static void call_push (runNode * obj, runNode* func) {
         call_stack.push_back (callStackElement (obj, func));
         call_top ++;
      }
      static void call_pop () {
         call_stack.pop_back ();
         call_top --;
      }
      static callStackElement call_get () {
         return call_stack[call_top];
      }
      static bool empty () {
         return !(call_top >= 0);
      }
   private:
      static vector<callStackElement> call_stack;
      static int call_top;
};
//----------------------------------------------------------------------

class functiongetNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase
    * \param id Identificador de la funcion
    */
   functiongetNode (runNode* id) : id_(id) {}
   void run ();
 private:
   runNode *id_;
};
//----------------------------------------------------------------------
/**
 * \class globalNode
 * \brief Nodo que hace que un determinado identificador y su referencia sean
 * accesible desde cualquier nivel de ejecución de la tabla de símbolos
 */
class globalNode :
   public runNode {
 public:
   /**
    * Constructor de la clase
    * \param id Identificador que se hará global
    */
   globalNode (runNode* id) : id_(id) {}
   /**
    * Ejecución del nodo. Se comprueba que el nodo sea un identificador,
   * se ejecuta y se se guarda una referencia de su valor en la tabla de
   * elementos globales
    */
   void run ();
 private:
   runNode *id_;
};
//----------------------------------------------------------------------
/**
 * \class returnException
 * \brief Exepcion return
 *
 * Se lanza producto de la ejecución de un nodo return. Esto hace que se
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
   returnException (runNode* resp): resp_(resp) {}
   /**
    * Método que se ejecuta cuando la excepción no es atrapada
    */
   const char* what() const throw() {
      return "return fuera de función";
   }
   /**
    * Obtiene el valor de la excepción
    */
   runNode* val () const {
      return resp_;
   }
 private:
   runNode* resp_;
};
//----------------------------------------------------------------------
/**
 * \class returnNode
 * \brief Nodo return o de devolución
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
   returnNode (runNode* value): value_(value) {}
   /**
    * Lanza una exepcion de tipo return con el valor
    * especificado en la inicialización
    */
   void run ();
 private:
   runNode* value_;
};
//----------------------------------------------------------------------
/**
 * \class refparamNode
 * \brief Nodo de parámetro por referencia
 *
 * Internamente estos nodos guardan una referencia a un identificador
 *
 * Esta clase de nodos es utilizada en lista de parámetros en la
 * declaración de una función. En la llamada a la función
 * si se detecta que un nodo de este tipo se pasarán los parámetros
 * por referencia y no por valor.
 */
class refparamNode :
   public runNode {
 public:
   /**
    * Constructor
    * \param value Identificador que se utilizará para el paso por
    * referencia
    */
   refparamNode (runNode* value): value_(value) {}
   /**
    * Este nodo solo sirve para que otros nodos cambien su comporamiento
    * por lo que su ejecución es vacía
    */
   void run () {}
   /**
    * Método observador que obtiene el identificador asociado
    */
   inline runNode* getValue () {
      return value_;
   }
 private:
   runNode* value_;
};
//----------------------------------------------------------------------
/**
 * \class classNode
 * \brief Nodo clase
 *
 * Esta clase define e implementa el nodo clase. Un nodo clase representa la
 * definición de una clase. Una clase es una estructura funcional utilizada
 * en la programación orientada a objetos.
 *
 * Un nodo clase sirve como interfaz para definir y manipular las clases
 * en ejecución.
 *
 * Todo nodo clase tiene una tabla de símbolos interna donde se referencia
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
 * una nueva tabla de símbolos, que será la tabla interna. Para finalizar
 * cambia al tabla activa a la iterna y se lleva a cabo la ejecución del cuerpo.
 *
 * Los nodos funciones declarados en el cuerpo de la clase serán referenciados
 * desde la tabla interna de la clase y son considerados los métodos de la msima.
 * De igual forma las variables son consideradas como los atributos.
 *
 * Nótose que a diferencia de las funciones (functionNode) la declaracón de una
 * clase conlleva a la ejecución del cuerpo, ya que las funciones y variables
 * se deben declarar en la tabla de símbolos interna.
 *
 * En liesh una determinada clase puede extender a otra, lo significa que heredará sus
 * métodos y atributos.
 *
 * Los nodos clase presentan un mecanismo para crear nuevas instancias de las
 * mismos denomidas objetos. Este mecanismo es utilizado por nodos como el
 * nodo "nueva instancia" (\see newNode). Cuando se crear una nueva instancia se
 * genera una copia de la declarión de la clase. Esta copia se puede asignar a una
 * un nodo id como si fuera un tipo de dato, guardándose asi una referencia en
 * la tabla de variables activa.
 *
 * Para acceder a los atributos y funciones de una instancia de un nodo
 * clase que se encuetre en la tabla de variables activa. Se utilizan los
 * nodos de llamada a método (\see methodcallNode) y llamada a atributo
 * (\see attributecallNode).
 *
 * \note Aún queda implementar los nodos staticNode, publicNode, privateNode y sobre carga de métodos
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
    */
   classNode (runNode* id, runNode* body, runNode *extends = NULL);
   /**
    * Lleva a cabo la ejecución del nodo clase corresponidiente
    * a la declaración de la misma. Para ello crea una referencia
    * en la tabla de clases activa a si misma, genera la tabla se símbolos
    * interna, y luego, tras cambiar la tabla en uso, ejecuta el cuerpo.
    */
   void run ();
   /**
    * Crea y devuelve una instancia de la clase. Para ello
    * copia el nodo clase y busca una función en la tabla interna de la copia
    * correspondiente al nombre de la clase. Esta función, considerada constructor,
    * será ejecutada con los parámetros indicados.
    */
   runNode* newcall (runNode *params);
   /**
    * Devuelve la tabla de símbolos interna del nodo clase
    */
   inline sTable* insideTable () const {
      return inside_;
   }
   inline classNode * getExtendClass () {
      return extend_class_;
   }
   inline runNode* getID(){
      return id_;
   }
   inline string name(){
      if (idNode* id = dynamic_cast<idNode*>(id_))
         return id->name();
      return "";
   }
   runNode * getMethod (runNode * key);
   refNode * getMethodRef (runNode * key);
   void setMethod (runNode * key, runNode * func);
   runNode * getFromStatic (runNode *key);
   void setFromStatic (runNode *key, runNode* val);
   runNode * toArray ();
   static sTable* static_class;
   runNode * newelement_;
 private:
   runNode *id_, *body_, *extends_;
   sTable *inside_, *static_;
   bool exec_;
   classNode *extend_class_;
};

//----------------------------------------------------------------------
class privateNode : public runNode {
   public:
      privateNode (runNode * stmt) : stmt_ (stmt) {}
      void run();
      static bool is;
   private:
      runNode * stmt_;
};
//----------------------------------------------------------------------
/**
 * \class newNode
 * \brief Nodo nueva instacia
 *
 * Este nodo es el encargado de crear una instancia de una clase denominada
 * objeto.
 *
 * Un nodo newNode es un nodo de tipo no definido por lo que guarda una
 * referencia a otro nodo. Tras la ejecución un nodo newNode se tomará
 * como referencia la instancia de una clase determinada por un identificador.
 *
 * Además un nodo newNode opera con un conjunto de parámetros que serán
 * los que se utilicen para crear una istancia de la clase en el método
 * constructor.
 */
class newNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase que se inicializa a partir de un nodo
    * identificador y una lista de parámetros
    */
   newNode (runNode* id, runNode* params);
   /**
    * Lleva a cabo la ejecución del nodo. Para ello busca en la
    * tabla de clases activa el nodo correspondiente al identificador
    * utilizado en la inicialización. Luego ejecuta el método
    * para crear una nueva instancia del nodo clase obtenido. Por
    * último toma como valor la instancia creada.
    */
   void run ();
 private:
   runNode *id_, *params_;
   runNode * nodeR_;
};
//----------------------------------------------------------------------
/**
 * \class thisNode
 * \brief Nodo referencia al objeto
 *
 * Este nodo es del tipo expresión no definida. Toma el valor del objeto
 * que opera sobre la tabla de símbolos actual, que se corresponderá con
 * el nodo en uso de la tabla.
 *
 * A pesar de ser un nodo de expresión no definida. El nodo de referencia
 * al objeto devuelve un error cuando se intenta modificar la referencia
 * a la que apunta. De forma que al interpretar expresiones del tipo
 * "this = var" liesh devolverá un error. Así se define thisNode como un nodo
 * de expresión no definida de sólo lectura.
 *
 */
class thisNode :
   public nexpNode {
 public:
   /**
    * Busca en la tabla de símbolos actual el nodo en uso y toma
    * dicho valor.
    *
    * Si la tabla activa no tiene un nodo en uso se produce una exepción
    * de error.
    */
   void run ();
   static runNode* thisval;
   virtual void noderef (runNode* node);
 private:
   
   runNode *nodeR_;
};
//----------------------------------------------------------------------
class parentNode : public thisNode {
   public:
      parentNode () {}
      runNode * get (runNode * key); 
      static classNode *link;
};
//----------------------------------------------------------------------
class staticNode : public runNode {
   public:
      staticNode () : stmt_ (NULL) {}
      staticNode (runNode *stmt) : stmt_ (stmt) {}
      void run () ;
      static runNode* link;
   private:
      runNode * stmt_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
class namespaceNode : public nexpNode {
   public:
      namespaceNode (runNode *space, runNode * key) : space_ (space), key_(key) {}
      void run () ;
   private:
      runNode * space_, *key_;
};
//----------------------------------------------------------------------
class functionLambdaNode: public functionNode {
 public:
   functionLambdaNode (runNode* params, runNode* ret) : functionNode ( NULL, params, new returnNode (ret) ) { }
};
//----------------------------------------------------------------------
class decoratorNode : public functionNode {
 public:
   decoratorNode (runNode* id, runNode* params, runNode* body);
};
//----------------------------------------------------------------------
class contextFunction : public nexpNode {
 public:
   contextFunction () {}
   void run ();
};
//----------------------------------------------------------------------
class partialFunctionNode : public nexpNode {
   public:
      partialFunctionNode (runNode * params, runNode *id, bool isrun = false);
      void run();
      static runNode* diffParams (runNode *pparams, runNode *fparams);
      static bool existAllParams (runNode *pparams, runNode *fparams);
   private:
      runNode * params_, *id_;
      bool isrun_;
};
//----------------------------------------------------------------------
#endif


