<?php
$content = str_replace ('.', '', str_replace('/', '',$_GET['content']));
include ('../../init.php');
template::header (['css' => 'latex']);
template::menuMobile ();
template::top ();
template::$content ();
template::upButton ();
template::footer ();
?>




