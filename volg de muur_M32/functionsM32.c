#include "RP6ControlLib.h"
#include "functionsM32.h"
#include "CMP_S10_compass.h"

void runningLight(void)
{
    static uint8_t runLight = 1;
	static uint8_t dir;  // Moving direction for running light

	if(getStopwatch1() > 100) // 100ms
	{
		// Set status LEDs to the value of the variable testLEDs:
		setLEDs(runLight);

		// Shift the LED bit left or right depending on direction:
		if(dir == 0)
			runLight <<= 1;
		else
			runLight >>= 1;

		// Change the direction if we reached one of the two outer LEDs:
		if(runLight > 7 )
			dir = 1;
		else if (runLight < 2 )
			dir = 0;

		// Reset Stopwatch1:
		setStopwatch1(0);
	}
}

void readRearDistanceSensors( uint16_t *rearLeft,uint16_t *rearRight)
{
    *rearLeft  = readADC(ADC_3);
    *rearRight = readADC(ADC_2);
}

void printScharpSensorsValues(_ir_distance *sensor)
{
        clearLCD();
        setCursorPosLCD(0,0);
        writeStringLCD("L");
        writeIntegerLCD(sensor->valueLeftFront,DEC);
        setCursorPosLCD(0,5);
        writeStringLCD("DL");
        writeIntegerLCD(sensor->diffLeftSide,DEC);
        setCursorPosLCD(0,12);
        writeStringLCD("R");
        writeIntegerLCD(sensor->valueRightFront,DEC);
        setCursorPosLCD(1,0);
        writeStringLCD("L");
        writeIntegerLCD(sensor->valueLeftRear,DEC);
        setCursorPosLCD(1,5);
        writeStringLCD("DR");
        writeIntegerLCD(sensor->diffRightSide,DEC);
        setCursorPosLCD(1,12);
        writeStringLCD("R");
        writeIntegerLCD(sensor->valueRightRear,DEC);
}

void getSharpSensorInfo( _ir_distance *sensor)
{
    readFrontDistanceSensors(&sensor->valueLeftFront,&sensor->valueRightFront);
    readRearDistanceSensors(&sensor->valueLeftRear,&sensor->valueRightRear);
    sensor->diffLeftSide = sensor->valueLeftRear - sensor->valueLeftFront;
    sensor->diffRightSide= sensor->valueRightRear - sensor->valueRightFront;

}

void printDataToCSharpApplcation (_ir_distance *sensor, uint16_t batteryValue)
{
    _CMP_S10 _compassStruct;
    //ReadCompass(&_compassStruct); // compass module is kapot.
    writeChar('$');
    writeInteger(sensor->valueLeftFront,DEC);
    writeChar(',');
    writeInteger(sensor->valueRightFront,DEC);
    writeChar(',');
    writeInteger(sensor->valueLeftRear,DEC);
    writeChar(',');
    writeInteger(sensor->valueRightRear,DEC);
    writeChar(',');
    writeInteger(sensor->diffRightSide,DEC);
    writeChar(',');
    writeInteger(sensor->diffLeftSide,DEC);
    writeChar(',');
    writeInteger(batteryValue,DEC);
    writeChar(',');
    writeInteger(_compassStruct.CompassBearing,DEC); // deze zal 0 aan geven ivm defecte compas sensor
    writeChar(',');
    writeChar('#');
    writeChar('\n');

}


