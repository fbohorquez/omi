//fileOpNode.cpp
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
#include "fileOpNode.h"
#include "../stmts/stmtNode.h"
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//fileNode
fileNode::fileNode (runNode * file, runNode * mode ): file_(file), mode_(mode), exec (false) {}

void fileNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   if (!exec) {
      runNode *file = file_, *mode = mode_;
      nexpNode::resolved(file);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      if (mode) {
         nexpNode::resolved (mode);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
      }     
      if (stringNode* file_str = dynamic_cast<stringNode*>(file)) {
         string file_s = file_str->strvalue();
         if (stringNode *mode_str = dynamic_cast<stringNode*> (mode)) {
            string mode_s = mode_str->strvalue();
            if (mode_s == "r") {
               f_ = new fstream (file_s.c_str(), ios::in);
            } else if (mode_s == "r+") {
               ofstream fs(file_s.c_str());
               fs.close();
               f_ = new fstream (file_s.c_str(), ios::in | ios::out);
            } else if (mode_s == "w") {
               f_ = new fstream (file_s.c_str(), ios::out | ios::trunc);
            } else if (mode_s == "w+") {
               f_ = new fstream (file_s.c_str(), ios::in | ios::out | ios::trunc);
            } else if (mode_s == "a"){
               ofstream fs(file_s.c_str());
               fs.close();
               f_ = new fstream (file_s.c_str(), ios::out | ios::ate);
            }else if (mode_s == "a+"){
               ofstream fs(file_s.c_str());
               fs.close();
               f_ = new fstream (file_s.c_str(), ios::in | ios::out | ios::ate);
            }
            //~ else if (mode_s == "b")
               //~ f_ = new fstream (file_s.c_str(), ios::in | ios::binary);
            //~ else if (mode_s == "b+")
               //~ f_ = new fstream (file_s.c_str(), ios::out | ios::in | ios::binary | ios::trunc);
         } else
            f_ = new fstream (file_s.c_str(), ios::in | ios::out | ios::ate);
         boolvalue_ = f_->is_open();
         #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
         #endif
      }
      exec = true;
   }   
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//fputNode
fputNode::fputNode (runNode * file, runNode * val ): file_(file), val_(val) {}

void fputNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode *file = file_, *val = val_;
   nexpNode::resolved(file);
   nexpNode::resolved (val);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   if (fileNode* file_node = dynamic_cast<fileNode*>(file)) {
      fstream *f = file_node->get();
      if (stringNode *val_str = dynamic_cast<stringNode*> (val)) {
         string val_s = val_str->strvalue();
         streampos begin = f->tellg();
         (*f) << val_s << flush;
         numvalue_ = f->tellg() - begin;
         #if JSON==1
         interpreter::to_jsonSetValue(this, numvalue_);
         #endif         
      } else {
         cerr << "Incorrect string to file" << endl;
      }
   } else {
      cerr << "Incorrect file" << endl;
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//fgetNode
fgetNode::fgetNode (runNode * file, runNode* size): file_(file), size_ (size) {}

void fgetNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif    
   runNode *file = file_, *size = size_;
   nexpNode::resolved(file);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif       
   if (size) {
      nexpNode::resolved(size);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif    
   }
   if (fileNode* file_node = dynamic_cast<fileNode*>(file)) {
      fstream *f = file_node->get();
      string s;
      if (size){
         int size_i = arithNode::to_num(size);
         int pos = f->tellg();
         f->seekg (0, ios::end);
         int length = (int)f->tellg() - pos;
         f->seekg (pos, ios::beg);
         if (size_i > length)
            size_i = length;
         char * a = new char[size_i + 1];
         if (((ifstream*)(f))->read(a, size_i)){
            a[size_i] = '\0';
            strvalue_ = (string)a; 
            #if JSON==1
               interpreter::to_jsonSetValue(this, strvalue_);
            #endif    
         }else{
            strvalue_ = "";
            #if JSON==1
               interpreter::to_jsonSetValue(this, strvalue_);
            #endif   
         }
      }else{
         if (getline (*f, s)){
            strvalue_ = s;
            #if JSON==1
               interpreter::to_jsonSetValue(this, strvalue_);
            #endif            
         }else{
            strvalue_ = "";
            #if JSON==1
               interpreter::to_jsonSetValue(this, strvalue_);
            #endif
         }        
      }
   } else {
      cerr << "Incorrect file" << endl;
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//freadNode
freadNode::freadNode (runNode * file): file_(file) {}

void freadNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *file = file_;
   nexpNode::resolved(file);
   bool isstr = false;
   if (stringNode* str = dynamic_cast<stringNode*>(file)) {
      str->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif     
      strNode s_aux ("r");
      s_aux.run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      file = new fileNode (str, &s_aux);
      file->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      isstr = true;
   }
   if (fileNode* file_node = dynamic_cast<fileNode*>(file)) {
      fstream *f = file_node->get();
      string s;
      ostringstream oss;
      bool first = true;
      while (getline (*f, s)) {
         if (first)
            first = false;
         else
            oss << endl;
         oss << s;
      }
      strvalue_ = oss.str();
      #if JSON==1
         interpreter::to_jsonSetValue(this, strvalue_);
      #endif      
      if (isstr) f->close();
   } else {
      cerr << "Incorrect file" << endl;
   }
   if (isstr) delete file;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//fWriteNode
fwriteNode::fwriteNode (runNode * file, runNode*str): file_(file), str_ (str) {}

void fwriteNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *file = file_, *str=str_;
   nexpNode::resolved(file);
   nexpNode::resolved(str);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   bool isstr = false;
   if (stringNode* strf = dynamic_cast<stringNode*>(file)) {
      strNode s_aux ("w");
      s_aux.run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif     
      file = new fileNode (strf, &s_aux);
      file->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      isstr = true;
   }
   if (fileNode* file_node = dynamic_cast<fileNode*>(file)) {
      fstream *f = file_node->get();
      (*f) << (strvalue_ = stringNode::to_str(str));
      if (isstr) f->close();
   } else {
      cerr << "Incorrect file" << endl;
   }
   if (isstr) delete file;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//fappendNode
fappendNode::fappendNode (runNode * file, runNode*str): file_(file), str_ (str) {}

void fappendNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *file = file_, *str=str_;
   nexpNode::resolved(file);
   nexpNode::resolved(str);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   bool isstr = false;
   if (stringNode* strf = dynamic_cast<stringNode*>(file)) {
      strNode s_aux ("a+");
      s_aux.run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      file = new fileNode (strf, &s_aux);
      file->run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif      
      isstr = true;
   }
   if (fileNode* file_node = dynamic_cast<fileNode*>(file)) {
      fstream *f = file_node->get();
      f->clear();
      f->seekp (0, ios::end);
      f->seekg (0, ios::end);
      (*f) << (strvalue_ = stringNode::to_str(str));
      if (isstr) f->close();
   } else {
      cerr << "Incorrect file" << endl;
   }
   if (isstr) delete file;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//fseekNode
fseekNode::fseekNode (runNode * file, runNode* offset, int pos): file_(file), offset_ (offset), pos_(pos) {}

void fseekNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *file = file_, *offset = offset_;
   nexpNode::resolved(file);
   nexpNode::resolved(offset);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if (fileNode* file_node = dynamic_cast<fileNode*>(file)) {
      fstream *f = file_node->get();
      f->clear();
      f->seekg (arithNode::to_num(offset), ((pos_ == 0)?ios::beg:((pos_ == 1)?ios::cur:ios::end)));
      f->seekp (arithNode::to_num(offset), ((pos_ == 0)?ios::beg:((pos_ == 1)?ios::cur:ios::end)));
      boolvalue_ = true;
      
   } else {
      cerr << "Incorrect file" << endl;
      boolvalue_ = false;
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif   
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//ftellNode
ftellNode::ftellNode (runNode * file): file_(file) {}

void ftellNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *file = file_;
   nexpNode::resolved(file);
   if (fileNode* file_node = dynamic_cast<fileNode*>(file)) {
      fstream *f = file_node->get();
      numvalue_ = f->tellg ();
   } else {
      numvalue_ = 0;
      #if JSON==1
         interpreter::to_jsonSetValue(this, numvalue_);
      #endif      
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//fcloseNode
fcloseNode::fcloseNode (runNode * file): file_(file) {}

void fcloseNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *file = file_;
   nexpNode::resolved(file);
   if (fileNode* file_node = dynamic_cast<fileNode*>(file)) {
      fstream *f = file_node->get();
      f->close ();
      boolvalue_ = true;
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif      
   } else
      boolvalue_ = false;
      #if JSON==1
         interpreter::to_jsonSetValue(this, boolvalue_);
      #endif      
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
