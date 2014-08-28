
#include "Compressor.h"

Compressor::Compressor(int pressure_switch_pin, int relay_pin){
	m_running = false;
	m_pressure_switch_pin = pressure_switch_pin;
	m_relay_pin - relay_pin;
}

void Compressor::init(){
	pinMode(m_pressure_switch_pin, INPUT);
	pinMode(m_relay_pin, OUTPUT);

	enable();
}

void Compressor::enable(){
	m_running = true;
}

void Compressor::run(){
	// Pressure switch is normally closed (HIGH)
	if(m_running && digitalRead(m_pressure_switch_pin) == HIGH){
		digitalWrite(m_relay_pin, HIGH);
	} else {
		digitalWrite(m_relay_pin, LOW);
	}
}

void Compressor::disable(){
	m_running = false;
}
