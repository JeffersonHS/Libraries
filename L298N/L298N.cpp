#include "L298N.h"
#include "Arduino.h"
#include "stdarg.h"

/*
  L298N.h - Library to use with H-Bridge L298N. (Version: 1.02)
  It works to control two motors conected at a H-Bridge L298N.

  It can be used to control besides the motors' rotation direction, the motors' velocity, adding pins "enableA" and "enableB" in the declaration of the object 'Motors', respectively.

  It can also be used to control the time that the comand (GoingForward, GoingBackward, TurnLeft and TurnRight) will works, adding the time that you want in the function.

  Created by Jefferson H. Silva (C), November 10th, 2017.
*/

//Declaration of pins used by the H-Bridge L298N.
Motors::Motors(int pinI1, int pinI2, int pinI3, int pinI4, ...) {
    pinMode(pinI1, OUTPUT);
    pinMode(pinI2, OUTPUT);
    pinMode(pinI3, OUTPUT);
    pinMode(pinI4, OUTPUT);
    
    va_list speedPin;
    int speedPinA = va_arg(speedPin, int);
    pinMode(speedPinA, OUTPUT);

    int speedPinB = va_arg(speedPin, int);
    pinMode(speedPinB, OUTPUT);

    va_end(speedPin);

    _speedPinA = speedPinA;
    _speedPinB = speedPinB;
    pinACWA = pinI1;
    pinCWA = pinI2;
    pinACWB = pinI3;
    pinCWB = pinI4;
}

//Do the motors go forward.
void Motors::GoingForward(int Speed, ...){
    int timeA = 0;
    
    va_list time;
    int timeA = va_arg(time, int);
    va_end(time);    

    analogWrite(_speedPinA, Speed);
    analogWrite(_speedPinB, Speed);
    //Motor A turn clockwise
    digitalWrite(pinACWA, LOW);
    digitalWrite(pinCWA, HIGH);
    //Motor B turn anticlockwise
    digitalWrite(pinACWB, HIGH);
    digitalWrite(pinCWB, LOW);

    if (timeA > 0) {
	delay(timeA);
        Brake();
    }
}

//Do the motors go backward.
void Motors::GoingBackward(int Speed, ...){
    int timeA = 0;
    
    va_list time;
    int timeA = va_arg(time, int);
    va_end(time); 

    analogWrite(_speedPinA, Speed);
    analogWrite(_speedPinB, Speed);
    //Motor A turn anticlockwise
    digitalWrite(pinACWA, HIGH);
    digitalWrite(pinCWA, LOW);
    //Motor B turn clockwise
    digitalWrite(pinACWB, LOW);
    digitalWrite(pinCWB, HIGH);

    if (timeA > 0) {
	delay(timeA);
        Brake();
    }
}

//Do the motors turn right.
void Motors::TurnRight(int Speed, ...){
    int timeA = 0;
    
    va_list time;
    int timeA = va_arg(time, int);
    va_end(time); 

    analogWrite(_speedPinA, Speed);
    analogWrite(_speedPinB, Speed);
    //Motor A turn anticlockwise
    digitalWrite(pinACWA, HIGH);
    digitalWrite(pinCWA, LOW);
    //Motor B turn anticlockwise
    digitalWrite(pinACWB, HIGH);
    digitalWrite(pinCWB, LOW);

    if (timeA > 0) {
	delay(timeA);
        Brake();
    }
}

//Do the motors turn left.
void Motors::TurnLeft(int Speed, ...){
    int timeA = 0;
    
    va_list time;
    timeA = va_arg(time, int);
    va_end(time); 

    analogWrite(_speedPinA, Speed);
    analogWrite(_speedPinB, Speed);
    //Motor A turn clockwise
    digitalWrite(pinACWA, LOW);
    digitalWrite(pinCWA, HIGH);
    //Motor B turn clockwise
    digitalWrite(pinACWB, LOW);
    digitalWrite(pinCWB, HIGH);

    if (timeA > 0) {
	delay(timeA);
        Brake();
    }
}

//Do the motors brake.
void Motors::Brake(){
    analogWrite(_speedPinA, 100);
    analogWrite(_speedPinB, 100);
    //Motor A turn clockwise
    digitalWrite(pinACWA, HIGH);
    digitalWrite(pinCWA, HIGH);
    //Motor B turn clockwise
    digitalWrite(pinACWB, HIGH);
    digitalWrite(pinCWB, HIGH);
}

//Do the motors turn off (neutral).
void Motors::Off(){
    analogWrite(_speedPinA, 0);
    analogWrite(_speedPinB, 0);
    //Motor A turn clockwise
    digitalWrite(pinACWA, LOW);
    digitalWrite(pinCWA, LOW);
    //Motor B turn clockwise
    digitalWrite(pinACWB, LOW);
    digitalWrite(pinCWB, LOW);
}