//interpreter.h
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

//----------------------------------------------------------------------
#ifndef _INTERPRETER_
#define _INTERPRETER_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "run/tree/runTree.h"
#include "run/table/sTable.h"

#define INTERPRETER_NAME "omi"
#define INTERPRETER_DESCRIPTION "Open Modular Interpreter"
#define INTERPRETER_VERSION "0.1"
#define INTERPRETER_LICENSE "GNU General Public License version 2"
#define HISTORY_FILE string(getenv("HOME")) + "/." + string(INTERPRETER_NAME)  + "_history" 
#define PS1 INTERPRETER_NAME + string(" |> ")
#define PS2 INTERPRETER_NAME + string(" {> ")
#define PS2_BRACKET INTERPRETER_NAME + string(" (> ")

using namespace std;

extern bool inline_param;
extern string infile;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class interpreter
 * \brief Interprete OMI
 * 
 * Esta clase representa el interprete en si. Es una clase singleton. 
 * Se encarga de procesar las opciones de líneas de comando, inicializar
 * las estructuras funcionales del sistemas e iniciar
 * la interpretación del código fuente.
 */
class interpreter {
   public:
      /**
       * Método que lleva a cabo la interpretación el código fuente
       * configurado
       */
      void run ();
      /**
       * Configura la cadena dada para que sea interpretada.
       * \param str Cadena que se establecerá como código fuente
       */
      void scan_string(const char* str);
      /**
       * Inicializa y ejecuta el interprete a partir de una cadena que se corresponde
       * con el código fuente y una lista de argumentos que serán accesibles
       * desde la interpretación. Devuelve ela salida resultado de la interpretación.
       * \param str Código fuente
       * \param args Parámetros del programa
       * \return Salida estándar de la interpretación
       */
      static string omi (string str, vector<string>args);
      /** 
       * Inicializa y devuelve el intérprete a partir de unos
       * argumentos.
       * \param argc Número de argumentos
       * \param argv Array de argumentos
       * \return Inérprete.
       */
      static interpreter *init (int argc, char *argv[]) {
         if (!interpreter_) 
            interpreter_ = new interpreter (argc, argv);
         return interpreter_;
      }
      /**
       * Obtiene el intérprete 
       * \return interprete
       */
      static interpreter *get () {
         return interpreter_;
      }
#if JSON==1
      bool json;
      string json_file;
      ofstream json_stream;
      bool json_init;
      string step_content;
      string step_extra;
      unsigned int steps;
      unsigned int steps_count;
      static void setSteps (int steps);
      static void jsonInit();
      static void to_json(string value, string end = "");
      static void to_jsonRun (runNode * r, string msg = "");
      static void to_jsonRunClass (runNode * r);
      static void to_jsonEndClass (runNode * r);
      static void to_jsonSetParent (runNode *r, runNode* val);
      static void to_jsonSetValue (runNode *r, runNode* val);
      static void to_jsonSetValue (runNode *r, bool val);
      static void to_jsonSetValue (runNode *r, string val);
      static void to_jsonSetValue (runNode *r, num val);
      static void to_jsonSetRef (runNode *r, runNode* ref, runNode* obj);
      static void to_jsonReturn (runNode *r, runNode* val);
      static void to_jsonSleep (runNode *r, int seg);
      static void to_jsonNewNode (runNode *node, bool implicit = false);
      static void to_jsonError (string error);
      static void to_jsonRemoveLevel (unsigned int level);
      static void to_jsonAccessVar (sTable *r, int level, runNode* str, runNode* ref, runNode*val);
      static void to_jsonAccessFunction (sTable *r, runNode* str, runNode* ref, runNode *val);
      static void to_jsonAccessClass (sTable *r, runNode* str, runNode* ref, runNode *val);
      static void to_jsonClone (runNode * elem, runNode * of, string name, string type);
      static void to_jsonChangeRef (runNode* ref, runNode* val);
      static void to_jsonChangeValue (runNode* node, string val);
      static void to_jsonDelete (runNode * elem);
      static void to_jsonOut (runNode * elem, string out);
      static void to_jsonRunStatic (runNode * elem);
      static void to_jsonEndStatic (runNode * elem);
      static void to_jsonRunPrivate (runNode * elem);
      static void to_jsonEndPrivate (runNode * elem);
      static void to_jsonRunGlobal (runNode * elem);
      static void to_jsonEndGlobal (runNode * elem);
      static string to_jsonInput (runNode * elem);
      static void to_jsonSymbols (runNode *elem, runNode* key, runNode * value);
      static void to_jsonLine (int line);
      static void jsonEnd(string error = "");
#endif
#if SERVER==1
      bool server;
      string port;
      ofstream *s_out;
      void serverRun ();
#endif
   private:
      interpreter (int argc, char *argv[]);
      void generateClass ();
      void parseOptions (int argc, char *argv[]);
      void parseArgs ();
      void caseScript ();
      void caseCode ();
      void caseInline ();
      void caseStdin ();
      void printVersion ();
      void loadModule (string module);
      void printHelp ();
      string getLine ();
      vector<string> args_;
      string file_;
      string code_;
      bool inl_, error_opt_;
      static interpreter* interpreter_;
      
};
#endif
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
