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
    explicit RobotStateHistory(QObject *parent = 0);

    /* List of previous robot states */
    QList<QObject*> stateList;
    /* Pointer to last valid state. Updated by add(). */
    RobotState *currentState;
    /* Real container (ownership) */
    std::vector<std::unique_ptr<RobotState>> container;

    /* Append a copy of the parameter to the end of the history */
    void add(const RobotState& state);

signals:
    /* emit after add() */
    void historyChanged();

public slots:
};

#endif // ROBOTSTATEHISTORY_H
