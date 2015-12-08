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

float Pid::getKp(void) {
    return Kp;
}

float Pid::getKi(void) {
    return Ki;
}

float Pid::getKd(void) {
    return Kd;
}

void Pid::writeTo(QDataStream& stream) const {
    stream << Kp;
    stream << Ki;
    stream << Kd;
}

QDataStream& operator<<(QDataStream& stream, const Pid& Pid) {
    Pid.writeTo(stream);
    return stream;
}
