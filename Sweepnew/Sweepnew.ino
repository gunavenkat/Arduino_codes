

#include <Servo.h>

Servo myservo;  
int pos = 45;   

void setup() {
  myservo.attach(9); 
}

void loop() {
 myservo.write(145);
 delay(500);
myservo.write(40);
 delay(500);
}
