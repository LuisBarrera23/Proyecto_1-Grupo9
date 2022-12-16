#define ZERO 11
#define NINETY 10
#define OPEN 9
#define CLOSE 8

#define ZERO1 7
#define NINETY1 6
#define OPEN1 5
#define CLOSE1 4

char entrada;
int state = 0;
int state1 = 0;

void setup() {
  pinMode(ZERO, OUTPUT);
  pinMode(NINETY, OUTPUT);
  pinMode(OPEN, INPUT);
  pinMode(CLOSE, INPUT);

  pinMode(ZERO1, OUTPUT);
  pinMode(NINETY1, OUTPUT);
  pinMode(OPEN1, INPUT);
  pinMode(CLOSE1, INPUT);

  digitalWrite(ZERO, HIGH);
  digitalWrite(NINETY, LOW);
  digitalWrite(ZERO1, HIGH);
  digitalWrite(NINETY1, LOW);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    entrada = Serial.read();

    if (entrada == 'E') {
      digitalWrite(ZERO, LOW);
      digitalWrite(NINETY, HIGH);
      state = 1;
    }

    if (entrada == 'S') {
      digitalWrite(ZERO1, LOW);
      digitalWrite(NINETY1, HIGH);
      state1 = 1;
    }
  } else {
    if (digitalRead(OPEN) == HIGH) {
      // ABRIENDO TALANQUERA POR MEDIO DEL BOTÓN
      digitalWrite(ZERO, LOW);
      digitalWrite(NINETY, HIGH);
      state = 1;
    }
    if (digitalRead(OPEN1) == HIGH) {
      // ABRIENDO TALANQUERA POR MEDIO DEL BOTÓN
      digitalWrite(ZERO1, LOW);
      digitalWrite(NINETY1, HIGH);
      state1 = 1;
    }
  }

  if (state == 1 && digitalRead(CLOSE) == LOW) {
    // CERRANDO TALANQUERA CUANDO EL SENSOR SE ALEJA
    digitalWrite(ZERO, HIGH);
    digitalWrite(NINETY, LOW);
    state = 0;
  }
  if (state1 == 1 && digitalRead(CLOSE1) == LOW) {
    // CERRANDO TALANQUERA CUANDO EL SENSOR SE ALEJA
    digitalWrite(ZERO1, HIGH);
    digitalWrite(NINETY1, LOW);
    state1 = 0;
  }
}