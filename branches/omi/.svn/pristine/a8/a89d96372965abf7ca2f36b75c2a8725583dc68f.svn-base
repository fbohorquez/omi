<?php
include ('../../init.php');
?>
<html>   
<head>
      <link href='https://fonts.googleapis.com/css?family=Dosis:700,500' rel='stylesheet' type='text/css'>
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css">
      <link rel="stylesheet" href="//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css">
      <link href="<?=URL;?>src/vendor/codemirror/lib/codemirror.css" rel="stylesheet" type="text/css" />
      <link href="<?=URL;?>src/vendor/codemirror/theme/yeti.css" rel="stylesheet" type="text/css" />
      <link href="<?=URL;?>src/css/main.css" rel="stylesheet" type="text/css" />
      <link href="<?=URL;?>src/css/client.css" rel="stylesheet" type="text/css" />
</head>
<body>
   <?php template::top(); ?>
   <div id="content">
<!--
      <form id="rtree" >
-->
   <div id="tree-container">
      <div class="buttons">
         <p id="tree-title" class="title" >
            Run tree<span title="<strong class=help-title>Árbol de ejecución:</strong><br/>Estructura de datos que es creada al procesar el código fuente enviado. Los nodos que forman el árbol serán ejecutados para para producir el resultado semántico. " class="help"><i class="fa fa-question-circle"></i></span>
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
            Symbols tables<span title="<strong class=help-title>Tablas de símbolos:</strong><br/>Estructuras  que referencian los datos que son creados dinámicamente durante la ejecución del código fuente. Se presenta tablas de símbolos independientes para variables, funciones y clases." class="help"><i class="fa fa-question-circle"></i></span>
       </p>
       <a href="#" id="symbols-vars-tab" class="tab tab-active" onclick="selectTableSimbols(symbols.omi && symbols.omi.tables.vars, 'vars','vars', null, symbols.omi && symbols.omi.tables.vars.current_level); fixed_select = select_symbols;return false;">Vars</a>
       <a href="#" id="symbols-funcs-tab" class="tab" onclick="selectTableSimbols(symbols.omi && symbols.omi.tables.funcs, 'funcs'); fixed_select = select_symbols; return false;">Functions</a>
       <a href="#" id="symbols-class-tab" class="tab" onclick="selectTableSimbols(symbols.omi &&  symbols.omi.tables.class, 'class'); fixed_select = select_symbols; return false;">Class</a>
    </div>
    <div id="symbols-container">
      <canvas id="symbols-drawing" width="" height="" 
      style="position: absolute; left: 20; top: 20; z-index: 0;"></canvas>
      <canvas id="symbols-info" width="" height="" 
      style="position: absolute; left: 20; top: 20; z-index: 1;"></canvas>
      
    </div>
    <div style="right: 15px;" id="symbols-menu" onclick="return false;">
      <div id="symbols-menu-items"></div>
   </div>
    <div id="symbols-controls">
      <button title="Ver clase padre" style="display:none" id="symbols-parent" onclick="printParent();return false;"><span id="symbols-parent-title">Parent</span></button>
      <button title="Niveles de la tabla de símbolos" id="symbols-navegate" onclick="printSelectSimbols();return false;"><i class="fa fa-table"></i> <span id="symbols-navegate-title">Vars</span></button>
    </div>
    <button title="Navegación automática [<span style=color:green;>SÍ</span>]" class="symbols-lock" onclick="return false;"><i class="fa fa-unlock"></i></button>
    <button title="Navegación automática [<span style=color:red;>NO</span>]" style="display:none;" onclick="return false;" class="symbols-lock" ><i class="fa fa-lock"></i>
</button>
   </div>
   <div id="inout">
    <div class="buttons">
      <p id="inout-title" class="title">
         SOURCE
      </p>
      <a href="#" id="tab-src" class="tab tab-inout tab-active" onclick="activeSrc();return false;">Src</a>
       <a href="#" id="tab-out" class="tab tab-inout" onclick="activeIO();return false;">In/Out</a>
    </div>
    <div id="source-01" class="source">
      <textarea id="code" name="code"></textarea>
      <button id="source-send" title="Enviar código fuente (Shift+Enter)" onclick="send();$('#tab-out').click();output_clear();return false;" ><i class="fa fa-paper-plane"></i> Enviar </button>
    </div>
    <div id="output-01" class="output-container" style="display:none;">
      <div id="output-terminal-01" class="output"  ></div>
      <button id="source-out-clean" title="Limpiar terminal (Ctrl+L)" onclick="if(confirm('¿Realmente desea limpiar la salida?')) output_clear();return false;" ><i class="fa fa-trash-o"></i> Limpiar </button>
    </div>
    
   </div>
   <div id="console_omi">
      <div id="console-help">
         <span title="<strong class=help-title>Consola:</strong><br/>Muestra información sobre el proceso de ejecución y los nodos seleccionados." class="help" style="margin-left: 7px;"><i class="fa fa-question-circle"></i></span>
      </div>
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
            <a href="#" id="control-play" title="Ejecución automática (F5)" class="disable button" onclick="if (!$(this).hasClass('disable')) tree.run_play();return false;"><i class="fa fa-play"></i></a>
            <a href="#" id="control-reset" title="Repetir ejecución" class="button" onclick="if (!$(this).hasClass('disable')) resetStep();return false;" style="display:none;" ><i class="fa fa-repeat"></i></a>
            <a href="#" id="control-pause" title="Pausar ejecución automática (F5)" class="disable button" onclick="if (!$(this).hasClass('disable')) tree.stop_play();return false;" style="display:none;" ><i class="fa fa-pause"></i></a>
            <a href="#" id="control-step" title="Siguiente paso (F6)" class="disable button" onclick="if (!$(this).hasClass('disable')) tree.run_next();return false;"><i class="fa fa-step-forward"></i></a>
            <a href="#" id="control-stmt" title="Siguiente sentencia (F7)" class="disable button" onclick="if (!$(this).hasClass('disable')) tree.run_next_stmt(); return false;"  ><i class="fa fa-fast-forward"></i></a>
            <a href="#" id="control-file" title="Abrir fichero (Ctrl+O)" class="button" style="font-size: 22px;padding: 7px 7px;" ><i class="fa fa-file-code-o"></i></a>
            <a href="#" id="control-save" title="Guardar fichero (Ctrl+S)" download="src.omi" class="button" style="font-size: 22px;padding: 7px 7px;" ><i class="fa fa-floppy-o"></i></a>
         </div>
      </div>
   </div>
   <input type="file" id="fileinput" style="display:none;"/>
<!--
   </form>
-->
</div>
<!--
<input type="button" value="Next" >
      <input type="button" value="Send" onclick="send();">
-->
<div id="footer">
   GPLv3
</div>

<script src="//code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.tree.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.node.js"></script>

<script type="text/javascript" src="<?=URL;?>src/js/omi.config.js"></script>

<script type="text/javascript" src="<?=URL;?>src/js/omi.extend.js"></script>

<script type="text/javascript" src="<?=URL;?>src/js/omi.symbols.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.ref.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.console.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.clone.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/omi.run.js"></script>
<script type="text/javascript" src="<?=URL;?>src/vendor/codemirror/lib/codemirror.js"></script>
<script type="text/javascript" src="<?=URL;?>src/vendor/codemirror/mode/clike/clike.js"></script>
<script type="text/javascript" src="<?=URL;?>src/vendor/shortcut/shortcut.js"></script>
<script type="text/javascript" src="<?=URL;?>src/vendor/FileSaver/FileSaver.min.js"></script>
<script type="text/javascript" src="<?=URL;?>src/js/interface.js"></script>


 <script>
   clearInterface();
   console_omi.iDefault ();
   editor.focus();
   shortcut.add("F5",function() {
      if (tree.play){
         if (!$("#control-pause").hasClass('disable')) tree.stop_play();
      }else{
         if (!$("#control-play").hasClass('disable')) tree.run_play();
      }
   });
   shortcut.add("F6",function() {
      if (!$("#control-step").hasClass('disable')) tree.run_next();
   });
   shortcut.add("F7",function() {
      if (!$("#control-step").hasClass('disable')) tree.run_next_stmt();
   });
   shortcut.add("Shift+Enter",function() {
      send();
   });
   shortcut.add("Ctrl+O",function() {
      e.preventDefault();
   $("#fileinput").trigger('click');
   });
   shortcut.add("Ctrl+L",function() {
      if ($("#tab-out:visible").length) {
         $("#source-out-clean").click();
      }
   });
   shortcut.add("Ctrl+S",function() {
      $("#control-save").click();
   });
   $("#tab-src").click();
   $(document).tooltip({
       content: function () {
           return $(this).prop('title');
       }
   });

</script>
</body>
</html>




