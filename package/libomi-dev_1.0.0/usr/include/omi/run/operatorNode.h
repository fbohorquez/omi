//operatorNode.h
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
 * \file operatorNode.h
 * \brief Nodos operadores.
 *
 * Los nodos ejecutables de operadores son nodos cuya ejecución realiza
 * una operación uno, dos o más nodos.
 *
 * Se definen una gran variedad de nodos de operadores. Así existen
 * nodos correspondientes a la operación suma, módulo, cocatenación,
 * comparación ...
 *
 * Los nodos operatodres pueden ser de dos tipos:
 *
 * - Definido: Heredan de tipos de nodos definidos
 * como stringNode, artihMode, booleanNode... Es por ello que tienen
 * valores internos definidos en tipos. Así el operador
 * suma se define como un nodo aritmético por lo que tienen un valor
 * numérico asociado.
 *
 * - No definidos: Heredan de tipos de nodos no definidos por lo que como
 * valor toma un nodo ejecutable de cualquier tipo.
 *
 * Tanto los operadores Difinidos, como no definidos son expresiones
 * (heredan de expNode) por lo que tienen un valor asociado.
 *
 */
//----------------------------------------------------------------------
#ifndef _OPERATORNODE_
#define _OPERATORNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "runTree.h"
#include "typeNode.h"
#include "stmtNode.h"
#include "sTable.h"
#include "../error.h"
#include <math.h> 
using namespace std;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class orNode
 * \brief Nodo operador or
 *
 * Este nodo implementa una operación lógica or entre dos nodos.
 *
 * Para llevar a cabo la operación lógica OR se realiza una evaluación
 * de cortocircuito. Donde el valor del nodo OR es el último
 * valor evaluado.
 *
 * Los nodos asociados deben ser nodos lógicos.
 */
class orNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase. Asocia los nodos operandos.
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    *
    * Los nodos asociados deben ser nodos lógicos, en caso contrario
    * se producirá un error de tipos de datos al ejecutarse el nodo.
    */
   orNode (runNode* op1, runNode* op2);
   /**
    * Función de ejecución. Procede a la ejecución de los nodos
    * asociados. Luego asigna el valor booleano según el valor
    * de la operación or entre el valor booleano de los nodos
    * asociados.
    */
   void run ();
   /**
    * Ejecuta la operación or entre dos nodos dados
    */
   bool do_or (runNode* op1, runNode* op2);
 private:
   runNode *op1_, *op2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class andNode
 * \brief Nodo operador and
 *
 * Este nodo implementa una operación lógica and entre dos nodos.
 *
 * Para llevar a cabo la operación lógica AND se realiza una evaluación
 * de cortocircuito. Donde el valor del nodo AND es el último
 * valor evaluado.
 *
 * Los nodos asociados deben ser nodos lógicos.
 */
class andNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase. Asocia los nodos operandos.
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    *
    * Los nodos asociados deben ser nodos lógicos, en caso contrario
    * se producirá un error de tipos de datos al ejecutarse el nodo.
    */
   andNode (runNode* op1, runNode* op2);
   /**
    * Función de ejecución. Procede a la ejecución de los nodos
    * asociados. Luego asigna el valor booleano según el valor
    * de la operación and entre el valor booleano de los nodos
    * asociados.
    */
   void run ();
   /**
    * Ejecuta la operación and entre dos nodos dados
    */
   bool do_and (runNode* op1, runNode* op2);
 private:
   runNode *op1_, *op2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class notNode
 * \brief Nodo operador not
 *
 * Este nodo implementa una operación lógica not aplicada a un nodo.
 *
 * Un nodo operador not es un nodo lógico ya que tiene un valor booleano
 * asociado, correspondiente a la operación not de su nodo asociado.
 *
 * El nodo asociado debe ser un nodo lógico.
 */
class notNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operando.
    * \param op Nodo operando.
    *
    * El nodo asociado debe ser un nodo lógico, en caso contrario
    * se producirá un error de tipos de datos al ejecutarse el nodo.
    */
   notNode (runNode* op);
   /**
    * Función de ejecución. Procede a la ejecución del nodo
    * asociado. Luego asigna el valor booleano según el valor
    * de la operación not sobre el valor booleano del nodo
    * asociado.
    */
   void run ();
   /**
    * Ejecuta la operación not sobre un nodo dado
    */
   bool do_not (runNode* op);
 private:
   runNode *op_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class lthNode
 * \brief Nodo operador menor que
 *
 * Este nodo implementa la operación menor que sobre dos nodos aritmeticos.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class lthNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Si los nodos asociados no son nodos aritmeticos se produce un
    * error de tipos incorrectos.
    */
   lthNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * aritméticos asociados. Luego obtiene el valor lógico
    * del nodo mediante la operación de comparación menor que entre
    * el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación menor sobre dos nodos dados
    */
   static bool do_lth (runNode *op1, runNode *op2);

 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class leqNode
 * \brief Nodo operador menor o igual que
 *
 * Este nodo implementa la operación menor o igual que sobre dos nodos aritmeticos.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class leqNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Si los nodos asociados no son nodos aritmeticos se produce un
    * error de tipos incorrectos.
    */
   leqNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * aritméticos asociados. Luego obtiene el valor lógico
    * del nodo mediante la operación de comparación menor o igual
    * que entre el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación menor o igual sobre dos nodos dados
    */
   static bool do_leq (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class gthNode
 * \brief Nodo operador mayor que
 *
 * Este nodo implementa la operación mayor que sobre dos nodos aritmeticos.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class gthNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Si los nodos asociados no son nodos aritmeticos se produce un
    * error de tipos incorrectos.
    */
   gthNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * aritméticos asociados. Luego obtiene el valor lógico
    * del nodo mediante la operación de comparación mayor que entre
    * el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación mayor sobre dos nodos dados
    */
   static bool do_gth (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class geqNode
 * \brief Nodo operador mayor o igual que
 *
 * Este nodo implementa la operación mayor o igual que sobre dos nodos aritmeticos.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class geqNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Si los nodos asociados no son nodos aritmeticos se produce un
    * error de tipos incorrectos.
    */
   geqNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * aritméticos asociados. Luego obtiene el valor lógico
    * del nodo mediante la operación de comparación mayor o igual
    * que entre el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación mayor o igual sobre dos nodos dados
    */
   static bool do_geq (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class eqNode
 * \brief Nodo operador igual que
 *
 * Este nodo implementa la operación igual que sobre dos nodos aritmeticos.
 *
 * Realmente la operación de igualdad se realiza sobre el valor simbólico
 * de los operandos y no sobre el tipo de dato. De esta forma "2" = 2 => true
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class eqNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Si los nodos asociados no son nodos aritmeticos se produce un
    * error de tipos incorrectos.
    */
   eqNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * aritméticos asociados. Luego obtiene el valor lógico
    * del nodo mediante la operación de comparación igual
    * que entre el valor de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación igual sobre dos nodos dados
    */
   static bool do_eq (runNode *op1, runNode* op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------
/**
 * \class idenNode
 * \brief Nodo operador identico
 *
 * Este nodo implementa la operación identico.
 *
 * Esta operación, complementaria de la iguldad, compara además del valor
 * simbólico de los operandos el tipo de dato
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class idenNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Si los nodos asociados no son nodos aritmeticos se produce un
    * error de tipos incorrectos.
    */
   idenNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * aritméticos asociados. Luego obtiene el valor lógico
    * del nodo mediante la operación de comparación identico
    * ntre el valor de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación idéntico sobre dos nodos dados
    */
   static bool do_iden (runNode* op1, runNode* op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class neqNode
 * \brief Nodo operador distinto
 *
 * Este nodo implementa la operación distinto sobre dos
 * nodos.
 *
 * Para obtener el valor de la operación solo se compara el
 * valor simbólido de los operandos. Asi "2" != 2 => false
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class neqNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Si los nodos asociados no son nodos aritmeticos se produce un
    * error de tipos incorrectos.
    */
   neqNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * aritméticos asociados. Luego obtiene el valor lógico
    * del nodo mediante la operación de comparación distinto
    * que entre el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación distinto sobre dos nodos dados
    */
   static bool do_neq (runNode* op1, runNode* op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class nidenNode
 * \brief Nodo operador no identico
 *
 * Este nodo implementa la operación no idéntico sobre dos
 * nodos.
 *
 * Para determinar el valor de la operación se comparan tanto el valor simbóico
 * de los operandos como su tipo.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class nidenNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Si los nodos asociados no son nodos aritmeticos se produce un
    * error de tipos incorrectos.
    */
   nidenNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * aritméticos asociados. Luego obtiene el valor lógico
    * del nodo mediante la operación de comparación no identico
    * entre el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación no idéntico sobre dos nodos dados
    */
   static bool do_niden (runNode* op1, runNode* op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
class isNullNode : public logicNode {
 public:
   isNullNode (runNode* node) : node_ (node) {}
   void run () {
      runNode *node = node_;
      nexpNode::resolved (node)->run();
      boolvalue_ = (bool)dynamic_cast<nullNode*>(node);
   }
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
class isBoolNode : public logicNode {
 public:
   isBoolNode (runNode* node) : node_ (node) {}
   void run () {
      runNode *node = node_;
      nexpNode::resolved (node)->run();
      boolvalue_ = (bool)dynamic_cast<boolNode*>(node);
   }
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
class isStringNode : public logicNode {
 public:
   isStringNode (runNode* node) : node_ (node) {}
   void run () {
      runNode *node = node_;
      nexpNode::resolved (node)->run();
      boolvalue_ = (bool)dynamic_cast<strNode*>(node);
   }
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
class isNumNode : public logicNode {
 public:
   isNumNode (runNode* node) : node_ (node) {}
   void run () {
      runNode *node = node_;
      nexpNode::resolved (node)->run();
      boolvalue_ = (bool)dynamic_cast<numNode*>(node);
   }
 private:
   runNode *node_;
};


//----------------------------------------------------------------------
class isArrayNode : public logicNode {
 public:
   isArrayNode (runNode* node) : node_ (node) {}
   void run () {
      runNode *node = node_;
      nexpNode::resolved (node)->run();
      boolvalue_ = (bool)dynamic_cast<arrayNode*>(node) && !((bool)dynamic_cast<objectNode*>(node));
   }
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
class isObjectNode : public logicNode {
 public:
   isObjectNode (runNode* node) : node_ (node) {}
   void run () {
      runNode *node = node_;
      nexpNode::resolved (node)->run();
      boolvalue_ = (bool)dynamic_cast<objectNode*>(node);
   }
 private:
   runNode *node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class addNode
 * \brief Nodo operador suma
 *
 * Este nodo implementa la operación suma sobre dos
 * nodos.
 *
 * Si algún nodo es de tipo no aritmético o array fuerza la conversión a un tipo
 * aritmético para realizar la operación.
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class addNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos.
    *
    * Los nodos asociados pueden ser de cualquier tipo.
    */
   addNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación suma entre el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación suma sobre dos nodos dados
    */
   static num do_add (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class catNode
 * \brief Nodo operador concatenación
 *
 * Este nodo implementa la operación concatenación sobre dos
 * nodos.
 *
 * Si algún nodo es de tipo no string fuerza la conversión a un tipo
 * string para realizar la operación
 *
 * El resultado de evaluar la expresión es un valor string.
 */
class catNode :
   public stringNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos.
    *
    * Los nodos asociados pueden ser de cualquier tipo.
    */
   catNode (runNode* node1, runNode* node2, bool newline = false);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor string del nodo mediante
    * la operación concatención entre el valor textual de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación concatenación sobre dos nodos dados
    */
   static string do_cat (runNode *op1, runNode *op2, bool newline = false);
 private:
   runNode *node1_, *node2_;
   bool newline_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class sizeNode
 * \brief Nodo operador de tamaño
 *
 * Este nodo implementa la operación obtener tamaño de un elemento
 *
 * Dependiendo del tipo de nodo al que se aplique la forma en que obtiene
 * su vlor varía
 *
 * Si el nodo es un array devuelve el núnmero de elementos del mismo
 * Si el nodo es un string devuelve el número de carácteres del mismo
 * Si el nodo es númerico devuelve el número de dígitos decimales
 * Si el nodo es lógico devuelve el 1 si es verdadero 0 en caso contrario
 *
 * El resultado de evaluar la expresión es un valor numérico.
 */
class sizeNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * un nodo.
    *
    * Los nodos asociados pueden ser de cualquier tipo.
    */
   sizeNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo
    * asociado. Luego obtiene el tamaño del nodo según su tipo
    */
   void run ();
   /**
    * Ejecuta la operación tamaño sobre un nodo dado
    */
   static num do_size (runNode* node);
 private:
   runNode *node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class subNode
 * \brief Nodo operador diferencia
 *
 * Este nodo implementa la operación diferencia sobre dos
 * nodos.
 *
 * Si algún nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class subNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos .
    *
    * Los nodos asociados pueden ser de cualquirer tipo.
    */
   subNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético
    * del nodo mediante la operación diferencia entre el valor numérico
    * de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación diferencia sobre dos nodos dados
    */
   static num do_sub (runNode *op1, runNode *op2);

 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class divNode
 * \brief Nodo operador division
 *
 * Este nodo implementa la operación division sobre dos
 * nodos.
 *
 * Si algún nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class divNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Los nodos asociados pueden ser de cualquier tipo.
    */
   divNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación producto entre el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación división sobre dos nodos dados
    */
   static num do_div (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class prodNode
 * \brief Nodo operador producto
 *
 * Este nodo implementa la operación producto sobre dos
 * nodos.
 *
 * Si algún nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class prodNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Los nodos asociados pueden ser de cualquier tipo.
    */
   prodNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación producto entre el valor numérico de los dos nodos asociados.
    */
   void run ();

   /**
    * Ejecuta la operación producto sobre dos nodos dados
    */
   static num do_prod (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class powNode
 * \brief Nodo operador potencia
 *
 * Este nodo implementa la operación potencia sobre dos
 * nodos.
 *
 * Si algún nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class powNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Los nodos asociados pueden ser de cualquier tipo.
    */
   powNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación potencia entre el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación potencia sobre dos nodos dados
    */
   static num do_pow (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};

//----------------------------------------------------------------------
/**
 * \class sqrtNode
 * \brief Nodo operador raíz cuadrada
 *
 * Este nodo implementa la operación raíz cuadrada sobre un nodo.
 *
 * Si el nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class sqrtNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Los nodos asociados pueden ser de cualquier tipo.
    */
   sqrtNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación raíz cuadrada sobre el nodo numérico asociado.
    */
   void run ();
   /**
    * Ejecuta la operación raíz cuadrada sobre el nodo dado
    */
   static num do_sqrt (runNode *op);
 private:
   runNode *node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class powNode
 * \brief Nodo operador módulo
 *
 * Este nodo implementa la operación módulo sobre dos
 * nodos.
 *
 * Si algún nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class modNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * dos nodos aritmeticos.
    *
    * Los nodos asociados pueden ser de cualquier tipo.
    */
   modNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación módulo entre el valor numérico de los dos nodos asociados.
    */
   void run ();
   /**
    * Ejecuta la operación módulo sobre dos nodos dados
    */
   static num do_mod (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class incasigNode
 * \brief Nodo operador incremento y asignación
 *
 * Este nodo implementa la operación incremento y asignación. Se lleva a cabo el
 * incremento una variable, luego el nuevo resultado se utiliza como valor
 *
 * El resultado de evaluar la expresión es la expresión incrementada.
 */
class incasigNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * un nodo id.
    *
    * Si el nodo asociado no es nodo id se produce un
    * error de tipos incorrectos.
    */
   incasigNode (runNode* node1);
   /**
    * Método que ejecuta el nodo. Procede a incrementar el valor del
    * nodo id asociado guardando el resultado. Luego asocia el nuevo
    * valor del nodo id al nodo.
    */
   void run ();
 private:
   runNode *node1_;
};
//----------------------------------------------------------------------
/**
 * \class asigincNode
 * \brief Nodo operador asignación e incremento
 *
 * Este nodo implementa la operación asignación e incremento. Se toma el
 * valor de un nodo id y luego se incrementa el valor de este.
 *
 * El resultado de evaluar la expresión es el valor del nodo antes de incrementar.
 */
class asigincNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * un nodo id.
    *
    * Si el nodo asociado no es nodo id se produce un
    * error de tipos incorrectos.
    */
   asigincNode (runNode* node1);
   /**
    * Método que ejecuta el nodo. Asocia el valor del nodo id al nodo.
    * Luego procede a incrementar el valor del nodo id asociado
    * guardando el resultado.
    */
   void run ();
 private:
   runNode *node1_;
};
//----------------------------------------------------------------------
/**
 * \class decasigNode
 * \brief Nodo operador decremento y asignación
 *
 * Este nodo implementa la operación decremento y asignación. Se lleva a cabo el
 * decremento una variable, luego el nuevo resultado se utiliza como valor
 *
 * El resultado de evaluar la expresión es la expresión decrementada.
 */
class decasigNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * un nodo id.
    *
    * Si el nodo asociado no es nodo id se produce un
    * error de tipos incorrectos.
    */
   decasigNode (runNode* node1);
   /**
    * Método que ejecuta el nodo. Procede a decrementar el valor del
    * nodo id asociado guardando el resultado. Luego asocia el nuevo
    * valor del nodo id al nodo.
    */
   void run ();
 private:
   runNode *node1_;
};
//----------------------------------------------------------------------
/**
 * \class asigdecNode
 * \brief Nodo operador asignación y decremento
 *
 * Este nodo implementa la operación asignación y decremento. Se toma el
 * valor de un nodo id y luego se decrementa el valor de este.
 *
 * El resultado de evaluar la expresión es el valor del nodo antes de decrementar.
 */
class asigdecNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a
    * un nodo id.
    *
    * Si el nodo asociado no es nodo id se produce un
    * error de tipos incorrectos.
    */
   asigdecNode (runNode* node1);
   /**
    * Método que ejecuta el nodo. Asocia el valor del nodo id al nodo.
    * Luego procede a decrementar el valor del nodo id asociado
    * guardando el resultado.
    */
   void run ();
 private:
   runNode *node1_;
};
//----------------------------------------------------------------------
/**
 * \class asigNode
 * \brief Nodo asignación
 *
 * Asigna el valor del nodo2 al nodo1. Nodo1 debe ser un nodo id y nodo2
 * un nodo expresión.
 *
 * Toma el valor de nodo2 y lo copia, luego hace que la referencia de
 * a la que hace nodo1 apunte a el objeto elemento de la copia.
 * Por tanto se realiza una copia/asignación en vez de una simple asignación.
 * Esto es debido a que, en caso contrario, si el elemento node2 cambiara
 * (por ejemplo es una variable) el elemento al que se le ha asigndo también cambiará.
 * Véase un ejemplo de esto:
 *
 * a = 1;
 * b = a;
 * echo a; #imprime: 1
 * echo b; #imprime: 1
 * a = 2;
 * echo a; #imprime: 2
 * echo b; #imprime: 2 y debería ser 1
 *
 * El nodo asignación es por si mismo una expresión cuyo valor tras la ejecución
 * será el nodo recien creado y asignado. Esto hace posible que se puedan
 * procesar expresiones como estas: "a = b = 1;", "echo a = b;", "!(a = --c )", ...
 */
class asigNode :
   public nexpNode {
 public:
   /**
    * Construcutor de la clase que asocia los nodos al nodo operación
    * de asignación
    */
   asigNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Se lleva a cabo la asignación,
    * para ello se procesa el lado derecho de la asignación, se copia
    * el valor del mismo como valor interno. Luego este valor es asignado a
    * como referencia del lado izquierdo.
    *
    * Generalmente el lado izquierdo de la expresión será un identificador.
    *
    * \note Cada vez que se añada un nuevo tipo de dato se debe añadir
    * al algoritmo de ejecución.
    */
   void run ();
   void runLevel ();
   /**
    * Asigna como referencia el valor de un nodo dado al nodo del
    * lado izquierdo del operador
    */
   void setValue (runNode* node);

   runNode* getLeft () {
      return node1_;
   }
   runNode* getRight () {
      return node2_;
   }
   bool is_runlist () const {
      return true;
   }
 private:
   bool isRefNode (runNode* node);
   vector<nexpNode*> nexp_;
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------
/**
 * \class asigrefNode
 * \brief Nodo asignación
 *
 * Asigna una referencia del nodo2 desde el nodo1. Nodo1 debe ser un nodo de tipo no defindo puro y nodo2
 * otro.
 *
 * Obtiene el valor de nodo2, luego hace que la referencia de
 * nodo1 sea hacia el elemento valor de node2.
 *
 * AL contrario q de la operación asignación esta operación no realiza una copia del
 * elemento de nodo2 sino que utiliza directamente al elemento para la asignación.
 *
 * Gracias a esto es posible crear una referencia a un elemento de la tabla de símbolos
 * Véase un ejemplo de esto:
 *
 * a = 1;
 * b = &a;
 * echo a; #imprime: 1
 * echo b; #imprime: 1
 * a = 2;
 * echo a; #imprime: 2
 * echo b; #imprime: 2
 *
 * Debido la aignacción de referencia es importante que cuando se reasigna un
 * elemento de la tabla símbolo a un nuevo nodo creado dinámicamente se reasigne
 * también todos los elementos de la tabla que hacian referencia al mismo nodo.
 *
 * El nodo asignación es por si mismo una expresión cuyo valor tras la ejecución
 * será el nodo recien asignado. Esto hace posible que se puedan
 * procesar expresiones como estas: "a = b = 1;", "echo a = b;", "!(a = --c )", ...
 */
class asigrefNode :
   public nexpNode {
 public:
   /**
    * Construcutor de la clase que asocia los nodos al nodo operación
    * de asignación de referencia
    */
   asigrefNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Se lleva a cabo la asignación,
    * para ello se procesa el lado derecho de la asignación, se obtiene
    * el valor del mismo como valor interno. Luego este valor es asignado
    * como referencia del lado izquierdo.
    *
    * Generalmente el lado izquierdo de la expresión será un identificador.
    *
    */
   void run ();
   /**
    * Asigna como referencia el valor de un nodo dado al nodo del
    * lado izquierdo del operador
    */
   void setValue (runNode* node);
 private:
   runNode *node1_, *node2_;
};
//----------------------------------------------------------------------
class getRefNode :
   public nexpNode {
 public:

   getRefNode (runNode* node);

   void run ();

 private:
   runNode *node_;
};
//----------------------------------------------------------------------
/**
 * \class intconvNode
 * \brief Node de conversión a entero
 *
 * Este nodo fuerza la conversion a entero del valor de un nodo
 *
 * Si el nodo es booleano toma el valor de 0 ó 1
 * Si el nodo es aritmético toma el valor entero del nodo
 * Si el nodo es cadena de texto tomo el valor entero significativo
 * de la cadena, en el caso de ser numérico. En caso contario toma el tamaño
 * de la cadena.
 * Si el nodo es array toma el numéro de elementos del mismo
 *
 */
class intconvNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase
    */
   intconvNode (runNode* node);
   /**
    * Fuerza la conversión a entero
    */
   void run ();
   /**
    * Convierte un nodo a su valor entero
    */
   static int do_intconv (runNode *node);
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
/**
 * \class floatconvNode
 * \brief Node de conversión a flotante
 *
 * Este nodo fuerza la conversion a flotante del valor de un nodo
 *
 * Si el nodo es booleano toma el valor de 0 ó 1
 * Si el nodo es aritmético toma el valor flotante del nodo
 * Si el nodo es cadena de texto tomo el valor flotante significativo
 * de la cadena, en el caso de ser numérico. En caso contario toma el tamaño
 * de la cadena.
 * Si el nodo es array toma el numéro de elementos del mismo
 *
 */
class floatconvNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase
    */
   floatconvNode (runNode* node);
   /**
    * Fuerza la conversión a flotante
    */
   void run ();
   /**
    * Convierte un nodo a su valor flotante
    */
   static num do_floatconv (runNode *node);
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
class strconvNode :
   public stringNode {
 public:
   strconvNode (runNode* node);
   void run ();
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
/**
 * \class boolconvNode
 * \brief Node de conversión a booleano
 *
 * Este nodo fuerza la conversion a flotante del valor de un nodo
 *
 * Si el nodo es booleano toma su propio valor
 * Si el nodo es aritmético toma el valor booleano del nodo
 * Si el nodo es cadena de texto toma verdadero si la cadena no es vacia
 * Si el nodo es array toma verdadero si el array no está vacio
 *
 */
class boolconvNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase
    */
   boolconvNode (runNode* node);
   /**
    * Fuerza la conversión a booleano
    */
   void run ();
   /**
    * Convierte un nodo a su valor flotante
    */
   static num do_boolconv (runNode *node);
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
/**
 * \class getNode_endValue
 * \brief Nodo final de array
 *
 * Realmente define a un pseudo tipo de dato ya que no guarda ningun valor real,
 * sino más bien una referencia al final de un array
 *
 * Gracias a este tipo de dato referencia es posible acceder
 * al último lugar de un array con expresiones como esta "a[] = 2"
 *
 * Este tipo de objeto es utilizado por la gramática y el operador de
 * acceso para obtener una referencia al final de un array, entendiéndose por
 * este a la sigueinte posición del último elemento del array. Como este elemento aun no se ha
 * creado se crea un nodo string con valor vacio. Así en la sentencia "a[] = 2" como última posición
 * de "a" se creará un nuevo nodo string con valor vacio que luego será sustituido por un nodo numérico de
 * valor 2. Esta creación intermedia del nodo string hace posible que se utilice la referencia al
 * final de un array sin el operador asignación "a[] + 3"
 */
class getNode_endValue:
   public runNode {
 public:
   /**
    * Este tipo no tiene ejecución ya que solo vale como referencia
    * para otros nodos
    */
   void run () {}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class getNode_strInterface
 * \brief Node interfaz de acceso a string
 *
 * Este nodo crea una referncia a una posición determina de un string
 * Es utilizado por el operador de acceso para obtener carácteres especificos de
 * una cadena de texto.
 */
class getNode_strInterface:
   public nexpNode {
 public:
   /**
    * Constructor de la clase
    */
   getNode_strInterface (stringNode* node, bool is_const = false);
   /**
    * Modifica el valor de la referencia
    */
   void noderef (runNode* node);
   /**
    * Obtiene el valor al qe se hace referencia
    */
   runNode* nodeval () const;
   /**
    * Obtien la psoición de la cadena a la que
    * se va ha acceder
    */
   int getn () const {
      return refn_;
   }
   /**
    * Establece la posición de la cadena a la que
    * se va a acceder
    */
   void setn ( int n);
   /**
    * Accede a la posición de la cadena creando un nuevo
    * nodo string con dicho valor
    */
   void run ();
 private:
   string* strref_;
   runNode* str_;
   int refn_;
   bool is_const_;
};
//----------------------------------------------------------------------

//---------------------------------------------------------------------
/**
 * \class getNode
 * \brief Nodo de acceso
 *
 * Obtienen una referencia a un nodo concreto dentro de tipos compuestos
 * Se considernan nodos de tipos compuestos los siguientes elementos:
 *
 * - cadenas
 * - arrays
 *
 * Este nodo opera sobre un nodo de tipo compuesto y una lista de claves.
 * La ejecución conciste en obtener una referencia a un elemento concreto
 * del nodo compuesto.
 *
 * Según el tipo de nodo compuesto el acceso se realiza de una forma determinada.
 *
 * En el caso de los array el acceso se hace en multiples niveles donde la
 * lista de claves determina a que elemento acceder en cada nivel. Si el elemento
 * de un determinado nivel no existe crea un nuevo elemento que, será un nuevo array
 * vacio, en el caso de que el nivel sea intermedio, o un string vacio en el caso de
 * que el nivel de acceso sea final.
 *
 * Es posible acceder al final del array usandose una clave de tipo getNode_endValue
 * en la lista lista de claves
 *
 * En los string el acceso se hace en un solo nivel por lo que la lista de claves solo deberá
 * contener un valor, en caso contrario los demás valores se desecharán. Para acceder a un determinado
 * caracter dentro de un nodo string se obtiene una referencia al string interno del nodo mediante
 * la clase getNode_strInterface. Esta clase se encarga de interactuar con el string obtenido y modificando
 * el valor de la posición.
 */
class getNode:
   public nexpNode {
 public:
   getNode (runNode* array, runNode* key, bool resolv = true);
   void run ();
   void noderef (runNode* node);
   void setFunctionCall ();
   bool getFunctionCall ();
   runNode* getKey ();
 private:
   void run_case_array (arrayNode* array, runNode* key);
   void run_case_str (strNode* str, runNode* num);
   void setNodeValue (arrayNode *array, runNode * key);
   void setDefaultValue (symbols *map, runNode * key);
   refNode * noderefAnidate ();
   runNode * array_, *key_;
   short unsigned int type_;
   bool exec_, is_this_node_, resolv_, is_const_, functioncall_;
   getNode *next_;
};
//---------------------------------------------------------------------
/**
 * \class emptyNode
 * \brief Node operador elemento vacío
 *
 * Este nodo determina si un elemento es vacío. Trabaja sobre diversos tipos de datos.
 *
 * Si el elemento es booleano toma el valor de la negación, si es númerico
 * toma true si el elemento es 0 y false en caso contrario. Para una cadena de texto
 * toma true si la cadena es la cadena vacía, false en otro caso.
 * Si se trata de una array toma el valor verdadero si este está vacio.
 */
class emptyNode : public logicNode {
 public:
   emptyNode (runNode* elem);
   void run ();
 private:
   runNode *elem_;

};
//----------------------------------------------------------------------
/**
 * \class ternNode
 * \brief Node operador ternario
 *
 */
class ternNode : public nexpNode {
 public:
   ternNode (runNode* cond, runNode* yes, runNode* no);
   void run ();
 private:
   runNode *cond_;
   runNode *yes_;
   runNode *no_;
};
//----------------------------------------------------------------------
/**
 * \class getiNode
 * \brief Node operador acceso a iterador
 *
 */
class getiNode : public nexpNode {
 public:
   getiNode (runNode *node = NULL);
   void run ();
 private:
   runNode* node_;
};
//----------------------------------------------------------------------
/**
 * \class notnullNode
 * \brief Node operador no nulo
 *
 */
class notnullNode : public nexpNode {
 public:
   notnullNode (runNode* list);
   void run ();
 private:
   runNode	 *list_;
};
//----------------------------------------------------------------------
/**
 * \class execNode
 * \brief Node operador ejecución
 *
 */
class execNode : public stringNode {
 public:
   execNode (runNode* node);
   void run ();
 private:
   runNode	 *node_;
};
//----------------------------------------------------------------------
/**
 * \class evalNode
 * \brief Node operador evaluación
 *
 */
class evalNode : public nexpNode {
 public:
   evalNode (runNode* node);
   void run ();
 private:
   runNode	 *node_;
};
//----------------------------------------------------------------------
/**
 * \class getEnvNode
 * \brief Node operador acceso a variable de entorno
 *
 */
class getEnvNode : public stringNode {
 public:
   getEnvNode (runNode* node);
   void run ();
 private:
   runNode	 *node_;
};
//----------------------------------------------------------------------
/**
 * \class reduceNode
 * \brief Nodo operador reduccion de array
 *
 */
class reduceNode : public nexpNode {
 public:
   reduceNode (runNode* elem, runNode* func);
   void run ();
   static runNode* asMethod ();
 private:
   runNode *elem_, *func_;
};
//----------------------------------------------------------------------
/**
 * \class getclassNode
 * \brief Nodo operador obtener clase
 *
 */
class getclassNode : public stringNode {
 public:
   getclassNode (runNode* node);
   void run ();
 private:
   runNode *node_;
};
//----------------------------------------------------------------------
#endif


