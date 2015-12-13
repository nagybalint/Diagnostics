#include "robotstatusmessage.h"
#include <QDebug>

RobotStatusMessage::RobotStatusMessage() :
    state()
{
    this->type = RobotStatusMessage::Type::StatusUpdate;
}


int RobotStatusMessage::parseMessage(QDataStream &inStream) {

    if(inStream.device()->bytesAvailable() < this->size)
        return -1;

    quint8 byteIn;
    float byteInArray[5];
    quint8* bytePtr;

    for(int i = 0; i < 4; i++)
    {
        bytePtr = (quint8*) &(byteInArray[i]);
        for(int j = 0; j < 4; j++) {
            inStream >> byteIn;
            bytePtr[j] = byteIn;
        }
    }

    this->state.setCarSpeed(byteInArray[0]);
    this->state.setSteeringAngle(byteInArray[1]);
    this->state.lineSensor.frontLinePos = byteInArray[2];
    this->state.lineSensor.lineOrientation = byteInArray[3];

    return 0;

}


