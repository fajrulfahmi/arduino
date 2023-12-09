#define buzzer 7

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  Serial.println("Buzzer Nyala");
  digitalWrite(buzzer, HIGH);

  delay(2000);

  Serial.println("Buzzer Mati");
  digitalWrite(buzzer, LOW);

  delay(2000);
}
