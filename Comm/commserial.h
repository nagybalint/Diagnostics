#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QSerialPort>
#include <memory>

class CommSerial : public QObject
{
    Q_OBJECT
public:
    CommSerial();
    ~CommSerial();

    bool isConnected();
    void connect();
    void disconnect();

    template<typename T>
    void send(const T& outObject) {

        auto stream = getSendStream();
        *stream << outObject;
        sendBufferedContent();

    }

private:

    QSerialPort serialPort;
    QByteArray sendBuffer;
    std::unique_ptr<QDataStream> receiveStream;

    QDataStream* getReceiveStream();
    std::unique_ptr<QDataStream> getSendStream();

    void sendBufferedContent();

signals:
    /* TODO Error signal */

    void dataAvailable(QDataStream &inStream);

public slots:
    void dataReceived();
    void handleSerialPortError(QSerialPort::SerialPortError error);
};

#endif // COMMUNICATION_H
