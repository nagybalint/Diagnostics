#include "distancesensor.h"

DistanceSensor::DistanceSensor(QObject *parent) : QObject(parent)
{
    distLeft = 0;
    distRight = 0;
    distFront = 0;
}

DistanceSensor::DistanceSensor(const DistanceSensor &from)
{
    distLeft = from.distLeft;
    distRight = from.distRight;
    distFront = from.distFront;
}

float DistanceSensor::getDistLeft()
{
    return distLeft;
}

float DistanceSensor::getDistRight()
{
    return distRight;
}

float DistanceSensor::getDistFront()
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

QDataStream& operator<<(QDataStream& stream, const DistanceSensor& DistanceSensor) {
    DistanceSensor.writeTo(stream);
    return stream;
}

QDataStream& operator>>(QDataStream& stream, DistanceSensor& DistanceSensor) {
    DistanceSensor.readFrom(stream);
    return stream;
}
