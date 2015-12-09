#ifndef ROBOTMSGHANDLER_H
#define ROBOTMSGHANDLER_H

#include <QObject>

#include "commserial.h"
#include "robotmessage.h"

class RobotMsgHandler : public QObject
{
    Q_OBJECT
public:
    RobotMsgHandler() = default;
    RobotMsgHandler(CommSerial& serial);
    ~RobotMsgHandler() = default;

    void listenOn(CommSerial& serial);

    enum class Error {
        MissingStartByte, MissingEndByte, UnknownType
    };

private:
    enum class ParseState {
        StartByte,
        MsgType,
        Parsing,
        EndByte
    };
    ParseState currentParseState;

    std::unique_ptr<RobotMessage> messageIn;

signals:
    void messageError(RobotMsgHandler::Error errorCode);

public slots:

    void dataAvailable(QDataStream &inStream);

};

#endif // ROBOTMSGHANDLER_H
