int herradura = 8;
int led = 9;

void setup() {
  pinMode(herradura,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  if(digitalRead(herradura) == HIGH)
  {
    digitalWrite(led,LOW);
  }
  else
  {
    digitalWrite(led,HIGH);
  }
}
