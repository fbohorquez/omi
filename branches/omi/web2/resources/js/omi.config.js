a = 
[{'id':'0xfa23c0','name':'stmt','type':'stmt','size':'24Bytes','rel': [{'id':'0xfa07a0','name':'asig','type':'operator','size':'24Bytes','rel': [{'id':'0xfa0060','name':'id','type':'symbol','size':'24Bytes','key': 'b',},{'id':'0xfa0170','name':'asig','type':'operator','size':'24Bytes','rel': [{'id':'0xfa04c0','name':'id','type':'symbol','size':'24Bytes','key': 'a',},{'id':'0xfa0100','name':'numConst','type':'data','size':'24Bytes','value':'4',},],},],},{'id':'0xfa0bf0','name':'stmt','type':'stmt','size':'24Bytes','rel': [{'id':'0xfa01f0','name':'asig','type':'operator','size':'24Bytes','rel': [{'id':'0xfa0840','name':'id','type':'symbol','size':'24Bytes','key': 'c',},{'id':'0xfa0360','name':'numConst','type':'data','size':'24Bytes','value':'8',},],},{'id':'0xfa0470','name':'stmt','type':'stmt','size':'24Bytes','rel': [{'id':'0xfa0810','name':'print','type':'stmt','size':'24Bytes','rel': [{'id':'0xfa2380','name':'or','type':'operator','size':'24Bytes','rel': [{'id':'0xfa0b50','name':'and','type':'operator','size':'24Bytes','rel': [{'id':'0xfa03f0','name':'eq','type':'operator','size':'24Bytes','value':'','rel': [{'id':'0xfa0d10','name':'id','type':'symbol','size':'24Bytes','key': 'a',},{'id':'0xfa0b90','name':'numConst','type':'data','size':'24Bytes','value':'4',},],},{'id':'0xfa0430','name':'lth','type':'operator','size':'24Bytes','value':'','rel': [{'id':'0xfa12b0','name':'numConst','type':'data','size':'24Bytes','value':'4',},{'id':'0xfa0ac0','name':'id','type':'symbol','size':'24Bytes','key': 'b',},],},],},{'id':'0xfa17b0','name':'and','type':'operator','size':'24Bytes','rel': [{'id':'0xfa0300','name':'gth','type':'operator','size':'24Bytes','value':'','rel': [{'id':'0xfa15f0','name':'numConst','type':'data','size':'24Bytes','value':'56',},{'id':'0xfa13c0','name':'id','type':'symbol','size':'24Bytes','key': 'c',},],},{'id':'0xfa14e0','name':'neq','type':'operator','size':'24Bytes','value':'','rel': [{'id':'0xfa1550','name':'id','type':'symbol','size':'24Bytes','key': 'a',},{'id':'0xfa1820','name':'id','type':'symbol','size':'24Bytes','key': 'c',},],},],},],},],},],},],},],},[{'action':'run','id':'0xfa23c0'},{'action':'run','id':'0xfa07a0'},{'action':'run','id':'0xfa0170'},{'action':'run','id':'0xfa0100'},{'action':'run','id':'0xfa0170'},{'action':'clone','id':'0xfa2400', 'attrs':{'of':'0xfa0100','node':{'id':'0xfa2400','name':'num','type':'data','size':'24Bytes','value':'4',} }},{'action':'setValue','id':'0xfa0170','attrs':{'value':'0xfa2400'}},{'action':'run','id':'0xfa04c0'},{'action':'accessVar','id':'0xf75850','attrs':{'str':'a','ref':'0xfa22a0','level':0, 'val': {'id':'0xfa27d0','name':'NULL','type':'data','size':'24Bytes','value':'',} }},{'action':'setValue','id':'0xfa04c0','attrs':{'value':'0xfa27d0'}},{'action':'changeRef','id':'0xfa22a0','attrs':{'val': '0xfa2400' }},{'action':'delete','id':'0xfa27d0'},{'action':'setValue','id':'0xfa04c0','attrs':{'value':'0xfa2400'}},{'action':'run','id':'0xfa2400'},{'action':'run','id':'0xfa07a0'},{'action':'setValue','id':'0xfa07a0','attrs':{'value':'0xfa2400'}},{'action':'run','id':'0xfa0060'},{'action':'accessVar','id':'0xf75850','attrs':{'str':'b','ref':'0x1002fc0','level':0, 'val': {'id':'0x1002d60','name':'NULL','type':'data','size':'24Bytes','value':'',} }},{'action':'setValue','id':'0xfa0060','attrs':{'value':'0x1002d60'}},{'action':'changeRef','id':'0x1002fc0','attrs':{'val': '0xfa2400' }},{'action':'delete','id':'0x1002d60'},{'action':'setValue','id':'0xfa0060','attrs':{'value':'0xfa2400'}},{'action':'run','id':'0xfa23c0'},{'action':'run','id':'0xfa0bf0'},{'action':'run','id':'0xfa01f0'},{'action':'run','id':'0xfa0360'},{'action':'run','id':'0xfa01f0'},{'action':'clone','id':'0x1002d60', 'attrs':{'of':'0xfa0360','node':{'id':'0x1002d60','name':'num','type':'data','size':'24Bytes','value':'8',} }},{'action':'setValue','id':'0xfa01f0','attrs':{'value':'0x1002d60'}},{'action':'run','id':'0xfa0840'},{'action':'accessVar','id':'0xf75850','attrs':{'str':'c','ref':'0x1003020','level':0, 'val': {'id':'0xfa2da0','name':'NULL','type':'data','size':'24Bytes','value':'',} }},{'action':'setValue','id':'0xfa0840','attrs':{'value':'0xfa2da0'}},{'action':'changeRef','id':'0x1003020','attrs':{'val': '0x1002d60' }},{'action':'delete','id':'0xfa2da0'},{'action':'setValue','id':'0xfa0840','attrs':{'value':'0x1002d60'}},{'action':'run','id':'0xfa0bf0'},{'action':'run','id':'0xfa0470'},{'action':'run','id':'0xfa0810'},{'action':'run','id':'0xfa2380'},{'action':'run','id':'0xfa0b50'},{'action':'run','id':'0xfa03f0'},{'action':'run','id':'0xfa0d10'},{'action':'accessVar','id':'0xf75850','attrs':{'str':'a','ref':'0xfa22a0','level':0, 'val': {'id':'0xfa2400','name':'Arithmetic: 4','type':'data','size':'24Bytes','value':'4',} }},{'action':'setValue','id':'0xfa0d10','attrs':{'value':'0xfa2400'}},{'action':'run','id':'0xfa03f0'},{'action':'run','id':'0xfa0b90'},{'action':'run','id':'0xfa03f0'},{'action':'setValue','id':'0xfa03f0','attrs':{'value':'true'}},{'action':'run','id':'0xfa0b50'},{'action':'run','id':'0xfa0430'},{'action':'run','id':'0xfa12b0'},{'action':'run','id':'0xfa0430'},{'action':'run','id':'0xfa0ac0'},{'action':'accessVar','id':'0xf75850','attrs':{'str':'b','ref':'0x1002fc0','level':0, 'val': {'id':'0xfa2400','name':'Arithmetic: 4','type':'data','size':'24Bytes','value':'4',} }},{'action':'setValue','id':'0xfa0ac0','attrs':{'value':'0xfa2400'}},{'action':'run','id':'0xfa0430'},{'action':'setValue','id':'0xfa0430','attrs':{'value':'false'}},{'action':'run','id':'0xfa0b50'},{'action':'setValue','id':'0xfa0b50','attrs':{'value':'0xfa0430'}},{'action':'run','id':'0xfa2380'},{'action':'run','id':'0xfa17b0'},{'action':'run','id':'0xfa0300'},{'action':'run','id':'0xfa15f0'},{'action':'run','id':'0xfa0300'},{'action':'run','id':'0xfa13c0'},{'action':'accessVar','id':'0xf75850','attrs':{'str':'c','ref':'0x1003020','level':0, 'val': {'id':'0x1002d60','name':'Arithmetic: 8','type':'data','size':'24Bytes','value':'8',} }},{'action':'setValue','id':'0xfa13c0','attrs':{'value':'0x1002d60'}},{'action':'run','id':'0xfa0300'},{'action':'setValue','id':'0xfa0300','attrs':{'value':'true'}},{'action':'run','id':'0xfa17b0'},{'action':'run','id':'0xfa14e0'},{'action':'run','id':'0xfa1550'},{'action':'accessVar','id':'0xf75850','attrs':{'str':'a','ref':'0xfa22a0','level':0, 'val': {'id':'0xfa2400','name':'Arithmetic: 4','type':'data','size':'24Bytes','value':'4',} }},{'action':'setValue','id':'0xfa1550','attrs':{'value':'0xfa2400'}},{'action':'run','id':'0xfa14e0'},{'action':'run','id':'0xfa1820'},{'action':'accessVar','id':'0xf75850','attrs':{'str':'c','ref':'0x1003020','level':0, 'val': {'id':'0x1002d60','name':'Arithmetic: 8','type':'data','size':'24Bytes','value':'8',} }},{'action':'setValue','id':'0xfa1820','attrs':{'value':'0x1002d60'}},{'action':'run','id':'0xfa14e0'},{'action':'setValue','id':'0xfa14e0','attrs':{'value':'true'}},{'action':'run','id':'0xfa17b0'},{'action':'setValue','id':'0xfa17b0','attrs':{'value':'0xfa14e0'}},{'action':'run','id':'0xfa2380'},{'action':'setValue','id':'0xfa2380','attrs':{'value':'0xfa14e0'}},{'action':'run','id':'0xfa0810'},{'action':'run','id':'0xfa0470'},{'action':'run','id':'0xfa0bf0'},{'action':'run','id':'0xfa23c0'},],]
;

//----------------------------------------------------------------------


var URL = "http://omi.local/";
var MAX_CACHE = 10;
var CONFIG = (function() {
     var node_conf = {
         'NODE_FONT': "bold 12px Sans",
         'NODE_MARGIN': 8,
         'NODE_HEIGHT': 26,
         //~ 'NODE_COLOR': "#F8BC44",
         'NODE_COLOR': "#FFDD00",
         'NODE_RUN_COLOR': "#1198D6",
         'NODE_REF_COLOR': "#7777FF",
         'VALUE_HEIGHT': 16,
         'VALUE_FONT': "bold 8px Arial",
         'VALUE_COLOR': "white",
         'VALUE_OFSET_X': 16,
         'VALUE_OFSET_Y': 6,
         'VALUE_COLAPSE_MAX' :12,
         'INFO_FONT': "bold 12px Sans",
         'INFO_LINE_HEIGTH' : 16,
         'INFO_MARGIN_VERTICAL' : 16,
         'INFO_MARGIN_HORIZONTAL' : 16,
         'INFO_ROW_HEIGTH' : 16,
         'INFO_ROW_OFSET' : 8,
         'INFO_COLOR' : "white",
         'PTR_HEIGHT' : 20,
         'PTR_COLOR' : "white",
         'KEY_COLOR' : "white",
         'COL_SIZE': 80,
         'ROW_SIZE' : 42,
         'DOWN_CHILD': ["stmt"],
     };
     var tree_conf = {
         'CONTAINER_ID' : "tree",
         'NODE_ID' : "tree-drawing",
         'INFO_ID' : "info-drawing",
     };
     var symbols_conf = {
         'CONTAINER_ID' : "symbols-container",
         'SYMBOLS_ID' : "symbols-drawing",
         'TABLE_LEFT_MARGIN' : 0,
         'TABLE_TOP_MARGIN' : 0,
         'VALUES_LEFT_MARGIN' : 490,
         'ROW_SIZE' : 26,
         'COL_SIZE' : 140,
         'NODE_MARGIN': 8,
         'NODE_HEIGHT': 26,
         'NODE_COLOR': "#BEC7D9",
         'ACCESS_COLOR': "#FF5B5B",
         'REF_COLOR': "white",
         'VERTICAL_MARGIN' : 20,
     };
     var console_omi_conf = {
         'CONTAINER_ID' : "console_omi-graph",
         'CONSOLE_ID' : "console_omi",
         'CONSOLE_GRAPH_ID' : "console_omi-graph-drawing",
         'CONSOLE_TEXT_ID' : "console_omi-txt",
         'CONSOLE_INFO_ID' : "console_omi-list-value",
         'TABLE_LEFT_MARGIN' : 0,
         'TABLE_TOP_MARGIN' : 0,
         'ROW_SIZE' : 26,
         'COL_SIZE' : 140,
         'NODE_MARGIN': 8,
         'NODE_HEIGHT': 26,
         'NODE_COLOR': "#BEC7D9",
         'REF_COLOR': "white",
     };
     return {
        NODE: function(name) { return node_conf[name]; },
        TREE: function(name) { return tree_conf[name]; },
        SYMBOLS: function(name) { return symbols_conf[name]; },
        CONSOLE: function(name) { return console_omi_conf[name]; },
    };
})();




//~ a = {
   //~ 'id':'0x12e2e30',
   //~ 'name':'stmt',
   //~ 'type':'stmt',
   //~ 'rel': [
      //~ {
         //~ 'id':'0x12e0d20',
         //~ 'name':'print',
         //~ 'type':'stmt','rel': [   
            //~ {
               //~ 'id':'0x12e19c0',
               //~ 'name':'or',
               //~ 'type':'operator',
               //~ 'rel': [
                  //~ {
                     //~ 'id':'0x12e1980',
                     //~ 'name':'or',
                     //~ 'type':'operator',
                     //~ 'rel': [
                        //~ {
                           //~ 'id':'0x12e19c01',
                           //~ 'name':'or',
                           //~ 'type':'operator',
                           //~ 'rel': [
                              //~ {
                                 //~ 'id':'0x12e19802',
                                 //~ 'name':'or',
                                 //~ 'type':'operator',
                                 //~ 'rel': [
                                    //~ {
                                       //~ 'id':'0x12e0290',
                                       //~ 'name':'boolConst',
                                       //~ 'type':'data',
                                       //~ 'value':'"PEPTIAOA ES EAKEKEKEKEKE"',
                                    //~ },
                                    //~ {
                                       //~ 'id':'0x12e00a0',
                                       //~ 'name':'boolConst',
                                       //~ 'type':'data',
                                       //~ 'value':
                                       //~ 'true',
                                    //~ },
                                 //~ ],
                              //~ },
                              //~ {
                                 //~ 'id':'0x12e0340',
                                 //~ 'name':'boolConst',
                                 //~ 'type':'data',
                                 //~ 'value':'true',
                              //~ },
                           //~ ],
                        //~ },
                        //~ {
                           //~ 'id':'0x12e00a03',
                           //~ 'name':'boolConst',
                           //~ 'type':'data',
                           //~ 'value':'true',
                        //~ },
                     //~ ],
                  //~ },
                  //~ {
                     //~ 'id':'0x12e03405',
                     //~ 'name':'boolConst',
                     //~ 'type':'data',
                     //~ 'value':'true',
                  //~ },
               //~ ],
            //~ },
         //~ ],
      //~ },
      //~ {
         //~ 'id':'0x12e2140',
         //~ 'name':'stmt',
         //~ 'type':'stmt',
         //~ 'rel': [
            //~ {
               //~ 'id':'0x12e1d60',
               //~ 'name':'print',
               //~ 'type':'stmt',
               //~ 'rel': [
                  //~ {
                     //~ 'id':'0x12e1d90',
                     //~ 'name':'or',
                     //~ 'type':'operator',
                     //~ 'rel': [
                        //~ {
                           //~ 'id':'0x12e0d50',
                           //~ 'name':'boolConst',
                           //~ 'type':'data',
                           //~ 'value':'true',
                        //~ },
                        //~ {
                           //~ 'id':'0x12e1950',
                           //~ 'name':'boolConst',
                           //~ 'type':'data',
                           //~ 'value':'true',
                        //~ },
                     //~ ],
                  //~ },
               //~ ],
            //~ },
            //~ {
               //~ 'id':'0x12e2e300',
               //~ 'name':'stmt',
               //~ 'type':'stmt',
               //~ 'rel': [
                  //~ {
                     //~ 'id':'0x12e0d201',
                     //~ 'name':'print',
                     //~ 'type':'stmt',
                     //~ 'rel': [
                        //~ {
                           //~ 'id':'0x12e19c02',
                           //~ 'name':'or',
                           //~ 'type':'operator',
                           //~ 'rel': [
                              //~ {
                                 //~ 'id':'0x12e19803',
                                 //~ 'name':'or',
                                 //~ 'type':'operator',
                                 //~ 'rel': [
                                    //~ {
                                       //~ 'id':'0x12e02901',
                                       //~ 'name':'boolConst',
                                       //~ 'type':'data',
                                       //~ 'value':'true',
                                    //~ },
                                       //~ 
                                    //~ {
                                       //~ 'id':'0x12e00a02',
                                       //~ 'name':'boolConst',
                                       //~ 'type':'data',
                                       //~ 'value':'true',
                                    //~ },
                                 //~ ],
                              //~ },
                              //~ {
                                 //~ 'id':'0x12e03402',
                                 //~ 'name':'boolConst',
                                 //~ 'type':'data',
                                 //~ 'value':'true',
                              //~ },
                           //~ ],
                        //~ },
                     //~ ],
                  //~ },
                  //~ {
                     //~ 'id':'0x12e21402',
                     //~ 'name':'stmt',
                     //~ 'type':'stmt',
                     //~ 'rel': [
                        //~ {
                           //~ 'id':'0x12e1d601',
                           //~ 'name':'print',
                           //~ 'type':'stmt',
                           //~ 'rel': [
                              //~ {
                                 //~ 'id':'0x12e1d901',
                                 //~ 'name':'or',
                                 //~ 'type':'operator',
                                 //~ 'rel': [
                                    //~ {
                                       //~ 'id':'0x12e0d505',
                                       //~ 'name':'boolConst',
                                       //~ 'type':'data',
                                       //~ 'value':'true',
                                    //~ },
                                    //~ {
                                       //~ 'id':'0x12e19502',
                                       //~ 'name':'boolConst',
                                       //~ 'type':'data',
                                       //~ 'value':'true',
                                    //~ },
                                 //~ ],
                              //~ },
                           //~ ],
                        //~ },
                     //~ ],
                  //~ },
               //~ ],
            //~ }
         //~ ],
      //~ },
   //~ ],
//~ };
