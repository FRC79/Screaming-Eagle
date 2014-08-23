#ifndef Victor_h
#define Victor_h

#include "Arduino.h"
#include <Servo.h>

class Victor {
public:
	Victor(int pin);
	~Victor();
	
	void Set(float value); // From -1.0 to 1.0
	float Get();

	void SetInverted(bool inverted);

private:
	bool m_inverted = false;
	Servo m_servo;
};

#endif
