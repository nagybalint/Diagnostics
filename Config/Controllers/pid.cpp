#include "pid.h"

Pid::Pid(QObject *parent) : QObject(parent)
{
    Kp = 20.0;
    Ki = 0.0;
    Kd = 300.0;
}

void Pid::setKp(float param) {
    Kp = param;
}

void Pid::setKi(float param) {
    Ki = param;
}

void Pid::setKd(float param) {
    Kd = param;
}

float Pid::getKp(void) const {
    return Kp;
}

float Pid::getKi(void) const {
    return Ki;
}

float Pid::getKd(void) const {
    return Kd;
}

void Pid::writeTo(QDataStream& stream) const {
    stream << Kp;
    stream << Ki;
    stream << Kd;
}

void Pid::readFrom(QDataStream &stream)
{
    stream >> Kp;
    stream >> Ki;
    stream >> Kd;
}

Pid &Pid::operator=(const Pid &other)
{
    Kp = other.Kp;
    Ki = other.Ki;
    Kd = other.Kd;

    return *this;
}

QDataStream& operator<<(QDataStream& stream, const Pid& Pid) {
    Pid.writeTo(stream);
    return stream;
}

QDataStream& operator>>(QDataStream& stream, Pid& Pid) {
    Pid.readFrom(stream);
    return stream;
}
