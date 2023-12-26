#define led 2
#define button 3

int count;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(button) == 0) {
    count++;
    Serial.println(count);
//    delay(300);
    if (count == 1) {
      digitalWrite(led, HIGH);
    } else if (count == 2) {
      digitalWrite(led, LOW);
      count = 0;
    }
  }
}
