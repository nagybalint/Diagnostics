#include "commserial.h"
#include <QDebug>
#include <QDataStream>

CommSerial::CommSerial() : receiveStream(nullptr) {

    serialPort.setBaudRate(115200);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setPortName("COM20");
    serialPort.setFlowControl(QSerialPort::NoFlowControl);
    serialPort.setDataBits(QSerialPort::Data8);

    QObject::connect(&serialPort, SIGNAL(error(QSerialPort::SerialPortError)),
            this,SLOT(handleSerialPortError(QSerialPort::SerialPortError)));

}

CommSerial::~CommSerial()  {

    if(receiveStream != nullptr)
        receiveStream = nullptr;

    serialPort.disconnect();
}

bool CommSerial::isConnected() {
    return serialPort.isOpen();
}

void CommSerial::connect() {
    if( !serialPort.open(QIODevice::ReadWrite) ) {
        qDebug() << "ERROR: Could not connect to serial port";
        // TODO emit error signal
    }
    else {
        receiveStream = std::make_unique<QDataStream>(&serialPort);
        QObject::connect(&serialPort, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    }
}

void CommSerial::disconnect() {
    if(!isConnected()) {
        serialPort.close();
    }
}

QDataStream* CommSerial::getReceiveStream() {
    return receiveStream.get();
}

std::unique_ptr<QDataStream> CommSerial::getSendStream() {
    return std::unique_ptr<QDataStream>(new QDataStream(&sendBuffer, QIODevice::WriteOnly));
}

void CommSerial::sendBufferedContent() {

    if(!serialPort.isOpen()) {
        qDebug() << "Trying to write to closed serial port";
        // TODO emit error message, show message dialog, etc
        return;
    }

    if(sendBuffer.size() > 0) {
        serialPort.write(sendBuffer);
        serialPort.waitForBytesWritten(-1);
    }
    else
        qDebug() << "SP: Writing data with negative length";

}

void CommSerial::dataReceived() {

    QDataStream& received = *getReceiveStream();
    if(received.device()->bytesAvailable() > 0)
        emit this->dataAvailable(received);
}

void CommSerial::handleSerialPortError(QSerialPort::SerialPortError error) {
    qDebug() << "Serial ERROR: " <<  error;
}
