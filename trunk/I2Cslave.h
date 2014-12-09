#ifndef I2CSLAVE_H_INCLUDED
#define I2CSLAVE_H_INCLUDED

// The Slave Address on the I2C Bus can be specified here:
#define RP6BASE_I2C_SLAVE_ADR 10

/*****************************************************************************/
// I2C Registers that can be read by the Master. Their names should
// be self-explanatory and directly relate to the equivalent variables/functions
// in the RP6Library

#define I2C_REG_STATUS1 		 0
#define I2C_REG_STATUS2 		 1
#define I2C_REG_MOTION_STATUS 	 2
#define I2C_REG_POWER_LEFT 		 3
#define I2C_REG_POWER_RIGHT 	 4
#define I2C_REG_SPEED_LEFT 		 5
#define I2C_REG_SPEED_RIGHT 	 6
#define I2C_REG_DES_SPEED_LEFT 	 7
#define I2C_REG_DES_SPEED_RIGHT  8
#define I2C_REG_DIST_LEFT_L 	 9
#define I2C_REG_DIST_LEFT_H 	 10
#define I2C_REG_DIST_RIGHT_L     11
#define I2C_REG_DIST_RIGHT_H 	 12
#define I2C_REG_ADC_LSL_L 		 13
#define I2C_REG_ADC_LSL_H 		 14
#define I2C_REG_ADC_LSR_L 		 15
#define I2C_REG_ADC_LSR_H 		 16
#define I2C_REG_ADC_MOTOR_CURL_L 17
#define I2C_REG_ADC_MOTOR_CURL_H 18
#define I2C_REG_ADC_MOTOR_CURR_L 19
#define I2C_REG_ADC_MOTOR_CURR_H 20
#define I2C_REG_ADC_UBAT_L 		 21
#define I2C_REG_ADC_UBAT_H 		 22
#define I2C_REG_ADC_ADC0_L 		 23
#define I2C_REG_ADC_ADC0_H 		 24
#define I2C_REG_ADC_ADC1_L 		 25
#define I2C_REG_ADC_ADC1_H 		 26
#define I2C_REG_RC5_ADR	 		 27
#define I2C_REG_RC5_DATA	 	 28
#define I2C_REG_LEDS	 		 29

/*****************************************************************************/
// Command Registers - these can be written by the Master.
// The other registers (read registers) can NOT be written to. The only way to
// communicate with the Robot is via specific commands.
// Of course you can also add more registers if you like...
#define I2C_REGW_CMD 0
#define I2C_REGW_CMD_PARAM1 1
#define I2C_REGW_CMD_PARAM2 2
#define I2C_REGW_CMD_PARAM3 3
#define I2C_REGW_CMD_PARAM4 4
#define I2C_REGW_CMD_PARAM5 5
#define I2C_REGW_CMD_PARAM6 6

// Commands:
#define CMD_POWER_OFF 		0
#define CMD_POWER_ON 		1
#define CMD_CONFIG 			2
#define CMD_SETLEDS 		3
#define CMD_STOP   			4
#define CMD_MOVE_AT_SPEED   5
#define CMD_CHANGE_DIR	    6
#define CMD_MOVE 			7
#define CMD_ROTATE 			8
#define CMD_SET_ACS_POWER	9
#define CMD_SEND_RC5		10
#define CMD_SET_WDT			11
#define CMD_SET_WDT_RQ		12

// Parameters for CMD_SET_ACS_POWER:
#define ACS_PWR_OFF  0
#define ACS_PWR_LOW  1
#define ACS_PWR_MED  2
#define ACS_PWR_HIGH 3




// This bitfield contains the main interrupt event status bits. This can be
// read out and any Master devices can react on the specific events.
// Elk element in de struct is 1 bit groot. totaat zijn er dus 8 elementen van 1 bit = 1 byte.
// volgens mij door het gebruik van een union, komen al de 8 bits in 1 byte achtereen in het geheugen
union {
 	uint8_t byte;
	struct {
		uint8_t batLow:1;
		uint8_t bumperLeft:1;
		uint8_t bumperRight:1;
		uint8_t RC5reception:1;
		uint8_t RC5transmitReady:1;
		uint8_t obstacleLeft:1;
		uint8_t obstacleRight:1;
		uint8_t driveSystemChange:1;
	};
} interrupt_status;

// Some status bits with current settings and other things.
union {
 	uint8_t byte;
	struct {
		uint8_t powerOn:1;
		uint8_t ACSactive:1;
		uint8_t watchDogTimer:1;
		uint8_t wdtRequest:1;
		uint8_t wdtRequestEnable:1;
		uint8_t unused:3; // 3 bits groot om de struct totaal 8 bits groot te maken om de union te vullen
	};
} status;

// Drive Status register contains information about current movements.
// You can check if movements are complete, if the motors are turned
// on, if there were overcurrent events and for direction.
union {
 	uint8_t byte;
	struct {
		uint8_t movementComplete:1;
		uint8_t motorsOn:1;
		uint8_t motorOvercurrent:1;
		uint8_t direction:2;
		uint8_t unused:3;
	};
} drive_status;


void signalInterrupt(void);
void clearInterrupt(void);
void acsStateChanged(void);
void bumpersStateChanged(void);
void motionControlStateChanged(void);
void task_update(void);
void task_updateRegisters(void);
uint8_t getCommand(void);
void task_commandProcessor(void);
void task_MasterTimeout(void);


#endif // I2CSLAVE_H_INCLUDED
