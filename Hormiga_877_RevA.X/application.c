#include "system.h"
#include "Keypad4x4.h"
#include <stdio.h>

#define A 7
#define B 8
#define C 9
#define D 10
#define E 11
#define F 12
#define G 13
// display de 7 Segmentos;
//-------------------{a,b,c,d, e, f ,g }
char Terminales[7] = {7,8,9,10,11,12,13};

void setup() 
{
    for(int i=0;i<7;i++)
    {
        pinMode(Terminales[i],OUTPUT);
        digitalWrite(Terminales[i],LOW);
    }
}


void loop()
{
    if(PBRead(0) == HIGH)
    {
        delay(50);
        if(PBRead(0) == HIGH)
        {
            digitalWrite(A,HIGH);
            digitalWrite(B,HIGH);
            digitalWrite(C,HIGH);
            digitalWrite(D,HIGH);
            digitalWrite(E,HIGH);
            digitalWrite(F,HIGH);
            digitalWrite(G,HIGH);
        }
    }
    else if(PBRead(1) == HIGH)
    {
        delay(50);
        if(PBRead(1) == HIGH)
        {
            digitalWrite(A,HIGH);
            digitalWrite(B,HIGH);
            digitalWrite(C,LOW);
            digitalWrite(D,LOW);
            digitalWrite(E,LOW);
            digitalWrite(F,LOW);
            digitalWrite(G,LOW);
        }
    }
    else if(PBRead(2) == HIGH)
    {
        delay(50);
        if(PBRead(2) == HIGH)
        {
            digitalWrite(A,LOW);
            digitalWrite(B,HIGH);
            digitalWrite(C,HIGH);
            digitalWrite(D,HIGH);
            digitalWrite(E,HIGH);
            digitalWrite(F,HIGH);
            digitalWrite(G,HIGH);
        }
    }
}