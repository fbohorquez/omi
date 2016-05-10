function tree (obj) {
   this.root = new node (obj);
   this.node_canvas = document.getElementById(CONFIG.TREE('NODE_ID'));
   this.node_canvas.height = (row + 4) * CONFIG.NODE('ROW_SIZE');
   this.node_canvas.width = (last_col + 1) * CONFIG.NODE('COL_SIZE') + 50;
   this.info_canvas = document.getElementById(CONFIG.TREE('INFO_ID'));
   this.info_canvas.height = (row +4) * CONFIG.NODE('ROW_SIZE');
   this.info_canvas.width = (last_col + 1) * CONFIG.NODE('COL_SIZE') + 50;
   this.container = document.getElementById(CONFIG.TREE('CONTAINER_ID'));
   this.node_canvas.tree = this;
   this.info_canvas.tree = this;
   this.ctx = this.node_canvas.getContext("2d");
   this.info_ctx = this.info_canvas.getContext("2d");
   this.node_canvas.ctx = this.ctx;
   this.info_canvas.ctx = this.info_ctx;
   this.info_canvas.mousemove = function (e) {
      this.ctx.clearRect(0, 0, this.width, this.height);
      var mouse = this.tree.getMouse(e);
      var nod = null;
      for(var key in idMap){
         if (
            idMap[key] && mouse.x > idMap[key].x && mouse.x <  idMap[key].x + idMap[key].w &&
            mouse.y > idMap[key].y && mouse.y <  idMap[key].y + idMap[key].h
         ){
            if (idMap[key] && idMap[key] && !idMap[key].dynamic && idMap[key].drawInfo) 
              idMap[key].drawInfo();
              nod = idMap[key];
         }else {
            if (idMap[key] && (idMap[key] == tree.node_out)){
               tree.node_out_call (tree.node_out);
               node_out_call = null;
               node_out = null;
            }
         }
      }
      isNodeClick(nod);
   };
   this.info_canvas.click = function (e) {
      this.ctx.clearRect(0, 0, this.width, this.height);
      var mouse = this.tree.getMouse(e);
      var nod = null;
      for(var key in idMap){
         //~ if (idMap[key] && idMap[key].x && idMap[key].y && idMap[key].w && idMap[key].h){
            if (
              idMap[key] && mouse.x > idMap[key].x && mouse.x <  idMap[key].x + idMap[key].w &&
               mouse.y > idMap[key].y && mouse.y <  idMap[key].y + idMap[key].h
            ){
               //~ if (idMap[key] && !idMap[key].dynamic && idMap[key].drawInfo) 
                 //~ idMap[key].click();
                 
               //~ if (vals[i] && (vals[i].dynamic || vals[i].share) && vals[i].drawInfo && vals[i].inTable (this.symbols.table_use)) {
                 var a = null;
                 if (idMap[key].symbols || idMap[key].funcs) {
                  a = select_symbols.slice ();
                 }
                 var unselect =  (tree.omi.select_node == idMap[key]);
                 idMap[key].click();
                 if ((idMap[key].symbols || idMap[key].funcs) && !unselect) {
                  if (idMap[key].funcs) {
                     select_symbols.unshift ({'name' : idMap[key].vars.id, 'table' : idMap[key].vars, 'level': 0, 'same' : idMap[key].id});
                  }
                  //~ select_symbols = select_symbols.concat (a);
                 }
              }
            //~ }
         //~ }
      }
   };
   if (!this.info_canvas.hasevent){
      this.info_canvas.addEventListener('mousemove', this.info_canvas.mousemove , true);
      this.info_canvas.addEventListener('click', this.info_canvas.click , true);
      this.info_canvas.hasevent = true;
   }
   this.run_list = new run ([]);
}


tree.prototype.getMouse = function(e) {
  var element = this.node_canvas, offsetX = 0, offsetY = 0, mx, my;
  if (element.offsetParent !== undefined) {
    do {
      offsetX += element.offsetLeft;
      offsetY += element.offsetTop;
    } while ((element = element.offsetParent));
  }
  offsetX -= this.container.scrollLeft;
  offsetY -= this.container.scrollTop;
  mx = e.pageX - offsetX;
  my = e.pageY - offsetY;
  return {x: mx, y: my};
}

tree.prototype.draw = function(clear) {
   if (this.root){
      if (clear) 
         this.clear();
      this.root.draw (this.ctx);
   }
}


tree.prototype.clear = function () {
   this.ctx.clearRect(0, 0, this.node_canvas.width, this.node_canvas.height);
   this.info_ctx.clearRect(0, 0, this.node_canvas.width, this.node_canvas.height);
}

idMap = {};
tree.node_out = null;
tree.node_out_call = null;
row = 0;

tree.iDefault = function (a) {
  tree.omi = new tree (a);
};

tree.run_next = function () {
   if (tree.omi) {
      if (step = tree.omi.run_list.next ()){
         run.action(step, step.action, step.attrs);
         
      }else if (!loop){
         console_omi.omi.setValues("<span style=\"color:#1198D6;\">La ejecución del programa ha finalizado.</span>");
         console_omi.omi.draw(true);
         endStep();
      }
   }
};

tree.is_next_stmt = function (){
   return tree.omi.run_list.list[0].action == "run" && idMap[tree.omi.run_list.list[0].id] && (idMap[tree.omi.run_list.list[0].id].name == "stmt" || idMap[tree.omi.run_list.list[0].id].name == "stmtNode");
}

tree.is_next_func = function (){
   return tree.omi.run_list.list[0].action == "run" && idMap[tree.omi.run_list.list[0].id] && (idMap[tree.omi.run_list.list[0].id].name == "function" || idMap[tree.omi.run_list.list[0].id].name == "functionNode");
}

current_stmt = null;
before_stmt = null;
bbefore_stmt = null;

tree.play = null;
tree.run_play = function () {
   $("#control-pause").show();
   $("#control-play").hide();
   tree.play = setInterval ( function () { tree.run_next(); }, 1000);
};

tree.stop_play = function () {
   $("#control-play").show();
   $("#control-pause").hide();
   clearInterval (tree.play);
   tree.play = null;
};


tree.run_next_stmt = function () {
   //~ bbefore_stmt = before_stmt;
   //~ before_stmt = current_stmt;
      //~ if (step = tree.omi.run_list.next ()){
         //~ run.action(step, step.action, step.attrs);
         while (tree.omi.run_list.list.length && !(tree.is_next_stmt())){
               if (step = tree.omi.run_list.next ()) {
                  run.action(step, step.action, step.attrs);
               }
               
         }
      if (step = tree.omi.run_list.next ()) {
         bbefore_stmt = before_stmt;
         before_stmt = current_stmt;
         current_stmt = idMap[step.id];
         run.action(step, step.action, step.attrs);
      }
      if (tree.omi.run_list.list.length && tree.is_next_stmt()){
         if (step = tree.omi.run_list.next ()) {
            current_stmt = idMap[step.id];
            run.action(step, step.action, step.attrs);
         }
      }
      if (tree.omi.run_list.list.length == 0 ){
         if(!loop && tree.omi.run_list.last.action != "inputNode" && tree.omi.run_list.last.action != "input"){
            console_omi.omi.setValues("<span style=\"color:#1198D6;\">La ejecución del programa ha finalizado.</span>");
            console_omi.omi.draw(true);
            endStep();
         }else{
            setTimeout (function () {tree.run_next_stmt();}, 50);
         }
      }
      if (current_stmt && bbefore_stmt && current_stmt.id == bbefore_stmt.id){
         while (tree.omi.run_list.list.length && tree.is_next_stmt()){
            if (step = tree.omi.run_list.next ()) {
               run.action(step, step.action, step.attrs);
            }
         }
         if (tree.omi.run_list.list.length != 0 )
            tree.run_next_stmt();
      }
      console.log (current_stmt && current_stmt.id,  before_stmt && before_stmt.id, bbefore_stmt && bbefore_stmt.id);
};

tree.prototype.del = function () {
   this.root = null;
   idMap = {};
   this.run_list.list = [];
   this.run_list.i = 0;
   this.clear ();
   row = 0;
}

