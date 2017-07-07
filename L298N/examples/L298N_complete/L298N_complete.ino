/* 
  Library for L298N H-Bridge (Motor Driver)

  It is a code very simple. 
  First, you have to inicialize the pins used on the L982N. (Motors name(pinI1, pinI2, pinI3, pinI4, speedPinA, speedPinB))
  The pins 'I' are to control the direction of motors' rotation and the pins 'speedPin' are to control the motors' velocity. 
  
  WRITTEN BY: Jefferson Silva
*/
#include <L298N.h>

#define speedPinA 6 //It have to be a PWM pin
#define pinI1 4 //It can be DIGITAL pin
#define pinI2 5 //It can be DIGITAL pin

#define speedPinB 9 //It have to be a PWM pin
#define pinI3 10 //It can be DIGITAL pin
#define pinI4 11 //It can be DIGITAL pin

#define speedMotor 150 //Between 0(OFF) and 255(MAXIMUM)

//Declaration of pins used on the L298N H-Bridge
Motors Robot(pinI1, pinI2, pinI3, pinI4, speedPinA, speedPinB);

void setup() {
  //Make the Robot go forward;
  Robot.GoingForward(speedMotor);
  delay(3000);
  //Make the Robot turn right;
  Robot.TurnRight(speedMotor);
  delay(1000);
  //Make the Robot go forward;
  Robot.GoingForward(speedMotor);
  delay(5000);
  //Make the Robot brake;
  Robot.Brake();
  delay(500);
  //Make the Robot go backward;
  Robot.GoingBackward(speedMotor);
  delay(2000);
  //Make the Robot turn left;
  Robot.TurnLeft(speedMotor);
  delay(1000);
  //Make the Robot brake;
  Robot.Brake();
  delay(500);
  //Turn off the Robot's motors (neutral);
  Robot.Off();
}

void loop() {

}
