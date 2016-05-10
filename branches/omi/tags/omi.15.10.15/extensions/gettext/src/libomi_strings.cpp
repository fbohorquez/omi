#include "libomi_strings.h"
void ucfirstNode::run () { 
   vector<runNode*> v = this->getParams ();
   if (v.size() == 1){
      strvalue_ = stringNode::to_str (v[0]);
      strvalue_[0] = toupper(strvalue_[0]);
   }else
       throw errorException("A parameter is required", "ucfirstNode::run, size " + to_string (v.size()) , ERROR_PARAMS);
}  

extern "C" void load (PluginsLoader* loader) {
      loader->add ("ucfirst", create<ucfirstNode>);
   }
