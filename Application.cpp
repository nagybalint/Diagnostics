#include "Application.h"
#include <QDebug>
#include "Comm/commserial.h"
#include "Comm/robotmsghandler.h"
#include "Comm/robotterminalmessage.h"

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv), engine(), console(*engine.rootContext())
{

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    auto rootObjects = engine.rootObjects();
    if (rootObjects.size() == 0)
    {
        qDebug() << "HIBA: Nem sikerült létrehozni a QML környezetet.";
        return;
    }

    QObject *rootObject = rootObjects[0];

    QObject::connect(rootObject, SIGNAL(sendTextInput(QString)), &console, SLOT(consoleTextArrived(QString)));
    QObject::connect(rootObject, SIGNAL(keyPressed(int)), &console, SLOT(consoleKeyPressed(int)));


    CommSerial serial;

    RobotMsgHandler handler(serial);
    handler.listenOn(serial);
    serial.connect();

    QString getHelpStr("help");
    RobotTerminalMessage getHelp(getHelpStr);

    serial.send(getHelp);


}

