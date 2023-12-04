//Four Channel Data transmision Exmaple
//Using Pointer in arrays with funcitons or subrutines

//Prededuring File
void WriteDataBytes(uint16_t *ChA, uint16_t *ChB, uint16_t *ChC, uint16_t *ChD)
{
    //For Channel A, Maximum 5 Positions, 8bit data
    //RD0 = Register Clear
    //RD1 = Shift Register Clock
    //RD2 = Shift Register Serialized Data Channel A.
    //RD3 = Shift Register Latch
    //RD4 = Shift Register Ouput Enable.
    //RD5 = Shift Register Serialized Data Channel B.
    //RD6 = Shift Register Serialized Data Channel C.
    //RD7 = Shift Register Serlalized Data Channel D.
    char buffer = 0x00;
    char dataOut = 0x03;
    for(char j=0;j<5;j++)  //Explora Columna
    {
        for(char i=0;i<8;i++) //Explora bit a bit cada byte de cada columna
        {
            buffer = *(ChA + j) << i; // Channel A
            buffer &= 0x80;
            buffer = buffer >> 5;
            dataOut |= buffer;
            buffer = *(ChB + j) << i; //Channel B
            buffer &= 0x80;
            buffer = buffer >> 2;
            dataOut |= buffer;
            buffer = *(ChC + j) << i; // Channel C
            buffer &= 0x80;
            buffer = buffer >> 1;
            dataOut |= buffer;
            buffer = *(ChD + j) << i; //Channel D
            buffer &= 0x80;
            buffer = buffer >> 0;
            dataOut |= buffer;
            PORTD = dataOut;
            __delay_ms(1);
            PORTD &= 0xE5; // Shift Register Clock Off.
            __delay_ms(1);
            dataOut = 0x03;
        }
    }
    PORTD |= 0x08; //End of File Latch Data
    __delay_ms(1);
    PORTD &= 0xF7;
    __delay_ms(1);
}

void WriteDataStream(char Modules, uint16_t (*Matrix)[5])
{
    /*
     *  How can I pass a pointer to a two-dimensional array to a function, 
     * or declare a pointer to a two-dimensional array?
        With a two-dimensional array, 
     * the compiler needs to know how many elements are in a column to 
     * move from one row to the next, but movement within a row is 
     * always by a single element, so the compiler doesn't need to 
     * know the number of rows. Thus the pointer declaration must 
     * include the number of columns in the array:

        char array[2][3] = { "19", "42" };

        void func(char (*p)[3])
        {
            puts(p[1]);      // prints "42"
        }

        func(array);

        * // or 

        char (*p)[3];
        p = array;
    /*
    For Channel A, Maximum 5 Positions, 8bit data
    RD0 = Register Clear
    RD1 = Shift Register Clock
    RD2 = Shift Register Serialized Data Channel A.
    RD3 = Shift Register Latch
    RD4 = Shift Register Ouput Enable.
    RD5 = Shift Register Serialized Data Channel B.
    RD6 = Shift Register Serialized Data Channel C.
    RD7 = Shift Register Serlalized Data Channel D.
    */
    char buffer = 0x00;
    char dataOut = 0x03;
    char PortMap[4] = {5,2,1,0};
    for(char k=0;k<Modules;k++) //Explora Columna
    {
        for(char j=0;j<8;j++) //Exploro bit a bit cada byte de cada Channel
        {
            for(char i=0;i<4;i++) //Se Separa bit a bit cada byte
            {
                // *(Matrix + 0) --> Valor Contenido en el la direccion que 
                // apuna a la primera columna, primer primer Renglon.
                // *(Matrix + 1) --> Valor contenido en la direccion que apunta
                // a la primera columna, segundo renglon.
                // *(Matrix + 2) --> Valor contenido en la direccion que apunta
                // a la primera columna, Tercer  renglon
                // *(Matrix + 3) --> Valor contenido en la direccion que apunta
                // a la primera columna, tercer renglon
                buffer = *(*(Matrix + i)+k) << j;
                buffer &= 0x80;
                buffer = buffer >> PortMap[i];
                dataOut |= buffer;
            }
            PORTD = dataOut;
            __delay_ms(1);
            PORTD &= 0xE5; // Shift Register Clock Off.
            __delay_ms(1);
            dataOut = 0x03;
        } 
    }
    PORTD |= 0x08; //End of File Latch Data
    __delay_ms(1);
    PORTD &= 0xF7;
    __delay_ms(1);
}

//End Proceduring File

//Application file
                            //Last Module ----> First Module
unsigned int ChannelA[5] = {0xAA,0x01,0x02,0x03,0x04};
unsigned int ChannelB[5] = {0x10,0xAA,0x12,0x13,0x14};
unsigned int ChannelC[5] = {0x20,0x21,0xAA,0x23,0x24};
unsigned int  ChannelD[5] = {0x30,0x31,0x32,0xAA,0x34};

unsigned int DataStream[4][5] = {
    {0xAA,0x01,0x02,0x03,0x04},
    {0x10,0xAA,0x12,0x13,0x14},
    {0x20,0x21,0xAA,0x23,0x24},
    {0x30,0x31,0x32,0xAA,0x34}
};

void setup()
{
    //WriteDataBytes(ChannelA,ChannelB,ChannelC, ChannelD);
    WriteDataStream(4,DataStream);
}


void loop()
{
    
}

//End application File