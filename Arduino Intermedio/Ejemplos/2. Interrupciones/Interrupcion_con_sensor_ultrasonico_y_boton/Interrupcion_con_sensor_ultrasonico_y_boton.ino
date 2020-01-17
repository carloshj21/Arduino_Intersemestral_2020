#define trig 8
#define echo 9

int contador = 0;

long distancia;
long tiempo;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3),modContador,FALLING);  // Para hacer la interrupción
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(3,INPUT_PULLUP);
}

void loop() {

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
  Serial.print("\nDistancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  Serial.print("Contador: ");
  Serial.println(contador);

  delay(500);
}

void modContador(){
  if(distancia <= 30){
    contador = contador + 1;
  }else{
    contador = contador - 1;
  }
}
