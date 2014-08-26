// #ifndef RobotDrive_h
// #define RobotDrive_h

// #include "Arduino.h"
// #include "SpeedController.h"

// class RobotDrive {

// public:
// 	RobotDrive(SpeedController *frontLeft, SpeedController *rearLeft, 
// 		SpeedController *frontRight, SpeedController *rearRight);
// 	~RobotDrive();

// 	void setLeft(float value);
// 	void setRight(float value);
// 	void setAll(float value);
// 	void stop();

// 	void tankDrive(float leftVal, float rightVal);
// 	void arcadeDrive(float moveValue, float rotateValue);

// void setInverted(bool inverted);

// private:
// 	bool m_inverted = false;
// 	SpeedController *m_frontLeft;
// 	SpeedController *m_rearLeft;
// 	SpeedController *m_frontRight;
// 	SpeedController *m_rearRight;

// 	float limit(float value);
// };

// #endif