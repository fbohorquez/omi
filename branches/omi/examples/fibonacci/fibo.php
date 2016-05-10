<?php
function fibo ($n){
   if ($n == 1 || $n == 2 || $n == null) 
      return 1;
   else
      return fibo ($n - 1) + fibo ($n - 2);
}
//~ var_dump($argv[1]);
echo fibo ($argv[1])."\n";
