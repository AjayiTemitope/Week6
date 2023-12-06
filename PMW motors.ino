uint8_t Motor_Pin = 15;
uint8_t button_Pin = 13;
uint8_t buttonState;

int PWMFreq  = 5000;
int PWMChannel = 1;
int PWMResolution = 10;
int MAX_DUTY_CYCLE = 1023;

void setup() {
  // put your setup code here, to run once:
  pinMode(button_Pin,OUTPUT);
  pinMode(Motor_Pin, OUTPUT);
ledcSetup(PWMChannel, PWMFreq, PWMResolution);
ledcAttachPin(Motor_Pin, PWMChannel);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button_Pin);
  if(buttonState = HIGH)
  {
  int dutyCycle = 512;
  ledcWrite(PWMChannel,dutyCycle);
}
else
{
 ledcWrite(Motor_Pin,LOW);
}
}