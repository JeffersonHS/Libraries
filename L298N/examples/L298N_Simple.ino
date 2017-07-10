/* 
  Library for L298N H-Bridge (Motor Driver)

  It is a code very simple. 
  First, you have to inicialize the pins used on the L982N. (Motors name(pinI1, pinI2, pinI3, pinI4)
  The pins 'I' are to control the motors' rotation direction. 
  
  WRITTEN BY: Jefferson H. Silva (C)
*/
#include <L298N.h>

#define pinI1 4 //It can be DIGITAL pin
#define pinI2 5 //It can be DIGITAL pin
#define pinI3 10 //It can be DIGITAL pin
#define pinI4 11 //It can be DIGITAL pin

//Declaration of pins used on the H-Bridge L298N
Motors Robot(pinI1, pinI2, pinI3, pinI4);

void setup() {
  //Make the Robot go forward;
  Robot.GoingForward(MAX);
  delay(3000);
  //Make the Robot turn right;
  Robot.TurnRight(MAX);
  delay(1000);
  //Make the Robot go forward;
  Robot.GoingForward(MAX);
  delay(5000);
  //Make the Robot brake;
  Robot.Brake();
  delay(500);
  //Make the Robot go backward;
  Robot.GoingBackward(MAX);
  delay(2000);
  //Make the Robot turn left;
  Robot.TurnLeft(MAX);
  delay(1000);
  //Make the Robot brake;
  Robot.Brake();
  delay(500);
  //Turn off the Robot's motors (neutral);
  Robot.Off();
}

void loop() {

}
