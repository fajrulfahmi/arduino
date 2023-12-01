#define button1 7
#define button2 8

#define pull1 digitalRead(button1)
#define pull2 digitalRead(button2)

#define buzzer 10

void setup() {
  Serial.begin(9600);
  
  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  
}

void loop() {
  if(!pull1){
    Serial.println("BUTTON 1 : DITEKAN");
    digitalWrite(buzzer, HIGH);
  }else if(!pull2){
    Serial.println("BUTTON 1 : DITEKAN");
    digitalWrite(buzzer, LOW);
  }

}
//
//bool value1, value2;
//
//void setup(){
//  Serial.begin(9600);
//
//  pinMode(buzzer, OUTPUT);
//  pinMode(button1, INPUT);
//  pinMode(button2, INPUT);
//}
//
//void loop(){
//  value1 = digitalRead(button1);
//  value2 = digitalRead(button2);
//
//  if(value1 == 1){
//    Serial.println("BUTTON 1 : DITEKAN");
//    digitalWrite(buzzer, HIGH);
//  }else if(value2 == 1){
//    Serial.println("BUTTON 1 : DITEKAN");
//    digitalWrite(buzzer, LOW);
//  }
//  
//}
