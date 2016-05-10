function tree (obj) {
   this.root = new node (obj);
   this.node_canvas = document.getElementById(CONFIG.TREE('NODE_ID'));
   this.node_canvas.height = (row + 4) * CONFIG.NODE('ROW_SIZE');
   this.info_canvas = document.getElementById(CONFIG.TREE('INFO_ID'));
   this.info_canvas.height = (row +4) * CONFIG.NODE('ROW_SIZE');
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
      for(var key in idMap){
         if (
            mouse.x > idMap[key].x && mouse.x <  idMap[key].x + idMap[key].w &&
            mouse.y > idMap[key].y && mouse.y <  idMap[key].y + idMap[key].h
         ){
            if (idMap[key] && idMap[key].drawInfo) 
              idMap[key].drawInfo();
         }else {
            if (idMap[key] == tree.node_out){
               tree.node_out_call (tree.node_out);
               node_out_call = null;
               node_out = null;
            }
         }
      }
   };
   this.info_canvas.addEventListener('mousemove', this.info_canvas.mousemove , true);
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
   if (tree.omi.run_list) {
      if (step = tree.omi.run_list.next ()){
         
         run.action(step, step.action, step.attrs);
         
      }
   }
};

tree.prototype.del = function () {
   this.root = null;
   idMap = {};
   this.run_list.list = [];
   this.run_list.i = 0;
   this.clear ();
   row = 0;
}

