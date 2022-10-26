#include "LineFollow.h"

Rover::Rover(int LeftPin, int MiddlePin, int RightPin)
{
	LeftInputPin = LeftPin;
	MiddleInputPin = MiddlePin;
	RightInputPin = RightPin;
}

Rover::~Rover()
{
	// nothing created on heap
}

void Rover::ChipInit(
	int LeftThrottle,
	int RightThrottle,
	int LeftMotorForward,
	int LeftMotorReverse,
	int RightMotorForward,
	int RightMotorReverse)
{
	this->LeftThrottle = LeftThrottle;
	this->RightThrottle = RightThrottle;
	this->LeftMotorForward = LeftMotorForward;
	this->LeftMotorReverse = LeftMotorReverse;
	this->RightMotorForward = RightMotorForward;
	this->RightMotorReverse = RightMotorReverse;
}

bool Rover::GetLeftInput()
{
	return (bool)digitalRead(RightInputPin);
}

bool Rover::GetMiddleInput()
{
	return (bool)digitalRead(MiddleInputPin);
}

bool Rover::GetRightInput()
{
	return (bool)digitalRead(LeftInputPin);
}

void Rover::PivotLeft(int speed)
{
	digitalWrite(LeftMotorForward, HIGH);
	digitalWrite(LeftMotorReverse, LOW);
	digitalWrite(RightMotorForward, LOW);
	digitalWrite(RightMotorReverse, HIGH);

	analogWrite(LeftThrottle, speed);
	analogWrite(RightThrottle, speed);
}

void Rover::TurnLeft(int speed)
{
	analogWrite(RightThrottle, 0);

	digitalWrite(LeftMotorForward, HIGH);
	digitalWrite(LeftMotorReverse, LOW);

	analogWrite(LeftThrottle, speed);
}

void Rover::PivotRight(int speed)
{
	digitalWrite(LeftMotorForward, LOW);
	digitalWrite(LeftMotorReverse, HIGH);
	digitalWrite(RightMotorForward, HIGH);
	digitalWrite(RightMotorReverse, LOW);

	analogWrite(LeftThrottle, speed);
	analogWrite(RightThrottle, speed);
}

void Rover::TurnRight(int speed)
{
	analogWrite(LeftThrottle, 0);

	digitalWrite(RightMotorForward, HIGH);
	digitalWrite(RightMotorReverse, LOW);

	analogWrite(RightThrottle, speed);
}

void Rover::GoStraight(int speed)
{
	digitalWrite(LeftMotorForward, HIGH);
	digitalWrite(LeftMotorReverse, LOW);
	digitalWrite(RightMotorForward, HIGH);
	digitalWrite(RightMotorReverse, LOW);

	analogWrite(LeftThrottle, speed);
	analogWrite(RightThrottle, speed);
}

void Rover::Halt()
{
	analogWrite(LeftThrottle, 0);
	analogWrite(RightThrottle, 0);
}