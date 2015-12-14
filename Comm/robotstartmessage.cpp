#include "robotstartmessage.h"
#include <QDataStream>

RobotStartMessage::RobotStartMessage(RobotStartMessage::Type type) {
    this->type = RobotMessage::Type::Start;
    this->startType = type;
}

int RobotStartMessage::parseMessage(QDataStream &inStream) {
    Q_UNUSED(inStream);
    return 0;
}

QDataStream& operator<<(QDataStream& stream, const RobotStartMessage& msg) {
    stream << (quint8) DEBUG_MSG_START_CODE;
    stream << (quint8) msg.type;
    stream << (quint8) msg.startType;
    stream << (quint8) DEBUG_MSG_END_CODE;
    return stream;
}
