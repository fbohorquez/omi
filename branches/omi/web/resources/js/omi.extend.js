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
//----------------------------------------------------------------------
CanvasRenderingContext2D.prototype.fillAndStrokeRect = function (x, y, w, h ) {
   this.fillRect(x,y,w,h);
   this.strokeRect(x,y,w,h);
};
//----------------------------------------------------------------------
