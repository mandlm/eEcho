#pragma once

class HCSR04
{
private:
	unsigned int m_triggerPin;
	unsigned int m_echoPin;

public:
	HCSR04() = delete;
	HCSR04(unsigned int triggerPin, unsigned int echoPin);

	void run();

	double getDistance();
};

