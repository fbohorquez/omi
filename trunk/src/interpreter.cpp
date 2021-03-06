//interpreter.cpp
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
#include "interpreter.h"
//~ #include "run/numData.h"
//~ #include "run/runTree.h"
//~ #include "run/sTable.h"
#include "run/tree/typeNode.h"
#include "run/operators/opNode.h"
//~ #include "run/operatorStrNode.h"
//~ #include "run/operatorArrayNode.h"
//~ #include "run/operatorDateNode.h"
//~ #include "run/operatorRegexpNode.h"
//~ #include "run/fileNode.h"
//~ #include "run/processNode.h"
//~ #include "run/componentNode.h"
#include "error.h"
//~ #include "run/sqliteDb.h"
#include "plugin.h"
#include "lshParser.h"

#if SERVER==1 || JSON==1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sstream>

#define DEFAULTPORT "8888"
#define MAX_TAM 2048
#define TRYBIND 10

#endif

extern int yylex(void);
extern void yy_scan_string (const char*);
extern char* yytext;
extern FILE *yyin;
extern int yylineno;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
interpreter* interpreter::interpreter_ = NULL;

void interpreter::scan_string(const char* str){
    yy_scan_string(str);
}

void interpreter::generateClass () {
   stringNode::generateClass () ;
   arrayNode::generateClass () ;
   logicNode::generateClass () ;
   arithNode::generateClass () ;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
interpreter::interpreter (int argc, char *argv[]) : inl_ (false), error_opt_ (false) {
   #if JSON==1
      json = false;
      step_content = "";
      steps = 0;
      steps_count = 0;
      json_init = false;
      step_extra = "";
   #endif 
   #if SERVER==1
      server = false;
   #endif 
   parseOptions (argc, argv);   
}
//----------------------------------------------------------------------
string interpreter::omi (string str, vector<string>args) {
   std::stringstream redirectStream;
   std::streambuf* oldbuf  = std::cout.rdbuf(redirectStream.rdbuf());
   interpreter_ = new interpreter (0, NULL);
   interpreter_->code_ = str;
   interpreter_->args_ = args;
   interpreter_->run();
   delete interpreter_;
   interpreter_ = NULL;
   std::cout.rdbuf(oldbuf);
   return redirectStream.str();
}

void interpreter::parseOptions (int argc, char *argv[]) {
   int i, oc, c;
   bool error_opt = false;
   struct option longopts[] = {
     { "inline",  0,  NULL, 'i' },
     { "version",  no_argument,  NULL, 'V' },
     { "cmd",  required_argument,  NULL,  'c' },
     { "load",  required_argument,  NULL,  'l' },
#if JSON==1
      {"json", required_argument, NULL, 'j'},
      {"steps", required_argument, NULL, 'x'},
#endif
#if SERVER==1
      {"server", optional_argument, NULL, 's' },
#endif
     { "help",  no_argument,  NULL,  'h' },
     {0, 0, 0, 0}
    };
   int index = 0;
   string ops = "ic:l:Vh";
#if JSON==1
   json = false;
   ops +="j:";
   ops +="x:";
#endif
#if SERVER==1
   server = false;
   ops +="s";
#endif
   const char* const short_options = ops.c_str();
   istringstream buffer;
   //~ const char* const short_options = "ic:V";
   while ((c = getopt_long(argc, argv, short_options, longopts, &index)) != -1) {
      switch (c){
         case 'i':
            inl_  = 1;
            inline_param = true;
            break;
#if JSON==1
         case 'j':
            json = true;
            json_file = optarg;
            break;
         case 'x':
            json = true;
            buffer.str (optarg);
            unsigned int value;
            buffer >> value; 
            this->steps_count = this->steps = value;
            break;
#endif
#if SERVER==1
         case 's':
            server = true;
            port = (optarg)?optarg:DEFAULTPORT;
            break;
#endif
         case 'c':
            code_ = optarg;
            break;
         case '?':
            error_opt_ = true;
            _exit(-1);
         case 'h':
            printHelp ();
            _exit(0);
         case 'V':
            printVersion ();
            _exit(0);
         case 'l':
            loadModule (optarg);
            break;
         default:
            break;
      }
   }
   if (!error_opt)
      for (i=optind; i<argc; i++) 
         args_.insert (args_.end(), argv[i]);
}

void interpreter::run() {
#if SERVER==1
   if(server) serverRun ();
#endif
   sTable::sys_sTable ();
   generateClass ();
   parseArgs ();
   if (code_ != "") caseCode();
   if (file_ != "") caseScript();
      else if (inl_) caseInline();   
      else caseStdin();
}

void interpreter::caseScript () {
   yyin = fopen (file_.c_str(),"r");
   yyparse();
}

void interpreter::caseCode () {
   yy_scan_string(code_.c_str());
   yyparse();
}

void interpreter::caseInline () {
   using_history ();
   string history_file = HISTORY_FILE;
   FILE *file = NULL;
   if (!(file = fopen(history_file.c_str(),"r")))
      file = fopen(history_file.c_str(),"w+b");
   fclose (file);
   if (int nerror = read_history (history_file.c_str ())) cerr << nerror << endl;;
   while (true) {
      string str = getLine();
      yy_scan_string(str.c_str());
      add_history (str.c_str());
      write_history (history_file.c_str ());
      yyparse();
      warningQueue::warning ();
   }
}

void interpreter::caseStdin () {
   yyparse();
}

void interpreter::parseArgs () {
   vector<string>::iterator iter = args_.begin();
   if (!args_.empty() && !inl_)
      infile = file_ = *iter;
   idNode *id;
   listNode* list = NULL;
   for (; iter != args_.end(); iter ++) 
      list = new listNode (list, new strNode (*iter));
   string str ("args"); 
   id = new idNode (str); 
   asigNode a (id, new arrayNode (list));
   a.run();
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string interpreter::getLine () {
   char* line = readline (string(PS1).c_str());
   string str (line);
   int pair_top = 0;
   int bracket_top = 0;
   bool pair_check = false;
   bool bracket_check = false;
   int pos = 0;
   while (!pair_check || !bracket_check) {
      for (int i = pos; i < str.size(); ++i){
         if (str[i] == '(' ) bracket_top ++;
         else if (str[i] == ')') bracket_top --;
         if (str[i] == '{' ) pair_top ++;
         else if (str[i] == '}') pair_top --;
      }
      if(!(pair_check = (pair_top == 0)) || !(bracket_check = (bracket_top == 0))){
         pos = str.size();
         line = readline (string(!pair_check?PS2:PS2_BRACKET).c_str());
         string s_aux (line);
         str += s_aux;
      }
   }
   return str;
}

void interpreter::printVersion () {
   cout << INTERPRETER_NAME << ": " << INTERPRETER_DESCRIPTION << " (" << INTERPRETER_VERSION << ") " << endl;
   cout << INTERPRETER_LICENSE << endl;
}

void interpreter::printHelp () {
   cout << "Usage: omi [options] <file> [args...]" << endl;
   cout << "omi -c <code> [args...]" << endl;
   cout << "omi -i [args...]" << endl;
   cout << endl;
   cout << " -i\t\tRun interactively" << endl;
   cout << " -c <code>\tRun code" << endl;
   cout << " -l <file.so>\tLoad module <file.so>" << endl;
   cout << " -h\t\tThis help" << endl;
   cout << " -V\t\tVersion number" << endl;
   #if JSON==1
      cout << " -j <file>\tPrint JSON process out in <file>" << endl; 
      cout << " -x <steps>\tGet <steps> JSON process out in port (10000 + pid)." << endl; 
   #endif
   #if SERVER==1
      cout << " -s [port]\tRun as server in [port] (default 8888)" << endl; 
   #endif
}
void interpreter::loadModule (string module) {
   strNode str (module);
   loadNode lnode (&str);
   lnode.run();
}
//======================================================================
#if JSON==1
void interpreter::setSteps (int steps) {
   if (interpreter_){
      interpreter_->steps = steps;
   }
}

void interpreter::jsonInit(){
   if (interpreter_) {
      interpreter_->json_stream.open (interpreter_->json_file.c_str());
      interpreter_->json_init = true;
      
   }
}
void interpreter::to_json(string value, string end){
   if (interpreter_ && interpreter_->json_init){
      interpreter_->json_stream << value;
      if (interpreter_->steps) {
         interpreter_->step_content += value;
         interpreter_->steps_count --; 
         interpreter_->step_extra += value; 
         if (interpreter_->steps_count == 0 ) {
            stringstream pid;
            pid << getpid();
            int sockfd, newsockfd;
            struct sockaddr_in serv_addr, cli_addr;
            int waittime = 0;
            int iport;
            socklen_t clilen;
            signal(SIGCHLD, SIG_IGN);
            sockfd = socket(AF_INET, SOCK_STREAM, 0); //Abrimos socket
            int reusePort = 1; 
            setsockopt(sockfd, SOL_SOCKET, 2, &reusePort, sizeof(reusePort));
            if (sockfd < 0) {
               perror("ERROR opening socket");
                 _exit(1);
            }
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons(10000 + getpid());
            int count = 0;
            while ((bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) && count < TRYBIND) {
                  count ++;
                  perror("ERROR on binding");
                  sleep(1);
            }
            if (count == TRYBIND) _exit (1);
            listen(sockfd,5);
            clilen = sizeof(cli_addr);
            cerr << "Abriendo sock " << 10000 + getpid() <<endl;
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            reusePort = 1; 
            setsockopt(newsockfd, SOL_SOCKET, 2, &reusePort, sizeof(reusePort));
            string out = "{\"json\":[" + interpreter_->step_content + "]" + end + "}";
            //~ cerr << out << endl;
            send (newsockfd, out.c_str(), out.length(), 0);
            
            
            close(sockfd);
            close(newsockfd);
            interpreter_->steps_count = interpreter_->steps;
            interpreter_->step_content = "";
            interpreter_->step_extra = "";
         }
      }
   }
}
void interpreter::to_jsonRun (runNode *r, string msg){
   if (interpreter_ && interpreter_->json){
      interpreter::to_json("{\"action\":\"run\",\"id\":\"" + r->getPtrString () + "\"" + ((msg != "")?",\"attrs\":{\"msg\":\"" + msg + "\"}":"") + "},");
   }
}

void interpreter::to_jsonRunClass (runNode *r){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"runClass\",\"id\":\"" + r->getPtrString () + "\"},");
   }
}

void interpreter::to_jsonEndClass (runNode *r){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"endClass\",\"id\":\"" + r->getPtrString () + "\"},");
   }
}

void interpreter::to_jsonRunStatic (runNode *r){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"runStatic\",\"id\":\"" + r->getPtrString () + "\"},");
   }
}

void interpreter::to_jsonEndStatic (runNode *r){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"endStatic\",\"id\":\"" + r->getPtrString () + "\"},");
   }
}

void interpreter::to_jsonRunPrivate (runNode *r){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"runPrivate\",\"id\":\"" + r->getPtrString () + "\"},");
   }
}

void interpreter::to_jsonEndPrivate (runNode *r){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"endPrivate\",\"id\":\"" + r->getPtrString () + "\"},");
   }
}

void interpreter::to_jsonRunGlobal (runNode *r){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"runGlobal\",\"id\":\"" + r->getPtrString () + "\"},");
   }
}

void interpreter::to_jsonEndGlobal (runNode *r){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"endGlobal\",\"id\":\"" + r->getPtrString () + "\"},");
   }
}

void interpreter::to_jsonSetValue (runNode *r, runNode* val){
   if (interpreter_->json)
      interpreter::to_json("{\"action\":\"setValue\",\"id\":\"" + r->getPtrString () + "\",\"attrs\":{\"value\":\"" + val->getPtrString() + "\"}},");
}

void interpreter::to_jsonSetParent (runNode *r, runNode* val){
   if (interpreter_->json)
      interpreter::to_json("{\"action\":\"setParent\",\"id\":\"" + r->getPtrString () + "\",\"attrs\":{\"value\":\"" + val->getPtrString() + "\"}},");
}
void interpreter::to_jsonSetRef (runNode *r, runNode* ref, runNode* obj){
   if (interpreter_->json)
      interpreter::to_json("{\"action\":\"setRef\",\"id\":\"" + r->getPtrString () + "\",\"attrs\":{\"value\":\"" + ref->getPtrString() + "\", \"obj\":\"" + obj->getPtrString()  + "\"}},");
}
void interpreter::to_jsonReturn (runNode *r, runNode* val){
   if (interpreter_->json)
      interpreter::to_json("{\"action\":\"return\",\"id\":\"" + r->getPtrString () + "\",\"attrs\":{\"value\":" + val->toJson(typeofNode::type (val), "data") + "}},");
}
void interpreter::to_jsonSleep (runNode *r, int seg){
   if (interpreter_->json){
      std::stringstream ss1;
      ss1 << seg;
      interpreter::to_json("{\"action\":\"sleep\",\"id\":\"" + r->getPtrString () + "\",\"attrs\":{\"value\":" + ss1.str() + "}},");
   }
}
void interpreter::to_jsonNewNode (runNode *node, bool implicit){
   if (interpreter_->json)
      interpreter::to_json("{\"action\":\"newNode\",\"id\":\"" + node->getPtrString () + "\",\"attrs\":{\"node\":" + node->toJson(typeofNode::type (node), "data") + ((implicit)?",\"implicit\":true":"") + "}},");
}
void interpreter::to_jsonRemoveLevel (unsigned int level){
   if (interpreter_->json){
       std::stringstream ss1;
       ss1 << level;
      interpreter::to_json("{\"action\":\"removeLevel\",\"id\":" + ss1.str() + "},");
   }
}
void interpreter::to_jsonSetValue (runNode *r, bool val){
   if (interpreter_->json)
      interpreter::to_json("{\"action\":\"setValue\",\"id\":\"" + r->getPtrString () + "\",\"attrs\":{\"value\":\"" + ((val)?"true":"false") + "\"}},");
}
void interpreter::to_jsonSetValue (runNode *r, string val){
   if (interpreter_->json)
      interpreter::to_json("{\"action\":\"setValue\",\"id\":\"" + r->getPtrString () + "\",\"attrs\":{\"value\":\"" + val + "\"}},");
}
void interpreter::to_jsonSetValue (runNode *r, num val){
   if (interpreter_->json){
      stringstream n;
      n << val;
      interpreter::to_json("{\"action\":\"setValue\",\"id\":\"" + r->getPtrString () + "\",\"attrs\":{\"value\":\"" + n.str() + "\"}},");
   }
}
void interpreter::to_jsonAccessClass (sTable *r, runNode* str, runNode* ref, runNode *val){
   if (interpreter_->json){
      string id = "";
      std::stringstream ss1, ss2;
      ss1 << r;
      ss2 << ref;
      if (refNode *r = dynamic_cast<refNode*>(str)){
         id = r->getKey();
      }
      else {
         id = stringNode::to_str(str);
      }
      interpreter::to_json("{\"action\":\"accessClass\",\"id\":\"" + ss1.str() + "\",\"attrs\":{\"str\":\"" + id + "\",\"ref\":\"" + ss2.str() + "\",\"val\": " + val->toJson(typeofNode::type (val), "data") + " }},");
   }
}
void interpreter::to_jsonAccessFunction (sTable *r, runNode* str, runNode* ref, runNode *val){
   if (interpreter_->json){
      string id = "";
      std::stringstream ss1, ss2;
      ss1 << r;
      ss2 << ref;
      if (refNode *r = dynamic_cast<refNode*>(str)){
         id = r->getKey();
      }
      else {
         id = stringNode::to_str(str);
      }
      interpreter::to_json("{\"action\":\"accessFunc\",\"id\":\"" + ss1.str() + "\",\"attrs\":{\"str\":\"" + id + "\",\"ref\":\"" + ss2.str() + "\",\"val\": " + val->toJson(typeofNode::type (val), "data") + " }},");
   }
}

void interpreter::to_jsonAccessVar (sTable *r, int level, runNode* str, runNode* ref, runNode *val){
   if (interpreter_->json){
      string id = "";
      std::stringstream ss1, ss2, ss3, ss4;
      ss1 << r;
      ss2 << ref;
      ss3 << level;
      if (refNode *r = dynamic_cast<refNode*>(str)){
         id = r->getKey();
      }
      else {
         id = stringNode::to_str(str);
      }
      interpreter::to_json("{\"action\":\"accessVar\",\"id\":\"" + ss1.str() + "\",\"attrs\":{\"str\":\"" + id + "\",\"ref\":\"" + ss2.str() + "\",\"level\":" + ss3.str() + ", \"val\": " + val->toJson(typeofNode::type (val), "data") + " }},");
   }
}

void interpreter::to_jsonChangeRef (runNode* ref, runNode* val){
   if (interpreter_->json) {
      interpreter::to_json("{\"action\":\"changeRef\",\"id\":\"" + ref->getPtrString() + "\",\"attrs\":{\"val\": \"" + val->getPtrString() + "\" }},");
   }
}

void interpreter::to_jsonChangeValue (runNode* node, string val){
   if (interpreter_->json) {
      interpreter::to_json("{\"action\":\"changeValue\",\"id\":\"" + node->getPtrString() + "\",\"attrs\":{\"val\": \"" + val + "\" }},");
   }
}


void interpreter::to_jsonClone (runNode * elem, runNode * of, string name, string type){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"clone\",\"id\":\"" + elem->getPtrString () + "\", \"attrs\":{\"of\":\"" + of->getPtrString () + "\",\"node\":" + elem->toJson(name, type) + " }},");
   }
}

void interpreter::to_jsonDelete (runNode * elem){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"delete\",\"id\":\"" + elem->getPtrString () + "\"},");      
   }
}

void interpreter::to_jsonError (string error){
   if (interpreter_->json){
      interpreter::to_json("{\"action\":\"error\",\"id\":\"" + error + "\"},");      
   }
}

void interpreter::to_jsonOut (runNode * elem, string out){
   if (interpreter_->json){
      size_t start_pos = 0;
      do {
         start_pos = out.find("\n");
         if(start_pos != std::string::npos)
            out.replace(start_pos, 1, "<br/>");
      } while (start_pos != std::string::npos);
      interpreter::to_json("{\"action\":\"print\",\"id\":\"" + elem->getPtrString () + "\", \"attrs\":{\"out\":\"" + out + "\"}},");
   }
}

void interpreter::to_jsonLine (int line){
   if (interpreter_->json){
      std::stringstream ss1, ss2;
      ss1 << line;
      interpreter::to_json("{\"action\":\"line\",\"id\":\"" + ss1.str() + "\"},");
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string interpreter::to_jsonInput (runNode * elem){
   if (interpreter_->json) {
      interpreter_->steps_count = 1;
      string resp = "";
      interpreter::to_json("{\"action\":\"input\",\"id\":\"" + elem->getPtrString () + "\"},", ", \"input\": \"true\"");
      stringstream pid;
      pid << getpid();
      int sockfd, newsockfd;
      struct sockaddr_in serv_addr, cli_addr;
      int waittime = 0;
      int iport;
      socklen_t clilen;
      signal(SIGCHLD, SIG_IGN);
      sockfd = socket(AF_INET, SOCK_STREAM, 0); //Abrimos socket
      int reusePort = 1; 
      setsockopt(sockfd, SOL_SOCKET, 2, &reusePort, sizeof(reusePort));
      if (sockfd < 0) {
         perror("ERROR opening socket");
           _exit(1);
      }
      serv_addr.sin_family = AF_INET;
      serv_addr.sin_addr.s_addr = INADDR_ANY;
      serv_addr.sin_port = htons(10000 + getpid());
      int count = 0;
      while ((bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) && count < TRYBIND) {
            perror("ERROR on binding");
            count ++;
            sleep(1);
      }
      if (count == TRYBIND) _exit (1);
      listen(sockfd,5);
      clilen = sizeof(cli_addr);
      cerr << "Abriendo para input " << 10000 + getpid() <<endl;
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
      reusePort = 1; 
      setsockopt(newsockfd, SOL_SOCKET, 2, &reusePort, sizeof(reusePort));
      char buffer[MAX_TAM];
      int bytes;
      string result;
      bytes = recv(newsockfd, buffer, MAX_TAM, 0);
      buffer[bytes] = '\0';
      resp = string (buffer);
      cerr << "Input recibido input " << resp <<endl;
      close(sockfd);
      close(newsockfd);
      return resp;
   }
   return "";
}

void interpreter::to_jsonSymbols (runNode *elem, runNode* key, runNode * value) {
   if (interpreter_->json) {
      interpreter::to_json("{\"action\":\"toSymbols\",\"id\":\"" + elem->getPtrString () + "\", \"attrs\":{\"key\":" + key->toJson(typeofNode::type(key), "data") + ", \"val\":" + value->toJson(typeofNode::type(value), "data") + "}},");
   }
}

void interpreter::jsonEnd(string error){
   interpreter_->json_stream.close();
   stringstream pid;
   cerr << "AAAAAAAAAAA" << interpreter_->steps <<  endl;
   if (interpreter_->steps){
      pid << getpid();
      int sockfd, newsockfd;
      struct sockaddr_in serv_addr, cli_addr;
      int waittime = 0;
      int iport;
      socklen_t clilen;
      signal(SIGCHLD, SIG_IGN);
      sockfd = socket(AF_INET, SOCK_STREAM, 0); //Abrimos socket
      int reusePort = 1; 
      setsockopt(sockfd, SOL_SOCKET, 2, &reusePort, sizeof(reusePort));
      if (sockfd < 0) {
         perror("ERROR opening socket");
           _exit(1);
      }
      serv_addr.sin_family = AF_INET;
      serv_addr.sin_addr.s_addr = INADDR_ANY;
      serv_addr.sin_port = htons(10000 + getpid());
      int count = 0;
      while ((bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) && count < TRYBIND) {
            perror("ERROR on binding");
            count ++;
            sleep(1);
      }
      if (count == TRYBIND) _exit (1);
      listen(sockfd,5);
      clilen = sizeof(cli_addr);
      cerr << "Abriendo sock " << 10000 + getpid() <<endl;
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
      reusePort = 1; 
      setsockopt(newsockfd, SOL_SOCKET, 2, &reusePort, sizeof(reusePort));
      string out; 
      
      out = (
         (error == "")
         ?("{\"json\":[" + interpreter_->step_extra + "],\"end\":\"true\"}")
         :("{\"error\":\"" + error + "\"}")
      );
      //~ cerr << out << endl;
      send (newsockfd, out.c_str(), out.length(), 0);
      close(sockfd);
      close(newsockfd);
   }
}
#endif
//======================================================================
#if SERVER==1
void interpreter::serverRun (){
    int sockfd, newsockfd;
    pid_t pid;
    struct sockaddr_in serv_addr, cli_addr;
    int waittime = 0;
    int iport;
    socklen_t clilen;
    signal(SIGCHLD, SIG_IGN);
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //Abrimos socket
    if (sockfd < 0) {
        perror("ERROR opening socket");
        _exit(1);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    istringstream iss (port);
    iss >> iport;
    serv_addr.sin_port = htons(iport);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
         perror("ERROR on binding");
         _exit(1);
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    while (1) {
        cout << "Wait conection in port " << port << endl;
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0){
            perror("ERROR on accept");
            _exit(1);
        }
        pid = fork();
        if (pid < 0){
            perror("ERROR on fork");
            _exit(1);
        }
        if (pid == 0)  {
            cout << "Wait code" << endl;
            char buffer[MAX_TAM];
            int bytes;
            string result;
            bytes = recv(newsockfd, buffer, MAX_TAM, 0);
            buffer[bytes] = '\0';
            code_ = string (buffer);
            cout << "Src: " << code_;
            stringstream pid;
            pid << getpid();
            //~ s_out = new ofstream (pid.str().c_str());
            //~ std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
            //~ std::cout.rdbuf(s_out->rdbuf());
            send (newsockfd, pid.str().c_str(), pid.str().length(), 0);
            close(sockfd);
            close(newsockfd);
            break;
        }
    }
    close(sockfd);
}
#endif
//----------------------------------------------------------------------

//Fco. Javier Bohórquez Ogalla
