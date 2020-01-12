int qrd = A0;  // Lectura digital
int buzzer = 6;  // Salida digital
int pot = A5;  // Con potenciómetro
//int ldr = A5;   // Con fotorresistencia
int lectura;
int volumen;

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(qrd);
  lectura = map(lectura,60,498,50,500);

  volumen = analogRead(pot);
  volumen = map(volumen,0,1023,0,255);  // Con potenciómetro
  //volumen = map(volumen,380,790,0,255);  // Con fotorresistencia

  // Producimos el tono
  analogWrite(buzzer,volumen);
  delayMicroseconds(lectura);
  digitalWrite(buzzer,LOW);
  delayMicroseconds(lectura);
}
