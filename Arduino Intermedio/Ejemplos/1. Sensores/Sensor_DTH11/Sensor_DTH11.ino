#include <DHT.h> // Incluimos biblioteca
#include <DHT_U.h>

#define DHTPIN 2  // Nombrando el pin

DHT dht(DHTPIN,DHT11);  // Inicializar sensor

void setup() {
  Serial.begin(9600);
  dht.begin();  // Inicializar comunicación con el sensor
}

void loop(){
  delay(5000); // Cada 5 segundos hace una lectura
  float humedad = dht.readHumidity();  // Leer datos de humedad
  float temperatura = dht.readTemperature();  // Leer datos de temperatura
  float farenheit = dht.readTemperature(true); // Leer temperatura en Farenheit

  if(isnan(humedad) || isnan(temperatura) || isnan(farenheit)){    // isnan: isn´t a number
    Serial.println("Error de lectura");
  }else{
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.print(" %\t");   // \t significa tabulación
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C\t");
    Serial.print(farenheit);
    Serial.println(" Farenheit");
  }
}

