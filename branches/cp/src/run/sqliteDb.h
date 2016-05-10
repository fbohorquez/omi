//sqliteDb.h
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
#ifndef _SQLITEDB_
#define _SQLITEDB_
#include <sqlite3.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include "typeNode.h"

using namespace std;



class db {
 public:
   static void connect ();

   static vector<string> keys (string table) {
      ostringstream oss;
      vector<string> values;
      sqlite3_stmt *stmt;
      oss << "pragma table_info ('" << table << "')";
      if (sqlite3_prepare_v2(db::db_, oss.str().c_str(), -1, &stmt, NULL) == SQLITE_OK) {
         while(sqlite3_step(stmt) == SQLITE_ROW) {
            values.push_back (std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))));
         }
      }
      return values;
   }

   static vector<vector<string> > keys_type (string table) { // { {'key0', 'type0'}, ..., {'keyn', 'typen'}}
      ostringstream oss;
      vector<vector<string> > values;
      sqlite3_stmt *stmt;
      oss << "pragma table_info ('" << table << "')";
      if (sqlite3_prepare_v2(db::db_, oss.str().c_str(), -1, &stmt, NULL) == SQLITE_OK) {
         sqlite3_step(stmt);
         while(sqlite3_step(stmt) == SQLITE_ROW) {
            vector<string> v;
            v.push_back (std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))));
            v.push_back (std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))));
            values.push_back (v);
         }
      }
      return values;
   }

   static bool exist_table (string table, string db = "") {
      ostringstream oss, oss_db;
      sqlite3_stmt *stmt;
      if (db != "")
         oss_db << db << ".";
      oss << "SELECT name FROM " << oss_db.str() << "sqlite_master WHERE type='table' AND name='" << table << "';";
      cerr << " -- debug: " << oss.str() << endl;
      return (sqlite3_prepare_v2(db::db_, oss.str().c_str(), -1, &stmt, NULL) == SQLITE_OK && sqlite3_step(stmt) == SQLITE_ROW );
   }

   static vector<vector<string> > query (string q, bool get_errors = true) {
      sqlite3_stmt *stmt;
      vector<string> values;
      int e;
      cerr << " -- debug: " << q.c_str() << endl;
      vector<vector<string> > resp;
      if ((e = sqlite3_prepare_v2(db::db_, q.c_str(), -1, &stmt, 0 )) == SQLITE_OK ) {

         int ctotal = sqlite3_column_count(stmt);
         int res = 0;
         while ( (e = sqlite3_step(stmt)) == SQLITE_ROW ) {
            vector<string> v;

            for ( int i = 0; i < ctotal; i++ ) {
               v.push_back (
                  (sqlite3_column_text(stmt, i))
                  ?((char*)sqlite3_column_text(stmt, i))
                  :""
               );
            }
            resp.push_back (v);
         }

         if (e == SQLITE_ERROR && get_errors)
            cerr << " -- debug: " << sqlite3_errstr(e) << endl;
         sqlite3_finalize(stmt);
      } else if (e == SQLITE_ERROR && get_errors) {
         cerr << " -- debug: " << sqlite3_errstr(e) << endl;
      }

      return resp;
   }


   static string lastid () {
      int a = sqlite3_last_insert_rowid(db::db_);
      stringstream ss;
      ss << a;
      return ss.str();
   }
   static int num_changes () {
      return sqlite3_changes(db::db_);
   }
   static string attach_database  (string db) {
      ostringstream oss;
      if (attach_db.find (db) == attach_db.end()) {
         oss << "ATTACH DATABASE '" << db << "' AS database" << attach_count << ";";
         db::query(oss.str());
         oss.str("");
         oss << "database" << attach_count;
         attach_db[db] = attach_count;
         attach_count ++;
      } else
         oss << "database" << attach_db[db];
      return oss.str();
   }
   static string fieldslist (arrayNode *a, bool second = false, string sep = " ", bool quote = false, string prefix = "");
   static string valueslist (arrayNode *a);
   static string create (string table, string list, bool mem = false);
   static string create (string table, arrayNode *a, bool mem = false);
   static string select (string table, arrayNode *a, string where = "");
   static string select (string table, string list, string where = "", bool id = true);
   static string update (string table, arrayNode *a, string where = "");
   static string update (string table, string list, string where = "");
   static string delrow (string table, string where = "");
   static string insert (string table, arrayNode *a);
   static string insert (string table, string fields, string values) ;
   static string add_column (string table, string name, string type);
   static string add_columns (string table, map<string, string> m);
   static void close () {
      sqlite3_close(db::db_);
   }
 private:
   static sqlite3 *db_;
   static string name;
   static int attach_count;
   static map<string, int> attach_db;
};
#endif
