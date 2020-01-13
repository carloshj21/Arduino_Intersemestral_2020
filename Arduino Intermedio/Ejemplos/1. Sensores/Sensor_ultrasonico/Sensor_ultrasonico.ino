// Se nombran los pines
int trig = 8;
int echo = 9;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
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
  delay(500);
}
