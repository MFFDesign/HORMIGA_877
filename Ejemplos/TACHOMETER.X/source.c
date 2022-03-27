#include "system.h"

#define MASTER 0x01
#define SLAVE 0x02


int main(void)
{
    Initialization();
    setup();
    while(1)
    {
        loop();
    }
    return 0;
}

void Initialization(void)
{
            //ADCCOnfiguration
    ADCON0 = 0x81; //FOSC/8 Channel 0, ADC ON
    ADCON1 = 0xC2; //RA3,RA2,RA1,RA0 Analogic || Vref+ = VDD, -Vref = Vss
    //PORT A Configuration
    asm("CLRF PORTA"); //All Terminal as Inputs. only RA4 as digital Inpuy
    asm("MOVLW 0x3F");
    asm("MOVWF TRISA");
    //TRISB = 0xFF; //all pins as Ouptus by default and low State
    asm("CLRF PORTB");
    asm("MOVLW 0x00");
    asm("MOVWF TRISB");
    //PORTC Configuration
    asm("CLRF PORTC");
    asm("MOVLW 0x00");
    asm("MOVWF TRISC");
    PWMConfiguration();
    //PORTD Configuration
    asm("CLRF PORTD");
    asm("MOVLW 0x00");
    asm("MOVF TRISD");
    PORTE = 0x00;
    TRISE = 0x00;
}
void PWMConfiguration(void)
{
    PR2 = 0xFF;
    T2CON = 0x05; //Tmier 2 prescaler equals 
    CCP1CON = 0x0C;//0x4F; //0100 1111 //New Value 0000 1100
    CCP2CON = 0x0C;//0x4F;
}

void PWMStop(void)
{
    CCP2CON = 0x00;
    CCP1CON = 0x00;
}

void pinMode(char pin, char mode)
{
    static uint8_t DataPC;
    static uint8_t DataPB;
    static uint8_t DataPD;
    	//	PORT | pin Number : 
	/*
		RC7 - 0       RB0 - 8		RD0 - 16		RA4 - 24
		RC6 - 1		  RB1 - 9		RD1 - 17
		RC5 - 2		  RB2 - 10		RD2 - 18
		RC4 - 3		  RB3 - 11		RD3 - 19
		RC3 - 4		  RB4 - 12		RD4 - 20
		RC2 - 5 (PWM) RB5 - 13		RD5 - 21
		RC1 - 6	(PWM) RB6 - 14		RD6 - 22
		RC0 - 7		  RB7 - 15		RD7 - 23
	*/
    switch(pin)
    {
        case 0:
            TRISCbits.TRISC7 = mode;
            break;
        case 1:
            TRISCbits.TRISC6 = mode;
            break;
        case 2:
            TRISCbits.TRISC5 = mode;
            break;
        case 3:
            TRISCbits.TRISC4 = mode;
            break;
        case 4:
            TRISCbits.TRISC3 = mode;
            break;
        case 5:
            TRISCbits.TRISC2 = mode;
            //CCP1CON = 0x00;      
            break;
        case 6:
            TRISCbits.TRISC1 = mode;
            //CCP2CON = 0x00;
            break;
        case 7:
            TRISCbits.TRISC0 = mode;
            break;
        case 8:
            TRISBbits.TRISB0 = mode;
            break;
        case 9:
            TRISBbits.TRISB1 = mode;
            break;
        case 10:
            TRISBbits.TRISB2 = mode;
            break;
        case 11:
            TRISBbits.TRISB3 = mode;
            break;
        case 12:
            TRISBbits.TRISB4 = mode;
            break;
        case 13:
            TRISBbits.TRISB5 = mode;
            break;
        case 14:
            TRISBbits.TRISB6 = mode;
            break;
        case 15:
            TRISBbits.TRISB7 = mode;
            break;
        case 16:
            TRISDbits.TRISD0 = mode;
            break;
        case 17:
            TRISDbits.TRISD1 = mode;
            break;
        case 18:
            TRISDbits.TRISD2 = mode;
            break;
        case 19:
            TRISDbits.TRISD3 = mode;
            break;
        case 20:
			TRISDbits.TRISD4 = mode;
			/*
            ADCON1bits.PCFG3 = 0;
            ADCON1bits.PCFG2 = 1;
            ADCON1bits.PCFG1 = 0;
            ADCON1bits.PCFG0 = 0;
            TRISAbits.TRISA5 = mode;
            //Analog pin Too Vref+ = VDD Vref- = Vss
            //with this configuration AN2 becomes digitalpin.
            */
			break;
        case 21:
            TRISDbits.TRISD5 = mode;
            break;
        case 22:
            TRISDbits.TRISD6 = mode;
            break;
        case 23:
            TRISDbits.TRISD7 = mode;
            break;      
        case 24:
            TRISAbits.TRISA4 = mode;
            break;
        default:
            if(pin == DPORTB)
            {
                DataPB = mode;
                TRISB = DataPB;
            }
            else if(pin == DPORTC)
            {
                DataPC = mode;
                TRISC = DataPC;
            }
            else if(pin == DPORTD)
            {
                DataPD = mode;
                TRISD = DataPD;
            }
            else if(pin == NIBBLE0TO3)
            {
                mode &= 0x0F;
                DataPC &= 0x0F;
                DataPC |= mode << 4;
                TRISC = DataPC;
            }
            else if(pin == NIBBLE4TO7)
            {
                mode &= 0x0F;
                DataPC &= 0xF0;
                DataPC |= mode;
                TRISC = DataPC;
            }
            else if(pin == NIBBLE8TO11)
            {
                mode &= 0x0F;
                DataPB &= 0xF0;
                DataPB |= mode;
                TRISB = DataPB;
            }
            else if(pin == NIBBLE12TO15)
            {
                mode &= 0x0F;
                DataPB &= 0x0F;
                DataPB |= (mode << 4);
                TRISB = DataPB;
            }
            else if(pin == NIBBLE16TO19)
            {
                mode &= 0x0F;
                DataPD &= 0xF0;
                DataPD |= mode;
                TRISD = DataPD;
            }
            else if(pin == NIBBLE20TO23)
            {
                mode &= 0x0F;
                DataPD &= 0x0F;
                DataPD |= (mode << 4);
                TRISD = DataPD;
            }
            break;
    }
}
void digitalWrite(char pin, char value)
{
    static uint8_t DataPC;
	static uint8_t DataPB;
	static uint8_t DataPD;
    	//	PORT | pin Number : 
	/*
		RC7 - 0       RB0 - 8		RD0 - 16		RA4 - 24
		RC6 - 1		  RB1 - 9		RD1 - 17
		RC5 - 2		  RB2 - 10		RD2 - 18
		RC4 - 3		  RB3 - 11		RD3 - 19
		RC3 - 4		  RB4 - 12		RD4 - 20
		RC2 - 5 (PWM) RB5 - 13		RD5 - 21
		RC1 - 6	(PWM) RB6 - 14		RD6 - 22
		RC0 - 7		  RB7 - 15		RD7 - 23
	*/
    switch(pin)
    {
        case 0:
            PORTCbits.RC7 = value;
            break;
        case 1:
            PORTCbits.RC6 = value;
            break;
        case 2:
            PORTCbits.RC5 = value;
            break;
        case 3:
            PORTCbits.RC4 = value;
            break;
        case 4:
            PORTCbits.RC3 = value;
            break;
        case 5:
            CCP1CON = 0x00; 
            PORTCbits.RC2 = value;
            break;
        case 6:
            CCP2CON = 0x00;
            PORTCbits.RC1 = value;
            break;
        case 7:
            PORTCbits.RC0 = value;
            break;
        case 8:
            PORTBbits.RB0 = value;
            break;
        case 9:
            PORTBbits.RB1 = value;
            break;
        case 10:
            PORTBbits.RB2 = value;
            break;
        case 11:
            PORTBbits.RB3 = value;
            break;
        case 12:
            PORTBbits.RB4 = value;
            break;
        case 13:
            PORTBbits.RB5 = value;
            break;
        case 14:
            PORTBbits.RB6 = value;
            break;
        case 15:
            PORTBbits.RB7 = value;
            break;
        case 16:
            PORTDbits.RD0 = value;
            break;
        case 17:
            PORTDbits.RD1 = value;
            break;
        case 18:
            PORTDbits.RD2 = value;
            break;
        case 19:
            PORTDbits.RD3 = value;
            break;
        case 20:
            PORTDbits.RD4 = value;
            break;
        case 21:
            PORTDbits.RD5 = value;
            break;
        case 22:
            PORTDbits.RD6 = value;
            break;
        case 23:
            PORTDbits.RD7 = value;
            break;
        case 24:
            PORTAbits.RA4 = value;
            break;
        default:
            if(pin == DPORTB)
            {
                DataPB = value;
                PORTB = DataPB;
            }
            else if(pin == DPORTC)
            {
                DataPC = value;
                PORTC = DataPC;
            }
            else if(pin == DPORTD)
            {
                DataPD = value;
                PORTD = DataPD;
            }
            else if(pin == NIBBLE0TO3)
            {
                value &= 0x0F;
                DataPC &= 0x0F;
                DataPC |= value << 4;
                PORTC = DataPC;
            }
            else if(pin == NIBBLE4TO7)
            {
                value &= 0x0F;
                DataPC &= 0xF0;
                DataPC |= value;
                PORTC = DataPC;
            }
            else if(pin == NIBBLE8TO11)
            {
                value &= 0x0F;
                DataPB &= 0xF0;
                DataPB |= value;
                PORTB = DataPB;
            }
            else if(pin == NIBBLE12TO15)
            {
                value &= 0x0F;
                DataPB &= 0x0F;
                DataPB |= (value << 4);
                PORTB = DataPB;
            }
            else if(pin == NIBBLE16TO19)
            {
                value &= 0x0F;
                DataPD &= 0xF0;
                DataPD |= value;
                PORTD = DataPD;
            }
            else if(pin == NIBBLE20TO23)
            {
                value &= 0x0F;
                DataPD &= 0x0F;
                DataPD |= (value << 4);
                PORTD = DataPD;
            }
            break;
    }
}
char digitalRead(char pin)
{
    switch(pin)
    {
        case 0:
             return PORTCbits.RC7;
            break;
        case 1:
            return PORTCbits.RC6;
            break;
        case 2:
            return PORTCbits.RC5;
            break;
        case 3:
            return PORTCbits.RC4;
            break;
        case 4:
            return PORTCbits.RC3;
            break;
        case 5:
            return PORTCbits.RC2;
            break;
        case 6:
            return PORTCbits.RC1;
            break;
        case 7:
            return PORTCbits.RC0;
            break;
        case 8:
            return PORTBbits.RB0;
            break;
        case 9:
            return PORTBbits.RB1;
            break;
        case 10:
            return PORTBbits.RB2;
            break;
        case 11:
            return PORTBbits.RB3;
            break;
        case 12:
            return PORTBbits.RB4;
            break;
        case 13:
            return PORTBbits.RB5;
            break;
        case 14:
            return PORTBbits.RB6;
            break;
        case 15:
            return PORTBbits.RB7;
            break;
        case 16:
            return PORTDbits.RD0;
            break;
        case 17:
            return PORTDbits.RD1;
            break;
        case 18:
            return PORTDbits.RD2;
            break;
        case 19:
            return PORTDbits.RD3;
            break;
        case 20:
            return PORTDbits.RD4;
            break;
        case 21:
            return PORTDbits.RD5;
            break;
        case 22:
            return PORTDbits.RD6;
            break;
        case 23:
            return PORTDbits.RD7;
            break;
        case 24:
            return PORTAbits.RA4;
            break;
			/*
        case 25:
            return PORTDbits.RD0;
            break;
        case 26:
            return PORTAbits.RA2;
            break;
			*/
    }
}
unsigned int analogRead(char channel)
{
    switch(channel)
    {
        case 0:
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
        case 1:
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 1;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
        case 2:
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 0;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
        case 3:
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 1;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
        case 4:
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
    }
}
uint8_t analogWrite(char pin, unsigned int value)
{
    char MSB = 0;
    switch(pin)
    {
        case 6://CCP2
            //TRISCbits.TRISC1 = 0;
            CCPR2L = value >> 2;
            CCP2X = value & 2;
            CCP2Y = value & 1;  
            break;
        case 5://CCP1
            TRISCbits.TRISC2 = 0;
            CCPR1L = value >> 2;
            CCP1X = value & 2;
            CCP1Y = value & 1;
            break;
    }
    return 0;
}
char PBRead(char pin)
{
    switch(pin)
    {
        case 0:
            return PORTEbits.RE0;
            break;
        case 1:
            return PORTEbits.RE1;
            break;
        case 2:
            return PORTEbits.RE2;
            break;
    }
}
double rescale(double x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

char SerialBegin(const long int BaudRate)
{
	/*
		BaudRate = _XTAL_FREQ / (64 * (SPBRG + 1))
	*/
	unsigned  int x;
	BRGH = 0;
	x = (_XTAL_FREQ / (64 * BaudRate)) - 1;
	if(x > 255)
	{
		BRGH = 1;
		x = (_XTAL_FREQ / (16 * BaudRate)) - 1;
		SPBRG = x;
		SYNC = 0;
		SPEN = 1;                                     //Enables Serial Port
		TRISC7 = 1;                                   //As Prescribed in Datasheet
		TRISC6 = 1;                                   //As Prescribed in Datasheet
		CREN = 1;                                     //Enables Continuous Reception
		TXEN = 1;
        TXREG = 0x00;
        RCREG = 0x00;
		return 0;
	}
	else
	{
		SPBRG = x;
		SYNC = 0;
		SPEN = 1;                                     //Enables Serial Port
		TRISC7 = 1;                                   //As Prescribed in Datasheet
		TRISC6 = 1;                                   //As Prescribed in Datasheet
		CREN = 1;                                     //Enables Continuous Reception
		TXEN = 1;
        TXREG = 0x00;
        RCREG = 0x00;
		return 1;
	}
}
uint8_t IsNumber(char data)
{
    if(data >= 0x30 && data <= 0x39)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char TxRegisterFull(void)
{
    return TRMT;
}
char SerialErrors(void)
{
    if((FERR == 1) && (FERR || OERR)) //Framing Error
    {
        return 1;
    }
    else if((OERR == 1) && (FERR || OERR)) //OverRun Error
    {
        return 2;
    }
    else if(OERR && FERR) 
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
void SerialWrite(char dataWrite)
{
    while(!TXIF);
    TXREG = dataWrite;
}

char SerialWriteText(char *dataText)
{
    unsigned int i;
    for(i=0;dataText[i]!='\0';i++)
    {
       SerialWrite(dataText[i]); 
    }
}
void SerialPrint(char *dataText)
{
    for(unsigned int i=0;dataText[i]!='\0';i++)
    {
        SerialWrite(dataText[i]);
    }
}
void SerialPrintLn(char *dataText)
{
    unsigned int i;
        for(i=0;dataText[i]!='\0';i++)
        {
            SerialWrite(dataText[i]);
        }
        SerialWrite(0x0A);
}
char SerialAvailable(void)
{
    return RCIF || (TXIF && TRMT);
}

char SerialRead(void)
{
    while(!RCIF);
    return RCREG;
}

void SerialReadText(char *Output, unsigned int lenght)
{
    unsigned int i;
    for(i=0;i<lenght;i++)
    {
        Output[i] = SerialRead();
    }
}

void I2CBegin(char Operation, const unsigned long param)
{
    switch(Operation)
    {
        case MASTER:
            SSPCON = 0b00101000;            //SSP Module as Master
            SSPCON2 = 0;
            SSPADD = (_XTAL_FREQ/(4*param))-1; //Setting Clock Speed
            SSPSTAT = 0;
            TRISC3 = 1;                   //Setting as input as given in datasheet
            TRISC4 = 1;    
            break;
        case SLAVE:
            SSPSTAT = 0x80;    
            SSPADD = param; //Setting address
            SSPCON = 0x36;    //As a slave device
            SSPCON2 = 0x01;
            TRISC3 = 1;       //Setting as input as given in datasheet
            TRISC4 = 1;       //Setting as input as given in datasheet
            GIE = 1;          //Global interrupt enable
            PEIE = 1;         //Peripheral interrupt enable
            SSPIF = 0;        //Clear interrupt flag
            SSPIE = 1;        //Synchronous serial port interrupt enable
            break;
    }
}
void I2CMasterWaiting()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)); //Transmit is in progress
}

void I2CMasterStart()
{
  I2CMasterWaiting();    
  SEN = 1;             //Initiate start condition
}
void I2CMasterRepeatedStart()
{
  I2CMasterWaiting();
  RSEN = 1;           //Initiate repeated start condition
}
void I2CMasterStop()
{
  I2CMasterWaiting();
  PEN = 1;           //Initiate stop condition
}
void I2CMasterWrite(unsigned d)
{
  I2CMasterWaiting();
  SSPBUF = d;         //Write data to SSPBUF
}

unsigned short I2CMasterRead(unsigned short a)
{
  unsigned short temp;
  I2CMasterWaiting();
  RCEN = 1;
  I2CMasterWaiting();
  temp = SSPBUF;      //Read data from SSPBUF
  I2CMasterWaiting();
  ACKDT = (a)?0:1;    //Acknowledge bit
  ACKEN = 1;          //Acknowledge sequence
  return temp;
}

void delay(const int milis)
{
    for(int j=0;j<milis;j++)
    {
        //Retardo de 1ms
        for(int i=0;i<236;i++)
        {
            asm("NOP");
        }
    }
}

void delayMicroseconds(const int us)
{
    for(char i=0;i<us;i++)
    {
        asm("NOP");
    }
}