#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QSerialPort>
#include <memory>

class Communication : public QObject
{
    Q_OBJECT
public:
    Communication();
    ~Communication();

    bool isConnected();
    void connect();
    void disconnect();

    void send(QByteArray data);

private:
    QSerialPort serialPort;

signals:
    /* TODO
     *  Error signal
     */

    void dataReady(QByteArray data);

public slots:
    void dataReceived();
    void handleSerialPortError(QSerialPort::SerialPortError error);
};

#endif // COMMUNICATION_H
