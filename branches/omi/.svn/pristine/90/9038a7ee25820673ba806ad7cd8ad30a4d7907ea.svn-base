#include <iostream>
#include <string>
#include "../src/plugin.h"
#include "../src/run/runTree.h"
#include "../src/run/typeNode.h"
#include <locale.h>
using namespace std;


class gettextNode : public stringNode {
	public:
		static runNode* create (listNode* list);
		gettextNode (listNode* list);
		void run ();
	private:
		listNode *list_;
};

class dgettextNode : public stringNode {
	public:
		dgettextNode (listNode* list);
		static runNode* create (listNode* list);
		void run ();
	private:
		listNode *list_;
};

class bindtextdomainNode : public stringNode {
	public:
		bindtextdomainNode (listNode* list);
		static runNode* create (listNode* list);
		void run ();
	private:
		listNode *list_;
};

class setlocaleNode : public stringNode {
	public:
		setlocaleNode (listNode* list);
		static runNode* create (listNode* list);
		void run ();  
	private:
		listNode *list_;
};

class textdomainNode : public stringNode {
	public:
		textdomainNode (listNode* list);
		static runNode* create (listNode* list);
		void run ();  
	private:
		listNode *list_;
};
