//logicOpNode.h
//-------------------------------------------------------------------------------------------
/*
 * Fco. Javier Bohórquez Ogalla
 * 75766599-E
 * Puerto Real (Cádiz)
 * powersgame@gmail.com
 */
//-------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------
/**
 * \file logicOpNode.h
 * \brief Nodos operadores lógicos.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores lógicos. Estos son modelados mediante clases de 
 * objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_OPERATORS_LOGICOPNODE_
#define _RUN_OPERATORS_LOGICOPNODE_

#include "../tree/typeNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class orNode
 * \brief Nodo operador OR
 *
 * Este nodo implementa una operación lógica OR entre dos nodos asociados.
 * 
 * Para llevar a cabo la operación lógica OR se realiza una evaluación
 * en cortocircuito, donde el valor del nodo OR es el último valor evaluado.
 *
 */
class orNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase. Asocia los nodos operandos.
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    */
   orNode (runNode* op1, runNode* op2);
   /**
    * Función de ejecución. Procede a la ejecución de los nodos
    * asociados. Toma como valor una referencia al último nodo evaluado
    * según la operación OR.
    */
   void run ();
   /**
    * Ejecuta la operación OR entre dos nodos dados.
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación
    */
   bool do_or (runNode* op1, runNode* op2);
 private:
   runNode *op1_, *op2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class andNode
 * \brief Nodo operador AND
 *
 * Este nodo implementa una operación lógica AND entre dos nodos asociados.
 * 
 * Para llevar a cabo la operación lógica AND se realiza una evaluación
 * en cortocircuito, donde el valor del nodo AND es el último valor evaluado.
 */
class andNode :
   public nexpNode {
 public:
   /**
    * Constructor de la clase. Asocia los nodos operandos.
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    */
   andNode (runNode* op1, runNode* op2);
   /**
    * Función de ejecución. Procede a la ejecución de los nodos asociados. 
    * Toma como valor una referencia al último nodo evaluado según la 
    * operación AND.
    */
   void run ();
   /**
    * Ejecuta la operación AND entre dos nodos dados
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación
    */
   bool do_and (runNode* op1, runNode* op2);
 private:
   runNode *op1_, *op2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class notNode
 * \brief Nodo operador NOT
 *
 * Este nodo implementa una operación lógica NOT aplicada a un nodo.
 *
 * Un nodo operador NOT es un nodo lógico ya que tiene un valor interno 
 * de tipo booleano, obtenido a partir de llevar a cabo la operación NOT 
 * sobre el nodo asociado.
 */
class notNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operando.
    * \param op Nodo operando.
    */
   notNode (runNode* op);
   /**
    * Función de ejecución. Procede a la ejecución del nodo asociado. 
    * Luego asigna el valor booleano según  la operación NOT.
    */
   void run ();
   /**
    * Ejecuta la operación NOT sobre un nodo dado.
    * \param op Nodo operando.
    * \return Valor de la operación
    */
   bool do_not (runNode* op);
 private:
   runNode *op_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class lthNode
 * \brief Nodo operador menor que
 *
 * Este nodo implementa la operación menor que sobre dos nodos asociados.
 *
 *  El resultado de evaluar la expresión es un valor booleano.
 */
class lthNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Sengundo nodo operando.
    * 
    */
   lthNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor lógico del nodo mediante la 
    * operación de comparación menor que entre el valor numérico de los 
    * dos nodos .
    */
   void run ();
   /**
    * Ejecuta la operación menor sobre dos nodos dados
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación
    */
   static bool do_lth (runNode *op1, runNode *op2);

 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class leqNode
 * \brief Nodo operador menor o igual que
 *
 * Este nodo implementa la operación menor o igual que sobre dos nodos 
 * asociados.
 * 
 * El resultado de evaluar la expresión es un valor booleano.
 */
class leqNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Sengundo nodo operando.
    */
   leqNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor lógico del nodo mediante la 
    * operación de comparación menor o igual que entre el valor numérico 
    * de los dos nodos .
    */
   void run ();
   /**
    * Ejecuta la operación menor o igual que sobre dos nodos dados.
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación
    */
   static bool do_leq (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class gthNode
 * \brief Nodo operador mayor que
 *
 * Este nodo implementa la operación mayor que sobre dos nodos asociados.
 * 
 * El resultado de evaluar la expresión es un valor booleano.
 */
class gthNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Sengundo nodo operando.
    */
   gthNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor lógico del nodo mediante la 
    * operación de comparación mayor que entre el valor numérico 
    * de los dos nodos .
    */
   void run ();
   /**
    * Ejecuta la operación mayor que sobre dos nodos dados.
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación
    */
   static bool do_gth (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class geqNode
 * \brief Nodo operador mayor o igual que
 *
 * Este nodo implementa la operación mayor o igual que sobre dos nodos
 * asociados.
 * 
 * El resultado de evaluar la expresión es un valor booleano.
 */
class geqNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Sengundo nodo operando.
    */
   geqNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor lógico del nodo mediante la 
    * operación de comparación mayor o igual que entre el valor numérico 
    * de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación mayor o igual que sobre dos nodos dados
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación    
    */
   static bool do_geq (runNode *op1, runNode *op2);
 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class eqNode
 * \brief Nodo operador igual que
 *
 * Este nodo implementa la operación igual que sobre dos nodos asociados.
 *
 * Realmente la operación de igualdad se realiza sobre el valor simbólico
 * de los operandos y no sobre el tipo de dato. De esta forma "2" == 2
 * es verdadero.
 * 
 * El resultado de evaluar la expresión es un valor booleano.
 */
class eqNode :
   public logicNode {
 public:
   /**
   * Constructor de la clase. Asocia el nodo operador a dos nodos.
   * \param node1 Primer nodo operando.
   * \param node2 Sengundo nodo operando.
   */
   eqNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor lógico del nodo mediante la 
    * operación de comparación  igual que entre el valor numérico 
    * de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación igual que sobre dos nodos dados
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación    
    */
   static bool do_eq (runNode *op1, runNode* op2);
 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class idenNode
 * \brief Nodo operador identico
 *
 * Este nodo implementa la operación idéntico entre dos nodos asociados.
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
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Sengundo nodo operando.
    */
   idenNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor lógico del nodo mediante la 
    * operación de comparación  idéntico entre el valor numérico 
    * de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación idéntico sobre dos nodos dados
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación.  
    */
   static bool do_iden (runNode* op1, runNode* op2);
 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class neqNode
 * \brief Nodo operador distinto
 *
 * Este nodo implementa la operación distinto sobre dos nodos asociados.
 *
 * Para obtener el valor de la operación solo se compara el
 * valor simbólido de los operandos. Así "2" != 2 es falso.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class neqNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Sengundo nodo operando.
    */
   neqNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor lógico del nodo mediante la 
    * operación de comparación distinto entre el valor numérico 
    * de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación distinto sobre dos nodos dados
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación. 
    */
   static bool do_neq (runNode* op1, runNode* op2);
 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class nidenNode
 * \brief Nodo operador no identico.
 *
 * Este nodo implementa la operación no idéntico sobre dos nodos asociados.
 *
 * Para determinar el valor de la operación se comparan tanto el valor
 * simbóico de los operandos como su tipo.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class nidenNode :
   public logicNode {
 public:
   /**
    * Constructor de la clase. Asocia el nodo operador a dos nodos.
    * \param node1 Primer nodo operando.
    * \param node2 Sengundo nodo operando.
    */
   nidenNode (runNode* node1, runNode*node2);
   /**
    * Método que ejecuta el nodo. Procede a la ejecución de los nodos
    * asociados. Luego obtiene el valor lógico del nodo mediante la 
    * operación de comparación no identico entre el valor numérico 
    * de los dos nodos.
    */
   void run ();
   /**
    * Ejecuta la operación no idéntico sobre dos nodos dados
    * \param op1 Primer nodo operando.
    * \param op2 Sengundo nodo operando.
    * \return Valor de la operación .
    */
   static bool do_niden (runNode* op1, runNode* op2);
 private:
   runNode *node1_, *node2_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class isNullNode
 * \brief Nodo operador de  comprobación de nulo.
 *
 * Este nodo implementa la operación de comprobación de tipo para el caso nulo.
 *
 * Para determinar el valor de la operación se comprueba si el valor del 
 * operando es de tipo nulo.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */
class isNullNode : 
   public logicNode {
 public:
    /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */  
   isNullNode (runNode* node);
    /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo asociado. 
    * Comprueba si el tipo del nodo asociado es nulo para tomar el valor 
    * lógico correspondiente.
    */  
   void run ();
 private:
   runNode *node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class isBoolNode
 * \brief Nodo operador comprobación de booleano.
 *
 * Este nodo implementa la operación de comprobación del tipo para el caso
 * booleano.
 *
 * Para determinar el valor de la operación se comprueba si el valor del 
 * operando es de tipo nulo.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */  
class isBoolNode : public logicNode {
 public:
    /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */  
   isBoolNode (runNode* node);
   void run ();
     /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo asociado. 
    * Comprueba si el tipo del nodo asociado es booleano para tomar el valor 
    * lógico correspondiente.
    */    
 private:
   runNode *node_;
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class isStringNode
 * \brief Nodo operador comprobación de cadena de caracteres.
 *
 * Este nodo implementa la operación de comprobación del tipo para el caso
 * cadena de caracteres.
 *
 * Para determinar el valor de la operación se comprueba si el valor del 
 * operando es de tipo cadena de caracteres.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */  
class isStringNode : public logicNode {
 public:
    /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */  
   isStringNode (runNode* node);
    /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo asociado. 
    * Comprueba si el tipo del nodo asociado es cadena de caracteres
    * para tomar el valor lógico correspondiente.
    */     
   void run ();
 private:
   runNode *node_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class isNumNode
 * \brief Nodo operador comprobación de numérico.
 *
 * Este nodo implementa la operación de comprobación del tipo para el caso
 * numérico.
 *
 * Para determinar el valor de la operación se comprueba si el valor del 
 * operando es de tipo numérico.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */  
class isNumNode : public logicNode {
 public:
    /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */   
   isNumNode (runNode* node);
     /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo asociado. 
    * Comprueba si el tipo del nodo asociado es numérico para tomar el
    * valor lógico correspondiente.
    */    
   void run ();
 private:
   runNode *node_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class isArrayNode
 * \brief Nodo operador comprobación de array.
 *
 * Este nodo implementa la operación de comprobación del tipo para el caso
 * array.
 *
 * Para determinar el valor de la operación se comprueba si el valor del 
 * operando es de tipo array.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */  
class isArrayNode : public logicNode {
 public:
     /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */ 
   isArrayNode (runNode* node);
    /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo asociado. 
    * Comprueba si el tipo del nodo asociado es array para tomar el
    * valor lógico correspondiente.
    */    
   void run ();
 private:
   runNode *node_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class isObjectNode
 * \brief Nodo operador comprobación de objeto.
 *
 * Este nodo implementa la operación de comprobación del tipo para el caso
 * objeto.
 *
 * Para determinar el valor de la operación se comprueba si el valor del 
 * operando es de tipo objeto.
 *
 * El resultado de evaluar la expresión es un valor booleano.
 */  
class isObjectNode : public logicNode {
 public:
    /**
    * Constructor de la clase. Asocia el nodo operador a un nodo.
    * \param node Nodo operando.
    */  
   isObjectNode (runNode* node);
    /**
    * Método que ejecuta el nodo. Procede a la ejecución del nodo asociado. 
    * Comprueba si el tipo del nodo asociado es objeto para tomar el
    * valor lógico correspondiente.
    */      
   void run ();
 private:
   runNode *node_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
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
   /**
   * Constructor de la clase. Asocia el nodo operador a un nodo.
   * \param elem Nodo operando.
   */   
   emptyNode (runNode* elem);
   /**
   * Método que ejecuta el nodo. Procede a la ejecución del nodo asociado. 
   * y toma como valor un booleano que indica si este representa un elemento vacio.
   */       
   void run ();
 private:
   runNode *elem_;
};
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
