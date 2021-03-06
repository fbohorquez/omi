function symbols () {
   this.node_canvas = document.getElementById(CONFIG.SYMBOLS('SYMBOLS_ID'));
   this.container = document.getElementById(CONFIG.SYMBOLS('CONTAINER_ID'));
   this.info_canvas = document.getElementById(CONFIG.SYMBOLS('INFO_ID'));
   this.node_canvas.width = CONFIG.SYMBOLS('VALUES_LEFT_MARGIN') + 130;
   this.info_canvas.width = CONFIG.SYMBOLS('VALUES_LEFT_MARGIN') + 130;
   this.node_canvas.symbols = this;
   this.info_canvas.symbols = this;
   this.ctx = this.node_canvas.getContext("2d");
   this.info_ctx = this.info_canvas.getContext("2d");
   this.node_canvas.ctx = this.ctx;
   this.info_canvas.ctx = this.info_ctx;
   this.tables = { 'vars' : new table (this, 'vars'), 'funcs' : new table (this, 'funcs'), 'class' :new table (this, 'class')};
   this.table_use = this.tables.vars;
   selectTableSimbols (this.tables.vars, 'vars');
   this.info_canvas.mousemove = function (e) {
      this.ctx.clearRect(0, 0, this.width, this.height);
      var mouse = this.symbols.getMouse(e);
      var vals = this.symbols.table_use.levels_vals[this.symbols.table_use.current_level];
      var nod = null;
      for(var i =0, n = vals.length; i < n; ++i){
         if (
            mouse.x > vals[i].xd && mouse.x <  vals[i].xd + vals[i].wd &&
            mouse.y > vals[i].yd && mouse.y <  vals[i].yd + vals[i].hd
         ){
            if (vals[i] && (vals[i].dynamic || vals[i].share) && vals[i].drawInfo && vals[i].inTable (this.symbols.table_use)) {
              nod = vals[i];
              vals[i].drawInfo(this.ctx, vals[i].xd, vals[i].yd, vals[i].wd, vals[i].hd);
            }
         }
      }
      isNodeClick(nod);
   };
   this.info_canvas.click = function (e) {
      var mouse = this.symbols.getMouse(e);
      var vals = this.symbols.table_use.levels_vals[this.symbols.table_use.current_level];
      for(var i =0, n = vals.length; i < n; ++i){
         if (
            mouse.x > vals[i].xd && mouse.x <  vals[i].xd + vals[i].wd &&
            mouse.y > vals[i].yd && mouse.y <  vals[i].yd + vals[i].hd
         ){
            if (vals[i] && (vals[i].dynamic || vals[i].share) && vals[i].drawInfo && vals[i].inTable (this.symbols.table_use)) {
              var a = null;
              if (vals[i].symbols || vals[i].funcs) {
               a = select_symbols.slice ();
              }
              var unselect =  (tree.omi.select_node == vals[i]);
              vals[i].click();
              if ((vals[i].symbols || vals[i].funcs) && !unselect) {
               if (vals[i].funcs) {
                  select_symbols.unshift ({'name' : vals[i].vars.id, 'table' : vals[i].vars, 'level': 0, 'same' : vals[i].id});
               }
               select_symbols = select_symbols.concat (a);
              }
           }
         }
      }
   };
   if (!this.info_canvas.hasevent){
      this.info_canvas.addEventListener('click', this.info_canvas.click , true);
      this.info_canvas.addEventListener('mousemove', this.info_canvas.mousemove , true);
      this.info_canvas.hasevent = true;
   }
}

symbols.iDefault = function () {
  symbols.omi = new symbols ();
  symbols.omi.funcs_default = symbols.omi.tables.funcs;
  symbols.omi.vars_default = symbols.omi.tables.vars;
};

symbols.prototype.getMouse = function(e) {
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


function table (symbols, id) {
   this.levels = [[]];
   this.levels_vals = [[]];
   this.refs = [{}];
   this.vals = [{}];
   this.current_level = 0;
   this.symbols = symbols;
   this.ctx = symbols.ctx;
   this.id = id;
}

table.prototype.draw = function(clear) {
      if (clear) 
         this.clear();
      var level = this.levels[this.current_level];
      var level_vals = this.levels_vals[this.current_level];
      var height = 2 + ((level.length > level_vals)?level.length:level_vals.length);
      this.symbols.node_canvas.height = (height) * (CONFIG.SYMBOLS('ROW_SIZE') + CONFIG.SYMBOLS('TABLE_TOP_MARGIN') + CONFIG.SYMBOLS('VERTICAL_MARGIN') + CONFIG.SYMBOLS('NODE_HEIGHT')) ;
      this.symbols.info_canvas.height = (height) * (CONFIG.SYMBOLS('ROW_SIZE') + CONFIG.SYMBOLS('TABLE_TOP_MARGIN') + CONFIG.SYMBOLS('VERTICAL_MARGIN') + CONFIG.SYMBOLS('NODE_HEIGHT')) ;
      if (level && level.length) {
         for (i = 0, n = level.length; i < n; ++i) {
            level[i].draw(this.ctx, i);
         }
      }
      if (level_vals && level_vals.length) {
         for (i = 0, n = level_vals.length; i < n; ++i) {
            level_vals[i].drawDynamic(this.ctx, i);
         }
      }
      if (level && level.length) {
         for (i = 0, n = level.length; i < n; ++i) {
            level[i].drawRef(this.ctx, i);
         }
      }
}


table.prototype.clear = function () {
   this.ctx.clearRect(0, 0, this.symbols.node_canvas.width, this.symbols.node_canvas.height);
}


