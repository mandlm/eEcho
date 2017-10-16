#pragma once

#include "hcsr04.h"
#include <QThread>

class DistanceThread : public QThread
{
    Q_OBJECT

private:
	HCSR04 m_hcsr04;

public:
	DistanceThread() = delete;
    DistanceThread(unsigned int triggerPin, unsigned int echoPin);

protected:
    void run() override;

signals:
    void distanceUpdated(double distMeters);
};

