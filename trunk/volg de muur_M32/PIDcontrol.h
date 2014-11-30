#ifndef PIDCONTROL_H_INCLUDED
#define PIDCONTROL_H_INCLUDED

typedef struct values
{
    double pocessValue;
    double setpoint;
    double upBound;
    double lowBound;
    double kpFactor;
    double tiFactor;
    double tdFactor;
    double pidOutput;

}_Values;

void pidController(_Values *pidValues );

#endif // PIDCONTROL_H_INCLUDED
