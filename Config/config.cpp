#include "config.h"
#include <QFile>
#include <QString>
#include <QDebug>

Config::Config(QObject *parent) : QObject(parent), pid()
{

}

void Config::writeTo(QDataStream &stream) const
{
    stream << pid;
}

void Config::readFrom(QDataStream &stream)
{
    stream >> pid;
}

void Config::setPid(Pid &pid) {
    this->pid = pid;
}


Config &Config::operator=(const Config &other)
{
    pid = other.pid;

    return *this;
}

QDataStream& operator<<(QDataStream& stream, const Config& Config) {
    Config.writeTo(stream);
    return stream;
}

QDataStream& operator>>(QDataStream& stream, Config& Config) {
    Config.readFrom(stream);
    return stream;
}
