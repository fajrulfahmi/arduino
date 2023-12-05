#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define enter 2
#define kiri 3
#define kanan 4

int index = 1;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(enter, INPUT_PULLUP);
  pinMode(kiri, INPUT_PULLUP);
  pinMode(kanan, INPUT_PULLUP);
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

  //menampilkan menu
  lcd.setCursor(6, 0);
  lcd.print("MENU");

  if (index == 1) {
    lcd.setCursor(0, 1);
    lcd.print("<   LED MERAH  >");
  }else if(index == 2){
    lcd.setCursor(0, 1);
    lcd.print("<  LED KUNING  >");
  }else if(index == 3){
    lcd.setCursor(0, 1);
    lcd.print("<   LED HIJAU  >");
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
