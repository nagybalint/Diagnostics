#include "Application.h"
#include <QDebug>
#include "Comm/commserial.h"
#include "Comm/robotmsghandler.h"
#include "Comm/robotterminalmessage.h"

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv), engine(), consoleTab(*engine.rootContext()), history(),
      graphTab(*engine.rootContext(), history), serial(), handler(serial),
      updateRequest(handler), mainWindow(*engine.rootContext(), history)
{

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    auto rootObjects = engine.rootObjects();
    if (rootObjects.size() == 0)
    {
        qDebug() << "HIBA: Nem sikerült létrehozni a QML környezetet.";
        return;
    }

    QObject *rootObject = rootObjects[0];

    graphTab.connectQmlSignals(rootObject, QString("speedGraph"));
    graphTab.connectQmlSignals(rootObject, QString("positionGraph"));
    graphTab.connectQmlSignals(rootObject, QString("steeringAngleGraph"));
    mainWindow.connectQmlSignals(rootObject, QString("graphOrientation"));

    QObject::connect(rootObject, SIGNAL(sendTextInput(QString)), &consoleTab, SLOT(consoleTextArrived(QString)));
    QObject::connect(rootObject, SIGNAL(keyPressed(int)), &consoleTab, SLOT(consoleKeyPressed(int)));
    QObject::connect(rootObject, SIGNAL(startCommand()), &mainWindow, SLOT(startCommand()));
    QObject::connect(rootObject, SIGNAL(stopCommand()), &mainWindow, SLOT(stopCommand()));
    QObject::connect(&consoleTab, SIGNAL(commandAvailable(QString&)), &handler, SLOT(sendTerminalMsg(QString&)));
    QObject::connect(&handler, SIGNAL(terminalMessageReceived(QString&)), &consoleTab, SLOT(addToListView(QString&)));
    QObject::connect(&handler, SIGNAL(statusUpdateReceived(RobotState&)), &history, SLOT(add(RobotState&)));

    serial.connect();
    updateRequest.start(100);

}


