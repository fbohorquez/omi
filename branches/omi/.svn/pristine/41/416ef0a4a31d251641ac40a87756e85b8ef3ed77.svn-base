//dateOpNode.h
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
 * \file dateOpNode.h
 * \brief Nodos operadores y funciones sobre fechas.
 * 
 * En este fichero se encuentran los nodos ejecutables correspondientes 
 * a los operadores y funciones aplicables a datos que representen fechas.
 * Estos son modelados mediante clases de objetos. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#ifndef _RUN_OPERATORS_DATEOPNODE_
#define _RUN_OPERATORS_DATEOPNODE_

#include "../tree/typeNode.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/**
 * \class dateNode
 * \brief Nodo operador 
 *
 */
class dateNode : public stringNode {
 public:
   dateNode (runNode * str, runNode * timestamp = NULL);
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class timeNode
 * \brief Nodo operador de tiempo
 *
 */
class timeNode : public arithNode {
 public:
   timeNode ();
   void run ();
 private:
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class sleepNode
 * \brief Nodo operador de 
 *
 */class sleepNode : public runNode {
 public:
   sleepNode (runNode * s);
   void run ();
 private:
   runNode* s_;
};

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
