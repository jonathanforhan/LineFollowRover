# LineFollowRover

Arduino Lib for line following rover

**TO INSTALL**
Copy the LineFollow folder and paste in Documents\Arduino\libraries

methods:

void ChipInit(
	int LeftThrottle,
	int RightThrottle,
	int LeftMotorForward, 
	int LeftMotorReverse,
	int RightMotorForward,
	int RightMotorReverse);

bool GetLeftInput();
bool GetMiddleInput();
bool GetRightInput();

void PivotLeft(int speed);
void PivotRight(int speed);
void TurnLeft(int speed);
void TurnRight(int speed);
void GoStraight(int speed);
void Halt();
