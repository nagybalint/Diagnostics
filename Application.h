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
#include "robottest.h"


/**
 * @brief The Application class - main() indítja el
 *
 * a konstruktor elvégzi a megfelelő példányosításokat majd signalok bekötését
 */
class Application : public QApplication
{
public:
    /**
     * @brief Application - alapvető példányosítások és signalok bekötése
     */
    Application(int argc, char *argv[]);

    /// Destruktor
    ~Application() = default;

    QQmlApplicationEngine engine;
    /**
     * @brief consoleTab - Felhasználió felület Consol fül
     */

    ConsoleTabEventClass consoleTab;
    /**
     * @brief history - Korábbi valamint aktuális állapotot tároló RobotStateHistory példány
     */

    RobotStateHistory history;
    /**
     * @brief graphTab - felhasználói felület Graph fül
     */
    GraphTabEventClass graphTab;

    /**
     * @brief serial - Soros port példányosíása
     */
    CommSerial serial;

    /**
     * @brief handler - üzenetkezelő
     */
    RobotMsgHandler handler;

    /**
     * @brief updateRequest
     */
    UpdateRequest updateRequest;

    /**
     * @brief mainWindow - felhasználói felület főbb része
     */
    MainWindowEventClass mainWindow;

    RobotTest selfTest;
};

#endif // APPLICATION_H
