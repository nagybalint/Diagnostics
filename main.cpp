#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "Comm/commserial.h"

void dataReady(QDataStream& data) {
    qDebug() << "Data IN: ";
    quint8 byteIn;
    for(int i = data.device()->bytesAvailable(); i > 0; i--) {
        data >> byteIn;
        qDebug() << byteIn;
    }
}

int main(int argc, char *argv[])
{

    Q_UNUSED(argc);
    Q_UNUSED(argv);

    CommSerial serial;

    QObject::connect(&serial, &CommSerial::dataAvailable, dataReady);

    serial.connect();

    serial.send("help");

    QTextStream s(stdin);
    QString str;

    while(1) {
        serial.send("ahah ha  ");
    }

    return 0;
}

