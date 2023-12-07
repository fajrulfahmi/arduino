#include <Servo.h>

#define s1 3
#define s2 4
#define bVerUp 5
#define bVerDown 6

Servo servo1;
Servo servo2;

int derejatServo1, derajatServo2 = 30;

void setup() {
  Serial.begin(9600);
  servo1.attach(s1);
  servo2.attach(s2);
  pinMode(bVerUp, INPUT_PULLUP);
  pinMode(bVerDown, INPUT_PULLUP);
}

void loop() {
  int vButtonUp = digitalRead(bVerUp);
  int vButtonDown = digitalRead(bVerDown);

  Serial.println("Button Up : " + (String)vButtonUp);
  Serial.println("Button Down : " + (String)vButtonDown);

  if (vButtonUp == 0) {
    derajatServo2++;
  } else if (vButtonDown == 0) {
    derajatServo2--;
  }
  servo2.write(derajatServo2);

  Serial.println(derajatServo2);
}
