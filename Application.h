#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include "ConsoleTabEventClass.h"
#include "Comm/commserial.h"
#include "Comm/robotmsghandler.h"
#include "GraphTabEventClass.h"
#include <QTimer>

class Application : public QApplication
{
public:
    Application(int argc, char *argv[]);
    ~Application() = default;

    QQmlApplicationEngine engine;
    ConsoleTabEventClass console;
    GraphTabEventClass testGraph;
    CommSerial serial;
    RobotMsgHandler handler;
};

#endif // APPLICATION_H
