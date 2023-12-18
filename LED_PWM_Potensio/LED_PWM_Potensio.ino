#define PWM_led 9
#define Potensio A0

int nilai_Potensio;
int output;

void setup() {
  Serial.begin(9600);
  pinMode(PWM_led, OUTPUT);
  pinMode(Potensio, INPUT);
}

void loop() {
  nilai_Potensio = analogRead(Potensio);          // memasukkan nilai Potensio kedalam variabel
  output = map(nilai_Potensio, 0, 1023, 0, 255);  // funsi mapping

  analogWrite(PWM_led, output);                   // mengatur kecerahan led

  Serial.print("Nilai awal Potensio   : ");
  Serial.println(nilai_Potensio);
  Serial.print("Nilai Output Potensio : ");
  Serial.println(output);
  Serial.println();

  delay(500);
}
