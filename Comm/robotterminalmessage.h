#ifndef ROBOTTERMINALMESSAGE_H
#define ROBOTTERMINALMESSAGE_H

#include <QObject>
#include "robotmessage.h"

class RobotTerminalMessage : public RobotMessage
{
    Q_OBJECT
public:
    RobotTerminalMessage();

    int parseMessage(QDataStream &inStream) override;
    friend QDataStream &operator<<(QDataStream &, const RobotTerminalMessage &);

private:
    QString message;

signals:

public slots:
};

QDataStream &operator<<(QDataStream &, const RobotTerminalMessage &);

#endif // ROBOTTERMINALMESSAGE_H
