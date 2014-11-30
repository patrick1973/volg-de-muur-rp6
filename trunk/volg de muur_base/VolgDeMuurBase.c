#include "RP6RobotBaseLib.h"
#include "RP6I2CslaveTWI.h"     // Include the I²C-Bus Slave Library
#include "functionsBase.h"
#include "I2Cslave.h"

uint16_t sensorWaardes[4] = {0,0,0,0};
int differenceFront;
int main(void)
{
    initRobotBase();
    I2CTWI_initSlave(RP6BASE_I2C_SLAVE_ADR);

    ACS_setStateChangedHandler(acsStateChanged);
	BUMPERS_setStateChangedHandler(bumpersStateChanged);
	MOTIONCONTROL_setStateChangedHandler(motionControlStateChanged);

    powerON();                  // schakel de encoders ed aan

	startStopwatch1();

    disableACS();
	setACSPwrOff();

	status.byte = 0;             //zet de hele union op 0
	interrupt_status.byte = 0;   //zet de hele union op 0
	drive_status.byte=0;         //zet de hele union op 0

	status.watchDogTimer = false;
	status.wdtRequest = false;

	startStopwatch3();
	startStopwatch4();


	for(;;)
	{
	    task_commandProcessor();
	    task_update();
	    task_updateRegisters();
	    task_RP6System();
	    task_MasterTimeout();





//        //printScharpSensorsValuesFront(sensorWaardes,4);
//        //runningLight();
//        readDistanceSensors(sensorWaardes);
//        differenceFront = sensorDifferenceLeftRight(sensorWaardes);
//         writeInteger(differenceFront,DEC);
//         writeString("\n");
    }
	return 0;
}
