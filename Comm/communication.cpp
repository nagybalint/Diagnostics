#include "communication.h"
#include <QDebug>


Communication::Communication() {

    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setPortName("COM5");
    serialPort.setFlowControl(QSerialPort::NoFlowControl);
    serialPort.setDataBits(QSerialPort::Data8);

    QObject::connect(&serialPort, SIGNAL(error(QSerialPort::SerialPortError)),
            this,SLOT(handleSerialPortError(QSerialPort::SerialPortError)));

}

Communication::~Communication()  {
    serialPort.disconnect();
}

bool Communication::isConnected() {
    return serialPort.isOpen();
}

void Communication::connect() {
    if(!serialPort.open(QIODevice::ReadWrite)) {
        qDebug() << "ERROR: Could not connect to serial port";
        // TODO emit error signal
    }
    QObject::connect(&serialPort, SIGNAL(readyRead()), this, SLOT(dataReceived()));

}

void Communication::disconnect() {
    if(!isConnected()) {
        serialPort.close();
    }
}

void Communication::send(QByteArray data) {

    if(!serialPort.isOpen()) {
        qDebug() << "Trying to write to close serial port";
        // TODO emit error message, show message dialog, etc
        return;
    }

    if(data != NULL && data.size() > 0) {
        serialPort.write(data);
        serialPort.waitForBytesWritten(-1);
    }
    else
        qDebug() << "SP: Writing data with negative length";

}

void Communication::dataReceived() {
    QByteArray received = serialPort.readAll();
    emit this->dataReady(received);
    qDebug() << "Received:" << received;
}

void Communication::handleSerialPortError(QSerialPort::SerialPortError error) {
    qDebug() << "Serial ERROR: " <<  error;
}
