
#include "RobotDrive.h"

RobotDrive::RobotDrive() 
{
	m_inverted = false;
}

void RobotDrive::init(int left_pin, int right_pin){
	m_left.attach(left_pin);
	m_right.attach(right_pin);
}

void RobotDrive::setLeft(float value){
	float output = (m_inverted) ? value : -value;
	m_left.set(output);
}

void RobotDrive::setRight(float value){
	float output = (m_inverted) ? -value : value;
	m_right.set(output);
}

void RobotDrive::setAll(float value){
	setLeft(value);
	setRight(value);
}

void RobotDrive::stop(){
	setAll(0.0f);
}

void RobotDrive::tankDrive(float leftVal, float rightVal){
	setLeft(leftVal);
	setRight(rightVal);
}

float RobotDrive::limit(float value){
	if(value > 1.0f){
		return 1.0f;
	} else if (value < -1.0f){
		return -1.0f;
	} else {
		return value;
	}
}

void RobotDrive::arcadeDrive(float moveValue, float rotateValue){
	float leftMotorSpeed;
    float rightMotorSpeed;

    moveValue = limit(moveValue);
    rotateValue = limit(rotateValue);

    if (moveValue > 0.0) {
        if (rotateValue > 0.0) {
            leftMotorSpeed = moveValue - rotateValue;
            rightMotorSpeed = max(moveValue, rotateValue);
        } else {
            leftMotorSpeed = max(moveValue, -rotateValue);
            rightMotorSpeed = moveValue + rotateValue;
        }
    } else {
        if (rotateValue > 0.0) {
            leftMotorSpeed = -max(-moveValue, rotateValue);
            rightMotorSpeed = moveValue + rotateValue;
        } else {
            leftMotorSpeed = moveValue - rotateValue;
            rightMotorSpeed = -max(-moveValue, -rotateValue);
        }
    }

    setLeft(leftMotorSpeed);
    setRight(rightMotorSpeed);
}

void RobotDrive::setInverted(bool inverted){
	m_inverted = inverted;
}
