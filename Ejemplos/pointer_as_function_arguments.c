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
unsigned int Vector[3][3] = {{4,8,11},{5,7,9}};


void setup()
{
    lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    lcdClear();
    GetAddress(Vector);
}

void loop()
{
    
}
/*
 * In two dimensional arrays, we can access each element by using subscripts; 
 * since memory computer is organized linearly it is not possible to store the 
 * two dimensional array in rows and columns. the concept of rows and columns 
 * is only theoretical, actually, a two dimensional array is stored in row-mayor
 * order; each row is stored next to each other.
 * 
 * var--> | arr[0][0] | arr[1][0] | arr[2][0] |
 * dir-->| 5000      |  5007     | 5013
 * value>|   1       |   2       |   3       |
 */

uint16_t GetAddress(uint16_t *ArrayAddress)
{
    uint16_t *ArrayPointer;
    ArrayPointer = ArrayAddress;
    for(char i=0;i<6;i++)
    {
        lcdClear();
        sprintf(FirstROW,"DIR: %u",ArrayPointer+i); //Show Address Value
        lcdPrint(FirstROW);
        lcdSetCursor(2,1);
        sprintf(SecondROW,"Value: %u",*(ArrayPointer+i)); //Show Value at that address
        lcdPrint(SecondROW);  
        delay(500);
    }
}