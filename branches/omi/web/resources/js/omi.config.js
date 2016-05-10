
var URL_BASE = "http://omi.local/";
//~ var URL_BASE = "http://192.168.1.15/";
var MAX_CACHE = 100;
var CONFIG = (function() {
     var node_conf = {
         'NODE_FONT': "bold 12px Sans",
         'NODE_MARGIN': 8,
         'NODE_HEIGHT': 26,
         //~ 'NODE_COLOR': "#F8BC44",
         'NODE_COLOR': "#FFDD00",
         'NODE_RUN_COLOR': "#1198D6",
         'NODE_REF_COLOR': "#7777FF",
         'NODE_SELECT_COLOR': "#E40546",
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
         'RELNAME_FONT' : "bold 10px Mono",
         'RELNAME_COLOR' : "#AAA",
         'RELNAME_RIGHTMARGIN' : "4",
         'RELNAME_BOTTOMMARGIN' : "2",
         'PTR_HEIGHT' : 20,
         'PTR_COLOR' : "white",
         'KEY_COLOR' : "white",
         'COL_SIZE': 100,
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
         'INFO_ID' : "symbols-info",
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
