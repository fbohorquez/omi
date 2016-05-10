/*! @file ccalc.c
 * @brief main program
 *********************************************************************
 * a simple calculator with variables
 *
 * sample-files for a artikel in developerworks.ibm.com
 * Author: Christian Hagen, chagen@de.ibm.com
 *
 * @par ccalc.c
 * main-program
 *
 *********************************************************************
 */
#include "error.h"
#include "run/stmts/stmtNode.h"
#include "interpreter.h"
queue<string> warningQueue::q_ = queue<string>();
extern
int yyerror(const char *s) {
   string str (infile);
   stringstream ss;
   if (infile != "") {
      ss << "Error: file " << infile << " line " << yylineno  << " => " << s << endl;
   } else if(!inline_param) {
      ss << "Error: line " << yylineno  << " => " << s << endl;
   } else {
      ss << "Error: " << s << endl;  
   }
#if JSON==1
   interpreter::jsonEnd(ss.str());
#endif
   cerr << ss.str();
   if (!inline_param) {
      stmtNode::compile_error = true;
   }
}

void errorException::error (string file, int line) {
   string file_txt;
   string line_txt;
   stringstream out;
   if (file != "") {
      file_txt = "file " + file + " ";
   }
   if (line && !inline_param) {
      stringstream ss;
      ss << line;
      line_txt = "line " + ss.str() + " => ";
   }
   out << "Error: " ;
   switch (code_) {
   default:
   case 0:
      out << file_txt << line_txt << msg_;
      break;
   case 1:
      out << file_txt << line_txt << "data type error, " << msg_ ;
      break;
   case 2:
      out << file_txt << line_txt << "parameters error, " << msg_;
      break;
   case 3:
      out << file_txt << line_txt << "access error, " << msg_;
      break;
   }
   //~ out << "dev: " << dev_ << endl;
   #if JSON==1
      interpreter::to_jsonError(out.str());
   #endif
   switch (exit_) {
   case 1:
      throw errorException ();
      break;
   }
   cerr << out.str() << endl;
}
