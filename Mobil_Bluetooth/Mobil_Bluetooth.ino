#include <SoftwareSerial.h>

#define pinENB 10
#define pinIN1 6
#define pinIN2 7
#define pinIN3 8
#define pinIN4 9
#define pinENA 5

#define buzzer 13
#define ledR 4
#define ledY 11
#define ledG 12

SoftwareSerial myBT(2, 3); //2 = TXD 3 = RXD
char recv;

void setup() {
  Serial.begin(9600);
  myBT.begin(9600);
  Serial.println("Mulai");

  pinMode(pinENB, OUTPUT);
  pinMode(pinENA, OUTPUT);
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);

}

void loop() {
  if (myBT.available()) { // cek koneksi bluetooth
    recv = myBT.read();   // membaca huruf yang diterema dari app
    Serial.print(recv);

    switch (recv) { //pengkodisian
      case 'F':
        Maju(122, 150);
        break;
      case 'B':
        Mundur(122, 150);
        break;
      case 'L':
        Kiri(150, 150);
        break;
      case 'R':
        Kanan(150, 150);
        break;
      case'G':
        Maju(90, 200);
        break;
      case'I':
        Maju(200, 110);
        break;
      case'H':
        Mundur(90, 200);
        break;
      case'J':
        Mundur(200, 110);
        break;
      case'V' :
        digitalWrite(buzzer, HIGH);
        break;
      case'v' :
        digitalWrite(buzzer, LOW);
        break;
      case 'S':
        Stops();
        break;

      //    switch(recv){
      //      case 'F':
      //        Maju(150, 150);
      //        break;
      //      case 'B':
      //        Mundur(150, 150);
      //        break;
      //      case 'L':
      //        Kiri(150, 150);
      //        break;
      //      case 'R':
      //        Kanan(150, 150);
      //        break;
      //      case 'S':
      //        Stops();
      //        break;
      default:
        break;
    }
  }
}

void Maju(int kiri, int kanan) {
  analogWrite(pinENB, kiri);
  digitalWrite(pinIN3, HIGH);
  digitalWrite(pinIN4, LOW);

  analogWrite(pinENA, kanan);
  digitalWrite(pinIN2, HIGH);
  digitalWrite(pinIN1, LOW);
}

void Mundur(int kiri, int kanan) {
  analogWrite(pinENB, kiri);
  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, HIGH);

  analogWrite(pinENA, kanan);
  digitalWrite(pinIN2, LOW);
  digitalWrite(pinIN1, HIGH);
}

void Kanan(int kiri, int kanan) {
  analogWrite(pinENB, kiri);
  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, HIGH);

  analogWrite(pinENA, kanan);
  digitalWrite(pinIN2, HIGH);
  digitalWrite(pinIN1, LOW);
}

void Kiri(int kiri, int kanan) {
  analogWrite(pinENB, kiri);
  digitalWrite(pinIN3, HIGH);
  digitalWrite(pinIN4, LOW);

  analogWrite(pinENA, kanan);
  digitalWrite(pinIN2, LOW);
  digitalWrite(pinIN1, HIGH);
}

void Stops() {
  analogWrite(pinENB, 0);
  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, LOW);

  analogWrite(pinENA, 0);
  digitalWrite(pinIN2, LOW);
  digitalWrite(pinIN1, LOW);
}
