#include <iostream>
#include <string>
#include "../src/run/runWebTree.h"

using namespace std;

class protocolFTPNode : public runWebNode {
  public:
    protocolFTPNode (runNode *list); 
    void run ();
    runNode** ref ();
    void noderef (runNode* node);
    runNode* nodeval () const {
      return *ref_;
    }
  private:
    runNode *list_;
};

class protocolFTPCreator : public runWebCreator {
  public:
    string  getName (){
      return "FTP";
    }
    protocolFTPNode* createInstance (runNode* list) const{
      return new protocolFTPNode (list);
    }
};

