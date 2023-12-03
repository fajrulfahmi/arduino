#define bKanan 7
#define bKiri 8

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pull1 digitalRead(bKanan)
#define pull2 digitalRead(bKiri)

int count;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(bKanan, INPUT_PULLUP);
  pinMode(bKiri, INPUT_PULLUP);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("------MENU------");

  if (!pull1) {
    delay(500);
    count++;

    lcd.setCursor(5, 1);
    lcd.print("Menu");
    lcd.setCursor(10, 1);
    lcd.print(count);
    Serial.print(count);

    if (count >= 3) {
      count = 0;
    }

  } else if (!pull2) {
    if (count == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Menu 2 dipilih ");
      lcd.setCursor(0, 1);
      lcd.print("  kondisi Aksi  ");
      delay(1500);
      
    } else if (count == 2) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Menu 2 dipilih ");
      lcd.setCursor(0, 1);
      lcd.print("  kondisi Aksi  ");
      delay(1500);

    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Menu 3 dipilih ");
      lcd.setCursor(0, 1);
      lcd.print("  kondisi Aksi  ");
      delay(1500);
    }
    lcd.clear();
  }
}
