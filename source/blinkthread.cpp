#include "blinkthread.h"
#include <wiringPi.h>

BlinkThread::BlinkThread()
{
    wiringPiSetup();
    pinMode(m_blinkPin, OUTPUT);
}

void BlinkThread::run()
{
    while (true)
    {
        digitalWrite(m_blinkPin, HIGH);
        emit ledOn();
        delay(500);

        digitalWrite(m_blinkPin, LOW);
        emit ledOff();
        delay(500);
    }
}
