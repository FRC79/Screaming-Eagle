
#include "Relay.h"

Relay::Relay(int forward_pin, int reverse_pin){
	m_forward_pin = forward_pin;
	m_reverse_pin = reverse_pin;
}

void Relay::init(){
	pinMode(m_forward_pin, OUTPUT);
	pinMode(m_reverse_pin, OUTPUT);

	off();
}

void Relay::forward(){
	digitalWrite(m_forward_pin, HIGH);
	digitalWrite(m_reverse_pin, LOW);
}

void Relay::reverse(){
	digitalWrite(m_forward_pin, LOW);
	digitalWrite(m_reverse_pin, HIGH);
}

void Relay::on(){
	digitalWrite(m_forward_pin, HIGH);
	digitalWrite(m_reverse_pin, HIGH);
}

void Relay::off(){
	digitalWrite(m_forward_pin, LOW);
	digitalWrite(m_reverse_pin, LOW);
}
