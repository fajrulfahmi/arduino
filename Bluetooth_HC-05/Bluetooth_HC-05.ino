#include <SoftwareSerial.h>
SoftwareSerial myBT(11, 12);

void setup() {
  Serial.begin(9600);
  myBT.begin(9600);
  Serial.println("START");
}

void loop() {
  //read myBT Serial     >> Recv SmartPhone
  if(myBT.available()){
    Serial.write(myBT.read());
  }
  //read Arduino Serial   >> Send SmartPhone
  if(Serial.available()){
    myBT.write(Serial.read());
  }
}
