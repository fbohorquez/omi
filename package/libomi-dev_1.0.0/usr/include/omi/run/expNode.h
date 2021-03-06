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
 * \file expNOde.h
 * \brief Árbol de ejecución
 */
//----------------------------------------------------------------------
#ifndef _EXPNODE_
#define _EXPNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "runTree.h"
#include "symbols.h"
#include "numData.h"
using namespace std;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
class objectTypeNode: public printableNode {
 public:
   objectTypeNode () : custom_class_ (NULL){}
   runNode* getMethod (runNode* key);
   refNode* getMethodRef (runNode* key);
   virtual runNode * getClass () {
      return NULL;
   }
   virtual void setClass (runNode * c) {
      custom_class_ = c;
   }
   protected:
      runNode * custom_class_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class expNode
 * \brief Nodo de expresión
 *
 * Una expresión tiene asociado un valor resultado de su evaluación, este
 * valor es a su vez un nodo ejecutable.
 *
 * Para acceder al valor de un nodo expresion se utiliza el método
 * nodeval () que define esta clase y que deberá ser implementado por las
 * clases que la hereden.
 *
 * Los nodos expresiones pueden ser de dos tipos:
 *
 * - Definidos (dexpNode): Tienen un valor interno definido. Por ejemplo un stringNode
 * se representa mediante un string.
 *
 * - No definidos (nexpNode): Tienen un valor interno no definido,
 * haciendo referencia a un nodo ejecutable. Por ejemplo, Una expresión
 * de asignación tomará una referencia al nodo asignado, este valor puede ser string, array ....
 *
 *
 * Generalmente los nodos de ejecucion de tipo definidos se puede liberar de memoria tras
 * la utilización de su valor en la interpretación de su nodo padre, ya que estos nodos representaran
 * valores fijos y al haberse utilizado estos ya no se volveran a utilizar. Vemos esto con un ejemplo.
 *
 * Si consideramos la expresión "5 * (4 + 2);" Durante la inicialización
 * del árbol de ejecución se ha generado en memoria dinámica tres nodos numéricos
 * con los valores 5, 4 y 2, y dos nodos expresiones, la suma y el producto. Lo primero que se interpreta
 * es la expresión suma que guarda de forma interna el resultado de sumar el valor numérico
 * 2 con 4, es decir 6. En este momento los nodos numericos 4 y 2 pueden ser liberados.
 * Luego se interpreta la expresion producto del  nodo numérico 5 con el valor
 * de la expresión suma (6) y se guarda como valor interno de la expresion producto (30). En
 * este momento tanto la expresión suma como el nodo numérico podría ser liberada de memoria
 * asi la expresión a quedado reducida a una unica expresión con valor 30.
 *
 * En contra partida no todos los nodos de ejecución de tipos no definidos  pueden ser liberados
 * tras la utilización de su valor ya que su valor es una referencia a un nodo ejecutable y este podría
 * ser referenciado desde otro lugar como desde la tabla de símbolos. Además el valor de un nodo expresion no definido
 * se determina en tiempo de ejecución, asi que puede variar con distintas ejecuciones del nodo. Es por esto que
 * que una sentencia que contenga un nodo expresión no definido no puede ser reducida, al menos en su totalidad.
 * El siguiente ejemplo muestra este caso:
 *
 *  Considiremos la expresión "3 + a - 1". En este caso en la inicializacion se
 * 	crean en memoria dianámica 2 nodos numéricos, un nodo id, un nodo resta y un nodo suma.
 * Primero se ejecuta el nodo id que obtiene la referencia del nodo al que apuenta en la tabla
 * de simbolos el identificador "a". El nodo id es un tipo no definido por lo que al ejecutarse se indicará que no se
 * debe liberar ningún nodo de la expresión. Luego se ejecuta la resta la cual obtiene el valor referenciado en "a"
 * y le resta el valor 1, la resta tomará el valor de a - 1.
 * Ni el nodo id, ni el nodo numérico pueden ser liberados ya que el nodo resta podria ser ejecutado
 * de nuevo y depende del valor de "a" para obtener su valor. Por último se ejecuta la suma del nodo 3 con el valor de la resta, que al ser
 * una expresión de tipo indefinido se toma el valor del nodo al que hace referencia, es decir 1. El resultado que es 4 se
 * guarda como valor interno de la expresión. De igual forma tras la ejecución del nodo suma no se puede borrar ni el nodo númerico, ni el nodo
 * resta ya que aunque el nodo resta es de tipo definido su ejecución depende de un tipo no defindido. Podemos decir
 * que la propiedad de tipo no defino se extiende a los nodos raiz del subárbol que conforma la sentencia.
 *
 * Lo normal es que en una setencia coexistan expresiones definidas y no definidas. Así toda rama de la sentencia que
 * solo contengan expresiones definidas será reducida.
 */
class expNode :
   public objectTypeNode {
 public:
   static runNode * clone (runNode* node);
   static runNode *toString (runNode *&node);
   virtual void setNodeValue (runNode* node) {}
  
};
//----------------------------------------------------------------------
/**
 * \class dexpNode
 * \brief Nodo expresión de tipo definido
 *
 * Los nodos de expresión de tipo definido tienen un valor o conjunto de
 * valores asociados. Estos valores son de un tipo concreto, conocido y
 * definido.
 *
 * Un rama del árbol de ejecución que solo incluya expresiones de tipos definidos
 * se puede simplificar tras su primera ejecución. Supongamos la expresión
 * "b = a + 8 + 5". En una primera ejecución se evaluará el conjunto de expresiones
 * completo, mientras que en ejecuciones posteriores se evaluará como "b = a + 13".
 * Esto es porque las expresiones correspondiente a la rama "8 + 5" son todas de
 * tipo definido.
 *
 * Cada clase especifica de expreciones definidas debe implementarán
 * métodos para el acceso de sus valores.
 *
 * Estos nodos se dividen en dos grupos:
 *
 * - Nodos tipos: Definen los tipos de datos básicos: booleanos, numéricos,
 * cadenas, arrays ...
 *
 * -Nodos operadores definidos: Definen operaciones cuyo tipo de valor es conocido.
 * Por ejemplo: la operción suma tiene un valor numérico asociado. la comparación
 * de igualdad un valor booleano;
 *
 */
class dexpNode : public expNode {
   public:
      virtual bool boolvalue () const { return false; }
      virtual num numvalue () const { return 0; }
      virtual string strvalue () const { return ""; }
};
/**
 * \class nexpNode
 * \brief Nodo expresión de tipo no definido.
 *
 * No tienen un valor definido. Su valor interno es una referencia a un nodo
 * ejecutable de cualquier tipo. Aunque generalmente el tipo de nodo al que referencia será una expresion de tipo definido
 * es posible que una expresión de tipo no definido apunte a otra de la misma naturaleza. Esto hace posible que
 * una determinada rama del árbol de ejecución este compuesta de varios nodos de tipo no definido, aunque
 * siempre se deberá cumplir que los nodos finales de cada rama sean de tipo definido.
 *
 * Las expresiones no definidas representan datos variables cuyo valor puede variar.
 * Estos datos suelen ser referenciados mediante la tabla de símbolos (sTable) para ser accesibles desde
 * cualquier parte del árbol de ejecución
 *
 * El ejemplo más claro de expresión no definida es el de variable. Una variable
 * puede contener cualquier tipo de elemento (string, arrays, enteros...). Esta se
 * representa mediante nodos identificadores y un elemento de la tabla de símbolos. En la tabla de símbolos
 * se guarda un par <nombre del identificador, referencia a un nodo ejecutable>. El
 * nodo identificador guarda una referencia a la referencia de la tabla de simbolos.
 * Esto hace posible que se pueda modificar la tabla de simbolos usando como interfaz
 * el nodo identificador.
 *
 * Todos los nodos expresiones no definidas implementan este concepto con determinados matices,
 * El nodo operador acceso a array, por ejemplo,  guarda una referencia a la referencia del elemento concreto dentro del
 * array. El operador asignación guarda una referencia a la referencia del elemento recién asignado.
 *
 * Todo nodo expresion no definido debe implementar los metodos de observación y
 * modificación de su referencia
 *
 */
class nexpNode : public expNode {
 public:
   nexpNode () : ref_ (NULL) {}
   /**
    * Método virtual que debe ser implementado por las clases herederas.
    * Obtiene la referencia de la expresión no definida.
    */
   virtual refNode *ref () {
      return ref_;
   }
   /**
    * Modifica la referencia de la expresión no definida
    */
   virtual void noderef (runNode* node){
      if (!ref_) ref_ = new refNode ();
      ref_->setRef(node);
   }
   /**
    * Modifica la referencia de la expresión no definida
    */
   virtual runNode* nodeval () const {
      if (ref_)
         return ref_->getRef();
      else
         return NULL;
   }
   /**
    * Modifica la referencia de la expresión no definida
    */
   virtual void setRef (refNode* node){
      ref_ = node;
   }
   virtual refNode* getRef (){
      return ref_;
   }
   /**
    *
    */
   static runNode* resolved (runNode* &node);
   static runNode* resolved (runNode* &node, runNode* &ref);
   static runNode* resolvedAsFunction (runNode* &node);
   static runNode* resolvedAsFunction (runNode* &node, runNode* &ref);
   static runNode* resolv (runNode* node) {
      if (nexpNode* nexp = dynamic_cast<nexpNode*> (node)) {
         nexp->run();
         node = nexp->nodeval();
      }
      return node;
   }
   void asig (runNode* &node, bool run = true) {
      runNode * node_ = node;
      if (run) {
         nexpNode::resolved(node_);
         node_->run();
      }
      if (expNode * exp = dynamic_cast<expNode*> (node_)) {
         noderef (exp);
      }
   }
   void setVal (runNode * node ) {
      noderef (node);
   }
   string print () const  {
      if (printableNode * p = dynamic_cast<printableNode*> (ref_->getRef())){
         return p->print();
      }
      return "";
   }
 protected:
   refNode *ref_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class logicNode
 * \brief Nodos lógicos
 *
 * Los nodos lógicos tienen un valor booleano asociado.
 *
 * Los nodos lógicos son una especialización de los nodos de expresión.
 */
class logicNode :
   public dexpNode {
 public:
   /**
    * Devuelve la cadena asociada al nodo. Según el valor booleano
    * del mismo devolverá la cadena "true" o "false".
    * \return Cadena de carácteres que representa el valor del nodo
    */
   string print () const;
   /**
    * Devuelve el valor booleano asociado al nodo.
    * \return Valor booleano del nodo.
    */
   bool boolvalue () const;
   /**
    * Método que devuelve un nodo de tipo booleano que con el mismo
    * valor del nodo lógico.
    * \return Nodo booleano.
    */
   runNode* nodeval () const;
   /**
    * Convierte un nodo a su valor lógico
    */
   static bool to_bool (runNode* node);
   
   num numvalue () const {
      return (int)boolvalue_;
   }
   string strvalue () const {
      return (boolvalue_)? "1":"";
   }
   runNode * getClass () {
      return custom_class_?custom_class_:logicNode::class_;
   }
   virtual void setNodeValue (runNode* node)  {
      boolvalue_ = logicNode::to_bool (node);
   }
   static void generateClass ();
   
 protected:
   static runNode* class_;
   /**
    * Atributo que representa el valor booleano del nodo.
    */
   bool boolvalue_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class arithNode
 * \brief Nodos aritmeticos
 *
 * Los nodos aritméticos tienen un valor numérico asociado.
 *
 * Los nodos aritméticos a su vez representan nodos lógicos, considerándose
 * que el valor booleano de estos es "true" si el valor numérico
 * es distinto de 0 y "false" en caso contrario.
 */
class arithNode :
   public dexpNode {
 public:
   /**
    * Devuelve la cadena asociada al nodo que representa el valor
    * numérico del mismo.
    * \return Cadena de carácteres que representa el valor del nodo
    */
   string print () const;
   /**
    * Método que devuelve un nodo de tipo booleano que con el mismo
    * valor del nodo lógico.
    * \return Nodo booleano.
    */
   runNode* nodeval () const;
   /**
    * Método observador que devuelve el valor numérico del nodo
    * \return Valor numerico del nodo.
    */
   num numvalue () const;

   static num dval (runNode* node);
   /**
    * Convierte un nodo a su valor aritmético
    */
   static num to_num (runNode* node, bool exception = true);
   /**
    * Convierte un nodo a su valor aritmético
    */
   bool boolvalue () const{ return numvalue_; }
   /**
    * Convierte un nodo a su valor aritmético
    */
   string strvalue () const;
   
   runNode * getClass () {
      return custom_class_?custom_class_:arithNode::class_;
   }

   static void generateClass ();
   virtual void setNodeValue (runNode* node)  {
      numvalue_ = arithNode::to_num (node);
   }
 protected:
 static runNode* class_;
   /**
    * Atributo que representa el valor numérico del nodo.
    */
   num numvalue_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class stringNode
 * \brief Nodos cadenas de texto
 *
 * Los nodos cadenas tienen un valor texto asociado.
 *
 * Los nodos cadenas a su vez representan nodos lógicos, considerándose
 * que el valor booleano de estos es "true" si la cadena es distinto de vacio
 * o "false" en caso contrario
 */
class stringNode :
   public dexpNode {
 public:
   stringNode ();
   /**
    * Devuelve la cadena asociada al nodo que representa el valor
    * numérico del mismo.
    * \return Cadena de carácteres que representa el valor del nodo
    */
   string print () const;
   /**
    * Método que devuelve un nodo de tipo booleano que con el mismo
    * valor del nodo lógico.
    * \return Nodo booleano.
    */
   runNode* nodeval () const;
   /**
    * Método observador que devuelve el valor string del nodo
    * \return Valor texto del nodo.
    */
   string strvalue () const;
   /**
    * Método modificador que devuelve una referencia al valor string del nodo
    * \return Ref. al valor texto del nodo.
    */
   string* strref () {
      return &strvalue_;
   }
   /**
    * Método que obtiene el valor numérico del string.
    * Si el string es un número devuelve su valor, en
    * caso contrario devuelve 0.
    *
    * print "3" + 8 #11
    * print 4 - "str" #0
    *
    */
   num numvalue () const;
   bool is_numvalue () const;

   static string to_str (runNode* node);
   runNode * getClass () {
      return custom_class_?custom_class_:stringNode::class_;
   }

   static void generateClass ();
   
   void setStrValue (string s) {
      strvalue_ = s;
   }
   bool boolvalue () const { return numvalue(); }
   virtual void setNodeValue (runNode* node)  {
      strvalue_ = stringNode::to_str (node);
   }
 protected:
   static runNode* class_;
   /**
    * Atributo que representa el valor texto del nodo.
    */
   string strvalue_;
};

//----------------------------------------------------------------------


#endif


