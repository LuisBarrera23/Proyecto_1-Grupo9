<?php
require_once './Conexion.php';
$conexion = new Conexion();
$conectar = $conexion->Conectar();

$body = json_decode(file_get_contents("php://input"), true);
$data = array();

if ($body['Methods'] != '') {
  switch ($body['Methods']) {
    case 'POST':
        // $data["usuario"] = $body['usuario'];
        // $data["password"] = $body['password'];
       
        $consulta2 = "SELECT * FROM `usuarios` WHERE `user` LIKE '{$body['usuario']}'";
        $resultado2 = $conectar->prepare($consulta2);
        $resultado2->execute();
        
        
        
        if ($resultado2->rowCount() >= 1) {
            $data["msg"] = "The user already exists.";
        } else {
            $consulta = "INSERT INTO `usuarios` (`id`, `user`, `password`,`pos`) VALUES (NULL, '{$body['usuario']}', '{$body['password']}', '{$body['pos']}')";
            $resultado = $conectar->prepare($consulta);
            $resultado->execute();
            $data["msg"] = "The user was added.";
        }
        
        
        echo json_encode($data);
      break;

    case 'GET':
        $usuario = $body['usuario'];
        $clave = $body['password'];
        $consulta = "SELECT * FROM `usuarios` WHERE `user` LIKE '{$usuario}' AND `password` LIKE '{$clave}'";
        $resultado = $conectar->prepare($consulta);
        $resultado->execute();
        
        if ($resultado->rowCount() >= 1) {
            if($usuario == "admin"){
                $data["resultado"] = 2; 
            }else{
                $data["resultado"] = 1;
            }
          
        } else {
          $data["resultado"] = 0; 
        }
        echo json_encode($data);
      break;
      
    case 'GETP1':
        $consulta = "SELECT * FROM `Parking 1`";
        $ejecutar = $conectar->prepare($consulta);
        $ejecutar->execute();
        $resultado = $ejecutar->fetchall(PDO::FETCH_OBJ);
        echo json_encode($resultado);
      break;
      
     case 'GETP2':
        $consulta = "SELECT * FROM `Parking 2`";
        $ejecutar = $conectar->prepare($consulta);
        $ejecutar->execute();
        $resultado = $ejecutar->fetchall(PDO::FETCH_OBJ);
        echo json_encode($resultado);
      break;
     
    case 'GETNUMP1':
        $consulta = "SELECT COUNT(*) FROM `Parking 1` WHERE `state` LIKE '0'";
        $ejecutar = $conectar->prepare($consulta);
        $ejecutar->execute();
        $resultado = $ejecutar->fetch();
        $data["disponibles"] = $resultado[0];
        $consulta = "SELECT COUNT(*) FROM `Parking 1` WHERE `state` LIKE '1'";
        $ejecutar = $conectar->prepare($consulta);
        $ejecutar->execute();
        $resultado = $ejecutar->fetch();
        $data["ocupados"] = $resultado[0];
        $consulta = "SELECT COUNT(*) FROM `Parking 1` WHERE `state` LIKE '2'";
        $ejecutar = $conectar->prepare($consulta);
        $ejecutar->execute();
        $resultado = $ejecutar->fetch();
        $data["reservados"] = $resultado[0];
        echo json_encode($data);
      break;
      
     case 'GETNUMP2':
        $consulta = "SELECT COUNT(*) FROM `Parking 2` WHERE `state` LIKE '0'";
        $ejecutar = $conectar->prepare($consulta);
        $ejecutar->execute();
        $resultado = $ejecutar->fetch();
        $data["disponibles"] = $resultado[0];
        $consulta = "SELECT COUNT(*) FROM `Parking 2` WHERE `state` LIKE '1'";
        $ejecutar = $conectar->prepare($consulta);
        $ejecutar->execute();
        $resultado = $ejecutar->fetch();
        $data["ocupados"] = $resultado[0];
        $consulta = "SELECT COUNT(*) FROM `Parking 2` WHERE `state` LIKE '2'";
        $ejecutar = $conectar->prepare($consulta);
        $ejecutar->execute();
        $resultado = $ejecutar->fetch();
        $data["reservados"] = $resultado[0];
        echo json_encode($data);
      break;
      
      case 'UPDATEP1':
        $consulta = "UPDATE `Parking 1` SET `state` = '2', `user` = '{$body['usuario']}' WHERE `Parking 1`.`id` = {$body['id']};";
        $resultado = $conectar->prepare($consulta);
        $resultado->execute();
        $data["msg"] = "Parking reserved";
        echo json_encode($data);
      break;
      
      case 'UPDATEP2':
        $consulta = "UPDATE `Parking 2` SET `state` = '2', `user` = '{$body['usuario']}' WHERE `Parking 2`.`id` = {$body['id']};";
        $resultado = $conectar->prepare($consulta);
        $resultado->execute();
        $data["msg"] = "Parking reserved";
        echo json_encode($data);
      break;
      
      
      case 'RESERVA':
            $usuario = $body['usuario'];
            $consulta = "SELECT * FROM `Parking 1` WHERE `user` LIKE '{$usuario}'";
            $resultado = $conectar->prepare($consulta);
            $resultado->execute();
            
            if ($resultado->rowCount() >= 1) {
                $resultado2 = $resultado->fetch(PDO::FETCH_BOTH);
                $data["id"] = $resultado2[0] + 1;
                $data["ocupado"] = true;
                $data["nivel"] = 1;
              
            } else {
                $consulta = "SELECT * FROM `Parking 2` WHERE `user` LIKE '{$usuario}'";
                $resultado = $conectar->prepare($consulta);
                $resultado->execute();
                
                if ($resultado->rowCount() >= 1) {
                    $resultado2 = $resultado->fetch(PDO::FETCH_BOTH);
                    $data["id"] = $resultado2[0] + 1;
                    $data["ocupado"] = true;
                    $data["nivel"] = 2;
              
                } else {
                    $data["id"] = 0;
                    $data["ocupado"] = false;
                    $data["nivel"] = 0;
                }
            }
            echo json_encode($data);
          
        break;
        
        case 'GETTIME':
            $consulta = "SELECT * FROM `Tiempo` WHERE `id` = 0";
            $resultado = $conectar->prepare($consulta);
            $resultado->execute();
            $resultado2 = $resultado->fetchAll();
            $data["time"] = $resultado2[0]['time'];
            echo json_encode($data);
        
        break;
        case 'UPDATETIME':
            $consulta = "UPDATE `Tiempo` SET `time` = '{$body['time']}' WHERE `Tiempo`.`id` = 0;";
            $resultado = $conectar->prepare($consulta);
            $resultado->execute();
            $data["msg"] = "The time was updated";
            echo json_encode($data);
        break;
        
        case 'UPDATEP1_PROT':
            $consulta = "UPDATE `Parking 1` SET `state` = '{$body['estado']}', `user` = '' WHERE `Parking 1`.`id` = {$body['id']};";
            $resultado = $conectar->prepare($consulta);
            $resultado->execute();
            $data["msg"] = "Estado actualizado.";
            echo json_encode($data);
        break;
        
        case 'UPDATEP2_PROT':
            $consulta = "UPDATE `Parking 2` SET `state` = '{$body['estado']}', `user` = '' WHERE `Parking 2`.`id` = {$body['id']};";
            $resultado = $conectar->prepare($consulta);
            $resultado->execute();
            $data["msg"] = "Estado actualizado.";
            echo json_encode($data);
        break;
  } 
} else {
    $data = ['error' => 'No hay Methods'];
}




?>