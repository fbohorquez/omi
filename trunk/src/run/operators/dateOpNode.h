//dateOpNode.h
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
 * \file dateOpNode.h
 * \brief Nodos operadores y funciones sobre fechas.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores y funciones aplicables a datos que representen fechas.
 * Estos son modelados mediante clases de objetos. 
*/

#ifndef _RUN_OPERATORS_DATEOPNODE_
#define _RUN_OPERATORS_DATEOPNODE_

#include "../tree/typeNode.h"

//-------------------------------------------------------------------------------------------

/**
 * \class dateNode
 * \brief Nodo función fecha. 
 * 
 * Este nodo genera una cadena que se corresponde a una fecha dada 
 * según un formato y una marca de tiempo. 
 *  
 * Para la cadena de formato se utiliza las siguientes directivas:
 *    - %d: Día del mes con dos dígitos.
 *    - %j: Día del mes sin ceros iniciales.
 *    - %l: Día de la semana de forma alfabética completa.
 *    - %D: Día de la semana de forma alfabética y con tres letras.
 *    - %w: Día de la semana de forma numérica (0-domingo,6-sábado).
 *    - %z: Día del año de forma numérica.
 *    - %F: Mes de forma alfabética.
 *    - %m: Mes de forma numérica con dos dígitos.
 *    - %n: Mes de forma numérica sin ceros iniciales.
 *    - %M: Mes de forma alfabética con tres letras.
 *    - %Y: Año con cuatro dígitos.
 *    - %y: Año con dos dígitos.
 *    - %a: Periodo del día (am/pm) en minúsculas.
 *    - %A: Periodo del día (am/pm) en mayúsculas.
 *    - %g: Hora en formato 12h sin ceros iniciales.
 *    - %G: Hora en formato 24h sin ceros iniciales.
 *    - %h: Hora en formato 12h con dos dígitos.
 *    - %H: Hora en formato 24h con dos dígitos.
 *    - %i: Minutos con dos dígitos.
 *    - %U: Segundos desde la Época Unix (1 de Enero del 1970 00:00:00 GMT).
 *    - %%: Carácter %.
 *
 */
class dateNode : public stringNode {
 public:
   /**
    * Constructor de la clase. 
    * \param str Nodo que representa la cadena de formato.
    * \param timestamp Nodo que representa la marca de tiempo. 
    * Si no se da se toma la marca de tiempo actual.
    */
   dateNode (runNode * str, runNode * timestamp = NULL);
   /**
    * Método que lleva a cabo la ejecución del nodo. Toma como valor 
    * una cadena determinada por la cadena de formato y la marca de tiempo.
    */
   void run ();
 private:
   runNode *str_, *timestamp_;
   string run_day (tm *ltm);
   string run_week3 (tm *ltm);
   string run_day_zero (tm *ltm);
   string run_week (tm *ltm);
   string run_week_num (tm *ltm);
   string run_day_year (tm *ltm);
   string run_month_str (tm *ltm);
   string run_month_num (tm *ltm);
   string run_month3_str (tm *ltm);
   string run_month_num_zero (tm *ltm);
   string run_year (tm *ltm);
   string run_year2 (tm *ltm);
   string run_am (tm *ltm);
   string run_AM (tm *ltm);
   string run_hour_12_zero (tm *ltm);
   string run_hour_24_zero (tm *ltm);
   string run_hour_12 (tm *ltm);
   string run_hour_24 (tm *ltm);
   string run_minute (tm *ltm);
   string run_second (tm *ltm);
   string run_unixtime (time_t now);
};

//-------------------------------------------------------------------------------------------

/**
 * \class timeNode
 * \brief Nodo función obtener marca de tiempo.
 * 
 * Obtiene la marca de tiempo actual.
 *
 */
class timeNode : public arithNode {
 public:
 /**
  * Constructor de la clase
  */
   timeNode ();
   /**
    * Método que ejecuta el nodo. Toma como valor el aritmético 
    * correspondiente a la marca de tiempo Unix actual.
    */
   void run ();
 private:
};

//-------------------------------------------------------------------------------------------

/**
 * \class sleepNode
 * \brief Nodo función de espera la ejecución.
 * 
 * Hace que la ejecución del programa se pare un número determinado de segundos.
 *
 */class sleepNode : public runNode {
 public:
   /**
    * Constructor de la clase
    * \param s Nodo que representa el número de segundos que se esperará.
    */
   sleepNode (runNode * s);
   /**
    * Método que ejecuta el nodo.  Para la ejecución del programa un 
    * número dado de segundos. 
    */
   void run ();
 private:
   runNode* s_;
};

#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
