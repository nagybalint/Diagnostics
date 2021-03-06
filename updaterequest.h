#ifndef UPDATEREQUEST_H
#define UPDATEREQUEST_H

#include <QObject>
#include <QTimer>
#include "Comm/robotmsghandler.h"

/**
 * @brief UpdateRequest osztály
 * Egy beállított periódusidővel kérdezi le a robottól a státuszát
 */

class UpdateRequest : public QObject
{
    Q_OBJECT
public:
    UpdateRequest(RobotMsgHandler& handler);
    ~UpdateRequest() = default;

private:

    float period;
    RobotMsgHandler* handler;
    QTimer timer;

signals:

public slots:
    void start(float interval);
    void stop();

    void tick();
};

#endif // UPDATEREQUEST_H
