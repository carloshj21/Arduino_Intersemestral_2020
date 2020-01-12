int herradura = 4;
int led = 3;

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
