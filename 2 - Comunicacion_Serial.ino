int pin = 13;  // Creamos una variable para el pin del LED que se encuentra incluido en la placa Arduino
char dato;  // Variable para recibir dato del monitor serie

void setup() {
  Serial.begin(9600);  // Iniciamos comunicación serial a 9600 baudios
  pinMode(pin,OUTPUT);  // Configuramos pin del LED
}

void loop() {
  if(Serial.available() != 0)   // Verificamos si está disponible la comuicación serie
  {
    dato = Serial.read();
    if(dato == 'a' || dato == 'A')  // Comprobamos si se cumple la condición
    {
      digitalWrite(pin,HIGH);   // Se enciende el LED
      Serial.println("LED encendido");  //Mandamos un mensaje al monitor serie de que el LED se encendió
    }
    if(dato == 'b' || dato == 'B')  // Comprobamos si se cumple la condición
    {
      digitalWrite(pin,LOW);  // Se apaga el LED
      Serial.println("LED apagado");  //Mandamos un mensaje al monitor serie de que el LED se apagó
    }
  }
  
  /*
  // Encendemos el LED
  digitalWrite(pin,HIGH);
  Serial.println("LED encendido");
  delay(1000);   // Esperamos 1 segundo

  // Apagamos el LED
  digitalWrite(pin,LOW);   
  Serial.println("LED apagado");
  delay(1000);  // Esperamos 1 segundo
  */
}
