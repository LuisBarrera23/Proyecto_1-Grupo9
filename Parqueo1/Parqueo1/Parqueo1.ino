int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
int entrada=11;
char *s;
int R16_9,  R8_1,  A16_9, A8_1,  V16_9,  V8_1 = 0;


#define TIEMPO 200
int inicio = 1;

//LED 1 al 8
int LED1 = 0;
int LED2 = 0;
int LED3 = 0;
int LED4 = 0;
int LED5 = 0;
int LED6 = 0;
int LED7 = 0;
int LED8 = 0;
int LED9 = 0;
int LED10 = 0;

#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3
#define S5 A4
#define S6 A5
#define S7 A6
#define S8 A7



#define S16 A15

boolean sensor1_old = LOW;
boolean sensor1_new;
boolean sensor2_old = LOW;
boolean sensor2_new;
boolean sensor3_old = LOW;
boolean sensor3_new;
boolean sensor4_old = LOW;
boolean sensor4_new;
boolean sensor5_old = LOW;
boolean sensor5_new;
boolean sensor6_old = LOW;
boolean sensor6_new;
boolean sensor7_old = LOW;
boolean sensor7_new;
boolean sensor8_old = LOW;
boolean sensor8_new;
boolean sensor9_old = LOW;
boolean sensor9_new;
boolean sensor10_old = LOW;
boolean sensor10_new;
boolean sensor11_old = LOW;
boolean sensor11_new;
boolean sensor12_old = LOW;
boolean sensor12_new;
boolean sensor13_old = LOW;
boolean sensor13_new;
boolean sensor14_old = LOW;
boolean sensor14_new;
boolean sensor15_old = LOW;
boolean sensor15_new;
boolean sensor16_old = LOW;
boolean sensor16_new;

void ledWrite(){
   shiftOut(pinData, pinClock, LSBFIRST, V8_1);
   shiftOut(pinData, pinClock, LSBFIRST, V16_9);
   shiftOut(pinData, pinClock, LSBFIRST, A8_1);
   shiftOut(pinData, pinClock, LSBFIRST, A16_9);
   shiftOut(pinData, pinClock, LSBFIRST, R8_1);
   shiftOut(pinData, pinClock, LSBFIRST, R16_9);
   digitalWrite(pinLatch, HIGH);
   digitalWrite(pinLatch, LOW);

   
}


void ledPrint(){
  V8_1 = 0;
  R8_1 = 0;
  A8_1 = 0;
  
  //LED 1
  if(LED1 == 0){
      V8_1 = V8_1 + 1;
    
  }else if(LED1 == 1){
      R8_1 = R8_1 + 1;
      
  }else if(LED1 == 2){
      A8_1 = A8_1 + 1;      
  }

  //LED 2
  if(LED2 == 0){
      V8_1 = V8_1 + 2;
    
  }else if(LED2 == 1){
      R8_1 = R8_1 + 2;
      
  }else if(LED2 == 2){
      A8_1 = A8_1 + 2;      
  }

  //LED 3
  if(LED3 == 0){
      V8_1 = V8_1 + 4;
    
  }else if(LED3 == 1){
      R8_1 = R8_1 + 4;
      
  }else if(LED3 == 2){
      A8_1 = A8_1 + 4;      
  }

  //LED 4
  if(LED4 == 0){
      V8_1 = V8_1 + 8;
    
  }else if(LED4 == 1){
      R8_1 = R8_1 + 8;
      
  }else if(LED4 == 2){
      A8_1 = A8_1 + 8;      
  }


  //LED 5
  if(LED5 == 0){
      V8_1 = V8_1 + 16;
    
  }else if(LED5 == 1){
      R8_1 = R8_1 + 16;
      
  }else if(LED5 == 2){
      A8_1 = A8_1 + 16;      
  }


  //LED 6
  if(LED6 == 0){
      V8_1 = V8_1 + 32;
    
  }else if(LED6 == 1){
      R8_1 = R8_1 + 32;
      
  }else if(LED6 == 2){
      A8_1 = A8_1 + 32;      
  }

  //LED 7
  if(LED7 == 0){
      V8_1 = V8_1 + 64;
    
  }else if(LED7 == 1){
      R8_1 = R8_1 + 64;
      
  }else if(LED7 == 2){
      A8_1 = A8_1 + 64;      
  }


  //LED 8
  if(LED8 == 0){
      V8_1 = V8_1 + 128;
    
  }else if(LED8 == 1){
      R8_1 = R8_1 + 128;
      
  }else if(LED8 == 2){
      A8_1 = A8_1+128;
  }

  


  
  
  ledWrite();
  
  
  
  
}

void setup(){
  Serial.begin(9600);
  pinMode(entrada, INPUT);
  pinMode(pinData, OUTPUT);
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);
  
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(S4,INPUT);
  pinMode(S5,INPUT);
  pinMode(S6,INPUT);
  pinMode(S7,INPUT);
  pinMode(S8,INPUT);
  
  pinMode(S16,INPUT);

}

void loop(){
  if (inicio == 1){
    ledPrint();
    inicio = 2;
  }

  if (Serial.available()>0){
    String option = Serial.readString();
    
    if (option != ""){
      int longitud = option.length() - (0.5 *option.length() - 0.5 );
      s = strtok(option.c_str(), ",");
      
      for(int i = 0; i<longitud; i++){        
        if(String(s) == "A"){
            s=strtok(NULL, ",");
            LED1 = atol(s);          
        } 
        if(String(s) == "B"){
            s=strtok(NULL, ",");
            LED2 = atol(s);          
        }
        if(String(s) == "C"){
            s=strtok(NULL, ",");
            LED3 = atol(s);          
        }
        if(String(s) == "D"){
            s=strtok(NULL, ",");
            LED4 = atol(s);          
        }
        if(String(s) == "E"){
            s=strtok(NULL, ",");
            LED5 = atol(s);          
        }
        if(String(s) == "F"){
            s=strtok(NULL, ",");
            LED6 = atol(s);          
        }
        if(String(s) == "G"){
            s=strtok(NULL, ",");
            LED7 = atol(s);          
        }
        if(String(s) == "H"){
            s=strtok(NULL, ",");
            LED8 = atol(s);          
        }
        if(String(s) == "I"){
            s=strtok(NULL, ",");
            LED9 = atol(s);          
        }
        if(String(s) == "J"){
            s=strtok(NULL, ",");
            LED10 = atol(s);          
        } 
        s=strtok(NULL, ",");
      }
      ledPrint(); 
    }
  }

  //LED 1
  sensor1_new = digitalRead(S1);
  if((sensor1_new != sensor1_old)){
    
    LED1 = sensor1_new;
    ledPrint();
    sensor1_old = sensor1_new;

    String a="UPDATEP1_PROT," + (String)sensor1_new +",0";
    Serial.println(a);
  }


  //LED 2
  sensor2_new = digitalRead(S2);
  if((sensor2_new != sensor2_old)){
    
    LED2 = sensor2_new;
    ledPrint();
    sensor2_old = sensor2_new;

    String a="UPDATEP1_PROT," + (String)sensor2_new +",1";
    Serial.println(a);
  }

  //LED 3
  sensor3_new = digitalRead(S3);
  if((sensor3_new != sensor3_old)){
    
    LED3 = sensor3_new;
    ledPrint();
    sensor3_old = sensor3_new;

    String a="UPDATEP1_PROT," + (String)sensor3_new +",2";
    Serial.println(a);
  }

  //LED 4
  sensor4_new = digitalRead(S4);
  if((sensor4_new != sensor4_old)){
    
    LED4 = sensor4_new;
    ledPrint();
    sensor4_old = sensor4_new;

    String a="UPDATEP1_PROT," + (String)sensor4_new +",3";
    Serial.println(a);
  }

  //LED 5
  sensor5_new = digitalRead(S5);
  if((sensor5_new != sensor5_old)){
    
    LED5 = sensor5_new;
    ledPrint();
    sensor5_old = sensor5_new;

    String a="UPDATEP1_PROT," + (String)sensor5_new +",4";
    Serial.println(a);
  }

  //LED 6
  sensor6_new = digitalRead(S6);
  if((sensor6_new != sensor6_old)){
    
    LED6 = sensor6_new;
    ledPrint();
    sensor6_old = sensor6_new;

    String a="UPDATEP1_PROT," + (String)sensor6_new +",5";
    Serial.println(a);
  }

  //LED 7
  sensor7_new = digitalRead(S7);
  if((sensor7_new != sensor7_old)){
    
    LED7 = sensor7_new;
    ledPrint();
    sensor7_old = sensor7_new;

    String a="UPDATEP1_PROT," + (String)sensor7_new +",6";
    Serial.println(a);
  }

  //LED 8
  sensor8_new = digitalRead(S8);
  if((sensor8_new != sensor8_old)){
    
    LED8 = sensor8_new;
    ledPrint();
    sensor8_old = sensor8_new;

    String a="UPDATEP1_PROT," + (String)sensor8_new +",7";
    Serial.println(a);
  }

  
  
}
