<?php

class Conexion
{
  public static function Conectar()
  {
    define('SERVIDOR', 'localhost');
    define('NOMBRE_BD', 'id20002854_estacionamiento');
    define('USUARIO', 'id20002854_carro');
    define('CLAVE', 'o?qOhF<y~4w{k-La');
    $opciones = [PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'];

    try {
      $pdo = new PDO('mysql:host=' . SERVIDOR . ';dbname=' . NOMBRE_BD, USUARIO, CLAVE, $opciones);
      return $pdo;
    } catch (Exception $e) {
      $respuesta = ['Error' => 'error: ' . $e->getMessage()];
      print json_encode($respuesta);
      die();
    }
  }
}

