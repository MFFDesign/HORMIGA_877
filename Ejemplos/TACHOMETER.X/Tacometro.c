#include "system.h"
#include "Tacometro.h"


void TachometerOneBegin(void)//(uint8_t Prescaler, uint8_t mode)
{
    /*
	TRISCbits.TRISC1 = 1;
	T1CON &= 0x00;
	T1CON |= Prescaler;
	T1CON |= mode;
	CCP2CON = 0x04; //Capture Mode Every Falling Edge
    */
	/*
		To change Prescaler Value, CCP Module Most be turned off
	*/
    /*
	CCPR2H = 0x00;
	CCPR2L = 0x00;
	PIR2bits.CCP2IF = 0; //Clear CCP1 Interrupt Flag bit
	PIE2bits.CCP2IE = 1;	//Enable CCP1 Interrupt
	TMR1H = 0x00;
	TMR1L = 0x00;
	PIR1bits.TMR1IF = 0;
    */
    //Timer 1 Configuration
    TMR1 = 0;
    TMR1CS = 0;
    T1CKPS0 = 0;
    T1CKPS1 = 0;
    TMR1ON = 1;
    //Setup for DDP2 for CaptureMode
    CCP2M3 = 0;
    CCP2M2 = 1;
    CCP2M1 = 0;
    CCP2M0 = 0;
    //Configure the CCP2 Interrupt
    CCP2IE = 1;
    PEIE = 1;
    GIE = 1;
}
