#include "robotterminalmessage.h"
#include <QDataStream>

RobotTerminalMessage::RobotTerminalMessage()
{
    this->type = RobotMessage::Type::Terminal;
}

int RobotTerminalMessage::parseMessage(QDataStream &inStream) {

    qint8 byteIn;

    for(int i = 0; i < inStream.device()->bytesAvailable(); i++) {
        inStream >> byteIn;
        message.append(byteIn);
    }

    if(byteIn == '\0')
        return 0;
    else
        return -1;

}

QDataStream &operator<<(QDataStream& stream, const RobotTerminalMessage& msg)
{
    stream << (quint8) DEBUG_MSG_START_CODE;
    stream << (quint8) msg.type;
    for(int i = 0; i < msg.message.length() - 1; i++)
        stream << msg.message[i];
    // Send ENTER instead of '\0'
    stream << (quint8) '\r';
    stream << (quint8) DEBUG_MSG_END_CODE;
    return stream;
}
