#include "roboterrormessage.h"
#include "QDataStream"
#include <QDebug>

RobotErrorMessage::RobotErrorMessage()
{
    this->type = RobotMessage::Type::Error;
}

RobotErrorMessage::Code RobotErrorMessage::getErrorCode(quint16 codeByte) {
    switch (codeByte) {
    case ((quint16) RobotErrorMessage::Code::LowBattery2S):
        return RobotErrorMessage::Code::LowBattery2S;
    case ((quint16) RobotErrorMessage::Code::LowBattery3S):
        return RobotErrorMessage::Code::LowBattery3S;
    default:
        break;
    }

    return (RobotErrorMessage::Code) 0;

}

RobotErrorMessage::Code RobotErrorMessage::getCode() {
    return this->errorCode;
}

int RobotErrorMessage::parseMessage(QDataStream &inStream) {

    if(inStream.device()->bytesAvailable() < this->msgSize)
        return -1;

    quint8 byteIn;
    quint16 error;
    inStream >> byteIn;
    error = byteIn;
    inStream >> byteIn;
    error |= (byteIn << 8);
    return 0;
}
