#ifndef UltrasonicSensor_H
#define UltrasonicSensor_H

/*
  UltrasonicSensor.h - Library to use with HC-SR04. (Version: 1.01)

  It can be used to read the distance between the sensor and the closest object or only detect an obstacle ahead.

  Created by Jefferson H. Silva (C), November 10th, 2017.
*/

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
    int DetectObstacle(int distance, int sistem);

private:
    int _echoPin, _triggerPin;
};

#endif // UltrasonicSensor_H