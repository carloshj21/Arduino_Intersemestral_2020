#define trig 8
#define echo 9

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  long distancia;
  long tiempo;

  digitalWrite(trig,LOW);
  delayMicroseconds(4);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  tiempo = pulseIn(echo,HIGH);
  tiempo = tiempo/2;
  distancia = tiempo / 29.2;

  if(distancia <= 10){
    Serial.write('H');
  }
}
