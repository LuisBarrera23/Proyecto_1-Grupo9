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
    

    if(entrada=='A') { 
      digitalWrite(13,1);
      // Entrada.step(90);
      // delay(1000); 
      // Entrada.step(-90);
    }
    
    if(entrada=='B') { 
      digitalWrite(13,0);
      // myStepper2.step(50);
      // delay(1000); 
      // myStepper2.step(-50);
    }
  }

}
