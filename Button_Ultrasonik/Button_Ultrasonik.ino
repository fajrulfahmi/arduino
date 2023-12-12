#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define button 3
#define trig 8
#define echo 9
#define maksimal 200

NewPing jarak(trig, echo, maksimal);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  bool buttonValue = digitalRead(button);
  int ultraValue = jarak.ping_cm();

  if (buttonValue == 0) {
    Serial.println("Button Ditekan");
    lcd.setCursor(0, 0);
    lcd.print("Jarak : " + (String)ultraValue + " cm");
    delay(1000);
    lcd.clear();
  }else{
    Serial.println("Button Dilepas");
    lcd.setCursor(0, 0);
    lcd.print("Jarak : -");
  }

  Serial.print("Ping");
  Serial.print(ultraValue);
  Serial.println("cm");
}
