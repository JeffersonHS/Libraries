#include "L298N.h"
#include "Arduino.h"

UltrasonicSensor::UltrasonicSensor(int echoPin, int triggerPin) {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);

    _triggerPin = triggerPin;
    _echoPin = echoPin;
}

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