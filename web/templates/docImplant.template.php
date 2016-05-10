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
<LI><A NAME="tex2html12"
  HREF="<?=URL?>doc/implantacion#SECTION00020000000000000000">Vista general</A>
<LI><A NAME="tex2html13"
  HREF="<?=URL?>doc/implantacion#SECTION00030000000000000000">Introducción</A>
<LI><A NAME="tex2html14"
  HREF="<?=URL?>doc/implantacion#SECTION00040000000000000000">Requisitos previos</A>
<LI><A NAME="tex2html15"
  HREF="<?=URL?>doc/implantacion#SECTION00050000000000000000">Inventario de componentes</A>
<UL>
<LI><A NAME="tex2html16"
  HREF="<?=URL?>doc/implantacion#SECTION00051000000000000000">Hardware</A>
<LI><A NAME="tex2html17"
  HREF="<?=URL?>doc/implantacion#SECTION00052000000000000000">Software</A>
</UL>
<BR>
<LI><A NAME="tex2html18"
  HREF="<?=URL?>doc/implantacion#SECTION00060000000000000000">Procedimiento de intalación</A>
<LI><A NAME="tex2html19"
  HREF="<?=URL?>doc/implantacion#SECTION00070000000000000000">Pruebas de implantación</A>
<LI><A NAME="tex2html20"
  HREF="<?=URL?>doc/implantacion#SECTION00080000000000000000">Procedimientos de operación y nivel de servicio</A>
</UL>
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

<P>

<H1><A NAME="SECTION00030000000000000000">
Introducción</A>
</H1>
Los objetivos del proyecto OMI es servir como una plataforma para el aprendizaje de cómo se 
construyen los lenguajes de programación. Esto lo hace mediante el estudio de un intérprete propio del 
proyecto, desarrollado desde cero y con características de los lenguajes actuales. Para facilitar toda esta información el
proyecto OMI pone a disposición del usuario una serie de herramientas que ayudan al aprendizaje, así mismo como toda la información relativa al proyecto. 

<P>
El sistema OMI pretende ser un sistema distribuido con una alta disponibilidad y de fácil acceso. Es por ello que 
todas las herramientas y recursos del proyecto son ofrecida vía online y pueden ser accedidas desde cualquier navegador o dispositivo.

<P>
La implantación del sistema OMI comprende la configuración del dominio, del servidor web y del sistema intérprete.

<P>

<H1><A NAME="SECTION00040000000000000000">
Requisitos previos</A>
</H1>
Para el correcto funcionamiento de la plataforma se precisa de un equipo con alta disponibilidad que hará de servidor web. Este equipo tendrá una 
una distribución GNU/Linux Debian o derivada.

<P>

<H1><A NAME="SECTION00050000000000000000">
Inventario de componentes</A>
</H1>

<P>

<H2><A NAME="SECTION00051000000000000000">
Hardware</A>
</H2>

<P>
<DL>
<DT><STRONG>Virtualizacion:</STRONG></DT>
<DD>VPS
</DD>
<DT><STRONG>RAM:</STRONG></DT>
<DD>2 GiB
</DD>
<DT><STRONG>CPU:</STRONG></DT>
<DD>8 núcleos
</DD>
</DL> 

<P>

<H2><A NAME="SECTION00052000000000000000">
Software</A>
</H2>
<DL>
<DT><STRONG>Sistema Operativo:</STRONG></DT>
<DD>Debian 7
</DD>
<DT><STRONG>Interprete:</STRONG></DT>
<DD>OMI 1.0
</DD>
<DT><STRONG>Nombre de dominio:</STRONG></DT>
<DD>Bind 9
</DD>
<DT><STRONG>Web:</STRONG></DT>
<DD>Apache 2.2
</DD>
<DT><STRONG>Interprete web:</STRONG></DT>
<DD>PHP 5.4
</DD>
<DT><STRONG>Plataforma:</STRONG></DT>
<DD>omi-project 1.0
</DD>
</DL>

<P>

<H1><A NAME="SECTION00060000000000000000">
Procedimiento de intalación</A>
</H1>

<P>
Se procede con la instalación de los paquetes necesarios
<PRE>
apt-get install apache2 php5 bind9 autoconf automake build-essential libreadline-dev libboost-regex-dev
</PRE>

<P>
Se configura la zona del dominio y los registros asociados al mismo.
<PRE>
; Zone file for omi-project.com
$TTL 14400
omi-project.com.	14400	IN	SOA	ns.omi-project.com. omi-project.com. (
			10000000001
			86400
			7200
			3600000
			86400 )

omi-project.com.	14400	IN	NS	ns1.omi-project.com.
omi-project.com.	14400 	IN	NS	ns2.omi-project.com.
omi-project.com.	14400	IN	A	$IP$
localhost	14400	IN	A	127.0.0.1
omi-project.com.	14400	IN	MX	10	mail
omi-project.com. 	14400	IN	TXT	"v=spf1 mx ptr ip4:$IP$ mx:mail.omi-project.com +all"
omi-project.com.     14400   IN      SPF     "v=spf1 mx ptr ip4:$IP$ mx:mail.omi-project.com +all"

mail	14400	IN	A	$IP$
www	14400	IN	CNAME	omi-project.com.
ftp	14400	IN	A	$IP$
ns	14400	IN	A	$IP$
ns1 	14400  	IN	A	$IP$
ns2 	14400	IN	A	$IP$
admin 	14400	IN	A	$IP$

_adsp._domainkey.omi-project.com. IN TXT "dkim=all; atps=y; asl=omi-project;"
</PRE>

<P>
Descarga y compilación del proyecto OMI.

<P>
<PRE>
wget http://www.omi-project.com/download/code/omi_1.0.tar.gz
tar -xzvf omi_1.0.tar.gz
cd omi_1.0.tar.gz
./configure JSON=1 SERVER=1
make
make install
make clean
</PRE>

<P>
Configuración del servidor web Apache. Se define un nuevo host virtual

<P>
<PRE>
&lt;VirtualHost *:80&gt;
     ServerAdmin admin@omi-project.com
     ServerName omi-project.com
     DocumentRoot $PATH$
     ErrorLog $PATH$/error.log
     TransferLog $PATH$/access.log
     &lt;Directory $PATH$ &gt;
         Require all granted
         AllowOverride all
     &lt;/Directory&gt;
   
   &lt;IfModule php5_module&gt;
	    php_flag session.cookie_httponly on
	&lt;/IfModule&gt;

	&lt;IfModule mod_headers.c&gt;
       Header always append X-Frame-Options SAMEORIGIN
       Header set Server "securesauce http/html processor"
       Header unset X-Powered-By
   &lt;/IfModule&gt;
&lt;/VirtualHost&gt;
</PRE>

<P>
Se ha de mover la web al directorio de producción y dar los permisos de acceso correspondientes
<PRE>
mv OMI_1.0/web $PATH$
chown -R omi:www-data $PATH$
chmod -R 750 $PATH$
</PRE>

<P>
Para finalizar se han de reiniciar los servicios.
<PRE>
service omi restart
service apache2 restart
service bind9 restart
</PRE>

<P>

<H1><A NAME="SECTION00070000000000000000">
Pruebas de implantación</A>
</H1>
Para comprobar que la implantación se ha llevado a cabo correctamente se puede llevar a cabo un chequeo de las pruebas automáticas. Para ello:
<PRE>
cd OMI_1.0
make check
</PRE>

<P>
También se puede acceder a las distintas secciones de la web. Navegando por los distintos páginas y comprobando la disponibilidad de los recursos.

<P>
Para comprobar que el servidor OMI se encuentra funcionando correctamente se puede usar el cliente runTree y comprobar
 que el código fuente enviado se interpreta correctamente.

<P>

<H1><A NAME="SECTION00080000000000000000">
Procedimientos de operación y nivel de servicio</A>
</H1>
 Para comprobar el correcto funcionamiento  del sistema en cuanto a rendimiento y disponibilidad se puede usar 
 un navegador web y las herramientas de desarrollo que la mayoría de estos tienen integradas. También se puede automatizar 
 un chequeo de disponibilidad desde una maquina tercera o la propia máquina

<P>
La web OMI no guarda ningún dato del usuario ni de los proceso asociados por lo que no es necesario hacer back-ups periódicos. 

<P>
Es posible chequear errores en el servicio web mediante el log $PATH$/error.log. También es posible
 chequear las transferencias de datos y las peticiones atendidas en el fichero $PATH$/access.log.
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
