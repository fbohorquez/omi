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
   $obj = @socket_read($socket, 10485760);
   //~ var_dump ($obj);
   @socket_close($socket);
   return $obj;
   
}

function data ($pid, $src) {
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
   socket_write($socket, $src, strlen($src));
   @socket_close($socket);
   sleep (1);
}


if($_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest' && is_numeric ($_POST['id'])) {
   if (isset($_POST['data'])){
      data(10000 + $_POST['id'], $_POST['data']);
   }
   $a =  request (10000 + $_POST['id']);
   $a = str_replace ("\n", "", $a);
   $str = str_replace (",]", "]", str_replace (",}", "}", $a));
   echo json_encode ([ 'obj' => json_decode ($str)]);
}
