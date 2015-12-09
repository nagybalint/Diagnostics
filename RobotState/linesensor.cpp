#include "linesensor.h"

LineSensor::LineSensor(QObject *parent) : QObject(parent)
{
    frontLinePos = 0;
    backLinePos = 0;
    lineOrientation = 0;
}

float LineSensor::getFrontLinePos() const
{
    return frontLinePos;
}

float LineSensor::getBackLinePos() const
{
    return backLinePos;
}

float LineSensor::getLineOrientation() const
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

LineSensor &LineSensor::operator=(const LineSensor &other)
{
    frontLinePos = other.frontLinePos;
    backLinePos = other.backLinePos;
    lineOrientation = other.lineOrientation;

    return *this;
}

QDataStream& operator<<(QDataStream& stream, const LineSensor& LineSensor) {
    LineSensor.writeTo(stream);
    return stream;
}

QDataStream& operator>>(QDataStream& stream, LineSensor& LineSensor) {
    LineSensor.readFrom(stream);
    return stream;
}
