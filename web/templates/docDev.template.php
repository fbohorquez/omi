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
   <div class="title"><h1 style="font-size:25px;">Construcción del sistema</h1></div>
   <div class="list">

<UL CLASS="TofC">
<LI><A NAME="tex2html6"
  HREF="<?=URL;?>doc/construccion#SECTION00020000000000000000">Vista general</A>
<LI><A NAME="tex2html7"
  HREF="<?=URL;?>doc/construccion#SECTION00030000000000000000">Entorno de construcción</A>
<LI><A NAME="tex2html8"
  HREF="<?=URL;?>doc/construccion#SECTION00040000000000000000">Ficheros de código fuente</A>

<LI><A NAME="tex2html13"
  HREF="<?=URL;?>doc/construccion#SECTION00050000000000000000">Extractos de código fuente</A>
<UL>
<LI><A NAME="tex2html14"
  HREF="<?=URL;?>doc/construccion#SECTION00051000000000000000">Acceso a variable</A>
<LI><A NAME="tex2html15"
  HREF="<?=URL;?>doc/construccion#SECTION00052000000000000000">Asignación</A>
<LI><A NAME="tex2html16"
  HREF="<?=URL;?>doc/construccion#SECTION00053000000000000000">Operación suma</A>
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
            <div class="row">En esta sección se tratan los aspectos relacionados con la con la implementación
del sistema y su codificación. Para ello se describen las herramientas software
y hardware utilizadas en el desarrollo, y la estructra del código fuente. 

<P>

<H1><A NAME="SECTION00030000000000000000">
Entorno de construcción</A>
</H1>

<P>
<DL>
<DT><STRONG>Entodrno de desarrollo (IDE):</STRONG></DT>
<DD>Geany
   
</DD>
<DT><STRONG>Lenguaje de programación:</STRONG></DT>
<DD>C++
   
</DD>
<DT><STRONG>Compilador:</STRONG></DT>
<DD>GCC
   
</DD>
<DT><STRONG>Configuración automática:</STRONG></DT>
<DD>Autoconf
   
</DD>
<DT><STRONG>Construcción automática:</STRONG></DT>
<DD>Automake
   
</DD>
<DT><STRONG>Gestión de dependencias:</STRONG></DT>
<DD>Make
   
</DD>
<DT><STRONG>Control de versions:</STRONG></DT>
<DD>Subversion
   
</DD>
<DT><STRONG>Generador de analizador léxico:</STRONG></DT>
<DD>Flex
   
</DD>
<DT><STRONG>Generador de analizador sintáctico:</STRONG></DT>
<DD>Bison
   
</DD>
<DT><STRONG>Depurador:</STRONG></DT>
<DD>GDB
   
</DD>
<DT><STRONG>Bibliotecas de desarrollo</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Editor de línea e histórico:</STRONG></DT>
<DD>Readline
         
</DD>
<DT><STRONG>Expresiones regulares:</STRONG></DT>
<DD>BoostRegex
         
</DD>
<DT><STRONG>Matemáticas:</STRONG></DT>
<DD>Biblioteca estándar de C
         
</DD>
<DT><STRONG>Enlaces dinámicos:</STRONG></DT>
<DD>Biblioteca del sistema GNU/Linux libdl
      
</DD>
</DL>
   
</DD>
<DT><STRONG>Desarrollo Web</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Programación en servidor:</STRONG></DT>
<DD>PHP
         
</DD>
<DT><STRONG>Programación en cliente:</STRONG></DT>
<DD>JavaScript
         
</DD>
<DT><STRONG>Estructura del contenido:</STRONG></DT>
<DD>HTML5
         
</DD>
<DT><STRONG>Presentación del contenido:</STRONG></DT>
<DD>CSS
      
</DD>
</DL>
</DD>
</DL>

<P>

<H1><A NAME="SECTION00040000000000000000">
Ficheros de código fuente</A>
</H1>
El sistema software se constituye de una serie de módulos o componentes en forma de ficheros, 
cada uno de los cuales contiene las estructuras de programación y el código fuente necesario
para implementar cada una de las funcionalidades del sistema.

<P>
<DL>
<DT><STRONG>interpreter:</STRONG></DT>
<DD>Interprete.
</DD>
<DT><STRONG>lshScanner:</STRONG></DT>
<DD>Analizador léxico.
</DD>
<DT><STRONG>lshParser:</STRONG></DT>
<DD>Analizador sintáctico.
</DD>
<DT><STRONG>error:</STRONG></DT>
<DD>Sistema de errores.
</DD>
<DT><STRONG>plugins:</STRONG></DT>
<DD>Sistema de extensiones.
</DD>
<DT><STRONG>run/runTree:</STRONG></DT>
<DD>Abstracción de nodo ejecutable.
</DD>
<DT><STRONG>run/expNode:</STRONG></DT>
<DD>Abstracción de nodos ejecutables expresiones.
</DD>
<DT><STRONG>run/symbols:</STRONG></DT>
<DD>Estructura de datos tabla de símbolos.
</DD>
<DT><STRONG>run/sTable:</STRONG></DT>
<DD>Gestión de tabla de de símbolos y definiciones.
</DD>
<DT><STRONG>run/typeNode:</STRONG></DT>
<DD>Nodos ejecutables para cada tipo de dato.
</DD>
<DT><STRONG>run/numData:</STRONG></DT>
<DD>Representación interna de datos numéricos.
</DD>
<DT><STRONG>run/stmtNode:</STRONG></DT>
<DD>Nodos ejecutables sentencias de control.
</DD>
<DT><STRONG>run/operatorBaseNode:</STRONG></DT>
<DD>Nodos ejecutables operadores básicos.
</DD>
<DT><STRONG>run/operatorLogicNode:</STRONG></DT>
<DD>Nodos ejecutables operadores lógicos.
</DD>
<DT><STRONG>run/operatorArithNode:</STRONG></DT>
<DD>Nodos ejecutables operadores aritméticos.
</DD>
<DT><STRONG>run/operatorStrNode:</STRONG></DT>
<DD>Nodos ejecutables operadores sobre cadenas.
</DD>
<DT><STRONG>run/operatorArrayNode:</STRONG></DT>
<DD>Nodos ejecutables operadores sobre arrays.
</DD>
<DT><STRONG>run/operatorRegexpNode:</STRONG></DT>
<DD>Nodos ejecutables operadores sobre expresiones regulares.
</DD>
<DT><STRONG>run/operatorDateNode:</STRONG></DT>
<DD>Nodos ejecutables operadores sobre fechas y tiempo.
</DD>
<DT><STRONG>run/operatorFileNode:</STRONG></DT>
<DD>Nodos ejecutables operadores sobre ficheros.
</DD>
<DT><STRONG>run/operatorProcessNode:</STRONG></DT>
<DD>Nodos ejecutables operadores sobre procesos.
</DD>
</DL>

<P>
A continuación se describen las dependencias entre ficheros mediante una serie de paquetes que contienen diagramas de componentes.
Este aspecto del sistema queda completamente descrito mediante la combinación de estos paquetes.

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="529" HEIGHT="740" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/interpreter.png"
 ALT="Image interpreter"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="109" HEIGHT="178" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/error.png"
 ALT="Image error"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="243" HEIGHT="215" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/plugin.png"
 ALT="Image plugin"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="118" HEIGHT="178" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/runTree.png"
 ALT="Image runTree"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="237" HEIGHT="178" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/expNode.png"
 ALT="Image expNode"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="370" HEIGHT="180" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/sTable.png"
 ALT="Image sTable"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="268" HEIGHT="252" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/symbols.png"
 ALT="Image symbols"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="365" HEIGHT="178" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/typeData.png"
 ALT="Image typeData"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="243" HEIGHT="185" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/stmtNode.png"
 ALT="Image stmtNode"> 
<BR>
</DIV>

<DIV ALIGN="CENTER">
<IMG
  WIDTH="319" HEIGHT="305" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorBaseNode.png"
 ALT="Image operatorBaseNode"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="325" HEIGHT="311" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorLogicNode.png"
 ALT="Image operatorLogicNode"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="319" HEIGHT="234" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorArithNode.png"
 ALT="Image operatorArithNode"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="319" HEIGHT="287" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorStrNode.png"
 ALT="Image operatorStrNode"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="319" HEIGHT="287" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorArrayNode.png"
 ALT="Image operatorArrayNode"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="319" HEIGHT="287" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorRegexpNode.png"
 ALT="Image operatorRegexpNode"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="327" HEIGHT="236" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorDateNode.png"
 ALT="Image operatorDateNode"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="319" HEIGHT="287" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorFileNode.png"
 ALT="Image operatorFileNode"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="325" HEIGHT="229" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/dev/operatorProcessNode.png"
 ALT="Image operatorProcessNode"> 
<BR>

</DIV>
<H1><A NAME="SECTION00050000000000000000">
Extractos de código fuente</A>
</H1>

<H2><A NAME="SECTION00051000000000000000">
Acceso a variable</A>
</H2>

<P>
<PRE>
void idNode::run (bool resolvkey) {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   sTable *table_ = sTable::sTable_use;
   refNode *str = new refNode(id_);
   exist_ = table_-&gt;exist (str);
   ref_ = table_-&gt;access (str);
   runNode *val = ref_-&gt;getRef();
   refNode * key = NULL;
   ref_ = refNode::resolved (val);
   #if JSON==1
         interpreter::to_jsonSetValue(this, val);
   #endif
   delete str;
}
</PRE>

<P>

<H2><A NAME="SECTION00052000000000000000">
Asignación</A>
</H2>
<PRE>
void asigNode::run () {
   runNode *node_aux = node2_, *nodeR_ = NULL;
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif
   ref_ = NULL;
   nexpNode::resolvedRef (node_aux);
   #if JSON==1
      if (node2_ != node_aux)
         interpreter::to_jsonRun(this);
   #endif
   if (!(bool)dynamic_cast&lt;functionNode*&gt;(node_aux) &amp;&amp; node2_ == node_aux) {
      node_aux-&gt;run();
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   }
   nodeR_ = this-&gt;isRefNode (node_aux)?node_aux:expNode::clone (node_aux);
   noderef(nodeR_);
   #if JSON==1
      interpreter::to_jsonSetValue(this, nodeR_);
   #endif
   setValue (nodeR_);
}
</PRE>

<P>

<H2><A NAME="SECTION00053000000000000000">
Operación suma</A>
</H2><PRE>
void addNode::run () {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif         
   runNode* op1 = node1_;
   runNode* op2 = node2_;
   nexpNode::resolved (op1);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif      
   nexpNode::resolved (op2);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif         
   numvalue_ = addNode::do_add (op1, op2);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}
</PRE>
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
