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

  Serial.print("Contador: ");
  Serial.println(contador);
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
  delay(500);
}


/*  *********************************************************************************************************************************
 
Observación:  Creo que debido al rebote de los botones del que se nos habló en clase, el contador aumenta, aveces, más de una ocasión. 

************************************************************************************************************************************** */
void modContador(){
  if(distancia <= 30){
    contador = contador + 1;
    
    Serial.print("\nDistancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
    Serial.print("Contador: ");
    Serial.println(contador);
  }else{
    contador = contador - 1;
    Serial.print("\nDistancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
    Serial.print("Contador: ");
    Serial.println(contador);
  }
}
