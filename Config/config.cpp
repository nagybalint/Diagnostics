#include "config.h"
#include <QFile>
#include <QString>
#include <QDebug>

Config::Config(QObject *parent) : QObject(parent)
{

}

void Config::writeTo(QDataStream &stream) const
{
    stream << Pid;
}

void Config::readFrom(QDataStream &stream)
{
    stream >> Pid;
}

QDataStream& operator<<(QDataStream& stream, const Config& Config) {
    Config.writeTo(stream);
    return stream;
}

QDataStream& operator>>(QDataStream& stream, Config& Config) {
    Config.readFrom(stream);
    return stream;
}
