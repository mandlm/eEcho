#include "distancethread.h"

DistanceThread::DistanceThread(unsigned int triggerPin, unsigned int echoPin)
	: m_hcsr04(triggerPin, echoPin)
{
}

void DistanceThread::run()
{
    while (true)
    {
		emit distanceUpdated(m_hcsr04.getDistance());
		msleep(100);
    }
}

