#ifndef ROBOTSTATEHISTORY_H
#define ROBOTSTATEHISTORY_H

#include <QObject>
#include <QtCore>
#include <memory>
#include <vector>
#include "RobotState/robotstate.h"

/**
 * @brief RobotState history - Robottól bejövő státuszok eltárolása
 *
 * RobotState típusú elemek egy vector-ban
 */
class RobotStateHistory : public QObject
{
    Q_OBJECT
public:
    /** @brief Default konstruktor */
    RobotStateHistory();
    /** @brief Default destruktor */
    ~RobotStateHistory() = default;

    /** @brief Előző állapotokat tároló lista */
    QList<QObject*> stateList;
    /** @brief Pointer az aktuális (utolsó) státuszra. Az add függvény frissíti. */
    RobotState* currentState;
    /** @brief A tényleges tároló (ownership) */
    std::vector<std::unique_ptr<RobotState>> container;

    /**
     * @brief Lista a kormányszög grafikon rajzolásához.
     *
     * Az add függvény mindig a history utolsó shownStateNumber darab értékét írja bele.
     * qreal típusú, mert a tárolt változók float-ok, de a QML azt nem tudja értelmezni.
     */
    QList<qreal> graphSteeringAngle;

    /**
     * @brief Lista az első vonalszenzor pozíció grafikon rajzolásához.
     *
     * Az add függvény mindig a history utolsó shownStateNumber darab értékét írja bele.
     * qreal típusú, mert a tárolt változók float-ok, de a QML azt nem tudja értelmezni.
     */
    QList<qreal> graphFrontLinePos;

    /**
     * @brief Lista a sebesség grafikon rajzolásához.
     *
     * Az add függvény mindig a history utolsó shownStateNumber darab értékét írja bele.
     * qreal típusú, mert a tárolt változók float-ok, de a QML azt nem tudja értelmezni.
     */
    QList<qreal> graphCarSpeed;

    /** @brief A grafikon ennyi elemet ábrázol */
    const int shownStateNumber = 100;

signals:
    /** @brief Az add függvény hívása után emittáljuk */
    void historyChanged();

public slots:
    /**
     * @brief A state állapotról másolatot készít, majd hozzáfűzi a historyhoz.
     * A currentState változót is frissíti.
     * @param state
     */
    void add(RobotState& state);
};

#endif // ROBOTSTATEHISTORY_H
