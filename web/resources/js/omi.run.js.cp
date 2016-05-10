function run (objs) {
   this.list = objs;
   this.last = null;
   this.i = 0;
}

run.next_action = null;
run.static = null;
run.private = null;
run.global = null;
run.element = null;
run.pid = null;
run.def = null;
run.loop = true;

run.prototype.next = function () {
   if (this.list[0]){
      this.last = this.list.shift();
      return this.last;
   }else{
      return null;
   }
};

run.prototype.addRun = function(add) {
   if (this.list){
      Array.prototype.push.apply(this.list , add);
   }
}

run.action = function (step, action, attrs){
   if (run.next_action) {
      run.next_action();
      run.next_action = null;
   }
   console.log (action, step.id);
   if (tree.omi.select_node) {
      tree.omi.select_node.node_color = CONFIG.NODE('NODE_COLOR');
      tree.omi.select_node = null;
   }
   switch (action){
      
      case 'runClass': 
         run.case_runClass (step, action, attrs);
      case 'run': 
         run.case_run (step, action, attrs);
         break;   
      case 'endClass':
         run.case_endClass (step, action, attrs);
         break;
      case 'setParent':
         run.case_setParent(step, action, attrs);
         break;  
      case 'setValue':
         run.case_setValue (step, action, attrs);
         break;  
      case 'setRef':
         run.case_setRef (step, action, attrs);
         break;
      case 'accessVar': 
         run.case_accessVar (step, action, attrs);
         break;   
      case 'accessFunc': 
         run.case_accessFunc (step, action, attrs);
         break;   
      case 'accessClass': 
         run.case_accessClass (step, action, attrs);
         break;   
      case 'clone': 
         run.case_clone (step, action, attrs);
         break;   
      case 'newNode': 
         run.case_newNode (step, action, attrs);
         break;   
      case 'changeRef': 
         run.case_changeRef (step, action, attrs);
         break;   
      case 'changeValue': 
         run.case_changeRef (step, action, attrs);
         break;   
      case 'delete': 
         run.case_delete (step, action, attrs);
         break;
      case 'print':
         run.case_print (step, action, attrs);
         break;
      case 'input':
         run.case_input (step, action, attrs);
         break;
      case 'toSymbols':
         run.case_toSymbols (step, action, attrs);
         break;
      case 'removeLevel':
         run.case_removeLevel (step, action, attrs);
         break;
      case 'return':
         run.case_return (step, action, attrs);
         break;
      case 'error':
         run.case_error (step, action, attrs);
         break;
      case 'sleep':
         run.case_sleep (step, action, attrs);
         break;
      case 'runStatic':
         run.case_runStatic (step, action, attrs);
         break;
      case 'endStatic':
         run.case_endStatic (step, action, attrs);
         break;
      case 'runPrivate':
         run.case_runPrivate (step, action, attrs);
         break;
      case 'endPrivate':
         run.case_endPrivate (step, action, attrs);
         break;
      case 'runGlobal':
         run.case_runGlobal (step, action, attrs);
         break;
      case 'endGlobal':
         run.case_endGlobal (step, action, attrs);
         break;
         
   }
   if (!select_automatic){
      select_symbols = fixed_select;
      selectTableSimbols ();
   }
};

run.case_runClass = function (step, action, attrs) {
   if (elem = idMap[step.id]){
      elem.isclass = true;
      elem.funcs = new table (symbols.omi, step.id + " [Meths]");
      elem.vars = new table (symbols.omi, step.id + " [Attrs]");
      symbols.omi.funcs_default = elem.funcs;
      symbols.omi.vars_default = elem.vars;
   }
}

run.case_run = function (step, action, attrs) {
   if (elem = idMap[step.id]){
      if (run.element) run.element.node_color = CONFIG.NODE('NODE_COLOR');
      elem.node_color = CONFIG.NODE('NODE_RUN_COLOR');
      run.element = elem;
      if (elem && (!elem.isvisible() || (elem.col == 0 && !elem.dynamic))){
         elem.toscroll();
      }
      console_omi.omi.setValues(( attrs && attrs.msg)?attrs.msg:"Ejecutando " + step.id + ".", elem);
      console_omi.omi.draw(true);
      tree.omi.draw (true);
      symbols.omi.table_use.draw(true);
   }else{
      console.log("Ejecutando nodo implicito");
      tree.run_next();
   }
}   

run.case_endClass = function (step, action, attrs) {
   symbols.omi.funcs_default = symbols.omi.tables.funcs;
   symbols.omi.vars_default = symbols.omi.tables.vars;
   tree.run_next();
}

run.case_setParent = function (step, action, attrs) {
   if(elem = idMap[step.id]){
      if (value = idMap[attrs.value]){
         elem.extends = value;
         console_omi.omi.setValues("Extendiendo la clase " + value.id + " mediante  la clase " + step.id+ ".", elem);
         console_omi.omi.draw(true);
      }
   }else{
      console.log("Asignando valor a nodo implicito");
      tree.run_next();
   }
}

run.case_setValue = function (step, action, attrs){
   if(elem = idMap[step.id]){
      elem.value = attrs.value;
      if (elem && (!elem.isvisible())){
         elem.toscroll();
      }
      console_omi.omi.setValues("Asignando " + elem.value + " como valor interno de " + step.id+ ".", elem);
      console_omi.omi.draw(true);
      if (elem && !elem.dynamic)
         tree.omi.draw (true);
      else
         symbols.omi.draw(true);
   }else{
      console.log("Asignando valor a nodo implicito");
      tree.run_next();
   }
}

run.case_setRef = function (step, action, attrs){
  if(elem = idMap[step.id]){
      elem.value = attrs.value;
      if (elem && (!elem.isvisible())){
         elem.toscroll();
      }
      console_omi.omi.setValues("Asignando " + elem.value + " como referencia de " + step.id+ ".", elem);
      console_omi.omi.draw(true);
      if (elem && !elem.dynamic)
         tree.omi.draw (true);
      else
         symbols.omi.draw(true);
      if (attrs.value && idMap[attrs.value] && idMap[attrs.value].table){
         selectTableSimbols (idMap[attrs.value].table, attrs.value, attrs.value);
      }
   }else{
      console.log("Asignando valor a nodo implicito");
      tree.run_next();
   }
}

run.case_accessVar = function (step, action, attrs){
   level = attrs.level;
   if (!symbols.omi.vars_default.levels[level]){
      symbols.omi.vars_default.levels[level] = [];
   }
   if (!symbols.omi.vars_default.levels_vals[level]){
      symbols.omi.vars_default.levels_vals[level] = [];
   }
   if (!symbols.omi.vars_default.refs[level]){
      symbols.omi.vars_default.refs[level] = {};
   }
   if (!symbols.omi.vars_default.vals[level]){
      symbols.omi.vars_default.vals[level] = {};
   }
   var r = symbols.omi.vars_default.refs[level][attrs.ref]; 
   if (!r){
      r = new ref ({'id': attrs.ref, 'key': attrs.str, 'level' :level, 'table' : symbols.omi.vars_default});
      symbols.omi.vars_default.levels[level].push (r);
      symbols.omi.vars_default.refs[level][attrs.ref] = r;
      if (run.static)
         r.static = true;
      if (run.private)
         r.private = true;
      if (run.global)
         r.global = true;
   }
   if(attrs.val && !symbols.omi.vars_default.vals[level][attrs.val.id]){
      attrs.val.dynamic = true;
      nod = new node (attrs.val);
      if (!nod.tables){
         nod.tables = [];
      }
      nod.tables.push({'table': symbols.omi.vars_default, 'level':level});
      symbols.omi.vars_default.vals[level][attrs.val.id] = nod;
      symbols.omi.vars_default.levels_vals[level].push (nod);
      nod.tables_symbols.push (symbols.omi.vars_default);
      if (nod) r.ref = nod;
   }
   if (r && (!r.isvisible())){
      r.toscroll();
   }
   symbols.omi.vars_default.refs[level][attrs.ref].node_color = CONFIG.SYMBOLS('ACCESS_COLOR');
   symbols.omi.vars_default.current_level  = level;
   console_omi.omi.setValues("Accediendo al s&iacute;mbolo " + attrs.str + " para obtener " + attrs.val.id + " [" + (attrs.val.value?attrs.val.value.trunc(5):"NULL") + "].");
   console_omi.omi.draw(true);
   run.next_action = function () {
      symbols.omi.vars_default.draw(true);
   }
   selectTableSimbols (symbols.omi.vars_default, symbols.omi.vars_default.id, symbols.omi.vars_default.id, null, level);
   symbols.omi.vars_default.refs[level][attrs.ref].node_color = CONFIG.SYMBOLS('NODE_COLOR');
}

run.case_accessFunc = function (step, action, attrs){
   var r = symbols.omi.funcs_default.refs[0][attrs.ref]; 
   if (!r){
      r = new ref ({'id': attrs.ref, 'key': attrs.str, 'level' :0, 'table' : symbols.omi.funcs_default});
      symbols.omi.funcs_default.levels[0].push (r);
      symbols.omi.funcs_default.refs[0][attrs.ref] = r;
      if (run.static)
         r.static = true;
      if (run.private)
         r.private = true;
      if (run.global)
         r.global = true;
   }
   if(attrs.val && !symbols.omi.funcs_default.vals[0][attrs.val.id]){
      
      attrs.val.dynamic = true;
      nod = new node (attrs.val);
      if (!nod.tables){
         nod.tables = [];
      }
      nod.tables.push({'table': symbols.omi.funcs_default, 'level':0});
      symbols.omi.funcs_default.vals[0][attrs.val.id] = nod;
      symbols.omi.funcs_default.levels_vals[0].push (nod);
      nod.tables_symbols.push (symbols.omi.funcs_default);
      if (nod) r.ref = nod;
   }
   if (r && (!r.isvisible())){
      r.toscroll();
   }
   symbols.omi.funcs_default.refs[0][attrs.ref].node_color = CONFIG.SYMBOLS('ACCESS_COLOR');
   symbols.omi.funcs_default.current_level  = 0;
   console_omi.omi.setValues("Accediendo al s&iacute;mbolo función '" + attrs.str  + "'" + (attrs.val && attrs.val.value?" para obtener " + attrs.val.id + " [" + attrs.val.value.trunc(5) + "].":""));
   console_omi.omi.draw(true);
   run.next_action = function () {
      symbols.omi.funcs_default.draw(true);
   }
   selectTableSimbols (symbols.omi.funcs_default, symbols.omi.funcs_default.id, symbols.omi.funcs_default.id);
   symbols.omi.funcs_default.refs[0][attrs.ref].node_color = CONFIG.SYMBOLS('NODE_COLOR');
}

run.case_accessClass = function (step, action, attrs){
   var r = symbols.omi.tables.class.refs[0][attrs.ref]; 
   if (!r){
      r = new ref ({'id': attrs.ref, 'key': attrs.str, 'level' :0, 'table' : symbols.omi.tables.class});
      symbols.omi.tables.class.levels[0].push (r);
      symbols.omi.tables.class.refs[0][attrs.ref] = r;
      if (run.static)
         r.static = true;
      if (run.private)
         r.private = true;
      if (run.global)
         r.global = true;
   }
   if(attrs.val && !symbols.omi.tables.class.vals[0][attrs.val.id]){
      
      attrs.val.dynamic = true;
      nod = new node (attrs.val);
      if (!nod.tables){
         nod.tables = [];
      }
      nod.tables.push({'table': symbols.omi.tables.class, 'level':0});
      symbols.omi.tables.class.vals[0][attrs.val.id] = nod;
      symbols.omi.tables.class.levels_vals[0].push (nod);
      nod.tables_symbols.push (symbols.omi.tables.funcs);
      if (nod) r.ref = nod;
   }
   if (r && (!r.isvisible())){
      r.toscroll();
   }
   symbols.omi.tables.class.refs[0][attrs.ref].node_color = CONFIG.SYMBOLS('ACCESS_COLOR');
   symbols.omi.tables.class.current_level  = 0;
   console_omi.omi.setValues("Accediendo al s&iacute;mbolo clase '" + attrs.str  + "'" + (attrs.val && attrs.val.value?" para obtener " + attrs.val.id + " [" + attrs.val.value.trunc(5) + "].":""));
   console_omi.omi.draw(true);
   run.next_action = function () {
      symbols.omi.tables.class.draw(true);
   }
   selectTableSimbols (symbols.omi.tables.class, 'class');
   symbols.omi.tables.class.refs[0][attrs.ref].node_color = CONFIG.SYMBOLS('NODE_COLOR');
}

run.case_clone = function (step, action, attrs){
   var nod = attrs.node;
   nod.dynamic = true;
   dest = idMap[step.id] = new node (nod);
   if (idMap[attrs.of]) {
      source = idMap[attrs.of];
   }
   if (source && (!source.isvisible())){
      source.toscroll();
   }
   c = new clone (source, dest);
   console_omi.omi.setValues("Clonando " + attrs.of + " como  " + step.id + ".", c, dest.generateInfo());
   console_omi.omi.draw(true);
}

run.case_newNode = function (step, action, attrs){
         var nod = attrs.node;
         nod.dynamic = true;
         idMap[step.id] = new node (nod);
         console_omi.omi.setValues("Creando nodo " + nod.id + ".", idMap[step.id]);
         console_omi.omi.draw(true);
         if (attrs.implicit) {
            tree.run_next();
         }
}

run.case_changeRef = function (step, action, attrs){
   if ((r = idMap[step.id]) && attrs.val) {
      if (v = idMap[attrs.val]){
         r.ref = v;
         if (!v.dynammic){
            v.share = true;
         }
         if (!r.table.vals[r.level][v.id]){
            r.table.vals[r.level][v.id] = v;
            v.tables_symbols.push (r.table);
            r.table.levels_vals[r.level].push(v);
         }
         if (r && (!r.isvisible())){
            r.toscroll();
         }
         console_omi.omi.setValues("Apuntando referencia " + r.id + " a  " + v.id + ".");
         console_omi.omi.draw(true);
         //~ r.table.draw(true);
         if (!v.tables)
            v.tables = [];
         v.tables.push({'table': r.table, 'level':r.level});
         selectTableSimbols (r.table, r.table.id, r.table.id, null, r.level);
      }
   }
}

run.case_changeRef = function (step, action, attrs){
   if ((r = idMap[step.id]) && attrs.val) {
      r.value = attrs.val;
      console_omi.omi.setValues("Cambiando valor de " + r.id + " por  " + v.value + ".", r);
      console_omi.omi.draw(true);
      if (!v.tables)
         v.tables = [];
      //~ v.tables.push({'table': r.tables_symbols[0], 'level':r.level});
      selectTableSimbols (r.tables_symbols[0], r.tables_symbols[0].id, r.tables_symbols[0].id, null, r.tables_symbols[0].level);
   }
}

run.case_delete = function (step, action, attrs){
   if ((nod = idMap[step.id]) && nod.dynamic) {
      if (nod.tables) {
         if (nod && (!nod.isvisible())){
            nod.toscroll();
         }
         for (i = 0, n = nod.tables.length;i <n;++i){
            var t = nod.tables[i];
            var elements = t.table.levels_vals[t.level];
            for (j = 0, m = elements.length; j < m; ++j){
               if (elements[j].id == step.id){
                   nod.drawDelete ();
                   t.table.levels_vals[t.level].splice (j, 1);
                   t.table.vals[t.level][step.id] = null;
                   return;
               }
            }
            var refs = t.table.levels[t.level];
            for (j = 0, m = refs.length; j < m; ++j){
               if (refs[j].ref && refs[j].ref.id == step.id){
                  refs[j].ref = null;
               }
            }
         }
         if (idMap[step.id].symbols){
            var element = idMap[step.id];
            run.next_action = function () {  
               if (element.symbols.levels[element.symbols.current_level].length)
                  selectTableSimbols (element.symbols, element.id, element.id);
               else
                  selectTableSimbols (symbols.omi.tables.vars, 'vars', 'vars');
               element = null;
            };
         }else{
            run.next_action = function () {
               symbols.omi.table_use.draw(true);
               if (select_symbols[0].table.levels_vals[select_symbols[0].table.current_level].length == 0) {
                  selectTableSimbols (symbols.omi.tables.vars, 'vars', 'vars');
               }
            };
         }
         console_omi.omi.setValues("Eliminando nodo " + idMap[step.id].id + ".", idMap[step.id]);
         console_omi.omi.draw(true);
         idMap[step.id] = null;
      }
   }
}

run.case_print = function (step, action, attrs){
   elem = idMap[step.id];
   console_omi.omi.setValues("Imprimiendo en la salida.", elem);
   console_omi.omi.draw(true);
   output (attrs.out);
   $("#tab-out").click();
}

run.case_input = function (step, action, attrs){
   elem = idMap[step.id];  
   console_omi.omi.setValues("<span style=\"color:#1198D6\">Escriba los datos de entrada.</span>", elem);
   console_omi.omi.draw(true);
   offStep ();
   input (function (str) {
      run.loop = true;
      requestSend (function (obj) {tree.omi.run_list.addRun(obj); loopfunc(); }, {'data': str});
      onStep ();
   });
   $("#tab-out").click();
}

run.case_toSymbols= function (step, action, attrs){
         if (elem = idMap[step.id]) {
            if (!idMap[step.id].symbols){
               idMap[step.id].symbols = new table (symbols.omi, step.id);
            }
            if (!(val = idMap[attrs.val.id])){
               val = attrs.val;
               val.dynamic = true;
               val = new node (val);
            }
            val.tables.push({'table' : idMap[step.id].symbols, 'level' :0});
            val.tables_symbols.push (idMap[step.id].symbols);
            if (!(key = idMap[attrs.key.id])){
               key = attrs.key;
               key.dynamic = true;
               key.table = idMap[step.id].symbols;
               key.key = key.value || key.name.replace("Ref: ", "");
               key.ref = val;
               key = new ref (key);
            }
            idMap[step.id].symbols.levels[0].push(key);
            idMap[step.id].symbols.refs[0][key.id] = key;
            idMap[step.id].symbols.levels_vals[0].push(val);
            idMap[step.id].symbols.vals[0][val.id] = val;
            symbols.omi.table_use = idMap[step.id].symbols;
            selectTableSimbols (idMap[step.id].symbols, idMap[step.id].id, idMap[step.id].id);
            //~ idMap[step.id].symbols.draw(true);
            console_omi.omi.setValues("Escribiendo tabla de símbolos de " + elem.id + ".", elem);
            console_omi.omi.draw(true);
            
         }
}

run.case_removeLevel= function (step, action, attrs){
   if (symbols.omi.tables.vars.levels[step.id]){
      var ltable = symbols.omi.tables.vars.levels[step.id];
      for (var i = 0, n = ltable.length; i < n; ++i) {
         if (idMap[ltable[i].id])
            idMap[ltable[i].id] = null;
      }
      symbols.omi.tables.vars.levels.pop();
      symbols.omi.tables.vars.levels_vals.pop();
      symbols.omi.tables.vars.vals.pop();
      symbols.omi.tables.vars.refs.pop();
      symbols.omi.tables.vars.current_level --;
      console_omi.omi.setValues("Eliminando nivel de tabla de símbolos.");
      console_omi.omi.draw(true);
      selectTableSimbols (symbols.omi.tables.vars, symbols.omi.tables.vars.id);
   }
}

run.case_return= function (step, action, attrs){
   if (idMap[step.id]){
      if (attrs.value){
         if (!(val = idMap[attrs.value.id])){
            val = attrs.value;
            val.dynamic = true;
            val = new node (val);
            idMap[val.id] = val; 
         }
         console_omi.omi.setValues("Devolviendo valor " + val.id + " [" + (val.value?val.value.trunc(5):"NULL") + "].", idMap[step.id]);
         console_omi.omi.draw(true);
      }
   }
}

run.case_error= function (step, action, attrs){
   console_omi.omi.setValues("<span style=\"color:#E40546;\">" + step.id + "</span>");
   console_omi.omi.draw(true);
}

run.case_sleep= function (step, action, attrs){
   var play = tree.play;
   offStep ();
   setTimeout (
      function () {
         console_omi.omi.setValues("<span style=\"color:#1198D6;\"> Espera finalizada.</span>");
         console_omi.omi.draw(true);
         onStep();
         if (play) {
            tree.run_play ();
         }
      }, 
      attrs.value * 1000
   );
   console_omi.omi.setValues("<span style=\"color:#E40546;\"> Esperando " + attrs.value + " segundos.</span>");
   console_omi.omi.draw(true);
}

run.case_runStatic= function (step, action, attrs){
      if (!run.static) {
         run.static = true;
      }
      run.action(step, 'run', attrs);
}

run.case_endStatic= function (step, action, attrs){
      run.static = null;
      tree.run_next ();
}

run.case_runPrivate= function (step, action, attrs){
   if (!run.private) {
      run.private = true;
   }
   run.action(step, 'run', attrs);
}

run.case_endPrivate= function (step, action, attrs){
   run.private = null;
   tree.run_next ();
}

run.case_runGlobal= function (step, action, attrs){
   if (!run.global) {
      run.global = true;
   }
   run.action(step, 'run', attrs);
}

run.case_endGlobal= function (step, action, attrs){
   run.global = null;
   tree.run_next ();
}

function loopfunc () {
   if (run.loop) {
      if (tree.omi.run_list.list.length < MAX_CACHE){
         requestSend (function (obj) {tree.omi.run_list.addRun(obj);});
      }
     setTimeout(function (){loopfunc ();}, 2000);
   } 
}

function initDefault (obj) {
   tree.iDefault(obj[0]);
   tree.omi.draw ();
   symbols.iDefault();
   console_omi.iDefault();
   run.loop = true;
   loopfunc ();
   onStep ();
}

function requestSend (cb, data) {
   cb = cb || initDefault;
   data = data || {};
   $.ajax ( {
      'url': URL_BASE + "rtree/request/omi_next.php",
      "dataType": "JSON",
      "type": "POST",
      "data":$.extend({'id' : run.pid}, data),
      "success": function (data) {
         if (data.obj){
            if (data.obj.input) {
               run.loop = false;
            }
            if (obj = data.obj.json){
               cb (obj);
               if (data.obj.end){
                  run.loop = false;
               }
            }
            else if (data.obj.error) {
               $("#tab-src").click();
               console_omi.omi.setValues("<span style=\"color:#E40546;\">" + data.obj.error + "</span>");
               console_omi.omi.draw(true);
               run.loop = false;
            } 
            else{
               alert ("Error obteniendo tree.");
               run.loop = false;
            }
         }else{
            alert ("Error de conexión");
         }
      }
   });
}

function send () {
   if (tree.omi)
      tree.omi.del();
   clearInterface ();
   $.ajax ( {
      'url': URL_BASE + "rtree/request/omi_init.php",
      "dataType": "JSON",
      "type": "POST",
      "data":{'code' : editor.getValue()},
      "success": function (data) {
         if (run.pid = data.id){
            requestSend();
         }else {
            alert ("Error de conexión.");
         }
      }
   });
}
