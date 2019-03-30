/*
 This sketch prints "Electronics for Enigneer" to the LCD and uses the
 scrollDisplayLeft() and scrollDisplayRight() methods to scroll
 the text.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/


#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);

pinMode(8, INPUT);
digitalWrite(8, HIGH);
pinMode(9, INPUT);
digitalWrite(9, HIGH);
}
double i = 0;
double a = millis();
double c ;

void loop() {

  lcd.clear();
lcd.print("press start");
delay(100);

if(digitalRead(8) == LOW)
{

lcd.clear();
a = millis();
while(digitalRead(9) == HIGH)
{

c = millis();
i = (c - a) / 1000;
lcd.print(i);
lcd.setCursor(7,0);
lcd.print("Sec's");
lcd.setCursor(0,0);
Serial.println(i);
Serial.println("......");
delay(100);
}

if(digitalRead(9) == LOW)
{
while(digitalRead(8) == HIGH)
{
lcd.setCursor(0,0);
lcd.print(i);
lcd.setCursor(11,0);
lcd.print("");
lcd.setCursor(0,0);
delay(100);
}
}
}
}
