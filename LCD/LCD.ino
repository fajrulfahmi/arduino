#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}
void loop() {
  lcd.setCursor(5, 0); 
  lcd.print("HELLO"); 
  lcd.setCursor(5, 1); 
  lcd.print("WORLD"); 
}
