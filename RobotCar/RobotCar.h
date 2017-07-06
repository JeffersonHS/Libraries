#ifndef robotcar_H
#define robotcar_H

#include "Arduino.h"

class Motors
{
public:
    Motors(int speedPinA, int pinI1, int pinI2, int speedPinB, int pinI3, int pinI4);
    void GoingForward(int Speed);
    void GoingBackward(int Speed);
    void TurnRight(int Speed);
    void TurnLeft(int Speed);
    void Brake();
    void Off();

private:
    int _speedPinA, _speedPinB, pinACWA, pinCWA, pinACWB, pinCWB;
};

class UltrasonicSensor {

public:
    UltrasonicSensor(int trigPin, int echoPin);
    void ReadDistance();

private:
    int _trigPin, _echoPin;
};

#endif // robotcar_H
