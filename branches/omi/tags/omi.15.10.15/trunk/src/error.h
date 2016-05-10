//error.h
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
#ifndef _ERROR_
#define _ERROR_
#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <queue>
#include "run/numData.h"
#include "run/stmtNode.h"
#include "lshParser.h"
#define ERROR 0
#define ERROR_DATA 1
#define ERROR_PARAMS 2
extern string infile;
extern bool inline_param;
extern int yyerror(const char *s);

using namespace std;
class errorException :
   public std::exception {
 public:
   errorException (string msg = "", string dev = "", int code = 0, int exit = 0): code_(code), msg_ (msg), exit_ (exit), dev_ (dev) {}
   const char* what() const throw() {
      return "Break fuera de bloque.";
   }
   ~errorException () throw() {}
   void error (string file = "", int line = 0);
 private:
   int code_, exit_;
   string msg_, dev_;
};
class warningQueue {
 public:
   static void warning (string file = "", int line = 0) {
      string file_txt;
      string line_txt;
      if (file != "") {
         file_txt = "file " + file + " ";
      }
      if (line && !inline_param) {
         stringstream ss;
         ss << line;
         line_txt = "line " + ss.str() + " => ";
      }
      while (!q_.empty()) {
         cerr << "Warning: "
              << file_txt << line_txt
              << q_.front() << endl;
         q_.pop();
      }
   }
   static void  add (string msg) {
      q_.push (msg);
   }
   static queue<string> q_;
};



#endif /*CCALC_H_*/
