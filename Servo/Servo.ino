#include <Servo.h>

#define servo 3
Servo myServo;
#define led 13

void setup() {
  myServo.attach(servo);
  pinMode(led,OUTPUT);
}

void loop() {
  myServo.write(0);
  digitalWrite(led, LOW);
  delay(1000);
  myServo.write(90);
  digitalWrite(led,HIGH);
  delay(2500);
  myServo.write(180);
  digitalWrite(led, LOW);
  delay(1000);
  myServo.write(90);
  digitalWrite(led, HIGH);
  delay(2500);



}
