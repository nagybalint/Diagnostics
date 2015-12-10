#ifndef ROBOTTEST_H
#define ROBOTTEST_H

#include <QObject>
#include <QTimer>
#include "Comm/robotmsghandler.h"

class RobotTest : public QObject
{
    Q_OBJECT
public:
    RobotTest(RobotMsgHandler& handler);
    ~RobotTest() = default;

private:
    QTimer timer;
    RobotMsgHandler* handler;
    enum class Stage{
        Start,
        ServoTest,
        SpeedTest
    };
signals:
    void robotTestMessage(QString message);

public slots:
    void run();
    void abort();
};

#endif // ROBOTTEST_H
