function ref (obj) {
  this.name = obj.key;
  this.id = obj.id;
  this.level = obj.level || 0;
  this.table = obj.table;
  idMap[this.id] = this;
  this.rel = obj.rel || null;
  this.ref = obj.ref || null;
  this.node_color = CONFIG.SYMBOLS('NODE_COLOR');
  this.dynamic = true;
  this.tables_symbols = [];
  this.static = null;
  this.global = null;
}

ref.prototype.draw = function(ctx, i, x,y,w,h) {
   ctx = ctx || symbols.omi.ctx;
   ctx.font = CONFIG.NODE('NODE_FONT');
   var flags = "";
   if(this.static) flags += "S,";
   if(this.private) flags += "P,";
   if(this.global) flags += "G,";
   if (flags) flags = flags.slice (0,-1);
   var txt = "Ref: " + this.name + ((flags)?' [' + flags + ']':'');
   this.node_txt_size = ctx.measureText(txt).width;
   ctx.fillStyle = this.node_color;
   if (!x) {
      this.x = CONFIG.SYMBOLS('TABLE_LEFT_MARGIN');
      this.y = i * (CONFIG.NODE('NODE_HEIGHT') + CONFIG.SYMBOLS('VERTICAL_MARGIN')) + (i + 1) * + CONFIG.NODE('PTR_HEIGHT') + CONFIG.SYMBOLS('TABLE_TOP_MARGIN') ;
      this.w = CONFIG.SYMBOLS('COL_SIZE') + CONFIG.SYMBOLS('NODE_MARGIN');
      this.h = CONFIG.NODE('NODE_HEIGHT');
   }else {
      this.x = x;
      this.y = y;
      this.w = w;
      this.h = h;
   }
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
      x = this.ref.xd;
      y = this.ref.yd + CONFIG.NODE('NODE_HEIGHT')/2;
      if (this.ref instanceof ref)
         y += CONFIG.NODE('PTR_HEIGHT');
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

ref.prototype.drawConsole = function (ctx, x, y, alter) {
   ctx = ctx || omi.console_omi.ctx;
   x = x || ctx.node_canvas.width/2;
   y = y || ctx.node_canvas.height/2;
   ctx.font = CONFIG.NODE('NODE_FONT');
   var name_ref = "Ref: " + this.name;
   var hasvalue = false;
   var xv, yv, wv, hv; 
   if (!this.key)
      this.node_txt_size = ctx.measureText((ctx.measureText(name_ref).width > ctx.measureText(this.id).width)?name_ref:this.id).width; //
   else{
      node_w = ctx.measureText(name_ref).width + ctx.measureText(this.key).width + CONFIG.NODE('NODE_MARGIN');
      id_w = ctx.measureText(this.id).width;
      this.node_txt_size = (node_w > id_w)?node_w:id_w;
   }
   
   ctx.fillStyle = this.node_color;
   x_aux = this.x;
   y_aux = this.y;
   w_aux = this.w;
   h_aux = this.h;
   this.x = x - (this.node_txt_size + CONFIG.NODE('NODE_MARGIN')) / 2;
   this.y = y - (CONFIG.NODE('NODE_HEIGHT')) / 2;;
   this.w = this.node_txt_size + CONFIG.NODE('NODE_MARGIN');
   this.h = CONFIG.NODE('NODE_HEIGHT');
   ctx.fillAndStrokeRect(this.x, this.y, this.w, this.h);
   ctx.fillStyle = "black";
   ctx.fillText(
      name_ref, 
      this.x + CONFIG.NODE('NODE_MARGIN')/2, 
      this.y + CONFIG.NODE('NODE_HEIGHT')/2 + 2 
   );
   if (this.key)
      this.drawKey (ctx);  
   this.drawPtr(ctx);
   if (idMap[this.value]){
      ctx.beginPath();
      ctx.moveTo(this.x_val + this.w_val, this.y_val + this.h_val/2);
      ctx.lineTo(idMap[this.value].x, idMap[this.value].y - CONFIG.NODE('PTR_HEIGHT') / 2);
      ctx.stroke();
      ctx.fillStyle = "black";
      ctx.lineTo(idMap[this.value].x - 5, idMap[this.value].y - CONFIG.NODE('PTR_HEIGHT') / 2 - 5);
      ctx.lineTo(idMap[this.value].x - 5, idMap[this.value].y - CONFIG.NODE('PTR_HEIGHT') / 2 + 5);
      ctx.lineTo(idMap[this.value].x, idMap[this.value].y - CONFIG.NODE('PTR_HEIGHT') / 2);
      ctx.fill();
   }
   if (!alter) {
      this.x = x_aux;
      this.y = y_aux;
      this.w = w_aux;
      this.h = h_aux;
   }
   if (hasvalue) {
      idMap[this.value].x = xv;
      idMap[this.value].y = yv;
      idMap[this.value].w = wv;
      idMap[this.value].h = hv;
   }
   this.y += CONFIG.NODE('PTR_HEIGHT');
   this.node_color = CONFIG.SYMBOLS('NODE_COLOR');
}

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

ref.prototype.drawDynamic = function(ctx, i) {
   ctx = ctx || symbols.omi.ctx;
   this.symbols_pos = i;
   ctx.font = CONFIG.NODE('NODE_FONT');
   cpx = this.x;
   cpy = this.y;
   cpw = this.w;
   cph = this.h;
   this.x = CONFIG.SYMBOLS('VALUES_LEFT_MARGIN');
   this.y = i * (CONFIG.NODE('NODE_HEIGHT') + CONFIG.SYMBOLS('VERTICAL_MARGIN')) + (i + 1) * + CONFIG.NODE('PTR_HEIGHT') + CONFIG.SYMBOLS('TABLE_TOP_MARGIN') ;
   this.w = CONFIG.SYMBOLS('COL_SIZE') + CONFIG.SYMBOLS('NODE_MARGIN');
   this.h = CONFIG.NODE('NODE_HEIGHT');
   this.draw (ctx, i,this.x,this.y,this.w,this.h);
   //~ this.drawPtr(ctx);
   this.xd = this.x;
   this.yd = this.y;
   this.wd = this.w;
   this.hd = this.h;
   this.x = cpx;
   this.y = cpy;
   this.h = cph;
   this.w = cpw;
}
