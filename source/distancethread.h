#pragma once

#include <QThread>

class DistanceThread : public QThread
{
    Q_OBJECT

private:
    const int m_triggerPin = 28;
    const int m_echoPin = 29;

public:
    DistanceThread();

protected:
    void run() override;

signals:
    void distanceUpdated(double distMeters);
};

