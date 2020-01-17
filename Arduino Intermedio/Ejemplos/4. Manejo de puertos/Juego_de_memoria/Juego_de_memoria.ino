
byte valorReg;

byte leds [4] = {1,2,4,8};//LEDS individuales
byte secuencia[9];
byte respuesta[9];

byte boton = 0;
int i;
int nivel=0;

boolean juego = false;


void inicioJuego(){
  if(juego == false){
    juego = !juego;
  }
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),inicioJuego,RISING);

  //Configuramos puertos
  //0-Entrada 1-Salida
  //En puerto B estaran los LED's
  //(13-8) 
  
  DDRB = B11111111;

  //En puerto C estaran los botones
  //(A5-A0);
  
  DDRC = B11110000;
  
}

void loop() {
  if(juego){
    //creamos secuencia
    for(i = 0; i<9 ; i++){
      secuencia[i] = leds[random(0,4)];
      if(i > 0){
        while(secuencia[i]  == secuencia[i-1]){
          secuencia[i] = leds[random(0,4)];
        }
      }
      
    }

    while(juego){
      for(i =0 ; i<=nivel ; i++){
        PORTB = secuencia[i];
        delay(1000);
        PORTB = 0;
      }
      

      for(i =0 ; i<=nivel ; i++){
        while(boton == 0 ){
          boton = PINC;
        }
        respuesta[i] = boton;
        boton = 0;
        delay(200);
        if(respuesta[i] != secuencia[i] ){
          juego = false;
          nivel = 0;
          break;
        }
      }

      if(juego && nivel != 8){
        nivel++;
      }else{
        nivel=0;
        juego = false;
      }
    } 
  }
}
