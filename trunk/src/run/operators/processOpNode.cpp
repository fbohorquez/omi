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
#include "../../interpreter.h"
#include "../../error.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//execNode
execNode::execNode (runNode* node) : node_(node) {}

void execNode::run () {
   #if JSON==1
      throw errorException ("function not allowed", "execNode: function not allowed in this mode", 3);
   #endif
   runNode *node = node_;
   nexpNode::resolved (node);
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
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//evalNode
evalNode::evalNode (runNode* node) : node_(node) {}

void evalNode::run () {
   #if JSON==1
      throw errorException ("function not allowed", "evalNode: function not allowed in this mode", 3);
   #endif
   runNode *node = node_;
   nexpNode::resolved (node);
   try {
      string code = stringNode::to_str (node);
      interpreter::get()->scan_string(code.c_str());
      yyparse();
      nullNode*s = new nullNode ();
      noderef(s);    
   } catch (returnException& e) {
      noderef(e.val());
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//forkNode
forkNode::forkNode () {}

void forkNode::run () {
   #if JSON==1
      throw errorException ("function not allowed", "forkNode: function not allowed in this mode", 3);
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
      throw errorException ("function not allowed", "waitNode: function not allowed in this mode", 3);
   #endif
   runNode *pID = pID_;
   int childExitStatus, pid;
   if (pID) {
      nexpNode::resolved (pID); 
      pid = arithNode::to_num (pID);
   } else {
      pid = 0;
   }
   pid_t ws = waitpid(pid, &childExitStatus, 0);
   if( !WIFEXITED(childExitStatus) ) {
      numvalue_ = WEXITSTATUS(childExitStatus);   
   } else if( WIFSIGNALED(childExitStatus) ) {
      numvalue_ = WEXITSTATUS(childExitStatus);
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getpid
getpidNode::getpidNode () {}

void getpidNode::run () {
   #if JSON==1
      throw errorException ("function not allowed", "getpidNode: function not allowed in this mode", 3);
   #endif
   pid_t pid ;
   pid = getpid();
   numvalue_ = pid;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//getppidNode
getppidNode::getppidNode () {}

void getppidNode::run () {
   #if JSON==1
      throw errorException ("function not allowed", "getppidNode: function not allowed in this mode", 3);
   #endif
   pid_t ppid;
   ppid = getppid();
   numvalue_ = ppid;
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
      throw errorException ("function not allowed", "processNode: function not allowed in this mode", 3);
   #endif
   pid_t pID = fork ();
   if (pID == 0) {
      processNode::processRun (this);
      _Exit(0);
   }
   boolvalue_ = true;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//exitProcessNode
exitProcessNode::exitProcessNode () {}

void exitProcessNode::run () {
   #if JSON==1
      throw errorException ("function not allowed", "exitProcessNode: function not allowed in this mode", 3);
   #endif 
   _Exit(0);
   boolvalue_ = true;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//signalNode
signalNode::signalNode (runNode* pid, runNode* signal) : signal_(signal), pid_ (pid) {}

void signalNode::run(){
   #if JSON==1
      throw errorException ("function not allowed", "signalNode: function not allowed in this mode", 3);
   #endif
   runNode *pid = pid_, *signal = signal_;
   nexpNode::resolved(pid);
   nexpNode::resolved(signal);
   boolvalue_ = kill((int)arithNode::to_num (pid), (int)arithNode::to_num (signal)) == 0;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//signalhandlerNode
vector<runNode *> signalhandlerNode::instances;

signalhandlerNode::signalhandlerNode (runNode* signal, runNode* function) : signal_(signal), function_ (function) {}

void signalhandlerNode::run(){
   #if JSON==1
      throw errorException ("function not allowed", "signalhandlerNode: function not allowed in this mode", 3);
   #endif
   runNode *function = function_, *sig = signal_;
   nexpNode::resolved(function);
   nexpNode::resolved(sig);
   signalhandlerNode::instances.push_back(function);
   signal ((int)arithNode::to_num (sig), signalhandlerNode::callHandlers);
   boolvalue_ = true;
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
