#include "config.h"
#include <QFile>
#include <QString>
#include <QDebug>

Config::Config(QObject *parent) : QObject(parent)
{

}

void Config::write(QString fileName) {
    QFile configFile(fileName);

    if(!configFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Could not open file to writing";
        return;
    }

    configFile.close();
}


void Config::read(QString fileName) {

}
