#include "roboterrormessage.h"

RobotErrorMessage::RobotErrorMessage()
{ }

quint32 RobotErrorMessage::getMsgSize() {
    return this->msgSize;
}

int RobotErrorMessage::parseMessage(QDataStream &inStream) {

    Q_UNUSED(inStream);

    /*
     *  A msghandler állapotgépben vagyunk még... csak akkor adja ide a vezérlést ha a teljes üzenet megjött
     * ezt pedig stream->device()->bytesAvailable() >= getMsgSize() -ból tudja...
     */
    return 0;
}

