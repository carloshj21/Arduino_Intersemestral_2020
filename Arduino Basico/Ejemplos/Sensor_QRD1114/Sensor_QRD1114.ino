int qrd = 2;  // Lectura digital
int led = 3;  // Salida digital
void setup() {
  pinMode(qrd,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(qrd) == LOW){
    digitalWrite(led,LOW);
    Serial.println("BAJO");
  }else{
    digitalWrite(led,HIGH);
    Serial.println("ALTO");
  }
}
