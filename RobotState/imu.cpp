#include "imu.h"

Imu::Imu(QObject *parent) : QObject(parent)
{
    orientX = 0;
    orientY = 0;
    orientZ = 0;
}

void Imu::setOrientX(float param)
{
    orientX = param;
}

void Imu::setOrientY(float param)
{
    orientY = param;
}

void Imu::setOrientZ(float param)
{
    orientZ = param;
}

float Imu::getOrientX()
{
    return orientX;
}

float Imu::getOrientY()
{
    return orientY;
}

float Imu::getOrientZ()
{
    return orientZ;
}

