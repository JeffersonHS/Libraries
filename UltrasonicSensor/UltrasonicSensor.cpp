/*
  UltrasonicSensor.h - Library to use with HC-SR04. (Version: 1.01)

  It can be used to read the distance between the sensor and the closest object or only detect an obstacle ahead.

  Created by Jefferson H. Silva (C), November 10th, 2017.
*/

#include "UltrasonicSensor.h"
#include "Arduino.h"

//Declaration of pins used by the Ultrasonic Sensor (HC-SR04).
UltrasonicSensor::UltrasonicSensor(int echoPin, int triggerPin) {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);

    _triggerPin = triggerPin;
    _echoPin = echoPin;
}

//Read the distance between the sensor and the closest object.
//Using SI, the function will return the distance in 'cm'.
//Using IMPERIAL, the  function will return the distance in 'inch'.
long UltrasonicSensor::ReadDistance(int sistem){
    long duration, distance;

    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_triggerPin, LOW);

    duration = pulseIn(_echoPin, HIGH);

    if (sistem == SI)  {
	distance = duration / 58.2;
    }

    if (sistem == IMPERIAL) {
	distance = duration / 148;
    }

    if (distance >= maxRange || distance <= minRange) {
      Serial.println("OUT OF RANGE");
    }
    else {
      //Serial.print("Distancia: ");
      //Serial.println(distance);
    }
    return distance;
}

//Detect an object ahead the sensor distant at "distance".
//Using "sistem = SI", you have to put the distance in 'cm'.
//Using "sistem = IMPERIAL", you have to put the distance in 'inch'.
int UltrasonicSensor::DetectObstacle(long distance, int sistem){
    long distanceTMP;
    int value = 0;
    if (sistem == SI) {
	distanceTMP = ReadDistance(SI);
    }
    if (sistem == IMPERIAL) {
	distanceTMP = ReadDistance(IMPERIAL);
    }
    if (distanceTMP <= distance) {
	value = 1;
    }
    else {
	value = 0;
    }
}