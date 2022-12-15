int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
int entrada=11;
char *s;
int R16_9,  R8_1,  A16_9, A8_1,  V16_9,  V8_1 = 0;


#define TIEMPO 200
#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3
#define S5 A4
#define S6 A5
#define S7 A6
#define S8 A7
#define S9 A8
#define S10 A9
#define S11 A10
#define S12 A11
#define S13 A12
#define S14 A13
#define S15 A14
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
  pinMode(S9,INPUT);
  pinMode(S10,INPUT);
  pinMode(S11,INPUT);
  pinMode(S12,INPUT);
  pinMode(S13,INPUT);
  pinMode(S14,INPUT);
  pinMode(S15,INPUT);
  pinMode(S16,INPUT);

}

void loop(){
   if (Serial.available()>0){
    String option = Serial.readString();

    if (option != ""){
      s = strtok(option.c_str(), ",");
      V8_1 = atol(s); 
      //Serial.println(V8_1);
      s=strtok(NULL, ",");
      V16_9 = atol(s);
      //Serial.println(V16_9);

      s=strtok(NULL, ",");
      A8_1 = atol(s);
      //Serial.println(A8_1);
      s=strtok(NULL, ",");
      A16_9 = atol(s);
      //Serial.println(A16_9);

      s=strtok(NULL, ",");
      R8_1 = atol(s);
      //Serial.println(R8_1);
      s=strtok(NULL, ",");
      R16_9 = atol(s);
      //Serial.println(R16_9);
      
      ledWrite(); 
    }
  }
  sensor16_new = digitalRead(S16);
  if((sensor16_new != sensor16_old)){
    String a="UPDATEP2_PROT," + (String)sensor16_new +",7";
    Serial.println(a);
  }
}
