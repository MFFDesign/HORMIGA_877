#include <stdio.h>
#include "system.h"


char data[30];
unsigned int buffer = 0;
volatile unsigned int New = 0;
volatile unsigned int Last = 0;
volatile float Period = 0;
unsigned int Decenas = 0;
char Unidades = 0;
unsigned int RPMs = 0;

void setup()
{
    SerialBegin(9600);
    //Timer 1 Configuration
    TRISC1 = 1; //RC1 Terminal as Input
    TMR1 = 0; //Timer 1 Register TMR1H and TMR1L equal to cero 
    TMR1CS = 0; //Clock select as internal clock source FOSC/4
    T1CKPS0 = 1;// Prescaler set to 8 to 1
    T1CKPS1 = 1;// Prescaler set to 8 to 1
    TMR1ON = 1;// Turn On 1
    //Setup for DDP2 for CaptureMode
    CCP2M3 = 0;//Capture Mode Every Falling Edge
    CCP2M2 = 1;
    CCP2M1 = 0;
    CCP2M0 = 0;
    //Configure the CCP2 Interrupt
    CCP2IF = 0;
    CCP2IE = 1;
    PEIE = 1;
    GIE = 1;
}

void loop()
{
    buffer = (int)(62500000/Period);
    Decenas = (int)(buffer / 100);
    Unidades = buffer - (Decenas * 100);
    RPMs = (int)((625000 *60)/Period);
    sprintf(data,"Freq : %u.%u Hz | RPMs : %u",Decenas,Unidades, RPMs);
    SerialPrintLn(data);
    delay(200);
}

void __interrupt() ISR(void)
{
   
    if(CCP2IF)
    {
        New = (CCPR2H << 8) + CCPR2L;
        Period = New - Last;
        Last = New;
        CCP2IF = 0;
    }
}