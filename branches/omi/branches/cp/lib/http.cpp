#include <iostream>
#include <string>
#include "../src/run/runTree.h"
#include "../src/run/runWebTree.h"
#include "../src/run/typeNode.h"
#include "http.h"

using namespace std;
//----------------------------------------------------------------------
protocolNode::protocolNode (runNode *list) : list_ (list){}

void protocolNode::run (){
  runNode *str = new strNode ("HTTP");
  cout << "HTTP" << endl;
  ref_ = &str;
}

runNode** protocolNode::ref (){
  return ref_;
}

void protocolNode::noderef (runNode* node){
  ref_ = &node;
}

protocolCreator* protocol = new protocolCreator();
//----------------------------------------------------------------------

//----------------------------------------------------------------------
extern "C" void load () {
  factoryWeb::getSingleton()->addElement("http", "protocol", protocol);
}
//----------------------------------------------------------------------
