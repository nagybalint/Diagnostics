#ifndef ROBOTMSGHANDLER_H
#define ROBOTMSGHANDLER_H

#include <QObject>

#include "commserial.h"
#include "robotmessage.h"
#include "roboterrormessage.h"
#include "RobotState/robotstate.h"

class RobotMsgHandler : public QObject
{
    Q_OBJECT
public:
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
    CommSerial* serial;
    std::unique_ptr<RobotMessage> messageIn;

signals:
    void messageError(RobotMsgHandler::Error errorCode);

    void terminalMessageReceived(QString& msg);
    void errorMessageReceived(RobotErrorMessage::Code errorCode);
    void statusUpdateReceived(RobotState& newState);

private:
    void emitSignal(RobotMessage* msg);

public slots:

    void dataAvailable(QDataStream &inStream);
    void sendTerminalMsg(QString& command);
    void setRobotAttribute(RobotMessage::Type attr, float value);
    void sendStatusRequest();

};

#endif // ROBOTMSGHANDLER_H