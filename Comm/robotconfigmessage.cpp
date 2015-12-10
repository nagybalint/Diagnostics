#include "robotconfigmessage.h"

RobotConfigMessage::RobotConfigMessage(Config& conf) {
    this->type = RobotMessage::Type::Config;
    this->config = &conf;
}

int RobotConfigMessage::parseMessage(QDataStream& inStream) {
    Q_UNUSED(inStream);
    return 0;
}

QDataStream& operator<<(QDataStream& stream, const RobotConfigMessage& msg) {

    stream << (quint8) DEBUG_MSG_START_CODE;
    stream << (quint8) msg.type;
    stream << *(msg.config);
    stream << (quint8) DEBUG_MSG_END_CODE;
    return stream;

}


