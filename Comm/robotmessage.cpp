#include "robotmessage.h"

RobotMessage::RobotMessage()
{ }

RobotMessage::Type RobotMessage::getType(quint8 modeID) {
    switch (modeID) {
    case (quint8) RobotMessage::Type::Terminal:
        return RobotMessage::Type::Terminal;
    case (quint8) RobotMessage::Type::Config:
        return RobotMessage::Type::Config;
    case (quint8) RobotMessage::Type::Error:
        return RobotMessage::Type::Error;
    default:
        break;
    }
}
