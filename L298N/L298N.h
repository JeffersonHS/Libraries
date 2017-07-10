#ifndef L298N_H
#define L298N_H

/*
  L298N.h - Library to use with H-Bridge L298N. (Version: 1.02)
  It works to control two motors conected at a H-Bridge L298N.

  It can be used to control besides the motors' rotation direction, the motors' velocity, adding pins "enableA" and "enableB" in the declaration of the object 'Motors', respectively. 

  It can also be used to control the time that the comand (GoingForward, GoingBackward, TurnLeft and TurnRight) will works, adding the time that you want in the function.

  Created by Jefferson H. Silva (C), November 10th, 2017.
*/

#include "Arduino.h"
#include "stdarg.h"

#define MAX 255

class Motors
{
public:
    Motors(int pinI1, int pinI2, int pinI3, int pinI4, ...);
    void GoingForward(int Speed, ...);
    void GoingBackward(int Speed, ...);
    void TurnRight(int Speed, ...);
    void TurnLeft(int Speed, ...);
    void Brake();
    void Off();

private:
    int _speedPinA, _speedPinB, pinACWA, pinCWA, pinACWB, pinCWB;
};

#endif // L298N_H