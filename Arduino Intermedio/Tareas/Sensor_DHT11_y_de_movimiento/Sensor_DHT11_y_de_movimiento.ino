/*
    Realizado por: Hernández Juárez Carlos
    Tarea 1: Sensor DHT11 y sensor de movimeinto PIR

    Arduino Intermedio

*/

#include <DHT.h> // Incluimos biblioteca
#include <DHT_U.h>

//Declaración de pines
#define DHTPIN 2
#define sensor 3

int valor;

DHT dht(DHTPIN,DHT11);

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  dht.begin();
}

//Función para desplegar humedad y temperatura
void tempeHumedad(){
  float humedad = dht.readHumidity();  // Leer datos de humedad
  float temperatura = dht.readTemperature();  // Leer datos de temperatura

  if(isnan(humedad) || isnan(temperatura)){
    Serial.println("Error de lectura");
  }else{
    //Se imprimen los valores de humedad y temperatura
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C\t");
  }
}

void loop() {
  
  valor = digitalRead(sensor);  // Se guarda el estado del sensor de movimiento

  if(valor == HIGH){  // Si el sensor detecta movimiento, se realiza el despliegue de la humedad y temperatura
    tempeHumedad();
  }
  delay(1000);
}
