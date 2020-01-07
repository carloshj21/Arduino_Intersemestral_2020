int pin = 13;  // Creamos una variable para el pin del LED que se encuentra incluido en la placa Arduino
char dato;  // Variable para recibir dato del monitor serie

void setup() {
  Serial.begin(9600);  // Iniciamos comunicación serial a 9600 baudios
  pinMode(pin,OUTPUT);  // Configuramos pin del LED
}

void loop() {
  // Encendemos el LED
  digitalWrite(pin,HIGH);
  Serial.println("LED encendido");
  delay(1000);   // Esperamos 1 segundo

  // Apagamos el LED
  digitalWrite(pin,LOW);   
  Serial.println("LED apagado");
  delay(1000);  // Esperamos 1 segundo
}
