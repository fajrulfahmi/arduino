#define PWM_led 9

void setup() {
  Serial.begin(9600);
  pinMode(PWM_led, OUTPUT);
}

void loop() {
  analogWrite(PWM_led, 0);        //0 merupakan nilai PWM
  Serial.println("PWM Led : 0");
  delay(1000);

  analogWrite(PWM_led, 100);      //100 merupakan nilai PWM
  Serial.println("PWM Led : 100");
  delay(1000);
}
