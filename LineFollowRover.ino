/*
* L293D wiring
*
* LT  (1)*(16) VCC
* LMF (2)*(15) RMF
* MR+ (3)*(14) MR+
* GND (4)*(13) GND
* GND (5)*(12) GND
* ML- (6)*(11) MR-
* LMR (7)*(10) RMR
* VCC (8)*( 9) RT
*
* ML -> left motor
* MR -> right motor
*/

#include<LineFollow.h>

const int LeftSensor = 2;
const int MiddleSensor = 3;
const int RightSensor = 4;

const int LT = 5;   // Left Throttle
const int RT = 6;   // Right Throttle
const int LMF = 7;  // Left Motor Forward
const int LMR = 8;  // Left Motor Reverse
const int RMF = 9;  // Right Motor Forward
const int RMR = 10; // Right Motor Reverse

Rover rover(LeftSensor, MiddleSensor, RightSensor); // make rover object with sensor input in the L, M, R format

void setup()
{
  rover.ChipInit(LT, RT, LMF, LMR, RMF, RMR); // initalize the L293D chip with your input pins
}

void loop()
{
  if (rover.GetMiddleInput())
  {
    rover.GoStraight(255); // the 255 is the speed, speed must be between 0-255
  }
  else if (rover.GetLeftInput())
  {
    rover.PivotLeft(126); // again, speed
  }
  else if (rover.GetRightInput())
  {
    rover.PivotRight(126);
  }
  else
  {
    rover.Halt();
  }
}
