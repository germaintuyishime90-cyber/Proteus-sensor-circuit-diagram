
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
// Define PIR sensor pin
int pirPin = 3;
int pirState = LOW;  // Start assuming no motion
int val = 0;         // Variable for reading PIR status

void setup() {
  pinMode(pirPin, INPUT);
  lcd.begin(16, 2); // 16x2 LCD
  lcd.print("PIR Sensor Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  val = digitalRead(pirPin); // Read PIR sensor

  if (val == LOW) {
    if (pirState == LOW) {
      lcd.clear();
      lcd.print("Motion Detected!");
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH) {
      lcd.clear();
      lcd.print("No Motion");
      pirState = LOW;
    }
  }
}



