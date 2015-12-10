#ifndef ROBOTTEST_H
#define ROBOTTEST_H

#include <QObject>
#include <QTimer>
#include "Comm/robotmsghandler.h"

/**
 * @brief The RobotTest class - ellenörzi a robot megfelelő működését
 */
class RobotTest : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief RobotTest - konstruktor
     * @param handler - használandó RobotMsgHandler példány
     */
    RobotTest(RobotMsgHandler& handler);
    ~RobotTest() = default;

private:
    /**
     * @brief timer - késleltetést szolgáló timer
     */
    QTimer timer;

    RobotMsgHandler* handler;

    enum class Stage{
        Start,
        ServoTest,
        SpeedTest
    };
signals:
    /**
     * @brief robotTestMessage - QML környezetbe küldi a tesztelés üzeneteit
     * @param message - felhasználói felületen megjelenítendő üzenet
     */
    void robotTestMessage(QString message);

public slots:
    /**
     * @brief run - elíndítja a robot tesztelését
     */
    void run();

    /**
     * @brief abort - leállítja a robot tesztelését
     */
    void abort();
};

#endif // ROBOTTEST_H
