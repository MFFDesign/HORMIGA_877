/* 
 * File:   NumberIO.h
 * Author: ToncheLAP
 *
 * Created on April 6, 2022, 2:13 PM
 */

#ifndef NUMBERIO_H
#define	NUMBERIO_H

void I2CPrintNumber(float number, char *DataVector);
void I2CShowNumber(float number, float resolution, char *DataVector);
unsigned int I2CParteEntera(float number );
double I2CMakeDoubleNumber(char row, char col);
unsigned int I2CMakeIntegerNumber(char row, char col);
char I2CMakeByteNumber(char row, char col);
char I2CCaseSelector(char *Vector, char SizeValues, char row, char col);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* NUMBERIO_H */

