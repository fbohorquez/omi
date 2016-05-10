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
   <div class="title"><h1 style="font-size:25px;">Implantación del sistema</h1></div>
   <div class="list">

<UL CLASS="TofC">
<LI><A NAME="tex2html143"
  HREF="<?=URL;?>doc/manual#SECTION00020000000000000000">Introducción</A>
<LI><A NAME="tex2html144"
  HREF="<?=URL;?>doc/manual#SECTION00030000000000000000">Características</A>
<LI><A NAME="tex2html145"
  HREF="<?=URL;?>doc/manual#SECTION00040000000000000000">Requisitos previos</A>
<LI><A NAME="tex2html146"
  HREF="<?=URL;?>doc/manual#SECTION00050000000000000000">Uso del sistema</A>
<UL>
<LI><A NAME="tex2html147"
  HREF="<?=URL;?>doc/manual#SECTION00051000000000000000">Obtener OMI</A>
<LI><A NAME="tex2html148"
  HREF="<?=URL;?>doc/manual#SECTION00052000000000000000">Instalación</A>
<LI><A NAME="tex2html149"
  HREF="<?=URL;?>doc/manual#SECTION00053000000000000000">Intérprete</A>
<LI><A NAME="tex2html150"
  HREF="<?=URL;?>doc/manual#SECTION00054000000000000000">Referencias del lenguaje</A>
<LI><A NAME="tex2html151"
  HREF="<?=URL;?>doc/manual#SECTION00055000000000000000">Funciones del lenguaje</A>
<LI><A NAME="tex2html152"
  HREF="<?=URL;?>doc/manual#SECTION00056000000000000000">Extensiones del lenguaje</A>
<LI><A NAME="tex2html152"
  HREF="<?=URL;?>doc/manual#SECTION00057000000000000000">Arquitectura cliente/servidor</A>
<LI><A NAME="tex2html152"
  HREF="<?=URL;?>doc/manual#SECTION00058000000000000000">Descripción del proceso de interpretación</A>
<LI><A NAME="tex2html152"
  HREF="<?=URL;?>doc/manual#SECTION00059000000000000000">runTree</A>
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
            <div class="row">En esta sección se detallan las instrucciones de instalación y explotación del sistema

OMI, acrónimo de Open Modular Interpreter, es un lenguaje para la creación de `scripts' que presenta un propósito general y es de código abierto.
El objetivo del proyecto OMI es servir de guía en la aplicación práctica de la teoría de compiladores e intérpretes. Para ello presenta un caso práctico 
en el que se construye un lenguaje de programación moderno a partir de los conceptos teóricos de autómatas y lenguajes formales. 

<P>
La plataforma OMI representa un sistema software desarrollado para la comunidad académica. Pretende ser una herramienta utilizada en el aprendizaje de
los sistemas intérpretes y traductores modernos, además de cualquier otro basado en los conceptos sobre los que estos se construyen. 

<P>
La plataforma OMI se constituye mediante los siguientes elementos:

<P>

<UL>
<LI>Documentación completa del proceso aplicado en el desarrollo de un lenguaje de programación.
</LI>
<LI>Intérprete de un lenguaje de programación denominado OMI, el cual da nombre al proyecto.
</LI>
<LI>Aplicación web que permite consultar la documentación e interactuar con el intérprete. 
</LI>
</UL>

<P>
Este manual describe al lenguaje, las funciones que integra, y las características del intérprete. Además detalla cómo se 
estructura el contenido dentro de la aplicación web y las herramientas que la componen.

<P>

<H1><A NAME="SECTION00030000000000000000">
Características</A>
</H1>
OMI representa una plataforma constituida por una serie de herramientas. Estas ayudan al aprendizaje en la aplicación práctica de la teoría
de autómatas y lenguajes formales para el desarrollo de un lenguaje de programación moderno. Sus características son las siguientes:

<P>

<UL>
<LI>Intérprete OMI
   
<UL>
<LI>Abierto
</LI>
<LI>Modular
</LI>
<LI>Interactivo
</LI>
<LI>Configurable
</LI>
<LI>Paso de argumentos
</LI>
<LI>Ejecución en modo servidor
</LI>
<LI>Autodescriptivo.
   
</LI>
</UL>
</LI>
<LI>Lenguaje OMI
   
<UL>
<LI>Propósito general
</LI>
<LI>Interpretado
</LI>
<LI>Sintaxis simple y cercana a los lenguajes modernos
</LI>
<LI>Tipado dinámico y débil
</LI>
<LI>Tipos de datos simples y compuestos
</LI>
<LI>Referencia de datos
</LI>
<LI>Funciones y operadores sobre los distintos tipos de datos
</LI>
<LI>Sentencias de control 
</LI>
<LI>Variable de ámbito global y local
</LI>
<LI>Definición de funciones
</LI>
<LI>Paso de parámetros por valor y por referencia
</LI>
<LI>Funciones de orden superior
</LI>
<LI>Clausura de funciones
</LI>
<LI>Funciones anónimas
</LI>
<LI>Aplicación parcial de funciones
</LI>
<LI>Decoradores
</LI>
<LI>Definición de clases de objetos
</LI>
<LI>Creación e instanciación de objetos
</LI>
<LI>Tipos de datos como clases de objetos
</LI>
<LI>Visibilidad de métodos y atributos
</LI>
<LI>Definición estática de métodos y atributos
</LI>
<LI>Polimorfismo
</LI>
<LI>Duck typing
</LI>
<LI>Herencia simple
</LI>
<LI>Métodos mágicos
</LI>
<LI>Dynamic binding
</LI>
<LI>Excepciones
</LI>
<LI>Evaluación por cortocircuito devolviendo último valor
</LI>
<LI>Operadores condicionales 
</LI>
<LI>Funciones de fechas y tiempo 
<BR></LI>
<LI>Funciones de creación y acceso a ficheros
</LI>
<LI>Concurrente
</LI>
<LI>Recolector de basura
   
</LI>
</UL>
</LI>
<LI>Web OMI project.
   
<UL>
<LI>Contenido estático
</LI>
<LI>Acceso a la documentación del proyecto
</LI>
<LI>Navegación por las distintas clases y módulos que conforman el software
</LI>
<LI>Acceso a la descarga del software
</LI>
<LI>Información sobre el proyecto y la autoría
</LI>
<LI>Información de contacto
   
</LI>
</UL>
</LI>
<LI>runTree
   
<UL>
<LI>Cliente OMI
</LI>
<LI>Alta disponibilidad y facilidad de acceso
</LI>
<LI>Interactivo
</LI>
<LI>Interfaz gráfica
</LI>
<LI>Descripción de diagramas
</LI>
<LI>Descripción del árbol sintáctico producido
</LI>
<LI>Descripción de las tablas de símbolos
</LI>
<LI>Descripción de la entrada/salida producidos
</LI>
<LI>Ayuda en pantalla
   
</LI>
</UL>
</LI>
</UL>

<H1><A NAME="SECTION00040000000000000000">
Requisitos previos</A>
</H1>
El intérprete OMI puede ser ejecutado sobre cualquier hardware actual. El software por si mismo
solo necesita unos pocos kilobytes de memoria para funcionar, sin embargo el hardware 
necesario dependerá en gran medida del código fuente que será interpretado.

<P>
Para usar el intérprete OMI es necesario disponer de un sistema GNU/Linux. 
El intreprete depende de una serie de bibliotecas de programación. Dependiendo 
de la instalación que se realice será necesario la instalación previa de estas o no.

<P>

<UL>
<LI>readline
</LI>
<LI>boost-regex
</LI>
</UL>

<P>
Por otro lado para el correcto uso de la aplicación web se precisa de un navegador web con soporte 
HTML5 y JavaScript.

<H1><A NAME="SECTION00050000000000000000">
Uso del sistema</A>
</H1>

<H2><A NAME="SECTION00051000000000000000">
Obtener OMI</A>
</H2>
El intérprete OMI puede ser descargado desde la web OMI project. Se ofrecen varias 
alternativas para la descarga:

<P>

<UL>
<LI>Código fuente.
</LI>
<LI>Precompilado y empaquetado para algunas distribuciones GNU/Linux.
</LI>
</UL>

<P>
Se recomienda la descarga de la última versión estable del sistema software. 

<P>

<H2><A NAME="SECTION00052000000000000000">
Instalación</A>
</H2>
El intérprete OMI puede ser instalado sobre un sistema GNU/Linux mediante varios procesos. 

<P>

<H3><A NAME="SECTION00052100000000000000"></A> <A NAME="sec:compile"></A>
<BR>
Compilación e instalación desde código fuente
</H3>
Para instalar OMI mediante el código fuente de la aplicación previamente se deberá llevar a cabo la compilación de este. 
Es posible obtener el código fuente de la aplicación desde la sección de descargas de la web OMI project. 

<P>
El proceso de compilación se vale de una serie de herramientas que lo simplifican y parametrizan, permitiendo la configuración
del ejecutable obtenido.

<P>

<UL>
<LI>autoconf
</LI>
<LI>automake
</LI>
<LI>make
</LI>
<LI>g++
</LI>
</UL>

<P>
Además se mantiene dependencia con las siguientes bibliotecas de programación:

<P>

<UL>
<LI>Biblioteca estándar de C/C++
</LI>
<LI>Biblioteca GNU readline
</LI>
<LI>Biblioteca Boost regex
</LI>
</UL>

<P>
Instalación de dependencias en una distribución Debian:
language=bash
<PRE>
$PS1 apt-get install autoconf automake build-essential \
$PS2  libreadline-dev libboost-regex-dev
</PRE>

<P>
Para la compilación es necesario abrir una sesión de terminal de comandos en el directorio sobre el
que se desea llevar a cabo el proceso. Se supone que el usuario tiene permisos suficientes en el 
sistema para llevar a cabo la instalación.

<P>
Descarga del código fuente de la versión $VERSION:
<PRE>
$PS1 wget http://wwww.omi-project.com/download/code/omi_$VERSION.tar.gz
</PRE>

<P>
Descompresión y desempaquetado del fichero:
<PRE>
$PS1 tar -xzvf omi_$VERSION.tar.gz
$PS1 cd omi_$VERSION
</PRE>

<P>
Es posible establecer determinados aspectos del intérprete durante el proceso de compilación. Las opciones 
más significativas son las siguientes:

<P>
<DL>
<DT><STRONG>numType:</STRONG></DT>
<DD>Tipo de dato utilizado para la representación interna de los datos numéricos. El valor por defecto es ``double''.
Su valor puede ser cualquier tipo de dato estándar de C/C++ o algún tipo específico facilitado por el usuario. También admite el
valor en número de bytes, siendo los posibles valores ``4bytes'', ``8bytes'' y ``16bytes''.
</DD>
<DT><STRONG>numPrecision:</STRONG></DT>
<DD>Precisión numérica utilizada en al escribir en la salida estándar. Su valor por defecto es 15, y puede ser cualquier número entero.
</DD>
<DT><STRONG>refCType:</STRONG></DT>
<DD>Tipo de dato utilizado para contar el número de referencias de los nodos. Determina el número de referencias máximas que puede llegar a tener un 
dato. Su valor por defecto ``unsigned int''. Puede ser cualquier tipo de dato estándar de C/C++ o  algún tipo específico facilitado por el usuario.
</DD>
<DT><STRONG>sizeNode:</STRONG></DT>
<DD>Esta opción permite configurar el intérprete dando valores óptimos a las opciones anteriores. Puede presentar uno de los siguientes valores:
<DL>
<DT><STRONG>small:</STRONG></DT>
<DD>numType=``float'' refCType=``unsigned int'' numPrecision=6
</DD>
<DT><STRONG>normal:</STRONG></DT>
<DD>numType=``double'' refCType=``unsigned int'' numPrecision=15
</DD>
<DT><STRONG>big:</STRONG></DT>
<DD>numType=``long double'' refCType=``unsigned int'' numPrecision=18
</DD>
</DL>
</DD>
</DL>

<P>
Para ver un listado completo de las opciones de configuración para la compilación:
<PRE>
$PS1 ./configure --help
</PRE>

<P>
Configurar el proceso de compilación con las opciones por defecto:
<PRE>
$PS1 ./configure
</PRE>

<P>
Durante la ejecución de este script se comprobará si se satisfacen las dependencias, y se creará los scripts necesarios para la compilación.

<P>
Para llevar a cabo la compilación:
<PRE>
$PS1 make
</PRE>

<P>
Una vez compilado con éxito es posible proceder con la instalación:
<PRE>
$PS1 make install
</PRE>

<P>
Para comprobar la integridad de la instalación:
<PRE>
$PS1 make check
</PRE>

<P>
Para limpiar el entorno de compilación:
<PRE>
$PS1 make clean
</PRE>

<P>
Para desinstalar el software:
<PRE>
$PS1 make unistall
</PRE>

<P>

<H3><A NAME="SECTION00052200000000000000"></A><A NAME="sec:deb_pack"></A>
<BR>
Instalación mediante paquete .deb
</H3>
Cada versión del intérprete es precompilada y empaquetada. Las bibliotecas externas se compilan
de forma estática por lo que se elimina la dependencia con otros paquetes.

<P>
Con una sesión de terminal y los permisos en el sistema suficientes es posible descargar e instalar el paquete .deb

<P>
Para descargar el paquete:
<PRE>
$PS1 wget http://wwww.omi-project.com/download/deb/omi_$VERSION.deb
</PRE>

<P>
Para instalar el paquete:
<PRE>
$PS1 dpkg -i omi_$VERSION.deb
</PRE>

<P>
Para desinstalar el paquete:
<PRE>
$PS1 dpkg -r omi
</PRE>

<P>

<H2><A NAME="SECTION00053000000000000000">
Intérprete</A>
</H2>labelsec:intérpreter
El intérprete es el sistema software sobre el que gira el proyecto OMI. Se trata
del software encargado de leer y ejecutar el código fuente escrito en OMI.

<P>
Para ejecutar el intérprete se utiliza el comando con el mismo nombre.
 <PRE>
$PS1 omi
</PRE>

<P>
Ejecutar el comando sin argumento hará que el intérprete lea y procese la entrada estándar.

<P>
La sintaxis del comando es la siguiente:
<P><!-- MATH
 \begin{displaymath}
omi\ [options]\ [file]\ [args...]
\end{displaymath}
 -->
</P>
<DIV ALIGN="CENTER" CLASS="mathdisplay">

</DIV><P></P>

<P>
El fichero será un documento escrito en el lenguaje OMI. La lista de argumentos serán datos accesibles
desde el código fuente contenido en el fichero.

<P>
Las posibles opciones son:
<DL>
<DT><STRONG>-c <SPAN ID="txt367">cmd</SPAN>:</STRONG></DT>
<DD>Interpreta la cadena cmd.
</DD>
<DT><STRONG>-i:</STRONG></DT>
<DD>Modo interactivo. Las expresiones y sentencias son interpretadas en tiempo real y solicitadas mediante un prompt.
</DD>
<DT><STRONG>-h:</STRONG></DT>
<DD>Muestra la ayuda del comando.
</DD>
<DT><STRONG>-V:</STRONG></DT>
<DD>Muestra la versión del software.
</DD>
</DL>

<P>
Los argumentos facilitados serán accesible desde el código fuente mediante el array ``args'', donde la primera posición del array es
el nombre del fichero y las siguientes los argumentos facilitados.

<P>
Se pone a disposición del usuario una hoja de manual que detalla el uso del comando.
<PRE>
$PS1 man omi
</PRE>

<P>
Con la instalación por defecto el intérprete es ubicado en la siguiente ruta:
<P><!-- MATH
 \begin{displaymath}
/usr/local/bin/omi
\end{displaymath}
 -->
</P>
<DIV ALIGN="CENTER" CLASS="mathdisplay">

</DIV><P></P>

<P>
Además los recursos, como por ejemplo las extensiones, serán ubicados en el siguiente directorio:
<P><!-- MATH
 \begin{displaymath}
/usr/local/share/omi
\end{displaymath}
 -->
</P>
<DIV ALIGN="CENTER" CLASS="mathdisplay">

</DIV><P></P>

<P>
language=omi

<H2><A NAME="SECTION00054000000000000000">
Referencias del lenguaje</A>
</H2>

<H3><A NAME="SECTION00054100000000000000"></A> <A NAME="sec:stmt"></A>
<BR>
Sentencias
</H3>
Como muchos otros lenguajes de programación toda sentencia OMI debe acabar en punto y coma ``;''. 

<P>
Es posible delimitar un bloque de sentencias entre llaves. Muchos recursos del lenguaje operan 
 o trabajan sobre un bloque de sentencias. Estas no necesitan acabar en ``;''.

<P>
Los cierre de bloque o fin de la entrada automáticamente implica un punto y coma.
En el modo interactivo no es necesario si la línea introducida sólo se compone de una sentencia. 
<BR>
<P>
<PRE>
   &lt;&lt; "Hola mundo"; // Sentencia acabada 
   if (true) { &lt;&lt; "Y un ejemplo"; } // Bloque de sentencias 
   &lt;&lt; "Soy un programa OMI"
</PRE>

<P>

<H3><A NAME="SECTION00054200000000000000"></A><A NAME="sec:comments"></A>
<BR>
Comentarios
</H3>
Los comentarios son fragmentos de texto que son incluidos en el código fuente y que serán omitidos por el intérprete. Se utilizan normalmente para aclarar y/o documentar las
piezas de código. 

<P>
En OMI es posible realizar un comentario de línea al estilo de C++ o de consola de comando UNIX. 
<BR>
<P>
<PRE>
   x = 1; //x vale 1
   y = 2; #y vale 2
</PRE>

<P>
Por otro lado, es posible escribir un bloque de una o varias líneas de comentarios delimitándolo mediante ``/*'' y ``*/''. 
<BR>
<P>
<PRE>
   /* 
      x vale 1
      y vale 2
   */
   x = 1; 
   y = 2;
</PRE>
<H3><A NAME="SECTION00054300000000000000"></A><A NAME="sec:execution"></A>
<BR>
Ejecución
</H3>
La ejecución de un programa escrito en OMI comenzará desde un fichero, y desde la primera sentencia contenida en este. Las sentencias 
en este fichero que no esten contenidas en ninguna función o método son consideradas el flujo principal del programa.

<P>
La ejecución del programa normalmente se realiza sentencia a sentencia de forma secuencial. Algunas sentencias y expresiones del lenguaje podrán cambiar este flujo.

<P>
La ejecución finaliza cuando se llega al final de este fichero o se resuelve una sentencia que produzca la salida. También es posible que se de algún error sintáctico o semántico

<P>

<H3><A NAME="SECTION00054400000000000000"></A><A NAME="sec:id"></A>
<BR>
Identificadores
</H3>
Los identificadores en OMI sirven para nombrar elementos del script definidos por el programador,
tales como variables, funciones, etiquetas, clases...

<P>
Un identificador debe comenzar por una letra (mayúscula o minúscula) o un subguión (_), seguidos de tantas letras, números o subguiones como se desee. 
<BR>
<P>
<PRE>
   foo = 1;  // foo identifica una variable que vale uno
   ~ bar () { // bar identifica una función que imprime "Hola mundo".
      &lt;&lt; "Hola mundo";
   }
</PRE>

<P>
OMI es sensible a mayúsculas, por lo que considera dos identificadores distintos si no mantienen la misma capitalización.

<P>
Un identificador no puede coincidir con una palabra reservada del lenguaje o se producirá un error sintáctico.

<P>

<H4><A NAME="SECTION00054410000000000000">
Palabras reservadas</A>
</H4>

<P>

<UL>
<LI>null
</LI>
<LI>NULL
</LI>
<LI>true
</LI>
<LI>false
</LI>
<LI>global
</LI>
<LI>getenv
</LI>
<LI>function
</LI>
<LI>P
</LI>
<LI>return
</LI>
<LI>class
</LI>
<LI>new
</LI>
<LI>private
</LI>
<LI>extends
</LI>
<LI>this
</LI>
<LI>extends
</LI>
<LI>parent
</LI>
<LI>static
</LI>
<LI>include
</LI>
<LI>if
</LI>
<LI>else
</LI>
<LI>elseif
</LI>
<LI>elif
</LI>
<LI>switch
</LI>
<LI>case
</LI>
<LI>default
</LI>
<LI>with
</LI>
<LI>do
</LI>
<LI>while
</LI>
<LI>for
</LI>
<LI>as
</LI>
<LI>in
</LI>
<LI>break
</LI>
<LI>continue
</LI>
<LI>exit
</LI>
<LI>goto
</LI>
<LI>throw
</LI>
<LI>try
</LI>
<LI>catch
</LI>
<LI>print
</LI>
<LI>echo
</LI>
<LI>input
</LI>
<LI>inputline
</LI>
<LI>typeof
</LI>
<LI>typeOf
</LI>
<LI>datinfo
</LI>
<LI>datInfo
</LI>
<LI>empty
</LI>
<LI>isnull
</LI>
<LI>isbool
</LI>
<LI>isnum
</LI>
<LI>isstring
</LI>
<LI>isarray
</LI>
<LI>isobject
</LI>
<LI>AND
</LI>
<LI>and
</LI>
<LI>OR
</LI>
<LI>or
</LI>
<LI>size
</LI>
<LI>str_explode
</LI>
<LI>str_implode
</LI>
<LI>array_implode
</LI>
<LI>str_implode
</LI>
<LI>str_find 
</LI>
<LI>str_pos 
</LI>
<LI>str_replace 
</LI>
<LI>str_replace_sub 
</LI>
<LI>str_upper 
</LI>
<LI>str_lower 
</LI>
<LI>str_search 
</LI>
<LI>str_match 
</LI>
<LI>sprintf 
</LI>
<LI>regexp 
</LI>
<LI>reduce 
</LI>
<LI>array_chunk 
</LI>
<LI>array_search 
</LI>
<LI>int 
</LI>
<LI>float 
</LI>
<LI>bool 
</LI>
<LI>string 
</LI>
<LI>date 
</LI>
<LI>time 
</LI>
<LI>sleep 
</LI>
<LI>file 
</LI>
<LI>fopen 
</LI>
<LI>fput 
</LI>
<LI>fget 
</LI>
<LI>fread 
</LI>
<LI>fwrite 
</LI>
<LI>fappend 
</LI>
<LI>fapp 
</LI>
<LI>fclose 
</LI>
<LI>ftell 
</LI>
<LI>fseek 
</LI>
<LI>fSET 
</LI>
<LI>fCUR 
</LI>
<LI>fEND 
</LI>
<LI>exec 
</LI>
<LI>eval 
</LI>
<LI>fork 
</LI>
<LI>wait 
</LI>
<LI>getpid 
</LI>
<LI>getppid 
</LI>
<LI>process 
</LI>
<LI>signal 
</LI>
<LI>kill 
</LI>
<LI>shandler 
</LI>
<LI>exit_process 
</LI>
<LI>load 
</LI>
</UL>

<P>
En OMI se nombran de igual forma las variables, funciones, clases... Es el contexto 
en el que se da un identificador el que determina el recurso que este nombra. 
Por regla general todos los operadores, funciones y demás construcciones del lenguaje toman, 
a no ser que se indique lo contrario, los identificadores como variables. Las excepciones a esta regla son:

<P>

<UL>
<LI>Operador llamada a función 
</LI>
<LI>Operador aplicación parcial
</LI>
<LI>Operador <SPAN CLASS="MATH"></SPAN>
</LI>
</UL>

<P>
OMI dispone de mecanismos para indicar explícitamente el tipo de recurso que es nombrado.

<P>

<H3><A NAME="SECTION00054500000000000000"></A><A NAME="sec:data_type"></A>
<BR>
Tipos de datos
</H3>
Haciendo uso del lenguaje OMI se puede operar sobre varios tipos de datos simples y compuestos. 

<P>
OMI es un lenguaje de programación que presenta un tipado dinámico, es decir, las variables se consideran del mismo tipo que al dato al que 
referencian. Así no es necesario declarar el tipo de dato que contendrán.

<P>
Los tipos de datos sobre los que opera OMI son:

<UL>
<LI>Simples:

<UL>
<LI>Booleanos.
</LI>
<LI>Numéricos.
</LI>
<LI>Cadenas de caracteres.
</LI>
</UL>
</LI>
<LI>Compuestos:

<UL>
<LI>Arrays.
</LI>
<LI>Objetos.
</LI>
</UL>
</LI>
<LI>Especiales:

<UL>
<LI>Nulo.
</LI>
<LI>Función.
</LI>
<LI>Expresión regular.
</LI>
</UL>
</LI>
</UL>

<P>
Algunas funciones y operadores del lenguaje tratan tipos de datos concretos. A pesar de ello OMI es un lenguaje débilmente tipado, por
lo que es posible usar valores de un tipo de dato en expresiones que requieran otro tipo de dato. Para ello se lleva a cabo una conversión de
tipo de forma implícita.

<P>

<H4><A NAME="SECTION00054510000000000000"></A><A NAME="sec:type_bool"></A>
<BR>
Booleano
</H4>
Este tipo de dato puede contener dos únicos valores: verdadero o falso. Es el tipo de dato 
más simple. El valor verdadero se expresa mediante el literal ``true'', mientras que el 
falso se representa mediante ``false''. 
<BR>
<P>
<PRE>
   a = true; // a presenta el valor verdadero
   b = false; // b presenta el valor falso
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Operadores lógicos (\autoref{sec:op_bool}).
   \item Operadores de comparación (\autoref{sec:op_cmp}).
   \item Conversión implícita entre tipos de datos (\autoref{sec:type_iconv})
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054520000000000000"></A><A NAME="sec:type_num"></A>
<BR>
Numérico
</H4>
En OMI únicamente existe un tipo de dato numérico. Mediante este tipo de dato es posible representar 
números enteros y aquellos decimales que puedan ser expresados en punto flotante. 

<P>
A pesar de que solo presenta un tipo de dato numérico ofrece mecanismos para operar con enteros y decimales, por ejemplo es posible obtener la parte entera de 
un número decimal.

<P>
Los números son expresados en OMI mediante cualquier conbinación de dígitos, separando la parte decimal mediante un punto si existiera. Además es
posible preceder la expresión de un signo ``+'' o ``-''. 
<BR>
<P>
<PRE>
   a = 1; // a presenta el valor 1
   b = -1; // b presenta el valor -1
   c = +1; // c presenta el valor +1
   d = 0.001; // d presenta el valor 0.001
   e = -0.001; // e presenta el valor -0.001
</PRE>

<P>
En OMI es posible configurar cómo los tipos de datos numéricos son almacenados y tratados de forma interna. Así es posible alterar el valor numérico máximo que se puede representar 
y la precisión. No obstante, esto sólo es posible en tiempo de compilación, por lo que se deberá usar la misma configuración para todos las ejecuciones. 
<BR>
<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Operadores aritméticos (\autoref{sec:op_arth}).
   \item Compilación e instalación desde código fuente (\autoref{sec:compile}).
   \item Conversión implícita entre tipos de datos (\autoref{sec:type_iconv})
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054530000000000000"></A><A NAME="sec:type_string"></A>
<BR>
Cadena de caracteres
</H4>
En general, un carácter se refiere a una letra, número u otro símbolo o signo. Las cadenas de caracteres son una sucesión de estos. Normalmente representan un contenido textual. 

<P>
En OMI las cadenas de caracteres son consideradas como un tipo de dato simple. Esto es debido a que no existe el tipo de dato carácter, y por tanto los datos de este tipo no puede ser 
descompuesto en datos de tipos más simples. De esta forma se considera al carácter simple como una cadena de un solo elemento.

<P>
Una cadena de caracteres queda delimitada entre comillas simples o comillas dobles. 
<BR>
<P>
<PRE>
   a = "Una cadena de caracteres"; // a es una cadena definida entre "
   b = 'Y otra'; // b es una cadena definida entre '
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Operadores sobre cadenas de caracteres(\autoref{sec:op_string}).
   \item Funciones sobre cadenas de caracteres (\autoref{sec:func_string}).
   \item Conversión implícita entre tipos de datos (\autoref{sec:type_iconv})
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054540000000000000"></A><A NAME="sec:type_array"></A>
<BR>
Array
</H4>

<P>
En OMI un array es una estructura de datos que almacena valores de forma contigua. Los datos que guarda un array pueden ser de diferente tipo. 

<P>
Se pueden dar dos tipos de arrays:

<P>

<UL>
<LI>Secuenciales.
</LI>
<LI>Asociativos.
</LI>
</UL>

<P>
Los arrays secuenciales son accesibles mediante índices numéricos y de una forma posicional. Se definen mediante una secuencia de expresiones que representan 
un valor. Estas serán separadas por el carácter ``,'' y delimitadas entre llaves ``'' y ``''. El primer elemento del array se corresponde con el índice numérico <SPAN CLASS="MATH">0</SPAN>. 
<BR>
<P>
<PRE>
   a = {0,1,2}; // a es un array que contiene los números 0, 1 y 2
   /* 
      b es un array que contiene el numero 0, la
      cadena "str" y otro array con los numeros 0 y 1
   */
   b = {0,"str", { 0, 1 } };
</PRE>

<P>
En arrays asociativos cada elemento está referenciado mediante una clave, de forma que se puede utilizar esta para acceder al elemento dentro del array. En OMI las claves 
de los arrays asociativos pueden ser cualquier expresión válida que represente un valor de tipo simple. Un array asociativo se define igual que uno secuencial salvo que los elementos que lo
componen son pares de expresiones correspondientes a la clave y al valor y separadas por el carácter ``:''. 
<BR>
<P>
<PRE>
   /*
      a es un array asociativo con las cadenas
      'k0', 'k1' y 'k2' como claves. Sus valores 
      son 0, 1 y 2 respectivamente.
   */
   a = {'k0' : 0, 'k1' : 1, 'k2' : 2};
   /* 
      b es un array asociativo con los números 0 y
      10, y la cadena "K" como claves. Sus valores son
      el numero 0, la cadena "str" y otro array con 
      los numeros 0 y 1.
   */
   b = { 10: 0, 0: "str", "K": { 0, 1 } };
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Operadores sobre arrays (\autoref{sec:op_string}).
   \item Funciones sobre arrays (\autoref{sec:func_string}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054550000000000000"></A> <A NAME="sec:type_object"></A>
<BR>
Objetos
</H4>
En programación orientada a objetos, un objeto es una estructura de datos que presenta un comportamiento asociado. Tiene un estado interno 
determinado por el valor de los datos que contiene, y se encarga de realizar una serie de tareas en tiempo de ejecución. Una clase de objetos es un
modelo que define las propiedades y el comportamiento que tienen objetos afines. 

<P>
El uso de las clases y los objetos es descrito en profundidad como una referencia del lenguaje (sec:class).

<P>
En OMI todo dato es considerado de tipo objeto, los otros tipos se ven como clases de objetos. Un dato, además de tener asociado un valor de un tipo concreto, 
presenta  una serie de acciones u operaciones que se pueden realizar con él y que están determinadas por su tipo. Por ejemplo sobre un dato array se puede realizar la operación
implode para obtener una cadena con todos los elementos del array separado por una subcadena separadora. 
<BR>
<P>
<PRE>
   /*
      A la variable "a" se le asigna
      el resultado de ejecutar la operación 
      implode sobre el array. 
   */
   a = {"hola","mundo"}-&gt;implode(" ");
</PRE> 

<P>
OMI permite al usuario definir, construir y utilizar sus propios objetos. Para ello se vale de las clases
y de mecanismos para instanciar los objetos a partir de estas.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Clases de objetos (\autoref{sec:class}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054560000000000000">
Nulo</A>
</H4>
Nulo representa la ausencia de valor. Es un tipo de dato especial que se utiliza para expresar referencias que no tienen valor asociado. Paradójicamente el
valor nulo conlleva la ausencia de valor. 

<P>
En OMI cualquier referencia sin valor se considera como nulo. Las variables no inicializadas, o las posiciones de arrays inexistentes tienen el valor nulo. 

<P>
Es posible expresar un dato nulo mediante el literal ``null'' (o en mayúsculas ``NULL''). 
<BR>
<P>
<PRE>
   a = null; // a no contiene valor
</PRE> 

<P>

<H4><A NAME="SECTION00054570000000000000"></A><A NAME="sec:type_func"></A>
<BR>
Función
</H4>
En OMI una función hace referencia a un bloque de sentencias que puede recibir una serie de parámetros y tomar un valor. Una función realiza una tarea específica dentro del programa.
Cuando una función es llamada se ejecuta el bloque de sentencias al que referencia, pasándole como parámetros los valores en la llamada. 

<P>
El uso de las funciones es descrito en detalle más adelante, en este manual, como una referencia del lenguaje (sec:class). 

<P>
En OMI las funciones son consideradas tipos de datos, siendo posible operar sobre ellas. Así una función puede ser asignada a una variable, pasada como parámetro 
o ser devuelta por otra función. 
<BR>
<P>
<PRE>
   /*
      a es una función que recibe un 
      parámetro y lo devuelve como valor
   */
   a = ~(param){ return param; };
</PRE> 

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Funciones (\autoref{sec:function}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054580000000000000">
Expresión regular</A>
</H4>
Una expresión regular es un patrón definido por un lenguaje regular. Normalmente se aplica a una cadena de caracteres, para 
determinar si pertenece al lenguaje que define. Se utiliza para realizar búsquedas de subcadenas o llevar a cabo remplazos.

<P>
Con OMI se puede expresar cualquier expresión regular usando la sintaxis PERL. Para ello se ha de delimitar entre acento grave (` ). 
<BR>
<P>
<PRE>
   /*
      "exp" es la expresión regular correspondiente
      al lenguaje descrito por cero o mas caracteres "a" 
      seguidos de dos caracteres "b"
   */
   exp = `a*bb`;
</PRE> 

<P>
El lenguaje dispone de funciones para crear y operar sobre expresiones regulares.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Funciones de expresiones regulares (\autoref{sec:func_regex}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054590000000000000"></A><A NAME="sec:type_iconv"></A>
<BR>
Conversión implícita entre tipos de datos
</H4>
OMI es un lenguaje de tipado débil, es decir, dado un valor de un tipo concreto es posible utilizarlo como otro tipo sin necesidad de 
llevar a cabo una conversión de forma explícita. Al usar un dato en una operación que espera  otro tipo OMI realizará
una conversión automática.

<P>
<DL>
<DT><STRONG>Nulo</STRONG></DT>
<DD>
   <DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>false
   
</DD>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>0
   
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN><SPAN CLASS="MATH"></SPAN>
</DD>
</DL>
</DD>
<DT><STRONG>Booleanos</STRONG></DT>
<DD>
   <DL>
<DT><STRONG>false</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>0 
      
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN><SPAN CLASS="MATH"></SPAN>
</DD>
</DL>
   
</DD>
<DT><STRONG>true</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>1 
      
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>1<SPAN CLASS="MATH"></SPAN>
</DD>
</DL>
</DD>
</DL>
</DD>
<DT><STRONG>Numéricos</STRONG></DT>
<DD>
   <DL>
<DT><STRONG>Número 0</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>false 
      
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>0<SPAN CLASS="MATH"></SPAN>
</DD>
</DL>
   
</DD>
<DT><STRONG>Número distinto a 0</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>true 
      
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD>Cadena que representa el número.
      
</DD>
</DL>
</DD>
</DL>
</DD>
<DT><STRONG>Cadena de caracteres</STRONG></DT>
<DD>
   <DL>
<DT><STRONG>Cadena vacía</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>false 
      
</DD>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>0
      
</DD>
</DL>
   
</DD>
<DT><STRONG>Cadena numérica</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>true 
      
</DD>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>Número que representa la cadena
      
</DD>
</DL>
   
</DD>
<DT><STRONG>Otra cadena</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>true 
      
</DD>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>Tamaño de la cadena
      
</DD>
</DL>
</DD>
</DL>
</DD>
</DL>

<P>
Normalmente no es posible usar un dato simple en lugar de uno compuesto. Las funciones y operaciones que esperan recibir como argumento
un dato compuesto devolverán un error si no es así. No obstante un dato compuesto puede utilizarse como uno simple sin que se produzcan
errores semánticos.

<P>
<DL>
<DT><STRONG>Array</STRONG></DT>
<DD>
   <DL>
<DT><STRONG>Array vacío</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>false 
      
</DD>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>0
      
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN><SPAN CLASS="MATH"></SPAN>
</DD>
</DL>
   
</DD>
<DT><STRONG>Array con elementos</STRONG></DT>
<DD>
      <DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>true 
      
</DD>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>0   
      
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN><SPAN CLASS="MATH"></SPAN>
</DD>
</DL>
</DD>
</DL>
</DD>
</DL>

<P>
En el caso de los objetos, es posible definir métodos que serán invocados cuando sean utilizados como otro tipo de dato. Estos métodos son denominados 
métodos mágicos (sec:magic_method).

<P>

<H3><A NAME="SECTION00054600000000000000">
Operadores</A>
</H3>
OMI soporta una serie de operadores de naturaleza muy variada. Mediante un operador se puede construir una expresión que, al ser evaluadas, se aplicará una función
sobre un conjunto de datos de entrada denominados operandos, y obtener así un valor.

<P>
Un operador normalmente es de naturaleza binaria, presentando dos entradas, aunque existe operadores unitarios o ternarios. Además presenta una sintaxis y semántica propia. 
<BR>
<P>
<PRE>
   foo = 1 + 1; // foo es el resultado de evaluar la operación suma
</PRE> 

<P>
Los operadores pueden combinarse para formar expresiones más complejas. Para la evaluación se establece una precedencia de operadores implícita, que determina en qué orden 
deben de resolverse. Es posible alterar la precedencia de operadores encerrando la expresión entre paréntesis. 
<BR>
<P>
<PRE>
   foo = 2 * 8 + 3; // se evalúa la operación producto y luego la suma.
   bar = 2 * (8 + 3); //se evalúa la operación suma y luego el producto.
</PRE> 

<P>
La mayoría de operadores que se pueden utilizar en OMI tienen una naturaleza matemática y se resuelven igual forma. No obstante también soporta otros operadores propios de
los lenguajes de programación. 

<P>

<H4><A NAME="SECTION00054610000000000000"></A><A NAME="sec:op_bool"></A>
<BR>
Operadores lógicos
</H4>

<P>
Al aplicarse un operador lógico se produce un resultado booleano derivado de la evaluación de una condición. 

<P>
Los operadores lógicos son los siguientes:

<P>
<DL>
<DT><STRONG>Negación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>AND lógico:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>OR lógico:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
<PRE>
   foo = !true; // foo vale falso
   foo = true &amp;&amp; false; // foo vale falso
   foo = true or false; // foo vale verdadero
</PRE> 

<P>
Los operadores AND y OR son evaluados de izquierda a derecha en corto circuito. Se puede producir el resultado mediante una evaluación parcial, al conocerse de antemano el 
valor que se obtendrá mediante la evaluación total. En este caso el resto de la expresión no será evaluada. Además el resultado siempre será el último operando en ser evaluado. 
<BR>
<P>
<PRE>
   foo = null and 3 + 4; // foo vale null, evaluación parcial 
   foo = {} or "10"; // foo vale "10", evaluación total
   foo = "10" and 3 + 4; // foo vale 7, evaluación total
   foo = "5" or {}; // foo vale "5", evaluación parcial
</PRE> 

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de dato (\autoref{sec:data_type}).
   \item Tipo de dato booleano (\autoref{sec:type_bool}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054620000000000000"></A><A NAME="sec:op_cmp"></A>
<BR>
Operadores de comparación
</H4>
Se encargan de evaluar el orden entre dos valores. El resultado es un valor booleano de verdadero si se satisface la comparación o falso en caso contrario.

<P>
Los operadores de comparación son los siguientes:

<P>
<DL>
<DT><STRONG>Igualdad:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Desigualdad:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Menor que:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Menor o igual que:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Mayor que:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Mayor o igual que:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Idéntico:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>No idéntico:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
<PRE>
   foo = 5 == 5; // foo vale verdadero
   foo = "5" == 5; // foo vale verdadero
   foo = 5 != 5; // foo vale falso
   foo = "3" &lt; 4; // foo vale verdadero
   foo = "3" &lt;= 4; // foo vale verdadero
   foo = 4 &gt; 4; // foo vale falso
   foo = 4 &gt;= 4; // foo vale verdadero
   foo = 5 === 5; // foo vale verdadero
   foo = "5" === 5; // foo vale falso
   foo = "5" !== 5; // foo vale verdadero
</PRE> 

<P>
Para los tipos booleanos se considera que verdadero (true) es mayor que falso (false). Para los datos de tipo numéricos se toma su valor aritmético.
Las cadenas de caracteres son ordenadas alfabéticamente.

<P>
Cuando se comparan datos de distintos tipos se realiza una conversión al tipo de dato más simple. Por ejemplo al comparar un dato numérico con un booleano se convertirá
el numérico a booleano. 
<BR>
<P>
<PRE>
   foo = true &lt;= 5; // foo vale verdadero
   foo = "5" == true; // foo vale verdadero
   foo = "word" &lt; 4; // foo vale falso
</PRE> 

<P>
Cuando se realiza una comparación de forma idéntica, además de comparar el valor de los datos, se comprueban los tipos.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de dato (\autoref{sec:data_type}).
   \item Tipo de dato booleano (\autoref{sec:type_bool}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054630000000000000"></A> <A NAME="sec:op_arth"></A>
<BR>
Operadores aritméticos
</H4>

<P>
Se corresponden con las operaciones aritméticas básicas que son la suma, la diferencia, el producto y la división, y 
aquellas derivadas de estas. El resultado de la operación será un número.

<P>
Los operadores aritméticos toman como operandos expresiones tratadas como numéricos. Todo dato que sea sometido a una operación
aritmética será convertido a numérico.

<P>
Los operadores aritméticos soportados por OMI son:

<P>
<DL>
<DT><STRONG>Suma:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Diferencia:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Producto:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Division:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Módulo:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Potencia:</STRONG></DT>
<DD>&#710;
</DD>
</DL> 

<P>
<PRE>
   foo = 1 + 1; // foo vale 2
   foo = "5" + 5; // foo vale 10
   foo = "word" + 4; // foo vale 8
   foo = true + 10; // foo vale 11
   foo = 4 - "2"; // foo vale 2
   foo = 3 * 4; // foo vale 12
   foo = 17 / 4; // foo vale 4.25
   foo = 2.1 / "8"; // foo vale 0.2625
   foo = 4 % 3; // foo vale 1
   foo = 4 ^ 2; // foo vale 16
</PRE> 

<P>
El resultado del operador módulo mantendrá el mismo signo que el operando que hace de dividendo.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de dato (\autoref{sec:data_type}).
   \item Tipo de dato numérico (\autoref{sec:type_num}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054640000000000000"></A><A NAME="sec:op_string"></A>
<BR>
Operadores sobre cadenas de caracteres
</H4>
OMI soporta una serie de operadores que pueden ser aplicados sobre cadenas de caracteres. 

<P>
<DL>
<DT><STRONG>Concatenación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Acceso a posición:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
<PRE>
   foo = "ABC" . "DEF"; // foo vale "ABCDEF"
   foo = "ABCDE"[0]; // foo vale "A"
</PRE> 

<P>
La concatenación se realiza después de que se determinen los números decimales presentes en la 
expresión. Todo carácter punto no suponga un separador decimal será considerado un operador
de concatenación.
<BR>
<P>
<PRE>
   foo = "AB".2.1.1."CD"; // foo vale "AB2.11CD"
   foo = "AB".2.1.1.1."CD"; // foo vale "AB2.11.1CD"
</PRE> 

<P>
El operador de acceso a posición recibe un índice que indica el elemento al que acceder dentro de la 
cadena. Si la posición indicada no existe se toma el valor nulo. El índice siempre será considerado como un 
dato numérico.

<P>
El operador de acceso también puede ser utilizado para escribir en una determinada posición de la cadena.
No obstante, en este caso, debe existir un elemento en la posición indicada o se producirá un error. 
<BR>
<P>
<PRE>
   foo = "ABCD"; // foo vale "ABCD"
   foo[0] = "E"; // foo vale "EBCD"
   foo[0] = "FG"; // foo vale "FGBCD"
   foo[10] = "X"; // se produce un error.
</PRE> 

<P>
No es posible utilizar el operador de acceso para escribir en una determinada posición de una cadena constante. 
<BR>
<P>
<PRE>
   "ABCD"[0] = "X"; // se produce un error.
</PRE> 

<P>
El operador de acceso es utilizado para otros tipos de datos como los arrays.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de dato (\autoref{sec:data_type}).
   \item Tipo de dato cadena de caracteres (\autoref{sec:type_string}).
   \item Funciones sobre cadena de caracteres (\autoref{sec:fun_string}).
   \item Operadores sobre array (\autoref{sec:op_array}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054650000000000000"></A> <A NAME="sec:op_asig"></A>
<BR>
Operadores de asignación
</H4>
La asignación es la operación mediante la cual el valor de una expresión puede ser atribuido a un símbolo variable. De esta forma se puede hacer uso 
del valor en otras expresiones. El operador se representa mediante un signo igual ``='' y toma una expresión (operando derecho) para asignarla a un símbolo variable (operando izquierdo).

<P>
En OMI se lleva a cabo una asignación destructiva. Cuando una expresión es asignada, por ejemplo a una variable, el valor de esta última cambia, indistintamente de lo que contenía
anteriormente.
<BR>
<P>
<PRE>
   foo = 1; // foo vale 1
   foo = 2; // foo a cambiado al valor 2
   bar = foo; // bar vale el valor actual de foo que es 2
   foo = 10; // foo a cambiado al valor 10 y bar sigue valiendo 2
</PRE> 

<P>
OMI, como otros lenguajes, soporta una serie de operadores que combinan una operación determinada y una asignación. Estos simplifican
muchas expresiones.

<P>
<DL>
<DT><STRONG>Suma y asignación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Diferencia y asignación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Producto y asignación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>División y asignación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Potencia y asignación:</STRONG></DT>
<DD>&#710; =
</DD>
<DT><STRONG>Módulo y asignación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Concatenación y asignación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
<PRE>
   foo = 1; // foo vale 1
   foo += 2; // foo a cambiado al valor 3
   foo -= 4; // foo a cambiado al valor -1
   foo *= -9; // foo a cambiado al valor 9
   foo /= 3; // foo a cambiado a 3
   foo ^= 3; // foo a cambiado a 27
   foo %= 2; // foo a cambiado a 1
   foo .= "F"; // foo a cambiado a "1F"
</PRE> 

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Operadores aritméticos (\autoref{sec:op_arth}).
   \item Operadores sobre cadenas de caracteres (\autoref{sec:op_string}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054660000000000000"></A> <A NAME="sec:op_inc"></A>
<BR>
Operadores de incremento y decremento
</H4>
Estos operadores se aplican a una expresión variable, incrementando o decrementado su valor
numérico. Este tipo de operaciones implican una asignación. 

<P>
Se distinguen entre si, además de que si el valor es incrementado o decrementado, en el momento en el momento
en el que se tomará el valor. Pudiendo aplicarse la operación antes o después de evaluar el resto de la expresión.

<P>
<DL>
<DT><STRONG>Preincremento:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Posincremento:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Predecremento:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Posdecremento:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
<PRE>
   foo = 1; // foo vale 1
   bar = ++foo; // bar vale 2 y foo vale 2
   bar = foo++; // bar vale 2 y foo vale 3
   bar = --foo; // bar vale 2 y foo vale 2
   bar = foo--; // bar vale 2 y foo vale 1
</PRE> 

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Operadores aritméticos (\autoref{sec:op_arth}).
   \item Operadores de asignación (\autoref{sec:op_asig}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054670000000000000"></A> <A NAME="sec:op_type"></A>
<BR>
Operadores de conversión de tipo
</H4>
En OMI se definen una serie de operadores que permiten realizar una conversión explícita a un determinado tipo de dato.

<P>
<DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Entero:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Punto flotante:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
<PRE>
   foo = bool 4; // foo vale el booleano true
   foo = bool 0; // foo vale el booleano false
   foo = int "4.5"; // foo vale el numérico 4
   foo = int "AA"; // foo vale el numérico 2
   foo = float "4.5"; // foo vale el numérico 4.5
   foo = string 55; // foo vale la cadena "55" 
   foo = string true; // foo vale la cadena "1"
</PRE> 

<P>
A pesar de que OMI soporta la conversión a enteros o flotantes, internamente estos se representan de la misma forma. Por lo que
se consideran del mismo tipo.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de datos (\autoref{sec:data_type}).
   \item Conversión implícita entre tipos de datos (\autoref{sec:type_iconv}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054680000000000000"></A> <A NAME="sec:op_array"></A>
<BR>
Operadores sobre arrays
</H4>
El lenguaje OMI soporta una serie de operadores que pueden ser aplicados sobre un dato array.

<P>
<DL>
<DT><STRONG>Acceso a posición:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Acceso a final:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Tamaño:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
<PRE>
   foo = {"A","B"}; // foo es un array que contiene las cadenas "A" y "B"
   bar = {"A","B"}[0]; // bar vale "A"
   bar = foo[1]; // bar vale "B"
   bar = size foo; // bar vale 2
   foo[] = "C"; // foo es un array que contiene las cadenas "A", "B" y "C"
   bar = size foo; // bar vale 3
   foo = { "k0": "v0", "k1": "v1" }; // foo es un array asociativo con dos claves
   bar = { "k0": "v0", "k1": "v1" }["k0"]; // bar vale "v0"
   bar = foo["k1"]; // bar vale "v1"
   bar = size foo; // bar vale 2
   foo["k2"] = "v2"; // foo es un array asociativo con tres claves
   foo[] = "v3"; // foo es un array asociativo con cuatro claves
</PRE> 

<P>
Con el operador de acceso a posición es posible acceder a un determinado elemento
dentro del array. Para ello se debe facilitar el índice o la clave a la que 
se desea acceder. 

<P>
El operador de acceso a posición en array no realiza ninguna conversión de tipos sobre 
el índice o clave. Las claves son comparadas con el operador de igualdad (sec:op_cmp).

<P>
Si se accede mediante un índice o clave que no existe en el array se toma el valor nulo.

<P>
El operador de acceso a última posición por si solo toma el valor nulo, pero puede ser utilizado 
para añadir elementos al final del array. 

<P>
No es posible asignar a posiciones de un array constante. 
<BR>
<P>
<PRE>
   {1,2}[0] = 10; // se produce un error
   {"key":"val"}["key"] = "other"; // se produce un error
   {1,2}[] = 10; // se produce un error
</PRE> 

<P>
El operador de acceso es utilizado en otros tipos de datos como las cadenas
de caracteres.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de dato (\autoref{sec:data_type}).
   \item Tipo de dato array (\autoref{sec:type_array}).
   \item Funciones sobre array (\autoref{sec:func_array}).
   \item Operadores sobre cadenas de caracteres (\autoref{sec:op_string}).
\par
\end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054690000000000000"></A> <A NAME="sec:op_object"></A>
<BR>
Operadores sobre clases y objetos
</H4>

<P>
OMI es un lenguaje de programación orientado a objetos, por lo que pone a 
disposición del usuario un conjunto de operadores relacionados con estos. 
<BR>
<P>
<DL>
<DT><STRONG>Acceso a atributos y métodos:</STRONG></DT>
<DD>-<SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Instanciación de clases:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Acceso al objeto en ejecución:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN> 
</DD>
<DT><STRONG>Acceso al objeto padre en ejecución:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN> 
</DD>
<DT><STRONG>Acceso a la clase en ejecución:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
El uso de las clases y objetos quedan descritos en la sección correspondiente (sec:class).

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Clases de objetos (\autoref{sec:class}).
   \item Tipos de datos (\autoref{sec:data_type}).
   \item Tipos de datos objetos (\autoref{sec:type_object}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION000546100000000000000"></A> <A NAME="sec:op_func"></A>
<BR>
Operadores sobre funciones
</H4>

<P>
OMI define una serie de operadores que son aplicables a funciones. 

<P>
<DL>
<DT><STRONG>Llamada a función:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Aplicación parcial:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Acceso a función de contexto:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
El uso de las funciones queda descritos en la sección correspondiente (sec:function).

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Funciones (\autoref{sec:function}).
   \item Tipos de datos (\autoref{sec:data_type}).
   \item Tipos de datos funciones (\autoref{sec:type_func}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION000546110000000000000"></A> <A NAME="sec:op_typecheck"></A>
<BR>
Operadores comprobación de tipos
</H4>
En OMI existen una serie de operadores encargados de comprobar el tipo de un dato dado. Estos devolverán
un valor booleano que dependerá de que el dato sea del tipo indicado o no.

<P>
<DL>
<DT><STRONG>Comprobación de nulo:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Comprobación de booleano:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Comprobación de numérico:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Comprobación de cadena:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Comprobación de array:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Comprobación de objeto:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
<PRE>
   foo = isnull null; // foo es true
   foo = isnull 4; //foo es false
   foo = isbool true; //foo es true
   foo = isbool false; //foo es true
   foo = isbool 5; //foo es false
   foo = isnum 4; // foo es true
   foo = isnum "4"; // foo es false
   foo = isnum 4.6; // foo es true
   foo = isstring "4"; // foo es true
   foo = isstring 4; // foo es false
   foo = isarray {}; // foo es true
   foo = isarray {1,2}; // foo es true 
   foo = isarray "{1,2}"; // foo es false
   foo = isobject new Class1 (); // foo es true
   foo = isobject 5; // foo es false
</PRE> 

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de datos (\autoref{sec:data_type}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION000546120000000000000"></A> <A NAME="sec:op_cond"></A>
<BR>
Operadores condicionales
</H4>

<P>
Los operadores condicionales evalúan una expresión que hace de condición, y en función del resultado obtenido realizan una determinada operación.

<P>
<DL>
<DT><STRONG>Operador ternario:</STRONG></DT>
<DD><!-- MATH
 $cond\ ?\ op1:op2$
 -->
<SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Fusión de nulos:</STRONG></DT>
<DD><!-- MATH
 $[[ op1, op2,...,opn ]]$
 -->
<SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
En el operador ternario si la expresión de condición se cumple se toma el valor del operando precedido por ``?'', en caso contrario se toma el del último, que es precedido por ``:''. 
<BR>
<P>
<PRE>
   foo = (4 == 4)?"OP1":"OP2"; // foo vale "OP1"
   foo = (4 != 4)?"OP1":"OP2"; // foo vale "OP2"
   foo = 5?"OP1":"OP2"; // foo vale "OP1"
</PRE> 

<P>
Existe distintas formas del operador ternario además de la descrita. El operador ternario simplificado en valor verdadero omite el operando que se devolverá en el caso de que la condición 
sea cierta, en este caso se devolverá el valor de la expresión de condición. Por otro lado existe el ternario simplificado en valor falso, que omite el último operando
y que tomará el valor nulo. 
<BR>
<P>
<PRE>
   foo = 5?:"OP2"; // foo vale 5
   foo = 0?:"OP2"; // foo vale "OP2"
   foo = "COND"?"OP1"; // foo vale "OP1"
   foo = ""?"OP1"; // foo vale null
</PRE> 

<P>
La fusión de nulos opera sobre una lista de operandos. El operador comprueba los elementos secuencialmente y devuelve el primero que no sea nulo o nulo si todos los son. 
<BR>
<P>
<PRE>
   foo = [[ null, null, 4 ]]; // foo vale 4
   foo = [[ null, 4, 5 ]]; // foo vale 4
   foo = [[ null, null, null ]]; // foo vale null
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de datos (\autoref{sec:data_type}).
   \item Operadores lógicos (\autoref{sec:op_bool}).
   \item Operadores de comparación (\autoref{sec:op_cmp}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION000546130000000000000"></A> <A NAME="sec:op_io"></A>
<BR>
Operadores de entrada/salida
</H4>
OMMI presenta una serie de operadores que permiten leer de la entrada estándar o
escribir en la salida estándar.

<P>
<DL>
<DT><STRONG>Entrada estándar:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Salida estándar:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN> , <SPAN CLASS="MATH"></SPAN>
</DD>
</DL> 

<P>
El operador de entrada estándar tiene como operando una expresión variable. Este se encarga de leer un flujo de caracteres de
la entrada estándar hasta que lee un carácter fin de línea. El conjunto de caracteres leídos es asignado a la variable como
una cadena. 
<BR>
<P>
<PRE>
   &gt;&gt; foo; // Se lee de la entrada estándar hasta un carácter fin de linea y se introduce en foo
   input foo; // Igual que el caso anterior
</PRE>

<P>
El operador de entrada tiene una segunda forma en la que se puede indicar una cadena de caracteres
que se mostrará como prompt. 
<BR>
<P>
<PRE>
   /*
      Se lee de la entrada estándar hasta un carácter fin de linea 
      y se introduce en foo. Para indicar que se espera una entrada
      se utiliza la cadena "Example:"
   */
   &gt;&gt;["Example:"] foo;
</PRE>

<P>
Los operadores de salida estándar se encargan de escribir en esta una cadena de caracteres. 
Estos operadores se diferencian entre si, además de en su forma léxica, en si 
escriben un carácter de fin de línea automático o no. 

<BR><PRE>
   echo "Hola mundo"; // Escribe la cadena "Hola mundo" en la salida estándar
   &lt;. "Hola mundo"; // Escribe la cadena "Hola mundo" en la salida estándar
   &lt;&lt; "Hola mundo"; // Escribe la cadena "Hola mundo" en la salida estándar y un salto de linea
</PRE>

<P>
Es posible utilizar los operadores <SPAN CLASS="MATH"></SPAN> y <SPAN CLASS="MATH"></SPAN> para concatenar un flujo de cadenas de caracteres en la
salida estándar. En el caso del operador <SPAN CLASS="MATH"></SPAN> se resolverá como el operador de concatenación de cadenas 
<SPAN CLASS="MATH"></SPAN>, introduciendo las cadenas una seguida a la otra. Por otro lado, usar el operador <SPAN CLASS="MATH"></SPAN> implica que se
va a concatenar un salto de línea antes que la cadena
<BR>
<P>
<PRE>
   echo "Hola " . "mundo"; // Escribe la cadena "Hola mundo" en la salida estándar
   echo "Hola " &lt;. "mundo"; // Escribe la cadena "Hola mundo" en la salida estándar
   echo "Hola " &lt;&lt; "mundo"; // Escribe la cadena "Hola \mundo" en la salida estándar
   
   &lt;. "Hola " . "mundo"; // Escribe la cadena "Hola mundo" en la salida estándar
   &lt;. "Hola " &lt;. "mundo"; // Escribe la cadena "Hola mundo" en la salida estándar
   &lt;. "Hola " &lt;&lt; "mundo"; // Escribe la cadena "Hola \mundo" en la salida estándar
   
   &lt;&lt; "Hola " . "mundo"; // Escribe la cadena "Hola mundo\n" en la salida estándar
   &lt;&lt; "Hola " &lt;. "mundo"; // Escribe la cadena "Hola mundo\n" en la salida estándar
   &lt;&lt; "Hola " &lt;&lt; "mundo"; // Escribe la cadena "Hola \mundo\n" en la salida estándar
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Tipos de datos (\autoref{sec:data_type}).
   \item Operadores sobre cadenas de caracteres (\autoref{sec:op_string}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION000546140000000000000"></A> <A NAME="sec:op_pre"></A>
<BR>
Precedencia de operadores
</H4>

<P>
Una expresión puede estar compuesta por varios operadores, se establece pues prioridades entre estos que determinan 
cómo ha de resolverse la expresión. 

<P>
Los operadores quedan ordenados en el siguiente listado de más prioritarios a menos:

<P>
<DL>
<DT><STRONG>Llamadas:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Operadores de acceso:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, -<SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Incrementos y decrementos:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Conversión de tipos:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Operadores condicionales:</STRONG></DT>
<DD><!-- MATH
 $[[op1,...]]$
 -->
<SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Operaciones aritméticas de primer nivel:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, &#710;
</DD>
<DT><STRONG>Operaciones aritméticas de segundo nivel:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Operaciones aritméticas de tercer nivel:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Operaciones comparación:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Operaciones lógicas de primer nivel:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Operaciones lógicas de segundo nivel:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Operaciones lógicas de tercer nivel:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>
</DD>
<DT><STRONG>Asignaciones:</STRONG></DT>
<DD><SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, <SPAN CLASS="MATH"></SPAN>, &#710; =
</DD>
</DL> 

<P>
Los operadores en el mismo nivel de prioridad son resueltos mediante una asociación desde la izquierda, excepto los operadores de asignación que son asociativos desde la derecha.

<P>

<H3><A NAME="SECTION00054700000000000000"></A> <A NAME="sec:label"></A>
<BR>
Etiquetas
</H3>
Es posible etiquetar sentencias dentro del código fuente para poder cambiar el flujo de ejecución al punto que esta ocupa.

<P>
Una sentencia está formada por un identificador seguido del carácter ':' y la sentencia etiquetada.

<P>
<PRE>
   label: &lt;&lt; "Sentencia";
</PRE>

<P>
Las etiquetas normalmente son referenciadas por la sentencia de control <SPAN CLASS="MATH"></SPAN> la cual cambia el flujo de ejecución 
a la sentencia etiquetada. 

<P>
Normalmente se desaconseja el uso de etiquetas y sentencias <SPAN CLASS="MATH"></SPAN> dado que dificultan la legibilidad del código. No obstante OMI 
soporta este mecanismo de control.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Sentencia $goto$\  (\autoref{sec:stmt_goto}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H3><A NAME="SECTION00054800000000000000">
Sentencias de control</A>
</H3>

<P>
Las sentencias de control son construcciones del lenguaje que permiten alterar el flujo de ejecución del programa. Son muy comunes y
utilizadas en los lenguajes de programación.

<P>
Se clasifican según su naturaleza, así es posible ver sentencias de control condicionales, iterativas, de salto, inclusivas o de excepción.

<P>
Muchas sentencias de control están formadas por bloques de sentencias cuya ejecución controlan. Estos bloques pueden estar formados por una sola sentencia.

<P>

<H4><A NAME="SECTION00054810000000000000"></A><A NAME="sec:stmt_if"></A>
<BR>
Sentencia condicional <!-- MATH
 $if...\ else...$
 -->
<SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia condicional <!-- MATH
 $if...\ else...$
 -->
<SPAN CLASS="MATH"></SPAN> está formada por una expresión de condición, además de dos bloques de sentencias que serán ejecutadas en función la condición sea evaluada 
como verdadera o falsa. 
<BR>
<P>
<PRE>
   &gt;&gt;["Dime el valor de foo:"] foo;
   if ( foo &lt; 10) { 
      &lt;&lt; foo &lt;&lt; " es menor que 10"; // Se ejecuta si la condición es verdadera
   }
   else {
      &lt;&lt; foo &lt;&lt; " no es menor que 10"; // Se ejecuta si la condición es falsa
   }
</PRE>

<P>
Si el caso de evaluación negativa no implica la ejecución de ninguna sentencia, el bloque <SPAN CLASS="MATH"></SPAN> puede omitirse. 
<BR>
<P>
<PRE>
   &gt;&gt;["Dime el valor de foo:"] foo;
   if ( foo &lt; 10) { 
      &lt;&lt; foo &lt;&lt; " es menor que 10"; // Se ejecuta si la condición es verdadera
   }
</PRE>

<P>
Otra forma de esta sentencia condicional es <!-- MATH
 $if...\ elif...\ else...$
 -->
<SPAN CLASS="MATH"></SPAN>, en donde se anidan varias
sentencias de este tipo. Se pueden anidar tantos <SPAN CLASS="MATH"></SPAN> como sea necesario.
<BR>
<P>
<PRE>
   &gt;&gt;["Dime el valor de foo:"] foo;
   if ( foo &lt; 10) { 
      &lt;&lt; foo &lt;&lt; " es menor que 10"; // La primera condición es verdadera
   }
   elif (foo == 10) {
      &lt;&lt; foo &lt;&lt; " es igual que 10"; // La primera es falsa y la segunda verdadera
   }
   else {
      &lt;&lt; foo &lt;&lt; " es mayor que 10"; // Todas las condiciones son falsas
   }
</PRE>

<P>

<H4><A NAME="SECTION00054820000000000000">
Sentencia condicional <!-- MATH
 $switch...\ case...$
 -->
<SPAN CLASS="MATH"></SPAN></A>
</H4>
La sentencia <!-- MATH
 $switch...\ case...$
 -->
<SPAN CLASS="MATH"></SPAN> agiliza la toma de decisiones múltiples. Opera de igual forma que varios 
<!-- MATH
 $if...\ else...$
 -->
<SPAN CLASS="MATH"></SPAN> anidados, pero presenta una sintaxis que en muchos casos favorece la legibilidad y 
la rapidez de programación.

<P>
Se compone de un dato a comparar y un bloque de sentencias etiquetadas con casos. Los casos están formados por una expresión que 
será comparada con el dato. La ejecución pasará a la primera sentencia etiquetada
con el caso que sea igual al dato comparado, procediéndose a ejecutar todas las sentencias siguientes. 
<BR>
<P>
<PRE>
   &gt;&gt;["Sentencia inicial:"] foo;
   switch (foo) {
      case 0: 
         &lt;&lt; "Sentencia 0"; // Se ejecuta si foo es 0
      case 1:
         &lt;&lt; "Sentencia 1"; // Se ejecuta si foo es 0 o 1
      case 2:
         &lt;&lt; "Sentencia 2"; // Se ejecuta si foo es 0, 1 o 2
   }
</PRE>

<P>
Es una práctica muy común, para omitir la ejecución de algunas sentencias, el utilizar la sentencia <SPAN CLASS="MATH"></SPAN>, la cual finaliza la 
ejecución del bloque de sentencias actual. 
<BR>
<P>
<PRE>
   &gt;&gt;["Sentencia inicial:"] foo;
   switch (foo) {
      case 0: 
         &lt;&lt; "Sentencia 0"; // Se ejecuta si foo es 0
         break;
      case 1:
         &lt;&lt; "Sentencia 1"; // Se ejecuta si foo es 1
         break;
      case 2:
         &lt;&lt; "Sentencia 2"; // Se ejecuta si foo es 2
   }
</PRE>

<P>
Si ningún caso es igual al dato comparado no se ejecuta ninguna sentencia del bloque, a menos que se encuentre 
la etiqueta <SPAN CLASS="MATH"></SPAN>. 
<BR>
<P>
<PRE>
   &gt;&gt;["Sentencia a ejecutar:"] foo;
   switch (foo) {
      case 0: 
         &lt;&lt; "Sentencia 0"; // Se ejecuta si foo es 0
         break;
      case 1:
         &lt;&lt; "Sentencia 1"; // Se ejecuta si foo es 1
         break;
      case 2:
         &lt;&lt; "Sentencia 2"; // Se ejecuta si foo es 2
         break;
      default:
         &lt;&lt; "Sentencia por defecto"; // Se ejecuta si foo no es 0, 1 ni 2
   }
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Sentencia break (\autoref{sec:stmt_break}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION00054830000000000000"></A> <A NAME="sec:stmt_while"></A>
<BR>
Sentencia iterativa <SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <SPAN CLASS="MATH"></SPAN> es una estructura de control iterativa que permite la ejecución de un bloque de 
sentencias repetidamente mientras que se cumpla una determinada expresión de condición. Se compone pues de una expresión que será evaluada como 
un dato booleano y un bloque de sentencias. 
<BR>
<P>
<PRE>
   /*
      Imprime la cadena 
      "Sentencia" 10 veces.
   */
   foo = 0;
   while (foo &lt; 10) {
      &lt;&lt; "Sentencia"; 
      foo++;
   }
</PRE>

<P>
La expresión de condición es evaluada al comienzo de cada ejecución del bloque de sentencias, por lo que si alguna sentencia vuelve 
la condición falsa se seguirá con la ejecución del bloque hasta la próxima iteración.

<P>

<H4><A NAME="SECTION00054840000000000000"></A> <A NAME="sec:stmt_dowhile"></A>
<BR>
Sentencia iterativa <!-- MATH
 $do...\ while$
 -->
<SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <!-- MATH
 $do...\ while$
 -->
<SPAN CLASS="MATH"></SPAN> es una estructura de control iterativa que permite la ejecución de un bloque de 
sentencias repetidamente mientras que se cumpla una determinada expresión de condición, y al menos una vez. Se compone pues de una expresión que será evaluada como 
un dato booleano y un bloque de sentencias. 
<BR>
<P>
<PRE>
   /*
      Imprime la cadena 
      "Sentencia" 10 veces.
   */
   foo = 0;
   do {
      &lt;&lt; "Sentencia"; 
      foo++;
   } while (foo &lt; 10);
</PRE>

<P>
A diferencia de la sentencia <!-- MATH
 $do...\ while$
 -->
<SPAN CLASS="MATH"></SPAN> la condición es evaluada al final de la ejecución del bloque de sentencias por lo que se asegura que este
se ejecutará al menos una vez. Al igual que <!-- MATH
 $do...\ while$
 -->
<SPAN CLASS="MATH"></SPAN> si alguna sentencia vuelve falsa la condición se proseguirá con la ejecución hasta que se 
produzca la evaluación.

<P>

<H4><A NAME="SECTION00054850000000000000"></A> <A NAME="sec:stmt_for"></A>
<BR>
Sentencia iterativa <SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <SPAN CLASS="MATH"></SPAN> es una estructura de control iterativa que permite la ejecución de un bloque de 
sentencias repetidamente mientras que se cumpla una determinada expresión de condición. La sentencia <SPAN CLASS="MATH"></SPAN> conlleva
la ejecución de la expresión de inicialización al inicio de la sentencia, y de una expresión de iteración al final de cada ejecución del
bloque. 
<BR>
<P>
<PRE>
   /*
      Imprime la cadena 
      "Sentencia" 10 veces.
   */
   for (foo = 0; foo &lt; 10; ++foo){
      &lt;&lt; "Sentencia"; 
   }
</PRE>

<P>
Es OMI es necesario especificar todas las expresiones que conforman la sentencia <SPAN CLASS="MATH"></SPAN>, si alguno es omitido se
producirá un error sintáctico.

<P>

<H4><A NAME="SECTION00054860000000000000"></A> <A NAME="sec:stmt_foreach"></A>
<BR>
Sentencia iterativa <!-- MATH
 $for...\ as...$
 -->
<SPAN CLASS="MATH"></SPAN> y <!-- MATH
 $for...\ in...$
 -->
<SPAN CLASS="MATH"></SPAN>
</H4>

<P>
OMI ofrece unas formas de sentencias <SPAN CLASS="MATH"></SPAN> que permiten ejecutar un bloque de sentencias para cada elemento contenido 
en una determinada expresión. Para ello se debe especificar la expresión a recorrer, el símbolo variable con el 
que se referenciará al elemento actual y el bloque de sentencias que se ejecutará para cada elemento contenido 
en la expresión. 
<BR>
<P>
<PRE>
   /*
      Imprime la cadena 
      "Sentencia" y su índice 
      10 veces.
   */
   for ( 10 as i ){
      &lt;&lt; "Sentencia " . i; 
   }
   /*
      Imprime la cadena 
      "Sentencia" y su índice
      10 veces.
   */
   for ( i in 10 ){
      &lt;&lt; "Sentencia " . i; 
   }
</PRE>

<P>
La diferencias entre <!-- MATH
 $for...\ as...$
 -->
<SPAN CLASS="MATH"></SPAN> y <!-- MATH
 $for...\ in...$
 -->
<SPAN CLASS="MATH"></SPAN> son puramente sintácticas, siendo el orden en que se especifican la expresión conjunto y el
símbolo variable su principal diferencia.

<P>
El comportamiento de estas estructuras cambia en función el tipo de dato de la expresión conjunto. 

<P>
<DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>Si es true se ejecutará el bloque indefinidamente y el símbolo variable tendrá el valor true. Si es falso el bloque de sentencias no se ejecutará.
</DD>
<DT><STRONG>Numéricos:</STRONG></DT>
<DD>Si es mayor que se <SPAN CLASS="MATH">0</SPAN> el bloque se ejecutará desde 0 hasta el valor de la expresión y el símbolo variable tendrá el valor numérico de cada iteración.
En otro caso no se llega a ejecutar el bloque.
</DD>
<DT><STRONG>Cadenas de caracteres:</STRONG></DT>
<DD>Se ejecuta el bloque de sentencias por cada carácter en la cadena, el símbolo variable tomará como valor la cadena correspondiente al 
caracter de cada iteración.
</DD>
<DT><STRONG>Array:</STRONG></DT>
<DD>Se ejecuta el bloque de sentencias por cada elemento en el array, el símbolo variable tomará como valor el elemento de cada iteración.
</DD>
</DL> 

<P>
Es posible especificar un par de símbolos variables separados por el carácter ``:''. Esto hará que si el elemento actual en el recorrido tiene una clave que lo referencia esta se guarde en 
el primero y el valor en el segundo. Si no tuviera clave solo se asignará el valor al segundo símbolo variable. 
<BR>
<P>
<PRE>
   /*
      Imprime todas las 
      claves y valores del array
   */
   array = {'k0':'v0', 'k1':'v1', 'k2':'v2'};
   for ( array as key:value ){
      &lt;&lt; key . " =&gt; " . value; 
   }
</PRE>

<P>

<H4><A NAME="SECTION00054870000000000000"></A> <A NAME="sec:stmt_agil"></A>
<BR>
Sentencia iterativa ágil
</H4>

<P>
OMI ofrece una estructura de control iterativa cuya sintaxis ha sido simplificada, su funcionalidad extendida. La sentencia de control de iteración ágil funciona
igual que una sentencia <!-- MATH
 $for...\ in...$
 -->
<SPAN CLASS="MATH"></SPAN>, pero sin que se produzca una asignación de cada elemento a un símbolo variable. En su lugar se puede acceder al elemento 
en curso mediante un operador de acceso especial.

<P>
La sentencia de iteración ágil se compone de una expresión a recorrer y de un bloque de sentencias que se ejecutará para cada elemento en la expresión. 
<BR>
<P>
<PRE>
   /*
      Imprime la cadena 
      "Sentencia" 10 veces.
   */
   $(10){
      &lt;&lt; "Sentencia"; 
   }
</PRE>

<P>
Durante la ejecución del bloque de sentencias es posible acceder al elemento actual mediante el operador ``$''. 
<BR>
<P>
<PRE>
   /*
      Imprime la cadena 
      "Sentencia" y su índice 
      10 veces.
   */
  $(10){
      &lt;&lt; "Sentencia " . $; 
   }
</PRE>

<P>
Es posible anidar dos o más sentencias de iteración ágil y acceder al índice de cada una de ellas, añadiendo una expresión que se corresponde con el nivel de
anidamiento tras el operador ``$'' y delimitada entre llaves. 
<BR>
<P>
<PRE>
   /*
      Imprime las tablas de multiplicar del 
      0 al 9.
   */
  $(10){ // Nivel 0
    &lt;&lt; "Tabla de multiplicar del " . ${0};
    $(10) { // Nivel 1
      &lt;&lt; ${0} . " x " . ${1} . " = " . (${0} * ${1}); 
    }
  }
</PRE>

<P>
Si el operador de acceso no presenta índice este se corresponderá con el nivel actual.

<P>

<H4><A NAME="SECTION00054880000000000000"></A> <A NAME="sec:stmt_break"></A>
<BR>
Sentencia de salto <SPAN CLASS="MATH"></SPAN>
</H4>
La sentencia <SPAN CLASS="MATH"></SPAN> permite terminar la ejecución de un bloque de sentencias correspondientes a una estructura iterativa y saltar a la siguiente sentencia tras el bloque. 
<BR>
<P>
<PRE>
   /*
      Imprime el valor dado
      hasta que este es 0.
   */
  while(true){
    &gt;&gt;["Dame un valor (0 para salir)"] foo;
    if (foo === "0")
      break;
    &lt;&lt; foo;
  }
  &lt;&lt; "Finalizando";
</PRE>

<P>
Es posible salir de dos bloques iterativos que se encuentren anidados, indicando tras <SPAN CLASS="MATH"></SPAN> cuantos satos se desean realizar. 
<BR>
<P>
<PRE>
   /*
      Imprime el valor dado
      hasta que este es 0.
      Imprimiendo cuantas 
      solicitudes se han 
      realizado cada 10 veces
   */
   count = 0;
   while (true) {
     i = 0;
     while(i &lt; 10){
       &gt;&gt;["Dame un valor (0 para salir)"] foo;
       count ++;
       if (foo === "0")
         break 2;
       &lt;&lt; foo;
       i ++;
     }
     
     &lt;&lt; "Se han solicitado " . count . " valores ";
   }
  &lt;&lt; "Finalizando";
</PRE> 

<P>

<H4><A NAME="SECTION00054890000000000000"></A> <A NAME="sec:stmt_continue"></A>
<BR>
Sentencia de salto <SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <SPAN CLASS="MATH"></SPAN> permite terminar la ejecución actual de un bloque de sentencias correspondientes a una estructura iterativa. De esta forma se salta a la comprobación y 
ejecución (si fuera el caso) de la siguiente iteración. 
<BR>
<P>
<PRE>
   /*
      Imprime el valor dado,
      excepto si este es "jump",
      hasta que es 0.
   */
  while(true){
    &gt;&gt;["Dame un valor (0 para salir, jump para saltar)"] foo;
    if (foo === "0")
      break;
   if (foo === "jump")
      continue;
   &lt;&lt; foo;
  }
  &lt;&lt; "Finalizando";
</PRE>

<P>
Es posible utilizar la sentencia <SPAN CLASS="MATH"></SPAN> para saltar a la siguiente iteración de una estructura iterativa concreta de varias anidadas. Para ello tras el literal 
se debe indicar una expresión cuyo valor sea el número de bloques anidados que se desea saltar. 
<BR>
<P>
<PRE>
   /*
      Imprime el valor dado hasta que este es 0.
      Imprimiendo cuantas solicitudes se han realizado cada 10 veces.
      Es posible forzar el reinicio del contador mediante el valor "restart"
   */
   count = 0;
   while (true) {
     i = 0;
     while(i &lt; 10){
       &gt;&gt;["Dame un valor (0 para salir, restart para reiniciar contador)"] foo;
       count ++;
       if (foo === "0")
         break 2;
       if (foo === "restart"){
         &lt;&lt; "Reiniciando contador ";
         count = 0;
         continue 2;
       }
       &lt;&lt; foo;
       i ++;
     }
     &lt;&lt; "Se han solicitado " &lt;&lt; count &lt;&lt; " valores ";
   }
  &lt;&lt; "Finalizando";
</PRE> 

<P>

<H4><A NAME="SECTION000548100000000000000"></A> <A NAME="sec:stmt_goto"></A>
<BR>
Sentencia de salto <SPAN CLASS="MATH"></SPAN>
</H4>
La sentencia <SPAN CLASS="MATH"></SPAN> se compone de un identificador y  permite cambiar el flujo de ejecución a la sentencia etiquetada con dicho identificador. 
<BR>
<P>
<PRE>
   /*
      Se imprime la cadena
      "Sentencia" indefinidamente
   */
   label: &lt;&lt; "Sentencia";
   goto label;
</PRE>

<P>
En general se desaconseja el uso de etiquetas y sentencias <SPAN CLASS="MATH"></SPAN> dado que dificultan la legibilidad del código.

<P>
Lo habitual es que la sentencia <SPAN CLASS="MATH"></SPAN> se encuentre condicionada para que el salto no se ejecute siempre. 
<BR>
<P>
<PRE>
   /*
      Se imprime la cadena
      "Sentencia" 10 veces
   */
   foo = 0;
   label: &lt;&lt; "Sentencia " . foo;
   if (foo &lt; 10){
      foo++;
      goto label;
   }
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Etiquetas (\autoref{sec:label}).
   \item Sentencia condicional $if...\ else...$\  (\autoref{sec:stmt_if}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION000548110000000000000"></A> <A NAME="sec:stmt_include"></A>
<BR>
Sentencia <SPAN CLASS="MATH"></SPAN>
</H4>
La sentencia <SPAN CLASS="MATH"></SPAN> permite separar el código fuente en diferentes ficheros. Se compone de una 
expresión que se corresponde con el fichero a incluir. Al ser evaluada,
la ejecución pasa a la primera sentencia en el fichero. 
<BR>
<P>
<PRE>
   /*
      fichero1.omi
      Se imprime el contenido de este fichero
      y se incluye el fichero 2
   */
   &lt;&lt; "Contenido fichero 1";
   include "fichero2.omi";
</PRE>

<P>
<PRE>
   /*
      fichero2.omi
      Se imprime el contenido de este fichero
   */
   &lt;&lt; "Contenido fichero 2";
</PRE>

<P>
Si la cadena facilitada como expresión no se corresponde con un fichero del sistema
se producirá un error y finalizará la ejecución del script.

<P>

<H4><A NAME="SECTION000548120000000000000"></A> <A NAME="sec:stmt_exit"></A>
<BR>
Sentencia <SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <SPAN CLASS="MATH"></SPAN> permite finalizar la ejecución del script en cualquier parte del mismo. 
<BR>
<P>
<PRE>
   /*
      Finaliza el script sin llegar 
      a ejecuta la ultima sentencia
   */
   &lt;&lt; "SENTENCIA EJECUTADA";
   exit;
   &lt;&lt; "SENTENCIA NO EJECUTADA";
</PRE>

<P>
A diferencia de otros lenguajes de programación en OMI no existe una forma de finalizar el script 
devolviendo un estado de error.

<P>

<H4><A NAME="SECTION000548130000000000000"></A> <A NAME="sec:stmt_with"></A>
<BR>
Sentencia <SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <SPAN CLASS="MATH"></SPAN> permite establecer un objeto como contexto dentro de un bloque de sentencias. Se forma mediante
una expresión correspondiente al objeto y un bloque de sentencias que será ejecutada con el objeto como contexto. 

<P>
Cuando se establece un objeto como contexto todas las funciones que se llamen, y que no se encuentren definidas, serán 
llamadas como métodos del objeto. 
<BR>
<P>
<PRE>
   class Foo {
      ~ identity () {
         &lt;&lt; "Soy Foo";
      } 
   }
   foo = new Foo ();
   with (foo) {
      identity(); // Llama al método identity del objeto foo
   }
</PRE>

<P>

<H4><A NAME="SECTION000548140000000000000"></A> <A NAME="sec:stmt_try"></A>
<BR>
Sentencia <!-- MATH
 $try...\ catch...$
 -->
<SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <!-- MATH
 $try...\ catch...$
 -->
<SPAN CLASS="MATH"></SPAN> permite delimitar mediante un bloque de sentencias 
un comportamiento en el que se pueden dar excepciones. Además, mediante otro 
bloque de sentencias y un símbolo variable, se puede especificar cómo serán tratadas
las excepciones que se den.

<P>
A diferencia de otros lenguajes de programación OMI solo permite un bloque de 
sentencias <SPAN CLASS="MATH"></SPAN>. No comprueba la clase de la excepción que se ha dado, esto recae
en resposabilidad del programador. 
<BR>
<P>
<PRE>
   class Exc {
      var = null;
      ~ Exc (num) {
         this-&gt;var = num;
      }
      ~ printError () {
         &lt;&lt; "Error " . this-&gt;var;
      }
   }
   try {
      &gt;&gt;["Dame un valor:"] foo;
      if ( foo === "" ){
         throw new Exc (404);
      } 
      &lt;&lt; foo;
   }catch (exc) {
      exc-&gt;printError ();
   }
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Excepciones (\autoref{sec:exception}).
   \item Sentencia  $throw$\  (\autoref{sec:stmt_throw}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION000548150000000000000"></A> <A NAME="sec:stmt_throw"></A>
<BR>
Sentencia <SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <SPAN CLASS="MATH"></SPAN> permite lanzar una excepción que puede ser atrapada por una 
sentencia <!-- MATH
 $try...\ catch...$
 -->
<SPAN CLASS="MATH"></SPAN>. Esta sentencia se construye mediante una expresión cuyo 
valor será asociado al símbolo variable del bloque de sentencias <SPAN CLASS="MATH"></SPAN>. 
<BR>
<P>
<PRE>
   class Exc {
      var = null;
      ~ Exc (num) {
         this-&gt;var = num;
      }
      ~ printError () {
         &lt;&lt; "Error " &lt;&lt; this-&gt;var;
      }
   }
   try {
      &gt;&gt;["Dame un valor:"] foo;
      if ( foo === "" ){
         throw new Exc (404);
      } 
      &lt;&lt; foo;
   }catch (exc) {
      exc-&gt;printError ();
   }
</PRE>

<P>
Si una excepción lanzada con <SPAN CLASS="MATH"></SPAN> no sucede dentro de una sentencia <!-- MATH
 $try...\ catch$
 -->
<SPAN CLASS="MATH"></SPAN> controlada
se producirá un error y se detendrá la ejecución del script.

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Excepciones (\autoref{sec:exception}).
   \item Sentencia  $try...\ catch...$\  (\autoref{sec:stmt_try}).
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H4><A NAME="SECTION000548160000000000000"></A> <A NAME="sec:stmt_sleep"></A>
<BR>
Sentencia <SPAN CLASS="MATH"></SPAN>
</H4>

<P>
La sentencia <SPAN CLASS="MATH"></SPAN> hace que la ejecución del programa se pare un número de segundos dados. 
<BR>
<P>
<PRE>
   &lt;&lt; "Antes de parar";
   sleep (10);
   &lt;&lt; "Tras 10 segundos";
</PRE>

<P>

<H4><A NAME="SECTION000548170000000000000"></A> <A NAME="sec:stmt_typeof"></A>
<BR>
Sentencia <SPAN CLASS="MATH"></SPAN>
</H4>
La sentencia <SPAN CLASS="MATH"></SPAN> imprime en la salida estándar el tipo de dato del valor 
referenciado por un símbolo variable. 
<BR>
<P>
<PRE>
   foo = 10;
   typeof foo; // Imprime Arithmetic
   foo = "STR";
   typeof foo; // Imprime String
   foo = {1,2};
   typeof foo; // Imprime Array(2)
</PRE>

<P>

<H4><A NAME="SECTION000548180000000000000"></A> <A NAME="sec:stmt_datInfo"></A>
<BR>
Sentencia <SPAN CLASS="MATH"></SPAN>
</H4>
La sentencia <SPAN CLASS="MATH"></SPAN> permite consultar el estado interno de un dato. Esto
es la posición de memoria que ocupa, el tipo y el número de referencias que tiene. 
<BR>
<P>
<PRE>
   datInfo 5; // Imprime ptr(0x1d72e00), type(Arithmetic: 5), refs(0)
   datInfo "A"; // Imprime ptr(0x1d72f70), type(String: A), refs(0)
   foo = 10;
   datInfo foo; // ptr(0x1d73f00), type(Arithmetic: 10), refs(1)
   bar = foo;
   datInfo bar; // ptr(0x1d73f00), type(Arithmetic: 10), refs(2)
</PRE>

<P>
La sentencia <SPAN CLASS="MATH"></SPAN> también admite la forma <SPAN CLASS="MATH"></SPAN>.

<P>

<H3><A NAME="SECTION00054900000000000000">
Variables</A>
</H3>
En programación una variable se define como un espacio que es asociado a un nombre o identificador, el contenido alojado en dicho espacio es llamado el valor de la variable.
Mediante el nombre es posible utilizar la variable en expresiones con independencia de la información exacta que esta referencia. Cuando una expresión que contiene una variable es resuelta
se obtiene el valor contenido en la misma. 

<P>
El valor de una variable puede cambiar durante la ejecución del programa. Para alterar el contenido de una variable lo habitual es utilizar el operador de asignación. 
En OMI la asignación de una variable es destructiva, es decir, la variable modifica su valor sobrescribiendo el valor anterior. 

<P>
Las variables suponen un recurso esencial para los lenguajes de programación imperativos, ya que son el mecanismo básico para guardar el estado del sistema. Las variables en matemáticas
forman parte de definiciones y una vez atribuido su valor este no variará, esto difiere del concepto de variable que presentan los lenguajes de programación imperativos. 

<P>
OMI es un lenguaje de programación de tipado dinámico, y por tanto, el tipo de dato de una variable está determinado por el valor actual de la misma, y no se encuentra 
asociado a la variable. En un momento dado una variable podría contener un valor entero, y en otro una cadena de caracteres. 

<P>
En OMI el tipo de dato del valor almacenado en una variable es desconocido hasta que es obtenido en la resolución de una expresión. Los operadores, funciones y demás recursos
del lenguaje usan el valor para operar, con independencia de la variable que lo contuviera.

<P>
En OMI no es necesario declarar ni inicializar una variable antes de su uso. Si una variable sin valor es usada en una expresión se toma el valor nulo.

<P>
Internamente OMI representa las variables como referencias a los valores, más que como contenedores de estos. En OMI no es necesario llevar una gestión los datos que han sido
creados y asignados a las variables de forma dinámica, un subsistema denominado recolector de basura será el encargado de esta tarea.

<P>
Las variables deben ser nombradas mediante un identificador válido, y no deben coincidir con ninguna palabra reservada. 

<P>
Las variables en OMI pueden presentar un ámbito local y global. Una variable puede ser local al flujo principal o a una función o método. Por defecto las variables son locales.
Una variable local solo puede ser accesible desde donde se utilizó inicialmente. Si en otro lugar se hace uso del mismo identificador se consideran variables distintas.
Las variables globales son accesibles desde cualquier parte de la aplicación. Para usar una variable como global debe ser declarada como tal con el literal <SPAN CLASS="MATH"></SPAN>. 
<BR>
<P>
<PRE>
   foo = 10; // foo es una variable local al flujo principal
   global bar; // bar es una variable global.
   bar = 20; 
   ~ func () {
      foo = 30; // foo es una variable local a la función func
      bar = 40; // Se asigna a la variable global bar
   }
</PRE>

<P>
<!-- MATH
 $\fbox{\parbox[c]{\textwidth}{\tiny{
   Para más información:
   \begin{itemize}
   \setlength{\itemsep}{1px}
   \item Operador de asignación (\autoref{sec:op_asig}).
   \item Identificadores (\autoref{sec:id})
   \end{itemize}
}}}$
 -->
<SPAN CLASS="MATH"></SPAN>

<P>

<H3><A NAME="SECTION000541000000000000000">
Referencias</A>
</H3>
Una referencia es un valor que permite acceder indirectamente a un dato almacenado en un símbolo variable. Cuando 
se opera sobre una referencia se hace sobre el dato almacenado en la variable.

<P>
Es posible obtener una referencia anteponiendo el símbolo ``<SPAN CLASS="MATH"></SPAN>'' ante el símbolo variable. 
<BR>
<P>
<PRE>
   foo = 10;
   bar = &amp;foo; // Se obtiene una referencia de foo
   &lt;&lt; foo . " - " . bar; // Imprime 10 - 10
   bar = 20; 
   &lt;&lt; foo . " - " . bar; // Imprime 20 - 20
</PRE>

<P>
En OMI es posible obtener una referencia de cualquier expresión que sea variable, y acceder su valor de forma indirecta. Así por
ejemplo se puede obtener una referencia a una posición de un array, a un atributo de un objeto, etc. 
<BR>
<P>
<PRE>
   foo = {{1,2}, 3}; 
   bar = &amp;foo[0][1];
   bar = 4;
   &lt;&lt; foo[0][1];
</PRE>

<P>
No es posible obtener una referencia a una posición dentro de una cadena, esto es debido a que en OMI las cadenas de caracteres son un tipo de dato simple.  
En su lugar se copiará el valor del carácter en la posición como otra cadena, por lo que la referencia no tendrá efecto. 
<BR>
<P>
<PRE>
   foo = "ABCD"; 
   bar = &amp;foo[0];
   bar = "Z";
   &lt;&lt; bar; // Imprime "Z"
   &lt;&lt; foo; // Imprime "ABCD". La referencia no tiene efecto.
</PRE>

<P>
Sintácticamente es posible obtener una referencia de un valor constante, no obstante esto hará que se tome el valor en si, sin que tenga efecto alguno.

<P>
Las referencias pueden ser utilizadas como un dato, por lo que pueden ser pasadas como parámetro. En este caso cualquier acceso al parámetro dentro de la función 
se hará sobre las variables a las que referencia. 
<BR>
<P>
<PRE>
   ~ inc (param) {
      param += 1;
   }
   
   a = 20;
   inc(&amp;a);
   &lt;&lt; a; // Imprime 21
</PRE>

<P>
Es posible hacer que algunos parámetros de una función sean pasados siempre por referencia. Para ello se antepone <SPAN CLASS="MATH"></SPAN> al parámetro en la definición de
la función. Ver paso de parámetros por referencia (sec:func_ref).

<P>
Las funciones y métodos pueden devolver referencias. De esta forma si una llamada a función es asignada se hará la operación sobre la referencia devuelta, 
por lo que cualquier acceso se hará sobre el símbolo variable a la que esta apunta. Si la referencia es a un símbolo variable de ámbito local, el cual es liberado al terminar la llamada, 
el valor será copiado. 
<BR>
<P>
<PRE>
   class example {
      private attr = null;
      
      ~ example (attr) {
         this-&gt;attr = attr;
      }
      
      ~ getRef () {
         return &amp;this-&gt;attr;
      }
      
      ~ printAttr () {
         &lt;&lt; this-&gt;attr;
      }
   }
   
   foo = new example (20);
   foo-&gt;printAttr(); // Imprime 20
   &lt;&lt; foo-&gt;attr; // Error acceso a elemento privado
   bar = foo-&gt;getRef(); // bar es una referencia a foo-&gt;attr
   bar = 40; 
   foo-&gt;printAttr(); // Imprime 40
</PRE>

<P>

<H3><A NAME="SECTION000541100000000000000"></A> <A NAME="sec:function"></A>
<BR>
Funciones
</H3>
Una función es un conjunto de sentencias que tienen un objetivo particular. Se corresponde con un
subalgoritmo dentro del algoritmo principal.

<P>
Una función se define normalmente mediante un identificador, una lista de parámetros (delimitados por paréntesis y separados por coma) y un bloque de sentencias. La
definición de una función debe empezar por el carácter ``<SPAN CLASS="MATH"></SPAN>'' o la palabra reservada <SPAN CLASS="MATH"></SPAN>. 
<BR>
<P>
<PRE>
   ~ func1 (param1, param2) { 
      &lt;&lt; "Soy fun1 con dos parametros:";
      &lt;&lt; "param1 =&gt; " . param1;
      &lt;&lt; "param2 =&gt; " . param2;
   }
   
   function func2 (param1, param2) { 
      &lt;&lt; "Soy func2 con dos parametros:";
      &lt;&lt; "param1 =&gt; " . param1;
      &lt;&lt; "param2 =&gt; " . param2;
   }
</PRE>

<P>
Los parámetros de la función suponen un mecanismo para que esta pueda recibir datos con los que operar
y realizar su tarea. Los parámetros son variables que pueden ser utilizadas en el bloque de sentencias
y cuyos valores serán dado cuando la función es llamada.

<P>
Las funciones pueden ser llamadas desde cualquier parte del código, lo que supondrá la ejecución del bloque
de sentencias. Para realizar una llamada a una función se utilizará el nombre de la función seguido de los 
valores que serán atribuidos a los parámetros, delimitados por paréntesis y separados por coma. La atribución
de valores a los parámetros se hace de forma posicional. 
<BR>
<P>
<PRE>
   ~ func1 (param1, param2) { 
      &lt;&lt; "Soy fun1 con dos parametros:";
      &lt;&lt; "param1 =&gt; " . param1;
      &lt;&lt; "param2 =&gt; " . param2;
   }
   
   func1 ("valor1", "valor2");
</PRE>

<P>
En una llamada los parámetros son pasados, a no ser que se indique lo contrario, por valor. Esto quiere decir 
que los valores son copiados a los parámetros, lo que implica que cualquier modificación de estos solo tendrá efecto en el bloque 
que define la función. 
<BR>
<P>
<PRE>
   ~ func1 (foo) { 
      foo = 20;
      &lt;&lt; foo;  // Imprime 20
   }
   
   foo = 40;
   func1 (foo);
   &lt;&lt; foo; // Imprime 40
</PRE>

<P>
Una función puede devolver un valor que será atribuido a la llamada. Para ello 
se hace uso de la sentencia <SPAN CLASS="MATH"></SPAN>. Esta sentencia, que puede formar parte del
bloque de sentencias de una función, esta formada por el valor que será devuelto 
y atribuido a la llamada. La ejecución de la sentencia <SPAN CLASS="MATH"></SPAN> implica 
la finalización de la función.

<P>
La llamada a un función es considerada un operador y puede formar parte de expresiones. El
valor de la llamada es dado por la ejecución de la sentencia <SPAN CLASS="MATH"></SPAN> en el bloque de sentencias
de esta. Si la ejecución de la función termina sin una sentencia <SPAN CLASS="MATH"></SPAN> se tomará el valor nulo. 
<BR>
<P>
<PRE>
   ~ sum (op1, op2) { 
      return op1 + op2;
   }
   
   &lt;&lt; sum(1,2) * 4; // Imprime 12
</PRE> 

<P>
Las llamadas a función son resueltas antes que cualquier otro operador, ya que presentan el mayor nivel de prioridad. 

<P>
Si una función es llamada sin que esta se encuentre definida se producirá un error semántico. También se producirá 
un error si el número de valores facilitados como parámetros en la llamada no se corresponden con la definición de la función. Cabe destacar 
que las definiciones de funciones son ejecutadas de forma secuencial dentro del flujo del programa, por lo que realizar 
un llamada de un función que se encuentre definida en sentencias posteriores producirá un error como si esta no
se encontrara definida, por ello es buena práctica disponer las definiciones de funciones al comienzo del programa.

<P>
Los nombres de las funciones deben seguir las reglas normales de uso de identificadores, y no corresponderse con ninguna
palabra reservada.

<P>
Si dos o más definiciones de función comparten el mismo identificador la última definición interpretada será la que se corresponda
con dicho identificador. 
<BR>
<P>
<PRE>
   ~ func () { 
      &lt;&lt; "FUNC 1";
   }
   
   ~ func () { 
      &lt;&lt; "FUNC 2";
   }
   
   func(); // Imprime "FUNC 2"
</PRE> 

<P>
A pesar de ser considerado un lenguaje imperativo, OMI presenta algunos recursos y mecanismos propios de la programación funcional. En las 
subsecciones siguientes se presentan los recursos y mecanismos que pueden ser utilizados y aplicados a las funciones. 

<P>

<H4><A NAME="SECTION000541110000000000000">
Parámetros con valores por defecto</A>
</H4>
En OMI es posible definir funciones cuyos parámetros presenten un valor por defecto, es decir, en caso de ser omitido en una llamada
dicho parámetro tendrá el valor especificado. 

<P>
En una llamada es obligatorio dar el valor de todos los parámetros excepto los que tienen definido un valor por defecto. Dado que la 
atribución de valores a los parámetros se hace de forma posicional, los parámetros con valores por defecto serán los últimos
para que puedan omitirse en la llamada. 

<P>
En la definición de una función se puede especificar que determinados parámetros tendrán valores por defecto siguiendo estos mediante el 
signo igual y el valor que tendrán. 
<BR>
<P>
<PRE>
   ~ sum (op1, op2 = 4) { 
      return op1 + op2;
   }
   
   &lt;&lt; sum(1,2) * 4; // Imprime 12
   &lt;&lt; sum(1) * 4; // Imprime 20
</PRE> 

<P>

<H4><A NAME="SECTION000541120000000000000"></A> <A NAME="sec:func_ref"></A>
<BR>
Paso de parámetros por referencia
</H4>
Por defecto los parámetros de una llamada a función son pasados por valor, lo que implica que cualquier modificación 
en los mismos dentro de la función no tendrá efecto fuera de esta. 

<P>
Es posible definir funciones donde algunos parámetros sean pasado como referencia en las llamadas. Esto es que si
en la llamada se facilita un símbolo variable como valor de dicho parámetro, cualquier modificación realizada 
en el mismo será aplicado a la variable fuera de la función. 

<P>
En la definición de una función se puede indicar que un determinado parámetro será pasado por referencia anteponiendo
el símbolo ``SPMamp;'' a dicho parámetro. 
<BR>
<P>
<PRE>
   ~ func1 (&amp;foo) { 
      foo = 20;
      &lt;&lt; foo;  // Imprime 20
   }
   
   foo = 40;
   func1 (foo);
   &lt;&lt; foo; // Imprime 20
</PRE>

<P>
Si un valor constante es dado como parámetro por referencias se producirá un error.

<P>

<H4><A NAME="SECTION000541130000000000000">
Definición como parte de expresiones</A>
</H4>

<P>
En OMI las funciones son consideradas tipos de datos, por lo que es posible asignarlas 
a variables, operar sobre ellas, etc. Sin embargo, no se puede realizar una conversión
de una función a otro tipo de dato y viceversa, por lo que la mayoría de operadores producirán 
un error al resolverse si operan con una función y otro tipo de dato.

<P>
Es posible utilizar la definición de una función como expresión en una operación de asignación. 
<BR>
<P>
<PRE>
   foo = ~ sum (param1, param2) { return param1 + param2; };
   &lt;&lt; foo (4, 5); // Imprime 9
   ((x &lt; 10)?~(){&lt;&lt;"A";}:~(){&lt;&lt;"B"})(); // Si x &lt; 10 imprime "A", si no imprime "B"
</PRE>

<P>

<H4><A NAME="SECTION000541140000000000000">
Referencias a funciones </A>
</H4>
En OMI se nombran de igual forma a las funciones, las variables y las clases. Para determinar 
si un identificador en una expresión hace referencia a una función u otro elemento se utiliza 
el contexto. 

<P>
En muchos casos es necesario indicar explícitamente que el objeto que se desea utilizar es una 
función ya definida, y no una variable u otro elemento. Para ello se antepone al identificador 
de la función el par de símbolos ``<SPAN CLASS="MATH"></SPAN>''. 
<BR>
<P>
<PRE>
   ~ foo () {
      return "FUNCIÓN";
   }
   foo = "VARIABLE";
   bar = foo; // bar vale "VARIABLE";
   bar = ~&amp;foo; // var vale la función que devuelve "FUNCIÓN"
</PRE>

<P>
Por regla general todos los operadores toman, a no ser que se indique lo contrario, 
los identificadores como variables. Las excepciones a esta regla son los 
siguientes operadores:

<P>

<UL>
<LI>Llamada a función 
</LI>
<LI>Aplicación parcial
</LI>
<LI><SPAN CLASS="MATH"></SPAN>.
</LI>
</UL>

<P>

<H4><A NAME="SECTION000541150000000000000">
Funciones anónimas</A>
</H4>
OMI permite definir funciones sin identificador que las nombre, lo que se denomina funciones 
anónimas. Normalmente las funciones anónimas son utilizadas
como dato en otras expresiones. 

<P>
Para definir una función anónima solo se ha de omitir el identificador. 
<BR>
<P>
<PRE> 
   bar = foo = ~() { &lt;&lt; "FUNCIÓN ANÓNIMA"; };
   foo(); // IMPRIME "FUNCIÓN ANÓNIMA"; 
   bar(); // IMPRIME "FUNCIÓN ANÓNIMA";
</PRE>

<P>

<H4><A NAME="SECTION000541160000000000000">
Expresiones parametrizadas</A>
</H4>
p
Una expresión parametrizada es similar a una función. Permite definir una expresión a partir de unos parámetros. 

<P>
La expresión parametrizada puede ser utilizada como dato para llevar a cabo operaciones sobre ella. Así es posible asignarla, 
llamarla con unos valores dado, ser devuelta como valores de función, etc.

<P>
Para definir una expresión parametrizada se utiliza el símbolo ``<SPAN CLASS="MATH"></SPAN>'' seguido de una lista de parámetros separados por coma, el símbolo ``:'' y la expresión 
a parametrizar, la cual normalmente hará uso de los parámetros. Es posible obtener el valor para unos determinados parámetros utilizando 
el operador de llamada a función. 
<BR>
<P>
<PRE> 
   sum = ~ x, y : x + y;
   &lt;&lt; sum (4,5);
</PRE>

<P>

<H4><A NAME="SECTION000541170000000000000">
Funciones de orden superior</A>
</H4>

<P>
Las funciones de orden superior son funciones que cumplen una de las siguientes premisas:

<P>

<UL>
<LI>Reciben como parámetros una o más funciones.
</LI>
<LI>Devuelven como valor una función.
</LI>
</UL>

<P>
En OMI las funciones son tipos de datos, por lo que es posible crear funciones de orden superior de
forma natural a la sintaxis del lenguaje. 
<BR>
<P>
<PRE>
   ~ call (f) {  // Funcón de orden superior que recibe una función como parámetro
      f();
   }
   
   ~ printA () { &lt;&lt; "A" }
   ~ printB () { &lt;&lt; "B" }
   
   call (~&amp;printA); // Imprime A
   call (~&amp;printB); // Imprime B
</PRE>

<P>

<BR>
<P>
<PRE>
   ~ getOp (code) {  // Función de orden superior que devuelve una función
      switch (code) {
         case 0:  return ~(a,b) { return a + b }; break;
         case 1: return ~(a,b) { return a - b }; break;
         default: return ~(a,b) { &lt;&lt; "WRONG CODE"; return null; }
      }
   }
   
   func = getOp (0);
   &lt;&lt; func (4, 5); // Imprime 9
   
   func = getOp (1);
   &lt;&lt; func (4, 5); // Imprime -1
   
   func = getOp ("*");
   &lt;&lt; func (4, 5); // Imprime "WRONG CODE"
</PRE>

<P>

<H4><A NAME="SECTION000541180000000000000">
Clausura de funciones</A>
</H4>
Si una función es definida en el bloque de sentencias de otra, cuando la función interna sea llamada, en su ejecución podrá 
acceder a las variables definidas en el bloque en el momento en el que se definió.

<P>
La clausura permite que funciones que sean definidas en un entorno puedan acceder a las variables de dicho entorno. 
<BR>
<P>
<PRE>
   ~ addX (X) { 
      return ~(num) {
         return num + X; // X pertenece al entorno de addX
      }
   }
   
   add1 = addX(1);
   add2 = addX(2);
   
   &lt;&lt; add1 (4); // Imprime 5
   &lt;&lt; add2 (4); // Imprime 6
</PRE>

<P>

<H4><A NAME="SECTION000541190000000000000">
Función de contexto</A>
</H4>
Por regla general la función de contexto se refiere a la función en ejecución. En OMI es 
posible acceder a la función de contexto mediante el operador ``<SPAN CLASS="MATH"></SPAN>'', esto permite definir 
funciones recursivas de forma simple. 
<BR>
<P>
<PRE>
   ~ factorial (num) {
      if (num == 2) return 2;
      return num * ~&gt;(num-1);
   }
</PRE>

<P>
En otros casos la función de contexto puede mantener otras referencias diferentes a la función 
en ejecución.

<P>

<H4><A NAME="SECTION0005411100000000000000">
Decoradores</A>
</H4>

<P>
Un decorador es una función que:

<UL>
<LI>Toma una función como parámetro. 
</LI>
<LI>Devuelve otra función que utiliza la función recibida como parámetro en su bloque de sentencias.
</LI>
</UL>

<P>
Es posible crear un decorador mediante funciones gracias al principio de clausura. 
<BR>
<P>
<PRE>
   ~ generateFileHTML (func) { //Decorador mediante funciones
      return ~(title, params){
         &lt;&lt; "&lt;html&gt;";
         &lt;&lt; "&lt;head&gt;";
         &lt;&lt; "&lt;title&gt;" &lt;&lt; title &lt;&lt; "&lt;/title&gt;";
         &lt;&lt; "&lt;/head&gt;";
         &lt;&lt; "&lt;body&gt;";
         func(params);
         &lt;&lt; "&lt;/body&gt;";
         &lt;&lt; "&lt;/html&gt;";
      }
   }
   
   search = ~(params) { &lt;&lt; "Buscando: " &lt;&lt; params; };
   info = ~(params) { &lt;&lt; "Información sobre: " &lt;&lt; params; };
   
   generateSearchHTML = generateFileHTML (search);
   generateInfoHTML = generateFileHTML (info);
   
   generateSearchHTML("Búsqueda", "concepto");
   generateInfoHTML("Información", "producto");
</PRE>

<P>
En OMI existe una construcción propia del lenguaje denominada decorador. Esta simplifica el 
proceso anterior. Un decorador se define de forma parecida a una función: presenta un identificador 
que lo nombra, una lista de parámetros y un bloque de sentencias. La lista de parámetros se corresponde 
con los que recibirá la función devuelta por el decorador, la cual se definirá a partir del 
bloque de sentencias. En el bloque de sentencias se podrá hacer referencia a la función a 
decorar mediante el operador de función de contexto ``<SPAN CLASS="MATH"></SPAN>''. Para definir un decorador se utiliza
el literal ``<SPAN CLASS="MATH"></SPAN>''. 
<BR>
<P>
<PRE>
   ~~ generateFileHTML (title, params) { // Decorador mediante construcciones del lenguaje
      &lt;&lt; "&lt;html&gt;";
      &lt;&lt; "&lt;head&gt;";
      &lt;&lt; "&lt;title&gt;" &lt;&lt; title &lt;&lt; "&lt;/title&gt;";
      &lt;&lt; "&lt;/head&gt;";
      &lt;&lt; "&lt;body&gt;";
      ~&gt;(params);
      &lt;&lt; "&lt;/body&gt;";
      &lt;&lt; "&lt;/html&gt;";
   }
   
   search = ~(params) { &lt;&lt; "Buscando: " &lt;&lt; params; };
   info = ~(params) { &lt;&lt; "Información sobre: " &lt;&lt; params; };
   
   generateSearchHTML = generateFileHTML (search);
   generateInfoHTML = generateFileHTML (info);
   
   generateSearchHTML("Búsqueda", "concepto");
   generateInfoHTML("Información", "producto");
</PRE>
<H4><A NAME="SECTION0005411110000000000000">
Aplicación parcial</A>
</H4>

<P>
La aplicación parcial toma una función y devuelve otra basada en esta, donde algunos de sus parámetros presentan ya un valor.

<P>
Para la aplicación parcial se utiliza el operador con el mismo nombre. Este consiste en el literal ``<SPAN CLASS="MATH"></SPAN>'' seguidos de 
una lista con los valores que se aplicarán y la función sobre la que se realizará la operación. La lista de parámetros consiste 
en pares parámetro/valor separados por el signo ``<SPAN CLASS="MATH"></SPAN>'', y entre si por coma. Los parámetros se han de corresponder con parámetros de
la función sobre la que se realizará la operación. La función resultante será una función que recibe tantos parámetros como la función original
exceptuando aquellos que tienen aplicados un valor. 
<BR>
<P>
<PRE>
   ~ addX (num, X) {
      return num + X;
   }
   
   add4 = P[X=4]addX;
   add8 = P[X=8]addX;
   
   &lt;&lt; add4(5); // Imprime 9
   &lt;&lt; add8(5); // Imprime 13
</PRE>

<P>

<H3><A NAME="SECTION000541200000000000000">
Listas por comprensión</A>
</H3>
En OMI es posible definir una lista o un diccionario por compresión. Para ello se utiliza una construcción del
lenguaje similar a la sentencia iterativa <SPAN CLASS="MATH"></SPAN>, salvo que en cada iteración genera un elemento del array 
asociado a la lista o diccionario. 

<P>
La definición de una lista por compresión debe ir entre paréntesis.

<P>
La forma más simple de crear una lista por compresión es mediante una expresión de generación, 
el literal <SPAN CLASS="MATH"></SPAN> y una variable que iterará sobre una expresión conjunto. En cada iteración la variable 
iteradora tomará un valor del conjunto. Para cada elemento se calculará el valor de 
la expresión generadora, la cual normalmente contendrá la variable iteradora, y será introducido en 
el array resultado. El conjunto sobre el que se itera dependerá del tipo de dato obtenido al evaluar la expresión conjunto:

<P>
<DL>
<DT><STRONG>Booleano:</STRONG></DT>
<DD>Se itera hasta que se evalúa como falso. En cada iteración se asigna el entero correspondiente al número de la misma.
</DD>
<DT><STRONG>Numérico:</STRONG></DT>
<DD>Si es positivo se itera desde cero hasta el valor sin incluirlo. Si es negtivo no se itera.
</DD>
<DT><STRONG>Cadena de caracteres:</STRONG></DT>
<DD>Se itera por cada carácter en la cadena.
</DD>
<DT><STRONG>Array:</STRONG></DT>
<DD>Se itera por cada elemento en el array.
</DD>
</DL>

<P>
<PRE>
   /*
      Array de 10 elementos: desde el 0 al 9
   */
    foo = ( y++ for x in y &lt; 10 )
   /*
      Array de 10 elementos donde las 
      posiciones pares valen 0 y las
      impares 1
   */
   foo = ( x % 2 for x in 10 ); 
   /*
      Array que contiene "A", "B", "C" y "D"
   */
   foo = ( x for x in "ABCD" ); 
   /*
      Array que contiene 1, 2 y 4
   */
   foo = ( x/2 for x in {2,4,8} );
</PRE>

<P>
En cada iteración la expresión de conjunto es evaluada antes de obtener el elemento correspondiente.

<P>
Es posible filtrar los datos que serán incluidos en el array, añadiendo el literal
<SPAN CLASS="MATH"></SPAN> y la condición que se debe cumplir. 
<BR>
<P>
<PRE>
   /*
      Array de los pares
      del 0 al 9
   */
   foo = ( x for x in 10 if x % 2 == 0 );
</PRE>

<P>
Dado un array asociativo como conjunto es posible iterar sobre los pares clave/valor que lo conforman ,
para ello se define el par de variables que se van a utilizar separadas por ``<SPAN CLASS="MATH"></SPAN>''. 
<BR>
<P>
<PRE>
   /*
      Array que contiene "key0 =&gt; val0"
      y "key1 =&gt; val1"
   */
   foo = ( k." =&gt; ".v for k:v in {"key0":"val0","key1":"val1"} );
</PRE>

<P>
El array generado puede ser asociativo utilizando dos expresiones de generación separadas por 
``<SPAN CLASS="MATH"></SPAN>'' que se utilizarán para construir las claves y el valores. 
<BR>
<P>
<PRE>
   /*
      Array asociativo con las claves "key0", "key1" y "key2",
      cuyos valores son 2, 4 y 6 respectivamente.
   */
   foo = ( "key".k : x for k:x in {2,4,6} );
</PRE>

<P>
Es posible indicar un bloque de sentencias que será ejecutado 
con cada iteración. Este bloque irá después del conjunto a iterar. 
<BR>
<P>
<PRE>
   /*
      Array con los valores dados.
      Se solicita valores y se van introduciendo
      en el array hasta que no se da valor 
   */
   foo = ( x for i in x !== "" {&gt;&gt;["Posición ".i.": "] x} if x !== "" );
</PRE>

<P>

<H3><A NAME="SECTION000541300000000000000"></A> <A NAME="sec:class"></A>
<BR>
Clases de objeto
</H3>
OMI es un lenguaje orientado a objetos, por tanto permite hacer uso de los conceptos y recursos enmarcados
dentro de este paradigma de programación.

<P>
Una clase es una construcción del lenguaje que modela un concepto del dominio del problema. Se trata de la definición de un conjunto de entidades u objetos
con características y propiedades comunes. Describe los datos necesarios para representarlos y el comportamiento que tienen asociado.

<P>
Los objetos son casos concretos de los conceptos modelados mediante las clases. Guardan un estado dando valores a los datos descritos.
Además presentan el comportamiento ligado al concepto. 

<P>
Los datos que representan el estado de un objeto son modelados mediante atributos, mientras que el comportamiento es definido mediante métodos.

<P>
En OMI una clase se construye mediante la palabra reservada ``<SPAN CLASS="MATH"></SPAN>'', un identificador que la nombra y un bloque de sentencias en la que se 
definirán los atributos y métodos. Un atributo se define de forma similar a una variable, y un método a una función. 
<BR>
<P>
<PRE>
   /*
      Se define una clase gato. Un gato 
      se representa mediante un nombre y tiene
      asociado el comportamiento de aullar.
   */
   class gato {
      nombre;
      ~ aullar () {
         &lt;&lt; "Miauuu";
      }
   }
</PRE>

<P>
Los objetos pueden ser creados mediante la instanciación de una clase. El objeto dará valores
a los atributos y se le podrá aplicar los métodos definidos. Al crear una instancia se 
obtendrá un objeto llamando al método constructor, que es aquel que tenga el mismo nombre que la clase. 
Para crear una instancia se utiliza el operador ``<SPAN CLASS="MATH"></SPAN>'' seguido del nombre de la clase y los parámetros 
del método constructor. 
<BR>
<P>
<PRE>
   /*
      Se define una clase gato. Un gato 
      se representa mediante un nombre y tiene
      asociado el comportamiento de aullar.
   */
   class gato {
      nombre;
      ~ gato (nombre) {
         &lt;&lt; "Construyendo el gato ".nombre;
      }
      ~ aullar () {
         &lt;&lt; "Miauuu";
      }
   }
   /*
      Se instancia un gato 
      llamado "MacAlistair"
   */
   mac = new gato ("MacAlistair"); // Imprime "Construyendo el gato MacAlistair"
</PRE>

<P>
Si se instancia una clase que no se encuentra definida se produce un error semántico y se continua con la ejecución del programa.

<P>
Es posible acceder a los atributos y métodos de un objeto mediante el operador ``<SPAN CLASS="MATH"></SPAN>''.
También se puede hacer referencia al objeto en ejecución dentro de los métodos, para ello se utiliza el operador ``<SPAN CLASS="MATH"></SPAN>''. 
<BR>
<P>
<PRE>
   /*
      Se define una clase gato. Un gato 
      se representa mediante un nombre y tiene
      asociado el comportamiento de aullar.
*/
   class gato {
      nombre;
      ~ gato (nombre) {
        this-&gt;nombre = nombre;
      }
      ~ aullar () {
         &lt;&lt; "Miauuu";
      }
   }
   /*
      Se instancia un gato 
      llamado "MacAlistair"
   */
   mac = new gato ("MacAlistair"); 
   mac-&gt;aullar(); // Imprime "Miauuu"
   &lt;&lt; mac-&gt;nombre; // Imprime "MacAlistair"
</PRE>

<P>
Si se accede a un atributo o método no existente se llaman al método ``_get'' o ``_call'' respectivamente (ver Métodos mágicos sec:magic_method). Si 
estos no existen se produce un error semántico y se continua con la ejecución.

<P>
Si no existe ningún método llamado igual que la clase, se considera que esta tiene un constructor vacío. Este es
un método con el bloque de sentencias vacío y sin parámetros.

<P>
Una clase solo puede disponer de un constructor, si se dan varios métodos llamados igual que la clase solo tendrá 
efecto el último definido.

<P>

<H4><A NAME="SECTION000541310000000000000">
Accesibilidad de métodos y atributos</A>
</H4>
Los métodos y atributos definidos en un clase pueden tener restricciones a la accesibilidad de los mismos. Estos pueden ser públicos 
o privados.

<P>
Los atributos y métodos públicos pueden ser accedidos desde un ámbito externo a la clase. A no ser que se especifique lo contrario todos los
métodos y atributos de una clase son públicos. 
<BR>
<P>
<PRE>
   /*
      Se define una clase gato. Un gato 
      se representa mediante un nombre y tiene
      asociado el comportamiento de aullar.
   */
   class gato {
      nombre; // Atributo público
      ~ gato (nombre) { // Método público
        this-&gt;nombre = nombre; // Acceso a atributo público dentro de la clase
      }
      ~ aullar () { // Método público
         &lt;&lt; "Miauuu";
      }
   }
   /*
      Se instancia un gato 
      llamado "MacAlistair"
   */
   mac = new gato ("MacAlistair"); 
   mac-&gt;aullar(); // Llamada a método público fuera de la clase
   &lt;&lt; mac-&gt;nombre;  // Acceso a atributo público fuera de la clase
</PRE>

<P>
Los métodos o atributos privados no son accesibles desde fuera de la propia clase, solo desde los métodos definido dentro de esta. Para 
declarar un atributo o método como privado se antepone la palabra clave <SPAN CLASS="MATH"></SPAN> a la definición. 
<BR>
<P>
<PRE>
   /*
      Se define una clase gato. Un gato 
      se representa mediante un nombre y tiene
      asociado el comportamiento de aullar.
   */
   class gato {
      private nombre; // Atributo privado
      ~ gato (nombre) { // Método público
        this-&gt;nombre = nombre; // Acceso a atributo privado dentro de la clase
      }
      ~ aullar () { // Método público
         &lt;&lt; "Miauuu";
      }
   }
   /*
      Se instancia un gato 
      llamado "MacAlistair"
   */
   mac = new gato ("MacAlistair"); 
   mac-&gt;aullar(); // Llamada a método público fuera de la clase
   &lt;&lt; mac-&gt;nombre;  // Acceso a atributo privado fuera de la clase (Error)
</PRE>

<P>
Si el constructor de una clase es privado solo se podrán crear instancias desde los métodos de esta, los cuales normalmente serán métodos estáticos. 

<P>

<H4><A NAME="SECTION000541320000000000000">
Atributos y métodos estáticos</A>
</H4>

<P>
En OMI es posible declarar un método o atributo como estático, esto hará que pertenezca a la clase y no a los objetos instanciados. 
Los atributos y métodos estáticos son accesibles utilizando la clase y no utilizando un objeto. Generalmente guardan datos o definen un 
comportamiento aplicables a un conjunto de objetos definido por la clase. 

<P>
Para declarar un atributo o método como estático se utiliza la palabra reservada ``<SPAN CLASS="MATH"></SPAN>''. Para acceder a un método o atributo se utiliza el
nombre de la clase, el operador de resolución de nombre de dominio ``<SPAN CLASS="MATH"></SPAN>'' y el nombre del atributo o método. Es posible especificar que 
un atributo o método será a la vez estático y privado. 
<BR>
<P>
<PRE>
   class gato {
      private nombre; 
      private raza;
      private energia = 100;
      private hambre = 100;
      
      static private energia_min = -10;
      static private hambre_min = -10;
      
      static ~ pasar_tiempo (gatos, h = 1) {
         if (h &gt; 0) {
            $(gatos) {
               $-&gt;energia -= 10;
               $-&gt;hambre -= (30 * h);
               if ($-&gt;energia &lt; gato::energia_min || $-&gt;hambre &lt; gato::hambre_min)
                  &lt;&lt; $-&gt;nombre." a pasado a un lugar mejor";
            }
         }else{
            &lt;&lt; "Imposible";
         }
      }
      
      ~ gato (nombre, raza) { 
        this-&gt;nombre = nombre; 
        this-&gt;raza = raza;
      }
      
      ~ getNombre () {
         return this-&gt;nombre;
      }
      
      ~ getRaza () {
         return this-&gt;raza;
      }
      
      ~ aullar () { 
         &lt;&lt; "Miauuu";
      }
      
      ~ comer () {
         this-&gt;hambre += 10;
         &lt;&lt; "El animal come";
      }
      
      ~ dormir () {
         this-&gt;energia += 10;
         &lt;&lt; "El animal duerme";
      }
      
      ~ jugar () {
         if (this-&gt;energia &lt;= 0 or this-&gt;hambre &lt;= 0)
            &lt;&lt; "El gato ".this-&gt;nombre." no quiere jugar.";
         else{
            &lt;&lt; "A ".this-&gt;nombre." le encanta jugar";
            this-&gt;energia -= 10;
            this-&gt;hambre -= 10;
         }
      }
      
   }

   mac = new gato ("MacAlistair", "Siamés"); 
   ada = new gato ("Ada", "Persa"); 
   bab = new gato ("Babbage", "Persa"); 

   $(15) {
      &lt;&lt; "Gatos disponibles";
      &lt;&lt; "[0]=&gt; ".mac-&gt;getNombre()." [".mac-&gt;getRaza()."] ";
      &lt;&lt; "[1]=&gt; ".ada-&gt;getNombre()." [".ada-&gt;getRaza()."] ";
      &lt;&lt; "[2]=&gt; ".bab-&gt;getNombre()." [".bab-&gt;getRaza()."] ";
      &lt;&lt; "[otro]=&gt; Salir ";
      &gt;&gt;["Seleccione un gato para interactuar:"] s;
      switch (s) {
         case 0: 
            g = mac;
            break;
         case 1: 
            g = ada;
            break;
         case 2:
            g = bab;
            break;
         default:
            exit;
      }
      &lt;&lt; "------------------------------------------------------------";
      &lt;&lt; "Acciones disponibles";
      &lt;&lt; "[0]=&gt; Dormir ";
      &lt;&lt; "[1]=&gt; Comer ";
      &lt;&lt; "[2]=&gt; Jugar ";
      &lt;&lt; "[otro]=&gt; Aullar ";
      &gt;&gt;["Seleccione una acción:"] s;
      switch (s) {
         case 0: 
            g-&gt;dormir();
            break;
         case 1: 
            g-&gt;comer();
            break;
         case 2:
            g-&gt;jugar();
            break;
         default:
            g-&gt;aullar();
      }
      gato::pasar_tiempo ({mac, ada, bab});
   }
</PRE>

<P>

<H4><A NAME="SECTION000541330000000000000">
Herencia de clases</A>
</H4>

<P>
En OMI es posible definir una relación de herencia entre dos clases. Que una clase herede de otra significa 
que es una especialización de esta.  

<P>
La herencia permite establecer una jerarquía entre clases, tal que la clase que especializa es denominada 
hija de la clase que más genérica, denominada padre. La clase hija deriva de la padre y extiende su funcionalidad y definición.
Una clase que extiende a otra toma todos sus métodos y atributos, pudiendo añadir nuevos o redefinir los existentes.

<P>
La herencia de clases permite que se dé la propiedad de polimorfismo, de forma que 
es posible mandar mensajes sintácticamente iguales a objetos de tipos distintos.

<P>
Para definir una relación de herencia entre dos clases se se sigue el nombre de la clase hija de la palabra 
reservada ``<SPAN CLASS="MATH"></SPAN>'' y del nombre de clase a la que extiende. 
<BR>
<P>
<PRE>
   class mascota {
      private nombre; 
      private raza;
      
      ~ mascota (nombre, raza) { 
        this-&gt;nombre = nombre; 
        this-&gt;raza = raza;
      }
      
      ~ getNombre () {
         return this-&gt;nombre;
      }
      
      ~ getRaza () {
         return this-&gt;raza;
      }
      
   }

   class gato extends mascota {
       ~ aullar () { 
         &lt;&lt; "Miauuu";
      }
   }

   class perro extends mascota {
       ~ aullar () { 
         &lt;&lt; "Guauuu";
      }
   }
   
   mac = new gato ("MacAlistair", "Siamés"); 
   ada = new perro ("Ada", "Bulldog");  
   mac-&gt;aullar(); // Imprime "Miauuu"
   ada-&gt;aullar(); // Imprime "Guauuu"
</PRE>

<P>
Si alguna clase hija no define constructor se toma el constructor de la clase padre si esta tuviera. 

<P>
Es posible definir una serie de clases de forma que presenten varios niveles de jerarquía.

<P>
Desde un método definido en la clase hija es posible hacer referencia a los métodos definidos en la clase padre 
mediante la palabra reservada ``<SPAN CLASS="MATH"></SPAN>''. 
<BR>
<P>
<PRE>
   class mascota {
      private nombre; 
      private raza;
      
      ~ mascota (nombre, raza) { 
        this-&gt;nombre = nombre; 
        this-&gt;raza = raza;
      }
      
      ~ getNombre () {
         return this-&gt;nombre;
      }
      
      ~ getRaza () {
         return this-&gt;raza;
      }
      
   }

   class gato extends mascota {
       ~ aullar () { 
         &lt;&lt; "Miauuu";
      }
   }

   class gato_persa extends gato {
       ~ gato_persa (nombre) {
         parent-&gt;gato (nombre, "Persa"); // Llama al método constructor de la clase padre.
       }
   }
   
   mac = new gato_persa ("MacAlistair"); 
   mac-&gt;aullar(); // Imprime "Miauuu"
   &lt;&lt; mac-&gt;getRaza(); // Imprime "Persa"
</PRE>

<P>
Cuando un método de una clase padre utiliza el operador ``<SPAN CLASS="MATH"></SPAN>'' se accede al objeto
en si, de la misma forma que se haría desde un método de la clase hija.  
<BR>
<P>
<PRE>
   class mascota {
      private nombre; 
      private raza;
      
      ~ mascota (nombre, raza) { 
        this-&gt;nombre = nombre; 
        this-&gt;raza = raza;
      }
      
      ~ getNombre () {
         return this-&gt;nombre;
      }
      
      ~ getRaza () {
         return this-&gt;raza;
      }
      
      ~ saludar () {
         // Accede al método getType definido en la clase hija
         &lt;&lt; "Hola soy ".this-&gt;nombre.", un ".this-&gt;getType()." ".this-&gt;raza;  
      }
      
   }

   class gato extends mascota {
       ~ getType () {
         return "gato";
       }
       
       ~ aullar () { 
         &lt;&lt; "Miauuu";
      }
   }

   class perro extends mascota {
       ~ getType () {
         return "perro";
       }
       
       ~ aullar () { 
         &lt;&lt; "Guauuu";
      }
   }
   
   mac = new gato ("MacAlistair", "Persa"); 
   mac-&gt;aullar(); // Imprime "Miauuu"
   mac-&gt;saludar(); // Imprime "Hola soy MacAlistair, un gato Persa"
   
   ada = new perro ("Ada", "Bulldog"); 
   ada-&gt;aullar(); // Imprime "Guauuu"
   ada-&gt;saludar(); // Imprime "Hola soy Ada, un perro Bulldog"
</PRE>

<P>
En OMI es posible acceder a un atributo o método estático que es definido en la clase hija, desde un método de
la clase padre. Para ello se utiliza la palabra reservada ``<SPAN CLASS="MATH"></SPAN>'' seguido del operador ``<SPAN CLASS="MATH"></SPAN>'' y el 
nombre del atributo o método al que se accederá. 
<BR>
<P>
<PRE>
   class mascota {
      private nombre; 
      private raza;
      
      ~ mascota (nombre, raza) { 
        this-&gt;nombre = nombre; 
        this-&gt;raza = raza;
      }
      
      ~ getNombre () {
         return this-&gt;nombre;
      }
      
      ~ getRaza () {
         return this-&gt;raza;
      }
      
      ~ saludar () {
         // Accede al atributo estático type definido en la clase hija
         &lt;&lt; "Hola soy ".this-&gt;nombre.", un ".static::type." ".this-&gt;raza;  
      }
      
   }

   class gato extends mascota {
       static type = "gato";
       
       ~ aullar () { 
         &lt;&lt; "Miauuu";
      }
   }

   class perro extends mascota {
      static type = "perro";
       
       ~ aullar () { 
         &lt;&lt; "Guauuu";
      }
   }
   
   mac = new gato ("MacAlistair", "Persa"); 
   mac-&gt;aullar(); // Imprime "Miauuu"
   mac-&gt;saludar(); // Imprime "Hola soy MacAlistair, un gato Persa"
   
   ada = new perro ("Ada", "Bulldog"); 
   ada-&gt;aullar(); // Imprime "Guauuu"
   ada-&gt;saludar(); // Imprime "Hola soy Ada, un perro Bulldog"
</PRE>

<P>
En OMI no es posible llevar a cabo herencia múltiple. Tampoco dispone de ningún
mecanismo con el que se pueda simular tales como traits. 

<P>

<H4><A NAME="SECTION000541340000000000000">
Redefinición de clases</A>
</H4>
En OMI es posible redefinir una clase, de forma que se pueden añadir métodos o sobrescribir los 
existentes. 

<P>
Para redefinir una clase basta con definirla nuevamente con el mismo identificador. La nueva 
clase tomará todos los atributos y métodos anteriores. 
<BR>
<P>
<PRE>
   class miClase {
      ~ meth1 () {
         &lt;&lt; "Método 1";
      }
   }
   
   class miClase {
      ~ meth2 () {
         &lt;&lt; "Método 2";
      }
   }
   foo = new miClase ();
   foo-&gt;meth1(); // Imprime "método 1"
   foo-&gt;meth2(); // Imprime "método 2"
   class miClase {
      ~ meth1 () {
         &lt;&lt; "Redefinición de método 1";
      }
   }
   foo = new miClase ();
   foo-&gt;meth1(); // Imprime "Redefinición de método 1"
   foo-&gt;meth2(); // Imprime "Método 2"
</PRE>

<P>
La redefinición de clases es un mecanismo que ofrece flexibilidad a la hora de construir clases de objetos, no obstante 
debe ser utilizado con cuidado ya que hace que la definición de una clase sea dinámica y pueda cambiar en la ejecución 
pudiendo ocasionar confusión en el código e inestabilidad del programa.

<P>

<H4><A NAME="SECTION000541350000000000000">
Clases bases</A>
</H4>
En OMI existen una serie de clases denominadas clases bases, a partir de las 
cuales se definen los tipos de datos básicos. Estas son:

<P>

<UL>
<LI>logicClass
</LI>
<LI>arithClass
</LI>
<LI>stringClass
</LI>
<LI>arrayClass
</LI>
</UL>

<P>
Es posible redefinir una clase base y modificar su comportamiento, añadiendo o sustituyendo 
métodos. 
<BR>
<P>
<PRE>
   class stringClass {
      ~ OReq (elems) {
         $(elems)
            if (this == $) 
               return true;
         return false;
      }
      ~ concatX () {
         return this .= "X";
      }
   }

   foo = "ABC"-&gt;OReq({"A", "AB", "ABC"}); // foo vale true
   foo = "ABCD"-&gt;OReq({"A", "AB", "ABC"}); // foo vale false
   foo = "ABCD"-&gt;concatX(); // foo vale "ABCDX"
   
   str = "ABCD";
   &lt;&lt; str-&gt;concatX(); // Imprime "ABCDX"
   &lt;&lt; str; // Imprime "ABCDX"
</PRE>

<P>
En una clase base el operador ``<SPAN CLASS="MATH"></SPAN>'' obtiene el dato en si, por lo que este será tratado como una variable
 de este tipo.

<P>
Es posible extender una clase base para especializarla mediante otras subclases. 
<BR>
<P>
<PRE>
   class stringA extends stringClass {
      ~ stringA (){
         this = "A";
      }
   }
   class stringB extends stringClass {
      ~ stringB (){
         this = "B";
      }
   }

   strA = new stingA ();
   strB = new stingB ();
   &lt;&lt; strA; // Imprime "A"
   &lt;&lt; strB; // Imprime "B"
   &lt;&lt; strA . strB; // Imprime "AB"
</PRE>

<P>
Las clases bases logicClass y arithClass no disponen inicialmente de métodos.
Las clases stringClass y arrayClass tienen como métodos los equivalentes 
a las funciones aplicables a estos tipos de datos.

<P>

<H4><A NAME="SECTION000541360000000000000">
Duck typing</A>
</H4>

<P>
OMI es un lenguaje de tipado dinámico que presenta un estilo duck typing.
La validez semántica en el uso de un objeto viene determinada
por el conjunto de atributos y métodos de este. 

<P>
Si en una expresión se accede a un método o atributo de un objeto únicamente se
comprobará que el elemento exista, indistintamente de la clase a la que pertenezca 
el objeto. De esta forma es posible utilizar un objeto independientemente de 
la clase a la que pertenece, sin que sea necesario un chequeo de tipos. 
<BR>
<P>
<PRE>
   class pato {
      ~ sonar () {
         &lt;&lt; "Cuack";
      }
   }

   class persona {
      ~ sonar () {
         &lt;&lt; "La persona imita el sonido de un pato";
      }
   }


   ~ sonar (obj) {
      /*
       * Sea cual sea la clase del objeto, 
       * si tiene el método sonar
       * será llamado
       */
      obj-&gt;sonar();
   }

   obj1 = new pato ();
   obj2 = new persona ();
   sonar (obj1); // Imprime "Cuack"
   sonar (obj2); // Imprime "La persona imita el sonido de un pato"
</PRE>

<P>
El estilo de tipado duck typing permite que se de polimorfismo sin herencia de 
clases, de forma que a objetos de distinto tipos se le puede enviar mensajes sintácticamente iguales.  

<P>

<H4><A NAME="SECTION000541370000000000000"></A> <A NAME="sec:magic_method"></A>
<BR>
Métodos mágicos
</H4>

<P>
En OMI se definen una serie de métodos mágicos. Estos son métodos que serán 
llamados en distintas circunstancias, como cuando se utilice al objeto 
como una cadena o se acceda a un atributo no existente. 

<P>
Los métodos mágicos comienzan por el signo ``_'' y son los siguientes: 

<P>
<DL>
<DT><STRONG>_str:</STRONG></DT>
<DD>Se llama cuando se accede a un objeto como una una cadena de caracteres.
</DD>
<DT><STRONG>_get:</STRONG></DT>
<DD>Se llama cuando se accede a un atributo que no existe.
</DD>
<DT><STRONG>_call:</STRONG></DT>
<DD>Se llama cuando se accede a un método que no existe.
</DD>
</DL>

<P>
El método ``_str'' no tendrá parámetros y devolverá la cadena de caracteres que
represente el objeto. 

<P>
<PRE>
   class persona {
      private nombre;
      private apellidos;
      
      ~ persona (nombre, apellidos) {
         this-&gt;nombre = nombre;
         this-&gt;apellidos = apellidos;
      }
      
      ~ _str () {
         return this-&gt;apellidos.', '.this-&gt;nombre;
      }
      
   }
   
   p = new persona ('Fco. Javier', 'Bohórquez Ogalla');
   &lt;&lt; p; // Imprime "Bohórquez Ogalla, Fco. Javier"
</PRE>

<P>
El método ``_get'' tendrá un único parámetro que se corresponderá con 
el nombre del atributo no existente al que se ha accedido. Y devolverá 
el valor para dicho atributo. 
<BR>
<P>
<PRE>
   class persona {
      private nombre;
      private apellidos;
      
      ~ persona (nombre, apellidos) {
         this-&gt;nombre = nombre;
         this-&gt;apellidos = apellidos;
      }
      
      ~ _get (attr) {
         &lt;&lt; "El atributo ".attr." no existe";
         return "No existe";
      }
      
   }
   
   p = new persona ('Fco. Javier', 'Bohórquez Ogalla');
   foo = p-&gt;test; // Imprime "El atributo test no existe"
   &lt;&lt; foo; // Imprime "No existe"
</PRE>

<P>
El método ``_call'' tendrá dos parámetros que se corresponderán con 
el nombre del método no existente al que se ha accedido y 
con un array que contendrá los parámetros pasados en la llama. El valor devuelto
será el valor de la llamada. 
<BR>
<P>
<PRE>
   class persona {
      private nombre;
      private apellidos;
      
      ~ persona (nombre, apellidos) {
         this-&gt;nombre = nombre;
         this-&gt;apellidos = apellidos;
      }
      
      ~ _call (meth, params) {
         &lt;."El método ".meth." no existe [ ";
         $(params) &lt;.$." ";
         &lt;&lt; "]";
         return "No existe";
      }
      
   }
   
   p = new persona ('Fco. Javier', 'Bohórquez Ogalla');
   foo = p-&gt;test("1", 2, "4"); // Imprime "El método test no existe [ 1 2 4 ]"
   &lt;&lt; foo; // Imprime "No existe"
</PRE>

<P>

<H3><A NAME="SECTION000541400000000000000"></A> <A NAME="sec:environment"></A>
<BR>
Entorno del programa
</H3>

<P>
En OMI es posible  acceder al entorno en el que se ejecuta el programa, definido por el sistema 
operativo y la entrada del programa. 

<P>
La mayoría de sistemas operativos permiten definir una serie de variables de entorno que pueden ser usadas
por los procesos y por el propio sistema operativo. En OMI es posible acceder a estas variables
mediante la función <SPAN CLASS="MATH"></SPAN> y una cadena que representa el nombre de la variable a la que se desea acceder. 
<BR>
<P>
<PRE>
   &lt;&lt; getenv ("USER"); // Imprime el nombre de usuario
</PRE>

<P>
Un programa escrito en OMI puede recibir una serie de parámetros cuando es ejecutado. Los argumentos serán almacenados
en una variable denominada <SPAN CLASS="MATH"></SPAN>. El valor de esta será un array donde el primer elemento es el nombre del script y los siguientes
los argumentos dados. 
<BR>
<P>
<PRE>
   // File: args.omi
   $(args) &lt;&lt; $; // Imprime el nombre del script y los argumentos.
</PRE>

<P>
<PRE>{language=bash}
   omi args.omi "ARG1" "ARG2" # Imprime args.omi ARG1 y ARG2
</PRE>

<P>

<H3><A NAME="SECTION000541500000000000000"></A> <A NAME="sec:exception"></A>
<BR>
Excepciones
</H3>

<P>
Las excepciones son un mecanismo de programación que permite tratar casos no habituales, normalmente de error, durante la ejecución de un programa. Las excepciones
permiten separar el código correspondiente al caso de normal o de éxito, del código extraordinario o de error. 

<P>
El uso de excepciones permite realizar programas robustos y tolerantes a errores, a la vez que se gana claridad en el código.

<P>
Para hacer uso del manejo de excepciones se utiliza la sentencia <!-- MATH
 $try...catch...$
 -->
<SPAN CLASS="MATH"></SPAN>, esta consiste en la palabra reservada <SPAN CLASS="MATH"></SPAN> seguida del bloque de 
sentencias en la que puede darse la excepción. Tras lo cual se utiliza la palabra reservada <SPAN CLASS="MATH"></SPAN>, un símbolo variable al que se le va a asignar el valor de la excepción y un bloque de 
sentencias en la que se va a tratar. Para lanzar la excepción se utilizar la palabra reservada <SPAN CLASS="MATH"></SPAN> seguida de una expresión que le da valor. 
<BR>
<P>
<PRE>
   class Exc {
      var = null;
      ~ Exc (num) {
         this-&gt;var = num;
      }
      ~ printError () {
         &lt;&lt; "Error " &lt;&lt; this-&gt;var;
      }
   }
   try {
      &gt;&gt;["Dame un valor:"] foo;
      if ( foo === "" ){
         throw new Exc (404);
      } 
      &lt;&lt; foo;
   }catch (exc) {
      exc-&gt;printError ();
   }
</PRE>

<P>
A diferencias de otros lenguajes de programación OMI solo permite un bloque catch que será ejecutado sea cual sea la excepción que se produzca. No se comprobará el 
tipo de dato del valor asociado a la excepción. 

<P>

<H3><A NAME="SECTION000541600000000000000">
Reflexión</A>
</H3>
OMI es un lenguaje que presenta características reflexivas. Un programa escrito en OMI puede hacer uso del entorno construido durante su ejecución para cambiar su propia estructura
y comportamiento.

<P>
En OMI es posible utilizar expresiones cuyo valor sea una cadena de caracteres como un identificador para una variable, una función, una clase, un método, etc. Para ello se 
utiliza el símbolo ``<SPAN CLASS="MATH"></SPAN>'' seguido de la expresión entre llaves. 
<BR>
<P>
<PRE>
   class Foo {
      ~ hello () {
         &lt;&lt; "Hola mundo";
      }
   }
   
   class_pre = "Fo";
   class_post = "o";
   var = "object";
   method = "hello";
   @{var} = new @{class_pre.class_post}();
   object-&gt;@{method}(); // Imprime "Hola mundo"
</PRE>

<P>
En OMI también es posible evaluar una cadena de caracteres como si de una sentencia de código fuente se tratase. Para ello se utiliza la sentencia ``<SPAN CLASS="MATH"></SPAN>''. 
<BR>
<P>
<PRE>
   foo = " x = 4 + 3 ";
   eval (foo);
   &lt;&lt; x; // Imprime 7
</PRE>

<P>

<H3><A NAME="SECTION000541700000000000000">
Introspección de tipos</A>
</H3>

<P>
OMI es un lenguaje en el que es posible llevar a cabo introspección de tipos. Permite examinar, en tiempo de ejecución, el tipo de los objetos creados. 

<P>
Para obtener la clase de un objeto dado se utiliza la palabra clave ``<SPAN CLASS="MATH"></SPAN>'' seguida de la expresión, cuyo valor representará el objeto, entre paréntesis. Se devolverá
la cadena de caracteres correspondiente al nombre de la clase, o la cadena vacía si la expresión no es un objeto. 
<BR>
<P>
<PRE>
   class Foo {
      ~ hello () {
         &lt;&lt; "Hola mundo";
      }
   }
   foo = new Foo ();
   if (getclass(foo) == 'Foo')
      foo-&gt;hello(); // Imprime "Hola mundo"
</PRE>

<P>

<H3><A NAME="SECTION000541800000000000000"></A> <A NAME="sec:error"></A>
<BR>
Errores
</H3>
Cuando un programa escrito en OMI es interpretado se pueden dar diferentes tipos de errores. Un error de interpretación 
puede tener diferentes efectos, pero en cualquier caso se presentará información sobre el error ocurrido. Si el código fuente está contenido en un fichero 
se indicará el nombre del mismo y la línea de código en la que se ha producido el error. 

<P>

<H4><A NAME="SECTION000541810000000000000">
Léxicos</A>
</H4> 
Los errores léxicos son originados durante el procesado del código fuente, cuando existe un carácter o cadena que no es reconocida por el intérprete. En este caso 
se detendrá el programa no será ejecutado y fallará el proceso de interpretación. 
<BR>
<P>
<PRE>
   |æ| = 10;
   Error: lexical error, unexpected character (|æ|)
</PRE>

<P>

<H4><A NAME="SECTION000541820000000000000">
Sintácticos</A>
</H4>
Los errores sintácticos tienen lugar durante el procesado del código fuente, cuando una sentencia o expresión no está construida de forma correcta y no respeta las reglas establecidas por el 
lenguaje. Si se detecta un error sintáctico al procesarse el código fuente este no será ejecutado y el programa se detendrá. 
<BR>
<P>
<PRE>
   [ id );
   Error: syntax error, unexpected |')'|, expecting |','| or |']'|
</PRE>

<P>

<H4><A NAME="SECTION000541830000000000000">
Semánticos</A>
</H4> 
Los errores semánticos se dan durante la ejecución del programa. Estos son dependientes del entorno y los datos. 

<P>
Cuando una sentencia o expresión es interpretada es posible que se dé un error semántico si no es capaz de operar sobre los datos
facilitados, o no se da el contexto adecuado. 

<P>
Existe gran variedad de posibles errores semánticos, estos son descritos en este manual al tratar las sentencias, expresiones y demás construcciones en las que se 
pueden dar. Cuando se produce un error semántico puede detenerse o no la ejecución del programa, dependerá del error en si. Si no se indica lo contrario en
el manual, cuando se produce un error semántico, se prosigue con la ejecución del programa. 
<BR>
<P>
<PRE>
   a = new noExist ()
   Error: data type error, worng |class| identifier
</PRE>

<P>
OMI es un lenguaje de tipado dinámico, por lo que cualquier error de tipo se da en tiempo de ejecución. Las funciones y operadores
del lenguaje esperan tratar con unos tipos de datos concretos. Si una función u operador recibe un valor de un tipo 
que no pueda manipular producirá un error semántico. En este manual se indica los tipos de datos con los que esperan operar 
las funciones y métodos, se entiende que otro tipo distinto producirá un error. 

<P>

<H2><A NAME="SECTION00055000000000000000">
Funciones del lenguaje</A>
</H2>

<H3><A NAME="SECTION00055100000000000000">
Cadenas de caracteres</A>
</H3>
OMI pone a disposición del programador un conjunto de funciones que operan sobre cadenas de caracteres.

<P>
En OMI las cadenas de caracteres pertenecen a una clase de objetos, así toda función aplicable a una cadena
puede ser llamada como un método de la cadena. 

<P>
Toda función aplicable a una cadena comienza con el prefijo ``str'' y toman como primer parámetro la cadena sobre la que 
operar. Por otro lado los métodos de cadena no disponen de prefijo y se toma implícitamente como primer parámetro el objeto 
cadena. 

<P>

<H4><A NAME="SECTION00055110000000000000">
str_explode</A>
</H4>
La función str_explode divide en partes una cadena de caracteres según una subcadena denominada separador. El resultado 
será un array de elementos que contendrá las cadenas correspondientes a cada una de las partes. 

<P>
<BR>

<BR>

<P>
<PRE>
   // foo es el array {"A", "B", "C", "D", "E"}
   foo = str_explode ("A,B,C,D,E", ","); 
   
   // foo es el array {"A", "B", "C", "D", "E"}
   foo = "A,B,C,D,E"-&gt;explode (",");
</PRE>

<P>

<H4><A NAME="SECTION00055120000000000000">
str_find</A>
</H4>
La función str_find obtiene la primera posición de una subcadena dentro de una cadena de caracteres. 

<P>
<BR>

<BR>

<P>
<PRE>
   foo = str_find ("A,B,C,D,C,F", "C"); // foo vale 4  
   foo = "A,B,C,D,C,F"-&gt;find ("C"); // foo vale 4

   foo = str_find ("A,B,C,D,C,F", "C", 5); // foo vale 8 
   foo = "A,B,C,D,C,F"-&gt;find ("C", 5); // foo vale 8
   
   foo = str_find ("A,B,C,D,C,F", `C(.*)C`); // foo vale 4
   foo = "A,B,C,D,C,F"-&gt;find (`C(.*)C`); // foo vale 4
</PRE>

<P>

<H4><A NAME="SECTION00055130000000000000">
str_replace</A>
</H4>
La función str_replace busca las ocurrencias de una subcadena dada en una cadena de caracteres, sustituyéndolas
por una cadena de remplazo. El valor devuelto por la función es la cadena con los remplazos efectuados. 
<BR>
<P>
<BR>

<BR>

<P>
<PRE>
   // foo vale "A,B,P,D,P,F" 
   foo = str_replace ("A,B,C,D,C,F", "C", "P"); 
   
   // foo vale "A,B,P,D,P,F" 
   foo = "A,B,C,D,C,F"-&gt;replace ("C", "P");

   // foo vale "A,B,P,D,C,F" 
   foo = str_replace ("A,B,C,D,C,F", "C", "P", 1); 
   
   // foo vale "A,B,P,D,C,F" 
   foo = "A,B,C,D,C,F"-&gt;replace ("C", "P", 1);

   // foo vale "A,B,D,F" 
   foo = str_replace ("A,B,C,D,C,F", `C,(.)`, "\1"); 
   
   // foo vale "A,B,D,F" 
   foo = "A,B,C,D,C,F"-&gt;replace (`C,(.)`, "\1");
</PRE>

<P>

<H4><A NAME="SECTION00055140000000000000">
str_replace_sub</A>
</H4>
La función str_replace_sub remplaza la subcadena dada por una posición inicial y una longitud dentro de un cadena de caracteres por otra cadena.

<P>
<BR>

<BR>

<P>
<PRE>
   // foo vale "A,B,P,C,F" 
   foo = str_replace_sub ("A,B,C,D,C,F", 4, 3, "P"); 
   
   // foo vale "A,B,P,C,F" 
   foo = "A,B,C,D,C,F"-&gt;replace_sub (4, 3, "P");
</PRE>

<P>

<H4><A NAME="SECTION00055150000000000000">
str_upper</A>
</H4>
La función str_upper convierte todos los caracteres alfabéticos de una cadena en mayúsculas. 

<P>
<BR>

<BR>

<P>
<PRE>
   foo = str_upper ("a,b,c,D"); // foo vale "A,B,C,D"
   foo = "a,b,c,D"-&gt;upper (); // foo vale "A,B,C,D"
</PRE>

<P>

<H4><A NAME="SECTION00055160000000000000">
str_lower</A>
</H4>
La función str_lower convierte todos los caracteres alfabéticos de una cadena en minúsculas. 

<P>
<BR>

<BR>

<P>
<PRE>   
   foo = str_lower ("A,B,C,d"); // foo vale "a,b,c,d"
   foo = "A,B,C,d"-&gt;lower (); // foo vale "a,b,c,d"
</PRE>

<P>

<H4><A NAME="SECTION00055170000000000000">
str_search</A>
</H4>
La función str_search permite llevar a cabo una búsqueda aplicando un patrón sobre una 
cadena de texto. Se obtendrá un array con los resultados de la búsqueda.

<P>
<BR>

<BR>

<P>
<PRE>   
   atag = `(?i)&lt;a[^&gt;]*href\s*=\s*\"([^\"]*)\"[^&gt;]*&gt;(.+?)&lt;\s*/\s*a\s*&gt;`;
   web = "&lt;a href=\"url01\"&gt;link01 -&gt; web01&lt; /a&gt;";
   web .= "\n&lt;div&gt;&lt;a id=\"id\" href=\"url02\" class=\"clase\"&gt;link02 -&gt; web02&lt;/a&gt;&lt;/div&gt;";
   /*
      links es el siguiente array:
      {
         {
            "url" : "url01",
            "label" : "link01 -&gt; web01"
         },
         {
            "url" : "url02",
            "label" : "link02 -&gt; web02"
         }
      }
   */
   links = str_search (web, atag, "url", "label");
</PRE>

<P>
Las cadenas de caracteres tienen el método search, que opera de igual forma que la
función str_search, salvo por que no acepta la lista de claves.

<P>

<H4><A NAME="SECTION00055180000000000000">
str_match</A>
</H4>
La función str_match comprueba si una cadena de caracteres pertenece o no al
lenguaje definido por una expresión regular.

<P>
<BR>

<BR>

<P>
<PRE>   
   foo = str_match ("ABCD",`A[^D]*D`); // foo vale true
   foo = "ABCD"-&gt;match(`A[^D]*D`); // foo vale true
</PRE>

<P>

<H4><A NAME="SECTION00055190000000000000">
regexp</A>
</H4>
La función regexp convierte una cadena de caracteres dada en una expresión regular

<P>
<BR>

<BR>

<P>
<PRE>   
   pattern = regexp ("A[^D]*D"); 
   foo = "ABCD"-&gt;match(pattern); // foo vale true
</PRE>

<P>

<H4><A NAME="SECTION000551100000000000000">
sprintf</A>
</H4>
La función sprintf permite obtener una cadena de caracteres formateada a partir de una serie de valores. 

<P>
<BR>

<BR>

<P>
<PRE>   
   &lt;&lt; sprintf("Esto es una %s formateada.", "cadena"); // Esto es una cadena formateada.
   &lt;&lt; sprintf("Ya son %2d", 2.003); // Ya son 02
   &lt;&lt; sprintf("Y %4s", "tres gatos"); // Y tres
   &lt;&lt; sprintf("Y %+4i", "4"); // Y +0004
   &lt;&lt; sprintf("Y %u", -5); // Y 5
   &lt;&lt; sprintf("Y %+2f", 6.6666 ); // Y +6.7
   &lt;&lt; sprintf("Y %+5e", 777.77777777); // Y +7.77778e+02
   &lt;&lt; sprintf("Y %F", "88888888888888888888888888"); // Y 8.88889E+25
   &lt;&lt; sprintf("Y %3E", "99.99"); // Y 9.999E+01
   &lt;&lt; sprintf("Y %^s", "diez"); // Y DIEZ
   &lt;&lt; sprintf("%d en octal es %#o", 31, 31); // 31 en octal es 037
   // 31 en hexadecimal es 0x1f o 0X1F
   &lt;&lt; sprintf("%d en hexadecimal es %#x o %#X", 31, 31, 31); 
   &lt;&lt; sprintf("Texto sin expresiones de formato"); // Texto sin expresiones de formato
   &lt;&lt; sprintf("%2sdenas %3stas", "Cadiz", "junio"); // Cadenas juntas
   // El 100% de aciertos en 100 intento
   &lt;&lt; sprintf("El %s%% de aciertos en %d intentos", 100, 100); 
   &lt;&lt; sprintf("%%%%%%"); // %%%%
</PRE>

<P>

<H3><A NAME="SECTION00055200000000000000">
Arrays</A>
</H3>
OMI pone a disposición del programador un conjunto de funciones que operan sobre arrays.

<P>
En OMI los arrays pertenecen a una clase de objetos, así toda función aplicable a un array
puede ser llamada como un método del mismo. 

<P>
Toda función aplicable a un array con el prefijo ``array'' y toman como primer parámetro el array sobre el que 
operar. Por otro lado los métodos de array no disponen de prefijo y se toma implícitamente como primer parámetro el objeto 
array.

<P>

<H4><A NAME="SECTION00055210000000000000">
array_implode</A>
</H4>
Forma una cadena de caracteres a partir de un array de cadenas y una cadena separadora. 

<P>
<BR>

<BR>

<P>
<PRE>   
   &lt;&lt; array_implode ({"Hola", "Mundo"}, " "); // Imprime "Hola Mundo"
   &lt;&lt; {"Hola", "Mundo"}-&gt;implode (" "); // Imprime "Hola Mundo"
</PRE>

<P>

<H4><A NAME="SECTION00055220000000000000">
array_first</A>
</H4>
Obtiene el primer elemento de un array. 

<P>
<BR>

<BR>

<P>
<PRE>   
   &lt;&lt; array_first ({"Hola", "Mundo"}); // Imprime "Hola"
   &lt;&lt; {"Hola", "Mundo"}-&gt;first (); // Imprime "Hola"
</PRE>

<P>

<H4><A NAME="SECTION00055230000000000000">
array_last</A>
</H4>
Obtiene el último elemento de un array. 

<P>
<BR>

<BR>

<P>
<PRE>   
   &lt;&lt; array_last ({"Hola", "Mundo"}); // Imprime "Mundo"
   &lt;&lt; {"Hola", "Mundo"}-&gt;last (); // Imprime "Mundo"
</PRE>

<P>

<H4><A NAME="SECTION00055240000000000000">
array_insert</A>
</H4>
Inserta un elemento en una determinada posición de un array dado.

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * foo vale el array { "Hola", "Mundo", "Digital"}
    */
   foo = array_insert ({"Hola", "Mundo"}, 2, "Digital"); 
   /*
    * foo vale el array { "Hola", "Mundo", "Digital"}
    */
   foo = {"Hola", "Mundo"}-&gt;insert (2, "Digital");
   
   foo = {"A", "C"};
   array_insert (foo, 1, "B"); // foo vale {"A", "B", "C"}
   foo-&gt;insert (3, "D"); // foo vale {"A", "B", "C", "D"}
</PRE>

<P>

<H4><A NAME="SECTION00055250000000000000">
array_delete</A>
</H4>
Elimina el elemento ocupa una determinada posición en un array dado.

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * foo vale el array { "Hola" }
    */
   foo = array_delete ({"Hola", "Mundo"}, 1); 
   /*
    * foo vale el array { "Hola" }
    */
   foo = {"Hola", "Mundo"}-&gt;delete (1);
   
   foo = {"A", "C"};
   array_delete (foo, 0); // foo vale {"C"}
   foo-&gt;delete (0); // foo vale {}
   
   foo = { 'key0' : 'val0', 'key1' : 'val1' };
   foo-&gt;delete ('key0'); // foo vale { 'key1' : 'val1' }
</PRE>

<P>

<H4><A NAME="SECTION00055260000000000000">
array_push</A>
</H4>
Inserta un elemento al final de un array dado.

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * foo vale el array { "Hola", "Mundo", "Digital" }
    */
   foo = array_push ({"Hola", "Mundo"}, "Digital"); 
   /*
    * foo vale el array { "Hola", "Mundo", "Digital"}
    */
   foo = {"Hola", "Mundo"}-&gt;push ("Digital");
   
   foo = {"A", "B"};
   array_push (foo, "C"); // foo vale { "A", "B", "C" }
   foo-&gt;push ("D"); // foo vale { "A", "B", "C", "D" }
   
   foo = { 'key0' : 'val0', 'key1' : 'val1'};
   foo-&gt;push ('val2'); // foo vale { 'key0' : 'val0', 'key1' : 'val1', '2' : 'val2' }
</PRE>

<P>

<H4><A NAME="SECTION00055270000000000000">
array_pop</A>
</H4>
Elimina y devuelve el último elemento de un array dado. 

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * foo vale la cadena "Mundo"
    */
   foo = array_pop ({"Hola", "Mundo"}); 
   /*
    * foo vale la cadena "Mundo"
    */
   foo = {"Hola", "Mundo"}-&gt;pop ();
   
   foo = {"A", "B"};
   array_pop (foo); // foo vale { "A" }
   foo-&gt;pop (); // foo vale { }
   
   foo = { 'key0' : 'val0', 'key1' : 'val1'};
   foo-&gt;pop (); // foo vale { 'key0' : 'val0' }
</PRE>

<P>

<H4><A NAME="SECTION00055280000000000000">
array_unshift</A>
</H4>
Inserta un elemento al inicio de un array dado.

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * foo vale el array { "Digital", "Hola", "Mundo" }
    */
   foo = array_unshift ({ "Hola", "Mundo" }, "Digital"); 
   /*
    * foo vale el array { "Digital", "Hola", "Mundo"}
    */
   foo = {"Hola", "Mundo"}-&gt;unshift ("Digital");
   
   foo = {"B", "C"};
   array_unshift (foo, "A"); // foo vale { "A", "B", "C" }
   foo-&gt;unshift ("-"); // foo vale { "-", "A", "B", "C" }
   
   foo = { 'key0' : 'val0', 'key1' : 'val1'};
   foo-&gt;unshift ('val2'); // foo vale { 'key0' : 'val2', 'key1' : 'val0', '2' : 'val1' }
</PRE>

<P>

<H4><A NAME="SECTION00055290000000000000">
array_shift</A>
</H4>
Elimina y devuelve el primer elemento de un array dado. 

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * foo vale la cadena "Hola"
    */
   foo = array_shift ({"Hola", "Mundo"}); 
   /*
    * foo vale la cadena "Hola"
    */
   foo = {"Hola", "Mundo"}-&gt;shift ();
   
   foo = {"A", "B"};
   array_shift (foo); // foo vale { "B" }
   foo-&gt;shift (); // foo vale { }
   
   foo = { 'key0' : 'val0', 'key1' : 'val1'};
   foo-&gt;shift (); // foo vale { 'key1' : 'val1' }
</PRE>

<P>

<H4><A NAME="SECTION000552100000000000000">
array_reduce</A>
</H4>
Lleva a cabo la reducción de un array a un único valor, aplicando iterativamente una función. 

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * foo vale la cadena "Hola Mundo Digital"
    */
   foo = array_reduce (
      {"Hola", "Mundo", "Digital"}, 
      ~(acumulador, elemento) { 
         return acumulador." ".elemento;
      }
   ); 
   /*
    * foo vale la cadena "Hola Mundo Digital"
    */
   foo = {"Hola", "Mundo", "Digital"}-&gt;reduce (
      ~(acumulador, elemento) { 
         return acumulador." ".elemento;
      }
   );
</PRE>

<P>

<H3><A NAME="SECTION00055300000000000000">
Procesos</A>
</H3>
OMI proporciona una serie de funciones para gestionarlos procesos. Así es posible abrir varios
hilos de ejecución creando procesos.

<P>
Es posible enviar señales a los procesos creados, y estos podrán manejarlas según sea necesario. 

<P>

<H4><A NAME="SECTION00055310000000000000">
exec</A>
</H4>
Ejecuta un comando del sistema y devuelve la salida.

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * foo vale el listado de procesos en ejecución
    */
   foo = exec ('ps -e');
</PRE>

<P>

<H4><A NAME="SECTION00055320000000000000">
fork</A>
</H4>
Crea un proceso hijo del proceso en ejecución.

<P>
<BR>

<BR>

<P>
<PRE>   
   /*
    * Se lleva a cabo la bifurcación de la ejecución mediante la 
    * creación de un proceso que imprimirá "Soy el proceso Hijo",
    * mientras que en el proceso principal imprimirá 
    * "Soy el proceso Padre de PID" donde PID es el identificador
    * del proceso hijo.
    */
    if (pid = fork ()) 
      &lt;&lt; "Soy el proceso Padre de " . pid;
    else
      &lt;&lt; "Soy el proceso Hijo";
</PRE>

<P>

<H4><A NAME="SECTION00055330000000000000">
wait</A>
</H4>
Espera la finalización de todos o algunos de los procesos hijos creados.

<P>
<BR>

<BR>

<P>
<PRE>  
   /*
    * Se crea un proceso y se espera
    * a que este finalice
    */
    if (pid = fork ()) {
      wait( pid );
      &lt;&lt; "Finaliza proceso padre";
   }else{
      sleep (10);
      &lt;&lt; "Finaliza proceso hijo";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055340000000000000">
getpid</A>
</H4>
Obtiene el identificador del proceso actual.

<P>
<BR>

<BR>

<P>
<PRE>  
   /*
    * Se crea un proceso y se imprimen
    * los identificadores.
    */
   if (pid = fork ()) {
      &lt;&lt; "PID del Padre " . getpid (); // Imprime el pid del padre
      &lt;&lt; "PID del Hijo " . pid; // Imprime el pid del hijo
   } else {
      &lt;&lt; "PID del Hijo " . getpid (); // Imprime el pid del hijo
   }
</PRE>

<P>

<H4><A NAME="SECTION00055350000000000000">
getppid</A>
</H4>
Obtiene el identificador del proceso padre.

<P>
<BR>

<BR>

<P>
<PRE>  
   /*
    * Se crea un proceso y se imprimen
    * los identificadores.
    */
   if (pid = fork ()) {
      &lt;&lt; "PID del Padre " . getpid (); // Imprime el pid del padre
      &lt;&lt; "PID del Hijo " . pid; // Imprime el pid del hijo
   } else {
      &lt;&lt; "PID del Padre " . getppid (); // Imprime el pid del padre
      &lt;&lt; "PID del Hijo " . getpid (); // Imprime el pid del hijo
   }
</PRE>

<P>

<H4><A NAME="SECTION00055360000000000000">
signal</A>
</H4>
Envía una señal a un proceso. 

<P>
<BR>

<BR>

<P>
<PRE>  
   /*
    * Se crea un proceso y envía una señal pasados
    * unos segundos para finalizar su ejecución
    */
   if (pid = fork ()) {
      &lt;&lt; "Padre: Esperando para finalizar";
      sleep (2);
      &lt;&lt; "Padre: Enviando señal";
      signal (pid, 9);
   } else {
      &lt;&lt; "Hijo: Esperando señal";
      sleep (30);
      &lt;&lt; "Hijo: Finaliza normal";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055370000000000000">
shandler</A>
</H4>
Permite establecer una función para manejar señales enviadas al proceso actual. 

<P>
<BR>

<BR>

<P>
<PRE>  
   /*
    * Se crea un proceso y envía una señal 
    * que será manejada
    */
   if (pid = fork ()) {
      &lt;&lt; "Padre: Esperando para interrumpir";
      sleep (2);
      &lt;&lt; "Padre: Enviando interrupción";
      signal (pid, 2);
   } else {
      if (shandler (2, ~(){ &lt;&lt; "Interrupción"; })){
         sleep (30);
         &lt;&lt; "Hijo: Finaliza normal";
      }else {
         &lt;&lt; "Error estableciendo manejador de señal";
      }
   }
</PRE>

<P>

<H4><A NAME="SECTION00055380000000000000">
exit_process</A>
</H4>
Finaliza el proceso en ejecución y todos los hijos de este. Si se da en el
proceso principal se sale del programa.

<P>
<BR>

<BR>

<P>
<PRE>  
   /*
    * Se crea un proceso y si el identificador de
    * proceso es menor que 20000 se cierra.
    */
   if (pid = fork ()) {
      sleep (30);
   } else {
      if (getpid() &lt; 20000){
         exit_process ();
      }
      &lt;&lt; "Exit";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055390000000000000">
process</A>
</H4>
Realiza una llamada a función como un proceso.

<P>
<BR>

<BR>

<P>
<PRE>  
   process ( ~() { $(100) &lt;&lt; "P1:".$; } );
   process ( ~(i) { $(i) &lt;&lt; "P2:".$; }, 100 );
</PRE>

<P>

<H3><A NAME="SECTION00055400000000000000">
Ficheros</A>
</H3>
OMI dispone de una serie de funciones para gestionar ficheros. Estas funciones permiten
abrir un fichero, leer su contenido, escribir en el mismo, etc.

<P>
OMI presenta un tipo de dato especial que se corresponde con un puntero a fichero. Este tipo 
de  dato sólo puede ser usado en las funciones de fichero, en cualquier otro contexto 
tomará un valor booleano que indica si el fichero se encuentra abierto. 

<P>
Un puntero a fichero referencia una posición dentro del mismo, posición a partir de la cual 
se llevarán a cabo las operaciones de lectura/escritura. Esta posición puede ser manipulada.

<P>
OMI solo es capaz de operar directamente con ficheros en texto plano. No es posible crear 
ficheros de tipo binario que no sea texto plano.

<P>

<H4><A NAME="SECTION00055410000000000000">
file</A>
</H4>
Abre un fichero según el modo especificado. 

<P>
<BR>

<BR>

<P>
<PRE>  
   if (f = file ("example.file", "w+")){
      &lt;&lt; "Fichero abierto con é|xito";
   } else {
      &lt;&lt; "Error abriendo el fichero";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055420000000000000">
fclose</A>
</H4>
Cierra un fichero abierto mediante la función ``file''

<P>
<BR>

<BR>

<P>
<PRE>  
   if (f = file ("example.file", "w+")){
      fclose (f); 
   } else {
      &lt;&lt; "Error abriendo el fichero";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055430000000000000">
fput</A>
</H4>
Escribe un contenido dado en la posición de lectura/escritura a la que apunta un puntero a fichero. Esta función presenta un alias ``f&gt;:''.
<BR>

<BR>

<P>
<PRE>  
   if (f = file ("example.file", "w+")){
      f&gt;: (f, "Contenido ha escribir"); 
      fclose(f);
   } else {
      &lt;&lt; "Error abriendo el fichero";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055440000000000000">
fget</A>
</H4>
Lee el un número de caracteres de un fichero, a partir de la posición de lectura/escritura dada por el puntero al mismo. Esta función presenta un alias ``f&lt;:''.

<P>
<BR>

<BR>

<P>
<PRE>  
   if (f = file ("example.file", "w")){
      f&gt;: (f, "Contenido escrito"); 
      fclose(f);
   } else {
      &lt;&lt; "Error abriendo el fichero";
   }
   if (f = file ("example.file", "r")){
      &lt;&lt; f&lt;:(f); // Imprime "Contenido escrito"
      fclose (f);
   } else {
      &lt;&lt; "Error abriendo el fichero";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055450000000000000">
fseek</A>
</H4>
Cambia la posición de lectura/escritura de un puntero a fichero.

<P>
<BR>

<BR>

<P>
<PRE>  
   if (f = file ("example.file", "w+")){
      f&gt;:(f, "ABCD");
      fseek (f, 2);
      &lt;&lt; f&lt;:(f, 1); // Imprime "C"
      fseek (f, -1, FEND);
      &lt;&lt; f&lt;:(f, 1); // Imprime "D"
      fseek (f, -1, FCUR);
      &lt;&lt; f&lt;:(f, 1); // Imprime "C"
      fseek (f, -1, FCUR);
      &lt;&lt; f&lt;:(f, 1); // Imprime "B"
      fseek (f, -1, FCUR);
      &lt;&lt; f&lt;:(f, 1); // Imprime "A"
      fclose(f);
   } else {
      &lt;&lt; "Error abriendo el fichero";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055460000000000000">
ftell</A>
</H4>
Obtiene la posición de lectura/escritura a la que apunta un puntero a fichero.

<P>
<BR>

<BR>

<P>
<PRE>  
   if (f = file ("example.file", "w+")){
      f&gt;:(f, "ABCD");
      fseek (f, 2);
      &lt;&lt; "Antes de leer: " . ftell (f); // Imprime 2
      &lt;&lt; f&lt;:(f, 1); // Imprime "C"
      &lt;&lt; "Después de leer: " . ftell (f); // Imprime 3
      fclose(f);
   } else {
      &lt;&lt; "Error abriendo el fichero";
   }
</PRE>

<P>

<H4><A NAME="SECTION00055470000000000000">
fread</A>
</H4>
Lee el contenido de un fichero.

<P>
<BR>

<BR>

<P>
<PRE>  
   foo = fread ('/etc/hosts'); // foo vale el contenido del fichero /etc/hosts
</PRE>

<P>

<H4><A NAME="SECTION00055480000000000000">
fwrite</A>
</H4>
Escribe el contenido de un fichero.

<P>
<BR>

<BR>

<P>
<PRE>  
   /*
   * El fichero /etc/hosts queda
   * con el contenido:
   * 127.0.0.1 localhost
   */
   fwrite ('/etc/hosts', '127.0.0.1 localhost');
</PRE>

<P>

<H4><A NAME="SECTION00055490000000000000">
fappend</A>
</H4>
Escribe el contenido al final de un fichero.

<P>
<BR>

<BR>

<P>
<PRE>  
   /*
   * Al fichero /etc/hosts se le
   * ha añadido el contenido:
   * 127.0.0.1 localhost
   */
   fappend ('/etc/hosts', '127.0.0.1 localhost');
</PRE>

<P>

<H3><A NAME="SECTION00055500000000000000">
Fechas y tiempo</A>
</H3>
OMI dispone de un conjunto de funciones de tiempo que permiten operar con fechas y con marcas de tiempo. 

<P>

<H4><A NAME="SECTION00055510000000000000">
date</A>
</H4>
Obtiene una fecha formateada.  

<P>
<BR>

<BR>

<P>
<PRE>  
   &lt;&lt; date ("%d/%m/%Y %H:%i:%s"); // Fecha y hora actual
   &lt;&lt; date ("%d/%m/%Y %H:%i:%s", 0); // 01/01/1970 00:00:00
</PRE>

<P>

<H4><A NAME="SECTION00055520000000000000">
time</A>
</H4>
Obtiene la marca de tiempo Unix actual.  

<P>
<BR>

<BR>

<P>
<PRE>  
   &lt;&lt; time (); // Imprime la marca de tiempo Unix actual
   &lt;&lt; date ("%d/%m/%Y %H:%i:%s", time()); // Fecha y hora actual
</PRE>

<P>
Esta es una función interna de OMI que puede ser utilizada sin paréntesis.

<P>

<H2><A NAME="SECTION00056000000000000000">
Extensiones del lenguaje</A>
</H2>
OMI es un lenguaje modular que puede ser extendido. 
Los módulos o extensiones permiten añadir funciones al lenguaje, ampliando así su funcionalidad y uso.

<P>
Los módulos son bibliotecas dinámicas que son cargadas en tiempo de ejecución. Estas
han sido programadas en un lenguaje de más bajo nivel (C/C++) y compiladas a código máquina. 

<P>
Es posible obtener módulos de OMI desde la web del proyecto 
(http://wwww.omi-project.com/download/extensions). 

<P>

<H3><A NAME="SECTION00056100000000000000">
Carga de módulos</A>
</H3>
Para cargar un módulo desde el código fuente se puede utilizar la sentencia <SPAN CLASS="MATH"></SPAN> seguida de 
una cadena entre paréntesis que representa la biblioteca dinámica que se usará como módulo. 
<BR>
<P>
<PRE>  
   load ('libomi_gettext.so');
   &lt;&lt; _('cadena traducida');
</PRE>

<P>
Se dispone de un mecanismo para autocargar módulos de extensiones del lenguaje. Al iniciarse 
el intérprete se cargarán todos los módulos indicados en el fichero ``libs.ini'' localizado 
en el directorio de datos de la aplicación (por defecto /usr/local/share/omi). Cada línea 
de este fichero será un módulo que será cargado, exceptuando las líneas que comiencen por ``;'' que
son consideradas comentarios.

<P>

<H3><A NAME="SECTION00056200000000000000">
Creación de módulos</A>
</H3>
OMI permite al programador extender el lenguaje haciendo uso de una biblioteca para el desarrollo de módulos. Esta
dispone de los elementos sobre los que se construye el intérprete. 

<P>
Para construir un módulo se ha de disponer de la biblioteca OMI correctamente instalada. Para ello se
dispone de dos opciones:

<P>
<DL>
<DT><STRONG>Paquete .deb:</STRONG></DT>
<DD>http://wwww.omi-project.com/download/deb/libomi-dev_$VERSION.deb
</DD>
<DT><STRONG>Código fuente:</STRONG></DT>
<DD>A partir del código fuente de OMI se puede construir e instalar la biblioteca 
mediante las reglas <SPAN CLASS="MATH"></SPAN> e <SPAN  CLASS="textit">install-dev</SPAN>
</DD>
</DL>

<P>
Un módulo OMI está escrito en C++ y se define mediante unas series de clases cada una de las cuales representará una
función que se desea añadir. 

<P>
El intérprete OMI se construye mediante una colección de nodos ejecutables. Todo es un nodo ejecutable: los booleanos,
los números, las variables, las funciones... Existen diferentes niveles de abstracción en los nodos ejecutables, así por ejemplo
un número es representado mediante un nodo ejecutable numérico, que a su vez es un nodo expresión aritmética, que a su vez es
una expresión de tipo definido... Las clases de un módulo extenderán los tipos de nodos definidos por la biblioteca de desarrollo OMI, 
normalmente nodos expresiones.

<P>
Las clases que integran un modulo OMI deben cumplir lo siguiente:

<P>

<UL>
<LI>Ser un tipo de nodo ejecutable. 
</LI>
<LI>Ser un nodo extensión e inherir su constructor.
</LI>
<LI>Implementar un método <SPAN CLASS="MATH"></SPAN> que lleve a cabo la funcionalidad.
</LI>
<LI>Ser añadidas al cargador de módulos.
</LI>
</UL>

<P>
Dependiendo el tipo de nodo ejecutable que se tome de base se dispondrá 
de un atributo que guardará el valor interno del nodo. Así un nodo de tipo cadena
de caracteres tendrá un atributo que representa la cadena guardada. El método 
<SPAN CLASS="MATH"></SPAN> llevará a cabo la funcionalidad y dará valor a este atributo.

<P>
Normalmente el método <SPAN CLASS="MATH"></SPAN> obtendrá los parámetros con los que se ha llamado a la 
función, les aplicará la operativa asociada y atribuirá el valor interno del 
nodo. Mediante una llamada al método <SPAN CLASS="MATH"></SPAN> es posible obtener un vector
con los parámetros pasados a la función en una ejecución. 
<BR>
<P>
language=cpp 
<PRE> 
   // libomi_strings.h
   #include &lt;omi/omi.h&gt;

   class ucfirstNode : public stringNode, public extensionNode {
      public:
         using extensionNode::extensionNode; // Si std=c++11
         // ucfirstNode (listNode* list) : extensionNode(list) {}  //Si std=c++98
         void run ();
   };
</PRE>

<P>
<PRE>
   // libomi_strings.cpp
   #include "libomi_strings.h"
   
   void ucfirstNode::run () { 
      vector&lt;runNode*&gt; v = this-&gt;getParams ();
      if (v.size() == 1){
         strvalue_ = stringNode::to_str (v[0]);
         strvalue_[0] = toupper(strvalue_[0]);
      }else
          throw errorException(
            "One parameter is required", 
            "ucfirstNode::run, size " + to_string (v.size()), 
            ERROR_PARAMS
         );
   }  
   
   extern "C" void load (PluginsLoader* loader) {
      loader-&gt;add ("ucfirst", create&lt;ucfirstNode&gt;);
   }
</PRE>

<P>
language=bash 
<PRE>
   $PS1 # Compilación del módulo
   $PS1 g++ -c -fPIC \
   $PS2     -DNUMTYPE='double' -DNUMPRECISION='15' -DREFCTYPE='unsigned int' \
   $PS2     -ansi -pedantic -g  -std=c++11  libomi_strings.cpp -o libomi_strings.o
   $PS1 g++ -g -O2 -shared -rdynamic -g -o libomi_strings.so libomi_strings.o -lomi
</PRE>

<P>
language=omi 
<PRE>
   // user.omi
   load ("./libomi_strings.so")
   &lt;&lt; ucfirst ("example"); // Imprime "Example"
</PRE>
<H2><A NAME="SECTION00057000000000000000">
Arquitectura cliente/servidor</A>
</H2>
El intérprete OMI puede funcionar bajo una arquitectura cliente/servidor para ello solo se ha de ejecutar este con la opción ``-s'' y el puerto de
escucha. 

<P>
En este caso el intérprete leerá por el puerto establecido una cadena de caracteres que representa el código a interpretar. El intérprete procesará 
la cadena y producirá un resultado.

<P>

<H2><A NAME="SECTION00058000000000000000">
Descripción del proceso de interpretación</A>
</H2>
Es posible iniciar el intérprete de forma que produzca una salida en formato JSON que describa los procesos de interpretación llevados a cabo. La estructura 
de datos JSON devuelta es descrita en su sección correspondiente de diseño del software.

<P>
Cuando se ejecuta el intérprete en de esta forma en conjunción con una arquitectura cliente/servidor esta estructura es devuelta por el puerto establecido. 

<P>

<H2><A NAME="SECTION00059000000000000000">
runTree</A>
</H2> 
runTree es un cliente para el intérprete OMI. Lee la estructura JSON producida por este y la representa en una interfaz gráfica. 

<P>
La interfaz de runTree se divide como sigue:

<P>

<UL>
<LI>Árbol de ejecución: Describe el árbol sintáctico producido y visualiza su procesamiento.
</LI>
<LI>Tablas de símbolos: Describe el contenido de las tablas de símbolos.
</LI>
<LI>Código fuente: Permite al usuario introducir el código fuente que será interpretado.
</LI>
<LI>Consola de entrada/salida: Muestra la salida producida y la recoge la entrada del usuario.
</LI>
<LI>Consola de estado: Describe el estado del proceso o de los elementos seleccionados.
</LI>
<LI>Consola de mandos: Contiene las opciones de control del proceso (avanzar, repetir, cargar código y guardar).
</LI>
</UL>
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
