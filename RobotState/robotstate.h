#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H

#include <QObject>
#include "RobotState/imu.h"

class RobotState : public QObject
{
    Q_OBJECT
public:
    explicit RobotState(QObject *parent = 0);

signals:

public slots:

private:
    Imu IMU;
    float batVoltage3S;
    float batVoltage2S;

};

#endif // ROBOTSTATE_H
