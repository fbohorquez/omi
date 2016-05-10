var editor = CodeMirror.fromTextArea(document.getElementById("code"), {
   lineNumbers: true,
   matchBrackets: true,
   mode: "text/x-omi",
});

var editor_height = editor.getScrollInfo().height;
var select_symbols = [];
var select_automatic = true;
var fixed_select = null;

editor.on("scroll", function () {
   (editor.getScrollInfo().height == editor_height) 
      && $("#source-send").css('right', '10px') 
      || $("#source-send").css('right', '20px');
});

$("#symbols-drawing")[0].width = $("#symbols-container").width();
$("#symbols-info")[0].width = $("#symbols-container").width();
$("#tree-drawing")[0].width = $("#tree").width();
$("#info-drawing")[0].width = $("#tree").width();
$("#info-drawing")[0].width = $("#tree").width();
$("#console_omi-graph-drawing")[0].width = $("#console_omi-graph").width() - 15;
editor.focus();

function output (str) {
   $("#output-terminal-01").html($("#output-terminal-01").html() + str);
   var div= document.getElementById('output-terminal-01');
   var hasVerticalScrollbar= div.scrollHeight>div.clientHeight
   $("#source-out-clean").css('right', (hasVerticalScrollbar)?27:15);
   $('#output-terminal-01').scrollTop($('#output-terminal-01')[0].scrollHeight);
}

function output_clear () {
   $("#output-terminal-01").html("");
   var div= document.getElementById('output-terminal-01');
   var hasVerticalScrollbar= div.scrollHeight>div.clientHeight
   $("#source-out-clean").css('right', (hasVerticalScrollbar)?27:15);
}

function input (cb) {
   var str = "";
   var limit = 0;
   function keyDownTextField(e) {
      if ($("#tab-out").hasClass('tab-active')){
         var keyCode = e.keyCode;
         if(!e.shiftKey && keyCode >= 65 && keyCode <= 90){
            keyCode += 32;
         }
         if(keyCode==13) {
            document.removeEventListener("keydown", keyDownTextField);
            $("#output-terminal-01").html($("#output-terminal-01").html() + "<br/>");
            cb (str);
         }else if(keyCode == 8) {
            if (limit > 0){
               str = str.slice(0, -1);
               $("#output-terminal-01").html($("#output-terminal-01").html().slice(0,-1));
            }
         } else {
            str += String.fromCharCode(keyCode);
            $("#output-terminal-01").html($("#output-terminal-01").html() + String.fromCharCode(keyCode));
            limit ++;
         }
      }
   }
   document.addEventListener("keydown", keyDownTextField, false);
}

function selectTableSimbols (table, key, name, noselect, level) {
   
   if (table){
      level = (level != undefined)?level:table.current_level;
      table.current_level = level;
   }else if (select_symbols.length){
      table = select_symbols[0].table;
      name = select_symbols[0].name;
      key = select_symbols[0].name;
      level = select_symbols[0].level;
   }
   if (table) table.draw();
   $("#symbols .tab").removeClass ('tab-active');
   switch (key) {
      case 'Vars': 
      case 'vars': 
         $("#symbols-vars-tab").addClass ('tab-active');
         name = 'Vars';
      break;
      case 'Functions': 
      case 'Funcs': 
      case 'funcs': 
         $("#symbols-funcs-tab").addClass ('tab-active');
         name = 'Functions';
      break;
      case 'Class': 
      case 'class': 
         $("#symbols-class-tab").addClass ('tab-active');
         name = 'Class';
      break;
   }
   if (!noselect)
      select_symbols = [{'name': name, 'table' : table, 'level' : level}];
   $("#symbols-navegate-title").html(name + ((level)?' (level:' + level +')':''));
   $('#symbols-menu').hide();
   if (symbols.omi)
      symbols.omi.table_use = table;
}

function printSelectSimbols () {
   if ($('#symbols-menu:visible').length == 0){
      var str = "";
      for (i = 0, n = select_symbols.length; i < n; ++i){
         for (var j = select_symbols[i].table.refs.length - 1; j >= 0; --j){ 
            str += '<p class="symbols-menu-item" ><a href="#" onclick="selectSymbol(\'' + select_symbols[i].name + '\', ' + j + ', \'' + select_symbols[i].same + '\' );return false;" >' + select_symbols[i].name + ((j != 0)?' (level: ' + j + ')':'') + '</a></p>';
         }
      }
      $("#symbols-menu-items").html(str);
      $('#symbols-menu').show();
   }else{
      $('#symbols-menu').hide();
   }
}

function selectSymbol (key, level, same) {
   i = 0;
   while (select_symbols.length){
      if (select_symbols[i].name == key && select_symbols[i].table) {
         selectTableSimbols(select_symbols[i].table, select_symbols[i].name, select_symbols[i].name, true, level);
         break;
      }
      else {
         if (same != select_symbols[i].same)
            select_symbols.shift();
         else
            i = 1;
      }
   }
   if (tree.omi.select_node) tree.omi.select_node.click();
   if (select_symbols[0] && select_symbols[0].same){
      if (idMap[select_symbols[0].same] && idMap[select_symbols[0].same].extends){
         $("#symbols-parent").attr('rel', idMap[select_symbols[0].same].extends.id);
         $("#symbols-parent").show ();
      }else {
         $("#symbols-parent").hide ();
      }
   }else {
      $("#symbols-parent").hide ();
   }
   //~ $("#symbols-navegate-title").html(key);
   $('#symbols-menu').hide();
   fixed_select = select_symbols;
}

function printParent () {
   if (rel = $("#symbols-parent").attr('rel')) {
      if (idMap [rel]){
         a = select_symbols.slice ();
         idMap [rel].click();
         select_symbols.unshift ({'name' : idMap [rel].vars.id, 'table' : idMap [rel].vars, 'level': 0, 'same' : idMap [rel].id});
         select_symbols = select_symbols.concat (a);
      }
   }
}

function clearInterface ()  {
   $('#symbols-menu').hide();
   selectTableSimbols (null, 'vars');
   if (console_omi.omi) console_omi.omi.clear();
}

function isNodeClick (node) {
   if (node) {
      document.body.style.cursor = 'pointer';
   }
   else {
      document.body.style.cursor = 'default';
   }
}

function offStep (){
   tree.stop_play ();
   $("#control-play").addClass('disable');
   $("#control-pause").addClass('disable');
   $("#control-step").addClass('disable');
   $("#control-stmt").addClass('disable');
}

function onStep (){
   $("#control-play").show();
   $("#control-reset").hide();
   $("#control-pause").hide();
   $("#control-play").removeClass('disable');
   $("#control-pause").removeClass('disable');
   $("#control-step").removeClass('disable');
   $("#control-stmt").removeClass('disable');
}

function endStep (){
   tree.stop_play ();
   $("#control-reset").show();
   $("#control-play").hide();
   $("#control-pause").hide();
   $("#control-reset").removeClass('disable');
   $("#control-step").addClass('disable');
   $("#control-stmt").addClass('disable');
}

function resetStep (){
   $("#control-reset").hide();
   $("#control-play").show();
   $("#control-pause").hide();
   output_clear();
   send();
}

function activeSrc() {
   $('#output-01').hide();
   $('#source-01').show();
   $('.tab-inout').removeClass('tab-active');
   $("#tab-src").addClass('tab-active');
   $('#inout-title').html('Source<span title=\"<strong class=help-title>Código fuente:</strong><br/> Escriba el código OMI que desee y envíelo para su interpretación paso por paso. Podrá analizar de forma interactiva cómo se lleva a cabo el procesamiento y la ejecución semántica de la pieza de código.\" class=\"help\"><i class=\"fa fa-question-circle\"></i></span>');
}

function activeIO() {
   $('#source-01').hide();
   $('#output-01').show();
   $('.tab-inout').removeClass('tab-active');
   $("#tab-out").addClass('tab-active');
   $('#inout-title').html('Input/Output<span title=\"<strong class=help-title>Terminal de entrada/salida:</strong><br/> Podrá consultar el resultado producido por el programa mientras es interpretado. También intrducir los datos solicitados por el mismo cuando sea necesario.\" class=\"help\"><i class=\"fa fa-question-circle\"></i></span>');
}

function readSingleFile(evt) {
 //Retrieve the first (and only!) File from the FileList object
 
}
  
$("#control-file").click(function(e){
   e.preventDefault();
   $("#fileinput").trigger('click');
});

$("#fileinput").change(function(evt) {
   var f = evt.target.files[0]; 
   if (f) {
   var r = new FileReader();
   r.onload = function(e) { 
      var contents = e.target.result;
      editor.setValue(contents);  
   }
   r.readAsText(f);
   } else { 
      alert("Failed to load file");
   }
});

$("#control-save").click( function () {
   var blob = new Blob([editor.getValue()], {type: "text/omi;charset=utf-8"});
   saveAs(blob, "src.omi");
});

$(".symbols-lock").click (function () {
      $(".symbols-lock").toggle();
      select_automatic = !select_automatic;
      if (!select_automatic) 
         fixed_select = select_symbols;
});


      
