int led;

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  for(led=8;led<=10;led++)
  {
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
  }
  for(led=9;led>8;led--)
  {
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
  }
}
