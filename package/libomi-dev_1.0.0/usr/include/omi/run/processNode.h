//processNode.h
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
#ifndef _PROCESSNODE_
#define _PROCESSNODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <pthread.h>
#include "runTree.h"
using namespace std;

class forkNode: public arithNode {
 public:
   forkNode ();
   void run ();
};

class waitNode: public arithNode {
 public:
   waitNode (runNode * pID = NULL);
   void run ();
 private:
   runNode * pID_;
};

class getpidNode: public arithNode {
 public:
   getpidNode ();
   void run ();
};

class getppidNode: public arithNode {
 public:
   getppidNode ();
   void run ();
};

class processNode : public logicNode {
 public:
   processNode (runNode* func, runNode* params = NULL);
   void run();
 private:
   static void *processRun (void *ptr);
   runNode *func_, *params_;
};

class exitProcessNode : public logicNode {
 public:
   exitProcessNode ();
   void run();
};

class signalNode : public logicNode {
 public:
   signalNode (runNode* pid, runNode* signal);
   void run();
 private:
   runNode* pid_, *signal_;
};

class signalhandlerNode : public logicNode {
 public:
   signalhandlerNode (runNode* signal, runNode* function);
   void run();
   static void callHandlers (int signum);
 private:
   runNode* function_, *signal_;
   static vector<runNode *> instances;
};
#endif


