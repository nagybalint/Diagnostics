#include "robotmsghandler.h"
#include "robotmessage.h"
#include "robotterminalmessage.h"
#include "roboterrormessage.h"
#include "robotsetattrmessage.h"
#include "robotstatusmessage.h"
#include "robotstatusrequest.h"
#include "robotconfigmessage.h"
#include <QDataStream>
#include <QTimer>
#include <QIODevice>
#include <QDebug>
#include <memory>


RobotMsgHandler::RobotMsgHandler(CommSerial& serial) :
    currentParseState(RobotMsgHandler::ParseState::StartByte),
    messageIn(nullptr)
{
    listenOn(serial);
}

void RobotMsgHandler::listenOn(CommSerial& serial) {
    this->serial = &serial;
    QObject::connect(this->serial, SIGNAL(dataAvailable(QDataStream&)), this, SLOT(dataAvailable(QDataStream&)));
}

void RobotMsgHandler::dataAvailable(QDataStream &inStream) {

    quint8 byteIn;
    QIODevice* socket = inStream.device();
    switch (currentParseState) {
    case RobotMsgHandler::ParseState::StartByte:
        inStream >> byteIn;
        if(byteIn == DEBUG_MSG_START_CODE)
            this->currentParseState = ParseState::MsgType;
        else
            emit this->messageError(RobotMsgHandler::Error::MissingStartByte);
        break;

    case RobotMsgHandler::ParseState::MsgType:
        inStream >> byteIn;
        currentParseState = RobotMsgHandler::ParseState::Parsing;
        switch (RobotMessage::getType(byteIn)) {
        case RobotMessage::Type::Terminal:
            messageIn = std::make_unique<RobotTerminalMessage>();
            break;
        case (RobotMessage::Type::Error):
            messageIn = std::make_unique<RobotErrorMessage>();
            break;
        case(RobotMessage::Type::StatusUpdate):
            messageIn = std::make_unique<RobotStatusMessage>();
            break;
        default:
            emit this->messageError(RobotMsgHandler::Error::UnknownType);
            currentParseState = RobotMsgHandler::ParseState::StartByte;
            break;
        }
        break;

    case RobotMsgHandler::ParseState::Parsing:
        if(!messageIn->parseMessage(inStream)) {
            emitSignal(messageIn.get());
            currentParseState = RobotMsgHandler::ParseState::EndByte;
        }
        break;

    case RobotMsgHandler::ParseState::EndByte:
        inStream >> byteIn;
        if(byteIn != DEBUG_MSG_END_CODE) {
            emit this->messageError(RobotMsgHandler::Error::MissingEndByte);
        }
        currentParseState = RobotMsgHandler::ParseState::StartByte;

    default:
        break;
    }

    if (socket->bytesAvailable() > 0) {
        QTimer::singleShot(0, serial, SLOT(dataReceived()));
    }
}

void RobotMsgHandler::emitSignal(RobotMessage* msg) {

    switch (msg->type) {
    case RobotMessage::Type::Terminal:
        emit this->terminalMessageReceived(((RobotTerminalMessage*) msg)->getMessage());
        break;
    case RobotMessage::Type::Error:
        emit this->errorMessageReceived(((RobotErrorMessage*) msg)->getCode());
        break;
    case RobotMessage::Type::StatusUpdate:
        emit this->statusUpdateReceived(((RobotStatusMessage*) msg)->state);
        break;
    default:
        break;
    }

}

void RobotMsgHandler::sendTerminalMsg(QString& command) {

    RobotTerminalMessage msg(command);
    this->serial->send(msg);
}

void RobotMsgHandler::setRobotAttribute(RobotMessage::Type attr, float value) {

    RobotSetAttrMessage msg(attr, value);
    this->serial->send(msg);

}

void RobotMsgHandler::sendStatusRequest() {
    RobotStatusRequest msg;
    this->serial->send(msg);
}

void RobotMsgHandler::sendConfig(Config& config) {
    RobotConfigMessage msg(config);
    this->serial->send(msg);
}

void RobotMsgHandler::sendStartMessage(RobotStartMessage& msg) {
    this->serial->send(msg);
}
