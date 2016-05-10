//operatorNode.cpp
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include "componentNode.h"
#include "sqliteDb.h"
#include <boost/regex.hpp>

using namespace boost;
//----------------------------------------------------------------------

//----------------------------------------------------------------------
defCNode::defCNode (runNode* component, runNode* def, runNode* not_exist, runNode* attach, runNode *like, runNode *extends)  :
   component_ (component),
   def_ (def),
   exec_ (false),
   not_exist_(not_exist),
   attach_(attach),
   id_key_ (NULL),
   like_ (like),
   extends_(extends),
   type_level_ (0),
   extend_level_ (0),
   name_db_ (""),
   arrayNode (),
   exist_ (false) {}

defCNode::defCNode (arrayNode *a)  :
   component_ (NULL),
   def_ (NULL),
   exec_ (false),
   not_exist_(NULL),
   attach_(NULL),
   id_key_ (NULL),
   like_ (NULL),
   extends_(NULL),
   type_level_ (0),
   extend_level_ (0),
   exist_ (false),
   name_db_ (""),
   arrayNode (a) {
   if (defCNode * def = dynamic_cast<defCNode*> (a)) {
      this->defCNodeCopy (def);
   }
}
defCNode::defCNode () :
   component_ (NULL),
   def_ (NULL),
   exec_ (false),
   not_exist_(NULL),
   attach_(NULL),
   id_key_ (NULL),
   arrayNode (),
   type_level_ (0),
   extend_level_ (0),
   name_db_ (""),
   like_(NULL),
   exist_ (false),
   extends_ (NULL) {}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string defCNode::getNameTable ( bool with_attach) {
   ostringstream oss;
   oss << name_table_;
   if ( with_attach && name_db_ != "") {
      oss.str("");
      oss << name_db_ << "." << name_table_;
   }
   return oss.str();
}

void defCNode::defCNodeCopy (defCNode * def, bool only_data ) {
   if (!only_data) {
      this->component_ = def->component_;
      this->def_ = def->def_;
      this->not_exist_ = def->not_exist_;
      this->attach_ = def->attach_;
      this->like_ = def->like_;
      this->extends_ = def->extends_;
   }
   this->rel_ = def->rel_;
   this->id_key_ = def->id_key_;
   this->default_val_ = def->default_val_;
   this->rel_tables_ = def->rel_tables_;
   this->name_db_ = def->name_db_;
   this->exist_ = def->exist_;

}

void defCNode::run (bool bypass, bool save ) {

   if (!exec_) {
      listC::push_defCNode (this);
      if (
         (!listC::top_dataCNode () && listC::top_defCNode ()) ||
         (listC::top_dataCNode () && !listC::top_defCNode ()) || bypass
      ) {
         runNode * key = component_;
         key = idNode::resolvedAsStr (key);
         nexpNode::resolved(key)->run();
         name_ = stringNode::to_str(key);
         if (!extends_) {
            name_table_ = name_;
         } else {

            if (defCNode *ext_def = listC::get_defCNode (extends_)) {
               name_table_ = ext_def->getNameTable();
               type_level_ = ext_def->type_level_  + 1;
               ext_def->calculateExtendsLevels (type_level_);
               attach_ = ext_def->attach_;
            } else {
               cerr << "incorrect extend" << endl;
            }
         }
         if (def_)
            def_->run();

         listC::set_defCNode (component_, this);
         listC::pop_defCNode ();
         exec_ = true;
         if (like_) {
            if (defCNode *edef = listC::get_defCNode (like_)) {
               this->defCNodeCopy (edef, true);
               symbols *m = edef->getArray();
               isym iter;
               for (iter = m->begin(); iter != m->end(); ++iter) {
                  this->insert (iter.first, iter.second);
               }
            } else {
               throw errorException ("like definition wrong", "Definition not exist", 0);
            }
         }
         this->run();
         
         if (save) this->save ();
      } else {
         listC::pop_defCNode ();
         throw errorException ("Init definition in data block", "Definition in data", 0);
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
runNode* defCNode::setElement (runNode* key, runNode* value) {
   runNode * key_ = key;
   nexpNode::resolved(key_)->run();
   this->insert (key_, value);
}

runNode* defCNode::getElement (runNode* key) {
   runNode * key_ = key;
   nexpNode::resolved(key_)->run();
   return this->get (new strNode (stringNode::to_str(key_)));
}

void defCNode::save ( ) {

   runNode * component = component_;
   string db_name = "";
   runNode *attach = attach_;
   string table = this->getNameTable();
   string table_db = table;
   this->saveRel ();

   if (attach) {
      nexpNode::resolved(attach)->run();
      string att = stringNode::to_str(attach);
      name_db_ = db::attach_database (att);
      ostringstream oss;
      oss << name_db_ << "." << table;
      table_db = oss.str();
   }
   if (extends_) {
      if (defCNode *ext_def = listC::get_defCNode (extends_)) { //Herencia
         vector<string> v = db::keys (this->getNameTable(true));
         ostringstream oss;
         name_db_ = ext_def->name_db_;
         oss << "_type_" << type_level_;
         if (std::find(v.begin(), v.end(), oss.str())==v.end()) {
            db::query(db::add_column (this->getNameTable(true), oss.str(), "TEXT"), false);
            this->calculateTypesLevels (oss.str());
         }
         isym i = this->getArray()->begin();
         for (; i != this->getArray()->end(); ++i) {
            if (!dynamic_cast<fexpNode*> (i.second) && !ext_def->get (i.first)) {
               db::query(db::add_column (this->getNameTable(true), stringNode::to_str(i.first), stringNode::to_str(i.second)), false);
               ext_def->addFieldsLevel (i.first, i.second);
            }

         }
         symbols map_aux = symbolsTable::copyRef(&ext_def->array_);
         for (i = this->array_.begin(); i != this->array_.end(); ++i) {
            map_aux [i.first] = i.second;
         }
         this->array_ = map_aux;
         if (!this->id_key_)
            this->id_key_ = ext_def->id_key_;
         map_aux = ext_def->default_val_;
         for (i = this->default_val_.begin(); i != this->default_val_.end(); ++i) {
            map_aux [i.first] = i.second;
         }
         this->default_val_ = map_aux;
         vector<string> v_s = ext_def->rel_tables_;
         for (int j = 0; j < this->rel_tables_.size(); ++j) {
            if (std::find(v_s.begin(), v_s.end(),  this->rel_tables_[j])== v_s.end())
               v_s.push_back( this->rel_tables_[j]);
         }
         map<string, defCNode*> rels_v = ext_def->rel_;
         map<string, defCNode*>::iterator i_rels;
         for (i_rels = this->rel_.begin(); i_rels != this->rel_.end() ; ++i_rels) {
            rels_v [i_rels->first] = i_rels->second;
         }
         this->rel_ = rels_v;
         vector<string> rels_t = ext_def->rel_tables_;
         for (int j = 0; j < this->rel_tables_.size(); ++j) {
            rels_t.push_back (this->rel_tables_[j]);
         }
         this->rel_tables_ = rels_t;
         this->exist_ = ext_def->exist_;
      } else {
         cerr << "incorrect extend" << endl;
      }
   } else {
      
      if (!db::exist_table (table, name_db_)) {
         
         db::query (db::create(table_db, this));
         if (not_exist_)
            not_exist_->run();
      } else {
         exist_ = true;
      }
   }
   
}



void defCNode::saveRel () {
   map<string, defCNode*>::iterator iter;
   for (iter = rel_.begin(); iter != rel_.end(); ++iter) {

      strNode s0 = strNode (this->getNameTable());
      strNode s1 = strNode (iter->second->getNameTable());

      mapNode n = mapNode (&s0,new strNode("INT"));
      mapNode m = mapNode (&s1, new strNode("INT"));
      listNode l = listNode (&n, &m);
      arrayNode a = arrayNode (&l);
      a.run();

      db::query(db::create (this->getRelName (iter->first, iter->second), &a));

   }
}

string defCNode::getRelName (string key, defCNode *def) {
   ostringstream oss;
   oss << "_" << this->getNameTable () << "_" << def->getNameTable () << "_" << key;
   return oss.str();
}

map<string, defCNode*> defCNode::getRels () const {
   return rel_;
}

void defCNode::setRel (string key, defCNode *def) {
   string table = this->getRelName (key, def);
   this->setRelTable (table);
   def->setRelTable (table);
   rel_[key] = def;
}

void defCNode::setRelTable (string table) {
   rel_tables_.push_back (table);
}

vector<string> defCNode::getRelTable () {
   return rel_tables_;
}

void defCNode::setId (runNode* key) {
   id_key_ = key;
}

string defCNode::getId () {
   return (id_key_)?stringNode::to_str (id_key_):"id";
}
defCNode* defCNode::getRel (string key) {
   return (rel_.find(key) != rel_.end())?rel_[key]:NULL;
}

runNode * defCNode::getDefaultVal (runNode* key) {
   if (default_val_.find (key) != default_val_.end())
      return default_val_[key];
   return NULL;
}

void defCNode::setDefaultVal (runNode* key, runNode* val) {
   default_val_[key] = val;
}

int defCNode::calculateExtendsLevels (int level) {
   if (level - type_level_ > extend_level_) {
      extend_level_ = level - type_level_;
      if (extends_) {
         if (defCNode * d = listC::get_defCNode (extends_)) {
            return extend_level_ = d->calculateExtendsLevels (level);
         }
      } else {
         return extend_level_ ;
      }
   }
}

void defCNode::calculateTypesLevels (string type) {
   this->insert (new strNode (type), new strNode ("TEXT"));
   if (extends_) {
      if (defCNode * d = listC::get_defCNode (extends_)) {
         d->calculateTypesLevels (type);
      }
   }
}

void defCNode::setTypesExtends (arrayNode* a) {
   if (this->getTypeLevel()) {
      ostringstream oss;
      oss << "_type_" << type_level_;
      a->insert (new strNode (oss.str()), new strNode(this->getName ()));
      if (extends_) {
         if (defCNode * d = listC::get_defCNode (extends_)) {
            d->setTypesExtends (a);
         }
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string defCNode::typeSelect (string str) {
   if (this->getTypeLevel()) {
      ostringstream oss;
      oss << "_type_" << type_level_;
      oss << " = '" << this->getName () << "' AND ";
      cmatch what;
      if (regex_match(str.c_str(), what, regex ("(^\\s*ORDER.*)|(^\\s*)"))) {
         oss << " 1 = 1 ";
      }
      oss << str;
      if (extends_) {
         if (defCNode * d = listC::get_defCNode (extends_)) {
            oss.str (d->typeSelect (oss.str()));
         }
      }
      str = oss.str();
   }
   return str;
}
void defCNode::addFieldsLevel  (runNode* key, runNode* val) {
   this->insert (key, val);
   if (extends_) {
      if (defCNode * d = listC::get_defCNode (extends_)) {
         d->addFieldsLevel (key,val);
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
relCNode::relCNode (runNode *field, runNode *stmts) : field_ (field), stmts_ (stmts), arrayNode (), rela_ (NULL), relb_(NULL), where_ (NULL), del_where_ (string("")) {}
relCNode::relCNode (string key, dataCNode *a, defCNode *b) : field_ (NULL), stmts_ (NULL), arrayNode (), data_ (a), relb_(b), key_ (key), where_ (NULL), del_where_ (string("")) {
   if (a) rela_ = a->getDef ();
}
relCNode::relCNode () : field_ (NULL), stmts_ (NULL), arrayNode (), rela_ (NULL), relb_(NULL), where_ (NULL), del_where_ (string("")) {}
relCNode::relCNode (arrayNode *a) : field_ (NULL), stmts_ (NULL), arrayNode (a), rela_ (NULL), relb_(NULL), where_ (NULL), del_where_ (string("")) {
   if (relCNode *rel = dynamic_cast<relCNode*> (a)) {
      this->data_ = rel->data_;
      this->key_ = rel->key_;
      this->rela_ = rel->rela_;
      this->relb_ = rel->relb_;
   }
}

void relCNode::run () {
   runNode * field = field_, *stmts = stmts_;
   if (field) {
      field = idNode::resolvedAsStr (field);
      nexpNode::resolved(field)->run();
      this->clear();
      if (dataCNode* d = listC::top_dataCNode ()) {

         relCNode * rel = d->getRel (stringNode::to_str(field));
         if (rel) this->setArray (*rel->getArray());
         listC::push_relCNode (this);
         if (stmts) {
            stmts->run();
         }

         listC::pop_relCNode ();
         this->setDataRel (stringNode::to_str(field), d);

      }
   }
}

void relCNode::setDataRel (string field, dataCNode * data) {
   data->setRel (field, this);
   symbols *m = this->getArray ();
   isym i;
  if(m) {
   if (m->begin() != m->end() && !data->getDef()) {

      if (dataCNode * d = dynamic_cast<dataCNode*> (m->begin().second) ) {

         if (defCNode * def = data->getDefC()) {
            strNode s = strNode (d->getNameTable());
            defCNode * defb_ = listC::get_defCNode (&s);
            def->setRel (field, defb_);
         }
      }
   }
   }
}

void relCNode::save (string field, dataCNode * data) {
   defCNode *def;
   if (def = data->getDef()) {
      symbols *m = this->getArray();
      isym iter;
      for (iter = m->begin(); iter != m->end(); ++iter) {
         if (dataCNode *d = dynamic_cast<dataCNode*> (iter.second)) {
            strNode s0 = strNode (data->getNameTable());
            strNode s1 = strNode (d->getNameTable());
            mapNode n = mapNode (&s0,new strNode(data->id));
            mapNode m = mapNode (&s1, new strNode(d->id));
            listNode l = listNode (&n, &m);
            arrayNode a = arrayNode (&l);
            a.run();
            db::query(db::insert (data->getRelName(field, d), &a));
         }
      }
   }
}
void  relCNode::processData () {
   if (data_) {

      rela_ = data_->getDef ();
      if (rela_ && relb_ ) {
         strNode s = strNode (relb_->getNameTable());
         vector<dataCNode*> v =
            this->seltologic (
               &s,
               relb_,
               db::query(
                  db::select (
                     reltable(),
                     relselect(),
                     relwhere(),
                     false
                  )
               )
            );
         this->logictoNode (v);
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string relCNode::reltable () {
   ostringstream oss;

   oss << rela_->getRelName (key_, relb_) << " INNER JOIN " << relb_->getNameTable ()
       << " ON "  << rela_->getRelName (key_, relb_) << "." << relb_->getNameTable ()
       << " = " << relb_->getNameTable () << ".id ";

   return oss.str();
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string relCNode::relselect() {
   ostringstream oss;
   oss << relb_->getNameTable () << ".";
   string table_name = oss.str();
   string def_str = db::fieldslist (this->relb_, false, " ", false, table_name);
   oss.str("");
   oss << table_name << "id, " << def_str;
   return oss.str();
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string relCNode::relwhere () {
   ostringstream oss, ossw;
   if (where_) {
      ossw << " AND " << stringNode::to_str (where_);
   }

   oss << rela_->getRelName (key_, relb_) << "." << rela_->getNameTable () << " = '" << data_->id << "'" << ossw.str();
   return oss.str();
}

void relCNode::setWhere (runNode* where) {
   where_ = where;
}

vector<dataCNode*> relCNode::seltologic (runNode *table, defCNode *def, vector<vector<string> > sel) {
   vector<dataCNode*> resp;
   int sel_n = sel.size();
   symbols *m;
   isym iter;
   //Busca el tipo para tomar la def.

   for (int i = 0; i < sel_n; ++i) {

      vector<string> sel_elem = sel[i];
      string id;
      defCNode *aux = def;
      symbols funcs;
      m = def->getArray(),
      iter = m->end();
      listNode *list = NULL;
      if (int n = def->getExtendLevel ()) {
         for (int j = sel_elem.size() ; j > 0;) {
            iter --; j --;
            while (dynamic_cast<fexpNode*> (iter.second)) {
               funcs[iter.first] = iter.second;
               if (iter != m->end()) iter --;
            }

            if (iter != m->end()) {
               ostringstream oss;
               oss << "_type_" << n;
               if (stringNode::to_str(iter.first) == oss.str()) {

                  if (sel_elem[j] != "") {
                     if (listC::get_defCNode (new strNode (sel_elem[j])))
                        aux = listC::get_defCNode (new strNode (sel_elem[j]));
                     break;
                  } else {
                     n --;
                  }
               }
            }
         }
      }
      vector<string> v_keys;
      m = aux->getArray();
      iter = m->begin();
      //Determina el array de keys
      v_keys.push_back("id");
      for (; iter != m->end(); ++iter) {

         if (!dynamic_cast<fexpNode*> (iter.second)) {

            v_keys.push_back (stringNode::to_str(iter.first));
         }
      }
      m = aux->getArray();
      iter = m->end();
      //Dar los valores buscandolos
      int count;
      do {
         iter --; count ++;
         while (dynamic_cast<fexpNode*> (iter.second)) {
            funcs[iter.first] = iter.second;
            iter --;
         }
         if (iter != m->end()) {
            for (int j = 0; j < v_keys.size(); ++j) {
               if (stringNode::to_str (iter.first) == v_keys[j]) {
                  list = new listNode (new mapNode (iter.first, new strNode (sel_elem[j])), list);
                  break;
               }
            }
         } else
            break;
      } while (iter != m->begin());
      list = new listNode (new mapNode (new strNode("id"), new strNode (sel_elem[0])), list);
      for (iter = funcs.begin(); iter != funcs.end(); ++iter) {
         list = new listNode (new mapNode (iter.first, iter.second), list);
      }
      dataCNode *data = new dataCNode (table, list);
      data->id = sel_elem[0];
      data->runArray();
      data->setComponent (new strNode (table));
      map<string, defCNode*> rels = aux->getRels();
      map<string, defCNode*>::iterator r_i;
      for (r_i = rels.begin(); r_i != rels.end(); ++r_i) {
         relCNode *rel = new relCNode  (r_i->first, data, aux->getRel(r_i->first));
         data->insert (new strNode(r_i->first), rel);
      }
      resp.push_back (data);

   }

   return resp;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
arrayNode* relCNode::logictoNode (vector<dataCNode *> sel) {
   listNode *list = NULL;
   int n = sel.size();
   this->clear();
   for (int j = 0; j < n; ++j) {
      this->push(sel[j]);
   }
   return this;
}

void relCNode::run_get() {
   if (revConnectNode::exist("asigNode")) {
      vector<runNode*> v;
      revConnectNode::push_stack ("asigNode", this, v);
   }
}

void relCNode::run_getData(runNode *key) {
   relAccessNode* access = new relAccessNode (key, this);
   if (revConnectNode::exist("asigNode")) {
      if (dataCNode* data = dynamic_cast<dataCNode*>(this->get (key))) {
         ostringstream oss;
         oss << " AND " << data->getNameTable () << " = " << data->id << " ";
         this->setDelWhere (oss.str());
      }
      vector<runNode*> v;
      revConnectNode::push_stack ("asigNode", access, v);
   }
}

void relCNode::runRev (vector<runNode*> params) {
   if (params.size ()) {
      runNode * node = params[0];

      if (arrayNode * a = dynamic_cast<arrayNode*> (node)) {
         if (this->rela_ && this->relb_ && this->key_ != "" && this->data_) {
            ostringstream oss;
            oss << this->rela_->getNameTable() << " = " << this->data_->id << " " << del_where_;
            db::query (db::delrow (this->rela_->getRelName (this->key_, this->relb_), oss.str()));
            symbols *m = a->getArray();
            isym iter = m->begin();
            for (; iter != m->end(); ++iter) {

               if (dataCNode *d = dynamic_cast<dataCNode*> (iter.second)) {
                  strNode str = strNode (d->getNameTable ());
                  if (listC::get_defCNode(&str) == relb_) {
                     strNode s0 = strNode (data_->getNameTable());
                     strNode s1 = strNode (relb_->getNameTable());
                     mapNode n = mapNode (&s0,new strNode(data_->id));
                     mapNode m = mapNode (&s1, new strNode(d->id));
                     listNode l = listNode (&n, &m);
                     arrayNode a = arrayNode (&l);
                     a.run();
                     db::query(db::insert (data_->getRelName(key_, d), &a));
                  } else {
                     cerr << "DEBE COINCIDIR EN LA DEFININICION" << endl;
                  }
               } else {
                  cerr << "DEBE SER DATAC" << endl;
               }
            }
         }
      } else {
         cerr << "DEBE SER ARRAY" << endl;
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
relAccessNode::relAccessNode (runNode * key, relCNode* rel) : key_(key), rel_ (rel) {}
void relAccessNode::runRev (vector<runNode*> params) {
   if (params.size ()) {
      runNode * node = params[0];
      dataCNode *a;
      if ((a = dynamic_cast<dataCNode*> (node)) && rel_ && key_) {
         rel_->del(key_);
         rel_->insert(key_, node);
         params[0] = rel_;
         rel_->runRev (params);
      }
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
dataCNode::dataCNode (runNode* component, runNode* stmts)  :
   component_ (component),
   stmts_ (stmts),
   exec_ (false),
   def_ (NULL), defC_ (NULL),
   arrayNode (), isdef(false), id("0"), last_access_key (NULL) { }
dataCNode::dataCNode (runNode* component, listNode* list)  :
   component_ (component),
   stmts_ (NULL),
   exec_ (false),
   def_ (NULL), defC_ (NULL),
   arrayNode (list), isdef(false), id("0"), last_access_key (NULL) {
   def_ = listC::get_defCNode (component);
}
dataCNode::dataCNode ()  :
   component_ (NULL),
   stmts_ (NULL),
   exec_ (true),
   def_ (NULL), defC_ (NULL),
   arrayNode (), isdef(false), id("0"), last_access_key (NULL) {}
dataCNode::dataCNode (arrayNode* array) :
   component_ (NULL),
   stmts_ (NULL),
   exec_ (true),
   def_ (NULL), defC_ (NULL),
   arrayNode (array), isdef(false), id("0"), last_access_key (NULL) {
   if (dataCNode * data = dynamic_cast<dataCNode*> (array)) {
      component_ = data->component_;
      stmts_ = data->stmts_;
      id = data->id;
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
runNode * dataCNode::getById (defCNode * def, runNode* id) {
   selCNode * sel = new selCNode (new strNode (def->getNameTable()), id, true);
   sel->run();
   return sel->nodeval();
}

void dataCNode::setRel (string key, relCNode *def) {
   rel_[key] = def;
}
relCNode* dataCNode::getRel (string key) {
   return (rel_.find(key) != rel_.end())?rel_[key]:NULL;
}
bool dataCNode::isData (runNode * node) {
   return !dynamic_cast<fexpNode*> (node) && !dynamic_cast<relCNode*> (node);
}

void dataCNode::run () {
   if (!exec_ && stmts_ ) {
      if (!listC::top_defCNode ()) {
         this->clearRef();
         sTable::sTable_use->setNodeUse (new dataCNode(this));
         id = "0";
         listC::push_dataCNode (this);
         this->iniDefC();
         relCNode* r = NULL;
         if (r = listC::top_relCNode ())
            listC::pop_relCNode ();
         if (stmts_)
            stmts_->run();
         if (r)
            listC::push_relCNode (r);
         listC::pop_dataCNode ();
         arrayNode::run();
         this->iniDef();
         this->save();
      } else {
         throw errorException ("Init data in definition block", "Data in definition", 0);
      }
   }
}

void dataCNode::runArray () {
   sTable::sTable_use->setNodeUse (this);
   exec_ = true;
   arrayNode::run();
}
void dataCNode::run_get() {
   if (revConnectNode::exist("asigNode")) {
      vector<runNode*> v;
      revConnectNode::push_stack ("asigNode", this, v);
   }
}
void dataCNode::runRev (vector<runNode*> params) {
   this->processData (params);
}

runNode* dataCNode::nodeval () const {
   return new dataCNode (*this);
}

void dataCNode::iniDefC () {
   if (!def_) {
      if (!(def_ = listC::get_defCNode (component_))) {
         defC_ = new defCNode (component_, NULL);

         defC_->run (true, false);

         isdef = true;
      }
   }
}

void dataCNode::iniDef () {
   if (!def_) {
      def_ = defC_;
      defC_ = NULL;
      def_->save ();
   }
   isdef = false;
}

void dataCNode::save () {
   vector<runNode*> v;
   this->processDefaultValues ();
   this->processData (v); //Guarda o actualiza los datos
   this->id = db::lastid();
   if (relCNode* r = listC::top_relCNode ()) { //Realiza asociaciones
      r->push (new dataCNode (this));
   } if (!rel_.empty()) {
      map<string, relCNode*>::iterator iter;
      for (iter = rel_.begin(); iter != rel_.end(); ++iter) {

         iter->second->save (iter->first, this);
      }
   }
}

void dataCNode::processDefaultValues () {
   if (defCNode * def = this->getDef()) {
      symbols m = def->getDefalutArray ();
      isym iter;
      
      for (iter = m.begin(); iter != m.end (); ++iter) {
         if (!this->get(iter.first)) {
            this->insert(iter.first, iter.second);
         }
      }
      
   }
}

void dataCNode::processData (vector<runNode*> params) {
   ostringstream oss;

   runNode * component = component_;
   if (params.size()) {
      if (dataCNode * data = dynamic_cast<dataCNode*>(params[0])) {
         if (defCNode *def = listC::get_defCNode (new strNode(this->getNameTable()))) {
            if( def = dynamic_cast<defCNode*>(def->getElement (this->last_access_key))) {
               this->insert (this->last_access_key, data);
            }
         }
      }
   }

   component = idNode::resolvedAsStr (component);
   nexpNode::resolved(component)->run();
   string table = stringNode::to_str(component);

   if (defCNode *def = this->getDef ()) {
      def->setTypesExtends (this);
      table = def->getNameTable ();
   }

   if (id != "0") {
      oss << " id = " << id << "";
      db::query(db::update (table, this, oss.str()));
   } else {

      db::query(db::insert (table, this));
   }

}

defCNode * dataCNode::getDef () const  {
   return def_;
}
defCNode * dataCNode::getDefC () const  {
   return defC_;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string dataCNode::getNameTable () {

   if (defCNode * def = listC::get_defCNode (component_)) {
      return def->getNameTable ();
   } else {
      runNode * key = component_;
      key = idNode::resolvedAsStr (key);
      nexpNode::resolved(key)->run();
      return stringNode::to_str(key);
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string dataCNode::getRelName (string key, dataCNode *data) {
   ostringstream oss;
   oss << "_" << this->getNameTable () << "_" << data->getNameTable () << "_" << key;
   return oss.str();
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
setCNode::setCNode (runNode * type, runNode *key, runNode * value, bool isdef, bool isid, runNode* default_val)
   : key_(key), type_(type), value_ (value), isdef_ (isdef), isid_(isid), default_val_ (default_val) {}

void setCNode::run () {
   runNode *key = key_, *type = type_, *value = value_;
   key = idNode::resolvedAsStr (key, false);
   type = idNode::resolvedAsStr (type, false);

   value = idNode::resolvedAsStr (value, false);

   nexpNode::resolved(key)->run();
   if (type)
      nexpNode::resolved(type)->run();
   nexpNode::resolved(value)->run();

   dataCNode* data = listC::top_dataCNode ();
   defCNode * def = NULL;
   if ((data = dynamic_cast<dataCNode*>(value)) && data->getDef())
      type = data->getDef();
   data = listC::top_dataCNode ();
   if (isdef_)
      value = listC::get_defCNode (value);

   if (dynamic_cast<fexpNode*>(value) || !data)
      type = value;
   def = this->insertDef (key, type, data);
   if (data) {
      if (!def || def->getElement (key)) {
         this->insertData (key, value, data);
      } else
         throw errorException ("Set attribute without type", "Definition no exist", 0);
   }

}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
defCNode* setCNode::insertDef (runNode *&key, runNode * type, dataCNode *data) {
   defCNode *def;

   if (data) {
      if (!(def = data->getDef ()) && !(def = data->getDefC ()))
         throw errorException ("Set attribute without definition", "Definition no exist", 0);
   } else {
      if (!(def = listC::top_defCNode ()))
         throw errorException ("Set attribute without definition", "Definition no exist", 0);
   }
   if (expNode *k = dynamic_cast<expNode*> (key))
      key = k;
   if (!dynamic_cast<fexpNode*> (type) && !dynamic_cast<defCNode*> (type))
      if (expNode * t = dynamic_cast<expNode*> (type) )
         type = t;
   if ((data && data->isdef) || !data) {
      if (!type)
         type = new nullNode ();
      if (isid_)
         def->setId (key);

      def->setElement (key, type);
      if (default_val_) {
         def->setDefaultVal (key, default_val_);
      }
   }
   return def;
}

void setCNode::insertData (runNode *key, runNode * value, dataCNode* data) {
   if (expNode *k = dynamic_cast<expNode*> (key))
      key = k;
   expNode * val;
   if ((val = dynamic_cast<expNode*> (value))&& !dynamic_cast<fexpNode*>(value) )
      value = val;

   data->insert (key, value);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
setExistRelCNode::setExistRelCNode (runNode * value)
   : value_ (value) {}

void setExistRelCNode::run () {

   runNode *value = value_;
   nexpNode::resolved(value)->run();

   if (relCNode* r = listC::top_relCNode ()) {
      arrayNode * a;
      if ((a = dynamic_cast<arrayNode*> (value)) && !dynamic_cast<dataCNode*> (value)) {
         symbols *m = a->getArray();
         isym iter = m->begin();
         for (; iter != m->end(); ++iter) {
            if (dataCNode* data = dynamic_cast<dataCNode*> (iter.second)) {
               r->push (new dataCNode (data));
            } else
               cerr << "NO DATAC" << endl;
         }
      } else if (dynamic_cast<dataCNode*> (value)) {
         r->push (new dataCNode (dynamic_cast<dataCNode*> (value)));
      } else {
         cerr << "NO ES ARRAY => PROGRAMAR CASO" << endl;
      }
   } else {
      cerr << "NO TOP RELATION" << endl;
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
existDefCNode::existDefCNode (runNode * value)
   : value_ (value) {}

void existDefCNode::run () {
   if (defCNode * def = listC::get_defCNode (value_)) {
      boolvalue_ = def->isExist ();
   } else {
      boolvalue_ = false;
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
setRelCNode::setRelCNode (runNode *key, runNode * value)
   : key_(key), value_ (value) {}

void setRelCNode::run () {
   runNode *key = key_, *value = value_;
   key = idNode::resolvedAsStr (key);
   value = idNode::resolvedAsStr (value);

   nexpNode::resolved(key)->run();
   nexpNode::resolved(value)->run();
   dataCNode* data = listC::top_dataCNode ();
   defCNode * def = NULL, *rel = NULL;
   if ((def = listC::top_defCNode ()) && (rel = listC::get_defCNode (value))) {
      def->setRel (stringNode::to_str(key), rel);
   } else
      throw errorException ("wrong definition", "Definition no exist", 0);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
selCNode::selCNode (runNode * component, runNode *where, bool uniq)
   : component_(component), where_(where), uniq_ (uniq) {}

void selCNode::run () {
   runNode *component = component_, *where = where_;
   ostringstream oss;
   component = idNode::resolvedAsStr (component);
   nexpNode::resolved(component)->run();
   bool isnum = false;
   if (where)
      nexpNode::resolved(where)->run();
   arithNode* num;
   stringNode* str;
   if (where && (str = dynamic_cast<stringNode*> (where))) {
      if (str->is_numvalue ()) {
         oss << " id = " << str->numvalue() << " ";
         isnum = true;
      } else
         oss << stringNode::to_str(where);
   } else if (where && (num = dynamic_cast<arithNode*> (where))) {
      oss << " id = " << num->numvalue() << " ";
      isnum = true;
   }

   if (defCNode * def = listC::get_defCNode(component)) {
      if (uniq_ && def->getId() != "id") {
         if (dynamic_cast<idNode*> (where_)) {
            where = idNode::resolvedAsStr (where_);
            nexpNode::resolved (where)->run();
         }
         oss.str ("");
         oss << " " << def->getId() << " = '" << stringNode::to_str(where) << "' ";
         isnum = true;
      }
      if (where_) oss.str (checkFunction::processWhere (def, oss.str ()));
      oss.str (def->typeSelect (oss.str()));
      vector<dataCNode*> v =
         this->seltologic (
            component,
            def,
            db::query(
               db::select (
                  def->getNameTable(),
                  db::fieldslist (def),
                  oss.str()
               )
            )
         );
      if (isnum && v.size() > 0 && uniq_) {
         noderef(v[0]);
      } else
         this->logictoNode (v);
   } else {
      throw errorException ("Component not is define", "Component no exist", 0);
   }

}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
vector<dataCNode*> selCNode::seltologic (runNode *table, defCNode *def, vector<vector<string> > sel) {
   vector<dataCNode*> resp;
   int sel_n = sel.size();
   vector<string> v_keys;
   symbols *m = def->getArray();
   isym iter = m->begin();
   //Determina el array de keys
   v_keys.push_back("id");
   for (; iter != m->end(); ++iter) {
      if (!dynamic_cast<fexpNode*> (iter.second)) {
         v_keys.push_back (stringNode::to_str(iter.first));
      }
   }
   //Busca el tipo para tomar la def.
   for (int i = 0; i < sel_n; ++i) {
      vector<string> sel_elem = sel[i];
      string id;
      defCNode *aux = def;
      symbols funcs;
      m = def->getArray(),
      iter = m->end();
      listNode *list = NULL;
      if (int n = def->getExtendLevel ()) {
         for (int j = sel_elem.size() ; j > 0;) {
            iter --; j --;
            while (dynamic_cast<fexpNode*> (iter.second)) {
               funcs[iter.first] = iter.second;
               if (iter != m->end()) iter --;
            }

            if (iter != m->end()) {
               ostringstream oss;
               oss << "_type_" << n;
               if (stringNode::to_str(iter.first) == oss.str()) {

                  if (sel_elem[j] != "") {
                     aux = listC::get_defCNode (new strNode (sel_elem[j]));
                     break;
                  } else {
                     n --;
                  }
               }
            }
         }
      }
      m = aux->getArray();
      iter = m->end();
      //Dar los valores buscandolos
      int count;
      do {
         iter --; count ++;
         while (dynamic_cast<fexpNode*> (iter.second)) {
            funcs[iter.first] = iter.second;
            iter --;
         }
         if (iter != m->end()) {
            for (int j = 0; j < v_keys.size(); ++j) {
               if (stringNode::to_str (iter.first) == v_keys[j]) {
                  list = new listNode (new mapNode (iter.first, new strNode (sel_elem[j])), list);
                  break;
               }
            }
         } else
            break;
      } while (iter != m->begin());
      list = new listNode (new mapNode (new strNode("id"), new strNode (sel_elem[0])), list);
      for (iter = funcs.begin(); iter != funcs.end(); ++iter) {
         list = new listNode (new mapNode (iter.first, iter.second), list);
      }
      dataCNode *data = new dataCNode (table, list);
      data->id = sel_elem[0];
      data->runArray();
      data->setComponent (new strNode (table));
      map<string, defCNode*> rels = aux->getRels();
      map<string, defCNode*>::iterator r_i;
      for (r_i = rels.begin(); r_i != rels.end(); ++r_i) {
         relCNode *rel = new relCNode  (r_i->first, data, aux->getRel(r_i->first));
         data->insert (new strNode(r_i->first), rel);
      }
      resp.push_back (data);
   }
   return resp;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
arrayNode* selCNode::logictoNode (vector<dataCNode *> sel) {
   listNode *list = NULL;
   for (int j = sel.size() ; j > 0;) {
      j --;
      list = new listNode (sel[j], list);
   }
   arrayNode *a = new arrayNode (list);
   a->run();
   noderef(a);
   return a;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
delCNode::delCNode (runNode * component, runNode *where)
   : component_(component), where_(where) {}

void delCNode::run () {
   runNode *component = component_, *where = where_;
   ostringstream oss;
   component = idNode::resolvedAsStr (component);
   nexpNode::resolved(component)->run();
   bool isnum = false;
   if (where)
      nexpNode::resolved(where)->run();
   arithNode* num;
   stringNode* str;
   if (where && (str = dynamic_cast<stringNode*> (where))) {
      if (str->is_numvalue ()) {
         oss << " id = " << str->numvalue() << " ";
         isnum = true;
      } else
         oss << stringNode::to_str(where);
   } else if (where && (num = dynamic_cast<arithNode*> (where))) {
      oss << " id = " << num->numvalue() << " ";
      isnum = true;
   }

   if (defCNode * def = listC::get_defCNode(component)) {
      oss.str (def->typeSelect (oss.str()));
      db::query(
         db::delrow (
            def->getNameTable(),
            oss.str()
         )
      );
      noderef(new numNode (db::num_changes()));
      vector<string> v = def->getRelTable ();
      vector<string>::iterator i = v.begin();
      for (; i != v.end(); ++i) {
         ostringstream from, field, wh;
         from << *i << " LEFT JOIN " << def->getNameTable() << " ON " << *i << "." << def->getNameTable() << " = " << def->getNameTable() << ".id ";
         field << *i << "." << def->getNameTable();
         wh <<  def->getNameTable() << ".id IS NULL ";
         vector<vector<string> > elems = db::query(
                                            db::select (
                                               from.str(),
                                               field.str(),
                                               wh.str(),
                                               false
                                            )
                                         );
         vector<vector<string > >::iterator j = elems.begin ();
         wh.str("");
         for(; j != elems.end(); ++j) {
            wh << " id = " << (*j)[0] << " OR ";
         }
         wh << " 1 != 1 ";
         db::query(
            db::delrow (
               *i,
               wh.str()
            )
         );
      }
   } else {
      throw errorException ("Component not is define", "Component no exist", 0);
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
map<string, defCNode *> listC::list;
vector<dataCNode*> listC::stack_data;
vector<defCNode*> listC::stack_def;
vector<relCNode*> listC::stack_rel;
int listC::stack_data_top = -1;
int listC::stack_def_top = -1;
int listC::stack_rel_top = -1;

void listC::set_defCNode (runNode *str, runNode* def) {
   runNode * key = str;
   key = idNode::resolvedAsStr (key);
   nexpNode::resolved(key)->run();
   set_defCNode (stringNode::to_str(key), def);
}
void listC::set_defCNode (string str, runNode* def) {

   if (!list[str]) {
      if (defCNode * d = dynamic_cast<defCNode*>(def))
         list[str] = d;
   } else {
      ostringstream oss;
      oss << "\"" << str << "\" definition already exists";
      throw errorException ("Double definition", oss.str(), 0);
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
defCNode* listC::get_defCNode (runNode *str) {
   runNode * key = str;
   key = idNode::resolvedAsStr (key);
   nexpNode::resolved(key)->run();
   return get_defCNode (stringNode::to_str(key));
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
defCNode* listC::get_defCNode (string str) {
   if (list.find(str) != list.end())
      return list[str];
   return NULL;
}
//--
void listC::push_defCNode (runNode* data) {
   if (defCNode* d = dynamic_cast<defCNode*> (data)) {
      listC::stack_def.push_back (d);
      listC::stack_def_top ++;
   } else {
      throw errorException ("stack_def component insert fail", "push_defCNode: data not is defCNode", 0);
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
defCNode* listC::top_defCNode () {
   return
      (listC::stack_def_top > -1)
      ?listC::stack_def[stack_def_top]
      :NULL;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
defCNode* listC::pop_defCNode () {
   defCNode* d = listC::top_defCNode ();
   listC::stack_def.pop_back ();
   listC::stack_def_top --;
   return d;
}
//--
void listC::push_dataCNode (runNode* data) {
   if (dataCNode* d = dynamic_cast<dataCNode*> (data)) {
      listC::stack_data.push_back (d);
      listC::stack_data_top ++;
   } else {
      throw errorException ("stack_data component insert fail", "push_dataCNode: data not is dataCNode", 0);
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
dataCNode* listC::top_dataCNode () {
   return
      (listC::stack_data_top > -1)
      ?listC::stack_data[stack_data_top]
      :NULL;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
dataCNode* listC::pop_dataCNode () {
   dataCNode* d = listC::top_dataCNode ();
   listC::stack_data.pop_back ();
   listC::stack_data_top --;
   return d;
}
//--
void listC::push_relCNode (runNode* rel) {
   if (relCNode* d = dynamic_cast<relCNode*> (rel)) {
      listC::stack_rel.push_back (d);
      listC::stack_rel_top ++;
   } else {
      throw errorException ("stack_rel component insert fail", "push_relCNode: rel not is relCNode", 0);
   }
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
relCNode* listC::top_relCNode () {
   return
      (listC::stack_rel_top > -1)
      ?listC::stack_rel[stack_rel_top]
      :NULL;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
relCNode* listC::pop_relCNode () {
   relCNode* d = listC::top_relCNode ();
   listC::stack_rel.pop_back ();
   listC::stack_rel_top --;
   return d;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string checkFunction::processRegExp (defCNode *def, string where) {
   symbols *m = def->getArray ();
   isym iter = m->begin();
   for (; iter != m->end(); ++iter) {
      if (dynamic_cast<fexpNode*> (iter.second)) {
         ostringstream oss;
         oss << " " << where;
         where = oss.str();
         oss.str("");
         oss  << " (" << stringNode::to_str(iter.first) << ") *\\(" << "([^\\)]*)\\)";
         regex e = regex (oss.str());
         string::const_iterator start, end;
         start = where.begin();
         end = where.end();
         match_results<std::string::const_iterator> what;
         match_flag_type flags = boost::match_default;
         bool first = true;
         regex_search(start,end, what, e, flags);
         int count = 0;
         int n = 0;
         while (start != end && regex_search(start,end, what, e, flags)) {
            string params = string (what[2].first, what[2].second);
            string sep = (params == "")?"":", ";
            oss.str ("");
            oss << "ck('" << string (what[1].first, what[1].second) << "'" << sep << params << ") ";
            where.replace (what.position() + n + 1, what.length() -1, oss.str());
            n = oss.str().length()+  what.position() + 1;
            if (what[0].first == what[0].second)
               start ++;
            else
               start = what[0].second;
         }
      }
   }
   return where;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
string checkFunction::processWhere (defCNode * def, string where) {
   where = checkFunction::processRegExp (def,where);
   std::size_t pos = 0;
   ostringstream oss;
   oss << "'" << def->getNameTable() << "', id, " << db::fieldslist (def, false ) << ", ";
   while ((pos = where.find("ck(", pos)) != string::npos ) {
      pos += 3;
      where.insert (pos, oss.str());
   }
   return where;
}
bool checkFunction::check () {
   string component = this->params [0];
   string function;
   strNode component_str = strNode (component);
   vector<string> values;
   vector<string> function_params;
   listNode *list = NULL;
   if (defCNode * def = listC::get_defCNode (&component_str)) {
      int n = def->getArray()->size();
      values.push_back (this->params [1]);
      int index = 2;
      symbols *m = def->getArray();
      isym iter = m->begin();

      for (; iter != m->end (); ++iter) {
         if (!dynamic_cast<fexpNode*> (iter.second)) {
            values.push_back (this->params [index]);
            index ++;
         }
      }
      function = this->params [index];
      index ++;
      for (; index < this->params.size(); ++index) {
         runNode *  param_str = new strNode (this->params[index]);
         list = new listNode (idNode::resolvedAsStr (param_str), list);
      }
      selCNode sel = selCNode (&component_str, NULL, 1);
      vector<vector<string> > v;
      dataCNode * data = NULL;
      v.push_back (values);
      data = sel.seltologic (&component_str, def, v) [0];
      strNode *function_str = new strNode (function);
      if (runNode * method = def->get(function_str)) {
         sTable::sTable_use->setNodeUse (data);
         functioncallNode call = functioncallNode (method, list);
         call.run ();

         if (runNode * call_val = call.nodeval ()) {
            nexpNode::resolved (call_val)->run ();
            if (logicNode * l = dynamic_cast<logicNode*> (call_val)) {
               return l->boolvalue ();
            }
         }

      } else {
         cerr << "NO EXISTE EL MÉTODO " << function << " EN EL COMPONENTE" << endl;
      }
   }
   return false;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Fco. javier Bohórquez Ogalla
