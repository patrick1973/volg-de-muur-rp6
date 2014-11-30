#include "RP6ControlLib.h"
#include "PIDcontrol.h"


//* PID regelaar
/*  De regelaar update wordt bepaald door de stopwatch die deze functie aan roept.
*/
void pidController(_Values *pidValues  )
{
    // decleratie variable
    double error, integral, kp , ki , kd ;
    static double last;
    const double intThresh = 2.0;

    // begin van de code
    error = (pidValues->setpoint) - (pidValues->pocessValue);

    if (abs(error) < intThresh)        // voorkom intergral windup
    {
        integral = integral + error;
    }
    else
    {
        integral = intThresh;
    }

    kp = error * pidValues->kpFactor;
    ki = integral * pidValues->tiFactor;
    kd = (last - pidValues->pocessValue) * pidValues->tdFactor;
    pidValues->pocessValue = kp + ki + kd ;

    last = pidValues->pocessValue;

}
