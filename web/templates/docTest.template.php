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
pre {
    margin-top: -15px;
}
</style>
<div id="content-doc">
<div id="index">
   <div class="title"><h1 style="font-size:25px;">Construcción del sistema</h1></div>
   <div class="list">

<UL CLASS="TofC">
<LI><A NAME="tex2html28"
  HREF="<?=URL;?>doc/pruebas#SECTION00020000000000000000">Visión general</A>
<LI><A NAME="tex2html29"
  HREF="<?=URL;?>doc/pruebas#SECTION00030000000000000000">Estrategia</A>
<LI><A NAME="tex2html30"
  HREF="<?=URL;?>doc/pruebas#SECTION00040000000000000000">Entorno de pruebas</A>
<UL>
<LI><A NAME="tex2html31"
  HREF="<?=URL;?>doc/pruebas#SECTION00041000000000000000">Hardware</A>
<LI><A NAME="tex2html32"
  HREF="<?=URL;?>doc/pruebas#SECTION00042000000000000000">Software</A>
</UL>
<BR>
<LI><A NAME="tex2html33"
  HREF="<?=URL;?>doc/pruebas#SECTION00050000000000000000">Roles</A>
<LI><A NAME="tex2html34"
  HREF="<?=URL;?>doc/pruebas#SECTION00060000000000000000">Niveles de pruebas</A>
<UL>
<LI><A NAME="tex2html35"
  HREF="<?=URL;?>doc/pruebas#SECTION00061000000000000000">Pruebas unitarias</A>
<LI><A NAME="tex2html36"
  HREF="<?=URL;?>doc/pruebas#SECTION00062000000000000000">Pruebas de integración</A>
<LI><A NAME="tex2html37"
  HREF="<?=URL;?>doc/pruebas#SECTION00063000000000000000">Pruebas funcionales del sistema</A>
<LI><A NAME="tex2html38"
  HREF="<?=URL;?>doc/pruebas#SECTION00064000000000000000">Pruebas no funcionales del sistema</A>
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
            <div class="row">El objetivo de esta sección del documento es presentar el plan de pruebas seguido, 
incluyendo los diferentes tipos de pruebas que se han realizado. 

<P>
En primer lugar se describe la estrategia de pruebas seguida. Para ello se describe 
el alcance de estas y el procedimiento de pruebas de regresión realizado. 

<P>
Otro aspecto tratado es la descripción del entorno que se deberá utilizar para la
realización de las pruebas. Esto incluye los requisitos de software y hardware necesarios. 

<P>
Además se incluyen los perfiles y participantes necesarios para llevar a cabo los casos 
de prueba. Esto son los roles desde los que se llevarán a cabo las pruebas.

<P>
Por último se documentan las diferentes pruebas realizadas según el tipo al que estas pertenecen.

<P>

<H1><A NAME="SECTION00030000000000000000">
Estrategia</A>
</H1>
Las pruebas llevadas a cabo comprenden toda la funcionalidad del sistema. En cada iteración del ciclo de
vida se realizan pruebas relativas a las funcionalidades comprendidas en la misma. 

<P>
Para el diseño de las pruebas se ha tomado un enfoque funcional o de caja negra, centrada en la 
especificación de las funciones, la entrada y salida. La técnica utilizada consiste en definir 
los casos de pruebas a partir de clases de equivalencias:

<P>

<OL>
<LI>Identificar las restricciones de formato y contenido de los datos de entrada.
</LI>
<LI>A partir de las restricciones identificar las clases de equivalencias. Contemplando tanto 
datos válidos como erróneos.
</LI>
<LI>Se identifican y definen los casos de prueba a partir de las clases de equivalencias.
</LI>
</OL>

<P>
Para asegurar la estabilidad en el resultado de las pruebas realizadas en cada iteración, se ha implementado un mecanismo
que lleve a cabo las pruebas de forma regresiva, ejecutándose todo el conjunto de estas cada vez que una nueva funcionalidad 
del software es desarrollada. 

<P>
Además de realizar pruebas funcionales en cada iteración, se han realizado una serie de pruebas no funcionales. 
Esta comprende aquellas que aseguran que se cumplen los requisitos no funcionales.

<P>

<H1><A NAME="SECTION00040000000000000000">
Entorno de pruebas</A>
</H1>
En este punto se define el entorno utilizado para las pruebas, tanto a nivel de software como a nivel de hardware. 

<P>

<H2><A NAME="SECTION00041000000000000000">
Hardware</A>
</H2>
Para las pruebas se ha tomado un PC de características medias, en el momento de la realización del proyecto. Este se conforma de:

<P>
<DL>
<DT><STRONG>CPU:</STRONG></DT>
<DD>Intel Core i5-4460 3.2Ghz 
</DD>
<DT><STRONG>Disco Duro:</STRONG></DT>
<DD>1TB Western/Seagate
</DD>
<DT><STRONG>Memoria Ram:</STRONG></DT>
<DD>4GB DDR3 1333 PC3-10600 CL9 Kingston
</DD>
<DT><STRONG>Placa Base:</STRONG></DT>
<DD>Gigabyte GA-H81M-S2H   
</DD>
<DT><STRONG>Tarjeta gráfica:</STRONG></DT>
<DD>1GB Integrada Intel 
</DD>
</DL>

<P>

<H2><A NAME="SECTION00042000000000000000">
Software</A>
</H2>
Para las pruebas se ha utilizado un sistema GNU/Linux, instalado y configurado desde una distribución de paquetes 
Debian 8 Jessie. 

<P>
<DL>
<DT><STRONG>Sistema operativo:</STRONG></DT>
<DD>GNU/Linux 
</DD>
<DT><STRONG>Distribución de paquetes:</STRONG></DT>
<DD>Debian Jessie 8
</DD>
<DT><STRONG>Entorno gráfico:</STRONG></DT>
<DD>Xfce 4
</DD>
<DT><STRONG>Interprete de comando:</STRONG></DT>
<DD>Bash 4.3.8
</DD>
<DT><STRONG>Interprete OMI:</STRONG></DT>
<DD>OMI 0.1
</DD>
</DL>

<P>

<H1><A NAME="SECTION00050000000000000000">
Roles</A>
</H1>
Las pruebas se han llevado a cabo desde la perspectiva del único rol que interactuará con el sistema correspondiente al usuario que 
normalmente será un programador que hará uso del mismo.

<P>
El usuario programador hace uso integro del sistema en función a los programas que desarrolle en el lenguaje. Un único programa, o conjunto finito de estos no 
son suficientes para probar todos los aspectos del sistema. Así aunque las pruebas son llevadas a cabo desde un perfil programador, estas no constituyen programas 
completos con un objetivo específico, sino baterías de pruebas que pretenden probar cada aspecto funcional del sistema. 

<P>

<H1><A NAME="SECTION00060000000000000000">
Niveles de pruebas</A>
</H1>
Las pruebas se presentan en distintos niveles, según el tipo de prueba realizado. Dado la gran cantidad de pruebas estas en su mayoría han sido automatizadas, presentándose
junto al sistema y siendo una característica más del mismo, la cual es recomendable ejecutar tras cada instalación. 

<P>

<H2><A NAME="SECTION00061000000000000000">
Pruebas unitarias</A>
</H2>
Son pruebas llevadas a cabo sobre cada artefacto o pieza software producido en cada iteración del ciclo de desarrollo. Estas aseguran la correcta implementación
de las piezas desarrolladas, comprobando que están libre de errores y que cada entrada es procesada correctamente. Además cada caso de prueba se ha estructurado en función 
los tipos de entradas para una mejor organización de las mismas. 

<P>
Las pruebas unitarias están recogidas en un subsistema de la aplicación que automatizan su ejecución y asegura que son llevadas a cabo de forma regresiva. 

<P>
A continuación se expone algunos ejemplos de las pruebas unitarias realizadas:

<P>

<H3><A NAME="SECTION00061100000000000000">
Asignación de booleanos</A>
</H3>
Estos casos de prueba se centran en el operador asignación cuando el elemento asignado es de valor boolenano.

<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 a = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Asignación sobre la variable <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> el valor booleano true.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> tiene el valor true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> tiene el valor true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 a = false;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Asignación sobre la variable <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> el valor booleano false.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> tiene el valor false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> tiene el valor false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 for (i = 0; i &lt; 10; ++i) 
   a = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A la variable <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> se le asigna el valor booleano true en cada iteración del bucle
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> tiene el valor true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> tiene el valor true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 a = b = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A la variable <SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> se le asigna el valor booleano true, el valor de <SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> es asignado a <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN>
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Tanto <SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> como <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> tienen el valor true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Tanto <SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> como <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> tienen el valor true.
	
</DD>

<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 array[0] = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A el array <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> se le asigna en el índice 0 el valor true
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> contiene en la para la clave 0 el valor true. Si <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> no existe es creado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> contiene en la para la clave 0 el valor true. Si <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> no existe es creado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 array[1] = true
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A el array <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> se le asigna en el índice 1 el valor false
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> contiene en la para la clave 1 el valor false. Si <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> no existe es creado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> contiene en la para la clave 1 el valor false. Si <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> no existe es creado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 for (i = 0; i &lt; 10; ++i) 
   array[i] = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A el array <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> se le asigna el valor true a los índices que van desde 0 a 9.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> contiene en la para las claves del 0 al 9 el valor true. Si <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> no existe es creado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD><SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> contiene en la para las claves del 0 al 9 el valor true. Si <SPAN CLASS="MATH"><IMG
 WIDTH="52" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/test/img5.png"
 ALT="$array$"></SPAN> no existe es creado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 str = "ABCDEF"; 
 str[0] = false;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A la cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> se le asigna en la posición 0 el valor false.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>La cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> queda con el ínice <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img7.png"
 ALT="$0$"></SPAN> con el valor false. La cadena resultante es "BCDEF".
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>La cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> queda con el índice <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img7.png"
 ALT="$0$"></SPAN> con el valor false. La cadena resultante es "BCDEF".
	
</DD>

<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 str = "ABCDEF"; 
 str[0] = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A la cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> se le asigna en la posición 0 el valor true.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>La cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> queda con el índice <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img7.png"
 ALT="$0$"></SPAN> con el valor true. La cadena resultante es "1BCDEF".
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>La cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> queda con el índice <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img7.png"
 ALT="$0$"></SPAN> con el valor true. La cadena resultante es "1BCDEF".
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 while (size str) 
   str[0] = false;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A la cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> se le asigna en la posición 0 el valor false, mientras que la cadena sea distinta a la cadena vacía.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>La cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> queda vacía.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>La cadena <SPAN CLASS="MATH"><IMG
 WIDTH="29" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img6.png"
 ALT="$str$"></SPAN> queda vacía.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 a = false; 
 b = &amp;a; 
 a = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> se le asigna el valor false, a <SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> se le asigna una referencia a <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN>, a <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> se le asigna el valor true.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Tanto el valor de <SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> como el de <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> es true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Tanto el valor de <SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img4.png"
 ALT="$b$"></SPAN> como el de <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> es true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 true = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A la constante true se le asigna la constante true.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Error asignación a constante.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Error asignación a constante.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 true = false;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A la constante true se le asigna la constante false.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Error asignación a constante.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Error asignación a constante.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 a = true = true;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>A a se le asigna el valor de asignar la constante true se le asigna la constante true.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Error asignación a constante. <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> permanece con el valor que tenía.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Error asignación a constante. <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/img3.png"
 ALT="$a$"></SPAN> permanece con el valor que tenía.
	
</DD>
</DL>
<P>

<H3><A NAME="SECTION00061200000000000000">
Operador de igualdad con operandos numéricos</A>
</H3>
Estos casos de prueba se enfoca en el operador de igualdad cuando las entradas son de tipo numéricas.

<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 0 == 0;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 0 y el segundo operando es  0.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 0 == 1;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 0 y el segundo operando es  1.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 1 == 0;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 1 y el segundo operando es  0.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 10 == 10;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 10 y el segundo operando es  10.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 10 == 2;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 10 y el segundo operando es  2.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 2 == 10;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 2 y el segundo operando es  10.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -12 == -12;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -12 y el segundo operando es  -12.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -12 == 12;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -12 y el segundo operando es  12.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 12 == -12;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 12 y el segundo operando es  -12.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 18.7 == 18.7;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 18.7 y el segundo operando es  18.7.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 18.7 == 18;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 18.7 y el segundo operando es  18.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 18 == 18.7;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 18 y el segundo operando es  18.7.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -18.7 == -18;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -18.7 y el segundo operando es  -18.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -18.69 == -18.7;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -18.69 y el segundo operando es  -18.7.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 18.069 == -18.0;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 18.069 y el segundo operando es  -18.0.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -11.7999999999999999 == -11.7999999999999999;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -11.7999999999999999 y el segundo operando es  -11.7999999999999999.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -11.7999999999999999 == -11.7999999999999991;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -11.7999999999999999 y el segundo operando es  -11.7999999999999991.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -11.7999999999999999 == -11.7999999999999998;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -11.7999999999999999 y el segundo operando es  -11.7999999999999998.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -11.7999999999999998 == -11.7999999999999999;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -11.7999999999999998 y el segundo operando es  -11.7999999999999999.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -11.79999999999999999 == -11.79999999999999998;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -11.79999999999999999 y el segundo operando es  -11.79999999999999998.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true. Aviso de precisión sobrepasada por representación numérica finita.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 -11.79999999999999999 == -11.8;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es -11.79999999999999999 y el segundo operando es  -11.8.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true. Aviso de precisión sobrepasada por representación numérica finita.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 999999999999999 == 1000000000000001;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 999999999999999 y el segundo operando es  1000000000000001.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 10000000000000001 == 10000000000000001;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 10000000000000001 y el segundo operando es  10000000000000001.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano true.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 10000000000000001 == 10000000000000002;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 10000000000000001 y el segundo operando es  10000000000000002.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 10000000000000002 == 10000000000000001;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 10000000000000002 y el segundo operando es  10000000000000001.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 10000000000000002 == 10000000000000001;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 10000000000000002 y el segundo operando es  10000000000000001.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 9999999999999999 == 100000000000000001;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 99999999999999999 y el segundo operando es  100000000000000001.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.  Aviso de precisión sobrepasada por representación numérica finita.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 100000000000000001 == 100000000000000002;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 100000000000000001 y el segundo operando es  100000000000000002.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.  Aviso de precisión sobrepasada por representación numérica finita.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 100000000000000001 == 100000000000000002;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Operador igualdad donde el primer operando es 100000000000000002 y el segundo operando es  100000000000000001.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Valor booleano false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Valor booleano true.  Aviso de precisión sobrepasada por representación numérica finita.
	
</DD>
</DL>
<P>

<H3><A NAME="SECTION00061300000000000000">
Definición y llamadas de funciones con cuerpo vacío</A>
</H3>

<P>
Los casos de pruebas expuestos a continuación comprenden la definión y posterior llamada de funciones con cuerpo vacío.

<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun () { } 
   empty_fun ();
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función sin parámetros y cuerpo vació. Llamada respetando el número de parámetros
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce resultado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce resultado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun () { } 
   empty_fun ("param");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función sin parámetros y cuerpo vació. Llamada sin respetar el número de parámetros (más de los definidos). 
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param) { } 
   empty_func ("param");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con un único parámetro y cuerpo vació. LLamada respetando número de parámetros.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param) { } 
   empty_func ();
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con un único parámetro y cuerpo vació. LLamada sin respetar el número de parámetros (menos de los definidos).
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param) { } 
   empty_func ("param1", "param2");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con un único parámetro y cuerpo vació. LLamada sin respetar el número de parámetros (más de los definidos).
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   param = "param";
   function empty_fun (&amp;param) { } 
   empty_func (param);
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con un único parámetro pasado por referencia y cuerpo vació. Llamada dando una variable como valor de la referencia.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce resultado alguno.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce resultado alguno.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   param = {"param"};
   function empty_fun (&amp;param) { } 
   empty_func (param[0]);
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con un único parámetro pasado por referencia y cuerpo vació. Llamada dando la posición de un array como valor de la referencia.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce resultado alguno.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce resultado alguno.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (&amp;param) { } 
   empty_func (param);
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con un único parámetro pasado por referencia y cuerpo vació. Llamada dando una variable no definida como valor de la referencia.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce resultado alguno.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce resultado alguno.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (&amp;param) { } 
   empty_func ("const");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con un único parámetro pasado por referencia y cuerpo vació. Llamada dando una constante como valor de la referencia.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de constante como referencia.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de constante como referencia.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1, param2) { } 
   empty_func ("param1", "param2");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros y cuerpo vació. Llamada respetando el número de parámetros.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1, param2) { } 
   empty_func ("param1");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros y cuerpo vació. Llamada sin respetar el número de parámetros (menos de los definidos). 
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto. 
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1, param2) { } 
   empty_func ("param1", "param2", "param3");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros y cuerpo vació. Llamada sin respetar el número de parámetros (más de los definidos). 
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto. 
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1, param2 = "default") { } 
   empty_function ("param1", "param2");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros, uno con valor por defecto, y cuerpo vació. Llamada facilitando todos los parámetros.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1, param2 = "default") { } 
   empty_function ("param1");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros, uno con valor por defecto, y cuerpo vació. Llamada facilitando los parámetros que no tienen valor por defecto.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1, param2 = "default") { } 
   empty_function ();
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros, uno con valor por defecto, y cuerpo vació. Llamada sin facilitar los parámetros que no tienen valor por defecto.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1, param2 = "default") { } 
   empty_function ("param1", "param2", "param3");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros, uno con valor por defecto, y cuerpo vació. Llamada sin respetar el número de parámetros (más de los definidos). 
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1 = "default", param2 = "default") { } 
   empty_fun ("param1", "param2");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros, todos con valor por defecto, y cuerpo vació. Llamada dando valor a todos los parámetros
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1 = "default", param2 = "default") { } 
   empty_fun ("param1");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros, todos con valor por defecto, y cuerpo vació. Llamada dando valor a algunos de los parámetros
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1 = "default", param2 = "default") { } 
   empty_fun ();
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros, todos con valor por defecto, y cuerpo vació. Llamada tomando valor por defecto de todos los parámetros.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado. 
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada no produce ningún resultado.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function empty_fun (param1 = "default", param2 = "default") { } 
   empty_fun ("param1", "param2", "param3");
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de función con dos parámetros, todos con valor por defecto, y cuerpo vació. Llamada sin respetar el número de parámetros (más de los definidos).
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se define la función especificada y se asocia al identificador dado. La llamada produce un error de número de parámetros incorrecto.
	
</DD>
</DL>
<P>

<H2><A NAME="SECTION00062000000000000000">
Pruebas de integración</A>
</H2>
Las prueba de integración son llevadas a cabo tras iteración del ciclo de vida. Incluyen casos de prueba correspondiente a la interacción de varios módulos o artefactos, desarrollados 
en la misma interacción del ciclo de desarrollo o anteriores. En este tipo de pruebas se ha de repasar las características desarrolladas en iteraciones anteriores con el objetivo de localizar errores en la integración 
de los módulos desarrollados con el resto del sistema.

<P>
En esta sección se recogen algunos casos de pruebas de integración. Junto el software se facilita un sistema de pruebas que comprueba automáticamente todos los casos.

<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   &lt;&lt; 22 / 2 + 8 - 5 * 2;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Impresión de expresión aritmética compuesta de varios operadores y operandos todos constantes.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se ha de imprimir en pantalla el resultado de la expresión: 9.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se imprime en pantalla el resultado de la expresión: 9.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   array = {22};
   var = 5;
   &lt;&lt; array[0] / 2 + 8 - var * 2;
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Impresión de expresión aritmética compuesta de varios operadores, algunos operandos variables y/o posiciones de array.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se ha de imprimir en pantalla el resultado de la expresión: 9.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se imprime en pantalla el resultado de la expresión: 9.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function const2 () {
      return 2;
   }
   array = {22};
   var = 5;
   &lt;&lt; array[0] / const2 () + 8 - var * const2 ();
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Impresión de expresión aritmética compuesta de varios operadores, algunos operandos variables, llamadas a funciones y/o posiciones de array.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se ha de imprimir en pantalla el resultado de la expresión: 9.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se imprime en pantalla el resultado de la expresión: 9.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   &lt;&lt; !((true &amp;&amp; true) || false );
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Impresión de expresión booleana compuesta de varios operadores y operandos todos constantes.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se ha de imprimir en pantalla el resultado de la expresión: false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se imprime en pantalla el resultado de la expresión: false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   array = {true};
   var = true;
   &lt;&lt; !((array [0] &amp;&amp; var) || false );
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Impresión de expresión booleana compuesta de varios operadores, algunos operandos variables y/o posiciones de array.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se ha de imprimir en pantalla el resultado de la expresión: false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se imprime en pantalla el resultado de la expresión: false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
   function identity (param) {
      return param;
   }
   array = {true};
   var = true;
   &lt;&lt; !((array [0] &amp;&amp; var) || identity (false));
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Impresión de expresión booleana compuesta de varios operadores, algunos operandos variables, llamadas a función y/o posiciones de array.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Se ha de imprimir en pantalla el resultado de la expresión: false.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Se imprime en pantalla el resultado de la expresión: false.
	
</DD>
</DL>
<P>
<DL>
<DT><STRONG>Entrada:</STRONG></DT>
<DD>
<BR><PRE>
 class fac {
  function factorial (a) {
    fac = 1;
    this-&gt;recursiva (a, fac);
    return fac;
  }
  private function recursiva (a, &amp;factorial){
    if (a &gt; 0){
      factorial *=  a;
      this-&gt;recursiva (a - 1, factorial);
    } 
  }
 }
 f = new fac ();
 &lt;&lt; f-&gt;factorial (4);
</PRE>
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Definición de clases con métodos públicos y privados. Paso de parámetros por referencia. Operadores aritméticos.
		
</DD>
<DT><STRONG>Salida esperada:</STRONG></DT>
<DD>Calcula el factorial de 4 de forma recursiva: 24.
		
</DD>
<DT><STRONG>Salida obtenida:</STRONG></DT>
<DD>Calcula el factorial de 4 de forma recursiva: 24.
	
</DD>
</DL>
<P>

<H2><A NAME="SECTION00063000000000000000">
Pruebas funcionales del sistema</A>
</H2>
Este tipo de pruebas tienen como objetivo comprobar la funcionalidad del sistema. La funcionalidad principal que debe cumplir el interprete 
es recibir un programa en forma de código fuente, interpretarlo y producir el resultado esperado.

<P>
Para comprobar que el sistema cumple la funcionalidad para el que fue diseñado se han realizado una serie de programas tipos, recogiendo diversos estilos de 
programación, y de una naturaleza distinta. Estos programas han sido codificados en el lenguaje reconocido por el intérprete y se han realizado distintas comprobaciones 
sobre los mismos.

<P>

<H3><A NAME="SECTION00063100000000000000">
Calculadora</A>
</H3>
Este programa representa una calculadora sencilla en la que se le pide al usuario dos operándos numéricos y una operación (suma, resta, producto o cociente). El 
programa muestra el resultado de la operación. El programa se ejecuta hasta que la operación dada no es reconocida. 
<BR>
<P>
<PRE>
#!/usr/local/bin/omi
#Calculadora sencilla.
while ( true ) {
   &lt;&lt; "=======================";
   &lt;&lt; "Calculadora";
   &lt;&lt; "Dame un numero";
   &gt;&gt; a;
   &lt;&lt; "Dame otro";
   &gt;&gt; b;
   &lt;&lt; "Dame una operacion [0=&gt;suma], [1=&gt;resta], [2=&gt;multi], [3=&gt;divide], [otro=&gt;sale]"; 
   &gt;&gt; op;
   if (op == 0) 
      &lt;&lt; a &lt;&lt; " + " &lt;&lt; b &lt;&lt; " = " &lt;&lt; ( a + b ); 
   elif (op == 1) 
      &lt;&lt; a &lt;&lt; " - " &lt;&lt; b &lt;&lt; " = " &lt;&lt; (a - b);
   elif (op == 2) 
      &lt;&lt; a &lt;&lt; " * " &lt;&lt; b &lt;&lt; " = " &lt;&lt; (a * b);
   elif (op == 3) {
      if (op == 0)
         &lt;&lt; "Error: no es posible dividir entre 0";
      else 
         &lt;&lt; a &lt;&lt; " / " &lt;&lt; b &lt;&lt; " = " &lt;&lt; (a / b);
   }
   else {
      &lt;&lt; "Adios";
      break;
   }
}
</PRE>

<P>

<H3><A NAME="SECTION00063200000000000000">
Sistema de cuestionarios</A>
</H3>
El siguiente programa representa un sistema de cuestionarios. Es en si mismo un DSL (lenguaje específico de dominio) definido de forma 
interna, por lo que presenta una estructura y gramática similar al lenguaje reconocido por el intérprete. 

<P>
Un cuestioanrios se define mediante preguntas y posibles respuestas. Cada pregunta presenta una valor, la suma de los valores de todas las preguntas 
se corresponde con el valor del cuestionario. El usuario que realice el cuestionario sacará una nota que se corresponderá con una parte del total según las preguntas
que responda correctamente. 

<P>
Cada pregunta del cuestionario tendrá una serie de posibles respuestas, las respuestas pueden ser de dos tipos:

<P>
<DL>
<DT><STRONG>De selección:</STRONG></DT>
<DD>En este caso tras la pregunta se dará una serie de respuestas acompañadas de un valor que indique si es correcta o falsa. Para una misma pregunta pueden
existir más de una respuesta correcta. En la ejecución del cuestionario al usuario se le permitirá eliguir entre todas las respuestas aquella (solo una) que considere es correcta.
</DD>
<DT><STRONG>De texto:</STRONG></DT>
<DD>En este caso tras la pregunta se dará una serie de respuestas todas correctas. En la ejecución del cuestionario se le permitirá al usuario introducir textualmente
la solución, y solo en el caso de que se coincida con alguna de las repuesta esta será dada como correcta.
</DD>
</DL>

<P>
Este programa ha sido modelado usando programación orientada a objetos. Se presenta un fichero de código fuente por cada clase que conforma el sistema de cuestionarios, otro fichero 
la definición del DSL junto con el flujo principal que conforma el motor de cuestionarios, y otro fichero que se corresponde con un custionario de ejemplo.

<P>
A continuación el diagrama de clases que ilustrna el diseño del sistema:

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="629" HEIGHT="204" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/sdl.png"
 ALT="Image sdl"> 
<BR>
</DIV>

<P>
file: quiz_system.omi
<PRE>
#!/usr/local/bin/omi
#Sistema de cuestionarios
#=======================================================================
include "quiz.class.omi";
#=======================================================================
global quiz;
#=======================================================================
#Funciones del DSL 
~multichoice (text, rating) {
   quiz-&gt;add_question (new MultiChoice (text, rating));
}

~text (text, rating) {
   quiz-&gt;add_question (new Text (text, rating));
}

~option (text, correct = null) {
   quiz-&gt;last_question()-&gt;add_option(new Option (text, correct));
}
#=======================================================================
if (args[1]){
   title = args[2]?:"Sin titulo";
   &lt;&lt; title;
   quiz =  new Quiz (title);
   include args[1];
   quiz-&gt;run_quiz();
}
else
   &lt;&lt; "Debe indicar un cuestionario";
#=======================================================================
</PRE>
file: quiz.class.omi
<PRE>
#quiz.class.omi
#=======================================================================
include "question.class.omi";
#=======================================================================
class Quiz {
   name = '';
   questions = {};
   ~ Quiz (name) {
      this-&gt;name = name;
   }
   ~ add_question (question) {
      this-&gt;questions[size this-&gt;questions] = question;
   }
   ~ last_question () {
      return this-&gt;questions [(size this-&gt;questions) - 1];
   }
   ~ run_quiz () {
      count = 0;
      total = 0;
      $(this-&gt;questions) {
         if ($-&gt;ask ()) count += $-&gt;rating;
         total += $-&gt;rating;
      }
      &lt;&lt; "Tienes " &lt;&lt; count &lt;&lt; " respuestas correctas de " &lt;&lt; total;
   }
}
#=======================================================================
</PRE>

<P>
file: question.class.omi
<PRE>
#question.class.omi
#=======================================================================
include "option.class.omi";
#=======================================================================
class Question {
   title = "";
   rating = 0;
   options = {};
   ~ Question (title, rating) {
      this-&gt;title = title;
      this-&gt;rating = rating;
   }
   ~ add_option (option) {
      this-&gt;options [(size this-&gt;options)] = option;
   }
}
#-----------------------------------------------------------------------
class Text extends Question {
   ~ Text (title, rating) {
      this-&gt;Question (title, rating);
   }
   ~ ask () {
      &lt;&lt; "";
      &lt;&lt; this-&gt;title &lt;&lt; " (" &lt;&lt; this-&gt;rating &lt;&lt; ")";
      &lt;&lt; "Introducir respuesta: ";
      &gt;&gt; ans;
      n = size (this-&gt;options);
      for (i = 0; i &lt; n; ++i) {
         if (ans == this-&gt;options[i]-&gt;title)
            return true;
      }
      return false;
   }
}
#-----------------------------------------------------------------------

class MultiChoice extends Question {
   ~ MultiChoice (title, rating) {
      this-&gt;Question (title, rating);
   }
   ~ ask () {
      &lt;&lt; this-&gt;title &lt;&lt; " (" &lt;&lt; this-&gt;rating &lt;&lt; ")";
      count = 0;
      $(this-&gt;options) &lt;&lt;  (++count) &lt;&lt; " - " &lt;&lt; $-&gt;title;
      &lt;&lt; "Introducir respuesta: ";
      &gt;&gt; ans;
      return (this-&gt;options[ans - 1]) &amp;&amp; this-&gt;options[ans - 1]-&gt;correct;
   }
}
#=======================================================================
</PRE>

<P>
file: option.class.omi
<PRE>
#option.class.omi
#=======================================================================
class Option {
   title = "";
   correct = "";
   ~ Option (title, correct){
      this-&gt;title = title;
      this-&gt;correct = correct;
   }
}
#=======================================================================
</PRE>

<P>
input file: quiz.q
<PRE>
#Ejemplo de cuestionario.
multichoice("Cuanto tiempo duro la guerra de los 100 annos?", 2.5);
option (100, false);
option (116, true);
option (90, false);
option (102, false);
multichoice("Un simil es ...", 2.5);
option ("Una comparacion", true);
option ("Una duda", false);
option ("Un aparato para medir el tiempo", false);
text ("En que provincia desemboca el rio Gualquivir?", 2.5);
option("Cadiz", true);
option("cadiz", true);
</PRE>

<P>
Para ejecutar el cuestionario en una terminal de comandos:

<P>
<PRE>
prompt$ ./quiz_system.omi quiz.q "Cuestionario"
</PRE>

<P>

<H3><A NAME="SECTION00063300000000000000">
Tic-Tac-Toe</A>
</H3>
El programa que se presenta a continuación se corresponde con el juego del Tic-Tac-Toe. Este juego, también llamado 
el juego de tres en raya, enfrenta a dos jugadores en una cuadrícula de 3x3. Cada jugador se corresponde con un símbolo, y
se turnan para ponerlo o dibujarlo en una posición vacía de la cuadrícula. El jugador que consiga poner tres de sus símbolos en línea
gana la partida. 

<P>
No es difícil darse cuenta que si ambos jugadores utilizan la estrategia más óptima el juego terminará en empate. Al ser un juego sencillo se 
utiliza para enseñar conceptos de teoría de juegos y, dentro de la inteligencia artificial, la búsqueda de árboles de juego.

<P>
El programa en primer lugar solicita el nombre y tipo de los jugadores, pudiéndose ser estos humanos o máquinas. Luego turno a turno va solicitando 
a cada jugador una posición vacía de la cuadrícula en la que efectuar el movimiento, esto se hace hasta que se da una línea ganadora o hasta que se
completa la cuadrícula. 

<P>
Para determinar el movimiento o acción llevada en cada turno se prosigue de la siguiente forma:

<UL>
<LI>Si el jugador es humano el sistema solicita la posición (fila y columna) en la que poner el símbolo. 
</LI>
<LI>Si el jugador es de tipo máquina se utiliza el algoritmo recursivo minimax para calcular el mejor 
movimiento a partir de busquedas en árboles de juego y la estado del tablero. Esto se hace con la salvedad de los primeros turnos, ya 
que en estos la estratégia óptima es fija.
</LI>
</UL>

<P>
El programa se divide en tres módulos, cada uno correspondiente a un fichero. En un fichero se disponen las funciones de entrada y salida, tales como
solicitar los datos de los jugadores, imprimir el tablero, etc. En otro fichero se encuentran las funciones de inteligencia artificial para el caso de 
jugadores de tipo máquina. Y en otro se encuentra el flujo principal correspondiente al bucle de juego.

<P>
file: IO.omi
<PRE>
#IO.omi
#=======================================================================
~IOJugadores () {
   jugadores = {};
   for (i = 1; i &lt;= 2; ++i) {
      &lt;&lt; "Nombre Jugador " &lt;&lt; i;
      &gt;&gt; nombre;
      &lt;&lt; "Tipo Jugador " &lt;&lt; i &lt;&lt; " [ 0 =&gt; Humano, otro =&gt; Maquina ]";
      &gt;&gt; tipo;
      if (tipo != 0) 
         tipo = 1;
      jugadores [] = { 
         'nombre' : nombre,
         'tipo' : tipo,
         'token' : (( i == 1)?1:-1),
      };
   }
   return jugadores; 
}
#-----------------------------------------------------------------------
~ IOTablero (tablero) {
   for (i = 0; i &lt; 3; ++i) 
      &lt;&lt; IOToken(tablero[i][0]) &lt;&lt; " or " 
         &lt;&lt; IOToken(tablero[i][1]) &lt;&lt; " or " 
         &lt;&lt; IOToken(tablero[i][2]);
}
#-----------------------------------------------------------------------
~ IOToken (pos) {
   if (pos == 1) 
      return 'X';
   elif (pos == -1)
      return 'O';
   else
      return '#';
}
#-----------------------------------------------------------------------
~ IOMover (tablero) {
   do {
      &lt;&lt; "Dame la fila";
      &gt;&gt; row;
      &lt;&lt; "Dame la columna";
      &gt;&gt; col;
   }while (tablero[row][col] !== 0);
   return {row, col};
}
#-----------------------------------------------------------------------
~IOGanador (jugadores, ganador) {
   if (ganador == 1 ){
      &lt;&lt; "El ganador es " &lt;&lt; jugadores[0]["nombre"];
   }elif (ganador == -1){
      &lt;&lt; "El ganador es " &lt;&lt; jugadores[1]["nombre"];
   }else{
      &lt;&lt; "La partida ha quedado en empate";
   }
}

#=======================================================================
</PRE>

<P>
file: AI.omi
<PRE>
#AI.omi
#=======================================================================
~primerosMov (tablero) {
   if (!tablero[1][1]) 
      return {1,1};
   do {
      col = row = time () % 2;
      if (row == 1) row = 2;
      if (col == 1) col = 2;
   }while (tablero[row][col] !== 0);
   return {row, col};
}
#-----------------------------------------------------------------------
~ miniMax (A, turno){
	mejor = turno * -1; 
   minMov = 9; 
   poda = 1;
   Mov = 0;
   posicion = {0, 0};
	if (!(t_ganador = procesarTablero (A)) &amp;&amp; !tableroLleno (A)){
		for (cont = 0; cont &lt; 3 &amp;&amp; poda; cont ++)
			for (cont2 = 0; cont2 &lt; 3 &amp;&amp; poda; cont2 ++){
				if ( A [cont] [cont2] == 0){
					A [cont] [cont2] = turno;
					actual = miniMax_R (A, turno * -1,0,Mov);
					if (turno == 1 ){
						if ( actual  &gt;= mejor &amp;&amp; Mov &lt;= minMov){
							mejor =actual;
							posicion [0] = cont;
							posicion [1] = cont2;
							if (mejor == turno){
								minMov = Mov;
								if (mejor == 1 &amp;&amp; minMov == 0)
									poda = 0;
							}
						}
					} else
						if ( actual &lt;= mejor &amp;&amp; Mov &lt;= minMov){
							mejor =actual;
							posicion [0] = cont;
							posicion [1] = cont2;
							if (mejor == turno){
								minMov = Mov;
								if (mejor == 1 &amp;&amp; minMov == 0)
									poda = 0;
							}
						}
					A [cont] [cont2] = 0;
				}
			}
	}
   return posicion;
}
#-----------------------------------------------------------------------
~ miniMax_R (&amp;A, turno, nMov, &amp;Mov){
	mejor = turno * -1;
   poda = 1; 
   minMov = 9 ;
	if (!(t_ganador = procesarTablero (A)) &amp;&amp; !tableroLleno (A)){
		for (cont = 0; cont &lt; 3 &amp;&amp; poda; cont ++){
			for (cont2 = 0; cont2 &lt; 3 &amp;&amp; poda; cont2 ++){
				if ( A [cont] [cont2] == 0){
					A [cont] [cont2] = turno;
					actual = miniMax_R (A, turno * -1, nMov +1, Mov);
					if (turno == 1 ){
						if ( actual  &gt;= mejor &amp;&amp; Mov &lt;= minMov){
							mejor =actual;
							if (mejor == turno){ 		
								minMov = Mov;
								if (mejor == 1 &amp;&amp; minMov == 0)
									poda = 0;
							}
						}
					} else
						if ( actual &lt;= mejor &amp;&amp; Mov &lt;= minMov){
								mejor =actual;
								if (mejor == turno){ 	
									minMov = Mov;
									if (mejor == 1 &amp;&amp; minMov == 0)
										poda = 0;
							}
						}
					A [cont] [cont2] = 0;
				}
			}
		}
		Mov = minMov;
		return mejor;
	}
	Mov = nMov;
	return  t_ganador;
}
#-----------------------------------------------------------------------
~procesarTablero (A) {
   ganador = 0;
   cont = 0;
	for (cont = 0; cont &lt; 3 &amp;&amp; ganador == 0; cont ++){
		if (A [cont] [0] == A[cont] [1] &amp;&amp; A [cont] [1] == A [cont] [2])
			ganador = A [cont] [1];
   }
	for (cont = 0; cont &lt; 3 &amp;&amp; ganador == 0; cont ++)
		if (A [0] [cont] == A [1] [cont] &amp;&amp; A [1] [cont] == A [2] [cont])
			ganador = A [0] [cont];
	if (A [0][0] == A [1][1] &amp;&amp; A [1][1] == A [2][2]  &amp;&amp; ganador == 0 )
		ganador = A [0][0];
	if (A [0][2] == A [1][1] &amp;&amp; A [1][1] == A [2][0] &amp;&amp; ganador == 0)
		ganador = A [0][2];
	return ganador;
}
#-----------------------------------------------------------------------
~ tableroLleno (A){
	resp = 1;
	for (cont = 0; cont &lt; 3 &amp;&amp; resp; cont ++)
		for (cont2 = 0; cont2 &lt; 3 &amp;&amp; resp; cont2 ++)
			resp = A [cont] [cont2] != 0;
	return resp;
}
#=======================================================================
</PRE>

<P>
file: tictactoe.omi
<PRE>
#!/usr/local/bin/omi
#=======================================================================
include "IO.omi";
include "AI.omi";
#-----------------------------------------------------------------------
~juego () {
   tablero = {{0,0,0},{0,0,0},{0,0,0}};
   posicion = {0,0};
   turno = 0;
   jugadores = IOJugadores ();
   while (!(ganador = procesarTablero (tablero)) &amp;&amp; !tableroLleno (tablero)){
      &lt;&lt; "----------------------------------------------";
      IOTablero (tablero);
      &lt;&lt; "\nTurno " &lt;&lt; jugadores[turno%2]['nombre'];
      if (jugadores[turno%2]['tipo'] == 0) {
         posicion = IOMover (tablero);
      }else {
         &lt;&lt; "Calculando movimiento...";
         if (turno &lt;= 1) {
            posicion = primerosMov (tablero);
         }else {
            posicion = miniMax (tablero, jugadores[turno%2]['token']);
         }
      }
      tablero[posicion[0]][posicion[1]] = jugadores[turno%2]['token'];
      turno ++;
   }
   IOTablero (tablero);
   IOGanador (jugadores, ganador);
}
#-----------------------------------------------------------------------
juego ();
#======================================================================$
</PRE>

<P>

<H2><A NAME="SECTION00064000000000000000">
Pruebas no funcionales del sistema</A>
</H2>
Estas pruebas están enfocadas a comprobar que el sistema cumple con los requisitos 
no funcionales determinado en las fases de especificación.

<P>
El interprete debe presentar un rendimiento óptimo en cuanto tiempo de interpretación. 
Dado que su objetivo no es constituir una herramienta para la producción de softwatre este 
aspecto no es crítico, no obstante debe cumplir unos mínimos para que sea operativo.

<P>
Por otro lado un programa interpretado no puede excederse en la memoria física que ocupa. Para ello 
se debe medir la cantidad de memoria de las entidades que conforma el programa.

<P>
Además se debe asegurar dentro de unos márgenes que el intérprete está libre de vulnerabilidades 
y que no es posible hacer un uso indebido del mismo para explotar la plataforma sobre la que se
ejecuta o el propio sistema software.

<P>

<H3><A NAME="SECTION00064100000000000000">
Rendimiento de tiempo</A>
</H3>
Para comprobar que el rendimiento que ofrece el software en relación a los tiempos tomados para la interpretación 
se ha sometido al sistema a una serie benchmarks conocidos, comparando los resultados con los obtenidos con otros 
lenguajes de programación interpretados.

<P>
Se considera que el sistema supera las pruebas de rendimiento siempre y cuando el tiempo en pasar los benchmarks sea inferior al doble de
los lenguajes pensados para la producción software.

<P>

<H4><A NAME="SECTION00064110000000000000">
Fibonacci</A>
</H4>
Esta prueba conciste en medir el tiempo para dististas entradas de un programa que trata de calcular, de forma recursiva, 
el número correspondiente a una determinada posición de la sucesión de Fibonacci. 

<P>
A continuación el código fuente:

<P>
file: fibonacci.omi
<PRE>
#!/usr/local/bin/omi
#fibonacci.omi
#=======================================================================
~ fibonaci (n) {
   if (n == 1 || n == 2) 
      return 1;
   else 
      return fibonaci (n - 1) + fibonaci (n - 2); 
}
#-----------------------------------------------------------------------
&lt;&lt; fibonaci (args[1]);
#=======================================================================
</PRE>

<P>
Los tiempos obtenidos frente otros lenguajes son los siguientes: 

<P>

<UL>
<LI>OMI: 
<BR>    
   <BR>    <DIV ALIGN="CENTER">
<TABLE CELLPADDING=3 BORDER="1" ALIGN="CENTER">
<TR><TH ALIGN="LEFT"><B>Tamaño de entrada </B></TH>
<TH ALIGN="LEFT"><B>Tiempo (s) </B></TH>
</TR>
<TR><TD ALIGN="LEFT">10</TD>
<TD ALIGN="LEFT">0.020</TD>
</TR>
<TR><TD ALIGN="LEFT">20</TD>
<TD ALIGN="LEFT">0.104</TD>
</TR>
<TR><TD ALIGN="LEFT">30</TD>
<TD ALIGN="LEFT">8.720</TD>
</TR>
</TABLE>
</DIV>
<BR>
   
</LI>
<LI>PHP: 
<BR>   <BR>    <DIV ALIGN="CENTER">
<TABLE CELLPADDING=3 BORDER="1" ALIGN="CENTER">
<TR><TH ALIGN="LEFT"><B>Tamaño de entrada </B></TH>
<TH ALIGN="LEFT"><B>Tiempo (s) </B></TH>
</TR>
<TR><TD ALIGN="LEFT">10</TD>
<TD ALIGN="LEFT">0.043</TD>
</TR>
<TR><TD ALIGN="LEFT">20</TD>
<TD ALIGN="LEFT">0.054</TD>
</TR>
<TR><TD ALIGN="LEFT">30</TD>
<TD ALIGN="LEFT">5.622</TD>
</TR>
</TABLE>
</DIV>
<BR>
   
</LI>
<LI>Python: 
<BR>   <BR>    <DIV ALIGN="CENTER">
<TABLE CELLPADDING=3 BORDER="1" ALIGN="CENTER">
<TR><TH ALIGN="LEFT"><B>Tamaño de entrada </B></TH>
<TH ALIGN="LEFT"><B>Tiempo (s) </B></TH>
</TR>
<TR><TD ALIGN="LEFT">10</TD>
<TD ALIGN="LEFT">0.023</TD>
</TR>
<TR><TD ALIGN="LEFT">20</TD>
<TD ALIGN="LEFT">0.029</TD>
</TR>
<TR><TD ALIGN="LEFT">30</TD>
<TD ALIGN="LEFT">4.963</TD>
</TR>
</TABLE>
</DIV>
<BR>
   
</LI>
</UL>

<P>

<H4><A NAME="SECTION00064120000000000000">
N-body</A>
</H4>

<P>
El primer benchmark al que ha sido sometido el sistema se denomina ``n-body''. Este conciste en una simulación de un sistema dinámico de
partículas que se encuentran bajo la influencia de fuerzas físicas como la gravedad. 

<P>
El código fuente para la prueba es el siguiente: 

<P>
file: n-body.omi
<PRE>
#!/usr/local/bin/omi
#=======================================================================
~ energy(&amp;b) {
   e = 0.0;
   m = size (b);
   for (i=0; i &lt; m; ++i) {
       b1=b[i]; 
       e += 0.5*b1[6]*(b1[3]*b1[3]+b1[4]*b1[4]+b1[5]*b1[5]);
       for (j=i+1; j&lt;m; j++) {
         b2=b[j];
         dx=b1[0]-b2[0]; dy=b1[1]-b2[1]; dz=b1[2]-b2[2];
         e -= (b1[6]*b2[6])/sqrt(dx*dx + dy*dy + dz*dz);
       }
   }
   return e;
}

pi=3.141592653589793;
solar_mass=4*pi*pi;
days_per_year=365.24;

bodies = {
   {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, solar_mass }, //Sun
   { 
      4.84143144246472090, //Jupiter
      -1.16032004402742839,
      -0.103622044471123109,
      0.00166007664274403694 * days_per_year,
      0.00769901118419740425 * days_per_year,
      -0.0000690460016972063023 * days_per_year,
      0.0009.54791938424326609 * solar_mass
   },
   {
      8.34336671824457987,    // Saturn
      4.12479856412430479,
      -0.403523417114321381,
      -0.00276742510726862411 * days_per_year,
      0.00499852801234917238 * days_per_year,
      0.00002.30417297573763929 * days_per_year,
      0.000285885980666130812 * solar_mass
   },
   {
      12.8943695621391310, // Uranus
      -15.1111514016986312,
      -0.223307578892655734,
      0.00296460137564761618 * days_per_year,
      0.00237847173959480950 * days_per_year,
      -0.0000296589568540237556 * days_per_year,
      0.0000436624404335156298 * solar_mass
   },
   {
      15.3796971148509165, // Neptune
      -25.9193146099879641,
      0.179258772950371181,
      0.00268067772490389322 * days_per_year,
      0.00162824170038242295 * days_per_year,
      -0.0000951592254519715870 * days_per_year,
      0.0000515138902046611451 * solar_mass
   }
};

// offset_momentum
px=py=pz=0.0;
for (bodies as e) {
    px+=e[3]*e[6]; 
    py+=e[4]*e[6]; 
    pz+=e[5]*e[6];
} 
bodies[0][3] = -1 * (px) / solar_mass;
bodies[0][4] = -1 * (py) / solar_mass;
bodies[0][5] = -1 * (pz) / solar_mass;

pairs = {};
m=size(bodies);
for (i=0; i&lt;m; ++i) 
   for (j=i+1; j&lt;m; j++) 
      pairs[] = {bodies[i], bodies[j]};

n = args[1];

&lt;&lt; energy(bodies);

i=0; 
do {
   for (pairs as p) {
      a=p[0]; b=p[1];
      dx=a[0]-b[0]; dy=a[1]-b[1]; dz=a[2]-b[2];

      dist = sqrt(dx*dx + dy*dy + dz*dz);
      mag = 0.01/(dist*dist*dist);
      mag_a = a[6]*mag; mag_b = b[6]*mag;
	
      a[3]-=dx*mag_b; a[4]-=dy*mag_b; a[5]-=dz*mag_b;
      b[3]+=dx*mag_a; b[4]+=dy*mag_a; b[5]+=dz*mag_a;
    } 

    for (bodies as b) {
        b[0]+=0.01*b[3]; b[1]+=0.01*b[4]; b[2]+=0.01*b[5];
    } 

} while(++i&lt;n);

&lt;&lt; energy(bodies);
</PRE>

<P>
Los tiempos obtenidos frente otros lenguajes son los siguientes: 

<P>

<UL>
<LI>OMI: 
<BR>    
   <BR>    <DIV ALIGN="CENTER">
<TABLE CELLPADDING=3 BORDER="1" ALIGN="CENTER">
<TR><TH ALIGN="LEFT"><B>Tamaño de entrada </B></TH>
<TH ALIGN="LEFT"><B>Tiempo (s) </B></TH>
</TR>
<TR><TD ALIGN="LEFT">500.000</TD>
<TD ALIGN="LEFT">14.10</TD>
</TR>
<TR><TD ALIGN="LEFT">5.000.000</TD>
<TD ALIGN="LEFT">240.4</TD>
</TR>
<TR><TD ALIGN="LEFT">50.000.000</TD>
<TD ALIGN="LEFT">1243.02</TD>
</TR>
</TABLE>
</DIV>
<BR>
   
</LI>
<LI>PHP: 
<BR>   <BR>    <DIV ALIGN="CENTER">
<TABLE CELLPADDING=3 BORDER="1" ALIGN="CENTER">
<TR><TH ALIGN="LEFT"><B>Tamaño de entrada </B></TH>
<TH ALIGN="LEFT"><B>Tiempo (s) </B></TH>
</TR>
<TR><TD ALIGN="LEFT">500.000</TD>
<TD ALIGN="LEFT">7.10</TD>
</TR>
<TR><TD ALIGN="LEFT">5.000.000</TD>
<TD ALIGN="LEFT">69.00</TD>
</TR>
<TR><TD ALIGN="LEFT">50.000.000</TD>
<TD ALIGN="LEFT">719.66</TD>
</TR>
</TABLE>
</DIV>
<BR>
   
</LI>
<LI>Python: 
<BR>   <BR>    <DIV ALIGN="CENTER">
<TABLE CELLPADDING=3 BORDER="1" ALIGN="CENTER">
<TR><TH ALIGN="LEFT"><B>Tamaño de entrada </B></TH>
<TH ALIGN="LEFT"><B>Tiempo (s) </B></TH>
</TR>
<TR><TD ALIGN="LEFT">500.000</TD>
<TD ALIGN="LEFT">9.86</TD>
</TR>
<TR><TD ALIGN="LEFT">5.000.000</TD>
<TD ALIGN="LEFT">96.17</TD>
</TR>
<TR><TD ALIGN="LEFT">50.000.000</TD>
<TD ALIGN="LEFT">967.81</TD>
</TR>
</TABLE>
</DIV>
<BR>
   
</LI>
</UL>

<P>

<H3><A NAME="SECTION00064200000000000000">
Espacio de memoria</A>
</H3>
El espacio de meoria que ocupa un determinado programa en ejecución es de vital improtancia. La memoria es un recurso físico limitado, y los programas deben hacer un buen 
uso de la misma.

<P>
Dado que el interprete es una herramienta con la que se van a escribir otros programas, el uso de memoria que haga este influye en gran medida 
en la cantidad que ocuparán los programas con son interpretados. De esta forma si el interprete no hace un uso óptimo de la memoria los programas que este procesará
tampoco. 

<P>
Las unidades mínimas sobre las que opera el interprete son los nodos ejecutables. Así en primer lugar se va a medir cuánto ocupa los nodos ejecutables básicos y más comunes. Cabe decir
que la representación interna de los distintos tipos de datos puede ser configurada como opciones de compilación, es por ello que se presenta la medición en función las distintas 
configuraciones posibles, indicándose solo aquellas que presentan un esquema óptimo debido a factores como el alineamiento.

<P>
La longitud del alineamiento en todos los casos viene dado por el puntero a la tabla de métodos virtuales. Este elemento referencia a una tabla que indexa los 
métodos de los que dispone un objeto debido a la jerarquía de herencia con la que se definió. Al ser un puntero su tamaño dependerá de la arquitectura del equipo.

<P>

<P>

<H4><A NAME="SECTION00064210000000000000">
Nodos lógicos</A>
</H4>

<P>
En el siguiente diagrama se presenta la memoria ocupada por un nodo de tipo lógico según las distintas combinaciones para la representación interna de los datos:

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="616" HEIGHT="523" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/memorySpaceLogic.png"
 ALT="Image memorySpaceLogic"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00064220000000000000">
Nodos aritméticos</A>
</H4>

<P>
En el siguiente diagrama se presenta la memoria ocupada por un nodo de tipo aritmético según las distintas combinaciones para la representación interna de los datos:

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="652" HEIGHT="748" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/memorySpaceArith.png"
 ALT="Image memorySpaceArith"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00064230000000000000">
Nodos cadenas de caracteres</A>
</H4>

<P>
En el siguiente diagrama se presenta la memoria ocupada por un nodo de tipo cadena de caracteres según las distintas combinaciones para la representación interna de los datos:

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="615" HEIGHT="518" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/test/memorySpaceStr.png"
 ALT="Image memorySpaceStr"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00064300000000000000">
Seguridad</A>
</H3>

<P>
La seguidad digital de un empresa se debe comprobar en una serie de niveles, tal que se han de realiza auditorias internas, perimetrales, pruebas APT, etc. Sin embargo, el objetivo de
este punto es medir la calidad en función de la seguridad del software desarrollado. Así, para asegurar que la aplicación cumple un mínimo de seguridad se han realizado una serie de 
auditorías al software. 

<P>
En el tipo de pruebas realizadas solo se ha tenido en cuenta el software correspondiente al interprete, dejando fuera todo el sistema web que conforma la plataforma de distribución. Un 
sistema web se ve afectado por tipos de vulnerabilidades tales como DoS, XSS, CSRF, SQL injectión, sistemas de autentificación... Por otro lado en un software de escritorio, como 
puede ser el interprete, se ve afectado por otro tipos de vulnerabilidades comunes.

<P>
Las pruebas que se han realizado sobre el software se enfocan en la entrada del usuario y se pueden categorizar de la siguiente forma:

<P>

   <BR>    <DIV ALIGN="CENTER">
<TABLE CELLPADDING=3 BORDER="1" ALIGN="CENTER">
<TR><TD ALIGN="LEFT">Desbordamiento de buffer</TD>
</TR>
<TR><TD ALIGN="LEFT">Desbordamiento de buffer por variables de entorno</TD>
</TR>
<TR><TD ALIGN="LEFT">Desbordamiento de buffer por recursos binarios</TD>
</TR>
<TR><TD ALIGN="LEFT">Injección de código</TD>
</TR>
<TR><TD ALIGN="LEFT">Salto de directorio (path traversal)</TD>
</TR>
</TABLE>
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
