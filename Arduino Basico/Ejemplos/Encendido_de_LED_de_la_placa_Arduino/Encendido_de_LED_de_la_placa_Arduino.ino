int pin = 13;  // Creamos una variable para el pin del LED que se encuentra incluido en la placa Arduino
void setup() {
  Serial.begin(9600);  // Iniciamos comunicación serial a 9600 baudios
  pinMode(pin,OUTPUT);  // Configuramos pin del LED
}

void loop() {
  digitalWrite(pin,HIGH);  // Encendemos el LED
  delay(1000);   // Esperamos 1 segundo
  digitalWrite(pin,LOW);   // Apagamos el LED
  delay(1000);  // Esperamos 1 segundo
}
