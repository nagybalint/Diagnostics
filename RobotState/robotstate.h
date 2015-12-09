#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H

#include <QObject>
#include "RobotState/imu.h"
#include "RobotState/linesensor.h"
#include "RobotState/distancesensor.h"

class RobotState : public QObject
{
    Q_OBJECT
public:
    explicit RobotState(QObject *parent = 0);

signals:

public slots:

private:
    /* car orientations around each axis */
    Imu IMU;

    /* data from linesensor */
    LineSensor LineSensor;

    /* distance sensors data */
    DistanceSensor DistanceSensor;

    /* battery voltages */
    float batVoltage3S;     // [V]
    float batVoltage2S;     // [V]

    /* speed of the car */
    float carSpeed;         // [m/s]

    /* angle of the steering servo */
    float steeringAngle;    // [rad]

    /* angle of the front sensor servo */
    float frontSensorAngle; // [rad]

};

#endif // ROBOTSTATE_H
