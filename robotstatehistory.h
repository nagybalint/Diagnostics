#ifndef ROBOTSTATEHISTORY_H
#define ROBOTSTATEHISTORY_H

#include <QObject>
#include <QtCore>
#include <memory>
#include <vector>
#include "RobotState/robotstate.h"

class RobotStateHistory : public QObject
{
    Q_OBJECT
public:
    RobotStateHistory();
    ~RobotStateHistory() = default;

    /* List of previous robot states */
    QList<QObject*> stateList;
    /* Pointer to last valid state. Updated by add(). */
    RobotState* currentState;
    /* Real container (ownership) */
    std::vector<std::unique_ptr<RobotState>> container;

    /* Lists for QML graph drawing */
    QList<qreal> graphSteeringAngle;
    QList<qreal> graphFrontLinePos;
    QList<qreal> graphCarSpeed;
    /* number of previous states to show */
    const int shownStateNumber = 100;



signals:
    /* emit after add() */
    void historyChanged();

public slots:
    /* Append a copy of the parameter to the end of the history and update currendState */
    void add(RobotState& state);
};

#endif // ROBOTSTATEHISTORY_H
