<?php
class template {
   function __callStatic ($f, $param) {
      $param = $param[0];
      if (file_exists (PATH.'templates/'.$f.'.template.php')){
         include (PATH.'templates/'.$f.'.template.php');
      }else {
         throw new exception ("No se encuentra ".PATH.'template/'.$f.'template.php');
      }
   }
}
?>
