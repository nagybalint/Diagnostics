#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include "ConsoleTabEventClass.h"
#include "Comm/commserial.h"
#include "Comm/robotmsghandler.h"
#include "GraphTabEventClass.h"

class Application : public QApplication
{
public:
    Application(int argc, char *argv[]);
    ~Application() = default;

    QQmlApplicationEngine engine;
    ConsoleTabEventClass console;
    CommSerial serial;
    RobotMsgHandler handler;
    GraphTabEventClass testGraph;

};

#endif // APPLICATION_H
