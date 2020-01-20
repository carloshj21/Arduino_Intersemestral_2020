import processing.serial.*;

Serial arduino;

int grados = 180;

void setup(){
  size(300,150);
  arduino = new Serial(this,"COM3",9600);
}

void draw(){
  background(0,0,250);
  
  fill(239,173,49);
  noStroke();
  textSize(25);
  text("Posición del Servo:",40,50);
  
  fill(255);
  noStroke();
  rect(110,85,80,30);
  
  fill(255,0,0);
  noStroke();
  ellipse(60,100,40,40);
  
  fill(255);
  noStroke();
  textSize(40);
  text("-",48,112);
  
  fill(0,255,0);
  noStroke();
  ellipse(240,100,40,40);
  
  fill(0);
  noStroke();
  textSize(40);
  text("+",225,112);
  
  fill(0);
  noStroke();
  textSize(25);
  text(grados,130,110);
  
  if(encimaBoton() && mousePressed){
    fill(0);
    ellipse(60,100,40,40);
  }
}

boolean encimaBoton(){
  if(mouseX >= 60 && mouseX <= 100 && mouseY >= 100 && mouseY <= 140){
    println("Estás dentro");
    return true;
  }
  else{
    return false;
  }
}
