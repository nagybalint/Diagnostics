#include "robotterminalmessage.h"
#include <QDataStream>
#include <QDebug>

RobotTerminalMessage::RobotTerminalMessage()
{
    this->type = RobotMessage::Type::Terminal;
}

RobotTerminalMessage::RobotTerminalMessage(QString& msg) : RobotTerminalMessage() {
    this->message = msg;
}

void RobotTerminalMessage::setMessage(QString& msg) {
    this->message = msg;
}

QString& RobotTerminalMessage::getMessage() {
    return this->message;
}

int RobotTerminalMessage::parseMessage(QDataStream &inStream) {

    quint8 byteIn = 1;

    while(inStream.device()->bytesAvailable() && (char) byteIn != '\0') {
        inStream >> byteIn;
        message.append(byteIn);
    }
    if((char) byteIn == '\0') {
        qDebug() << message;
        return 0;
    }
    else
        return -1;
}

QDataStream &operator<<(QDataStream& stream, const RobotTerminalMessage& msg)
{
    stream << (quint8) DEBUG_MSG_START_CODE;
    stream << (quint8) msg.type;
    for(int i = 0; i < msg.message.length(); i++)
        stream << (quint8) msg.message[i].toLatin1();
    // Send ENTER instead of '\0'
    stream << (quint8) '\r';
    stream << (quint8) DEBUG_MSG_END_CODE;
    return stream;
}
