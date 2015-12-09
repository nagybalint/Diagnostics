#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H

#include <QObject>
#include <QDataStream>
#include <QString>
#include "RobotState/imu.h"
#include "RobotState/linesensor.h"
#include "RobotState/distancesensor.h"
#include "Config/config.h"

class RobotState : public QObject
{
    Q_OBJECT
public:
    explicit RobotState(QObject *parent = 0);
/*
    Q_PROPERTY(Config config READ getConfig WRITE setConfig MEMBER Config NOTIFY configChanged)
    Config getConfig() const { return Config; }
    void setConfig(const Config& param) { Config = param; }

    Q_PROPERTY(Imu imu READ getImu WRITE setImu MEMBER IMU NOTIFY imuChanged)
    Imu getImu() const { return IMU; }
    void setImu(const Imu& param) { IMU = param; }

    Q_PROPERTY(LineSensor linesensor READ getLineSensor WRITE setLineSensor MEMBER LineSensor NOTIFY linesensorChanged)
    LineSensor getLineSensor() const { return LineSensor; }
    void setLineSensor(const LineSensor& param) { LineSensor = param; }

    Q_PROPERTY(DistanceSensor distsensor READ getDistanceSensor WRITE setDistanceSensor MEMBER DistanceSensor NOTIFY distanceSensorChanged)
    Config getDistanceSensor() const { return DistanceSensor; }
    void setDistanceSensor(const DistanceSensor& param) { DistanceSensor = param; }
*/
    Q_PROPERTY(float batvoltage3S READ getBatVoltage3S WRITE setBatVoltage3S MEMBER batVoltage3S NOTIFY batVoltage3SChanged)
    float getBatVoltage3S() const { return batVoltage3S; }
    void setBatVoltage3S(const float& param) { batVoltage3S = param; }

    Q_PROPERTY(float batvoltage2S READ getBatVoltage2S WRITE setBatVoltage2S MEMBER batVoltage3S NOTIFY batVoltage2SChanged)
    float getBatVoltage2S() const { return batVoltage2S; }
    void setBatVoltage2S(const float& param) { batVoltage2S = param; }

    Q_PROPERTY(float carspeed READ getCarSpeed WRITE setCarSpeed MEMBER carSpeed NOTIFY carSpeedChanged)
    float getCarSpeed() const { return carSpeed; }
    void setCarSpeed(const float& param) { carSpeed = param; }

    Q_PROPERTY(float steeringangle READ getSteeringAngle WRITE setSteeringAngle MEMBER steeringAngle NOTIFY steeringAngleChanged)
    float getSteeringAngle() const { return steeringAngle; }
    void setSteeringAngle(const float& param) { steeringAngle = param; }

    Q_PROPERTY(float frontsensorangle READ getFrontSensorAngle WRITE setFrontSensorAngle MEMBER frontSensorAngle NOTIFY frontSensorAngleChanged)
    float getFrontSensorAngle() const { return frontSensorAngle; }
    void setFrontSensorAngle(const float& param) { frontSensorAngle = param; }

    void writeTo(QDataStream& stream) const;
    void readFrom(QDataStream& stream);
    void copyFrom(const RobotState &other);

signals:
    /* not used */
    void batVoltage3SChanged();
    void batVoltage2SChanged();
    void carSpeedChanged();
    void steeringAngleChanged();
    void frontSensorAngleChanged();

public slots:

private:
    /* Configurable values (eg. controller gains) */
    Config config;

    /* car orientations around each axis */
    Imu IMU;

    /* data from linesensor */
    LineSensor lineSensor;

    /* distance sensors data */
    DistanceSensor distanceSensor;

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
