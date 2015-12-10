#ifndef ROBOTSTATUSMESSAGE_H
#define ROBOTSTATUSMESSAGE_H

#include <QObject>
#include "robotmessage.h"
#include "RobotState/robotstate.h"

class RobotStatusMessage : public RobotMessage
{
    Q_OBJECT
public:

    RobotState state;
    RobotStatusMessage();
    ~RobotStatusMessage() = default;
    int parseMessage(QDataStream &inStream) override;

private:
    static const quint32 size = 5 * sizeof(float);
signals:

public slots:
};

#endif // ROBOTSTATUSMESSAGE_H
