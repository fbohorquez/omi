#include <iostream>
#include <string>
#include "../src/run/runWebTree.h"

using namespace std;

class protocolNode : public runWebNode {
  public:
    protocolNode (runNode *list); 
    void run ();
    runNode** ref ();
    void noderef (runNode* node);
    runNode* nodeval () const {
      return *ref_;
    }
  private:
    runNode *list_;
};

class protocolCreator : public runWebCreator {
  public:
    string  getName (){
      return "HTTP";
    }
    protocolNode* createInstance (runNode* list) const{
      return new protocolNode (list);
    }
};

