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
    float meomeomeo[5];
    quint8* bytePtr;

    for(int i = 0; i < 5; i++)
    {
        bytePtr = (quint8*) &(meomeomeo[i]);
        for(int j = 0; j < 4; j++) {
            inStream >> byteIn;
            bytePtr[j] = byteIn;
        }
    }

    this->state.setBatVoltage3S(meomeomeo[0]);
    this->state.setBatVoltage2S(meomeomeo[1]);
    this->state.setCarSpeed(meomeomeo[2]);
    this->state.setSteeringAngle(meomeomeo[3]);
    this->state.lineSensor.frontLinePos = meomeomeo[4];

    return 0;

}


