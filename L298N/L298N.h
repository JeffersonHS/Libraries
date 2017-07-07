#ifndef L298N_H
#define L298N_H

#include "Arduino.h"

class Motors
{
public:
    Motors(int pinI1, int pinI2, int pinI3, int pinI4, ...);
    void GoingForward(int Speed);
    void GoingBackward(int Speed);
    void TurnRight(int Speed);
    void TurnLeft(int Speed);
    void Brake();
    void Off();

private:
    int _speedPinA, _speedPinB, pinACWA, pinCWA, pinACWB, pinCWB;
};

#endif // L298N_H