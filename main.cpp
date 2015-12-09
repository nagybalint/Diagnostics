#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "Comm/commserial.h"

void dataReady(QDataStream& data) {
    qDebug() << "Data IN: ";
    quint8 byteIn;
    QByteArray a;
    for(int i = data.device()->bytesAvailable(); i > 0; i--){
        data >> byteIn;
        a.append(byteIn);
    }
    QString s(a);
    qDebug() << s;
}

int main(int argc, char *argv[])
{

    Q_UNUSED(argc);
    Q_UNUSED(argv);

    CommSerial serial;

    QObject::connect(&serial, &CommSerial::dataAvailable, dataReady);

    serial.connect();

    QTextStream s(stdin);
    QString str;

    serial.send((quint8)'h');
    serial.send((quint8)'e');
    serial.send((quint8)'l');
    serial.send((quint8)'p');
    serial.send((quint8)13);

    while(1) {
        ;
    }

    return 0;
}

