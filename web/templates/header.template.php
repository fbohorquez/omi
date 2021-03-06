<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" >
<head>
      <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
      <meta name="viewport" content="width=device-width,initial-scale=1">
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
      <meta http-equiv="Content-Language" content="es_ES">
      <link rel="shortcut icon" href="<?= URL;?>src/images/omi.ico">
		<title><?= $param['title']?:'OMI Open Modular Interpreter'?></title>
		<meta name="description" content="<?= $param['description']?:'Intérprete Abierto y Modular enfocado en el estudio de la terría de autómatas y lenguajes formales.'?>">
      <meta name="keywords" content="interprete abierto modular lenguaje teoría autómata lenguajes formales compiladores didáctico estudio <?= $param['keywors'];?>">
      <link href='https://fonts.googleapis.com/css?family=Dosis:700,500' rel='stylesheet' type='text/css'>
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css">
      <link href="<?=URL;?>src/css/main.css" rel="stylesheet" type="text/css" />
      <link href="<?=URL;?>src/css/media.css" rel="stylesheet" type="text/css" />
<?php
      if($param['css']){
         if (!is_array($param['css'])) $param['css'] = array ($param['css']);
         for ($i = 0, $n = count ($param['css']); $i < $n; ++$i) 
            echo '<link href="'.URL.'src/css/'.$param['css'][$i].'.css" rel="stylesheet" type="text/css" />';
      }
?>
</head>
<body>
