#include "distancesensor.h"

DistanceSensor::DistanceSensor(QObject *parent) : QObject(parent)
{
    distLeft = 0;
    distRight = 0;
    distFront = 0;
}

float DistanceSensor::getDistLeft() const
{
    return distLeft;
}

float DistanceSensor::getDistRight() const
{
    return distRight;
}

float DistanceSensor::getDistFront() const
{
    return distFront;
}

void DistanceSensor::writeTo(QDataStream &stream) const
{
    stream << distLeft;
    stream << distRight;
    stream << distFront;
}

void DistanceSensor::readFrom(QDataStream &stream)
{
    stream >> distLeft;
    stream >> distRight;
    stream >> distFront;
}

DistanceSensor &DistanceSensor::operator=(const DistanceSensor &other)
{
    distLeft = other.getDistLeft();
    distRight = other.getDistRight();
    distFront = other.getDistFront();

    return *this;
}

QDataStream& operator<<(QDataStream& stream, const DistanceSensor& DistanceSensor) {
    DistanceSensor.writeTo(stream);
    return stream;
}

QDataStream& operator>>(QDataStream& stream, DistanceSensor& DistanceSensor) {
    DistanceSensor.readFrom(stream);
    return stream;
}
