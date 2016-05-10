//mysqlDBNode.h
//~ g++ -c -fPIC mysql-ext.cpp -o mysql-ext.o && g++ -shared mysql-ext.o -o mysql-ext.so `mysql_config --cflags --libs`
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
 * \file mysqlDdNode.h
 * \brief Nodos de bases de datos con implementación para mysql
 * 
 * Este fichero implementas las clases necesarias para operar con 
 * bases de datos en sistema MYSQL. 
 * 
 * Entre las clases implementadas se encuentran la definición del tipo
 * base de datos y la consulta abierta. Estas conforman la base para el 
 * sistema de base de datos.
 * 
 * Liesh es un sistema abierto y versátil en cuanto a base de datos se 
 * refiere. En el momento de compilación del programa, el usuario
 * deberá elegir el sistema de base de datos. Así es posible compilar 
 * Liesh con soporte para multitud de bases de datos. No obstante el programa
 * sólo se puede compilar con sorporte para un único sistema de bases de datos.  
 */
//----------------------------------------------------------------------
#ifndef _DBNODE_
#define _DBNODE_
//----------------------------------------------------------------------
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <mysql/mysql.h>

#include "../src/plugin.h"
#include "../src/run/sTable.h"
#include "../src/run/runTree.h"
#include "../src/run/typeNode.h"

/**
 * \class dbNode
 * \brief Nodo tipo base de datos
 * 
 * Este nodo representa una comunicación con la base de datos. 
 * 
 * Para establecer una comunicación con un sistema de bases de datos se 
 * necesitan  la dirección del equipo que aloja el sistema de base de datos, 
 * un usuario y una contraseña. Opcionalmente también se puede indicar
 * la base de datos sobre la que se realizará la conexión y el puerto en 
 * el que el se encuentra el sistema de base de datos. 
 * 
 * Se presentan dos formas de trabajar con base de datos. La primera de ellas
 * es mediante consultas directas. Para ello se escribe una consulta que será 
 * enviada y ejecutada por el sistema de base de datos. La segunda es mediante 
 * consultas con datos estructurados. En este caso la consulta o parte de ella 
 * es codificada en un elemento del tipo array asociativo. Así es posible crear 
 * consultas mediante arrays.  
 * 
 * Para codificar la consulta en una estructura de arrays asociativos liesh interpreta dos tipos
 * de claves. Las claves que hacen referencia a un campo de la base de datos y las claves que 
 * que establecen relaciones entre tablas. Además cada nivel del array se corresponderá con una tabla 
 * de la base de datos. 
 * 
 * El siguiente array asociativo representa una consulta para insertar los datos personales de un usuario y sus datos de acceso
 * 
 * array = { 'nombre' : 'Fco. Javier', 'apellidos' : 'Bohórquez Ogalla', 'accesos:acceso' : { 'login' : 'franj', 'pass' : 'xxxxxx' } };
 * 
 * Las claves de campos simples especifican un campo concreto de la tabla del nivel actual en el array. Su valor, el 
 * cual será de un tipo de dato simple, indica el valor de dicho campo en la consulta.
 * 
 * Las claves de campos relacionales tienen la siguiente forma {campo}{directiva}{tabla}. Se establece pues una relación entre 
 * la tabla actual y la tabla dada, mediante el campo especificado. La relación puede ser simple (uno a uno) si el valor de la clave
 * es un array asociativo, o múltiple (uno a varios) si el valor de la clave es un array con índices numéricos de arrays asociativos. 
 * Las directivas añaden cierto significado a la relación que le indica al interprete cómo realizar la consulta. El significado de estas dependen de la
 * sentencia que ejecute el array. 
 * 
 * Para realizar la consulta a partir de una estructura de arrays asociativos se utilizan una serie de sentencias
 * correspondientes a las diferentes acciones sobre la base de datos. Así para insertar los datos de usuario
 * vistos en el ejemplo anterior se tendrá que usar la sentencia insert especificando el array, la tabla inicial y la base datos.
 * 
 * Cabe destacar que la tabla inicial puede codificarse también en el array. En el ejemplo anterior:
 * 
 * array = { 'persona@personas' : { 'nombre' : 'Fco. Javier', 'apellidos' : 'Bohórquez Ogalla', 'accesos:acceso' : { 'login' : 'franj', 'pass' : 'xxxxxx' } }}
 * 
 * Otro concepto que se debe tener en cuenta al trabajar con bases de datos en liesh es que este guarda una variable global con la
 * última base de datos a la que se conectó en la ejecución. Todas las sentencias que trabajan con bases de datos reciben 
 * como parámetros la conexión sobre la cual operar. Este parámetro se puede omitir  tomándose así la base de datos global. 
 * De esta forma el programador se puede abstraer, si lo desea, del tipo de dato conexión a base de datos. 
 *   
 */
class dbNode : 
  public runNode {
    public:
	  static runNode* create (listNode* list);
      /**
       * Constructor principal.
       * \param host Dirección del equipo que aloja el sistema de base de datos
       * \param user Usuario con el que realizar la conexión
       * \param password Contraseña del usuario
       * \param database Base de datos a la que se desea conectar 
       * \param port Puerto en el que se encuentra el sistema de base de datos
       */
      dbNode (
        string host, 
        string user, 
        string password, 
        string database = "",
        unsigned int port = 0
      );
      /**
       * Constructor copia
       * 
       * \param db Base de datos a copiar
       */
      dbNode (dbNode* db);
      /**
       * Destructor. Cierra las conexiones con el sistema de base de datos
       */
      ~dbNode ();
      /**
       * Lleva a cabo la ejecución del nodo. Para ello realiza la 
       * conexión a la base de datos.
       */
      void run ();
      /**
       * Realiza la conexión a la base de datos especificada del 
       * sistema de base de datos.
       * 
       * \param db Base de datos
       */
      void connectBD (string db);
      /**
       * Obtiene la conexión a la base de datos a un bajo nivel 
       * de abstracción
       */
      inline MYSQL* getSQL () const { return sql_; }
      /**
       * Obtiene la dirección en la que se aloja el sistema de base de datos
       */
      inline string getHost () const { return host_; }
      /**
       * Obtiene el usuario con el que se realizó la conexión
       */
      inline string getUser () const { return user_; }
      /**
       * Obtiene la clave con la que se realizó la conexión
       */
      inline string getPassword () const { return password_; }
      /**
       * Obtiene la base de datos sobre la cual se realizó la conexión
       */
      inline string getDataBase () const { return database_; }
      /**
       * Obtiene el puerto del sistema de base de datos
       */
      inline unsigned int getPort () const { return port_; }
      /**
       * Obtiene el carácter que establece relaciones entre tablas
       */
      inline string getFieldTable () const { return field_table_; }
      /**
       * Cambia el carácter que establece relaciones entre tablas
       */
      inline void setFieldTable (string field_table) { field_table_ = field_table; }
      /**
        * Dado un nodo que representa una clave relacional
        * obtiene el campo
        */
      string fieldFieldTable (runNode *node);
      /**
        * Dado un nodo que representa una clave relacional
        * obtiene la tabla
        */
      runNode* tableFieldTable (runNode *node);
      /**
        * Dado un nodo que representa una clave relacional
        * determina si contiene una directiva de selección
        */
      bool isSelectTable (runNode *node);
      /**
       * Determina si una clave es una clave relacional
       */
      bool isFieldTable (runNode *node);
      /**
       * Obtiene la conexión de bases de datos global
       */
      static dbNode* getGlobal ();
      /**
       * Modifica la conexión de base de datos global
       */
      static void setGlobal (runNode* global); 
     
      runNode* cloneNode (runNode* node) {
		  if (dbNode * d = dynamic_cast<dbNode*>(node))
			return new dbNode (d);
		  return NULL;
	  } 
    private:
      string host_, user_, password_, database_;
      unsigned int port_;
      MYSQL* sql_;
      string field_table_;
      static dbNode* global_;
};  

//----------------------------------------------------------------------
/**
 * \class dbConnectNode
 * \brief Nodo conexión a base de datos
 * 
 * Este nodo abre una conexión a la base de datos. Tras la ejecución del nodo
 * toma coma valor interno un nodo del tipo dbNode que representa la conexión 
 * con la base de datos. 
 * 
 * Para iniciar la conexión con la base de datos se necesita la dirección del equipo
 * que guarda el sistema de base de datos y un usuario y contraseña para el acceso. Opcionalmente
 * se puede indicar la base de datos a la que realizar la conexión y el puerto del sistema de base de datos. 
 * 
 * Adicionalmente se puede realizar la conexión a una base de datos concreta partiendo 
 * de una conexión existente para ello se precisa del elemento dbNode que representa la conexión y 
 * el nombre de la base de datos a la cual se desea connectar. 
 * 
 */
class dbConnectNode : 
  public nexpNode {
    public:
	  static runNode* create (listNode* list);
      /**
       * Constructor a partir de los datos de conexión
       * \param host Dirección del equipo que aloja el sistema de base de datos
       * \param user Usuario con el que realizar la conexión
       * \param password Clave con la que realizar la conexión
       * \param port Puerto en el que se encuentra el sistema de base de datos
       */
      dbConnectNode (
        runNode* host, 
        runNode* user, 
        runNode* password, 
        runNode* database,
        runNode* port
      );
      /**
       * Constructor a partir de un conexión existente y una base de datos
       * \param conn Conexión a sistema de base de datos
       * \param add Base de datos a la que se desea conectar.
       */
      dbConnectNode (runNode* conn, runNode* add);
      /**
       * Lleva a cabo la ejecución del nodo. Esta dependerá del tipo de constructor 
       * utilizado. Si se especificarón datos de conexión se crea una conexión mediante un nodo
       * dbNode y se toma como valor interno del nodo. Si se desea ampliar una conexión existente
       * este método creará una nueva conexión con los datos de la conexión existente y la base de datos
       * con la que se desea conectar. 
       */ 
      void run ();
      /**
       * Obtiene la conexión a la base de datos realizada
       */
      inline runNode* getDB () const { return nodeval(); }
      /**
       * Obtiene la dirección del equipo que aloja el sistema de base de datos
       */
      inline runNode* getHost () const { return host_; }
      /**
       * Obtiene el usuario con el que se realizó la conexión
       */ 
      inline runNode* getUser () const { return user_; }
      /**
       * Obtiene la clave con la que se realizó la conexión
       */
      inline runNode* getPassword () const { return password_; }
      /**
       * Obtiene la base de datos a la que se realizó al conexión
       */
      inline runNode* getDataBase () const { return database_; }
      /**
       * Obtiene el puerto en el que se encuentra el sistema de base de datos
       */
      inline runNode* getPort () const { return port_; }
      //~ /**
       //~ * Devuelve el valor interno del nodo
       //~ */
      //~ runNode* nodeval () const;
      //~ /**
       //~ * Obtiene una referencia al valor interno del nodo
       //~ */
      //~ runNode** ref ();
      //~ /**
       //~ * Cambia el valor interno del nodo
       //~ */
      //~ void noderef (runNode* node);
    private:
      void run_ini ();
      void run_add ();
    
      runNode* host_, *user_, *password_, *database_, *port_;
      runNode* add_, *conn_;
};  
//----------------------------------------------------------------------
/**
 * \class dbQueryNode
 * \brief Nodo consulta a base de datos
 * 
 * Este nodo se encarga de realizar una consulta a la base de datos. 
 * Para ello, utilizando la sintáxis del sistema de base de datos, se 
 * escribe una consulta en una cadena de texto. Esta será enviada e interpretada
 * por el sistema de base de datos.
 * 
 * Este nodo representa la forma más directa de realizar consultas a la 
 * base de datos. 
 * 
 * Tras la ejecuión del nodo toma como valor un booleano que indicasi la consulta
 * se realizó correctamente. 
 * 
 * Para manipular las consultas realizadas mediante la ejecución de este nodo se presisa de una serie de 
 * nodos que permiten procesar los resultados obtenidos.
 * 
 */
class dbQueryNode : 
  public nexpNode {
    public:
	  static runNode* create (listNode* list);
      /**
       * Contructor principal
       * \param db Conexión a base de datos
       * \param query Cadena de texto con la consulta a realizar
       */
      dbQueryNode (
        runNode* db, 
        runNode* query
      );
      /**
       * LLeva a cabo la ejecución del nodo, basada en el envío de 
       * la consulta al sistema de base de datos. 
       */
      void run ();
      /**
       * Obtiene la conexión a la base de datos
       */
      inline runNode* getDB () const { return db_; }
      /**
       * Obtiene el nodo que representa la consulta al sistema de base de datos.
       */
      inline runNode* getQuery () const {return query_; }
    private:
      runNode *db_, *query_;
      
      
};  
//----------------------------------------------------------------------
/**
 * \class dbInsertNode
 * \brief Nodo consulta insert estructurada
 * 
 * Este nodo ejecuta una consulta insert estructurada. Las consultas
 * estructuradas parten de una estructura de datos construida con arrays 
 * asociaciativos que codifica toda o parte de la consulta. 
 * 
 * Como todo nodo de base de datos este nodo se inicializa a partir
 * de una conexión abierta que puede ser omitida, tomándose así la 
 * conexión global
 * 
 * Además este nodo trabaja sobre una tabla inicial o conjunto de estas. La 
 * tabla inicial también pueden omitirse, siempre que se codifique en la estructura 
 * de arrays asociativos. 
 * 
 * Un concepto que se debe tener en cuenta en las consultas estructuras 
 * es el concepto de tabla inicial. Toda consulta estructurada parte de 
 * una tabla inicial que será a partir de la cual se establezcan las 
 * relaciones con otras tablas. 
 * 
 * Para comprender mejor el concepto de tabla inicial se expondrá el siguirnte ejemplo. 
 * Se desea insertar los datos personales y de acceso de un usuario en una base de datos que, entre otras,
 * cuenta con las tablas usuarios y accesos, relacionándose la primera con la segunda madiante un campo entero.
 * Para construir el array asociativo en primer lugar se deberá elegir una tabla inicial. Lo más
 * natural en este caso es tomar como tabla inicial la tabla personas.  
 * 
 * array = { 'nombre' : 'Fco Javier', ..., 'acceso:accesos' : {'login' : 'franj', 'passs' : 'xxxx'} }
 * 
 * En una consulta estructurada insert la estructura de arrays guarda 
 * los valores a insertar. La estructura de arrays puede codificar, además 
 * de los valores de los campos, relaciones entre tablas. Así, por ejemplo, con una sola
 * consulta insert es posible añadir a la base de datos los datos personales de un usuario,
 * las distintas direcciones en las que reside, los datos de acceso, los departamentos a 
 * los que pertenece...
 * 
 * Una consulta estructurada insert puede conllevar a varias consultas en el lenguaje del
 * sistema de base de datos. 
 * 
 * Cabe destacar que las consultas estructuradas son menos óptimas en comparación con su
 * equivalente en consultas simples. Esto es así porque el interprete debe procesar los datos en
 * el array asociativo. 
 * 
 * Un array asociativo para la inserción de datos puede contar con varios niveles. Cada nivel 
 * se corresponde con una tabla de la base de datos. El primer nivel de la estructura de arrays definirá los datos de la consulta referente a 
 * la tabla inicial. Algunos de estos datos pueden ser campos relaciones que definirán la relación entre la tabla inicial y otra tabla, construyéndose 
 * así un array con los datos relativos a la tabla relacionada, lo que formará otro nivel de la estructura. De esta forma es posible hacer la 
 * insercción en varias tablas relacionadas construyendo una sola estructura  
 * 
 * El primer nivel del array asociativo puede definir los datos de la tabla inicial y las relaciones de esta para así insertar un conjunto 
 * de datos relacionados. No obstante si el primer nivel del array tiene índices numéricos cada posición del array será un conjunto de datos 
 * que se insertarán desde la tabla inicial.
 * 
 * Es posible utilizar el primer nivel del array para indicar la 
 * tabla inicial, o incluso un conjunto de tablas iniciales. Para ello bastaría con no indicar
 * tabla inicial y codificarla en la estructura mediante claves relacionales. 
 * 
 * Las claves relacionales en el array asociativo, son aquellas que relacionan la tabla del 
 * nivel actual con otra tabla. En liesh toda clave relacional tiene la siguiente estructura
 * {campo}{directiva}{tabla}. Indicando así la tabla y el campo con el que se relaciona la tabla
 * actual. Puede suceder que el campo se encuentre en la tabla actual, por lo el valor de 
 * la clave será un array asociativo con los valores y relaciones de la tabla con la que se relaciona.
 * También puede suceder que el campo se encuentre en otra tabla, por ejemplo en una relación de uno 
 * a varios, en ese caso el valor de la clave relacional tendrá como valor un array numérico donde cada posición será otro 
 * array asociativo con cada uno de los datos que se relacionan con la tabla actual.
 * 
 * La directiva de una clave relacional indica al intérprete cómo insertar los datos relacionados. Las posibles
 * directivas son:
 * 
 * - ':' Los datos de las tablas relacionadas se insertan normalmente. El campo en la tabla actual tendrá como valor la
 *      clave primaria de los datos insertados en la tabla relacionada
 * 
 * - '@' Los datos de las tablas relacionadas son buscados en la base de datos, si existe se toma la clave primaria, si no existe se 
 * insertan y se toma la clave primaria de la fila insertada. 
 * 
 * Tras la ejecución del nodo este toma como valor interno una estructura de arrays con las claves 
 * primarias de cada uno de los elementos insertados.   
 */
class dbInsertNode :
  public nexpNode {
    public :
	  static runNode* create (listNode* list);
      /**
       * Constructor prinipal. Inicializa la consulta insert a 
       * partir de una conexión a la base de datos, una tabla inicial y
       * una estructura de arrays que representa los datos a guardas y las relaciones entre tablas. 
       *
       * \param db Conexión a BD. Puede ser NULL
       * \param table_ini Tabla inicial. Puede ser NULL
       * \param values Array asociativo que representa los datos a insertar y las relaciones entre tablas.
       */
      dbInsertNode (runNode* db, runNode* table_ini, runNode* values );
      /**
       * Lleva a cabo la ejecución del nodo. Para ello inserta los datos en la
       * estructura de arrays asociativos 
       * 
       * Procesa las relaciones entre tablas expresadas en el array.
       */
      void run ();
      /**
       * Obtiene la conexión a la base de datos. Si esta no se especificó
       * devuelve NULL.
       */
      inline runNode* getDB () const { return db_; }
      /**
       * Obtiene la tabla inicial de la consulta estructurada. 
       * Si no se especificó se devuelve NULL.
       */
      inline runNode* getTable () const { return table_ini_; }
      /**
       * Obtiene la estructura de arrays asociativos
       * que representa la consulta.
       */
      inline runNode* getValues () const { return values_; }
      /**
       * Esta función estática realiza una consulta select estructurada
       * en la que se devuelve la clave primaria de la fila en la tabla inicial
       * que cumpla con la condición de igualdad de los datos definidos en la estructura.
       */
      static runNode* select (runNode* db, runNode* table, runNode* values);
      /**
       * Variable de control que controla que se esta llevando a cabo una relación múltiple.
       */
      static bool multi;
      
      
    private:
      runNode *db_, *table_ini_, *values_;
};
//----------------------------------------------------------------------
class dbSelectNode :
  public nexpNode {
    public :
	  static runNode* create (listNode* list);
      dbSelectNode (runNode* db, runNode* tables, runNode* fields, runNode* values );
      
      void run ();
      
      inline runNode* getDB () const { return db_; }
      
      inline runNode* getTable () const { return tables_; }
      
      inline runNode* getFields () const { return fields_; }
      
      inline runNode* getValues () const { return values_; }

      
      
    private:
      runNode *db_, *tables_, *values_, *fields_;
};
//----------------------------------------------------------------------
class dbUpdateNode :
  public nexpNode {
    public :
      static runNode* create (listNode* list);
      dbUpdateNode (runNode* db, runNode* tables, runNode* fields, runNode* values );
      
      void run ();
      
      inline runNode* getDB () const { return db_; }
      
      inline runNode* getTable () const { return tables_; }
      
      inline runNode* getFields () const { return fields_; }
      
      inline runNode* getValues () const { return values_; }

      
      
    private:
      runNode *db_, *tables_, *values_, *fields_;
};
//----------------------------------------------------------------------
class dbDeleteNode :
  public nexpNode {
    public :
      static runNode* create (listNode* list);
      dbDeleteNode (runNode* db, runNode* tables, runNode* values );
      
      void run ();
      
      inline runNode* getDB () const { return db_; }
      
      inline runNode* getTable () const { return tables_; }
            
      inline runNode* getValues () const { return values_; }

      
      
    private:
      runNode *db_, *tables_, *values_;
};
//----------------------------------------------------------------------
#endif
