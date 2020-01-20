void setup(){
  // ESta función se ejecuta una sola vez
  size(500,200);
  //background(0,0,127); // Azul en formato RGB
  background(255);
}

void draw(){
  // Esta función se ejecuta en loop
  
  background(255);
  // RGB fill(rojo,verde,azul);
  fill(255,0,0);  // Color de relleno
  stroke(0,0,255);  // Color de contorno o delineado
  rect(250,100,50,50);
  
  fill(255,255,0);
  stroke(255);
  
  // mouseX: posición en 'x' del ratón
  // mouse Y: posición en 'y' del ratón
  ellipse(mouseX,mouseY,50,50);
  
  fill(50);
  noStroke();
  textSize(25);
  text("Hola Mundo",200,80);
  
  if(mousePressed){
    fill(0,255,0);
    rect(250,100,50,50);
  }
}
