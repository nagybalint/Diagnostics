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

    quint16 getCode();
    quint32 getMsgSize();

    int parseMessage(QDataStream &inStream) override;

    enum class Code {
        LowBattery3S = 0x0001,
        LowBattery2S = 0x0002
    };

    RobotErrorMessage::Code getErrorCode(quint16 codeByte);

private:
    RobotErrorMessage::Code errorCode;
    const quint32 msgSize = 2; // In bytes

signals:
    void robotError(RobotErrorMessage::Code errorCode);

public slots:
};

#endif // ROBOTERRORMESSAGE_H
