#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include "ConsoleTabEventClass.h"
#include "Comm/commserial.h"
#include "Comm/robotmsghandler.h"
#include "GraphTabEventClass.h"
#include <QTimer>
#include "robotstatehistory.h"
#include "updaterequest.h"
#include "MainWindowEventClass.h"

class Application : public QApplication
{
public:
    Application(int argc, char *argv[]);
    ~Application() = default;

    QQmlApplicationEngine engine;
    ConsoleTabEventClass consoleTab;
    RobotStateHistory history;
    GraphTabEventClass graphTab;
    CommSerial serial;
    RobotMsgHandler handler;
    UpdateRequest updateRequest;
    MainWindowEventClass mainWindow;
};

#endif // APPLICATION_H
