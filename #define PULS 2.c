#define PULS        2
#define PASO        1
#define BAURENDT    9600
#define RESET       3
#define VALOR       0

unsigned int cont=0;

void setup(){
    Serial.begin (BAURENDT);
    pinMode(PULS, INPUT_PULLUP)
    pinMode(RESET, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PULS),interrumpir, FALLING);
    attachInterrupt(digitalPinToInterrupt(rESET),reinicio, FALLING);
}
void loop(){
delay(5000);
}
void interrumpir(){
    cont+=PASO; //cont=cont+1
    Serial.println(cont);
}
void reinicio(){
    
}