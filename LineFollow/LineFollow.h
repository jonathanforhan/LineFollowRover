#ifndef LINE_H
#define LINE_H

#include<Arduino.h>

class Rover
{
private:
	int LeftInputPin;
	int MiddleInputPin;
	int RightInputPin;

	int LeftThrottle;
	int RightThrottle;
	int LeftMotorForward;
	int LeftMotorReverse;
	int RightMotorForward;
	int RightMotorReverse;
public:
	Rover(int LeftInputPin, int MiddleInputPin, int RightInputPin);
	~Rover();

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
};

#endif