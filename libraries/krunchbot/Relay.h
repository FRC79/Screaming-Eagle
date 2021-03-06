#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay {
public:
	Relay(int forward_pin);
	Relay(int forward_pin, int reverse_pin);

	void init();

	void forward();
	void reverse();
	void on();
	void off();

private:
	int m_forward_pin;
	int m_reverse_pin;
	bool m_using_both_pins;

	void setForwardAndReverse(int forward, int reverse);
};

#endif