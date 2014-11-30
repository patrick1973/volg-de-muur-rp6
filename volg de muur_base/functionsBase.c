#include "RP6RobotBaseLib.h"
#include "RP6I2CslaveTWI.h"     // Include the I²C-Bus Slave Library
#include "functionsBase.h"

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

void readDistanceSensors(uint16_t *sensorValues[])
{
    sensorValues[0] = readADC(ADC_ADC0);
    sensorValues[1] = readADC(ADC_ADC1);
}

void printScharpSensorsValuesFront(uint16_t sensorValues[], uint8_t lenght)
{
    static uint16_t nonBlocking = 0;
    if (nonBlocking >= 1000)
       {
         writeString("Front right : ");
         writeInteger(sensorValues[0],DEC);

          writeString("Front left  : ");
          writeInteger(sensorValues[1],DEC);
          writeString("\n");
          nonBlocking = 0;
       }
       nonBlocking++;
}
uint16_t sensorDifferenceLeftRight(uint16_t *sensorValues[])
{
    return sensorValues[0]-sensorValues[1];
}

