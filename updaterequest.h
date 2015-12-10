#ifndef UPDATEREQUEST_H
#define UPDATEREQUEST_H

#include <QObject>
#include <QTimer>
#include "Comm/robotmsghandler.h"

class UpdateRequest : public QObject
{
    Q_OBJECT
public:
    UpdateRequest(RobotMsgHandler& handler);
    ~UpdateRequest() = default;
    void start(float interval);
    void stop();

private:

    float period;
    RobotMsgHandler* handler;
    QTimer timer;

signals:

public slots:

    void tick();
};

#endif // UPDATEREQUEST_H