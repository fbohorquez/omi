#include "sqliteDb.h"
#include "runTree.h"
#include "stmtNode.h"
#include "typeNode.h"
#include "componentNode.h"
#include <boost/regex.hpp>
string db::name = ":memory:";
//~ string db::name = "data.db";
sqlite3 *db::db_;
int db::attach_count = 0;
map<string,int> db::attach_db;


static void ck(sqlite3_context *context, int argc, sqlite3_value **argv) {
   checkFunction ck;
   ostringstream oss;
   for (int i = 0; i < argc; ++i) {
      oss.str("");
      oss << sqlite3_value_text(argv[i]);
      ck.params.push_back(oss.str());
   }
   sqlite3_result_int (context, ck.check());
}

void db::connect () {
   remove (db::name.c_str());
   if( sqlite3_open(db::name.c_str(), &db::db_) ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db::db_));
      return ;
   }
   sqlite3_create_function(db::db_, "ck", -1, SQLITE_UTF8, NULL, &ck, NULL, NULL);
}

string db::fieldslist (arrayNode *a, bool second , string sep, bool quote, string prefix) {

   ostringstream oss;
   symbols*m = a->getArray ();
   isym iter, last, aux;
   if (m->begin() != m->end()) {
      last = m->end(); last --;
   }

   for ( iter = m->begin(); iter != m->end(); ++iter) {
      if (dataCNode::isData (iter.second)) {
         oss << prefix << stringNode::to_str (iter.first) << sep;         
         stringNode *s;
         runNode * str = iter.second, *straux = NULL;
         if (second && dynamic_cast<defCNode*> (str)) {
            straux = new strNode ("INT");
            str = straux;
         } else if (dataCNode* d = dynamic_cast<dataCNode*> (str)) {
            straux = new strNode (d->id);
            str = straux;
         }
         if (((s = dynamic_cast<stringNode*>(str)) && s->is_numvalue ()) ||  !str->is_string())
            oss << (second?stringNode::to_str (str):"");
         else
            oss << (quote?"'":"") << (second?stringNode::to_str (str):"") << (quote?"'":"");
         aux = iter; aux ++;
         while (aux != last && !dataCNode::isData (aux.second)) aux ++;
         if (iter != last  && !(aux == last && !dataCNode::isData (aux.second))) oss <<  ", ";
         if (straux) delete straux;
      }
   }
   return oss.str();
}


string db::valueslist (arrayNode *a) {
   ostringstream oss;

   symbols*m = a->getArray ();
   isym iter, last, aux;
   if (m->begin() != m->end()) {
      last = m->end(); last --;
   }

   for ( iter = m->begin(); iter != m->end(); ++iter) {
      if (!dynamic_cast<fexpNode*> (iter.second)) {
         stringNode *s;
         runNode * str = iter.second, *straux = NULL;
         if (dataCNode* d = dynamic_cast<dataCNode*> (str)) {
            straux = new strNode (d->id);
            str = straux;
         }

         if (((s = dynamic_cast<stringNode*>(str)) && s->is_numvalue ()) ||  !str->is_string())
            oss << stringNode::to_str (str);
         else
            oss << "'" << stringNode::to_str (str) << "'";

         aux = iter; aux ++;
         while (aux != last && dynamic_cast<fexpNode*> (aux.second)) {
            aux ++;
         }

         if (iter != last && !(aux == last && dynamic_cast<fexpNode*> (aux.second)))
            oss <<  ", ";
      }

   }
   return oss.str();
}

string db::create (string table, string list, bool mem) {
   ostringstream oss;
   oss << "CREATE " << (mem?"TEMPORARY ":"") << "TABLE " << table << " ( "
       << "id INTEGER PRIMARY KEY, " << list << ");";
   return oss.str();
}

string db::create (string table, arrayNode *a, bool mem) {
   return db::create (table, db::fieldslist (a, true), mem);
}

string db::select (string table, arrayNode *a, string where) {
   return db::select (table, fieldslist (a), where);
}

string db::select (string table, string list, string where, bool id) {
   regex e = regex ("^\\s*ORDER.*");
   cmatch what;
   ostringstream oss;
   oss << "SELECT " << (id?"id, ":"")
       << list
       << " FROM "
       << table
       << ((where != "" && !regex_match(where.c_str(), what, e))?" WHERE ":"")
       << ((where != "")?where:"") << " ;";
   return oss.str();
}

string db::update (string table, arrayNode *a, string where) {
   return db::update (table, fieldslist (a, true, " = ", true), where);
}

string db::update (string table, string list, string where) {
   ostringstream oss;
   oss << "UPDATE " << table
       << " SET " << list
       << ((where != "")?" WHERE ":"")
       << ((where != "")?where:"") << " ;";
   return oss.str();
}


string db::delrow (string table, string where) {
   ostringstream oss;
   oss << "DELETE FROM " << table
       << ((where != "")?" WHERE ":"")
       << ((where != "")?where:"") << " ;";
   return oss.str();
}

string db::insert (string table, arrayNode *a) {
   return db::insert (table, fieldslist (a), valueslist(a));
}

string db::insert (string table, string fields, string values) {
   ostringstream oss;
   oss << "INSERT INTO " << table << " (" << fields << ") VALUES (" << values << ");";
   return oss.str();
}

string db::add_column (string table, string name, string type) {
   ostringstream oss;
   oss << "ALTER TABLE " << table << " ADD COLUMN " << name << " " << type << ";";
   return oss.str();
}

string db::add_columns (string table, map<string, string> m) {
   ostringstream oss;
   map<string, string>::iterator iter;
   for (iter = m.begin(); iter != m.end(); ++iter)
      oss << db::add_column (table, iter->first, iter->second) << " ";
   return oss.str();
}
