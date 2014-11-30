#include "RP6ControlLib.h"
#include "RP6I2CmasterTWI.h"
#include "CMP_S10_compass.h"

void ReadCompass(_CMP_S10 *compassStruct)
{
	static signed char teller;
	static signed char CompassResult[22];

	if(TWI_operation == I2CTWI_NO_OPERATION)
	{
		if(getStopwatch4() > 100) // 100ms
		{
			for (teller=0; teller <=21; ++teller)
			{
				I2CTWI_transmitByte(CMPS10,teller);
				CompassResult[teller]= I2CTWI_readByte(CMPS10);
			}
		setStopwatch4(0);
		}
	}

	compassStruct->CompassSoftwareVersion= CompassResult[0];
	compassStruct->CompassBearingByte 	= CompassResult[1];
	compassStruct->CompassPitch			= CompassResult[4];
	compassStruct->CompassRoll			= CompassResult[5];
	compassStruct->CompassBearing		= ((CompassResult[2]<<8)+ CompassResult[3]); // schuif de highbyte op en zet de low byte er bij
	compassStruct->CompassMagX			= ((CompassResult[10]<<8)+CompassResult[11]);
	compassStruct->CompassMagY			= ((CompassResult[12]<<8)+CompassResult[13]);
	compassStruct->CompassMagZ			= ((CompassResult[14]<<8)+CompassResult[15]);
	compassStruct->CompassAccX			= ((CompassResult[16]<<8)+CompassResult[17]);
	compassStruct->CompassAccY			= (( CompassResult[18]<<8)+CompassResult[19]);
	compassStruct->CompassAccZ			= ((CompassResult[20]<<8)+CompassResult[21]);
}

void writeSerialCompass(_CMP_S10 *compassStruct)
{
    writeString_P("\f");
	writeString_P("Compass Software Version = ");	writeInteger(compassStruct->CompassSoftwareVersion,DEC); writeString_P("\n");
	writeString_P("Compass Bearing Byte     = ");	writeInteger(compassStruct->CompassBearingByte,DEC); writeString_P("\n");
	writeString_P("Compass Bearing          = ");	writeInteger(compassStruct->CompassBearing,DEC); writeString_P("\n");
	writeString_P("Compass Pitch			= ");	writeInteger(compassStruct->CompassPitch,DEC); writeString_P("\n");
	writeString_P("Compass Roll 			= ");	writeInteger(compassStruct->CompassRoll,DEC); writeString_P("\n");
	writeString_P("Compass Magnetometer X 	= ");	writeInteger(compassStruct->CompassMagX,DEC); writeString_P("\n");
	writeString_P("Compass Magnetometer Y 	= ");	writeInteger(compassStruct->CompassMagY,DEC); writeString_P("\n");
	writeString_P("Compass Magnetometer Z 	= ");	writeInteger(compassStruct->CompassMagZ,DEC); writeString_P("\n");
	writeString_P("Compass Accelerometer X 	= ");	writeInteger(compassStruct->CompassAccX,DEC); writeString_P("\n");
	writeString_P("Compass Accelerometer Y 	= ");	writeInteger(compassStruct->CompassAccY,DEC); writeString_P("\n");
	writeString_P("Compass Accelerometer Z 	= ");	writeInteger(compassStruct->CompassAccZ,DEC); writeString_P("\n");
}

void WriteLCD(_CMP_S10 *compassStruct)
{
		setCursorPosLCD(0,0);
		clearLCD();
		writeStringLCD_P("B=");
		setCursorPosLCD(0,2);
		writeIntegerLCD((compassStruct->CompassBearing/10),DEC);
		writeCharLCD('.');
		writeIntegerLCD((compassStruct->CompassBearing%10),DEC);
		setCursorPosLCD(0,7);
		writeStringLCD_P("P");
		writeIntegerLCD(compassStruct->CompassPitch,DEC);
		setCursorPosLCD(0,12);
		writeStringLCD_P("R");
		writeIntegerLCD(compassStruct->CompassRoll,DEC);
		setCursorPosLCD(1,0);
}

