#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "Comm/communication.h"

void dataReady(QByteArray data) {
    qDebug() << "Data IN: " << data;
}

int main(int argc, char *argv[])
{

    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Communication serial;

    QObject::connect(&serial, &Communication::dataReady, dataReady);

    serial.connect();

    serial.send("help");
    serial.send(QByteArray(1, 13));

    while(1) {
        ;
    }

    return 0;
}

