#ifndef DS1307_H_INCLUDED
#define DS1307_H_INCLUDED

#define DS1307_I2C_ADDRESS 0xD0



typedef struct
{
	uint8_t 	second;
	uint8_t		minute;
	uint8_t		hour;
	uint8_t		dayOfTheWeek;
	uint8_t		dayOfTheMonth;
	uint8_t		month;
	uint8_t		year;
} RtcInfo;

uint8_t decToBcd(uint8_t val);
uint8_t bcdToDec(uint8_t val);
void readRtc(RtcInfo *rtcStruct);
void setRtc(void);
void I2C_requestedDataReadyRtc(uint8_t dataRequestID);


#endif // DS1307_H_INCLUDED
