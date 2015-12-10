#ifndef GRAPHTABEVENTCLASS_H
#define GRAPHTABEVENTCLASS_H

#include <QObject>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <robotstatehistory.h>

/**
 * @brief The GraphTabEventClass class -
 * Gaphics fülhöz események kezelését végző osztály, mely csatlakozik a qml oldalhoz
 */

class GraphTabEventClass : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief GraphTabEventClass - konstruktor, csatlakozik a szükséges qml oldali változókhoz valamint összekapcsolja
     * a history.historyChanged(); signalt a graphChanged(); slottal
     * @param context - qml kontextus a változók valamit signalok eléréséhez
     * @param history - grafikon adatait tartalmazó lista
     */
    GraphTabEventClass(QQmlContext &context, RobotStateHistory &history);

    ~GraphTabEventClass() = default;

    /**
     * @brief connectQmlSignals - kikeresi a kívánt qml oldali obektumot majd csatlakozik a requestPaint() slothoz
     * a grafikonok újrarajzolásához
     * @param rootObject - első qml  objektumra mutató pointer
     * @param str - keresett qml objektum
     */
    void connectQmlSignals(QObject *rootObject, QString str);

public slots:

    /**
     * @brief graphChanged - grafikon értékeit frissítő slot, az értékek frissítése
     * után meghívja a graphContextUpdated(); signalt
     */
    void graphChanged();

signals:
    /**
     * @brief graphContextUpdated - signal mely újrarajzoltatja a qml oldali grafikonokat
     */
    void graphContextUpdated();


private:
    /**
     * @brief qmlContext - qml kontextus a változók és signalok eléréséhez
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

#endif // GRAPHTABEVENTCLASS_H
