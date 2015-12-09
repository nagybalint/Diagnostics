#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include "ConsoleTabEventClass.h"
#include "GraphTabEventClass.h"

class Application : public QApplication
{
public:
    Application(int argc, char *argv[]);
    ~Application() = default;

private:
    QQmlApplicationEngine engine;
    ConsoleTabEventClass console;
    GraphTabEventClass testGraph;
};

#endif // APPLICATION_H
