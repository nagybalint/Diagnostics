#include "Application.h"
#include <QDebug>
#include "Comm/commserial.h"
#include "Comm/robotmsghandler.h"
#include "Comm/robotterminalmessage.h"

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv), engine(), console(*engine.rootContext()),
      serial(), handler(serial)
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
    QObject::connect(&console, SIGNAL(commandAvailable(QString&)), &handler, SLOT(sendTerminalMsg(QString&)));
    QObject::connect(&handler, SIGNAL(terminalMessageReceived(QString&)), &console, SLOT(addToListView(QString&)));
    serial.connect();

}


