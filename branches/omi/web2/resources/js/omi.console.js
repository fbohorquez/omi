function console_omi () {
   this.node_canvas = document.getElementById(CONFIG.CONSOLE('CONSOLE_GRAPH_ID'));
   this.container = document.getElementById(CONFIG.CONSOLE('CONTAINER_ID'));
   this.node_canvas.console_omi = this;
   this.ctx = this.node_canvas.getContext("2d");
   this.ctx.node_canvas = this.node_canvas;
   this.node_canvas.ctx = this.ctx;
   this.log = null;
   this.data = null;
   this.graph = null;
   this.text = document.getElementById(CONFIG.CONSOLE('CONSOLE_TEXT_ID'))
   this.info = document.getElementById(CONFIG.CONSOLE('CONSOLE_INFO_ID'))
}

console_omi.iDefault = function () {
  console_omi.omi = new console_omi ();
};


console_omi.prototype.draw = function(clear) {
      if (clear) 
         this.clear();
      if (this.graph) {
         this.graph.drawConsole (this.ctx);
      }
      if (this.log) {
         this.text.innerHTML = this.log;
      }
      if (this.data) {
         this.generateInfo (this.data);
      }
      else if (this.graph){
         var info = this.graph.generateInfo ();
         this.generateInfo (info);
      }
}

console_omi.prototype.generateInfo = function (info) {
   for (i = 0, n = info.length ; i < n ; ++i){
      this.info.innerHTML += "<li>" + info[i] + "</li>";
   }
}

console_omi.prototype.setValues = function(log, graph, data) {
   this.log = log;
   this.data = data;
   this.graph = graph;
}


console_omi.prototype.clear = function () {
   this.ctx.clearRect(0, 0, this.node_canvas.width, this.node_canvas.height);
   this.text.innerHTML = "";
   this.info.innerHTML = "";
}

