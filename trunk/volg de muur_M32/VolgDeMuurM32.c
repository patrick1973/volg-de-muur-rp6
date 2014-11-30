#include "RP6ControlLib.h"
#include "RP6I2CmasterTWI.h"
#include "functionsM32.h"
#include "I2Cmaster.h"
#include "PIDcontrol.h"
#include "CMP_S10_compass.h"
#include <string.h>

double pid;
char arrayString[20] = "patrick 1973";
_ir_distance sharpSensor;   // struct voor IR sensoren
_Values pidValues;          // struct voor PID regelaar
_CMP_S10 compassModule;     // struct voor compass module

void taskFrontSensors(void);

void taskFrontSensors(void)
{
    if (getStopwatch2() > 1000)
    {
        //ReadCompass(&compassModule); // module is kapot
        getSharpSensorInfo(&sharpSensor);
        printScharpSensorsValues(&sharpSensor);
        printDataToCSharpApplcation (&sharpSensor,getbatteryLevel());
        setStopwatch2(0);

    }
}


int main(void)
{

    portInit(); // na een koude start moeten de poorten goed geinit worden.

    I2CTWI_setTransmissionErrorHandler(I2C_transmissionError);

	initRP6Control();		// Initialize extension board processor
	initLCD();				// Initialize the LC-Display (LCD)
	I2CTWI_initMaster(100);

	startStopwatch1();
	startStopwatch2();
	startStopwatch4(); // wordt gebruikt door de compass module

	for(;;)
	{
	    pidValues.kpFactor      = 0.5;
        pidValues.tdFactor      = 0.0;
        pidValues.tiFactor      = 500.0;
        pidValues.pocessValue   = (double)sharpSensor.diffRightSide;
        pidValues.setpoint      = 0.0;
        pidValues.lowBound      = -20.0;
        pidValues.upBound       = 20.0;


        taskFrontSensors();
        runningLight();
        //moveAtSpeed(80,20);


//
//        if ( pidValues.pidOutput < -10.0)
//        {
//           // RP6_rotate(40,LEFT,((int16_t)pidValues.pidOutput* -1.0));
//           writeString("kleiner dan 10");
//           writeString("\n");
//        }
//        else if  ( pidValues.pidOutput > 10.0)
//        {
//           // RP6_rotate(40,RIGHT,(int16_t)pidValues.pidOutput);
//           writeString("groter dan 10");
//           writeString("\n");
//        }
//        else
//        {
//            //moveAtSpeed(40,40);
//            writeString("rond de 0");
//           writeString("\n");
//
//        }
//        writeChar('\n');
    }
	return 0;
}
