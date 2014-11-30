#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED




typedef enum dir
{
   MOVE_LEFT,
   MOVE_RIGHT,
   MOVE_BACK,
   MOVE_FOREWARD
}Direction;

typedef struct ir_distance
{
    uint16_t valueRightFront;
    uint16_t valueRightRear;
    uint16_t valueLeftFront;
    uint16_t valueLeftRear;
    int16_t  diffRightSide;
    int16_t  diffLeftSide;
}_ir_distance;

void runningLight(void);
void printScharpSensorsValuesRight(_ir_distance *sensor);
void readRearDistanceSensors( uint16_t *rearLeft,uint16_t *rearRight);
void getSharpSensorInfo( _ir_distance *sensor);
void printDataToCSharpApplcation (_ir_distance *sensor, uint16_t batteryValue);
#endif // FUNCTIONS_H_INCLUDED
