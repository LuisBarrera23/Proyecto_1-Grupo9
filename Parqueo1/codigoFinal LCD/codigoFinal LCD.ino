#include <LiquidCrystal.h>

#define COLS 16 // Columnas del LCD
#define ROWS 2 // Filas del LCD
#define VELOCIDAD 100 // Velocidad a la que se mueve el texto

// Lo primero is inicializar la librería indicando los pins de la interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Textos

char *s;

String des="";
String ocp="";
String re="";

String datos="";


//Aquí creamos los nuevos caractere
  byte parte1[8] = { B01111, B10001, B10001, B10001, B10001, B10001, B11111, B11111 };
  byte parte2[8] = { B11100, B00011, B00001, B00001, B00001, B00001, B11111, B11111 };
  byte parte3[8] = { B00000, B00000, B00000, B00000, B00000, B11000, B11100, B11100 };
  byte parte4[8] = { B11111, B11111, B11111, B01001, B01001, B01001, B00110, B00000 };
  byte parte5[8] = { B11111, B11111, B11111, B11110, B00010, B00010, B00001, B00000 };
  byte parte6[8] = { B11111, B11111, B11111, B01000, B01000, B01000, B10000, B00000 };
   

  byte parte11[8] = { B01111, B10001, B10001, B10001, B10001, B10001, B11111, B11111 };
  byte parte22[8] = { B11100, B00011, B00001, B00001, B00001, B00001, B11111, B11111 };
  byte parte33[8] = { B00000, B00000, B00000, B00000, B00000, B11000, B11100, B11100 };
  byte parte44[8] = { B11111, B11111, B11111, B01001, B01001, B01001, B00110, B00000 };
  byte parte55[8] = { B11111, B11111, B11111, B11110, B00010, B00010, B00001, B00000 };
  byte parte66[8] = { B11111, B11111, B11111, B01000, B01000, B01000, B10000, B00000 };
  byte x1[8] ={ B10001, B01010, B00100, B01010, B10001, B00000, B00000, B00000 };




void setup() {
  Serial.begin(19200);
  // Configuramos las filas y las columnas del LCD en este caso 16 columnas y 2 filas
  lcd.begin(COLS, ROWS);
  
  //Creando nuevos caracteres
 // lcd.createChar(1, parte1);      
  //lcd.createChar(2, parte2);
  //lcd.createChar(3, parte3);      
  //lcd.createChar(4, parte4);
  //lcd.createChar(5, parte5);      
  //lcd.createChar(6, parte6);
  
  
 // lcd.createChar(7, parte11);      
 // lcd.createChar(8, parte22);
 // lcd.createChar(9, parte33);      
 // lcd.createChar(10, parte44);
 // lcd.createChar(11, parte55);      
 // lcd.createChar(12, parte66);
 // lcd.createChar(13, x1); 

  lcd.createChar(0, x1); 
  lcd.createChar(1, parte1);      
  lcd.createChar(2, parte2);
  lcd.createChar(3, parte3);      
  lcd.createChar(4, parte4);
  lcd.createChar(5, parte5);      
  lcd.createChar(6, parte6);
  lcd.createChar(7, x1);

  
}

void loop() {
 
  
  if (Serial.available()>0){
    String option = Serial.readString();
    s = strtok(option.c_str(), ",");   
    String movimiento = strtok(NULL, ",");
   
    /*if (option != "16,00,00"){
        digitalWrite(pinLed, HIGH);
        delay(2000);
    }*/
    re="";
    if (option != ""){
      s = strtok(NULL,",");
      des=s;

      s = strtok(NULL, ",");
      ocp=s;

      s = strtok(NULL, ",");
      re=s;
    }
       
  datos="";
  datos="Disp: "+des +"  Ocup: "+ocp+"  Reser: "+re;
  int tamano_texto=datos.length();
  for(int i=tamano_texto;i>0;i--){
    String texto=datos.substring(i-1);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(texto);
    delay(VELOCIDAD);
  }
  
  for(int i=1;i<=16;i++){
    lcd.clear();
    lcd.setCursor(i,0);
    lcd.print(datos);
    delay(VELOCIDAD);
  }

  
  for(int i=16;i>=1;i--){
    lcd.clear();
    lcd.setCursor(i,1);
    lcd.print(datos);
    delay(VELOCIDAD);
  }
  
  
  for(int i=1;i<=tamano_texto;i++){
    String texto=datos.substring(i-1);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(texto);
    delay(VELOCIDAD);
  }
  delay(100);
    if(movimiento!="FULL") {

      
   
    for(int i=1;i<=16;i++){
      lcd.clear();
      lcd.setCursor(i, 0);   
        lcd.write(byte(1));  

        lcd.setCursor(i+1, 0);   
        lcd.write(byte(2));

        lcd.setCursor(i+2, 0);   
        lcd.write(byte(3));

        lcd.setCursor(i, 1);   
        lcd.write(byte(4));

        lcd.setCursor(i+1, 1);   
        lcd.write(byte(5));

        lcd.setCursor(i+2, 1);   
        lcd.write(byte(6));

      delay(100);

    }
    }else{

       lcd.clear();
      lcd.setCursor(0, 0);   
        lcd.write(byte(0)); 
      lcd.setCursor(1, 0);   
        lcd.write(byte(1));  

        lcd.setCursor(2, 0);   
        lcd.write(byte(2));

        lcd.setCursor(3, 0);   
        lcd.write(byte(3));
//x        
        lcd.setCursor(4, 0);   
        lcd.write(byte(0));

  // pausa
        lcd.setCursor(0, 1);   
        lcd.write(byte(0));
        
        lcd.setCursor(1, 1);   
        lcd.write(byte(4));

        lcd.setCursor(2, 1);   
        lcd.write(byte(5));

        lcd.setCursor(3, 1);   
        lcd.write(byte(6));
        
        lcd.setCursor(4, 1);   
        lcd.write(byte(7));

      delay(1500);

    }

  }



    
  
  delay(95);

  
}