import processing.serial.*;

Serial arduino;
int lectura;

void setup(){
  size(200,200);
  println(Serial.list());  // Muestra todos los puertos en donde está conectado algo
  frameRate(60);
  // Opciones para el puerto de arduino
  arduino = new Serial(this,"COM3",9600);
  //arduino = new Serial(this,Serial,list[0]);  // Si solo se tiene una cosa conectada
}

void draw(){
  if(arduino.available() > 0){
    lectura = arduino.read();
  }
  background(250);
  if(lectura == 0){
    fill(0);
  }
  else{
    fill(0,255,0);
  }
  rect(50,50,100,100);
}
