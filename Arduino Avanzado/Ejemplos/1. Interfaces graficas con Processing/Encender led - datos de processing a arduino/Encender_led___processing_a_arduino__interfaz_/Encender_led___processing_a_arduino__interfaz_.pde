import processing.serial.*;

Serial arduino;

void setup(){
  size(400,400);
  arduino = new Serial(this,"COM3",9600);
}

void draw(){
  background(250);
  
  if(sobreCuadrado()){
    fill(200);
    arduino.write('h');
  }
  else{
    fill(0);
    arduino.write('l');
  }
  
  rect(150,150,100,100);
}

boolean sobreCuadrado(){
  if(mouseX >= 150 && mouseX <= 250 && mouseY >= 150 && mouseY <= 250){
    return true;
  }
  else{
    return false;
  }
}
