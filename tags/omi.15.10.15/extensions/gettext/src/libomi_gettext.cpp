//~ g++ -c -fPIC gettext-ext.cpp -o gettext-ext.o && g++ -shared gettext-ext.o -o gettext-ext.so

//~ #include <iostream>
//~ #include <string>
//~ #include <map>
//~ #include <locale.h>
#include "libomi_gettext.h"

using namespace std;
//----------------------------------------------------------------------
extern "C" void load (PluginsLoader* loader) {
    loader->add ("gettext", create<gettextNode>);
    loader->add ("dgettext", dgettextNode::create);
    loader->add ("_", create<gettextNode>);
    loader->add ("bindtextdomain", bindtextdomainNode::create);
    loader->add ("setlocale", setlocaleNode::create);
    loader->add ("textdomain", textdomainNode::create);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//~ runNode* gettextNode::create (listNode* list) {
	//~ return new gettextNode (list);
//~ }
//~ gettextNode::gettextNode (listNode* list) : list_ (list) {}



void gettextNode::run () { 
   vector<runNode*> v = this->getParams ();
   if (v.size() == 1)
      strvalue_ = gettext(stringNode::to_str (v[0]).c_str());
   else
      cerr << "Wrong number parameters" << endl;
}  
//----------------------------------------------------------------------

//----------------------------------------------------------------------
runNode* dgettextNode::create (listNode* list) {
	return new dgettextNode (list);
}
dgettextNode::dgettextNode (listNode* list) : list_ (list) {}

void dgettextNode::run () { 
	listNode * list = list_;
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 2) {
			strvalue_ = dgettext(stringNode::to_str (v[0]).c_str(), stringNode::to_str (v[1]).c_str());
			return;
		} else
			cerr << "Wrong number parameters" << endl;
	}
	strvalue_ = "";
}  

//----------------------------------------------------------------------

//----------------------------------------------------------------------
bindtextdomainNode::bindtextdomainNode (listNode* list) : list_ (list) {}

runNode* bindtextdomainNode::create (listNode* list) {
	return new bindtextdomainNode (list);
}

void bindtextdomainNode::run () { 
	listNode * list = list_;
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 2) {
			strvalue_ = bindtextdomain (stringNode::to_str (v[0]).c_str(), stringNode::to_str (v[1]).c_str());
			return;
		} else
			cerr << "Wrong number parameters" << endl;
	}
	strvalue_ = "";
}  

//----------------------------------------------------------------------

//----------------------------------------------------------------------

setlocaleNode::setlocaleNode (listNode* list) : list_ (list) {}

runNode * setlocaleNode::create (listNode* list) {
	return new setlocaleNode (list);
}

void setlocaleNode::run () { 
	listNode * list = list_;
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 1) {
			if (char * locale = setlocale (LC_ALL, stringNode::to_str (v[0]).c_str())){
				strvalue_ = locale;
				return;
			}
		} else
			cerr << "Wrong number parameters" << endl;
	}
	strvalue_ = "";
}  

//----------------------------------------------------------------------

textdomainNode::textdomainNode (listNode* list) : list_ (list) {}

runNode * textdomainNode::create (listNode* list) {
	return new textdomainNode (list);
}

void textdomainNode::run () { 
	listNode * list = list_;
	if (!list) 
		cerr << "Wrong number parameters" << endl;
	else {
		list->run();
		vector<runNode*> v = list->listvalue ();
		if (v.size() == 1) {
			if (char * locale = textdomain (stringNode::to_str (v[0]).c_str())){
				strvalue_ = locale;
				return;
			}
		} else
			cerr << "Wrong number parameters" << endl;
	}
	strvalue_ =  "";
}  
