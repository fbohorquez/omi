//~ g++ -c -fPIC http.cpp -o http.o
//~ g++ -shared http.o -o http.so

#include <iostream>
#include <string>
#include "../src/run/runTree.h"
#include "../src/run/runWebTree.h"
#include "../src/run/typeNode.h"
#include "ftp.h"

using namespace std;
//----------------------------------------------------------------------
protocolFTPNode::protocolFTPNode (runNode *list) : list_ (list){}

void protocolFTPNode::run (){
  runNode *str = new strNode ("FTP");
  cout << "FTP" << endl;
  ref_ = &str;
}

runNode** protocolFTPNode::ref (){
  return ref_;
}

void protocolFTPNode::noderef (runNode* node){
  ref_ = &node;
}

protocolFTPCreator* protocol = new protocolFTPCreator();
//----------------------------------------------------------------------

//----------------------------------------------------------------------
extern "C" void load () {
  factoryWeb::getSingleton()->addElement("ftp", "protocol", protocol);
}
//----------------------------------------------------------------------
