#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define enter 2
#define kiri 3
#define kanan 4

#define merah 5
#define kuning 6
#define hijau 7


int index = 1;
int cMerah, cKuning, cHijau;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(enter, INPUT_PULLUP);
  pinMode(kiri, INPUT_PULLUP);
  pinMode(kanan, INPUT_PULLUP);

  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
}

void loop() {
  bool nilaiEnter = digitalRead(enter);
  bool nilaiKanan = digitalRead(kanan);
  bool nilaiKiri = digitalRead(kiri);

  // menagatur nilai Index
  if (nilaiKanan == 0) {
    index++;
    delay(500);
  } else if (nilaiKiri == 0) {
    index--;
    delay(500);
  }

  //mengatur nilai min dan max index
  if (index < 1) {
    index = 3;
  } else if (index > 3) {
    index = 1;
  }

  //program enter

  //menampilkan menu
  lcd.setCursor(6, 0);
  lcd.print("MENU");

  if (index == 1) {
    lcd.setCursor(0, 1);
    lcd.print("<   LED MERAH  >");
    // Toggle
    if (nilaiEnter == 0) {
      cMerah++;
      Serial.println("count Merah : " + (String)cMerah);
      delay(100);

      if (cMerah == 1) {
        digitalWrite(merah, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("  LED MERAH ON  ");
        delay(500);
        lcd.clear();

      } else if (cMerah == 2) {
        digitalWrite(merah, LOW);
        cMerah = 0;
        lcd.setCursor(0, 1);
        lcd.print("  LED MERAH OFF ");
        delay(500);
        lcd.clear();
      }
    }

  } else if (index == 2) {
    lcd.setCursor(0, 1);
    lcd.print("<  LED KUNING  >");

    if (nilaiEnter == 0) {
      cKuning++;
      Serial.println("count Kuning : " + (String)cKuning);
      delay(100);

      if (cKuning == 1) {
        digitalWrite(kuning, HIGH);
        lcd.setCursor(0, 1);
        lcd.print(" LED KUNING ON  ");
        delay(500);
        lcd.clear();

      } else if (cKuning == 2) {
        digitalWrite(kuning, LOW);
        cKuning = 0;
        lcd.setCursor(0, 1);
        lcd.print(" LED KUNING OFF ");
        delay(500);
        lcd.clear();
      }
    }

  } else if (index == 3) {
    lcd.setCursor(0, 1);
    lcd.print("<   LED HIJAU  >");

    if (nilaiEnter == 0) {
      cHijau++;
      Serial.println("count Hijau : " + (String)cHijau);
      delay(100);

      if (cHijau == 1) {
        digitalWrite(hijau, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("  LED HIJAU ON  ");
        delay(500);
        lcd.clear();

      } else if (cHijau == 2) {
        digitalWrite(hijau, LOW);
        cHijau = 0;
        lcd.setCursor(0, 1);
        lcd.print("  LED HIJAU OFF ");
        delay(500);
        lcd.clear();
      }
    }

  }

  Serial.print("index : ");
  Serial.println(index);
  Serial.print("Enter : ");
  Serial.println(nilaiEnter); //Serial.println("Enter : " + nilaiEnter);
  Serial.print("Kanan : ");
  Serial.println(nilaiKanan);
  Serial.print("Kiri : ");
  Serial.println(nilaiKiri);
  Serial.println();
  delay(500);
  lcd.clear();
}
