#pragma once

class Led
{
private:
	unsigned int m_pin = 0;

public:
	Led(unsigned int pin);

	void on() const;
	void off() const;
};


