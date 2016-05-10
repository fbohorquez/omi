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
   <div class="title"><h1>Requisitos del sistema</h1></div>
   <div class="list">

<UL CLASS="TofC">
<LI><A NAME="tex2html221"
  HREF="#SECTION00030000000000000000">Situación actual</A>
<LI><A NAME="tex2html222"
  HREF="#SECTION00040000000000000000">Necesidades</A>
<LI><A NAME="tex2html223"
  HREF="#SECTION00050000000000000000">Objetivos</A>
<LI><A NAME="tex2html224"
  HREF="#SECTION00060000000000000000">Requisitos funcionales</A>
<UL>
<LI><A NAME="tex2html225"
  HREF="#SECTION00061000000000000000">Intérprete</A>
<LI><A NAME="tex2html226"
  HREF="#SECTION00062000000000000000">Ejecución</A>
<LI><A NAME="tex2html227"
  HREF="#SECTION00063000000000000000">Tipos de datos</A>
<LI><A NAME="tex2html228"
  HREF="#SECTION00064000000000000000">Sentencias</A>
<LI><A NAME="tex2html229"
  HREF="#SECTION00065000000000000000">Definiciones</A>
<LI><A NAME="tex2html230"
  HREF="#SECTION00066000000000000000">Asignaciones</A>
<LI><A NAME="tex2html231"
  HREF="#SECTION00067000000000000000">Operadores aritméticos</A>
<LI><A NAME="tex2html232"
  HREF="#SECTION00068000000000000000">Operadores lógicos</A>
<LI><A NAME="tex2html233"
  HREF="#SECTION00069000000000000000">Operadores sobre cadenas</A>
<LI><A NAME="tex2html234"
  HREF="#SECTION000610000000000000000">Operadores sobre array</A>
<LI><A NAME="tex2html235"
  HREF="#SECTION000611000000000000000">Operadores sobre expresiones regulares</A>
<LI><A NAME="tex2html236"
  HREF="#SECTION000612000000000000000">Operadores de conversión de tipo</A>
<LI><A NAME="tex2html237"
  HREF="#SECTION000613000000000000000">Operadores de entrada/salida</A>
<LI><A NAME="tex2html238"
  HREF="#SECTION000614000000000000000">Leer de la entrada estándar</A>
<LI><A NAME="tex2html239"
  HREF="#SECTION000615000000000000000">Operadores informativos</A>
<LI><A NAME="tex2html240"
  HREF="#SECTION000616000000000000000">Procesos</A>
<LI><A NAME="tex2html241"
  HREF="#SECTION000617000000000000000">Ficheros</A>
<LI><A NAME="tex2html242"
  HREF="#SECTION000618000000000000000">Fechas y tiempo</A>
<LI><A NAME="tex2html243"
  HREF="#SECTION000619000000000000000">Errores</A>
<LI><A NAME="tex2html244"
  HREF="#SECTION000620000000000000000">Extensiones</A>
<LI><A NAME="tex2html245"
  HREF="#SECTION000621000000000000000">Biblioteca de desarrollo OMI</A>
<LI><A NAME="tex2html246"
  HREF="#SECTION000622000000000000000">Web del proyecto OMI</A>
<LI><A NAME="tex2html247"
  HREF="#SECTION000623000000000000000">RunTree</A>
</UL>
<BR>
<LI><A NAME="tex2html248"
  HREF="#SECTION00070000000000000000">Requisitos no funcionales</A>
<UL>
<LI><A NAME="tex2html249"
  HREF="#SECTION00071000000000000000">Rendimiento</A>
<LI><A NAME="tex2html250"
  HREF="#SECTION00072000000000000000">Usabilidad</A>
<LI><A NAME="tex2html251"
  HREF="#SECTION00073000000000000000">Accesibilidad</A>
<LI><A NAME="tex2html252"
  HREF="#SECTION00074000000000000000">Estabilidad</A>
<LI><A NAME="tex2html253"
  HREF="#SECTION00075000000000000000">Mantenibilidad</A>
<LI><A NAME="tex2html254"
  HREF="#SECTION00076000000000000000">Concurrencia</A>
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
            <div class="row"><p>
En esta sección se lleva a cabo un análisis de la situación actual en el estudio de la teoría de autómatas y los lenguajes formales. 
Se describirán las necesidades presentes en este campo, y que serán objetivo de las soluciones planteadas. A partir de estos objetivos se llevará 
acabo una descripción de los requisitos que debe cumplir la solución tomada. 

<P>

<H1><A NAME="SECTION00030000000000000000">
Situación actual</A>
</H1>

<P>
El estudio de los lenguajes formales es anterior a la concepción de las computadoras. Las matemáticas, la lógica y otras ciencias venían haciendo 
uso de los conceptos de los lenguajes formales para la solución de problemas. 

<P>
Una computadora desde un punto de vista teórico es un autómata o máquina de estados, que es capaz de ejecutar una serie de instrucciones descritas
en lenguaje máquina. Por tanto fueron los avances en la rama de la teoría de autómata y los lenguajes formales, entre otros campos, los que permitieron la concepción de 
las primeras computadoras. Actualmente la mayoría de las ingenierías de la información se estudian los conceptos teóricos detrás de las computadoras 
y los lenguajes de programación.

<P>
Lo más común es que un estudiante de informática comience sus estudios en estos campos con los autómatas: los tipos que existen, cómo se definen 
y para qué se utilizan. Llegando a comprender conceptos como el de estado, alfabeto, etc. Incluso estudiando definiciones de algunos tipos de lenguajes 
formales como los lenguajes regulares.  

<P>
Posteriormente el alumno podría utilizar los conceptos aprendidos para estudiar distintos modelos de computación, los cuales son definidos formalmente y desde un punto de vista teórico.
La máquina de turing y el cálculo lambda son piezas esenciales en este punto del aprendizaje. 

<P>
Una vez que se es poseedor del conocimiento base en la teoría de autómatas y los lenguajes formales, el alumno puede aplicar estos conocimientos para estudiar las estructuras, mecanismos 
y demás conceptos detrás de los lenguajes de programación. En este punto se estudian los interpretes y compiladores, y los 
conceptos básicos que hay detrás estos. Conceptos como el léxico, sintaxis y la semántica de los lenguajes de programación, las tablas de símbolos, o las distintos tipos de gramáticas. 

<P>
Hasta aquí se habrá obtenido los conocimientos teóricos necesarios y el alumno podría comenzar a dar soluciones prácticas a problemas, aplicando así los conocimientos obtenidos. Así es
común que se comience con el desarrollo de analizadores léxicos y sintácticos sencillos y concretos, para luego aplicarles una semántica. Ejercicios como el desarrollo de 
una calculadora suelen ser habituales. Además se estudian algunas de las herramientas que asisten al proceso del desarrollo de este tipo de tecnologías.

<P>
Después del proceso descrito al alumno se le ha brindado la oportunidad de profundizar en un campo con multitud de ramas, técnicas, metodologías y conceptos, que son fruto de años de 
estudio de expertos y apasionados. Podría profundizar en el proceso de compilación o traducción, en las distintas gramáticas, en técnicas de optimización o diseñar sus propias herramientas 
de traducción o interpretación de lenguajes formales.

<P>
Por otro lado, en la industria de la tecnología de la información se hace uso de lenguajes muy completos, con gran diversidad de mecanismos y bien consolidados, que son efecto de la evolución 
y las necesidades en el sector. En la mayoría de cursos académicos se estudian estas herramientas desde un punto de vista práctico y de uso. 

<P>
La teoría de autómatas y lenguajes formales presenta la base para el estudio de los compiladores e interpretes que son parte fundamental de la industrial 
actual. A pesar de ello no existen herramientas divulgativas, colaborativas e interactivas que, a partir de los conocimientos básicos, ayude a comprender cómo se desarrollan los distintos 
mecanismos y herramientas presentes en la tecnología actual.

<P>
Los lenguajes de programación han evolucionado mucho desde que comenzaron ha alejarse del lenguaje máquina. El alumnado actual trabaja sobre los conceptos que le ayudan a entender esta evolución, 
pero no dispone de herramientas o medios para ver cómo estos conceptos son trasladados a un producto real y presente en el día a día de un programador actual. 

<P>

<H1><A NAME="SECTION00040000000000000000">
Necesidades</A>
</H1>
Dada la situación actual se precisa de una herramienta que ayude a comprender cómo se implementa y construye un intérprete para un lenguaje de programación. Es condición necesaria que 
este proceso quede correctamente documentado. La herramienta elaborada deberá ser accesible por cualquier interesado en el tema, que desee profundizar en la práctica del desarrollo
de interpretes y lenguajes de programación. 

<P>
Se partirá de los conceptos básicos de la teoría de autómatas y los lenguajes formales, así como de la teoría de compiladores e intérpretes. Se asume pues que el usuario dispone
de este conocimiento.

<P>

<H1><A NAME="SECTION00050000000000000000">
Objetivos</A>
</H1>
Se llegará a construir un lenguaje de programación completo con características presente en la tecnología actual. Este proceso quedará correctamente documentado y se pondrá a disposición pública.
Las características que serán contempladas son:

<P>

<UL>
<LI>Distintos tipos de datos simples y compuestos.
</LI>
<LI>Expresiones lógicas y aritméticas.
</LI>
<LI>Expresiones y funciones sobre cadenas.
</LI>
<LI>Expresiones y funciones sobre vectores de datos.
</LI>
<LI>Expresiones y funciones sobre expresiones regulares.
</LI>
<LI>Operadores de conversión de tipos.
</LI>
<LI>Mecanismos de entrada/salida.
</LI>
<LI>Creación de procesos.
</LI>
<LI>Manipulación de ficheros.
</LI>
<LI>Funciones de fecha y tiempo.
</LI>
<LI>Definición y uso de variables de tipado dinámico.
</LI>
<LI>Ámbito de variables.
</LI>
<LI>Sentencias de control de flujo condicionales e iterativas.
</LI>
<LI>Definición y uso de funciones y procedimientos.
</LI>
<LI>Mecanismos y técnicas de la programación funcional.
</LI>
<LI>Definición y uso de clases de objetos.
</LI>
<LI>Mecanismos y técnicas de la programación orientada a objeto.
</LI>
<LI>Integración de módulos que extienden el lenguaje.
</LI>
</UL>

<P>
El interprete desarrollado podrá ser usado de una forma interactiva, permitiendo así la ejecución de
instrucciones bajo demanda. Además deberá tener la capacidad de dar información
estructurada de todo el proceso de interpretación. Otros sistemas podrán utilizar
esta información para ilustrar este proceso de una forma flexible. El intérprete también 
se deberá poder ejecutar en modo servidor, recibiendo así cualquier cadena que hace de código fuente por un puerto TCP e interpretándola.  

<P>
Toda la documentación generada a partir del proceso de desarrollo deberá ser estructurada y cumplimentada para 
formar una parte de una aplicación web que la haga accesible. La aplicación web además permitirá el uso online del intérprete, y mostrará información relativa al proceso de interpretación.

<P>
El proyecto presentará una licencia de uso libre para que pueda ser usado abiertamente por la comunidad,  a la vez que se nutrirá de las contribuciones de la misma. 

<H1><A NAME="SECTION00060000000000000000">
Requisitos funcionales</A>
</H1>

<H2><A NAME="SECTION00061000000000000000">
Intérprete</A>
</H2>

<P>

<H3><A NAME="SECTION00061100000000000000">
Léxico</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>115
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Léxico.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe fijar el léxico del lenguaje conformado por una conjunto de palabras y expresiones bien definidas y acotadas.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00061200000000000000">
Gramática</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0001
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Gramática.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe definir una gramática que representará el lenguaje. La gramática debe ser libre de contexto, clara
		y uniforme en toda su extensión. Además debe estar libre de ambigüedades.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00061300000000000000">
Semántica</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0002
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Interpretación semántica.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un contenido fuente el sistema debe analizarlo en función al léxico (análisis léxico) y la gramática (análisis sintáctico)
		del lenguaje y producir el resultado semántico asociado.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00061400000000000000">
Comentarios</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0003
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Comentarios.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de contemplar un mecanismo para añadir comentarios al contenido fuente que serán ignorados
		durante la tarea de interpretación. 

<P>
Los comentarios comprenderán desde un carácter ``#'', o bien ``//'', hasta fin de línea.

<P>
Por otro lado se ha de contemplar los comentarios de múltiples líneas, que deberán estar contenidos entre ``/*'' y ``*/''.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00061500000000000000">
Contenido fuente</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0004
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Fuente desde línea de comandos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de obtener contenido fuente desde una línea de comandos.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0005
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Fuente desde entrada estándar.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de obtener contenido fuente desde la entrada estándar del sistema.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0006
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Fuente desde fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de obtener contenido fuente desde un fichero.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0007
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Fuente desde puerto TCP.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe poder ser ejecutado en modo servidor, recibiendo una cadena de caracteres por un puerto TCP, e interpretándola. Esto ocasionará que el 
servidor devuelva por otro puerto una estructura de datos que representa el proceso de interpretación. 
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00061600000000000000">
Salida</A>
</H3>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0008
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Salida por la salida estándar.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe poder utilizar la salida estándar del sistema
para imprimir el resultado de la interpretación según el código fuente. Para ello se deberá presentar
sentencias que permitan escribir en esta.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0009
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Salida estructurada.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe de tener la capacidad de producir una serie 
de datos estructurados que representen el proceso de interpretación llevado a cabo para un determinado código fuente. Estos datos podrán ser almacenados en un fichero o devueltos por 
un puerto TCP.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00061700000000000000">
Entorno</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0010
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Entorno de ejecución.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Intérprete.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe definir un entorno de ejecución en
		el que se controlen parámetros de entrada, variables de entornos del sistema operativo e información sobre
		el proceso como número de línea actual y los errores producidos.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00061800000000000000">
Parámetros</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0011
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Parámetros al programa.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Entrada.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo para que el contenido fuente pueda recibir parámetros de entrada desde la
		invocación a su interpretación. Estos parámetros deberán ser copiados a símbolos variables accesibles desde el contenido fuente. 
		Adicionalmente se tratará otro parámetro que se corresponderá con el número de parámetros dados.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION00062000000000000000">
Ejecución</A>
</H2>

<H3><A NAME="SECTION00062100000000000000">
Sentencias</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0012
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Ejecución.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Son las unidades interpretables más pequeña en las que se divide un contenido fuente. Las sentencias están sujetas a
		unas reglas sintácticas y encierran un significado semántico. El intérprete debe definir la gramática de cada sentencia y dotarlas de significado
		semántico. Toda sentencia debe finalizar con el carácter ``;'', excluyendo las sentencias formadas por bloques de sentencias. Aunque carezca
		de sentido práctico, para evitar posibles errores de codificación y mantener coherencia en la sintaxis y la definición del lenguaje, se debe
		contemplar la sentencia vacía que sólo conste del carácter ``;''.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0013
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Bloques de sentencias.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Ejecución.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Son un conjunto de sentencias que deberán ser interpretadas y ejecutadas secuencialmente. La disposición de
		sentencias en el bloque determinan el flujo de ejecución que se llevará a cabo cuando se intérprete el bloque. El contenido fuente
		en si mismo es un bloque de sentencias. Todo bloque de sentencias de más de una sentencia (con excepción del contenido fuente en si mismo)
		debe ir delimitado mediante llaves. Aunque no sea de uso común, para mantener coherencia en la sintaxis y la definición del lenguaje, se debe
		contemplar el bloque de sentencias vacío.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00062200000000000000">
Expresiones</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0014
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Expresiones.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Ejecución.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de evaluar expresiones. Estas son secuencias de datos, operadores, operandos,
		elementos de puntuación y/o palabras clave, que especifican una unidad computacional.
		Generalmente encierran un valor que se asocia a la expresión después de ser evaluada. Una sentencia puede estar formada por una o
		varias expresiones que deberán ser evaluadas o interpretadas para dotarla de significado. Una sentencia puede constar únicamente
		de una expresión en ese caso la sentencia es considerada la evaluación de dicha expresión.

<P>
La expresión más simple equivale a un único dato, en este caso el valor de la expresión será el del dato.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0015
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Expresiones de tipo definido.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Ejecución.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Son expresiones cuyo valor es de un tipo definido y fijo. El sistema debe interpretar estas expresiones para determinar el valor
		asociado a la mismas en un momento dado.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Expresiones de tipo no definido.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Ejecución.
		
</DD>
<DT><STRONG>Número:</STRONG></DT>
<DD>0016
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Son expresiones cuyo valor no tiene un tipo definido ni fijo, sino que es durante la interpretación cuando se determina el tipo.
		El sistema debe interpretar estas expresiones para determinar, además del valor asociado a la mismas, el tipo de dato que guardan en un momento
		dado.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00062300000000000000">
Datos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Datos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Ejecución.
		
</DD>
<DT><STRONG>Número:</STRONG></DT>
<DD>0017
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete deberá operar sobre datos. El contenido fuente 
      definirá cómo se han de construir y/o acceder a los datos y las operaciones que se realizarán sobre ellos durante la ejecución. 

<P>
Un dato será tratado en función de su tipo. El tipo de dato lo dota de una semántica, un significado.
      Así, todo dato deberá ser considerado un objeto, por lo que tendrán unas propiedades y funcionalidad ligadas al tipo como el que es tratado.

<P>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00062400000000000000">
Operadores</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0018
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Operadores.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar una serie de operadores que permitan manipular los datos. Los operadores
		son en si mismo expresiones, por los que estos tendrán un valor asociado tras ejecutarse. Los operadores constarán
		de una serie operandos que intervendrán en la operación y que serán a su vez otras expresiones.

<P>
Los operadores se clasificarán en función del tipo de valor que tendrán tras la ejecución, los tipos de
		los operandos y/o la naturaleza del operador en si.  

<P>
Un operador puede presentarse en forma de función, los operandos serán los parámetros de esta. La ejecución
      de la función conllevará la realización de la operación asociada al operador.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION00063000000000000000">
Tipos de datos</A>
</H2>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0019
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tipos de datos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Tipos de datos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe ser capaz de interpretar y operar sobre diferentes tipos de datos. Las expresiones
		pueden tener un tipo de dato asociado que puede o no ser definido y fijo. Los tipos de datos pueden ser simples o compuestos.

<P>
Un dato debe tratarse como diferente tipo en función del contexto en el que se utilice. Así un dato de un tipo concreto puede ser tratado como
		otro tipo de dato si fuese necesario. Un dato por si mismo siempre será considerado del tipo de dato con el que se creó, sin embargo
		cuando interviene en una operación es posible que se precise una conversión o equivalencia de tipos. Para ello debe tomar su valor como si de otro
		tipo se tratase. Si en la operación no es posible convertir el tipo en el tipo requerido se debe producir un error de tipos.

<P>
Se debe establecer un mecanismo de conversión de tipos. La relación de conversión de tipo debe ser transitiva, así
		si un dato de tipo lógico puede verse como un dato de tipo aritmético y un dato aritmético como un cadena de caracteres, entonces el
		dato de tipo lógico también puede verse como una cadena.
   
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00063100000000000000">
Nulo</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0020
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tipo de dato nulo.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Tipo de dato.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar el tipo de dato nulo. Este tipo de dato tendrá un único valor 
      posible. El valor nulo deberá representar un elemento no definido. Una expresión puede tomar el
      valor nulo cuando sea evaluada si se hace uso de elementos no definidos.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00063200000000000000">
Lógico</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0021
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tipo de dato lógico.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Tipo de dato.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe ser capaz de interpretar y operar sobre datos de tipo lógicos. Este tipo
		de dato sólo contempla dos posibles valores: falso y verdadero. Este será el tipo de dato más simple. Un dato lógico
		puede ser tratado como un tipo de dato aritmético tomándose falso como el valor cero, y verdadero como el valor uno.
	
</DD>
</DL>
</DIV>
<H3><A NAME="SECTION00063300000000000000">
Aritmético</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0022
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tipo de dato aritmético.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Tipo de dato.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe ser capaz de interpretar y operar sobre datos de tipo aritméticos. Este tipo
		de dato contempla valores numéricos racionales que puedan ser represetnados mediante notación en coma flotante. Todo dato aritmético además tiene asociado un valor lógico cuando se utiliza como este
		tipo de dato, tal que cualquier número distinto de cero tiene valor verdadero y el cero tiene el valor falso. Además cuando un dato aritmético
		es tratado como una cadena de caracteres se tomará la cadena que representa al número. El intérprete debe tener la capacidad de configurarse con una representación interna distinta para los datos aritméticos.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00063400000000000000">
Cadena de caracteres</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0023
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tipo de dato cadenas de caracteres
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Tipo de dato.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe ser capaz de interpretar y operar sobre datos de tipo cadena de caracteres. Este tipo
		de dato contempla cualquier sucesión de caracteres alfanuméricos, secuencias de escape, u otros signos o símbolos. Esta sucesión pude
		ser vacía. Una cadena de caracteres vendrá delimitada mediante comillas dobles o simples. Toda cadena de caracteres además tiene asociado
		un valor aritmético cuando se utiliza como este tipo de dato, tal que, si la cadena representa un número racional el valor será el del
		propio número, por otro lado, si la cadena
		no representa un número racional el valor aritmético de la misma será el número de caracteres que la conforman.  No se ha de considerar el tipo de dato carácter simple, pudiéndose tratar este como una cadena de un solo elemento.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00063500000000000000">
Expresiones regulares</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0024
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tipo de dato expresión regular.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Tipo de dato.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe ser capaz de interpretar y operar sobre datos de tipo expresión regular. Una expresión regular
		consiste en una cadena de caracteres que representan un patrón. Las expresiones regulares tendrán una sintaxis PERL. Una expresión regular
		se delimita mediante caracteres acento grave (` ). El tipo de dato expresión regular no debe ser tratado como otro tipo de dato.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00063600000000000000">
Arrays</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0025
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tipo de dato array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Tipo de dato.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe ser capaz de interpretar y operar sobre datos de tipo array. Este tipo
		de dato contempla cualquier sucesión de elementos. Estos elementos pueden ser pares de expresiones clave/valor donde la clave servirá
		para referenciar el valor dentro de la sucesión. También pueden ser simples expresiones, por lo que se tomará automáticamente una clave
		numérica y secuencial según el orden del array y como valor el de la expresión. El significado semántico de las claves en un array puede
		ser numérico (array numérico) o cadenas de caracteres (array asociativo).  
		Una definición de array se delimita mediante llaves y sus elementos se denotarán mediante un listado de expresiones o pares de estas. Un dato de tipo array solo puede ser tratado como un tipo de dato booleano,
		siendo falso si se encuentra vacío y verdadero en caso contrario.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION00064000000000000000">
Sentencias</A>
</H2>

<H3><A NAME="SECTION00064100000000000000">
Inclusión de ficheros</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0026
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Inclusión de ficheros.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar un mecanismo para incluir, en un punto de la ejecución, contenido fuente localizado en recurso
		externo. El recurso consistirá en un fichero con sentencias interpretables.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00064200000000000000">
Saltar a etiqueta</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0027
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Saltar a etiqueta.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar un mecanismo para llevar el flujo de ejecución a la sentencia  
		referenciada por una etiqueta.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00064300000000000000">
Sentencia if</A>
</H3> 
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0028
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia if.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Deben de existir una serie de sentencias condicionales que alteren el flujo de ejecución. Las  
		sentencias if deberán estar construidas por bloques de sentencias y una serie de expresiones denominadas ``condiciones''.
		La interpretación de una sentencia de este tipo debe consistir en la evaluación lógica de las ``condiciones'' para determinar el
		bloque de sentencias que se ejecutará. Las formas de la sentencia if que el intérprete debe aceptar son las siguientes:
		
<UL>
<LI>if (cond) stmts
</LI>
<LI>if (cond) stmts else stmts
</LI>
<LI>if (cond) stmts elif (cond) stmts ... else stmts
		
</LI>
</UL>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00064400000000000000">
Sentencia switch</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0029
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia switch.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de interpretar sentencias del tipo switch case. Estas
		constan de una lista de bloques de sentencias precedidas de una expresión denominada ``caso''. Dada una expresión base
		esta debe ser comparada mediante la operación de igualdad con cada uno de los casos, ejecutando el bloque correspondiente al ``caso''
		cuya comparación sea positiva y todos los bloques siguientes. Se deberá poder especificar un bloque denominado ``default''
		que no dispondrá de expresión ``caso'' y será ejecutado sin aplicar condición alguna.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00064500000000000000">
Sentencia while</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0030
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia while.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de interpretar sentencias del tipo while. Esta es una sentencia de control
		iterativa que consta de una expresión denominada ``condición'' y un bloque de sentencias. El bloque de sentencias debe ser ejecutado
	    mientras que ``condición'' permanezca verdadera.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00064600000000000000">
Sentencia do...while</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0031
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia do...while.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de interpretar sentencias del tipo do while. Esta es una sentencia de control
		iterativa que consta de una expresión denominada ``condición'' y un bloque de sentencias. El bloque de sentencias debe ser ejecutado
	    mientras que ``condición'' permanezca verdadera, llevándose a cabo la ejecución al menos una vez.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00064700000000000000">
Sentencia for</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0032
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia for.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de interpretar sentencias del tipo for. Esta es una sentencia de control
		iterativa que consta de tres expresiones denominadas ``inicialización'', ``condición'' y ``paso'', además de un bloque de sentencias.
		Primero se ha de evaluar la expresión ``inicialización'', luego el bloque de sentencias se ejecutará mientras ``condición'' se
		valore como verdadera. La expresión ``paso'' se deberá ejecutar al finalizar cada iteración.  
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00064800000000000000">
Sentencia foreach</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0033
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia foreach.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencia de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se han de de interpretar sentencias del tipo forearch. Esta es una sentencia de control
		iterativa que consta un bloque de sentencias, de una expresión denominada ``conjunto'' y  un identificador denominado ``valor''.
		Se debe poder, aunque de forma opcional, especificar otro identificador que se denominará ``clave''.
		El bloque de sentencias será ejecutado de forma iterativa en función el tipo de dato y el valor de ``conjunto''.  El ``conjunto''
		será evaluado para determinar el número de iteraciones y el valor que se le asignará como variables a los identificadores en
		cada iteración. Dependiendo del tipo de la expresión ``conjunto'' la sentencia foreach deberá actuar como sigue:

<P>
<DL>
<DT><STRONG>Tipo lógico:</STRONG></DT>
<DD>El bloque de sentencias se ejecutará mientras ``conjunto'' sea verdadero. El identificador ``valor'' tomará
			el valor verdadero. En el caso en el que se especifique un identificador ``clave'' a este no se le asignará ningún valor.
			
</DD>
<DT><STRONG>Tipo aritmético:</STRONG></DT>
<DD>Si ``conjunto'' representa un número mayor que cero el bloque de sentencias se ejecutará
			tantas veces como el valor numérico que representa. En cada iteración ``valor'' se le asignará el número de la iteración
			comenzando por cero. Si se presenta un identificador ``clave'' a este no se le asignará ningún valor.
			Si el valor de ``conjunto'' es menor o igual a cero el bloque no deberá ejecutarse.
			
</DD>
<DT><STRONG>Tipo cadena de caracteres:</STRONG></DT>
<DD>Si ``conjunto'' es una cadena de caracteres que representa un número racional la
			ejecución deberá ser como si de un tipo aritmético se tratase. Si el ``conjunto'' es una cadena que no representa un número racional
			el bloque de sentencias se ejecutará por cada carácter en la cadena. En este último caso a ``valor'' se le asignará el carácter
			contemplado en cada iteración. Si se dio un identificador ``clave'' este no será asignado.
			
</DD>
<DT><STRONG>Tipo array:</STRONG></DT>
<DD>Si ``conjunto'' es un array, u otro tipo de dato derivado de este como un objeto, el bloque de sentencias
			se ejecuta por cada elemento en el mismo. Al identificador ``valor'' se le asignará el valor del elemento en el array correspondiente
			a la iteración. En el caso de que se facilite un identificador ``clave'' este deberá tomar la clave del elemento en el array.
			
</DD>
<DT><STRONG>Otros tipos:</STRONG></DT>
<DD>No se llevará a cabo ninguna operación.
		
</DD>
</DL>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00064900000000000000">
Sentencia de iteración ágil</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0034
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia de iteración ágil.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencia de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar una sentencia de control que permita
		iterar un bloque de sentencias en función una expresión ``conjunto'' de forma ágil y sencilla.
		Para ello esta sentencia deberá operar igual que la sentencia foreach pero sin ser necesario, aunque posible,
		dar un identificador ``valor'' sobre el que se realizará la asignación. En lugar de ello la asignación que se produce
		en cada iteración se deberá realizar sobre un símbolo con identificador fijo y contenido variable denominado iterador.
		El iterador debe ser accesible desde el bloque de sentencias. Además se debe contemplar el acceso al iterador de 
      varias sentencias de ciclo ágil cuando estas se presentan de forma anidada. 
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000641000000000000000">
Sentencia with</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0035
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia with.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencia de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se deberá facilitar un mecanismo que permita establecer una estructura compuesta como contexto. Así todo acceso que se
      realice, y cuya definición no exista, se deberá hacer sobre los elementos que de la estructura compuesta utilizada como contexto. 
      Esta sentencia se deberá construir a partir del dato compuesto y un bloque de sentencias sobre el que se aplicará el contexto.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000641100000000000000">
Finalizar bloque de sentencias</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0036
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Finalizar bloque de sentencias.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de un mecanismo para indicar que el flujo debe salir de una sentencia de control. Se ha de contemplar
		las sentencias anidadas.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000641200000000000000">
Finalizar iteración</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0037
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Finalizar iteración.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe facilitar algún recurso que permita finalizar la iteración actual
		de una sentencia de control en ejecución y comenzar con la siguiente. Este
		mecanismo debe contemplar la posibilidad de salir de varias sentencias de control anidadas.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000641300000000000000">
Finalizar ejecución</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0038
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Finalizar ejecución.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de un mecanismo para que el sistema finalice de forma inmediata de
		interpretar el contenido fuente.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000641400000000000000">
Capturar excepción</A>
</H3>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0039
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Capturar excepción.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de un mecanismo para definir un bloque de
sentencias en el que puede suceder una excepción, a la vez que permita definir un bloque de sentencias en el que esta será tratada. La excepción podrá devolver un valor que debe ser capturado.
No se ha de contemplar bloques en los que se trate cada excepción según su tipo, en lugar de ello se
usará un único bloque de sentencias y el tipo deberá ser evaluado dentro de este.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000641500000000000000">
Lanzar excepción</A>
</H3>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0040
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Lanzar excepción.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Sentencias de control de flujo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de un mecanismo para lanzar excepciones. Cuando una excepción es lanzada esta podrá ser capturada por un bloque de sentencias destinado para ello. Si la excepción no es capturada se producirá un error. Cuando una excepción es lanzada se deberá de dar un valor que podrá ser utilizado en el bloque que la captura.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION00065000000000000000">
Definiciones</A>
</H2>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0041
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Identificadores.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe facilitar mecanismos para que el usuario defina e identifique expresiones, datos, bloques de sentencias, y
		otras construcciones y elementos del lenguaje. Se precisa una manera unívoca de nombrar estos elementos. Un identificador válido debe estar
		formado por una secuencia de caracteres alfanuméricos de al menos un carácter, donde el primer carácter a de ser una letra.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0042
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tabla de símbolos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de gestionar tablas de símbolos. Los símbolos
		hacen referencias a valores, funciones y otras expresiones del lenguajes. Para acceder a estos símbolos
		se debe utilizar un identificador. Se hace necesario el acceso y uso de los símbolos según el contexto
		de ejecución, determinado por el ámbito y el tipo símbolo, para ello deben poder coexistir diferentes
		tablas de símbolos globales. Para evitar conflictos en el uso de identificadores algunos conceptos 
      deben disponer de su propia tabla de símbolos.

<P>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00065100000000000000">
Variables</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0043
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Variables.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz gestionar una serie de símbolos
		denominados variables. Estos relacionan un identificador con un valor que puede variar durante el proceso de ejecución. El tipo
		de una variable dependerá del tipo del valor al que referencia (tipado dinámico), este podría ser de cualquiera de los tipos de
		datos soportados. La tabla de símbolos de variables debe adaptarse al contexto de ejecución.
	
</DD>
</DL>
</DIV>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0044
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Variables globales.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Aunque la tabla de símbolos de variables es dependiente del contexto de ejecución se
		ha de facilitar algún mecanismo para que un dato esté disponible independientemente del contexto en el que
		se acceda.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00065200000000000000">
Funciones</A>
</H3>

<P>

<H4><A NAME="SECTION00065210000000000000">
Definición de función</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0045
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Definición de función
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo que permita definir y nominar bloques de sentencias. Estos bloques podrán recibir unos valores
		de entrada y producir una salida. Las sentencias en el bloque podrán operar sobre los parámetros de entrada, representados por
		unos símbolos variables que tomarán distintos valores en cada ejecución. Tras interpretarse el bloque 
		de sentencias se podrá tomar un valor considerado de salida. 

<P>
La definición de una función representará en si misma un dato, por lo que podrán formar parte de operaciones 
		y otras expresiones. 
		Una función se define mediante un bloque de sentencias, una lista de identificadores que nominan a los parámetros de entrada y un 
		identificador que le da nombre a la propia función, aunque este último no debe ser necesario (funciones anónimas). 

<P>
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065220000000000000">
Llamada a función</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0046
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Llamada a función
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dada una función, se debe disponer de un mecanismo que permita la ejecución del bloque de 
		sentencias que la forma, mediante el uso de unos valores concretos como parámetros de entrada, y con la posibilidad de tomar 
		el valor de salida.

<P>
Una llamada a función se deberá componer de un identificador relativo a su definición, y una lista de expresiones
		que determinarán los valores de los parámetros. La llamada deberá ser en si misma una expresión 
		que tomará como valor la salida de la función tras la ejecución.

<P>
Los valores de los parámetros se corresponderán con los parámetros de la definición de la función de forma posicional.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065230000000000000">
Valor de retorno</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0047
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Valor de retorno
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo en forma de sentencia que, dada una función, determine
		el valor del salida que se tomará en la llamada a la misma. La sentencia return se compondrá de una 
		expresión correspondiente al valor salida. Al ser interpretada la ejecución de
		la función deberá finalizar, y tomará el valor de la expresión dada.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065240000000000000">
Valores de parámetros por defecto</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0048
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Valores de parámetros por defecto.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dada la definición de una función, debe existir un mecanismo para que los parámetros de esta puedan tener 
		valores por defecto. Estos valores serán asignado a los parámetros cuando los valores no sean dados en una llamada a función. 

<P>
Como la correspondencia entre parámetros en una llamada a función se hace de forma posicional, los valores por defecto deberán ser especificados 
		desde el final de la lista de parámetros hasta el inicio.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065250000000000000">
Parámetros por valor</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0049
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Parámetros por valor.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Cuando una función es ejecutada todos los símbolos variables que se definan y utilicen deben tratarse de forma 
		local al bloque de sentencias de la función. De esta forma los símbolos variables definidos fuera de la función no serán accesibles
		desde el cuerpo de la misma y viceversa. Cuando se realice una llamada a función los valores de los parámetros deben ser copiados
		a los símbolos variables correspondientes.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065260000000000000">
Parámetros por referencia</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0050
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Parámetros por referencia.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo que permita que los parámetros de una función referencien valores definidos 
		fuera del cuerpo de la misma. De esta forma se podrá acceder y/o modificar datos externos a la función. 

<P>
Cuando en una llamada a función se especifiquen expresiones que sean símbolos variables como algunos de sus parámetros, si estos se definieron en la
		función como parámetros por referencia, el valor del símbolo en la llamada será referenciado por el símbolo correspondiente de la función.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065270000000000000">
Función lambda</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0051
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función lambda.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe dar la posibilidad de crear funciones anónimas. Estas funciones carecerán de nombre y 
		normalmente se utilizarán en la asignación de variables, como parámetros de otras funciones o como valor de retorno. 
		Las funciones lambda deberán ser en si misma una expresión que toma como valor el dato correspondiente a la función. 
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065280000000000000">
Expresiones parametrizadas</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0052
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función lambda simple.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe de facilitar un mecanismo para crear funciones simples, que solo consten de una lista de parámetros
		y de una única expresión que será devuelta y que constituirá el cuerpo de la función. 
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065290000000000000">
Referencia a función</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0053
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Referencia a función.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo para referenciar funciones ya creadas, de forma que puedan ser asignadas a variables, 
		pasadas como parámetros o devueltas como valor de retorno. 
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION000652100000000000000">
Funciones de orden superior</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0054
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Funciones de orden superior.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe poder definir funciones de orden superior, estas pueden recibir otras funciones como parámetros o tomar como valor de 
      retorno otra función.  
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION000652110000000000000">
Funciones clausura</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0055
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Funciones clausura.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe poder definir funciones dentro del contexto de otras. La función de clausura puede tener variables que dependan 
      del entorno en el que se ha definido la función. De esta forma cuando la función es llamada podrá acceder al valor de la variable en el contexto
      en el que se definió.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION000652120000000000000">
Aplicación parcial</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0056
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Aplicación parcial.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo que permita, a partir de una función, obtener otra
      equivalente donde se ha dado valor a un subconjunto de los parámetros.
    
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION000652130000000000000">
Decoradores</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0057
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Decoradores.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo para definir decoradores. Un decorador será un tipo especial de función.
      Al igual que una función se define mediante un identificador que lo nomina, una lista de parámetros y un bloque de sentencias. 

<P>
A diferencia de las funciones ordinarias, la llamada a un decorador deberá tener como parámetro una función que será decorada, como
      resultado se deberá obtener una función que tendrá las siguientes características:

<P>

<UL>
<LI>La lista de parámetros que admite será la misma que la lista con la que se definió el decorador
</LI>
<LI>El bloque de sentencias será el del decorador pero haciendo uso de la función que ha sido decorada
      
</LI>
</UL>

<P>
Se debe facilitar un mecanismo para referenciar la función que se va a decorar dentro del decorador. Para ello
      se utilizará la función de contexto.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION000652140000000000000">
Función de contexto</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0058
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función de contexto.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo para acceder a la función de contexto. Esta será una función 
      cuyo valor dependerá del contexto en el que se ejecute:
      
<UL>
<LI>En el primer nivel de ejecución la función de contexto no estará definida. 
</LI>
<LI>En el cuerpo de una función será la propia función.  
</LI>
<LI>En el cuerpo de un decorador será la función que se decorará.
      
</LI>
</UL>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00065300000000000000">
Clases de objetos</A>
</H3>

<H4><A NAME="SECTION00065310000000000000">
Clase de objeto</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0059
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Clase de objeto.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El lenguaje debe contemplar el paradigma de la programación orientada a objetos. Una clase
      se ha de ver como una definición estática e inmutable que será utilizada para la creación de objetos.

<P>
Las clases definirán tipos de objetos que tendrán métodos y atributos comunes. Una clase se construye
		mediante un identificador que le da nombre y un bloque de sentencias que contendrá una serie de funciones (métodos)
		y símbolos variables (atributos).  

<P>
Las características de la programación orientada a objetos que se deberán contemplar son:
		<DL>
<DT><STRONG>Abstracción:</STRONG></DT>
<DD>Un objeto por si mismo representará una entidad abstracta que podrá tener cierta funcionalidad
			asociada, disponer de atributos que establezcan su estado interno o comunicarse con otros objetos. 
			
</DD>
<DT><STRONG>Encapsulamiento:</STRONG></DT>
<DD>Un objeto podrá contener todos los elementos correspondiente a su definición, estado y funcionalidad.
         
</DD>
<DT><STRONG>Principio de ocultación:</STRONG></DT>
<DD>Un objeto podrá tener atributos y/o métodos privados, de forma que sólo sean
         accesibles desde el propio objeto. 
			
</DD>
<DT><STRONG>Polimorfismo:</STRONG></DT>
<DD>Se debe permitir a objetos de distinto tipo se le pueda enviar mensajes sintácticamente iguales, de forma
			que se pueda  llamar un método de objeto sin tener que conocer su tipo.
			
</DD>
<DT><STRONG>Herencia:</STRONG></DT>
<DD>Se debe contemplar la herencia simple entre clases de forma que  una clase se pueda definir mediante otra.
		
</DD>
</DL>
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065320000000000000">
Objeto</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0060
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Objeto.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe ser capaz de interpretar y operar sobre objetos. Los objetos serán vistos
		como estructuras de datos funcionales, formado tanto por datos de diferentes tipos (atributos), como por funciones (métodos). 

<P>
Se podrá crear objetos a partir de una clase ya definida. Las clases de objetos pueden definir un método constructor que será utilizado cuando se cree un objeto a partir de la misma. 

<P>
Dentro del bloque de sentencias que conforma un método es posible hacer referencia a los demás valores del objeto mediante 
      la expresión especial ``this''.

<P>
Las clases de objetos podrán definir un método constructor que será llamado cuando el objeto sea instanciado. 

<P>
Un objeto podrá disponer de un método que será llamado cuando se precise su conversión a un tipo de dato cadena de caracteres. También podrán disponer de métodos que serán llamados cuando
se acceda a un atributo o método no existente.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065330000000000000">
Elementos privados</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0061
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Elementos privados.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Clases de Objetos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo para definir atributos y métodos de una clase de objetos como privados. 
      Estos elementos solo serán accesibles desde métodos del propio objeto. Se deberá contemplar el acceso a estos elementos
      sobre objetos del mismo tipo dentro de métodos de la clase.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065340000000000000">
Elementos estáticos</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0062
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Elementos estáticos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Clases de Objetos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo para definir atributos y métodos de una clase de objetos pertenecientes
      a la propia clase. Estos elementos no serán trasladados a los objetos instanciados.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065350000000000000">
Herencia de clases</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0063
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Herencia de clases.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Clases de Objetos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe de disponer de un mecanismo que permita establecer una relación de herencia entre unas clases dadas. 
		Así será posible la definición de nuevas clases partiendo de otras. La clase derivará de otra extendiendo su funcionalidad y definición. 

<P>
En la definición de una clase se debe de disponer de un mecanismo que permita especificar la clase que se extenderá. La nueva clase tendrá todos 
		los atributos y métodos de la extendida y añadirá los suyos propios, pudiendo sobrescribirse los ya existentes.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065360000000000000">
Instanciación de clases</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0064
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Instanciación de clases.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Clases de Objetos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dada una clase, se debe de disponer de un mecanismo que permita crear objetos a partir de la misma.   
		Para construir un objeto a partir de la instanciación de una clase se deben llevar las funciones y variables definidas en el
		cuerpo de la clase a métodos y atributos del objeto. 

<P>
Una clase pude definir un método constructor que deberá ser llamado sobre el objeto recién creado cuando la clase es instanciada.

<P>
La instanciación se deberá realizar mediante un operador que, a partir de un identificador correspondiente a la clase y una lista de expresiones 
		correspondientes a los parámetros del método constructor, tome como valor el objeto recién creado.
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065370000000000000">
Acceso al objeto en ejecución</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0065
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Acceso al objeto en ejecución.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Clases de Objetos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe de disponer de un mecanismo que permita acceder a los atributos y métodos de un objeto desde la ejecución 
		de un método del mismo. Este mecanismo, correspondiente a una expresión, deberá tomar como valor el objeto en ejecución. 
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065380000000000000">
Acceso al objeto en ejecución como clase padre</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0066
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Acceso al objeto en ejecución como clase padre.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Clases de Objetos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe de disponer de un mecanismo que permita acceder a los atributos y métodos de la clase padre de un objeto desde 
      la ejecución de un método del mismo. Este mecanismo, correspondiente a una expresión, deberá tomar como valor el objeto en ejecución, pero tomando
      como métodos y atributos los de la clase padre de la cual deriva. 
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION00065390000000000000">
Enlace estático en tiempo de ejecución</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0067
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Enlace estático en tiempo de ejecución.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Clases de Objetos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe de disponer de un mecanismo que permita acceder a los atributos y métodos estáticos de una clase hija desde un método 
      estático de la clase padre. 
	
</DD>
</DL>
</DIV>

<P>

<H4><A NAME="SECTION000653100000000000000">
Obtener clase</A>
</H4>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0068
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener clase
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Clases de Objetos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe de disponer de un mecanismo para, a partir de un objeto, obtener la clase a la que pertenece como una cadena correspondiente al nombre.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00065400000000000000">
Listas</A>
</H3>

<P>
<DIV class="requisite">
	<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Listado.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Número:</STRONG></DT>
<DD>0069
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar un mecanismo que permita agrupar expresiones para darles un significado operacional
		común. Este deberá consistir en una serie de expresiones separadas por comas.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00065500000000000000">
Pares clave/valor</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Pares clave/valor.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Número:</STRONG></DT>
<DD>0070
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar un mecanismo que permita relacionar un par de expresiones para darles un significado estructural.
		Este deberá consistir en el par de expresiones separadas por el carácter ``:''.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00065600000000000000">
Etiqueta</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0071
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Etiqueta.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El sistema debe ser capaz de interpretar y operar sobre etiquetas. Una etiqueta es una referencia
		a una sentencia concreta dentro del contenido fuente. Las etiquetas dependen quedarán definidas dentro de un contexto determinado por
		el bloque de sentencias en el que se encuentren.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00065700000000000000">
Listas por comprensión</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0072
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Listas por comprensión.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo que sea una expresión por si mismo y que permita generar arrays desde una sentencia iterativa. 
		Este mecanismo se formará mediante una expresión seguida da una sentencia for. La expresión será ejecutada tras iteración del bucle y será 
		asignada como último elemento de un array. Al final de la ejecución la expresión tomará el valor del array generado.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00065800000000000000">
Expresiones reflexivas</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0073
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Expresiones reflexivas.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Definiciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de un mecanismo de reflexión, que permita
utilizar expresiones del lenguaje para definir otras expresiones como identificadores.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION00066000000000000000">
Asignaciones</A>
</H2>

<H3><A NAME="SECTION00066100000000000000">
Asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0074
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Asignaciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se hace necesario la gestión de los símbolos variables creados durante la ejecución, lo que implica
		la asignación de valores a las variables que serán definidas y utilizadas por el contenido fuente dado por el usuario.
		El valor que es asignado a una variable puede ser cualquier tipo de dato contemplado, incluso funciones o objetos. El valor asignado
		puede ser determinado a partir de cualquier expresión que tenga un valor asociado después de su ejecución.  La operación de asignación debe ser en si misma una expresión que toma como
		valor tras su ejecución el valor asignado.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00066200000000000000">
Asignación de referencia</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0075
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Asignación de referencia.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Asignaciones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo para que dos símbolos variables distintos referencien al mismo valor.
		Para ello se ha de facilitar un mecanismo para obtener la referencia de un símbolo variable, de forma que esta pueda ser usada en una asignación.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION00067000000000000000">
Operadores aritméticos</A>
</H2>

<P>

<H3><A NAME="SECTION00067100000000000000">
Suma</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0076
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Suma.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación aritmética ``suma''. Para realizar
		esta operación se deberá tomar el valor aritmético de cada operando. Tras realizarse la operación, el valor de la expresión
		deberá ser el resultado aritmético de la misma.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00067200000000000000">
Diferencia</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0077
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Diferencia.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación aritmética ``resta''. Para realizar
		esta operación se deberá tomar el valor aritmético de cada operando. Tras realizarse la operación, el valor de la expresión
		deberá ser el resultado aritmético de la misma.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00067300000000000000">
Producto</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0078
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Producto.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación aritmética ``producto''. Para realizar
		esta operación se deberá tomar el valor aritmético de cada operando. Tras realizarse la operación, el valor de la expresión
		deberá ser el resultado aritmético de la misma.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00067400000000000000">
División</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0079
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>División.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación aritmética ``división''. Para realizar
		esta operación se deberá tomar el valor aritmético de cada operando. El segundo operando debe ser
		distinto de 0. Si el segundo operando tiene valor aritmético 0 se deberá mostrar un error que informe del caso.
		Tras realizarse la operación, el valor de la expresión
		deberá ser el resultado aritmético de la misma.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00067500000000000000">
Potencia</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0080
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Potencia.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación aritmética ``potencia''. Para realizar
		esta operación se deberá tomar el valor aritmético de cada operando. Tras realizarse la operación, el valor de la expresión
		deberá ser el resultado aritmético de la misma.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00067600000000000000">
Módulo</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0081
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Módulo.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación aritmética ``módulo''. Para realizar
		esta operación se deberá tomar el valor aritmético de cada operando. El segundo operando debe ser
		distinto de 0. Si el segundo operando tiene valor aritmético 0 se deberá mostrar un error que informe del caso.
		Tras realizarse la operación, el valor de la expresión deberá ser el resultado aritmético de la misma.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00067700000000000000">
Tamaño</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0082
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tamaño.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de algún mecanismo que dado un dato calcule el tamaño de este. Este operador calculará el
		tamaño dependiendo del tipo de dato del operando. Tras ejecutase la expresión el valor que tome será de tipo aritmético.
		<DL>
<DT><STRONG>Lógico:</STRONG></DT>
<DD>Si es verdadero el tamaño es uno, si es falso será cero.
			
</DD>
<DT><STRONG>Aritmético:</STRONG></DT>
<DD>Tomará el número de dígitos decimales.
			
</DD>
<DT><STRONG>Cadena:</STRONG></DT>
<DD>El tamaño será el número de caracteres de la cadena.
			
</DD>
<DT><STRONG>Array:</STRONG></DT>
<DD>Para el tipo de dato array u otros derivados se el tamaño será el número de elementos contenidos en el mismo.
			
</DD>
<DT><STRONG>Otro tipo de dato:</STRONG></DT>
<DD>Se deberá dar un error de tipos.
		
</DD>
</DL>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00067800000000000000">
Incremento y asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0083
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Incremento y asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, el valor de esta se debe poder incrementar y
		reasignar. Para ello se tomará el valor aritmético de la variable, se incrementará en una unidad y se reasignará a la misma.
		El valor de la expresión será el de la variable incrementada.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00067900000000000000">
Asignación e incremento</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0084
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Asignación e incremento.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, el valor de esta se debe poder incrementar y
		reasignar. Para ello se tomará el valor aritmético de la variable, se incrementará en una unidad y se reasignará a la misma.
		El valor de la expresión será el de la variable antes de ser incrementada.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000671000000000000000">
Decremento y asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0085
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Decremento y asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, el valor de esta se debe poder decrementar y
		reasignar. Para ello se tomará el valor aritmético de la variable, se decrementará en una unidad y se reasignará a la misma.
		El valor de la expresión será el de la variable decrementada.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000671100000000000000">
Asignación y decremento</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0086
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Asignación y decremento.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, el valor de esta se debe poder decrementar y
		reasignar. Para ello se tomará el valor aritmético de la variable, se decrementará en una unidad y se reasignará a la misma.
		El valor de la expresión será el de la variable antes de ser decrementada.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000671200000000000000">
Suma y asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0087
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Suma y asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, al valor de esta se ha de poder sumar otra expresión
		y reasignarle el resultado. Para ello se tomará el valor aritmético de la variable, se le sumará el valor aritmético de la expresión
		y se reasignará a la variable el resultado. El valor de la expresión será el resultado de la suma aritmética.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000671300000000000000">
Diferencia y asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0088
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Diferencia y asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, al valor de esta se ha de poder restar otra expresión
		y reasignarle el resultado. Para ello se tomará el valor aritmético de la variable, se le restará el valor aritmético de la expresión
		y se reasignará a la variable el resultado. El valor de la expresión será el resultado de la resta aritmética.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000671400000000000000">
Producto y asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0089
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Producto y asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, al valor de esta se ha de poder multiplicar
		otra expresión y reasignarle el resultado. Para ello se tomará el valor aritmético de la variable, se calculará el producto  y se reasignará a la variable el resultado. El valor de la expresión será el resultado del producto aritmético.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000671500000000000000">
División y asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0090
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>División y asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, al valor de esta se ha de poder dividir por
		otra expresión y reasignarle el resultado. Para ello se tomará el valor aritmético de la variable, se realizará la división y se reasignará a la variable el resultado. La expresión no puede tener un valor aritmético de cero.
		El valor de la expresión será el resultado de la división aritmética.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000671600000000000000">
Potencia y asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0091
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Potencia y asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, al valor de esta se ha de poder elevar a
		otra expresión y reasignarle el resultado. Para ello se tomará el valor aritmético de la variable, se elevará  y se reasignará a la variable el resultado. El valor de la expresión será el resultado de la potencia.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000671700000000000000">
Módulo y asignación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0092
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Módulo y asignación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores aritméticos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dado un identificador o expresión que referencia a una dato variable, al valor de esta se ha de poder dividir por
		otra expresión y reasignarle el resto originado. Para ello se tomará el valor aritmético de la variable, se realizará la división por el
		valor aritmético de la expresión y se reasignará a la variable el resto obtenido. La expresión no puede tener un valor aritmético de cero.
		El valor de la expresión será el resultado de la operación módulo.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION00068000000000000000">
Operadores lógicos</A>
</H2>

<H3><A NAME="SECTION00068100000000000000">
AND lógico</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0093
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>AND lógico.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores lógicos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica AND. Para ello se deberá tomar
		el valor lógico de cada uno de los operandos. La evaluación de la operación lógica AND debe ser de cortocircuito, tomándose el valor del
		último elemento evaluado. Así, aunque esta expresión se corresponde con un operador lógico, el valor de la misma será el del
		último elemento evaluado.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00068200000000000000">
OR lógico</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0094
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>OR lógico.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores lógicos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica OR. Para ello se deberá tomar
		el valor lógico de cada uno de los operandos. La evaluación de la operación lógica OR debe ser de cortocircuito, tomándose el valor del
		último elemento evaluado. Así, aunque esta expresión se corresponde con un operador lógico, el valor de la misma será el del
		último elemento evaluado.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00068300000000000000">
NOT lógico</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0095
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>NOT lógico.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores lógicos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica NOT. Para ello se deberá tomar
		el valor lógico de su único operando y negarlo. La expresión deberá tomar un valor de tipo booleano tras realizarse la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00068400000000000000">
Vacío</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0096
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Vacío.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores lógicos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un operador que determine si un dato se considera vacío. Este operador tendrá un
		único operando y funcionará igual que el operador lógico NOT. El valor que tomará la expresión será lógico.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00068500000000000000">
Es nulo</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0097
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Es nulo.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores lógicos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un operador que determine si un dato o expresión contiene el valor nulo.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00068600000000000000">
Menor que</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0098
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Menor que.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de comparación.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica ``menor que''. Para ello se deberá tomar
		el valor aritmético de cada operando. La expresión deberá tomar un valor de tipo booleano tras realizarse la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00068700000000000000">
Menor o igual que</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0099
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Menor o igual que.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de comparación.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica ``menor o igual que''. Para ello se deberá tomar
		el valor aritmético de cada operando. La expresión deberá tomar un valor de tipo booleano tras realizarse la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00068800000000000000">
Mayor que</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0100
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Mayor que.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de comparación.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica ``mayor que''. Para ello se deberá tomar
		el valor aritmético de cada operando. La expresión deberá tomar un valor de tipo booleano tras realizarse la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00068900000000000000">
Mayor o igual que</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0101
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Mayor o igual que.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de comparación.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica ``mayor o igual que''. Para ello se deberá tomar
		el valor aritmético de cada operando. La expresión deberá tomar un valor de tipo booleano tras realizarse la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000681000000000000000">
Igual que</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0102
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Igual que.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de comparación.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica ``igual que''. La operación de igualdad
		debe ser independiente de los tipos de datos de los operandos, aplicándose en función del tipo de dato más completo que compartan.
		Por ejemplo si se compara un dato cadena que no representa un número racional con uno aritmético, como el tipo de dato común a ambos
		es el booleano, ambos tomarán su valor lógico para la comparación.  
		Si ambos datos son tipos compuestos, se ha de comprobar mediante la operación de igualdad todos los elementos simples que lo componen
		por pares y de forma posicional.
		Como valor de la expresión se toma el valor booleano de la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000681100000000000000">
Idéntico que</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0103
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Idéntico que.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de comparación.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica ``idéntico que''. Esta operación
		se refiere a una operación lógica de igualdad pero contemplando además que los datos tengan el mismo tipo. Como valor
		de la expresión se debe tomar el valor booleano resultado de aplicar la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000681200000000000000">
Distinto que</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0104
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Distinto que.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de comparación.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica ``distinto que''. Esta operación
		debe ser independiente de los tipos de datos de los operandos, aplicándose en función del tipo de dato más completo que compartan.
		Por ejemplo si se compara un dato cadena que no representa un número racional con uno aritmético, como el valor más completo que
		ambos pueden tomar es el booleano, tomarán su valor lógico para la comparación.  
		Si ambos datos son tipos compuestos, se ha de comprobar mediante la operación de igualdad todos los elementos simples que lo componen
		por pares y de forma posicional.
		Como valor de la expresión se toma el valor booleano de la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000681300000000000000">
No idéntico que</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0105
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>No idéntico que.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de comparación.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe contemplar la expresión correspondiente a la operación lógica ``no idéntico que''. Esta operación
		se corresponde con la operación inversa de la operación ``idéntico que''. Como valor
		de la expresión se debe tomar el valor booleano resultado de aplicar la operación.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION00069000000000000000">
Operadores sobre cadenas</A>
</H2>

<P>

<H3><A NAME="SECTION00069100000000000000">
Concatenación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0106
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Operador concatenación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La expresión que simboliza una operación de concatenación precisa de dos operandos que serán
		tratados como cadena de caracteres. El valor que tomará la expresión será la cadena resultante de concatenar ambas.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00069200000000000000">
explode</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0107
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función explode.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La función explode deberá tomar dos cadenas de caracteres como operandos denominadas ``texto'' y ``separador''.
		El valor será el array resultante de separar la cadena ``texto'' en diferentes cadenas en función la cadena ``separador''.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00069300000000000000">
implode</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0108
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función implode.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Representa la operación inversa a explode. La función implode deberá tomar como argumentos un array denominado
		``listado'' y una cadena denominada ``separador''. El valor de la expresión será una cadena resultado de concatenar cada uno
		de los elementos de ``listado'' separados por la cadena ``separador''.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00069400000000000000">
sprintf</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0109
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función de formato.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se hace necesario un mecanismo que permita generar cadenas formateadas. Este deberá consistir
		en una cadena de caracteres denominada ``formato'' y un listado de expresiones. La cadena formato contendrá una serie de
		directivas de formato. Estas directivas serán sustituidas por el valor correspondiente, según posición, de la
		lista de expresiones. Cuando se realiza cada sustitución el valor es formateado según la directiva.

<P>
Las directivas de formato tienen el siguiente forma:
		<P><!-- MATH
 \begin{displaymath}
\%[operador][precisi\acute{o}n][formato]
\end{displaymath}
 -->
</P>
<DIV ALIGN="CENTER" CLASS="mathdisplay">
<IMG
 WIDTH="276" HEIGHT="39" ALIGN="MIDDLE" BORDER="0"
 SRC="<?=URL;?>src/images/requisites/img1.png"
 ALT="$\displaystyle \%[operador][precisi\acute{o}n][formato]$">
</DIV><P></P>

<P>
Los posibles operadores serán los siguientes:
		<DL>
<DT><STRONG>+:</STRONG></DT>
<DD>Fuerza la impresión del símbolo + cuando se formatean números positivos.
			
</DD>
<DT><STRONG>&#710; :</STRONG></DT>
<DD>Convierte el caracteres a mayúsculas cuando se formatean cadenas de texto.
			
</DD>
<DT><STRONG>#:</STRONG></DT>
<DD>Añade el carácter 0x cuando se formatean números hexadecimales y el carácter 0 cuando se formatean octales.
		
</DD>
</DL>

<P>
La precisión se refiere al número de decimales que se imprimirán en el caso de formatear
		números o el número de caracteres en el caso de formatear cadenas.			

<P>
El carácter de formato indica que tipo de formato se le dará al valor:
		<DL>
<DT><STRONG>i|d:</STRONG></DT>
<DD>Número entero.
			
</DD>
<DT><STRONG>u:</STRONG></DT>
<DD>Sin signo.
			
</DD>
<DT><STRONG>f:</STRONG></DT>
<DD>Coma flotante.
			
</DD>
<DT><STRONG>%:</STRONG></DT>
<DD>Carácter %.
			
</DD>
<DT><STRONG>e:</STRONG></DT>
<DD>Notación científica.
			
</DD>
<DT><STRONG>o:</STRONG></DT>
<DD>Octal.
			
</DD>
<DT><STRONG>x:</STRONG></DT>
<DD>Hexadecimal.
			
</DD>
<DT><STRONG>s|c:</STRONG></DT>
<DD>Cadena de texto.
		
</DD>
</DL>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00069500000000000000">
Buscar subcadena</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0110
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función de búsqueda de subcadena.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Esta es una función básica en el tratamiento de cadenas. Opera sobre dos argumentos
		que serán tratados como cadenas de caracteres, uno denominado ``texto'' y otro ``subcadena''. La función
		toma como valor un dato aritmético relativo a la posición de la primera ocurrencia de ``subcadena'' dentro
		de ``texto''. Si no se encuentra ningún resultado se tomará el valor nulo. Adicionalmente se puede dar otro
		operando denominado ``offset'' que simbolice la posición dentro de ``texto'' a partir de la cual se comenzará a buscar.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00069600000000000000">
Buscar y remplazar</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0111
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función de remplazo de subcadena.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo para buscar y remplazar subcadenas dentro de otra.
		Este debe buscar las ocurrencias de una subcadena ``búsqueda'' en una
		cadena ``texto'', sustituyéndolas por una cadena de ``remplazo''. Esta función debe admitir
		el número máximo de sustituciones que se llevarán a cabo. Tras la ejecución debe tomar como valor la cadena
		resultante de sustituir en la cadena principal las ocurrencias de la subcadenas por la cadena de remplazo.

<P>
Adicionalmente la subcadena de ``búsqueda'' puede ser una expresión regular, en cuyo caso
		se buscará subcadenas que pertenezcan al conjunto de las palabras definido por la
		expresión regular.

<P>
Si se utiliza una expresión regular como patrón de búsqueda deberá ser posible
		utilizar en la cadena de remplazo parte de la subcadena
		que concuerda con la expresión regular. Para ello se ha de formar la expresión regular mediante
		subexpresiones delimitadas por ``()''. En la cadena de remplazo se debe poder hacer referencia,
		de forma posicional, a las subcadenas correspondientes a cada una de las subexpresiones.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00069700000000000000">
Remplazar subcadena</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0112
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función de remplazo de subcadena mediante posiciones.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo para buscar y remplazar subcadenas dentro de otra.
		Este debe sustituir en una cadena ``texto'' la subcadena comprendida entre dos posiciones dadas por 
      expresiones numéricas, sustituyendo las subcadena correspondiente por una cadena de ``remplazo''. 
      Tras la ejecución debe tomar como valor la cadena
		resultante de sustituir, en la cadena principal, la subcadena correspondiente a las pociones dadas por la cadena de remplazo.

<P>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00069800000000000000">
Convertir a mayúsculas</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0113
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función conversión a mayúsculas.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dada una cadena de caracteres se necesita de un mecanismo que convierta todos los caracteres
		alfabéticos que la conforman en mayúsculas. El valor que se tomará será la cadena resultante de la operación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION00069900000000000000">
Convertir a minúsculas</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0114
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función conversión a minúsculas.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre cadena de caracteres.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dada una cadena de caracteres se necesita de un mecanismo que convierta todos los caracteres
		alfabéticos que la conforman en minúsculas. El valor que se tomará será la cadena resultante de la operación.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000610000000000000000">
Operadores sobre array</A>
</H2>

<P>

<H3><A NAME="SECTION000610100000000000000">
Dividir en fragmentos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0115
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función dividir array en fragmentos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array y un valor aritmético. Se divida el array en varios subarray de tantos
      elementos como indique el valor (a excepción del último). 
      La expresión tomará como valor un array que contiene cada uno de los subarray.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000610200000000000000">
Reducir mediante función</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0116
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función reducir array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo que dado un array y una función reduzca el array a un solo valor.
      La función de reducción deberá recibir como parámetro dos valores correspondiente al valor acumulado y al nuevo valor. 
      La función de reducción se ejecutará por cada elemento del array (excepto para el primero) tomando el valor acumulado y el nuevo valor, y devolviendo
      el próximo valor acumulado. Como valor este operador tomará el valor de la reducción. 
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000610300000000000000">
Obtener último</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0117
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función obtener último elemento de array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array se obtenga el 
último elemento de este, o el valor nulo si este está vacío.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000610400000000000000">
Obtener primero</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0118
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función obtener primer elemento de array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array se obtenga el 
primer elemento de este, o el valor nulo si este está vacío.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000610500000000000000">
Insertar en posición</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0119
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función para insertar un elemento en una posición de  array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array, un elemento
y una expresión aritmética que hace de posición, se inserte el elemento en dicha posición del array.
Si la posición se encuentra fuera de rango se dará un error de acceso.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000610600000000000000">
Eliminar posición</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0120
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función eliminar elemento de array de una posición.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array y una expresión aritmética que hace de posición, se elimine el elemento que ocupa dicha posición dentro del array.
Si la posición se encuentra fuera de rango se dará un error de acceso.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000610700000000000000">
Insertar al inicio</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0121
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función insertar al inicio de un array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array y un elemento de un tipo arbitrario, se inserte el elemento al comienzo del array.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000610800000000000000">
Insertar al final</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0122
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función insertar al final de un array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array y un elemento de un tipo arbitrario, se inserte el elemento al final del array.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000610900000000000000">
Eliminar del inicio</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0123
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función eliminar del comienzo de un array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array, se elimine
el primer elemento del mismo. Como valor se tomará el elemento eliminado del array, o el valor nulo si este se encontraba vacío.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION0006101000000000000000">
Eliminar del inicio</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0124
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función eliminar del final de un array.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre array.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que, dado un array, se elimine
el último elemento del mismo. Como valor se tomará el elemento eliminado del array, o el valor nulo si este se encontraba vacío.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000611000000000000000">
Operadores sobre expresiones regulares</A>
</H2>

<P>

<H3><A NAME="SECTION000611100000000000000">
Crear expresión regular</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0125
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Operador creador de expresión regular.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre expresiones regulares.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Dada una cadena de caracteres se necesita de un operador que convierta esta en una expresión regular. El
		valor del operador será la expresión regular.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000611200000000000000">
Comprobar expresión regular</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0126
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función comprobación de expresión regular.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre expresiones regulares.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa un operador que, dada una expresión regular y una cadena de caracteres,
		compruebe si esta pertenece al lenguaje definido por la expresión regular. Se
		deberá tomar como valor un dato de tipo lógico resultado de la operación.

<P>
Para que el resultado sea positivo la cadena debe pertenecer al conjunto de palabras delimitadas
		por la expresión regular. Si tan solo existe correspondencia parcial el resultado será negativo.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000611300000000000000">
Buscar mediante expresión regular</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0127
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Función de búsqueda estructurada.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre expresiones regulares.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo que lleve a cabo una búsqueda estructurada, es decir,
		obtener una estructura de datos array condicionada por una expresión regular denominada
		``patrón de búsqueda'' y una cadena de caracteres ``texto'' sobre la que se comprueba.

<P>
En la ejecución de este operador se deberá
		buscar en ``texto'' subcadenas que pertenezcan al conjunto definido por la expresión regular, originando
		un array con cada una de las coincidencias, que será el valor que tome la operación.

<P>
Adicionalmente la expresión regular podría estar formada por subexpresiones delimitadas
		por ``()''. En dicho caso se buscará en ``texto'' subcadenas que pertenezcan al
		conjunto delimitado por la expresión regular. Por cada subcadena encontrada se creará un array
		con las correspondencias de cada subexpresión. Cada uno de los arrays resultantes se
		deberán guardar en otro que será el valor que tome la operación.

<P>
Si se utiliza una expresión regular formada por subexpresiones los arrays correspondientes
		a cada subcadena deberán tener índices numéricos. Sin embargo debe darse la posibilidad de
		especificar una lista ordenada de cadenas claves para crear un array asociativo.

<P>
Además se ha de contemplar la búsqueda estructurada sobre un array de cadenas ``texto''.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000612000000000000000">
Operadores de conversión de tipo</A>
</H2>

<H3><A NAME="SECTION000612100000000000000">
Conversión a numérico</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0128
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Conversión a numérico.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de conversión de tipo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar un operador que permita convertir un dato a tipo aritmético. Esta conversión
		se deberá realizar en función al tipo de dato origen y de la forma descrita en el requisito en el que se hace referencia al mismo.
		El valor que tomará la operación deberá ser el dato tras la conversión de tipos. La conversión se podrá realizar a un número
      entro o flotante.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000612200000000000000">
Conversión a lógico</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0129
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Conversión a lógico.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de conversión de tipo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar un operador que permita convertir un dato a tipo lógico. Esta conversión
		se deberá realizar en función al tipo de dato origen y de la forma descrita en el requisito en el que se hace referencia al mismo.
		El valor que tomará la operación deberá ser el dato tras la conversión de tipos.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000612300000000000000">
Conversión a cadena de caracteres</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0130
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Conversión a cadena de caracteres.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de conversión de tipo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de facilitar un operador que permita convertir un dato a tipo cadena de caracteres. Esta conversión
		se deberá realizar en función al tipo de dato origen y de la forma descrita en el requisito en el que se hace referencia al mismo.
		El valor que tomará la operación deberá ser el dato tras la conversión de tipos.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000613000000000000000">
Operadores de entrada/salida</A>
</H2>

<P>

<H3><A NAME="SECTION000613100000000000000">
Escribir en la salida estándar</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0131
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Escribir en la salida estándar.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de entrada/salida.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe disponer de una serie de mecanismos que permitan llevar acabo la salida de datos. Esta permitirán que el contenido fuente pueda mostrar en la salida estándar los datos sobre los que opera. Estos datos
		debes tener una representación gráfica y ser imprimibles.  
	
</DD>
</DL>
</DIV>

<P>

<H2><A NAME="SECTION000614000000000000000">
Leer de la entrada estándar</A>
</H2>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0132
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Leer de la entrada estándar.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores de entrada/salida.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe implementar algún recurso que permita que el contenido fuente del usuario
		obtenga datos de la entrada estándar para operar. Este mecanismo deberá dar la posibilidad de mostrar un prompt.
		Además debe dar la opción de que la entrada finalice al introducir un salto de línea o al generarse una señal EOF (end-of-file).
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000615000000000000000">
Operadores informativos</A>
</H2>

<H3><A NAME="SECTION000615100000000000000">
Tipo de</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0133
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener tipo de dato.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores informativos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Debido al tipado dinámico se precisa de un mecanismo para conocer el tipo de dato relacionado
		con una variable. Este deberá mostrar en la salida estándar el tipo de la variable asociada a un identificador dado.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000615200000000000000">
Tamaño de</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0134
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener tamaño de dato.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores informativos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo para obtener el tamaño en memoria que ocupa el valor referenciado por una variable.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000615300000000000000">
Información sobre</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0135
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener información interna de un dato.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores informativos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un mecanismo para obtener información estructural de un dato, cómo este es representado por 
      el intérprete y el tamaño que ocupa.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000616000000000000000">
Procesos</A>
</H2>

<P>

<H3><A NAME="SECTION000616100000000000000">
Ejecutar comando</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0136
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Ejecutar comando.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un operador que ejecute un comando dado. 
		Para ello se deberá usar el interprete de comandos definido por el entorno del sistema operativo. Este operador contemplará
		un único operando correspondiente al comando a ejecutar. Como valor se deberá tomar la cadena de caracteres correspondiente 
		a la salida del comando.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000616200000000000000">
Evaluar cadena</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0137
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Evaluar cadena.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Deberá existir un operador que utilice el interprete para procesar una cadena de caracteres escrita en 
		el léxico y con la sintaxis del propio lenguaje. Este operador tomará como valor una cadena de caracteres relativa a la salida 
		generada por la interpretación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000616300000000000000">
Bifurcación de proceso</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0138
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Bifurcación de proceso.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo que bifurque el flujo de ejecución mediante la creación de un proceso hijo.
		El intérprete deberá crear un proceso clonado de si mismo, cuya ejecución proseguirá en el mismo punto. El operador 
		de bifurcación tomará valor aritmético cero en el proceso hijo, mientras que en el padre tomará el valor aritmético
		correspondiente al identificador del proceso hijo.    
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000616400000000000000">
Espera entre procesos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0139
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Espera entre procesos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un mecanismo que permita hacer que la ejecución de un proceso padre espere 
		a que todos o algunos de sus hijos finalicen su ejecución. Este podrá operar sobre un dato aritmético 
		que referenciará al identificador de proceso del hijo que se ha de esperar. El valor que tomará consistirá en
		el código correspondiente a la señal de salida producida por el último proceso finalizado.     
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000616500000000000000">
Obtener identificador de proceso</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0140
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener identificador de proceso.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Todo proceso tiene un identificador único en el sistema sobre el que se ejecuta. Se deberá
		disponer de un operador que tome el valor del identificador de proceso correspondiente al interprete.     
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000616600000000000000">
Obtener identificador de proceso padre</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0141
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener identificador de proceso padre.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Debe existir algún mecanismo que permita obtener el identificador del proceso padre cuando 
		el interprete se ejecuta como proceso hijo de otro.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000616700000000000000">
Señales entre procesos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0142
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Señales entre procesos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Debe existir algún mecanismo que permita mandar señales entre procesos. Estas señales se corresponderán con
      señales UNIX. Para mandar una señal a un proceso se deberá dar un identificador de proceso y un entero correspondiente a la
      señal a enviar.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000616800000000000000">
Manejador de señales a procesos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0143
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Manejador de señales a procesos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Debe existir algún mecanismo que permita especificar una función que será ejecutada cuando el proceso reciba una 
      determinada señal.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000616900000000000000">
Llamar a función como proceso</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0144
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Llamar a función como proceso.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre procesos.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de operador que mediante una función y un listado de parámetros realice una llamada 
		a la misma mediante la creación de un proceso hijo.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000617000000000000000">
Ficheros</A>
</H2>

<H3><A NAME="SECTION000617100000000000000">
Fichero</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0145
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>El intérprete debe ser capaz de manipular ficheros, para ello se precisa de un tipo de dato
		que simbolice un puntero a un fichero del sistema de ficheros. Este tipo de dato no debe ser convertido a ningún otro
		tipo de dato ni viceversa. Además solo será tratado por algunos operadores dedicados. 

<P>
No se tendrán en cuenta los  ficheros binarios.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000617200000000000000">
Abrir ficheros</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0146
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Abrir ficheros.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Es necesario un mecanismo que permita abrir ficheros para su manipulación. Este operará sobre
		una cadena de caracteres que simbolice la ruta al fichero y otra que determine el modo en el que será abierto. Se 
		tomará como valor un dato de tipo puntero a fichero. Los posibles modos serán:

<P>
<DL>
<DT><STRONG>r:</STRONG></DT>
<DD>Lectura.
			
</DD>
<DT><STRONG>r+:</STRONG></DT>
<DD>Lectura y/o escritura.
			
</DD>
<DT><STRONG>w:</STRONG></DT>
<DD>Escritura truncando el contenido del fichero.
			
</DD>
<DT><STRONG>w+:</STRONG></DT>
<DD>Lectura y/o escritura truncando el contenido del fichero.
			
</DD>
<DT><STRONG>a:</STRONG></DT>
<DD>Escritura posicionando el puntero al final el fichero.
			
</DD>
<DT><STRONG>a+:</STRONG></DT>
<DD>Lectura y/o escritura posicionando el puntero al final del fichero.
		
</DD>
</DL>

<P>
Todos los modos a excepción de sólo lectura deberán crear el fichero si este no existe.  
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000617300000000000000">
Cerrar ficheros</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0147
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Cerrar ficheros.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Es necesario un mecanismo que permita cerrar ficheros abiertos a partir de un puntero al mismo.
		Se deberá finalizar cualquier flujo de datos abierto y el fichero quedará cerrado. Como valor se deberá tomar 
		un dato de tipo lógico que determine si la operación se ha realizado correctamente.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000617400000000000000">
Escribir en fichero</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0148
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Escribir en fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se hace necesario un operador que, dado un dato de tipo puntero a fichero, pueda escribir datos
		en la posición referenciada por el mismo. Así este operador trabaja sobre dos operandos, un puntero a fichero y una 
		cadena de caracteres que simbolizará el contenido a escribir. Como valor el operador toma el número de bytes que 
		fueron escritos.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000617500000000000000">
Leer de fichero</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0149
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Leer de fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se hace necesario un operador que, dado un dato de tipo puntero a fichero, lea desde la
		posición referenciada por el mismo hasta un carácter de nueva línea, o bien un número de caracteres dado. Así el operador deberá tomar como valor 
		una cadena de caracteres que represente el contenido leído.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000617600000000000000">
Cambiar posición de puntero a fichero</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0150
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Cambiar posición de puntero a fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Una operación básica sobre punteros a ficheros es desplazar este dentro del contenido del mismo. 
		Para ello se precisa de un operador que, dado un puntero a fichero, cambie la posición de este dentro del propio fichero.
		Así la nueva posición deberá ser una expresión numérica que represente un offset relativo al principio del fichero, el final 
		o la posición actual del puntero. La expresión correspondiente al operador deberá tomar un valor booleano que determine si el cambio
		de posición se ha realizado correctamente.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000617700000000000000">
Obtener la posición actual de puntero a fichero</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0151
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener la posición actual de puntero a fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se necesita de un operador que dado un puntero a fichero tome el valor aritmético que represente la posición de este 
		dentro del mismo.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000617800000000000000">
Obtener contenido de un fichero</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0152
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener contenido de un fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un operador que simplifique la tarea de obtener el contenido completo de un fichero, sin que sea necesario disponer de un 
		puntero al mismo. Para ello se deberá facilitar una cadena de caracteres que simbolice la ruta completa del fichero. El operador tomará como valor
		una cadena de caracteres que contenga todo el contenido del fichero. En el caso de que el fichero no exista se deberá tomar como valor la cadena vacía.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000617900000000000000">
Cadena como contenido de un fichero.</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0153
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Cadena como contenido de un fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un operador que simplifique la tarea de escribir una cadena de caracteres en un fichero, sin que sea necesario 
		disponer de un puntero al mismo. Si el fichero existe su contenido deberá ser truncado, si no existe será creado. Este operador tendrá como operandos dos cadenas 
		de caracteres que se correspondan con la ruta del fichero y la cadena a escribir. Como valor se tomará la cadena escrita.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION0006171000000000000000">
Añadir cadena al contenido de un fichero</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0154
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Añadir cadena al contenido de un fichero.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Operadores sobre ficheros.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un operador que simplifique la tarea de añadir una cadena de caracteres al final de un fichero, sin que sea necesario 
		disponer de un puntero al mismo. Si el fichero no existe será creado. Este operador tendrá como operandos dos cadenas 
		de caracteres que se correspondan con la ruta del fichero y la cadena a escribir. Como valor se tomará la cadena escrita.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000618000000000000000">
Fechas y tiempo</A>
</H2>

<P>

<H3><A NAME="SECTION000618100000000000000">
Obtener fecha</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0155
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Obtener fecha.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Fechas y tiempo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Es necesario disponer de un operador que dé formato a la fecha/hora local. Este operador 
		deberá tener como operando una expresión cadena de caracteres que contenga una serie de directivas de 
		formato. El valor que tomará la operación será una cadena de caracteres que represente la fecha/hora en
		el formato dado. Las directivas de formato serán las siguientes:
		<DL>
<DT><STRONG>%d:</STRONG></DT>
<DD>Día del mes con dos dígitos.
			
</DD>
<DT><STRONG>%j:</STRONG></DT>
<DD>Día del mes sin ceros iniciales.
			
</DD>
<DT><STRONG>%l:</STRONG></DT>
<DD>Día de la semana de forma alfabética completa.
			
</DD>
<DT><STRONG>%D:</STRONG></DT>
<DD>Día de la semana de forma alfabética y con tres letras.
			
</DD>
<DT><STRONG>%w:</STRONG></DT>
<DD>Día de la semana de forma numérica (0-domingo,6-sábado).
			
</DD>
<DT><STRONG>%z:</STRONG></DT>
<DD>Día del año de forma numérica.
			
</DD>
<DT><STRONG>%F:</STRONG></DT>
<DD>Mes de forma alfabética.
			
</DD>
<DT><STRONG>%m:</STRONG></DT>
<DD>Mes de forma numérica con dos dígitos.
			
</DD>
<DT><STRONG>%n:</STRONG></DT>
<DD>Mes de forma numérica sin ceros iniciales.
			
</DD>
<DT><STRONG>%M:</STRONG></DT>
<DD>Mes de forma alfabética con tres letras.
			
</DD>
<DT><STRONG>%Y:</STRONG></DT>
<DD>Año con cuatro dígitos.
			
</DD>
<DT><STRONG>%y:</STRONG></DT>
<DD>Año con dos dígitos.
			
</DD>
<DT><STRONG>%a:</STRONG></DT>
<DD>Periodo del día (am/pm) en minúsculas.
			
</DD>
<DT><STRONG>%A:</STRONG></DT>
<DD>Periodo del día (am/pm) en mayúsculas.
			
</DD>
<DT><STRONG>%g:</STRONG></DT>
<DD>Hora en formato 12h sin ceros iniciales.
			
</DD>
<DT><STRONG>%G:</STRONG></DT>
<DD>Hora en formato 24h sin ceros iniciales.
			
</DD>
<DT><STRONG>%h:</STRONG></DT>
<DD>Hora en formato 12h con dos dígitos.
			
</DD>
<DT><STRONG>%H:</STRONG></DT>
<DD>Hora en formato 24h con dos dígitos.
			
</DD>
<DT><STRONG>%i:</STRONG></DT>
<DD>Minutos con dos dígitos.
			
</DD>
<DT><STRONG>%U:</STRONG></DT>
<DD>Segundos desde la Época Unix (1 de Enero del 1970 00:00:00 GMT).
			
</DD>
<DT><STRONG>%%:</STRONG></DT>
<DD>Carácter %.		
		
</DD>
</DL>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000618200000000000000">
Tiempo Unix </A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0156
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Operador time.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Fechas y tiempo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se precisa de un operador que calcule el número de segundos desde 
		la Época Unix (1 de Enero del 1970 00:00:00 GMT). Este operador no tendrá operandos y 
		tomará el valor aritmético correspondiente.		
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000618300000000000000">
Parar ejecución</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0157
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Parar ejecución.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Fechas y tiempo.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se deberá de proporcionar un mecanismo que permita suspender o bloquear
		la ejecución durante un tiempo dado. Constará de una expresión que
		represente el valor aritmético del tiempo en segundos.
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000619000000000000000">
Errores</A>
</H2>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0158
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Información de errores.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Error.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Si se produce un error el intérprete debe informar del tipo y causa del error, así como del contexto en el que se ha producido (nombre y línea de fichero).
	
</DD>
</DL>
</DIV>

<H2><A NAME="SECTION000620000000000000000">
Extensiones</A>
</H2>

<H3><A NAME="SECTION000620100000000000000">
Extensión</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0159
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Extensión.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Extensiones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La funcionalidad y características del intérprete deben ser extensible mediante módulos dinámicos. 
      Estos módulos añadirán sentencias, operadores y demás elementos propios de un lenguaje de programación. 

<P>
Para que un extensión pueda ser utilizada se deberá cargar. 
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000620200000000000000">
Carga de extensiones mediante fichero de configuración</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0160
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Carga de extensiones mediante fichero de configuración.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Extensiones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo que permita especificar un listado de extensiones que serán cargados al ejecutarse
      el intérprete. Estos módulos serán especificados en un fichero de texto plano separados mediante saltos de línea. Toda ejecución del intérprete
      conllevará la carga de las extensiones especificadas.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000620300000000000000">
Carga de extensiones mediante sentencia</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0161
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Carga de extensiones mediante sentencia.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Extensiones.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo que permita cargar una extensión en tiempo de ejecución. Para ello se deberá
      facilitar la ruta del módulo correspondiente a la extensión como una cadena de caracteres. Tras la carga de la extensión las 
      características de esta serán añadidas al intérprete.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000620400000000000000">
Biblioteca GNU de internacionalización (gettext)</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0162
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Extensión gettext.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Extensión gettext.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se deberá facilitar a modo de extensión la funcionalidad y características de la 
      biblioteca GNU de internacionalización (i18n), gettext. 
	
</DD>
</DL>
</DIV>
<H2><A NAME="SECTION000621000000000000000">
Biblioteca de desarrollo OMI</A>
</H2>

<P>

<H3><A NAME="SECTION000621100000000000000">
Recursos del intérprete</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0163
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Recursos del intérprete.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Biblioteca OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Todos los recursos de desarrollo sobre los que se construye el intérprete tales 
      como clases, funciones, etc. Deberán ser construidos para que puedan ser utilizados desde otros desarrollos,
      estableciéndose así un marco de trabajo para otros proyectos. 
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000621200000000000000">
Interpretar desde otros proyectos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0164
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Intérpretar desde otros proyectos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Biblioteca OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se debe facilitar un mecanismo para que otros proyectos software puedan interpretar código
      OMI de forma interna. Esto se hará mediante la llamada a una función de la biblioteca OMI.
	
</DD>
</DL>
</DIV>

<P>

<H2><A NAME="SECTION000622000000000000000">
Web del proyecto OMI</A>
</H2>

<P>

<H3><A NAME="SECTION000622100000000000000">
Sitio web</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0165
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sitio web.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de una web que sirva de plataforma para acceder al 
      proyecto y todos los recursos que este brinda. Esta web tendrá una estructura estática.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000622200000000000000">
Home del sitio web</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0166
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Home del sitio web.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La web OMI debe dispone de una página de entrada en la que se
      recoge: 
      
<UL>
<LI>Una descripción resumida del proyecto.
</LI>
<LI>Enlaces a las secciones principales.
</LI>
<LI>Un listado de noticias que será mantenida manualmente por el administrador
</LI>
<LI>Enlaces a las descargas de la última versión de los recursos.
      
</LI>
</UL>
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000622300000000000000">
Sobre OMI</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0167
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sobre OMI.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Deberá recoger información sobre el proyeto, el alcance del mismo, la autoría y los organismos implicados.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000622400000000000000">
Contacto</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0168
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Contacto.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>deberá listar diferentes medios de contacto. 
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000622500000000000000">
Índice de documentación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0169
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Índice de documentación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de dispone de una página en la que se enlace de forma ordenada las distintas secciones de la 
      documentación, así como las distintas herramientas para navegar por esta.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000622600000000000000">
Página de documentación</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0170
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Índice de documentación.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Cada documento relativo a la presente memoria deberá estar disponible desde la web del proyecto.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000622700000000000000">
Características</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0171
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Características.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de una página en la que se liste las características del intérprete.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000622800000000000000">
Navegador de gramática</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0172
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Gramática.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de una página que sirva para navegar por las reglas gramaticales que definen el intérprete.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000622900000000000000">
Navegador de clases</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0173
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Clases.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de una página que sirva para navegar por las clases de programación sobre las que se construye el 
      intérprete.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION0006221000000000000000">
Navegador de archivos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0174
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Archivos .
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de una página que sirva para navegar por los archivos de código fuente que sirven para construir el intérprete.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION0006221100000000000000">
Wiki</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0175
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Wiki .
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>Web OMI.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de una wiki para el proyecto que recoja aspectos relativos al proyecto y las materias que este estudia.
	
</DD>
</DL>
</DIV>

<P>

<H2><A NAME="SECTION000623000000000000000">
RunTree</A>
</H2>

<P>

<H3><A NAME="SECTION000623100000000000000">
Intérprete online</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0176
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Intérprete online.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>Se ha de disponer de una herramienta que permita
      hacer uso del intérprete desde el navegador. Esta herramienta tomará un código fuente 
      escrito en el lenguaje de programación y lo enviará a un intérprete OMI para su procesamiento. 
      Luego mostrará, paso a paso, información relativa al proceso de interpretación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000623200000000000000">
Escribir código fuente</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0177
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Escribir código fuente.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de disponer de un campo de formulario en el que se pueda escribir el código fuente
      que será enviado para interpretar. Este campo deberá mostrar un resaltado de sintaxis.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000623300000000000000">
Árbol sintáctico</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0178
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Árbol sintáctico.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de mostrar el árbol sintáctico resultado de la interpretación y permitir la navegabilidad por este.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000623400000000000000">
Tabla de símbolos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0179
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Tabla de símbolos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de mostrar el estado de las tablas de símbolos en cada paso del proceso.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000623500000000000000">
Salida de datos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0180
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Salida.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá mostrar la salida generada por cada paso del proceso.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000623600000000000000">
Entrada de datos</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0181
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Entrada de datos.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá solicitar al usuario la entrada de datos cunado el proceso de interpretación lo requiera.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000623700000000000000">
Limpieza de salida</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0182
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Limpieza de salida.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá dar la posibilidad de limpiar la salida generada por el proceso de interpretación.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000623800000000000000">
Consola de información</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0183
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Consola de información.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de disponer de una sección en la que se muestre textualmente la operación llevada a cabo.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION000623900000000000000">
Ejecución paso a paso</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0184
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Paso a paso.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de disponer de acciones que permitan avanzar la ejecución un paso.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION0006231000000000000000">
Ejecución sentencia a sentencia</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0185
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Sentencia a sentencia.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de disponer de acciones que permitan avanzar la ejecución una sentencia.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION0006231100000000000000">
Ejecución automática</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0186
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Ejecución automática.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de disponer de la capacidad de ejecutar paso a paso el programa pero de una forma automática.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION0006231200000000000000">
Guardar código fuente</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0187
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Guardar código fuente.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de disponer de la capacidad de guardar el código fuente escrito en un fichero local.
	
</DD>
</DL>
</DIV>

<P>

<H3><A NAME="SECTION0006231300000000000000">
Abrir código fuente</A>
</H3>
<DIV class="requisite">
	<DL>
<DT><STRONG>Número:</STRONG></DT>
<DD>0188
		
</DD>
<DT><STRONG>Nombre:</STRONG></DT>
<DD>Abrir código fuente.
		
</DD>
<DT><STRONG>Categoría:</STRONG></DT>
<DD>RunTree.
		
</DD>
<DT><STRONG>Descripción:</STRONG></DT>
<DD>La herramienta deberá de disponer de la capacidad de leer el código fuente escrito en un fichero local para enviarlo a interpretar.
	
</DD>
</DL>
</DIV>

<P>

<H1><A NAME="SECTION00070000000000000000">
Requisitos no funcionales</A>
</H1>

<H2><A NAME="SECTION00071000000000000000">
Rendimiento</A>
</H2>
Es condición necesaria que el sistema software desarrollado presente un rendimiento óptimo. Para ello se medirá el rendimiento 
desde dos aspectos: tiempo y espacio

<H3><A NAME="SECTION00071100000000000000">
Tiempo</A>
</H3>
A pesar de que el objetivo del interprete no es servir para la producción de software, al ser un sistema que será utilizado para el 
desarrollo de otras aplicaciones, el rendimiento en cuanto al tiempo debe ser aceptable en comparación con las herramientas existentes en 
el mercado. 

<P>

<H3><A NAME="SECTION00071200000000000000">
Espacio</A>
</H3>
El sistema debe ser óptimo en cuanto el espacio en memoria que ocupan sus estructuras. Debe hacer un uso correcto de la memoria. 
Si las estructuras que conforman el intérprete ocupan demasiado espacio, los datos de los que hagan uso el usuario en sus programas también lo
harán.

<P>

<H2><A NAME="SECTION00072000000000000000">
Usabilidad</A>
</H2>

<H3><A NAME="SECTION00072100000000000000">
Reglas léxicas y sintácticas</A>
</H3>
El sistema deberá interpretar un lenguaje con reglas léxicas y sintácticas claras, que sean fáciles de comprender y asimilar. La estructura del 
lenguaje en cuanto a estos dos aspectos debe ser similar a los lenguajes de programación actuales. 

<H3><A NAME="SECTION00072200000000000000">
Interfaz</A>
</H3>
La interfaz de entrada salida del interprete debe ser clara y presentar las opciones de una forma adecuada. Además la interfaz web debe 
ser amigable a la forma de operara del usuario que la utilice.

<P>

<H2><A NAME="SECTION00073000000000000000">
Accesibilidad</A>
</H2>
El sistema desarrollado debe ser accesible desde cualquier computadora con acceso a internet. Para ello se utilizará un navegador web. Por otro lado 
el interprete podrá ser instalado de forma local para un uso individual.

<P>

<H2><A NAME="SECTION00074000000000000000">
Estabilidad</A>
</H2>
Se requiere que el sistema desarrollado presente un umbral de fallos bajo. Debe adaptarse a los casos excepcionales, y en caso de error informar adecuadamente de
los motivos y causas del mismo.

<P>

<H2><A NAME="SECTION00075000000000000000">
Mantenibilidad</A>
</H2>
El sistema desarrollado debe ser mantenible en el tiempo. Para ello debe estar correctamente documentado, modularizado y estructurado. 

<P>

<H2><A NAME="SECTION00076000000000000000">
Concurrencia</A>
</H2>
El sistema deberá ser accesible por varios usuarios en el mismo marco de tiempo. Es por ello que deberá ser capaz de funcionar en un entorno de 
concurrencia.
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
