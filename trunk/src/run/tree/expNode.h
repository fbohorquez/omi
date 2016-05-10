//expNode.h
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
 * \file expNode.h
 * \brief Expresiones
 * 
 * En este fichero se describe y definen los nodos ejecutables expresiones 
 * generales. Una expresión es modelada mediante un nodo que puede
 *  tener un valor, este puede ser de tipo conocido o no.
 */

#ifndef _RUN_TREE_EXPNODE_
#define _RUN_TREE_EXPNODE_

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "runTree.h"

using namespace std;
 
//-------------------------------------------------------------------------------------------

/**
 * \class expNode
 * \brief Nodo de expresión
 *
 * Una expresión tiene asociado un valor resultado de su evaluación.
 *
 * Los nodos expresiones pueden ser de dos tipos:
 *
 * - Definidos (dexpNode): Tienen un valor interno definido. Por ejemplo un 
 * stringNode se representa mediante un string.
 *
 * - No definidos (nexpNode): Tienen un valor interno no definido,
 * haciendo referencia a un nodo ejecutable. Por ejemplo, una expresión
 * de asignación tomará una referencia al nodo asignado, este valor puede 
 * ser string, array ....
 *
 * Los nodos expresión son la base de muchos otros nodos que representan 
 * datos, operadores...
 * Estos nodos serán utilizados como parte de una sentencia. 
 */
class expNode :
   public objectTypeNode {
 public:
   /**
    * Método que toma un nodo y lo clona en función de su tipo.
    * \param node Nodo a clonar.
    * \return Nodo nuevo.
    */
   static runNode * clone (runNode* node);
   /**
    * Establece el valor del nodo. Este método puede ser escrito en 
    * los nodos derivados.
    * \param node Nodo que se toma como valor.
    */
   virtual void setNodeValue (runNode* node);
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class dexpNode
 * \brief Nodo expresión de tipo definido.
 *
 * Los nodos de expresión de tipo definido tienen un valor o conjunto de
 * valores asociados. Estos valores son de un tipo concreto, conocido y
 * definido.
 *
 * Toda expresión definida podrá realizar una conversión de su valor interno 
 * a los tipos booleano, numérico y cadena de caracteres.
 * 
 * Estos nodos se dividen en dos grupos:
 *
 * - Nodos tipos: Definen los tipos de datos básicos: booleanos, numéricos,
 * cadenas, arrays ...
 *
 * -Nodos operadores definidos: Definen operaciones cuyo tipo de valor 
 * es conocido. Por ejemplo: la operación suma tiene un valor numérico 
 * asociado. la comparación de igualdad un valor booleano;
 *
 */
class dexpNode : public expNode {
   public:
      /**
      * Obtiene el valor booleano del nodo.
      * \return Booleano que representa el valor del nodo.
      */
      virtual bool boolvalue () const;
       /**
      * Obtiene el valor numérico del nodo.
      * \return Numérico que representa el valor del nodo.
      */     
      virtual num numvalue () const;
      /**
      * Obtiene el valor cadena de caracteres del nodo.
      * \return Cadena de caracteres que representa el valor del nodo.
      */
      virtual string strvalue () const;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class nexpNode
 * \brief Nodo expresión de tipo no definido.
 *
 * No tienen un valor definido. Su valor interno es una referencia a un nodo
 * ejecutable de cualquier tipo. Aunque generalmente el tipo del nodo al 
 * que referencia será una expresion de tipo definido, es posible que una 
 * expresión de tipo no definido apunte a otra de la misma naturaleza. 
 * Esto hace posible que una determinada rama del árbol de ejecución este 
 * compuesta de varios nodos de tipo no definido, aunque siempre se deberá 
 * cumplir que los nodos finales de cada rama sean de tipo definido.
 *
 * Las expresiones no definidas representan datos variables cuyo valor puede variar.
 * Estos datos suelen ser referenciados mediante la tabla de símbolos 
 * (sTable) para ser accesibles desde cualquier parte del árbol de ejecución.
 *
 * El ejemplo más claro de expresión no definida es el de variable. 
 * Una variable puede contener cualquier tipo de elemento (string, arrays, enteros...). 
 *
 * Todos los nodos expresiones no definidas implementan este concepto 
 * con determinados matices, el nodo operador acceso a array, por ejemplo,  
 * guarda una referencia a la referencia del elemento concreto dentro del array. 
 * El operador asignación guarda una referencia al elemento recién asignado.
 *
 * Todo nodo expresión no definido debe implementar los métodos de observación y
 * modificación de su referencia.
 *
 */
class nexpNode : public expNode {
 public:
   nexpNode ();
   /**
    * Método virtual que debe ser implementado por las clases herederas.
    * Obtiene la referencia de la expresión no definida.
    */
   virtual refNode *ref ();
   /**
    * Modifica la referencia de la expresión no definida.
    */
   virtual void noderef (runNode* node);
   /**
    * Modifica la referencia de la expresión no definida.
    */
   virtual runNode* nodeval () const;
   /**
    * Modifica la referencia de la expresión no definida.
    */
   virtual void setRef (refNode* node);
   /**
    * Obtiene la referencia de la expresión no definida
    * \return Referencia de la expresión.
    */
   virtual refNode* getRef ();
   /**
    * Resuelve un nodo ejecutable. Si el nodo dado como parámetro 
    * presenta una referencia obtiene el valor de esta, repitiendo el proceso 
    * hasta que se obtiene un nodo de tipo definido.  El nodo dado como parámetro
    * será modificado por el valor obtenido.  El nodo obtenido es además ejecutado
    * \param Nodo que será resuelto.
    * \return Nodo resultado del proceso.
    */
   static runNode* resolved (runNode* &node);
  /**
    * Resuelve un nodo ejecutable. Si el nodo dado como parámetro 
    * presenta una referencia obtiene el valor de esta, repitiendo el proceso 
    * hasta que se obtiene un nodo de tipo definido.  El nodo dado como parámetro
    * será modificado por el valor obtenido.  El nodo obtenido no es ejecutado
    * \param Nodo que será resuelto.
    * \return Nodo resultado del proceso.
    */
   static runNode* resolvedRef (runNode* &node);
  /**
    * Resuelve un nodo ejecutable. Si el nodo dado como parámetro 
    * presenta una referencia obtiene el valor de esta, repitiendo el proceso 
    * hasta que se obtiene un nodo de tipo definido.  El nodo dado como parámetro
    * será modificado por el valor obtenido. El nodo dado como parámetro referencia
    * tomará el valor de la última referencia resuelta. 
    * \param Nodo que será resuelto.
    * \param Nodo que contendrá la última referencia resuelta.
    * \return Nodo resultado del proceso.
    */ 
   static runNode* resolved (runNode* &node, runNode* &ref);
   /**
    * Resuelve el nodo ejecutable como un función. Se busca el nodo 
    * dado en la tabla de funciones y se devuelve la función correspondiente
    * si existe, NULL en caso contrario. El parámetro toma como valor la función.
    * \param node Nodo que será resulto como función.
    * \return Nodo función.
    */
   static runNode* resolvedAsFunction (runNode* &node);
   /**
    * Resuelve el nodo ejecutable como una función. Se busca el nodo 
    * dado en la tabla de funciones y se devuelve la función correspondiente
    * si existe, NULL en caso contrario. El parámetro toma como valor la función.
    * El parámetro dado como referencia tomará el valor de la última referencia resuelta.
    * \param node Nodo que será resulto como función.
    * \param ref Tomará como valor la última referencia resuelta.
    * \return Nodo función.
    */
   static runNode* resolvedAsFunction (runNode* &node, runNode* &ref);
   /**
    * Resuelve un nodo ejecutable. Si el nodo dado como parámetro 
    * presenta una referencia obtiene el valor de esta, repitiendo el proceso 
    * hasta que se obtiene un nodo de tipo definido. 
    * \param Nodo que será resuelto.
    * \return Nodo resultado del proceso.
    */
   static runNode* resolv (runNode* node);
   /**
    * Establece el valor del nodo al de un nodo dado tras resolver todas
    * las referencias. El nodo asignado puede ser ejecutado.
    * \param node Nodo a asignar.
    * \param run Determina si se debe ejecutar el nodo asignado.
    */
   void asig (runNode* &node, bool run = true);
   /**
    * Establece el valor del nodo al de un nodo dado. 
    * \param node Nodo a tomar como valor.
    */
   void setVal (runNode * node );
   /**
    * Devuelve una cadena de caracteres que se corresponde con la 
    * representación textual del nodo que es referenciado.
    * \return Cadena que representa el valor de la referencia.
    */
   string print () const;
 protected:
   refNode *ref_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class logicNode
 * \brief Nodos lógicos.
 *
 * Los nodos lógicos tienen un valor booleano asociado.
 *
 * Los nodos lógicos son una especialización de los nodos de expresión.
 * 
 * Todo nodo lógico está asociado al nodo clase "logicClass".
 */
class logicNode :
   public dexpNode {
 public:
   logicNode ();
   /**
    * Devuelve la cadena asociada al nodo. Según el valor booleano
    * del mismo devolverá la cadena "true" o "false".
    * \return Cadena de caracteres que representa el valor del nodo.
    */
   string print () const;
   /**
    * Devuelve el valor booleano asociado al nodo.
    * \return Valor booleano del nodo.
    */
   bool boolvalue () const;
   /**
    * Método que devuelve un nodo de tipo booleano con el mismo
    * valor del nodo lógico.
    * \return Nodo booleano.
    */
   runNode* nodeval () const;
   /**
    * Convierte un nodo a su valor lógico.
    * \return valor lógico del nodo.
    */
   static bool to_bool (runNode* node);
   /**
    * Devuelve el valor numérico asociado al nodo.
    * \return Valor numérico del nodo.
    */
   num numvalue () const;
   /**
    * Devuelve el valor cadena de caracteres asociado al nodo.
    * \return Valor cadena del nodo.
    */
   string strvalue () const;
   /**
    * Obtiene la clase asociada a todo nodo lógico.
    * \return Nodo clase asociado a los nodos lógicos.
    */
   runNode * getClass ();
  /**
    * Establece el valor del nodo a partir de otro nodo.
    * \param node Nodo a partir del cual se tomará el valor.
    */
   virtual void setNodeValue (runNode* node);
   /**
    * Genera el nodo clase "logicClass" asociado a todo nodo lógico 
    * y la añade a la tabla de símbolos clases.
    */
   static void generateClass ();
 protected:
   static runNode* class_;
   /**
    * Atributo que representa el valor booleano del nodo.
    */
   bool boolvalue_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class arithNode
 * \brief Nodos aritméticos.
 *
 * Los nodos aritméticos tienen un valor numérico asociado. Para la representación
 * interna de un número se utiliza el tipo num que puede ser dado en 
 * tiempo de compilación.  Normalmente este tipo contemplará los números
 * que pueden ser representados por una expresión en coma flotante.
 * 
 * Todo nodo aritmético está asociado a un nodo clase "arithClass"
 */
class arithNode :
   public dexpNode {
 public:
   /**
    * Devuelve la cadena de caracteres asociada al nodo que representa 
    * el valor numérico del mismo.
    * \return Cadena de caracteres que representa el valor del nodo.
    */
   string print () const;
   /**
    * Método que devuelve un nodo de tipo booleano con el mismo
    * valor del nodo lógico.
    * \return Nodo booleano.
    */
   runNode* nodeval () const;
   /**
    * Método observador que devuelve el valor numérico del nodo.
    * \return Valor numérico del nodo.
    */
   num numvalue () const;
   /**
    * Convierte un nodo a su valor aritmético.
    * \return Valor numérico.
    */
   static num to_num (runNode* node, bool exception = true);
   /**
    * Convierte un nodo a su valor booleano.
    * \return Valor booleano.
    */
   bool boolvalue () const;
   /**
    * Convierte un nodo a su valor cadena de caracteres.
    * \return Valor cadena de caracteres.
    */
   string strvalue () const;
   /**
    * Obtienen el nodo clase asociado al nodo aritmético.
    * \return Nodo clase.
    */ 
   runNode * getClass ();
   /**
    * Genera la clase "arithClass" y la añade a la tabla de símbolos clases.
    */
   static void generateClass ();
    /**
    * Establece el valor del nodo a partir de otro nodo.
    * \param node Nodo a partir del cual se tomará el valor.
    */
   virtual void setNodeValue (runNode* node);
 protected:
 static runNode* class_;
   /**
    * Atributo que representa el valor numérico del nodo.
    */
   num numvalue_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class stringNode
 * \brief Nodos cadenas de texto.
 *
 * Los nodos cadenas tienen un valor texto asociado.
 *
 * Todo nodo cadena está asociado al nodo clase "stringClass".
 */
class stringNode :
   public dexpNode {
 public:
   stringNode ();
   /**
    * Devuelve la cadena asociada al nodo.
    * \return Cadena de caracteres que representa el valor del nodo.
    */
   string print () const;
   /**
    * Método que devuelve un nodo de tipo cadena de caracteres con el 
    * mismo valor del nodo.
    * \return Nodo cadena de caracteres.
    */
   runNode* nodeval () const;
   /**
    * Método observador que devuelve el valor string del nodo.
    * \return Valor textual del nodo.
    */
   string strvalue () const;
   /**
    * Método modificador que devuelve una referencia al valor string del nodo.
    * \return Referencia al valor texto del nodo.
    */
   string* strref ();
   /**
    * Método que obtiene el valor numérico del string.
    * Si el string es un número devuelve su valor, en caso contrario devuelve 0.
    *
    * print "3" + 8 #11
    * print 4 - "str" #0
    */
   num numvalue () const;
   /**
    * Comprueba si la cadena de caracteres representa un número.
    * \return Booleano que indica si la cadena es numérica.
    */
   bool is_numvalue () const;
   /**
    * Convierte un nodo a una cadena de  caracteres.
    * \param node Nodo a convertir.
    * \return Cadena de caracteres.
    */
   static string to_str (runNode* node);
  /**
   * Obtiene el nodo clase asociado a los nodos cadenas de caracteres.
   * \return Nodo clase.
   */
   runNode * getClass ();
   /**
    * Genera la clase "stringClass" asociada a toda cadena de caracteres.
    */
   static void generateClass ();
   /**
    * Establece el valor de la cadena de caracteres interna.
    * \param s Cadena que se establecerá como valor.
    */
   void setStrValue (string s);
   /**
    * Establece el valor de la cadena de caracteres interna a partir de un nodo ejecutable.
    * \param node Nodo que representa la cadena de caracteres que se establecerá como valor.
    */
   void  setNodeValue (runNode* node);
   /**
    * Obtiene el valor booleano del nodo.
    * \return Booleano que representa el valor del nodo.
    */
   bool boolvalue () const;
 protected:
   static runNode* class_;
   /**
    * Atributo que representa el valor texto del nodo.
    */
   string strvalue_;
};
 
//-------------------------------------------------------------------------------------------

/**
 * \class fexpNode
 * \brief Nodo expresiones funciones.
 * 
 * Define nodos que representan expresiones formadas mediante
 * la declaración de funciones.
 */
class fexpNode : public expNode {
 public:
 /**
  * Una función no es imprimible.
  * \return Falso
  */
   bool is_print () const;
   /**
  * Una función no es un elemento de lista.
  * \return Falso
  */
   bool is_runlist () const;
   /**
    * Una función no puede ser eliminada de la formal normal.
    */
   void rmRef ();
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. javier Bóhorquez Ogalla


