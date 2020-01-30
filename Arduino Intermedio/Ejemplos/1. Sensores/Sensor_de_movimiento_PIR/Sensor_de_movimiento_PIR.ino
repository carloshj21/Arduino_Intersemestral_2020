int alarma = 3;
int sensor = 2;

int valor;  // Guardar si está activado el sensor

void setup() {
  pinMode(alarma,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  valor = digitalRead(sensor);
  Serial.print("Sensor: ");
  Serial.println(valor);
  
  if(valor == HIGH){
    digitalWrite(alarma,HIGH);
    delay(2000);
    digitalWrite(alarma,LOW);
  }else{
    digitalWrite(alarma,LOW);
  }

  delay(50);
}
