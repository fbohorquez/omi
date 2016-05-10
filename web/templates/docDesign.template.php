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

.gramatic {
    margin: 20px;
    max-width: 75%;
}
</style>
<div id="content-doc">
<div id="index">
   <div class="title"><h1>Diseño del sistema</h1></div>
   <div class="list">

<UL CLASS="TofC">
<LI><A NAME="tex2html109"
  HREF="<?=URL;?>doc/diseño#SECTION00020000000000000000">Arquitectura del sistema</A>
<UL>
<LI><A NAME="tex2html110"
  HREF="<?=URL;?>doc/diseño#SECTION00021000000000000000">Arquitectura física</A>
<LI><A NAME="tex2html111"
  HREF="<?=URL;?>doc/diseño#SECTION00022000000000000000">Arquitectura lógica</A>
</UL>
<BR>
<LI><A NAME="tex2html112"
  HREF="<?=URL;?>doc/diseño#SECTION00030000000000000000">Diseño de la gramática</A>
<UL>
<LI><A NAME="tex2html113"
  HREF="<?=URL;?>doc/diseño#SECTION00031000000000000000">Programa</A>
<LI><A NAME="tex2html114"
  HREF="<?=URL;?>doc/diseño#SECTION00032000000000000000">Sentencias</A>
<LI><A NAME="tex2html115"
  HREF="<?=URL;?>doc/diseño#SECTION00033000000000000000">Expresiones</A>
<LI><A NAME="tex2html116"
  HREF="<?=URL;?>doc/diseño#SECTION00034000000000000000">Identidades</A>
</UL>
<BR>
<LI><A NAME="tex2html117"
  HREF="<?=URL;?>doc/diseño#SECTION00040000000000000000">Diseño de comunicaciones</A>
<UL>
<LI><A NAME="tex2html118"
  HREF="<?=URL;?>doc/diseño#SECTION00041000000000000000">Esquema JSON</A>
<LI><A NAME="tex2html119"
  HREF="<?=URL;?>doc/diseño#SECTION00042000000000000000">Nodos ejecutables</A>
<LI><A NAME="tex2html120"
  HREF="<?=URL;?>doc/diseño#SECTION00043000000000000000">Acciones</A>
</UL>
<BR>
<LI><A NAME="tex2html121"
  HREF="<?=URL;?>doc/diseño#SECTION00050000000000000000">Diseño de componentes</A>
<UL>
<LI><A NAME="tex2html122"
  HREF="<?=URL;?>doc/diseño#SECTION00051000000000000000">Interpretar código fuente</A>
<LI><A NAME="tex2html123"
  HREF="<?=URL;?>doc/diseño#SECTION00052000000000000000">Sentencias</A>
</UL>
<BR>
<LI><A NAME="tex2html124"
  HREF="<?=URL;?>doc/diseño#SECTION00060000000000000000">Diseño de la interfaz de usuario</A>
<UL>
<LI><A NAME="tex2html125"
  HREF="<?=URL;?>doc/diseño#SECTION00061000000000000000">Intérprete</A>
<LI><A NAME="tex2html126"
  HREF="<?=URL;?>doc/diseño#SECTION00062000000000000000">runTree</A>
<LI><A NAME="tex2html127"
  HREF="<?=URL;?>doc/diseño#SECTION00063000000000000000">Sitio web</A>
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
Arquitectura del sistema</A>
</H1>

<H2><A NAME="SECTION00021000000000000000">
Arquitectura física</A>
</H2>
Las herramientas del proyecto OMI pueden ser dispuestas sobre diferente arquitectura física. Por un lado se puede hacer uso 
del intérprete como una herramienta de un sistema operativo GNU/Linux, siguiendo así una arquitectura de escritorio. 
Por otro se puede usar el sistema en como una arquitectura cliente/servidor.

<P>

<H3><A NAME="SECTION00021100000000000000">
Escritorio</A>
</H3>
El cliente OMI puede ser utilizado en una arquitectura de escritorio, funcionando como un comando del sistema. Para ello solo se precisa de un PC con un sistema operativo GNU/Linux.

<P>

<H3><A NAME="SECTION00021200000000000000">
Cliente/servidor</A>
</H3>
El intérprete OMI puede ser usado en una arquitectura cliente/servidor, en la que hace de servidor. El servidor OMI espera una petición para un proceso de interpretación. Esta petición
contendrá el código fuente que se desea interpretar.

<P>
El servidor OMI procesa un código fuente para su interpretación devolviendo una estructura de datos en formato JSON que representa el árbol de nodos resultado del análisis léxico y sintáctico. 
Luego espera peticiones para resolver cada paso dentro del proceso de interpretación y devolver una estructura de datos en el mismo formato que representa qué ha ocurrido mediante el estado actual.

<P>
El sistema servidor es independiente del cliente en el sentido de que pueden usarse distintos clientes para el mismo servicio. El proyecto OMI presenta un cliente web llamado runTree 
que funciona en cualquier navegador moderno, no obstante se puede usar otra tecnología como cliente. 

<P>
Para ejecutar el sistema en una arquitectura cliente servidor se precisa de un equipo que tenga conexión a internet con un navegador web que hará de cliente. Por otro lado se necesita de un equipo servidor
que presente una alta disponibilidad. Este equipo dispondrá de uns sitema GNU/Linux sobre el que se ejecutará el intérprete y un servidor web Apache que servirá de plataforma para dar el servicio web.

<P>

<H2><A NAME="SECTION00022000000000000000">
Arquitectura lógica</A>
</H2>
En esta sección se presenta la arquitectura del sistema. Se presentan 
dos niveles de organización la parte frontal (front-end) y la parte 
interna o motor (back-end). 

<P>
La parte frontal se encarga de analizar y procesar la entrada del usuario.
Una vez tratada la entrada, se pasa la ejecución a las estructuras que conforman 
el motor del sistema. Estas llevarán a cabo una serie de tareas que puden producir
un resultado que será enviado al frontal. La parte frontal mostrará 
los datos como salida del programa en un formato establecido.

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="108" HEIGHT="170" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/generic.png"
 ALT="Image generic"> 
<BR>
</DIV>

<P>
Aunque bien se podría haber especificado otra capa correspondiente a la gestión de datos
llevada a cabo por las tablas de símbolos, esta se ha incluido en la parte del motor. Los datos que 
las tablas de símbolos tratan no mantienen persistencia, están muy ligados al proceso interno de 
interpretación y no representan los datos correspondientes al modelo de datos, sino que sirve para
referenciar componentes de la capa del motor de la aplicación.

<P>

<H3><A NAME="SECTION00022100000000000000">
Frontal (front-end)</A>
</H3>
El frontal del sistema se compone de un analizador léxico y un analizador sintáctico. 
Aunque es posible especificar reglas léxicas mediante reglas gramaticales, se ha separado el 
estos dos componentes por los siguientes motivos:

<P>

<UL>
<LI>La reglas lexicográficas suelen ser muy simples y para su descripción no se precisa de una 
notación tan compleja como las gramaticales.
</LI>
<LI>Las expresiones regulares son más concisas y fáciles de entender que las gramáticas
</LI>
<LI>A partir de expresiones regulares se puede describir analizadores léxicos eficientes.
</LI>
<LI>Se modulariza el proceso en dos componentes con objetivos bien definidos. 
</LI>
</UL>

<P>
Además del analizador léxico y sintáctico el front-end contiene estructuras funcionales correspondientes
a la toma de datos de entradas y a la impresión de la salida. 

<P>

<H4><A NAME="SECTION00022110000000000000">
Analizador léxico</A>
</H4>
El analizador léxico implementa una gramática de tipo 3 en la jerarquía de Chomsky, estas
se corresponden con las gramáticas regulares. 

<P>
Las gramáticas regulares, también llamadas gramáticas finitas, se pueden describir mediante expresiones regulares. 
Cada expresión regular denota un lenguaje <SPAN CLASS="MATH"><IMG
 WIDTH="41" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img3.png"
 ALT="$ L(r)$"></SPAN>. Una expresión regular se construye a partir de otras expresiones
más simples, utilizando un conjunto definidos de reglas. Estas reglas indican la manera de conseguir el conjunto 
<SPAN CLASS="MATH"><IMG
 WIDTH="41" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img3.png"
 ALT="$ L(r)$"></SPAN> combinando de varias formas los lenguajes denotados por las subexpresiones de <SPAN CLASS="MATH"><IMG
 WIDTH="13" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img4.png"
 ALT="$ r$"></SPAN>. Las expresiones regulares
se pueden definir de una forma recursiva como sigue: 

<P>

<OL>
<LI><SPAN CLASS="MATH"><IMG
 WIDTH="12" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img5.png"
 ALT="$ \epsilon$"></SPAN> es una expresión regular que denota el lenguaje que unicamente contiene la cadena vacía.
</LI>
<LI>Si <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img6.png"
 ALT="$ a$"></SPAN> fuese un símbolo del alfabeto, entonces <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img6.png"
 ALT="$ a$"></SPAN> es una expresión regular que denota el lenguaje formado
por la cadena <SPAN CLASS="MATH"><IMG
 WIDTH="14" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img6.png"
 ALT="$ a$"></SPAN>.
</LI>
<LI>Si <SPAN CLASS="MATH"><IMG
 WIDTH="13" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img4.png"
 ALT="$ r$"></SPAN> y <SPAN CLASS="MATH"><IMG
 WIDTH="13" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img7.png"
 ALT="$ s$"></SPAN> son dos expresiones regulares que denotan los lenguajes <SPAN CLASS="MATH"><IMG
 WIDTH="41" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img3.png"
 ALT="$ L(r)$"></SPAN> y <SPAN CLASS="MATH"><IMG
 WIDTH="41" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img8.png"
 ALT="$ L(s)$"></SPAN> respectivamente entonces:

<UL>
<LI><!-- MATH
 $L(r|s)\ \rightarrow\ L(r)\ \cup\ L(s)$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="203" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img9.png"
 ALT="$ L(r\vert s)\ \rightarrow\ L(r)\ \cup\ L(s)$"></SPAN>
</LI>
<LI><!-- MATH
 $L(rs) \ \rightarrow\ L(r)L(s)$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="164" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img10.png"
 ALT="$ L(rs) \ \rightarrow\ L(r)L(s)$"></SPAN>
</LI>
<LI><!-- MATH
 $L(r*)\ \rightarrow\ (L(r))*$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="153" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img11.png"
 ALT="$ L(r*)\ \rightarrow\ (L(r))*$"></SPAN>
</LI>
<LI><!-- MATH
 $L(r+)\ \rightarrow\ (L(r))+$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="163" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img12.png"
 ALT="$ L(r+)\ \rightarrow\ (L(r))+$"></SPAN>
</LI>
<LI><!-- MATH
 $L(r?)\ \rightarrow\ \{\epsilon\}\ \cup\ L(r)$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="188" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img13.png"
 ALT="$ L(r?)\ \rightarrow\ \{\epsilon\}\ \cup\ L(r)$"></SPAN>
</LI>
<LI><!-- MATH
 $L((r))\ \rightarrow\ (L(r))$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="148" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img14.png"
 ALT="$ L((r))\ \rightarrow\ (L(r))$"></SPAN>
</LI>
</UL>
</LI>
</OL>

<P>
Las gramáticas regulares pueden ser implementadas mediante un autómata finito. Un autómata finito se define formalmente como sigue:
<P><!-- MATH
 \begin{displaymath}
AF = (S,\Sigma,\delta,S_0,F)
\end{displaymath}
 -->
</P>
<DIV ALIGN="CENTER" CLASS="mathdisplay">
<IMG
 WIDTH="173" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img15.png"
 ALT="$\displaystyle AF = (S,\Sigma,\delta,S_0,F)$">
</DIV><P></P>

<P>
De forma que:

<UL>
<LI><SPAN CLASS="MATH"><IMG
 WIDTH="17" HEIGHT="17" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img16.png"
 ALT="$ S$"></SPAN> es un conjunto de estados.
</LI>
<LI><SPAN CLASS="MATH"><IMG
 WIDTH="18" HEIGHT="16" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img17.png"
 ALT="$ \Sigma$"></SPAN> es el conjunto de símbolos que conforman el alfabeto.
</LI>
<LI><SPAN CLASS="MATH"><IMG
 WIDTH="13" HEIGHT="20" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img18.png"
 ALT="$ \delta$"></SPAN> es una función de transición tal que <!-- MATH
 $(\delta\ :\ S\times\Sigma \rightarrow S)$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="148" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img19.png"
 ALT="$ (\delta\ :\ S\times\Sigma \rightarrow S)$"></SPAN>. Donde para cada estado y según 
cada carácter de entrada del alfabeto le hace corresponder un nuevo estado.
</LI>
<LI><SPAN CLASS="MATH"><IMG
 WIDTH="24" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img20.png"
 ALT="$ S_0$"></SPAN> es el estado inicial.
</LI>
<LI><SPAN CLASS="MATH"><IMG
 WIDTH="19" HEIGHT="16" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img21.png"
 ALT="$ F$"></SPAN> es un conjunto de estado finales.
</LI>
</UL>

<P>
El analizador léxico se corresponde con un autómata finito donde, al alcanzarse un estado final, se produce la generación de un token.
Un token es un elemento léxico con cierto valor para el lenguaje. Normalmente se corresponde con una cadena de
caracteres que se puede corresponder con una palabra reservada, un identificador, un número... Un token puede contener un 
valor. Los token son utilizados por el analizador sintáctico para llevar a cabo el procesamiento del código fuente. 

<P>
Las reglas lexicográficas a partir de las cuales se construye el analizador léxico son descritas junto la gramática, haciendo uso
de expresiones regulares y diagramas sintácticos.

<P>

<H4><A NAME="SECTION00022120000000000000">
Analizador sintáctico</A>
</H4>
El analizador sintáctico implementa una gramática de tipo 2 en la jerarquía de Chomsky, esta se corresponden con las 
gramáticas independientes del contexto. Una gramática de este tipo, como su propio nombre indica, no depende del contexto para
su resolución, lo que origina que los recursos que permiten analizarlas sean relativamente eficientes y simples. Una gramática de
este tipo pueden ser analizadas mediante algoritmos con un orden <SPAN CLASS="MATH"><IMG
 WIDTH="53" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img22.png"
 ALT="$ O(n^3)$"></SPAN> donde <SPAN CLASS="MATH"><IMG
 WIDTH="16" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img23.png"
 ALT="$ n$"></SPAN> es el tamaño de la entrada. No obstante existen 
un subconjuntos de este tipo de gramáticas como las <SPAN CLASS="MATH"><IMG
 WIDTH="55" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img24.png"
 ALT="$ LL(k)$"></SPAN> y <SPAN CLASS="MATH"><IMG
 WIDTH="56" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img25.png"
 ALT="$ LR(k)$"></SPAN> que pueden ser analizados en tiempo <SPAN CLASS="MATH"><IMG
 WIDTH="45" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img26.png"
 ALT="$ O(n)$"></SPAN>. Estos últimos son los
comúnmente utilizados en los lenguajes de programación.

<P>
En el análisis sintáctico se pueden utilizar métodos descendentes o ascendentes, en función de cómo se genera el árbol sintáctico. 

<P>
Los métodos de análisis descendentes tienen como objetivo construir el árbol de derivación desde la raíz hacia las hojas. Normalmente se
utilizan analizadores del tipo <SPAN CLASS="MATH"><IMG
 WIDTH="30" HEIGHT="16" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img27.png"
 ALT="$ LL$"></SPAN> dado que la entrada es tratada desde la izquierda y las reglas de producción también desde la izquierda.
Estos tipos de analizadores tienen el problema de la incertidumbre, debido a que dado un símbolo no terminal debe determinar qué regla de derivación aplicar. 
La incertidumbre puede ser reducida mediante métodos como el retroceso o la predicción.

<P>
Los métodos de análisis de ascendentes pretenden construir el árbol de derivación o de sintáxis desde las hojas hacia la raíz. Para este tipo normalmente se utiliza 
analizadores del tipo <SPAN CLASS="MATH"><IMG
 WIDTH="32" HEIGHT="17" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img28.png"
 ALT="$ LR$"></SPAN> dado que la entrada es tratada desde la izquierda, mientras que las reglas de producción son tratadas desde la derecha. Este tipo de
analizadores reducen la incertidumbre dado que se parte de una una regla de derivación para obtener el símbolo no terminal que se corresponde a la misma. 

<P>
Para el lenguaje tratado en este proyecto se tomará un analizador sintáctico ascendente <SPAN CLASS="MATH"><IMG
 WIDTH="32" HEIGHT="17" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img28.png"
 ALT="$ LR$"></SPAN>, dado que es uno de los más utilizados, son eficientes y 
existen herramientas que permiten su generación automática a partir de la descripción de la gramática. 

<P>
Las gramáticas libres de contexto son analizadas mediante un autómata de pila. La configuración en un momento dado del analizador se corresponde con el contendido de la pila y el resto de la 
entrada que aún está por analizar. La entrada estará constituida por tokens obtenidos por el analizador léxicos, teóricamente estos serán almacenados en una estructura de buffer, pero 
en la práctica estos son generados bajo demanda por el analizador léxico. En la pila se irá almacenando una serie de estados en función del procesamiento realizado sobre la cadena de entrada. 
El autómata puede llevar a cabo dos operaciones:

<P>
<DL>
<DT><STRONG>Desplazar:</STRONG></DT>
<DD>Consiste en sacar del buffer de entrada un símbolo terminal e introducir el estado correspondiente en la pila.
</DD>
<DT><STRONG>Reducir:</STRONG></DT>
<DD>Consiste en reducir <SPAN CLASS="MATH"><IMG
 WIDTH="16" HEIGHT="19" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img23.png"
 ALT="$ n$"></SPAN> estados del tope de la pila al estado correspondiente, según las reglas de producción.
</DD>
</DL>

<P>
El análisis finaliza cuando se produce un estado de aceptación o de error. 

<P>
En la práctica este tipo de analizador sintáctico se implementa mediante un programa monitor que encierra la lógica descrita, un buffer de entrada en el que se almacenan
los tokens, una pila que almacena los estados producidos, y dos tablas. La primera tabla guardará las acciones y determina, para el estado actual y el primer símbolo del buffer, 
la acción a realizar (desplazar o reducir). La otra tabla, la tabla de saltos, es utilizada tras llevarse a cabo una de reducción, y determina a partir del estado en el tope de la pila
tras la reducción y la regla que se utilizó para la misma, el siguiente estado a introducir en la pila. 

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="346" HEIGHT="271" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/asd.png"
 ALT="Image asd"> 
<BR>
</DIV>

<P>
Por cada reducción que se lleve a cabo se creará un nodo del árbol sintáctico. De esta forma el árbol es creado desde las hojas hacia la raíz. Cada nodo encierra un significado semántico que 
será llevado a cabo cuando se ejecuten. Estos nodos constituyen a su vez el motor, o back-end, del sistema.

<P>

<H4><A NAME="SECTION00022130000000000000">
Mecanismos de entrada/salida</A>
</H4>
En el nivel de front-end también se dan los diferentes componentes para capturar la entrada del usuario, así como para facilitar la salida que produce en sistema.

<P>
La entrada más común supondrá código fuente que será interpretado y ejecutado. Este se podrá dar de varias formas:

<P>

<UL>
<LI>Mediante la entrada estándar del sistema.
</LI>
<LI>Contenido en fichero.
</LI>
<LI>Mediante un intérprete de línea.
</LI>
</UL>

<P>
Es posible que se den datos de entrada que no sean código fuente, como por ejemplo, una extensión que debe ser cargada, la opción de mostrar ayuda ...

<P>
Por otro lado los datos de salida que produce el programa normalmente serán volcados en la salida estándar sistema en forma de cadenas de caracteres. 
Esta será el resultado visual de la interpretación del código fuente, aunque es posible que un determinado código fuente no produzca salida de este tipo. 

<P>
El programa debe ser capaz de procesar los errores y mostrarlos por la salida de errores del sistema. Para ello debe controlar las líneas y ficheros procesados en cada
momento. Los errores pueden ser de diferente tipos:

<P>

<UL>
<LI>Errores léxicos.
</LI>
<LI>Errores sintácticos.
</LI>
<LI>Errores semánticos.
</LI>
</UL>

<P>
Además los errores pueden presentar diferente grado:

<P>
<DL>
<DT><STRONG>Avisos:</STRONG></DT>
<DD>Informan de que algún recurso del lenguaje no se utiliza de la forma habitual, y aunque no se produce un error como tal, puede suponer un error de codificación.
</DD>
<DT><STRONG>Normales:</STRONG></DT>
<DD>No finalizan la ejecución del código fuente pero provocan que la sentencia en la que sucede no se pueda ejecutar.
</DD>
<DT><STRONG>Críticos:</STRONG></DT>
<DD>Finalizan la ejecución del código fuente.
</DD>
</DL>

<P>

<H3><A NAME="SECTION00022200000000000000">
Motor (back-end)</A>
</H3>
El motor del sistema lo conforman los nodos creados mediante el análisis sintáctico. Estos nodos se denominan nodos ejecutables, dado que su procesamiento conlleva la realización operacional
de la semántica que encierran. Los nodos ejecutables se categorizan según el tipo de operaciones que conlleva su ejecución, así existen nodos aritméticos, lógicos, de control de flujo, 
de definiciones... 

<P>
El sistema presenta una jerarquía de nodos ejecutables que establece la naturaleza de los mismos, dotándolos de características de una forma general y que serán concretadas en los niveles más
bajos de la jerarquía. Se presenta de esta forma, nodos ejecutable genéricos como expresiones, referencias, imprimibles....

<P>
El procesamiento de un nodo ejecutable, que fue creado a partir del análisis sintáctico, puede originar la creación de otros nodos ejecutables, a estos 
últimos se les denominará nodos ejecutables dinámicos. Un nodo dinámico es creado y referenciado por una estructura de datos denominada tabla de símbolos. 
Esta estructura también es considerada un componente del motor del sistema.

<P>
Los nodos ejecutables presentan dos niveles de procesamiento semántico: la inicialización y la ejecución. Además también se ha de controlar cómo estos son creados y eliminados de 
forma dinámica en la tabla de símbolos. 

<P>

<H4><A NAME="SECTION00022210000000000000">
Inicialización</A>
</H4>
Todo nodo ejecutable se inicializa a partir de otros nodos ejecutable sobre los que operará. Normalmente estos nodos se corresponderán con los hijos del nodo en cuestión en el árbol sintáctico. 

<P>
La inicialización de un nodo ejecutable se lleva a cabo durante la creación del árbol sintáctico, por tanto los nodos se inicializan de una forma ascendente, es decir,
antes los nodos hijos que los padre.

<P>
Durante la inicialización se lleva a cabo algunas comprobaciones de tipos, asignaciones y otras operaciones. No obstante, todo proceso que se lleve a cabo durante la
inicialización debe ser independiente de la ejecución. Se ha de tener en cuenta que un nodo ejecutable sólo se inicializa una vez, y sin embargo se puede ejecutar varias
veces, siendo esta última dependiente del estado en un momento dado. Se puede decir pues que la inicialización tiene un carácter estático.

<P>

<H4><A NAME="SECTION00022220000000000000">
Ejecución</A>
</H4>
Una vez generado el árbol sintáctico, lo que conlleva la inicialización de los nodos ejecutables que lo componen, se procede a la ejecución del mismo. La ejecución comienza desde el 
nodo raíz hacia las hojas, se hace pues un recorrido del árbol en profundidad.

<P>
La ejecución de un nodo es iniciada normalmente desde su nodo padre, y generalmente conlleva la ejecución de sus nodos hijos antes de proceder a su propia ejecución. Así por ejemplo 
la ejecución de un nodo suma conllevará el cálculo del lado izquierdo de la expresión, lo que se corresponde con la ejecución uno de sus nodos hijo, luego se calculará
el lado derecho, correspondiente a la ejecución del otro nodo hijo, para, una vez ejecutados sus hijos (los operandos), proceder al cálculo de la suma, lo que se corresponde 
con su propia ejecución. 

<P>
Durante la ejecución de un nodo ejecutable lo normal es que primero se resuelvan los nodos referencias, aquellos que se corresponden con nodos dinámicos de tipos no definidos. Estos 
nodos referencian a otros nodos creados dinámicamente en la interpretación y que se encuentran accesibles desde la tabla de símbolos. Algunos nodos referencias, 
también denominados nodos de expresiones no definidas, son los correspondientes a: variables, funciones u clases de objetos. Una vez se ha obtenido el nodo al que estos referencian, 
se procede con la ejecución como si los nodos obtenidos fueran los hijos del nodo en proceso.

<P>
Aunque la ejecución del árbol se hace inicialmente con un recorrido en profundidad existen nodos que rompen esta secuencia, haciendo que la ejecución pase a nodos específicos 
o repitiendo la ejecución de varios de sus hijos. Cabe decir que una vez se salte la secuencia de ejecución el recorrido seguirá siendo en profundidad. Estos nodos 
se corresponden con sentencias de control de flujo, llamadas a funciones, etc.

<P>
El resultado de ejecutar un nodo no tiene por que ser estático, dependiendo en gran medida del contexto, es decir, del estado de la tabla de símbolos. Se puede decir pues que la 
ejecución de un nodo tiene un carácter dinámico dependiente de la tabla de símbolos.

<P>

<H4><A NAME="SECTION00022230000000000000">
Tabla de símbolos</A>
</H4>
La tabla de símbolos es una estructura de datos que almacena referencias a nodos creados dinámicamente en el proceso de interpretación. Estos nodos serán creados en la 
ejecución del árbol de sintáctico y serán accedidos desde la ejecución de determinados nodos en la resolución de referencias. 

<P>
Las tablas de símbolos se componen de pares donde el primer elemento es un identificador que nomina al símbolo y el segundo elemento es una referencia al nodo ejecutable. 

<P>
Aunque en una tabla de símbolos es posible guardar referencias a cualquier nodo se mantiene diferentes tipos tablas de símbolos según la naturaleza de los nodos a los que se
referencian. Esto hace posible que se puedan repetir identificadores para distintos tipos de nodos como variables, funciones o clases.

<P>
Dos identificadores que pueden estar en la misma tabla de símbolos o distintas, pueden referenciar al mismo nodo. El propio nodo debe ser capaz de guardar cuantas referencias al 
mismo tiene. Esto se hace por criterios de optimización, para la reutilización de datos y para realizar una eliminación del nodo de una forma segura cuando sea necesario.

<P>
Las tablas de símbolos pueden quedar organizadas en niveles, aunque únicamente un nivel, el actual en un momento dado, es el que se utilizará para la resolución de referencias.
Esto hace posible definir diferentes ámbito para el acceso a determinados símbolos. Los niveles quedan dispuestos en una estructura de pila, de forma que el nivel actual es
la cima de la pila. Una vez un nivel es eliminado de la pila se eliminan todas las referencias del mismo y el nivel anterior queda en la cima y por tanto es considerado el nivel actual.

<P>
Existen nodos que presentan sus propias tablas de símbolos, esto hace que muchas definiciones sean internas al mismo. Por ejemplo las clases de objetos mantienen sus propias tablas
de símbolos para referencias los métodos y atributos, y los arrays presentan una tabla de símbolos para guardar las claves y sus valores. Es común que en la ejecución 
de uno de estos nodos se sustituya la tabla de símbolos en uso por la del nodo en cuestión.

<P>
La tabla de símbolo es una estructura de datos que forma parte del motor de la aplicación dado que gestiona y almacena datos presentes en este nivel. 

<P>

<H4><A NAME="SECTION00022240000000000000">
Eliminación de referencias</A>
</H4>
Los nodos creados de forma dinámica por el proceso de interpretación deben ser eliminados cuando ya no se precisen de ellos. Por ejemplo cuando se produce una asignación destructiva. Como
los nodos creados de forma dinámica son reutilizados y pueden ser referenciados por más de un símbolo se ha de controlar que no exista ninguna referencia al mismo 
antes de proceder a su eliminación. Así cada nodo guarda el número de referencias al mismo.

<P>
Los nodos correspondientes al árbol sintáctico nunca serán eliminados durante la ejecución y no será hasta la finalización del programa hasta que se proceda a la liberación de los recursos 
que consumen.

<P>

<H3><A NAME="SECTION00022300000000000000">
runTree</A>
</H3>
runTree es un sistema que hace de cliente del intérprete OMI, cuando este funciona como servidor. Se encarga de llevar a cabo peticiones para navegar por el proceso de interpretación de un código
fuente dado. 

<P>
El cliente runTree presenta una arquitectura interna en dos capas al igual que el intérprete. El backend de este se comunica con el forntend del intérprete cuando funciona de servidor

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="257" HEIGHT="145" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/generic_cliente_servidor.png"
 ALT="Image generic_cliente_servidor"> 
<BR>
</DIV>

<P>
El frontend del cliente runTree lo componen elementos relacionados con la interfaz del usuario. Captura eventos de esta y lo envía al backend para su procesamiento, a su vez representa los datos que recibe del backend. 

<P>
El backend del cliente runTree lo componen elementos que guardan el estado interno del proceso de interpretación. Normalmente estos elementos son inicializados mediante datos que recibe del servidor como fruto de 
una petición.

<P>
<H1><A NAME="SECTION00030000000000000000">
Diseño de la gramática</A>
</H1>
En esta sección se presenta la gramática del lenguaje, para ello 
se procede a una descripción de las reglas gramaticales
 mediante el lenguaje EBNF (Extended Backus–Naur Form) 
usado para expresar gramáticas libres de contexto. Además cada regla se acompaña de un
diagrama sintáctico o diagrama de carril. 

<P>
Una gramática <SPAN CLASS="MATH"><IMG class="gramatic"
  ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img29.png"
 ALT="$ G$"></SPAN> se define formalmente como sigue:

<P>
<P><!-- MATH
 \begin{displaymath}
G = (V_t,V_n, P, S)
\end{displaymath}
 -->
</P>
<DIV ALIGN="CENTER" CLASS="mathdisplay">
<IMG class="gramatic"
  ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img30.png"
 ALT="$\displaystyle G = (V_t,V_n, P, S)$">
</DIV><P></P>

<P>
De forma que:

<P>
<DL>
<DT><STRONG><SPAN CLASS="MATH"><IMG class="gramatic"
  ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img31.png"
 ALT="$ V_t$"></SPAN></STRONG></DT>
<DD>es un conjunto finito de símbolos no terminales
</DD>
<DT><STRONG><SPAN CLASS="MATH"><IMG class="gramatic"
  ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img32.png"
 ALT="$ V_n$"></SPAN></STRONG></DT>
<DD>es un conjunto finito de símbolos terminales
</DD>
<DT><STRONG><SPAN CLASS="MATH"><IMG class="gramatic"
  ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/img33.png"
 ALT="$ P$"></SPAN></STRONG></DT>
<DD>es un conjunto finito de reglas de producción
</DD>
<DT><STRONG><!-- MATH
 $S\ \epsilon\ V_n$
 -->
<SPAN CLASS="MATH"><IMG class="gramatic"
  ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img34.png"
 ALT="$ S\ \epsilon\ V_n$"></SPAN></STRONG></DT>
<DD>es el símbolo inicial
</DD>
</DL>

<P>
Las reglas de producción de una grmática libre de contexto tiene la forma siguiente forma:

<P>
<P><!-- MATH
 \begin{displaymath}
V_n\ \rightarrow\ (V_t\ \cup\ V_n)^*
\end{displaymath}
 -->
</P>
<DIV ALIGN="CENTER" CLASS="mathdisplay">
<IMG class="gramatic"
  ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img35.png"
 ALT="$\displaystyle V_n\ \rightarrow\ (V_t\ \cup\ V_n)^*$">
</DIV><P></P> 

<P>
La gramática libre de contexto abordada tiene como símbolo inicial 
el no terminal <SPAN CLASS="MATH"><IMG class="gramatic"
  ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img36.png"
 ALT="$ program$"></SPAN>. Se comienza pues describiendo las reglas de producción 
relicionadas con este símbolo, siguiendo con las reglas de producción derivadas 
de esta. 

<P>
Las reglas de producción se organizan en niveles como sigue:

<P>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/omi.png"
 ALT="Image omi"> 
<BR>
</DIV>

<P>
Estos niveles son dados a partir del nivel de abstracción del significado 
semántico que encierran las reglas de producción contenidas en los mismos.

<P>
Las reglas de producción correspondientes al nivel de programa 
son las más genéricas y se valen de las de la siguiente nivel para 
su definición. Estas definen el programa como una secuencia de
sentencias. La gramática descrita contempla el programa vacío, es decir,
el programa que no contiene ninguna sentencia.

<P>
Las reglas de producción del nivel de sentencia se definen a 
partir de expresiones o de otras sentencias. Una sentencia contiene un significado semántico
operativo de valor para el programa. Cabe decir que una expresión por si sola 
puede constituir una sentencia. La gramática expuesta describe la sentencia
vacía, esta es una sentencia que no tienen ningún significado semántico.

<P>
Las expresiones son la unidad mínima con significado semántico atribuido por 
el lenguaje. La mayoría de expresiones se definen a partir de identidades, 
sin embargo algunos tipos de expresiones, como las funciones, pueden formarse
a partir de reglas de más alto nivel de abstracción semantica. Por otro lado las 
reglas de producción correspondiente a las expresiones están organizadas en niveles según
la prioridad atribuida en su resolución.

<P>
Las identidades son reglas de producción atómicas, componiéndose únicamente de símblos no terminales. 
Tienen un significado semántico asociado de forma directa. Normalmente este valor viene dado por 
el análisis léxico.  

<P>

<H2><A NAME="SECTION00031000000000000000">
Programa</A>
</H2>
<PRE>
program  ::=  stmts
            | empty
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
WIDTH="200" HALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/program.png"
 ALT="Image program"> 
<BR>
</DIV>
<H2><A NAME="SECTION00032000000000000000">
Sentencias</A>
</H2>

<H3><A NAME="SECTION00032100000000000000">
Secuecia de sentencias</A>
</H3>
<PRE>
stmts    ::=   stmt ";" stmts
            |  stmt ";"?
            |  stmtb 
            |  label stmts
            |  ";"
</PRE>  	

<DIV ALIGN="CENTER">
<IMG class="gramatic"
  WIDTH="200" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/stmts.png"
 ALT="Image stmts"> 
<BR>
</DIV>

<H3><A NAME="SECTION00032200000000000000">
Sentencia de bloque</A>
</H3>
<PRE>
stmtb ::=   if
         |  while
         |  dowhile
         |  for
         |  foreach
         |  break
         |  switch
         |  iloop
         |  trycatch
         |  class
         |  with
</PRE>  	

<DIV ALIGN="CENTER">
<IMG class="gramatic"
 WIDTH="200"  ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/stmtb.png"
 ALT="Image stmtb"> 
<BR>
</DIV>
<H4><A NAME="SECTION00032210000000000000">
Sentencia de control: if</A>
</H4>
<PRE>[style=nonumbers,
    basicstyle=\tiny, %or \small or \footnotesize etc.
]
if ::= "if" exp ("{" stmts? "}" | stmt ";" | stmtb) elif* ("else" ("{" stmts? "}" | stmt ";" | stmtb))?

elif ::=  "elif" exp ( "{" stmts? "}" | stmt ";" | stmtb )
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/if.png"
 ALT="Image if"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/elif.png"
 ALT="Image elif"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00032220000000000000">
Sentencia de control: while</A>
</H4>
<PRE>[style=nonumbers,
    basicstyle=\tiny]
while ::= 
   "while" exp ("{" stmts? "}" | stmt ";" | stmtb)
</PRE>  	

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/while.png"
 ALT="Image while"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00032230000000000000">
Sentencia de control: do...while</A>
</H4>
<PRE>
dowhile ::=  "do" ( "{" stmts? "}" | stmt ";" | stmtb ) "while" exp ";"
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/dowhile.png"
 ALT="Image dowhile"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00032240000000000000">
Sentencia de control: for</A>
</H4>
<PRE>
for ::= "for" "("? exp? ";" exp? ";" exp? ")"? ( "{" stmts? "}" | stmt ";" | stmtb )
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/for.png"
 ALT="Image for"> 
<BR>
</DIV>
<H4><A NAME="SECTION00032250000000000000">
Sentencia de control: forearch</A>
</H4>
<PRE>[style=nonumbers,basicstyle=\tiny]
foreach ::= 
   "for" "("?(id (":" id)? "in" exp | exp "as" id (":" id)?)")"? ("{" stmts? "}" | stmt ";" | stmtb)
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/foreach.png"
 ALT="Image foreach"> 
<BR>
</DIV>

<H4><A NAME="SECTION00032260000000000000">
Sentencia de control: switch</A>
</H4>
<PRE>
switch ::= "switch" "(" exp ")" "{" cases? "}"

cases ::= "case" exp ":" ( stmts cases | stmts | cases )
   |  "default" ":" stmts
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/switch.png"
 ALT="Image switch"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/cases.png"
 ALT="Image cases"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00032270000000000000">
Sentencia de control: iloop</A>
</H4>
<PRE>[style=nonumbers,basicstyle=\tiny]
iloop ::= "$" "(" exp ( "as" id (":" id)? )? ("," exp )? ")" ( "{" stmts? "}" | stmt ";" | stmtb )

iloop_access ::=  "$"
               |  "$" "{" NUM "}"
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/iloop.png"
 ALT="Image iloop"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/iloop_access.png"
 ALT="Image iloop_access"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00032280000000000000">
Sentencia de control: try...catch</A>
</H4>

<P>
<PRE>[style=nonumbers,basicstyle=\tiny]
trycatch ::= 
 "try" ( "{" stmts? "}" | stmt ";" | stmtb ) catch "(" id ")" ( "{" stmts? "}" | stmt ";" |  stmtb )
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/trycatch.png"
 ALT="Image trycatch"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00032290000000000000">
Sentencia de control: with</A>
</H4>
<PRE>[style=nonumbers,basicstyle=\tiny]
with ::= 
 "with" exp ( "{" stmts? "}" | stmt ";" | stmtb )
</PRE>  	

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/with.png"
 ALT="Image with"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00032300000000000000">
Sentencia simple</A>
</H3>
<PRE>
stmt  ::=   exp
         |  "&lt;&lt;" exp
         |  "&gt;&gt;" ("[" exp "]")? id
         |  "goto" exp
         |  "include" exp
         |  "return" exp?
         |  "sleep" exp 
         |  "load" exp 
         |  "typeof" id 
         |  "datinfo" exp
         |  "exit"
         |  "throw" exp
         |  "global" identity
         |  "break" num? ";"
         |  "continue" num? ";"
</PRE>  	

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/stmt.png"
 ALT="Image stmt"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00032400000000000000">
Etiquetas</A>
</H3>
<PRE>
label ::=   id ":"
</PRE>  	

<DIV ALIGN="CENTER">
<IMG class="gramatic"
 WIDTH="200"  ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/label.png"
 ALT="Image label"> 
<BR>
</DIV>

<H3><A NAME="SECTION00032500000000000000">
Nombres de espacios</A>
</H3>
<PRE>[style=nonumbers, basicstyle=\tiny]      
namespace ::=  namespace "::" id
            |  id "::" id
            |  "parent" "::" id
            |  "static" "::" id
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/namespace.png"
 ALT="Image namespace"> 
<BR>
</DIV>
<H3><A NAME="SECTION00032600000000000000">
Clases</A>
</H3>
<PRE>
class ::= "class" id ("extends" id )? "{" class_stmts? "}"
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/class_gramatic.png"
 ALT="Image class_gramatic"> 
<BR>
</DIV>
<H4><A NAME="SECTION00032610000000000000">
Métodos y atributos</A>
</H4>
<PRE>
class_stmts ::= 
   (("static"|"private"|"private" "static"|"static" "private")? (function|id|assig))*
</PRE>  	
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/class_stmts.png"
 ALT="Image class_stmts"> 
<BR>
</DIV>
<H2><A NAME="SECTION00033000000000000000">
Expresiones</A>
</H2>
<PRE>      
exp ::= op1
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/exp.png"
 ALT="Image exp"> 
<BR>
</DIV>
<H3><A NAME="SECTION00033100000000000000">
Operadores lógicos</A>
</H3>

<H4><A NAME="SECTION00033110000000000000">
Or lógico</A>
</H4>
<PRE>      
op1 ::=  op1 ( "||" | "or" ) op2
      |  op2
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/lop1.png"
 ALT="Image lop1"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00033120000000000000">
And lógico</A>
</H4>
<PRE>      
op2 ::=  op2 ( "&amp;&amp;" | "and" ) op3
      |  op3
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/op2.png"
 ALT="Image op2"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00033130000000000000">
Negación lógica</A>
</H4>
<PRE>      
op3 ::=  "!" op3 
      |  op4
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/op3.png"
 ALT="Image op3"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00033140000000000000">
Comparaciones</A>
</H4>
<PRE>      
op4 ::=  op4 "&lt;" op5
      |  op4 "&lt;=" op5
      |  op4 "&gt;" op5
      |  op4 "&gt;=" op5
      |  op4 "==" op5
      |  op4 "!=" op5
      |  op4 "===" op5
      |  op4 "!==" op5
      |  op5
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/op4.png"
 ALT="Image op4"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00033200000000000000">
Operadores aritméticos</A>
</H3>

<H4><A NAME="SECTION00033210000000000000">
Suma y diferencia</A>
</H4>
<PRE>      
op5 ::= op5 "+" op6
      |  op5  "-" op6
      |  op6
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/op5.png"
 ALT="Image op5"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00033220000000000000">
Producto y división</A>
</H4>
<PRE>      
op6  ::= op6 "*" op7
      |  op6 "/" op7
      |  op7
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/op6.png"
 ALT="Image op6"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00033230000000000000">
Potencia y módulo</A>
</H4>
<PRE>      
op7  ::= op7 "^" op8
      |  op7 "%" op8
      |  op8
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/op7.png"
 ALT="Image op7"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00033300000000000000">
Operadores cadenas de caracteres</A>
</H3>

<H4><A NAME="SECTION00033310000000000000">
Concatenación</A>
</H4>
<PRE>      
op8 ::=  op8 "." op9
      |  op9
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/op8.png"
 ALT="Image op8"> 
<BR>
</DIV>
<H4><A NAME="SECTION00033320000000000000">
Flujo</A>
</H4>
<PRE>      
op9  ::= call "&lt;&lt;" op9
      |  call
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/op9.png"
 ALT="Image op9"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00033400000000000000">
Llamadas</A>
</H3>
<PRE>      
call ::= call "(" list? ")"
      |  opc
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/call.png"
 ALT="Image call"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00033500000000000000">
Operadores condicionales</A>
</H3>
<PRE>      
opc ::=  tern
      |  nullcoalescing
      |  unity
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/opc.png"
 ALT="Image opc"> 
<BR>
</DIV>
<H4><A NAME="SECTION00033510000000000000">
Operador ternario</A>
</H4>
<PRE>      
tern ::= exp "?" exp? ":" exp
   |  exp "?" exp
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/tern.png"
 ALT="Image tern"> 
<BR>
</DIV>
<H4><A NAME="SECTION00033520000000000000">
Null coalescing</A>
</H4>
<PRE>      
nullcoalescing ::= "[[" list "]]"
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/nullcoalescing.png"
 ALT="Image nullcoalescing"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00033600000000000000">
Operadores unitarios</A>
</H3>
<PRE>      
unity ::=   inc_dec
         |  assignation_exp
         |  cast
         |  logical_func
         |  arith_func
         |  array_func
         |  string_func
         |  regexp_func
         |  iloop_access
         |  class_exp
         |  func_exp
         |  file
         |  date
         |  process
         |  generator
         |  environments
         |  array
         |  identity
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/unity.png"
 ALT="Image unity"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00033610000000000000">
Incrementos y decrementos</A>
</H4>
<PRE>      
inc_dec ::= "++" exp
         |  exp "++"
         |  "--" exp
         |  exp "--"
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/inc_dec.png"
 ALT="Image inc_dec"> 
<BR>
</DIV>

<H4><A NAME="SECTION00033620000000000000">
Conversión de tipos</A>
</H4>
<PRE>      
cast ::= "int" exp
      |  "float" exp
      |  "bool" exp
      |  "str" exp
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/cast.png"
 ALT="Image cast"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION00033630000000000000">
Accesos</A>
</H4>
<PRE>[style=nonumbers, basicstyle=\tiny]      
access ::=  access "-&gt;" id
         |  access "[" exp? "]"
         |  call "-&gt;" id
         |  call "[" exp? "]"
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/access.png"
 ALT="Image access"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00033700000000000000">
Asignaciones</A>
</H3>
<PRE>[style=nonumbers, basicstyle=\tiny]      
assignation ::=   
 (id | assignation | access)  "=" "&amp;"? exp
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/assignation.png"
 ALT="Image assignation"> 
<BR>
</DIV>
<H3><A NAME="SECTION00033800000000000000">
Funciones</A>
</H3>
<PRE>
function ::= "~" id "(" params_val? ")" "{" stmts? "}"
</PRE>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/function.png"
 ALT="Image function"> 
<BR>
</DIV>
<H4><A NAME="SECTION00033810000000000000">
Función lambda</A>
</H4>
<PRE>
function_lambda ::= "~" "(" params_val? ")" "{" stmts? "}"
    | "~" params_val ":" exp
    | "~&amp;" id
</PRE>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/function_lambda.png"
 ALT="Image function_lambda"> 
<BR>
</DIV>
<H4><A NAME="SECTION00033820000000000000">
Cálculo parcial</A>
</H4>
<PRE>
function_partial ::= "P" "[" params_val "]" "(" id ")"
   |  "P" "[" params_val "]" "(" function_exp ")"
   |  "P" "[" params_val "]" "(" arrayexp ")"
</PRE>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/function_partial.png"
 ALT="Image function_partial"> 
<BR>
</DIV>
<H4><A NAME="SECTION00033830000000000000">
Función de contexto</A>
</H4>
<PRE>
function_context ::= "~&gt;"
</PRE>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/function_context.png"
 ALT="Image function_context"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00033900000000000000">
Decoradores</A>
</H3>
<PRE>
decorator ::= "~~" id "(" params_val? ")" "{" stmts? "}"
</PRE>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/decorator.png"
 ALT="Image decorator"> 
<BR>
</DIV>
<H4><A NAME="SECTION00033910000000000000">
Decorador lambda</A>
</H4>
<PRE>
decorator_lambda ::= "~~" "(" params_val? ")" "{" stmts? "}"
</PRE>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/function_decorator.png"
 ALT="Image function_decorator"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000331000000000000000">
Operadores clases y objetos</A>
</H3>
<PRE>      
class_exp ::=  "new" id ("(" list? ")")?
            |  "this" 
            |  "parent"
            |  namespace
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/class_exp.png"
 ALT="Image class_exp"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000331100000000000000">
Funciones del lenguaje</A>
</H3>

<H4><A NAME="SECTION000331110000000000000">
Funciones lógicas</A>
</H4>
<PRE>      
logical_func ::=  "isnull" exp
               |  "empty" exp
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/logical_func.png"
 ALT="Image logical_func"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION000331120000000000000">
Funciones aritméticas</A>
</H4>
<PRE>      
arith_func ::= "size" exp
            |  "sizeof" exp
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/arith_func.png"
 ALT="Image arith_func"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION000331130000000000000">
Funciones cadenas de caracteres</A>
</H4>
<PRE>      
string_func ::=   "sprintf" "(" exp "," exp ")"
               |  "str_replace" "(" exp "," exp "," exp ("," exp)? ")"
               |  "str_subreplace" "(" exp "," exp "," exp "," exp ")"
               |  "str_find" "(" exp "," exp ("," exp)? ")"
               |  "str_upper" "(" exp ")"
               |  "str_lower" "(" exp ")"
</PRE>  
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/string_func.png"
 ALT="Image string_func"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION000331140000000000000">
Funciones arrays</A>
</H4>
<PRE>      
array_func ::= 
 "array_explode" "(" exp "," exp ")"
 |  "array_implode" "(" exp "," exp ")"
 |  "array_chunck" "(" exp "," exp ")"
 |  "array_reduce" "(" exp "," exp ")"
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/array_func.png"
 ALT="Image array_func"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION000331150000000000000">
Funciones expresiones regulares</A>
</H4>
<PRE>      
regexp_func ::=   "regexp" "(" exp ")"
               |  "search" "(" exp "," exp ("," list)? ")"
               |  "match" "(" exp "," exp ")"
</PRE>  
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/regexp_func.png"
 ALT="Image regexp_func"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION000331160000000000000">
Funciones fechas y tiempo</A>
</H4>
<PRE>      
date ::= "date" "(" exp ")"
      |  "time" ("(" ")")
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/date.png"
 ALT="Image date"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION000331170000000000000">
Funciones acceso a entorno</A>
</H4>
<PRE>      
environment ::= "getenv" "(" exp ")"
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/environment.png"
 ALT="Image environment"> 
<BR>
</DIV>

<P>

<H4><A NAME="SECTION000331180000000000000">
Funciones ficheros</A>
</H4>
<PRE>[style=nonumbers, basicstyle=\tiny]      
file ::= "file" "(" exp ("," exp)? ")"
   |  "fput" "(" exp "," exp ")"
   |  "fwrite" "(" exp "," exp ")"
   |  "fappend" "(" exp "," exp ")"
   |  "fget" "(" exp ("," exp)? ")"
   |  "fread" "(" exp ")"
   |  "fclose" "(" exp ")"
   |  "fseek" "(" exp "," exp ("," fposs)? ")"
   |  "ftell" "(" exp ")"

fpos ::= FSET
      |  FCUR
      |  FEND
</PRE>  
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/fpos.png"
 ALT="Image fpos"> 
<BR>
</DIV>

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/file.png"
 ALT="Image file"> 
<BR>
</DIV>

<P>

<P>

<H4><A NAME="SECTION000331190000000000000">
Funciones procesos</A>
</H4>
<PRE>[style=nonumbers, basicstyle=\tiny]      
process ::= "exec" "(" exp ")"
         |  "eval" "(" exp ")"
         |  "fork" "(" ")"
         |  "wait" "(" exp? ")"
         |  "signal" "(" exp "," exp ")"
         |  "signalhandler" "(" exp "," exp ")"
         |  "exitProcess" "(" ")"
         |  "getpid" "(" ")"
         |  "getppid" "(" ")"
         |  "process" "(" exp ("," list)? ")"
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/process.png"
 ALT="Image process"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION000331200000000000000">
Generadores</A>
</H3>
<PRE>[style=nonumbers, basicstyle=\tiny]      
generator ::= "(" exp (":" exp)? "for" id (":" id )? "in" exp ( "if" exp )? ("{" stmts "}")? ")"
   | "(" exp (":" exp)? "for" "(" id (":" id )? "in" exp ")" ( "if" exp )? ("{" stmts "}")? ")"
</PRE>  
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/generator.png"
 ALT="Image generator"> 
<BR>
</DIV>
<H2><A NAME="SECTION00034000000000000000">
Identidades</A>
</H2>
<PRE>      
identity ::=   num
            |  "true"
            |  "false"
            |  "null"
            |  str
            |  rexp
            |  id
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/identity.png"
 ALT="Image identity"> 
<BR>
</DIV>
<H3><A NAME="SECTION00034100000000000000">
Parámetros</A>
</H3>
<PRE>
params_val ::= params_val "," id "=" identity 
   |  params "," id "=" identity 
   |  id "=" identity 
   |  params
   
params ::= params "," "&amp;"? id
   |  "&amp;"? id
</PRE>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/params_val.png"
 ALT="Image params_val"> 
<BR>
</DIV>

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/params.png"
 ALT="Image params"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00034200000000000000">
Listas y pares</A>
</H3>
<PRE>      
list ::= list "," exp?
      |  exp
</PRE>  
<PRE>      
map ::=  map "," pair?
      |  pair
   
pair ::= exp ":" exp
</PRE>  
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/pair.png"
 ALT="Image pair"> 
<BR>
</DIV>

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/list.png"
 ALT="Image list"> 
<BR>
</DIV>
<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/map.png"
 ALT="Image map"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00034300000000000000">
Identificador</A>
</H3>
<PRE>      
id ::= [a-zA-Z_][a-zA-Z0-9_]*
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/id.png"
 ALT="Image id"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00034400000000000000">
Números</A>
</H3>
<PRE>      
num ::=  ("+"|"-"|) [0-9]+(.[0-9]+)?
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/num.png"
 ALT="Image num"> 
<BR>
</DIV>
<H3><A NAME="SECTION00034500000000000000">
Cadenas de caracteres</A>
</H3>
<PRE>      
str ::= "'".* "'"
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/str.png"
 ALT="Image str"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00034600000000000000">
Array</A>
</H3>
<PRE>      
array ::=   "{" list "}"
         |  "{" map "}"
         |  "{""}"
         |  "arrayop"
         |  access
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/array.png"
 ALT="Image array"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00034700000000000000">
Expresión regular</A>
</H3>
<PRE>      
regexp ::= "`".*"`"
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/regexp.png"
 ALT="Image regexp"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00034800000000000000">
Comentarios</A>
</H3>
<PRE>      
comments ::=   "/*" [^*]* "*/"
            |  "//"[^\n]
            |  "#" [^#]
</PRE>  

<DIV ALIGN="CENTER">
<IMG class="gramatic"
   ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/comments.png"
 ALT="Image comments"> 
<BR>
</DIV>

<P>

<H1><A NAME="SECTION00040000000000000000">
Diseño de comunicaciones</A>
</H1>
OMI puede ser ejecutado de forma que guarde en un fichero una estructura de datos que representa el proceso de interpretación seguido. 
Esta estructura de datos tiene un formato JSON. En esta sección se presenta la estructura de estos ficheros mediante el esquema de 
json-schema.org.

<P>
Cuando el intérprete se ejecuta en modo servidor se vale de esta misma estructura para devolver el estado del proceso. Otros sistemas
que hagan de cliente pueden interpretar esta estrucutra de datos para operar con los mismos. 
<H2><A NAME="SECTION00041000000000000000">
Esquema JSON</A>
</H2>

<P>

<H2><A NAME="SECTION00042000000000000000">
Nodos ejecutables</A>
</H2>
La primera estructura de datos JSON que es guardada representa el árbol fruto del análisis léxico y sintáctico. Esta estructura de datos tiene como elemento
base un nodo que mantendrá relaciones con otros nodos. A partir del nodo raíz se puede obtener todo el árbol de nodos.

<P>
<PRE>
{
   "$schema": "http://omi-project.com/json-schema/node",
   "title": "Nodos del ábol sintáctico"
   "type": "object",
   "properties": {
      "id": {
        "description": "Posición de memoria del nodo",
        "type" : "string", 
      },
      "name": {
         "description": "Nombre del nodo",
         "type": "string",
      },
      "type": {
         "description": "Tipo del nodo",
         "type": "string",
      },
      "size": {
         "description": "Tamaño del nodo en Bytes",
         "type": "string",
      },
      "rel": {
         "description": "Relaciones con otros nodos",
         "type": "array",
         "items": {
            "ref":  "http://omi-project.com/json-schema/node"
         }
      },
      "relname": {
         "description": "Nombre de las relaciones con otros nodos",
         "type": "array",
         "items": {
            "type":  "string",
         }
      },
   }
}
</PRE>
<P>

<H2><A NAME="SECTION00043000000000000000">
Acciones</A>
</H2>
Para representar el proceso de interpretación se precisa de una estructura de datos que indique las acciones 
llevadas a cabo en el proceso.

<P>
<PRE>
{
   "$schema": "http://omi-project.com/json-schema/process",
   "title": "Proceso de interpretación",
   "type": "array",
   "items": {
      "type": "object",
        "properties": { 
            "action": {
               "description": "Acción que se corresponde con un paso",
               "type": "enum",
            },
            "id": {
               "description": "Id del nodo sobre el que se lleva a cabo la acción",
               "type": "string",
            },
            "attrs": {
               "description": "Atributos de la accón. Dependen de la acción".
               "type": "object",
            }
      }
   }
}
</PRE>
<P>
Los tipos de acciones son los siguientes:
<DL>
<DT><STRONG>run:</STRONG></DT>
<DD>Ejecución de un nodo.
</DD>
<DT><STRONG>runClass:</STRONG></DT>
<DD>Ejecución de un nodo clase.
</DD>
<DT><STRONG>endClass:</STRONG></DT>
<DD>Finaliza la ejecución de una clase.
</DD>
<DT><STRONG>setParent:</STRONG></DT>
<DD>Establece el padre de un nodo clase.
</DD>
<DT><STRONG>setValue:</STRONG></DT>
<DD>Establece el valor de un nodo.
</DD>
<DT><STRONG>setRef:</STRONG></DT>
<DD>Establece el valor de una referencia.
</DD>
<DT><STRONG>accessVar:</STRONG></DT>
<DD>Accede al valor de una variable.
</DD>
<DT><STRONG>accessFunc:</STRONG></DT>
<DD>Accede al valor de una funcion.
</DD>
<DT><STRONG>accessClass:</STRONG></DT>
<DD>Accede al valor de una clase.
</DD>
<DT><STRONG>clone:</STRONG></DT>
<DD>Clona un nodo.
</DD>
<DT><STRONG>newNode:</STRONG></DT>
<DD>Crea un nuevo nodo.
</DD>
<DT><STRONG>changeRef:</STRONG></DT>
<DD>Cambia el valor de una referencia.
</DD>
<DT><STRONG>changeValue:</STRONG></DT>
<DD>Cambia el valor de un nodo.
</DD>
<DT><STRONG>delete:</STRONG></DT>
<DD>Elimina un nodo.
</DD>
<DT><STRONG>print:</STRONG></DT>
<DD>Imprime en la salida estándar.
</DD>
<DT><STRONG>input:</STRONG></DT>
<DD>Toma valores de la entrada estándar.
</DD>
<DT><STRONG>toSymbols:</STRONG></DT>
<DD>Añade elementos a la tabla de símbolos interna de un nodo.
</DD>
<DT><STRONG>removeLevel:</STRONG></DT>
<DD>Elimina un nivel de la tabla de símbolos.
</DD>
<DT><STRONG>return:</STRONG></DT>
<DD>Se devuelve un valor.
</DD>
<DT><STRONG>error:</STRONG></DT>
<DD>Se ha producido un error.
</DD>
<DT><STRONG>sleep:</STRONG></DT>
<DD>Se espera un evento.
</DD>
<DT><STRONG>runStatic:</STRONG></DT>
<DD>Comienza la ejecución de un elemento estático.
</DD>
<DT><STRONG>endStatic:</STRONG></DT>
<DD>Finaliza la ejecución de un elemento estático.
</DD>
<DT><STRONG>runPrivate:</STRONG></DT>
<DD>Comienza la ejecución de un elemento privado.
</DD>
<DT><STRONG>endPrivate:</STRONG></DT>
<DD>Finaliza la ejecución de un elemento privado.
</DD>
<DT><STRONG>runGlobal:</STRONG></DT>
<DD>Comienza la ejecución de un elemento global.
</DD>
<DT><STRONG>endGlobal:</STRONG></DT>
<DD>Finaliza la ejecución de un elemento global.
</DD>
<DT><STRONG>line:</STRONG></DT>
<DD>Especifica la línea actual del código fuente.
</DD>
</DL>

<H1><A NAME="SECTION00050000000000000000">
Diseño de componentes</A>
</H1>
El presente documento constituye el modelo de comportamiento básico.
Este detalla cómo los distintos objetos interaccionan y se comunican entre sí para
analizar la entrada del usuario, correspondiente el código fuente, e interpretarlo
para su ejecución.

<P>
Se presenta un diagrama de secuencia para la operación interpretación
de un código fuente. Luego se presenta diagramas de comunicación correspondientes
a algunas sentencias escritas en el lenguaje.

<P>

<H2><A NAME="SECTION00051000000000000000">
Interpretar código fuente</A>
</H2>
Para la interpretación de código fuente el sistema crea los objetos 
encargados del análisis léxico y sintáctico del mismo. El objeto principal
del sistema se encarga de crear e inicializar el analizador sintáctico (parser) a
partir del código fuente, a su vez este crea el analizador léxico (scanner)
que crea una estructura correspondiente al código fuente que será interpretado.

<P>
El sistema envía un mensaje para que el parser analice el código fuente.
El analizador sintáctico define una serie de reglas gramaticales e irá comprobando que 
el código fuente cumple estas reglas a la vez que las utiliza para crear un árbol de derivación 
denominado árbol sintáctico. Para ello hace uso de una serie de tokens que irá solicitando 
al analizador léxico. Este último obtendrá los tokens a partir del código fuente, mediante 
una serie de reglas léxicas formadas a partir de lenguajes regulares. Por cada regla 
gramatical que se cumpla en el parser, este habrá obtenido del scanner tantos tokens como 
componentes léxicos sean necesarios para cumplir la regla. Además por cada regla gramatical se
construirá un nodo ejecutable formado a partir del valor asociado a una serie de tokens, o 
a partir de otros nodos ejecutables construidos por reglas de mayor prioridad y creados en 
anteriores interacciones. Esto formará un árbol sintáctico formado por nodos ejecutables que 
contienen la semántica que encierran las construcciones del código fuente.

<P>
A partir del nodo raíz del árbol de nodos ejecutables comienza un recorrido en profundidad del
árbol que conllevará la ejecución del código fuente, produciéndose así el resultado semántico 
esperado.

<P>
En el caso de que no se de una regla gramatical que se corresponda con el código analizado se 
producirá un error sintáctico. Por otro lado, en el caso de que alguna cadena contenida
en el código fuente no se corresponda con los lenguajes regulares que define el scanner
se producirá un error léxico.

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="549" HEIGHT="691" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/interaction.png"
 ALT="Image interaction"> 
<BR>
</DIV>

<P>

<H2><A NAME="SECTION00052000000000000000">
Sentencias</A>
</H2>

<H3><A NAME="SECTION00052100000000000000">
Sentencia de control condicional </A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="380" HEIGHT="88" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/if.png"
 ALT="Image if"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00052200000000000000">
Operaciones aritméticas </A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="344" HEIGHT="229" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/arith.png"
 ALT="Image arith"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00052300000000000000">
Asignaciones </A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="412" HEIGHT="232" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/asig.png"
 ALT="Image asig"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="412" HEIGHT="206" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/asig2.png"
 ALT="Image asig2"> 
<BR>
</DIV>

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="407" HEIGHT="229" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/asig3.png"
 ALT="Image asig3"> 
<BR>
</DIV>

<P>

<H1><A NAME="SECTION00060000000000000000">
Diseño de la interfaz de usuario</A>
</H1>
En esta sección se describe el diseño de la interfaz del usuario a partir del análisis llevado a cabo.

<P>
El intérprete presenta una interfaz de consola de comandos, por lo que el diseño se corresponde con una descripción de los usos 
del comando y el listado de las opciones que acepta.

<P>
El cliente runTree y la web en general presenta una interfaz web. El diseño se corresponde con una descripción 
gráfica de las páginas que la conforman y de las secciones que las componen.
<H2><A NAME="SECTION00061000000000000000">
Intérprete</A>
</H2>
El intérprete es un programa de consola de comando por lo que la interfaz con el usuario no es gráfica.

<P>
El comando ``omi'' permite ejecutar el intérprete. Se puede usar de las siguientes forma:

<UL>
<LI>omi [opciones] <SPAN CLASS="MATH"><IMG
 WIDTH="107" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img37.png"
 ALT="$ &lt;fichero&gt;$"></SPAN> [argumentos...]
</LI>
<LI>omi -c <SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img38.png"
 ALT="$ &lt;codigo&gt;$"></SPAN> [argumentos...]
</LI>
<LI>omi -i [argumentos...]
</LI>
<LI>omi -sj <!-- MATH
 $<fichero.json>$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="150" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img39.png"
 ALT="$ &lt;fichero.json&gt;$"></SPAN>
</LI>
</UL>

<P>
El listado de opciones que acepta el comando a continuación:

<P>
<DL>
<DT><STRONG>-i	</STRONG></DT>
<DD>:	Ejecuta el intérprete de forma interactiva.
 
</DD>
<DT><STRONG>-c <SPAN CLASS="MATH"><IMG
 WIDTH="96" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img38.png"
 ALT="$ &lt;codigo&gt;$"></SPAN></STRONG></DT>
<DD>:	Interpreta el código dado.
 
</DD>
<DT><STRONG>-l <!-- MATH
 $<fichero.so>$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="130" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img40.png"
 ALT="$ &lt;fichero.so&gt;$"></SPAN></STRONG></DT>
<DD>: Carga el módulo <!-- MATH
 $<fichero.so>$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="130" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img40.png"
 ALT="$ &lt;fichero.so&gt;$"></SPAN>.
</DD>
<DT><STRONG>-h</STRONG></DT>
<DD>: Muestra la ayuda.
 
</DD>
<DT><STRONG>-V</STRONG></DT>
<DD>: Muestra la versión.
</DD>
<DT><STRONG>-j <!-- MATH
 $<fichero.json>$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="150" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img39.png"
 ALT="$ &lt;fichero.json&gt;$"></SPAN></STRONG></DT>
<DD>: Imprime una descripción del procesos en formato json en el fichero <!-- MATH
 $<fichero.json>$
 -->
<SPAN CLASS="MATH"><IMG
 WIDTH="150" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img39.png"
 ALT="$ &lt;fichero.json&gt;$"></SPAN>.
  
</DD>
<DT><STRONG>-x <SPAN CLASS="MATH"><IMG
 WIDTH="90" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img41.png"
 ALT="$ &lt;pasos&gt;$"></SPAN></STRONG></DT>
<DD>: Obtiene <SPAN CLASS="MATH"><IMG
 WIDTH="90" HEIGHT="35" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/design/img41.png"
 ALT="$ &lt;pasos&gt;$"></SPAN> pasos del proceso de interpretación en cada petición. 
 
</DD>
<DT><STRONG>-s</STRONG></DT>
<DD>:	Ejecuta como servidor en el puerto 8888.
</DD>
</DL>

<P>

<H2><A NAME="SECTION00062000000000000000">
runTree</A>
</H2>

<P>
runTree es un cliente web del intérprete OMI. Muestra información sobre el proceso de interpretación y permite navegar por este. 

<P>
El sistema lo compone una única página web con un diseño de cuadrícula.

<P>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="384" HEIGHT="179" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/runtree.png"
 ALT="Image runtree"> 
<BR>
</DIV>

<P>
La primera parte de la retícula, superior izquierda, muestra el árbol sintáctico correspondiente al código enviado. En este árbol se marcarán los nodos a medida 
que se van ejecutando y resolviendo semánticamente. Además mostrará información directa de cada nodo tal como el nombre, el valor o el tipo.

<P>
En la segunda parte, superior derecha, muestra las tablas de símbolos de variables, funciones y clases. Esta sección permite navegar por las tablas de símbolos 
y los elementos que serán referenciados desde las mismas.

<P>
En la tercera parte, inferior izquierda, se muestra el código fuente y la interfaz de entrada/salida del programa.

<P>
En la última sección, inferior derecha, se muestra una consola informativa, en la que aparece una descripción del nodo actualmente en ejecución o 
los nodos seleccionados por el usuario. También se colocan en esta sección las opciones de control para avanzar un paso, una sentencia, la reproducción automática, abrir un fichero local o guardar el 
código en un fichero local. 

<P>

<H2><A NAME="SECTION00063000000000000000">
Sitio web</A>
</H2>
Según el análisis de la interfaz de usuario llevado a cabo se procede a detallar gráficamente cada página descrita.

<P>

<H3><A NAME="SECTION00063100000000000000">
Home</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="350" HEIGHT="402" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/home.png"
 ALT="Image home"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00063200000000000000">
Sobre OMI</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="382" HEIGHT="296" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/about.png"
 ALT="Image about"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00063300000000000000">
Contacto</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="382" HEIGHT="199" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/contact.png"
 ALT="Image contact"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00063400000000000000">
Índice de la documentación</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="350" HEIGHT="253" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/doc-index.png"
 ALT="Image doc-index"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00063500000000000000">
Documento</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="350" HEIGHT="176" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/doc-content-x.png"
 ALT="Image doc-content-x"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00063600000000000000">
Navegador de gramática</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="378" HEIGHT="230" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/gramatic-x.png"
 ALT="Image gramatic-x"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00063700000000000000">
Navegador de clases</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="382" HEIGHT="283" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/class.png"
 ALT="Image class"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00063800000000000000">
Navegador de ficheros</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="382" HEIGHT="291" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/files.png"
 ALT="Image files"> 
<BR>
</DIV>

<P>

<H3><A NAME="SECTION00063900000000000000">
Descargas</A>
</H3>
<DIV ALIGN="CENTER">
<IMG
  WIDTH="350" HEIGHT="241" ALIGN="BOTTOM" BORDER="0"
 SRC="<?=URL;?>src/images/design/download.png"
 ALT="Image download"> 
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
