
// #include "RobotDrive.h"

// RobotDrive::RobotDrive(SpeedController *frontLeft, SpeedController *rearLeft, 
// 		SpeedController *frontRight, SpeedController *rearRight) 
// {
// 	m_frontLeft = frontLeft;
// 	m_rearLeft = rearLeft;
// 	m_frontRight = frontRight;
// 	m_rearRight = rearRight;
// }

// RobotDrive::~RobotDrive(){}

// void RobotDrive::setLeft(float value){
// 	float output = (m_inverted) ? value : -value;
// 	m_frontLeft->set(ouput);
// 	m_rearLeft->set(ouput);
// }

// void RobotDrive::setRight(float value){
// 	float output = (m_inverted) ? -value : value;
// 	m_frontRight->set(output);
// 	m_rearRight->set(output);
// }

// void RobotDrive::setAll(float value){
// 	setLeft(value);
// 	setRight(value);
// }

// void RobotDrive::stop(){
// 	setAll(0.0f);
// }

// void RobotDrive::tankDrive(float leftVal, float rightVal){
// 	setLeft(leftVal);
// 	setRight(rightVal);
// }

// float RobotDrive::limit(float value){
// 	if(value > 1.0f){
// 		return 1.0f;
// 	} else if (value < -1.0f){
// 		return -1.0f;
// 	}
// }

// void RobotDrive::arcadeDrive(float moveValue, float rotateValue){
// 	float leftMotorSpeed;
//     float rightMotorSpeed;

//     moveValue = limit(moveValue);
//     rotateValue = limit(rotateValue);

//     if (moveValue > 0.0) {
//         if (rotateValue > 0.0) {
//             leftMotorSpeed = moveValue - rotateValue;
//             rightMotorSpeed = max(moveValue, rotateValue);
//         } else {
//             leftMotorSpeed = max(moveValue, -rotateValue);
//             rightMotorSpeed = moveValue + rotateValue;
//         }
//     } else {
//         if (rotateValue > 0.0) {
//             leftMotorSpeed = -max(-moveValue, rotateValue);
//             rightMotorSpeed = moveValue + rotateValue;
//         } else {
//             leftMotorSpeed = moveValue - rotateValue;
//             rightMotorSpeed = -max(-moveValue, -rotateValue);
//         }
//     }

//     setLeft(leftMotorSpeed);
//     setRight(rightMotorSpeed);
// }

// void RobotDrive::setInverted(bool inverted){
// 	m_inverted = inverted;
// }
