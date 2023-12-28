#include <NewPing.h>
#include <Servo.h>

#define trig      12
#define echo      11
#define maksimal  200

//SERVO
#define servo 7

NewPing jarak(trig, echo, maksimal);

//PENGENALAN SERVO
Servo myservo;

void setup() {
  Serial.begin(9600);

  //SERVO
  myservo.attach(servo);
  
}

void loop() {
  Serial.print("Ping : ");
  Serial.print (jarak.ping_cm());
  Serial.println("cm");

  if(jarak.ping_cm() > 0){
    if(jarak.ping_cm() < 15){
      Serial.println("JARAK DEKAT");
      Serial.println("SERVO : 135");
      myservo.write(135);
    }else{
      Serial.println("JARAK JAUH");
      Serial.println("SERVO : 90");
      myservo.write(90);
    }
  }
}
