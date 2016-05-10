//fileNode.h
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
#ifndef _FILENODE_
#define _FILENODE_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <string>
#include <ctime>
#include "runTree.h"
#include <fstream>
using namespace std;

class fileNode : public logicNode {
 public:
   fileNode (runNode * file, runNode * mode = NULL);
   void run ();
   inline fstream *get () const {
      return f_;
   }
   inline string getMode () {
      return stringNode::to_str(mode_);
   }
 private:
   runNode *file_, *mode_;
   fstream *f_;
   bool exec;
};

class fputNode : public arithNode {
 public:
   fputNode (runNode * file, runNode * val);
   void run ();
 private:
   runNode *file_, *val_;
};

class fgetNode : public stringNode {
 public:
   fgetNode (runNode * file, runNode *size = NULL);
   void run ();
 private:
   runNode *file_, *size_;
};

class freadNode : public stringNode {
 public:
   freadNode (runNode * file);
   void run ();
 private:
   runNode *file_;
};

class fwriteNode : public stringNode {
 public:
   fwriteNode (runNode * file, runNode* str);
   void run ();
 private:
   runNode *file_, *str_;
};

class fappendNode : public stringNode {
 public:
   fappendNode (runNode * file, runNode* str);
   void run ();
 private:
   runNode *file_, *str_;
};

class fseekNode : public logicNode {
 public:
   fseekNode  (runNode * file, runNode* offset, int pos = 0);
   void run ();
 private:
   runNode *file_, *offset_;
   int pos_;
};

class ftellNode : public arithNode {
 public:
   ftellNode  (runNode * file);
   void run ();
 private:
   runNode *file_;
};

class fcloseNode : public logicNode {
 public:
   fcloseNode  (runNode * file);
   void run ();
 private:
   runNode *file_;
};
#endif


