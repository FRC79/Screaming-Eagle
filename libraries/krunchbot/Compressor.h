#ifndef Compressor_h
#define Compressor_h

#include "Arduino.h"

class Compressor {
public:
	Compressor(int pressure_switch_pin, int relay_pin);

	void init();
	void enable();
	void run();
	void disable();

private:
	bool m_running;
	int m_pressure_switch_pin;
	int m_relay_pin;
};

#endif