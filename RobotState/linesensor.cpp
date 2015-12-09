#include "linesensor.h"

LineSensor::LineSensor(QObject *parent) : QObject(parent)
{
    frontLinePos = 0;
    backLinePos = 0;
    lineOrientation = 0;
}

float LineSensor::getFrontLinePos()
{
    return frontLinePos;
}

float LineSensor::getBackLinePos()
{
    return backLinePos;
}

float LineSensor::getLineOrientation()
{
    return lineOrientation;
}

void LineSensor::writeTo(QDataStream &stream) const
{
    stream << frontLinePos;
    stream << backLinePos;
    stream << lineOrientation;
}

void LineSensor::readFrom(QDataStream &stream)
{
    stream >> frontLinePos;
    stream >> backLinePos;
    stream >> lineOrientation;
}

QDataStream& operator<<(QDataStream& stream, const LineSensor& LineSensor) {
    LineSensor.writeTo(stream);
    return stream;
}

QDataStream& operator>>(QDataStream& stream, LineSensor& LineSensor) {
    LineSensor.readFrom(stream);
    return stream;
}
