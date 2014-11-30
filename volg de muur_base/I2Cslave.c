#include "RP6RobotBaseLib.h"
#include "RP6I2CslaveTWI.h"     // Include the I²C-Bus Slave Library
#include "I2Cslave.h"

uint16_t uBat_measure = 720;
uint8_t  uBat_count = 0;

uint8_t cmd;
uint8_t param1;
uint8_t param2;
uint8_t param3;
uint8_t param4;
uint8_t param5;
uint8_t param6;

uint8_t leds = 1;

/**
 * Generates Interrupt Signal and starts Software Watchdog
 */
void signalInterrupt(void)
{
	I2CTWI_dataWasRead = 0;
	extIntON();
	if(status.watchDogTimer)
		startStopwatch2();
}

/**
 * Clears Interrupt
 */
void clearInterrupt(void)
{
	stopStopwatch2();
	setStopwatch2(0);
	status.wdtRequest = false;
	interrupt_status.RC5reception = false;
	interrupt_status.driveSystemChange = false;
	extIntOFF();
}

/**
 * ACS Event Handler
 */
void acsStateChanged(void)
{
	interrupt_status.obstacleLeft = obstacle_left;
	interrupt_status.obstacleRight = obstacle_right;
	signalInterrupt();
}

/**
 * Bumpers Event Handler
 */
void bumpersStateChanged(void)
{
	interrupt_status.bumperLeft = bumper_left;
	if(bumper_right)
		interrupt_status.bumperRight = true;
	else
		interrupt_status.bumperRight = false;
	signalInterrupt();
}

/**
 * Motion Control Event Handler
 */
void motionControlStateChanged(void)
{
	drive_status.movementComplete = isMovementComplete();
	drive_status.motorOvercurrent = motion_status.overcurrent;
	interrupt_status.driveSystemChange = true;
	signalInterrupt();
}

/**
 * This function needs to be called frequently in the main loop. It updates
 * some values (currently only Battery Voltage and Motor status, but this may
 * be expanded in future).
 */
void task_update(void)
{
	if(getStopwatch4() > 250)
	{
		uBat_measure += adcBat;
		uBat_measure /= 2;
		uBat_count++;
		setStopwatch2(0);
	}
	if(uBat_count > 5)
	{
		if(!interrupt_status.batLow && uBat_measure < 560)
		{
			interrupt_status.batLow = true;
			signalInterrupt();
		}
		else if(interrupt_status.batLow && uBat_measure > 580)
		{
			interrupt_status.batLow = false;
			signalInterrupt();
		}
		uBat_count = 0;
	}

	drive_status.motorsOn = (mleft_power || mright_power);
	drive_status.direction = getDirection();
}
/**
 * This very important function updates ALL registers that the Master can read.
 * It is called frequently out of the Main loop.
 */
void task_updateRegisters(void)
{
	if(!I2CTWI_readBusy)
	{
		I2CTWI_readRegisters[I2C_REG_STATUS1] = 		 (uint8_t)(interrupt_status.byte);
		I2CTWI_readRegisters[I2C_REG_STATUS2] = 		 (uint8_t)(status.byte);
		I2CTWI_readRegisters[I2C_REG_MOTION_STATUS] = 	 (uint8_t)(drive_status.byte);
		I2CTWI_readRegisters[I2C_REG_POWER_LEFT] = 		 (uint8_t)(mleft_power);
		I2CTWI_readRegisters[I2C_REG_POWER_RIGHT] = 	 (uint8_t)(mright_power);
		I2CTWI_readRegisters[I2C_REG_SPEED_LEFT] = 		 (uint8_t)(getLeftSpeed());
		I2CTWI_readRegisters[I2C_REG_SPEED_RIGHT] = 	 (uint8_t)(getRightSpeed());
		I2CTWI_readRegisters[I2C_REG_DES_SPEED_LEFT] = 	 (uint8_t)(getDesSpeedLeft());
		I2CTWI_readRegisters[I2C_REG_DES_SPEED_RIGHT] =  (uint8_t)(getDesSpeedRight());
		I2CTWI_readRegisters[I2C_REG_DIST_LEFT_L] = 	 (uint8_t)(getLeftDistance());
		I2CTWI_readRegisters[I2C_REG_DIST_LEFT_H] = 	 (uint8_t)(getLeftDistance()>>8);
		I2CTWI_readRegisters[I2C_REG_DIST_RIGHT_L] = 	 (uint8_t)(getRightDistance());
		I2CTWI_readRegisters[I2C_REG_DIST_RIGHT_H] = 	 (uint8_t)(getRightDistance()>>8);
		I2CTWI_readRegisters[I2C_REG_ADC_LSL_L] = 		 (uint8_t)(adcLSL);
		I2CTWI_readRegisters[I2C_REG_ADC_LSL_H] =	 	 (uint8_t)(adcLSL>>8);
		I2CTWI_readRegisters[I2C_REG_ADC_LSR_L] = 		 (uint8_t)(adcLSR);
		I2CTWI_readRegisters[I2C_REG_ADC_LSR_H] = 		 (uint8_t)(adcLSR>>8);
		I2CTWI_readRegisters[I2C_REG_ADC_MOTOR_CURL_L] = (uint8_t)(adcMotorCurrentLeft);
		I2CTWI_readRegisters[I2C_REG_ADC_MOTOR_CURL_H] = (uint8_t)(adcMotorCurrentLeft>>8);
		I2CTWI_readRegisters[I2C_REG_ADC_MOTOR_CURR_L] = (uint8_t)(adcMotorCurrentRight);
		I2CTWI_readRegisters[I2C_REG_ADC_MOTOR_CURR_H] = (uint8_t)(adcMotorCurrentRight>>8);
		I2CTWI_readRegisters[I2C_REG_ADC_UBAT_L] = 		 (uint8_t)(adcBat);
		I2CTWI_readRegisters[I2C_REG_ADC_UBAT_H] = 		 (uint8_t)(adcBat>>8);
		I2CTWI_readRegisters[I2C_REG_ADC_ADC0_L] = 		 (uint8_t)(adc0);
		I2CTWI_readRegisters[I2C_REG_ADC_ADC0_H] = 		 (uint8_t)(adc0>>8);
		I2CTWI_readRegisters[I2C_REG_ADC_ADC1_L] = 		 (uint8_t)(adc1);
		I2CTWI_readRegisters[I2C_REG_ADC_ADC1_H] = 		 (uint8_t)(adc1>>8);
		I2CTWI_readRegisters[I2C_REG_LEDS] = 			 (uint8_t)(statusLEDs.byte);
		//I2CTWI_readRegisters[I2C_REG_RC5_ADR] = 		 (uint8_t)((lastRC5Reception.device)|(lastRC5Reception.toggle_bit<<5));
		//I2CTWI_readRegisters[I2C_REG_RC5_DATA] = 		 (uint8_t)(lastRC5Reception.key_code);
		if(I2CTWI_dataWasRead && I2CTWI_dataReadFromReg == 0)
			clearInterrupt();
	}
}

/**
 * Checks if a new Command has been received and also reads all
 * paramters associated with this command.
 * It returns true if a new command has been received.
 */
uint8_t getCommand(void)
{
	if(I2CTWI_writeRegisters[I2C_REGW_CMD] && !I2CTWI_writeBusy)
	{
		cmd = I2CTWI_writeRegisters[I2C_REGW_CMD]; // store command register
		I2CTWI_writeRegisters[I2C_REGW_CMD] = 0; // clear command register (!!!)
		param1 = I2CTWI_writeRegisters[I2C_REGW_CMD_PARAM1]; // parameters 1-6...
		param2 = I2CTWI_writeRegisters[I2C_REGW_CMD_PARAM2];
		param3 = I2CTWI_writeRegisters[I2C_REGW_CMD_PARAM3];
		param4 = I2CTWI_writeRegisters[I2C_REGW_CMD_PARAM4];
		param5 = I2CTWI_writeRegisters[I2C_REGW_CMD_PARAM5];
		param6 = I2CTWI_writeRegisters[I2C_REGW_CMD_PARAM6];
		return true;
	}
	return false;
}

/**
 * This function checks if commands have been received and processes them.
 */
void task_commandProcessor(void)
{
	if(getCommand())
	{
		switch(cmd)
		{
			case CMD_POWER_OFF:	powerOFF(); status.powerOn = false; break;
			case CMD_POWER_ON:  powerON(); status.powerOn = true; break;
			case CMD_CONFIG: break;
			case CMD_SETLEDS: setLEDs(param1); break;
			case CMD_STOP: stop(); break;
			case CMD_MOVE_AT_SPEED: moveAtSpeed(param1, param2); break;
			case CMD_CHANGE_DIR: changeDirection(param1); break;
			case CMD_MOVE: move(param1, param2, ((param3<<8)+param4), false); break;
			case CMD_ROTATE: rotate(param1, param2, ((param3<<8)+param4), false); break;
			case CMD_SET_ACS_POWER:
				switch(param1)
				{
					case ACS_PWR_OFF:
						disableACS(); setACSPwrOff(); status.ACSactive = false;
					break;
					case ACS_PWR_LOW:
						enableACS(); setACSPwrLow();  status.ACSactive = true;
					break;
					case ACS_PWR_MED:
						enableACS(); setACSPwrMed();  status.ACSactive = true;
					break;
					case ACS_PWR_HIGH:
						enableACS(); setACSPwrHigh(); status.ACSactive = true;
					break;
				}
			break;
			case CMD_SEND_RC5: IRCOMM_sendRC5(param1, param2); break;
			case CMD_SET_WDT: status.watchDogTimer = param1 ? true : false; break;
			case CMD_SET_WDT_RQ: status.wdtRequestEnable = param1 ? true : false; break;
		}
	}
}

/**
 * This is the Software watchdog function. After any interrupt event, a timer is
 * stated and if a certain amount of time has passed by with no reaction from
 * the Master, the Robot is stopped to prevent any damages. Usually the Master
 * program has errors or is locked up if it does not react, so this it is
 * very good idea to stop moving.
 */
void task_MasterTimeout(void)
{
	if(status.watchDogTimer)
	{
		if( getStopwatch2() > 3000)  // 3 seconds timeout for the master to react on
		{							// our interrupt events - if he does not react, we
									// stop all operations!
			cli();
			IRCOMM_OFF();
			setACSPwrOff();
			OCR1AL = 0;
			OCR1BL = 0;
			TCCR1A = 0;
			powerOFF();
			writeString_P("\n\n##### EMERGENCY SHUTDOWN #####\n");
			writeString_P("##### ALL OPERATIONS STOPPED TO PREVENT ANY DAMAGE! #####\n\n");
			writeString_P("The Master Controller did not respond to the interrupt requests\n");
			writeString_P("within the defined timeout! Maybe he's locked up!\n");
			writeString_P("\nThe Robot needs to be resetted now.\n\n");
			while(true) // Rest In Peace
			{
				setLEDs(0b100010);
				uint8_t dly;
				for(dly = 10; dly; dly--)
					delayCycles(32768);
				setLEDs(0b010100);
				for(dly = 10; dly; dly--)
					delayCycles(32768);
			}
		}
		else if(getStopwatch3() > 250)
		{
			status.wdtRequest = true;
			signalInterrupt();
			setStopwatch3(0);
		}
	}
}
