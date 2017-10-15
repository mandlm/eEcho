#pragma once

#include <QThread>

class BlinkThread : public QThread
{
    Q_OBJECT

private:
    const int m_blinkPin = 15;

public:
    BlinkThread();

protected:
    void run() override;

signals:
    void ledOn();
    void ledOff();
};

