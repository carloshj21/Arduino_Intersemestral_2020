// Se nombran los pines
int trig = 8;
int echo = 9;

int buzzer = 7;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  long distancia;
  long tiempo;
  
  // Para activar el sensor
  digitalWrite(trig,LOW);
  delayMicroseconds(4);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  // Operaciones
  tiempo = pulseIn(echo,HIGH);  // Para recibir la información del sensor
  tiempo = tiempo/2;
  distancia = tiempo/29.2;
  Serial.print(distancia);
  Serial.println(" cm");
  
  if(distancia <= 10){
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
  }
  delay(500);
}
