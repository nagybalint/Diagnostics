#ifndef ROBOTSTATUSREQUEST_H
#define ROBOTSTATUSREQUEST_H

#include <QObject>
#include "robotmessage.h"
#include <QDataStream>

class RobotStatusRequest : public RobotMessage
{
    Q_OBJECT
public:
    RobotStatusRequest();
    int parseMessage(QDataStream &inStream) override;

signals:

public slots:
};

QDataStream& operator<<(QDataStream&, const RobotStatusRequest&);

#endif // ROBOTSTATUSREQUEST_H
