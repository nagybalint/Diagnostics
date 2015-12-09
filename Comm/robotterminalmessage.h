#ifndef ROBOTTERMINALMESSAGE_H
#define ROBOTTERMINALMESSAGE_H

#include <QObject>
#include "robotmessage.h"

class RobotTerminalMessage : public RobotMessage
{
    Q_OBJECT
public:
    RobotTerminalMessage();
    RobotTerminalMessage(QString& msg);

    int parseMessage(QDataStream &inStream) override;
    void setMessage(QString& msg);
    QString& getMessage();
    friend QDataStream &operator<<(QDataStream &, const RobotTerminalMessage &);

private:
    QString message;

signals:

public slots:
};

QDataStream &operator<<(QDataStream &, const RobotTerminalMessage &);

#endif // ROBOTTERMINALMESSAGE_H
