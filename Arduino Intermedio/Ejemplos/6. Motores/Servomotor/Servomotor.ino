#include <Servo.h>

// Declaro mi objeto para servo
Servo miServo;
int i;

void setup() {
  miServo.attach(7);
}

void loop() {
  for(i=0;i<=180;i++){
    miServo.write(i);
    delay(10);
  }

  for(i=180;i>=0;i--){
    miServo.write(i);
    delay(10);
  }
}
