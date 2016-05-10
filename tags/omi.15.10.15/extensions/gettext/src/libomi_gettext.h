#include <omi/plugin.h>
#include <omi/run/typeNode.h>

class gettextNode : public stringNode, public extensionNode {
	public:
      using extensionNode::extensionNode;
		void run ();
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
