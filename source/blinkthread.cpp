#include "blinkthread.h"
#include "led.h"

BlinkThread::BlinkThread(unsigned int pin)
	: m_led(pin)
{
}

void BlinkThread::run()
{
    while (true)
    {
       	m_led.on(); 
        emit ledOn();
        msleep(500);

		m_led.off();
        emit ledOff();
        msleep(500);
    }
}
