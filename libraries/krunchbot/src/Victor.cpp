
#include "Victor.h"

Victor::Victor(int pin){
	m_servo.attach(pin);
}

Victor::~Victor(){
	m_servo.detach();
}

void Victor::Set(float value){
	int input = (value * 90) + 90; // Scale from (-1.0, 1.0) to (0, 180)
	input = (m_inverted) ? -input : input;
	m_servo.write(input);
}

float Victor::Get(){
	int output = m_servo.read();
	return (output - 90) / 90.0;
}

void Victor::SetInverted(bool inverted){
	m_inverted = inverted;
}
