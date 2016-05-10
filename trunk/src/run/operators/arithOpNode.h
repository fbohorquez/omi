//arithOpNode.h
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
 * \file arithOpNode.h
 * \brief Nodos operadores aritméticos.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores aritméticos. Estos son modelados mediante clases de 
 * objetos. 
*/

#ifndef _RUN_OPERATORS_ARITHOPNODE_
#define _RUN_OPERATORS_ARITHOPNODE_

#include "../tree/typeNode.h"

//-------------------------------------------------------------------------------------------

/**
 * \class addNode
 * \brief Nodo operador suma.
 *
 * Este nodo implementa la operación suma sobre dos nodos asociados.
 *
 * Si algún nodo es de tipo no aritmético  fuerza la conversión a un tipo
 * aritmético para realizar la operación.
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class addNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Segundo nodo operando.
    */
   addNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación suma entre el valor numérico de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación suma sobre dos nodos dados
    * \param op1 Primer nodo operando.
    * \param op2 Segundo nodo operando.
    * \return Valor de la operación.    
    */
   static num do_add (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class subNode
 * \brief Nodo operador diferencia.
 *
 * Este nodo implementa la operación diferencia sobre dos nodos asociados.
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
    * Constructor de la clase. Asocia el nodo operador a dos nodos .
    * \param node1 Primer nodo operando.
    * \param node2 Segundo nodo operando.
    */
   subNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante la 
    * operación diferencia entre el valor numérico de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación diferencia sobre dos nodos dados.
    * \param op1 Primer nodo operando.
    * \param op2 Segundo nodo operando.
    * \return Valor de la operación.     
    */
   static num do_sub (runNode *op1, runNode *op2);

 private:
   runNode *node1_, *node2_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class prodNode
 * \brief Nodo operador producto.
 *
 * Este nodo implementa la operación producto sobre dos nodos asociados.
 *
 * Si algún nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación.
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class prodNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos aritméticos.
    * \param node1 Primer nodo operando.
    * \param node2 Segundo nodo operando.
    */
   prodNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación producto entre el valor numérico de los dos nodos.
    */
   void run ();

   /**
    * Ejecuta la operación producto sobre dos nodos dados.
    * \param op1 Primer nodo operando.
    * \param op2 Segundo nodo operando.
    * \return Valor de la operación.  
    */
   static num do_prod (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class divNode
 * \brief Nodo operador división.
 *
 * Este nodo implementa la operación división sobre dos nodos asociados.
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
    * Constructor de la clase. Asocia el nodo operador a dos nodos aritméticos.
    * \param node1 Primer nodo operando.
    * \param node2 Segundo nodo operando.
    */
   divNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación producto entre el valor numérico de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación división sobre dos nodos dados.
    * \param op1 Primer nodo operando.
    * \param op2 Segundo nodo operando.
    * \return Valor de la operación.       
    */
   static num do_div (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class powNode
 * \brief Nodo operador potencia.
 *
 * Este nodo implementa la operación potencia sobre dos nodos asociados.
 *
 * Si algún nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación.
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class powNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos aritméticos.
    * \param node1 Primer nodo operando.
    * \param node2 Segundo nodo operando.
    */
   powNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación potencia entre el valor numérico de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación potencia sobre dos nodos dados.
    * \param op1 Primer nodo operando.
    * \param op2 Segundo nodo operando.
    * \return Valor de la operación.       
    */
   static num do_pow (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class sqrtNode
 * \brief Nodo operador raíz cuadrada.
 *
 * Este nodo implementa la operación raíz cuadrada sobre un nodo asociado.
 *
 * Si el nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación.
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class sqrtNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */
   sqrtNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo asociado. 
    * Luego obtiene el valor aritmético del nodo mediante
    * la operación raíz cuadrada sobre el nodo numérico.
    */
   void run ();
   /**
    * Ejecuta la operación raíz cuadrada sobre el nodo dado.
    */
   static num do_sqrt (runNode *op);
 private:
   runNode *node_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class modNode
 * \brief Nodo operador módulo.
 *
 * Este nodo implementa la operación módulo sobre dos nodos asociados.
 *
 * Si algún nodo es de tipo no aritmético fuerza la conversión a un tipo
 * aritmético para realizar la operación.
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class modNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos aritméticos.
    * \param node1 Primer nodo operando.
    * \param node2 Segundo nodo operando.
    */
   modNode (runNode* node1, runNode* node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor aritmético del nodo mediante
    * la operación módulo entre el valor numérico de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación módulo sobre dos nodos dados.
    * \param op1 Primer nodo operando.
    * \param op2 Segundo nodo operando.
    * \return Valor de la operación.    
    */
   static num do_mod (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class incasigNode
 * \brief Nodo operador incremento y asignación.
 *
 * Este nodo implementa la operación incremento y asignación. Se lleva a cabo el
 * incremento del nodo asociado, luego el nuevo resultado se utiliza como valor
 * del operador.
 *
 * El resultado de evaluar la expresión es un valor aritmético correspondiente
 * al incremento.
 */
class incasigNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */
   incasigNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Procede a incrementar el valor del
    * nodo operando. Luego asocia el resultado del incremento como
    * valor interno del operador.
    */
   void run ();
 private:
   runNode *node_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class asigincNode
 * \brief Nodo operador asignación e incremento.
 *
 * Este nodo implementa la operación asignación e incremento. Se toma el
 * valor de el nodo asociado, que normalmente representará un símbolo 
 * variable,  luego se incrementa el valor de este.
 *
 * El resultado de evaluar la expresión es el valor antes de incrementar.
 */
class asigincNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
   * \param node Nodo operando.
   */
   asigincNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Asocia el valor del nodo operando
    * como valor interno del operador.
    * Luego procede a incrementar el valor del nodo asociado.
    */
   void run ();
 private:
   runNode *node_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class decasigNode
 * \brief Nodo operador decremento y asignación.
 *
 * Este nodo implementa la operación decremento y asignación. Se lleva a cabo el
 * decremento del nodo asociado, luego el nuevo resultado se utiliza como valor
 * del operador.
 *
 * El resultado de evaluar la expresión es un valor aritmético correspondiente
 * al decremento.
 */
class decasigNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */
   decasigNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Procede a decrementar el valor del
    * nodo operando. Luego asocia el resultado del decremento como
    * valor interno del operador.
    */
   void run ();
 private:
   runNode *node_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class asigdecNode
 * \brief Nodo operador asignación y decremento.
 *
 * Este nodo implementa la operación asignación y decremento. Se toma el
 * valor de el nodo asociado, que normalmente representará un símbolo 
 * variable,  luego se decrementa el valor de este.
 *
 * El resultado de evaluar la expresión es el valor antes de decrementar.
 */
class asigdecNode :
   public arithNode {
 public:
   /**
   * Constructor de la clase. Asocia el nodo operador a un nodo.
   * \param node Nodo operando.
    */
   asigdecNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Asocia el valor del nodo operando
    * como valor interno del operador.
    * Luego procede a decrementar el valor del nodo asociado.
    */
   void run ();
 private:
   runNode *node_;
};

//------------------------------------------------------------------------------------------------------

/**
 * \class sizeNode
 * \brief Nodo operador de tamaño.
 *
 * Este nodo implementa la operación obtener tamaño de un elemento.
 *
 * Dependiendo del tipo de nodo al que se aplique la forma en que obtiene
 * su valor varía.
 *
 * Si el nodo es un array devuelve el número de elementos del mismo.
 * Si el nodo es un cadena de caracteres devuelve el número de caracteres 
 * del mismo.
 * Si el nodo es numérico devuelve el número de dígitos decimales.
 * Si el nodo es lógico devuelve 1 si es verdadero ó 0 en caso contrario.
 *
 * El resultado de evaluar la expresión es un valor aritmético.
 */
class sizeNode :
   public arithNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */
   sizeNode (runNode* node);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo
    * asociado. Luego obtiene el tamaño del nodo según su tipo.
    */
   void run ();
   /**
    * Ejecuta la operación tamaño sobre un nodo dado.
    * \param node Nodo operando..
    * \return Valor de la operación.  .  
    */
   static num do_size (runNode* node);
 private:
   runNode *node_;
};

#endif
//-------------------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
