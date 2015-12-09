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

