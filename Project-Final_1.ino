#include "rgb_lcd.h"
rgb_lcd lcd;

uint8_t laserpin = 3;
uint8_t Motor_Pin = 6;
uint8_t buttonPin = 4;
uint8_t buttonstate;

uint64_t  pulse;
float AverageVelocity = 0.00881912;
uint64_t distance_inch;
uint64_t distance_cm;

int PWMFreq  = 5000;
int PWMChannel = 1;
int PWMResolution = 10;
int MAX_DUTY_CYCLE = 1023;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(115200);
  pinMode(4, INPUT);

  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  ledcAttachPin(Motor_Pin, PWMChannel);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, LOW);
  digitalWrite(3, HIGH);
  delayMicroseconds(2);
  digitalWrite(3, LOW);

  pinMode(3, INPUT);
  pulse =  pulseIn(3, HIGH);
  distance_inch =  AverageVelocity * pulse;
  distance_cm = distance_inch * 2.54;
  Serial.print ((float)pulse);
  Serial.println((float)distance_cm);

  buttonstate = digitalRead(4);
  pinMode(3, OUTPUT);

  lcd.setCursor(2, 0);
  lcd.print("TIME");
  lcd.setCursor(8, 0);
  lcd.print("DISTANCE");
  lcd.setCursor(2, 2);
  lcd.print(pulse);
  
int dutyCycle;

  if (buttonstate == LOW)
  {
    delay(300);
    lcd.setCursor(8, 2);
    lcd.print(distance_cm);
    lcd.write("cm  ");

    if (distance_cm > 30)
    {
      dutyCycle = 100;
    }
    if (distance_cm > 27 && distance_cm <= 30)
    {
      dutyCycle = 200;
    }
    if (distance_cm > 23 && distance_cm <= 27)
    {
      dutyCycle = 300;
    }
    if (distance_cm > 20 && distance_cm <= 23)
    {
      dutyCycle = 400;
    }
    if (distance_cm == 20)
    {
      dutyCycle = 450;
    }
    if (distance_cm > 15 && distance_cm < 20)
    {
      dutyCycle = 500;
    }
    if (distance_cm == 15)
    {
      dutyCycle = 600;
    }
    if (distance_cm > 10 && distance_cm < 15)
    {
      dutyCycle = 700;
    }
    if (distance_cm == 10)
    {
      dutyCycle = 800;
    }
    if (distance_cm > 5 && distance_cm < 10)
    {
      dutyCycle = 900;
    }
    if (distance_cm == 5)
    {
      dutyCycle = 950;
    }
    if (distance_cm > 1 && distance_cm < 5)
    {
      dutyCycle = 1000;
    }
    if (distance_cm == 1)
    {
      dutyCycle = 1022;
    }
    ledcWrite (PWMChannel, dutyCycle);
  }
  else
  {
    ledcWrite(PWMChannel, 0);
  }
}
