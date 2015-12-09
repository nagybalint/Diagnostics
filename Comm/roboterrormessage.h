#ifndef ROBOTERRORMESSAGE_H
#define ROBOTERRORMESSAGE_H

#include <QObject>
#include "robotmessage.h"

class RobotErrorMessage : public RobotMessage
{
    Q_OBJECT
public:
    RobotErrorMessage();
    ~RobotErrorMessage() = default;

    quint8 getCode();
    quint32 getMsgSize();

    int parseMessage(QDataStream &inStream) override;

private:
    quint8 code;
    const quint32 msgSize = 10;

signals:

public slots:
};

#endif // ROBOTERRORMESSAGE_H
