#include <EEPROM.h>
#define BOTON1      2 //Buenas prácticas de programación: escribir todos los define en mayúsculas
#define BOTON2      3 //Los pines 2 y 3 son para interrupciones
#define TIME        5000
#define BAUDRATE    9600 
#define I_EEPROMP   0
#define MAXVOL      100
#define MINVOL      0

unint8__t volumen=EEPROM.read(I_EEPROMP);
bool flag = false;
volatile unsigned long lasttime=0;
volatile unsigned long debounce=60;
volatile unsigned long lasttime2=0;

void setup(){
    pinmode(BOTON1, INPUT_PULLUP); //INPUT_PULLUP es para usar la resistencia de la placa
    pinmode(BOTON2, INPUT_PULLUP);
    attatchInterrupt(digitalPinToInterrupt(BOTON1), up, FALLING); //FALLING detecta el flanco de bajada
    attatchInterrupt(digitalPinToInterrupt(BOTON2), down, FALLING);
}

void loop(){//PARA LA PRÁCTICA 2 USAR BANDERAS Y TRABAJAR AQUÍ

    // Verificación de antirrebote para BOTON1
    // Si ambos botones están presionados, reseteamos el volumen
    if (flag1==true && flag2==true) {
        volumen = 0;
        Serial.println("VOLUMEN: 0 ");
        EEPROM.write(I_EEPROMP, volumen); // Guardamos en la EEPROM
        bool flag1 = false;
        bool flag2 = false;
    }

    delay(TIME);
}


void up(){
    if(millis()-lasttime>debounce){ //millis es un tipo de temporizador(reloj)
        flag =true;
        if(volumen<MAXVOL){
            volumen++;
            serial.println"VOLUMEN(+): ";
            serial.println (volumen);
            EEPROM.write(I_EEPROMP,value)

        }
        lasttime=millis();//podemos llamar a millis las veces que queremos porque nos retornará al reloj
    }
}

void down(){
   if(millis()-lasttime<debounce){
        flag =true;
        if(volumen>MINVOL){
            volumen--;
            serial.println"VOLUMEN(+): ";
            serial.println (volumen);
        }
    lasttime=millis();
   }
}