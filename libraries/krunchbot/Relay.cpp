
#include "Relay.h"

Relay::Relay(int forward_pin){
	m_forward_pin = forward_pin;

	m_using_both_pins = false;
}

Relay::Relay(int forward_pin, int reverse_pin){
	m_forward_pin = forward_pin;
	m_reverse_pin = reverse_pin;

	m_using_both_pins = true;
}

void Relay::init(){
	pinMode(m_forward_pin, OUTPUT);
	
	if(m_using_both_pins){
		pinMode(m_reverse_pin, OUTPUT);
	}

	off();
}

void Relay::setForwardAndReverse(int forward, int reverse){
	digitalWrite(m_forward_pin, forward);

	if(m_using_both_pins){
		digitalWrite(m_reverse_pin, reverse);
	}
}

void Relay::forward(){
	setForwardAndReverse(HIGH, LOW);
}

void Relay::reverse(){
	setForwardAndReverse(LOW, HIGH);
}

void Relay::on(){
	setForwardAndReverse(HIGH, HIGH);
}

void Relay::off(){
	setForwardAndReverse(LOW, LOW);
}
