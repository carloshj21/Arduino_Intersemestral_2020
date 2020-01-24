/*
    Realizado por: Hernández Juárez Carlos
    Tarea 1: Processing
    Arduino Avanzado
*/

import processing.serial.*;

Serial arduino;

void setup(){
  size(500,300);
  arduino = new Serial(this,"COM3",9600);
  
  background(245,243,141);
  
  // Título de la interfaz
  fill(255,0,0);
  noStroke();
  textSize(25);
  text("Control motor DC",140,50);
  
  // Botón de encendido
  fill(120);
  ellipse(60,100,40,40);
  fill(0);
  textSize(20);
  text("Encendido",100,107);
  
  // Botón de apagado
  fill(120);
  ellipse(300,100,40,40);
  fill(0);
  textSize(20);
  text("Apagado",340,107);
  
  // Botón de izquierda
  fill(15,84,101);
  rect(120,180,50,30);
  triangle(120,170,120,220,100,195);
  fill(0);
  textSize(20);
  text("Izquierda",90,250);
  
  // Botón de derecha
  fill(15,84,101);
  rect(310,180,50,30);
  triangle(360,170,360,220,380,195);
  fill(0);
  textSize(20);
  text("Derecha",310,250);
}

void draw(){

}

void mousePressed(){
  if(sobreEncendido()){
    fill(0,255,0);
    ellipse(60,100,40,40);
    fill(120);
    ellipse(300,100,40,40);
    arduino.write(1);
  }
  if(sobreApagado()){
    fill(120);
    ellipse(60,100,40,40);
    fill(255,0,0);
    ellipse(300,100,40,40);
    fill(15,84,101);
    rect(120,180,50,30);
    triangle(120,170,120,220,100,195);
    rect(310,180,50,30);
    triangle(360,170,360,220,380,195);
    arduino.write(2);
  }
  if(sobreIzquierda()){
    fill(15,84,101);
    rect(310,180,50,30);
    triangle(360,170,360,220,380,195);
    arduino.write(3);
  }
  if(sobreDerecha()){
    fill(15,84,101);
    rect(120,180,50,30);
    triangle(120,170,120,220,100,195);
    arduino.write(4);
  }
}

boolean sobreEncendido(){
  if(mouseX >= 40 && mouseX <= 80 && mouseY >= 80 && mouseY <= 120){
    fill(0,255,0);
    ellipse(60,100,40,40);
    return true;
  }
  else{
    return false;
  }
}

boolean sobreApagado(){
  if(mouseX >= 280 && mouseX <= 320 && mouseY >= 80 && mouseY <= 120){
    fill(255,0,0);
    ellipse(300,100,40,40);
    return true;
  }
  else{
    return false;
  }
}

boolean sobreIzquierda(){
  if(mouseX >= 100 && mouseX <= 170 && mouseY >= 170 && mouseY <= 220){
    fill(67,175,202);
    rect(120,180,50,30);
    triangle(120,170,120,220,100,195);
    return true;
  }
  else{
    return false;
  }
}

boolean sobreDerecha(){
  if(mouseX >= 310 && mouseX <= 380 && mouseY >= 170 && mouseY <= 220){
    fill(67,175,202);
    rect(310,180,50,30);
    triangle(360,170,360,220,380,195);
    return true;
  }
  else{
    return false;
  }
}
