#define led 9
#define ldr A0

int nilai;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop() {
  nilai = analogRead(ldr);
  Serial.println(nilai);

  if (nilai > 200) {
    digitalWrite(led, LOW);

  } else {
    digitalWrite(led, HIGH);
  }
}
