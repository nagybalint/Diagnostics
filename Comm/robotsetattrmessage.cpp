#include "robotsetattrmessage.h"

RobotSetAttrMessage::RobotSetAttrMessage(RobotMessage::Type type, float value) {
    this->type = type;
    this->value = value;
}

// Dummy function
int RobotSetAttrMessage::parseMessage(QDataStream &inStream) {
    Q_UNUSED(inStream);
    return 0;
}

QDataStream& operator<<(QDataStream& stream, const RobotSetAttrMessage& msg) {

    quint8* dataByte = ((quint8*) &msg.value);

    stream << (quint8) DEBUG_MSG_START_CODE;
    stream << (quint8) msg.type;
    for(int i = 0; i < 4; i++)
        stream << dataByte[i];
    stream << (quint8) DEBUG_MSG_END_CODE;
    return stream;
}
