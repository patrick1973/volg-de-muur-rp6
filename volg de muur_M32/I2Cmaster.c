#include "RP6ControlLib.h"
#include "RP6I2CmasterTWI.h"
#include "I2Cmaster.h"


void I2C_transmissionError(uint8_t errorState)
{
    switch(errorState)
	{
	case 0x08:	writeString_P("\nI2C ERROR - 0x08 START has been transmitted\n"); break;
	case 0x10: 	writeString_P("\nI2C ERROR - 0x10 Repeated START has been transmitted\n"); break;
	case 0x38: 	writeString_P("\nI2C ERROR - 0x38 Arbitration lost\n"); break;
	case 0x20: 	writeString_P("\nI2C ERROR - 0x20 SLA+W has been transmitted and NACK received\n"); break;
	case 0x18: 	writeString_P("\nI2C ERROR - 0x18 SLA+W has been transmitted and ACK received\n"); break;
	case 0x28: 	writeString_P("\nI2C ERROR - 0x28 Data byte has been transmitted and ACK received\n"); break;
	case 0x30: 	writeString_P("\nI2C ERROR - 0x30 Data byte has been transmitted and NACK received\n"); break;
	case 0x40: 	writeString_P("\nI2C ERROR - 0x40 SLA+R has been transmitted and ACK received\n"); break;
	case 0x48:	writeString_P("\nI2C ERROR - 0x48 SLA+R has been transmitted and NACK received\n"); break;
	case 0x50: 	writeString_P("\nI2C ERROR - 0x50 Data byte has been received and ACK transmitted\n"); break;
	case 0x58: 	writeString_P("\nI2C ERROR - 0x58 Data byte has been received and NACK transmitted\n"); break;
	case 0xA8: 	writeString_P("\nI2C ERROR - 0xA8 Own SLA+R has been received; ACK has been returned\n"); break;
	case 0xB0: 	writeString_P("\nI2C ERROR - 0xB0 Arbitration lost in SLA+R/W as Master; own SLA+R has been received; ACK has been returned\n"); break;
	case 0xB8: 	writeString_P("\nI2C ERROR - 0xB8 Data byte in TWDR has been transmitted; ACK has been received\n"); break;
	case 0xC0: 	writeString_P("\nI2C ERROR - 0xC0 Data byte in TWDR has been transmitted; NOT ACK has been received\n"); break;
	case 0xC8: 	writeString_P("\nI2C ERROR - 0xC8 Last data byte in TWDR has been transmitted (TWEA = “0”); ACK has been received\n"); break;
	case 0x60:	writeString_P("\nI2C ERROR - 0x60 Own SLA+W has been received ACK has been returned\n"); break;
	case 0x68: 	writeString_P("\nI2C ERROR - 0x68 Arbitration lost in SLA+R/W as Master; own SLA+W has been received; ACK has been returned\n"); break;
	case 0x70: 	writeString_P("\nI2C ERROR - 0x70 General call address has been received; ACK has been returned\n"); break;
	case 0x78: 	writeString_P("\nI2C ERROR - 0x78 Arbitration lost in SLA+R/W as Master; General call address has been received; ACK has been returned\n"); break;
	case 0x80: 	writeString_P("\nI2C ERROR - 0x80 Previously addressed with own SLA+W; data has been received; ACK has been returned\n"); break;
	case 0x88: 	writeString_P("\nI2C ERROR - 0x88 Previously addressed with own SLA+W; data has been received; NOT ACK has been returned\n"); break;
	case 0x90: 	writeString_P("\nI2C ERROR - 0x90 Previously addressed with general call; data has been received; ACK has been returned\n"); break;
	case 0x98: 	writeString_P("\nI2C ERROR - 0x98 Previously addressed with general call; data has been received; NOT ACK has been returned\n"); break;
	case 0xA0:	writeString_P("\nI2C ERROR - 0xA0 A STOP condition or repeated START condition has been received while still addressed as Slave\n"); break;
	case 0xF8: 	writeString_P("\nI2C ERROR - 0xF8 No relevant state information available; TWINT = “0”\n"); break;
	case 0x00: 	writeString_P("\nI2C ERROR - 0x00 Bus error due to an illegal START or STOP condition\n"); break;
	default	 :	writeString_P("\nAll oke\n"); break;
	}
}

    /*****************************************************************************/
// Read all registers function

uint8_t RP6data[32]; // This array will contain all register values of RP6
					 // after you called readAllRegisters()

					 // It is better to keep such big arrays GLOBAL as
					 // they otherwise fill up the stack in memory...

void readAllRegisters(void)
{

	I2CTWI_transmitByte(I2C_RP6_BASE_ADR, 0);       // Start with register 0...
	I2CTWI_readBytes(I2C_RP6_BASE_ADR,RP6data, 30); // and read all 30 registers up to
													// register Number 29 !

	// Now we output the Data we have just read on the serial interface:
	writeString_P("\nREADING ALL RP6 REGISTERS:");
	uint8_t i = 0;
	for(i = 0; i < 30; i++)
	{
		if(i % 8 == 0) 		  // add some newline chars otherwise everything
        {
            writeChar('\n');  // is printed on ONE single line...
        }
		else
        {
           writeString_P(" | ");
        }

        writeChar('#');
        writeIntegerLength(i,DEC,2);
        writeChar(':');
        writeIntegerLength(RP6data[i],DEC,3);
	}
	writeChar('\n');
}



void readFrontDistanceSensors(uint16_t *frontLeft,uint16_t *frontRight )
{
    uint8_t tempArray[3];
//        I2C_REG_ADC_ADC0_L 		 23
//        I2C_REG_ADC_ADC0_H 		 24
//        I2C_REG_ADC_ADC1_L 		 25
//        I2C_REG_ADC_ADC1_H 		 26
        I2CTWI_transmitByte(I2C_RP6_BASE_ADR, 23);          // Start with register 23...
        I2CTWI_readBytes(I2C_RP6_BASE_ADR,tempArray, 4);    // lees de 4 bytes van ADC0_L ADC0_H ADC1L ADC1_H

        *frontLeft  = ((tempArray[1]<<8)+tempArray[0]); //combineer de lage en de hoge byte tot 1 16 bit int
        *frontRight = ((tempArray[3]<<8)+tempArray[2]);
}

uint16_t getbatteryLevel()
{
    uint8_t tempArray[2];
    I2CTWI_transmitByte(I2C_RP6_BASE_ADR, 21);          // Start with register 21...
    I2CTWI_readBytes(I2C_RP6_BASE_ADR,tempArray, 2);    // lees de 2 bytes

    return ((tempArray[1]<<8)+tempArray[0]);
}

uint16_t getMotorLeftCurrent()
{
    uint8_t tempArray[2];
    I2CTWI_transmitByte(I2C_RP6_BASE_ADR, 17);          // Start with register 17...
    I2CTWI_readBytes(I2C_RP6_BASE_ADR,tempArray, 2);    // lees de 2 bytes

    return ((tempArray[1]<<8)+tempArray[0]);
}

uint16_t getMotorRightCurrent()
{
    uint8_t tempArray[2];
    I2CTWI_transmitByte(I2C_RP6_BASE_ADR, 19);          // Start with register 19...
    I2CTWI_readBytes(I2C_RP6_BASE_ADR,tempArray, 2);    // lees de 2 bytes

    return ((tempArray[1]<<8)+tempArray[0]);
}

uint8_t transmit_buffer[10]; // temporary transmit buffer
							 // A global variable saves space on the heap...


void moveAtSpeed(uint8_t desired_speed_left, uint8_t desired_speed_right)
{
    transmit_buffer[0] = 0;
	transmit_buffer[1] = CMD_MOVE_AT_SPEED;
	transmit_buffer[2] = desired_speed_left;
	transmit_buffer[3] = desired_speed_right;
	transmit_buffer[4] = 0;
	transmit_buffer[5] = 0;
	I2CTWI_transmitBytes(I2C_RP6_BASE_ADR, transmit_buffer, 6 );
}

void RP6_rotate(uint8_t desired_speed, uint8_t dir, uint16_t angle)
{
	transmit_buffer[0] = 0;
	transmit_buffer[1] = CMD_ROTATE;
	transmit_buffer[2] = desired_speed;
	transmit_buffer[3] = dir;
	transmit_buffer[4] = ((angle>>8) & 0xFF);
	transmit_buffer[5] = (angle & 0xFF);
	I2CTWI_transmitBytes(I2C_RP6_BASE_ADR, transmit_buffer, 6 );
}
