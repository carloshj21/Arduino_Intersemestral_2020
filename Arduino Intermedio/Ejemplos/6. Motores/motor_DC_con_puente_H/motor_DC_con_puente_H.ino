int entrada1 = 7;
int entrada2 = 6;
int enable = 9;

void setup() {
  pinMode(entrada1,OUTPUT);
  pinMode(entrada2,OUTPUT);
  pinMode(enable,OUTPUT);

  digitalWrite(enable,HIGH);
}

void loop() {
  digitalWrite(entrada1,LOW);
  digitalWrite(entrada2,HIGH);
  delay(2000);
  digitalWrite(entrada1,HIGH);
  digitalWrite(entrada2,LOW);
  delay(2000);
}
