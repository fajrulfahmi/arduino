#include <NewPing.h>  //library sensor ultrasonik
#include <Servo.h>  //library servo

#define servo     7  //pin servo
#define trig      12  //pin trig ultrasonik
#define echo      11  //pin echo ultrasonik
#define maksimal  180 //maksimal jarak ultrasonik

Servo myservo;  //membuat variabel myservo

NewPing jarak(trig, echo, maksimal);  //membuat variabel jarak

int point;

void setup() {
  Serial.begin(9600);
  myservo.attach(servo); //memanggil variabel servo
}

void loop() {
//  Serial.print("Ping");
//  Serial.print(jarak.ping_cm());  // menampilkan jarak
//  Serial.println("cm");

  point = jarak.ping_cm();
  point = map(point, 0, 30, 0, 180);
  Serial.print("POINT = ");
  Serial.println(point);
  myservo.write(point); // servo bergerak sesuai jarak
  delay(300);
}
