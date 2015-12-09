#ifndef ROBOTMESSAGE_H
#define ROBOTMESSAGE_H

#include <QObject>

#define DEBUG_MSG_START_CODE                0x02
#define DEBUG_MSG_END_CODE                  0x03

class RobotMessage : public QObject
{
    Q_OBJECT
public:

    RobotMessage();
    ~RobotMessage() = default;

    enum class Type {
        Terminal = 0x00,
        Error = 0x01,
        Status = 0x02,
        Config = 0x03
    };

    Type type;

    static RobotMessage::Type getType(quint8 modeID);

    virtual int parseMessage(QDataStream &inStream) = 0;

signals:
    void messageError(QString description);

};

#endif // ROBOTMESSAGE_H
