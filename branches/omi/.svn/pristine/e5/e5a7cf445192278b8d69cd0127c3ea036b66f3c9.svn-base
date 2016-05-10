//processOpNode.cpp
//-------------------------------------------------------------------------------------------
/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#include "processOpNode.h"
//~ #include "stmtNode.h"
#include "../../interpreter.h"
#include "../../error.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
//~ #include <math.h>
//~ #include <stdlib.h>
//~ #include <string>
//~ #include <iostream>
//~ #include <stdio.h>
//~ #include "interpreter.h"
//~ #include "lshParser.h"
//~ #include "operatorRegexpNode.h"
//~ #include "../interpreter.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//execNode
execNode::execNode (runNode* node) : node_(node) {}

void execNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   string cmd = stringNode::to_str (node);
   FILE* pipe = popen(cmd.c_str(), "r");
   if (!pipe) cerr << "ERROR" << endl;
   char buffer[128];
   std::string result = "";
   while(!feof(pipe)) {
      if(fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }
   pclose(pipe);
   strvalue_ = result;
   #if JSON==1
      interpreter::to_jsonSetValue(this, strvalue_);
   #endif   
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//evalNode
evalNode::evalNode (runNode* node) : node_(node) {}

void evalNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *node = node_;
   nexpNode::resolved (node);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   try {
      string code = stringNode::to_str (node);
      interpreter::get()->scan_string(code.c_str());
      yyparse();
      nullNode*s = new nullNode ();
      noderef(s);
      #if JSON==1
         interpreter::to_jsonSetValue(this, s);
      #endif      
   } catch (returnException& e) {
      noderef(e.val());
      #if JSON==1
         interpreter::to_jsonSetValue(this, e.val());
      #endif
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//forkNode
forkNode::forkNode () {}

void forkNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   pid_t pID = fork ();
   numvalue_ = pID;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//waitNode
waitNode::waitNode (runNode *pID) : pID_(pID) {}

void waitNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode *pID = pID_;
   int childExitStatus, pid;
   if (pID) {
      nexpNode::resolved (pID);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif       
      pid = arithNode::to_num (pID);
   } else {
      pid = 0;
   }
   pid_t ws = waitpid(pid, &childExitStatus, 0);
   if( !WIFEXITED(childExitStatus) ) {
      numvalue_ = WEXITSTATUS(childExitStatus);
      #if JSON==1
         interpreter::to_jsonSetValue(this, numvalue_);
      #endif         
   } else if( WIFSIGNALED(childExitStatus) ) {
      numvalue_ = WEXITSTATUS(childExitStatus);
      #if JSON==1
         interpreter::to_jsonSetValue(this, numvalue_);
      #endif      
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getpid
getpidNode::getpidNode () {}

void getpidNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   pid_t pid ;
   pid = getpid();
   numvalue_ = pid;
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getppidNode
getppidNode::getppidNode () {}

void getppidNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif 
   pid_t ppid;
   ppid = getppid();
   numvalue_ = ppid;
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//processNode
processNode::processNode (runNode * func, runNode* params) : func_(func), params_ (params) {}

void *processNode::processRun (void *ptr) {
   if (processNode * thNode = (processNode*)ptr) {
      runNode *func = thNode->func_, *params = thNode->params_;
      if (idNode* id = dynamic_cast<idNode*>(func)) {
         if (id->existfunction ()) {
            id->runf();          
            func = id->nodevalf();
         }
      }
      nexpNode::resolved(func)->run ();      
      listNode * plist = dynamic_cast<listNode*>(params);
      if (functionNode * f = dynamic_cast<functionNode*> (func)) {
         functioncallNode *call = new functioncallNode (f, plist);
         call->run();
         return NULL;
      }
   }
   return NULL;
}

void processNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   //~ pthread_t th;
   pid_t pID = fork ();
   if (pID == 0) {
      processNode::processRun (this);
      _Exit(0);
   }
   boolvalue_ = true;
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
   //~ pthread_create(&th, NULL, processNode::processRun, this);
   //~ processNode::ths_.push_back (th);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//exitProcessNode
exitProcessNode::exitProcessNode () {}

void exitProcessNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   _Exit(0);
   boolvalue_ = true;
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//signalNode
signalNode::signalNode (runNode* pid, runNode* signal) : signal_(signal), pid_ (pid) {}

void signalNode::run(){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *pid = pid_, *signal = signal_;
   nexpNode::resolved(pid);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(signal);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif  
   boolvalue_ = kill((int)arithNode::to_num (pid), (int)arithNode::to_num (signal)) == 0;
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//signalhandlerNode
vector<runNode *> signalhandlerNode::instances;

signalhandlerNode::signalhandlerNode (runNode* signal, runNode* function) : signal_(signal), function_ (function) {}

void signalhandlerNode::run(){
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   runNode *function = function_, *sig = signal_;
   nexpNode::resolved(function);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   nexpNode::resolved(sig);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   signalhandlerNode::instances.push_back(function);
   signal ((int)arithNode::to_num (sig), signalhandlerNode::callHandlers);
   boolvalue_ = true;
   #if JSON==1
      interpreter::to_jsonSetValue(this, boolvalue_);
   #endif
}

void signalhandlerNode::callHandlers (int signum){
   int n = instances.size();
   for (int i = 0; i < n; ++i) {
      if (functionNode* f = dynamic_cast<functionNode*> (instances[i])){
         f->call (NULL);
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
