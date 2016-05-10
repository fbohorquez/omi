function symbols () {
   this.node_canvas = document.getElementById(CONFIG.SYMBOLS('SYMBOLS_ID'));
   this.container = document.getElementById(CONFIG.SYMBOLS('CONTAINER_ID'));
   this.node_canvas.symbols = this;
   this.ctx = this.node_canvas.getContext("2d");
   this.node_canvas.ctx = this.ctx;
   this.tables = { 'vars' : new table (this), 'funcs' : new table (this), 'class' :new table (this)};
   this.table_use = this.tables.vars;
}

symbols.iDefault = function () {
  symbols.omi = new symbols ();
};

function table (symbols) {
   this.levels = [[]];
   this.levels_vals = [[]];
   this.refs = [{}];
   this.vals = [{}];
   this.current_level = 0;
   this.symbols = symbols;
   this.ctx = symbols.ctx;
}

table.prototype.draw = function(clear) {
      if (clear) 
         this.clear();
      var level = this.levels[this.current_level];
      if (level && level.length) {
         for (i = 0, n = level.length; i < n; ++i) {
            level[i].draw(this.ctx, i);
         }
      }
      var level_vals = this.levels_vals[this.current_level];
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

