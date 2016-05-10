function node (obj, col, parent) {
   var c = col || 0;
   this.parent = parent || null;
   this.id = obj.id;
   this.name = obj.name;
   this.type = obj.type;
   this.value = obj.value;
   this.size = obj.size;
   this.key = obj.key;
   this.rel = [];
   this.col = c;
   this.node_color = CONFIG.NODE('NODE_COLOR');
   this.value_color = CONFIG.NODE('VALUE_COLOR');
   this.info_color = CONFIG.NODE('INFO_COLOR');
   this.colapse_value = true;
   this.row = row;
   this.dynamic = obj.dynamic || false;
   if (obj.rel){
      for (var i = 0; i < obj.rel.length; ++i){
         if (i > 0) 
            row++;
         c += ((CONFIG.NODE('DOWN_CHILD').indexOf(obj.name) != -1 && (i > 0))?0:1);
         this.rel.push(new node (obj.rel[i], c, this));   
         c -= ((CONFIG.NODE('DOWN_CHILD').indexOf(obj.name) != -1 && (i > 0))?0:1);        
      }
   }
   idMap[this.id] = this;
}

node.prototype.draw = function(ctx, x, y, w, h) {
   ctx = ctx || tree.omi.ctx;
   ctx.font = CONFIG.NODE('NODE_FONT');
   this.node_txt_size = ctx.measureText(this.name).width;
   ctx.fillStyle = this.node_color;
   this.x = x || this.col * CONFIG.NODE('COL_SIZE');
   this.y = y || this.row * CONFIG.NODE('ROW_SIZE');
   this.w = w || this.node_txt_size + CONFIG.NODE('NODE_MARGIN');
   this.h = h || CONFIG.NODE('NODE_HEIGHT');
   ctx.fillAndStrokeRect(this.x, this.y, this.w, this.h);
   ctx.fillStyle = "black";
   ctx.fillText(
      this.name, 
      this.x + CONFIG.NODE('NODE_MARGIN')/2, 
      this.y + CONFIG.NODE('NODE_HEIGHT')/2 + 3 
   );
   if (this.key) {
      this.drawKey (ctx);
   }
   if (this.rel)
      for (var i = 0; i < this.rel.length; ++i){
         this.rel[i].draw (ctx);
         this.drawRel (ctx,this.rel[i]);
   }
   this.drawVal(ctx);
}

node.prototype.drawRel = function(ctx, n, func) {
   ctx = ctx || tree.omi.ctx;
   if (this.row == n.row){
      var ix = this.col * CONFIG.NODE('COL_SIZE') +
         this.node_txt_size + CONFIG.NODE('NODE_MARGIN');
      var iy =  this.row * CONFIG.NODE('ROW_SIZE') + 
         CONFIG.NODE('NODE_HEIGHT')/2;
      var ex = this.col * CONFIG.NODE('COL_SIZE') + 
         (n.col - this.col) * CONFIG.NODE('COL_SIZE');
      var ey = iy;
      if (!func){
         ctx.beginPath();
         ctx.moveTo(ix,iy);
         ctx.lineTo(ex,ey);
         ctx.stroke();
      }else{
         func (ctx,ix,iy,ex,ey);
      }
   }else {
      var ix = this.col * CONFIG.NODE('COL_SIZE') +
         (this.node_txt_size + CONFIG.NODE('NODE_MARGIN'))/2;
      var iy = this.row * CONFIG.NODE('ROW_SIZE') + CONFIG.NODE('NODE_HEIGHT');
      var ex = ix;
      var ey = iy + ((n.row - this.row) * CONFIG.NODE('ROW_SIZE')) - CONFIG.NODE('NODE_HEIGHT')/((this.col == n.col)?1:2);
      if (!func){
         ctx.beginPath();
         ctx.moveTo(ix,iy);
         ctx.lineTo(ex,ey);
         ctx.stroke();
      }else{
         func (ctx,ix,iy,ex,ey);
      }
      if (this.col != n.col)  {
         ix = ex;
         iy = ey;
         ex = ix + CONFIG.NODE('COL_SIZE') - (this.node_txt_size + CONFIG.NODE('NODE_MARGIN'))/2;
         ey = iy;
         if(!func){
            ctx.beginPath();
            ctx.moveTo(ix,iy);
            ctx.lineTo(ex,ey);
            ctx.stroke();
         }else{
            func (ctx,ix,iy,ex,ey);
         }
      }
   }
}

node.prototype.drawVal = function(ctx) {
   if(this.value){
      ctx.font = CONFIG.NODE('VALUE_FONT');
      ctx.fillStyle = this.value_color;
      var txt = this.value
      if (this.colapse_value)
         txt = txt.trunc(CONFIG.NODE('VALUE_COLAPSE_MAX')) + ((txt[0] == '"')?'"':'');
      this.value_txt_size = ctx.measureText(txt).width;
      this.w_val = this.value_txt_size + CONFIG.NODE('NODE_MARGIN');
      this.h_val = CONFIG.NODE('VALUE_HEIGHT');
      this.x_val = this.x + this.w - (this.value_txt_size + CONFIG.NODE('NODE_MARGIN')) / 2;
      this.y_val = this.y + this.h - CONFIG.NODE('VALUE_OFSET_Y');
      ctx.fillAndStrokeRect (this.x_val, this.y_val, this.w_val, this.h_val);
      ctx.fillStyle = "black";
      ctx.fillText(
         txt, 
         this.x + this.w - this.value_txt_size / 2, 
         this.y + this.h - CONFIG.NODE('VALUE_OFSET_Y') + 
            CONFIG.NODE('VALUE_HEIGHT')/2 + 3 
      );
   }
}

node.prototype.clear = function(ctx) {
   ctx = ctx || tree.omi.ctx;
   ctx.clearRect(
      this.col * CONFIG.NODE('COL_SIZE') -1, 
      this.row * CONFIG.NODE('ROW_SIZE') -1, 
      this.node_txt_size + CONFIG.NODE('NODE_MARGIN') + 2, 
      CONFIG.NODE('NODE_HEIGHT') + 2
   );
}

node.prototype.del = function(ctx) {
   ctx = ctx || tree.omi.ctx;
   canvas = ctx.canvas;
   ctx.clearRect(
      this.col * CONFIG.NODE('COL_SIZE') -2, 
      this.row * CONFIG.NODE('ROW_SIZE') -2, 
      canvas.width, 
      CONFIG.NODE('ROW_SIZE') *  (((this.rel.length)?this.rel[this.rel.length - 1].row - this.row:0) + 1 )
   );
   f = function (ctx, ix,iy,ex,ey) {
      if (ix == ex) {
         ctx.clearRect(ix -1, iy + 1, 2, ey - iy );
      }else{
         ctx.clearRect(ix +1 , iy -1, ex - ix, 2 );
      }
   };
   this.parent.drawRel(ctx, this, f);
}

node.prototype.drawInfo = function (ctx) {
   ctx = ctx || tree.omi.info_ctx;
   var info = this.generateInfo();
   this.info_txt_size = 0;
   for (var i = 0; i < info.length; ++i) 
      if (this.info_txt_size < ctx.measureText(info[i]).width)
         this.info_txt_size = ctx.measureText(info[i]).width
   this.info_txt_heigth = CONFIG.NODE('INFO_LINE_HEIGTH') * info.length;
   var x, y, w, h, draw_row;
   if (this.col != 0) {
      x = this.x + this.w/2 - (this.info_txt_size + CONFIG.NODE('INFO_MARGIN_HORIZONTAL'))/2;
      y = this.y + this.h - CONFIG.NODE('INFO_ROW_OFSET') + CONFIG.NODE('INFO_ROW_HEIGTH');
      func = this.drawInfoRowDown;
   }else {
      x = this.x + this.w - CONFIG.NODE('INFO_ROW_OFSET') + CONFIG.NODE('INFO_ROW_HEIGTH');
      y = this.y + this.h - CONFIG.NODE('INFO_ROW_OFSET');
      func = this.drawInfoRowRight;
   }
   h = this.info_txt_heigth + CONFIG.NODE('INFO_MARGIN_VERTICAL');
   w = this.info_txt_size + CONFIG.NODE('INFO_MARGIN_HORIZONTAL');
   this.drawInfoTxt (ctx, x, y, w, h, info);
   func.call(this,ctx);
}

node.prototype.drawInfoTxt = function(ctx, x, y, w, h, info) {
   ctx.fillStyle = this.info_color;
   ctx.fillAndStrokeRect (x,y,w,h);
   ctx.fillStyle = "black";
   ctx.font = CONFIG.NODE('INFO_FONT');
   
   for (var i = 0; i < info.length; ++i){
      ctx.fillText(
         info[i], 
         x + CONFIG.NODE('INFO_MARGIN_HORIZONTAL')/2, 
         y + (CONFIG.NODE('INFO_LINE_HEIGTH') * i) +  CONFIG.NODE('INFO_LINE_HEIGTH')/2 + CONFIG.NODE('INFO_MARGIN_VERTICAL')/2 + 3
      ); 
   }
   if (idMap[this.value] && !idMap[this.value].dynamic) {
         idMap[this.value].node_color = CONFIG.NODE('NODE_REF_COLOR');
         idMap[this.value].draw();
         tree.node_out = this;
         tree.node_out_call = function (obj) {
            if (idMap[obj.value]){
               idMap[obj.value].node_color = CONFIG.NODE('NODE_COLOR');
               idMap[obj.value].draw();
            }
         }
         ctx.beginPath();
         ctx.strokeStyle = CONFIG.NODE('NODE_REF_COLOR');
         ctx.lineWidth=3;
         ctx.beginPath();
         var underx =  x + CONFIG.NODE('INFO_MARGIN_HORIZONTAL')/2;
         var undery = y + (CONFIG.NODE('INFO_LINE_HEIGTH') * (info.length - 1)) 
            +  CONFIG.NODE('INFO_LINE_HEIGTH')/2 + CONFIG.NODE('INFO_MARGIN_VERTICAL')/2 + 8
         ctx.moveTo(underx + 55, undery );
         ctx.lineTo(underx + 124, undery);
         ctx.stroke();  
         ctx.strokeStyle = "black";
         ctx.lineWidth=1;
   }
};

node.prototype.drawInfoRowDown = function(ctx) {
   var row_x = this.x + this.w/2;
   var row_y = this.y + this.h - CONFIG.NODE('INFO_ROW_OFSET');
   ctx.fillStyle = this.info_color;
   ctx.beginPath();
   ctx.moveTo(row_x,row_y);
   ctx.lineTo(row_x - (CONFIG.NODE('INFO_ROW_HEIGTH')/2),row_y + CONFIG.NODE('INFO_ROW_HEIGTH') + 1);
   ctx.lineTo(row_x + (CONFIG.NODE('INFO_ROW_HEIGTH')/2),row_y + CONFIG.NODE('INFO_ROW_HEIGTH') + 1);
   ctx.fill();
   ctx.fillStyle = "black";
   ctx.beginPath();
   ctx.moveTo(row_x,row_y);
   ctx.lineTo(row_x - (CONFIG.NODE('INFO_ROW_HEIGTH')/2),row_y + CONFIG.NODE('INFO_ROW_HEIGTH') + 1);
   ctx.moveTo(row_x,row_y);
   ctx.lineTo(row_x + (CONFIG.NODE('INFO_ROW_HEIGTH')/2),row_y + CONFIG.NODE('INFO_ROW_HEIGTH') + 1);
   ctx.stroke(); 
};

node.prototype.drawInfoRowRight = function(ctx) {
   var row_x = this.x + this.w - CONFIG.NODE('INFO_ROW_OFSET');
   var row_y = this.y + this.h - CONFIG.NODE('INFO_ROW_OFSET');
   ctx.fillStyle = this.info_color;
   ctx.beginPath();
   ctx.moveTo(row_x,row_y);
   ctx.lineTo(row_x + CONFIG.NODE('INFO_ROW_HEIGTH') + 1, row_y);
   ctx.lineTo(row_x + CONFIG.NODE('INFO_ROW_HEIGTH') + 1,row_y + CONFIG.NODE('INFO_ROW_HEIGTH'));
   ctx.fill();
   ctx.fillStyle = "black";
   ctx.beginPath();
   ctx.moveTo(row_x,row_y);
   ctx.lineTo(row_x + CONFIG.NODE('INFO_ROW_HEIGTH') + 1, row_y);
   ctx.moveTo(row_x,row_y);
   ctx.lineTo(row_x + CONFIG.NODE('INFO_ROW_HEIGTH') + 1,row_y + CONFIG.NODE('INFO_ROW_HEIGTH'));
   ctx.stroke(); 
};

node.prototype.drawConsole = function (ctx, x, y) {
   ctx = ctx || omi.console_omi.ctx;
   x = x || ctx.node_canvas.width/2;
   y = y || ctx.node_canvas.height/2;
   ctx.font = CONFIG.NODE('NODE_FONT');
   if (idMap[this.value]){
      x /= 2;
      idMap[this.value].drawConsole (ctx, x*3, y);
      ctx.font = CONFIG.NODE('NODE_FONT');
   }
   if (!this.key)
      this.node_txt_size = ctx.measureText((ctx.measureText(this.name).width > ctx.measureText(this.id).width)?this.name:this.id).width; //
   else{
      node_w = ctx.measureText(this.name).width + ctx.measureText(this.key).width + CONFIG.NODE('NODE_MARGIN');
      id_w = ctx.measureText(this.id).width;
      this.node_txt_size = (node_w > id_w)?node_w:id_w;
   }
   
   ctx.fillStyle = this.node_color;
   this.x = x - (this.node_txt_size + CONFIG.NODE('NODE_MARGIN')) / 2;
   this.y = y - (CONFIG.NODE('NODE_HEIGHT')) / 2;;
   this.w = this.node_txt_size + CONFIG.NODE('NODE_MARGIN');
   this.h = CONFIG.NODE('NODE_HEIGHT');
   ctx.fillAndStrokeRect(this.x, this.y, this.w, this.h);
   ctx.fillStyle = "black";
   ctx.fillText(
      this.name, 
      this.x + CONFIG.NODE('NODE_MARGIN')/2, 
      this.y + CONFIG.NODE('NODE_HEIGHT')/2 + 2 
   );
   if (this.key)
      this.drawKey (ctx);  
   this.drawVal(ctx);
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
}

node.prototype.drawDynamic = function(ctx, i) {
   ctx = ctx || symbols.omi.ctx;
   this.symbols_pos = i;
   ctx.font = CONFIG.NODE('NODE_FONT');
   this.x = CONFIG.SYMBOLS('VALUES_LEFT_MARGIN');
   this.y = i * (CONFIG.NODE('NODE_HEIGHT') + CONFIG.SYMBOLS('VERTICAL_MARGIN')) + (i + 1) * + CONFIG.NODE('PTR_HEIGHT') + CONFIG.SYMBOLS('TABLE_TOP_MARGIN') ;
   this.w = ctx.measureText((ctx.measureText(this.name).width > ctx.measureText(this.id).width)?this.name:this.id).width + CONFIG.NODE('NODE_MARGIN');
   this.draw (
      ctx, 
      this.x,
      this.y,
      this.w
      
   );
   this.drawPtr(ctx);
   this.drawVal(ctx);
}

node.prototype.drawDelete = function(ctx) {
   ctx = ctx || symbols.omi.ctx;
   ctx.beginPath();
   ctx.strokeStyle = CONFIG.NODE("DELETE_LINE_COLOR") || "black";
   ctx.lineWidth = 3;
   ctx.moveTo(this.x, this.y);
   ctx.lineTo(this.x + this.w, this.y + this.h);
   ctx.stroke();
   ctx.moveTo(this.x, this.y + this.h);
   ctx.lineTo(this.x + this.w, this.y);
   ctx.stroke();
   ctx.lineWidth = 1;
};

node.prototype.drawPtr = function (ctx) {
   ctx = ctx || omi.console_omi.ctx;
   ctx.font = CONFIG.NODE('NODE_FONT');
   y = this.y - CONFIG.NODE('PTR_HEIGHT');
   ctx.fillStyle = CONFIG.NODE('PTR_COLOR');
   ctx.fillAndStrokeRect(this.x, this.y - CONFIG.NODE('PTR_HEIGHT'), this.w, CONFIG.NODE('PTR_HEIGHT'));
   ctx.fillStyle = "black";
   ctx.fillText(
      this.id, 
      this.x + CONFIG.NODE('NODE_MARGIN')/2, 
      this.y - CONFIG.NODE('PTR_HEIGHT') + CONFIG.NODE('NODE_HEIGHT')/2
   );
   this.drawVal(ctx);
}

node.prototype.drawKey = function (ctx) {
   ctx = ctx || omi.console_omi.ctx;
   var x = this.x + this.w;
   var y = this.y;
   var txt_size = ctx.measureText(this.key).width;
   var w = txt_size + CONFIG.NODE('NODE_MARGIN');
   var h = this.h;
   ctx.fillStyle = CONFIG.NODE('KEY_COLOR');
   ctx.fillAndStrokeRect(x, y, w, h);
   this.w += w;
   ctx.fillStyle = "black";
   ctx.fillText(
      this.key, 
      x + CONFIG.NODE('NODE_MARGIN')/2, 
      y + CONFIG.NODE('NODE_HEIGHT')/2 + 3
   );
}

node.prototype.isvisible = function () {
   return (
      this.y >= ((!this.dynamic)?tree:symbols).omi.container.scrollTop && 
      this.y < ((!this.dynamic)?tree:symbols).omi.container.scrollTop + ((!this.dynamic)?tree:symbols).omi.container.clientHeight + 36 &&
      this.x >= ((!this.dynamic)?tree:symbols).omi.container.scrollLeft && 
      this.x < ((!this.dynamic)?tree:symbols).omi.container.scrollLeft + ((!this.dynamic)?tree:symbols).omi.container.clientWidth - 36
   );
};
node.prototype.toscroll = function () {
   ((!this.dynamic)?tree:symbols).omi.container.scrollTop = this.y - ((this.dynamic)?(CONFIG.NODE('PTR_HEIGHT')):0);
   ((!this.dynamic)?tree:symbols).omi.container.scrollLeft = this.x;
};

node.prototype.generateInfo = function() {
   var info = [
      "- name: " + this.name,
      "- ptr*: " + this.id,
      "- type: " + this.type,
      "- size: " + this.size,
   ];
   if (this.dynamic) {
      info.push("- dynamic node"); 
   }
   if (this.value) {
      values_line = this.value.multiline(20, ((this.value[0] == '"')?"   \"":""), (this.value[0] == '"')?"\" \\\\":"");
      info.push("- value: " + values_line[0]);
      for (i = 1, n = values_line.length; i < n; ++i)
         info.push(values_line[i]);
   }
   return info;
}
