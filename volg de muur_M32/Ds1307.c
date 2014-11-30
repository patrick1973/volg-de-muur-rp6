#include "RP6ControlLib.h" // the control lib
#include "RP6I2CmasterTWI.h"
#include "Ds1307.h"


// Convert normal decimal numbers to binary coded decimal
uint8_t decToBcd(uint8_t val)
{
  return ( (val/10*16) + (val%10) );
}

// Convert binary coded decimal to normal decimal numbers
uint8_t bcdToDec(uint8_t val)
{
  return ( (val/16*10) + (val%16) );
}

void readRtc(RtcInfo *rtcStruct)
{
    static uint8_t counter;
	static uint8_t RTCResult[7];


	if(TWI_operation == I2CTWI_NO_OPERATION)				//if not busy
	{
		if(getStopwatch1() > 100) 							// wait 100ms
		{
		    for ( counter = 0; counter <=7; counter++)
            {
                I2CTWI_transmitByte(DS1307_I2C_ADDRESS,counter);			// what register to read
                RTCResult[counter] = I2CTWI_readByte(DS1307_I2C_ADDRESS);
                writeString_P("De data van de klok\n");
                writeInteger(RTCResult[0],DEC);writeString_P("\n");
                writeInteger(RTCResult[1],DEC);writeString_P("\n");
            }

		setStopwatch1(0);
		}
	}
	rtcStruct->second					=	bcdToDec(RTCResult[0] & 0x7f);
	rtcStruct->minute					=	bcdToDec(RTCResult[1]);
	rtcStruct->hour						=	bcdToDec(RTCResult[2] & 0x3f);
	rtcStruct->dayOfTheWeek	            =	bcdToDec(RTCResult[3]);
	rtcStruct->dayOfTheMonth	        =	bcdToDec(RTCResult[4]);
	rtcStruct->month					=	bcdToDec(RTCResult[5]);
	rtcStruct->year						=	bcdToDec(RTCResult[6]);

}

void setRtc(void)
{
  uint8_t second    =   45; //0-59
  uint8_t minute    =   40; //0-59
  uint8_t hour      =   0;  //0-23
  uint8_t weekDay   =   2;  //1-7
  uint8_t monthDay  =   1;  //1-31
  uint8_t month     =   3;  //1-12
  uint8_t year      =   11; //0-99

  if(TWI_operation == I2CTWI_NO_OPERATION)
  {
      I2CTWI_transmitByte(DS1307_I2C_ADDRESS,0);			//begin transmission
      I2CTWI_transmitByte(DS1307_I2C_ADDRESS,decToBcd(second));
      I2CTWI_transmitByte(DS1307_I2C_ADDRESS,decToBcd(minute));
      I2CTWI_transmitByte(DS1307_I2C_ADDRESS,decToBcd(hour));
      I2CTWI_transmitByte(DS1307_I2C_ADDRESS,decToBcd(weekDay));
      I2CTWI_transmitByte(DS1307_I2C_ADDRESS,decToBcd(monthDay));
      I2CTWI_transmitByte(DS1307_I2C_ADDRESS,decToBcd(month));
      I2CTWI_transmitByte(DS1307_I2C_ADDRESS,decToBcd(year));
  }

}

void I2C_requestedDataReadyRtc(uint8_t dataRequestID)
{
    writeInteger(dataRequestID,DEC);
}
