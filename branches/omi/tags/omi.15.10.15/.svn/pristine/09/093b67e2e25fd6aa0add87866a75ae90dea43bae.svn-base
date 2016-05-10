//plugin.h
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
#ifndef _PLUGIN_
#define _PLUGIN_
#include <vector>
#include "run/runTree.h"
#include "run/typeNode.h"
using namespace std;
//----------------------------------------------------------------------
/**
 * \file plugin.h
 * \brief Cargador de módulos dinámicos
 *
 * Este módulo es el encargado de cargar de forma dinámica módulos funcionales
 * del programa.
 *
 * Liesh utiliza módulos dinámicos para los siguientes casos:
 *
 * - Defición de operaciones y tipos de datos de los distintos protocolos de red en
 * la capa de aplicación.
 *
 * Se define una clase que cargará de forma dinámica los módulos. Para ello
 * lee de un fichero en disco la ruta y nombre de los módulos.
 *
 */
//----------------------------------------------------------------------
class PluginsLoader;
//----------------------------------------------------------------------
/**
 * \class PluginLoader
 * \brief Cargador de módulo dinámico
 *
 * Esta clase se encarga de cargar un módulo dinámico
 * dado. Para ello llama a la función load del módulo.
 */
class PluginLoader {
   void* m_libHandler;

 public:
   PluginLoader () : m_libHandler(NULL) {}

   bool	load (const char* name, PluginsLoader* pls);
   void	unload ();
};
//----------------------------------------------------------------------
/**
 * \class PluginsLoader
 * \brief Cargador de módulos dinámicos
 *
 * Esta clase se encarga de cargar de cargar los módulos dinámicos
 * especificados en el fichero de configuración libs.
 */
class PluginsLoader {
   map<string, runNode*(*)(listNode*)> creates;
 public:
   vector<PluginLoader*> libs;
   PluginsLoader ();
   void add (string key,runNode*(*val)(listNode*)) {
      creates[key] = val;
   }
   runNode *get (string key, listNode *list) {
      if (creates.find(key) != creates.end()) {
         runNode*(*func)(listNode*) = creates [key];
         return (*func)(list);
      } else {
         return NULL;
      }
      return NULL;
   }
};
//----------------------------------------------------------------------
//~ /**
 //~ * \class pluginNode
 //~ * \brief Nodo dinámico
 //~ *
 //~ * Esta clase se encarga de cargar de cargar los módulos dinámicos
 //~ * especificados en el fichero de configuración libs.
 //~ */
//~ class pluginNode : public nexpNode {
 //~ public:
   //~ static runNode *create (listNode* list) {}
//~ };
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * \class loadNode
 * \brief Nodo carga librería dinámica
 *
 */
class loadNode : public logicNode {
 public:
   loadNode (runNode* module);
   void run();
 private:
   runNode *module_;
};
//----------------------------------------------------------------------
extern PluginsLoader *libs;
#endif
