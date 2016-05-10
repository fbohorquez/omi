//componentNode.h
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
 * \file componentNode.h
 * \brief Sistema de nodos componentes.
 *
 * Los nodos componentes representan estucturas de datos que se encuentran
 * organizadas, estructuradas y relacionadas. Sobre estos se pueden realizar
 * operaciones de  acceso, búsqueda, modificación y eliminación.
 *
 * El sistema de componentes emplea técnicas de mapeo objeto-relacional
 * (ORM) sobre una base de datos. Sirve de enlace entre la capa conceptual de la
 * aplicación y la capa de datos, permitiendo al programador abstraerse de
 * la representación y disposición física de los datos. Además ofrece
 * mecanismos para asegurar la persistencia de los datos.
 *
 * El sistema de componentes se basa en los conceptos de definición de tipo,
 * componente y relación entre componentes
 *
 * - Definición de tipo
 * 	 La definición de un tipo de componente especifica los atributos y métodos
 *   de los que dispondrá todo componente de dicho tipo. La definición también
 *   establece las relaciones que tendrán los componentes. Además determina
 *   los valores por defecto, el lugar físico y el fomato con el que se guardarán los datos,
 *   y la forma con la que se accederán a estos. Representa un mecanismo de definición y control.
 *   Una definición se corresponde a la vez con una clase de un modelo de orientado a objetos
 *   y con la definición de una tabla entidad-relación.
 *
 * - Componente
 *   Un componente se corresponde a una instanciación concreta de un tipo de
 *   componente. Guarda los valores de los atributos, referencias a los métodos
 *   y accesos a las relaciones. La instanciación de un componente se puede
 *   realizar mediante la construcción del mismo o mediante una selección
 *   entre los ya existentes. Es posible ver un componente como
 *   un objeto de una clase y como un registro de un modelo entidad-relacón
 *
 * - Relaciones entre componentes
 *   Las relaciones entre componentes establecen cómo estos van a iteractuar
 *   entre sí, compartiendo datos, o estableciendo una conexión semántica.
 *   Estas serán de un tipo y presentarán una cardinalidad. Toda relación
 *   tiene una representación a nivel conceptual y física.
 *
 * Como se puede observar un sistema de componentes es una extención de un
 * sistema orientado a objetos. Esta extención no solo se da debido al motor
 * de persistencia que trabaja bajo estos conceptos, sino ademnás a muchos
 * otros aspectos como la construcción y definición dinámica, la referencia
 * de métodos, propotipado de componentes...
 *
 * \section Tabla de símbolos componentes
 * El sistema de componentes dispone de una tabla de símbolos propia en la que
 * se referencia cada definción de tipo creada. Además cada definición, así como cada
 * componente en si, tienen su tabla de símbolos interna.
 *
 * \section Pilas de llamadas constructoras
 * Tanto las definiciones de tipo, como los propios componetes, se pueden
 * construir de forma dinámica y anidada, es por ello que se precisa de
 * un mecanismo que controle las distintas llamadas a bloques constructores
 *
 * \section Base de datos
 *
 * Aunque gracias al sistema de componentes se accede a los datos
 * de forma transparente y automática, el programador puede tomar consciencia
 * de la base de datos y dar propiedades a los tipos de componentes
 * para personalizar la disposición física y el formato de los datos. Además
 * puede realizar operaciones directamente sobre la base de datos.
 *
 * El sistema de base de datos utilizado por defecto es SQLite pero el
 * interprete es lo suficientemente flexible como para poder funcionar con
 * otros sistemas de base de datos relacionales.
 *
 *
 */
//----------------------------------------------------------------------
#ifndef _COMPONENTNODE_
#define _COMPONENTNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include "runTree.h"
#include "numData.h"
#include "typeNode.h"
#include "stmtNode.h"
#include "sTable.h"
#include "../error.h"

using namespace std;
class dataCNode;
//----------------------------------------------------------------------
class defCNode : public arrayNode {
 public:
   defCNode (runNode* component, runNode* def, runNode* not_exist = NULL, runNode* attach = NULL, runNode * like = NULL, runNode* extends = NULL);
   defCNode (arrayNode *a);
   defCNode ();
   void defCNodeCopy (defCNode * def, bool only_data = false) ;
   void run () {
      this->run(false);
   }
   void run (bool bypass, bool save = true);
   runNode* setElement (runNode* key, runNode* value);
   runNode* getElement (runNode* key);
   void setRel (string key, defCNode *def);
   void setRelTable (string table);
   defCNode *getRel (string key);
   vector<string> getRelTable ();
   void save ();
   void saveRel ();
   string getNameTable (bool with_attach = false);
   void setId (runNode *key);
   string getId ();
   string getRelName (string key, defCNode *def);
   map<string, defCNode*> getRels () const;
   runNode * copyArray (arrayNode * a) {
      return new defCNode (a);
   }
   runNode * getDefaultVal (runNode* key);
   void setDefaultVal (runNode* key, runNode* val);
   int calculateExtendsLevels (int level);
   void calculateTypesLevels (string type);
   inline int getTypeLevel () {
      return type_level_;
   }
   inline int getExtendLevel () {
      return extend_level_;
   }
   void setTypesExtends (arrayNode* a);
   string typeSelect (string str);
   void addFieldsLevel  (runNode* key, runNode* val);
   inline string getName () {
      return name_;
   }
   symbols getDefalutArray () {
      return default_val_;
   }
   inline bool isExist () {
      return exist_;
   }
 private:
   runNode *component_, *def_, *attach_, *not_exist_, *like_, *extends_;
   string name_table_, name_db_, name_;
   map<string, defCNode*> rel_;
   vector<string> rel_tables_;
   symbols default_val_;
   bool exec_, exist_;
   int type_level_, extend_level_;
   runNode *id_key_;
};
//----------------------------------------------------------------------
class relCNode : public arrayNode {
 public:
   relCNode (runNode *field, runNode* stmts);
   relCNode (string key, dataCNode *a, defCNode *b);
   relCNode (arrayNode *a);
   relCNode ();
   void run();
   void save (string field, dataCNode * data);
   bool is_print () const {
      return false;
   }
   bool is_runlist () const {
      return false;
   }
   runNode * copyArray (arrayNode * a) {
      return new relCNode (a);
   }
   void processData () ;
   string reltable ();
   string relselect();
   string relwhere ();
   void run_get ();
   void run_getData(runNode *key);
   void runRev (vector<runNode*> params);
   vector<dataCNode*> seltologic (runNode *table, defCNode *def, vector<vector<string> > sel);
   arrayNode* logictoNode (vector<dataCNode *> sel);
   void setWhere (runNode* where);
   void setDelWhere (string str) {
      del_where_ = str;
   }
 private:
   void setDataRel (string field, dataCNode * data);
   runNode *field_, *stmts_, *where_;
   defCNode *rela_, *relb_;
   dataCNode *data_;
   string key_, del_where_;
};
class relAccessNode : public runNode {
 public:
   relAccessNode (runNode * key, relCNode* rel);
   void run () {}
   void runRev (vector<runNode*> params);
 private:
   relCNode * rel_;
   runNode * key_;
};

//----------------------------------------------------------------------
class dataCNode : public arrayNode {
 public:
   dataCNode (arrayNode* array);
   dataCNode (runNode * component, listNode *list);
   dataCNode (runNode * component, runNode *stmts);
   dataCNode () ;
   void run ();
   void runArray ();
   void runRev (vector<runNode*> params);
   void run_get ();

   defCNode * getDef () const ;
   defCNode * getDefC () const ; //Cache
   void save ();
   void setRel (string key, relCNode *def);
   relCNode *getRel (string key);

   bool isdef;
   string id;
   void processData (vector<runNode*> params);
   void processDefaultValues ();
   runNode* nodeval () const;
   string getNameTable ();
   string getRelName (string key, dataCNode *data);
   static bool isData (runNode * node);
   runNode * copyArray (arrayNode * a) {
      return new dataCNode (a);
   }
   void setComponent (runNode *component) {
      component_ = component;
   }
   static runNode * getById (defCNode * def, runNode* id);
   runNode* last_access_key ;
 private:
   void iniDefC ();
   void iniDef ();
   runNode *component_, *stmts_;
   bool exec_;
   defCNode * def_, *defC_;
   map<string, relCNode*> rel_;

};

//----------------------------------------------------------------------
class setCNode : public runNode {
 public:
   setCNode (runNode * type, runNode *key, runNode * value, bool isdef = false, bool isid = false, runNode* default_val = NULL);
   void run ();
 private:
   defCNode* insertDef (runNode *&key, runNode * value, dataCNode *data);
   void insertData (runNode *key, runNode * value, dataCNode* data);
   runNode *key_, *type_, *value_, *default_val_;
   bool isdef_, isid_;
};
//----------------------------------------------------------------------
class setRelCNode : public runNode {
 public:
   setRelCNode (runNode *key, runNode * value);
   void run ();
 private:
   runNode *key_, *value_;
};
//----------------------------------------------------------------------
class setExistRelCNode : public runNode {
 public:
   setExistRelCNode (runNode * value);
   void run ();
 private:
   runNode *value_;
};
//----------------------------------------------------------------------
class existDefCNode : public logicNode {
 public:
   existDefCNode (runNode * value);
   void run ();
 private:
   runNode *value_;
};
//----------------------------------------------------------------------
class selCNode : public nexpNode {
 public:
   selCNode (runNode * component, runNode *where, bool uniq = false);
   void run ();
   vector<dataCNode*> seltologic (runNode* table, defCNode *def, vector<vector<string> > sel);
 private:

   arrayNode* logictoNode (vector<dataCNode *> sel) ;
   runNode *component_,  *where_;
   bool uniq_;
};

//----------------------------------------------------------------------
class delCNode : public nexpNode {
 public:
   delCNode (runNode * component, runNode *where);
   void run ();
 private:
   runNode *component_,  *where_;
};
//----------------------------------------------------------------------
/**
 * Controla la lista de definición de componentes y la pila de llamadas
 * a nodos componentes y nodos definiciones.
 */
class listC {
 public:
   static void set_defCNode (runNode *str, runNode* def);
   static defCNode* get_defCNode (runNode *str);
   static void set_defCNode (string str, runNode* def);
   static defCNode* get_defCNode (string str);

   static void push_dataCNode (runNode* data);
   static dataCNode* top_dataCNode ();
   static dataCNode* pop_dataCNode ();


   static void push_defCNode (runNode* data);
   static defCNode* top_defCNode ();
   static defCNode* pop_defCNode ();

   static void push_relCNode (runNode* data);
   static relCNode* top_relCNode ();
   static relCNode* pop_relCNode ();

   static map<string, defCNode *> list;
   static vector<dataCNode*> stack_data;
   static vector<relCNode*> stack_rel;
   static vector<defCNode*> stack_def;
   static int stack_data_top;
   static int stack_def_top;
   static int stack_rel_top;
};
//----------------------------------------------------------------------
class checkFunction {
 public:
   static string processRegExp (defCNode *def, string where);
   static string processWhere (defCNode * def, string where);
   bool check ();
   vector<string> params;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#endif


