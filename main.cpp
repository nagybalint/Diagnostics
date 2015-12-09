#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "Comm/commserial.h"
#include "Comm/robotmsghandler.h"
#include "Comm/robotterminalmessage.h"

int main(int argc, char *argv[])
{

    Q_UNUSED(argc);
    Q_UNUSED(argv);

    CommSerial serial;

    RobotMsgHandler handler(serial);
    handler.listenOn(serial);
    serial.connect();

    QString getHelpStr("help");
    RobotTerminalMessage getHelp(getHelpStr);

    serial.send(getHelp);

    while(1) {
        serial.send(getHelp);
    }

    return 0;
}

