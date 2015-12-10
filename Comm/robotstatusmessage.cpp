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

    for(int i = 0; i < 5; i++)
    {
        QByteArray bytes;
        for(int j = 0; j < 4; j++) {
            inStream >> byteIn;
            bytes.append(byteIn);
        }
        qDebug() << "hex: " << bytes.toHex() << ", Float: " << bytes.toFloat();
    }

    return 0;

}


