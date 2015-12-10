#include "robotstatusrequest.h"


RobotStatusRequest::RobotStatusRequest() {
    this->type = RobotMessage::Type::StatusRequest;
}

// Dummy function
int RobotStatusRequest::parseMessage(QDataStream &inStream) {
    Q_UNUSED(inStream);
    return 0;
}


QDataStream& operator<<(QDataStream& stream, RobotStatusRequest& msg) {
    stream << (quint8) DEBUG_MSG_START_CODE;
    stream << (quint8) msg.type;
    stream << (quint8) 0; // Dummy data for robot state machine
    stream << (quint8) DEBUG_MSG_END_CODE;
}
