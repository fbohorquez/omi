//typeNode.cpp
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
#include "mysql-ext.h"
#include "../src/run/stmtNode.h"


extern "C" void load (PluginsLoader* loader) {
    loader->add ("connect", dbConnectNode::create);
    loader->add ("query", dbQueryNode::create);
    loader->add ("select", dbSelectNode::create);
    loader->add ("insert", dbInsertNode::create);
    loader->add ("update", dbUpdateNode::create);
    loader->add ("delete", dbDeleteNode::create);
}

//----------------------------------------------------------------------
//dbNode


dbNode* dbNode::global_ = NULL;

dbNode::dbNode (
  string host, 
  string user, 
  string password, 
  string database,
  unsigned int port
) : 
  host_ (host),
  user_ (user),
  password_ (password),
  database_ (database),
  port_ (port),
  sql_ (NULL), 
  field_table_ ("s"){}

dbNode::dbNode (dbNode* db) : 
  host_ (db->host_),
  user_ (db->user_),
  password_ (db->password_),
  database_ (db->database_),
  port_ (db->port_),
  sql_ (NULL), 
  field_table_ ("s"){this->run ();}

void dbNode::run (){
  
  sql_ = mysql_init(NULL);
  
  if (sql_ == NULL) {
      throw errorException ("Impossible to initiate database", "dbNode: int database system", 0);
  }

  if (mysql_real_connect(sql_, host_.c_str(), user_.c_str(), 
          password_.c_str(), database_.c_str(), port_, NULL, 0) == NULL) {
      throw errorException ("Can't connect to database", "dbNode: connect database system", 0);
  }
  
}

dbNode::~dbNode () {
  if (global_ == this){
    global_ = NULL;
  }
  //~ mysql_close(sql_);
}

dbNode* dbNode::getGlobal () { 
  return global_; 
}

void dbNode::setGlobal (runNode* global) { 
  
  if (global_ = dynamic_cast<dbNode*> (global)){
    idNode *id = new idNode ("db");
    id->run ();

    asigNode a (id, global);
    a.run();
  }
} 

runNode* dbNode::tableFieldTable (runNode *node){
  if (strNode* s_node = dynamic_cast<strNode*> (node)){
    string s = s_node->strvalue ();
    int pos;
    if (((pos = s.find (":")) != string::npos) || ((pos = s.find ("@")) != string::npos)) {
       return new strNode (s.substr (pos + 1, s.size() - pos));
    }else{
      return new strNode (s);
    }
  }
  else if (refNode* s_node = dynamic_cast<refNode*> (node)){
    string s = s_node->strvalue ();
    int pos;
    if (((pos = s.find (":")) != string::npos) || ((pos = s.find ("@")) != string::npos)) {
       return new strNode (s.substr (pos + 1, s.size() - pos));
    }else{
      return new strNode (s);
    }
  }else{
    throw errorException ("Wrong type", "dbNode: node must be string", 1);
  }
}

string dbNode::fieldFieldTable (runNode *node){
  if (strNode* s_node = dynamic_cast<strNode*> (node)){
   
    string s = s_node->strvalue ();
    int pos;
    if (((pos = s.find (":")) != string::npos) || ((pos = s.find ("@")) != string::npos)) {
         
       return s.substr (0, pos);
    }else{ 
        return s;
    }
  }
  else if (refNode* s_node = dynamic_cast<refNode*> (node)){
    string s = s_node->strvalue ();
    int pos;
    if (((pos = s.find (":")) != string::npos) || ((pos = s.find ("@")) != string::npos)) {
       return s.substr (0, pos);
    }else{ 
        return s;
    }
  }else{
    throw errorException ("Wrong type", "dbNode: node must be string", 1);
  }
}
      
bool dbNode::isFieldTable (runNode *node){
  if (strNode* s_node = dynamic_cast<strNode*> (node)){
    string s = s_node->strvalue ();
    return 
      (s.find (":") != string::npos) || 
      (s.find ("@") != string::npos);
  }
  else if (refNode* s_node = dynamic_cast<refNode*> (node)){
    string s = s_node->strvalue ();
    return 
      (s.find (":") != string::npos) || 
      (s.find ("@") != string::npos);
  }else{
    throw errorException ("Wrong type", "dbNode: node must be string", 1);
  }
}
      
bool dbNode::isSelectTable (runNode *node){
  if (strNode* s_node = dynamic_cast<strNode*> (node)){
    string s = s_node->strvalue ();
    return s.find ("@") != string::npos;
  }else if (refNode* s_node = dynamic_cast<refNode*> (node)){
    string s = s_node->strvalue ();
    return s.find ("@") != string::npos;
  }else{
    throw errorException ("Wrong type", "dbNode: node must be string", 1);
  }
}

void dbNode::connectBD (string db){
  mysql_close(sql_);
  database_ = db;
  run ();
}
      
//----------------------------------------------------------------------
//dbConnectNode
runNode* dbConnectNode::create (listNode* list){
	
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 5) 
			return new dbConnectNode (v[0], v[1], v[2], v[3], v[4]);
		else if (v.size () == 4) 
			return new dbConnectNode (v[0], v[1], v[2], v[3], new numNode ((double)0));
		else if (v.size() == 3) 
			return new dbConnectNode (v[0], v[1], v[2], new strNode (""), new numNode ((double)0));
		else if (v.size() ==2) 
			return new dbConnectNode (v[0], v[1]);
		else
			cerr << "Wrong number parameters" << endl;
		return NULL;
			
	}	
}

dbConnectNode::dbConnectNode (
  runNode* host, 
  runNode* user, 
  runNode* password, 
  runNode* database,
  runNode* port
): 
  host_ (host),
  user_ (user),
  password_ (password),
  database_ (database),
  port_ (port),
  conn_(NULL),
  add_(NULL) {}
      
dbConnectNode::dbConnectNode (runNode* conn, runNode* add): 
  host_ (NULL),
  user_ (NULL),
  password_ (NULL),
  database_ (NULL),
  port_ (NULL),
  conn_(conn),
  add_(add) {}
  
void dbConnectNode::run (){
  if (host_)
    run_ini();
  else
    run_add();
}

void dbConnectNode::run_ini (){
  runNode 
    *node_aux1 = host_,
    *node_aux2 = user_,
    *node_aux3 = password_,
    *node_aux4 = database_,
    *node_aux5 = port_;
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux1)){
    n_exp->run();
    node_aux1 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux2)){
    n_exp->run();
    node_aux2 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux3)){
    n_exp->run();
    node_aux3 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux4)){
    n_exp->run();
    node_aux4 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux5)){
    n_exp->run();
    node_aux5 = n_exp->nodeval ();
  }
  node_aux1->run();
  node_aux2->run();
  node_aux3->run();
  node_aux4->run();
  node_aux5->run();
  strNode 
    *s_host_node = NULL,
    *s_user_node = NULL,
    *s_password_node = NULL,
    *s_database_node = NULL;
  numNode *n_port_node = NULL; 
  if (!(s_host_node = dynamic_cast<strNode*> (node_aux1)))
     throw errorException ("Wrong type", "dbConnectNode: host must be string", 1);
  if (!(s_user_node = dynamic_cast<strNode*> (node_aux2)))
     throw errorException ("Wrong type", "dbConnectNode: user must be string", 1);

  if (!(s_password_node = dynamic_cast<strNode*> (node_aux3)))
     throw errorException ("Wrong type", "dbConnectNode: password must be string", 1);

  if (!(s_database_node = dynamic_cast<strNode*> (node_aux4)))
     throw errorException ("Wrong type", "dbConnectNode: database must be string", 1);

  if (!(n_port_node = dynamic_cast<numNode*> (node_aux5)))
     throw errorException ("Wrong type", "dbConnectNode: port must be unsigned int", 1);
  else
    if (n_port_node->numvalue () != (int)n_port_node->numvalue () || n_port_node->numvalue () < 0)
      throw errorException ("Wrong type", "dbConnectNode: port must be unsigned int", 1);
  
  noderef(new dbNode (
    s_host_node->strvalue(), 
    s_user_node->strvalue(), 
    s_password_node->strvalue(), 
    s_database_node->strvalue(), 
    n_port_node->numvalue ())
  );
  nodeval()->run();
  dbNode::setGlobal (nodeval());
}

void dbConnectNode::run_add (){
  runNode 
    *node_aux1 = conn_,
    *node_aux2 = add_;
  if (!node_aux1){
    if (!(node_aux1 = dbNode::getGlobal ()))
      throw errorException ("Not connected to database", "dbQueryNode: database is null", 1);
  }  
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux1)){
    n_exp->run();
    node_aux1 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux2)){
    n_exp->run();
    node_aux2 = n_exp->nodeval ();
  }
  node_aux1->run();
  node_aux2->run();

  dbNode *conn_node = NULL;
  strNode *add_node = NULL;
   
  if (!(conn_node = dynamic_cast<dbNode*> (node_aux1)))
     throw errorException ("Wrong type", "dbConnectNode: conn must be database connection", 1);
  if (!(add_node = dynamic_cast<strNode*> (node_aux2)))
     throw errorException ("Wrong type", "dbConnectNode: add must be string", 1);
  //~ conn_node->connectBD (add_node->strvalue());
  //~ nodeR_ = conn_node;
  noderef(new dbNode (
    conn_node->getHost (),
    conn_node->getUser (),
    conn_node->getPassword (),
    add_node->strvalue(),
    conn_node->getPort ()
  ));
  nodeval()->run();
  dbNode::setGlobal (nodeval());
}
//~ 
//~ runNode* dbConnectNode::nodeval () const{
  //~ return nodeR_;
//~ }
//~ 
//~ runNode** dbConnectNode::ref (){
  //~ return &nodeR_;
//~ }
//~ 
//~ void dbConnectNode::noderef (runNode* node){
  //~ nodeR_ = node;
//~ }

//----------------------------------------------------------------------
//dbQueryNode
runNode* dbQueryNode::create (listNode* list){
	
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 2) 
			return new dbQueryNode (v[0], v[1]);
		else if (v.size () == 1) 
			return new dbQueryNode (NULL, v[0]);
		else
			cerr << "Wrong number parameters" << endl;
		return NULL;
			
	}
}
	
dbQueryNode::dbQueryNode (
  runNode* db, 
  runNode* query
):
  db_ (db), query_(query){}

void dbQueryNode::run (){
  runNode 
    *node_aux1 = db_,
    *node_aux2 = query_;
  if (!node_aux1){
    if (!(node_aux1 = dbNode::getGlobal ()))
      throw errorException ("Not connected to database", "dbQueryNode: database is null", 1);
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux1)){
    n_exp->run();
    node_aux1 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux2)){
    n_exp->run();
    node_aux2 = n_exp->nodeval ();
  }
  node_aux1->run();
  node_aux2->run();
  dbNode* db_node = NULL; 
  strNode* sn_query = NULL;
  if (!(db_node = dynamic_cast<dbNode*> (node_aux1))){
    throw errorException ("Wrong type", "dbQueryNode: database must be dbNode", 1);
  } 
  if (!(sn_query = dynamic_cast<strNode*> (node_aux2))){
    throw errorException ("Wrong type", "dbQueryNode: query must be string", 1);
  }
  if(MYSQL* conn = db_node->getSQL ()){
    if (mysql_query(conn, sn_query->strvalue().c_str())){
      ostringstream os (ostringstream::out);
      os << mysql_error(conn) << " (" << mysql_errno(conn) << ") "; 
      cerr << sn_query->strvalue() << endl; 
      throw errorException (mysql_error(conn), os.str(), 1);
    }
    noderef(new boolNode (true));
  }
  
}

//----------------------------------------------------------------------      
//dbInsertNode
runNode* dbInsertNode::create (listNode* list){
	
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 3) 
			return new dbInsertNode (v[0], v[1], v[2]);
		else if (v.size () == 2) 
			return new dbInsertNode (NULL, v[0], v[1]);
		else if (v.size () == 1) 
			return new dbInsertNode (NULL, NULL, v[0]);
		else
			cerr << "Wrong number parameters" << endl;
		return NULL;
			
	}
}

dbInsertNode::dbInsertNode (
  runNode* db, 
  runNode* table_ini,
  runNode* values
):
  db_ (db), 
  table_ini_(table_ini), 
  values_ (values) {}

bool dbInsertNode::multi = false;


void dbInsertNode::run (){
  runNode 
    *node_aux1 = db_,
    *node_aux2 = table_ini_,
    *node_aux3 = values_;
  if (!node_aux1){
    if (!(node_aux1 = dbNode::getGlobal ()))
      throw errorException ("Not connected to database", "dbQueryNode: database is null", 1);
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux1)){
    n_exp->run();
    node_aux1 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux2)){
    n_exp->run();
    node_aux2 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux3)){
    n_exp->run();
    node_aux3 = n_exp->nodeval ();
  }
  //~ node_aux1->run();
  node_aux3->run();
  if (node_aux2){ 
    node_aux2->run();
  }
  dbNode* db_node = NULL; 
  strNode* s_table_node = NULL;
  arrayNode* a_values_node = NULL;
  if (!(db_node = dynamic_cast<dbNode*> (node_aux1))){
    throw errorException ("Wrong type", "dbQueryNode: database must be dbNode", 1);
  } 
  //~ if (node_aux2)
    //~ node_aux2 = db_node->tableFieldTable (node_aux2);

  if (!(s_table_node = dynamic_cast<strNode*> (node_aux2))){
     
      if (a_values_node = dynamic_cast<arrayNode*> (node_aux3)){
        //No se ha especificado tabla
        isym iter;
        symbols* map = a_values_node->getArray ();
        vector<listNode*> ids;
        for (iter = map->begin (); iter != map->end(); iter ++){
          runNode* value;
          multi = false;
          if (!db_node->isSelectTable (iter.first)){
            dbInsertNode insert (db_node, iter.first, iter.second);
            insert.run ();
            value = insert.nodeval ();
          }
          else {
             
            value = select (db_node, iter.first, iter.second);
          }
          ids.push_back (new listNode (new mapNode (db_node->tableFieldTable(iter.first),value)));
        }
        listNode* list_ = NULL;
        cerr << "---- size : " << ids.size() <<  endl;
        for (int i = ids.size() -1; i >= 0 ; --i){
          list_ = new listNode(ids [i], list_); 
        }
        noderef(new arrayNode (list_));
      }
  }else {
      
     //Se ha especificado tabla
     if (a_values_node = dynamic_cast<arrayNode*> (node_aux3)){
        if (a_values_node->getCount () == 0){
          
          //El array no es numérico
          isym iter;
          symbols* map_a= a_values_node->getArray ();
          multi = true;
          vector<runNode*>multis_values;
          vector<runNode*>multis_tables;
          vector<runNode*>multis_names;
          ostringstream 
            key (ostringstream::out), 
            values (ostringstream::out);
          bool inverse = false;
          for (iter = map_a->begin (); iter != map_a->end(); iter ++){
            
            if (db_node->isFieldTable (iter.first)){
              runNode* value;
              if (!db_node->isSelectTable (iter.first)){
                cerr << "1=============================" << endl;
                dbInsertNode insert (db_node, iter.first, iter.second);
                insert.run ();
                value = insert.nodeval ();
                value->run();
                cerr << "1=============================" << endl;
                typeofNode::type(iter.first);
                typeofNode::type(iter.second);
                typeofNode::type(value);
              }
              else {
                 
                value = select (db_node, iter.first, iter.second);
              }
              
              strNode* s_value = NULL;
              if (value){
                if (key.str() != "")
                  key << ", " << db_node->fieldFieldTable (iter.first);
                else
                  key << db_node->fieldFieldTable (iter.first);
                
                
                cerr << dynamic_cast<strNode*> (value) << " ----> " << dynamic_cast<refNode*> (value) << endl;
                if (numNode* n_value = dynamic_cast<numNode*> (value)){
                  ostringstream out (ostringstream::out);
                  out << n_value->numvalue ();
                  s_value = new strNode (out.str());
                }else if (s_value = dynamic_cast<strNode*> (value)){
                   
                  ostringstream out (ostringstream::out);
                  out << "\"" << s_value->strvalue() << "\"";
                  s_value = new strNode (out.str());
                }else if (refNode *r_value = dynamic_cast<refNode*> (value)){
                   
                  ostringstream out (ostringstream::out);
                  out << "\"" << r_value->strvalue() << "\"";
                  s_value = new strNode (out.str());
                }else{
                    throw errorException ("Wrong value", "dbInsertNode: value must be string", 1);
                }if (values.str()  != "")
                  values << ", " << s_value->strvalue ();
                else
                 values << s_value->strvalue ();
             }else{
              multis_tables.push_back (node_aux2);
              multis_values.push_back (iter.second);
              multis_names.push_back (iter.first);
              inverse = true;
             }
               
            }else {
              
              if (key.str() != "")
                key << ", " << db_node->fieldFieldTable (iter.first);
              else
                key << db_node->fieldFieldTable (iter.first);
              
              runNode* value = iter.second;
              strNode* s_value = NULL;
              if (numNode* n_value = dynamic_cast<numNode*> (value)){
                ostringstream out (ostringstream::out);
                out << n_value->numvalue ();
                s_value = new strNode (out.str());
              }else if (s_value = dynamic_cast<strNode*> (value)){
                ostringstream out (ostringstream::out);
                out << "\"" << s_value->strvalue() << "\"";
                s_value = new strNode (out.str());
              }else if (refNode* r_value = dynamic_cast<refNode*> (value)){
                ostringstream out (ostringstream::out);
                out << "\"" << r_value->strvalue() << "\"";
                s_value = new strNode (out.str());
              }else
                if (!inverse){
                  throw errorException ("Wrong value", "dbInsertNode: value must be string", 1);
                }
              if (values.str() != "")
                values << ", " << s_value->strvalue ();
              else
               values << s_value->strvalue ();
              
            }
          }
          if (values.str() != "" && key.str()!= "" && s_table_node->strvalue () != ""){
            //Inserccion de relaciones simples
            ostringstream query (ostringstream::out);
            strNode * table = dynamic_cast<strNode*> (db_node->tableFieldTable (s_table_node));
            query << "INSERT INTO " << table->strvalue() << " ( " << key.str() << " ) VALUES ( " << values.str() << ") ";  
             cerr << query.str() << endl;
            MYSQL* conn;
            int id;
            if(conn = db_node->getSQL ()){
              cerr << query.str() << endl;
              if (mysql_query(conn, query.str().c_str())){
                ostringstream os (ostringstream::out);
                os << mysql_error(conn) << " (" << mysql_errno(conn) << ") ";  
                throw errorException (mysql_error(conn), os.str(), 1);
              }
              id = mysql_insert_id(conn);
              noderef(new numNode (mysql_insert_id(conn)));
            }
            if (inverse){
              //Inserccion de relaciones múltiples
              inverse = false;
              
              for (int i = 0; i < multis_values.size(); ++i){
                runNode 
                  *m_table = multis_tables[i],
                  *m_value = multis_values[i],
                  *m_name = multis_names[i];
                if (arrayNode *array_values = dynamic_cast<arrayNode*> (m_value)){
                  symbols* maped;
                  maped = array_values->getArray ();
                  if (array_values->getCount()) {
                    isym iter;
                    for (iter = maped->begin(); iter != maped->end(); iter ++){
                      if (arrayNode *array_value = dynamic_cast<arrayNode*> (iter.second)){
                        array_value->insert (new strNode (db_node->fieldFieldTable (m_name)), new numNode (id));
                        multi = false;
                        dbInsertNode insert (db_node, db_node->tableFieldTable (m_name), array_value);
                        insert.run();
                      }
                    }
                  }

                  
                } 
              }
            }
          }
         
        }else{

          //El array es numérico
          if (!multi){
            //Si es el array inicial
            multi = true;
            symbols* map = a_values_node->getArray ();
            vector<listNode*> ids;
            for (isym iter = map->begin(); iter != map->end(); iter++){
              if (numNode* n_value = dynamic_cast<numNode*> (iter.first)){
                runNode *value;
                if (!(db_node->isSelectTable (s_table_node))){
                  dbInsertNode insert (db_node, s_table_node, iter.second);
                  insert.run ();
                  value = insert.nodeval ();
                }else{
                  value = select (db_node, s_table_node, iter.second);
                }
                ids.push_back (new listNode (value)); 
              }
            }
            listNode* list_ = NULL;
            for (int i = ids.size() -1; i >= 0 ; --i){
              list_ = new listNode(ids [i], list_); 
            }
            noderef(new arrayNode (list_));
            multi = false;
          }else{
            noderef(NULL);
          }
        }
     }
  }
}


runNode* dbInsertNode::select (runNode* db, runNode* table, runNode* values){
  runNode 
    *node_aux1 = db,
    *node_aux2 = table,
    *node_aux3 = values;

  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux1)){
    n_exp->run();
    node_aux1 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux2)){
    n_exp->run();
    node_aux2 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux3)){
    n_exp->run();
    node_aux3 = n_exp->nodeval ();
  }
 
  dbNode *db_node = NULL;
  strNode *table_node = NULL;
  arrayNode *val_node = NULL;
  if (!(db_node = dynamic_cast<dbNode*> (node_aux1)))
    throw errorException ("Wrong type", "dbInsertNode: database must be dbNode", 1);
  if (!(table_node = dynamic_cast<strNode*> (db_node->tableFieldTable(node_aux2))))
    throw errorException ("Wrong type", "dbInsertNode: table must be string", 1);
  if (!(val_node = dynamic_cast<arrayNode*> (node_aux3)))
    throw errorException ("Wrong type", "dbInsertNode: values must be array", 1);
  MYSQL* conn;
  MYSQL_RES *result;
  MYSQL_ROW row;
  int num_fields;
  long int num_rows;
  if(conn = db_node->getSQL ()){
    ostringstream q_index (ostringstream::out);
    string index = "";
    q_index << "SHOW INDEX FROM ";
    q_index << table_node->strvalue ();
    q_index << " WHERE Key_name = \"PRIMARY\"";
    
    
    //Primary key
    cerr << q_index.str().c_str() << endl;
    if (mysql_query(conn, q_index.str().c_str())){
      ostringstream os (ostringstream::out);
      os << mysql_error(conn) << " (" << mysql_errno(conn) << ") ";  
      throw errorException (mysql_error(conn), os.str(), 1);
    }
    result = mysql_store_result(conn);
    num_fields = mysql_num_fields(result);
    
    if (num_fields != 0){
      while ((row = mysql_fetch_row(result))) {
        for(int i = 0; i < num_fields && index == ""; i++){
            MYSQL_FIELD *field;
            int count = 0;
            while((field = mysql_fetch_field(result))){
              ostringstream out (ostringstream::out);
              out << field->name;
              if (out.str() == "Column_name"){
                break;
              }
              count ++;
            }
            index = row[count];
        }
      }
    }
    else{
      throw errorException ("Table haven't PRIMARY KEY", "dbInsertNode: table must have PRIMARY KEY", 1);
    }
    mysql_free_result(result);
    //WHERE
    symbols* map = val_node->getArray (), *map_m;
    ostringstream q_where (ostringstream::out);
    
    for (isym iter = map->begin(); iter != map->end(); iter++){
      if (val_node->getCount () == 0){
        if (db_node->isFieldTable (iter.first)){
           runNode* value;
          
          if (!db_node->isSelectTable (iter.first)){
            dbInsertNode insert (db_node, db_node->tableFieldTable (iter.first), iter.second);
            insert.run ();
            value = insert.nodeval ();
          }
          else {
            value = select (db_node, db_node->tableFieldTable (iter.first), iter.second);
          }
          strNode* s_value = NULL;
          if (value){
            if (q_where.str() != "")
              q_where << "AND " << db_node->fieldFieldTable (iter.first) << " = ";
            else
              q_where << db_node->fieldFieldTable (iter.first) << " = ";
            
            if (numNode* n_value = dynamic_cast<numNode*> (value)){
              ostringstream out (ostringstream::out);
              out << n_value->numvalue ();
              s_value = new strNode (out.str());
            }else if (s_value = dynamic_cast<strNode*> (value)){
              ostringstream out (ostringstream::out);
              out << "\"" << s_value->strvalue() << "\"";
              s_value = new strNode (out.str());
            }else if (refNode * r_value = dynamic_cast<refNode*> (value)){
              ostringstream out (ostringstream::out);
              out << "\"" << r_value->strvalue() << "\"";
              s_value = new strNode (out.str());
            }else{
              throw errorException ("Wrong value", "dbInsertNode: value must be string", 1);
            }
            q_where << s_value->strvalue () << " ";
          }
        }else {
          runNode* value = iter.second;
          strNode* s_value = NULL;
          
          if (value){
            if (q_where.str() != "")
              q_where << "AND " << db_node->fieldFieldTable (iter.first) << " = ";
            else
              q_where << db_node->fieldFieldTable (iter.first) << " = ";
            
            typeofNode::type(value);
            if (numNode* n_value = dynamic_cast<numNode*> (value)){
              ostringstream out (ostringstream::out);
              out << n_value->numvalue ();
              s_value = new strNode (out.str());
            }else if (s_value = dynamic_cast<strNode*> (value)){
              ostringstream out (ostringstream::out);
              out << "\"" << s_value->strvalue() << "\"";
              s_value = new strNode (out.str());
            }else if (refNode *r_value = dynamic_cast<refNode*> (value)){
              ostringstream out (ostringstream::out);
              out << "\"" << r_value->strvalue() << "\"";
              s_value = new strNode (out.str());
            }else{
                throw errorException ("Wrong value", "dbInsertNode: value must be string", 1);
             }
            q_where << s_value->strvalue () << " ";
          }
        }
      }else{
        map_m = val_node->getArray ();
        vector<listNode*> ids;
        multi = true;
        for (isym iter_m = map_m->begin(); iter_m != map_m->end(); iter_m++){
          runNode* value;
          if (!db_node->isSelectTable (node_aux2)){
            dbInsertNode insert (db_node, node_aux2, iter_m.second);
            insert.run ();
            value = insert.nodeval ();
          }
          else {
            value = select (db_node, node_aux2, iter_m.second);
          }
          ids.push_back (new listNode (value));
        }
        multi = false;
        listNode* list_ = NULL;
        for (int i = ids.size() -1; i >= 0 ; --i){
          list_ = new listNode(ids [i], list_); 
        }
        return new arrayNode (list_);
      }
    }
    //SELECT
    ostringstream q_sel (ostringstream::out);
    ostringstream resp (ostringstream::out);
    q_sel << "SELECT ";
    q_sel << index;
    q_sel << " FROM ";
    q_sel << table_node->strvalue ();
    if (q_where.str() != ""){
       q_sel << " WHERE ";
       q_sel << q_where.str();
    }
    //~ cout << q_sel.str() << endl << endl;
    if (mysql_query(conn, q_sel.str().c_str())){
      ostringstream os (ostringstream::out);
      os << mysql_error(conn) << " (" << mysql_errno(conn) << ") ";  
      cerr << q_sel.str() << endl;
      throw errorException (mysql_error(conn), os.str(), 1);
    }
    result = mysql_store_result(conn);
    num_fields = mysql_num_fields(result);
    num_rows = mysql_num_rows (result);
    if (num_rows > 0){
      row = mysql_fetch_row(result);
      resp << row[0];
      strNode* str;
      str = new strNode (resp.str());
      str->run();
      return str;
    }
    else{
      dbInsertNode insert (db_node, table_node, val_node);
      insert.run();
      return insert.nodeval (); 
    }
  }else{
    throw errorException ("Not connect to database system", "dbInsertNode: database system not connect", 1);
  }
}

//---------------------------------------------------------------------- 

//----------------------------------------------------------------------
//dbSelectNode
runNode* dbSelectNode::create (listNode* list){
	
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 4)  {
			return new dbSelectNode (v[0], v[1], v[2], v[3]);
		}else if (v.size () == 3) 
			return new dbSelectNode (NULL, v[0], v[1], v[2]);
		else
			cerr << "Wrong number parameters" << endl;
		return NULL;
			
	}
}

dbSelectNode::dbSelectNode (runNode* db, runNode* tables, runNode* fields, runNode* values ):
  db_ (db),
  tables_ (tables),
  fields_ (fields),
  values_ (values) {}

void dbSelectNode::run (){
  runNode 
    *node_aux1 = db_,
    *node_aux2 = tables_,
    *node_aux3 = fields_,
    *node_aux4 = values_;
   
  if (!node_aux1){
    if (!(node_aux1 = dbNode::getGlobal ()))
      throw errorException ("Not connected to database", "dbQueryNode: database is null", 1);
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux1)){
    n_exp->run();
    node_aux1 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux2)){
    n_exp->run();
    node_aux2 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux3)){
    n_exp->run();
    node_aux3 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux4)){
    n_exp->run();
    node_aux4 = n_exp->nodeval ();
  }
  if (node_aux2) node_aux2->run();
  if (node_aux3) node_aux3->run();
  if (node_aux4) node_aux4->run();
  dbNode* db_node = NULL;
  if (!(db_node = dynamic_cast<dbNode*> (node_aux1))){
    throw errorException ("Wrong type", "dbQueryNode: database must be dbNode", 1);
  } 
  if (strNode* s_tables_node = dynamic_cast<strNode*> (node_aux2)){
    if (strNode* s_fields_node = dynamic_cast<strNode*> (node_aux3)){
      if (strNode* s_values_node = dynamic_cast<strNode*> (node_aux4)){
        
        MYSQL* conn;
        MYSQL_RES *result;
        MYSQL_ROW row;
        int num_fields;
        long int num_rows;
        
        if(conn = db_node->getSQL ()){
          ostringstream q_select (ostringstream::out);
          q_select 
            << "SELECT " 
            << s_fields_node->strvalue() 
            << " FROM " 
            << s_tables_node->strvalue()
            << " " 
            << s_values_node->strvalue();    
    
          //Select
          if (mysql_query(conn, q_select.str().c_str())){
            ostringstream os (ostringstream::out);
            os << mysql_error(conn) << " (" << mysql_errno(conn) << ") ";  
            cerr << q_select.str() << endl;
            throw errorException (mysql_error(conn), os.str(), 1);
          }
          result = mysql_store_result(conn);
          num_fields = mysql_num_fields(result);
          num_rows = mysql_num_rows(result);
        
          if (num_fields != 0){
            vector<string> fields_names;
            MYSQL_FIELD *field;
            while((field = mysql_fetch_field(result)))
              fields_names.push_back (field->name);
            vector<arrayNode*> rows_array;
            while ((row = mysql_fetch_row(result))) {
              listNode *list = NULL;
              for(int i = 0; i < num_fields; i++){
                list = new listNode (new mapNode (new strNode (fields_names[i]), new strNode (row[i])), list);
                
              }
              rows_array.push_back(new arrayNode (list));
            }
            if (num_rows == 0)
              noderef(new arrayNode ());
            else{
              listNode* list = NULL;
              for (int i = num_rows -1; i >= 0 ; i --){
                list = new listNode (rows_array[i], list);
              }
              noderef(new arrayNode (list));
            }
              
          }
        }
      }
    }
  }
}

//----------------------------------------------------------------------
//dbUpdateNode
runNode* dbUpdateNode::create (listNode* list){
	
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 4) 
			return new dbUpdateNode (v[0], v[1], v[2], v[3]);
		else if (v.size () == 3) 
			return new dbUpdateNode (NULL, v[0], v[1], v[2]);
		else
			cerr << "Wrong number parameters" << endl;
		return NULL;
			
	}
}
dbUpdateNode::dbUpdateNode (runNode* db, runNode* tables, runNode* fields, runNode* values ):
  db_ (db),
  tables_ (tables),
  fields_ (fields),
  values_ (values) {}

void dbUpdateNode::run (){
  runNode 
    *node_aux1 = db_,
    *node_aux2 = tables_,
    *node_aux3 = fields_,
    *node_aux4 = values_;
  if (!node_aux1){
    if (!(node_aux1 = dbNode::getGlobal ()))
      throw errorException ("Not connected to database", "dbQueryNode: database is null", 1);
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux1)){
    n_exp->run();
    node_aux1 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux2)){
    n_exp->run();
    node_aux2 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux3)){
    n_exp->run();
    node_aux3 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux4)){
    n_exp->run();
    node_aux4 = n_exp->nodeval ();
  }
  if (node_aux2) node_aux2->run();
  if (node_aux3) node_aux3->run();
  if (node_aux4) node_aux4->run();
  dbNode* db_node = NULL;
  if (!(db_node = dynamic_cast<dbNode*> (node_aux1)))
    throw errorException ("Wrong type", "dbQueryNode: database must be dbNode", 1);
  if (strNode* s_tables_node = dynamic_cast<strNode*> (node_aux2)){
    ostringstream q_fields (ostringstream::out);
    if (arrayNode* a_fields_node = dynamic_cast<arrayNode*> (node_aux3)){
      for (isym iter = a_fields_node->getArray()->begin(); iter != a_fields_node->getArray()->end();iter ++){
        strNode *key, *value;
        if (!(key = dynamic_cast<strNode*> (iter.first)))
          throw errorException ("Wrong type", "dbUpdateNode: key must be strNode", 1);
        if (!(value = dynamic_cast<strNode*> (iter.second)))
          throw errorException ("Wrong type", "dbUpdateNode: value must be strNode", 1);
        if (iter != a_fields_node->getArray()->begin())
          q_fields << ", " << key->strvalue() << "=" << "'" << value->strvalue () << "'"; 
        else
           q_fields << key->strvalue() << "=" << "'" << value->strvalue () << "'";
      }
    }
    else if (strNode * s_fields_node = dynamic_cast<strNode*> (node_aux3)){
      q_fields << " " << s_fields_node->strvalue() << " ";
    }
    if (strNode* s_values_node = dynamic_cast<strNode*> (node_aux4)){
      MYSQL *conn;
      MYSQL_RES *result;
      MYSQL_ROW row;
      int num_fields;
      long int num_rows;
      if(conn = db_node->getSQL ()){
        ostringstream q_update (ostringstream::out);
        q_update 
          << "UPDATE " 
          << s_tables_node->strvalue()
          << " SET "
          << q_fields.str()
          << " "  
          << s_values_node->strvalue();    
        //Update
        if (mysql_query(conn, q_update.str().c_str())){
          ostringstream os (ostringstream::out);
          os << mysql_error(conn) << " (" << mysql_errno(conn) << ") ";  
          cerr << q_update.str() << endl;
          throw errorException (mysql_error(conn), os.str(), 1);
        }
        result = mysql_store_result(conn);
        noderef(new boolNode ((bool) mysql_affected_rows(conn)));
      }
    }
  }
}


//----------------------------------------------------------------------
//dbDeleteNode
runNode* dbDeleteNode::create (listNode* list){
	
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 3) 
			return new dbDeleteNode (v[0], v[1], v[2]);
		else if (v.size () == 2) 
			return new dbDeleteNode (NULL, v[0], v[1]);
		else
			cerr << "Wrong number parameters" << endl;
		return NULL;
			
	}
}
dbDeleteNode::dbDeleteNode (runNode* db, runNode* tables, runNode* values ):
  db_ (db),
  tables_ (tables),
  values_ (values) {}

void dbDeleteNode::run (){
  runNode 
    *node_aux1 = db_,
    *node_aux2 = tables_,
    *node_aux3 = values_;
  if (!node_aux1){
    if (!(node_aux1 = dbNode::getGlobal ()))
      throw errorException ("Not connected to database", "dbQueryNode: database is null", 1);
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux1)){
    n_exp->run();
    node_aux1 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux2)){
    n_exp->run();
    node_aux2 = n_exp->nodeval ();
  }
  if (nexpNode* n_exp = dynamic_cast<nexpNode*> (node_aux3)){
    n_exp->run();
    node_aux3 = n_exp->nodeval ();
  }
  if (node_aux2) node_aux2->run();
  if (node_aux3) node_aux3->run();
  dbNode* db_node = NULL;
  if (!(db_node = dynamic_cast<dbNode*> (node_aux1)))
    throw errorException ("Wrong type", "dbQueryNode: database must be dbNode", 1);
  if (strNode* s_tables_node = dynamic_cast<strNode*> (node_aux2)){
    ostringstream q_fields (ostringstream::out);
    if (strNode* s_values_node = dynamic_cast<strNode*> (node_aux3)){
      MYSQL *conn;
      MYSQL_RES *result;
      MYSQL_ROW row;
      int num_fields;
      long int num_rows;
      if(conn = db_node->getSQL ()){
        ostringstream q_delete (ostringstream::out);
        q_delete 
          << "DELETE FROM " 
          << s_tables_node->strvalue()
          << " "  
          << s_values_node->strvalue();    
        //Delete
        if (mysql_query(conn, q_delete.str().c_str())){
          ostringstream os (ostringstream::out);
          os << mysql_error(conn) << " (" << mysql_errno(conn) << ") ";  
          cerr << q_delete.str() << endl;
          throw errorException (mysql_error(conn), os.str(), 1);
        }
        result = mysql_store_result(conn);
        noderef(new boolNode ((bool) mysql_affected_rows(conn)));
      }
    }
  }
}
