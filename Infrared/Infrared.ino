#define infrared 7
#define buzzer 8

void setup() { 
  pinMode(infrared, INPUT);
  pinMode(buzzer, OUTPUT);
 
  Serial.begin(9600); //Serial 9600
}
void loop() {
  if (digitalRead(infrared) == LOW) { 
    Serial.println("OBJECT - DETECTED");
    digitalWrite(buzzer, HIGH);
    delay(500);
  }
  if (digitalRead(infrared) == HIGH) { 
    Serial.println("NO OBJECT");
    digitalWrite(buzzer, LOW);
 }
}
