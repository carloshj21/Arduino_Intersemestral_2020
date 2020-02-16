#define pot A0
int lectura;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(pot);
  Serial.println(lectura);
}
