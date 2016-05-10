<?php
include_once('../../../init.php');
start($_POST);
 

function request ($pid) {
   //Socket
   error_reporting(E_ALL ^ E_NOTICE);
   $address = gethostbyname('localhost');

   $socket = @socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
   if ($socket === false) {
      $log = "ERROR SOCKET";
   } 
   $result = @socket_connect($socket, $address, $pid);
   if ($result === false) {
     $log = "socket_connect() falló.\nRazón: ($result) " . socket_strerror(socket_last_error($socket)) . "\n";
   }
   //Tipo
   $obj = @socket_read($socket, 1048576);
   @socket_close($socket);
   return $obj;
   
}

if($_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest' && is_numeric ($_POST['id'])) {
   $str = str_replace (",]", "]", str_replace (",}", "}", request (10000 + $_POST['id'])));
   echo json_encode ([ 'obj' => json_decode ($str)]);
}
