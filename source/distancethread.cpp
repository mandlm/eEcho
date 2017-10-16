#include "distancethread.h"
#include <wiringPi.h>

volatile unsigned int timestampHigh = 0;
volatile unsigned int pulseLength = 0;

DistanceThread::DistanceThread()
{
    wiringPiSetup();
    pinMode(m_triggerPin, OUTPUT);
    pinMode(m_echoPin, INPUT);
}

void DistanceThread::run()
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

    while (true)
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
			emit distanceUpdated(median(values) / 0.58);
		}

		delay(100);
    }
}

template<typename VALUE_TYPE>
double DistanceThread::median(std::vector<VALUE_TYPE> values) const
{
	if (values.size() == 0)
	{
		return 0.0;
	}

	size_t centerIndex = values.size() / 2;
	std::nth_element(values.begin(), values.begin() + centerIndex, values.end());
	
	if (values.size() % 2 == 1)
	{
		return values[centerIndex];
	}
	else
	{
		std::nth_element(values.begin(), values.begin() + centerIndex + 1, values.end());
		return (values[centerIndex] + values[centerIndex + 1]) / 2.0;
	}
}
