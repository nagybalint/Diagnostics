#ifndef ROBOTSETATTRMESSAGE_H
#define ROBOTSETATTRMESSAGE_H

#include "robotmessage.h"
#include <QDataStream>

class RobotSetAttrMessage : RobotMessage
{
public:

    float value;

    RobotSetAttrMessage(RobotMessage::Type type, float value);
    ~RobotSetAttrMessage() = default;
    int parseMessage(QDataStream &inStream) override;
    friend QDataStream& operator<<(QDataStream&, const RobotSetAttrMessage&);

};

QDataStream& operator<<(QDataStream&, const RobotSetAttrMessage&);

#endif // ROBOTSETATTRMESSAGE_H
