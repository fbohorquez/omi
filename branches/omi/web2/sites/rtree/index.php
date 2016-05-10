<?php
include ('../../init.php');
?>
<html>   
<head>
      <link href="<?=URL;?>src/vendor/codemirror/lib/codemirror.css" rel="stylesheet" type="text/css" />
      <link href="<?=URL;?>src/vendor/codemirror/theme/yeti.css" rel="stylesheet" type="text/css" />
      <link href="<?=URL;?>src/css/client.css" rel="stylesheet" type="text/css" />
</head>
<body>
   <div id="header">
      <img src="<?=URL?>src/images/logo.png" height="60"/>
   </div>
   <div id="content">
      <form id="rtree" >
   <div id="tree-container">
      <div class="buttons">
         <p id="tree-title" class="title" >
            Run tree
         </p>
      </div>
      <div id="tree">
       <canvas id="tree-drawing" width="1000" height="" 
         style="position: absolute; left: 20; top: 20; z-index: 0;"></canvas>
       <canvas id="info-drawing" width="1000" height="" 
         style="position: absolute; left: 20; top: 20; z-index: 1;"></canvas>
      </div>
   </div>
   <div id="symbols">
    <div class="buttons">
       <p id="symbols-title" class="title" >
            Symbols tables
       </p>
       <a href="#" class="tab tab-active">Vars</a>
       <a href="#" class="tab">Functions</a>
       <a href="#" class="tab">Class</a>
    </div>
    <div id="symbols-container">
      <canvas id="symbols-drawing" width="" height="" 
      style="position: absolute; left: 20; top: 20; z-index: 1;"></canvas>
    </div>
   </div>
   <div id="inout">
    <div class="buttons">
      <p id="inout-title" class="title">
         Input/Output
      </p>
      <a href="#" class="tab tab-active" class="active">In</a>
       <a href="#" class="tab">Out</a>
    </div>
    <div class="source">
      <textarea id="code" name="code"></textarea>
    </div>
   </div>
   <div id="console_omi">
      <div id="console_omi-info">
         <div id="console_omi-graph">
         <canvas id="console_omi-graph-drawing" width="546" height="160" 
            style="position: absolute; left: 0; top: 0; z-index: 1;"></canvas>
         </div>
         <div id="console_omi-txt">
            
         </div>
      </div>
      <div id="console_omi-data">
         <ul id="console_omi-list-value"></ul>
         <div id="controls">
            <a href="#" class="button" onclick="tree.run_next();return false;">Next</a>
            <a href="#" class="button" onclick="send();;return false;">Send</a>
         </div>
      </div>
   </div>
   </form>
</div>
<!--
<input type="button" value="Next" >
      <input type="button" value="Send" onclick="send();">
-->
<div id="footer">
   GPLv3
</div>
<script src="//code.jquery.com/jquery-1.11.3.min.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.tree.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.node.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.config.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.extend.js"></script>

<script type="text/javascript" src="<?=URL;?>src/js/omi.symbols.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.ref.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.console.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.clone.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.run.js"></script>
<script src="<?=URL;?>src/vendor/codemirror/lib/codemirror.js"></script>
<script src="<?=URL;?>src/vendor/codemirror/mode/clike/clike.js" type="text/javascript"></script>
<script> 
  var editor = CodeMirror.fromTextArea(document.getElementById("code"), {
    lineNumbers: true,
    matchBrackets: true,
    mode: "text/x-omi"
  });
  $("#symbols-drawing")[0].width = $("#symbols-container").width();
  $("#tree-drawing")[0].width = $("#tree").width();
  $("#info-drawing")[0].width = $("#tree").width();
  editor.focus();
</script> 
 <script>
   //~ initDefault();
</script>
</body>
</html>




