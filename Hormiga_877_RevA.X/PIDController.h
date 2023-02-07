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
void PIDSetSampleTime(char dt);
unsigned int EventCounters(void);
unsigned char AccionControl(double SetPoint, double Feedback, double dt);



#ifdef	__cplusplus
}
#endif

#endif	/* PIDCONTROLLER_H */

