#ifndef CMP_S10_COMPASS_H_INCLUDED
#define CMP_S10_COMPASS_H_INCLUDED

// define addresses of I2C Compass
#define CMPS10	0xC0

typedef struct compass
{
	signed char  CompassSoftwareVersion;
	signed char  CompassBearingByte;
	signed char  CompassPitch;
	signed char  CompassRoll;
	unsigned int CompassBearing;
	unsigned int CompassMagX;
	unsigned int CompassMagY;
	unsigned int CompassMagZ;
	unsigned int CompassAccX;
	unsigned int CompassAccY;
	unsigned int CompassAccZ;
}_CMP_S10;

void ReadCompass(_CMP_S10 *compassStruct);
void writeSerialCompass(_CMP_S10 *compassStruct);
void WriteLCD(_CMP_S10 *compassStruct);

#endif // CMP_S10_COMPASS_H_INCLUDED
