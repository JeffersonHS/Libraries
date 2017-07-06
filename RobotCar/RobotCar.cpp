#include "Arduino.h"
#include "robotcar.h"

Motors::Motors(int speedPinA, int pinI1, int pinI2, int speedPinB, int pinI3, int pinI4) {
    pinMode(speedPinA, OUTPUT);
    pinMode(pinI1, OUTPUT);
    pinMode(pinI2, OUTPUT);
    pinMode(speedPinA, OUTPUT);
    pinMode(pinI3, OUTPUT);
    pinMode(pinI4, OUTPUT);
    _speedPinA = speedPinA;
    _speedPinB = speedPinB;
    pinACWA = pinI1;
    pinCWA = pinI2;
    pinACWB = pinI3;
    pinCWB = pinI4;
}

void Motors::GoingForward(int Speed){
    analogWrite(_speedPinA, Speed);
    analogWrite(_speedPinB, Speed);
    //Motor A turn clockwise
    digitalWrite(pinACWA, LOW);
    digitalWrite(pinCWA, HIGH);
    //Motor B turn anticlockwise
    digitalWrite(pinACWB, HIGH);
    digitalWrite(pinCWB, LOW);
}

void Motors::GoingBackward(int Speed){
    analogWrite(_speedPinA, Speed);
    analogWrite(_speedPinB, Speed);
    //Motor A turn anticlockwise
    digitalWrite(pinACWA, HIGH);
    digitalWrite(pinCWA, LOW);
    //Motor B turn clockwise
    digitalWrite(pinACWB, LOW);
    digitalWrite(pinCWB, HIGH);
}

void Motors::TurnRight(int Speed){
    analogWrite(_speedPinA, Speed);
    analogWrite(_speedPinB, Speed);
    //Motor A turn anticlockwise
    digitalWrite(pinACWA, HIGH);
    digitalWrite(pinCWA, LOW);
    //Motor B turn anticlockwise
    digitalWrite(pinACWB, HIGH);
    digitalWrite(pinCWB, LOW);
}

void Motors::TurnLeft(int Speed){
    analogWrite(_speedPinA, Speed);
    analogWrite(_speedPinB, Speed);
    //Motor A turn clockwise
    digitalWrite(pinACWA, LOW);
    digitalWrite(pinCWA, HIGH);
    //Motor B turn clockwise
    digitalWrite(pinACWB, LOW);
    digitalWrite(pinCWB, HIGH);
}

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

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void UltrasonicSensor::ReadDistance(){

}