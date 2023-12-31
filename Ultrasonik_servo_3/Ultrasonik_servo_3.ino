#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <Servo.h>
#define servo 10

Servo myServo;

#include <NewPing.h>
#define trig      8
#define echo      9
#define maksimal  200

NewPing jarak(trig, echo, maksimal);

int nilai;

void setup() {
  Serial.begin(9600);
  myServo.attach(servo);
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  nilai = jarak.ping_cm();
  Serial.println(nilai);
  
  lcd.setCursor(1, 0);
  lcd.print("Jarak : ");
  lcd.setCursor(9, 0);
  lcd.print(nilai);
  lcd.setCursor(13, 0);
  lcd.print("cm");

  if(nilai < 4){
    myServo.write(180);
    lcd.setCursor(0, 1);
    lcd.print("  Pintu terbuka  ");
  }else{
    myServo.write(0);
    lcd.setCursor(0, 1);
    lcd.print(" Pintu tertutup  ");
  }
  delay(1000);
  lcd.clear();
}
