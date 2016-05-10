<?php
function start ($data = []) {
   session_start ();
}

function __autoload ($class) {
   if (file_exists (PATH.'class/'.$class.'.class.php')){
      include (PATH.'class/'.$class.'.class.php');
   }
} 
