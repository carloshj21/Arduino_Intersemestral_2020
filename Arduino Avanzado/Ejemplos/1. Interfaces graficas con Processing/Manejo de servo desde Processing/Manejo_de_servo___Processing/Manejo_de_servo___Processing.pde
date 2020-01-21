import processing.serial.*;

Serial arduino;

int grados = 0;

void setup(){
  size(300,150);
  arduino = new Serial(this,"COM3",9600);
}

void draw(){
  background(0,0,250);
  
  // Título de la interfaz
  fill(239,173,49);
  noStroke();
  textSize(25);
  text("Posición del Servo:",40,50);
  
  // Rectángulo donde se muestran los grados
  fill(255);
  rect(110,85,80,30);
  
  // Botón de -
  fill(255,0,0);
  ellipse(60,100,40,40);
  fill(255);
  textSize(40);
  text("-",48,112);
  
  // Botón de +
  fill(0,255,0);
  ellipse(240,100,40,40);
  fill(0);
  textSize(40);
  text("+",225,112);
  
  // Texto que muestra los datos
  textSize(25);
  text(grados,130,110);
  
  arduino.write(grados);
  // Prueba
  
  /*if(sobreMenos()){
    fill(250,140,0);
    ellipse(60,100,40,40);
    grados++;
  }
  
  if(sobreMas() && mousePressed){
    fill(0,255,140);
    ellipse(240,100,40,40);
    grados++;
  }*/
}

void mouseClicked(){
  if(sobreMenos() && grados > 0){
    grados--;
  }
  if(sobreMas() && grados < 180){
    grados++;
  }
}

void mouseWheel(MouseEvent evento){
  println(evento.getCount());  // Método que me dice si me estoy desplazando para arriba o hacia abajo
  if(grados > 0 && grados < 180){
    grados = grados - evento.getCount();
  }
}

boolean sobreMenos(){
  if(mouseX >= 40 && mouseX <= 80 && mouseY >= 80 && mouseY <= 120){
    return true;
  }
  else{
    return false;
  }
}

boolean sobreMas(){
  if(mouseX >= 220 && mouseX <= 260 && mouseY >= 80 && mouseY <= 120){
    return true;
  }
  else{
    return false;
  }
}
