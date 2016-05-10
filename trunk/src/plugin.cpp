//plugin.cpp
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
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <dlfcn.h>

#include "plugin.h"

using namespace std;

PluginsLoader *libs = PluginsLoader::getPluginsLoader ();
PluginsLoader* PluginsLoader::singleton = NULL;
bool	PluginLoader::load (const char* name, PluginsLoader* pls) {
   if (m_libHandler != NULL) {
      unload();
   }
   m_libHandler = dlopen(name, RTLD_LAZY | RTLD_GLOBAL);
   if (m_libHandler == NULL) {
      cerr  << dlerror() << endl;
      return false;
   } else {
      char* err = NULL;
      
      void(*load)(PluginsLoader*) = (void (*)(PluginsLoader*)) dlsym(m_libHandler, "load");
      if ( (err = dlerror()) != NULL) {
         std::cout << "Unable to load symbol \"load\" from library " << name << ": " << err << std::endl;
         unload();
         return false;
      }

      (*load)(pls);
      return true;
   }
}
//----------------------------------------------------------------------


void PluginLoader::unload () {
   if (m_libHandler != NULL) {
      char* err = NULL;

      void (*unload)(void) = (void (*)()) dlsym(m_libHandler, "unload");
      (*unload)();

      dlclose(m_libHandler);
      m_libHandler=NULL;
   }
}
//----------------------------------------------------------------------
PluginsLoader::PluginsLoader () {
   string name;
   ostringstream o (ostringstream::out);
   o <<  DATADIR << "/omi/libs.ini";
   ifstream fe(o.str().c_str());
   if (fe) {
      while(true) {
         PluginLoader * plugin = new PluginLoader ();
         getline(fe,name);
         if (fe.eof()) break;
         if (name.c_str()[0] != ';' && name.length() > 0){
            
            plugin->load(name.c_str(), this);
            libs.push_back (plugin);
         }
      }
   }
   fe.close();
}
//----------------------------------------------------------------------

loadNode::loadNode (runNode* module) : module_(module) {}

void loadNode::run () {
   runNode *module = module_;
   nexpNode::resolved (module)->run();
   PluginLoader * plugin = new PluginLoader ();
   plugin->load((stringNode::to_str(module)).c_str(), libs);
   libs->addPlugin (plugin);
}
