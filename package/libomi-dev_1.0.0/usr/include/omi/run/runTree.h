//runTree.h
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
 * \file runTree.h
 * \brief Árbol de ejecución
 *
 * Un árbol de ejecución es una estructura de datos funcional. Está
 * formado por nodos de ejecución. Existen una gran variedad de
 * especializaciones de nodos ejecutables.
 *
 * Tras un análisis léxico y sintáctico de un programa liesh
 * se construye el árbol de ejecución con los nodos
 * correspondientes a las distintas sentencias que lo forman.
 *
 * La ejecución de un árbol de esta naturaleza producirá la salida del
 * programa liesh.
 *
 * En un árbol de ejecución los hijos asociados a cada nodo dependen
 * de la naturaleza del nodo en si.
 *
 * En el fichero runTree.h se define e implementa la clase genérica
 * runNode que modela un nodo ejecutable. Además se especifican las
 * clases que derivan inmediatamente de esta y que, aunque siguen
 * teniendo un proposito general, definen subtipos de nodos ejecutables
 * con propiedades afines.
 */
//----------------------------------------------------------------------
#ifndef _RUNNODE_
#define _RUNNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "numData.h"
using namespace std;
//----------------------------------------------------------------------


//----------------------------------------------------------------------
/**
 * \class runNode
 * \brief Nodo ejecutable
 *
 * Un nodo de ejecución representa la unidad funcional básica de un
 * programa liesh.
 *
 * Se definen una gran variedad de tipos de nodos ejecutables. Así
 * existirá un nodo de ejecución por cada tipo de dato, sentencia,
 * operador... Como es de imaginar cada uno de estos tipos realizará una
 * función diferente sobre los datos y elementos que los forma, que
 * igualmente serán nodos de ejecución.
 *
 * Por ejemplo una sentencia "if" se corresponderá con un nodo de
 * ejecución que a su vez enlaza a 3 nodos. El primero de
 * los cuales representa una expresión booleana que será evaluada al
 * ejecutarse el nodo "if". Si la expresión booleana resulta verdadera
 * se ejecutará uno de los otros nodos, el cual representará el bloque
 * de sentencias "then". Por el contrario si la expresión resulta falsa
 * se ejecutará el otro que representa el bloque de sentencias "else".
 *
 * Es posible distengir entre dos clases de nodos de ejecución:
 *
 * \li Genéricos
 * \li Específicos
 *
 * Los nodos genéricos definen clases de nodos con atributos y métodos
 * comunes. Por ejemplo los nodos lógicos tendran un valor booleano
 * asociado, los nodos imprimibles podrán ser procesados para conformar
 * una salida, etc. Estos nodos son tipos de datos incompletos o interfaces.
 *
 * Los nodos específicos suelen derivar de los anteriores, es decir, son
 * especializaciones de los nodos genéricos. Algunos de estos nodos
 * pueden ser el operador "or", la sentencia "if", el dato entero ....
 *
 */
class runNode {
 public:
   runNode (string str);
   runNode () : ref_count_ (0), isprivate_ (false) {}
   /**
    * Método virtual de ejecución. Este método debe ser implementado
    * por todas las clases de nodos ejecutables.
    *
    * La implementación de este método definirá la función que se
    * llevará a cabo al ejecutarse el nodo.
    *
    * En escencia los distintos nodos se diferencia entre si por
    * la forma en que implementan esta función.
    */
   virtual void run () = 0;
   /**
    * Compara dos punteros runNode
    *
    * \param node1, node2 Nodos a comparar
    * \param op
    * 	Operador a a plicar
   		case 0:  ==
   		case 1:  !=
   		case 2:	 >
   		case 3:	 <
   		case 4:	 >=
   		case 5:	 <=
   		case 6: ===
   */
   virtual void addRef () {
      ref_count_ ++;
   }
   virtual void rmRef () {
      ref_count_ --;
      if (ref_count_ == 0) {
         //~ cerr << "ELIMINANDO (" << this->to_str() << ")" << endl;
         delete this;
      }
   }
   static bool compare(runNode  *node1, runNode *node2, int op = 0);
   virtual void runRev (vector<runNode*> params) {  }
   virtual bool is_print () const {
      return true;
   }
   virtual bool is_runlist () const {
      return false;
   }
   virtual bool is_string () const {
      return false;
   }
   virtual runNode* cloneNode (runNode* node) {
      return NULL;
   }   
   virtual bool to_bool ();
   virtual num to_num ();
   virtual string to_str ();
   virtual ~runNode () {}
   refC ref_count_;
   bool isprivate_;
};
//----------------------------------------------------------------------
/**
 * Estructura que define la comparación de elementos runNode
 *
 * Esta estructura hace posible la ordenación de elementos
 * puntero a nodo ejecutable por su valor interno.
 *
 */
struct cmp_runNode {
   /**
    * Realiza la comparación del valor de *node1 con el valor de *node2
    * Y determina si *node1 < *node2
    */
   bool operator()(runNode  *node1, runNode *node2);

};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class printableNode
 * \brief Nodos imprimible
 *
 * Los nodos imprimibes implementan un método "print" que devuelve una
 * cadena de texto que representa el contenido del nodo.
 *
 */
class printableNode: public runNode {
 public:
   /**
    * Método virtual que devuelve la cadena de texto asociada al
    * nodo.
    */
   virtual string print () const = 0;


};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
class refNode : public printableNode {
  public:
      refNode() : keyvalue_ (""), refSymbol_ (NULL){}
      refNode(string str) : keyvalue_ (str), refSymbol_ (NULL){}
      refNode(runNode* data);
      refNode (refNode *a) : keyvalue_ (a->keyvalue_), refSymbol_ (a->refSymbol_){}
      void setRef (runNode* node ) {
         refSymbol_ = node;
      }
      runNode* getRef () const {
         return refSymbol_ ;
      }
      runNode* &getRef () {
         return refSymbol_ ;
      }
      void run () {}
      void rmRef () {}
      void del () {
         if (!ref_count_)
            delete this;
      }
      string strvalue () {
         return keyvalue_;
      }
      int numvalue () {
         return keyvalue_.size();
      }
      bool boolvalue () {
         return keyvalue_ == "";
      }
      string print () const {
         if (printableNode* p = (printableNode*)dynamic_cast<printableNode*>(this->getRef()))
            return p->print();
         return "";
      }
      void setKey (string s) {
         keyvalue_ = s;
      }
      string getKey () {
         return keyvalue_;
      }
   private:
      string keyvalue_;
      runNode * refSymbol_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
class revConnectNode {
 public:
   static void push_stack (string key, runNode* node, vector<runNode*> params) {
      if (m_stack.find(key) == m_stack.end()) return;
      int top = m_key_top[key];
      vector<vector<runNode*> > stack_aux = m_stack[key];
      vector<vector<vector<runNode*> > > stack_params_aux = m_stack_params[key];

      if (top < stack_aux.size()) {
         vector<runNode*> stack;
         vector<vector<runNode*> > stack_params;
         stack = stack_aux[top];
         stack_params = stack_params_aux[top];
         int stack_top = m_stack_top[key][top];

         stack.push_back (node);
         stack_params.push_back (params);
         stack_top ++;

         m_stack_top[key][top] = stack_top;
         stack_params_aux[top] = stack_params;
         stack_aux[top] = stack;
         m_stack[key] = stack_aux;
         m_stack_params[key] =  stack_params_aux;

      }
   }
   static void init (string key) {
      vector<vector <runNode*> > key_v;
      vector<vector<vector <runNode*> > > param_v;
      vector<int> i_v;
      if (m_stack.find(key) == m_stack.end()) {


         m_key_top [key] = -1;
         m_stack[key] = key_v;
         m_stack_params[key] = param_v;

         m_stack_top[key] = i_v;

      }
      key_v = m_stack[key];
      param_v = m_stack_params[key];
      i_v = m_stack_top [key];

      vector<runNode*> call_v;
      vector<vector<runNode*> > call_p;
      key_v.push_back (call_v);
      param_v.push_back (call_p);
      i_v.push_back (-1);

      m_stack[key] = key_v;
      m_stack_params[key] = param_v;
      m_key_top [key] ++;
      m_stack_top [key] = i_v;
   }
   static void end (string key) {
      vector<vector <runNode*> > key_v;
      vector<vector<vector <runNode*> > > param_v;
      vector<int> i_v;
      if (m_stack.find(key)  != m_stack.end() ) {
         key_v = m_stack[key];
         param_v = m_stack_params[key];
         i_v = m_stack_top [key];


         key_v.pop_back();
         param_v.pop_back();
         i_v.pop_back();
         m_key_top [key] --;
         if (m_key_top [key] < 0) {
            m_key_top.erase(key);
            m_stack.erase(key);
            m_stack_params.erase(key);
            m_stack_top .erase(key);
         } else {
            m_stack[key] = key_v;
            m_stack_params[key] = param_v;
            m_stack_top [key] = i_v;
         }

      }
   }
   static void pop_stack (string key) {
      if (m_stack.find(key) == m_stack.end()) return;
      int top = m_key_top[key];
      vector<vector<runNode*> > stack_aux = m_stack[key];
      vector<vector<vector<runNode*> > >stack_params_aux = m_stack_params[key];

      if (top < stack_aux.size()) {
         vector<runNode*> stack;
         vector<vector<runNode*> > stack_params;
         stack = stack_aux[top];
         stack_params = stack_params_aux[top];
         int stack_top = m_stack_top[key][top];

         stack.pop_back ();
         stack_params.pop_back ();
         stack_top --;
         m_stack_top[key][top] = stack_top;
         stack_params_aux[top] = stack_params;
         stack_aux[top] = stack;
         m_stack[key] = stack_aux;
         m_stack_params[key] =  stack_params_aux;

      }
   }
   static runNode* top_stack (string key) {
      if (m_stack.find(key) == m_stack.end()) return NULL;
      int top = m_key_top[key];
      vector<vector<runNode*> > stack_aux = m_stack[key];
      if (top < stack_aux.size()) {
         vector<runNode*> stack;
         stack = stack_aux[top];

         int stack_top = m_stack_top[key][top];
         return ((stack_top >= 0)?stack [stack_top]:NULL);
      }
      return NULL;
   }
   static vector<runNode*> params_stack (string key) {
      vector<runNode*> v;
      if (m_stack.find(key) == m_stack.end()) return v;
      int top = m_key_top[key];
      vector<vector<vector<runNode*> > > stack_params_aux = m_stack_params[key];

      if (top < stack_params_aux.size()) {
         vector<vector<runNode*> > stack_params;
         stack_params = stack_params_aux[top];
         int stack_top = m_stack_top[key][top];
         return ((stack_top >= 0)?(stack_params[stack_top]):v);
      }
      return v;
   }
   static void run_rev (string key, runNode* e_param, int times = -1);
   static bool exist (string key) {
      return (m_stack.find(key) != m_stack.end());
   }
 private:
   static map<string, vector<int> > m_stack_top;
   static map<string, int> m_key_top;
   static map<string, vector<vector<runNode*> > >m_stack;
   static map<string, vector<vector<vector<runNode*> > > >m_stack_params;
};
//----------------------------------------------------------------------
#endif


