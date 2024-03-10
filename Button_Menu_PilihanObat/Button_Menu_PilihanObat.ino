#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int index = 0;
int btnY = 0;
int btnN = 0;
int btnE = 0;

const int btnY_pin = 2;
const int btnN_pin = 3;
const int btnE_pin = 4;
const int ledPin = 13;


void setup() {
  Serial.begin(9600);
  pinMode(btnY_pin, INPUT);
  pinMode(btnN_pin, INPUT);
  pinMode(btnE_pin, INPUT);
  pinMode(ledPin, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int btnYv = digitalRead(btnY_pin);
  int btnNv = digitalRead(btnN_pin);
  int btnEv = digitalRead(btnE_pin);

  if (index == 6) { //pilihan Obat nyeri otot
    if (btnYv == 1) {
      index = 9;
    }
    if (btnNv == 1) {
      index = 10;
    }
  }

  if (index == 5) { //Pilihan obat Gatal Kulit
    if (btnYv == 1) {
      index = 7;
    }
    if (btnNv == 1) {
      index = 8;
    }
  }

  if (index == 2) { //Gatal Kulit
    if (btnYv == 1) {
      index = 5;
    }
    if (btnNv == 1) {
      index = 6;
    }
  }

  if (index == 1) { //pilihan Obat demam
    if (btnYv == 1) {
      index = 3;
    }
    if (btnNv == 1) {
      index = 4;
    }
  }

  if (index == 0) { //Demam
    if (btnYv == 1) {
      index = 1;
    }
    if (btnNv == 1) {
      index = 2;
    }
  }

  if (btnEv == 1) {
    if (index == 1 || index == 2) {
      index = 0;
    }
    if (index == 3 || index == 4) {
      index = 1;
    }
    if (index == 5 || index == 6) {
      index = 2;
    }
    if (index == 7 || index == 8) {
      index = 5;
    }
    if (index == 9 || index == 10) {
      index = 6;
    }
  }

  if (index == 0) {
    lcd.setCursor(5, 0);
    lcd.print("Demam");
  }
  if (index == 1) {
    lcd.setCursor(0, 0);
    lcd.print("Batuk Pilek");
  }
  if (index == 2) {
    lcd.setCursor(0, 0);
    lcd.print("Gatal Kulit");
  }
  if (index == 3) {
    lcd.setCursor(0, 0);
    lcd.print("DemamBP");
  }
  if (index == 4) {
    lcd.setCursor(0, 0);
    lcd.print("DemamBiasa   ");
  }
  if (index == 5) {
    lcd.setCursor(0, 0);
    lcd.print("Gatal Kulit Luar");
  }
  if (index == 6) {
    lcd.setCursor(0, 0);
    lcd.print("Nyeri Otot ");
  }
  if (index == 7) {
    lcd.setCursor(0, 0);
    lcd.print("Gatal Kulit-Luar");
  }
  if (index == 8) {
    lcd.setCursor(0, 0);
    lcd.print("Gatal Kulit Dlm ");
  }
  if (index == 9) {
    lcd.setCursor(0, 0);
    lcd.print("obatNyeriOtot");
  }
  if (index == 10) {
    lcd.setCursor(0, 0);
    lcd.print("obtTdkDiTmkan");
  }


  if (btnYv == 1) {
    Serial.println("Y Ditekan");
  }
  if (btnNv == 1) {
    Serial.println("N Ditekan");
  }
  if (btnEv == 1) {
    Serial.println("E Ditekan");
  }
  Serial.println("index : " + (String)index);
  delay(100);
  lcd.clear();
}
