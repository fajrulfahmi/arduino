#include <NewPing.h>

//ULTRA
#define trig      8
#define echo      9
#define maksimal  200

//pengenalan jarak
NewPing jarak(trig, echo, maksimal);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Ping");
  Serial.print(jarak.ping_cm());
  Serial.println("cm");
  delay(1000);

}
