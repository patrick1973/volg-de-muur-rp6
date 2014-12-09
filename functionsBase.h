#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void runningLight(void);
void printScharpSensorsValuesFront(uint16_t sensorValues[], uint8_t lenght);
void readDistanceSensors(uint16_t *sensorValues[]);
uint16_t sensorDifferenceLeftRight(uint16_t *sensorValues[]);

#endif // FUNCTIONS_H_INCLUDED
