/* 
 * File:   PIDController.h
 * Author: c4810
 *
 * Created on February 3, 2023, 1:48 PM
 */

#ifndef PIDCONTROLLER_H
#define	PIDCONTROLLER_H

#ifdef	__cplusplus
extern "C" {
#endif
void SetSampleTime(char dt);
void SetProportionalTune(double value);
void SetIntegralTune(double value);
void SetDerivativeTune(double value);
double AccionControl(double SetPoint, double Feedback);
unsigned int EventCounter(void);
double map(double data, double X2, double X1, double Y2, double Y1);



#ifdef	__cplusplus
}
#endif

#endif	/* PIDCONTROLLER_H */

