#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H

#include <QObject>
#include <QDataStream>
#include "RobotState/imu.h"
#include "RobotState/linesensor.h"
#include "RobotState/distancesensor.h"
#include "Config/config.h"

class RobotState : public QObject
{
    Q_OBJECT
public:
    explicit RobotState(QObject *parent = 0);

    void writeTo(QDataStream& stream) const;
    void readFrom(QDataStream& stream);

signals:

public slots:

private:
    /* Configurable values (eg. controller gains) */
    Config Config;

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

/* covers writeTo function */
QDataStream& operator<<(QDataStream& stream, const RobotState& RobotState);
/* covers readFrom function */
QDataStream& operator>>(QDataStream& stream, RobotState& RobotState);

#endif // ROBOTSTATE_H
