#include "distancethread.h"
#include <wiringPi.h>

volatile unsigned int timestampHigh = 0;
volatile unsigned int timestampLow = 0;

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
        else
        {
            timestampLow = micros();
        }
    });

    while (true)
    {
        digitalWrite(m_triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(m_triggerPin, LOW);
        delayMicroseconds(40);

        unsigned int delayUS = timestampLow - timestampHigh;
        if (delayUS < 25e3)
        {
            emit distanceUpdated(delayUS / 0.58);
        }

        delay(100);
    }
}
