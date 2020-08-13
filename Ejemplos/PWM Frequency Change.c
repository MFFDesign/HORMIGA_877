#include "system.h"


/*
	Cambiar Frecuencia de PWM y Ciclo de Trabajo
*/
char OnPin = 13;
enum Signal{ON,OFF};
enum Signal State = OFF;
char MenuA  = 0;
void setup()
{
    pinMode(OnPin,OUTPUT);
    digitalWrite(OnPin,LOW);
    analogWrite(22,0);
}


void loop()
{
    switch(State)
    {
        case ON:
            digitalWrite(OnPin,HIGH);
            analogWrite(22,512);
            while(MenuA != 1)
            {
                T2CON = 0x05;
                delay(1000);
                T2CON = 0x07;
                delay(1000);
                if(PBRead(0) == HIGH)
                {
                    delay(150);
                    if(PBRead(0) == HIGH)
                    {
                        MenuA = 1;
                    }
                }
            }
            MenuA = 0;
            State = OFF;
            break;
        case OFF:
            digitalWrite(OnPin,LOW);
            analogWrite(22,0);
            while(MenuA != 1)
            {
                if(PBRead(0) == HIGH)
                {
                    delay(150);
                    if(PBRead(0) == HIGH)
                    {
                        MenuA = 1;
                    }
                }
            }
            MenuA = 0;
            State = ON;
            break;
    }
}