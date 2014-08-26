#ifndef SpeedController_h
#define SpeedController_h

#include "Arduino.h"
#include <Servo.h>

class SpeedController : public Servo {
public:
	SpeedController();
	
	void set(float value); // From -1.0 to 1.0
	float get();

	void setInverted(bool inverted);

private:
	bool m_inverted;

	float limit(float value);
};

#endif
