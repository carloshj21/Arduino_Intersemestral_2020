void setup(){
  size(500,500);
  background(255);
}

void draw(){
  fill(255,0,0);
  noStroke();
  rect(200,200,100,100);
  
  if(mouseX >= 200 && mouseX <= 300 && mouseY >= 200 && mouseY <= 300){
    fill(0,255,0);
    rect(200,200,100,100);
  }
}
