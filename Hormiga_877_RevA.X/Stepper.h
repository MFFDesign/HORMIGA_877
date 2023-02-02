/* 
 * File:   Stepper.h
 * Author: DSIRe
 *
 * Created on 1 de febrero de 2023, 01:43 PM
 */

#ifndef STEPPER_H
#define	STEPPER_H

#ifdef	__cplusplus
extern "C" {
#endif
#define FWD         0x01
#define REV         0x00
#define TEnable     0x13
#define TDisable    0x14
    unsigned int AccelProfile(const int ni, const int n);
    void StepperExconBegin(char Step, char Dir, char Enable);
    unsigned int Accelcalculation(unsigned int VelFinal, unsigned int TimeRamp);
    unsigned int MoveStepper(unsigned int Steps, char Dir);
    void MoveStepperHWD(unsigned int Steps, char Dir);
    void HardwareDelay(unsigned char mode, unsigned char time);
    unsigned long StepMove(char Dir, unsigned int dt);
    void ResetStepsCount(void);
    void VelProfile(unsigned long Steps, char Dir, unsigned int Vi, unsigned int Vf, unsigned long *StepsOut);
    void MotorEnable(void);
void MotorDisable(void);



#ifdef	__cplusplus
}
#endif

#endif	/* STEPPER_H */

