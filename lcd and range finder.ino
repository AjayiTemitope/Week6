#include "rgb_lcd.h"

rgb_lcd lcd;

uint8_t laserpin = 4;

uint64_t  pulse4;
float AverageVelocity = 0.00781912;
uint64_t distance4inch;
uint64_t distance4cm;

uint8_t buttonPin = 17;
uint8_t buttonstate;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(115200);

pinMode(17,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(4,LOW);
digitalWrite(4,HIGH);
 delayMicroseconds(2);
digitalWrite(4,LOW);

  pinMode(4,INPUT);
 pulse4 =  pulseIn(4,HIGH);
 distance4inch =  AverageVelocity*pulse4;
 distance4cm = distance4inch*2.54;
 Serial.print ((float)pulse4);
 Serial.print((float)distance4inch);
 Serial.println((float)distance4cm);

buttonstate = digitalRead(17);
 pinMode(4,OUTPUT);

if (buttonstate == HIGH)
{
lcd.setCursor(2,0);
 lcd.print("TIME");
 lcd.setCursor(8,0);
 lcd.print("DISTANCE");

lcd.setCursor(2,2);
 lcd.print(pulse4);
 delay(600);
 lcd.setCursor(8,2);
lcd.print(distance4inch);
lcd.write("inch  ");
}
else
{
lcd.setCursor(2,0);
 lcd.print("TIME");
 lcd.setCursor(8,0);
 lcd.print("DISTANCE");

lcd.setCursor(2,2);
 lcd.print(pulse4);
 delay(600);
 lcd.setCursor(8,2);
lcd.print(distance4cm);
lcd.write("cm  ");
}
}
