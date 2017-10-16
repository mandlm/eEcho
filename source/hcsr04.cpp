#include "hcsr04.h"
#include "median.h"
#include <wiringPi.h>

volatile unsigned int timestampHigh = 0;
volatile unsigned int pulseLength = 0;

HCSR04::HCSR04(unsigned int triggerPin, unsigned int echoPin)
	: m_triggerPin(triggerPin)
	, m_echoPin(echoPin)
{
	wiringPiSetup();
	pinMode(m_triggerPin, OUTPUT);
	pinMode(m_echoPin, INPUT);
}

void HCSR04::run()
{
	wiringPiISR(m_echoPin, INT_EDGE_BOTH, []
	{
		if (digitalRead(29) == HIGH)
		{
			timestampHigh = micros();
		}
		else if (timestampHigh != 0)
		{
			pulseLength = micros() - timestampHigh;
			timestampHigh = 0;
		}
	});
}

double HCSR04::getDistance() 
{
	std::vector<double> values;
	for (int i = 0; i < 15; ++i)
	{
		digitalWrite(m_triggerPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(m_triggerPin, LOW);
		delayMicroseconds(40);

		if (pulseLength < 25e3)
		{
			values.push_back(pulseLength);	
		}

		delay(10);
	}

	if (!values.empty())
	{
		return median(values) / 0.58;
	}

	return 0;
}

