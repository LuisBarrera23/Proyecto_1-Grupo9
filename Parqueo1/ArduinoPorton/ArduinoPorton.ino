#define ZERO 11
#define NINETY 10
#define OPEN 9
#define CLOSE 8

int state = 0;

void setup(){
  pinMode(ZERO, OUTPUT);
  pinMode(NINETY, OUTPUT);
  pinMode(OPEN, INPUT);
  pinMode(CLOSE, INPUT);

  digitalWrite(ZERO, HIGH);
  digitalWrite(NINETY, LOW);
}

void loop(){
  switch(state){
    case 0:
      if(digitalRead(OPEN) == HIGH){
        // ABRIENDO TALANQUERA POR MEDIO DEL BOTÓN
        digitalWrite(ZERO, LOW);
        digitalWrite(NINETY, HIGH);
        state = 1;
      }
      break;
    case 1:
      if(digitalRead(CLOSE) == LOW){
        // CERRANDO TALANQUERA CUANDO EL SENSOR SE ALEJA
        digitalWrite(ZERO, HIGH);
        digitalWrite(NINETY, LOW);
        state = 0;
      }
      break;
  }
}
/*
#include <Stepper.h>

  
Stepper Entrada(40,8,9,10,11);
char entrada; 
 
void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  Entrada.setSpeed(100);
}
 
void loop() {  

  if (Serial.available()>0){
    entrada=Serial.read();
    

    if(entrada=='E') { 
      digitalWrite(13,1);
      // Entrada.step(90);
      // delay(1000); 
      // Entrada.step(-90);
    }
    
    if(entrada=='S') { 
      digitalWrite(13,0);
      // myStepper2.step(50);
      // delay(1000); 
      // myStepper2.step(-50);
    }
  }

}
*/
