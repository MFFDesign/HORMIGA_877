//#include "system.h"
//#include "LCD16x2.h"
//#include "Keypad4x4.h"
//
///*
// * Practica 2:  Control de Velocidad de Motor de Corriente Continua.
// *  1. Teclear las revoluciones de giro en el teclado Matricial.
// *  2. Lectura se anota en el LCD.
// *  3. Controlar las revoluciones con el valor anotado en el LCD.
// *  4. Aplicar la ecuacion de la recta para controlar el giro del motor.
// */
//char Teclas[4][4] = {
//	{'1','2','3','A'},
//	{'4','5','6','B'},
//	{'7','8','9','C'},
//	{'*','0','#','D'},
//};
//char Tecla = 'n';
//const int ROWS[4] = {20,19,18,17};
//const int COLS[4] = {16,12,14,13};
//
//// Terminales de la LCD.
//char RS = 2;
//char RnW = 1;
//char En = 3;
//char D4 = 5;
//char D5 = 6;
//char D6 = 7;
//char D7 = 8;
//char FirstROW[16]; //Buffer de Datos de la LCD Primer Renglon
//char SecondROW[16];//Buffer de datos segundo Renglon
//
//char Motor = 4;
//int counter = 0;
//int DataStorage[2];
//int ValorRPMS = 0;
//int Velocidad = 0;
//int kp = 1;
//
//enum Estados{Run,Config};
//enum Estados estado;
//
//void setup()
//{
//    lcdBegin(RS, En, RnW, D4, D5, D6, D7);
//    KeypadBegin(ROWS,COLS,Teclas);
//    pinMode(Motor,OUTPUT);
//    lcdClear();
//    lcdSetCursor(1,1);
//    lcdPrint("P-2:Control  RPM");
//    lcdSetCursor(2,1);
//    for(char i=0;i<16;i++)
//    {
//        lcdWrite('.');
//        delay(250);
//    }
//    lcdClear();
//    lcdSetCursor(1,1);
//    lcdPrint("Ingrese RPMS: ");
//    delay(500);
//}
//
//void loop()
//{
//    Tecla = KeypadRead();
//    if(counter < 2)
//    {
//        //lcdClear();
//        if(Tecla != NO_KEY)
//        {
//            delay(100);
//            if(Tecla != NO_KEY)
//            {
//                DataStorage[counter]  = Tecla - 48;
//                //lcdWrite(Tecla);
//                lcdSetCursor(2,1);
//                ValorRPMS = (DataStorage[0] * 10) + DataStorage[1];
//                sprintf(SecondROW,"RPMs: %i ,Key:%i ",ValorRPMS,DataStorage[counter]);
//                lcdPrint(SecondROW);
//                counter++;
//                delay(500);
//                if(counter >  1)
//                {
//                    lcdClear();
//                }
//            }
//        }
//    }
//    else
//    {
//        lcdSetCursor(1,1);
//        sprintf(FirstROW,"RevPerMin: %i",ValorRPMS);
//        lcdPrint(FirstROW);
//        Velocidad = rescale(ValorRPMS,0,100,0,1000);
//        if(Velocidad >=900)
//        {
//            Velocidad = 900;
//        }
//        else if(Velocidad <=0)
//        {
//            Velocidad = 0;
//        }
//        analogWrite(Motor,Velocidad);
//        lcdSetCursor(2,1);
//        sprintf(SecondROW,"Vel(%): %f",Velocidad * 0.1);
//        lcdPrint(SecondROW);
//        Velocidad = kp * Velocidad;
//        if(PBRead(0) == HIGH)
//        {
//            lcdClear();
//            counter = 0;
//        }
//    }
//}
