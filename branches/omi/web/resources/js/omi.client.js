a = {
   'id':'0x12e2e30',
   'name':'stmt',
   'type':'stmt',
   'rel': [
      {
         'id':'0x12e0d20',
         'name':'print',
         'type':'stmt','rel': [   
            {
               'id':'0x12e19c0',
               'name':'or',
               'type':'operator',
               'rel': [
                  {
                     'id':'0x12e1980',
                     'name':'or',
                     'type':'operator',
                     'rel': [
                        {
                           'id':'0x12e19c01',
                           'name':'or',
                           'type':'operator',
                           'rel': [
                              {
                                 'id':'0x12e19802',
                                 'name':'or',
                                 'type':'operator',
                                 'rel': [
                                    {
                                       'id':'0x12e0290',
                                       'name':'boolConst',
                                       'type':'data',
                                       'value':'"PEPTIAOA ES EAKEKEKEKEKE"',
                                    },
                                    {
                                       'id':'0x12e00a0',
                                       'name':'boolConst',
                                       'type':'data',
                                       'value':
                                       'true',
                                    },
                                 ],
                              },
                              {
                                 'id':'0x12e0340',
                                 'name':'boolConst',
                                 'type':'data',
                                 'value':'true',
                              },
                           ],
                        },
                        {
                           'id':'0x12e00a03',
                           'name':'boolConst',
                           'type':'data',
                           'value':'true',
                        },
                     ],
                  },
                  {
                     'id':'0x12e03405',
                     'name':'boolConst',
                     'type':'data',
                     'value':'true',
                  },
               ],
            },
         ],
      },
      {
         'id':'0x12e2140',
         'name':'stmt',
         'type':'stmt',
         'rel': [
            {
               'id':'0x12e1d60',
               'name':'print',
               'type':'stmt',
               'rel': [
                  {
                     'id':'0x12e1d90',
                     'name':'or',
                     'type':'operator',
                     'rel': [
                        {
                           'id':'0x12e0d50',
                           'name':'boolConst',
                           'type':'data',
                           'value':'true',
                        },
                        {
                           'id':'0x12e1950',
                           'name':'boolConst',
                           'type':'data',
                           'value':'true',
                        },
                     ],
                  },
               ],
            },
            {
               'id':'0x12e2e300',
               'name':'stmt',
               'type':'stmt',
               'rel': [
                  {
                     'id':'0x12e0d201',
                     'name':'print',
                     'type':'stmt',
                     'rel': [
                        {
                           'id':'0x12e19c02',
                           'name':'or',
                           'type':'operator',
                           'rel': [
                              {
                                 'id':'0x12e19803',
                                 'name':'or',
                                 'type':'operator',
                                 'rel': [
                                    {
                                       'id':'0x12e02901',
                                       'name':'boolConst',
                                       'type':'data',
                                       'value':'true',
                                    },
                                       
                                    {
                                       'id':'0x12e00a02',
                                       'name':'boolConst',
                                       'type':'data',
                                       'value':'true',
                                    },
                                 ],
                              },
                              {
                                 'id':'0x12e03402',
                                 'name':'boolConst',
                                 'type':'data',
                                 'value':'true',
                              },
                           ],
                        },
                     ],
                  },
                  {
                     'id':'0x12e21402',
                     'name':'stmt',
                     'type':'stmt',
                     'rel': [
                        {
                           'id':'0x12e1d601',
                           'name':'print',
                           'type':'stmt',
                           'rel': [
                              {
                                 'id':'0x12e1d901',
                                 'name':'or',
                                 'type':'operator',
                                 'rel': [
                                    {
                                       'id':'0x12e0d505',
                                       'name':'boolConst',
                                       'type':'data',
                                       'value':'true',
                                    },
                                    {
                                       'id':'0x12e19502',
                                       'name':'boolConst',
                                       'type':'data',
                                       'value':'true',
                                    },
                                 ],
                              },
                           ],
                        },
                     ],
                  },
               ],
            }
         ],
      },
   ],
};
//----------------------------------------------------------------------
a = [{'id':'0x2037fc0','name':'stmt','type':'stmt','size':'24Bytes','rel': [{'id':'0x2037600','name':'print','type':'stmt','size':'24Bytes','rel': [{'id':'0x2037930','name':'or','type':'operator','size':'24Bytes','rel': [{'id':'0x20378f0','name':'or','type':'operator','size':'24Bytes','rel': [{'id':'0x202e2a0','name':'boolConst','type':'data','size':'24Bytes','value':'true',},{'id':'0x202e2d0','name':'boolConst','type':'data','size':'24Bytes','value':'true',},],},{'id':'0x20375d0','name':'boolConst','type':'data','size':'24Bytes','value':'true',},],},],},{'id':'0x2037ca0','name':'stmt','type':'stmt','size':'24Bytes','rel': [{'id':'0x2037b40','name':'print','type':'stmt','size':'24Bytes','rel': [{'id':'0x2037c30','name':'or','type':'operator','size':'24Bytes','rel': [{'id':'0x2037860','name':'boolConst','type':'data','size':'24Bytes','value':'true',},{'id':'0x20378c0','name':'boolConst','type':'data','size':'24Bytes','value':'true',},],},],},],},],},[{ 'action':'run', 'id' : '0x2037fc0' },{ 'action':'run', 'id' : '0x2037ca0' },],];
//----------------------------------------------------------------------
row = 0;

var CONFIG = (function() {
     var node_conf = {
         'NODE_FONT': "bold 12px Sans",
         'NODE_MARGIN': 12,
         'NODE_HEIGHT': 40,
         'NODE_COLOR': "#F8BC44",
         'NODE_RUN_COLOR': "red",
         'VALUE_HEIGHT': 20,
         'VALUE_FONT': "bold 12px Sans",
         'VALUE_COLOR': "white",
         'VALUE_OFSET_X': 20,
         'VALUE_OFSET_Y': 10,
         'VALUE_COLAPSE_MAX' :8,
         'INFO_FONT': "bold 12px Sans",
         'INFO_LINE_HEIGTH' : 16,
         'INFO_MARGIN_VERTICAL' : 16,
         'INFO_MARGIN_HORIZONTAL' : 16,
         'INFO_ROW_HEIGTH' : 16,
         'INFO_ROW_OFSET' : 8,
         'INFO_COLOR' : "white",
         'COL_SIZE': 70,
         'ROW_SIZE' : 60,
         'DOWN_CHILD': ["stmt"],
     };
     var tree_conf = {
         'NODE_ID' : "tree-drawing",
         'INFO_ID' : "info-drawing",
     };
     return {
        NODE: function(name) { return node_conf[name]; },
        TREE: function(name) { return tree_conf[name]; },
    };
})();

function node (obj, col, parent) {
   var c = col || 0;
   this.parent = parent || null;
   this.id = obj.id;
   this.name = obj.name;
   this.type = obj.type;
   this.value = obj.value;
   this.size = obj.size;
   this.rel = [];
   this.col = c;
   this.node_color = CONFIG.NODE('NODE_COLOR');
   this.value_color = CONFIG.NODE('VALUE_COLOR');
   this.info_color = CONFIG.NODE('INFO_COLOR');
   this.colapse_value = true;
   this.row = row;
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

node.prototype.draw = function(ctx) {
   ctx = ctx || tree.omi.ctx;
   ctx.font = CONFIG.NODE('NODE_FONT');
   this.node_txt_size = ctx.measureText(this.name).width;
   ctx.fillStyle = this.node_color;
   this.x = this.col * CONFIG.NODE('COL_SIZE');
   this.y = this.row * CONFIG.NODE('ROW_SIZE');
   this.w = this.node_txt_size + CONFIG.NODE('NODE_MARGIN');
   this.h = CONFIG.NODE('NODE_HEIGHT');
   ctx.fillAndStrokeRect(this.x, this.y, this.w, this.h);
   ctx.fillStyle = "black";
   ctx.fillText(
      this.name, 
      this.col * CONFIG.NODE('COL_SIZE') + CONFIG.NODE('NODE_MARGIN')/2, 
      this.row * CONFIG.NODE('ROW_SIZE') + CONFIG.NODE('NODE_HEIGHT')/2 + 3 
   );
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
      ctx.fillAndStrokeRect (
         this.col * CONFIG.NODE('COL_SIZE') +
            this.node_txt_size + CONFIG.NODE('NODE_MARGIN') - CONFIG.NODE('VALUE_OFSET_X'), 
         this.row * CONFIG.NODE('ROW_SIZE') + 
            CONFIG.NODE('NODE_HEIGHT') - CONFIG.NODE('VALUE_OFSET_Y'), 
         this.value_txt_size + CONFIG.NODE('NODE_MARGIN'), 
         CONFIG.NODE('VALUE_HEIGHT')
      );
      ctx.fillStyle = "black";
      ctx.fillText(
         txt, 
         this.col * CONFIG.NODE('COL_SIZE') +
            this.node_txt_size + CONFIG.NODE('NODE_MARGIN') - 
            CONFIG.NODE('VALUE_OFSET_X') + CONFIG.NODE('NODE_MARGIN')/2, 
         this.row * CONFIG.NODE('ROW_SIZE') + 
            CONFIG.NODE('NODE_HEIGHT') - CONFIG.NODE('VALUE_OFSET_Y') + 
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
   var info = [
      "- name: " + this.name,
      "- ptr*: " + this.id,
      "- type: " + this.type,
      "- size: " + this.size,
   ];
   if (this.value) {
      values_line = this.value.multiline(20, ((this.value[0] == '"')?"   \"":""), (this.value[0] == '"')?"\" \\\\":"");
      info.push("- value: " + values_line[0]);
      for (i = 1, n = values_line.length; i < n; ++i)
         info.push(values_line[i]);
   }
   this.info_txt_size = 0;
   for (var i = 0; i < info.length; ++i) 
      if (this.info_txt_size < ctx.measureText(info[i]).width)
         this.info_txt_size = ctx.measureText(info[i]).width
   this.info_txt_heigth = CONFIG.NODE('INFO_LINE_HEIGTH') * info.length;
   var x = this.x + this.w/2 - (this.info_txt_size + CONFIG.NODE('INFO_MARGIN_HORIZONTAL'))/2;
   var y = this.y + this.h - CONFIG.NODE('INFO_ROW_OFSET') + CONFIG.NODE('INFO_ROW_HEIGTH');
   var h = this.info_txt_heigth + CONFIG.NODE('INFO_MARGIN_VERTICAL');
   var w = this.info_txt_size + CONFIG.NODE('INFO_MARGIN_HORIZONTAL');
   ctx.fillStyle = this.info_color;
   ctx.fillAndStrokeRect (x,y,w,h);
   ctx.fillStyle = "black";
   ctx.font = CONFIG.NODE('INFO_FONT');
   for (var i = 0; i < info.length; ++i)
      ctx.fillText(
         info[i], 
         x + CONFIG.NODE('INFO_MARGIN_HORIZONTAL')/2, 
         y + (CONFIG.NODE('INFO_LINE_HEIGTH') * i) +  CONFIG.NODE('INFO_LINE_HEIGTH')/2 + CONFIG.NODE('INFO_MARGIN_VERTICAL')/2 + 3
      ); 
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
}

//----------------------------------------------------------------------

function tree (obj) {
   this.root = new node (obj);
   this.node_canvas = document.getElementById(CONFIG.TREE('NODE_ID'));
   this.info_canvas = document.getElementById(CONFIG.TREE('INFO_ID'));
   this.node_canvas.tree = this;
   this.info_canvas.tree = this;
   this.ctx = this.node_canvas.getContext("2d");
   this.info_ctx = this.info_canvas.getContext("2d");
   this.node_canvas.ctx = this.ctx;
   this.info_canvas.ctx = this.info_ctx;
   this.info_canvas.addEventListener('mousemove', function(e) {
      this.ctx.clearRect(0, 0, this.width, this.height);
      var mouse = this.tree.getMouse(e);
      for(var key in idMap){
         if (
            mouse.x > idMap[key].x && mouse.x <  idMap[key].x + idMap[key].w &&
            mouse.y > idMap[key].y && mouse.y <  idMap[key].y + idMap[key].h
         )
           idMap[key].drawInfo();
      }
   }, true);
}

tree.prototype.getMouse = function(e) {
  var element = this.node_canvas, offsetX = 0, offsetY = 0, mx, my;
  if (element.offsetParent !== undefined) {
    do {
      offsetX += element.offsetLeft;
      offsetY += element.offsetTop;
    } while ((element = element.offsetParent));
  }
  //~ offsetX += this.stylePaddingLeft + this.styleBorderLeft + this.htmlLeft;
  //~ offsetY += this.stylePaddingTop + this.styleBorderTop + this.htmlTop;
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

tree.iDefault = function (a) {
  tree.omi = new tree (a);
}

//----------------------------------------------------------------------
var def = null;
function initDefault () {
   def = new tree (a);
}

//----------------------------------------------------------------------
String.prototype.trunc = 
   String.prototype.trunc ||
   function(n){
       return this.length>n ? this.substr(0,n-3)+'...' : this;
   };
String.prototype.multiline = 
   String.prototype.multiline ||
   function(n, ini, end){
      var i,j,temparray = [],chunk = n;
      for (i=0,j=this.length; i<j; i+=n) 
          temparray.push(((i != 0 && ini)?ini:'') + this.substring(i,i+n) + ((i + n < j && end)?end:''));
      return temparray;
   };

CanvasRenderingContext2D.prototype.fillAndStrokeRect = function (x, y, w, h ) {
   this.fillRect(x,y,w,h);
   this.strokeRect(x,y,w,h);
};
