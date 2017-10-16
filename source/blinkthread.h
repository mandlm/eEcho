#pragma once

#include "led.h"
#include <QThread>

class BlinkThread : public QThread
{
    Q_OBJECT

private:
	Led m_led;

public:
	BlinkThread() = delete;
	BlinkThread(unsigned int pin);

protected:
    void run() override;

signals:
    void ledOn();
    void ledOff();
};

