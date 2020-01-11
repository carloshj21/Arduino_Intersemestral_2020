int led = 6;
int ldr = A5;
int lectura;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(ldr);
  lectura = constrain(lectura,220,785);  // Este constrain es necesario para definir el rango del LED, sino el LED prende de más cuando debería estar casi apagado.
  lectura = map(lectura,220,785,0,255);
  lectura = 255 - lectura;
  analogWrite(led,lectura);
}
