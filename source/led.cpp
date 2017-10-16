#include "led.h"
#include <wiringPi.h>

#include <iostream>

Led::Led(unsigned int pin)
	: m_pin(pin)
{
	wiringPiSetup();
	pinMode(m_pin, OUTPUT);
}

void Led::on() const
{
	digitalWrite(m_pin, HIGH);
}

void Led::off() const
{
	digitalWrite(m_pin, LOW);
}

