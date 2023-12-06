#include <HardwareSerial.h>

uint8_t serial_rx_pin = 15;
uint8_t serial_tx_pin = 14;

uint8_t buttonPin1 = 17;
uint8_t buttonPin2 = 7;
uint8_t buttonPin3 = 3;

HardwareSerial xSerial(1);

void setup() {
  // put your setup code here, to run once:
  xSerial.begin(9600,SERIAL_8N1,serial_rx_pin,serial_tx_pin);
Serial.begin (9600);

pinMode(buttonPin1,INPUT);
pinMode(buttonPin2,INPUT);
pinMode(buttonPin3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(buttonPin1) == HIGH){
xSerial.print("@");
}
if(digitalRead(buttonPin2) == HIGH){
  xSerial.print ("#");
}
if(digitalRead(buttonPin3) == HIGH){
 xSerial.print ("$");
}
}
