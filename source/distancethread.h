#pragma once

#include <vector>
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

private:
	template<typename VALUE_TYPE>
	double median(std::vector<VALUE_TYPE> values) const;

signals:
    void distanceUpdated(double distMeters);
};

