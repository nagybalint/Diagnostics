#include "Application.h"
#include <QDebug>
#include "Comm/commserial.h"
#include "Comm/robotmsghandler.h"
#include "Comm/robotterminalmessage.h"
#include "robottest.h"

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv), engine(), consoleTab(*engine.rootContext()), history(),
      graphTab(*engine.rootContext(), history), serial(), handler(serial),
      updateRequest(handler), mainWindow(*engine.rootContext(), history), selfTest(handler)
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
    QObject::connect(rootObject, SIGNAL(runTestCmd()), &selfTest, SLOT(run()));
    QObject::connect(rootObject, SIGNAL(abortTestCmd()), &selfTest, SLOT(abort()));
    QObject::connect(rootObject, SIGNAL(setPid(qreal, qreal, qreal)), &mainWindow, SLOT(setPidParemeters(qreal,qreal,qreal)));
    QObject::connect(rootObject, SIGNAL(setSS(QString, QString)), &mainWindow, SLOT(setSSParameters(QString,QString)));
    QObject::connect(&consoleTab, SIGNAL(commandAvailable(QString&)), &handler, SLOT(sendTerminalMsg(QString&)));
    QObject::connect(&handler, SIGNAL(terminalMessageReceived(QString&)), &consoleTab, SLOT(addToListView(QString&)));
    QObject::connect(&handler, SIGNAL(statusUpdateReceived(RobotState&)), &history, SLOT(add(RobotState&)));
    QObject::connect(&handler, SIGNAL(errorMessageReceived(RobotErrorMessage::Code)), &mainWindow, SLOT(errorMsgReceived(RobotErrorMessage::Code)));
    QObject::connect(&selfTest, SIGNAL(robotTestMessage(QString)), &mainWindow, SLOT(selfTestReceivedMessage(QString)));
    QObject::connect(&mainWindow, SIGNAL(startRobotControl(RobotStartMessage&)), &handler, SLOT(sendStartMessage(RobotStartMessage&)));
    QObject::connect(&mainWindow, SIGNAL(stopRobotControl(RobotStartMessage&)), &handler, SLOT(sendStartMessage(RobotStartMessage&)));
    QObject::connect(&mainWindow, SIGNAL(controlParametersUpdated(Config&)), &handler, SLOT(sendConfig(Config&)));

    serial.connect();
    updateRequest.start(30);

}


