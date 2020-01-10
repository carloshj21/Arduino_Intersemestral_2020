int buzzer = 13;
int i;

void setup() {
  pinMode(buzzer,OUTPUT);
}

void loop() {
  for(i=34;i<20000;i++)
  {
    tone(buzzer,i);
    delay(200);
  }
}
