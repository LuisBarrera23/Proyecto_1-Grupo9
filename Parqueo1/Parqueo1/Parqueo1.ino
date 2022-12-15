int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
int entrada=11;
char *s;
int R16_9,  R8_1,  A16_9, A8_1,  V16_9,  V8_1 = 0;


#define TIEMPO 200
#define S16 A15


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

   pinMode(S16,INPUT);
}

void setup(){
   Serial.begin(9600);
   pinMode(entrada, INPUT);
   pinMode(pinData, OUTPUT);
   pinMode(pinLatch, OUTPUT);
   pinMode(pinClock, OUTPUT);
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
  if((sensor16_new =! sensor16_old)){
    Serial.println("{\"sensor\":16}");
    sensor16_old = sensor16_new;
  }
}
