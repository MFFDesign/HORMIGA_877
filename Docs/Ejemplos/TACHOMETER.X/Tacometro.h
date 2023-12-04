/* 
 * File:   Tacometro.h
 * Author: Carlos Tonche
 *
 * Created on March 23, 2021, 1:31 PM
 */

#ifndef TACOMETRO_H
#define	TACOMETRO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "system.h"

//Prescaler Values for Timer One
#define OneToEight 		0x30	
#define OneToFourth		0x20
#define OneToSecond		0x10
#define OneToOne		0x00
#define TOneOn			0x01
#define TOneOff			0x00

double RevsPerMinute = 0;
void TachometerOneBegin(void);//(uint8_t Prescaler, uint8_t mode);
//double __interrupt() TachoRead(void);



#ifdef	__cplusplus
}
#endif

#endif	/* TACOMETRO_H */

