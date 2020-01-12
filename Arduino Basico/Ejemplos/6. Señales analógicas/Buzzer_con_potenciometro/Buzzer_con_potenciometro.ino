int buzzer = 13;
int i;
int pot = A0;
int frec;

void setup() {
  pinMode(buzzer,OUTPUT);
}

void loop() {
  frec = analogRead(pot);
  frec = map(frec,0,1023,1000,10000);
  tone(buzzer,frec);
}
