#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int count = LOW;
unsigned long previousMillis = 0;
long OnTime = 5000;
long OffTime = 2000;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  unsigned long currentMillis = millis();

  if ((count == HIGH) && (currentMillis - previousMillis >= OnTime)) {
    count = LOW;
    previousMillis = currentMillis;
    Serial.println("Test 2");
    lcd.setCursor(10, 0);
    lcd.print("Test 2");
    lcd.setCursor(0, 0);
    lcd.print("      ");
    
  } else if ((count == LOW) && (currentMillis - previousMillis >= OffTime)) {
    count = HIGH;
    previousMillis = currentMillis;
    Serial.println("Test 1");
    lcd.setCursor(0, 0);
    lcd.print("Test 1");
    lcd.setCursor(10, 0);
    lcd.print("      ");
  }
}
