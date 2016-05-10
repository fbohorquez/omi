   // libomi_strings.h
   #include <omi/omi.h>

   class ucfirstNode : public stringNode, public extensionNode {
      public:
         using extensionNode::extensionNode; // Si std=c++11
         // ucfirstNode (listNode* list) : extensionNode(list) {}  //Si std=gnu++98
         void run ();
   };
