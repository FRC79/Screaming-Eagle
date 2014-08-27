#ifndef RobotDrive_h
#define RobotDrive_h

#include "Arduino.h"
#include <SpeedController.h>

class RobotDrive {

public:
	RobotDrive();
	void init(int left_pin, int right_pin);
	
	void setLeft(float value);
	void setRight(float value);
	void setAll(float value);
	void stop();

	void tankDrive(float leftVal, float rightVal);
	void arcadeDrive(float moveValue, float rotateValue);

void setInverted(bool inverted);

private:
	bool m_inverted;
	SpeedController m_left;
	SpeedController m_right;

	float limit(float value);
};

#endif