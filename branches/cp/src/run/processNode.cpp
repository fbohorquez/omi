//fileNode.cpp
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
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../interpreter.h"
#include "typeNode.h"
#include "sTable.h"
#include "processNode.h"

//----------------------------------------------------------------------

//----------------------------------------------------------------------
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

//Fco. Javier Bohórquez Ogalla
