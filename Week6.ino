// hello

uint8_t LEDPin1 = 3;
uint8_t LEDPin2 = 10;
uint8_t LEDPin3 = 12;
int PWMFreq  = 5000;
int PWMChannelr = 0;
int PWMChannelg = 1;
int PWMChannelb = 2;
int PWMResolution = 10;

int MAX_DUTY_CYCLE = 1023;
int dutyCycle = 1023;
int Dim_Mer1 = dutyCycle - 10;
int direction = -10;
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2,OUTPUT);
  pinMode(LEDPin3,OUTPUT);
ledcSetup(PWMChannelr, PWMFreq, PWMResolution);
ledcSetup(PWMChannelg, PWMFreq, PWMResolution);
ledcSetup(PWMChannelb, PWMFreq, PWMResolution);
ledcAttachPin(LEDPin1, PWMChannelr);
ledcAttachPin(LEDPin2, PWMChannelg);
ledcAttachPin(LEDPin3, PWMChannelb);
}

void loop() {
  // put your main code here, to run repeatedly:
  {
dutyCycle =1023;
  ledcWrite(PWMChannelr,dutyCycle);
if(Dim_Mer1 >= 1023){
  direction = -10;
}
delay(500);
 Dim_Mer1 = Dim_Mer1 +direction;
  ledcWrite(PWMChannelr, Dim_Mer1);
  if(Dim_Mer1 <= 0){
    direction = 10;
}
  }
delay(1000);
{
  dutyCycle =1022;
ledcWrite(PWMChannelg,dutyCycle);
if(Dim_Mer1 == 1022){
  direction = -10;
}
delay(500);
 Dim_Mer1 = Dim_Mer1 +direction;
  ledcWrite(PWMChannelg, Dim_Mer1);
  if(Dim_Mer1 <= 0){
    direction = 10;
  }
}
  delay(1000);
  {
    dutyCycle =1021;
  ledcWrite(PWMChannelb,dutyCycle);
  if(Dim_Mer1 >= 1021){
  direction = -10;
}
delay(500);
 Dim_Mer1 = Dim_Mer1 +direction;
  ledcWrite(PWMChannelb, Dim_Mer1);
  if(Dim_Mer1 <= 0){
    direction = 10;
}
delay(1000);
}
}