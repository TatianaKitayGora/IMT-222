//MACROS
#define POT A0
#define LED 6

void setup()
{
    pinMode(POT,INPUT);
  	p inMode(LED,OUTPUT);
}

void loop()
{
    int16_t lectura=analogRead(POT);
    int8_t pwm=map(lectura,0,1023,0,254);
  analogWrite(LED,pwm);
}