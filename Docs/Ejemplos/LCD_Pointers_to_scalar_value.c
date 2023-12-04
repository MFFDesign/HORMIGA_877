#include <stdio.h>
#include "Hormiga877.h"
#include "LCD16x2.h"
//LCD16x2 Declaration
const char RS = 12;
const char RnW = 13;
const char En = 14;

const char D4 = 8;
const char D5 = 9;
const char D6 = 10;
const char D7 = 11;

char FirstROW[16] = {0};
char SecondROW[16] = {0};

enum Estados{Encendido,Apagado};
enum Estados Estado = Apagado;
unsigned int MenuA = 16;
/*
 * 1. Since ther is a "*" in declaration, "pointer" becomes a pointer variable
 * (a variable that stores  address off another variable)
 * 2. Since there is "int"  before "*" , "pointer" is a pointer  to an integer
 *  type variable.
 */
unsigned int *pointer;

void setup()
{
    /* "&" Operator before "MenuA" is used to get address of "MenuA" variable
     * .The Address of "MenuA" is assignment to "pointer".
     * 
     * <pointer variable> = &<variable>
     * <Variable address> = &<variable>
     */
    pointer = &MenuA;
    lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    lcdClear();
	lcdSetCursor(1,1);
    sprintf(FirstROW,"DIR :%d",pointer);
    lcdPrint(FirstROW);
    /*
     * The pointer variable with an "*" before the pointer variable and after
     * declaration shows the value stored in that address.
     * *<Variable Pointer> = <variable value>
     * thus can be used as Left Handed Value assignment.
     * *pointer = MenuA
     * (*pointer = k) = (MenuA = k)
     */
    sprintf(SecondROW,"VAL:%d",*pointer);
    lcdSetCursor(2,1);
    lcdPrint(SecondROW);
}

void loop()
{
    
}
