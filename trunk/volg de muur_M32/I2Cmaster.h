#ifndef I2CMASTER_H_INCLUDED
#define I2CMASTER_H_INCLUDED

#define CMD_MOVE_AT_SPEED 5
#define CMD_MOVE 7
#define CMD_ROTATE 8
#define LEFT 2
#define RIGHT 3
#define I2C_RP6_BASE_ADR 10		// The default address of the Slave Controller
								// on the RP6 Mainboard


void I2C_transmissionError(uint8_t errorState);
void readAllRegisters(void);
void readFrontDistanceSensors( uint16_t *frontLeft,uint16_t *frontRight );
void moveAtSpeed(uint8_t desired_speed_left, uint8_t desired_speed_right);
void RP6_rotate(uint8_t desired_speed, uint8_t dir, uint16_t angle);
uint16_t getbatteryLevel();
uint16_t getMotorLeftCurrent();
uint16_t getMotorRightCurrent();

#endif // I2CMASTER_H_INCLUDED
