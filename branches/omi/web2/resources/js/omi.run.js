function run (objs) {
   this.list = objs;
   this.i = 0;
}

run.prototype.next = function () {
   if (this.list[0]){
      return this.list.shift();
   }else{
      return null;
   }
};

run.prototype.addRun = function(add) {
   if (this.list){
      Array.prototype.push.apply(this.list , add);
   }
}


run.next_action = null;

run.action = function (step, action, attrs){
   if (run.next_action) {
      run.next_action();
      run.next_action = null;
   }
   console.log (action, step.id);
   switch (action){
      case 'run': 
         elem = idMap[step.id];
         if (run.element) run.element.node_color = CONFIG.NODE('NODE_COLOR');
         elem.node_color = CONFIG.NODE('NODE_RUN_COLOR');
         run.element = elem;
         if (elem && (!elem.isvisible() || (elem.col == 0 && !elem.dynamic))){
            elem.toscroll();
         }
         console_omi.omi.setValues("Ejecutando " + step.id + ".", elem);
         console_omi.omi.draw(true);
         tree.omi.draw (true);
         symbols.omi.table_use.draw(true);
         break;   
      case 'setValue':
         elem = idMap[step.id];
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
         break;   
      case 'accessVar': 
         level = attrs.level;
         if (!symbols.omi.tables.vars.levels[level]){
            symbols.omi.tables.vars.levels[level] = [];
         }
         if (!symbols.omi.tables.vars.refs[level]){
            symbols.omi.tables.vars.refs[level] = {};
         }
         if (!symbols.omi.tables.vars.vals[level]){
            symbols.omi.tables.vars.vals[level] = {};
         }
         symbols.omi.tables.vars.id = step.id;
         var r = symbols.omi.tables.vars.refs[level][attrs.ref]; 
         if (!r){
            r = new ref ({'id': attrs.ref, 'key': attrs.str, 'level' :level, 'table' : symbols.omi.tables.vars});
            symbols.omi.tables.vars.levels[level].push (r);
            symbols.omi.tables.vars.refs[level][attrs.ref] = r;
         }
         if(attrs.val && !symbols.omi.tables.vars.vals[level][attrs.val.id]){
            
            attrs.val.dynamic = true;
            nod = new node (attrs.val);
            if (!nod.tables){
               nod.tables = [];
            }
            nod.tables.push({'table': symbols.omi.tables.vars, 'level':level});
            symbols.omi.tables.vars.vals[level][attrs.val.id] = nod;
            symbols.omi.tables.vars.levels_vals[level].push (nod);
            if (nod) r.ref = nod;
         }
         if (r && (!r.isvisible())){
            r.toscroll();
         }
         symbols.omi.tables.vars.refs[level][attrs.ref].node_color = CONFIG.SYMBOLS('ACCESS_COLOR');
         symbols.omi.tables.vars.current_level  = level;
         symbols.omi.tables.vars.draw(true);
         console_omi.omi.setValues("Accediendo al s&iacute;mbolo " + attrs.str + " para obtener " + attrs.val.id + " [" + attrs.val.value.trunc(5) + "].");
         console_omi.omi.draw(true);
         symbols.omi.tables.vars.refs[level][attrs.ref].node_color = CONFIG.SYMBOLS('NODE_COLOR');
         run.next_action = function () {
            symbols.omi.tables.vars.draw(true);
         }
         break;   
      case 'clone': 
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
         break;   
      case 'changeRef': 
         if ((r = idMap[step.id]) && attrs.val) {
            if (v = idMap[attrs.val]){
               r.ref = v;
               if (!r.table.vals[r.level][v.id]){
                  r.table.vals[r.level][v.id] = v;
                  r.table.levels_vals[r.level].push(v);
               }
               if (r && (!r.isvisible())){
                  r.toscroll();
               }
               console_omi.omi.setValues("Apuntando referencia " + r.id + " a  " + v.id + ".");
               console_omi.omi.draw(true);
               r.table.draw(true);
               if (!v.tables)
                  v.tables = [];
               v.tables.push({'table': r.table, 'level':r.level});
            }
         }
         break;   
      case 'delete': 
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
                         break;
                     }
                  }
               }
               run.next_action = function () {
                  symbols.omi.table_use.draw(true);
               }
            }
         }
         break;   
   }
   
};

run.element = null;
var pid = null;
var def = null;
var loop = true;

function loopfunc () {
   if (loop) {
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
   loop = true;
   loopfunc ();
   //~ loop = setInterval ( 
      //~ function () {
         //~ requestSend (function (obj) {tree.omi.run_list.addRun(obj);});
      //~ },
      //~ 1000
   //~ );
}



function requestSend (cb) {
   cb = cb || initDefault;
   $.ajax ( {
      'url': URL + "rtree/request/omi_next.php",
      "dataType": "JSON",
      "type": "POST",
      "data":{'id' : pid},
      "success": function (data) {
         if (obj = data.obj.json){
            cb (obj);
            if (data.obj.end){
               loop = false;
            }
         }
         else if (data.obj.error) {
            alert (data.obj.error);
            loop = false;
         } 
         else{
            alert ("Error obteniendo tree.");
            loop = false;
         }
      }
   });
}

function send () {
   if (tree.omi)
      tree.omi.del();
   $.ajax ( {
      'url': URL + "rtree/request/omi_init.php",
      "dataType": "JSON",
      "type": "POST",
      "data":{'code' : editor.getValue()},
      "success": function (data) {
         if (pid = data.id){
            requestSend();
         }else {
            alert ("Error de conexión.");
         }
      }
   });
}
