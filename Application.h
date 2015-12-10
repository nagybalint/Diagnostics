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

class Application : public QApplication
{
public:
    Application(int argc, char *argv[]);
    ~Application() = default;

    QQmlApplicationEngine engine;
    ConsoleTabEventClass console;
    RobotStateHistory history;
    GraphTabEventClass testGraph;
    CommSerial serial;
    RobotMsgHandler handler;
    UpdateRequest updateRequest;
};

#endif // APPLICATION_H
