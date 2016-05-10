<?php
include_once('../../../init.php');
start($_POST);
 

function request ($src) {
   //Socket
   error_reporting(E_ALL ^ E_NOTICE);
   $address = gethostbyname('localhost');

   $socket = @socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
   if ($socket === false) {
      $log = "ERROR SOCKET";
   } 
   $result = @socket_connect($socket, $address, PORT_SOCKET);
   if ($result === false) {
     $log = "socket_connect() falló.\nRazón: ($result) " . socket_strerror(socket_last_error($socket)) . "\n";
   }
   //Tipo
   socket_write($socket, $src, strlen($src));
   $pid = @socket_read($socket, 2048);
   @socket_close($socket);
   return $pid;
   
}

if($_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest') {
  echo json_encode ([ 'id' => request ($_POST['code'])]);
}
