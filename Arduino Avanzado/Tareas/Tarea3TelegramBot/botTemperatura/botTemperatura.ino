#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2

DHT dht(DHTPIN,DHT11); 

byte temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
    delay(5000);
    float temperatura = dht.readTemperature();
  
    if(isnan(temperatura)){
      Serial.write("Error de lectura");
    }else{
      temp = byte(temperatura);
      Serial.println(temperatura);
      Serial.println(temp);
    }
}
