int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;

#define TIEMPO 200

void ledWrite(int R16_9, int R8_1, int A16_9,int A8_1, int V16_9, int V8_1){
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
   pinMode(pinData, OUTPUT);
   pinMode(pinLatch, OUTPUT);
   pinMode(pinClock, OUTPUT);
}

void loop(){
  int h = 255;
  ledWrite(B00000000,B00000000,B00000000,B00000000,B11111111,B11111111); 
  delay(1000);
  ledWrite(B11111111,B11111111,B00000000,B00000000,B00000000,B00000000); 
  delay(1000);
  ledWrite(B00000000,B00000000,B11111111,B11111111,B00000000,B00000000); 
  delay(1000);
  
}