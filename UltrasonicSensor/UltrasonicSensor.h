#ifndef UltrasonicSensor_H
#define UltrasonicSensor_H

#include "Arduino.h"

#define SI 1
#define IMPERIAL 2

#define minRange 0
#define maxRange 200

class UltrasonicSensor
{
public:
    UltrasonicSensor(int echoPin, int triggerPin);
    long ReadDistance(int sistem);

private:
    int _echoPin, _triggerPin;
};

#endif // UltrasonicSensor_H