function clone (source, dest){
   this.source = source;
   this.dest = dest;
};

clone.prototype.drawConsole = function (ctx) {
   ctx = ctx || omi.console_omi.ctx;
   if (this.source) {
      this.source.drawConsole (ctx, ctx.node_canvas.width/4,  ctx.node_canvas.height/ 2)
   }
   if (this.dest) {
      this.dest.drawConsole ( ctx, 3 * ctx.node_canvas.width/4,  ctx.node_canvas.height/ 2)
   }
};
