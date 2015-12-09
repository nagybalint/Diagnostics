#include "distancesensor.h"

DistanceSensor::DistanceSensor(QObject *parent) : QObject(parent)
{
    distLeft = 0;
    distRight = 0;
    distFront = 0;
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

