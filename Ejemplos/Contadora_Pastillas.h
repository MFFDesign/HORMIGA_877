/* 
 * File:   Contadora_Pastillas.h
 * Author: user
 *
 * Created on July 4, 2020, 11:32 AM
 */

#ifndef CONTADORA_PASTILLAS_H
#define	CONTADORA_PASTILLAS_H

#define RST 0x15
#define CNT 0x10

void IOConfiguration(void);
void ContadorBegin(void);
uint8_t Contador(char mode);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONTADORA_PASTILLAS_H */

