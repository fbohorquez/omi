<style>
.requisite  dl {
  width: 100%;
  overflow: hidden;
  padding: 0;
  margin: 0
}
.requisite  dt {
  float: left;
  width: 100px;
  padding: 0;
  margin: 0
}
.requisite dd {
  float: left;
  width: calc(100% - 100px);
  padding: 0;
  margin: 0
}
.requisite {
   border: 1px solid #AAA;
   padding: 10px;
}
.title h1 {
   font-size:28px;
}
</style>
<div id="content-doc">
<div id="index">
   <div class="title"><h1>Análisis del sistema</h1></div>
   <div class="list">

<UL CLASS="TofC">
<LI><A NAME="tex2html210"
  HREF="head.html#SECTION00020000000000000000">Modelo conceptual</A>
<UL>
<LI><A NAME="tex2html211"
  HREF="<?= URL;?>/doc/analisis#SECTION00021000000000000000">Intérprete</A>
<LI><A NAME="tex2html212"
  HREF="<?= URL;?>/doc/analisis#SECTION00022000000000000000">Nodos ejecutables</A>
<LI><A NAME="tex2html213"
  HREF="<?= URL;?>/doc/analisis#SECTION00023000000000000000">Tipos de datos</A>
<LI><A NAME="tex2html214"
  HREF="<?= URL;?>/doc/analisis#SECTION00024000000000000000">Sentencias de control de flujo</A>
<LI><A NAME="tex2html215"
  HREF="<?= URL;?>/doc/analisis#SECTION00025000000000000000">Definiciones</A>
<LI><A NAME="tex2html216"
  HREF="<?= URL;?>/doc/analisis#SECTION00026000000000000000">Asignaciones</A>
<LI><A NAME="tex2html217"
  HREF="<?= URL;?>/doc/analisis#SECTION00027000000000000000">Operadores aritméticos</A>
<LI><A NAME="tex2html218"
  HREF="<?= URL;?>/doc/analisis#SECTION00028000000000000000">Operadores lógicos</A>
<LI><A NAME="tex2html219"
  HREF="<?= URL;?>/doc/analisis#SECTION00029000000000000000">Operadores sobre cadenas</A>
<LI><A NAME="tex2html220"
  HREF="<?= URL;?>/doc/analisis#SECTION000210000000000000000">Operadores sobre array</A>
<LI><A NAME="tex2html221"
  HREF="<?= URL;?>/doc/analisis#SECTION000211000000000000000">Operadores sobre expresiones regulares</A>
<LI><A NAME="tex2html222"
  HREF="<?= URL;?>/doc/analisis#SECTION000212000000000000000">Conversión de tipos</A>
<LI><A NAME="tex2html223"
  HREF="<?= URL;?>/doc/analisis#SECTION000213000000000000000">Operadores de acceso</A>
<LI><A NAME="tex2html224"
  HREF="<?= URL;?>/doc/analisis#SECTION000214000000000000000">Operadores condicionales</A>
<LI><A NAME="tex2html225"
  HREF="<?= URL;?>/doc/analisis#SECTION000215000000000000000">Operadores de entrada/salida</A>
<LI><A NAME="tex2html226"
  HREF="<?= URL;?>/doc/analisis#SECTION000216000000000000000">Operadores informativos</A>
<LI><A NAME="tex2html227"
  HREF="<?= URL;?>/doc/analisis#SECTION000217000000000000000">Procesos</A>
<LI><A NAME="tex2html228"
  HREF="<?= URL;?>/doc/analisis#SECTION000218000000000000000">Ficheros</A>
<LI><A NAME="tex2html229"
  HREF="<?= URL;?>/doc/analisis#SECTION000219000000000000000">Fechas</A>
<LI><A NAME="tex2html230"
  HREF="<?= URL;?>/doc/analisis#SECTION000220000000000000000">Errores</A>
<LI><A NAME="tex2html231"
  HREF="<?= URL;?>/doc/analisis#SECTION000221000000000000000">Extensiones</A>
<LI><A NAME="tex2html232"
  HREF="<?= URL;?>/doc/analisis#SECTION000222000000000000000">rTree</A>
</UL>
<BR>
<LI><A NAME="tex2html233"
  HREF="<?= URL;?>/doc/analisis#SECTION00030000000000000000">Modelo de casos de uso</A>
<UL>
<LI><A NAME="tex2html234"
  HREF="<?= URL;?>/doc/analisis#SECTION00031000000000000000">Actores</A>
<LI><A NAME="tex2html235"
  HREF="<?= URL;?>/doc/analisis#SECTION00032000000000000000">Intérprete</A>
<LI><A NAME="tex2html236"
  HREF="<?= URL;?>/doc/analisis#SECTION00033000000000000000">runTree</A>
</UL>
<BR>
<LI><A NAME="tex2html237"
  HREF="<?= URL;?>/doc/analisis#SECTION00040000000000000000">Visión general</A>
<LI><A NAME="tex2html238"
  HREF="<?= URL;?>/doc/analisis#SECTION00050000000000000000">Diagramas de secuencia del sistema</A>
<UL>
<LI><A NAME="tex2html239"
  HREF="<?= URL;?>/doc/analisis#SECTION00051000000000000000">Intérprete</A>
<LI><A NAME="tex2html240"
  HREF="<?= URL;?>/doc/analisis#SECTION00052000000000000000">runTree</A>
</UL>
<BR>
<LI><A NAME="tex2html241"
  HREF="<?= URL;?>/doc/analisis#SECTION00060000000000000000">Contratos de operaciones del sistema</A>
<UL>
<LI><A NAME="tex2html242"
  HREF="<?= URL;?>/doc/analisis#SECTION00061000000000000000">Intérprete</A>
<LI><A NAME="tex2html243"
  HREF="<?= URL;?>/doc/analisis#SECTION00062000000000000000">runTree</A>
</UL>
<BR>
<LI><A NAME="tex2html244"
  HREF="<?= URL;?>/doc/analisis#SECTION00070000000000000000">Modelo de interfaz de usuario</A>
<UL>
<LI><A NAME="tex2html245"
  HREF="<?= URL;?>/doc/analisis#SECTION00071000000000000000">Intérprete</A>
<LI><A NAME="tex2html246"
  HREF="<?= URL;?>/doc/analisis#SECTION00072000000000000000">runTree</A>
<LI><A NAME="tex2html247"
  HREF="<?= URL;?>/doc/analisis#SECTION00073000000000000000">Sitio web</A>
</UL></UL>

   </div>
<!--
</div>
-->
   <div class="clear"></div>
</div>
<div id="container-doc">
   <div id="container">
      <div class="border">
      <div class="border-2">
         <div id="content">
            <div class="row"><H1><A NAME="SECTION00020000000000000000">
Modelo conceptual</A>
</H1>
El presente documento representa un análisis de los datos que construyen
el sistema OMI y cómo estos se relacionan. El documento describe el 
modelo conceptual de datos del sistema mediante diagramas de clases. Las 
clases son organizadas en paquetes para facilitar la modularidad del sistema
y su entendimiento. 

<P>
El proceso de interpretar consiste en tomar código fuente, procesarlo y ejecutar 
su significado semántico. Por tanto el modelo de datos estará constituido por
entidades que guardan un significado concreto y preciso dentro del lenguaje.
Estos elementos, que representan la unidad semántica mínima, 
son denominados nodos ejecutables, debido a que cuando 
son ejecutados producen el resultado semántico asociado.  Muchos nodos ejecutables
por si solos no presentan un resultado semántico completo, por lo que precisan de otros
nodos. 

<P>
El diagrama general de paquetes describe los paquetes que componen el 
sistema según el carácter funcional de las entidades que contienen. Un 
paquete podrá contener clases u otros paquetes.

<P>
El paquete ``interpreter'' describe las entidades que procesan  
el contenido fuente según el léxico y la gramática del lenguaje OMI. 
El objetivo es generar el árbol de nodos ejecutables correspondiente al
programa. Al procesarse este árbol se aplicará la semántica que encierran 
las líneas de código del contenido fuente, produciéndose de esta forma la ejecución del programa.

<P>
El paquete ``runNode'' describe el nodo ejecutable y aquellos tipos de nodos derivados
de este, que son abstractos y que serán extendidos por tipos más específicos.

<P>
El paquete ``typeData'' describe los nodos correspondientes a los tipos de datos básicos 
que pueden ser manipulados por el sistema. 

<P>
El paquete ``error'' describe el sistema de errores y los nodos ejecutables que permiten
su control.

<P>
El paquete ``extensions'' describe el sistema de extensiones del interprete, el cual
permite extender la funcionalidades del lenguaje de una forma dinámica. Además contiene dos
el modelado de dos extensiones concretas.  

<P>
Los paquetes siguientes categorizan y agrupan nodos ejecutables según la funcionalidad 
que encierran y el tipo de dato sobre el que operan. 

<P>
El último paquete ``rtree'' describe el modelo de datos correspondiente al sistema 
software cliente. Una aplicación web que hace uso del interprete de forma online
y representa el estado de este.

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="227" HEIGHT="755" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/package-omi.png"
 ALT="Image package-omi"> 
<BR>
</DIV>
<H2><A NAME="SECTION00021000000000000000">
Intérprete</A>
</H2>
El sistema OMI se corresponde con un interprete que opera sobre 
un contenido fuente escrito en el lenguaje con el mismo nombre. 
El interprete se compone de un analizador sintáctico que encierra la 
gramática del lenguaje, esta es descrita a partir de una serie de tokens.

<P>
El analizador sintáctico se vale de un analizador léxico que validará 
y obtendrá los tokens (bajo petición) desde el código fuente.
El analizador léxico debe controlar el fichero que contiene el código fuente, 
así como la línea y posición que se encuentra procesando en el mismo.

<P>
Los tokens obtenidos se definen por un identificador y la línea del código fuente en la que se generó,
además pueden tener asociado un valor que puede ser numérico o cadena. Serán utilizados 
por el analizador sintáctico para determinar las reglas gramaticales que se deben aplicar y
construir el árbol sintáctico correspondiente. Este árbol está formado 
por nodos denominados ejecutables, dado que al ser procesados en profundidad se llevará 
a cabo la ejecución del programa. Los nodos ejecutables dan singnificado semántico a 
cada una de las sentencias que componen el contenido fuente.

<P>
El interprete se compone además de un contexto denominado principal, que será sobre el que 
opere de forma predeterminada. Un contexto está formado por una serie de tablas de símbolos 
que serán manipuladas por ciertos nodos ejecutables cuando sean procesados. Estas tablas guardan 
referencias a nodos ejecutables correspondientes a símbolos variables, funciones y clases de objetos 
que son definidos en el código fuente. Existen determinados nodos que al ser ejecutados pueden 
cambiar el contexto en uso.

<P>
El interprete es ejecutado con una serie de argumentos que alteran su funcionamiento.

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="498" HEIGHT="177" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/interpreter.png"
 ALT="Image interpreter"> 
<BR>
</DIV>
<H2><A NAME="SECTION00022000000000000000">
Nodos ejecutables</A>
</H2>
Se definen un nodo ejecutable para cada aspecto o funcionalidad que contemple el lenguaje.
Cada sentencia se corresponde con un nodo ejecutable, que a su vez puede estar compuestos de otros
nodos. Cada nodo ejecutable guarda el número de nodos que lo referencian para que se pueda hacer un uso 
óptimo del mismo.

<P>
Las expresiones son nodos ejecutables que tomarán un valor tras ser procesados. Generalmente forman parte de otros 
nodos correspondientes a sentencias u otras expresiones. El valor que toman pueden ser de un tipo determinado y conocido (numérico, lógico, etc), 
o de tipo indeterminado o no conocido hasta que el nodo es procesado. 

<P>
Las expresiones de tipo determinado son extendidas por cada tipo de dato soportado por el lenguaje. Además 
pueden ser consideradas tipos de objetos y estar así asociadas a una clase. De esta forma toda expresión puede disponer
de métodos y atributos según el tipo de dato que guarde.

<P>
Las expresiones de tipo indeterminado se componen de una referencia al nodo que guarda el valor tras la ejecución, este podrá ser una 
expresión de tipo determinado.

<P>
Las expresiones son nodos imprimibles lo que significa que tienen una representación gráfica asociada que puede ser volcada en la
salida estándar.

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="416" HEIGHT="308" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/runNode.png"
 ALT="Image runNode"> 
<BR>
</DIV>
<H2><A NAME="SECTION00023000000000000000">
Tipos de datos</A>
</H2>
Este paquete contiene los nodos que representan expresiones con tipos de datos definidos.
Se describe cada tipo de dato como un nodo con un valor asociado (en algunos casos el tipo puede comprender un único valor).

<P>
Muchos nodos son especializaciones de tipos de datos, correspondiéndose con expresiones que 
guardan un valor del tipo de dato al que extienden. Así por ejemplo los nodos de operaciones aritméticas
generalmente extenderán al nodo del mismo tipo de dato. 

<P>
Algunos nodos de tipos datos son concretados por nodos que representan un valor constante de dicho tipo de dato.

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="410" HEIGHT="319" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/typeData.png"
 ALT="Image typeData"> 
<BR>
</DIV>
<H2><A NAME="SECTION00024000000000000000">
Sentencias de control de flujo</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="312" HEIGHT="320" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/flowstmts.png"
 ALT="Image flowstmts"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024100000000000000">
Sentencia</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="126" HEIGHT="59" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/stmt.png"
 ALT="Image stmt"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024200000000000000">
Sentencia vacía</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="83" HEIGHT="71" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/emptyStmt.png"
 ALT="Image emptyStmt"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024300000000000000">
include</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="84" HEIGHT="70" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/include.png"
 ALT="Image include"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024400000000000000">
exit</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="71" HEIGHT="63" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/exit.png"
 ALT="Image exit"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024500000000000000">
goto</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="65" HEIGHT="56" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/goto.png"
 ALT="Image goto"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024600000000000000">
if</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="131" HEIGHT="76" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/if.png"
 ALT="Image if"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024700000000000000">
switch</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="176" HEIGHT="104" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/switch.png"
 ALT="Image switch"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024800000000000000">
while</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="130" HEIGHT="76" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/while.png"
 ALT="Image while"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00024900000000000000">
do...while</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="143" HEIGHT="76" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/dowhile.png"
 ALT="Image dowhile"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000241000000000000000">
for</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="146" HEIGHT="89" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/for.png"
 ALT="Image for"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000241100000000000000">
foreach</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="141" HEIGHT="84" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/foreach.png"
 ALT="Image foreach"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000241200000000000000">
iloop</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="143" HEIGHT="102" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/iloop.png"
 ALT="Image iloop"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000241300000000000000">
continue</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="137" HEIGHT="75" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/continue.png"
 ALT="Image continue"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000241400000000000000">
break</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="144" HEIGHT="104" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/break.png"
 ALT="Image break"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000241500000000000000">
try</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="142" HEIGHT="74" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/try.png"
 ALT="Image try"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000241600000000000000">
throw</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="142" HEIGHT="70" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/throw.png"
 ALT="Image throw"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000241700000000000000">
with</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="134" HEIGHT="64" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/with.png"
 ALT="Image with"> 
<BR>
</DIV>
<H2><A NAME="SECTION00025000000000000000">
Definiciones</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="147" HEIGHT="239" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/definitions.png"
 ALT="Image definitions"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025100000000000000">
Variables</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="222" HEIGHT="203" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/id.png"
 ALT="Image id"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025200000000000000">
Funciones</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="525" HEIGHT="213" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/functions.png"
 ALT="Image functions"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025300000000000000">
Clases</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="567" HEIGHT="369" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/class.png"
 ALT="Image class"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025400000000000000">
Objetos</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="326" HEIGHT="270" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/object.png"
 ALT="Image object"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025500000000000000">
Listas</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="142" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/list.png"
 ALT="Image list"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025600000000000000">
Pares clave/valor</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="114" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/map.png"
 ALT="Image map"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025700000000000000">
Etiquetas</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="114" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/label.png"
 ALT="Image label"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025800000000000000">
Definiciones globales</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="142" HEIGHT="114" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/global.png"
 ALT="Image global"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00025900000000000000">
Generadores</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="312" HEIGHT="312" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/generator.png"
 ALT="Image generator"> 
<BR>
</DIV>
<H2><A NAME="SECTION00026000000000000000">
Asignaciones</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="74" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/assig-package.png"
 ALT="Image assig-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00026100000000000000">
Asignación</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="199" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/assigNode.png"
 ALT="Image assigNode"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00026200000000000000">
Asignación de referencia</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="199" HEIGHT="213" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/assigRef.png"
 ALT="Image assigRef"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION00027000000000000000">
Operadores aritméticos</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="396" HEIGHT="153" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/arithOp-package.png"
 ALT="Image arithOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027100000000000000">
Suma</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/add.png"
 ALT="Image add"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027200000000000000">
Diferencia</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/sub.png"
 ALT="Image sub"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027300000000000000">
Producto</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/prod.png"
 ALT="Image prod"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027400000000000000">
División</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/div.png"
 ALT="Image div"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027500000000000000">
Potencia</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/pow.png"
 ALT="Image pow"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027600000000000000">
Módulo</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/mod.png"
 ALT="Image mod"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027700000000000000">
Tamaño</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/size.png"
 ALT="Image size"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027800000000000000">
Incremento y asignación</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="185" HEIGHT="256" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/incAssig.png"
 ALT="Image incAssig"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00027900000000000000">
Asignación e incremento</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="185" HEIGHT="256" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/assigInc.png"
 ALT="Image assigInc"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000271000000000000000">
Decremento y asignación</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="185" HEIGHT="256" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/decAssig.png"
 ALT="Image decAssig"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000271100000000000000">
Asignación y decremento</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="185" HEIGHT="256" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/assigDec.png"
 ALT="Image assigDec"> 
<BR>
</DIV>
<H2><A NAME="SECTION00028000000000000000">
Operadores lógicos</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="340" HEIGHT="117" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/logicOp-package.png"
 ALT="Image logicOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028100000000000000">
Or</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/or.png"
 ALT="Image or"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028200000000000000">
And</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/and.png"
 ALT="Image and"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028300000000000000">
Negación</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="128" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/not.png"
 ALT="Image not"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028400000000000000">
Igual que</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/eq.png"
 ALT="Image eq"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028500000000000000">
Distinto que</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/neq.png"
 ALT="Image neq"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028600000000000000">
Menor que</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/lth.png"
 ALT="Image lth"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028700000000000000">
Menor o igual que</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/leq.png"
 ALT="Image leq"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028800000000000000">
Mayor que</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/gth.png"
 ALT="Image gth"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00028900000000000000">
Mayor o igual que</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/geq.png"
 ALT="Image geq"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000281000000000000000">
Idéntico a</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/iden.png"
 ALT="Image iden"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000281100000000000000">
No idéntico a</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="185" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/niden.png"
 ALT="Image niden"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000281200000000000000">
Es nulo</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="185" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/isNull.png"
 ALT="Image isNull"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000281300000000000000">
Vacío</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/empty.png"
 ALT="Image empty"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION00029000000000000000">
Operadores sobre cadenas</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="340" HEIGHT="119" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/stringOp-package.png"
 ALT="Image stringOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029100000000000000">
Concatenación</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/cat.png"
 ALT="Image cat"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029200000000000000">
explode</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/explode.png"
 ALT="Image explode"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029300000000000000">
implode</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/implode.png"
 ALT="Image implode"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029400000000000000">
sprintf</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/sprintf.png"
 ALT="Image sprintf"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029500000000000000">
Buscar subcadena</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="199" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/find.png"
 ALT="Image find"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029600000000000000">
Buscar y remplazar</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="227" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/replace.png"
 ALT="Image replace"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029700000000000000">
Remplazar subcadena</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="241" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/subreplace.png"
 ALT="Image subreplace"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029800000000000000">
Convertir a mayúsculas</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="142" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/upper.png"
 ALT="Image upper"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00029900000000000000">
Convertir a minúsculas</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="142" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/lower.png"
 ALT="Image lower"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION000210000000000000000">
Operadores sobre array</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="176" HEIGHT="67" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/arrayOp-package.png"
 ALT="Image arrayOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210100000000000000">
Dividir en fragmentos</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="256" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/chunk.png"
 ALT="Image chunk"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210200000000000000">
Reducir mediante función</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="256" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/reduce.png"
 ALT="Image reduce"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210300000000000000">
Obtener último</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="109" HEIGHT="93" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/last.png"
 ALT="Image last"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210400000000000000">
Obtener primero</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="109" HEIGHT="93" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/first.png"
 ALT="Image first"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210500000000000000">
Insertar en posición</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="133" HEIGHT="93" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/insert.png"
 ALT="Image insert"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210600000000000000">
Eliminar posición</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="131" HEIGHT="93" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/delete.png"
 ALT="Image delete"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210700000000000000">
Insertar al inicio</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="131" HEIGHT="93" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/unshift.png"
 ALT="Image unshift"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210800000000000000">
Insertar al final</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="131" HEIGHT="93" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/push.png"
 ALT="Image push"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000210900000000000000">
Eliminar del inicio</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="131" HEIGHT="93" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/shift.png"
 ALT="Image shift"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION0002101000000000000000">
Eliminar del final</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="131" HEIGHT="93" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/pop.png"
 ALT="Image pop"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION000211000000000000000">
Operadores sobre expresiones regulares</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="226" HEIGHT="70" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/regexpOp-package.png"
 ALT="Image regexpOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000211100000000000000">
Crear expresión regular</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="199" HEIGHT="213" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/newRegExp.png"
 ALT="Image newRegExp"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000211200000000000000">
match</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="199" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/match.png"
 ALT="Image match"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000211300000000000000">
search</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="227" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/search.png"
 ALT="Image search"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION000212000000000000000">
Conversión de tipos</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="160" HEIGHT="113" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/convOp-package.png"
 ALT="Image convOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000212100000000000000">
Conversión a lógico</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="91" HEIGHT="86" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/boolconv.png"
 ALT="Image boolconv"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000212200000000000000">
Conversión a entero</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="91" HEIGHT="86" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/intconv.png"
 ALT="Image intconv"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000212300000000000000">
Conversión a flotante</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="91" HEIGHT="86" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/floatconv.png"
 ALT="Image floatconv"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000212400000000000000">
Conversión a cadena</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="91" HEIGHT="86" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/strconv.png"
 ALT="Image strconv"> 
<BR>
</DIV>
<P>

<H2><A NAME="SECTION000213000000000000000">
Operadores de acceso</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="202" HEIGHT="71" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/accessOp-package.png"
 ALT="Image accessOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000213100000000000000">
Acceso a clave</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="168" HEIGHT="166" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/get.png"
 ALT="Image get"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000213200000000000000">
Acceso a función</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/getFunc.png"
 ALT="Image getFunc"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000213300000000000000">
Acceso a variable de entorno</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/getEnvSys.png"
 ALT="Image getEnvSys"> 
<BR>
</DIV>
<P>

<H2><A NAME="SECTION000214000000000000000">
Operadores condicionales</A>
</H2> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="168" HEIGHT="70" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/condOp-package.png"
 ALT="Image condOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000214100000000000000">
Ternario</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="185" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/tern.png"
 ALT="Image tern"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000214200000000000000">
Fusión de nulos</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="227" HEIGHT="213" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/nullCoalescing.png"
 ALT="Image nullCoalescing"> 
<BR>
</DIV>
<P>

<H2><A NAME="SECTION000215000000000000000">
Operadores de entrada/salida</A>
</H2> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="133" HEIGHT="70" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/ioOp-package.png"
 ALT="Image ioOp-package"> 
<BR>
</DIV>
<H3><A NAME="SECTION000215100000000000000">
Salida estándar</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="142" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/output.png"
 ALT="Image output"> 
<BR>
</DIV>
<H3><A NAME="SECTION000215200000000000000">
Entrada estándar</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="213" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/input.png"
 ALT="Image input"> 
<BR>
</DIV>
<H2><A NAME="SECTION000216000000000000000">
Operadores informativos</A>
</H2> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="203" HEIGHT="70" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/infoOp-package.png"
 ALT="Image infoOp-package"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000216100000000000000">
Tipo de</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="128" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/typeOf.png"
 ALT="Image typeOf"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000216200000000000000">
Tamaño de</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/sizeOf.png"
 ALT="Image sizeOf"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000216300000000000000">
Información sobre</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="128" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/datInfo.png"
 ALT="Image datInfo"> 
<BR>
</DIV>
<P>

<H2><A NAME="SECTION000217000000000000000">
Procesos</A>
</H2> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="252" HEIGHT="154" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/processOp-package.png"
 ALT="Image processOp-package"> 
<BR>
</DIV>

<P>
   
<H3><A NAME="SECTION000217100000000000000">
Crear proceso</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="128" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fork.png"
 ALT="Image fork"> 
<BR>   
</DIV>

<H3><A NAME="SECTION000217200000000000000">
Esperar finalización</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="142" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/wait.png"
 ALT="Image wait"> 
<BR>   
</DIV>

<P>
   
<H3><A NAME="SECTION000217300000000000000">
Obtener identificador </A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="100" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/getpid.png"
 ALT="Image getpid"> 
<BR>   
</DIV>

<H3><A NAME="SECTION000217400000000000000">
Obtener identificador padre</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="114" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/getppid.png"
 ALT="Image getppid"> 
<BR>   
</DIV>

<P>
   
<H3><A NAME="SECTION000217500000000000000">
Ejecutar como proceso</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="213" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/process.png"
 ALT="Image process"> 
<BR>   
</DIV>

<H3><A NAME="SECTION000217600000000000000">
Salir de proceso</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="156" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/exitProcess.png"
 ALT="Image exitProcess"> 
<BR>   
</DIV>

<P>
   
<H3><A NAME="SECTION000217700000000000000">
Señal a proceso</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="185" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/signal.png"
 ALT="Image signal"> 
<BR>   
</DIV>

<H3><A NAME="SECTION000217800000000000000">
Manejador de señales</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="241" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/signalhandler.png"
 ALT="Image signalhandler"> 
<BR>   
</DIV>

<P>
   
<H3><A NAME="SECTION000217900000000000000">
Evaluar cadena</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/eval.png"
 ALT="Image eval"> 
<BR>   
</DIV>

<H3><A NAME="SECTION0002171000000000000000">
Ejecutar comando del sistema</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/exec.png"
 ALT="Image exec"> 
<BR>   
</DIV>
<P>

<H2><A NAME="SECTION000218000000000000000">
Ficheros</A>
</H2> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="199" HEIGHT="154" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fileOp-package.png"
 ALT="Image fileOp-package"> 
<BR>
</DIV>

<P>
   
<H3><A NAME="SECTION000218100000000000000">
Obtener un flujo a fichero</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/file.png"
 ALT="Image file"> 
<BR>   
</DIV>

<P>

<H3><A NAME="SECTION000218200000000000000">
Escribir en flujo a fichero</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fput.png"
 ALT="Image fput"> 
<BR>   
</DIV>

<P>

<H3><A NAME="SECTION000218300000000000000">
Leer de flujo a fichero</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="170" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fget.png"
 ALT="Image fget"> 
<BR>   
</DIV>

<P>

<H3><A NAME="SECTION000218400000000000000">
Cambiar posición en fichero</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="241" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fseek.png"
 ALT="Image fseek"> 
<BR>   
</DIV>

<H3><A NAME="SECTION000218500000000000000">
Obtener posición en flujo a fichero</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/ftell.png"
 ALT="Image ftell"> 
<BR>   
</DIV>

<P>

<H3><A NAME="SECTION000218600000000000000">
Cerrar flujo a fichero</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fclose.png"
 ALT="Image fclose"> 
<BR>   
</DIV>

<P>

<H3><A NAME="SECTION000218700000000000000">
Leer fichero</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fread.png"
 ALT="Image fread"> 
<BR>   
</DIV>

<P>

<H3><A NAME="SECTION000218800000000000000">
Escribir en fichero</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="199" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fwrite.png"
 ALT="Image fwrite"> 
<BR>   
</DIV>

<P>

<H3><A NAME="SECTION000218900000000000000">
Escribir al final de fichero</A>
</H3> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="199" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/fappend.png"
 ALT="Image fappend"> 
<BR>
</DIV>
<P>

<H2><A NAME="SECTION000219000000000000000">
Fechas</A>
</H2>
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="183" HEIGHT="77" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/dateOp-package.png"
 ALT="Image dateOp-package"> 
<BR>   
</DIV>
<H3><A NAME="SECTION000219100000000000000">
Tiempo Unix</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/time.png"
 ALT="Image time"> 
<BR>   
</DIV>

<H3><A NAME="SECTION000219200000000000000">
Fecha y hora con formato</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/date.png"
 ALT="Image date"> 
<BR>   
</DIV>

<P>

<H3><A NAME="SECTION000219300000000000000">
sleep</A>
</H3> 
   <DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="128" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/sleep.png"
 ALT="Image sleep"> 
<BR>   
</DIV>
<P>

<H2><A NAME="SECTION000220000000000000000">
Errores</A>
</H2> <DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/errorException.png"
 ALT="Image errorException"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION000221000000000000000">
Extensiones</A>
</H2> 
<DIV ALIGN="CENTER">
<IMG
  WIDTH="213" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/extensions-package.png"
 ALT="Image extensions-package"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="284" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/plugins.png"
 ALT="Image plugins"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000221100000000000000">
Biblioteca GNU de internacionalización (gettext)</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="253" HEIGHT="113" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/gettext-ext-package.png"
 ALT="Image gettext-ext-package"> 
<BR>
</DIV>
<H4><A NAME="SECTION000221110000000000000">
gettext</A>
</H4>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="213" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/gettext.png"
 ALT="Image gettext"> 
<BR>
</DIV>

<H4><A NAME="SECTION000221120000000000000">
setlocale</A>
</H4>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="227" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/setlocale.png"
 ALT="Image setlocale"> 
<BR>
</DIV>
<H4><A NAME="SECTION000221130000000000000">
dgettext</A>
</H4>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="213" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/dgettext.png"
 ALT="Image dgettext"> 
<BR>
</DIV>

<H4><A NAME="SECTION000221140000000000000">
bindtextdomain</A>
</H4>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="227" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/bindtextdomain.png"
 ALT="Image bindtextdomain"> 
<BR>
</DIV>
<H4><A NAME="SECTION000221150000000000000">
textdomain</A>
</H4>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="227" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/textdomain.png"
 ALT="Image textdomain"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION000222000000000000000">
rTree</A>
</H2> 
El intérprete OMI tiene la capacidad de generar una salida relativa
a su estado y funcionamiento. Para completar el proyecto se precisa 
de una herramienta capaz de interpretar y representar este estado 
interno de forma gráfica y textual. 

<P>
El modelo de datos del cliente OMI se define de forma similar al intérprete.
La principal diferencia es que en el intérprete este modelo de datos se usa para procesar y 
ejecutar el código fuente, mientras que en el cliente se usa para representar gráficamente 
el proceso llevado a cabo. Es por ello que el modelo de datos del cliente es más abstracto. 

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="267" HEIGHT="216" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/rtree.png"
 ALT="Image rtree"> 
<BR>
</DIV>

<P>

<H1><A NAME="SECTION00030000000000000000">
Modelo de casos de uso</A>
</H1>En esta sección se detallan los casos de usos que recogen los sistemas que conforman el proyecto OMI. 
Un caso de uso describe la secuencia de  interacciones entre el sistema y sus
actores como consecuencia de un evento. 

<P>
En primer lugar se describen los actores que hacen uso del sistema, llegándose a distinguir dos que serán nominados 
usuario y sistema externo. Luego se describen los casos de uso del sistema intérprete y del cliente runTree. 

<P>

<H2><A NAME="SECTION00031000000000000000">
Actores</A>
</H2>
Los actores humanos que interactúan con los sistemas OMI presentan todos un mismo rol. Así el 
único actor definido será llamado usuario.  Los usuarios que hacen uso del intérprete pueden ser desarrolladores,
estudiantes u otros perfiles técnicos, pero todos usarán el sistema de la misma forma.

<P>
Por otro lado el intérprete OMI puede ser usado por otros sistemas, viéndose estos actores de determinados casos
de uso. Algunos sistemas del proyecto OMI hacen uso del intérprete para llevar  a cabo su propósito.

<P>

<H2><A NAME="SECTION00032000000000000000">
Intérprete</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="281" HEIGHT="319" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/use_case_interpreter.png"
 ALT="Image use_case_interpreter"> 
<BR>
</DIV>
<H3><A NAME="SECTION00032100000000000000">
Interpretar entrada estándar</A>
</H3>

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Interpretar entrada estándar.
  
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>General.
  
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario introduce un bloque de código en forma de cadena de 
  caracteres mediante la entrada estándar. El sistema lo interpreta 
  y ejecuta.
  
</DD>
<DT><STRONG>Actores:</STRONG></DT>
<DD>Usuario.
  
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>El sistema debe estar esperando un bloque de código mediante la entrada estándar.
  
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>El código introducido es interpretado y ejecutado.
  
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
  
<OL>
<LI>El usuario inicia el sistema facilitando un listado de argumentos.
</LI>
<LI>El sistema asigna como variables cada argumento y solicita contenido fuente al usuario. 
</LI>
<LI>El usuario introduce un bloque de código en la entrada estándar.
</LI>
<LI>El sistema obtiene el bloque de código a interpretar mediante la entrada estándar.
</LI>
<LI>Incluir (Interpretar). 
  
</LI>
</OL>
</DD>
</DL>
<H3><A NAME="SECTION00032200000000000000">
Interpretar fichero</A>
</H3>

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Interpretar fichero.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>General.
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario indica un fichero que contiene código y que será 
   interpretado y ejecutado por el sistema.
   
</DD>
<DT><STRONG>Actores:</STRONG></DT>
<DD>Usuario.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>El sistema espera que se le indique un fichero.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>El fichero es leído y el código en el mismo es interpretado y ejecutado.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario indica la ruta a un fichero y una serie de argumentos
</LI>
<LI>El sistema lee el fichero y obtiene el código en el mismo, además asigna cada argumento a variables.
</LI>
<LI>Incluir (Interpretar).
   
</LI>
</OL>

<P>
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El fichero indicado no se encuentra.
         
<OL>
<LI>El sistema informa del error y finaliza.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00032300000000000000">
Interpretar línea</A>
</H3>

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Interpretar línea.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>General.
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario introduce bloques de códigos denominados líneas
   de una forma interactiva. El sistema solicita por la entrada 
   estándar las líneas de código, que serán interpretadas y ejecutadas.
   
</DD>
<DT><STRONG>Actores:</STRONG></DT>
<DD>Usuario.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>El sistema se encuentra en modo interactivo.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se interpreta cada línea introducida por el usuario
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario inicia el sistema facilitando un listado de argumentos y la opción de interprete de línea.
</LI>
<LI>El sistema asigna como variables cada argumento y muestra un prompt que indica que espera una línea de código.
</LI>
<LI>El usuario introduce una línea de código.
</LI>
<LI>El sistema lee de la entrada estándar la línea introducida.
</LI>
<LI>Include (Interpretar). 
<BR>
<BR>
El sistema repite el caso de uso hasta que se interpreta una sentencia que produzca 
   la salida.
   
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00032400000000000000">
Interpretar</A>
</H3>

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Interpretar.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>General.
   
</DD>
<DT><STRONG>Nivel:</STRONG></DT>
<DD>Subfunción.
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema analiza, interpreta y ejecuta un bloque de código facilitado por el usuario.
   Para ello comprueba que este cumple con el léxico y la gramática del lenguaje 
   que define, dividiéndolo a su vez en sentencias que serán interpretadas. 
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>Se dispone de un bloque de código.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>El bloque de código es interpretado.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El sistema procesa y comprueba el bloque de código, aplicando
   la gramática y léxico que define.
</LI>
<LI>El sistema obtiene e interpreta cada sentencia en el código, produciéndose
   el significado semántico que estas encierran.
   
</LI>
</OL>
   
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El código no respeta el léxico del lenguaje.
         
<OL>
<LI>El sistema informa del error y finaliza.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
   
 <OL>
<LI><OL>
<LI>El código no respeta la gramática del lenguaje.
         
<OL>
<LI>El sistema informa del error y finaliza.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
   
 <OL>
<LI><OL>
<LI>El código no contiene ninguna sentencia.
         
<OL>
<LI>El sistema finaliza.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00032500000000000000">
Ver ayuda</A>
</H3>

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Ver ayuda.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>General.
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se muestra una ayuda que detalla cada opción disponible en el sistema.
   
</DD>
<DT><STRONG>Actores:</STRONG></DT>
<DD>Usuario.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>Sin precondiciones.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>El sistema muestra un listado que presenta las distintas opciones.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario indica que quiere visualizar la ayuda.
</LI>
<LI>El sistema muestra un listado completo de las opciones que
   presenta. 
   
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00032600000000000000">
Cargar extensión</A>
</H3>

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Cargar extensión.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>General.
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario indica que una extensión que será cargada por
   el sistema.
   
</DD>
<DT><STRONG>Actores:</STRONG></DT>
<DD>Usuario.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>Sin precondiciones.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>El sistema cargar la extensión facilitada.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario indica la ruta a la extensión que desea cargar.
</LI>
<LI>El sistema carga la extensión para disponer de las distintas opciones que 
   ofrece. 
   
</LI>
</OL>
   
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>La extensión indicada no se encuentra.
         
<OL>
<LI>El sistema informa del error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
   
 <OL>
<LI><OL>
<LI>La extensión indicada no es una extensión válida.
         
<OL>
<LI>El sistema informa del error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00032700000000000000">
Listar extensiones</A>
</H3>

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Listar extensiones.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>General.
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Lista las extensiones que serán cargadas en cada ejecución del sistema.
   
</DD>
<DT><STRONG>Actores:</STRONG></DT>
<DD>Usuario.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>Sin precondiciones.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>El sistema lista las extensiones que serán cargadas.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario indica que desea listar las extensiones cargadas.
</LI>
<LI>El sistema lista las extensiones cargadas por defecto. 
   
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00032800000000000000">
Iniciar interpretación red</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Iniciar interpretación red 
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>Red
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Un sistema externo inicia una interpretación por red, estableciendo el contenido fuente que será interpretado.
   El sistema procesa la petición y abre un nuevo proceso de interpretación por pasos.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene. 
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se establece el código fuente a interpretar y se inicia una interpretación por pasos.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El sistema espera una petición de interpretación por red.
</LI>
<LI>El sistema externo inicia la comunicación y facilita el código fuente.
</LI>
<LI>El sistema establece el código fuente y abre un nuevo proceso de interpretación por pasos. 
   
</LI>
</OL>
   
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El servicio no se encuentra disponible.
         
<OL>
<LI>Se devuelve un estado de error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00032900000000000000">
Obtener pasos interpretación red</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Obtener pasos interpretación red 
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>Red
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Un sistema externo obtiene un nuevo estado dentro de los pasos en el proceso de
   interpretación del código fuente establecido.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>Se ha establecido código fuente para una interpretación por pasos.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se lleva a cabo un nuevo paso dentro del proceso de interpretación. Obteniéndose el 
   siguiente estado.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El sistema espera la petición de un nuevo paso en una iterpretación por red.
</LI>
<LI>El sistema externo realiza la petición de un nuevo paso.
</LI>
<LI>Incluir (Interpretar).
</LI>
<LI>El sistema devuelve una estructura de datos que representa 
   el estado actual del proceso de interpretación.
   
</LI>
</OL>
   
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El servicio no se encuentra disponible.
         
<OL>
<LI>Se devuelve un estado de error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
   
 <OL>
<LI><OL>
<LI>El código fuente presenta errores sintáctico o léxicos.
         
<OL>
<LI>Se devuelve un estado de error. 
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H2><A NAME="SECTION00033000000000000000">
runTree</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="237" HEIGHT="410" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/runtree.png"
 ALT="Image runtree"> 
<BR>
</DIV>
<H3><A NAME="SECTION00033100000000000000">
Enviar código fuente</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Enviar código fuente 
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario envía  texto correspondiente a código fuente para su interpretación y análisis. 
   El sistema cliente envía el código al servidor que lo establecerá como fuente a interpretar y enviará
   datos relativos al proceso.
   El cliente imprime el árbol sintáctico y espera acciones del usuario.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se ha establecido el código fuente para el análisis del proceso de interpretación y se ha imprimido el árbol sintáctico. 
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El sistema solicita  código fuente escrito en OMI.
</LI>
<LI>El usuario introduce código fuente escrito en el lenguaje OMI.
</LI>
<LI>El sistema cliente runtree envía el código fuente al servidor para su interpretación.
</LI>
<LI>El sistema servidor devuelve una representación de los datos que describen el árbol sintáctico relativo al código fuente enviado.
</LI>
<LI>El sistema cliente imprime el árbol sintáctico. 
   
</LI>
</OL>
   
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El código fuente no presenta una sintaxis OMI correcta.
         
<OL>
<LI>Se devuelve un estado de error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
   
 <OL>
<LI><OL>
<LI>El servicio no se encuentra disponible.
         
<OL>
<LI>Se devuelve un estado de error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00033200000000000000">
Siguiente paso</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Siguiente paso
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario usuario solicita un nuevo paso en el proceso de interpretación. 
   El sistema cliente obtiene el nuevo paso del servidor y lo representa en pantalla.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
   
<UL>
<LI>Existe un código fuente establecido para estudio. 
</LI>
<LI>El estado actual del proceso no es final.
</LI>
<LI>La ejecución automática se encuentra desactivada. 
   
</LI>
</UL>
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se representa en nuevo paso. 
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario solicita un nuevo paso en el proceso de interpretación
</LI>
<LI>El sistema cliente solicita la resolución de un nuevo paso y representa
   el nuevo estado en pantalla. 
   
</LI>
</OL>
   
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El servicio no se encuentra disponible.
         
<OL>
<LI>Se devuelve un estado de error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00033300000000000000">
Siguiente sentencia</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Siguiente sentencia
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario solicita la resolución de la siguiente sentencia. 
   El sistema cliente obtiene el estado correspondiente a la interpretación de la siguiente sentencia 
   dentro del proceso de interpretación y lo representa en pantalla.
  
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
   
<UL>
<LI>Existe un código fuente establecido para estudio. 
</LI>
<LI>El estado actual del proceso no es final.
</LI>
<LI>La ejecución automática se encuentra desactivada. 
   
</LI>
</UL>
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se representa en nuevo estado correspondiente a la interpretación de una sentencia completa. 
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario solicita la resolución de una nueva senterncia en el proceso de interpretación.
</LI>
<LI>El sistema cliente solicita la resolución de la sentencia completa y representa
   el nuevo estado en pantalla. 
   
</LI>
</OL>
   
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El servicio no se encuentra disponible.
         
<OL>
<LI>Se devuelve un estado de error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00033400000000000000">
Activar ejecución automática</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Activar ejecución automática
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario solicita la ejecución automática. 
   El sistema cliente obtiene y representa cada paso dentro del proceso 
   de interpretación hasta obtenerse un estado final.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
   
<UL>
<LI>Existe un código fuente establecido para estudio. 
</LI>
<LI>El estado actual del proceso no es final.
</LI>
<LI>La ejecución automática se encuentra desactivada. 
   
</LI>
</UL>
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se obtiene un estado final.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario activa la ejecución automática.
</LI>
<LI>El sistema obtiene y representa cada paso en el proceso de interpretación hasta que se 
   obtiene un estado final.
   
</LI>
</OL>
   
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El servicio no se encuentra disponible.
         
<OL>
<LI>Se devuelve un estado de error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00033500000000000000">
Desactivar ejecución automática</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Desactivar ejecución automática
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario solicita la detención de la ejecución automática. 
   El sistema cliente detiene la ejecución automática y representa el estado actual.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
   
<UL>
<LI>Existe un código fuente establecido para estudio. 
</LI>
<LI>El estado actual del proceso no es final.
</LI>
<LI>La ejecución automática se encuentra activada.
   
</LI>
</UL>
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se obtiene el estado actual del proceso.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario desactiva la ejecución automática.
</LI>
<LI>El sistema cliente para la ejecución automática y representa el estado actual 
   
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00033600000000000000">
Limpiar salida</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Limpiar salida
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario solicita la limpieza de los datos de salida. 
   El sistema cliente elimina la información disponible en la consola de salida.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>La consola de salida queda vacía.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario solicita la limpieza de la salida.
</LI>
<LI>El sistema cliente limpia la información disponible en la consola de salida.  
   
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00033700000000000000">
Ver información de nodo</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Ver información de nodo.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario marca un nodo para ver su información.  
   El sistema cliente muestra la información relativa al nodo.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>Existe un código fuente establecido para estudio. 
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se muestra información relativa al nodo.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario marca un nodo para ver su información.
</LI>
<LI>El sistema muestra información relativa al nodo tal como su 
   posición de memoria interna, su tamaño, su tipo y su nombre.  
   
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00033800000000000000">
Ver contenido de la tabla de símbolos</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Ver contenido de la tabla de símbolos.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario marca una tabla de símbolos para ver su contenido.  
   El sistema cliente muestra la información relativa a la tabla de símbolos.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>Existe un código fuente establecido para estudio. 
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se muestra información relativa a la tabla de símbolos.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario indica una tabla de símbolos para ver su contenido.
</LI>
<LI>El sistema cliente muestra los nodos referenciados desde la tabla de
   símbolos dada.
   
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00033900000000000000">
Guardar código fuente</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Guardar código fuente.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario solicita guardar el codigo fuente escrito en un fichero local y el cliente
   abre el cuadro de diálogo correspondiente.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>Existe un código escrito en el cliente 
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se guarda el código fuente en un fichero local.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario solicita guardar el código fuente en un fichero local.
</LI>
<LI>El sistema abre el cuadro de diálogo correspondiente.
   
</LI>
</OL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION000331000000000000000">
Abrir código fuente</A>
</H3> 

<P>
<DL>
<DT><STRONG>Caso de Uso:</STRONG></DT>
<DD>Abrir código fuente.
   
</DD>
<DT><STRONG>Tipo:</STRONG></DT>
<DD>runTree
   
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El usuario solicita cargar código fuente desde un fichero local.
   
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene.
   
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>Se carga el código fuente contenido en el fichero.
   
</DD>
<DT><STRONG>Escenario principal:</STRONG></DT>
<DD>
   
<OL>
<LI>El usuario solicita abrir un fichero de código fuente.
</LI>
<LI>El sistema abre el cuadro de diálogo correspondiente.
</LI>
<LI>El sistama carga el contenido del código fuente.
   
</LI>
</OL>
    
</DD>
<DT><STRONG>Flujo alternativo:</STRONG></DT>
<DD>
   
 <OL>
<LI><OL>
<LI>El fichero no contiene código en texto plano.
         
<OL>
<LI>Se devuelve un estado de error.
         
</LI>
</OL>
</LI>
</OL>
</LI>
</OL>
</DD>
</DL>

<P>

<H1><A NAME="SECTION00040000000000000000">
Visión general</A>
</H1>
El presente documento constituye el modelo de comportamiento del sistema.

<P>
Partiendo de los casos de usos se presentan los diagramas de secuencias que modelan 
los eventos que el sistema puede recibir del usuario y los valores de retorno
que produce como consecuencia de estos.  Esta sección considera tanto al sistema intérprete
como el cliente.

<P>
A partir de los diagramas de secuencia del sistema se obtienen las operaciones 
que este presenta. Luego se describen los contratos de cada una de las operaciones.  
<H1><A NAME="SECTION00050000000000000000">
Diagramas de secuencia del sistema</A>
</H1>

<H2><A NAME="SECTION00051000000000000000">
Intérprete</A>
</H2>

<H3><A NAME="SECTION00051100000000000000">
Interpretar entrada estándar</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/interpretar_stdin.png"
 ALT="Image interpretar_stdin"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00051200000000000000">
Interpretar línea</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/interpretar_line.png"
 ALT="Image interpretar_line"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00051300000000000000">
Interpretar fichero</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/interpretar_file.png"
 ALT="Image interpretar_file"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00051400000000000000">
Ver ayuda</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="168" HEIGHT="190" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/ver_ayuda.png"
 ALT="Image ver_ayuda"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00051500000000000000">
Cargar extensión</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="292" HEIGHT="412" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/cagar_extension.png"
 ALT="Image cagar_extension"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00051600000000000000">
Listar extensiones</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="268" HEIGHT="312" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/listar_extensiones.png"
 ALT="Image listar_extensiones"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00051700000000000000">
Iniciar interpretación red</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="188" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/iniciar_interpretacion_red.png"
 ALT="Image iniciar_interpretacion_red"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00051800000000000000">
Obtener pasos interpretación red</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="188" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/obtener_paso_interpretacion_red.png"
 ALT="Image obtener_paso_interpretacion_red"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION00052000000000000000">
runTree</A>
</H2>

<H3><A NAME="SECTION00052100000000000000">
Enviar código fuente</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/enviar_codigo_fuente.png"
 ALT="Image enviar_codigo_fuente"> 
<BR>
</DIV>
<H3><A NAME="SECTION00052200000000000000">
Siguiente paso</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/siguiente_paso.png"
 ALT="Image siguiente_paso"> 
<BR>
</DIV>
<H3><A NAME="SECTION00052300000000000000">
Siguiente sentencia</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/siguiente_sentencia.png"
 ALT="Image siguiente_sentencia"> 
<BR>
</DIV>
<H3><A NAME="SECTION00052400000000000000">
Activar ejecución automática</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="189" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/activar_ejecucion_automatica.png"
 ALT="Image activar_ejecucion_automatica"> 
<BR>
</DIV>
<H3><A NAME="SECTION00052500000000000000">
Desctivar ejecución automática</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/desactivar_ejecucion_automatica.png"
 ALT="Image desactivar_ejecucion_automatica"> 
<BR>
</DIV>
<H3><A NAME="SECTION00052600000000000000">
Limpiar salida</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/limpiar_salida.png"
 ALT="Image limpiar_salida"> 
<BR>
</DIV>
<H3><A NAME="SECTION00052700000000000000">
Ver infomación de nodo</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/ver_info_nodo.png"
 ALT="Image ver_info_nodo"> 
<BR>
</DIV>
<H3><A NAME="SECTION00052800000000000000">
Ver contenido tabla de símbolo</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/ver_tabla_simbolos.png"
 ALT="Image ver_tabla_simbolos"> 
<BR>
</DIV>
<H3><A NAME="SECTION00052900000000000000">
Guardar código fuente</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/guardar_codigo_fuente.png"
 ALT="Image guardar_codigo_fuente"> 
<BR>
</DIV>
<H3><A NAME="SECTION000521000000000000000">
Abrir código fuente</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="156" HEIGHT="182" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/abrir_codigo_fuente.png"
 ALT="Image abrir_codigo_fuente"> 
<BR>
</DIV>

<P>

<H1><A NAME="SECTION00060000000000000000">
Contratos de operaciones del sistema</A>
</H1>
En esta sección se listan las operaciones del sistema y se detallan los contratos de aquellas
que implican un cambio en la estructura de datos interna del programa. 

<P>

<H2><A NAME="SECTION00061000000000000000">
Intérprete</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="192" HEIGHT="124" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/operaciones_sistema.png"
 ALT="Image operaciones_sistema"> 
<BR>
</DIV>
<H3><A NAME="SECTION00061100000000000000">
Operación inicio_interprete_stdin</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>inicio_interprete_stdin(args)
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Iniciar la interpretación de la entrada estándar.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Interpretar entrada estándar
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene.
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó una instancia ``i'' de ``interpreter'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``i''.
</LI>
<LI>Se crearon las instancias ``<SPAN CLASS="MATH"><IMG
 WIDTH="56" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img3.png"
 ALT="$ a_0...a_n$"></SPAN>'' de ``arg'' por cada argumento en ``args'' (creación de objeto).
</LI>
<LI>Se asignó ``args<SPAN CLASS="MATH"><IMG
 WIDTH="10" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img4.png"
 ALT="$ _i$"></SPAN>'' a ``<SPAN CLASS="MATH"><IMG
 WIDTH="70" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img5.png"
 ALT="$ a_i.value$"></SPAN>'' (<!-- MATH
 $a_i.value =$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="90" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img6.png"
 ALT="$ a_i.value = $"></SPAN>args<SPAN CLASS="MATH"><IMG
 WIDTH="10" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img4.png"
 ALT="$ _i$"></SPAN>) (modificación de atributos).
</LI>
<LI>Se asoció los ``arg'' ``<SPAN CLASS="MATH"><IMG
 WIDTH="56" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img3.png"
 ALT="$ a_0...a_n$"></SPAN>'' al objeto ``i'' de ``interpreter'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``p'' de ``parser'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``p''.
</LI>
<LI>Se creó una instancia ``s'' de ``scanner'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``s''.
</LI>
<LI>Se asoció el ``scanner'' ``s'' al objeto ``p'' de ``parser'' (creación de enlace).
</LI>
<LI>Se asoció el ``parser'' ``p'' al objeto ``i'' de ``interpreter'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``c'' de ``context'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``c''.
</LI>
<LI>Se creó una instancia ``var'' de ``varSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``var''.
</LI>
<LI>Se asoció el ``varSymbols'' ``var'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``func'' de ``funcSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``func''.
</LI>
<LI>Se asoció el ``funcSymbols'' ``func'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``class'' de ``classSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``class''.
</LI>
<LI>Se asoció el ``classSymbols'' ``class'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se asoció el ``context'' ``c'' al objeto ``i'' de ``interpreter'' (creación de enlace).
      
</LI>
</UL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00061200000000000000">
Operación inicio_interprete_linea</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>inicio_interprete_linea(args)
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Iniciar la interpretación interactiva línea a línea.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Interpretar línea
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene.
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó una instancia ``i'' de ``interpreter'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``i''.
</LI>
<LI>Se crearon las instancias ``<SPAN CLASS="MATH"><IMG
 WIDTH="56" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img3.png"
 ALT="$ a_0...a_n$"></SPAN>'' de ``arg'' por cada argumento en ``args'' (creación de objeto).
</LI>
<LI>Se asignó ``args<SPAN CLASS="MATH"><IMG
 WIDTH="10" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img4.png"
 ALT="$ _i$"></SPAN>'' a ``<SPAN CLASS="MATH"><IMG
 WIDTH="70" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img5.png"
 ALT="$ a_i.value$"></SPAN>'' (<!-- MATH
 $a_i.value =$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="90" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img6.png"
 ALT="$ a_i.value = $"></SPAN>args<SPAN CLASS="MATH"><IMG
 WIDTH="10" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img4.png"
 ALT="$ _i$"></SPAN>) (modificación de atributos).
</LI>
<LI>Se asoció los ``arg'' ``<SPAN CLASS="MATH"><IMG
 WIDTH="56" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img3.png"
 ALT="$ a_0...a_n$"></SPAN>'' al objeto ``i'' de ``interpreter'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``p'' de ``parser'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``p''.
</LI>
<LI>Se creó una instancia ``s'' de ``scanner'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``s''.
</LI>
<LI>Se asoció el ``scanner'' ``s'' al objeto ``p'' de ``parser'' (creación de enlace).
</LI>
<LI>Se asoció el ``parser'' ``p'' al objeto ``i'' de ``interpreter'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``c'' de ``context'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``c''.
</LI>
<LI>Se creó una instancia ``var'' de ``varSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``var''.
</LI>
<LI>Se asoció el ``varSymbols'' ``var'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``func'' de ``funcSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``func''.
</LI>
<LI>Se asoció el ``funcSymbols'' ``func'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``class'' de ``classSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``class''.
</LI>
<LI>Se asoció el ``classSymbols'' ``class'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se asoció el ``context'' ``c'' al objeto ``i'' de ``interpreter'' (creación de enlace).
      
</LI>
</UL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00061300000000000000">
Operación interpretar_cadena</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>interpretar_cadena(str)
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Interpreta el contenido fuente almacenado en la cadena ``str''
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>
      
<UL>
<LI>Caso de Uso: Interpretar entrada estándar 
</LI>
<LI>Caso de Uso: Interpretar línea
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó un ``interpreter'' ``i''.
</LI>
<LI>Se creó y asoció una instancia de ``parser'' y ``scanner'' a ``i''.
</LI>
<LI>Se creó y asoció una instancia de ``varSymblos'', ``funcSymbols'' y ``classSymbols'' a ``i''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó una instancia ``s'' de ``source'' (creación de objeto).
</LI>
<LI>Se asignó ``str'' a ``s.src'' (s.src = str) (modificación de atributos)
</LI>
<LI>Se asoció ``s'' al ``scanner'' componente del ``interpreter'' ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="50" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img7.png"
 ALT="$ t_0...t_n$"></SPAN>'' de ``token'' a partir del análisis léxico (creación de objeto).
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``runNode'' a partir del análisis sintáctico (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico (creación de enlace).
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``interprter'' ``i'' (creación de enlace).
         
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="93" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img12.png"
 ALT="$ var_0...var_n$"></SPAN>'' de ``refNode'' correspondientes a las variables definidas en el contenido fuente (creación de objetos).
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $val_0...val_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="87" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img13.png"
 ALT="$ val_0...val_n$"></SPAN>'' de ``runNode'' correspondientes a los valores asignados a las variables definidas en el contenido fuente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $val_i\ \epsilon\ val_0...val_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="137" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img14.png"
 ALT="$ val_i \epsilon val_0...val_n$"></SPAN>'' a  ``<!-- MATH
 $var_i\ \epsilon\ var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="146" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img15.png"
 ALT="$ var_i \epsilon var_0...var_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="35" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img16.png"
 ALT="$ val_i$"></SPAN> es el valor de la variable <SPAN CLASS="MATH"><IMG
 WIDTH="38" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img17.png"
 ALT="$ var_i$"></SPAN> (creación de enlace). 
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="93" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img12.png"
 ALT="$ var_0...var_n$"></SPAN>'' al componente ``varSymbols'' de ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="119" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img18.png"
 ALT="$ func_0...func_n$"></SPAN>'' de ``refNode'' correspondientes a las funciones con identificador definidas en el contenido fuente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $func_i\ \epsilon\ func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="185" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img19.png"
 ALT="$ func_i \epsilon func_0...func_n$"></SPAN>'' a  ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="21" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img20.png"
 ALT="$ n_i$"></SPAN> es un ``funcNode'' correspondiente a la definición de la función <SPAN CLASS="MATH"><IMG
 WIDTH="51" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img21.png"
 ALT="$ func_i$"></SPAN> (creación de enlaces).
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="119" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img18.png"
 ALT="$ func_0...func_n$"></SPAN>'' al componente ``funcSymbols'' de ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="120" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img22.png"
 ALT="$ class_0...class_n$"></SPAN>'' de ``refNode'' correspondientes a las clases definidas en el contenido fuente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $class_i\ \epsilon\ class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="186" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img23.png"
 ALT="$ class_i \epsilon class_0...class_n$"></SPAN>'' a  ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="21" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img20.png"
 ALT="$ n_i$"></SPAN> es un ``classNode'' correspondiente a la definición de la clase <SPAN CLASS="MATH"><IMG
 WIDTH="51" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img24.png"
 ALT="$ class_i$"></SPAN> (creación de enlaces).
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="120" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img22.png"
 ALT="$ class_0...class_n$"></SPAN>'' al componente ``classSymbols'' de ``i'' (creación de enlace). 
      
</LI>
</UL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00061400000000000000">
Operación interpretar_fichero</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>interpretar_fichero(fichero, args)
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Interpreta el contenido fuente almacenado en ``fichero''
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Interpretar fichero
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene.
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó una instancia ``i'' de ``interpreter'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``i''.
</LI>
<LI>Se creó el conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="56" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img3.png"
 ALT="$ a_0...a_n$"></SPAN>'' de ``arg'' según el número de argumentos en ``args'' (creación de objeto).
</LI>
<LI>Se asignó ``args<SPAN CLASS="MATH"><IMG
 WIDTH="10" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img4.png"
 ALT="$ _i$"></SPAN>'' a ``<SPAN CLASS="MATH"><IMG
 WIDTH="70" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img5.png"
 ALT="$ a_i.value$"></SPAN>'' (<!-- MATH
 $a_i.value =$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="90" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img6.png"
 ALT="$ a_i.value = $"></SPAN>args<SPAN CLASS="MATH"><IMG
 WIDTH="10" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img4.png"
 ALT="$ _i$"></SPAN>) (modificación de atributos).
</LI>
<LI>Se asoció los ``arg'' ``<SPAN CLASS="MATH"><IMG
 WIDTH="56" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img3.png"
 ALT="$ a_0...a_n$"></SPAN>'' al objeto ``i'' de ``interpreter'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``p'' de ``parser'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``p''.
</LI>
<LI>Se creó una instancia ``s'' de ``scanner'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``s''.
</LI>
<LI>Se asoció el ``scanner'' ``s'' al objeto ``p'' de ``parser'' (creación de enlace).
</LI>
<LI>Se asoció el ``parser'' ``p'' al objeto ``i'' de ``interpreter'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``c'' de ``context'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``c''.
</LI>
<LI>Se creó una instancia ``var'' de ``varSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``var''.
</LI>
<LI>Se asoció el ``varSymbols'' ``var'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``func'' de ``funcSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``func''.
</LI>
<LI>Se asoció el ``funcSymbols'' ``func'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``class'' de ``classSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``class''.
</LI>
<LI>Se asoció el ``classSymbols'' ``class'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se asoció el ``context'' ``c'' al objeto ``i'' de ``interpreter'' (creación de enlace).

<P>
</LI>
<LI>Se creó una instancia ``src'' de ``source'' (creación de objeto).
</LI>
<LI>Se asignó el contenido de ``fichero'' a ``src.src'' (src.src = fichero) (modificación de atributos)
</LI>
<LI>Se asoció ``src'' al ``scanner'' ``s'' componente del ``interpreter'' ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="50" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img7.png"
 ALT="$ t_0...t_n$"></SPAN>'' de ``token'' a partir del análisis léxico (creación de objeto).
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``runNode'' a partir del análisis sintáctico (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico (creación de enlace).
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``interprter'' ``i'' (creación de enlace).
         
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="93" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img12.png"
 ALT="$ var_0...var_n$"></SPAN>'' de ``refNode'' correspondientes a las variables definidas en el contenido fuente (creación de objetos).
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $val_0...val_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="87" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img13.png"
 ALT="$ val_0...val_n$"></SPAN>'' de ``runNode'' correspondientes a los valores asignados a las variables definidas en el contenido fuente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $val_i\ \epsilon\ val_0...val_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="137" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img14.png"
 ALT="$ val_i \epsilon val_0...val_n$"></SPAN>'' a  ``<!-- MATH
 $var_i\ \epsilon\ var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="146" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img15.png"
 ALT="$ var_i \epsilon var_0...var_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="35" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img16.png"
 ALT="$ val_i$"></SPAN> es el valor de la variable <SPAN CLASS="MATH"><IMG
 WIDTH="38" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img17.png"
 ALT="$ var_i$"></SPAN> (creación de enlace). 
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="93" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img12.png"
 ALT="$ var_0...var_n$"></SPAN>'' al componente ``varSymbols'' de ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="119" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img18.png"
 ALT="$ func_0...func_n$"></SPAN>'' de ``refNode'' correspondientes a las funciones con identificador definidas en el contenido fuente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $func_i\ \epsilon\ func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="185" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img19.png"
 ALT="$ func_i \epsilon func_0...func_n$"></SPAN>'' a  ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="21" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img20.png"
 ALT="$ n_i$"></SPAN> es un ``funcNode'' correspondiente a la definición de la función <SPAN CLASS="MATH"><IMG
 WIDTH="51" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img21.png"
 ALT="$ func_i$"></SPAN> (creación de enlaces).
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="119" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img18.png"
 ALT="$ func_0...func_n$"></SPAN>'' al componente ``funcSymbols'' de ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="120" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img22.png"
 ALT="$ class_0...class_n$"></SPAN>'' de ``refNode'' correspondientes a las clases definidas en el contenido fuente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $class_i\ \epsilon\ class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="186" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img23.png"
 ALT="$ class_i \epsilon class_0...class_n$"></SPAN>'' a  ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="21" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img20.png"
 ALT="$ n_i$"></SPAN> es un ``classNode'' correspondiente a la definición de la clase <SPAN CLASS="MATH"><IMG
 WIDTH="51" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img24.png"
 ALT="$ class_i$"></SPAN> (creación de enlaces).
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="120" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img22.png"
 ALT="$ class_0...class_n$"></SPAN>'' al componente ``classSymbols'' de ``i'' (creación de enlace). 
      
</LI>
</UL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00061500000000000000">
Operación iniciar_interpretacion_red</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>iniciar_interpretacion_red (src)
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Iniciar la interpretación de una petición por red.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Iniciar interpretación red
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene.
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó una instancia ``i'' de ``interpreter'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``i''.
</LI>
<LI>Se creó una instancia ``p'' de ``parser'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``p''.
</LI>
<LI>Se creó una instancia ``s'' de ``scanner'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``s''.
</LI>
<LI>Se asoció el ``scanner'' ``s'' al objeto ``p'' de ``parser'' (creación de enlace).
</LI>
<LI>Se asoció el ``parser'' ``p'' al objeto ``i'' de ``interpreter'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``c'' de ``context'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``c''.
</LI>
<LI>Se creó una instancia ``var'' de ``varSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``var''.
</LI>
<LI>Se asoció el ``varSymbols'' ``var'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``func'' de ``funcSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``func''.
</LI>
<LI>Se asoció el ``funcSymbols'' ``func'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``class'' de ``classSymbols'' (creación de objeto).
</LI>
<LI>Se inicializaron los atributos de ``class''.
</LI>
<LI>Se asoció el ``classSymbols'' ``class'' al objeto ``c'' de ``context'' (creación de enlace).
</LI>
<LI>Se asoció el ``context'' ``c'' al objeto ``i'' de ``interpreter'' (creación de enlace).
</LI>
<LI>Se creó una instancia ``src'' de ``source'' (creación de objeto).
</LI>
<LI>Se asignó el contenido de ``fichero'' a ``src.src'' (src.src = fichero) (modificación de atributos)
</LI>
<LI>Se asoció ``src'' al ``scanner'' ``s'' componente del ``interpreter'' ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="50" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img7.png"
 ALT="$ t_0...t_n$"></SPAN>'' de ``token'' a partir del análisis léxico (creación de objeto).
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``runNode'' a partir del análisis sintáctico (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico (creación de enlace).
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``interprter'' ``i'' (creación de enlace).
      
</LI>
</UL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00061600000000000000">
Operación obtener_paso_interpretacion_red</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>obtener_paso_interpretacion_red
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Obtiene el siguiente paso de la interpretación de una petición por red abierta.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Obtener pasos interpretación red
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó un ``interpreter'' ``i''.
</LI>
<LI>Se creó y asoció una instancia de ``parser'' y ``scanner'' a ``i''.
</LI>
<LI>Se creó y asoció una instancia de ``varSymblos'', ``funcSymbols'' y ``classSymbols'' a ``i''.
</LI>
<LI>Se creó una instancia ``src'' de ``source''.
</LI>
<LI>Se asoció ``src'' al ``scanner'' ``s'' componente del ``interpreter'' ``i''. 
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="50" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img7.png"
 ALT="$ t_0...t_n$"></SPAN>'' de ``token'' a partir del análisis léxico.
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``runNode'' a partir del análisis sintáctico.
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico.
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``interprter'' ``i''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó un conjunto ``<!-- MATH
 $var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="93" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img12.png"
 ALT="$ var_0...var_n$"></SPAN>'' de ``refNode'' correspondientes a las variables definidas en el paso correspondiente (creación de objetos).
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $val_0...val_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="87" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img13.png"
 ALT="$ val_0...val_n$"></SPAN>'' de ``runNode'' correspondientes a los valores asignados a las variables definidas en el paso correspondiente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $val_i\ \epsilon\ val_0...val_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="137" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img14.png"
 ALT="$ val_i \epsilon val_0...val_n$"></SPAN>'' a  ``<!-- MATH
 $var_i\ \epsilon\ var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="146" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img15.png"
 ALT="$ var_i \epsilon var_0...var_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="35" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img16.png"
 ALT="$ val_i$"></SPAN> es el valor de la variable <SPAN CLASS="MATH"><IMG
 WIDTH="38" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img17.png"
 ALT="$ var_i$"></SPAN> (creación de enlace). 
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $var_0...var_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="93" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img12.png"
 ALT="$ var_0...var_n$"></SPAN>'' al componente ``varSymbols'' de ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="119" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img18.png"
 ALT="$ func_0...func_n$"></SPAN>'' de ``refNode'' correspondientes a las funciones con identificador definidas en el paso correspondiente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $func_i\ \epsilon\ func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="185" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img19.png"
 ALT="$ func_i \epsilon func_0...func_n$"></SPAN>'' a  ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="21" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img20.png"
 ALT="$ n_i$"></SPAN> es un ``funcNode'' correspondiente a la definición de la función <SPAN CLASS="MATH"><IMG
 WIDTH="51" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img21.png"
 ALT="$ func_i$"></SPAN> (creación de enlaces).
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $func_0...func_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="119" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img18.png"
 ALT="$ func_0...func_n$"></SPAN>'' al componente ``funcSymbols'' de ``i'' (creación de enlace). 
</LI>
<LI>Se creó un conjunto ``<!-- MATH
 $class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="120" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img22.png"
 ALT="$ class_0...class_n$"></SPAN>'' de ``refNode'' correspondientes a las clases definidas en el paso correspondiente (creación de objetos).
</LI>
<LI>Se asoció ``<!-- MATH
 $class_i\ \epsilon\ class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="186" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img23.png"
 ALT="$ class_i \epsilon class_0...class_n$"></SPAN>'' a  ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' donde <SPAN CLASS="MATH"><IMG
 WIDTH="21" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img20.png"
 ALT="$ n_i$"></SPAN> es un ``classNode'' correspondiente a la definición de la clase <SPAN CLASS="MATH"><IMG
 WIDTH="51" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img24.png"
 ALT="$ class_i$"></SPAN> (creación de enlaces).
</LI>
<LI>Se asoció todo ``refNode'' ``<!-- MATH
 $class_0...class_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="120" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img22.png"
 ALT="$ class_0...class_n$"></SPAN>'' al componente ``classSymbols'' de ``i'' (creación de enlace). 
      
</LI>
</UL>
</DD>
</DL>

<P>

<H2><A NAME="SECTION00062000000000000000">
runTree</A>
</H2>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="192" HEIGHT="136" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/operaciones_sistema_runtree.png"
 ALT="Image operaciones_sistema_runtree"> 
<BR>
</DIV>
<H3><A NAME="SECTION00062100000000000000">
Operación enviar_codigo_fuente</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>enviar_codigo_fuente (src)
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Envía código fuente para una interpretación por red.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Enviar código fuente
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>No tiene.
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó un ``tree'' ``t'' a partir del código enviado a interpretación (creación de objeto).
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``node'' a partir de los datos recibidos de la petición (creación de objeto).
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico (creación de enlace).
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``tree'' ``t'' (creación de enlace).
</LI>
<LI>Se inicializó el atributo ``canvas'' del ``tree'' `t'' para dibujar el árbol correspondiente a los nodos ``<!-- MATH
 $\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>''.
</LI>
<LI>Se creó un ``symbols'' ``s'' (creación de objeto).
</LI>
<LI>Se creó tres instancias de ``table'': ``vars'', ``funcs'' y ``class'' (creación de objeto).
</LI>
<LI>Se asociarón ``vars'', ``funcs'' y ``class'' a ``s'' (creación de enlace).
      
</LI>
</UL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00062200000000000000">
Operación siguiente_paso</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>siguiente_paso
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Obtiene el siguiente paso del proceso de interpretación abierto.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Siguiente paso
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
         
<UL>
<LI>Se creó un ``tree'' ``t''.
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``node''.
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico.
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``tree'' ``t''.
</LI>
<LI>Se creó un ``symbols'' ``s''.
</LI>
<LI>Se creó tres instancias de ``table'': ``vars'', ``funcs'' y ``class''.
</LI>
<LI>Se asociarón ``vars'', ``funcs'' y ``class'' a ``s''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó el conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="53" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img25.png"
 ALT="$ r_0...r_n$"></SPAN>'' de `refs'' según el nuevo paso del proceso de interpretación (creación de objeto).
</LI>
<LI>Se creó el conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="58" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img26.png"
 ALT="$ v_0...v_m$"></SPAN>'' de `node'' correspondiente a los valores generados en el paso del proceso de interpretación (creación de objeto).
</LI>
<LI>Se asoció ``<SPAN CLASS="MATH"><IMG
 WIDTH="19" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img27.png"
 ALT="$ v_i$"></SPAN>'' a ``<SPAN CLASS="MATH"><IMG
 WIDTH="18" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img28.png"
 ALT="$ r_i$"></SPAN>'' como valor de la refercia (creación de enlace).
</LI>
<LI>Se asoció ``<!-- MATH
 $r_i\ \epsilon \ r_0...r_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="87" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img29.png"
 ALT="$ r_i \epsilon  r_0...r_n$"></SPAN>'' a ``vars'', ``funcs'' o ``class'' según el paso del proceso de interpretación (creación de enlace).  
</LI>
<LI>Se actualizó el valor del atributo ``canvas'' de ``s'' para reflejar el nuevo estado tras la ejecución del paso.
</LI>
<LI>Se actualizó el valor del atributo ``canvas'' de ``t'' para reflejar el nuevo estado tras la ejecución del paso.
      
</LI>
</UL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00062300000000000000">
Operación siguiente_sentencia</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>siguiente_sentencia
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Obtiene la siguiente sentencia dentro del proceso de interpretación abierto.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Siguiente sentencia
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
         
<UL>
<LI>Se creó un ``tree'' ``t''.
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``node''.
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico.
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``tree'' ``t''.
</LI>
<LI>Se creó un ``symbols'' ``s''.
</LI>
<LI>Se creó tres instancias de ``table'': ``vars'', ``funcs'' y ``class''.
</LI>
<LI>Se asociarón ``vars'', ``funcs'' y ``class'' a ``s''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se creó el conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="53" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img25.png"
 ALT="$ r_0...r_n$"></SPAN>'' de `refs'' según la nueva sentencia interpretada (creación de objeto).
</LI>
<LI>Se creó el conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="58" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img26.png"
 ALT="$ v_0...v_m$"></SPAN>'' de `node'' correspondiente a los valores generados en la sentencia  interpretada (creación de objeto).
</LI>
<LI>Se asoció ``<SPAN CLASS="MATH"><IMG
 WIDTH="19" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img27.png"
 ALT="$ v_i$"></SPAN>'' a ``<SPAN CLASS="MATH"><IMG
 WIDTH="18" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img28.png"
 ALT="$ r_i$"></SPAN>'' como valor de la refercia (creación de enlace).
</LI>
<LI>Se asoció ``<!-- MATH
 $r_i\ \epsilon \ r_0...r_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="87" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img29.png"
 ALT="$ r_i \epsilon  r_0...r_n$"></SPAN>'' a ``vars'', ``funcs'' o ``class'' según la sentencia interpretada (creación de enlace).  
</LI>
<LI>Se actualizó el valor del atributo ``canvas'' de ``s'' para reflejar el nuevo estado tras la ejecución de la sentencia.
</LI>
<LI>Se actualizó el valor del atributo ``canvas'' de ``t'' para reflejar el nuevo estado tras la ejecución del la sentencia.
      
</LI>
</UL>
</DD>
</DL>

<P>

<H3><A NAME="SECTION00062400000000000000">
Operación activar_ejecucion_automatica</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>activar_ejecucion_automatica
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Activa la ejecución automática del proceso de interpretación.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Activar ejecución automática
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
         
<UL>
<LI>Se creó un ``tree'' ``t''.
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``node''.
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico.
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``tree'' ``t''.
</LI>
<LI>Se creó un ``symbols'' ``s''.
</LI>
<LI>Se creó tres instancias de ``table'': ``vars'', ``funcs'' y ``class''.
</LI>
<LI>Se asociarón ``vars'', ``funcs'' y ``class'' a ``s''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se establece a ``1'' el atributo ``auto'' de ``t''.
      
</LI>
</UL>
</DD>
</DL> 

<P>

<H3><A NAME="SECTION00062500000000000000">
Operación desactivar_ejecucion_automatica</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>desactivar_ejecucion_automatica
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Desactiva la ejecución automática del proceso de interpretación.
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Desactivar ejecución automática
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
         
<UL>
<LI>Se creó un ``tree'' ``t''.
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``node''.
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico.
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``tree'' ``t''.
</LI>
<LI>Se creó un ``symbols'' ``s''.
</LI>
<LI>Se creó tres instancias de ``table'': ``vars'', ``funcs'' y ``class''.
</LI>
<LI>Se asociarón ``vars'', ``funcs'' y ``class'' a ``s''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se establece a ``0'' el atributo ``auto'' de ``t''.
      
</LI>
</UL>
</DD>
</DL> 

<P>

<H3><A NAME="SECTION00062600000000000000">
Operación limpiar_salida</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>limpiar_salida
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Limpia la salida producida por el proceso de interpretación
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Limpiar salida
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
         
<UL>
<LI>Se creó un ``tree'' ``t''.
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``node''.
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico.
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``tree'' ``t''.
</LI>
<LI>Se creó un ``symbols'' ``s''.
</LI>
<LI>Se creó tres instancias de ``table'': ``vars'', ``funcs'' y ``class''.
</LI>
<LI>Se asociarón ``vars'', ``funcs'' y ``class'' a ``s''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se restablece los valores del atributo ``canvas'' de ``t''.
      
</LI>
</UL>
</DD>
</DL> 

<P>

<H3><A NAME="SECTION00062700000000000000">
Operación ver_informacion_nodo</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>ver_informacion_nodo
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Muestra la información de un nodo
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Ver información nodo
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
         
<UL>
<LI>Se creó un ``tree'' ``t''.
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``node''.
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico.
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``tree'' ``t''.
</LI>
<LI>Se creó un ``symbols'' ``s''.
</LI>
<LI>Se creó tres instancias de ``table'': ``vars'', ``funcs'' y ``class''.
</LI>
<LI>Se asociarón ``vars'', ``funcs'' y ``class'' a ``s''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se establece los valores del atributo ``canvas'' de ``t'' para representar la información del nodo.
      
</LI>
</UL>
</DD>
</DL> 

<P>

<H3><A NAME="SECTION00062800000000000000">
Operación ver_tabla_simbolos</A>
</H3>

<P>
<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>ver_tabla_simbolos
		
</DD>
<DT><STRONG>Responsabilidades:</STRONG></DT>
<DD>Muestra la información contenida en una tabla de símbolos
		
</DD>
<DT><STRONG>Referencias Cruzadas: </STRONG></DT>
<DD>Caso de Uso: Ver información nodo
      
</DD>
<DT><STRONG>Precondiciones:</STRONG></DT>
<DD>
         
<UL>
<LI>Se creó un ``tree'' ``t''.
</LI>
<LI>Se creó un conjunto ``<SPAN CLASS="MATH"><IMG
 WIDTH="59" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img8.png"
 ALT="$ n_0...n_n$"></SPAN>'' de ``node''.
</LI>
<LI>Se asoció ``<!-- MATH
 $n_i\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img9.png"
 ALT="$ n_i \epsilon n_0...n_n$"></SPAN>'' a ``<!-- MATH
 $n_k\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="98" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img10.png"
 ALT="$ n_k \epsilon n_0...n_n$"></SPAN>'' para construir el árbol sintáctico.
</LI>
<LI>Se asoció  ``<!-- MATH
 $n_r\ \epsilon\ n_0...n_n$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="97" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL?>src/images/analysis/img11.png"
 ALT="$ n_r \epsilon n_0...n_n$"></SPAN>'', raíz del árbol sintáctico, al ``tree'' ``t''.
</LI>
<LI>Se creó un ``symbols'' ``s''.
</LI>
<LI>Se creó tres instancias de ``table'': ``vars'', ``funcs'' y ``class''.
</LI>
<LI>Se asociarón ``vars'', ``funcs'' y ``class'' a ``s''.
      
</LI>
</UL>
      
</DD>
<DT><STRONG>Postcondiciones:</STRONG></DT>
<DD>
      
<UL>
<LI>Se establece los valores del atributo ``canvas'' de ``s'' para representar la información de la tabla de símbolos.
      
</LI>
</UL>
</DD>
</DL> 

<P>

<H1><A NAME="SECTION00070000000000000000">
Modelo de interfaz de usuario</A>
</H1>
En esta sección se procede al análisis de la interfaz de usuario. Para ello se analizará la interfaz precisa 
para el intérprete y para el cliente runTree.

<P>
El intérprete utilizará una interfaz de consola de comandos. Toda la información de salida la presentará como 
cadenas de caracteres. Así mismo toda la información de entrada la tomará del teclado en formato orden y opciones. 

<P>
Por otro lado el cliente runTree presentará una interfaz en la que se disponga de una descripción gráfica de todo el proceso 
de interpretación. Para una descripción del proceso de interpretación se precisa de la visualización del código fuente, un árbol con los nodos
que encierran el significado semántico del código, las distintas tablas de símbolos que referenciarán a varibles, funciones y clases, y una consola
en la que se mostrará información textual.

<P>
También un diagrama de navegación en el que se expone las distintas ventanas de la web OMI.
<H2><A NAME="SECTION00071000000000000000">
Intérprete</A>
</H2>
El interprete será accesible como cualquier otro comando de la consola del sistema. Este recibirá una serie de opciones y parámetros. 
Las opciones del intérprete tendrán los siguientes propósitos:

<UL>
<LI>Determinar cómo se toma el código fuente, pudiéndo ser desde la entrada estándar, un fichero o la propia línea de comandos
</LI>
<LI>Ejecutar el intérprete de forma interactiva, mostrando un prompt en el que se introdusca directamente las sentencias
</LI>
<LI>Listar y cargar los módulos del intérprete.
</LI>
<LI>Ver la ayuda.
</LI>
<LI>Abrir un puerto de escucha para peticiones de red.
</LI>
<LI>Configurar el formato de la salida que describe el proceso de interpretación.
</LI>
</UL>

<P>
Como cualquier interprete que tome su entrada de la estrada estándar, el interprete OMI puede ser ejecutado por el 
sistema operativo si se indica al comienzo de un script como el shebang del mismo. 
<H2><A NAME="SECTION00072000000000000000">
runTree</A>
</H2>
El cliente runTree será accesible desde un navegador web, y presentará una interfaz gráfica compatible con las versiones actuales de estos.
La interfaz gráfica del cliente deberá contener la siguiente información:

<P>

<UL>
<LI>El código fuente introducido por el usuario y que será enviado a interpretar.
</LI>
<LI>El árbol de nodos resultado del análisis léxico y sintáctico. 
</LI>
<LI>Las distintas tablas de símbolos que guardarán información sobre las variables, las funciones y las clases que serán creadas.
</LI>
<LI>La explicación del proceso semántico llevado a cabo. 
</LI>
<LI>La salida producida como fruto de la ejecución del código fuente.
</LI>
<LI>La entrada introducida por el usuario y que ha sido solicitada por el código fuente.
</LI>
<LI>Información relativa a los nodos y tablas de símbolos que el usuario señale.
</LI>
</UL>

<P>

<H3><A NAME="SECTION00072100000000000000">
Wireframe</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="167" HEIGHT="147" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/wireframe_runtree.png"
 ALT="Image wireframe_runtree"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION00073000000000000000">
Sitio web</A>
</H2>
El proyecto OMI incluye un sitio web que sirve como presentación del mismo, además de como medio de acceso a la documentación 
y el software desarrollado. Todas las páginas web pertenecientes al sitio contienen información relativa al proyecto y a las áreas que este
ocupa. 

<P>
El sitio web OMI se compone de: 

<P>
<DL>
<DT><STRONG>Página de inicio:</STRONG></DT>
<DD>Describe e introduce brevemente el proyecto. Contiene enlaces a las demás secciones del sitio web. Además presenta un
listado de noticias y enlaces de descargas a la última versión del intérprete.
</DD>
<DT><STRONG>Índice de documentación:</STRONG></DT>
<DD>Página que representa un índice de los documentos que conforman el proyecto.
</DD>
<DT><STRONG>Documentos:</STRONG></DT>
<DD>Páginas relativas a la documentación del proyecto en si.
</DD>
<DT><STRONG>Navegador de clases:</STRONG></DT>
<DD>Páginas relativas a la documentación de las clases incluidas en la biblioteca. 
</DD>
<DT><STRONG>Navegador de ficheros:</STRONG></DT>
<DD>Páginas relativas a la documentación de los ficheros que conforman 
el código fuente de la biblioteca y el intérprete.
</DD>
<DT><STRONG>Navegador de gramática:</STRONG></DT>
<DD>Páginas relativas a la documentación gráfica de la gramática del lenguaje.
</DD>
<DT><STRONG>Descargas:</STRONG></DT>
<DD>Página que enlaza la descarga de las distintas versiones del software que conforma el proyecto, disponibles en varios formatos de instalación.
</DD>
<DT><STRONG>Sobre OMI:</STRONG></DT>
<DD>Página con información relativa a la motivación y circunstancias en las que se ha dado el proyecto. Además da detalles sobre los autores y los
organismos implicados en el desarrollo del mismo.
</DD>
<DT><STRONG>Contacto:</STRONG></DT>
<DD>Página con información de contacto.
</DD>
</DL>

<H3><A NAME="SECTION00073100000000000000">
Wireframe</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="458" HEIGHT="472" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/analysis/wireframe.png"
 ALT="Image wireframe"> 
<BR>
</DIV>
            <div class="clear"></div>
         </div>
         <div class="clear"></div> 
      </div>
      <div class="clear"></div> 
      </div>
      <div class="clear"></div>
   </div>
</div>
<div class="clear"></div>
</div>
</div>
<!--

-->
