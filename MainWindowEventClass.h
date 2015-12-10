#ifndef MAINWINDOWEVENTCLASS_H
#define MAINWINDOWEVENTCLASS_H

#include <QObject>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include "robotstatehistory.h"
#include "Comm/roboterrormessage.h"

/**
 * @brief The MainWindowEventClass class - Tartalmazza a felhasználói felület eseménykezelőit
 *
 * @note - A megfelelő működéshez a connectQmlSignals() metódust
 *  QML gyökér objektummal kell meghívni.
 */
class MainWindowEventClass : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief MainWindowEventClass - kontruktor, függőségeket állítja be, összeköti a history.historyChanged(); signalt
     * a graphChanged(); slottal
     * @param context - QML kontextus
     * @param hState - history objektum
     */
    MainWindowEventClass(QQmlContext &context, RobotStateHistory &hState);

    ~MainWindowEventClass() = default;

    /**
     * @brief connectQmlSignals - kikeresi a kívánt qml oldali obektumot majd csatlakozik a requestPaint() slothoz
     * a grafikonok újrarajzolásához
     * @warning - kötelezően meg kell hívni, ez biztosítja az újrarajzoláshoz szükséges slot megfelelő bekötését
     * @param rootObject - QMl gyökérelem
     * @param str - keresett QML objetum
     */
    void connectQmlSignals(QObject *rootObject, QString str);

public slots:
    /**
     * @brief graphChanged - frissíti a QML oldali változókat az aktuális history értékekkel, majd kiad
     * egy graphContextUpdated(); signalt a grafikonok újrarajzolásához
     */
    void graphChanged();

    /**
     * @brief stopCommand - parancs mely leállítja a futást
     */
    void stopCommand();

    /**
     * @brief startCommand - parancs mely leállítja a futást
     */
    void startCommand();

    void errorMsgReceived(RobotErrorMessage::Code code);

    void selfTestReceivedMessage(QString message);

signals:
    /**
     * @brief graphContextUpdated - signal mely újrarajzoltatja a QML oldali grafikont
     */
    void graphContextUpdated();

private:
    /**
     * @brief qmlContext - QML kontextus
     */
    QQmlContext &qmlContext;

    /**
     * @brief history - grafikonra rajzolandó adatok listája
     */
    RobotStateHistory &history;

    /**
     * @brief FindItemByName - QML elemek rekurzív megkeresését szolgáló függvény
     * @param rootObject - QML gyökérelem
     * @param name - keresett objektum neve
     * @return - a megtalált objektumra mutató poiter
     */
    static QQuickItem* FindItemByName(QObject *rootObject, const QString& name);

    /**
     * @brief FindItemByName - QML elemek rekurzív megkeresését szolgáló függvény, mely a
     * FindItemByName(QObject *rootObject, const QString& name) függvényt használja fel
     * @param nodes - node-ok listája amiben ekurzívan keressük a kívánt objektumunkat
     * @param name - keresett objektum neve
     * @return - a megtalált objektumra mutató poiter
     */
    static QQuickItem* FindItemByName(QList<QObject*> nodes, const QString& name);
};

#endif // MAINWINDOWEVENTCLASS_H
