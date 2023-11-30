#include <SoftwareSerial.h>
#define led 5

SoftwareSerial myBT(7, 8); // TX || RX
char receive;

void setup() {
  Serial.begin(9600);
  myBT.begin(6900);
  Serial.println("START");

  pinMode(led, OUTPUT);
}

void loop() {
  //read myBT Serial     >> Recv SmartPhone
  if(myBT.available()){

    receive = myBT.read();
    Serial.print(receive);

    if(receive == 'n'){
      Serial.print("Lampu Nyala");
      digitalWrite(led, HIGH);
      myBT.write("LED ON \n");
      
    }else if(receive == 'f'){
      Serial.print("Lampu Mati");
      digitalWrite(led, LOW);
      myBT.write("LED OFF \n");
    }
  }
  //read Arduino Serial   >> Send SmartPhone
  if(Serial.available()){
    myBT.write(Serial.read());
  }
}
