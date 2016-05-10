function ref (obj) {
  this.name = obj.key;
  this.id = obj.id;
  this.level = obj.level || 0;
  this.table = obj.table;
  idMap[this.id] = this;
  this.rel = obj.rel || null;
  this.node_color = CONFIG.SYMBOLS('NODE_COLOR');
}

ref.prototype.draw = function(ctx, i) {
   ctx = ctx || symbols.omi.ctx;
   ctx.font = CONFIG.NODE('NODE_FONT');
   var txt = "Ref: " + this.name;
   this.node_txt_size = ctx.measureText(txt).width;
   ctx.fillStyle = this.node_color;
   this.x = CONFIG.SYMBOLS('TABLE_LEFT_MARGIN');
   this.y = i * (CONFIG.NODE('NODE_HEIGHT') + CONFIG.SYMBOLS('VERTICAL_MARGIN')) + (i + 1) * + CONFIG.NODE('PTR_HEIGHT') + CONFIG.SYMBOLS('TABLE_TOP_MARGIN') ;
   this.w = CONFIG.SYMBOLS('COL_SIZE') + CONFIG.SYMBOLS('NODE_MARGIN');
   this.h = CONFIG.NODE('NODE_HEIGHT');
   ctx.fillAndStrokeRect(this.x, this.y, this.w, this.h);
   ctx.fillStyle = "black";
   ctx.fillText(
      txt, 
      //~ this.x + (this.w /2 ) - this.node_txt_size/2, 
      this.x + CONFIG.NODE('NODE_MARGIN')/2,
      this.y + CONFIG.NODE('ROW_SIZE')/2 - 3 
   );
   ctx.fillStyle = CONFIG.SYMBOLS('REF_COLOR');
   
   ctx.fillAndStrokeRect(this.x + this.w, this.y, CONFIG.SYMBOLS('ROW_SIZE'),CONFIG.SYMBOLS('ROW_SIZE'));
   this.w += CONFIG.SYMBOLS('ROW_SIZE');
   this.drawPtr (ctx);
};

ref.prototype.drawRef = function(ctx, i) {
   if (this.ref) {
      var x = this.x + this.w;
      var y = this.y + this.h - CONFIG.NODE('NODE_HEIGHT')/2;
      ctx.beginPath();
      ctx.moveTo(x, y);
      x = this.ref.x;
      y = this.ref.y + CONFIG.NODE('NODE_HEIGHT')/2;
      ctx.lineTo(x, y);
      ctx.stroke();
      ctx.moveTo(x, y);
      ctx.fillStyle = "black";
      ctx.lineTo(x - 5, y  - 5);
      ctx.lineTo(x - 5, y + 5);
      ctx.lineTo(x, y);
      ctx.fill();
   }
};

ref.prototype.drawPtr = function(ctx) {
   ctx = ctx || symbols.omi.ctx;
   ctx.font = CONFIG.NODE('PTR_FONT');
   var txt = this.id;
   ptr_size = ctx.measureText(txt).width;
   ctx.fillStyle = CONFIG.NODE('PTR_COLOR');
   var x = this.x;
   var y = this.y - CONFIG.NODE('PTR_HEIGHT');
   var w = this.w;
   var h = CONFIG.NODE('PTR_HEIGHT');
   ctx.fillAndStrokeRect(x, y, w, h);
   ctx.fillStyle = "black";
   ctx.fillText(
      txt, 
      //~ this.x + (this.w /2 ) - ptr_size/2, 
      this.x + CONFIG.NODE('NODE_MARGIN')/2, 
      y + CONFIG.NODE('PTR_HEIGHT')/2 + 3
   );
   this.y = y;
   this.h += CONFIG.NODE('PTR_HEIGHT');
};

ref.prototype.isvisible = function () {
   return (
      this.y >= symbols.omi.container.scrollTop && 
      this.y < symbols.omi.container.scrollTop + symbols.omi.container.clientHeight + 36 &&
      this.x >= symbols.omi.container.scrollLeft && 
      this.x < symbols.omi.container.scrollLeft + symbols.omi.container.clientWidth - 36
   );
};
ref.prototype.toscroll = function () {
   symbols.omi.container.scrollTop = this.y - CONFIG.NODE('PTR_HEIGHT');
   symbols.omi.container.scrollLeft = this.x;
};
