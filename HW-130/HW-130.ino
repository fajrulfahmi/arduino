#include <AFMotor.h>

AF_DCMotor M1(1);
AF_DCMotor M2(2);
 
void setup() {
  M1.setSpeed(150);
  M2.setSpeed(150);
}
 
void loop() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  delay(2000);
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  delay(2000);
  M1.run(RELEASE);
  M2.run(RELEASE);
  delay(500);
}