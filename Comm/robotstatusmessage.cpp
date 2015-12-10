#include "robotstatusmessage.h"

RobotStatusMessage::RobotStatusMessage() :
    state()
{
    this->type = RobotStatusMessage::Type::Status;
}


int RobotStatusMessage::parseMessage(QDataStream &inStream) {

    if(inStream.device()->bytesAvailable() < this->size)
        return -1;
    float dataIn;

    inStream >> dataIn;
    state.setBatVoltage3S(dataIn);
    inStream >> dataIn;
    state.setBatVoltage2S(dataIn);
    inStream >> dataIn;
    state.setCarSpeed(dataIn);
    inStream >> dataIn;
    state.lineSensor.frontLinePos = dataIn;
    inStream >> dataIn;
    state.setSteeringAngle(dataIn);


    return 0;

}


