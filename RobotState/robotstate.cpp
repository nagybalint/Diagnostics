#include "robotstate.h"

RobotState::RobotState(QObject *parent) : QObject(parent)
{
    batVoltage3S = 0;
    batVoltage2S = 0;
    carSpeed = 0;
    steeringAngle = 0;
    frontSensorAngle = 0;
}

void RobotState::writeTo(QDataStream& stream) const
{
    stream << config;
    stream << carSpeed;
    stream << steeringAngle;
    stream << frontSensorAngle;
}

void RobotState::readFrom(QDataStream &stream)
{
    stream >> config;
    stream >> IMU;
    stream >> lineSensor;
    stream >> distanceSensor;
    stream >> batVoltage3S;
    stream >> batVoltage2S;
    stream >> carSpeed;
    stream >> steeringAngle;
    stream >> frontSensorAngle;
}

void RobotState::copyFrom(const RobotState &other)
{
    config = other.config;
    IMU = other.IMU;
    lineSensor = other.lineSensor;
    distanceSensor = other.distanceSensor;
    batVoltage3S = other.batVoltage3S;
    batVoltage2S = other.batVoltage2S;
    carSpeed = other.carSpeed;
    steeringAngle = other.steeringAngle;
    frontSensorAngle = other.frontSensorAngle;
}

QDataStream& operator<<(QDataStream& stream, const RobotState& RobotState) {
    RobotState.writeTo(stream);
    return stream;
}

QDataStream& operator>>(QDataStream& stream, RobotState& RobotState) {
    RobotState.readFrom(stream);
    return stream;
}
