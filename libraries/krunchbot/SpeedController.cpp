
#include "SpeedController.h"

SpeedController::SpeedController(){
	m_inverted = false;
}

float SpeedController::limit(float value){
	if(value > 1.0f){
		return 1.0f;
	} else if (value < -1.0f){
		return -1.0f;
	}
}

void SpeedController::set(float value){
	int input = (int)(limit(value) * 90) + 90; // Scale from (-1.0, 1.0) to (0, 180)
	input = (m_inverted) ? -input : input;
	write(input);
}

float SpeedController::get(){
	int output = read();
	return (output - 90) / 90.0f;
}

void SpeedController::setInverted(bool inverted){
	m_inverted = inverted;
}
